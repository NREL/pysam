from typing import Iterable
import PySAM.Fuelcell as fuelcell

from .HybridBase import HybridGenerator

class FuelCellHybrid(HybridGenerator):
    """
    Class that adds Fuelcell to HybridSystem
    """
    def __init__(self) -> None:
        super().__init__(fuelcell, "fuelcell")
        self._data: fuelcell.Fuelcell

    @property
    def om_fixed(self):
        """
        Fuel cell fixed O&M annual amount [$/year]
        """
        return self._ssc.data_get_array(self._data, b'om_fuelcell_fixed_cost')
    
    @om_fixed.setter
    def om_fixed(self, om_fixed: Iterable):
        if not isinstance(om_fixed, Iterable):
            om_fixed = [om_fixed]
        self._ssc.data_set_array(self._data, b'om_fuelcell_fixed_cost', om_fixed)
    
    @property
    def om_production(self):
        """
        Fuel cell production-based O&M amount [$/MWh]
        """
        return self._ssc.data_get_array(self._data, b'om_fuelcell_variable_cost')
    
    @om_production.setter
    def om_production(self, om_production: Iterable):
        if not isinstance(om_production, Iterable):
            om_production = [om_production]
        self._ssc.data_set_array(self._data, b'om_fuelcell_variable_cost', om_production)

    @property
    def om_capacity(self):
        """
        Fuel cell capacity-based O&M amount [$/kWcap]
        """
        return self._ssc.data_get_array(self._data, b'om_fuelcell_capacity_cost')
    
    @om_fixed.setter
    def om_capacity(self, om_capacity: Iterable):
        if not isinstance(om_capacity, Iterable):
            om_capacity = [om_capacity]
        self._ssc.data_set_array(self._data, b'om_fuelcell_capacity_cost', om_capacity)

    @property
    def om_fuel_cost(self):
        """
        Fuel cost [$/MMBtu]
        """
        return self._ssc.data_get_array(self._data, b'om_fuel_cost')
    
    @om_fuel_cost.setter
    def om_fuel_cost(self, om_fuel_cost: Iterable):
        if not isinstance(om_fuel_cost, Iterable):
            om_fuel_cost = [om_fuel_cost]
        self._ssc.data_set_array(self._data, b'om_fuel_cost', om_fuel_cost)