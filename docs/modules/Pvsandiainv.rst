.. _Pvsandiainv:

Pvsandiainv
**************************

Wrapper for SAM Simulation Core model: `cmod_pvsandiainv.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_pvsandiainv.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Pvsandiainv model description**

.. automodule:: PySAM.Pvsandiainv
	:members:

Functions
=========================

.. autoclass:: PySAM.Pvsandiainv.Pvsandiainv
	:members:

SandiaInverterModel Group
==============

.. autoclass:: PySAM.Pvsandiainv.Pvsandiainv.SandiaInverterModel
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Pvsandiainv.Pvsandiainv.Outputs
	:members:

