.. _UiUdpcChecks:

UiUdpcChecks
***********************************

Wrapper for SAM Simulation Core model: `cmod_ui_udpc_checks.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_ui_udpc_checks.cpp>`_

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

**UiUdpcChecks model description**

.. automodule:: PySAM.UiUdpcChecks
	:members:

Functions
===================================

.. autoclass:: PySAM.UiUdpcChecks.UiUdpcChecks
	:members:

UserDefinedPowerCycle Group
======================================================

.. autoclass:: PySAM.UiUdpcChecks.UiUdpcChecks.UserDefinedPowerCycle
	:members:

Common Group
======================================================

.. autoclass:: PySAM.UiUdpcChecks.UiUdpcChecks.Common
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.UiUdpcChecks.UiUdpcChecks.Outputs
	:members:

