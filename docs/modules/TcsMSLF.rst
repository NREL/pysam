.. _TcsMSLF:

TcsMSLF
***********************************

Wrapper for SAM Simulation Core model: `cmod_tcsMSLF.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcsmslf.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - A_aperture
 - Dirt_mirror
 - Error
 - Fluid
 - GeomEffects
 - I_bn_des
 - L_mod
 - P_ref
 - T_amb_sf_des
 - T_field_in_des
 - T_field_out_des
 - T_htf_cold_ref
 - T_htf_hot_ref
 - T_loop_in_des
 - T_loop_out
 - T_tank_cold_ini
 - T_tank_hot_ini
 - TrackingError
 - V_tank_hot_ini
 - W_pb_design
 - dt_cold
 - dt_hot
 - eta_ref
 - field_fluid
 - fthr_ok
 - fthrok
 - is_hx
 - nLoops
 - nMod
 - nSCA
 - pb_rated_cap
 - q_max_aux
 - q_pb_design
 - reflectivity
 - solar_mult
 - solarm
 - store_fl_props
 - store_fluid
 - system_capacity
 - tes_temp
 - tshours
 - vol_tank

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**TcsMSLF model description**

.. automodule:: PySAM.TcsMSLF
	:members:

Functions
===================================

.. autoclass:: PySAM.TcsMSLF.TcsMSLF
	:members:

Weather Group
======================================================

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.Weather
	:members:

Mslf Group
======================================================

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.Mslf
	:members:

TouTranslator Group
======================================================

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.TouTranslator
	:members:

Controller Group
======================================================

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.Controller
	:members:

SolarField Group
======================================================

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.SolarField
	:members:

Powerblock Group
======================================================

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.Powerblock
	:members:

UserDefinedPC Group
======================================================

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.UserDefinedPC
	:members:

Enet Group
======================================================

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.Enet
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.Outputs
	:members:

