PySAM Functions
================

.. note::
    This section is a draft to be revised and expanded.

``new()``
    Create an instance with empty attributes.

``default(config)``
    Populate a compute module's attributes with default values for the configuration name ``config``.

``from_existing(compute-module, config-optional)``
    Share underlying data with a PySAM object ``compute-module`` that was created using either ``default()`` or another ``from_existing()``. If ``config-optional`` is provided, loads defaults for the named configuration.

``wrap()``
    Allows compatibility with PySSC, for details, refer to :doc: PySSC <PySSC>`.
