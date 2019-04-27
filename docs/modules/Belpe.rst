.. _Belpe:

Belpe
**************************

Wrapper for SAM Simulation Core model: `cmod_belpe.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_belpe.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Belpe model description**

.. automodule:: PySAM.Belpe
	:members:

Functions
=========================

.. autoclass:: PySAM.Belpe.Belpe
	:members:

LoadProfileEstimator Group
==============

.. autoclass:: PySAM.Belpe.Belpe.LoadProfileEstimator
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Belpe.Belpe.Outputs
	:members:

