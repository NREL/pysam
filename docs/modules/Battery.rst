.. _Battery:

Battery
***********************************

Wrapper for SAM Simulation Core model: `cmod_battery.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_battery.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Battery model description**

.. automodule:: PySAM.Battery
	:members:

Functions
===================================

.. autoclass:: PySAM.Battery.Battery
	:members:

Simulation Group
===================================

.. autoclass:: PySAM.Battery.Battery.Simulation
	:members:

Lifetime Group
===================================

.. autoclass:: PySAM.Battery.Battery.Lifetime
	:members:

BatterySystem Group
===================================

.. autoclass:: PySAM.Battery.Battery.BatterySystem
	:members:

SystemOutput Group
===================================

.. autoclass:: PySAM.Battery.Battery.SystemOutput
	:members:

Load Group
===================================

.. autoclass:: PySAM.Battery.Battery.Load
	:members:

BatteryCell Group
===================================

.. autoclass:: PySAM.Battery.Battery.BatteryCell
	:members:

Inverter Group
===================================

.. autoclass:: PySAM.Battery.Battery.Inverter
	:members:

Losses Group
===================================

.. autoclass:: PySAM.Battery.Battery.Losses
	:members:

BatteryDispatch Group
===================================

.. autoclass:: PySAM.Battery.Battery.BatteryDispatch
	:members:

FuelCell Group
===================================

.. autoclass:: PySAM.Battery.Battery.FuelCell
	:members:

PriceSignal Group
===================================

.. autoclass:: PySAM.Battery.Battery.PriceSignal
	:members:

ElectricityRates Group
===================================

.. autoclass:: PySAM.Battery.Battery.ElectricityRates
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.Battery.Battery.Outputs
	:members:

