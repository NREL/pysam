.. _BatteryStateful:

BatteryStateful
================

.. automodule:: PySAM.BatteryStateful
	:members:

BatteryStateful is a wrapper for the SSC compute module `cmod_battery_stateful.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_battery_stateful.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

- None

Functions
-----------

.. autoclass:: PySAM.BatteryStateful.BatteryStateful
	:members:

Controls Group
---------------

.. autoclass:: PySAM.BatteryStateful.BatteryStateful.Controls
	:members:

ParamsCell Group
-----------------

.. autoclass:: PySAM.BatteryStateful.BatteryStateful.ParamsCell
	:members:

ParamsPack Group
-----------------

.. autoclass:: PySAM.BatteryStateful.BatteryStateful.ParamsPack
	:members:

StatePack Group
----------------

.. autoclass:: PySAM.BatteryStateful.BatteryStateful.StatePack
	:members:

StateCell Group
----------------

.. autoclass:: PySAM.BatteryStateful.BatteryStateful.StateCell
	:members:

