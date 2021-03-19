.. _Thermalrate:

Thermalrate
***********************************

Wrapper for SAM Simulation Core model: `cmod_thermalrate.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_thermalrate.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - thermal_buy_rate
 - thermal_buy_rate_flat
 - thermal_buy_rate_option
 - thermal_sell_rate
 - thermal_sell_rate_flat
 - thermal_sell_rate_option

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**Thermalrate model description**

.. automodule:: PySAM.Thermalrate
	:members:

Functions
===================================

.. autoclass:: PySAM.Thermalrate.Thermalrate
	:members:

ThermalRate Group
======================================================

.. autoclass:: PySAM.Thermalrate.Thermalrate.ThermalRate
	:members:

Lifetime Group
======================================================

.. autoclass:: PySAM.Thermalrate.Thermalrate.Lifetime
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Thermalrate.Thermalrate.Outputs
	:members:

