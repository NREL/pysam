.. Import:

To import a case from the SAM GUI
*********************************

1: Export from SAM GUI
======================

On the drop-down menu for the case, click **Generate code** then **JSON for inputs**, and export the case inputs to a JSON file.

2: Create each model by wrapping the data
=========================================

For each SSC compute module required for the simulation (see [Configurations and SSC Compute Modules](#configurations-and-ssc-compute-modules) below), create a new PySSC data table and wrap it with the equivalent PySAM class, releasing memory ownership to the newly created instance. Do not call ``PySSC.data_free`` on the data passed to the wrap function!

For example, the following code imports the parameters from a JSON file named _genericsystem_case.json_ that was exported from a Generic System-Single Owner case in SAM, creates a PySSC table for the Generic System and Single Owner SSC compute modules, and then wraps each table in the appropriate PySAM class::

	import json
	import PySAM.GenericSystem as GenericSystem
	import PySAM.Singleowner as Singleowner
	from PySAM.PySSC import *

	ssc = PySSC()
	with open("genericsystem_case.json") as f:
		dic = json.load(f)
		gs_dat = dict_to_ssc_table(dic, "generic_system")
		so_dat = dict_to_ssc_table(dic, "singleowner")
		gs = GenericSystem.wrap(gs_dat)
		so = Singleowner.wrap(so_dat)


For each PySAM class, you can export the parameters to separate dictionaries. This allows the data to be loaded later using ``assign``::

	help(gs.Plant) # descriptions
	gs_params = gs.export()
	so_params = so.export()
	...
	another_gs = GenericSystem.new()
	another_gs.assign(gs_params)
	another_so = Singleowner.new()
	another_so.assign(so_params)

3: Make a sequence of models
============================

Downsteam models require upstream model outputs as inputs. To execute a model, use ``execute(verbosity)`` where 0 indicates minimal messages and 1 produces log messages. All outputs are available in the Outputs group of a PySAM class.::

	gs.execute()
	so.SystemOutput.gen = gs.gen
	... # transfer other variables
	so.execute()
	so.Outputs.export() # as dictionary

For some compute module input parameters, the SAM graphical user interface (GUI) uses equations to calculate the value of the parameter from special GUI inputs that are not passed to the compute module. Other compute module input parameters are used by more than one compute module in the simulation. In some cases, you may need to write additional code to ensure values for these parameters are correctly assigned. We hope to eliminate the need for this additional code in the future. Until then, you can find the SAM GUI equations in the [runtime/ui folder](https://github.com/NREL/SAM/tree/develop/deploy/runtime/ui), and determine compute module inputs from the [SSC source code](https://github.com/nrel/ssc) or using the SDKtool, available as part of the SAM installation as described on the [SAM SDK web page](https://sam.nrel.gov/sdk).

For example, for the Flat Plate PV-Single Owner configuration, the ground coverage ratio (GCR) is used in two ways: It is an input to the Flat Plate PV compute module for self-shading calculations, and also may be used in GUI equations to calculate the land cost component of the total installed cost input to the Single Owner compute module. If your Python code changes the value of ``Pvsamv1.SystemDesign.gcr`` to ``x``, and you are including land cost ``y`` in $/acre in your analysis, you need code like the following adapted from the GUI equations in _runtime/ui/PV System Design.txt_ to ensure the change is accounted for in ``Singleowner.SystemCosts.total_installed_cost``::

	pv.SystemDesign.subarray1_gcr = x
	land_area = pv.CECPerformanceModelWithModuleDatabase.cec_area 
		* (pv.SystemDesign.subarray1_nstrings 
		* pv.SystemDesign.subarray1_modules_per_string) / x * 0.0002471  # m^2 to acres

	# total_installed_cost = total_direct_cost + permitting_total + engr_total + 
	#			grid_total + landprep_total + sales_tax_total + land_total
	# y = land cost in $/acre
	so.SystemCosts.total_installed_cost = cost_without_land + y * land_area


For the same Flat Plate PV-Single Owner configuration, an example of an input that is used by both compute modules is ``analysis_period``. It is used by the Single Owner module as the number of years for the cash flow, and by the Flat Plate PV model for battery lifecycle calculations.
