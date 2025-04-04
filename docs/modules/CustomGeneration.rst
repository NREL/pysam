.. _CustomGeneration:

CustomGeneration
=================

.. automodule:: PySAM.CustomGeneration
	:members:

CustomGeneration is a wrapper for the SSC compute module `cmod_custom_generation.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_custom_generation.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

 - conv_eff

 - heat_rate

 - system_capacity

Functions
-----------

.. autoclass:: PySAM.CustomGeneration.CustomGeneration
	:members:

Plant Group
------------

.. autoclass:: PySAM.CustomGeneration.CustomGeneration.Plant
	:members:

Lifetime Group
---------------

.. autoclass:: PySAM.CustomGeneration.CustomGeneration.Lifetime
	:members:

AdjustmentFactors Group
------------------------

.. autoclass:: PySAM.CustomGeneration.CustomGeneration.AdjustmentFactors
	:members:

HybridCosts Group
------------------

.. autoclass:: PySAM.CustomGeneration.CustomGeneration.HybridCosts
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.CustomGeneration.CustomGeneration.Outputs
	:members:

