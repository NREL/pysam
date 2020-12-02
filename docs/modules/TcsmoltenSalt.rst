.. _TcsmoltenSalt:

TcsmoltenSalt
***********************************

Wrapper for SAM Simulation Core model: `cmod_tcsmolten_salt.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcsmolten_salt.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdepedent but the equations accounting for these
interdependencies that enforce consistency among these input parameters are not available in the PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - D_rec
 - P_ref
 - T_htf_cold_des
 - T_htf_hot_des
 - aux_par
 - aux_par_0
 - aux_par_1
 - aux_par_2
 - aux_par_f
 - bop_par
 - bop_par_0
 - bop_par_1
 - bop_par_2
 - bop_par_f
 - bop_spec_cost
 - c_atm_0
 - c_atm_1
 - c_atm_2
 - c_atm_3
 - const_per_interest_rate1
 - const_per_interest_rate2
 - const_per_interest_rate3
 - const_per_interest_rate4
 - const_per_interest_rate5
 - const_per_months1
 - const_per_months2
 - const_per_months3
 - const_per_months4
 - const_per_months5
 - const_per_percent1
 - const_per_percent2
 - const_per_percent3
 - const_per_percent4
 - const_per_percent5
 - const_per_upfront_rate1
 - const_per_upfront_rate2
 - const_per_upfront_rate3
 - const_per_upfront_rate4
 - const_per_upfront_rate5
 - contingency_rate
 - cost_sf_fixed
 - dens_mirror
 - design_eff
 - dni_des
 - field_fl_props
 - field_model_type
 - fossil_spec_cost
 - gross_net_conversion_factor
 - h_tower
 - helio_area_tot
 - helio_height
 - helio_optical_error_mrad
 - helio_positions
 - helio_width
 - heliostat_spec_cost
 - is_dispatch
 - is_wlim_series
 - land_area_base
 - land_max
 - land_min
 - land_spec_cost
 - opt_algorithm
 - opt_flux_penalty
 - piping_length_const
 - piping_length_mult
 - piping_loss
 - plant_spec_cost
 - rec_cost_exp
 - rec_height
 - rec_htf
 - rec_ref_area
 - rec_ref_cost
 - sales_tax_frac
 - sales_tax_rate
 - site_spec_cost
 - solarm
 - tes_spec_cost
 - tower_exp
 - tower_fixed_cost
 - tshours
 - wlim_series

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**TcsmoltenSalt model description**

.. automodule:: PySAM.TcsmoltenSalt
	:members:

Functions
===================================

.. autoclass:: PySAM.TcsmoltenSalt.TcsmoltenSalt
	:members:

SolarResource Group
======================================================

.. autoclass:: PySAM.TcsmoltenSalt.TcsmoltenSalt.SolarResource
	:members:

TimeOfDeliveryFactors Group
======================================================

.. autoclass:: PySAM.TcsmoltenSalt.TcsmoltenSalt.TimeOfDeliveryFactors
	:members:

HeliostatField Group
======================================================

.. autoclass:: PySAM.TcsmoltenSalt.TcsmoltenSalt.HeliostatField
	:members:

SystemDesign Group
======================================================

.. autoclass:: PySAM.TcsmoltenSalt.TcsmoltenSalt.SystemDesign
	:members:

TowerAndReceiver Group
======================================================

.. autoclass:: PySAM.TcsmoltenSalt.TcsmoltenSalt.TowerAndReceiver
	:members:

SystemCosts Group
======================================================

.. autoclass:: PySAM.TcsmoltenSalt.TcsmoltenSalt.SystemCosts
	:members:

FinancialParameters Group
======================================================

.. autoclass:: PySAM.TcsmoltenSalt.TcsmoltenSalt.FinancialParameters
	:members:

ThermalStorage Group
======================================================

.. autoclass:: PySAM.TcsmoltenSalt.TcsmoltenSalt.ThermalStorage
	:members:

RADCOOL Group
======================================================

.. autoclass:: PySAM.TcsmoltenSalt.TcsmoltenSalt.RADCOOL
	:members:

PowerCycle Group
======================================================

.. autoclass:: PySAM.TcsmoltenSalt.TcsmoltenSalt.PowerCycle
	:members:

RankineCycle Group
======================================================

.. autoclass:: PySAM.TcsmoltenSalt.TcsmoltenSalt.RankineCycle
	:members:

SystemControl Group
======================================================

.. autoclass:: PySAM.TcsmoltenSalt.TcsmoltenSalt.SystemControl
	:members:

UserDefinedPowerCycle Group
======================================================

.. autoclass:: PySAM.TcsmoltenSalt.TcsmoltenSalt.UserDefinedPowerCycle
	:members:

SCO2Cycle Group
======================================================

.. autoclass:: PySAM.TcsmoltenSalt.TcsmoltenSalt.SCO2Cycle
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.TcsmoltenSalt.TcsmoltenSalt.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.TcsmoltenSalt.TcsmoltenSalt.Outputs
	:members:

