Code Examples
==============

.. note::
    This section is a draft to be revised and expanded.

For PySAM code examples see the `PySAM repository on GitHub <https://github.com/NREL/pysam/tree/master/Examples>`_.

Generate Inputs for a REopt API Call
-------------------------------------

The Pvwattsv8 and Pvsamv1 compute modules, when used in a configuration with battery storage, have and option to size and dispatch the battery using the `ReOpt API <https://developer.nrel.gov/docs/energy-optimization/reopt-v1/>`_.

This basic code example shows how to use the ``Reopt_size_battery_post()`` function in preparation for a call to the REopt API. The function returns a dictionary of REopt inputs that can be converted to JSON for the API call. A complete model would require the ``Utilityrate5`` compute module for electricity bill calculations, and the ``Cashloan`` module for cash flow calculations.

.. code:: python

    import PySAM.Utilityrate5 as ur
    import PySAM.Pvsamv1 as pvsam
    import PySAM.StandAloneBattery as stbt

    system_model = pvsam.default("FlatPlatePVCommercial")
    financial_model = ur.from_existing(system_model, "FlatPlatePVCommercial")
    battery_model = stbt.from_existing(system_model, "BatteryNone")

    # ReOpt requires lat/lon for downloading a weather file internally; custom weather files cannot be provided
    # so instead lat lon can be read from a weather file
    system_model.SolarResource.solar_resource_file = filename

    battery_model.Load.crit_load = [0] * 8760
    post = system_model.Reopt_size_battery_post()
