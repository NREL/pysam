.. _Singleowner:

Singleowner
**************************

Wrapper for SAM Simulation Core model: `cmod_singleowner.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_singleowner.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Singleowner model description**

.. automodule:: PySAM.Singleowner
	:members:

Functions
=========================

.. autoclass:: PySAM.Singleowner.Singleowner
	:members:

Revenue Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.Revenue
	:members:

FinancialParameters Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.FinancialParameters
	:members:

SystemCosts Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.SystemCosts
	:members:

TaxCreditIncentives Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.TaxCreditIncentives
	:members:

Depreciation Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.Depreciation
	:members:

PaymentIncentives Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.PaymentIncentives
	:members:

BatterySystem Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.BatterySystem
	:members:

ElectricityRates Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.ElectricityRates
	:members:

SystemOutput Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.SystemOutput
	:members:

UtilityBill Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.UtilityBill
	:members:

Lifetime Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.Lifetime
	:members:

FuelCell Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.FuelCell
	:members:

CapacityPayments Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.CapacityPayments
	:members:

GridLimits Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.GridLimits
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.Outputs
	:members:

