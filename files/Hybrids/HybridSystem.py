from collections import OrderedDict
from ctypes import *

from .HybridBase import HybridGenerator
from .PVWattsHybrid import PVWattsHybrid, pvwatts
from .PVHybrid import PVHybrid, pv
from .WindHybrid import WindHybrid, wind
from .BatteryHybrid import BatteryHybrid, batt
from .CustomGenerationHybrid import CustomGenerationHybrid, custom
from .FuelCellHybrid import FuelCellHybrid, fuelcell

import PySAM.Grid as grid
import PySAM.HostDeveloper as hd
import PySAM.Utilityrate5 as ur
import PySAM.Singleowner as so
import PySAM.Hybrid as hybrid


class HybridSystem:
    """
    Class for hybrid systems that combines a performance model with a financial model and runs a PySAM.Hybrid simulation

    Supported performance model modules: Pvsamv1, Pvwattsv8, Windpower, CustomGeneration, Battery, Fuelcell

    Supported financial model modules: Singleowner, HostDeveloper

    Intermediate modules for financial models: Grid, Utililityrate5

    Modules for hybrid systems are defined as follows:

    HybridSystem.pv = PVHybrid (PySAM.Pvsamv1)
    HybridSystem.pvwatts = PVWattsHybrid (PySAM.Pvwattsv8)
    HybridSystem.wind = WindHybrid (PySAM.Windpower)
    HybridSystem.custom = CustomGenerationHybrid (PySAM.CustomGeneration)
    HybridSystem.battery = BatteryHybrid (PySAM.Battery)
    HybridSystem.fuelcell = FuelCellHybrid (PySAM.Fuelcell)
    HybridSystem._grid = PySAM.Grid
    HybridSystem.singleowner = PySAM.Singleowner
    HybridSystem.utilityrate5 = PySAM.Utilityrate5
    HybridSystem.host_developer = PySAM.HostDeveloper
    """
    supported_financial_modules = {"singleowner": so, "utilityrate5": ur, "host_developer": hd}

    def __init__(self, technology_modules, financial_model: str) -> None:
        """
        `technology_modules` is a list of PySAM modules of the technology subsystems
        `financial_modules` is "singleowner" or "hostdeveloper"
        """
        self._technology_modules = technology_modules
        self._financial_module = financial_model

        # data container for Hybrid module, ownership will belong to self._hybrid
        self._data_ptr = HybridGenerator._ssc.data_create()
        # input data container, will be copied into data container. Ownership stays with HybridSystem
        self._data_input_ptr = HybridGenerator._ssc.data_create()
        # PySAM model that will perform the Hybrid simulation
        self._hybrid = hybrid.wrap(self._data_ptr)

        self._generators = OrderedDict()

        # create PySAM models for each of the sub-systems
        for pysam_module in technology_modules:
            if pysam_module == pv:
                self.pv: PVHybrid = PVHybrid()
                self._generators['pvsamv1'] = self.pv
            elif pysam_module == pvwatts:
                self.pvwatts: PVWattsHybrid = PVWattsHybrid()
                self._generators['pvwattsv8'] = self.pvwatts
            elif pysam_module == wind:
                self.wind: WindHybrid = WindHybrid()
                self._generators['windpower'] = self.wind
            elif pysam_module == custom:
                self.custom: CustomGenerationHybrid = CustomGenerationHybrid()
                self._generators['custom_generation'] = self.custom
            elif pysam_module == batt:
                self.battery: BatteryHybrid = BatteryHybrid()
                self._generators['battery'] = self.battery
            elif pysam_module == fuelcell:
                self.fuelcell: FuelCellHybrid = FuelCellHybrid()
                self._generators['fuelcell'] = self.fuelcell
            else:
                raise NotImplementedError(f"HybridSystem currently not enabled for module {pysam_module}")

        self._financials = OrderedDict()

        self._grid: grid.Grid
        
        if financial_model.lower() == "singleowner":
            self.singleowner: so.Singleowner
            self._financials['singleowner'] = None
        elif financial_model.lower() == "hostdeveloper":
            self.utilityrate5: ur.Utilityrate5
            self._financials['utilityrate5'] = None
            self.host_developer: hd.HostDeveloper
            self._financials['host_developer'] = None
        else:
            raise NotImplementedError(f"HybridSystem currently not enabled for {financial_model}")

        self._cmod_list = list(self._generators.keys()) + ['grid'] + list(self._financials.keys())

    def new(self):
        """
        Create model
        """
        for gen in self._generators.values():
            gen.new()
        self._grid = grid.new()
        for k in self._financials.keys():
            setattr(self, k, self.supported_financial_modules[k].from_existing(self._grid))
            self._financials[k] = getattr(self, k)

    def default(self, config_name: str):
        """
        Create model with input variables set to default values. Available default configurations are:

            "CustomGenerationPVWattsWindFuelCellBatteryHybridHostDeveloper"
            "CustomGenerationPVWattsWindFuelCellBatteryHybridSingleOwner"
            "PVWattsWindBatteryHybridHostDeveloper"
            "PVWattsWindBatteryHybridSingleOwner"
            "PVWattsWindFuelCellBatteryHybridHostDeveloper"
            "PVWattsWindFuelCellBatteryHybridSingleOwner"
            "PhotovoltaicWindBatteryHybridHostDeveloper"
            "PhotovoltaicWindBatteryHybridSingleOwner"
        """
        for gen in self._generators.values():
            gen.default(config_name)
        self._grid = grid.default(config_name)
        for k in self._financials.keys():
            setattr(self, k, self.supported_financial_modules[k].from_existing(self._grid, config_name))
            self._financials[k] = getattr(self, k)

    def assign(self, input_dict):
        """
        Assign attributes from nested dictionary, except for Outputs::

            nested_dict = { 
                'pvsamv1': {
                    'SolarResource': { 
                        'solar_resource_file': val, ...
                    }, ...
                },
                'pvwattsv8': {...}

        Names of performance model modules: pvsamv1, pvwattsv8, windpower, custom_generation, battery, fuelcell
        Names of financial model modules: singleowner, utilityrate5, host_developer
        Names of intermediate modules: _grid, utilityrate5

        Returns dictionary of variables that weren't assigned

        """
        unassigned_dict = {}
        for k, v in input_dict.items():
            if k in self._generators.keys():
                unassigned_dict[k] = self._generators[k].assign(v)
            elif k.lower() == "hybrid":
                unassigned = []
                for key, value in input_dict[k].items():
                    if key in self._grid.GridLimits.__dir__() or key in self._grid.Load.__dir__():
                        self._grid.value(key, value)
                    else:
                        # Try to find which financial module it may belong to
                        assigned = False
                        for fin_model in self._financials.values():
                            for attr in fin_model.__dir__():
                                # PySAM group names are capitalized
                                if not attr[0].isupper():
                                    continue
                                attr = getattr(fin_model, attr)
                                if not hasattr(attr, '__dir__'):
                                    continue
                                # if variable belongs to this group
                                if key in attr.__dir__():
                                    fin_model.value(key, value)
                                    assigned = True
                                    break
                            if assigned:
                                break
                        if not assigned:
                            unassigned.append(key)
                unassigned_dict['hybrid'] = unassigned
        return unassigned_dict

    def value(self, name):
        """
        Get the value of a hybrid system model output
        """
        outputs = self._hybrid.Outputs.output
        if name not in outputs.keys:
            raise ValueError(f"{name} is not an output of HybridSystem")
        return self._hybrid.Outputs.output[name]

    def _collect_hybrid_inputs(self):
        """
        Takes data container from the sub-system models and passes them to the hybrid system input data container, which makes a copy
        """
        for name, gen in self._generators.items():
            gen._collect_inputs(self._data_input_ptr)

        HybridGenerator._ssc.data_set_table(self._data_input_ptr, b'hybrid', self._grid.get_data_ptr())
        HybridGenerator._ssc.data_set_data_array(self._data_input_ptr, b'compute_modules', self._cmod_list)
        HybridGenerator._ssc.data_set_table(self._data_ptr, b'input', self._data_input_ptr)

    def _collect_hybrid_outputs(self):
        """
        Gets sub-system data from the hybrid system model and copies them back to the sub-system classes
        """
        data_input = HybridGenerator._ssc.data_get_table(self._data_ptr, b'input')
        for name, gen in self._generators.items():
            gen._collect_outputs(data_input)
        p_fin_ret = HybridGenerator._ssc.data_get_table(data_input, b'hybrid')
        data_ptr = self._grid.get_data_ptr()
        HybridGenerator._ssc.data_deep_copy(p_fin_ret, data_ptr)

    def execute(self, verbosity_int=0):
        """
        Runs a hybrid system simulation
        """
        HybridGenerator._ssc.data_clear(self._data_input_ptr)
        HybridGenerator._ssc.data_clear(self._data_ptr)
        self._collect_hybrid_inputs()
        self._hybrid.execute(verbosity_int)
        self._collect_hybrid_outputs()

    def export(self):
        """
        Dictionary of hybrid system input and outputs
        """
        return self._hybrid.export()