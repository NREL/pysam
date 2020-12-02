.. _Grid:

Grid
***********************************

Wrapper for SAM Simulation Core model: `cmod_grid.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_grid.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdepedent but the equations accounting for these
interdependencies that enforce consistency among these input parameters are not available in the PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:


Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**Grid model description**

.. automodule:: PySAM.Grid
	:members:

Functions
===================================

.. autoclass:: PySAM.Grid.Grid
	:members:

Lifetime Group
======================================================

.. autoclass:: PySAM.Grid.Grid.Lifetime
	:members:

GridLimits Group
======================================================

.. autoclass:: PySAM.Grid.Grid.GridLimits
	:members:

SystemOutput Group
======================================================

.. autoclass:: PySAM.Grid.Grid.SystemOutput
	:members:

Load Group
======================================================

.. autoclass:: PySAM.Grid.Grid.Load
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Grid.Grid.Outputs
	:members:

