Accessing SAM Defaults
=======================

When you create a case in SAM, it loads default values for all of the inputs in the case. These defaults are stored in files that come with the SAM installation, and are updated with each version of SAM to reflect market and industry conditions at the time of the software release. This default data is also accessible from PySAM.

The ``default()`` function loads a compute module's defaults for a given configuration. Use it with the ``from_existing()`` function to load defaults for a set of compute modules to build a complete configuration.

For example, to load defaults for the Detailed PV-Battery -- Commercial configuration, first, refer to :doc:`sam-configurations` to identify the list of compute modules you need to import for the configuration. Then use ``default()`` to initialize the first compute module in the list and load its defaults, and  ``from_existing()`` to load the defaults for the remaining modules:

.. code:: python

    import PySAM.Pvsamv1 as pv
    import PySAM.Grid as gr
    import PySAM.Utilityrate5 as ur
    import PySAM.Cashloan as co

    system_model = pv.default('PVBatteryCommercial')

    grid_model = gr.from_existing(system_model, 'PVBatteryCommercial')
    utilityrate_model = ur.from_existing(system_model, 'PVBatteryCommercial')
    financial_model = so.from_existing(system_model, 'PVBatteryCommercial')

The ``from_existing()`` function ensures that any data that the different modules share is consistent. In this case, for example, ``gen`` is both a member of the ``Outputs`` group of ``Pvsamv1`` and of the ``SystemOutput`` group of ``Cashloan``, and we want to ensure that the two variables have the same value.

To work with defaults in PySAM, you need to know the list of compute modules for the configuration and the configuration name for defaults. You can find this information in :doc:`sam-configurations`.

For SAM versions after SAM 2021.12.02 Revision 2, SAM loads defaults from JSON files that come with the SAM installation. As an alternative to the method described here, you could read the defaults directly from those JSON files, which are in the SAM installation folder on your computer at ``path/to/sam/version/runtime/defaults``. You can also find current development versions of the files are available on the `SAM GitHub repository <https://github.com/NREL/SAM/tree/develop/deploy/runtime/defaults>`_.

.. note::
    Because of the way the weather file path is stored in SAM, when you build a configuration by loading defaults, you have to explicitly set its value to a valid path on your computer. The group name and variable that stores the weather file path is different for different compute modules. Use the :doc:`ssc-modules` to find the group and variable name for your compute module's weather file path.

.. warning::
    When you change the value of an input after loading the defaults, you must check that its value is not dependent on other inputs, or that other input values are not dependent on the one you are changing. If the input you are changing is listed in the Interdependent Variables list in the compute module's documentation, search the documentation page to find interdependent inputs. See :doc:`interdependent-variables` for more details and examples.

The following code finishes the example above by setting the weather file for the Detailed PV model, running a simulation, and displaying results you can compare to SAM's results.

.. code:: python

    import PySAM.Pvsamv1 as pv
    import PySAM.Grid as gr
    import PySAM.Utilityrate5 as ur
    import PySAM.Cashloan as co

    print('Loading defaults...')
    system_model = pv.default('FlatPlatePVCommercial')
    grid_model = gr.from_existing(system_model,'FlatPlatePVCommercial')
    utilityrate_model = ur.from_existing(system_model,'FlatPlatePVCommercial')
    financial_model = co.from_existing(system_model,'FlatPlatePVCommercial')

    # path to small collection of default weather files that come with SAM
    # edit and set as needed for Windows, Mac, Linux
    wf_paths = ['C:\\SAM\\2021.12.02r1\\solar_resource\\',
     '/home/Applications/SAM_2021.12.02r1/SAM.app/Contents/solar_resource/',
    '/home/sam/2021.12.02.r1/solar_resource/']
    wf_name = 'phoenix_az_33.450495_-111.983688_psmv3_60_tmy.csv' # default for PV - Commercial configurations

    # for wf_paths 0 = windows, 1=mac, 2=linux as defined above
    filename = wf_paths[0] + wf_name
    system_model.SolarResource.solar_resource_file = filename

    print('Simulating...')
    system_model.execute()
    grid_model.execute()
    utilityrate_model.execute()
    financial_model.execute()

    print('Done.')
    print(system_model.value('annual_energy'))
    print(financial_model.Outputs.npv)
