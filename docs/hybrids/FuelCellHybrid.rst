.. _FuelCellHybrid:

FuelCellHybrid
==============

.. py:class:: PySAM.Hybrids.FuelCellHybrid.FuelCellHybrid()

    Class that adds :mod:`PySAM.FuelCell.FuelCell` to :mod:`PySAM.Hybrids.HybridSystem.HybridSystem`
    
    .. py:function:: new() -> FuelCellHybrid

    .. py:function:: default(config) -> FuelCellHybrid

        Load defaults for the configuration config. Available configurations:

            "GenericPVWattsWindFuelCellBatteryHybridHostDeveloper"

            "GenericPVWattsWindFuelCellBatteryHybridSingleOwner"

            "PVWattsWindFuelCellBatteryHybridHostDeveloper"

            "PVWattsWindFuelCellBatteryHybridSingleOwner"

    .. py:function:: value(name, value=None) -> None | float | dict | sequence | str

        Get or set by name a value in any of the variable groups.

    .. py:function:: assign(input_dict) -> dict

        Assign attributes from nested dictionary, except for Outputs::

            nested_dict = { 'FuelCell': { 'fuelcell_efficiency': val, ...}, ...}

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

    .. py:class:: Common
        
        See :mod:`PySAM.FuelCellHybrid.FuelCellHybrid.Common`

    .. py:class:: Lifetime
                
        See :mod:`PySAM.FuelCellHybrid.FuelCellHybrid.Lifetime`

    .. py:class:: Load
                
        See :mod:`PySAM.FuelCellHybrid.FuelCellHybrid.Load`

    .. py:class:: FuelCell
                
        See :mod:`PySAM.FuelCellHybrid.FuelCellHybrid.FuelCell`

    .. py:class:: Outputs
                
        See :mod:`PySAM.FuelCellHybrid.FuelCellHybrid.Outputs`