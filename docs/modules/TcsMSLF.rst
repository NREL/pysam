.. _TcsMSLF:

TcsMSLF
========

.. automodule:: PySAM.TcsMSLF
	:members:

TcsMSLF is a wrapper for the SSC compute module `cmod_tcsMSLF.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcsmslf.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

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

Functions
-----------

.. autoclass:: PySAM.TcsMSLF.TcsMSLF
	:members:

Weather Group
--------------

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.Weather
	:members:

Mslf Group
-----------

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.Mslf
	:members:

TouTranslator Group
--------------------

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.TouTranslator
	:members:

Controller Group
-----------------

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.Controller
	:members:

SolarField Group
-----------------

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.SolarField
	:members:

Powerblock Group
-----------------

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.Powerblock
	:members:

UserDefinedPC Group
--------------------

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.UserDefinedPC
	:members:

Enet Group
-----------

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.Enet
	:members:

AdjustmentFactors Group
------------------------

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.AdjustmentFactors
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.TcsMSLF.TcsMSLF.Outputs
	:members:

