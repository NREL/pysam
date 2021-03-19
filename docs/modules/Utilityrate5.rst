.. _Utilityrate5:

Utilityrate5
***********************************

Wrapper for SAM Simulation Core model: `cmod_utilityrate5.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_utilityrate5.cpp>`_

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

**Utilityrate5 model description**

.. automodule:: PySAM.Utilityrate5
	:members:

Functions
===================================

.. autoclass:: PySAM.Utilityrate5.Utilityrate5
	:members:

ElectricityRates Group
======================================================

.. autoclass:: PySAM.Utilityrate5.Utilityrate5.ElectricityRates
	:members:

Lifetime Group
======================================================

.. autoclass:: PySAM.Utilityrate5.Utilityrate5.Lifetime
	:members:

SystemOutput Group
======================================================

.. autoclass:: PySAM.Utilityrate5.Utilityrate5.SystemOutput
	:members:

Load Group
======================================================

.. autoclass:: PySAM.Utilityrate5.Utilityrate5.Load
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Utilityrate5.Utilityrate5.Outputs
	:members:

