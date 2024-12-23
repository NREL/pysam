.. _Battwatts:

Battwatts
==========

.. automodule:: PySAM.Battwatts
	:members:

Battwatts is a wrapper for the SSC compute module `cmod_battwatts.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_battwatts.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

- None

Functions
-----------

.. autoclass:: PySAM.Battwatts.Battwatts
	:members:

Lifetime Group
---------------

.. autoclass:: PySAM.Battwatts.Battwatts.Lifetime
	:members:

Battery Group
--------------

.. autoclass:: PySAM.Battwatts.Battwatts.Battery
	:members:

Load Group
-----------

.. autoclass:: PySAM.Battwatts.Battwatts.Load
	:members:

AdjustmentFactors Group
------------------------

.. autoclass:: PySAM.AdjustmentFactors.AdjustmentFactors
	:members:
	:noindex:

GridLimits Group
-----------------

.. autoclass:: PySAM.Battwatts.Battwatts.GridLimits
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.Battwatts.Battwatts.Outputs
	:members:

