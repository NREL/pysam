.. _Grid:

Grid
**************************

Wrapper for SAM Simulation Core model: `cmod_grid.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_grid.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Grid model description**

.. automodule:: PySAM.Grid
	:members:

Functions
=========================

.. autoclass:: PySAM.Grid.Grid
	:members:

Lifetime Group
==============

.. autoclass:: PySAM.Grid.Grid.Lifetime
	:members:

Common Group
==============

.. autoclass:: PySAM.Grid.Grid.Common
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Grid.Grid.Outputs
	:members:

