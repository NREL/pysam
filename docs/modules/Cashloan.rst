.. _Cashloan:

Cashloan
=========

.. automodule:: PySAM.Cashloan
	:members:

Cashloan is a wrapper for the SSC compute module `cmod_cashloan.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_cashloan.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

 - battery_per_kWh

 - battery_total_cost_lcos

 - om_batt_nameplate

 - total_installed_cost

Functions
-----------

.. autoclass:: PySAM.Cashloan.Cashloan
	:members:

FinancialParameters Group
--------------------------

.. autoclass:: PySAM.Cashloan.Cashloan.FinancialParameters
	:members:

SystemCosts Group
------------------

.. autoclass:: PySAM.Cashloan.Cashloan.SystemCosts
	:members:

LandLease Group
----------------

.. autoclass:: PySAM.Cashloan.Cashloan.LandLease
	:members:

Depreciation Group
-------------------

.. autoclass:: PySAM.Cashloan.Cashloan.Depreciation
	:members:

TaxCreditIncentives Group
--------------------------

.. autoclass:: PySAM.Cashloan.Cashloan.TaxCreditIncentives
	:members:

PaymentIncentives Group
------------------------

.. autoclass:: PySAM.Cashloan.Cashloan.PaymentIncentives
	:members:

BatterySystem Group
--------------------

.. autoclass:: PySAM.Cashloan.Cashloan.BatterySystem
	:members:

FuelCell Group
---------------

.. autoclass:: PySAM.Cashloan.Cashloan.FuelCell
	:members:

ChargesByMonth Group
---------------------

.. autoclass:: PySAM.Cashloan.Cashloan.ChargesByMonth
	:members:

Battery Group
--------------

.. autoclass:: PySAM.Cashloan.Cashloan.Battery
	:members:

TimeSeries Group
-----------------

.. autoclass:: PySAM.Cashloan.Cashloan.TimeSeries
	:members:

SystemOutput Group
-------------------

.. autoclass:: PySAM.Cashloan.Cashloan.SystemOutput
	:members:

Lifetime Group
---------------

.. autoclass:: PySAM.Cashloan.Cashloan.Lifetime
	:members:

LCOS Group
-----------

.. autoclass:: PySAM.Cashloan.Cashloan.LCOS
	:members:

ElectricityRates Group
-----------------------

.. autoclass:: PySAM.Cashloan.Cashloan.ElectricityRates
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.Cashloan.Cashloan.Outputs
	:members:

