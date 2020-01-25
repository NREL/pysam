.. _MhkCosts:

MhkCosts
**************************

Wrapper for SAM Simulation Core model: `cmod_mhk_costs.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_mhk_costs.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**MhkCosts model description**

.. automodule:: PySAM.MhkCosts
	:members:

Functions
=========================

.. autoclass:: PySAM.MhkCosts.MhkCosts
	:members:

MHKCosts Group
==============

.. autoclass:: PySAM.MhkCosts.MhkCosts.MHKCosts
	:members:

Outputs Group
==============

.. autoclass:: PySAM.MhkCosts.MhkCosts.Outputs
	:members:

