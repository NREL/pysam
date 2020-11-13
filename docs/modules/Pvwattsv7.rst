.. _Pvwattsv7:

Pvwattsv7
***********************************

Wrapper for SAM Simulation Core model: `cmod_pvwattsv7.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_pvwattsv7.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Pvwattsv7 model description**

.. automodule:: PySAM.Pvwattsv7
	:members:

Functions
===================================

.. autoclass:: PySAM.Pvwattsv7.Pvwattsv7
	:members:

SolarResource Group
===================================

.. autoclass:: PySAM.Pvwattsv7.Pvwattsv7.SolarResource
	:members:

Lifetime Group
===================================

.. autoclass:: PySAM.Pvwattsv7.Pvwattsv7.Lifetime
	:members:

SystemDesign Group
===================================

.. autoclass:: PySAM.Pvwattsv7.Pvwattsv7.SystemDesign
	:members:

AdjustmentFactors Group
===================================

.. autoclass:: PySAM.Pvwattsv7.Pvwattsv7.AdjustmentFactors
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.Pvwattsv7.Pvwattsv7.Outputs
	:members:

