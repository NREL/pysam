.. _TcstroughPhysical:

TcstroughPhysical
**************************

Wrapper for SAM Simulation Core model: `cmod_tcstrough_physical.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcstrough_physical.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**TcstroughPhysical model description**

.. automodule:: PySAM.TcstroughPhysical
	:members:

Functions
=========================

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical
	:members:

Weather Group
==============

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.Weather
	:members:

Trough Group
==============

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.Trough
	:members:

SolarField Group
==============

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.SolarField
	:members:

Controller Group
==============

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.Controller
	:members:

TouTranslator Group
==============

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.TouTranslator
	:members:

Powerblock Group
==============

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.Powerblock
	:members:

UserDefinedPC Group
==============

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.UserDefinedPC
	:members:

Enet Group
==============

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.Enet
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.Outputs
	:members:

