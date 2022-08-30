.. _EtesPtes:

EtesPtes
***********************************

Wrapper for SAM Simulation Core model: `cmod_etes_ptes.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_etes_ptes.cpp>`_

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

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**EtesPtes model description**

.. automodule:: PySAM.EtesPtes
	:members:

Functions
===================================

.. autoclass:: PySAM.EtesPtes.EtesPtes
	:members:

SolarResource Group
======================================================

.. autoclass:: PySAM.EtesPtes.EtesPtes.SolarResource
	:members:

SystemControl Group
======================================================

.. autoclass:: PySAM.EtesPtes.EtesPtes.SystemControl
	:members:

FinancialModel Group
======================================================

.. autoclass:: PySAM.EtesPtes.EtesPtes.FinancialModel
	:members:

SystemDesign Group
======================================================

.. autoclass:: PySAM.EtesPtes.EtesPtes.SystemDesign
	:members:

ThermalStorage Group
======================================================

.. autoclass:: PySAM.EtesPtes.EtesPtes.ThermalStorage
	:members:

Heater Group
======================================================

.. autoclass:: PySAM.EtesPtes.EtesPtes.Heater
	:members:

PowerCycle Group
======================================================

.. autoclass:: PySAM.EtesPtes.EtesPtes.PowerCycle
	:members:

HotThermalStorage Group
======================================================

.. autoclass:: PySAM.EtesPtes.EtesPtes.HotThermalStorage
	:members:

ColdThermalStorage Group
======================================================

.. autoclass:: PySAM.EtesPtes.EtesPtes.ColdThermalStorage
	:members:

TimeOfDeliveryFactors Group
======================================================

.. autoclass:: PySAM.EtesPtes.EtesPtes.TimeOfDeliveryFactors
	:members:

Revenue Group
======================================================

.. autoclass:: PySAM.EtesPtes.EtesPtes.Revenue
	:members:

SystemCosts Group
======================================================

.. autoclass:: PySAM.EtesPtes.EtesPtes.SystemCosts
	:members:

FinancialParameters Group
======================================================

.. autoclass:: PySAM.EtesPtes.EtesPtes.FinancialParameters
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.EtesPtes.EtesPtes.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.EtesPtes.EtesPtes.Outputs
	:members:

