.. _InvCecCg:

InvCecCg
***********************************

Wrapper for SAM Simulation Core model: `cmod_inv_cec_cg.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_inv_cec_cg.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**InvCecCg model description**

.. automodule:: PySAM.InvCecCg
	:members:

Functions
===================================

.. autoclass:: PySAM.InvCecCg.InvCecCg
	:members:

Common Group
===================================

.. autoclass:: PySAM.InvCecCg.InvCecCg.Common
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.InvCecCg.InvCecCg.Outputs
	:members:

