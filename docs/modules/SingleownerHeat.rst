.. _SingleownerHeat:

SingleownerHeat
================

.. automodule:: PySAM.SingleownerHeat
	:members:

SingleownerHeat is a wrapper for the SSC compute module `cmod_singleowner_heat.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_singleowner_heat.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

 - cbi_fed_amount

 - cbi_fed_amount_heat_btu

 - cbi_oth_amount

 - cbi_oth_amount_heat_btu

 - cbi_sta_amount

 - cbi_sta_amount_heat_btu

 - cbi_uti_amount

 - cbi_uti_amount_heat_btu

 - construction_financing_cost

 - total_installed_cost

Functions
-----------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat
	:members:

Revenue Group
--------------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat.Revenue
	:members:

FinancialParameters Group
--------------------------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat.FinancialParameters
	:members:

SystemCosts Group
------------------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat.SystemCosts
	:members:

LandLease Group
----------------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat.LandLease
	:members:

TaxCreditIncentives Group
--------------------------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat.TaxCreditIncentives
	:members:

PaymentIncentives Group
------------------------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat.PaymentIncentives
	:members:

Depreciation Group
-------------------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat.Depreciation
	:members:

BatterySystem Group
--------------------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat.BatterySystem
	:members:

ElectricityRates Group
-----------------------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat.ElectricityRates
	:members:

SystemOutput Group
-------------------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat.SystemOutput
	:members:

HeatModelOutput Group
----------------------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat.HeatModelOutput
	:members:

UtilityBill Group
------------------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat.UtilityBill
	:members:

Lifetime Group
---------------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat.Lifetime
	:members:

FuelCell Group
---------------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat.FuelCell
	:members:

LCOS Group
-----------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat.LCOS
	:members:

ChargesByMonth Group
---------------------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat.ChargesByMonth
	:members:

HybridFin Group
----------------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat.HybridFin
	:members:

Monthly Group
--------------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat.Monthly
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.SingleownerHeat.SingleownerHeat.Outputs
	:members:

