.. _MhkWave:

MhkWave
========

.. automodule:: PySAM.MhkWave
	:members:

MhkWave is a wrapper for the SSC compute module `cmod_mhk_wave.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_mhk_wave.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

 - device_rated_power

 - number_devices

 - system_capacity

 - wave_power_matrix

Functions
-----------

.. autoclass:: PySAM.MhkWave.MhkWave
	:members:

MHKWave Group
--------------

.. autoclass:: PySAM.MhkWave.MhkWave.MHKWave
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.MhkWave.MhkWave.Outputs
	:members:

