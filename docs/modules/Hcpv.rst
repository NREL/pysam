.. _Hcpv:

Hcpv
=====

.. automodule:: PySAM.Hcpv
	:members:

Hcpv is a wrapper for the SSC compute module `cmod_hcpv.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_hcpv.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

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

Functions
-----------

.. autoclass:: PySAM.Hcpv.Hcpv
	:members:

SolarResourceData Group
------------------------

.. autoclass:: PySAM.Hcpv.Hcpv.SolarResourceData
	:members:

PVWatts Group
--------------

.. autoclass:: PySAM.Hcpv.Hcpv.PVWatts
	:members:

HCPVModule Group
-----------------

.. autoclass:: PySAM.Hcpv.Hcpv.HCPVModule
	:members:

InverterCECDatabase Group
--------------------------

.. autoclass:: PySAM.Hcpv.Hcpv.InverterCECDatabase
	:members:

HCPVArray Group
----------------

.. autoclass:: PySAM.Hcpv.Hcpv.HCPVArray
	:members:

AdjustmentFactors Group
------------------------

.. autoclass:: PySAM.AdjustmentFactors.AdjustmentFactors
	:members:
	:noindex:

Outputs Group
--------------

.. autoclass:: PySAM.Hcpv.Hcpv.Outputs
	:members:

