from collections import OrderedDict
from ctypes import *

from .HybridBase import HybridGenerator
from .PVWattsHybrid import PVWattsHybrid, pvwatts
from .PVHybrid import PVHybrid, pv
from .WindHybrid import WindHybrid, wind
from .BatteryHybrid import BatteryHybrid, batt
from .GenericSystemHybrid import GenericSystemHybrid, gensys
from .FuelCellHybrid import FuelCellHybrid, fuelcell

import PySAM.Grid as grid
import PySAM.HostDeveloper as hd
import PySAM.Utilityrate5 as ur
import PySAM.Singleowner as so
import PySAM.Hybrid as hybrid


class HybridSystem:
    supported_financial_modules = {"singleowner": so, "utilityrate5": ur, "host_developer": hd}

    def __init__(self, technology_modules, financial_modules) -> None:
        self._technology_modules = technology_modules
        self._financial_module = financial_modules

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
            elif pysam_module == gensys:
                self.gensys: GenericSystemHybrid = GenericSystemHybrid()
                self._generators['generic_system'] = self.gensys
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
        
        for financial_module in financial_modules:
            if financial_module == so:
                self.singleowner: so.Singleowner
                self._financials['singleowner'] = None
            elif financial_module == ur:
                self.utilityrate5: ur.Utilityrate5
                self._financials['utilityrate5'] = None
            elif financial_module == hd:
                self.host_developer: hd.HostDeveloper
                self._financials['host_developer'] = None
            else:
                raise NotImplementedError(f"HybridSystem currently not enabled for module {financial_module}")
        
        self._cmod_list = list(self._generators.keys()) + ['grid'] + list(self._financials.keys())

    def new(self):
        for gen in self._generators.values():
            gen.new()
        self._grid = grid.new()
        for k in self._financials.keys():
            setattr(self, k, self.supported_financial_modules[k].from_existing(self._grid))
            self._financials[k] = getattr(self, k)

    def default(self, config_name: str):
        for gen in self._generators.values():
            gen.default(config_name)
        self._grid = grid.default(config_name)
        for k in self._financials.keys():
            setattr(self, k, self.supported_financial_modules[k].from_existing(self._grid, config_name))
            self._financials[k] = getattr(self, k)

    def assign(self, input_dict):
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
        return unassigned

    def value(self, name):
        outputs = self._hybrid.Outputs.output
        if name not in outputs.keys:
            raise ValueError(f"{name} is not an output of HybridSystem")
        return self._hybrid.Outputs.output[name]

    def _collect_hybrid_inputs(self):
        """
        Takes data container from the sub-system models and passes them to the hybrid input data container, which makes a copy
        """
        for name, gen in self._generators.items():
            gen._collect_inputs(self._data_input_ptr)

        HybridGenerator._ssc.data_set_table(self._data_input_ptr, b'hybrid', self._grid.get_data_ptr())
        HybridGenerator._ssc.data_set_data_array(self._data_input_ptr, b'compute_modules', self._cmod_list)
        HybridGenerator._ssc.data_set_table(self._data_ptr, b'input', self._data_input_ptr)

    def _collect_hybrid_outputs(self):
        """
        Gets sub-system data from the hybrid model and copies them back to the sub-system classes
        """
        data_input = HybridGenerator._ssc.pdll.ssc_data_get_table(c_ulong(self._data_ptr), b'input')
        for name, gen in self._generators.items():
            gen._collect_outputs(data_input)
        p_fin_ret = HybridGenerator._ssc.pdll.ssc_data_get_table(c_ulong(data_input), b'hybrid')
        data_ptr = self._grid.get_data_ptr()
        HybridGenerator._ssc.pdll.ssc_data_deep_copy(c_ulong(p_fin_ret), c_ulong(data_ptr))

    def execute(self, verbosity_int=0):
        self._collect_hybrid_inputs()
        self._hybrid.execute(verbosity_int)
        self._collect_hybrid_outputs()

    def export(self):
        return self._hybrid.export()