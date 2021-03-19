.. _WindObos:

WindObos
***********************************

Wrapper for SAM Simulation Core model: `cmod_wind_obos.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_wind_obos.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:


Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**WindObos model description**

.. automodule:: PySAM.WindObos
	:members:

Functions
===================================

.. autoclass:: PySAM.WindObos.WindObos
	:members:

Wobos Group
======================================================

.. autoclass:: PySAM.WindObos.WindObos.Wobos
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.WindObos.WindObos.Outputs
	:members:

