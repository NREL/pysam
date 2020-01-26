.. _GeothermalCosts:

GeothermalCosts
**************************

Wrapper for SAM Simulation Core model: `cmod_geothermal_costs.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_geothermal_costs.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**GeothermalCosts model description**

.. automodule:: PySAM.GeothermalCosts
	:members:

Functions
=========================

.. autoclass:: PySAM.GeothermalCosts.GeothermalCosts
	:members:

GeoHourly Group
==============

.. autoclass:: PySAM.GeothermalCosts.GeothermalCosts.GeoHourly
	:members:

Outputs Group
==============

.. autoclass:: PySAM.GeothermalCosts.GeothermalCosts.Outputs
	:members:

