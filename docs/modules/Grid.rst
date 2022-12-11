.. _Grid:

Grid
=====

.. automodule:: PySAM.Grid
	:members:

Grid is a wrapper for the SSC compute module `cmod_grid.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_grid.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

- None

Functions
-----------

.. autoclass:: PySAM.Grid.Grid
	:members:

Lifetime Group
---------------

.. autoclass:: PySAM.Grid.Grid.Lifetime
	:members:

SystemOutput Group
-------------------

.. autoclass:: PySAM.Grid.Grid.SystemOutput
	:members:

Load Group
-----------

.. autoclass:: PySAM.Grid.Grid.Load
	:members:

GridLimits Group
-----------------

.. autoclass:: PySAM.Grid.Grid.GridLimits
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.Grid.Grid.Outputs
	:members:

