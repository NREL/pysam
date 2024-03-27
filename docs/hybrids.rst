Hybrid Systems
==============

Hybrid Systems are simulated in PySAM using the :mod:`PySAM.Hybrids.HybridGenerator` and :mod:`PySAM.Hybrids.HybridSystem` classes.


:mod:`HybridGenerator<PySAM.Hybrids.HybridGenerator>` is the base class for all subsystem technologies (e.g. PV, wind, battery).
This class wraps the PySAM module for the subsystem technology (e.g. PVWattsv8 or Pvsamv1, Windpower, and Battery) to provide access for the input and output data.


:mod:`HybridSystem<PySAM.Hybrids.HybridSystem>` is the class that contains and organizes all the subsystem technologies and financial models for simulation.
The simulation is executed by :mod:`PySAM.Hybrid.Hybrid`.

.. toctree::
    :maxdepth: 1

    hybrids/HybridGenerator.rst
    hybrids/HybridSystem.rst

Available technologies
--------------------------------

Currently only the following technologies are enabled for simulation as part of a hybrid system::

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

Each of the subsystem classes contains a PySAM module whose data can be accessed directly from the class.

For instance, for a hybrid system with PVWatts, Wind, Battery and SingleOwner, the input and output data can be accessed in the following ways::

    import PySAM.Battery as Battery
    import PySAM.Windpower as Windpower
    import PySAM.Pvwattsv8 as Pvwattsv8

    m = HybridSystem([Pvwattsv8, Windpower, Battery], 'singleowner')

    # set directly
    m.pvwatts.SolarResource.solar_resource_file = filename
    m.wind.Resource.wind_resource_filename = wind_filename

    # set using `value`
    m.pv.value("solar_resource_file", filename)

    # set using `assign`
    resource_file_dict = {
        "pvwattsv8": {"SolarResource": {"solar_resource_file": filename} },
        "windpower": {"Resource": {"wind_resource_filename": wind_filename} }
    }
    m.assign(resource_file_dict)


Creating models
-----------------


Starting from GUI
~~~~~~~~~~~~~~~~~

Use the :ref:`SAM Code Generator <sam_code_generator>` to generate inputs via the "JSON for inputs" option.

Then load the inputs via :mod:`assign<PySAM.Hybrids.HybridSystem.HybridSystem.assign>`::

    inputs_file = test_dir / "PVWatts Wind Battery Hybrid_Single Owner.json"
    with open(inputs_file, "r") as f:
        inputs = json.load(f)['input']

    m = HybridSystem([Pvwattsv8, Windpower, Battery], 'singleowner')
    m.new()
    unassigned = m.assign(inputs)


Using defaults
~~~~~~~~~~~~~~~

Available default configurations are listed in the documentation for :mod:`default<PySAM.Hybrids.HybridSystem.HybridSystem.default>`

.. code:: python

    import PySAM.Pvsamv1 as Pvsamv1

    m = HybridSystem([Pvsamv1, Windpower, Battery], 'singleowner')
    m.default("PhotovoltaicWindBatteryHybridSingleOwner")
