.. _GenericSystem:

GenericSystem
***********************************

Wrapper for SAM Simulation Core model: `cmod_generic_system.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_generic_system.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - conv_eff
 - heat_rate

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**GenericSystem model description**

.. automodule:: PySAM.GenericSystem
	:members:

Functions
===================================

.. autoclass:: PySAM.GenericSystem.GenericSystem
	:members:

Plant Group
======================================================

.. autoclass:: PySAM.GenericSystem.GenericSystem.Plant
	:members:

Lifetime Group
======================================================

.. autoclass:: PySAM.GenericSystem.GenericSystem.Lifetime
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.GenericSystem.GenericSystem.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.GenericSystem.GenericSystem.Outputs
	:members:

