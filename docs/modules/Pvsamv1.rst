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

 - 6par_bvoc

 - 6par_imp

 - 6par_isc

 - 6par_vmp

 - 6par_voc

 - cec_area

 - cec_i_mp_ref

 - cec_module_length

 - cec_module_width

 - cec_v_mp_ref

 - cec_v_oc_ref

 - inv_cec_cg_c0

 - inv_cec_cg_c1

 - inv_cec_cg_c2

 - inv_cec_cg_c3

 - inv_cec_cg_eff_cec

 - inv_cec_cg_paco

 - inv_cec_cg_pdco

 - inv_cec_cg_psco

 - inv_cec_cg_vdco

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

 - module_model

 - mppt_hi_inverter

 - mppt_low_inverter

 - sd11par_Vmp0

 - sd11par_Voc0

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

 - subarray1_modules_per_string

 - subarray1_nstrings

 - subarray2_enable

 - subarray2_modules_per_string

 - subarray2_nstrings

 - subarray3_enable

 - subarray3_modules_per_string

 - subarray3_nstrings

 - subarray4_enable

 - subarray4_modules_per_string

 - subarray4_nstrings

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

AdjustmentFactors Group
------------------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.AdjustmentFactors
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Outputs
	:members:

