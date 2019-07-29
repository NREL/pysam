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

Battery Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.Battery
	:members:

System Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.System
	:members:

ElectricLoad Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.ElectricLoad
	:members:

Common Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.Common
	:members:

Inverter Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.Inverter
	:members:

PV Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.PV
	:members:

FuelCell Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.FuelCell
	:members:

ElectricityRate Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.ElectricityRate
	:members:

TimeOfDelivery Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.TimeOfDelivery
	:members:

Outputs Group
==============

.. autoclass:: PySAM.StandAloneBattery.StandAloneBattery.Outputs
	:members:

