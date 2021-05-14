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

TimeOfDeliveryFactors Group
======================================================

.. autoclass:: PySAM.EtesElectricResistance.EtesElectricResistance.TimeOfDeliveryFactors
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

