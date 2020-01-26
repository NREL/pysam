.. Examples:

Examples
========

Accessing Variables
*******************

All variables in a PySAM class are organized into subclasses called Groups. There are several ways to access a variable.

Directly as <class><subclass><variable>, as for the LocationAndResource group in Pvwattsv7::

    import PySAM.Pvwattsv7 as pv

    system_model = pv.new()
    system_model.SolarResource.solar_resource_file


Groups and variables can also be accessed using `__getattribute__`. Variables can be set with `__setattr__::

    system_model.__getattribute__('SolarResource').__getattribute__('solar_resource_file')
    system_model.__getattribute__('SolarResource').__setattr__('solar_resource_file') = filename


If the group name isn't known, a variable can be accessed using `value`::

    system_model.value('solar_resource_file')
    system_model.valie('solar_resource_file', filename)


The `assign` and `export` functions can be used to work with groups of variables in dictionaries::

    systemDesign = {'azimuth':100, 'gcr': .5}   # ground coverage ratio
    system_model.SystemDesign.assign(systemDesign)
    system_model.SystemDesign.export()

Creating a Simulation from Multiple Modules
**************************************


This is how to create a PV PPA plant simulation using the simplified PV model, Pvwattsv7, and Singleowner, where the
values are loaded from the set of default parameters in the configuration "PVWattsSingleOwner".

The Singleowner model is created using the `from_existing` function so that it shares the same underlying data as the
PVwattsv7 model. The execute function of each model is called sequentially.::

    import PySAM.Pvwattsv7 as pv
    import PySAM.Singleowner as so

    system_model = pv.default('PVWattsSingleOwner')
    financial_model = so.from_existing(system_model, 'PVWattsSingleOwner')

    system_model.SolarResource.solar_resource_file = filename

    system_model.execute()
    financial_model.execute()

    print(system_model.Outputs.ac_annual, financial_model.Outputs.ppa)


Importing a SAM GUI Case
*******************


For an example of how to import the modules and variables from a SAM GUI Case, see :doc:`Import`.


Sizing a PV + Battery system with ReOpt
**************************************

Pvwattsv7 and Pvsamv1 have the option to size and dispatch a StandAloneBattery or Battwatts model from ReOpt Lite's
optimization. The Utilityrate5 model is also required to provide electric tariff info, and other financial models
such as Cashloan may also be linked to provide financial parameters. The `Reopt_size_battery_post` function returns
a properly-formatted dictionary of ReOpt inputs that can then be posted to the ReOpt Lite API as a json string::

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



