.. Examples:

Examples
========

There are a few example python scripts using PySAM in the Examples directory of the github repository.

Accessing Variables
*******************

All variables in a PySAM class are organized into subclasses called Groups.
There are several ways to access a variable.  The subclass and variable names
and descriptions are given in the :doc:`Models` documentation.

Variables may be accessed directly as `<class>.<subclass>.<variable>`.
For example, `the solar_resource_file` which is part of the subclass `SolarResource` group in Pvwattsv7::

    import PySAM.Pvwattsv8 as pv

    system_model = pv.new()
    system_model.SolarResource.solar_resource_file


Groups and variables can also be accessed using `getattr`. Variables can be set with `setattr`::

    getattr(getattr(system_model, 'SolarResource'), 'solar_resource_file')
    setattr(getattr(system_model, 'SolarResource'), 'solar_resource_file', filename)

If the group name isn't known, a variable can be accessed using `value`::

    system_model.value('solar_resource_file')

    filename = 'My_TMY_or_TYA_File'
    # This is how you would assign the variable, solar_resource_file to your own file name.
    system_model.value('solar_resource_file', filename)


The `assign` and `export` functions can be used to work with groups of variables in dictionaries::

    systemDesign = {'azimuth':100, 'gcr': .5}   # ground coverage ratio
    system_model.SystemDesign.assign(systemDesign)
    system_model.SystemDesign.export()

Creating a Simulation from Multiple Modules
*******************************************


Suppose you wish to create a PV Power Purchase Agreement (PPA) single owner
plant simulation. First you go to :doc:`Configs`, where you find the modules you
need for this simulation are Pvwattsv7, and Singleowner in that order.  In this
simple example the values are loaded from the set of default parameters in the
configuration "PVWattsSingleOwner".  The docs listing possible configurations of
the modules are found in the documentation for those :doc:`Models`; for example,
for Pvwattsv7 they are found in :doc:`modules/Pvwattsv7`.  There is a
configuration for each of the types of simulations listed in :doc:`Configs`.

The Singleowner model is created using the `from_existing` function so that it
shares the same underlying data as the
PVwattsv7 model.  This means when the Pvwattsv7 model is executed, the data for
the financial Singleowner model is loaded from its outputs. The execute
functions for each model are called sequentially to do the simulation.::

    import PySAM.Pvwattsv8 as pv
    import PySAM.Singleowner as so

    system_model = pv.default('PVWattsSingleOwner')
    financial_model = so.from_existing(system_model, 'PVWattsSingleOwner')

    filename = 'My_TMY_or_TYA_File'
    system_model.SolarResource.solar_resource_file = filename

    system_model.execute()
    financial_model.execute()

    print(system_model.Outputs.ac_annual, financial_model.Outputs.ppa)


Importing a SAM GUI Case
************************

Entering or changing all the data describing your simulation from default values
can be tedious, and make your python script less readable.  An alternative is to
use the SAM GUI to enter the data, and then to save the inputs as a JSON file.
This file can then be imported into PySAM, making for less tedium.
For an example of how to import the modules and variables from a SAM GUI Case, see :doc:`Import`.


Sizing a PV + Battery system with ReOpt
***************************************

Pvwattsv8 and Pvsamv1 have the option to size and dispatch a StandAloneBattery
or Battwatts model from `ReOpt Lite's <https://developer.nrel.gov/docs/energy-optimization/reopt-v1/>`_ optimization.
The Utilityrate5 model is also required to provide electric tariff
info, and other financial models
such as Cashloan may also be linked to provide financial parameters. The
`Reopt_size_battery_post` function returns
a properly-formatted dictionary of ReOpt inputs that can then be posted to the
`ReOpt Lite's API <https://github.com/NREL/REopt-API-Analysis>`_ as a json string::

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



