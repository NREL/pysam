.. _Utilityrate2:

Utilityrate2
***********************************

Wrapper for SAM Simulation Core model: `cmod_utilityrate2.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_utilityrate2.cpp>`_

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

**Utilityrate2 model description**

.. automodule:: PySAM.Utilityrate2
	:members:

Functions
===================================

.. autoclass:: PySAM.Utilityrate2.Utilityrate2
	:members:

Common Group
======================================================

.. autoclass:: PySAM.Utilityrate2.Utilityrate2.Common
	:members:

AnnualOutput Group
======================================================

.. autoclass:: PySAM.Utilityrate2.Utilityrate2.AnnualOutput
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Utilityrate2.Utilityrate2.Outputs
	:members:

