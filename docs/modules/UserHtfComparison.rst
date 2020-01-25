.. _UserHtfComparison:

UserHtfComparison
**************************

Wrapper for SAM Simulation Core model: `cmod_user_htf_comparison.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_user_htf_comparison.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**UserHtfComparison model description**

.. automodule:: PySAM.UserHtfComparison
	:members:

Functions
=========================

.. autoclass:: PySAM.UserHtfComparison.UserHtfComparison
	:members:

Common Group
==============

.. autoclass:: PySAM.UserHtfComparison.UserHtfComparison.Common
	:members:

Outputs Group
==============

.. autoclass:: PySAM.UserHtfComparison.UserHtfComparison.Outputs
	:members:

