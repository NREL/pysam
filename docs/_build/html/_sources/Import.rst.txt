.. Import:

To import a case from the SAM GUI
*********************************

Export from SAM GUI
======================

On the drop-down menu for the case, click **Generate code** then 
**JSON for inputs**, and export the case inputs to a JSON file. 
This file will have the case name as the file prefix, with the
suffix being ".json".

Move the data into the appropriate PySAM Module Classes
=======================================================

For each SSC compute module required for the simulation (see :doc:`Configs`), create a new PySSC data table and wrap it with the equivalent PySAM class, releasing memory ownership to the newly created instance. Do not call ``PySSC.data_free`` on the data passed to the wrap function!

Example
^^^^^^^
Suppose we wish to make a python script that replicates the
simulation SAM does for a PVWatts Distributed Commercial installation.  We go to  :doc:`Configs` where we find that the three modules we need are *pvwatts7*, *utilityrate5*, and *cashloan*, in that order.  In our python script, we import the modules, ``json`` (because we are reading a JSON file), the three modules for our simulation, and ``PySSC`` which is used to move the data into the proper classes.
::
    import json
    import PySAM.Pvwattsv7 as PVWatts
    import PySAM.Utilityrate5 as UtilityRate
    import PySAM.Cashloan as Cashloan
    import PySAM.PySSC as pssc
    
    ssc = pssc.PySSC() 
    
The json file you exported from the SAM GUI is then loaded.  Make sure to change the name to that of the file you exported.
::  
    
    json_file_path = 'pvwattsdistcomm.json' 
    with open(json_file_path) as f:
            dic = json.load(f)
The next three lines make data structures for the models listed.
::
    pv_dat = pssc.dict_to_ssc_table(dic, "pvwattsv7")
    ur_dat = pssc.dict_to_ssc_table(dic, "utilityrate5")
    cl_dat = pssc.dict_to_ssc_table(dic, "cashloan")

Next we move that data into the model classes, starting with the
first one to be executed, and then basing the subsequent ones on
that one, so their inputs will fill with the outputs of the 
previously run modules.
::
    pv = PVWatts.wrap(pv_dat)  
    ur = UtilityRate.from_existing(pv, 'PVWattsCommercial')
    cl = Cashloan.from_existing(pv, 'PVWattsCommercial')
    ur.assign(UtilityRate.wrap(ur_dat).export())
    cl.assign(Cashloan.wrap(cl_dat).export())
    


Execute the sequence of models
=================================

Downsteam models require upstream model outputs as inputs. Since the underlying data between `pv`, `ur` and `cl` are shared
due to the `from_existing` function, the outputs of `pv` required as inputs to `ur` and `cl` will automatically be accessible to them.
To execute a model, use ``execute(verbosity)`` where 0 indicates minimal messages and 1 produces log messages.
All outputs are available in the Outputs group of a PySAM class.

Example (Continued)
^^^^^^^^^^^^^^^^^^^
Here we continue our example.
::
    pv.execute()
    ur.execute()
    cl.execute()
    
We can then print out some of the data.  The variable and group names are found in the :doc:`Models`.
::    
    print('ac_annual: ', pv.Outputs.ac_annual)
    print('ur_ec_tou_mat: ', ur.ElectricityRates.ur_ec_tou_mat)
    print('cl.Outputs.npv: ', cl.Outputs.npv)

Possible Problems
^^^^^^^^^^^^^^^^^
You probably noticed that in SAM, there are black and blue input variables.  The blue ones are calculated by the SAM GUI from the black ones.  For some compute module input parameters the SAM graphical user interface (GUI) uses equations to calculate the value
of the parameter from special GUI inputs that are not passed to the compute module. Other compute module input parameters
are used by more than one compute module in the simulation. In some cases, you may need to write additional code to ensure
values for these parameters are correctly assigned. We hope to eliminate the need for this additional code in the future.

In each PySAM Module's page, each variable that may be affected by such equations will have a
"Changes to this variable may require updating the values of the following" and
"This variable may need to be updated if the values of the following have changed" section to provide suggestions for
which variables may be affected upstream or downstream.

For greatest detail, you can find the SAM GUI equations in the `runtime/ui folder <https://github.com/NREL/SAM/tree/develop/deploy/runtime/ui>`_,
and determine compute module inputs from the `SSC source code <https://github.com/nrel/ssc>`_ or using the SDKtool,
available as part of the SAM installation as described on the `SAM SDK web page <https://sam.nrel.gov/sdk>`_.

For example, for the Flat Plate PV-Single Owner configuration, the ground coverage ratio (GCR) is used in two ways:
It is an input to the Flat Plate PV compute module for self-shading calculations, and also may be used in GUI equations
to calculate the land cost component of the total installed cost input to the Single Owner compute module.
If your Python code changes the value of ``Pvsamv1.SystemDesign.gcr`` to ``x``, and you are including land cost ``y``
in $/acre in your analysis, you need code like the following adapted from the GUI equations in 
`runtime/ui/PV System Design.txt <https://github.com/NREL/SAM/blob/develop/deploy/runtime/ui/PV%20System%20Design.txt>`_
to ensure the change is accounted for in ``Singleowner.SystemCosts.total_installed_cost``::

	pv.SystemDesign.subarray1_gcr = x
	land_area = pv.CECPerformanceModelWithModuleDatabase.cec_area
		* (pv.SystemDesign.subarray1_nstrings
		* pv.SystemDesign.subarray1_modules_per_string) / x * 0.0002471  # m^2 to acres

	# total_installed_cost = total_direct_cost + permitting_total + engr_total +
	#			grid_total + landprep_total + sales_tax_total + land_total
	# y = land cost in $/acre
	so.SystemCosts.total_installed_cost = cost_without_land + y * land_area



