.. _HybridGenerator:

HybridGenerator
===============

.. py:class:: PySAM.Hybrids.HybridGenerator.HybridGenerator(pysam_module)

    Class that wraps around PySAM technology modules as a component of a :mod:`HybridSystem<PySAM.Hybrids.HybridSystem.HybridSystem>`. 

    All hybrid subsystem models require cost inputs that are added as properties here (e.g. om_fixed)

    The PySAM model contains the simulation data for the hybrid simulation, which are modified simlarly to how they are for PySAM
    modules: `value`, `assign`, direct access, and `export`.

    The subsystem model data is copied to and from the :mod:`HybridSystem<PySAM.Hybrids.HybridSystem.HybridSystem>` during execution.

    .. py:function:: new() -> HybridGenerator

    .. py:function:: default(config) -> HybridGenerator

        Load defaults for the configuration config. Available configurations depend on the technology

    .. py:function:: value(name, value=None) -> None | float | dict | sequence | str

        Get or set by name a value in any of the variable groups.

    .. py:function:: assign(input_dict) -> dict

        Assign attributes from nested dictionary, except for Outputs::

            nested_dict = { 'Solar Resource': { var: val, ...}, ...}

        Returns list of variables that weren't assigned

    .. py:function:: export() -> dict

        Export attributes into nested dictionary

    .. py:property:: total_installed_cost

        Total installed cost for technology [$]

        :type: float

    .. py:property:: om_fixed

        Fixed O&M annual amount [$/year]

        :type: sequence

    .. py:property:: om_fixed_escal

        Fixed O&M escalation [%/year]

        :type: float

    .. py:property:: om_production

        Production-based O&M amount [$/MWh]

        :type: sequence

    .. py:property:: om_production_escal

        Production-based O&M escalation [%/year]

        :type: float

    .. py:property:: om_capacity

        Capacity-based O&M amount [$/kWcap]

        :type: sequence

    .. py:property:: om_capacity_escal

        Capacity-based O&M escalation [%/year]

        :type: float

    .. py:property:: degradation

        Annual AC degradation [%]. If not provided, defaults to [0]

        :type: sequence
