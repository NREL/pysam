.. _TcsdirectSteam:

TcsdirectSteam
***********************************

Wrapper for SAM Simulation Core model: `cmod_tcsdirect_steam.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcsdirect_steam.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:


Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**TcsdirectSteam model description**

.. automodule:: PySAM.TcsdirectSteam
	:members:

Functions
===================================

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam
	:members:

Weather Group
======================================================

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.Weather
	:members:

DirectSteamTower Group
======================================================

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.DirectSteamTower
	:members:

TouTranslator Group
======================================================

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.TouTranslator
	:members:

Heliostat Group
======================================================

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.Heliostat
	:members:

Receiver Group
======================================================

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.Receiver
	:members:

DsgController Group
======================================================

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.DsgController
	:members:

Powerblock Group
======================================================

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.Powerblock
	:members:

Parasitics Group
======================================================

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.Parasitics
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.TcsdirectSteam.TcsdirectSteam.Outputs
	:members:

