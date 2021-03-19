.. _TcstroughPhysical:

TcstroughPhysical
***********************************

Wrapper for SAM Simulation Core model: `cmod_tcstrough_physical.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcstrough_physical.cpp>`_

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

**TcstroughPhysical model description**

.. automodule:: PySAM.TcstroughPhysical
	:members:

Functions
===================================

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical
	:members:

Weather Group
======================================================

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.Weather
	:members:

Trough Group
======================================================

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.Trough
	:members:

SolarField Group
======================================================

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.SolarField
	:members:

Controller Group
======================================================

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.Controller
	:members:

TouTranslator Group
======================================================

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.TouTranslator
	:members:

Powerblock Group
======================================================

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.Powerblock
	:members:

UserDefinedPC Group
======================================================

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.UserDefinedPC
	:members:

Enet Group
======================================================

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.Enet
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.TcstroughPhysical.TcstroughPhysical.Outputs
	:members:

