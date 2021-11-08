.. _Merchantplant:

Merchantplant
***********************************

Wrapper for SAM Simulation Core model: `cmod_merchantplant.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_merchantplant.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - construction_financing_cost
 - cp_battery_nameplate
 - cp_system_nameplate
 - total_installed_cost

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**Merchantplant model description**

.. automodule:: PySAM.Merchantplant
	:members:

Functions
===================================

.. autoclass:: PySAM.Merchantplant.Merchantplant
	:members:

FinancialParameters Group
======================================================

.. autoclass:: PySAM.Merchantplant.Merchantplant.FinancialParameters
	:members:

SystemCosts Group
======================================================

.. autoclass:: PySAM.Merchantplant.Merchantplant.SystemCosts
	:members:

TaxCreditIncentives Group
======================================================

.. autoclass:: PySAM.Merchantplant.Merchantplant.TaxCreditIncentives
	:members:

Depreciation Group
======================================================

.. autoclass:: PySAM.Merchantplant.Merchantplant.Depreciation
	:members:

PaymentIncentives Group
======================================================

.. autoclass:: PySAM.Merchantplant.Merchantplant.PaymentIncentives
	:members:

Revenue Group
======================================================

.. autoclass:: PySAM.Merchantplant.Merchantplant.Revenue
	:members:

BatterySystem Group
======================================================

.. autoclass:: PySAM.Merchantplant.Merchantplant.BatterySystem
	:members:

SystemOutput Group
======================================================

.. autoclass:: PySAM.Merchantplant.Merchantplant.SystemOutput
	:members:

UtilityBill Group
======================================================

.. autoclass:: PySAM.Merchantplant.Merchantplant.UtilityBill
	:members:

Lifetime Group
======================================================

.. autoclass:: PySAM.Merchantplant.Merchantplant.Lifetime
	:members:

FuelCell Group
======================================================

.. autoclass:: PySAM.Merchantplant.Merchantplant.FuelCell
	:members:

CapacityPayments Group
======================================================

.. autoclass:: PySAM.Merchantplant.Merchantplant.CapacityPayments
	:members:

LCOS Group
======================================================

.. autoclass:: PySAM.Merchantplant.Merchantplant.LCOS
	:members:

GridLimits Group
======================================================

.. autoclass:: PySAM.Merchantplant.Merchantplant.GridLimits
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Merchantplant.Merchantplant.Outputs
	:members:

