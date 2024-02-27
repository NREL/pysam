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
    All properties that not SSC variables should be prepended with '_'
    """
    _ssc: PySSC = PySSC()
    _ssc.pdll.ssc_data_get_table.restype = c_long
    _ssc.pdll.ssc_data_create.restype = c_long
    _ssc.pdll.ssc_var_get_number.restype = POINTER(c_float)
    
    def __init__(self, pysam_module, name, hybrid_data) -> None:
        # create the system cmod and the required financial stuff
        self._name = name
        self._factory = pysam_module
        self._compute_module_name = pysam_module.__name__.split('.')[1].lower()
        self._data = None
        self._data_ptr = None
        self._hybrid_data = hybrid_data

    def new(self):
        self._data = self._factory.from_existing(self._hybrid_data)
        self._data_ptr = self._data.get_data_ptr()

    def default(self, config_name: str):
        self._data = self._factory.from_existing(self._hybrid_data, config_name)
        self._data_ptr = self._data.get_data_ptr()

        # load the fin vars manually
        defaults_dir = Path(PySAM.__file__).parent / "defaults" / f"{self._compute_module_name}_{config_name.lower()}.df"
        with open(defaults_dir, 'rb') as f:
            defaults = marshal.load(f)
        for k, v in defaults['HybridCosts'].items():
            self.__setattr__(k, v)

    def _collect_inputs(self, input):
        self._ssc.data_set_table(input, self._name.encode("ascii"), self._data_ptr)

    def _collect_outputs(self, input):
        p_pv_ret = self._ssc.pdll.ssc_data_get_table(c_ulong(input), self._name.encode("ascii"))
        self._data.set_data_ptr(p_pv_ret)

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
    def om_production_escal(self):
        """
        Capacity-based O&M escalation [%/year]
        """
        return self._ssc.data_get_number(self._data_ptr, b'om_production_escal')
    
    @om_production_escal.setter
    def om_production_escal(self, om_production_escal: float):
        self._ssc.data_set_number(self._data_ptr, b'om_production_escal', om_production_escal)

    @property
    def degradation(self):
        """
        Annual AC degradation [%]. If not provided, defaults to 0
        """
        return self._ssc.data_get_array(self._data_ptr, b'degradation')
    
    @degradation.setter
    def degradation(self, degradation: Iterable):
        if not isinstance(degradation, Iterable):
            om_capacity = [om_capacity]
        self._ssc.data_set_array(self._data_ptr, b'degradation', degradation)