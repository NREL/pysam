.. _Annualoutput:

Annualoutput
***********************************

Wrapper for SAM Simulation Core model: `cmod_annualoutput.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_annualoutput.cpp>`_

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

**Annualoutput model description**

.. automodule:: PySAM.Annualoutput
	:members:

Functions
===================================

.. autoclass:: PySAM.Annualoutput.Annualoutput
	:members:

AnnualOutput Group
======================================================

.. autoclass:: PySAM.Annualoutput.Annualoutput.AnnualOutput
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Annualoutput.Annualoutput.Outputs
	:members:

