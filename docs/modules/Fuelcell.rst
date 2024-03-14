.. _Fuelcell:

Fuelcell
=========

.. automodule:: PySAM.Fuelcell
	:members:

Fuelcell is a wrapper for the SSC compute module `cmod_fuelcell.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_fuelcell.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

 - dispatch_manual_fuelcelldischarge

 - dispatch_manual_percent_fc_discharge

 - dispatch_manual_units_fc_discharge

 - fuelcell_degradation

 - fuelcell_dispatch

 - fuelcell_dynamic_response_down

 - fuelcell_dynamic_response_up

 - fuelcell_fuel_available

 - fuelcell_fuel_type

 - fuelcell_lhv

 - fuelcell_number_of_units

 - fuelcell_unit_max_power

 - fuelcell_unit_min_power

Functions
-----------

.. autoclass:: PySAM.Fuelcell.Fuelcell
	:members:

Lifetime Group
---------------

.. autoclass:: PySAM.Fuelcell.Fuelcell.Lifetime
	:members:

Common Group
-------------

.. autoclass:: PySAM.Fuelcell.Fuelcell.Common
	:members:

Load Group
-----------

.. autoclass:: PySAM.Fuelcell.Fuelcell.Load
	:members:

FuelCell Group
---------------

.. autoclass:: PySAM.Fuelcell.Fuelcell.FuelCell
	:members:

HybridCosts Group
------------------

.. autoclass:: PySAM.Fuelcell.Fuelcell.HybridCosts
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.Fuelcell.Fuelcell.Outputs
	:members:

