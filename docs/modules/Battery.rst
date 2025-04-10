.. _Battery:

Battery
========

.. automodule:: PySAM.Battery
	:members:

Battery is a wrapper for the SSC compute module `cmod_battery.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_battery.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

 - LeadAcid_q10_computed

 - LeadAcid_q20_computed

 - LeadAcid_qn_computed

 - batt_Qexp

 - batt_Qfull

 - batt_Qfull_flow

 - batt_Qnom

 - batt_Vnom_default

 - batt_ac_dc_efficiency

 - batt_ac_or_dc

 - batt_chem

 - batt_computed_bank_capacity

 - batt_computed_series

 - batt_computed_strings

 - batt_current_charge_max

 - batt_current_choice

 - batt_current_discharge_max

 - batt_dc_ac_efficiency

 - batt_dc_dc_efficiency

 - batt_dispatch_load_forecast_choice

 - batt_load_ac_forecast

 - batt_load_ac_forecast_escalation

 - batt_mass

 - batt_power_charge_max_kwac

 - batt_power_charge_max_kwdc

 - batt_power_discharge_max_kwac

 - batt_power_discharge_max_kwdc

 - batt_room_temperature_celsius

 - batt_surface_area

 - dispatch_manual_discharge

 - dispatch_manual_gridcharge

 - dispatch_manual_percent_discharge

 - dispatch_manual_percent_gridcharge

 - grid_curtailment

 - load_escalation

Functions
-----------

.. autoclass:: PySAM.Battery.Battery
	:members:

Simulation Group
-----------------

.. autoclass:: PySAM.Battery.Battery.Simulation
	:members:

Lifetime Group
---------------

.. autoclass:: PySAM.Battery.Battery.Lifetime
	:members:

BatterySystem Group
--------------------

.. autoclass:: PySAM.Battery.Battery.BatterySystem
	:members:

SystemOutput Group
-------------------

.. autoclass:: PySAM.Battery.Battery.SystemOutput
	:members:

Load Group
-----------

.. autoclass:: PySAM.Battery.Battery.Load
	:members:

BatteryCell Group
------------------

.. autoclass:: PySAM.Battery.Battery.BatteryCell
	:members:

Inverter Group
---------------

.. autoclass:: PySAM.Battery.Battery.Inverter
	:members:

Losses Group
-------------

.. autoclass:: PySAM.Battery.Battery.Losses
	:members:

BatteryDispatch Group
----------------------

.. autoclass:: PySAM.Battery.Battery.BatteryDispatch
	:members:

SystemCosts Group
------------------

.. autoclass:: PySAM.Battery.Battery.SystemCosts
	:members:

FuelCell Group
---------------

.. autoclass:: PySAM.Battery.Battery.FuelCell
	:members:

PriceSignal Group
------------------

.. autoclass:: PySAM.Battery.Battery.PriceSignal
	:members:

Revenue Group
--------------

.. autoclass:: PySAM.Battery.Battery.Revenue
	:members:

AdjustmentFactors Group
------------------------

.. autoclass:: PySAM.Battery.Battery.AdjustmentFactors
	:members:

ElectricityRates Group
-----------------------

.. autoclass:: PySAM.Battery.Battery.ElectricityRates
	:members:

GridLimits Group
-----------------

.. autoclass:: PySAM.Battery.Battery.GridLimits
	:members:

HybridCosts Group
------------------

.. autoclass:: PySAM.Battery.Battery.HybridCosts
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.Battery.Battery.Outputs
	:members:

