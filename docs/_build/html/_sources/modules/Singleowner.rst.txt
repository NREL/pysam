.. _Singleowner:

Singleowner Module
**************************

Wrapper for SAM Simulation Core model: `cmod_singleowner.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_singleowner.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`PySSC`.

**Singleowner model description**

.. automodule:: PySAM.Singleowner
	:members:

Functions
=========================

.. autoclass:: PySAM.Singleowner.Singleowner
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

PaymentIncentives Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.PaymentIncentives
	:members:

Battery Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.Battery
	:members:

SystemOutput Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.SystemOutput
	:members:

UtilityBill Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.UtilityBill
	:members:

ReturnOnEquity Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.ReturnOnEquity
	:members:

Moratorium Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.Moratorium
	:members:

Recapitalization Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.Recapitalization
	:members:

TimeOfDelivery Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.TimeOfDelivery
	:members:

ReserveAccounts Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.ReserveAccounts
	:members:

Depreciation Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.Depreciation
	:members:

SalvageValue Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.SalvageValue
	:members:

SolutionMode Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.SolutionMode
	:members:

PPAPrice Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.PPAPrice
	:members:

ConstructionFinancing Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.ConstructionFinancing
	:members:

ProjectTermDebt Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.ProjectTermDebt
	:members:

OtherCapitalCosts Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.OtherCapitalCosts
	:members:

IRRTargets Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.IRRTargets
	:members:

CashIncentives Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.CashIncentives
	:members:

FuelCell Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.FuelCell
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Singleowner.Singleowner.Outputs
	:members:

