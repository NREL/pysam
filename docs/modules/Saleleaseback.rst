.. _Saleleaseback:

Saleleaseback
***********************************

Wrapper for SAM Simulation Core model: `cmod_saleleaseback.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_saleleaseback.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - construction_financing_cost
 - total_installed_cost

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**Saleleaseback model description**

.. automodule:: PySAM.Saleleaseback
	:members:

Functions
===================================

.. autoclass:: PySAM.Saleleaseback.Saleleaseback
	:members:

Revenue Group
======================================================

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.Revenue
	:members:

FinancialParameters Group
======================================================

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.FinancialParameters
	:members:

SystemCosts Group
======================================================

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.SystemCosts
	:members:

TaxCreditIncentives Group
======================================================

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.TaxCreditIncentives
	:members:

Depreciation Group
======================================================

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.Depreciation
	:members:

PaymentIncentives Group
======================================================

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.PaymentIncentives
	:members:

SystemOutput Group
======================================================

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.SystemOutput
	:members:

SaleLeaseback Group
======================================================

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.SaleLeaseback
	:members:

TimeOfDelivery Group
======================================================

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.TimeOfDelivery
	:members:

OtherCapitalCosts Group
======================================================

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.OtherCapitalCosts
	:members:

Battery Group
======================================================

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.Battery
	:members:

ChargesByMonth Group
======================================================

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.ChargesByMonth
	:members:

Monthly Group
======================================================

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.Monthly
	:members:

BatterySystem Group
======================================================

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.BatterySystem
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Saleleaseback.Saleleaseback.Outputs
	:members:

