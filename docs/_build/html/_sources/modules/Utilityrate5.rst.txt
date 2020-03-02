.. _Utilityrate5:

Utilityrate5
**************************

Wrapper for SAM Simulation Core model: `cmod_utilityrate5.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_utilityrate5.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Utilityrate5 model description**

.. automodule:: PySAM.Utilityrate5
	:members:

Functions
=========================

.. autoclass:: PySAM.Utilityrate5.Utilityrate5
	:members:

ElectricityRates Group
==============

.. autoclass:: PySAM.Utilityrate5.Utilityrate5.ElectricityRates
	:members:

Lifetime Group
==============

.. autoclass:: PySAM.Utilityrate5.Utilityrate5.Lifetime
	:members:

SystemOutput Group
==============

.. autoclass:: PySAM.Utilityrate5.Utilityrate5.SystemOutput
	:members:

Load Group
==============

.. autoclass:: PySAM.Utilityrate5.Utilityrate5.Load
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Utilityrate5.Utilityrate5.Outputs
	:members:

