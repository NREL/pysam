.. _Thermalrate:

Thermalrate
**************************

Wrapper for SAM Simulation Core model: `cmod_thermalrate.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_thermalrate.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Thermalrate model description**

.. automodule:: PySAM.Thermalrate
	:members:

Functions
=========================

.. autoclass:: PySAM.Thermalrate.Thermalrate
	:members:

ThermalRate Group
==============

.. autoclass:: PySAM.Thermalrate.Thermalrate.ThermalRate
	:members:

Lifetime Group
==============

.. autoclass:: PySAM.Thermalrate.Thermalrate.Lifetime
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Thermalrate.Thermalrate.Outputs
	:members:

