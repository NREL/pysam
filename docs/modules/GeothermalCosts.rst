.. _GeothermalCosts:

GeothermalCosts
================

.. automodule:: PySAM.GeothermalCosts
	:members:

GeothermalCosts is a wrapper for the SSC compute module `cmod_geothermal_costs.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_geothermal_costs.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

- None

Functions
-----------

.. autoclass:: PySAM.GeothermalCosts.GeothermalCosts
	:members:

GeoHourly Group
----------------

.. autoclass:: PySAM.GeothermalCosts.GeothermalCosts.GeoHourly
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.GeothermalCosts.GeothermalCosts.Outputs
	:members:

