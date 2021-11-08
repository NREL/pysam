.. _HostDeveloper:

HostDeveloper
***********************************

Wrapper for SAM Simulation Core model: `cmod_host_developer.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_host_developer.cpp>`_

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

**HostDeveloper model description**

.. automodule:: PySAM.HostDeveloper
	:members:

Functions
===================================

.. autoclass:: PySAM.HostDeveloper.HostDeveloper
	:members:

Revenue Group
======================================================

.. autoclass:: PySAM.HostDeveloper.HostDeveloper.Revenue
	:members:

FinancialParameters Group
======================================================

.. autoclass:: PySAM.HostDeveloper.HostDeveloper.FinancialParameters
	:members:

SystemCosts Group
======================================================

.. autoclass:: PySAM.HostDeveloper.HostDeveloper.SystemCosts
	:members:

TaxCreditIncentives Group
======================================================

.. autoclass:: PySAM.HostDeveloper.HostDeveloper.TaxCreditIncentives
	:members:

Depreciation Group
======================================================

.. autoclass:: PySAM.HostDeveloper.HostDeveloper.Depreciation
	:members:

PaymentIncentives Group
======================================================

.. autoclass:: PySAM.HostDeveloper.HostDeveloper.PaymentIncentives
	:members:

Host Group
======================================================

.. autoclass:: PySAM.HostDeveloper.HostDeveloper.Host
	:members:

SystemOutput Group
======================================================

.. autoclass:: PySAM.HostDeveloper.HostDeveloper.SystemOutput
	:members:

ReturnOnEquity Group
======================================================

.. autoclass:: PySAM.HostDeveloper.HostDeveloper.ReturnOnEquity
	:members:

Moratorium Group
======================================================

.. autoclass:: PySAM.HostDeveloper.HostDeveloper.Moratorium
	:members:

Recapitalization Group
======================================================

.. autoclass:: PySAM.HostDeveloper.HostDeveloper.Recapitalization
	:members:

TimeOfDelivery Group
======================================================

.. autoclass:: PySAM.HostDeveloper.HostDeveloper.TimeOfDelivery
	:members:

ConstructionFinancing Group
======================================================

.. autoclass:: PySAM.HostDeveloper.HostDeveloper.ConstructionFinancing
	:members:

BatterySystem Group
======================================================

.. autoclass:: PySAM.HostDeveloper.HostDeveloper.BatterySystem
	:members:

LCOS Group
======================================================

.. autoclass:: PySAM.HostDeveloper.HostDeveloper.LCOS
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.HostDeveloper.HostDeveloper.Outputs
	:members:

