.. _PVHybrid:

PVHybrid
========

.. py:class:: PySAM.Hybrids.PVHybrid.PVHybrid()

    Class that adds PVHybrid to HybridSystem
    
    .. py:function:: new() -> PVHybrid

    .. py:function:: default(config) -> PVHybrid

        Load defaults for the configuration config. Available configurations:

            "PhotovoltaicWindBatteryHybridHostDeveloper"

            "PhotovoltaicWindBatteryHybridSingleOwner"
    
    .. py:function:: value(name, value=None) -> None | float | dict | sequence | str

        Get or set by name a value in any of the variable groups.

    .. py:function:: assign(input_dict) -> dict

        Assign attributes from nested dictionary, except for Outputs::

            nested_dict = { 'SolarResource': { 'solar_resource_file': val, ...}, ...}

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

    .. py:class:: SolarResource
        
        See :mod:`PySAM.PVHybrid.PVHybrid.SolarResource`

    .. py:class:: Losses
                
        See :mod:`PySAM.PVHybrid.PVHybrid.Losses`

    .. py:class:: Lifetime
                
        See :mod:`PySAM.PVHybrid.PVHybrid.Lifetime`

    .. py:class:: SystemDesign
                
        See :mod:`PySAM.PVHybrid.PVHybrid.SystemDesign`

    .. py:class:: Shading
                
        See :mod:`PySAM.PVHybrid.PVHybrid.Shading`

    .. py:class:: Layout
                
        See :mod:`PySAM.PVHybrid.PVHybrid.Layout`

    .. py:class:: Module
                
        See :mod:`PySAM.PVHybrid.PVHybrid.Module`

    .. py:class:: SimpleEfficiencyModuleModel
                
        See :mod:`PySAM.PVHybrid.PVHybrid.SimpleEfficiencyModuleModel`

    .. py:class:: CECPerformanceModelWithModuleDatabase
                
        See :mod:`PySAM.PVHybrid.PVHybrid.CECPerformanceModelWithModuleDatabase`

    .. py:class:: CECPerformanceModelWithUserEnteredSpecifications
                
        See :mod:`PySAM.PVHybrid.PVHybrid.CECPerformanceModelWithUserEnteredSpecifications`

    .. py:class:: SandiaPVArrayPerformanceModelWithModuleDatabase
                
        See :mod:`PySAM.PVHybrid.PVHybrid.SandiaPVArrayPerformanceModelWithModuleDatabase`


    .. py:class:: IEC61853SingleDiodeModel
                
        See :mod:`PySAM.PVHybrid.PVHybrid.IEC61853SingleDiodeModel`

    .. py:class:: MermoudLejeuneSingleDiodeModel
                
        See :mod:`PySAM.PVHybrid.PVHybrid.MermoudLejeuneSingleDiodeModel`

    .. py:class:: Inverter
                
        See :mod:`PySAM.PVHybrid.PVHybrid.Inverter`

    .. py:class:: InverterCECDatabase
                
        See :mod:`PySAM.PVHybrid.PVHybrid.InverterCECDatabase`

    .. py:class:: InverterCECCoefficientGenerator
                
        See :mod:`PySAM.PVHybrid.PVHybrid.InverterCECCoefficientGenerator`

    .. py:class:: InverterDatasheet
                
        See :mod:`PySAM.PVHybrid.PVHybrid.InverterDatasheet`

    .. py:class:: InverterPartLoadCurve
                
        See :mod:`PySAM.PVHybrid.PVHybrid.InverterPartLoadCurve`

    .. py:class:: InverterMermoudLejeuneModel
                
        See :mod:`PySAM.PVHybrid.PVHybrid.InverterMermoudLejeuneModel`

    .. py:class:: BatterySystem
                
        See :mod:`PySAM.PVHybrid.PVHybrid.BatterySystem`

    .. py:class:: Load
                
        See :mod:`PySAM.PVHybrid.PVHybrid.Load`

    .. py:class:: PVLosses
                
        See :mod:`PySAM.PVHybrid.PVHybrid.PVLosses`

    .. py:class:: AdjustmentFactors
                
        See :mod:`PySAM.PVHybrid.PVHybrid.AdjustmentFactors`

    .. py:class:: BatteryCell
                
        See :mod:`PySAM.PVHybrid.PVHybrid.BatteryCell`

    .. py:class:: BatteryDispatch
                
        See :mod:`PySAM.PVHybrid.PVHybrid.BatteryDispatch`

    .. py:class:: SystemCosts
                
        See :mod:`PySAM.PVHybrid.PVHybrid.SystemCosts`

    .. py:class:: FuelCell
                
        See :mod:`PySAM.PVHybrid.PVHybrid.FuelCell`

    .. py:class:: PriceSignal
                
        See :mod:`PySAM.PVHybrid.PVHybrid.PriceSignal`

    .. py:class:: Revenue
                
        See :mod:`PySAM.PVHybrid.PVHybrid.Revenue`

    .. py:class:: ElectricityRates
                
        See :mod:`PySAM.PVHybrid.PVHybrid.ElectricityRates`

    .. py:class:: GridLimits
                
        See :mod:`PySAM.PVHybrid.PVHybrid.GridLimits`

    .. py:class:: Outputs
                
        See :mod:`PySAM.PVHybrid.PVHybrid.GridLimits`
