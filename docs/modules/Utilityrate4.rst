.. _Utilityrate4:

Utilityrate4
***********************************

Wrapper for SAM Simulation Core model: `cmod_utilityrate4.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_utilityrate4.cpp>`_

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

**Utilityrate4 model description**

.. automodule:: PySAM.Utilityrate4
	:members:

Functions
===================================

.. autoclass:: PySAM.Utilityrate4.Utilityrate4
	:members:

Common Group
======================================================

.. autoclass:: PySAM.Utilityrate4.Utilityrate4.Common
	:members:

TimeSeries Group
======================================================

.. autoclass:: PySAM.Utilityrate4.Utilityrate4.TimeSeries
	:members:

Financials Group
======================================================

.. autoclass:: PySAM.Utilityrate4.Utilityrate4.Financials
	:members:

AnnualOutput Group
======================================================

.. autoclass:: PySAM.Utilityrate4.Utilityrate4.AnnualOutput
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Utilityrate4.Utilityrate4.Outputs
	:members:

