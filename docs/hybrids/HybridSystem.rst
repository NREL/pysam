.. _HybridSystem:

HybridSystem
===============

.. py:class:: PySAM.Hybrids.HybridSystem.HybridSystem(technology_modules, financial_model)

    Class that contains PySAM technology subsystem models with a financial model and runs them in a :mod:`PySAM.Hybrid.Hybrid` simulation

    Currently only :mod:`PySAM.Singleowner.Singleowner` and :mod:`PySAM.HostDeveloper.HostDeveloper` financial models are supported

    .. py:data:: pv
        :type: PVHybrid | None

        None if :mod:`Pvsamv1<PySAM.Pvsamv1>` is in not in the technology stack

    .. py:data:: pvwatts
        :type: PVWattsHybrid | None

        None if :mod:`Pvwattsv8<PySAM.Pvwattsv8>` is in not in the technology stack

    .. py:data:: wind
        :type: WindHybrid | None

        None if :mod:`Windpower<PySAM.Windpower>` is in not in the technology stack

    .. py:data:: custom
        :type: CustomGenerationHybrid | None

        None if :mod:`CustomGeneration<PySAM.CustomGeneration>` is in not in the technology stack

    .. py:data:: battery
        :type: BatteryHybrid | None

        None if :mod:`Battery<PySAM.Battery>` is in not in the technology stack

    .. py:data:: fuelcell
        :type: FuelCellHybrid | None

        None if :mod:`Fuelcell<PySAM.Fuelcell>` is in not in the technology stack

    .. py:data:: _grid
        :type: Grid

    .. py:data:: singleowner
        :type: Singleowner | None

        None if ``financial_model`` is not "singleowner"

    .. py:data:: utilityrate5
        :type: Utilityrate5 | None

        None if ``financial_model`` is not "host_developer"

    .. py:data:: host_developer
        :type: HostDeveloper | None

        None if ``financial_model`` is not "host_developer"

    .. py:function:: new() -> HybridSystem

    .. py:function:: default(config_name) -> HybridSystem

        Create model with variables set to defaults of a configuration. Available configurations are:

            "CustomGenerationPVWattsWindFuelCellBatteryHybridHostDeveloper"

            "CustomGenerationPVWattsWindFuelCellBatteryHybridSingleOwner"

            "PVWattsWindBatteryHybridHostDeveloper"

            "PVWattsWindBatteryHybridSingleOwner"

            "PVWattsWindFuelCellBatteryHybridHostDeveloper"

            "PVWattsWindFuelCellBatteryHybridSingleOwner"

            "PhotovoltaicWindBatteryHybridHostDeveloper"

            "PhotovoltaicWindBatteryHybridSingleOwner"

    .. py:function:: value(name) -> float | dict | sequence | str

        Get the value of a Hybrid output

    .. py:function:: assign(input_dict) -> dict

        Assign attributes from nested dictionary, except for Outputs::

            nested_dict = { 
                'pvsamv1': {
                    'SolarResource': { 
                        'solar_resource_file': val, ...
                    }, ...
                },
                'pvwattsv8': {...}

        Names of the technology models: "pvsamv1", "pvwattsv8", "windpower", "custom_generation", "battery", "fuelcell"
        Names of the financial models: "singleowner", "utilityrate5", "host_developer"

    .. py:function:: execute(verbosity_int=0) -> None

        Runs simulation

    .. py:function:: export() -> dict

        Dictionary of input and outputs

