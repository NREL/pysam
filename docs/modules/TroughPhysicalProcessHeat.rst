.. _TroughPhysicalProcessHeat:

TroughPhysicalProcessHeat
***********************************

Wrapper for SAM Simulation Core model: `cmod_trough_physical_process_heat.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_trough_physical_process_heat.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - A_aperture
 - Ave_Focal_Length
 - ColperSCA
 - D_2
 - D_cpnt
 - Design_loss
 - Dirt_HCE
 - Dirt_mirror
 - Distance_SCA
 - Error
 - Fluid
 - GeomEffects
 - HCE_FieldFrac
 - IAM_matrix
 - I_bn_des
 - K_cpnt
 - L_SCA
 - L_aperture
 - L_cpnt
 - Rho_mirror_clean
 - Row_Distance
 - SCADefocusArray
 - SCAInfoArray
 - SCA_drives_elec
 - Shadowing
 - T_loop_in_des
 - T_loop_out
 - Tau_envelope
 - TrackingError
 - Type_cpnt
 - W_aperture
 - alpha_abs
 - azimuth
 - disp_wlim_maxspec
 - field_fl_props
 - fluid_dens_inlet_temp
 - fluid_dens_outlet_temp
 - is_dispatch
 - is_wlim_series
 - lat
 - m_dot_htfmax
 - m_dot_htfmin
 - nLoops
 - nSCA
 - non_solar_field_land_area_multiplier
 - q_pb_design
 - radio_sm_or_area
 - solar_mult
 - specified_solar_multiple
 - specified_total_aperture
 - tilt
 - trough_loop_control
 - tshours
 - wlim_series

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**TroughPhysicalProcessHeat model description**

.. automodule:: PySAM.TroughPhysicalProcessHeat
	:members:

Functions
===================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat
	:members:

Weather Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.Weather
	:members:

SolarField Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.SolarField
	:members:

Controller Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.Controller
	:members:

SystemDesign Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.SystemDesign
	:members:

TES Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.TES
	:members:

TES2tank Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.TES2tank
	:members:

Tou Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.Tou
	:members:

System Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.System
	:members:

Powerblock Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.Powerblock
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.Outputs
	:members:

