.. Version Changes:

Changes to Modules with Version 2.3.0
===============================================

This document shows the changes for each Module

Battery
************************************************

:doc:`modules/Battery` New Default files:

	 - StandaloneBatteryAllEquityPartnershipFlip
	 - StandaloneBatteryCommercial
	 - StandaloneBatteryHostDeveloper
	 - StandaloneBatteryLeveragedPartnershipFlip
	 - StandaloneBatteryMerchantPlant
	 - StandaloneBatteryResidential
	 - StandaloneBatterySaleLeaseback
	 - StandaloneBatterySingleOwner
	 - StandaloneBatteryThirdParty

:doc:`modules/Battery` Modified Variables:

	New variables:

		 - batt_dispatch_auto_btm_can_discharge_to_grid
		 - batt_dispatch_auto_can_clipcharge
		 - batt_dispatch_charge_only_system_exceeds_load
		 - batt_dispatch_discharge_only_load_exceeds_system
		 - batt_dispatch_load_forecast_choice
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

		 - ur_ec_billing_demand_lookback_percentages
		 - ur_ec_billing_demand_lookback_period
		 - ur_ec_billing_demand_minimum
		 - ur_ec_enable_billing_demand

:doc:`modules/Battery` Modified Default Values:

	 - Battery_FuelCellCommercial

		['batt_room_temperature_celsius', 'ur_yearzero_usage_peaks', 'batt_calendar_choice', 'batt_calendar_c']

	 - Battery_FuelCellSingleOwner

		['batt_room_temperature_celsius', 'ur_ec_sched_weekend', 'ur_ec_tou_mat', 'ur_monthly_fixed_charge', 'ur_ec_sched_weekday', 'batt_calendar_choice', 'ur_dc_enable', 'batt_meter_position', 'ur_dc_sched_weekend', 'ur_dc_tou_mat', 'ur_dc_sched_weekday', 'batt_calendar_c', 'batt_minimum_SOC', 'ppa_price_input']

	 - Battery_GenericBatteryAllEquityPartnershipFlip

		['dispatch_manual_sched', 'dispatch_manual_sched_weekend', 'batt_h_to_ambient', 'batt_calendar_c']

	 - Battery_GenericBatteryCommercial

		['batt_calendar_c', 'batt_minimum_SOC']

	 - Battery_GenericBatteryHostDeveloper

		['batt_calendar_c', 'batt_minimum_SOC']

	 - Battery_GenericBatteryLeveragedPartnershipFlip

		['dispatch_manual_sched', 'dispatch_manual_sched_weekend', 'batt_h_to_ambient', 'batt_calendar_c']

	 - Battery_GenericBatteryMerchantPlant

		['batt_dispatch_choice', 'mp_ancserv2_revenue', 'batt_dispatch_auto_can_clipcharge', 'dispatch_manual_sched', 'mp_ancserv3_revenue', 'dispatch_manual_sched_weekend', 'batt_room_temperature_celsius', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'batt_h_to_ambient', 'batt_calendar_c', 'mp_ancserv4_revenue']

	 - Battery_GenericBatteryResidential

		['batt_dispatch_choice', 'ur_yearzero_usage_peaks', 'batt_calendar_c', 'batt_minimum_SOC']

	 - Battery_GenericBatterySaleLeaseback

		['dispatch_manual_sched', 'dispatch_manual_sched_weekend', 'batt_h_to_ambient', 'batt_calendar_c']

	 - Battery_GenericBatterySingleOwner

		['dispatch_manual_sched', 'dispatch_manual_sched_weekend', 'batt_h_to_ambient', 'ur_ec_tou_mat', 'ur_dc_tou_mat', 'batt_calendar_c']

	 - Battery_GenericBatteryThirdParty

		['ur_yearzero_usage_peaks', 'batt_calendar_c', 'batt_minimum_SOC']

	 - Battwatts_PVWattsBatteryCommercial

		['batt_simple_kwh', 'batt_simple_kw']

	 - Battwatts_PVWattsBatteryHostDeveloper

		['batt_simple_kwh', 'batt_simple_kw']

	 - Battwatts_PVWattsBatteryResidential

		['batt_simple_kwh', 'batt_simple_kw']

	 - Battwatts_PVWattsBatteryThirdParty

		['batt_simple_kwh', 'batt_simple_kw']

	 - Cashloan_GenericBatteryCommercial

		['om_batt_capacity_cost', 'om_batt_replacement_cost', 'loan_rate', 'battery_per_kWh']

	 - Cashloan_GenericBatteryResidential

		['om_batt_capacity_cost', 'om_batt_replacement_cost', 'loan_rate', 'om_capacity', 'battery_per_kWh', 'federal_tax_rate']

	 - Cashloan_PVBatteryCommercial

		['om_batt_capacity_cost', 'om_batt_replacement_cost', 'loan_rate', 'om_capacity', 'battery_per_kWh']

	 - Cashloan_PVBatteryResidential

		['om_batt_capacity_cost', 'om_batt_replacement_cost', 'loan_rate', 'battery_per_kWh', 'federal_tax_rate']

	 - Cashloan_PVWattsBatteryCommercial

		['om_capacity', 'total_installed_cost', 'battery_per_kWh', 'degradation', 'battery_total_cost_lcos']

	 - Cashloan_PVWattsBatteryResidential

		['system_capacity', 'battery_per_kWh', 'degradation', 'federal_tax_rate']

	 - Equpartflip_GenericBatteryAllEquityPartnershipFlip

		['insurance_rate', 'om_batt_capacity_cost', 'reserves_interest', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'equip1_reserve_freq', 'ppa_escalation', 'om_capacity', 'battery_per_kWh']

	 - Equpartflip_PVBatteryAllEquityPartnershipFlip

		['insurance_rate', 'om_batt_capacity_cost', 'reserves_interest', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'equip1_reserve_freq', 'ppa_escalation', 'om_capacity', 'ppa_price_input', 'battery_per_kWh']

	 - HostDeveloper_GenericBatteryHostDeveloper

		['om_batt_capacity_cost', 'reserves_interest', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'equip1_reserve_freq', 'term_int_rate', 'battery_per_kWh']

	 - HostDeveloper_PVBatteryHostDeveloper

		['om_batt_capacity_cost', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'equip1_reserve_freq', 'om_capacity', 'battery_per_kWh']

	 - HostDeveloper_PVWattsBatteryHostDeveloper

		['construction_financing_cost', 'total_installed_cost', 'battery_per_kWh', 'degradation', 'battery_total_cost_lcos']

	 - Levpartflip_GenericBatteryLeveragedPartnershipFlip

		['insurance_rate', 'om_batt_capacity_cost', 'reserves_interest', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'equip1_reserve_freq', 'ppa_escalation', 'om_capacity', 'term_int_rate', 'battery_per_kWh']

	 - Levpartflip_PVBatteryLeveragedPartnershipFlip

		['insurance_rate', 'om_batt_capacity_cost', 'reserves_interest', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'equip1_reserve_freq', 'ppa_escalation', 'om_capacity', 'term_int_rate', 'ppa_price_input', 'battery_per_kWh']

	 - Merchantplant_GenericBatteryMerchantPlant

		['insurance_rate', 'om_batt_capacity_cost', 'mp_ancserv2_revenue', 'reserves_interest', 'om_batt_replacement_cost', 'mp_ancserv3_revenue', 'equip1_reserve_cost', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'equip1_reserve_freq', 'om_capacity', 'term_int_rate', 'battery_per_kWh', 'mp_ancserv4_revenue']

	 - Merchantplant_PVBatteryMerchantPlant

		['insurance_rate', 'om_batt_capacity_cost', 'mp_ancserv2_revenue', 'reserves_interest', 'om_batt_replacement_cost', 'mp_ancserv3_revenue', 'equip1_reserve_cost', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'equip1_reserve_freq', 'om_capacity', 'term_int_rate', 'battery_per_kWh', 'mp_ancserv4_revenue']

	 - Pvsamv1_PVBatteryAllEquityPartnershipFlip

		['inv_tdc_cec_cg', 'subarray1_tilt', 'subarray1_track_mode', 'batt_calendar_c', 'inverter_count', 'inv_tdc_ds', 'dispatch_manual_sched_weekend', 'use_wf_albedo', 'ppa_price_input', 'inv_tdc_plc', 'inv_tdc_cec_db', 'dispatch_manual_sched', 'batt_h_to_ambient']

	 - Pvsamv1_PVBatteryCommercial

		['inv_tdc_cec_cg', 'batt_calendar_c', 'inv_tdc_ds', 'ur_yearzero_usage_peaks', 'use_wf_albedo', 'inv_tdc_plc', 'inv_tdc_cec_db', 'batt_minimum_SOC']

	 - Pvsamv1_PVBatteryHostDeveloper

		['inv_tdc_cec_cg', 'batt_calendar_c', 'inv_tdc_ds', 'use_wf_albedo', 'inv_tdc_plc', 'inv_tdc_cec_db', 'batt_minimum_SOC']

	 - Pvsamv1_PVBatteryLeveragedPartnershipFlip

		['inv_tdc_cec_cg', 'subarray1_tilt', 'subarray1_track_mode', 'batt_calendar_c', 'inverter_count', 'inv_tdc_ds', 'dispatch_manual_sched_weekend', 'use_wf_albedo', 'ppa_price_input', 'inv_tdc_plc', 'inv_tdc_cec_db', 'dispatch_manual_sched', 'batt_h_to_ambient']

	 - Pvsamv1_PVBatteryMerchantPlant

		['mp_ancserv2_revenue', 'inv_tdc_cec_cg', 'subarray1_tilt', 'mp_ancserv4_revenue', 'subarray1_track_mode', 'mp_ancserv3_revenue', 'batt_calendar_c', 'inverter_count', 'inv_tdc_ds', 'dispatch_manual_sched_weekend', 'batt_room_temperature_celsius', 'use_wf_albedo', 'inv_tdc_plc', 'inv_tdc_cec_db', 'dispatch_manual_sched', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'batt_h_to_ambient']

	 - Pvsamv1_PVBatteryResidential

		['inv_tdc_cec_cg', 'subarray2_mismatch_loss', 'dcoptimizer_loss', 'subarray1_mismatch_loss', 'batt_calendar_c', 'subarray3_mismatch_loss', 'subarray4_mismatch_loss', 'inv_tdc_ds', 'ur_yearzero_usage_peaks', 'use_wf_albedo', 'inv_tdc_plc', 'inv_tdc_cec_db', 'batt_minimum_SOC']

	 - Pvsamv1_PVBatterySaleLeaseback

		['inv_tdc_cec_cg', 'subarray1_tilt', 'subarray1_track_mode', 'batt_calendar_c', 'inverter_count', 'inv_tdc_ds', 'dispatch_manual_sched_weekend', 'use_wf_albedo', 'ppa_price_input', 'inv_tdc_plc', 'inv_tdc_cec_db', 'dispatch_manual_sched', 'batt_h_to_ambient']

	 - Pvsamv1_PVBatterySingleOwner

		['batt_mass', 'batt_power_charge_max_kwdc', 'inv_tdc_cec_cg', 'subarray1_tilt', 'batt_computed_strings', 'batt_computed_bank_capacity', 'subarray1_track_mode', 'batt_current_discharge_max', 'batt_current_charge_max', 'ur_ec_tou_mat', 'batt_calendar_c', 'batt_surface_area', 'inverter_count', 'batt_power_charge_max_kwac', 'inv_tdc_ds', 'dispatch_manual_sched_weekend', 'ur_yearzero_usage_peaks', 'ur_dc_tou_mat', 'batt_Qfull_flow', 'use_wf_albedo', 'ppa_price_input', 'inv_tdc_plc', 'inv_tdc_cec_db', 'dispatch_manual_sched', 'batt_h_to_ambient', 'batt_power_discharge_max_kwdc', 'batt_power_discharge_max_kwac']

	 - Pvsamv1_PVBatteryThirdParty

		['inv_tdc_cec_cg', 'subarray2_mismatch_loss', 'dcoptimizer_loss', 'subarray1_mismatch_loss', 'batt_calendar_c', 'subarray3_mismatch_loss', 'subarray4_mismatch_loss', 'inv_tdc_ds', 'ur_yearzero_usage_peaks', 'use_wf_albedo', 'inv_tdc_plc', 'inv_tdc_cec_db', 'batt_minimum_SOC']

	 - Saleleaseback_GenericBatterySaleLeaseback

		['insurance_rate', 'om_batt_capacity_cost', 'reserves_interest', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'equip1_reserve_freq', 'ppa_escalation', 'om_capacity', 'battery_per_kWh']

	 - Saleleaseback_PVBatterySaleLeaseback

		['insurance_rate', 'om_batt_capacity_cost', 'reserves_interest', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'equip1_reserve_freq', 'ppa_escalation', 'om_capacity', 'ppa_price_input', 'battery_per_kWh']

	 - Singleowner_GenericBatterySingleOwner

		['insurance_rate', 'om_batt_capacity_cost', 'reserves_interest', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'equip1_reserve_freq', 'ppa_escalation', 'om_capacity', 'term_int_rate', 'battery_per_kWh']

	 - Singleowner_PVBatterySingleOwner

		['insurance_rate', 'om_batt_capacity_cost', 'reserves_interest', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'om_batt_nameplate', 'equip1_reserve_freq', 'construction_financing_cost', 'ppa_escalation', 'om_capacity', 'total_installed_cost', 'term_int_rate', 'ppa_price_input', 'battery_per_kWh', 'batt_computed_bank_capacity', 'battery_total_cost_lcos']

	 - Thirdpartyownership_PVWattsBatteryThirdParty

		['degradation']

	 - Utilityrate5_GenericBatteryResidential

		['ur_yearzero_usage_peaks']

	 - Utilityrate5_GenericBatterySingleOwner

		['ur_ec_tou_mat', 'ur_dc_tou_mat']

	 - Utilityrate5_GenericBatteryThirdParty

		['ur_yearzero_usage_peaks']

	 - Utilityrate5_PVBatteryCommercial

		['ur_yearzero_usage_peaks']

	 - Utilityrate5_PVBatteryResidential

		['ur_yearzero_usage_peaks']

	 - Utilityrate5_PVBatterySingleOwner

		['ur_ec_tou_mat', 'ur_dc_tou_mat', 'ur_yearzero_usage_peaks']

	 - Utilityrate5_PVBatteryThirdParty

		['ur_yearzero_usage_peaks']

	 - Utilityrate5_PVWattsBatteryCommercial

		['degradation', 'ur_yearzero_usage_peaks']

	 - Utilityrate5_PVWattsBatteryHostDeveloper

		['degradation']

	 - Utilityrate5_PVWattsBatteryResidential

		['degradation', 'ur_yearzero_usage_peaks']

	 - Utilityrate5_PVWattsBatteryThirdParty

		['degradation', 'ur_yearzero_usage_peaks']



Battwatts
************************************************

:doc:`modules/Battwatts` Modified Variables:

	New variables:

		 - grid_outage

:doc:`modules/Battwatts` Modified Default Values:

	 - Battwatts_PVWattsBatteryCommercial

		['batt_simple_kwh', 'batt_simple_kw']

	 - Battwatts_PVWattsBatteryHostDeveloper

		['batt_simple_kwh', 'batt_simple_kw']

	 - Battwatts_PVWattsBatteryResidential

		['batt_simple_kwh', 'batt_simple_kw']

	 - Battwatts_PVWattsBatteryThirdParty

		['batt_simple_kwh', 'batt_simple_kw']



Belpe
************************************************

:doc:`modules/Belpe` New Default files:

	 - StandaloneBatteryResidential
	 - StandaloneBatteryThirdParty


Cashloan
************************************************

:doc:`modules/Cashloan` New Default files:

	 - StandaloneBatteryCommercial
	 - StandaloneBatteryResidential

:doc:`modules/Cashloan` Removed Default files

	 - PhysicalTroughCommercial

:doc:`modules/Cashloan` Modified Variables:

	New variables:

		 - charge_w_sys_dc_tou_ym
		 - charge_w_sys_fixed_ym
		 - en_standalone_batt
		 - land_area
		 - net_billing_credits_ym
		 - nm_dollars_applied_ym
		 - om_land_lease
		 - om_land_lease_escal
		 - utility_bill_w_sys
		 - year1_hourly_dc_with_system
		 - year1_hourly_e_fromgrid
		 - year1_hourly_ec_with_system

:doc:`modules/Cashloan` Modified Default Values:

	 - Cashloan_DSLFCommercial

		['loan_rate']

	 - Cashloan_EmpiricalTroughCommercial

		['loan_rate']

	 - Cashloan_FlatPlatePVCommercial

		['insurance_rate', 'loan_rate', 'om_capacity']

	 - Cashloan_FlatPlatePVResidential

		['insurance_rate', 'system_capacity', 'loan_rate', 'total_installed_cost']

	 - Cashloan_FuelCellCommercial

		['om_fuelcell_capacity_cost', 'insurance_rate', 'om_batt_capacity_cost', 'om_batt_replacement_cost', 'loan_rate', 'battery_per_kWh']

	 - Cashloan_GenericBatteryCommercial

		['om_batt_capacity_cost', 'om_batt_replacement_cost', 'loan_rate', 'battery_per_kWh']

	 - Cashloan_GenericBatteryResidential

		['om_batt_capacity_cost', 'om_batt_replacement_cost', 'loan_rate', 'om_capacity', 'battery_per_kWh', 'federal_tax_rate']

	 - Cashloan_GenericCSPSystemCommercial

		['loan_rate']

	 - Cashloan_GenericSystemCommercial

		['loan_rate']

	 - Cashloan_GenericSystemResidential

		['loan_rate', 'federal_tax_rate']

	 - Cashloan_MSLFCommercial

		['loan_rate']

	 - Cashloan_PVBatteryCommercial

		['om_batt_capacity_cost', 'om_batt_replacement_cost', 'loan_rate', 'om_capacity', 'battery_per_kWh']

	 - Cashloan_PVBatteryResidential

		['om_batt_capacity_cost', 'om_batt_replacement_cost', 'loan_rate', 'battery_per_kWh', 'federal_tax_rate']

	 - Cashloan_PVWattsBatteryCommercial

		['om_capacity', 'total_installed_cost', 'battery_per_kWh', 'degradation', 'battery_total_cost_lcos']

	 - Cashloan_PVWattsBatteryResidential

		['system_capacity', 'battery_per_kWh', 'degradation', 'federal_tax_rate']

	 - Cashloan_PVWattsCommercial

		['insurance_rate', 'loan_rate', 'om_capacity']

	 - Cashloan_PVWattsResidential

		['insurance_rate', 'system_capacity', 'loan_rate']

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

:doc:`modules/Communitysolar` New Default files:

	 - PVWattsCommunitySolar


Equpartflip
************************************************

:doc:`modules/Equpartflip` New Default files:

	 - StandaloneBatteryAllEquityPartnershipFlip

:doc:`modules/Equpartflip` Modified Variables:

	New variables:

		 - en_electricity_rates
		 - en_standalone_batt
		 - land_area
		 - om_land_lease
		 - om_land_lease_escal

:doc:`modules/Equpartflip` Modified Default Values:

	 - Equpartflip_BiopowerAllEquityPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'construction_financing_cost', 'ppa_price_input']

	 - Equpartflip_DSLFAllEquityPartnershipFlip

		['ppa_soln_mode', 'reserves_interest']

	 - Equpartflip_EmpiricalTroughAllEquityPartnershipFlip

		['ppa_soln_mode', 'reserves_interest']

	 - Equpartflip_FlatPlatePVAllEquityPartnershipFlip

		['insurance_rate', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'equip1_reserve_freq', 'om_capacity', 'ppa_price_input']

	 - Equpartflip_GenericBatteryAllEquityPartnershipFlip

		['insurance_rate', 'om_batt_capacity_cost', 'reserves_interest', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'equip1_reserve_freq', 'ppa_escalation', 'om_capacity', 'battery_per_kWh']

	 - Equpartflip_GenericCSPSystemAllEquityPartnershipFlip

		['ppa_soln_mode', 'reserves_interest']

	 - Equpartflip_GenericSystemAllEquityPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'ppa_price_input']

	 - Equpartflip_GeothermalPowerAllEquityPartnershipFlip

		['ppa_soln_mode', 'system_capacity', 'reserves_interest', 'equip1_reserve_cost', 'construction_financing_cost', 'system_recapitalization_cost', 'total_installed_cost']

	 - Equpartflip_HighXConcentratingPVAllEquityPartnershipFlip

		['insurance_rate', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'equip1_reserve_freq']

	 - Equpartflip_MSLFAllEquityPartnershipFlip

		['ppa_soln_mode', 'reserves_interest']

	 - Equpartflip_MSPTAllEquityPartnershipFlip

		['ppa_soln_mode', 'reserves_interest']

	 - Equpartflip_PVBatteryAllEquityPartnershipFlip

		['insurance_rate', 'om_batt_capacity_cost', 'reserves_interest', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'equip1_reserve_freq', 'ppa_escalation', 'om_capacity', 'ppa_price_input', 'battery_per_kWh']

	 - Equpartflip_PVWattsAllEquityPartnershipFlip

		['insurance_rate', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'equip1_reserve_freq', 'om_capacity', 'ppa_price_input']

	 - Equpartflip_PhysicalTroughAllEquityPartnershipFlip

		['ppa_soln_mode', 'reserves_interest']

	 - Equpartflip_WindPowerAllEquityPartnershipFlip

		['insurance_rate', 'ppa_soln_mode', 'system_capacity', 'reserves_interest', 'equip1_reserve_cost']



EtesElectricResistance
************************************************

:doc:`modules/EtesElectricResistance` New Default files:

	 - ETESSingleOwner


GenericSystem
************************************************

:doc:`modules/GenericSystem` Modified Default Values:

	 - Cashloan_GenericSystemCommercial

		['loan_rate']

	 - Cashloan_GenericSystemResidential

		['loan_rate', 'federal_tax_rate']

	 - Equpartflip_GenericSystemAllEquityPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'ppa_price_input']

	 - GenericSystem_GenericSystemHostDeveloper

		['user_capacity_factor']

	 - GenericSystem_GenericSystemLeveragedPartnershipFlip

		['user_capacity_factor']

	 - GenericSystem_GenericSystemMerchantPlant

		['user_capacity_factor']

	 - HostDeveloper_GenericSystemHostDeveloper

		['state_tax_rate', 'reserves_interest', 'term_int_rate']

	 - Levpartflip_GenericSystemLeveragedPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'term_int_rate', 'ppa_price_input']

	 - Merchantplant_GenericSystemMerchantPlant

		['mp_ancserv2_revenue', 'reserves_interest', 'mp_ancserv3_revenue', 'equip1_reserve_cost', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'term_int_rate', 'mp_ancserv4_revenue']

	 - Saleleaseback_GenericSystemSaleLeaseback

		['ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'ppa_price_input']

	 - Singleowner_GenericSystemSingleOwner

		['ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'term_int_rate', 'ppa_price_input']

	 - Utilityrate5_GenericSystemThirdParty

		['ur_yearzero_usage_peaks']



Geothermal
************************************************

:doc:`modules/Geothermal` Modified Variables:

	New variables:

		 - dt_prod_well

:doc:`modules/Geothermal` Modified Default Values:

	 - Equpartflip_GeothermalPowerAllEquityPartnershipFlip

		['ppa_soln_mode', 'system_capacity', 'reserves_interest', 'equip1_reserve_cost', 'construction_financing_cost', 'system_recapitalization_cost', 'total_installed_cost']

	 - Geothermal_GeothermalPowerAllEquityPartnershipFlip

		['well_flow_rate', 'num_wells_getem', 'well_diameter']

	 - Geothermal_GeothermalPowerLCOECalculator

		['num_wells_getem']

	 - Geothermal_GeothermalPowerLeveragedPartnershipFlip

		['num_wells_getem']

	 - Geothermal_GeothermalPowerMerchantPlant

		['well_flow_rate', 'num_wells_getem', 'well_diameter']

	 - Geothermal_GeothermalPowerNone

		['num_wells_getem']

	 - Geothermal_GeothermalPowerSaleLeaseback

		['num_wells_getem']

	 - Geothermal_GeothermalPowerSingleOwner

		['num_wells_getem']

	 - Lcoefcr_GeothermalPowerLCOECalculator

		['fixed_operating_cost', 'capital_cost']

	 - Levpartflip_GeothermalPowerLeveragedPartnershipFlip

		['ppa_soln_mode', 'system_capacity', 'reserves_interest', 'equip1_reserve_cost', 'construction_financing_cost', 'system_recapitalization_cost', 'total_installed_cost', 'term_int_rate']

	 - Merchantplant_GeothermalPowerMerchantPlant

		['cp_system_nameplate', 'system_capacity', 'mp_ancserv2_revenue', 'reserves_interest', 'mp_ancserv3_revenue', 'equip1_reserve_cost', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'construction_financing_cost', 'system_recapitalization_cost', 'total_installed_cost', 'term_int_rate', 'mp_ancserv4_revenue']

	 - Saleleaseback_GeothermalPowerSaleLeaseback

		['ppa_soln_mode', 'system_capacity', 'reserves_interest', 'equip1_reserve_cost', 'construction_financing_cost', 'system_recapitalization_cost', 'total_installed_cost']

	 - Singleowner_GeothermalPowerSingleOwner

		['cp_system_nameplate', 'ppa_soln_mode', 'system_capacity', 'reserves_interest', 'equip1_reserve_cost', 'construction_financing_cost', 'system_recapitalization_cost', 'total_installed_cost', 'term_int_rate']



Grid
************************************************

:doc:`modules/Grid` New Default files:

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

:doc:`modules/Grid` Removed Default files

	 - PhysicalTroughCommercial

:doc:`modules/Grid` Modified Variables:

	New variables:

		 - crit_load
		 - grid_outage


HostDeveloper
************************************************

:doc:`modules/HostDeveloper` New Default files:

	 - StandaloneBatteryHostDeveloper

:doc:`modules/HostDeveloper` Modified Variables:

	New variables:

		 - charge_w_sys_fixed_ym
		 - dscr_limit_debt_fraction
		 - dscr_maximum_debt_fraction
		 - en_standalone_batt
		 - net_billing_credits_ym
		 - nm_dollars_applied_ym
		 - year1_hourly_dc_with_system
		 - year1_hourly_e_fromgrid
		 - year1_hourly_ec_with_system

	Removed variables:

		 - roe_input

:doc:`modules/HostDeveloper` Modified Default Values:

	 - Battery_GenericBatteryHostDeveloper

		['batt_calendar_c', 'batt_minimum_SOC']

	 - Battwatts_PVWattsBatteryHostDeveloper

		['batt_simple_kwh', 'batt_simple_kw']

	 - GenericSystem_GenericSystemHostDeveloper

		['user_capacity_factor']

	 - HostDeveloper_FlatPlatePVHostDeveloper

		['insurance_rate', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'equip1_reserve_freq', 'om_capacity', 'term_int_rate']

	 - HostDeveloper_GenericBatteryHostDeveloper

		['om_batt_capacity_cost', 'reserves_interest', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'equip1_reserve_freq', 'term_int_rate', 'battery_per_kWh']

	 - HostDeveloper_GenericSystemHostDeveloper

		['state_tax_rate', 'reserves_interest', 'term_int_rate']

	 - HostDeveloper_PVBatteryHostDeveloper

		['om_batt_capacity_cost', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'equip1_reserve_freq', 'om_capacity', 'battery_per_kWh']

	 - HostDeveloper_PVWattsBatteryHostDeveloper

		['construction_financing_cost', 'total_installed_cost', 'battery_per_kWh', 'degradation', 'battery_total_cost_lcos']

	 - HostDeveloper_PVWattsHostDeveloper

		['insurance_rate', 'reserves_interest', 'equip1_reserve_cost', 'equip1_reserve_freq', 'om_capacity', 'term_int_rate']

	 - Pvsamv1_FlatPlatePVHostDeveloper

		['inv_tdc_cec_cg', 'inv_tdc_ds', 'use_wf_albedo', 'inv_tdc_plc', 'inv_tdc_cec_db']

	 - Pvsamv1_PVBatteryHostDeveloper

		['inv_tdc_cec_cg', 'batt_calendar_c', 'inv_tdc_ds', 'use_wf_albedo', 'inv_tdc_plc', 'inv_tdc_cec_db', 'batt_minimum_SOC']

	 - Utilityrate5_PVWattsBatteryHostDeveloper

		['degradation']



Lcoefcr
************************************************

:doc:`modules/Lcoefcr` Modified Default Values:

	 - Lcoefcr_FlatPlatePVLCOECalculator

		['fixed_charge_rate', 'fixed_operating_cost', 'capital_cost']

	 - Lcoefcr_GeothermalPowerLCOECalculator

		['fixed_operating_cost', 'capital_cost']

	 - Lcoefcr_MEtidalLCOECalculator

		['annual_energy', 'fixed_operating_cost', 'capital_cost']

	 - Lcoefcr_MEwaveLCOECalculator

		['annual_energy', 'capital_cost']

	 - Lcoefcr_PVWattsLCOECalculator

		['fixed_charge_rate', 'fixed_operating_cost', 'capital_cost']

	 - Lcoefcr_WindPowerLCOECalculator

		['fixed_charge_rate', 'fixed_operating_cost', 'capital_cost']



Levpartflip
************************************************

:doc:`modules/Levpartflip` New Default files:

	 - StandaloneBatteryLeveragedPartnershipFlip

:doc:`modules/Levpartflip` Modified Variables:

	New variables:

		 - dscr_limit_debt_fraction
		 - dscr_maximum_debt_fraction
		 - en_electricity_rates
		 - en_standalone_batt
		 - land_area
		 - om_land_lease
		 - om_land_lease_escal

:doc:`modules/Levpartflip` Modified Default Values:

	 - Levpartflip_BiopowerLeveragedPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'construction_financing_cost', 'term_int_rate', 'ppa_price_input']

	 - Levpartflip_DSLFLeveragedPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'term_int_rate']

	 - Levpartflip_EmpiricalTroughLeveragedPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'term_int_rate']

	 - Levpartflip_FlatPlatePVLeveragedPartnershipFlip

		['insurance_rate', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'equip1_reserve_freq', 'om_capacity', 'term_int_rate', 'ppa_price_input']

	 - Levpartflip_GenericBatteryLeveragedPartnershipFlip

		['insurance_rate', 'om_batt_capacity_cost', 'reserves_interest', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'equip1_reserve_freq', 'ppa_escalation', 'om_capacity', 'term_int_rate', 'battery_per_kWh']

	 - Levpartflip_GenericCSPSystemLeveragedPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'term_int_rate']

	 - Levpartflip_GenericSystemLeveragedPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'term_int_rate', 'ppa_price_input']

	 - Levpartflip_GeothermalPowerLeveragedPartnershipFlip

		['ppa_soln_mode', 'system_capacity', 'reserves_interest', 'equip1_reserve_cost', 'construction_financing_cost', 'system_recapitalization_cost', 'total_installed_cost', 'term_int_rate']

	 - Levpartflip_HighXConcentratingPVLeveragedPartnershipFlip

		['insurance_rate', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'equip1_reserve_freq', 'term_int_rate']

	 - Levpartflip_MSLFLeveragedPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'term_int_rate']

	 - Levpartflip_MSPTLeveragedPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'term_int_rate']

	 - Levpartflip_PVBatteryLeveragedPartnershipFlip

		['insurance_rate', 'om_batt_capacity_cost', 'reserves_interest', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'equip1_reserve_freq', 'ppa_escalation', 'om_capacity', 'term_int_rate', 'ppa_price_input', 'battery_per_kWh']

	 - Levpartflip_PVWattsLeveragedPartnershipFlip

		['insurance_rate', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'equip1_reserve_freq', 'om_capacity', 'term_int_rate', 'ppa_price_input']

	 - Levpartflip_PhysicalTroughLeveragedPartnershipFlip

		['ppa_soln_mode', 'reserves_interest', 'term_int_rate']

	 - Levpartflip_WindPowerLeveragedPartnershipFlip

		['insurance_rate', 'ppa_soln_mode', 'system_capacity', 'reserves_interest', 'equip1_reserve_cost', 'term_int_rate']



Merchantplant
************************************************

:doc:`modules/Merchantplant` New Default files:

	 - StandaloneBatteryMerchantPlant

:doc:`modules/Merchantplant` Modified Variables:

	New variables:

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
		 - om_land_lease
		 - om_land_lease_escal

	Removed variables:

		 - roe_input

:doc:`modules/Merchantplant` Modified Default Values:

	 - Merchantplant_BiopowerMerchantPlant

		['mp_ancserv2_revenue', 'reserves_interest', 'mp_ancserv3_revenue', 'equip1_reserve_cost', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'term_int_rate', 'mp_ancserv4_revenue']

	 - Merchantplant_DSLFMerchantPlant

		['mp_ancserv2_revenue', 'reserves_interest', 'mp_ancserv3_revenue', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'term_int_rate', 'mp_ancserv4_revenue']

	 - Merchantplant_EmpiricalTroughMerchantPlant

		['mp_ancserv2_revenue', 'reserves_interest', 'mp_ancserv3_revenue', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'term_int_rate', 'mp_ancserv4_revenue']

	 - Merchantplant_FlatPlatePVMerchantPlant

		['insurance_rate', 'mp_ancserv2_revenue', 'reserves_interest', 'mp_ancserv3_revenue', 'equip1_reserve_cost', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'equip1_reserve_freq', 'om_capacity', 'term_int_rate', 'mp_ancserv4_revenue']

	 - Merchantplant_GenericBatteryMerchantPlant

		['insurance_rate', 'om_batt_capacity_cost', 'mp_ancserv2_revenue', 'reserves_interest', 'om_batt_replacement_cost', 'mp_ancserv3_revenue', 'equip1_reserve_cost', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'equip1_reserve_freq', 'om_capacity', 'term_int_rate', 'battery_per_kWh', 'mp_ancserv4_revenue']

	 - Merchantplant_GenericCSPSystemMerchantPlant

		['cp_system_nameplate', 'system_capacity', 'mp_ancserv2_revenue', 'reserves_interest', 'mp_ancserv3_revenue', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'construction_financing_cost', 'total_installed_cost', 'term_int_rate', 'mp_ancserv4_revenue']

	 - Merchantplant_GenericSystemMerchantPlant

		['mp_ancserv2_revenue', 'reserves_interest', 'mp_ancserv3_revenue', 'equip1_reserve_cost', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'term_int_rate', 'mp_ancserv4_revenue']

	 - Merchantplant_GeothermalPowerMerchantPlant

		['cp_system_nameplate', 'system_capacity', 'mp_ancserv2_revenue', 'reserves_interest', 'mp_ancserv3_revenue', 'equip1_reserve_cost', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'construction_financing_cost', 'system_recapitalization_cost', 'total_installed_cost', 'term_int_rate', 'mp_ancserv4_revenue']

	 - Merchantplant_HighXConcentratingPVMerchantPlant

		['insurance_rate', 'mp_ancserv2_revenue', 'reserves_interest', 'mp_ancserv3_revenue', 'equip1_reserve_cost', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'equip1_reserve_freq', 'term_int_rate', 'mp_ancserv4_revenue']

	 - Merchantplant_MSLFMerchantPlant

		['mp_ancserv2_revenue', 'reserves_interest', 'mp_ancserv3_revenue', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'term_int_rate', 'mp_ancserv4_revenue']

	 - Merchantplant_MSPTMerchantPlant

		['mp_ancserv2_revenue', 'reserves_interest', 'mp_ancserv3_revenue', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'term_int_rate', 'mp_ancserv4_revenue']

	 - Merchantplant_PVBatteryMerchantPlant

		['insurance_rate', 'om_batt_capacity_cost', 'mp_ancserv2_revenue', 'reserves_interest', 'om_batt_replacement_cost', 'mp_ancserv3_revenue', 'equip1_reserve_cost', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'equip1_reserve_freq', 'om_capacity', 'term_int_rate', 'battery_per_kWh', 'mp_ancserv4_revenue']

	 - Merchantplant_PVWattsMerchantPlant

		['insurance_rate', 'mp_ancserv2_revenue', 'reserves_interest', 'mp_ancserv3_revenue', 'equip1_reserve_cost', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'equip1_reserve_freq', 'om_capacity', 'term_int_rate', 'mp_ancserv4_revenue']

	 - Merchantplant_PhysicalTroughMerchantPlant

		['mp_ancserv2_revenue', 'reserves_interest', 'mp_ancserv3_revenue', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'term_int_rate', 'mp_ancserv4_revenue']

	 - Merchantplant_WindPowerMerchantPlant

		['insurance_rate', 'system_capacity', 'mp_ancserv2_revenue', 'reserves_interest', 'mp_ancserv3_revenue', 'equip1_reserve_cost', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'term_int_rate', 'mp_ancserv4_revenue']



MhkTidal
************************************************

:doc:`modules/MhkTidal` New Default files:

	 - MEtidalNone

:doc:`modules/MhkTidal` Modified Variables:

	New variables:

		 - system_capacity

:doc:`modules/MhkTidal` Modified Default Values:

	 - MhkTidal_MEtidalLCOECalculator

		['balance_of_system_cost_total', 'number_devices', 'total_operating_cost', 'device_costs_total', 'financial_cost_total']



MhkWave
************************************************

:doc:`modules/MhkWave` Modified Default Values:

	 - MhkWave_MEwaveLCOECalculator

		['balance_of_system_cost_total', 'significant_wave_height', 'energy_period', 'financial_cost_total']

	 - MhkWave_MEwaveNone

		['year']



Pvsamv1
************************************************

:doc:`modules/Pvsamv1` Modified Variables:

	New variables:

		 - batt_dispatch_auto_btm_can_discharge_to_grid
		 - batt_dispatch_auto_can_clipcharge
		 - batt_dispatch_charge_only_system_exceeds_load
		 - batt_dispatch_discharge_only_load_exceeds_system
		 - batt_dispatch_load_forecast_choice
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
		 - grid_outage
		 - om_batt_replacement_cost
		 - om_replacement_cost_escal
		 - rate_escalation
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

		 - ur_ec_billing_demand_lookback_percentages
		 - ur_ec_billing_demand_lookback_period
		 - ur_ec_billing_demand_minimum
		 - ur_ec_enable_billing_demand

:doc:`modules/Pvsamv1` Modified Default Values:

	 - Pvsamv1_FlatPlatePVAllEquityPartnershipFlip

		['subarray4_tilt', 'subarray2_track_mode', 'subarray3_track_mode', 'subarray2_tilt', 'inv_tdc_cec_cg', 'subarray1_tilt', 'subarray3_tilt', 'subarray1_track_mode', 'subarray4_track_mode', 'inverter_count', 'inv_tdc_ds', 'use_wf_albedo', 'ppa_price_input', 'inv_tdc_plc', 'inv_tdc_cec_db']

	 - Pvsamv1_FlatPlatePVCommercial

		['inv_tdc_cec_cg', 'inv_tdc_ds', 'use_wf_albedo', 'inv_tdc_plc', 'inv_tdc_cec_db']

	 - Pvsamv1_FlatPlatePVHostDeveloper

		['inv_tdc_cec_cg', 'inv_tdc_ds', 'use_wf_albedo', 'inv_tdc_plc', 'inv_tdc_cec_db']

	 - Pvsamv1_FlatPlatePVLCOECalculator

		['inverter_count', 'subarray4_tilt', 'inv_tdc_cec_db', 'system_capacity', 'inv_tdc_ds', 'subarray1_track_mode', 'subarray2_track_mode', 'subarray3_track_mode', 'subarray2_tilt', 'inv_tdc_cec_cg', 'subarray1_tilt', 'subarray3_tilt', 'subarray1_nstrings', 'use_wf_albedo', 'subarray4_track_mode', 'inv_tdc_plc']

	 - Pvsamv1_FlatPlatePVLeveragedPartnershipFlip

		['subarray4_tilt', 'subarray2_track_mode', 'subarray3_track_mode', 'subarray2_tilt', 'inv_tdc_cec_cg', 'subarray1_tilt', 'subarray3_tilt', 'subarray1_track_mode', 'subarray4_track_mode', 'inverter_count', 'inv_tdc_ds', 'use_wf_albedo', 'ppa_price_input', 'inv_tdc_plc', 'inv_tdc_cec_db']

	 - Pvsamv1_FlatPlatePVMerchantPlant

		['subarray4_tilt', 'mp_ancserv2_revenue', 'subarray2_track_mode', 'subarray3_track_mode', 'subarray2_tilt', 'inv_tdc_cec_cg', 'subarray1_tilt', 'subarray3_tilt', 'mp_ancserv4_revenue', 'subarray1_track_mode', 'mp_ancserv3_revenue', 'subarray4_track_mode', 'inverter_count', 'inv_tdc_ds', 'use_wf_albedo', 'inv_tdc_plc', 'inv_tdc_cec_db', 'mp_energy_market_revenue', 'mp_ancserv1_revenue']

	 - Pvsamv1_FlatPlatePVNone

		['inv_tdc_cec_db', 'inv_snl_pso', 'system_capacity', 'inv_snl_eff_cec', 'inv_tdc_ds', 'inv_snl_pdco', 'inv_snl_c3', 'inv_snl_pnt', 'inv_snl_paco', 'inv_snl_c0', 'inv_snl_c2', 'inv_tdc_cec_cg', 'subarray1_modules_per_string', 'inv_snl_vdcmax', 'subarray1_nstrings', 'mppt_hi_inverter', 'inv_snl_vdco', 'use_wf_albedo', 'mppt_low_inverter', 'inv_snl_c1', 'inv_tdc_plc']

	 - Pvsamv1_FlatPlatePVResidential

		['inv_snl_c0', 'inv_tdc_cec_cg', 'subarray2_mismatch_loss', 'inv_snl_c1', 'dcoptimizer_loss', 'inv_snl_pso', 'inv_snl_pdco', 'subarray1_mismatch_loss', 'inv_snl_c3', 'subarray1_nstrings', 'mppt_hi_inverter', 'subarray3_mismatch_loss', 'subarray4_mismatch_loss', 'inv_tdc_ds', 'inv_snl_c2', 'subarray1_modules_per_string', 'mppt_low_inverter', 'inv_snl_vdco', 'use_wf_albedo', 'inv_tdc_plc', 'inv_tdc_cec_db', 'system_capacity', 'inv_snl_eff_cec', 'inv_snl_pnt', 'inv_snl_paco', 'inv_snl_vdcmax']

	 - Pvsamv1_FlatPlatePVSaleLeaseback

		['subarray4_tilt', 'subarray2_track_mode', 'subarray3_track_mode', 'subarray2_tilt', 'inv_tdc_cec_cg', 'subarray1_tilt', 'subarray3_tilt', 'subarray1_track_mode', 'subarray4_track_mode', 'inverter_count', 'inv_tdc_ds', 'use_wf_albedo', 'ppa_price_input', 'inv_tdc_plc', 'inv_tdc_cec_db']

	 - Pvsamv1_FlatPlatePVSingleOwner

		['subarray4_tilt', 'subarray2_track_mode', 'subarray3_track_mode', 'subarray2_tilt', 'inv_tdc_cec_cg', 'subarray1_tilt', 'subarray3_tilt', 'subarray1_track_mode', 'subarray4_track_mode', 'inverter_count', 'inv_tdc_ds', 'use_wf_albedo', 'ppa_price_input', 'inv_tdc_plc', 'inv_tdc_cec_db']

	 - Pvsamv1_FlatPlatePVThirdParty

		['inv_snl_c0', 'inv_tdc_cec_cg', 'subarray2_mismatch_loss', 'inv_snl_c1', 'dcoptimizer_loss', 'inv_snl_pso', 'inv_snl_pdco', 'subarray1_mismatch_loss', 'inv_snl_c3', 'subarray1_nstrings', 'mppt_hi_inverter', 'subarray3_mismatch_loss', 'inverter_count', 'subarray4_mismatch_loss', 'inv_tdc_ds', 'ur_yearzero_usage_peaks', 'inv_snl_c2', 'subarray1_modules_per_string', 'mppt_low_inverter', 'inv_snl_vdco', 'use_wf_albedo', 'inv_tdc_plc', 'inv_tdc_cec_db', 'system_capacity', 'inv_snl_eff_cec', 'inv_snl_pnt', 'inv_snl_paco', 'inv_snl_vdcmax']

	 - Pvsamv1_PVBatteryAllEquityPartnershipFlip

		['inv_tdc_cec_cg', 'subarray1_tilt', 'subarray1_track_mode', 'batt_calendar_c', 'inverter_count', 'inv_tdc_ds', 'dispatch_manual_sched_weekend', 'use_wf_albedo', 'ppa_price_input', 'inv_tdc_plc', 'inv_tdc_cec_db', 'dispatch_manual_sched', 'batt_h_to_ambient']

	 - Pvsamv1_PVBatteryCommercial

		['inv_tdc_cec_cg', 'batt_calendar_c', 'inv_tdc_ds', 'ur_yearzero_usage_peaks', 'use_wf_albedo', 'inv_tdc_plc', 'inv_tdc_cec_db', 'batt_minimum_SOC']

	 - Pvsamv1_PVBatteryHostDeveloper

		['inv_tdc_cec_cg', 'batt_calendar_c', 'inv_tdc_ds', 'use_wf_albedo', 'inv_tdc_plc', 'inv_tdc_cec_db', 'batt_minimum_SOC']

	 - Pvsamv1_PVBatteryLeveragedPartnershipFlip

		['inv_tdc_cec_cg', 'subarray1_tilt', 'subarray1_track_mode', 'batt_calendar_c', 'inverter_count', 'inv_tdc_ds', 'dispatch_manual_sched_weekend', 'use_wf_albedo', 'ppa_price_input', 'inv_tdc_plc', 'inv_tdc_cec_db', 'dispatch_manual_sched', 'batt_h_to_ambient']

	 - Pvsamv1_PVBatteryMerchantPlant

		['mp_ancserv2_revenue', 'inv_tdc_cec_cg', 'subarray1_tilt', 'mp_ancserv4_revenue', 'subarray1_track_mode', 'mp_ancserv3_revenue', 'batt_calendar_c', 'inverter_count', 'inv_tdc_ds', 'dispatch_manual_sched_weekend', 'batt_room_temperature_celsius', 'use_wf_albedo', 'inv_tdc_plc', 'inv_tdc_cec_db', 'dispatch_manual_sched', 'mp_energy_market_revenue', 'mp_ancserv1_revenue', 'batt_h_to_ambient']

	 - Pvsamv1_PVBatteryResidential

		['inv_tdc_cec_cg', 'subarray2_mismatch_loss', 'dcoptimizer_loss', 'subarray1_mismatch_loss', 'batt_calendar_c', 'subarray3_mismatch_loss', 'subarray4_mismatch_loss', 'inv_tdc_ds', 'ur_yearzero_usage_peaks', 'use_wf_albedo', 'inv_tdc_plc', 'inv_tdc_cec_db', 'batt_minimum_SOC']

	 - Pvsamv1_PVBatterySaleLeaseback

		['inv_tdc_cec_cg', 'subarray1_tilt', 'subarray1_track_mode', 'batt_calendar_c', 'inverter_count', 'inv_tdc_ds', 'dispatch_manual_sched_weekend', 'use_wf_albedo', 'ppa_price_input', 'inv_tdc_plc', 'inv_tdc_cec_db', 'dispatch_manual_sched', 'batt_h_to_ambient']

	 - Pvsamv1_PVBatterySingleOwner

		['batt_mass', 'batt_power_charge_max_kwdc', 'inv_tdc_cec_cg', 'subarray1_tilt', 'batt_computed_strings', 'batt_computed_bank_capacity', 'subarray1_track_mode', 'batt_current_discharge_max', 'batt_current_charge_max', 'ur_ec_tou_mat', 'batt_calendar_c', 'batt_surface_area', 'inverter_count', 'batt_power_charge_max_kwac', 'inv_tdc_ds', 'dispatch_manual_sched_weekend', 'ur_yearzero_usage_peaks', 'ur_dc_tou_mat', 'batt_Qfull_flow', 'use_wf_albedo', 'ppa_price_input', 'inv_tdc_plc', 'inv_tdc_cec_db', 'dispatch_manual_sched', 'batt_h_to_ambient', 'batt_power_discharge_max_kwdc', 'batt_power_discharge_max_kwac']

	 - Pvsamv1_PVBatteryThirdParty

		['inv_tdc_cec_cg', 'subarray2_mismatch_loss', 'dcoptimizer_loss', 'subarray1_mismatch_loss', 'batt_calendar_c', 'subarray3_mismatch_loss', 'subarray4_mismatch_loss', 'inv_tdc_ds', 'ur_yearzero_usage_peaks', 'use_wf_albedo', 'inv_tdc_plc', 'inv_tdc_cec_db', 'batt_minimum_SOC']



Pvwattsv7
************************************************

:doc:`modules/Pvwattsv7` Removed Default files

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

:doc:`modules/Pvwattsv8` New Default files:

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

:doc:`modules/Saleleaseback` New Default files:

	 - StandaloneBatterySaleLeaseback

:doc:`modules/Saleleaseback` Modified Variables:

	New variables:

		 - en_electricity_rates
		 - en_standalone_batt
		 - land_area
		 - om_land_lease
		 - om_land_lease_escal

:doc:`modules/Saleleaseback` Modified Default Values:

	 - Saleleaseback_BiopowerSaleLeaseback

		['ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'construction_financing_cost', 'ppa_price_input']

	 - Saleleaseback_DSLFSaleLeaseback

		['ppa_soln_mode', 'reserves_interest']

	 - Saleleaseback_EmpiricalTroughSaleLeaseback

		['ppa_soln_mode', 'reserves_interest']

	 - Saleleaseback_FlatPlatePVSaleLeaseback

		['insurance_rate', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'equip1_reserve_freq', 'om_capacity', 'ppa_price_input']

	 - Saleleaseback_GenericBatterySaleLeaseback

		['insurance_rate', 'om_batt_capacity_cost', 'reserves_interest', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'equip1_reserve_freq', 'ppa_escalation', 'om_capacity', 'battery_per_kWh']

	 - Saleleaseback_GenericCSPSystemSaleLeaseback

		['ppa_soln_mode', 'reserves_interest']

	 - Saleleaseback_GenericSystemSaleLeaseback

		['ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'ppa_price_input']

	 - Saleleaseback_GeothermalPowerSaleLeaseback

		['ppa_soln_mode', 'system_capacity', 'reserves_interest', 'equip1_reserve_cost', 'construction_financing_cost', 'system_recapitalization_cost', 'total_installed_cost']

	 - Saleleaseback_HighXConcentratingPVSaleLeaseback

		['insurance_rate', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'equip1_reserve_freq']

	 - Saleleaseback_MSLFSaleLeaseback

		['ppa_soln_mode', 'reserves_interest']

	 - Saleleaseback_MSPTSaleLeaseback

		['ppa_soln_mode', 'reserves_interest']

	 - Saleleaseback_PVBatterySaleLeaseback

		['insurance_rate', 'om_batt_capacity_cost', 'reserves_interest', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'equip1_reserve_freq', 'ppa_escalation', 'om_capacity', 'ppa_price_input', 'battery_per_kWh']

	 - Saleleaseback_PVWattsSaleLeaseback

		['insurance_rate', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'equip1_reserve_freq', 'om_capacity', 'ppa_price_input']

	 - Saleleaseback_PhysicalTroughSaleLeaseback

		['ppa_soln_mode', 'reserves_interest']

	 - Saleleaseback_WindPowerSaleLeaseback

		['insurance_rate', 'ppa_soln_mode', 'system_capacity', 'reserves_interest', 'equip1_reserve_cost']



Singleowner
************************************************

:doc:`modules/Singleowner` New Default files:

	 - ETESSingleOwner
	 - StandaloneBatterySingleOwner

:doc:`modules/Singleowner` Modified Variables:

	New variables:

		 - dscr_limit_debt_fraction
		 - dscr_maximum_debt_fraction
		 - en_electricity_rates
		 - en_standalone_batt
		 - land_area
		 - om_land_lease
		 - om_land_lease_escal

	Removed variables:

		 - roe_input

:doc:`modules/Singleowner` Modified Default Values:

	 - Singleowner_BiopowerSingleOwner

		['ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'term_int_rate', 'ppa_price_input']

	 - Singleowner_DSLFSingleOwner

		['ppa_soln_mode', 'reserves_interest', 'term_int_rate']

	 - Singleowner_EmpiricalTroughSingleOwner

		['ppa_soln_mode', 'reserves_interest', 'term_int_rate']

	 - Singleowner_FlatPlatePVSingleOwner

		['insurance_rate', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'equip1_reserve_freq', 'om_capacity', 'term_int_rate', 'ppa_price_input']

	 - Singleowner_FuelCellSingleOwner

		['om_fuelcell_capacity_cost', 'insurance_rate', 'term_tenor', 'state_tax_rate', 'ppa_soln_mode', 'om_batt_capacity_cost', 'reserves_interest', 'equip1_reserve_cost', 'dscr', 'equip1_reserve_freq', 'cost_debt_fee', 'batt_meter_position', 'real_discount_rate', 'om_capacity', 'term_int_rate', 'ppa_price_input', 'battery_per_kWh', 'cost_debt_closing', 'federal_tax_rate']

	 - Singleowner_GenericBatterySingleOwner

		['insurance_rate', 'om_batt_capacity_cost', 'reserves_interest', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'equip1_reserve_freq', 'ppa_escalation', 'om_capacity', 'term_int_rate', 'battery_per_kWh']

	 - Singleowner_GenericCSPSystemSingleOwner

		['ppa_soln_mode', 'reserves_interest', 'term_int_rate']

	 - Singleowner_GenericSystemSingleOwner

		['ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'term_int_rate', 'ppa_price_input']

	 - Singleowner_GeothermalPowerSingleOwner

		['cp_system_nameplate', 'ppa_soln_mode', 'system_capacity', 'reserves_interest', 'equip1_reserve_cost', 'construction_financing_cost', 'system_recapitalization_cost', 'total_installed_cost', 'term_int_rate']

	 - Singleowner_HighXConcentratingPVSingleOwner

		['insurance_rate', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'equip1_reserve_freq', 'term_int_rate']

	 - Singleowner_MSLFSingleOwner

		['ppa_soln_mode', 'reserves_interest', 'term_int_rate']

	 - Singleowner_MSPTSingleOwner

		['ppa_soln_mode', 'reserves_interest', 'term_int_rate']

	 - Singleowner_PVBatterySingleOwner

		['insurance_rate', 'om_batt_capacity_cost', 'reserves_interest', 'om_batt_replacement_cost', 'equip1_reserve_cost', 'om_batt_nameplate', 'equip1_reserve_freq', 'construction_financing_cost', 'ppa_escalation', 'om_capacity', 'total_installed_cost', 'term_int_rate', 'ppa_price_input', 'battery_per_kWh', 'batt_computed_bank_capacity', 'battery_total_cost_lcos']

	 - Singleowner_PVWattsSingleOwner

		['insurance_rate', 'ppa_soln_mode', 'reserves_interest', 'equip1_reserve_cost', 'equip1_reserve_freq', 'om_capacity', 'term_int_rate', 'ppa_price_input']

	 - Singleowner_PhysicalTroughSingleOwner

		['ppa_soln_mode', 'reserves_interest', 'term_int_rate']

	 - Singleowner_WindPowerSingleOwner

		['insurance_rate', 'ppa_soln_mode', 'system_capacity', 'reserves_interest', 'equip1_reserve_cost', 'term_int_rate']



TcsMSLF
************************************************

:doc:`modules/TcsMSLF` Modified Default Values:

	 - TcsMSLF_MSLFLeveragedPartnershipFlip

		['weekend_schedule']

	 - TcsMSLF_MSLFMerchantPlant

		['weekday_schedule', 'weekend_schedule']



TcsgenericSolar
************************************************

:doc:`modules/TcsgenericSolar` Modified Default Values:

	 - TcsgenericSolar_GenericCSPSystemLeveragedPartnershipFlip

		['weekend_schedule']

	 - TcsgenericSolar_GenericCSPSystemMerchantPlant

		['weekday_schedule', 'w_des', 'qsf_des', 'system_capacity', 'weekend_schedule']



TcslinearFresnel
************************************************

:doc:`modules/TcslinearFresnel` Modified Default Values:

	 - TcslinearFresnel_DSLFMerchantPlant

		['weekday_schedule', 'weekend_schedule']



TcsmoltenSalt
************************************************

:doc:`modules/TcsmoltenSalt` Modified Variables:

	New variables:

		 - cav_rec_height
		 - cav_rec_passive_abs
		 - cav_rec_passive_eps
		 - cav_rec_span
		 - cav_rec_width
		 - en_electricity_rates
		 - n_cav_rec_panels
		 - piping_loss_coefficient
		 - ppa_soln_mode
		 - receiver_type

	Removed variables:

		 - piping_loss

:doc:`modules/TcsmoltenSalt` Modified Default Values:

	 - TcsmoltenSalt_MSPTAllEquityPartnershipFlip

		['weekday_schedule', 'weekend_schedule', 'sf_constant', 'const_per_interest_rate1']

	 - TcsmoltenSalt_MSPTLeveragedPartnershipFlip

		['weekday_schedule', 'weekend_schedule', 'sf_constant', 'const_per_interest_rate1']

	 - TcsmoltenSalt_MSPTMerchantPlant

		['weekday_schedule', 'mp_energy_market_revenue', 'weekend_schedule', 'sf_constant', 'const_per_interest_rate1']

	 - TcsmoltenSalt_MSPTSaleLeaseback

		['weekday_schedule', 'weekend_schedule', 'sf_constant', 'const_per_interest_rate1']

	 - TcsmoltenSalt_MSPTSingleOwner

		['weekday_schedule', 'weekend_schedule', 'sf_constant', 'const_per_interest_rate1']



TcstroughEmpirical
************************************************

:doc:`modules/TcstroughEmpirical` Modified Default Values:

	 - TcstroughEmpirical_EmpiricalTroughAllEquityPartnershipFlip

		['CtPar']

	 - TcstroughEmpirical_EmpiricalTroughCommercial

		['CtPar']

	 - TcstroughEmpirical_EmpiricalTroughLeveragedPartnershipFlip

		['weekend_schedule', 'CtPar']

	 - TcstroughEmpirical_EmpiricalTroughMerchantPlant

		['weekday_schedule', 'weekend_schedule', 'CtPar']

	 - TcstroughEmpirical_EmpiricalTroughSaleLeaseback

		['CtPar']

	 - TcstroughEmpirical_EmpiricalTroughSingleOwner

		['CtPar']



Thirdpartyownership
************************************************

:doc:`modules/Thirdpartyownership` New Default files:

	 - StandaloneBatteryThirdParty

:doc:`modules/Thirdpartyownership` Modified Default Values:

	 - Thirdpartyownership_PVWattsBatteryThirdParty

		['degradation']



TroughPhysical
************************************************

:doc:`modules/TroughPhysical` Removed Default files

	 - PhysicalTroughCommercial

:doc:`modules/TroughPhysical` Modified Variables:

	New variables:

		 - en_electricity_rates
		 - ppa_soln_mode

	Removed variables:

		 - is_hx

:doc:`modules/TroughPhysical` Modified Default Values:

	 - TroughPhysical_PhysicalTroughMerchantPlant

		['mp_energy_market_revenue']



Utilityrate5
************************************************

:doc:`modules/Utilityrate5` New Default files:

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

:doc:`modules/Utilityrate5` Removed Default files

	 - PhysicalTroughCommercial

:doc:`modules/Utilityrate5` Modified Variables:

	New variables:

		 - ur_billing_demand_lookback_percentages
		 - ur_billing_demand_lookback_period
		 - ur_billing_demand_minimum
		 - ur_dc_billing_demand_periods
		 - ur_enable_billing_demand

	Removed variables:

		 - ur_ec_billing_demand_lookback_percentages
		 - ur_ec_billing_demand_lookback_period
		 - ur_ec_billing_demand_minimum
		 - ur_ec_enable_billing_demand

:doc:`modules/Utilityrate5` Modified Default Values:

	 - Utilityrate5_FlatPlatePVThirdParty

		['ur_yearzero_usage_peaks']

	 - Utilityrate5_FuelCellCommercial

		['ur_yearzero_usage_peaks']

	 - Utilityrate5_FuelCellSingleOwner

		['ur_ec_tou_mat', 'ur_monthly_fixed_charge', 'ur_ec_sched_weekday', 'ur_dc_enable', 'ur_dc_sched_weekend', 'ur_ec_sched_weekend', 'ur_dc_tou_mat', 'ur_dc_sched_weekday']

	 - Utilityrate5_GenericBatteryResidential

		['ur_yearzero_usage_peaks']

	 - Utilityrate5_GenericBatterySingleOwner

		['ur_ec_tou_mat', 'ur_dc_tou_mat']

	 - Utilityrate5_GenericBatteryThirdParty

		['ur_yearzero_usage_peaks']

	 - Utilityrate5_GenericSystemThirdParty

		['ur_yearzero_usage_peaks']

	 - Utilityrate5_PVBatteryCommercial

		['ur_yearzero_usage_peaks']

	 - Utilityrate5_PVBatteryResidential

		['ur_yearzero_usage_peaks']

	 - Utilityrate5_PVBatterySingleOwner

		['ur_ec_tou_mat', 'ur_dc_tou_mat', 'ur_yearzero_usage_peaks']

	 - Utilityrate5_PVBatteryThirdParty

		['ur_yearzero_usage_peaks']

	 - Utilityrate5_PVWattsBatteryCommercial

		['degradation', 'ur_yearzero_usage_peaks']

	 - Utilityrate5_PVWattsBatteryHostDeveloper

		['degradation']

	 - Utilityrate5_PVWattsBatteryResidential

		['degradation', 'ur_yearzero_usage_peaks']

	 - Utilityrate5_PVWattsBatteryThirdParty

		['degradation', 'ur_yearzero_usage_peaks']

	 - Utilityrate5_PVWattsThirdParty

		['ur_yearzero_usage_peaks']



Windpower
************************************************

:doc:`modules/Windpower` Modified Default Values:

	 - Windpower_WindPowerAllEquityPartnershipFlip

		['system_capacity', 'wind_turbine_rotor_diameter']

	 - Windpower_WindPowerLCOECalculator

		['wind_turbine_powercurve_powerout', 'wind_farm_xCoordinates', 'wind_farm_yCoordinates', 'system_capacity', 'wind_turbine_rotor_diameter']

	 - Windpower_WindPowerLeveragedPartnershipFlip

		['system_capacity', 'wind_turbine_rotor_diameter']

	 - Windpower_WindPowerMerchantPlant

		['system_capacity', 'wind_turbine_rotor_diameter']

	 - Windpower_WindPowerSaleLeaseback

		['system_capacity', 'wind_turbine_rotor_diameter']

	 - Windpower_WindPowerSingleOwner

		['system_capacity', 'wind_turbine_rotor_diameter']



