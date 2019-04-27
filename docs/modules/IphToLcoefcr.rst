.. _IphToLcoefcr:

IphToLcoefcr
**************************

Wrapper for SAM Simulation Core model: `cmod_iph_to_lcoefcr.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_iph_to_lcoefcr.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**IphToLcoefcr model description**

.. automodule:: PySAM.IphToLcoefcr
	:members:

Functions
=========================

.. autoclass:: PySAM.IphToLcoefcr.IphToLcoefcr
	:members:

IPHLCOH Group
==============

.. autoclass:: PySAM.IphToLcoefcr.IphToLcoefcr.IPHLCOH
	:members:

SimpleLCOE Group
==============

.. autoclass:: PySAM.IphToLcoefcr.IphToLcoefcr.SimpleLCOE
	:members:

Outputs Group
==============

.. autoclass:: PySAM.IphToLcoefcr.IphToLcoefcr.Outputs
	:members:

