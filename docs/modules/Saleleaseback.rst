.. _Saleleaseback:

Saleleaseback
**************************

Wrapper for SAM Simulation Core model: `cmod_saleleaseback.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_saleleaseback.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Saleleaseback model description**

.. automodule:: PySAM.Saleleaseback
	:members:

Functions
=========================

.. autoclass:: PySAM.Saleleaseback.Saleleaseback
	:members:

Revenue Group
==============

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.Revenue
	:members:

FinancialParameters Group
==============

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.FinancialParameters
	:members:

SystemCosts Group
==============

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.SystemCosts
	:members:

TaxCreditIncentives Group
==============

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.TaxCreditIncentives
	:members:

Depreciation Group
==============

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.Depreciation
	:members:

PaymentIncentives Group
==============

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.PaymentIncentives
	:members:

SystemOutput Group
==============

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.SystemOutput
	:members:

SaleLeaseback Group
==============

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.SaleLeaseback
	:members:

TimeOfDelivery Group
==============

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.TimeOfDelivery
	:members:

OtherCapitalCosts Group
==============

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.OtherCapitalCosts
	:members:

BatterySystem Group
==============

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.BatterySystem
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.Outputs
	:members:

