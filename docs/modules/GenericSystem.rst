.. _GenericSystem:

GenericSystem
==============

.. automodule:: PySAM.GenericSystem
	:members:

GenericSystem is a wrapper for the SSC compute module `cmod_generic_system.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_generic_system.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

 - conv_eff

 - heat_rate

 - system_capacity

Functions
-----------

.. autoclass:: PySAM.GenericSystem.GenericSystem
	:members:

Plant Group
------------

.. autoclass:: PySAM.GenericSystem.GenericSystem.Plant
	:members:

Lifetime Group
---------------

.. autoclass:: PySAM.GenericSystem.GenericSystem.Lifetime
	:members:

AdjustmentFactors Group
------------------------

.. autoclass:: PySAM.AdjustmentFactors.AdjustmentFactors
	:members:
	:noindex:

HybridCosts Group
------------------

.. autoclass:: PySAM.GenericSystem.GenericSystem.HybridCosts
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.GenericSystem.GenericSystem.Outputs
	:members:

