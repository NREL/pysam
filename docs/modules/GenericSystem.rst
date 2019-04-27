.. _GenericSystem:

GenericSystem
**************************

Wrapper for SAM Simulation Core model: `cmod_generic_system.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_generic_system.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**GenericSystem model description**

.. automodule:: PySAM.GenericSystem
	:members:

Functions
=========================

.. autoclass:: PySAM.GenericSystem.GenericSystem
	:members:

Plant Group
==============

.. autoclass:: PySAM.GenericSystem.GenericSystem.Plant
	:members:

Lifetime Group
==============

.. autoclass:: PySAM.GenericSystem.GenericSystem.Lifetime
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.GenericSystem.GenericSystem.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.GenericSystem.GenericSystem.Outputs
	:members:

