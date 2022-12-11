.. _Merchantplant:

Merchantplant
==============

.. automodule:: PySAM.Merchantplant
	:members:

Merchantplant is a wrapper for the SSC compute module `cmod_merchantplant.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_merchantplant.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

 - construction_financing_cost

 - cp_battery_nameplate

 - cp_system_nameplate

 - total_installed_cost

Functions
-----------

.. autoclass:: PySAM.Merchantplant.Merchantplant
	:members:

FinancialParameters Group
--------------------------

.. autoclass:: PySAM.Merchantplant.Merchantplant.FinancialParameters
	:members:

SystemCosts Group
------------------

.. autoclass:: PySAM.Merchantplant.Merchantplant.SystemCosts
	:members:

LandLease Group
----------------

.. autoclass:: PySAM.Merchantplant.Merchantplant.LandLease
	:members:

TaxCreditIncentives Group
--------------------------

.. autoclass:: PySAM.Merchantplant.Merchantplant.TaxCreditIncentives
	:members:

Depreciation Group
-------------------

.. autoclass:: PySAM.Merchantplant.Merchantplant.Depreciation
	:members:

PaymentIncentives Group
------------------------

.. autoclass:: PySAM.Merchantplant.Merchantplant.PaymentIncentives
	:members:

Revenue Group
--------------

.. autoclass:: PySAM.Merchantplant.Merchantplant.Revenue
	:members:

BatterySystem Group
--------------------

.. autoclass:: PySAM.Merchantplant.Merchantplant.BatterySystem
	:members:

ElectricityRates Group
-----------------------

.. autoclass:: PySAM.Merchantplant.Merchantplant.ElectricityRates
	:members:

SystemOutput Group
-------------------

.. autoclass:: PySAM.Merchantplant.Merchantplant.SystemOutput
	:members:

UtilityBill Group
------------------

.. autoclass:: PySAM.Merchantplant.Merchantplant.UtilityBill
	:members:

Lifetime Group
---------------

.. autoclass:: PySAM.Merchantplant.Merchantplant.Lifetime
	:members:

FuelCell Group
---------------

.. autoclass:: PySAM.Merchantplant.Merchantplant.FuelCell
	:members:

CapacityPayments Group
-----------------------

.. autoclass:: PySAM.Merchantplant.Merchantplant.CapacityPayments
	:members:

LCOS Group
-----------

.. autoclass:: PySAM.Merchantplant.Merchantplant.LCOS
	:members:

ChargesByMonth Group
---------------------

.. autoclass:: PySAM.Merchantplant.Merchantplant.ChargesByMonth
	:members:

GridLimits Group
-----------------

.. autoclass:: PySAM.Merchantplant.Merchantplant.GridLimits
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.Merchantplant.Merchantplant.Outputs
	:members:

