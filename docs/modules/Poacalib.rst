.. _Poacalib:

Poacalib
***********************************

Wrapper for SAM Simulation Core model: `cmod_poacalib.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_poacalib.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Poacalib model description**

.. automodule:: PySAM.Poacalib
	:members:

Functions
===================================

.. autoclass:: PySAM.Poacalib.Poacalib
	:members:

POACalibrate Group
===================================

.. autoclass:: PySAM.Poacalib.Poacalib.POACalibrate
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.Poacalib.Poacalib.Outputs
	:members:

