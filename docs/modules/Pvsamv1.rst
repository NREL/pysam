.. _Pvsamv1:

Pvsamv1
========

.. automodule:: PySAM.Pvsamv1
	:members:

Pvsamv1 is a wrapper for the SSC compute module `cmod_pvsamv1.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_pvsamv1.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

 - 6par_aisc

 - 6par_area

 - 6par_bvoc

 - 6par_imp

 - 6par_isc

 - 6par_vmp

 - 6par_voc

 - LeadAcid_q10_computed

 - LeadAcid_q20_computed

 - LeadAcid_qn_computed

 - batt_Qexp

 - batt_Qfull

 - batt_Qfull_flow

 - batt_Qnom

 - batt_Vnom_default

 - batt_ac_dc_efficiency

 - batt_ac_or_dc

 - batt_chem

 - batt_computed_bank_capacity

 - batt_computed_series

 - batt_computed_strings

 - batt_current_charge_max

 - batt_current_choice

 - batt_current_discharge_max

 - batt_dc_ac_efficiency

 - batt_dc_dc_efficiency

 - batt_dispatch_load_forecast_choice

 - batt_load_ac_forecast

 - batt_load_ac_forecast_escalation

 - batt_mass

 - batt_power_charge_max_kwac

 - batt_power_charge_max_kwdc

 - batt_power_discharge_max_kwac

 - batt_power_discharge_max_kwdc

 - batt_room_temperature_celsius

 - batt_surface_area

 - cec_area

 - cec_i_mp_ref

 - cec_module_length

 - cec_module_width

 - cec_v_mp_ref

 - cec_v_oc_ref

 - dispatch_manual_discharge

 - dispatch_manual_gridcharge

 - dispatch_manual_percent_discharge

 - dispatch_manual_percent_gridcharge

 - grid_curtailment

 - inv_cec_cg_c0

 - inv_cec_cg_c1

 - inv_cec_cg_c2

 - inv_cec_cg_c3

 - inv_cec_cg_eff_cec

 - inv_cec_cg_paco

 - inv_cec_cg_pdco

 - inv_cec_cg_psco

 - inv_cec_cg_vdco

 - inv_ds_eff

 - inv_ds_paco

 - inv_num_mppt

 - inv_pd_eff

 - inv_pd_paco

 - inv_pd_pdco

 - inv_snl_c0

 - inv_snl_c1

 - inv_snl_c2

 - inv_snl_c3

 - inv_snl_eff_cec

 - inv_snl_paco

 - inv_snl_pdco

 - inv_snl_pso

 - inv_snl_vdco

 - inverter_count

 - inverter_model

 - load

 - load_escalation

 - module_aspect_ratio

 - module_model

 - mppt_hi_inverter

 - mppt_low_inverter

 - sd11par_Vmp0

 - sd11par_Voc0

 - sd11par_area

 - snl_a

 - snl_a0

 - snl_a1

 - snl_a2

 - snl_a3

 - snl_a4

 - snl_aimp

 - snl_aisc

 - snl_area

 - snl_b

 - snl_b0

 - snl_b1

 - snl_b2

 - snl_b3

 - snl_b4

 - snl_b5

 - snl_bvmpo

 - snl_bvoco

 - snl_c0

 - snl_c1

 - snl_c2

 - snl_c3

 - snl_dtc

 - snl_fd

 - snl_impo

 - snl_isco

 - snl_mbvmp

 - snl_mbvoc

 - snl_module_structure

 - snl_n

 - snl_ref_a

 - snl_ref_b

 - snl_ref_dT

 - snl_series_cells

 - snl_vmpo

 - snl_voco

 - solar_resource_file

 - spe_area

 - spe_eff0

 - spe_eff1

 - spe_eff2

 - spe_eff3

 - spe_eff4

 - spe_rad0

 - spe_rad1

 - spe_rad2

 - spe_rad3

 - spe_rad4

 - spe_reference

 - spe_vmp

 - spe_voc

 - subarray1_gcr

 - subarray1_mod_orient

 - subarray1_modules_per_string

 - subarray1_monthly_tilt

 - subarray1_nmodx

 - subarray1_nmody

 - subarray1_nstrings

 - subarray1_shade_mode

 - subarray1_tilt

 - subarray1_track_mode

 - subarray2_enable

 - subarray2_gcr

 - subarray2_mod_orient

 - subarray2_modules_per_string

 - subarray2_monthly_tilt

 - subarray2_nmodx

 - subarray2_nmody

 - subarray2_nstrings

 - subarray2_shade_mode

 - subarray2_tilt

 - subarray2_track_mode

 - subarray3_enable

 - subarray3_gcr

 - subarray3_mod_orient

 - subarray3_modules_per_string

 - subarray3_monthly_tilt

 - subarray3_nmodx

 - subarray3_nmody

 - subarray3_nstrings

 - subarray3_shade_mode

 - subarray3_tilt

 - subarray3_track_mode

 - subarray4_enable

 - subarray4_gcr

 - subarray4_mod_orient

 - subarray4_modules_per_string

 - subarray4_monthly_tilt

 - subarray4_nmodx

 - subarray4_nmody

 - subarray4_nstrings

 - subarray4_shade_mode

 - subarray4_tilt

 - subarray4_track_mode

 - system_capacity

Functions
-----------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1
	:members:

SolarResource Group
--------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.SolarResource
	:members:

Losses Group
-------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Losses
	:members:

Lifetime Group
---------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Lifetime
	:members:

SystemDesign Group
-------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.SystemDesign
	:members:

Shading Group
--------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Shading
	:members:

Layout Group
-------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Layout
	:members:

Module Group
-------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Module
	:members:

SimpleEfficiencyModuleModel Group
----------------------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.SimpleEfficiencyModuleModel
	:members:

CECPerformanceModelWithModuleDatabase Group
--------------------------------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.CECPerformanceModelWithModuleDatabase
	:members:

CECPerformanceModelWithUserEnteredSpecifications Group
-------------------------------------------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.CECPerformanceModelWithUserEnteredSpecifications
	:members:

SandiaPVArrayPerformanceModelWithModuleDatabase Group
------------------------------------------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.SandiaPVArrayPerformanceModelWithModuleDatabase
	:members:

IEC61853SingleDiodeModel Group
-------------------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.IEC61853SingleDiodeModel
	:members:

MermoudLejeuneSingleDiodeModel Group
-------------------------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.MermoudLejeuneSingleDiodeModel
	:members:

Inverter Group
---------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Inverter
	:members:

InverterCECDatabase Group
--------------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.InverterCECDatabase
	:members:

InverterCECCoefficientGenerator Group
--------------------------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.InverterCECCoefficientGenerator
	:members:

InverterDatasheet Group
------------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.InverterDatasheet
	:members:

InverterPartLoadCurve Group
----------------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.InverterPartLoadCurve
	:members:

InverterMermoudLejeuneModel Group
----------------------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.InverterMermoudLejeuneModel
	:members:

BatterySystem Group
--------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.BatterySystem
	:members:

Load Group
-----------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Load
	:members:

PVLosses Group
---------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.PVLosses
	:members:

AdjustmentFactors Group
------------------------

.. autoclass:: PySAM.AdjustmentFactors.AdjustmentFactors
	:members:
	:noindex:

BatteryCell Group
------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.BatteryCell
	:members:

BatteryDispatch Group
----------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.BatteryDispatch
	:members:

SystemCosts Group
------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.SystemCosts
	:members:

FuelCell Group
---------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.FuelCell
	:members:

PriceSignal Group
------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.PriceSignal
	:members:

Revenue Group
--------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Revenue
	:members:

ElectricityRates Group
-----------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.ElectricityRates
	:members:

GridLimits Group
-----------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.GridLimits
	:members:

HybridCosts Group
------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.HybridCosts
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Outputs
	:members:

