.. _Levpartflip:

Levpartflip
***********************************

Wrapper for SAM Simulation Core model: `cmod_levpartflip.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_levpartflip.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdepedent but the equations accounting for these
interdependencies that enforce consistency among these input parameters are not available in the PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - construction_financing_cost
 - total_installed_cost

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**Levpartflip model description**

.. automodule:: PySAM.Levpartflip
	:members:

Functions
===================================

.. autoclass:: PySAM.Levpartflip.Levpartflip
	:members:

Revenue Group
======================================================

.. autoclass:: PySAM.Levpartflip.Levpartflip.Revenue
	:members:

FinancialParameters Group
======================================================

.. autoclass:: PySAM.Levpartflip.Levpartflip.FinancialParameters
	:members:

SystemCosts Group
======================================================

.. autoclass:: PySAM.Levpartflip.Levpartflip.SystemCosts
	:members:

TaxCreditIncentives Group
======================================================

.. autoclass:: PySAM.Levpartflip.Levpartflip.TaxCreditIncentives
	:members:

Depreciation Group
======================================================

.. autoclass:: PySAM.Levpartflip.Levpartflip.Depreciation
	:members:

PaymentIncentives Group
======================================================

.. autoclass:: PySAM.Levpartflip.Levpartflip.PaymentIncentives
	:members:

SystemOutput Group
======================================================

.. autoclass:: PySAM.Levpartflip.Levpartflip.SystemOutput
	:members:

Moratorium Group
======================================================

.. autoclass:: PySAM.Levpartflip.Levpartflip.Moratorium
	:members:

Recapitalization Group
======================================================

.. autoclass:: PySAM.Levpartflip.Levpartflip.Recapitalization
	:members:

TimeOfDelivery Group
======================================================

.. autoclass:: PySAM.Levpartflip.Levpartflip.TimeOfDelivery
	:members:

ConstructionFinancing Group
======================================================

.. autoclass:: PySAM.Levpartflip.Levpartflip.ConstructionFinancing
	:members:

OtherCapitalCosts Group
======================================================

.. autoclass:: PySAM.Levpartflip.Levpartflip.OtherCapitalCosts
	:members:

IRRTargets Group
======================================================

.. autoclass:: PySAM.Levpartflip.Levpartflip.IRRTargets
	:members:

BatterySystem Group
======================================================

.. autoclass:: PySAM.Levpartflip.Levpartflip.BatterySystem
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Levpartflip.Levpartflip.Outputs
	:members:

