.. _Pvwattsv5Lifetime:

Pvwattsv5Lifetime Module
**************************

Wrapper for SAM Simulation Core model: `cmod_pvwattsv5_lifetime.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_pvwattsv5_lifetime.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`PySSC`.

**Pvwattsv5Lifetime model description**

.. automodule:: PySAM.Pvwattsv5Lifetime
	:members:

Functions
=========================

.. autoclass:: PySAM.Pvwattsv5Lifetime.Pvwattsv5Lifetime
	:members:

Common Group
==============

.. autoclass:: PySAM.Pvwattsv5Lifetime.Pvwattsv5Lifetime.Common
	:members:

FinancialAnalysisParameters Group
==============

.. autoclass:: PySAM.Pvwattsv5Lifetime.Pvwattsv5Lifetime.FinancialAnalysisParameters
	:members:

LifetimePV Group
==============

.. autoclass:: PySAM.Pvwattsv5Lifetime.Pvwattsv5Lifetime.LifetimePV
	:members:

Weather Group
==============

.. autoclass:: PySAM.Pvwattsv5Lifetime.Pvwattsv5Lifetime.Weather
	:members:

PVWatts Group
==============

.. autoclass:: PySAM.Pvwattsv5Lifetime.Pvwattsv5Lifetime.PVWatts
	:members:

Battwatts Group
==============

.. autoclass:: PySAM.Pvwattsv5Lifetime.Pvwattsv5Lifetime.Battwatts
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.Pvwattsv5Lifetime.Pvwattsv5Lifetime.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Pvwattsv5Lifetime.Pvwattsv5Lifetime.Outputs
	:members:

