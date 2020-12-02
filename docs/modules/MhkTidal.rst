.. _MhkTidal:

MhkTidal
***********************************

Wrapper for SAM Simulation Core model: `cmod_mhk_tidal.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_mhk_tidal.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdepedent but the equations accounting for these
interdependencies that enforce consistency among these input parameters are not available in the PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - balance_of_system_cost_total
 - device_costs_total
 - financial_cost_total
 - number_devices
 - tidal_power_curve
 - total_operating_cost

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**MhkTidal model description**

.. automodule:: PySAM.MhkTidal
	:members:

Functions
===================================

.. autoclass:: PySAM.MhkTidal.MhkTidal
	:members:

MHKTidal Group
======================================================

.. autoclass:: PySAM.MhkTidal.MhkTidal.MHKTidal
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.MhkTidal.MhkTidal.Outputs
	:members:

