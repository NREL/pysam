.. _Singleowner:

Singleowner
***********************************

Wrapper for SAM Simulation Core model: `cmod_singleowner.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_singleowner.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - construction_financing_cost
 - cp_battery_nameplate
 - cp_system_nameplate
 - system_capacity
 - total_installed_cost

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**Singleowner model description**

.. automodule:: PySAM.Singleowner
	:members:

Functions
===================================

.. autoclass:: PySAM.Singleowner.Singleowner
	:members:

Revenue Group
======================================================

.. autoclass:: PySAM.Singleowner.Singleowner.Revenue
	:members:

FinancialParameters Group
======================================================

.. autoclass:: PySAM.Singleowner.Singleowner.FinancialParameters
	:members:

SystemCosts Group
======================================================

.. autoclass:: PySAM.Singleowner.Singleowner.SystemCosts
	:members:

TaxCreditIncentives Group
======================================================

.. autoclass:: PySAM.Singleowner.Singleowner.TaxCreditIncentives
	:members:

Depreciation Group
======================================================

.. autoclass:: PySAM.Singleowner.Singleowner.Depreciation
	:members:

PaymentIncentives Group
======================================================

.. autoclass:: PySAM.Singleowner.Singleowner.PaymentIncentives
	:members:

BatterySystem Group
======================================================

.. autoclass:: PySAM.Singleowner.Singleowner.BatterySystem
	:members:

ElectricityRates Group
======================================================

.. autoclass:: PySAM.Singleowner.Singleowner.ElectricityRates
	:members:

SystemOutput Group
======================================================

.. autoclass:: PySAM.Singleowner.Singleowner.SystemOutput
	:members:

UtilityBill Group
======================================================

.. autoclass:: PySAM.Singleowner.Singleowner.UtilityBill
	:members:

Lifetime Group
======================================================

.. autoclass:: PySAM.Singleowner.Singleowner.Lifetime
	:members:

FuelCell Group
======================================================

.. autoclass:: PySAM.Singleowner.Singleowner.FuelCell
	:members:

CapacityPayments Group
======================================================

.. autoclass:: PySAM.Singleowner.Singleowner.CapacityPayments
	:members:

GridLimits Group
======================================================

.. autoclass:: PySAM.Singleowner.Singleowner.GridLimits
	:members:

Battery Group
======================================================

.. autoclass:: PySAM.Singleowner.Singleowner.Battery
	:members:

ChargesByMonth Group
======================================================

.. autoclass:: PySAM.Singleowner.Singleowner.ChargesByMonth
	:members:

Monthly Group
======================================================

.. autoclass:: PySAM.Singleowner.Singleowner.Monthly
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Singleowner.Singleowner.Outputs
	:members:

