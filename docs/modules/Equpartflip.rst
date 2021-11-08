.. _Equpartflip:

Equpartflip
***********************************

Wrapper for SAM Simulation Core model: `cmod_equpartflip.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_equpartflip.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - construction_financing_cost
 - total_installed_cost

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**Equpartflip model description**

.. automodule:: PySAM.Equpartflip
	:members:

Functions
===================================

.. autoclass:: PySAM.Equpartflip.Equpartflip
	:members:

Revenue Group
======================================================

.. autoclass:: PySAM.Equpartflip.Equpartflip.Revenue
	:members:

FinancialParameters Group
======================================================

.. autoclass:: PySAM.Equpartflip.Equpartflip.FinancialParameters
	:members:

SystemCosts Group
======================================================

.. autoclass:: PySAM.Equpartflip.Equpartflip.SystemCosts
	:members:

TaxCreditIncentives Group
======================================================

.. autoclass:: PySAM.Equpartflip.Equpartflip.TaxCreditIncentives
	:members:

Depreciation Group
======================================================

.. autoclass:: PySAM.Equpartflip.Equpartflip.Depreciation
	:members:

PaymentIncentives Group
======================================================

.. autoclass:: PySAM.Equpartflip.Equpartflip.PaymentIncentives
	:members:

SystemOutput Group
======================================================

.. autoclass:: PySAM.Equpartflip.Equpartflip.SystemOutput
	:members:

Recapitalization Group
======================================================

.. autoclass:: PySAM.Equpartflip.Equpartflip.Recapitalization
	:members:

TimeOfDelivery Group
======================================================

.. autoclass:: PySAM.Equpartflip.Equpartflip.TimeOfDelivery
	:members:

ConstructionFinancing Group
======================================================

.. autoclass:: PySAM.Equpartflip.Equpartflip.ConstructionFinancing
	:members:

OtherCapitalCosts Group
======================================================

.. autoclass:: PySAM.Equpartflip.Equpartflip.OtherCapitalCosts
	:members:

IRRTargets Group
======================================================

.. autoclass:: PySAM.Equpartflip.Equpartflip.IRRTargets
	:members:

DeveloperCapitalRecovery Group
======================================================

.. autoclass:: PySAM.Equpartflip.Equpartflip.DeveloperCapitalRecovery
	:members:

LCOS Group
======================================================

.. autoclass:: PySAM.Equpartflip.Equpartflip.LCOS
	:members:

BatterySystem Group
======================================================

.. autoclass:: PySAM.Equpartflip.Equpartflip.BatterySystem
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Equpartflip.Equpartflip.Outputs
	:members:

