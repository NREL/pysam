.. _Cashloan:

Cashloan
***********************************

Wrapper for SAM Simulation Core model: `cmod_cashloan.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_cashloan.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Cashloan model description**

.. automodule:: PySAM.Cashloan
	:members:

Functions
===================================

.. autoclass:: PySAM.Cashloan.Cashloan
	:members:

FinancialParameters Group
===================================

.. autoclass:: PySAM.Cashloan.Cashloan.FinancialParameters
	:members:

SystemCosts Group
===================================

.. autoclass:: PySAM.Cashloan.Cashloan.SystemCosts
	:members:

Depreciation Group
===================================

.. autoclass:: PySAM.Cashloan.Cashloan.Depreciation
	:members:

TaxCreditIncentives Group
===================================

.. autoclass:: PySAM.Cashloan.Cashloan.TaxCreditIncentives
	:members:

PaymentIncentives Group
===================================

.. autoclass:: PySAM.Cashloan.Cashloan.PaymentIncentives
	:members:

BatterySystem Group
===================================

.. autoclass:: PySAM.Cashloan.Cashloan.BatterySystem
	:members:

FuelCell Group
===================================

.. autoclass:: PySAM.Cashloan.Cashloan.FuelCell
	:members:

SystemOutput Group
===================================

.. autoclass:: PySAM.Cashloan.Cashloan.SystemOutput
	:members:

Lifetime Group
===================================

.. autoclass:: PySAM.Cashloan.Cashloan.Lifetime
	:members:

ThirdPartyOwnership Group
===================================

.. autoclass:: PySAM.Cashloan.Cashloan.ThirdPartyOwnership
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.Cashloan.Cashloan.Outputs
	:members:

