Working with Variables
=======================

A compute module's input and output variables are organized into groups. You can find group names and other information about variables in the documentation of each compute module in :doc:`ssc-modules`.

The following code examples show how to get and set a variable's value, and how to work with groups.

For these examples, first import and create an instance of the :doc:`modules/Pvwattsv8` module with default values for the PVWatts -- No Financial configuration:

.. code:: python

    import PySAM.Pvwattsv8 as pv

    system_model = pv.default('PVWattsNone')

Get a variable's value
-----------------------

There are three ways to get a variables value:

1. Access variables directly with ``<class>.<subclass>.<variable>``.

    For example, to get the value of ``array_type`` variable, which is in the ``SystemDesign`` group:

    .. code:: python

        x = system_model.SystemDesign.array_type
        print(x)

2. Use the get attributes function ``getattr()``:

    .. code:: python

        group_object = getattr(system_model,'SystemDesign')
        variable = getattr(group_object,'array_type')
        print(group_object)
        print(variable)

        # equivalent with one line of code
        print( getattr(getattr(system_model, 'SystemDesign'), 'array_type') )

3. Use ``value()``, which does not require the group name:

    .. code:: python

        x = system_model.value('array_type')
        print(x)

Set a variable value
---------------------

1. Use ``setattr()``:

    .. code:: python

        old_array_type = system_model.SystemDesign.array_type
        new_array_type = 0

        system_design_group_object = getattr(system_model,'SystemDesign')
        setattr(system_design_group_object, 'array_type', new_array_type )

        print(old_array_type)
        print(system_model.SystemDesign.array_type)


2. Use ``value()``:

    .. code:: python

        old_array_type = system_model.SystemDesign.array_type
        new_array_type = 0

        system_model.value('array_type', new_array_type);

        print(old_array_type)
        print(system_model.SystemDesign.array_type)

Get and Set Variable Values by Group
-------------------------------------

Use the ``assign()`` and ``export()`` functions to work with groups.

To get a dictionary of all variables in a group, use ``export()``:

.. code:: python

    x = system_model.SystemDesign.export()
    print(x)

Use ``assign()`` to set variable values by group. For example, this code first uses ``export()`` to get a dictionary ``x`` of variables in the ``SystemDesign`` group so you can see what the group variables and values are. It then uses ``assign()`` to change the value of the ``azimuth`` and ``gcr`` variables in that group, and gets a new dictionary ``y``:

.. code:: python

    x = system_model.SystemDesign.export()
    print(x)

    inputs_to_change = {'azimuth':100, 'gcr': .5}
    system_model.SystemDesign.assign(inputs_to_change)

    y = system_model.SystemDesign.export()
    print(y)
