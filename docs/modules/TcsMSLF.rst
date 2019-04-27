.. _TcsMSLF:

TcsMSLF
**************************

Wrapper for SAM Simulation Core model: `cmod_tcsMSLF.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcsmslf.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**TcsMSLF model description**

.. automodule:: PySAM.TcsMSLF
	:members:

Functions
=========================

.. autoclass:: PySAM.TcsMSLF.TcsMSLF
	:members:

Weather Group
==============

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.Weather
	:members:

Mslf Group
==============

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.Mslf
	:members:

TouTranslator Group
==============

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.TouTranslator
	:members:

Controller Group
==============

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.Controller
	:members:

SolarField Group
==============

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.SolarField
	:members:

Powerblock Group
==============

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.Powerblock
	:members:

UserDefinedPC Group
==============

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.UserDefinedPC
	:members:

Enet Group
==============

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.Enet
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.Outputs
	:members:

