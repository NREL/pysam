.. _Geothermal:

Geothermal
**************************

Wrapper for SAM Simulation Core model: `cmod_geothermal.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_geothermal.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Geothermal model description**

.. automodule:: PySAM.Geothermal
	:members:

Functions
=========================

.. autoclass:: PySAM.Geothermal.Geothermal
	:members:

GeoHourly Group
==============

.. autoclass:: PySAM.Geothermal.Geothermal.GeoHourly
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.Geothermal.Geothermal.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Geothermal.Geothermal.Outputs
	:members:

