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
import PySAM.Singleowner as so
import PySAM.Hybrid as hybrid


class HybridSystem:
    def __init__(self, technology_modules, financial_module) -> None:
        self._technology_modules = technology_modules
        self._financial_module = financial_module

        self._data_ptr = HybridGenerator._ssc.data_create()
        self._data_input_ptr = HybridGenerator._ssc.data_create()
        self._hybrid = hybrid.wrap(self._data_ptr)

        self._generators = OrderedDict()

        for pysam_module in technology_modules:
            if pysam_module == pv:
                self.pv: PVHybrid = PVHybrid()
                self._generators['pvsamv1'] = self.pv
            elif pysam_module == pvwatts:
                self.pvwatts: PVWattsHybrid = PVWattsHybrid(self._hybrid)
                self._generators['pvwattsv8'] = self.pvwatts
            elif pysam_module == wind:
                self.wind: WindHybrid = WindHybrid(self._hybrid)
                self._generators['windpower'] = self.wind
            elif pysam_module == gensys:
                self.gensys: GenericSystemHybrid = GenericSystemHybrid()
                self._generators['generic_system'] = self.gensys
            elif pysam_module == batt:
                self.battery: BatteryHybrid = BatteryHybrid(self._hybrid)
                self._generators['battery'] = self.battery
            elif pysam_module == fuelcell:
                self.fuelcell: FuelCellHybrid = FuelCellHybrid()
                self._generators['fuelcell'] = self.fuelcell
            else:
                raise NotImplementedError(f"HybridSystem currently not enabled for module {pysam_module}")
            
        self.grid: grid.Grid
        
        if financial_module == so:
            self._financial: so.Singleowner
        elif financial_module == hd:
            self._financial: hd.HostDeveloper
        else:
            raise NotImplementedError(f"HybridSystem currently not enabled for module {financial_module}")
        
        # self._data_ptr = None
        # self._data_input_ptr = None

        self._cmod_list = list(self._generators.keys()) + ['grid', financial_module.__name__.split('.')[1].lower()]

    def new(self):
        for gen in self._generators.values():
            gen.new()
        self.grid = grid.new()
        self.financial = self._financial_module.from_existing(self.grid)

    def default(self, config_name: str):
        for gen in self._generators.values():
            gen.default(config_name)
        self.grid = grid.default(config_name)
        self.financial = self._financial_module.from_existing(self.grid, config_name)

    def assign(self, dict):
        # assigns dict separately to each module
        pass

    def value(self, name, value=None):
        pass

    def unassign(self, name):
        pass

    def _collect_hybrid_inputs(self):
        for name, gen in self._generators.items():
            gen._collect_inputs(self._data_input_ptr)

        HybridGenerator._ssc.data_set_table(self._data_input_ptr, b'hybrid', self.grid.get_data_ptr())
        HybridGenerator._ssc.data_set_data_array(self._data_input_ptr, b'compute_modules', self._cmod_list)
        HybridGenerator._ssc.data_set_table(self._data_ptr, b'input', self._data_input_ptr)

    def _collect_hybrid_outputs(self):
        data_input = HybridGenerator._ssc.pdll.ssc_data_get_table(c_ulong(self._data_ptr), b'input')
        for name, gen in self._generators.items():
            gen._collect_outputs(data_input)
        p_fin_ret = HybridGenerator._ssc.pdll.ssc_data_get_table(c_ulong(data_input), b'hybrid')
        self.grid.set_data_ptr(p_fin_ret)
        self.financial.set_data_ptr(p_fin_ret)

    def _clean(self):
        pass

    def execute(self, verbosity_int=0):
        self._clean()

        self._data_ptr = HybridGenerator._ssc.data_create()
        self._data_input_ptr = HybridGenerator._ssc.data_create()

        self._collect_hybrid_inputs()
        m_hybrid = hybrid.wrap(self._data_ptr)
        m_hybrid.execute(verbosity_int)
        m_hybrid.export()
        self._collect_hybrid_outputs()

        # HybridGenerator._ssc.data_free(self._data_ptr)
        self._data_ptr = None
        self._data_input_ptr = None

    def export(self):
        pass