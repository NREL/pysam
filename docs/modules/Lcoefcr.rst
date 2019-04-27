.. _Lcoefcr:

Lcoefcr
**************************

Wrapper for SAM Simulation Core model: `cmod_lcoefcr.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_lcoefcr.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Lcoefcr model description**

.. automodule:: PySAM.Lcoefcr
	:members:

Functions
=========================

.. autoclass:: PySAM.Lcoefcr.Lcoefcr
	:members:

SimpleLCOE Group
==============

.. autoclass:: PySAM.Lcoefcr.Lcoefcr.SimpleLCOE
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Lcoefcr.Lcoefcr.Outputs
	:members:

