from typing import Iterable
import PySAM.Battery as batt

from .HybridBase import HybridGenerator

class BatteryHybrid(HybridGenerator):
    """
    Class that adds Battery to HybridSystem
    """
    def __init__(self) -> None:
        super().__init__(batt, 'battery')
        self._data: batt.Battery

    def _collect_inputs(self, input):
        """
        Hybrid version requires `system_capacity` and `om_batt_nameplate` inputs, provide these from `batt_computed_bank_capacity`
        """
        if self._ssc.data_query(self._data_ptr, b'batt_computed_bank_capacity') != self._ssc.NUMBER:
            raise RuntimeError("BatteryHybrid error: BatterySystem.batt_computed_bank_capacity required but not assigned")
        self._ssc.data_set_variable(self._data_ptr, 'system_capacity', self._data.BatterySystem.batt_computed_bank_capacity)
        self._ssc.data_set_variable(self._data_ptr, 'om_batt_nameplate', self._data.BatterySystem.batt_computed_bank_capacity)
        super()._collect_inputs(input)

    @property
    def om_fixed(self):
        """
        Battery fixed O&M annual amount [$/year]
        """
        return self._ssc.data_get_array(self._data_ptr, b'om_batt_fixed_cost')
    
    @om_fixed.setter
    def om_fixed(self, om_fixed: Iterable):
        if not isinstance(om_fixed, Iterable):
            om_fixed = [om_fixed]
        self._ssc.data_set_array(self._data_ptr, b'om_batt_fixed_cost', om_fixed)
    
    @property
    def om_production(self):
        """
        Battery production-based O&M amount [$/MWh]
        """
        return self._ssc.data_get_array(self._data_ptr, b'om_batt_variable_cost')
    
    @om_production.setter
    def om_production(self, om_production: Iterable):
        if not isinstance(om_production, Iterable):
            om_production = [om_production]
        self._ssc.data_set_array(self._data_ptr, b'om_batt_variable_cost', om_production)

    @property
    def om_capacity(self):
        """
        Battery capacity-based O&M amount [$/kWcap]
        """
        return self._ssc.data_get_array(self._data_ptr, b'om_batt_capacity_cost')
    
    @om_capacity.setter
    def om_capacity(self, om_capacity: Iterable):
        if not isinstance(om_capacity, Iterable):
            om_capacity = [om_capacity]
        self._ssc.data_set_array(self._data_ptr, b'om_batt_capacity_cost', om_capacity)
