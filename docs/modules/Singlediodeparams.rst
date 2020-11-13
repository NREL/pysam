.. _Singlediodeparams:

Singlediodeparams
***********************************

Wrapper for SAM Simulation Core model: `cmod_singlediodeparams.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_singlediodeparams.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Singlediodeparams model description**

.. automodule:: PySAM.Singlediodeparams
	:members:

Functions
===================================

.. autoclass:: PySAM.Singlediodeparams.Singlediodeparams
	:members:

SingleDiodeModel Group
===================================

.. autoclass:: PySAM.Singlediodeparams.Singlediodeparams.SingleDiodeModel
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.Singlediodeparams.Singlediodeparams.Outputs
	:members:

