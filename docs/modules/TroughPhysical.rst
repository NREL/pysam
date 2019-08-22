.. _TroughPhysical:

TroughPhysical
**************************

Wrapper for SAM Simulation Core model: `cmod_trough_physical.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_trough_physical.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**TroughPhysical model description**

.. automodule:: PySAM.TroughPhysical
	:members:

Functions
=========================

.. autoclass:: PySAM.TroughPhysical.TroughPhysical
	:members:

Weather Group
==============

.. autoclass:: PySAM.TroughPhysical.TroughPhysical.Weather
	:members:

SolarField Group
==============

.. autoclass:: PySAM.TroughPhysical.TroughPhysical.SolarField
	:members:

Powerblock Group
==============

.. autoclass:: PySAM.TroughPhysical.TroughPhysical.Powerblock
	:members:

TES Group
==============

.. autoclass:: PySAM.TroughPhysical.TroughPhysical.TES
	:members:

Tou Group
==============

.. autoclass:: PySAM.TroughPhysical.TroughPhysical.Tou
	:members:

System Group
==============

.. autoclass:: PySAM.TroughPhysical.TroughPhysical.System
	:members:

Controller Group
==============

.. autoclass:: PySAM.TroughPhysical.TroughPhysical.Controller
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.TroughPhysical.TroughPhysical.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.TroughPhysical.TroughPhysical.Outputs
	:members:

