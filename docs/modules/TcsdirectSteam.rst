.. _TcsdirectSteam:

TcsdirectSteam
**************************

Wrapper for SAM Simulation Core model: `cmod_tcsdirect_steam.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcsdirect_steam.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**TcsdirectSteam model description**

.. automodule:: PySAM.TcsdirectSteam
	:members:

Functions
=========================

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam
	:members:

Weather Group
==============

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.Weather
	:members:

DirectSteamTower Group
==============

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.DirectSteamTower
	:members:

TouTranslator Group
==============

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.TouTranslator
	:members:

Heliostat Group
==============

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.Heliostat
	:members:

Receiver Group
==============

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.Receiver
	:members:

DsgController Group
==============

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.DsgController
	:members:

Powerblock Group
==============

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.Powerblock
	:members:

Parasitics Group
==============

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.Parasitics
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.Outputs
	:members:

