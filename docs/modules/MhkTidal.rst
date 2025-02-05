.. _MhkTidal:

MhkTidal
=========

.. automodule:: PySAM.MhkTidal
	:members:

MhkTidal is a wrapper for the SSC compute module `cmod_mhk_tidal.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_mhk_tidal.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

 - number_devices

 - system_capacity

 - tidal_power_curve

 - tidal_resource

Functions
-----------

.. autoclass:: PySAM.MhkTidal.MhkTidal
	:members:

MHKTidal Group
---------------

.. autoclass:: PySAM.MhkTidal.MhkTidal.MHKTidal
	:members:

AdjustmentFactors Group
------------------------

.. autoclass:: PySAM.AdjustmentFactors.AdjustmentFactors
	:members:
	:noindex:

Outputs Group
--------------

.. autoclass:: PySAM.MhkTidal.MhkTidal.Outputs
	:members:

