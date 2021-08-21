.. _Battery:

Battery
***********************************

Wrapper for SAM Simulation Core model: `cmod_battery.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_battery.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

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
 - batt_mass
 - batt_power_charge_max_kwac
 - batt_power_charge_max_kwdc
 - batt_power_discharge_max_kwac
 - batt_power_discharge_max_kwdc
 - batt_surface_area
 - dispatch_manual_discharge
 - dispatch_manual_gridcharge
 - dispatch_manual_percent_discharge
 - dispatch_manual_percent_gridcharge

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**Battery model description**

.. automodule:: PySAM.Battery
	:members:

Functions
===================================

.. autoclass:: PySAM.Battery.Battery
	:members:

Simulation Group
======================================================

.. autoclass:: PySAM.Battery.Battery.Simulation
	:members:

Lifetime Group
======================================================

.. autoclass:: PySAM.Battery.Battery.Lifetime
	:members:

BatterySystem Group
======================================================

.. autoclass:: PySAM.Battery.Battery.BatterySystem
	:members:

SystemOutput Group
======================================================

.. autoclass:: PySAM.Battery.Battery.SystemOutput
	:members:

Load Group
======================================================

.. autoclass:: PySAM.Battery.Battery.Load
	:members:

BatteryCell Group
======================================================

.. autoclass:: PySAM.Battery.Battery.BatteryCell
	:members:

Inverter Group
======================================================

.. autoclass:: PySAM.Battery.Battery.Inverter
	:members:

Losses Group
======================================================

.. autoclass:: PySAM.Battery.Battery.Losses
	:members:

BatteryDispatch Group
======================================================

.. autoclass:: PySAM.Battery.Battery.BatteryDispatch
	:members:

FuelCell Group
======================================================

.. autoclass:: PySAM.Battery.Battery.FuelCell
	:members:

PriceSignal Group
======================================================

.. autoclass:: PySAM.Battery.Battery.PriceSignal
	:members:

ElectricityRates Group
======================================================

.. autoclass:: PySAM.Battery.Battery.ElectricityRates
	:members:

GridLimits Group
======================================================

.. autoclass:: PySAM.Battery.Battery.GridLimits
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Battery.Battery.Outputs
	:members:

