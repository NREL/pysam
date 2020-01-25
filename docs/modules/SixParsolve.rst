.. _SixParsolve:

6parsolve
**************************

Wrapper for SAM Simulation Core model: `cmod_6parsolve.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_6parsolve.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**SixParsolve model description**

.. automodule:: PySAM.SixParsolve
	:members:

Functions
=========================

.. autoclass:: PySAM.SixParsolve.SixParsolve
	:members:

SixParameterSolver Group
==============

.. autoclass:: PySAM.SixParsolve.SixParsolve.SixParameterSolver
	:members:

Outputs Group
==============

.. autoclass:: PySAM.SixParsolve.SixParsolve.Outputs
	:members:

