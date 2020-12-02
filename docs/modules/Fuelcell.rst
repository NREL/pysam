.. _Fuelcell:

Fuelcell
***********************************

Wrapper for SAM Simulation Core model: `cmod_fuelcell.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_fuelcell.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdepedent but the equations accounting for these
interdependencies that enforce consistency among these input parameters are not available in the PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

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

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**Fuelcell model description**

.. automodule:: PySAM.Fuelcell
	:members:

Functions
===================================

.. autoclass:: PySAM.Fuelcell.Fuelcell
	:members:

Lifetime Group
======================================================

.. autoclass:: PySAM.Fuelcell.Fuelcell.Lifetime
	:members:

Common Group
======================================================

.. autoclass:: PySAM.Fuelcell.Fuelcell.Common
	:members:

Load Group
======================================================

.. autoclass:: PySAM.Fuelcell.Fuelcell.Load
	:members:

FuelCell Group
======================================================

.. autoclass:: PySAM.Fuelcell.Fuelcell.FuelCell
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Fuelcell.Fuelcell.Outputs
	:members:

