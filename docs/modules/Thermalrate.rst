.. _Thermalrate:

Thermalrate
============

.. automodule:: PySAM.Thermalrate
	:members:

Thermalrate is a wrapper for the SSC compute module `cmod_thermalrate.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_thermalrate.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

 - thermal_buy_rate

 - thermal_buy_rate_flat

 - thermal_buy_rate_option

 - thermal_sell_rate

 - thermal_sell_rate_flat

 - thermal_sell_rate_option

Functions
-----------

.. autoclass:: PySAM.Thermalrate.Thermalrate
	:members:

ThermalRate Group
------------------

.. autoclass:: PySAM.Thermalrate.Thermalrate.ThermalRate
	:members:

Lifetime Group
---------------

.. autoclass:: PySAM.Thermalrate.Thermalrate.Lifetime
	:members:

HybridCosts Group
------------------

.. autoclass:: PySAM.Thermalrate.Thermalrate.HybridCosts
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.Thermalrate.Thermalrate.Outputs
	:members:

