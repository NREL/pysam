.. _Communitysolar:

Communitysolar
***********************************

Wrapper for SAM Simulation Core model: `cmod_communitysolar.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_communitysolar.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - construction_financing_cost
 - land_area
 - total_installed_cost

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**Communitysolar model description**

.. automodule:: PySAM.Communitysolar
	:members:

Functions
===================================

.. autoclass:: PySAM.Communitysolar.Communitysolar
	:members:

FinancialParameters Group
======================================================

.. autoclass:: PySAM.Communitysolar.Communitysolar.FinancialParameters
	:members:

SystemCosts Group
======================================================

.. autoclass:: PySAM.Communitysolar.Communitysolar.SystemCosts
	:members:

LandLease Group
======================================================

.. autoclass:: PySAM.Communitysolar.Communitysolar.LandLease
	:members:

TaxCreditIncentives Group
======================================================

.. autoclass:: PySAM.Communitysolar.Communitysolar.TaxCreditIncentives
	:members:

Depreciation Group
======================================================

.. autoclass:: PySAM.Communitysolar.Communitysolar.Depreciation
	:members:

PaymentIncentives Group
======================================================

.. autoclass:: PySAM.Communitysolar.Communitysolar.PaymentIncentives
	:members:

Revenue Group
======================================================

.. autoclass:: PySAM.Communitysolar.Communitysolar.Revenue
	:members:

BatterySystem Group
======================================================

.. autoclass:: PySAM.Communitysolar.Communitysolar.BatterySystem
	:members:

ElectricityRates Group
======================================================

.. autoclass:: PySAM.Communitysolar.Communitysolar.ElectricityRates
	:members:

SystemOutput Group
======================================================

.. autoclass:: PySAM.Communitysolar.Communitysolar.SystemOutput
	:members:

UtilityBill Group
======================================================

.. autoclass:: PySAM.Communitysolar.Communitysolar.UtilityBill
	:members:

Lifetime Group
======================================================

.. autoclass:: PySAM.Communitysolar.Communitysolar.Lifetime
	:members:

CommunitySolar Group
======================================================

.. autoclass:: PySAM.Communitysolar.Communitysolar.CommunitySolar
	:members:

FuelCell Group
======================================================

.. autoclass:: PySAM.Communitysolar.Communitysolar.FuelCell
	:members:

GridLimits Group
======================================================

.. autoclass:: PySAM.Communitysolar.Communitysolar.GridLimits
	:members:

LCOS Group
======================================================

.. autoclass:: PySAM.Communitysolar.Communitysolar.LCOS
	:members:

ChargesByMonth Group
======================================================

.. autoclass:: PySAM.Communitysolar.Communitysolar.ChargesByMonth
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Communitysolar.Communitysolar.Outputs
	:members:

