.. _Singlediode:

Singlediode
**************************

Wrapper for SAM Simulation Core model: `cmod_singlediode.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_singlediode.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Singlediode model description**

.. automodule:: PySAM.Singlediode
	:members:

Functions
=========================

.. autoclass:: PySAM.Singlediode.Singlediode
	:members:

SingleDiodeModel Group
==============

.. autoclass:: PySAM.Singlediode.Singlediode.SingleDiodeModel
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Singlediode.Singlediode.Outputs
	:members:

