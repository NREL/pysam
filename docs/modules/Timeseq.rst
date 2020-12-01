.. _Timeseq:

Timeseq
***********************************

Wrapper for SAM Simulation Core model: `cmod_timeseq.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_timeseq.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Timeseq model description**

.. automodule:: PySAM.Timeseq
	:members:

Functions
===================================

.. autoclass:: PySAM.Timeseq.Timeseq
	:members:

TimeSequence Group
===================================

.. autoclass:: PySAM.Timeseq.Timeseq.TimeSequence
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.Timeseq.Timeseq.Outputs
	:members:

