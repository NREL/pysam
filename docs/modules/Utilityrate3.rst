.. _Utilityrate3:

Utilityrate3
***********************************

Wrapper for SAM Simulation Core model: `cmod_utilityrate3.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_utilityrate3.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Utilityrate3 model description**

.. automodule:: PySAM.Utilityrate3
	:members:

Functions
===================================

.. autoclass:: PySAM.Utilityrate3.Utilityrate3
	:members:

Common Group
===================================

.. autoclass:: PySAM.Utilityrate3.Utilityrate3.Common
	:members:

TimeSeries Group
===================================

.. autoclass:: PySAM.Utilityrate3.Utilityrate3.TimeSeries
	:members:

Financials Group
===================================

.. autoclass:: PySAM.Utilityrate3.Utilityrate3.Financials
	:members:

AnnualOutput Group
===================================

.. autoclass:: PySAM.Utilityrate3.Utilityrate3.AnnualOutput
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.Utilityrate3.Utilityrate3.Outputs
	:members:

