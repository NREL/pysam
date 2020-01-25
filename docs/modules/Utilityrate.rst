.. _Utilityrate:

Utilityrate
**************************

Wrapper for SAM Simulation Core model: `cmod_utilityrate.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_utilityrate.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Utilityrate model description**

.. automodule:: PySAM.Utilityrate
	:members:

Functions
=========================

.. autoclass:: PySAM.Utilityrate.Utilityrate
	:members:

Common Group
==============

.. autoclass:: PySAM.Utilityrate.Utilityrate.Common
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Utilityrate.Utilityrate.Outputs
	:members:

