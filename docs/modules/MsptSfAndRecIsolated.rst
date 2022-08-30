.. _MsptSfAndRecIsolated:

MsptSfAndRecIsolated
***********************************

Wrapper for SAM Simulation Core model: `cmod_mspt_sf_and_rec_isolated.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_mspt_sf_and_rec_isolated.cpp>`_

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

**MsptSfAndRecIsolated model description**

.. automodule:: PySAM.MsptSfAndRecIsolated
	:members:

Functions
===================================

.. autoclass:: PySAM.MsptSfAndRecIsolated.MsptSfAndRecIsolated
	:members:

Simulation Group
======================================================

.. autoclass:: PySAM.MsptSfAndRecIsolated.MsptSfAndRecIsolated.Simulation
	:members:

TowerAndReceiver Group
======================================================

.. autoclass:: PySAM.MsptSfAndRecIsolated.MsptSfAndRecIsolated.TowerAndReceiver
	:members:

ReceiverControl Group
======================================================

.. autoclass:: PySAM.MsptSfAndRecIsolated.MsptSfAndRecIsolated.ReceiverControl
	:members:

Timeseries Group
======================================================

.. autoclass:: PySAM.MsptSfAndRecIsolated.MsptSfAndRecIsolated.Timeseries
	:members:

Weather Group
======================================================

.. autoclass:: PySAM.MsptSfAndRecIsolated.MsptSfAndRecIsolated.Weather
	:members:

Flux Group
======================================================

.. autoclass:: PySAM.MsptSfAndRecIsolated.MsptSfAndRecIsolated.Flux
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.MsptSfAndRecIsolated.MsptSfAndRecIsolated.Outputs
	:members:

