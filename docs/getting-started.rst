Getting Started
================

To get started using PySAM, install it as described in :doc:`installation`, and then work through Example 1 and Example 2 below to familiarize yourself with how to set up a model with inputs from SAM, and how set up a complete configuration from defaults.

For a general description of PySAM, including the relationship between PySAM, SSC, and SAM, see :doc:`overview`.

There are two ways to approach building a model in PySAM. The first, and the one we recommend, is to build the model in SAM and then export the inputs to use in PySAM as shown in Example 1 below and described in more detail in :doc:`inputs-from-sam`.

The second approach is to create a model from defaults as described in Example 2. This approach does not require running SAM, but makes it harder to troubleshoot when you get unexpected results or errors. For more details on this approach see :doc:`defaults`.

If you are new to PySAM, work through these two examples to familiarize yourself with the process of building models in PySAM before building your own models.

Example 1: Build a Model from SAM
----------------------------------

For this example, you will:

* Create a model in SAM and use the PySAM documentation to identify a compute module's input and output variables.
* Export inputs from SAM to a JSON file.
* Write a Python script to create the model in PySAM and then read and set inputs from JSON, run the model, and get outputs.

If you are new to SAM, download and install it from the SAM website at https://sam.nrel.gov/download.

This example uses SAM's PVWatts -- No Financial configuration to model a photovoltaic system with no financial model. This runs the ``pvwattsv8`` SSC compute module, equivalent to the "Pvwattsv8" compute module in PySAM.

Create a PVWatts model in SAM
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1. Create a PVWatts / No financing case in SAM.

2. On the System Design page, note the **System nameplate capacity** input.

3. On the File menu, click **Inputs browser** and use the search box to find the variable name for the system nameplate capacity input. SAM's `inputs browser <https://samrepo.nrelcloud.org/help/inputs_browser.htm>`_ displays a table of all of the inputs in the case with both the SSC variable name and SAM variable label so you can quickly identify the name of the SSC variable you want to change in your Python script.

4. Click **Simulate** to run a simulation and review results: On the `Data Tables <https://samrepo.nrelcloud.org/help/data.htm>`_ tab, you can see a list of all of the PVWatts outputs. Expand the Single Values section and check the box for the Annual AC output variable.

5. Find the SSC variable name for the "Annual AC output" variable in the documentation for the :doc:`modules/Pvwattsv8` module.

.. tip::

    You can use SAM's `LK script <https://sam.nrel.gov/lk-script.html>`_ editor to find the SSC names of both input and output variables.

Export SAM inputs to JSON
~~~~~~~~~~~~~~~~~~~~~~~~~~

1. On SAM's Case menu, click **Generate code** and choose **PySAM JSON** at the `bottom of the list <https://samrepo.nrelcloud.org/help/sdk.htm>`_. This will create a folder with a JSON file and SSC library files.

2. Open the JSON file in a text editor or web browser that renders JSON and find the system nameplate capacity input variable to confirm that it was exported with the correct value. By default, the JSON file is named *untitled_pvwattsv8.json*.

Write the Python script
~~~~~~~~~~~~~~~~~~~~~~~~

Create a new ``.py`` file for your script and save it in the same folder as the JSON file. This script runs the Pvwattsv8 module twice: Once with the JSON inputs from SAM, and once after modifying the system capacity input. Run the script, and then run SAM to compare the value of the Annual AC variable.

.. code:: python

    import json
    import PySAM.Pvwattsv8 as pv # import the PVWatts module from PySAM

    # create a new instance of the Pvwattsv8 module
    pv_model = pv.new()

    # get the inputs from the JSON file
    with open( 'untitled_pvwattsv8.json', 'r') as f:
            pv_inputs = json.load( f )

    # iterate through the input key-value pairs and set the module inputs
    for k, v in pv_inputs.items():
        if k != 'number_inputs':
            pv_model.value(k, v)

    # run the module
    pv_model.execute()

    # print results
    print('Annual AC output for {capacity:,.2f} kW system is {output:,.0f} kWh.\n'.format(capacity = pv_model.value('system_capacity'), output = pv_model.Outputs.ac_annual) )

    # run PVWatts for a series of nameplate capacities
    capacities = [10, 100, 1000]
    for c in capacities:
        # change the value of the system_capacity input
        pv_model.value('system_capacity',c)
        # run the module
        pv_model.execute()
        # print some results
        print('Annual AC output for {capacity:,.2f} kW system is {output:,.0f} kWh.'.format(capacity = pv_model.value('system_capacity'), output = pv_model.Outputs.ac_annual) )


For the first model run, the results for Annual AC Output in SAM and PySAM should be the same. If they aren't, compare the inputs in the JSON file to those in SAM and make sure the input values are the same. You can also change the system nameplate capacity in SAM to 10, 100, and 1000 kW to verify that PySAM's results are the same as SAM's.

.. note::

    For this simple example, comparing the JSON file to the SAM inputs is reasonable because Pvwattsv8 has a relatively small number of inputs. As you build more complex models, you will find that the modules have more inputs than it is practical to compare manually in this way.

    Also, changing the system nameplate capacity in this way is possible with PVWatts, but not for other performance models including the Detailed PV model and CSP models because of :doc:`interdependent-variables`. For those models, you have to inputs like Number of Strings in Parallel for the Detailed PV model, or Design Turbine Gross Output for the CSP models.

Example 2: Build a Model from Defaults
---------------------------------------

In Example 1, we created a simple model of a photovoltaic system with a single  Pvwattsv8 compute module. In Example 2, we create a model for a complete PVWatts - Single Owner configuration using default input values.

A SAM configuration is a combination of a performance model and financial model that represents a renewable energy project. Each configuration consists of a series of compute modules that must be executed in the correct order.

.. note::

    PySAM defaults do not include the renewable resource data file (solar, wind, wave or tide) from SAM, so when you use set up a configuration from defaults, you must have a weather file ready to use for the simulation. For the example script below, we assume you used SAM's Location and Resource input page to download a weather file for Denver, CO to SAM's default "SAM Downloaded Weather Files" folder. (Some compute modules allow resource data input as a dictionary instead of file, see the module documentation for details.)

See :doc:`defaults` for more details.

.. code:: python

    import os # need this to get user path for weather file

    # import compute modules required for the PVWatts - Single Owner configuration
    import PySAM.Pvwattsv8 as pv
    import PySAM.Grid as gr
    import PySAM.Utilityrate5 as ur
    import PySAM.Singleowner as so

    # create an instance of the Pvwattsv8 module with defaults from the PVWatts - Single Owner configuration
    system_model = pv.default('PVWattsSingleOwner')

    # create instances of the other modules with shared data from the PVwattsv8 module
    grid_model = gr.from_existing(system_model, 'PVWattsSingleOwner')
    utilityrate_model = ur.from_existing(system_model, 'PVWattsSingleOwner')
    financial_model = so.from_existing(system_model, 'PVWattsSingleOwner')

    # use weather file downloaded from SAM as "denver, co", you can replace this with a path to any valid weather file in the SAM CSV format
    filename = os.path.expanduser('~') + '/SAM Downloaded Weather Files/denver_co_39.7385_-104.985_psm3-tmy_60_tmy.csv'
    system_model.SolarResource.solar_resource_file = filename

    # run the modules in the correct order
    system_model.execute()
    grid_model.execute()
    utilityrate_model.execute()
    financial_model.execute()

    # display results
    print( 'Annual AC Output in Year 1 = {:,.3f} kWh'.format( system_model.Outputs.ac_annual ) )
    print( 'Net Present Value = ${:,.2f}'.format(financial_model.Outputs.project_return_aftertax_npv) )
