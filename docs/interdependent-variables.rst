Interdependent Variables
=========================

Some variables are inputs to a compute module and are not interdependent on other variables. For example, the value of the :doc:`modules/Pvwattsv8` module input ``array_type`` does not depend on any other input variable, and its value does not affect the value of any other input.

An input is an interdependent variable if either its value depends on the value of one or more other inputs, or its value affects the value of one or more other inputs.

For example, the :doc:`modules/Pvsamv1` module's ``system_capacity`` input depends on ``subarray1_modules_per_string`` and ``subarray1_nstrings`` among other inputs because the photovoltaic system capacity is calculated from the number of modules in the array. Similarly, several inputs depend on the value of the ``inv_ds_paco`` input, including ``inv_pd_pdco`` because the inverter's rated DC power is calculated from its rated AC power and nominal efficiency.

Finding Relationships between Variables
----------------------------------------

Use the following resources to identify the relationship between interdependent variables:

* In SAM's user interface, blue "calculated values" indicate interdependent variables, and `SAM's Help system <https://sam.nrel.gov/help>`_ includes descriptions of many of the relationships with equations.

* The code for the calculated values in SAM's user interface is in the ``runtime/ui`` folder of the SAM installation on your computer, and also available `on GitHub <https://github.com/NREL/SAM/tree/develop/deploy/runtime/ui>`_.

* The SDKtool application that comes with SAM has a Module Browser that you can use to explore SSC compute modules. Its script editor is also useful for testing code. Learn more on the `SAM Software Development Kit (SDK) page of the SAM website <https://sam.nrel.gov/sdk>`_.

* The compute module documentation accessible from :doc:`ssc-modules` includes lists of interdependent variables: All of a module's interdependent variables are listed at the top of the module's page, and the description of each variable includes a list of any interdependent variables.

* Ask for help from the SAM team: :doc:`getting-help`.

Calculated Values in SAM
-------------------------

SAM's user interface displays "calculated values" in blue boxes that you cannot edit. A calculated value may be:

* A compute module input calculated from other inputs. For example, the **Nameplate DC capacity** calculated value on the Detailed PV model's System Design page is the :doc:`modules/Pvsamv1` input ``system_capacity``, which is calculated from the module nameplate capacity, along with the modules per string in subarray and strings in parallel in subarray for each enabled subarray.

* A value copied from a different page and shown for reference that may or may not be an input to a compute module. For example, on Detailed PV model's System Design page, under **Electrical Sizing Information**, the inverter maximum DC voltage, minimum MPPT voltage, and maximum MPPT voltage are values copied from the Inverter page. These values are shown to help you determine the correct number of strings in parallel for each subarray.

* A value shown for information that is not an input to a compute module. For example, the Detailed PV model's System Design page shows the total number of modules in each subarray, which is not an input to any compute module. The value is shown to help you see how large the array is.

.. note::

    Calculated values in SAM may not be SSC inputs. See :doc:`variables-sam` for information about how to use SAM to find SSC variables.

.. note::

    For some compute modules, including TroughPhysical and Tscmoltensalt, the equations in the user interface used for calculated values have been migrated to SSC eliminating the problem of interdependent variables for those modules. NREL is working to migrate equations for other modules for future versions of SAM and PySAM.

Examples
---------

These examples are for the Pvsamv1 module, but you can use similar techniques for other modules.

Pvsamv1 System Nameplate Capacity
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The `system_capacity` input to the :doc:`modules/Pvsamv1` module is an example of an interdependent variable. The module documentation shows that its value depends on several variables, including ``subarray1_nstrings``. To explore this interdependence, we created a default Photovoltaic -- No Financial case in SAM, and experimented with doubling the size of the system by doubling the values of **Strings in parallel in subarray** and **Number of inverters**,  noting how the calculated value **Nameplate DC capacity** changes: Doubling the number of strings doubles the system capacity as we would expect. However, if you try this with PySAM, you will note that ``system_capacity`` does not change when you change ``subarray1_nstrings``.

We used the following information to figure out why:

* Lists of interdependent variables in :doc:`modules/Pvsamv1`.

* The `Help topic <https://samrepo.nrelcloud.org/help/pv_system_design.htm>`_ for SAM's System Design page.

* SAM `user interface equations <https://github.com/NREL/SAM/blob/develop/deploy/runtime/ui/PV%20System%20Design.txt#L7273>`_ for the System Design page.

And then, based on what we learned, wrote the following test script:

.. code:: python

    import os
    import PySAM.Pvsamv1 as pv
    import PySAM.Grid as gr

    # calculate Pvsamv1 system_capacity for array with one subarray
    def pv_capacity_calc():
        v_mp = system.value('cec_v_mp_ref')
        i_mp = system.value('cec_i_mp_ref')
        n_modules_per_string = system.value('subarray1_modules_per_string')
        n_strings = system.value('subarray1_nstrings')
        return v_mp * n_modules_per_string * i_mp * n_strings * 0.001

    # print inputs and outputs to demonstrate results
    def print_results():
        print('subarray1_nstrings = ', system.value('subarray1_nstrings'))
        print('inverter_count = ', system.value('inverter_count'))
        print('system_capacity = ', system.value('system_capacity'))
        print('calculated system_capacity = ', pv_capacity_calc())
        print('Outputs.annual_energy = ', system.Outputs.annual_energy)
        print('Outputs.capacity_factor output = ', system.Outputs.capacity_factor)
        print()

    system = pv.default('FlatPlatePVNone')
    grid = gr.from_existing(system,'FlatPlatePVNone')

    # use weather file downloaded from SAM as "denver, co", you can replace this with a path to any valid weather file in the SAM CSV format
    filename = os.path.expanduser('~') + '/SAM Downloaded Weather Files/denver_co_39.7385_-104.985_psm3-tmy_60_tmy.csv'
    system.SolarResource.solar_resource_file = filename

    # default system capacity and annual energy
    print('\n** defaults **')
    system.execute()
    print_results()

    # double system capacity by doubling value of strings in parallel and number of inverters
    print('** double number of strings and inverters without recalculating system_capacity **')
    system.value('subarray1_nstrings',6.0)
    system.value('inverter_count',2.0)
    system.execute()
    print_results()
    print('  capacity_factor doubles because we did not recalculate system_capacity!!\n')

    # recalculate and set system_capacity
    print('** recalculate system capacity **')
    system.value('subarray1_nstrings',6.0)
    system.value('inverter_count',2.0)
    system.value('system_capacity',pv_capacity_calc())
    system.execute()
    print_results()


Pvsamv1 Ground Coverage Ratio (GCR)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The ground coverage ratio (GCR) is used in two ways by the Pvsamv1 compute module when it is paired with the :doc:`modules/Singleowner` financial model for the Detailed PV -- Single Owner configuration. It used by :doc:`modules/Pvsamv1` for self-shading calculations, and in user interface equations to calculate the land area for :doc:`modules/Singleowner` land-related installation and operating costs. If your Python code changes the value of ``Pvsamv1.SystemDesign.gcr`` to ``x``, and you are including land cost ``y`` in $/acre in your analysis, you need code like the following adapted from the equations for SAM's user interface in
`runtime/ui/PV System Design.txt <https://github.com/NREL/SAM/blob/446d70d8bbf22f950e2613821a9f6490a7e61f72/deploy/runtime/ui/PV%20System%20Design.txt#L7457>`_ to ensure the change is accounted for in ``Singleowner.SystemCosts.total_installed_cost``:

::

	pv.SystemDesign.subarray1_gcr = x
	land_area = pv.CECPerformanceModelWithModuleDatabase.cec_area
		* (pv.SystemDesign.subarray1_nstrings
		* pv.SystemDesign.subarray1_modules_per_string) / x * 0.0002471  # m^2 to acres

	# total_installed_cost = total_direct_cost + permitting_total + engr_total +
	#			grid_total + landprep_total + sales_tax_total + land_total
	# y = land cost in $/acre
	so.SystemCosts.total_installed_cost = cost_without_land + y * land_area
