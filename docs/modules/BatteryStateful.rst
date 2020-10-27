.. _BatteryStateful:

BatteryStateful
***********************************

Wrapper for SAM Simulation Core model: `cmod_battery_stateful.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_battery_stateful.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**BatteryStateful model description**

.. automodule:: PySAM.BatteryStateful
	:members:

Functions
===================================

.. autoclass:: PySAM.BatteryStateful.BatteryStateful
	:members:

Controls Group
===================================

.. autoclass:: PySAM.BatteryStateful.BatteryStateful.Controls
	:members:

ParamsCell Group
===================================

.. autoclass:: PySAM.BatteryStateful.BatteryStateful.ParamsCell
	:members:

ParamsPack Group
===================================

.. autoclass:: PySAM.BatteryStateful.BatteryStateful.ParamsPack
	:members:

StatePack Group
===================================

.. autoclass:: PySAM.BatteryStateful.BatteryStateful.StatePack
	:members:

StateCell Group
===================================

.. autoclass:: PySAM.BatteryStateful.BatteryStateful.StateCell
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.BatteryStateful.BatteryStateful.Outputs
	:members:

