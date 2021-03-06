.. _Thirdpartyownership:

Thirdpartyownership
***********************************

Wrapper for SAM Simulation Core model: `cmod_thirdpartyownership.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_thirdpartyownership.cpp>`_

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

**Thirdpartyownership model description**

.. automodule:: PySAM.Thirdpartyownership
	:members:

Functions
===================================

.. autoclass:: PySAM.Thirdpartyownership.Thirdpartyownership
	:members:

Depreciation Group
======================================================

.. autoclass:: PySAM.Thirdpartyownership.Thirdpartyownership.Depreciation
	:members:

Financials Group
======================================================

.. autoclass:: PySAM.Thirdpartyownership.Thirdpartyownership.Financials
	:members:

FinancialThirdPartyOwnership Group
======================================================

.. autoclass:: PySAM.Thirdpartyownership.Thirdpartyownership.FinancialThirdPartyOwnership
	:members:

Common Group
======================================================

.. autoclass:: PySAM.Thirdpartyownership.Thirdpartyownership.Common
	:members:

AnnualOutput Group
======================================================

.. autoclass:: PySAM.Thirdpartyownership.Thirdpartyownership.AnnualOutput
	:members:

CashFlow Group
======================================================

.. autoclass:: PySAM.Thirdpartyownership.Thirdpartyownership.CashFlow
	:members:

ElectricityCost Group
======================================================

.. autoclass:: PySAM.Thirdpartyownership.Thirdpartyownership.ElectricityCost
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Thirdpartyownership.Thirdpartyownership.Outputs
	:members:

