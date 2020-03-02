.. _StandAloneBattery:

Battery
**************************

Wrapper for SAM Simulation Core model: `cmod_battery.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_battery.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**StandAloneBattery model description**

.. automodule:: PySAM.StandAloneBattery
	:members:

Functions
=========================

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery
	:members:

Simulation Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.Simulation
	:members:

Lifetime Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.Lifetime
	:members:

BatterySystem Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.BatterySystem
	:members:

SystemOutput Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.SystemOutput
	:members:

Load Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.Load
	:members:

BatteryCell Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.BatteryCell
	:members:

Inverter Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.Inverter
	:members:

Losses Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.Losses
	:members:

BatteryDispatch Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.BatteryDispatch
	:members:

ElectricityRates Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.ElectricityRates
	:members:

FuelCell Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.FuelCell
	:members:

PriceSignal Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.PriceSignal
	:members:

Outputs Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.Outputs
	:members:

