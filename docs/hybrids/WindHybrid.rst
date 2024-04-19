.. _WindHybrid:

WindHybrid
==========

.. py:class:: PySAM.Hybrids.WindHybrid.WindHybrid()

    Class that adds :mod:`PySAM.Windpower.Windpower` to :mod:`PySAM.Hybrids.HybridSystem.HybridSystem`
    
    .. py:function:: new() -> WindHybrid

    .. py:function:: default(config) -> WindHybrid

        Load defaults for the configuration config. Available configurations:

            "GenericPVWattsWindFuelCellBatteryHybridHostDeveloper"

            "GenericPVWattsWindFuelCellBatteryHybridSingleOwner"

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

            nested_dict = { 'Resource': { 'wind_resource_filename': val, ...}, ...}

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

    .. py:class:: Resource
        
        See :mod:`PySAM.Windpower.Windpower.Resource`

    .. py:class:: Turbine
                
        See :mod:`PySAM.Windpower.Windpower.Turbine`

    .. py:class:: Farm
                
        See :mod:`PySAM.Windpower.Windpower.Farm`

    .. py:class:: Losses
                
        See :mod:`PySAM.Windpower.Windpower.Losses`
    

    .. py:class:: AdjustmentFactors
                
        See :mod:`PySAM.Windpower.Windpower.AdjustmentFactors`

    .. py:class:: Uncertainty
                
        See :mod:`PySAM.Windpower.Windpower.Uncertainty`
    

    .. py:class:: Outputs
                
        See :mod:`PySAM.Windpower.Windpower.Outputs`