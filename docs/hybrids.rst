Hybrid Systems
==============

Use the :mod:`PySAM.Hybrids.HybridGenerator` and :mod:`PySAM.Hybrids.HybridSystem` classes for hybrid system models. These classes provide functions for creating 
models with default input values or from JSON, accessing variables, and running simulations.

:mod:`HybridGenerator<PySAM.Hybrids.HybridGenerator>` is the base class for performance model modules that are available for Hybrid systems. It wraps the PySAM 
module for each subsystem module and provides access to the module input and output variables.

:mod:`HybridSystem<PySAM.Hybrids.HybridSystem>` contains and organizes the performance and financial model modules and runs simulations. The simulation is executed 
by :mod:`PySAM.Hybrid.Hybrid`.

.. toctree::
    :maxdepth: 1

    hybrids/HybridGenerator.rst
    hybrids/HybridSystem.rst

Available modules
-----------------

The following modules are available for hybrid systems::

    HybridSystem.pv = PVHybrid (PySAM.Pvsamv1)
    HybridSystem.pvwatts = PVWattsHybrid (PySAM.Pvwattsv8)
    HybridSystem.wind = WindHybrid (PySAM.Windpower)
    HybridSystem.custom = CustomGenerationHybrid (PySAM.CustomGeneration)
    HybridSystem.battery = BatteryHybrid (PySAM.Battery)
    HybridSystem.fuelcell = FuelCellHybrid (PySAM.Fuelcell)

.. note::
	Be careful to use module names like `pv`, `pvwatts`, and `wind` as defined by `HybridSystem` instead of the PySAM module names like `Pvsamv1`, `Pvwattsv8`, and `Windpower`.

.. toctree::
    :maxdepth: 1

    hybrids/BatteryHybrid.rst
    hybrids/FuelCellHybrid.rst
    hybrids/CustomGenerationHybrid.rst
    hybrids/PVHybrid.rst
    hybrids/PVWattsHybrid.rst
    hybrids/WindHybrid.rst

The `Singleowner` and `HostDeveloper` financial models are available for hybrid configurations, along with the intermediate `Grid` and `Utilityrate5` modules::

    HybridSystem._grid = PySAM.Grid
    HybridSystem.singleowner = PySAM.Singleowner
    HybridSystem.utilityrate5 = PySAM.Utilityrate5
    HybridSystem.host_developer = PySAM.HostDeveloper

Accessing and setting variables
--------------------------------

Each hybrid subsystem class contains a PySAM module. Access the subsystem module inputs and outputs from the class. The following example shows different 
methods to access inputs and output variables for a PVWatts Wind Battery / Single Owner hybrid system model.

.. code:: python

	# import the module for each performance model
	import PySAM.Battery as battery_model
	import PySAM.Windpower as wind_model
	import PySAM.Pvwattsv8 as pv_model
	
	# import the hybrid system class
	from PySAM.Hybrids.HybridSystem import HybridSystem
	
	# Create the hybrid system model
	m = HybridSystem([pv_model, wind_model, battery_model], 'singleowner')
	
	# load input values from defaults for the 
	# PVWatts Wind Battery / Single Owner configuration
	# default configuration is for a 100 MW PV system with 80 2.5 MW turbines
	m.default('PVWattsWindBatteryHybridSingleOwner')
	
	# assign values to solar and wind resource files (these are not loaded with defaults)
	solar_resource_path = '/path-to-weather-file/your-solar-weather-file-goes-here.csv'
	wind_resource_path =  '/path-to-weather-file/your-wind-weather-file-goes-here.csv'
	
	m.pvwatts.SolarResource.solar_resource_file = str(solar_resource_path)
	m.wind.Resource.wind_resource_filename = str(wind_resource_path)
	
	# Method 1: set variable values directly for a 8 MW PV system with four 2.5 MW turbines
	# Note the module names "pvwatts" and "wind" as defined by the HybridSystem class,
	# instead of PySAM module names "Pvwattsv8" and "Windpower".
	m.pvwatts.SystemDesign.system_capacity = 8000
	m.wind.Farm.wind_farm_xCoordinates = [0, 800, 1600, 2400]
	m.wind.Farm.wind_farm_yCoordinates = [0, 0, 0, 0]
	m.wind.Farm.system_capacity = 10000
	
	# run a simulation
	m.execute()
	
	# print some outputs
	print(m.pvwatts.Outputs.ac_annual)
	print(m.wind.Outputs.annual_energy)
	
	# Method 2: Use `value()` for a 4 MW PV system with two 2.5 MW turbines
	m.pvwatts.value("system_capacity", 4000)
	m.wind.value("wind_farm_xCoordinates", [0, 800])
	m.wind.value("wind_farm_yCoordinates", [0, 0])
	m.wind.value("system_capacity", 5000)
	
	m.execute()
	
	print(m.pvwatts.value("ac_annual"))
	print(m.wind.value("annual_energy"))
	
	# Method 3: Use `assign()` for a 6 MW PV system with three 2.5 MW turbines
	inputs_dict = {
		"pvwatts": {"SystemDesign": {"system_capacity": 6000} },
		"wind": {"Farm": {"wind_farm_xCoordinates": [0, 800, 1600]} },
		"wind": {"Farm": {"wind_farm_yCoordinates": [0, 0, 0]} }, 
		"wind": {"Farm": {"system_capacity": 7500} }
	}
	m.assign(inputs_dict)
	
	m.execute()
	
	print(m.pvwatts.value("ac_annual"))
	print(m.wind.value("annual_energy"))

Creating models
----------------

Create a hybrid system model by either first creating it in SAM and using the code generator to export inputs as JSON, or by loading defaults for the hybrid configuration
you want to model. 

Example 1: Create a PVWatts Wind Battery / Single Owner hybrid model from SAM
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Before running the following code, create a hybrid system model in SAM, and use the :ref:`SAM Code Generator <sam_code_generator>` to export inputs from SAM to 
a JSON file using the **JSON for inputs** option. (Do *not* use the **PySAM JSON** option.)

.. code:: python

	import json
	
	import PySAM.Pvwattsv8 as pv_model
	import PySAM.Windpower as wind_model
	import PySAM.Battery as battery_model
	
	from PySAM.Hybrids.HybridSystem import HybridSystem
	
	# JSON is from SAM code generator for a PVWatts Wind Battery / Host Developer case
	inputs_file = /path-to-json-file/your-json-from-sam-code-generator.json'
	with open(inputs_file, 'r') as f:
		inputs = json.load(f)['input']
	
	# create the hybrid system model using performance model names as defined by the import statements above
	# use the string 'hostdeveloper' or 'singleowner' for the financial model
	m = HybridSystem([pv_model, wind_model, battery_model], 'hostdeveloper')
	m.new()

	unassigned = m.assign(inputs) # returns a list of unassigned variables if any
	print(unassigned)
	
	# run a simulation
	m.execute()
	
	# store some outputs
	# be careful to use the correct module names as defined by the HybridSystem() function: 
	#     pv, pvwatts, wind, custom, battery, fuelcell
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
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Names of configurations available for hybrid systems are listed in the documentation for :mod:`default<PySAM.Hybrids.HybridSystem.HybridSystem.default>`

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
	
	# load defaults for the Photovoltaid Wind Battery Hybrid / Single Owner configuration
	m.default('PhotovoltaicWindBatteryHybridSingleOwner')
	
	# assign values to solar and wind resource files (these are not loaded with defaults)
	solar_resource_path = '/path-to-weather-file/your-solar-weather-file-goes-here.csv'
	wind_resource_path =  '/path-to-weather-file/your-wind-weather-file-goes-here.csv'
	
	m.pv.SolarResource.solar_resource_file = solar_resource_path
	m.wind.Resource.wind_resource_filename = wind_resource_path
	
	# run a simulation
	print('running...')
	m.execute()
	
	# store some outputs
	# be careful to use the correct module names as defined by the HybridSystem() function: 
	#     pv, pvwatts, wind, custom, battery, fuelcell
	#     _grid, singleowner, utilityrate5, host_developer
	pvannualenergy = m.pv.Outputs.annual_energy
	windannualenergy = m.wind.Outputs.annual_energy
	battrountripefficiency = m.battery.Outputs.average_battery_roundtrip_efficiency
	gridannualenergy = m._grid.SystemOutput.annual_energy
	npv = m.singleowner.Outputs.project_return_aftertax_npv
	
	# print outputs
	print(pvannualenergy)
	print(windannualenergy)
	print(battrountripefficiency)
	print(gridannualenergy)
	print(npv)