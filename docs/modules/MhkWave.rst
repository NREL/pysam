.. _MhkWave:

MhkWave
***********************************

Wrapper for SAM Simulation Core model: `cmod_mhk_wave.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_mhk_wave.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - device_rated_power
 - number_devices
 - system_capacity
 - wave_power_matrix

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**MhkWave model description**

.. automodule:: PySAM.MhkWave
	:members:

Functions
===================================

.. autoclass:: PySAM.MhkWave.MhkWave
	:members:

MHKWave Group
======================================================

.. autoclass:: PySAM.MhkWave.MhkWave.MHKWave
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.MhkWave.MhkWave.Outputs
	:members:

