.. _BatteryHybrid:

BatteryHybrid
=============

.. py:class:: PySAM.Hybrids.BatteryHybrid.BatteryHybrid()

    Class that adds :mod:`PySAM.Battery.Battery` to :mod:`PySAM.Hybrids.HybridSystem.HybridSystem`
    
    .. py:function:: new() -> BatteryHybrid

    .. py:function:: default(config) -> BatteryHybrid

        Load defaults for the configuration config. Available configurations:

            "CustomGenerationPVWattsWindFuelCellBatteryHybridHostDeveloper"

            "CustomGenerationPVWattsWindFuelCellBatteryHybridSingleOwner"

            "PVWattsWindBatteryHybridHostDeveloper"

            "PVWattsWindBatteryHybridSingleOwner"

            "PVWattsWindFuelCellBatteryHybridHostDeveloper"

            "PVWattsWindFuelCellBatteryHybridSingleOwner"

            "PhotovoltaicWindBatteryHybridHostDeveloper"
            
            "PhotovoltaicWindBatteryHybridSingleOwner"

    .. py:function:: value(name, value=None) -> None | float | dict | sequence | str

        Get or set by name a value in any of the variable groups.

    .. py:function:: assign(input_dict) -> dict

        Assign attributes from nested dictionary, except for Outputs::

            nested_dict = { 'BatterySystem': { 'batt_ac_dc_efficiency': val, ...}, ...}

        Returns list of variables that weren't assigned

    .. py:function:: export() -> dict

        Export attributes into nested dictionary

    .. py:property:: total_installed_cost

        Total installed cost for technology [$]

        :type: float

    .. py:property:: om_fixed

        Fixed O&M annual amount [$/year]

        :type: sequence

    .. py:property:: om_fixed_escal

        Fixed O&M escalation [%/year]

        :type: float

    .. py:property:: om_production

        Production-based O&M amount [$/MWh]

        :type: sequence

    .. py:property:: om_production_escal

        Production-based O&M escalation [%/year]

        :type: float

    .. py:property:: om_capacity

        Capacity-based O&M amount [$/kWcap]

        :type: sequence

    .. py:property:: om_capacity_escal

        Capacity-based O&M escalation [%/year]

        :type: float

    .. py:property:: degradation

        Annual AC degradation [%]. If not provided, defaults to [0]

        :type: sequence

    .. py:class:: Simulation
        
        See :mod:`PySAM.BatteryHybrid.BatteryHybrid.Simulation`

    .. py:class:: Lifetime
                
        See :mod:`PySAM.BatteryHybrid.BatteryHybrid.Lifetime`

    .. py:class:: BatterySystem
                
        See :mod:`PySAM.BatteryHybrid.BatteryHybrid.BatterySystem`

    .. py:class:: SystemOutput
                
        See :mod:`PySAM.BatteryHybrid.BatteryHybrid.SystemOutput`

    .. py:class:: Load
                
        See :mod:`PySAM.BatteryHybrid.BatteryHybrid.Load`

    .. py:class:: BatteryCell
                
        See :mod:`PySAM.BatteryHybrid.BatteryHybrid.BatteryCell`

    .. py:class:: Inverter
                
        See :mod:`PySAM.BatteryHybrid.BatteryHybrid.Inverter`

    .. py:class:: BatteryDispatch
                
        See :mod:`PySAM.BatteryHybrid.BatteryHybrid.BatteryDispatch`

    .. py:class:: Losses
                
        See :mod:`PySAM.BatteryHybrid.BatteryHybrid.Losses`

    .. py:class:: SystemCosts
                
        See :mod:`PySAM.BatteryHybrid.BatteryHybrid.SystemCosts`
        
    .. py:class:: FuelCell
                
        See :mod:`PySAM.BatteryHybrid.BatteryHybrid.FuelCell`

    .. py:class:: PriceSignal
                
        See :mod:`PySAM.BatteryHybrid.BatteryHybrid.PriceSignal`

    .. py:class:: Revenue
                
        See :mod:`PySAM.BatteryHybrid.BatteryHybrid.Revenue`
        
    .. py:class:: ElectricityRates
                
        See :mod:`PySAM.BatteryHybrid.BatteryHybrid.ElectricityRates`

    .. py:class:: GridLimits
                
        See :mod:`PySAM.BatteryHybrid.BatteryHybrid.GridLimits`

    .. py:class:: Outputs
                
        See :mod:`PySAM.BatteryHybrid.BatteryHybrid.Outputs`

    .. py:function:: Reopt_size_standalone_battery_post