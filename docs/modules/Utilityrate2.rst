.. _Utilityrate2:

Utilityrate2
***********************************

Wrapper for SAM Simulation Core model: `cmod_utilityrate2.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_utilityrate2.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Utilityrate2 model description**

.. automodule:: PySAM.Utilityrate2
	:members:

Functions
===================================

.. autoclass:: PySAM.Utilityrate2.Utilityrate2
	:members:

Common Group
===================================

.. autoclass:: PySAM.Utilityrate2.Utilityrate2.Common
	:members:

AnnualOutput Group
===================================

.. autoclass:: PySAM.Utilityrate2.Utilityrate2.AnnualOutput
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.Utilityrate2.Utilityrate2.Outputs
	:members:

