from typing import Any, Iterable
from pathlib import Path
import PySAM
from PySAM.PySSC import PySSC
import marshal
from ctypes import *

import PySAM.Grid as grid
import PySAM.Singleowner as so
import PySAM.HostDeveloper as hd 


class HybridGenerator:
    """
    Class that wraps around PySAM technology modules as a component of a HybridSystem. 

    All hybrid subsystem models require cost inputs that are added as properties here (e.g. om_fixed)

    The PySAM model contains the simulation data for the hybrid simulation, which are modified simlarly to how they are for PySAM
    modules: `value`, `assign`, direct access, and `export`.

    The subsystem model data is copied to and from the HybridSystem during execution.
    """
    _ssc: PySSC = PySSC()
    _ssc.pdll.ssc_data_get_table.restype = c_void_p
    _ssc.pdll.ssc_data_create.restype = c_void_p
    _ssc.pdll.ssc_var_get_number.restype = POINTER(c_float)
    
    def __init__(self, pysam_module, name) -> None:
        # create the system cmod and the required financial stuff
        self._name = name
        self._factory = pysam_module
        self._compute_module_name = pysam_module.__name__.split('.')[1].lower()
        # PySAM model that provides access to the simulation data
        self._data = None
        # Pointer to the simulation data container inside the PySAM model
        self._data_ptr = None

    def new(self):
        if self._data != None:
            raise NotImplementedError("Model data already created. Replacing model data is currently not supported. Create a new instance of HybridGenerator instead")
        self._data = self._factory.new()
        self._data_ptr = self._data.get_data_ptr()
        self._sole_data_owner = True

    def default(self, config_name: str):
        """
        Load defaults for the configuration config. Available configurations depend on the technology
        """
        if self._data != None:
            raise NotImplementedError("Model data already created. Replacing model data is currently not supported. Create a new instance of HybridGenerator instead")
        self._data = self._factory.default(config_name)
        self._data_ptr = self._data.get_data_ptr()
        self._sole_data_owner = True

        # load the fin vars manually
        defaults_dir = Path(PySAM.__file__).parent / "defaults" / f"{self._compute_module_name}_{config_name.lower()}.df"
        with open(defaults_dir, 'rb') as f:
            defaults = marshal.load(f)
        for k, v in defaults['HybridCosts'].items():
            self.__setattr__(k, v)

    def _collect_inputs(self, hybrid_input_data_ptr):
        """
        Insert the simulation data from this technology model as input into the hybrid input data.
        Hybrid input data makes a copy of the simulation data. 
        PySAM model still has data ownership of original simulation data
        """
        self._ssc.data_set_table(hybrid_input_data_ptr, self._name.encode("ascii"), self._data_ptr)

    def _collect_outputs(self, hybrid_input_data_ptr):
        """
        Function should only be called after `_collect_inputs` has been called. 

        Get the updated simulation data from the hybrid input data, now with results, and copy it
        """
        p_pv_ret = self._ssc.data_get_table(hybrid_input_data_ptr, self._name.encode("ascii"))
        if not p_pv_ret:
            raise RuntimeError(f"Outputs for {self._name} sub-system does not exist in `hybrid_input_data_ptr`")
        self._ssc.data_deep_copy(p_pv_ret, self._data_ptr)

    def __getattr__(self, name: str):
        if name in self.__dir__():
            return super().__getattr__(name)
        else:
            if not self._data:
                raise RuntimeError("Create the compute module first with `new` or ` default`")
            else:
                try:
                    return self._data.__getattribute__(name)
                except:
                    raise AttributeError(f"Attribute {name} does not exist in {self._factory.__name__} "
                                     "and is not a HybridGenerator financial variable.")

    def value(self, name, value=None):
        """
        Get or set by name a value in any of the variable groups.
        """
        if name == 'value':
            return
        elif name in self.__dir__():
            attr = getattr(self, name)
            if value is None:
                return attr
            else:
                return setattr(attr, value)
        else:
            if value is None:
                return self._data.value(name)
            return self._data.value(name, value)
        
    def assign(self, input_dict):
        """
        Assign attributes from nested dictionary, except for Outputs

        nested_dict = { 'Solar Resource': { var: val, ...}, ...}

        Returns list of variables that weren't assigned
        """
        unassigned = []
        for k, v in input_dict.items():
            try:
                if 'adjust_' in k:
                    k = k.split('adjust_')[1]
                self._data.value(k, v)
            except:
                unassigned.append(k)
        return unassigned
    
    def export(self):
        """
        Export attributes into nested dictionary
        """
        return self._data.export()

    @property
    def total_installed_cost(self):
        """
        Total installed cost for technology [$]
        """
        return self._ssc.data_get_number(self._data_ptr, b'total_installed_cost')
    
    @total_installed_cost.setter
    def total_installed_cost(self, total_installed_cost: float):
        self._ssc.data_set_number(self._data_ptr, b'total_installed_cost', total_installed_cost)

    @property
    def om_fixed(self):
        """
        Fixed O&M annual amount [$/year]
        """
        return self._ssc.data_get_array(self._data_ptr, b'om_fixed')
    
    @om_fixed.setter
    def om_fixed(self, om_fixed: Iterable):
        if not isinstance(om_fixed, Iterable):
            om_fixed = [om_fixed]
        self._ssc.data_set_array(self._data_ptr, b'om_fixed', om_fixed)

    @property
    def om_fixed_escal(self):
        """
        Fixed O&M escalation [%/year]
        """
        return self._ssc.data_get_number(self._data_ptr, b'om_fixed_escal')
    
    @om_fixed_escal.setter
    def om_fixed_escal(self, om_fixed_escal: float):
        self._ssc.data_set_number(self._data_ptr, b'om_fixed_escal', om_fixed_escal)

    @property
    def om_production(self):
        """
        Production-based O&M amount [$/MWh]
        """
        return self._ssc.data_get_array(self._data_ptr, b'om_production')
    
    @om_production.setter
    def om_production(self, om_production: Iterable):
        if not isinstance(om_production, Iterable):
            om_production = [om_production]
        self._ssc.data_set_array(self._data_ptr, b'om_production', om_production)

    @property
    def om_production_escal(self):
        """
        Production-based O&M escalation [%/year]
        """
        return self._ssc.data_get_number(self._data_ptr, b'om_production_escal')
    
    @om_production_escal.setter
    def om_production_escal(self, om_production_escal: float):
        self._ssc.data_set_number(self._data_ptr, b'om_production_escal', om_production_escal)

    @property
    def om_capacity(self):
        """
        Capacity-based O&M amount [$/kWcap]
        """
        return self._ssc.data_get_array(self._data_ptr, b'om_capacity')
    
    @om_fixed.setter
    def om_capacity(self, om_capacity: Iterable):
        if not isinstance(om_capacity, Iterable):
            om_capacity = [om_capacity]
        self._ssc.data_set_array(self._data_ptr, b'om_capacity', om_capacity)

    @property
    def om_capacity_escal(self):
        """
        Capacity-based O&M escalation [%/year]
        """
        return self._ssc.data_get_number(self._data_ptr, b'om_capacity_escal')
    
    @om_capacity_escal.setter
    def om_capacity_escal(self, om_capacity_escal: float):
        self._ssc.data_set_number(self._data_ptr, b'om_capacity_escal', om_capacity_escal)

    @property
    def degradation(self):
        """
        Annual AC degradation [%/yr]. If not provided, defaults to [0]
        """
        return self._ssc.data_get_array(self._data_ptr, b'degradation')
    
    @degradation.setter
    def degradation(self, degradation: Iterable):
        if not isinstance(degradation, Iterable):
            om_capacity = [om_capacity]
        self._ssc.data_set_array(self._data_ptr, b'degradation', degradation)
