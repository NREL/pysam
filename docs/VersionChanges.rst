.. Version Changes:

Changes to Modules with Version 2.3.0
===============================================

This document shows the changes for each Module

Battery
************************************************

Battery New Default files:

	 - StandaloneBatteryAllEquityPartnershipFlip
	 - StandaloneBatteryCommercial
	 - StandaloneBatteryHostDeveloper
	 - StandaloneBatteryLeveragedPartnershipFlip
	 - StandaloneBatteryMerchantPlant
	 - StandaloneBatteryResidential
	 - StandaloneBatterySaleLeaseback
	 - StandaloneBatterySingleOwner
	 - StandaloneBatteryThirdParty

Battery Modified Variables:

	New variables:

		 - batt_Vcut
		 - batt_dispatch_auto_btm_can_discharge_to_grid
		 - batt_dispatch_auto_can_clipcharge
		 - batt_dispatch_charge_only_system_exceeds_load
		 - batt_dispatch_discharge_only_load_exceeds_system
		 - batt_dispatch_load_forecast_choice
		 - batt_dispatch_pvs_ac_lb
		 - batt_dispatch_pvs_ac_lb_enable
		 - batt_dispatch_pvs_ac_ub
		 - batt_dispatch_pvs_ac_ub_enable
		 - batt_dispatch_pvs_curtail_as_control
		 - batt_dispatch_pvs_curtail_if_violation
		 - batt_dispatch_pvs_forecast_shift_periods
		 - batt_dispatch_pvs_kf
		 - batt_dispatch_pvs_ki
		 - batt_dispatch_pvs_kp
		 - batt_dispatch_pvs_max_ramp
		 - batt_dispatch_pvs_nameplate_ac
		 - batt_dispatch_pvs_short_forecast_enable
		 - batt_dispatch_pvs_soc_rest
		 - batt_dispatch_pvs_timestep_multiplier
		 - batt_dispatch_wf_forecast_choice
		 - batt_life_model
		 - batt_load_ac_forecast
		 - batt_load_ac_forecast_escalation
		 - batt_minimum_outage_SOC
		 - batt_pv_ac_forecast
		 - batt_pv_clipping_forecast
		 - crit_load
		 - crit_load_escalation
		 - dispatch_manual_btm_discharge_to_grid
		 - en_standalone_batt
		 - enable_interconnection_limit
		 - grid_curtailment
		 - grid_interconnection_limit_kwac
		 - grid_outage
		 - om_batt_replacement_cost
		 - om_replacement_cost_escal
		 - rate_escalation
		 - run_resiliency_calcs
		 - ur_annual_min_charge
		 - ur_billing_demand_lookback_percentages
		 - ur_billing_demand_lookback_period
		 - ur_billing_demand_minimum
		 - ur_dc_billing_demand_periods
		 - ur_dc_enable
		 - ur_dc_flat_mat
		 - ur_dc_sched_weekday
		 - ur_dc_sched_weekend
		 - ur_dc_tou_mat
		 - ur_ec_sched_weekday
		 - ur_ec_sched_weekend
		 - ur_ec_tou_mat
		 - ur_en_ts_buy_rate
		 - ur_en_ts_sell_rate
		 - ur_enable_billing_demand
		 - ur_metering_option
		 - ur_monthly_fixed_charge
		 - ur_monthly_min_charge
		 - ur_nm_credit_month
		 - ur_nm_credit_rollover
		 - ur_nm_yearend_sell_rate
		 - ur_ts_buy_rate
		 - ur_ts_sell_rate
		 - ur_yearzero_usage_peaks

	Removed variables:

		 - batt_auto_gridcharge_max_daily
		 - om_replacement_cost1

Battery Modified Default Values:

	 - BatteryStateful_LeadAcid

		['voltage_matrix']

	 - Battery_FuelCellCommercial

		['batt_room_temperature_celsius', 'batt_power_discharge_max_kwac', 'batt_calendar_c', 'batt_calendar_choice', 'batt_power_charge_max_kwac']

	 - Battery_FuelCellSingleOwner

		['ur_dc_sched_weekday', 'batt_room_temperature_celsius', 'batt_minimum_SOC', 'batt_power_discharge_max_kwac', 'batt_calendar_c', 'ur_ec_sched_weekend', 'ur_ec_sched_weekday', 'ur_dc_sched_weekend', 'ur_nm_yearend_sell_rate', 'batt_meter_position', 'ur_metering_option', 'ur_dc_enable', 'ur_dc_tou_mat', 'ur_ec_tou_mat', 'batt_calendar_choice', 'ppa_price_input', 'batt_power_charge_max_kwac', 'ur_monthly_fixed_charge']

	 - Battery_GenericBatteryAllEquityPartnershipFlip

		['batt_room_temperature_celsius', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'dispatch_manual_sched', 'batt_calendar_c', 'LeadAcid_q10_computed', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'batt_dispatch_choice', 'dispatch_tod_factors', 'dispatch_manual_sched_weekend', 'batt_h_to_ambient', 'batt_dispatch_auto_can_clipcharge', 'batt_Qfull_flow']

	 - Battery_GenericBatteryCommercial

		['batt_minimum_SOC', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'batt_calendar_c', 'LeadAcid_q10_computed', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'batt_surface_area', 'batt_computed_bank_capacity', 'batt_power_charge_max_kwac', 'batt_power_charge_max_kwdc', 'batt_computed_strings', 'batt_current_charge_max', 'batt_mass', 'batt_current_discharge_max', 'batt_Qfull_flow']

	 - Battery_GenericBatteryHostDeveloper

		['batt_minimum_SOC', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'batt_calendar_c', 'LeadAcid_q10_computed', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'batt_surface_area', 'batt_computed_bank_capacity', 'batt_power_charge_max_kwac', 'batt_power_charge_max_kwdc', 'batt_computed_strings', 'batt_current_charge_max', 'batt_mass', 'batt_current_discharge_max', 'batt_Qfull_flow']

	 - Battery_GenericBatteryLeveragedPartnershipFlip

		['batt_room_temperature_celsius', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'dispatch_manual_sched', 'batt_calendar_c', 'LeadAcid_q10_computed', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'batt_dispatch_choice', 'dispatch_tod_factors', 'dispatch_manual_sched_weekend', 'batt_h_to_ambient', 'batt_dispatch_auto_can_clipcharge', 'batt_Qfull_flow']

	 - Battery_GenericBatteryMerchantPlant

		['batt_room_temperature_celsius', 'mp_ancserv2_revenue', 'mp_ancserv4_revenue', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'dispatch_manual_sched', 'batt_calendar_c', 'LeadAcid_q10_computed', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'batt_dispatch_choice', 'mp_ancserv1_revenue', 'dispatch_manual_sched_weekend', 'batt_h_to_ambient', 'mp_ancserv3_revenue', 'mp_energy_market_revenue', 'batt_Qfull_flow']

	 - Battery_GenericBatteryResidential

		['batt_minimum_SOC', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'batt_calendar_c', 'LeadAcid_q10_computed', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'batt_surface_area', 'batt_computed_bank_capacity', 'batt_dispatch_choice', 'batt_power_charge_max_kwac', 'batt_power_charge_max_kwdc', 'batt_computed_strings', 'batt_current_charge_max', 'batt_mass', 'batt_current_discharge_max', 'batt_Qfull_flow']

	 - Battery_GenericBatterySaleLeaseback

		['batt_room_temperature_celsius', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'dispatch_manual_sched', 'batt_calendar_c', 'LeadAcid_q10_computed', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'batt_dispatch_choice', 'dispatch_tod_factors', 'dispatch_manual_sched_weekend', 'batt_h_to_ambient', 'batt_dispatch_auto_can_clipcharge', 'batt_Qfull_flow']

	 - Battery_GenericBatterySingleOwner

		['batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'dispatch_manual_sched', 'batt_calendar_c', 'LeadAcid_q10_computed', 'LeadAcid_q20_computed', 'ur_nm_yearend_sell_rate', 'batt_power_discharge_max_kwdc', 'batt_dispatch_choice', 'ur_dc_tou_mat', 'dispatch_manual_sched_weekend', 'ur_ec_tou_mat', 'batt_h_to_ambient', 'batt_dispatch_auto_can_clipcharge', 'batt_Qfull_flow']

	 - Battery_GenericBatteryThirdParty

		['batt_minimum_SOC', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'batt_calendar_c', 'LeadAcid_q10_computed', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'batt_surface_area', 'batt_computed_bank_capacity', 'batt_dispatch_choice', 'batt_power_charge_max_kwac', 'batt_power_charge_max_kwdc', 'batt_computed_strings', 'batt_current_charge_max', 'batt_mass', 'batt_current_discharge_max', 'batt_Qfull_flow']

	 - Battwatts_PVWattsBatteryCommercial

		['batt_simple_kw', 'batt_simple_kwh']

	 - Battwatts_PVWattsBatteryHostDeveloper

		['batt_simple_kw', 'batt_simple_kwh']

	 - Battwatts_PVWattsBatteryResidential

		['batt_simple_kw', 'batt_simple_kwh']

	 - Battwatts_PVWattsBatteryThirdParty

		['batt_simple_kw', 'batt_simple_kwh']

	 - Cashloan_GenericBatteryCommercial

		['loan_rate', 'battery_per_kWh', 'itc_fed_percent', 'batt_computed_bank_capacity', 'total_installed_cost']

	 - Cashloan_GenericBatteryResidential

		['loan_rate', 'battery_per_kWh', 'batt_computed_bank_capacity', 'federal_tax_rate', 'total_installed_cost', 'om_capacity']

	 - Cashloan_PVBatteryCommercial

		['loan_rate', 'battery_per_kWh', 'batt_computed_bank_capacity', 'system_capacity', 'total_installed_cost']

	 - Cashloan_PVBatteryResidential

		['loan_rate', 'battery_per_kWh', 'batt_computed_bank_capacity', 'federal_tax_rate', 'total_installed_cost', 'om_capacity']

	 - Cashloan_PVWattsBatteryCommercial

		['battery_per_kWh', 'system_capacity', 'degradation', 'total_installed_cost', 'om_capacity']

	 - Cashloan_PVWattsBatteryResidential

		['battery_per_kWh', 'federal_tax_rate', 'system_capacity', 'degradation', 'total_installed_cost', 'om_capacity']

	 - Equpartflip_GenericBatteryAllEquityPartnershipFlip

		['equip1_reserve_cost', 'battery_per_kWh', 'reserves_interest', 'ppa_escalation', 'equip1_reserve_freq', 'insurance_rate', 'total_installed_cost', 'construction_financing_cost', 'om_capacity']

	 - Equpartflip_PVBatteryAllEquityPartnershipFlip

		['equip1_reserve_cost', 'battery_per_kWh', 'reserves_interest', 'ppa_escalation', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'ppa_price_input', 'total_installed_cost', 'construction_financing_cost', 'om_capacity']

	 - HostDeveloper_GenericBatteryHostDeveloper

		['equip1_reserve_cost', 'battery_per_kWh', 'reserves_interest', 'itc_fed_percent', 'batt_computed_bank_capacity', 'equip1_reserve_freq', 'total_installed_cost', 'term_int_rate', 'construction_financing_cost']

	 - HostDeveloper_PVBatteryHostDeveloper

		['equip1_reserve_cost', 'battery_per_kWh', 'batt_computed_bank_capacity', 'equip1_reserve_freq', 'system_capacity', 'total_installed_cost', 'construction_financing_cost']

	 - HostDeveloper_PVWattsBatteryHostDeveloper

		['battery_per_kWh', 'system_capacity', 'degradation', 'total_installed_cost', 'construction_financing_cost', 'om_capacity']

	 - Levpartflip_GenericBatteryLeveragedPartnershipFlip

		['equip1_reserve_cost', 'battery_per_kWh', 'reserves_interest', 'ppa_escalation', 'equip1_reserve_freq', 'insurance_rate', 'total_installed_cost', 'term_int_rate', 'construction_financing_cost', 'om_capacity']

	 - Levpartflip_PVBatteryLeveragedPartnershipFlip

		['equip1_reserve_cost', 'battery_per_kWh', 'reserves_interest', 'ppa_escalation', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'ppa_price_input', 'total_installed_cost', 'term_int_rate', 'construction_financing_cost', 'om_capacity']

	 - Merchantplant_GenericBatteryMerchantPlant

		['mp_ancserv2_revenue', 'equip1_reserve_cost', 'mp_ancserv4_revenue', 'battery_per_kWh', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate', 'mp_ancserv1_revenue', 'total_installed_cost', 'mp_ancserv3_revenue', 'term_int_rate', 'mp_energy_market_revenue', 'construction_financing_cost', 'cp_battery_nameplate', 'om_capacity']

	 - Merchantplant_PVBatteryMerchantPlant

		['mp_ancserv2_revenue', 'equip1_reserve_cost', 'mp_ancserv4_revenue', 'battery_per_kWh', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'mp_ancserv1_revenue', 'total_installed_cost', 'mp_ancserv3_revenue', 'term_int_rate', 'mp_energy_market_revenue', 'cp_system_nameplate', 'construction_financing_cost', 'cp_battery_nameplate', 'om_capacity']

	 - Pvsamv1_PVBatteryAllEquityPartnershipFlip

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'dispatch_manual_sched', 'inverter_count', 'LeadAcid_q10_computed', 'inv_tdc_plc', 'batt_calendar_c', 'cec_i_o_ref', 'batt_surface_area', 'batt_dispatch_choice', 'system_capacity', 'ppa_price_input', 'batt_Qfull_flow', 'batt_room_temperature_celsius', 'subarray1_nstrings', 'use_wf_albedo', 'subarray1_tilt', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'dispatch_manual_sched_weekend', 'cec_r_sh_ref', 'inv_snl_c0', 'inv_tdc_cec_db', 'inv_tdc_ds', 'batt_h_to_ambient', 'subarray1_track_mode']

	 - Pvsamv1_PVBatteryCommercial

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'inverter_count', 'LeadAcid_q10_computed', 'inv_tdc_plc', 'batt_power_charge_max_kwac', 'batt_power_charge_max_kwdc', 'batt_computed_strings', 'batt_calendar_c', 'cec_i_o_ref', 'batt_surface_area', 'system_capacity', 'batt_current_charge_max', 'batt_current_discharge_max', 'batt_Qfull_flow', 'subarray1_nstrings', 'use_wf_albedo', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'cec_r_sh_ref', 'inv_snl_c0', 'batt_minimum_SOC', 'inv_tdc_cec_db', 'batt_computed_bank_capacity', 'batt_target_power_monthly', 'inv_tdc_ds', 'batt_mass']

	 - Pvsamv1_PVBatteryHostDeveloper

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'inverter_count', 'LeadAcid_q10_computed', 'inv_tdc_plc', 'batt_power_charge_max_kwac', 'batt_power_charge_max_kwdc', 'batt_computed_strings', 'batt_calendar_c', 'cec_i_o_ref', 'batt_surface_area', 'system_capacity', 'batt_current_charge_max', 'batt_current_discharge_max', 'batt_Qfull_flow', 'subarray1_nstrings', 'use_wf_albedo', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'cec_r_sh_ref', 'inv_snl_c0', 'batt_minimum_SOC', 'inv_tdc_cec_db', 'batt_computed_bank_capacity', 'inv_tdc_ds', 'batt_mass']

	 - Pvsamv1_PVBatteryLeveragedPartnershipFlip

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'dispatch_manual_sched', 'inverter_count', 'LeadAcid_q10_computed', 'inv_tdc_plc', 'batt_calendar_c', 'cec_i_o_ref', 'batt_surface_area', 'batt_dispatch_choice', 'system_capacity', 'ppa_price_input', 'batt_Qfull_flow', 'batt_room_temperature_celsius', 'subarray1_nstrings', 'use_wf_albedo', 'subarray1_tilt', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'dispatch_manual_sched_weekend', 'cec_r_sh_ref', 'inv_snl_c0', 'inv_tdc_cec_db', 'inv_tdc_ds', 'batt_h_to_ambient', 'subarray1_track_mode']

	 - Pvsamv1_PVBatteryMerchantPlant

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'dispatch_manual_sched', 'inverter_count', 'LeadAcid_q10_computed', 'inv_tdc_plc', 'mp_ancserv4_revenue', 'batt_calendar_c', 'cec_i_o_ref', 'batt_surface_area', 'batt_dispatch_choice', 'system_capacity', 'mp_ancserv1_revenue', 'mp_ancserv3_revenue', 'mp_energy_market_revenue', 'batt_Qfull_flow', 'batt_room_temperature_celsius', 'subarray1_nstrings', 'use_wf_albedo', 'subarray1_tilt', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'dispatch_manual_sched_weekend', 'cec_r_sh_ref', 'inv_snl_c0', 'mp_ancserv2_revenue', 'inv_tdc_cec_db', 'inv_tdc_ds', 'batt_h_to_ambient', 'subarray1_track_mode']

	 - Pvsamv1_PVBatteryResidential

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'subarray3_mismatch_loss', 'LeadAcid_q10_computed', 'inv_tdc_plc', 'batt_power_charge_max_kwac', 'batt_power_charge_max_kwdc', 'batt_computed_strings', 'dcoptimizer_loss', 'batt_calendar_c', 'cec_i_o_ref', 'batt_surface_area', 'batt_dispatch_choice', 'batt_current_charge_max', 'batt_current_discharge_max', 'batt_Qfull_flow', 'use_wf_albedo', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'cec_r_sh_ref', 'subarray2_mismatch_loss', 'cec_r_s', 'inv_snl_c0', 'batt_minimum_SOC', 'inv_tdc_cec_db', 'batt_computed_bank_capacity', 'subarray4_mismatch_loss', 'inv_tdc_ds', 'batt_mass', 'subarray1_mismatch_loss']

	 - Pvsamv1_PVBatterySaleLeaseback

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'dispatch_manual_sched', 'inverter_count', 'LeadAcid_q10_computed', 'inv_tdc_plc', 'batt_calendar_c', 'cec_i_o_ref', 'batt_surface_area', 'batt_dispatch_choice', 'system_capacity', 'ppa_price_input', 'batt_Qfull_flow', 'batt_room_temperature_celsius', 'subarray1_nstrings', 'use_wf_albedo', 'subarray1_tilt', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'dispatch_manual_sched_weekend', 'cec_r_sh_ref', 'inv_snl_c0', 'inv_tdc_cec_db', 'inv_tdc_ds', 'batt_h_to_ambient', 'subarray1_track_mode']

	 - Pvsamv1_PVBatterySingleOwner

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'batt_power_discharge_max_kwac', 'dispatch_manual_sched', 'inverter_count', 'inv_tdc_plc', 'ur_ec_tou_mat', 'batt_power_charge_max_kwac', 'batt_power_charge_max_kwdc', 'batt_computed_strings', 'batt_calendar_c', 'cec_i_o_ref', 'batt_surface_area', 'batt_dispatch_choice', 'system_capacity', 'ppa_price_input', 'batt_current_charge_max', 'batt_current_discharge_max', 'batt_Qfull_flow', 'subarray1_nstrings', 'use_wf_albedo', 'subarray1_tilt', 'ur_nm_yearend_sell_rate', 'batt_power_discharge_max_kwdc', 'dispatch_manual_sched_weekend', 'cec_r_sh_ref', 'inv_snl_c0', 'inv_tdc_cec_db', 'batt_computed_bank_capacity', 'inv_tdc_ds', 'ur_dc_tou_mat', 'batt_h_to_ambient', 'batt_mass', 'subarray1_track_mode']

	 - Pvsamv1_PVBatteryThirdParty

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'inverter_count', 'subarray3_mismatch_loss', 'LeadAcid_q10_computed', 'inv_tdc_plc', 'batt_power_charge_max_kwac', 'batt_power_charge_max_kwdc', 'batt_computed_strings', 'dcoptimizer_loss', 'batt_calendar_c', 'cec_i_o_ref', 'batt_surface_area', 'batt_dispatch_choice', 'system_capacity', 'batt_current_charge_max', 'batt_current_discharge_max', 'batt_Qfull_flow', 'subarray1_nstrings', 'use_wf_albedo', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'cec_r_sh_ref', 'subarray2_mismatch_loss', 'cec_r_s', 'inv_snl_c0', 'batt_minimum_SOC', 'inv_tdc_cec_db', 'batt_computed_bank_capacity', 'subarray4_mismatch_loss', 'inv_tdc_ds', 'batt_mass', 'subarray1_mismatch_loss']

	 - Saleleaseback_GenericBatterySaleLeaseback

		['equip1_reserve_cost', 'battery_per_kWh', 'reserves_interest', 'ppa_escalation', 'equip1_reserve_freq', 'insurance_rate', 'total_installed_cost', 'construction_financing_cost', 'om_capacity']

	 - Saleleaseback_PVBatterySaleLeaseback

		['equip1_reserve_cost', 'battery_per_kWh', 'reserves_interest', 'ppa_escalation', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'ppa_price_input', 'total_installed_cost', 'construction_financing_cost', 'om_capacity']

	 - Singleowner_GenericBatterySingleOwner

		['equip1_reserve_cost', 'battery_per_kWh', 'reserves_interest', 'ppa_escalation', 'equip1_reserve_freq', 'insurance_rate', 'total_installed_cost', 'term_int_rate', 'construction_financing_cost', 'cp_battery_nameplate', 'om_capacity']

	 - Singleowner_PVBatterySingleOwner

		['equip1_reserve_cost', 'battery_per_kWh', 'reserves_interest', 'ppa_escalation', 'batt_computed_bank_capacity', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'ppa_price_input', 'total_installed_cost', 'term_int_rate', 'cp_system_nameplate', 'construction_financing_cost', 'om_capacity']

	 - Thirdpartyownership_PVWattsBatteryThirdParty

		['degradation']

	 - Utilityrate5_GenericBatterySingleOwner

		['ur_dc_tou_mat', 'ur_nm_yearend_sell_rate', 'ur_ec_tou_mat']

	 - Utilityrate5_PVBatterySingleOwner

		['ur_dc_tou_mat', 'ur_nm_yearend_sell_rate', 'ur_ec_tou_mat']

	 - Utilityrate5_PVWattsBatteryCommercial

		['degradation']

	 - Utilityrate5_PVWattsBatteryHostDeveloper

		['degradation']

	 - Utilityrate5_PVWattsBatteryResidential

		['degradation']

	 - Utilityrate5_PVWattsBatteryThirdParty

		['degradation']



BatteryStateful
************************************************

BatteryStateful New Default files:

	 - LMOLTO

BatteryStateful Modified Variables:

	New variables:

		 - Vcut
		 - life_model

BatteryStateful Modified Default Values:

	 - BatteryStateful_LeadAcid

		['voltage_matrix']



Battwatts
************************************************

Battwatts Modified Variables:

	New variables:

		 - enable_interconnection_limit
		 - grid_curtailment
		 - grid_interconnection_limit_kwac
		 - grid_outage
		 - run_resiliency_calcs

Battwatts Modified Default Values:

	 - Battwatts_PVWattsBatteryCommercial

		['batt_simple_kw', 'batt_simple_kwh']

	 - Battwatts_PVWattsBatteryHostDeveloper

		['batt_simple_kw', 'batt_simple_kwh']

	 - Battwatts_PVWattsBatteryResidential

		['batt_simple_kw', 'batt_simple_kwh']

	 - Battwatts_PVWattsBatteryThirdParty

		['batt_simple_kw', 'batt_simple_kwh']



Belpe
************************************************

Belpe New Default files:

	 - StandaloneBatteryResidential
	 - StandaloneBatteryThirdParty


Cashloan
************************************************

Cashloan New Default files:

	 - StandaloneBatteryCommercial
	 - StandaloneBatteryResidential

Cashloan Removed Default file:s

	 - DishStirlingCommercial
	 - PhysicalTroughCommercial

Cashloan Modified Variables:

	New variables:

		 - add_om_num_types
		 - batt_salvage_percentage
		 - battery_total_cost_lcos
		 - charge_w_sys_dc_tou_ym
		 - charge_w_sys_fixed_ym
		 - en_standalone_batt
		 - land_area
		 - net_billing_credits_ym
		 - nm_dollars_applied_ym
		 - om_batt_capacity_cost
		 - om_batt_fixed_cost
		 - om_batt_nameplate
		 - om_batt_replacement_cost
		 - om_batt_variable_cost
		 - om_fuelcell_capacity_cost
		 - om_fuelcell_fixed_cost
		 - om_fuelcell_nameplate
		 - om_fuelcell_replacement_cost
		 - om_fuelcell_variable_cost
		 - om_land_lease
		 - om_land_lease_escal
		 - utility_bill_w_sys
		 - year1_hourly_dc_with_system
		 - year1_hourly_e_fromgrid
		 - year1_hourly_ec_with_system

	Removed variables:

		 - om_capacity1
		 - om_capacity1_nameplate
		 - om_capacity2
		 - om_capacity2_nameplate
		 - om_fixed1
		 - om_fixed2
		 - om_fuel_cost
		 - om_fuel_cost_escal
		 - om_replacement_cost1
		 - om_replacement_cost2
		 - om_replacement_cost_escal

Cashloan Modified Default Values:

	 - Cashloan_DSLFCommercial

		['loan_rate', 'itc_fed_percent', 'om_fuel_cost']

	 - Cashloan_EmpiricalTroughCommercial

		['loan_rate', 'itc_fed_percent']

	 - Cashloan_FlatPlatePVCommercial

		['loan_rate', 'insurance_rate', 'system_capacity', 'total_installed_cost']

	 - Cashloan_FlatPlatePVResidential

		['loan_rate', 'insurance_rate', 'system_capacity', 'total_installed_cost', 'om_capacity']

	 - Cashloan_FuelCellCommercial

		['loan_rate', 'battery_per_kWh', 'insurance_rate', 'total_installed_cost']

	 - Cashloan_GenericBatteryCommercial

		['loan_rate', 'battery_per_kWh', 'itc_fed_percent', 'batt_computed_bank_capacity', 'total_installed_cost']

	 - Cashloan_GenericBatteryResidential

		['loan_rate', 'battery_per_kWh', 'batt_computed_bank_capacity', 'federal_tax_rate', 'total_installed_cost', 'om_capacity']

	 - Cashloan_GenericCSPSystemCommercial

		['loan_rate', 'itc_fed_percent']

	 - Cashloan_GenericSystemCommercial

		['loan_rate', 'itc_fed_percent', 'om_fuel_cost']

	 - Cashloan_GenericSystemResidential

		['loan_rate', 'federal_tax_rate', 'om_fuel_cost']

	 - Cashloan_MSLFCommercial

		['loan_rate', 'itc_fed_percent', 'om_fuel_cost']

	 - Cashloan_PVBatteryCommercial

		['loan_rate', 'battery_per_kWh', 'batt_computed_bank_capacity', 'system_capacity', 'total_installed_cost']

	 - Cashloan_PVBatteryResidential

		['loan_rate', 'battery_per_kWh', 'batt_computed_bank_capacity', 'federal_tax_rate', 'total_installed_cost', 'om_capacity']

	 - Cashloan_PVWattsBatteryCommercial

		['battery_per_kWh', 'system_capacity', 'degradation', 'total_installed_cost', 'om_capacity']

	 - Cashloan_PVWattsBatteryResidential

		['battery_per_kWh', 'federal_tax_rate', 'system_capacity', 'degradation', 'total_installed_cost', 'om_capacity']

	 - Cashloan_PVWattsCommercial

		['loan_rate', 'insurance_rate', 'system_capacity', 'total_installed_cost']

	 - Cashloan_PVWattsResidential

		['loan_rate', 'insurance_rate', 'system_capacity', 'total_installed_cost', 'om_capacity']

	 - Cashloan_SolarWaterHeatingCommercial

		['loan_rate']

	 - Cashloan_SolarWaterHeatingResidential

		['loan_rate', 'federal_tax_rate']

	 - Cashloan_WindPowerCommercial

		['loan_rate']

	 - Cashloan_WindPowerResidential

		['loan_rate', 'federal_tax_rate']



Communitysolar
************************************************

Communitysolar New Default files:

	 - PVWattsCommunitySolar


Equpartflip
************************************************

Equpartflip New Default files:

	 - StandaloneBatteryAllEquityPartnershipFlip

Equpartflip Removed Default file:s

	 - DSPTAllEquityPartnershipFlip
	 - DishStirlingAllEquityPartnershipFlip

Equpartflip Modified Variables:

	New variables:

		 - add_om_num_types
		 - batt_salvage_percentage
		 - battery_total_cost_lcos
		 - en_electricity_rates
		 - en_standalone_batt
		 - land_area
		 - om_batt_capacity_cost
		 - om_batt_fixed_cost
		 - om_batt_nameplate
		 - om_batt_replacement_cost
		 - om_batt_variable_cost
		 - om_land_lease
		 - om_land_lease_escal

	Removed variables:

		 - om_fuel_cost
		 - om_fuel_cost_escal
		 - om_replacement_cost1
		 - om_replacement_cost_escal
		 - system_use_recapitalization

Equpartflip Modified Default Values:

	 - Equpartflip_BiopowerAllEquityPartnershipFlip

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'ppa_price_input', 'construction_financing_cost']

	 - Equpartflip_DSLFAllEquityPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'om_fuel_cost']

	 - Equpartflip_EmpiricalTroughAllEquityPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent']

	 - Equpartflip_FlatPlatePVAllEquityPartnershipFlip

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'ppa_price_input', 'total_installed_cost', 'construction_financing_cost', 'om_capacity']

	 - Equpartflip_GenericBatteryAllEquityPartnershipFlip

		['equip1_reserve_cost', 'battery_per_kWh', 'reserves_interest', 'ppa_escalation', 'equip1_reserve_freq', 'insurance_rate', 'total_installed_cost', 'construction_financing_cost', 'om_capacity']

	 - Equpartflip_GenericCSPSystemAllEquityPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent']

	 - Equpartflip_GenericSystemAllEquityPartnershipFlip

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'ppa_price_input']

	 - Equpartflip_GeothermalPowerAllEquityPartnershipFlip

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'system_capacity', 'total_installed_cost', 'system_recapitalization_cost', 'construction_financing_cost']

	 - Equpartflip_HighXConcentratingPVAllEquityPartnershipFlip

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate']

	 - Equpartflip_MSLFAllEquityPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'om_fuel_cost']

	 - Equpartflip_MSPTAllEquityPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent']

	 - Equpartflip_PVBatteryAllEquityPartnershipFlip

		['equip1_reserve_cost', 'battery_per_kWh', 'reserves_interest', 'ppa_escalation', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'ppa_price_input', 'total_installed_cost', 'construction_financing_cost', 'om_capacity']

	 - Equpartflip_PVWattsAllEquityPartnershipFlip

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'ppa_price_input', 'total_installed_cost', 'construction_financing_cost', 'om_capacity']

	 - Equpartflip_PhysicalTroughAllEquityPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent']

	 - Equpartflip_WindPowerAllEquityPartnershipFlip

		['equip1_reserve_cost', 'ptc_fed_amount', 'ppa_soln_mode', 'reserves_interest', 'insurance_rate', 'system_capacity']



EtesElectricResistance
************************************************

EtesElectricResistance New Default files:

	 - ETESSingleOwner


GenericSystem
************************************************

GenericSystem Modified Default Values:

	 - Cashloan_GenericSystemCommercial

		['loan_rate', 'itc_fed_percent', 'om_fuel_cost']

	 - Cashloan_GenericSystemResidential

		['loan_rate', 'federal_tax_rate', 'om_fuel_cost']

	 - Equpartflip_GenericSystemAllEquityPartnershipFlip

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'ppa_price_input']

	 - GenericSystem_GenericSystemHostDeveloper

		['user_capacity_factor']

	 - GenericSystem_GenericSystemLeveragedPartnershipFlip

		['user_capacity_factor']

	 - GenericSystem_GenericSystemMerchantPlant

		['user_capacity_factor']

	 - HostDeveloper_GenericSystemHostDeveloper

		['reserves_interest', 'itc_fed_percent', 'state_tax_rate', 'om_fuel_cost', 'term_int_rate']

	 - Levpartflip_GenericSystemLeveragedPartnershipFlip

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'ppa_price_input', 'term_int_rate']

	 - Merchantplant_GenericSystemMerchantPlant

		['mp_ancserv2_revenue', 'equip1_reserve_cost', 'mp_ancserv4_revenue', 'reserves_interest', 'mp_ancserv1_revenue', 'mp_ancserv3_revenue', 'term_int_rate', 'mp_energy_market_revenue']

	 - Saleleaseback_GenericSystemSaleLeaseback

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'ppa_price_input']

	 - Singleowner_GenericSystemSingleOwner

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'ppa_price_input', 'term_int_rate']



Geothermal
************************************************

Geothermal Modified Variables:

	New variables:

		 - dt_prod_well

Geothermal Modified Default Values:

	 - Equpartflip_GeothermalPowerAllEquityPartnershipFlip

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'system_capacity', 'total_installed_cost', 'system_recapitalization_cost', 'construction_financing_cost']

	 - Geothermal_GeothermalPowerAllEquityPartnershipFlip

		['num_wells_getem', 'well_diameter', 'well_flow_rate']

	 - Geothermal_GeothermalPowerLCOECalculator

		['num_wells_getem']

	 - Geothermal_GeothermalPowerLeveragedPartnershipFlip

		['num_wells_getem']

	 - Geothermal_GeothermalPowerMerchantPlant

		['num_wells_getem', 'well_diameter', 'well_flow_rate']

	 - Geothermal_GeothermalPowerNone

		['num_wells_getem']

	 - Geothermal_GeothermalPowerSaleLeaseback

		['num_wells_getem']

	 - Geothermal_GeothermalPowerSingleOwner

		['num_wells_getem']

	 - Lcoefcr_GeothermalPowerLCOECalculator

		['capital_cost', 'fixed_operating_cost']

	 - Levpartflip_GeothermalPowerLeveragedPartnershipFlip

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'system_capacity', 'total_installed_cost', 'term_int_rate', 'system_recapitalization_cost', 'construction_financing_cost']

	 - Merchantplant_GeothermalPowerMerchantPlant

		['mp_ancserv2_revenue', 'equip1_reserve_cost', 'mp_ancserv4_revenue', 'reserves_interest', 'itc_fed_percent', 'system_capacity', 'mp_ancserv1_revenue', 'total_installed_cost', 'mp_ancserv3_revenue', 'term_int_rate', 'mp_energy_market_revenue', 'cp_system_nameplate', 'system_recapitalization_cost', 'construction_financing_cost']

	 - Saleleaseback_GeothermalPowerSaleLeaseback

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'system_capacity', 'total_installed_cost', 'system_recapitalization_cost', 'construction_financing_cost']

	 - Singleowner_GeothermalPowerSingleOwner

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'system_capacity', 'total_installed_cost', 'term_int_rate', 'cp_system_nameplate', 'system_recapitalization_cost', 'construction_financing_cost']



Grid
************************************************

Grid New Default files:

	 - PVWattsCommunitySolar
	 - StandaloneBatteryAllEquityPartnershipFlip
	 - StandaloneBatteryCommercial
	 - StandaloneBatteryHostDeveloper
	 - StandaloneBatteryLeveragedPartnershipFlip
	 - StandaloneBatteryMerchantPlant
	 - StandaloneBatteryResidential
	 - StandaloneBatterySaleLeaseback
	 - StandaloneBatterySingleOwner
	 - StandaloneBatteryThirdParty

Grid Removed Default file:s

	 - DSPTAllEquityPartnershipFlip
	 - DSPTLeveragedPartnershipFlip
	 - DSPTMerchantPlant
	 - DSPTSaleLeaseback
	 - DSPTSingleOwner
	 - DishStirlingAllEquityPartnershipFlip
	 - DishStirlingCommercial
	 - DishStirlingLCOECalculator
	 - DishStirlingLeveragedPartnershipFlip
	 - DishStirlingMerchantPlant
	 - DishStirlingNone
	 - DishStirlingSaleLeaseback
	 - DishStirlingSingleOwner
	 - PhysicalTroughCommercial

Grid Modified Variables:

	New variables:

		 - crit_load
		 - grid_outage


Hcpv
************************************************

Hcpv Modified Default Values:

	 - Hcpv_HighXConcentratingPVAllEquityPartnershipFlip

		['inv_snl_c0']

	 - Hcpv_HighXConcentratingPVLeveragedPartnershipFlip

		['inv_snl_c0']

	 - Hcpv_HighXConcentratingPVMerchantPlant

		['inv_snl_c0']

	 - Hcpv_HighXConcentratingPVSaleLeaseback

		['inv_snl_c0']

	 - Hcpv_HighXConcentratingPVSingleOwner

		['inv_snl_c0']



HostDeveloper
************************************************

HostDeveloper New Default files:

	 - StandaloneBatteryHostDeveloper

HostDeveloper Modified Variables:

	New variables:

		 - add_om_num_types
		 - batt_salvage_percentage
		 - battery_total_cost_lcos
		 - charge_w_sys_fixed_ym
		 - dscr_limit_debt_fraction
		 - dscr_maximum_debt_fraction
		 - en_standalone_batt
		 - net_billing_credits_ym
		 - nm_dollars_applied_ym
		 - om_batt_capacity_cost
		 - om_batt_fixed_cost
		 - om_batt_nameplate
		 - om_batt_replacement_cost
		 - om_batt_variable_cost
		 - year1_hourly_dc_with_system
		 - year1_hourly_e_fromgrid
		 - year1_hourly_ec_with_system

	Removed variables:

		 - gen
		 - om_fuel_cost
		 - om_fuel_cost_escal
		 - om_replacement_cost1
		 - om_replacement_cost_escal
		 - roe_input
		 - system_use_recapitalization

HostDeveloper Modified Default Values:

	 - Battery_GenericBatteryHostDeveloper

		['batt_minimum_SOC', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'batt_calendar_c', 'LeadAcid_q10_computed', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'batt_surface_area', 'batt_computed_bank_capacity', 'batt_power_charge_max_kwac', 'batt_power_charge_max_kwdc', 'batt_computed_strings', 'batt_current_charge_max', 'batt_mass', 'batt_current_discharge_max', 'batt_Qfull_flow']

	 - Battwatts_PVWattsBatteryHostDeveloper

		['batt_simple_kw', 'batt_simple_kwh']

	 - GenericSystem_GenericSystemHostDeveloper

		['user_capacity_factor']

	 - HostDeveloper_FlatPlatePVHostDeveloper

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'total_installed_cost', 'term_int_rate', 'construction_financing_cost']

	 - HostDeveloper_GenericBatteryHostDeveloper

		['equip1_reserve_cost', 'battery_per_kWh', 'reserves_interest', 'itc_fed_percent', 'batt_computed_bank_capacity', 'equip1_reserve_freq', 'total_installed_cost', 'term_int_rate', 'construction_financing_cost']

	 - HostDeveloper_GenericSystemHostDeveloper

		['reserves_interest', 'itc_fed_percent', 'state_tax_rate', 'om_fuel_cost', 'term_int_rate']

	 - HostDeveloper_PVBatteryHostDeveloper

		['equip1_reserve_cost', 'battery_per_kWh', 'batt_computed_bank_capacity', 'equip1_reserve_freq', 'system_capacity', 'total_installed_cost', 'construction_financing_cost']

	 - HostDeveloper_PVWattsBatteryHostDeveloper

		['battery_per_kWh', 'system_capacity', 'degradation', 'total_installed_cost', 'construction_financing_cost', 'om_capacity']

	 - HostDeveloper_PVWattsHostDeveloper

		['equip1_reserve_cost', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'total_installed_cost', 'term_int_rate', 'construction_financing_cost']

	 - Pvsamv1_FlatPlatePVHostDeveloper

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'inverter_count', 'inv_snl_pdco', 'inv_tdc_plc', 'inv_snl_c2', 'cec_i_o_ref', 'mppt_low_inverter', 'system_capacity', 'inv_snl_c1', 'inv_snl_c3', 'subarray1_nstrings', 'use_wf_albedo', 'cec_r_sh_ref', 'inv_snl_pnt', 'mppt_hi_inverter', 'inv_snl_c0', 'inv_tdc_cec_db', 'inv_tdc_ds', 'inv_snl_vdco', 'inv_snl_paco', 'inv_snl_vdcmax', 'inv_snl_pso']

	 - Pvsamv1_PVBatteryHostDeveloper

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'inverter_count', 'LeadAcid_q10_computed', 'inv_tdc_plc', 'batt_power_charge_max_kwac', 'batt_power_charge_max_kwdc', 'batt_computed_strings', 'batt_calendar_c', 'cec_i_o_ref', 'batt_surface_area', 'system_capacity', 'batt_current_charge_max', 'batt_current_discharge_max', 'batt_Qfull_flow', 'subarray1_nstrings', 'use_wf_albedo', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'cec_r_sh_ref', 'inv_snl_c0', 'batt_minimum_SOC', 'inv_tdc_cec_db', 'batt_computed_bank_capacity', 'inv_tdc_ds', 'batt_mass']

	 - Utilityrate5_PVWattsBatteryHostDeveloper

		['degradation']



Lcoefcr
************************************************

Lcoefcr Removed Default file:s

	 - DishStirlingLCOECalculator

Lcoefcr Modified Default Values:

	 - Lcoefcr_FlatPlatePVLCOECalculator

		['capital_cost', 'fixed_charge_rate', 'fixed_operating_cost']

	 - Lcoefcr_GeothermalPowerLCOECalculator

		['capital_cost', 'fixed_operating_cost']

	 - Lcoefcr_MEtidalLCOECalculator

		['capital_cost', 'fixed_operating_cost', 'annual_energy']

	 - Lcoefcr_MEwaveLCOECalculator

		['capital_cost', 'annual_energy']

	 - Lcoefcr_PVWattsLCOECalculator

		['capital_cost', 'fixed_charge_rate', 'fixed_operating_cost']

	 - Lcoefcr_WindPowerLCOECalculator

		['capital_cost', 'fixed_charge_rate', 'fixed_operating_cost']



Levpartflip
************************************************

Levpartflip New Default files:

	 - StandaloneBatteryLeveragedPartnershipFlip

Levpartflip Removed Default file:s

	 - DSPTLeveragedPartnershipFlip
	 - DishStirlingLeveragedPartnershipFlip

Levpartflip Modified Variables:

	New variables:

		 - add_om_num_types
		 - batt_salvage_percentage
		 - battery_total_cost_lcos
		 - dscr_limit_debt_fraction
		 - dscr_maximum_debt_fraction
		 - en_electricity_rates
		 - en_standalone_batt
		 - land_area
		 - om_batt_capacity_cost
		 - om_batt_fixed_cost
		 - om_batt_nameplate
		 - om_batt_replacement_cost
		 - om_batt_variable_cost
		 - om_land_lease
		 - om_land_lease_escal

	Removed variables:

		 - om_fuel_cost
		 - om_fuel_cost_escal
		 - om_replacement_cost1
		 - om_replacement_cost_escal
		 - system_use_recapitalization

Levpartflip Modified Default Values:

	 - Levpartflip_BiopowerLeveragedPartnershipFlip

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'ppa_price_input', 'term_int_rate', 'construction_financing_cost']

	 - Levpartflip_DSLFLeveragedPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'om_fuel_cost', 'term_int_rate']

	 - Levpartflip_EmpiricalTroughLeveragedPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'term_int_rate']

	 - Levpartflip_FlatPlatePVLeveragedPartnershipFlip

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'ppa_price_input', 'total_installed_cost', 'term_int_rate', 'construction_financing_cost', 'om_capacity']

	 - Levpartflip_GenericBatteryLeveragedPartnershipFlip

		['equip1_reserve_cost', 'battery_per_kWh', 'reserves_interest', 'ppa_escalation', 'equip1_reserve_freq', 'insurance_rate', 'total_installed_cost', 'term_int_rate', 'construction_financing_cost', 'om_capacity']

	 - Levpartflip_GenericCSPSystemLeveragedPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'term_int_rate']

	 - Levpartflip_GenericSystemLeveragedPartnershipFlip

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'ppa_price_input', 'term_int_rate']

	 - Levpartflip_GeothermalPowerLeveragedPartnershipFlip

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'system_capacity', 'total_installed_cost', 'term_int_rate', 'system_recapitalization_cost', 'construction_financing_cost']

	 - Levpartflip_HighXConcentratingPVLeveragedPartnershipFlip

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate', 'term_int_rate']

	 - Levpartflip_MSLFLeveragedPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'om_fuel_cost', 'term_int_rate']

	 - Levpartflip_MSPTLeveragedPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'term_int_rate']

	 - Levpartflip_PVBatteryLeveragedPartnershipFlip

		['equip1_reserve_cost', 'battery_per_kWh', 'reserves_interest', 'ppa_escalation', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'ppa_price_input', 'total_installed_cost', 'term_int_rate', 'construction_financing_cost', 'om_capacity']

	 - Levpartflip_PVWattsLeveragedPartnershipFlip

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'ppa_price_input', 'total_installed_cost', 'term_int_rate', 'construction_financing_cost', 'om_capacity']

	 - Levpartflip_PhysicalTroughLeveragedPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'term_int_rate']

	 - Levpartflip_WindPowerLeveragedPartnershipFlip

		['equip1_reserve_cost', 'ptc_fed_amount', 'ppa_soln_mode', 'reserves_interest', 'insurance_rate', 'system_capacity', 'term_int_rate']



Merchantplant
************************************************

Merchantplant New Default files:

	 - StandaloneBatteryMerchantPlant

Merchantplant Removed Default file:s

	 - DSPTMerchantPlant
	 - DishStirlingMerchantPlant

Merchantplant Modified Variables:

	New variables:

		 - add_om_num_types
		 - batt_salvage_percentage
		 - battery_total_cost_lcos
		 - dscr_limit_debt_fraction
		 - dscr_maximum_debt_fraction
		 - en_electricity_rates
		 - en_standalone_batt
		 - land_area
		 - mp_ancserv1_percent_gen
		 - mp_ancserv1_revenue_single
		 - mp_ancserv2_percent_gen
		 - mp_ancserv2_revenue_single
		 - mp_ancserv3_percent_gen
		 - mp_ancserv3_revenue_single
		 - mp_ancserv4_percent_gen
		 - mp_ancserv4_revenue_single
		 - mp_enable_ancserv1_percent_gen
		 - mp_enable_ancserv2_percent_gen
		 - mp_enable_ancserv3_percent_gen
		 - mp_enable_ancserv4_percent_gen
		 - mp_enable_market_percent_gen
		 - mp_energy_market_revenue_single
		 - mp_market_percent_gen
		 - om_batt_capacity_cost
		 - om_batt_fixed_cost
		 - om_batt_nameplate
		 - om_batt_replacement_cost
		 - om_batt_variable_cost
		 - om_land_lease
		 - om_land_lease_escal

	Removed variables:

		 - om_fuel_cost
		 - om_fuel_cost_escal
		 - om_replacement_cost1
		 - om_replacement_cost_escal
		 - roe_input
		 - system_use_recapitalization

Merchantplant Modified Default Values:

	 - Merchantplant_BiopowerMerchantPlant

		['mp_ancserv2_revenue', 'equip1_reserve_cost', 'mp_ancserv4_revenue', 'reserves_interest', 'itc_fed_percent', 'mp_ancserv1_revenue', 'mp_ancserv3_revenue', 'term_int_rate', 'mp_energy_market_revenue']

	 - Merchantplant_DSLFMerchantPlant

		['mp_ancserv2_revenue', 'mp_ancserv4_revenue', 'reserves_interest', 'mp_ancserv1_revenue', 'om_fuel_cost', 'mp_ancserv3_revenue', 'term_int_rate', 'mp_energy_market_revenue']

	 - Merchantplant_EmpiricalTroughMerchantPlant

		['mp_ancserv2_revenue', 'mp_ancserv4_revenue', 'reserves_interest', 'mp_ancserv1_revenue', 'mp_ancserv3_revenue', 'term_int_rate', 'mp_energy_market_revenue']

	 - Merchantplant_FlatPlatePVMerchantPlant

		['mp_ancserv2_revenue', 'equip1_reserve_cost', 'mp_ancserv4_revenue', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'mp_ancserv1_revenue', 'total_installed_cost', 'mp_ancserv3_revenue', 'term_int_rate', 'mp_energy_market_revenue', 'cp_system_nameplate', 'construction_financing_cost', 'om_capacity']

	 - Merchantplant_GenericBatteryMerchantPlant

		['mp_ancserv2_revenue', 'equip1_reserve_cost', 'mp_ancserv4_revenue', 'battery_per_kWh', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate', 'mp_ancserv1_revenue', 'total_installed_cost', 'mp_ancserv3_revenue', 'term_int_rate', 'mp_energy_market_revenue', 'construction_financing_cost', 'cp_battery_nameplate', 'om_capacity']

	 - Merchantplant_GenericCSPSystemMerchantPlant

		['mp_ancserv2_revenue', 'mp_ancserv4_revenue', 'reserves_interest', 'system_capacity', 'mp_ancserv1_revenue', 'total_installed_cost', 'mp_ancserv3_revenue', 'term_int_rate', 'mp_energy_market_revenue', 'cp_system_nameplate', 'construction_financing_cost']

	 - Merchantplant_GenericSystemMerchantPlant

		['mp_ancserv2_revenue', 'equip1_reserve_cost', 'mp_ancserv4_revenue', 'reserves_interest', 'mp_ancserv1_revenue', 'mp_ancserv3_revenue', 'term_int_rate', 'mp_energy_market_revenue']

	 - Merchantplant_GeothermalPowerMerchantPlant

		['mp_ancserv2_revenue', 'equip1_reserve_cost', 'mp_ancserv4_revenue', 'reserves_interest', 'itc_fed_percent', 'system_capacity', 'mp_ancserv1_revenue', 'total_installed_cost', 'mp_ancserv3_revenue', 'term_int_rate', 'mp_energy_market_revenue', 'cp_system_nameplate', 'system_recapitalization_cost', 'construction_financing_cost']

	 - Merchantplant_HighXConcentratingPVMerchantPlant

		['mp_ancserv2_revenue', 'equip1_reserve_cost', 'mp_ancserv4_revenue', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate', 'mp_ancserv1_revenue', 'mp_ancserv3_revenue', 'term_int_rate', 'mp_energy_market_revenue']

	 - Merchantplant_MSLFMerchantPlant

		['mp_ancserv2_revenue', 'mp_ancserv4_revenue', 'reserves_interest', 'mp_ancserv1_revenue', 'om_fuel_cost', 'mp_ancserv3_revenue', 'term_int_rate', 'mp_energy_market_revenue']

	 - Merchantplant_MSPTMerchantPlant

		['mp_ancserv2_revenue', 'mp_ancserv4_revenue', 'reserves_interest', 'itc_fed_percent', 'mp_ancserv1_revenue', 'mp_ancserv3_revenue', 'term_int_rate', 'mp_energy_market_revenue']

	 - Merchantplant_PVBatteryMerchantPlant

		['mp_ancserv2_revenue', 'equip1_reserve_cost', 'mp_ancserv4_revenue', 'battery_per_kWh', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'mp_ancserv1_revenue', 'total_installed_cost', 'mp_ancserv3_revenue', 'term_int_rate', 'mp_energy_market_revenue', 'cp_system_nameplate', 'construction_financing_cost', 'cp_battery_nameplate', 'om_capacity']

	 - Merchantplant_PVWattsMerchantPlant

		['mp_ancserv2_revenue', 'equip1_reserve_cost', 'mp_ancserv4_revenue', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'mp_ancserv1_revenue', 'total_installed_cost', 'mp_ancserv3_revenue', 'term_int_rate', 'mp_energy_market_revenue', 'cp_system_nameplate', 'construction_financing_cost', 'om_capacity']

	 - Merchantplant_PhysicalTroughMerchantPlant

		['mp_ancserv2_revenue', 'mp_ancserv4_revenue', 'reserves_interest', 'mp_ancserv1_revenue', 'mp_ancserv3_revenue', 'term_int_rate', 'mp_energy_market_revenue']

	 - Merchantplant_WindPowerMerchantPlant

		['mp_ancserv2_revenue', 'equip1_reserve_cost', 'mp_ancserv4_revenue', 'ptc_fed_amount', 'reserves_interest', 'insurance_rate', 'system_capacity', 'mp_ancserv1_revenue', 'mp_ancserv3_revenue', 'term_int_rate', 'mp_energy_market_revenue']



MhkTidal
************************************************

MhkTidal New Default files:

	 - MEtidalNone

MhkTidal Modified Variables:

	New variables:

		 - system_capacity

MhkTidal Modified Default Values:

	 - MhkTidal_MEtidalLCOECalculator

		['total_operating_cost', 'balance_of_system_cost_total', 'device_costs_total', 'financial_cost_total', 'number_devices']



MhkWave
************************************************

MhkWave New Default files:

	 - MEwaveNone

MhkWave Modified Variables:

	New variables:

		 - energy_period
		 - number_hours
		 - number_records
		 - significant_wave_height
		 - wave_resource_model_choice
		 - year

MhkWave Modified Default Values:

	 - MhkWave_MEwaveLCOECalculator

		['balance_of_system_cost_total', 'financial_cost_total']



Pvsamv1
************************************************

Pvsamv1 Modified Variables:

	New variables:

		 - batt_Vcut
		 - batt_dispatch_auto_btm_can_discharge_to_grid
		 - batt_dispatch_auto_can_clipcharge
		 - batt_dispatch_charge_only_system_exceeds_load
		 - batt_dispatch_discharge_only_load_exceeds_system
		 - batt_dispatch_load_forecast_choice
		 - batt_dispatch_pvs_ac_lb
		 - batt_dispatch_pvs_ac_lb_enable
		 - batt_dispatch_pvs_ac_ub
		 - batt_dispatch_pvs_ac_ub_enable
		 - batt_dispatch_pvs_curtail_as_control
		 - batt_dispatch_pvs_curtail_if_violation
		 - batt_dispatch_pvs_forecast_shift_periods
		 - batt_dispatch_pvs_kf
		 - batt_dispatch_pvs_ki
		 - batt_dispatch_pvs_kp
		 - batt_dispatch_pvs_max_ramp
		 - batt_dispatch_pvs_nameplate_ac
		 - batt_dispatch_pvs_short_forecast_enable
		 - batt_dispatch_pvs_soc_rest
		 - batt_dispatch_pvs_timestep_multiplier
		 - batt_dispatch_wf_forecast_choice
		 - batt_life_model
		 - batt_load_ac_forecast
		 - batt_load_ac_forecast_escalation
		 - batt_minimum_outage_SOC
		 - batt_pv_ac_forecast
		 - batt_pv_clipping_forecast
		 - crit_load_escalation
		 - dispatch_manual_btm_discharge_to_grid
		 - en_standalone_batt
		 - enable_interconnection_limit
		 - grid_curtailment
		 - grid_interconnection_limit_kwac
		 - grid_outage
		 - om_batt_replacement_cost
		 - om_replacement_cost_escal
		 - rate_escalation
		 - run_resiliency_calcs
		 - sixpar_aisc
		 - sixpar_area
		 - sixpar_bifacial_ground_clearance_height
		 - sixpar_bifacial_transmission_factor
		 - sixpar_bifaciality
		 - sixpar_bvoc
		 - sixpar_celltech
		 - sixpar_gpmp
		 - sixpar_imp
		 - sixpar_is_bifacial
		 - sixpar_isc
		 - sixpar_mounting
		 - sixpar_nser
		 - sixpar_standoff
		 - sixpar_tnoct
		 - sixpar_transient_thermal_model_unit_mass
		 - sixpar_vmp
		 - sixpar_voc
		 - subarray1_slope_azm
		 - subarray1_slope_tilt
		 - subarray2_slope_azm
		 - subarray2_slope_tilt
		 - subarray3_slope_azm
		 - subarray3_slope_tilt
		 - subarray4_slope_azm
		 - subarray4_slope_tilt
		 - ur_annual_min_charge
		 - ur_billing_demand_lookback_percentages
		 - ur_billing_demand_lookback_period
		 - ur_billing_demand_minimum
		 - ur_dc_billing_demand_periods
		 - ur_dc_enable
		 - ur_dc_flat_mat
		 - ur_dc_sched_weekday
		 - ur_dc_sched_weekend
		 - ur_dc_tou_mat
		 - ur_ec_sched_weekday
		 - ur_ec_sched_weekend
		 - ur_ec_tou_mat
		 - ur_en_ts_buy_rate
		 - ur_en_ts_sell_rate
		 - ur_enable_billing_demand
		 - ur_metering_option
		 - ur_monthly_fixed_charge
		 - ur_monthly_min_charge
		 - ur_nm_credit_month
		 - ur_nm_credit_rollover
		 - ur_nm_yearend_sell_rate
		 - ur_ts_buy_rate
		 - ur_ts_sell_rate
		 - ur_yearzero_usage_peaks

	Removed variables:

		 - 6par_aisc
		 - 6par_area
		 - 6par_bifacial_ground_clearance_height
		 - 6par_bifacial_transmission_factor
		 - 6par_bifaciality
		 - 6par_bvoc
		 - 6par_celltech
		 - 6par_gpmp
		 - 6par_imp
		 - 6par_is_bifacial
		 - 6par_isc
		 - 6par_mounting
		 - 6par_nser
		 - 6par_standoff
		 - 6par_tnoct
		 - 6par_transient_thermal_model_unit_mass
		 - 6par_vmp
		 - 6par_voc
		 - batt_auto_gridcharge_max_daily
		 - om_replacement_cost1

Pvsamv1 Modified Default Values:

	 - Pvsamv1_FlatPlatePVAllEquityPartnershipFlip

		['inv_snl_c0', 'inv_snl_eff_cec', 'inv_tdc_cec_cg', 'subarray3_track_mode', 'inv_tdc_cec_db', 'subarray1_nstrings', 'inverter_count', 'use_wf_albedo', 'subarray1_tilt', 'cec_i_o_ref', 'inv_tdc_plc', 'inv_tdc_ds', 'system_capacity', 'subarray4_tilt', 'cec_r_sh_ref', 'subarray2_tilt', 'ppa_price_input', 'subarray2_track_mode', 'subarray3_tilt', 'subarray1_track_mode', 'subarray4_track_mode']

	 - Pvsamv1_FlatPlatePVCommercial

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'inverter_count', 'inv_snl_pdco', 'inv_tdc_plc', 'inv_snl_c2', 'cec_i_o_ref', 'mppt_low_inverter', 'system_capacity', 'inv_snl_c1', 'inv_snl_c3', 'subarray1_nstrings', 'use_wf_albedo', 'cec_r_sh_ref', 'inv_snl_pnt', 'mppt_hi_inverter', 'inv_snl_c0', 'inv_tdc_cec_db', 'inv_tdc_ds', 'inv_snl_vdco', 'inv_snl_paco', 'inv_snl_vdcmax', 'inv_snl_pso']

	 - Pvsamv1_FlatPlatePVHostDeveloper

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'inverter_count', 'inv_snl_pdco', 'inv_tdc_plc', 'inv_snl_c2', 'cec_i_o_ref', 'mppt_low_inverter', 'system_capacity', 'inv_snl_c1', 'inv_snl_c3', 'subarray1_nstrings', 'use_wf_albedo', 'cec_r_sh_ref', 'inv_snl_pnt', 'mppt_hi_inverter', 'inv_snl_c0', 'inv_tdc_cec_db', 'inv_tdc_ds', 'inv_snl_vdco', 'inv_snl_paco', 'inv_snl_vdcmax', 'inv_snl_pso']

	 - Pvsamv1_FlatPlatePVLCOECalculator

		['inv_snl_c0', 'inv_snl_eff_cec', 'inv_tdc_cec_cg', 'subarray3_track_mode', 'inv_tdc_cec_db', 'subarray1_nstrings', 'inverter_count', 'use_wf_albedo', 'subarray1_tilt', 'cec_i_o_ref', 'inv_tdc_plc', 'subarray4_track_mode', 'inv_tdc_ds', 'system_capacity', 'subarray4_tilt', 'cec_r_sh_ref', 'subarray2_tilt', 'subarray2_track_mode', 'subarray3_tilt', 'subarray1_track_mode']

	 - Pvsamv1_FlatPlatePVLeveragedPartnershipFlip

		['inv_snl_c0', 'inv_snl_eff_cec', 'inv_tdc_cec_cg', 'subarray3_track_mode', 'inv_tdc_cec_db', 'subarray1_nstrings', 'inverter_count', 'use_wf_albedo', 'subarray1_tilt', 'cec_i_o_ref', 'inv_tdc_plc', 'inv_tdc_ds', 'system_capacity', 'subarray4_tilt', 'cec_r_sh_ref', 'subarray2_tilt', 'ppa_price_input', 'subarray2_track_mode', 'subarray3_tilt', 'subarray1_track_mode', 'subarray4_track_mode']

	 - Pvsamv1_FlatPlatePVMerchantPlant

		['inv_snl_c0', 'inv_snl_eff_cec', 'mp_ancserv2_revenue', 'inv_tdc_cec_cg', 'mp_ancserv4_revenue', 'subarray3_track_mode', 'inv_tdc_cec_db', 'subarray1_nstrings', 'inverter_count', 'use_wf_albedo', 'subarray1_tilt', 'cec_i_o_ref', 'inv_tdc_plc', 'inv_tdc_ds', 'system_capacity', 'mp_ancserv1_revenue', 'subarray4_tilt', 'cec_r_sh_ref', 'subarray2_tilt', 'subarray2_track_mode', 'mp_ancserv3_revenue', 'mp_energy_market_revenue', 'subarray3_tilt', 'subarray1_track_mode', 'subarray4_track_mode']

	 - Pvsamv1_FlatPlatePVNone

		['inv_snl_c0', 'inv_snl_eff_cec', 'inv_tdc_cec_cg', 'inv_tdc_cec_db', 'subarray1_nstrings', 'inv_snl_pdco', 'use_wf_albedo', 'cec_i_o_ref', 'inv_tdc_plc', 'mppt_low_inverter', 'inv_tdc_ds', 'system_capacity', 'inv_snl_vdco', 'inv_snl_c1', 'cec_r_sh_ref', 'inv_snl_paco', 'cec_r_s', 'inv_snl_pnt', 'inv_snl_c2', 'inv_snl_c3', 'inv_snl_vdcmax', 'mppt_hi_inverter', 'inv_snl_pso', 'subarray1_modules_per_string']

	 - Pvsamv1_FlatPlatePVResidential

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'inv_snl_pdco', 'subarray3_mismatch_loss', 'inv_tdc_plc', 'inv_snl_c2', 'dcoptimizer_loss', 'cec_i_o_ref', 'mppt_low_inverter', 'system_capacity', 'inv_snl_c1', 'inv_snl_c3', 'subarray1_modules_per_string', 'subarray1_nstrings', 'use_wf_albedo', 'cec_r_sh_ref', 'subarray2_mismatch_loss', 'cec_r_s', 'inv_snl_pnt', 'mppt_hi_inverter', 'inv_snl_c0', 'inv_tdc_cec_db', 'subarray4_mismatch_loss', 'inv_tdc_ds', 'inv_snl_vdco', 'inv_snl_paco', 'inv_snl_vdcmax', 'inv_snl_pso', 'subarray1_mismatch_loss']

	 - Pvsamv1_FlatPlatePVSaleLeaseback

		['inv_snl_c0', 'inv_snl_eff_cec', 'inv_tdc_cec_cg', 'subarray3_track_mode', 'inv_tdc_cec_db', 'subarray1_nstrings', 'inverter_count', 'use_wf_albedo', 'subarray1_tilt', 'cec_i_o_ref', 'inv_tdc_plc', 'inv_tdc_ds', 'system_capacity', 'subarray4_tilt', 'cec_r_sh_ref', 'subarray2_tilt', 'ppa_price_input', 'subarray2_track_mode', 'subarray3_tilt', 'subarray1_track_mode', 'subarray4_track_mode']

	 - Pvsamv1_FlatPlatePVSingleOwner

		['inv_snl_c0', 'inv_snl_eff_cec', 'inv_tdc_cec_cg', 'subarray3_track_mode', 'inv_tdc_cec_db', 'subarray1_nstrings', 'inverter_count', 'use_wf_albedo', 'subarray1_tilt', 'cec_i_o_ref', 'inv_tdc_plc', 'inv_tdc_ds', 'system_capacity', 'subarray4_tilt', 'cec_r_sh_ref', 'subarray2_tilt', 'ppa_price_input', 'subarray2_track_mode', 'subarray3_tilt', 'subarray1_track_mode', 'subarray4_track_mode']

	 - Pvsamv1_FlatPlatePVThirdParty

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'inv_snl_pdco', 'subarray3_mismatch_loss', 'inv_tdc_plc', 'inv_snl_c2', 'dcoptimizer_loss', 'cec_i_o_ref', 'mppt_low_inverter', 'system_capacity', 'inv_snl_c1', 'inv_snl_c3', 'subarray1_modules_per_string', 'subarray1_nstrings', 'use_wf_albedo', 'cec_r_sh_ref', 'subarray2_mismatch_loss', 'cec_r_s', 'inv_snl_pnt', 'mppt_hi_inverter', 'inv_snl_c0', 'inv_tdc_cec_db', 'subarray4_mismatch_loss', 'inv_tdc_ds', 'inv_snl_vdco', 'inv_snl_paco', 'inv_snl_vdcmax', 'inv_snl_pso', 'subarray1_mismatch_loss']

	 - Pvsamv1_PVBatteryAllEquityPartnershipFlip

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'dispatch_manual_sched', 'inverter_count', 'LeadAcid_q10_computed', 'inv_tdc_plc', 'batt_calendar_c', 'cec_i_o_ref', 'batt_surface_area', 'batt_dispatch_choice', 'system_capacity', 'ppa_price_input', 'batt_Qfull_flow', 'batt_room_temperature_celsius', 'subarray1_nstrings', 'use_wf_albedo', 'subarray1_tilt', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'dispatch_manual_sched_weekend', 'cec_r_sh_ref', 'inv_snl_c0', 'inv_tdc_cec_db', 'inv_tdc_ds', 'batt_h_to_ambient', 'subarray1_track_mode']

	 - Pvsamv1_PVBatteryCommercial

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'inverter_count', 'LeadAcid_q10_computed', 'inv_tdc_plc', 'batt_power_charge_max_kwac', 'batt_power_charge_max_kwdc', 'batt_computed_strings', 'batt_calendar_c', 'cec_i_o_ref', 'batt_surface_area', 'system_capacity', 'batt_current_charge_max', 'batt_current_discharge_max', 'batt_Qfull_flow', 'subarray1_nstrings', 'use_wf_albedo', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'cec_r_sh_ref', 'inv_snl_c0', 'batt_minimum_SOC', 'inv_tdc_cec_db', 'batt_computed_bank_capacity', 'batt_target_power_monthly', 'inv_tdc_ds', 'batt_mass']

	 - Pvsamv1_PVBatteryHostDeveloper

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'inverter_count', 'LeadAcid_q10_computed', 'inv_tdc_plc', 'batt_power_charge_max_kwac', 'batt_power_charge_max_kwdc', 'batt_computed_strings', 'batt_calendar_c', 'cec_i_o_ref', 'batt_surface_area', 'system_capacity', 'batt_current_charge_max', 'batt_current_discharge_max', 'batt_Qfull_flow', 'subarray1_nstrings', 'use_wf_albedo', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'cec_r_sh_ref', 'inv_snl_c0', 'batt_minimum_SOC', 'inv_tdc_cec_db', 'batt_computed_bank_capacity', 'inv_tdc_ds', 'batt_mass']

	 - Pvsamv1_PVBatteryLeveragedPartnershipFlip

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'dispatch_manual_sched', 'inverter_count', 'LeadAcid_q10_computed', 'inv_tdc_plc', 'batt_calendar_c', 'cec_i_o_ref', 'batt_surface_area', 'batt_dispatch_choice', 'system_capacity', 'ppa_price_input', 'batt_Qfull_flow', 'batt_room_temperature_celsius', 'subarray1_nstrings', 'use_wf_albedo', 'subarray1_tilt', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'dispatch_manual_sched_weekend', 'cec_r_sh_ref', 'inv_snl_c0', 'inv_tdc_cec_db', 'inv_tdc_ds', 'batt_h_to_ambient', 'subarray1_track_mode']

	 - Pvsamv1_PVBatteryMerchantPlant

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'dispatch_manual_sched', 'inverter_count', 'LeadAcid_q10_computed', 'inv_tdc_plc', 'mp_ancserv4_revenue', 'batt_calendar_c', 'cec_i_o_ref', 'batt_surface_area', 'batt_dispatch_choice', 'system_capacity', 'mp_ancserv1_revenue', 'mp_ancserv3_revenue', 'mp_energy_market_revenue', 'batt_Qfull_flow', 'batt_room_temperature_celsius', 'subarray1_nstrings', 'use_wf_albedo', 'subarray1_tilt', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'dispatch_manual_sched_weekend', 'cec_r_sh_ref', 'inv_snl_c0', 'mp_ancserv2_revenue', 'inv_tdc_cec_db', 'inv_tdc_ds', 'batt_h_to_ambient', 'subarray1_track_mode']

	 - Pvsamv1_PVBatteryResidential

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'subarray3_mismatch_loss', 'LeadAcid_q10_computed', 'inv_tdc_plc', 'batt_power_charge_max_kwac', 'batt_power_charge_max_kwdc', 'batt_computed_strings', 'dcoptimizer_loss', 'batt_calendar_c', 'cec_i_o_ref', 'batt_surface_area', 'batt_dispatch_choice', 'batt_current_charge_max', 'batt_current_discharge_max', 'batt_Qfull_flow', 'use_wf_albedo', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'cec_r_sh_ref', 'subarray2_mismatch_loss', 'cec_r_s', 'inv_snl_c0', 'batt_minimum_SOC', 'inv_tdc_cec_db', 'batt_computed_bank_capacity', 'subarray4_mismatch_loss', 'inv_tdc_ds', 'batt_mass', 'subarray1_mismatch_loss']

	 - Pvsamv1_PVBatterySaleLeaseback

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'dispatch_manual_sched', 'inverter_count', 'LeadAcid_q10_computed', 'inv_tdc_plc', 'batt_calendar_c', 'cec_i_o_ref', 'batt_surface_area', 'batt_dispatch_choice', 'system_capacity', 'ppa_price_input', 'batt_Qfull_flow', 'batt_room_temperature_celsius', 'subarray1_nstrings', 'use_wf_albedo', 'subarray1_tilt', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'dispatch_manual_sched_weekend', 'cec_r_sh_ref', 'inv_snl_c0', 'inv_tdc_cec_db', 'inv_tdc_ds', 'batt_h_to_ambient', 'subarray1_track_mode']

	 - Pvsamv1_PVBatterySingleOwner

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'batt_power_discharge_max_kwac', 'dispatch_manual_sched', 'inverter_count', 'inv_tdc_plc', 'ur_ec_tou_mat', 'batt_power_charge_max_kwac', 'batt_power_charge_max_kwdc', 'batt_computed_strings', 'batt_calendar_c', 'cec_i_o_ref', 'batt_surface_area', 'batt_dispatch_choice', 'system_capacity', 'ppa_price_input', 'batt_current_charge_max', 'batt_current_discharge_max', 'batt_Qfull_flow', 'subarray1_nstrings', 'use_wf_albedo', 'subarray1_tilt', 'ur_nm_yearend_sell_rate', 'batt_power_discharge_max_kwdc', 'dispatch_manual_sched_weekend', 'cec_r_sh_ref', 'inv_snl_c0', 'inv_tdc_cec_db', 'batt_computed_bank_capacity', 'inv_tdc_ds', 'ur_dc_tou_mat', 'batt_h_to_ambient', 'batt_mass', 'subarray1_track_mode']

	 - Pvsamv1_PVBatteryThirdParty

		['inv_snl_eff_cec', 'inv_tdc_cec_cg', 'batt_power_discharge_max_kwac', 'LeadAcid_qn_computed', 'inverter_count', 'subarray3_mismatch_loss', 'LeadAcid_q10_computed', 'inv_tdc_plc', 'batt_power_charge_max_kwac', 'batt_power_charge_max_kwdc', 'batt_computed_strings', 'dcoptimizer_loss', 'batt_calendar_c', 'cec_i_o_ref', 'batt_surface_area', 'batt_dispatch_choice', 'system_capacity', 'batt_current_charge_max', 'batt_current_discharge_max', 'batt_Qfull_flow', 'subarray1_nstrings', 'use_wf_albedo', 'LeadAcid_q20_computed', 'batt_power_discharge_max_kwdc', 'cec_r_sh_ref', 'subarray2_mismatch_loss', 'cec_r_s', 'inv_snl_c0', 'batt_minimum_SOC', 'inv_tdc_cec_db', 'batt_computed_bank_capacity', 'subarray4_mismatch_loss', 'inv_tdc_ds', 'batt_mass', 'subarray1_mismatch_loss']



Pvwattsv7
************************************************

Pvwattsv7 Removed Default file:s

	 - FuelCellCommercial
	 - FuelCellSingleOwner
	 - PVWattsAllEquityPartnershipFlip
	 - PVWattsBatteryCommercial
	 - PVWattsBatteryHostDeveloper
	 - PVWattsBatteryResidential
	 - PVWattsBatteryThirdParty
	 - PVWattsCommercial
	 - PVWattsHostDeveloper
	 - PVWattsLCOECalculator
	 - PVWattsLeveragedPartnershipFlip
	 - PVWattsMerchantPlant
	 - PVWattsNone
	 - PVWattsResidential
	 - PVWattsSaleLeaseback
	 - PVWattsSingleOwner
	 - PVWattsThirdParty


Pvwattsv8
************************************************

Pvwattsv8 New Default files:

	 - FuelCellCommercial
	 - FuelCellSingleOwner
	 - PVWattsAllEquityPartnershipFlip
	 - PVWattsBatteryCommercial
	 - PVWattsBatteryHostDeveloper
	 - PVWattsBatteryResidential
	 - PVWattsBatteryThirdParty
	 - PVWattsCommercial
	 - PVWattsCommunitySolar
	 - PVWattsHostDeveloper
	 - PVWattsLCOECalculator
	 - PVWattsLeveragedPartnershipFlip
	 - PVWattsMerchantPlant
	 - PVWattsNone
	 - PVWattsResidential
	 - PVWattsSaleLeaseback
	 - PVWattsSingleOwner
	 - PVWattsThirdParty


Saleleaseback
************************************************

Saleleaseback New Default files:

	 - StandaloneBatterySaleLeaseback

Saleleaseback Removed Default file:s

	 - DSPTSaleLeaseback
	 - DishStirlingSaleLeaseback

Saleleaseback Modified Variables:

	New variables:

		 - add_om_num_types
		 - batt_salvage_percentage
		 - battery_total_cost_lcos
		 - en_electricity_rates
		 - en_standalone_batt
		 - land_area
		 - om_batt_capacity_cost
		 - om_batt_fixed_cost
		 - om_batt_nameplate
		 - om_batt_replacement_cost
		 - om_batt_variable_cost
		 - om_land_lease
		 - om_land_lease_escal

	Removed variables:

		 - om_fuel_cost
		 - om_fuel_cost_escal
		 - om_replacement_cost1
		 - om_replacement_cost_escal
		 - system_use_recapitalization

Saleleaseback Modified Default Values:

	 - Saleleaseback_BiopowerSaleLeaseback

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'ppa_price_input', 'construction_financing_cost']

	 - Saleleaseback_DSLFSaleLeaseback

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'om_fuel_cost']

	 - Saleleaseback_EmpiricalTroughSaleLeaseback

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent']

	 - Saleleaseback_FlatPlatePVSaleLeaseback

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'ppa_price_input', 'total_installed_cost', 'construction_financing_cost', 'om_capacity']

	 - Saleleaseback_GenericBatterySaleLeaseback

		['equip1_reserve_cost', 'battery_per_kWh', 'reserves_interest', 'ppa_escalation', 'equip1_reserve_freq', 'insurance_rate', 'total_installed_cost', 'construction_financing_cost', 'om_capacity']

	 - Saleleaseback_GenericCSPSystemSaleLeaseback

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent']

	 - Saleleaseback_GenericSystemSaleLeaseback

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'ppa_price_input']

	 - Saleleaseback_GeothermalPowerSaleLeaseback

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'system_capacity', 'total_installed_cost', 'system_recapitalization_cost', 'construction_financing_cost']

	 - Saleleaseback_HighXConcentratingPVSaleLeaseback

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate']

	 - Saleleaseback_MSLFSaleLeaseback

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'om_fuel_cost']

	 - Saleleaseback_MSPTSaleLeaseback

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent']

	 - Saleleaseback_PVBatterySaleLeaseback

		['equip1_reserve_cost', 'battery_per_kWh', 'reserves_interest', 'ppa_escalation', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'ppa_price_input', 'total_installed_cost', 'construction_financing_cost', 'om_capacity']

	 - Saleleaseback_PVWattsSaleLeaseback

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'ppa_price_input', 'total_installed_cost', 'construction_financing_cost', 'om_capacity']

	 - Saleleaseback_PhysicalTroughSaleLeaseback

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent']

	 - Saleleaseback_WindPowerSaleLeaseback

		['equip1_reserve_cost', 'ptc_fed_amount', 'ppa_soln_mode', 'reserves_interest', 'insurance_rate', 'system_capacity']



Singleowner
************************************************

Singleowner New Default files:

	 - ETESSingleOwner
	 - StandaloneBatterySingleOwner

Singleowner Removed Default file:s

	 - DSPTSingleOwner
	 - DishStirlingSingleOwner

Singleowner Modified Variables:

	New variables:

		 - add_om_num_types
		 - batt_salvage_percentage
		 - battery_total_cost_lcos
		 - dscr_limit_debt_fraction
		 - dscr_maximum_debt_fraction
		 - en_electricity_rates
		 - en_standalone_batt
		 - land_area
		 - om_batt_capacity_cost
		 - om_batt_fixed_cost
		 - om_batt_nameplate
		 - om_batt_replacement_cost
		 - om_batt_variable_cost
		 - om_fuelcell_capacity_cost
		 - om_fuelcell_fixed_cost
		 - om_fuelcell_nameplate
		 - om_fuelcell_replacement_cost
		 - om_fuelcell_variable_cost
		 - om_land_lease
		 - om_land_lease_escal

	Removed variables:

		 - om_capacity1
		 - om_capacity1_nameplate
		 - om_capacity2
		 - om_capacity2_nameplate
		 - om_fixed1
		 - om_fixed2
		 - om_fuel_cost
		 - om_fuel_cost_escal
		 - om_replacement_cost1
		 - om_replacement_cost2
		 - om_replacement_cost_escal
		 - roe_input
		 - system_use_recapitalization

Singleowner Modified Default Values:

	 - Singleowner_BiopowerSingleOwner

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'ppa_price_input', 'term_int_rate']

	 - Singleowner_DSLFSingleOwner

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'om_fuel_cost', 'term_int_rate']

	 - Singleowner_EmpiricalTroughSingleOwner

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'term_int_rate']

	 - Singleowner_FlatPlatePVSingleOwner

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'ppa_price_input', 'total_installed_cost', 'term_int_rate', 'cp_system_nameplate', 'construction_financing_cost', 'om_capacity']

	 - Singleowner_FuelCellSingleOwner

		['equip1_reserve_cost', 'battery_per_kWh', 'ppa_soln_mode', 'reserves_interest', 'cost_debt_fee', 'term_tenor', 'equip1_reserve_freq', 'federal_tax_rate', 'state_tax_rate', 'batt_meter_position', 'insurance_rate', 'real_discount_rate', 'en_electricity_rates', 'ppa_price_input', 'cost_debt_closing', 'dscr', 'total_installed_cost', 'term_int_rate', 'om_capacity']

	 - Singleowner_GenericBatterySingleOwner

		['equip1_reserve_cost', 'battery_per_kWh', 'reserves_interest', 'ppa_escalation', 'equip1_reserve_freq', 'insurance_rate', 'total_installed_cost', 'term_int_rate', 'construction_financing_cost', 'cp_battery_nameplate', 'om_capacity']

	 - Singleowner_GenericCSPSystemSingleOwner

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'term_int_rate']

	 - Singleowner_GenericSystemSingleOwner

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'ppa_price_input', 'term_int_rate']

	 - Singleowner_GeothermalPowerSingleOwner

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'system_capacity', 'total_installed_cost', 'term_int_rate', 'cp_system_nameplate', 'system_recapitalization_cost', 'construction_financing_cost']

	 - Singleowner_HighXConcentratingPVSingleOwner

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate', 'term_int_rate']

	 - Singleowner_MSLFSingleOwner

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'om_fuel_cost', 'term_int_rate']

	 - Singleowner_MSPTSingleOwner

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'term_int_rate']

	 - Singleowner_PVBatterySingleOwner

		['equip1_reserve_cost', 'battery_per_kWh', 'reserves_interest', 'ppa_escalation', 'batt_computed_bank_capacity', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'ppa_price_input', 'total_installed_cost', 'term_int_rate', 'cp_system_nameplate', 'construction_financing_cost', 'om_capacity']

	 - Singleowner_PVWattsSingleOwner

		['equip1_reserve_cost', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_freq', 'insurance_rate', 'system_capacity', 'ppa_price_input', 'total_installed_cost', 'term_int_rate', 'cp_system_nameplate', 'construction_financing_cost', 'om_capacity']

	 - Singleowner_PhysicalTroughSingleOwner

		['ppa_soln_mode', 'reserves_interest', 'itc_fed_percent', 'term_int_rate']

	 - Singleowner_WindPowerSingleOwner

		['equip1_reserve_cost', 'ptc_fed_amount', 'ppa_soln_mode', 'reserves_interest', 'insurance_rate', 'system_capacity', 'term_int_rate']



TcsMSLF
************************************************

TcsMSLF Modified Default Values:

	 - TcsMSLF_MSLFLeveragedPartnershipFlip

		['weekend_schedule']

	 - TcsMSLF_MSLFMerchantPlant

		['weekend_schedule', 'weekday_schedule']



TcsdirectSteam
************************************************

TcsdirectSteam Removed Default file:s

	 - DSPTAllEquityPartnershipFlip
	 - DSPTLeveragedPartnershipFlip
	 - DSPTMerchantPlant
	 - DSPTSaleLeaseback
	 - DSPTSingleOwner


Tcsdish
************************************************

Tcsdish Removed Default file:s

	 - DishStirlingAllEquityPartnershipFlip
	 - DishStirlingCommercial
	 - DishStirlingLCOECalculator
	 - DishStirlingLeveragedPartnershipFlip
	 - DishStirlingMerchantPlant
	 - DishStirlingNone
	 - DishStirlingSaleLeaseback
	 - DishStirlingSingleOwner


TcsgenericSolar
************************************************

TcsgenericSolar Modified Default Values:

	 - TcsgenericSolar_GenericCSPSystemLeveragedPartnershipFlip

		['weekend_schedule']

	 - TcsgenericSolar_GenericCSPSystemMerchantPlant

		['system_capacity', 'weekend_schedule', 'w_des', 'qsf_des', 'weekday_schedule']



TcslinearFresnel
************************************************

TcslinearFresnel Modified Default Values:

	 - TcslinearFresnel_DSLFMerchantPlant

		['weekend_schedule', 'weekday_schedule']



TcsmoltenSalt
************************************************

TcsmoltenSalt Modified Variables:

	New variables:

		 - cav_rec_height
		 - cav_rec_passive_abs
		 - cav_rec_passive_eps
		 - cav_rec_span
		 - cav_rec_width
		 - csp_financial_model
		 - en_electricity_rates
		 - mp_energy_market_revenue
		 - n_cav_rec_panels
		 - piping_loss_coefficient
		 - ppa_soln_mode
		 - receiver_type

	Removed variables:

		 - P_high_limit
		 - _sco2_P_high_limit
		 - _sco2_P_ref
		 - _sco2_T_amb_des
		 - _sco2_T_approach
		 - _sco2_T_htf_hot_des
		 - _sco2_deltaT_PHX
		 - _sco2_design_eff
		 - _sco2_eta_c
		 - _sco2_eta_t
		 - _sco2_recup_eff_max
		 - deltaT_PHX
		 - eta_c
		 - eta_t
		 - fan_power_perc_net
		 - is_sco2_preprocess
		 - piping_loss
		 - recup_eff_max
		 - sco2_T_amb_des
		 - sco2_T_approach
		 - sco2_cycle_config
		 - sco2ud_T_amb_high
		 - sco2ud_T_amb_ind_od
		 - sco2ud_T_amb_low
		 - sco2ud_T_htf_cold_calc
		 - sco2ud_T_htf_high
		 - sco2ud_T_htf_ind_od
		 - sco2ud_T_htf_low
		 - sco2ud_m_dot_htf_high
		 - sco2ud_m_dot_htf_ind_od
		 - sco2ud_m_dot_htf_low

TcsmoltenSalt Modified Default Values:

	 - TcsmoltenSalt_MSPTAllEquityPartnershipFlip

		['weekend_schedule', 'weekday_schedule', 'sf_constant', 'const_per_interest_rate1']

	 - TcsmoltenSalt_MSPTLeveragedPartnershipFlip

		['weekend_schedule', 'weekday_schedule', 'sf_constant', 'const_per_interest_rate1']

	 - TcsmoltenSalt_MSPTMerchantPlant

		['weekend_schedule', 'weekday_schedule', 'sf_constant', 'const_per_interest_rate1']

	 - TcsmoltenSalt_MSPTSaleLeaseback

		['weekend_schedule', 'weekday_schedule', 'sf_constant', 'const_per_interest_rate1']

	 - TcsmoltenSalt_MSPTSingleOwner

		['weekend_schedule', 'weekday_schedule', 'sf_constant', 'const_per_interest_rate1']



TcstroughEmpirical
************************************************

TcstroughEmpirical Modified Default Values:

	 - TcstroughEmpirical_EmpiricalTroughAllEquityPartnershipFlip

		['CtPar']

	 - TcstroughEmpirical_EmpiricalTroughCommercial

		['CtPar']

	 - TcstroughEmpirical_EmpiricalTroughLeveragedPartnershipFlip

		['weekend_schedule', 'CtPar']

	 - TcstroughEmpirical_EmpiricalTroughMerchantPlant

		['weekend_schedule', 'CtPar', 'weekday_schedule']

	 - TcstroughEmpirical_EmpiricalTroughSaleLeaseback

		['CtPar']

	 - TcstroughEmpirical_EmpiricalTroughSingleOwner

		['CtPar']



Thirdpartyownership
************************************************

Thirdpartyownership New Default files:

	 - StandaloneBatteryThirdParty

Thirdpartyownership Modified Default Values:

	 - Thirdpartyownership_PVWattsBatteryThirdParty

		['degradation']



TroughPhysical
************************************************

TroughPhysical Removed Default file:s

	 - PhysicalTroughCommercial

TroughPhysical Modified Variables:

	New variables:

		 - csp_financial_model
		 - disp_wlim_maxspec
		 - en_electricity_rates
		 - mp_energy_market_revenue
		 - non_solar_field_land_area_multiplier
		 - ppa_soln_mode
		 - specified_solar_multiple
		 - specified_total_aperture
		 - trough_loop_control
		 - use_solar_mult_or_aperture_area

	Removed variables:

		 - SCADefocusArray
		 - SCAInfoArray
		 - is_hx
		 - solar_mult
		 - tes_lengths


TroughPhysicalProcessHeat
************************************************

TroughPhysicalProcessHeat Modified Variables:

	New variables:

		 - disp_wlim_maxspec
		 - non_solar_field_land_area_multiplier
		 - specified_solar_multiple
		 - trough_loop_control

	Removed variables:

		 - SCADefocusArray
		 - SCAInfoArray
		 - solar_mult


Utilityrate5
************************************************

Utilityrate5 New Default files:

	 - BiopowerAllEquityPartnershipFlip
	 - BiopowerLeveragedPartnershipFlip
	 - BiopowerMerchantPlant
	 - BiopowerSaleLeaseback
	 - BiopowerSingleOwner
	 - DSLFAllEquityPartnershipFlip
	 - DSLFLeveragedPartnershipFlip
	 - DSLFMerchantPlant
	 - DSLFSaleLeaseback
	 - DSLFSingleOwner
	 - EmpiricalTroughAllEquityPartnershipFlip
	 - EmpiricalTroughLeveragedPartnershipFlip
	 - EmpiricalTroughMerchantPlant
	 - EmpiricalTroughSaleLeaseback
	 - EmpiricalTroughSingleOwner
	 - FlatPlatePVAllEquityPartnershipFlip
	 - FlatPlatePVLeveragedPartnershipFlip
	 - FlatPlatePVMerchantPlant
	 - FlatPlatePVSaleLeaseback
	 - FlatPlatePVSingleOwner
	 - GenericBatteryAllEquityPartnershipFlip
	 - GenericBatteryLeveragedPartnershipFlip
	 - GenericBatteryMerchantPlant
	 - GenericBatterySaleLeaseback
	 - GenericCSPSystemAllEquityPartnershipFlip
	 - GenericCSPSystemLeveragedPartnershipFlip
	 - GenericCSPSystemMerchantPlant
	 - GenericCSPSystemSaleLeaseback
	 - GenericCSPSystemSingleOwner
	 - GenericSystemAllEquityPartnershipFlip
	 - GenericSystemLeveragedPartnershipFlip
	 - GenericSystemMerchantPlant
	 - GenericSystemSaleLeaseback
	 - GenericSystemSingleOwner
	 - GeothermalPowerAllEquityPartnershipFlip
	 - GeothermalPowerLeveragedPartnershipFlip
	 - GeothermalPowerMerchantPlant
	 - GeothermalPowerSaleLeaseback
	 - GeothermalPowerSingleOwner
	 - HighXConcentratingPVAllEquityPartnershipFlip
	 - HighXConcentratingPVLeveragedPartnershipFlip
	 - HighXConcentratingPVMerchantPlant
	 - HighXConcentratingPVSaleLeaseback
	 - HighXConcentratingPVSingleOwner
	 - MSLFAllEquityPartnershipFlip
	 - MSLFLeveragedPartnershipFlip
	 - MSLFMerchantPlant
	 - MSLFSaleLeaseback
	 - MSLFSingleOwner
	 - MSPTAllEquityPartnershipFlip
	 - MSPTLeveragedPartnershipFlip
	 - MSPTMerchantPlant
	 - MSPTSaleLeaseback
	 - MSPTSingleOwner
	 - PVBatteryAllEquityPartnershipFlip
	 - PVBatteryLeveragedPartnershipFlip
	 - PVBatteryMerchantPlant
	 - PVBatterySaleLeaseback
	 - PVWattsAllEquityPartnershipFlip
	 - PVWattsLeveragedPartnershipFlip
	 - PVWattsMerchantPlant
	 - PVWattsSaleLeaseback
	 - PVWattsSingleOwner
	 - PhysicalTroughAllEquityPartnershipFlip
	 - PhysicalTroughLeveragedPartnershipFlip
	 - PhysicalTroughMerchantPlant
	 - PhysicalTroughSaleLeaseback
	 - PhysicalTroughSingleOwner
	 - StandaloneBatteryAllEquityPartnershipFlip
	 - StandaloneBatteryCommercial
	 - StandaloneBatteryHostDeveloper
	 - StandaloneBatteryLeveragedPartnershipFlip
	 - StandaloneBatteryMerchantPlant
	 - StandaloneBatteryResidential
	 - StandaloneBatterySaleLeaseback
	 - StandaloneBatterySingleOwner
	 - StandaloneBatteryThirdParty
	 - WindPowerAllEquityPartnershipFlip
	 - WindPowerLeveragedPartnershipFlip
	 - WindPowerMerchantPlant
	 - WindPowerSaleLeaseback
	 - WindPowerSingleOwner

Utilityrate5 Removed Default file:s

	 - DishStirlingCommercial
	 - PhysicalTroughCommercial

Utilityrate5 Modified Variables:

	New variables:

		 - ur_billing_demand_lookback_percentages
		 - ur_billing_demand_lookback_period
		 - ur_billing_demand_minimum
		 - ur_dc_billing_demand_periods
		 - ur_enable_billing_demand
		 - ur_yearzero_usage_peaks

Utilityrate5 Modified Default Values:

	 - Utilityrate5_DSLFCommercial

		['ur_nm_yearend_sell_rate']

	 - Utilityrate5_EmpiricalTroughCommercial

		['ur_nm_yearend_sell_rate']

	 - Utilityrate5_FuelCellSingleOwner

		['ur_ec_sched_weekend', 'ur_dc_sched_weekday', 'ur_metering_option', 'ur_ec_sched_weekday', 'ur_dc_sched_weekend', 'ur_dc_enable', 'ur_dc_tou_mat', 'ur_nm_yearend_sell_rate', 'ur_ec_tou_mat', 'en_electricity_rates', 'ur_monthly_fixed_charge']

	 - Utilityrate5_GenericBatterySingleOwner

		['ur_dc_tou_mat', 'ur_nm_yearend_sell_rate', 'ur_ec_tou_mat']

	 - Utilityrate5_GenericCSPSystemCommercial

		['ur_nm_yearend_sell_rate']

	 - Utilityrate5_MSLFCommercial

		['ur_nm_yearend_sell_rate']

	 - Utilityrate5_PVBatterySingleOwner

		['ur_dc_tou_mat', 'ur_nm_yearend_sell_rate', 'ur_ec_tou_mat']

	 - Utilityrate5_PVWattsBatteryCommercial

		['degradation']

	 - Utilityrate5_PVWattsBatteryHostDeveloper

		['degradation']

	 - Utilityrate5_PVWattsBatteryResidential

		['degradation']

	 - Utilityrate5_PVWattsBatteryThirdParty

		['degradation']



WaveFileReader
************************************************

WaveFileReader New Default files:

	 - MEwaveNone

WaveFileReader Modified Variables:

	New variables:

		 - wave_resource_model_choice

	Removed variables:

		 - use_specific_wf_wave


Windpower
************************************************

Windpower Modified Default Values:

	 - Windpower_WindPowerAllEquityPartnershipFlip

		['system_capacity', 'wind_resource_distribution', 'wind_turbine_rotor_diameter']

	 - Windpower_WindPowerCommercial

		['wind_turbine_powercurve_powerout', 'wind_turbine_powercurve_windspeeds', 'wind_resource_distribution']

	 - Windpower_WindPowerLCOECalculator

		['wind_turbine_powercurve_powerout', 'system_capacity', 'wind_resource_distribution', 'wind_turbine_rotor_diameter', 'wind_farm_yCoordinates', 'wind_farm_xCoordinates']

	 - Windpower_WindPowerLeveragedPartnershipFlip

		['system_capacity', 'wind_resource_distribution', 'wind_turbine_rotor_diameter']

	 - Windpower_WindPowerMerchantPlant

		['system_capacity', 'wind_resource_distribution', 'wind_turbine_rotor_diameter']

	 - Windpower_WindPowerNone

		['wind_resource_distribution']

	 - Windpower_WindPowerResidential

		['wind_resource_distribution']

	 - Windpower_WindPowerSaleLeaseback

		['system_capacity', 'wind_resource_distribution', 'wind_turbine_rotor_diameter']

	 - Windpower_WindPowerSingleOwner

		['system_capacity', 'wind_resource_distribution', 'wind_turbine_rotor_diameter']



