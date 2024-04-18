Hybrid Systems
==============

Use the :mod:`PySAM.Hybrids.HybridGenerator` and :mod:`PySAM.Hybrids.HybridSystem` classes for hybrid system models. These classes provide functions for creating 
models with default input values or from JSON, accessing variables, and running simulations.

:mod:`HybridGenerator<PySAM.Hybrids.HybridGenerator>` is the base class for available peformance models. It wraps the PySAM module for each subsystem performance 
model module (Pvwattsv8 or Pvsamv1, Windpower, GenericSystem, Fuelcell, Battery) and provides to the modules' input and output variables.

:mod:`HybridSystem<PySAM.Hybrids.HybridSystem>` contains and organizes the performance and financial models modules and runs simulations. The simulation is executed 
by :mod:`PySAM.Hybrid.Hybrid`.

.. toctree::
    :maxdepth: 1

    hybrids/HybridGenerator.rst
    hybrids/HybridSystem.rst

Available modules
-----------------

The following modules are available for hybrid systems. Use module names like `pv`, `pvwatts`, `wind` as defined by the `HybridSystem` for the hybrid system model 
rather than the PySAM model names like `Pvsamv1`, `Pvwattsv8`, `Windpower`::

    HybridSystem.pv = PVHybrid (PySAM.Pvsamv1)
    HybridSystem.pvwatts = PVWattsHybrid (PySAM.Pvwattsv8)
    HybridSystem.wind = WindHybrid (PySAM.Windpower)
    HybridSystem.gensys = GenericSystemHybrid (PySAM.GenericSystem)
    HybridSystem.battery = BatteryHybrid (PySAM.Battery)
    HybridSystem.fuelcell = FuelCellHybrid (PySAM.Fuelcell)
    HybridSystem._grid = PySAM.Grid
    HybridSystem.singleowner = PySAM.Singleowner
    HybridSystem.utilityrate5 = PySAM.Utilityrate5
    HybridSystem.host_developer = PySAM.HostDeveloper

.. toctree::
    :maxdepth: 1

    hybrids/BatteryHybrid.rst
    hybrids/FuelCellHybrid.rst
    hybrids/GenericSystemHybrid.rst
    hybrids/PVHybrid.rst
    hybrids/PVWattsHybrid.rst
    hybrids/WindHybrid.rst

Accessing and setting variables
--------------------------------

Each hybrid subsystem class contains a PySAM module. Access the subsystem module inputs and outputs from the class. The following example shows different 
methods to access inputs and output variables for a PVWatts Wind Battery / Single Owner hybrid system model.

.. code:: python

    # import the module for each performance model
    import PySAM.Battery as Battery
    import PySAM.Windpower as Windpower
    import PySAM.Pvwattsv8 as Pvwattsv8

    # Create the hybrid system model
    m = HybridSystem([Pvwattsv8, Windpower, Battery], 'singleowner')

    # Method 1: set variable values directly
    # Note the module names "pvwatts" and "wind" as defined by the HybridSystem class,
    # rather than the PySAM module names "Pvwattsv8" and "Windpower".
    m.pvwatts.SystemDesign.system_capacity = 10
    m.wind.Resource.wind_resource_filename = wind_filename

    # Method 2: Use `value()`
    m.pv.value("solar_resource_file", solar_filename)
    m.wind.value("wind_resource_filename", wind_filename)

    # Method 3: Use `assign()`
    resource_file_dict = {
        "pvwattsv8": {"SolarResource": {"solar_resource_file": solar_filename} },
        "windpower": {"Resource": {"wind_resource_filename": wind_filename} }
    }
    m.assign(resource_file_dict)

Creating models
-----------------

Example 1: Create a PVWatts Wind Battery / Single Owner hybrid model from SAM
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Before running the following code, create a hybrid system model in SAM, and use the :ref:`SAM Code Generator <sam_code_generator>` to export inputs from SAM to 
a JSON file using the **JSON for inputs** option. (Do *not* use the **PySAM JSON** option.)

.. code:: python

    import json

    # get performance model for each subsystem
    import PySAM.Pvwattsv8 as pv_model
    import PySAM.Windpower as wind_model
    import PySAM.Battery as battery_model

    # get function for managing hybrid variables and simulations
    from PySAM.Hybrids.HybridSystem import HybridSystem

    # JSON is from SAM code generator for a PVWatts Wind Battery / Host Developer case
    # inputs_file = /path-to-json-file/your-json-from-sam-code-generator.json'

    # store inputs from JSON
    with open(inputs_file, 'r') as f:
        inputs = json.load(f)['input']

    # create the hybrid system model using performance model names as defined by the import statements above
    # use the string 'hostdeveloper' or 'singleowner' for the financial model
    m = HybridSystem([pv_model, wind_model, battery_model], 'hostdeveloper')

    # initialize the model
    m.new()

    # assign inputs to model
    unassigned = m.assign(inputs)

    # run a simulation
    print('running...')
    m.execute()

    # store some outputs
    # be careful to use the correct module names as defined by the HybridSystem() function: 
    #     pv, pvwatts, wind, gensys, battery, fuelcell
    #     _grid, singleowner, utilityrate5, host_developer
    pvannualenergy = m.pvwatts.Outputs.annual_energy
    windannualenergy = m.wind.Outputs.annual_energy
    battrountripefficiency = m.battery.Outputs.average_battery_roundtrip_efficiency
    gridannualenergy = m._grid.SystemOutput.annual_energy
    npv = m.host_developer.Outputs.npv

    # print outputs
    print(pvannualenergy)
    print(windannualenergy)
    print(battrountripefficiency)
    print(gridannualenergy)
    print(npv)

Example 2: Create a Photovoltaic Wind Batterty / Single Owner hybrid model from defaults
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Available default configurations are listed in the documentation for :mod:`default<PySAM.Hybrids.HybridSystem.HybridSystem.default>`

.. code:: python

    # get performance model for each subsystem
    import PySAM.Pvsamv1 as pv_model
    import PySAM.Windpower as wind_model
    import PySAM.Battery as battery_model

    # get function for managing hybrid variables and simulations
    from PySAM.Hybrids.HybridSystem import HybridSystem

    # create the hybrid system model using performance model names as defined by the import statements above
    # use the string 'hostdeveloper' or 'singleowner' for the financial model
    m = HybridSystem([pv_model, wind_model, battery_model], 'singleowner')

    # load defaults from for the Photovoltaid Wind Battery Hybrid / Single Owner configuration
    m.default('PhotovoltaicWindBatteryHybridSingleOwner')

    # assign values to solar and wind resource files (these are not loaded with defaults)
    #solar_resource_path = '/path-to-weather-file/your-solar-weather-file-goes-here.csv'
    #wind_resource_path =  '/path-to-weather-file/your-wind-weather-file-goes-here.csv'

    m.pv.SolarResource.solar_resource_file = str(solar_resource_path)
    m.wind.Resource.wind_resource_filename = str(wind_resource_path)

    # run a simulation
    print('running...')
    m.execute()

    # store some outputs
    # be careful to use the correct module names as defined by the HybridSystem() function: 
    #     pv, pvwatts, wind, gensys, battery, fuelcell
    #     _grid, singleowner, utilityrate5, host_developer
    pvannualenergy = m.pv.Outputs.annual_energy # Outputs group of Pvsamv1 module
    windannualenergy = m.wind.Outputs.annual_energy # Outputs group of Windpower module
    battrountripefficiency = m.battery.Outputs.average_battery_roundtrip_efficiency # Outputs group of Battery module
    gridannualenergy = m._grid.SystemOutput.annual_energy # SystemOutput group of Grid module
    npv = m.singleowner.Outputs.project_return_aftertax_npv # Outputs group of Singleowner module

    # print outputs
    print(pvannualenergy)
    print(windannualenergy)
    print(battrountripefficiency)
    print(gridannualenergy)
    print(npv)