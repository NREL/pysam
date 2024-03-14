.. _Singleowner:

Singleowner
============

.. automodule:: PySAM.Singleowner
	:members:

Singleowner is a wrapper for the SSC compute module `cmod_singleowner.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_singleowner.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

 - battery_per_kWh

 - battery_total_cost_lcos

 - construction_financing_cost

 - cp_battery_nameplate

 - cp_system_nameplate

 - land_area

 - om_batt_nameplate

 - total_installed_cost

Functions
-----------

.. autoclass:: PySAM.Singleowner.Singleowner
	:members:

Revenue Group
--------------

.. autoclass:: PySAM.Singleowner.Singleowner.Revenue
	:members:

FinancialParameters Group
--------------------------

.. autoclass:: PySAM.Singleowner.Singleowner.FinancialParameters
	:members:

SystemCosts Group
------------------

.. autoclass:: PySAM.Singleowner.Singleowner.SystemCosts
	:members:

LandLease Group
----------------

.. autoclass:: PySAM.Singleowner.Singleowner.LandLease
	:members:

TaxCreditIncentives Group
--------------------------

.. autoclass:: PySAM.Singleowner.Singleowner.TaxCreditIncentives
	:members:

Depreciation Group
-------------------

.. autoclass:: PySAM.Singleowner.Singleowner.Depreciation
	:members:

PaymentIncentives Group
------------------------

.. autoclass:: PySAM.Singleowner.Singleowner.PaymentIncentives
	:members:

BatterySystem Group
--------------------

.. autoclass:: PySAM.Singleowner.Singleowner.BatterySystem
	:members:

ElectricityRates Group
-----------------------

.. autoclass:: PySAM.Singleowner.Singleowner.ElectricityRates
	:members:

SystemOutput Group
-------------------

.. autoclass:: PySAM.Singleowner.Singleowner.SystemOutput
	:members:

UtilityBill Group
------------------

.. autoclass:: PySAM.Singleowner.Singleowner.UtilityBill
	:members:

Lifetime Group
---------------

.. autoclass:: PySAM.Singleowner.Singleowner.Lifetime
	:members:

FuelCell Group
---------------

.. autoclass:: PySAM.Singleowner.Singleowner.FuelCell
	:members:

CapacityPayments Group
-----------------------

.. autoclass:: PySAM.Singleowner.Singleowner.CapacityPayments
	:members:

GridLimits Group
-----------------

.. autoclass:: PySAM.Singleowner.Singleowner.GridLimits
	:members:

LCOS Group
-----------

.. autoclass:: PySAM.Singleowner.Singleowner.LCOS
	:members:

ChargesByMonth Group
---------------------

.. autoclass:: PySAM.Singleowner.Singleowner.ChargesByMonth
	:members:

HybridFin Group
----------------

.. autoclass:: PySAM.Singleowner.Singleowner.HybridFin
	:members:

Monthly Group
--------------

.. autoclass:: PySAM.Singleowner.Singleowner.Monthly
	:members:

HybridCosts Group
------------------

.. autoclass:: PySAM.Singleowner.Singleowner.HybridCosts
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.Singleowner.Singleowner.Outputs
	:members:

