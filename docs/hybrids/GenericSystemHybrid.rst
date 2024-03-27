.. _GenericSystemHybrid:

GenericSystemHybrid
===================

.. py:class:: PySAM.Hybrids.GenericSystemHybrid.GenericSystemHybrid()

    Class that adds :mod:`PySAM.GenericSystem.GenericSystem` to :mod:`PySAM.Hybrids.HybridSystem.HybridSystem`
    
    .. py:function:: new() -> 

    .. py:function:: default(config) -> GenericSystemHybrid

        Load defaults for the configuration config. Available configurations:

            "GenericPVWattsWindFuelCellBatteryHybridHostDeveloper"
            
            "GenericPVWattsWindFuelCellBatteryHybridSingleOwner"
    
    .. py:function:: value(name, value=None) -> None | float | dict | sequence | str

        Get or set by name a value in any of the variable groups.

    .. py:function:: assign(input_dict) -> dict

        Assign attributes from nested dictionary, except for Outputs::

            nested_dict = { 'Plant': { 'conv_eff': val, ...}, ...}

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

    .. py:class:: Plant
        
        See :mod:`PySAM.GenericSystemHybrid.GenericSystemHybrid.Plant`

    .. py:class:: Lifetime
                
        See :mod:`PySAM.GenericSystemHybrid.GenericSystemHybrid.Lifetime`

    .. py:class:: AdjustmentFactors
                
        See :mod:`PySAM.GenericSystemHybrid.GenericSystemHybrid.AdjustmentFactors`

    .. py:class:: Outputs
                
        See :mod:`PySAM.GenericSystemHybrid.GenericSystemHybrid.Outputs`