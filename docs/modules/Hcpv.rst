.. _Hcpv:

Hcpv
***********************************

Wrapper for SAM Simulation Core model: `cmod_hcpv.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_hcpv.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdepedent but the equations accounting for these
interdependencies that enforce consistency among these input parameters are not available in the PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - array_modules_per_tracker
 - array_num_inverters
 - array_num_trackers
 - inv_snl_pdco
 - module_a0
 - module_a1
 - module_a2
 - module_a3
 - module_a4
 - module_alignment_error
 - module_cell_area
 - module_concentration
 - module_flutter_loss_coeff
 - module_ncells
 - module_optical_error
 - module_reference
 - system_capacity

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**Hcpv model description**

.. automodule:: PySAM.Hcpv
	:members:

Functions
===================================

.. autoclass:: PySAM.Hcpv.Hcpv
	:members:

SolarResourceData Group
======================================================

.. autoclass:: PySAM.Hcpv.Hcpv.SolarResourceData
	:members:

PVWatts Group
======================================================

.. autoclass:: PySAM.Hcpv.Hcpv.PVWatts
	:members:

HCPVModule Group
======================================================

.. autoclass:: PySAM.Hcpv.Hcpv.HCPVModule
	:members:

InverterCECDatabase Group
======================================================

.. autoclass:: PySAM.Hcpv.Hcpv.InverterCECDatabase
	:members:

HCPVArray Group
======================================================

.. autoclass:: PySAM.Hcpv.Hcpv.HCPVArray
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.Hcpv.Hcpv.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Hcpv.Hcpv.Outputs
	:members:

