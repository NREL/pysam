.. _Pvwattsv1:

Pvwattsv1
**************************

Wrapper for SAM Simulation Core model: `cmod_pvwattsv1.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_pvwattsv1.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Pvwattsv1 model description**

.. automodule:: PySAM.Pvwattsv1
	:members:

Functions
=========================

.. autoclass:: PySAM.Pvwattsv1.Pvwattsv1
	:members:

Weather Group
==============

.. autoclass:: PySAM.Pvwattsv1.Pvwattsv1.Weather
	:members:

PVWatts Group
==============

.. autoclass:: PySAM.Pvwattsv1.Pvwattsv1.PVWatts
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.Pvwattsv1.Pvwattsv1.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Pvwattsv1.Pvwattsv1.Outputs
	:members:

