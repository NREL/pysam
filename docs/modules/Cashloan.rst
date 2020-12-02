.. _Cashloan:

Cashloan
***********************************

Wrapper for SAM Simulation Core model: `cmod_cashloan.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_cashloan.cpp>`_

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

**Cashloan model description**

.. automodule:: PySAM.Cashloan
	:members:

Functions
===================================

.. autoclass:: PySAM.Cashloan.Cashloan
	:members:

FinancialParameters Group
======================================================

.. autoclass:: PySAM.Cashloan.Cashloan.FinancialParameters
	:members:

SystemCosts Group
======================================================

.. autoclass:: PySAM.Cashloan.Cashloan.SystemCosts
	:members:

Depreciation Group
======================================================

.. autoclass:: PySAM.Cashloan.Cashloan.Depreciation
	:members:

TaxCreditIncentives Group
======================================================

.. autoclass:: PySAM.Cashloan.Cashloan.TaxCreditIncentives
	:members:

PaymentIncentives Group
======================================================

.. autoclass:: PySAM.Cashloan.Cashloan.PaymentIncentives
	:members:

BatterySystem Group
======================================================

.. autoclass:: PySAM.Cashloan.Cashloan.BatterySystem
	:members:

FuelCell Group
======================================================

.. autoclass:: PySAM.Cashloan.Cashloan.FuelCell
	:members:

SystemOutput Group
======================================================

.. autoclass:: PySAM.Cashloan.Cashloan.SystemOutput
	:members:

Lifetime Group
======================================================

.. autoclass:: PySAM.Cashloan.Cashloan.Lifetime
	:members:

ThirdPartyOwnership Group
======================================================

.. autoclass:: PySAM.Cashloan.Cashloan.ThirdPartyOwnership
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Cashloan.Cashloan.Outputs
	:members:

