.. _EtesElectricResistance:

EtesElectricResistance
***********************************

Wrapper for SAM Simulation Core model: `cmod_etes_electric_resistance.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_etes_electric_resistance.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - const_per_interest_rate1
 - const_per_interest_rate2
 - const_per_interest_rate3
 - const_per_interest_rate4
 - const_per_interest_rate5
 - const_per_months1
 - const_per_months2
 - const_per_months3
 - const_per_months4
 - const_per_months5
 - const_per_percent1
 - const_per_percent2
 - const_per_percent3
 - const_per_percent4
 - const_per_percent5
 - const_per_upfront_rate1
 - const_per_upfront_rate2
 - const_per_upfront_rate3
 - const_per_upfront_rate4
 - const_per_upfront_rate5
 - dispatch_factor1
 - dispatch_factor2
 - dispatch_factor3
 - dispatch_factor4
 - dispatch_factor5
 - dispatch_factor6
 - dispatch_factor7
 - dispatch_factor8
 - dispatch_factor9
 - dispatch_factors_ts
 - dispatch_sched_weekday
 - dispatch_sched_weekend
 - ppa_multiplier_model

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**EtesElectricResistance model description**

.. automodule:: PySAM.EtesElectricResistance
	:members:

Functions
===================================

.. autoclass:: PySAM.EtesElectricResistance.EtesElectricResistance
	:members:

SolarResource Group
======================================================

.. autoclass:: PySAM.EtesElectricResistance.EtesElectricResistance.SolarResource
	:members:

SystemControl Group
======================================================

.. autoclass:: PySAM.EtesElectricResistance.EtesElectricResistance.SystemControl
	:members:

FinancialModel Group
======================================================

.. autoclass:: PySAM.EtesElectricResistance.EtesElectricResistance.FinancialModel
	:members:

SystemDesign Group
======================================================

.. autoclass:: PySAM.EtesElectricResistance.EtesElectricResistance.SystemDesign
	:members:

PowerCycle Group
======================================================

.. autoclass:: PySAM.EtesElectricResistance.EtesElectricResistance.PowerCycle
	:members:

RankineCycle Group
======================================================

.. autoclass:: PySAM.EtesElectricResistance.EtesElectricResistance.RankineCycle
	:members:

UserDefinedPowerCycle Group
======================================================

.. autoclass:: PySAM.EtesElectricResistance.EtesElectricResistance.UserDefinedPowerCycle
	:members:

ThermalStorage Group
======================================================

.. autoclass:: PySAM.EtesElectricResistance.EtesElectricResistance.ThermalStorage
	:members:

Heater Group
======================================================

.. autoclass:: PySAM.EtesElectricResistance.EtesElectricResistance.Heater
	:members:

TimeOfDeliveryFactors Group
======================================================

.. autoclass:: PySAM.EtesElectricResistance.EtesElectricResistance.TimeOfDeliveryFactors
	:members:

Revenue Group
======================================================

.. autoclass:: PySAM.EtesElectricResistance.EtesElectricResistance.Revenue
	:members:

SystemCost Group
======================================================

.. autoclass:: PySAM.EtesElectricResistance.EtesElectricResistance.SystemCost
	:members:

SystemCosts Group
======================================================

.. autoclass:: PySAM.EtesElectricResistance.EtesElectricResistance.SystemCosts
	:members:

FinancialParameters Group
======================================================

.. autoclass:: PySAM.EtesElectricResistance.EtesElectricResistance.FinancialParameters
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.EtesElectricResistance.EtesElectricResistance.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.EtesElectricResistance.EtesElectricResistance.Outputs
	:members:

