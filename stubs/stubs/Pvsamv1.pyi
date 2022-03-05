class Pvsamv1(object):
	def assign(self, dict):
		pass

	def value(self, name, value=None):
		pass

	def unassign(self, name):
		pass

	def execute(self, int_verbosity):
		pass

	def export(self):
		pass

	def __getattribute__(self, *args, **kwargs):
		pass

	def __init__(self, *args, **kwargs):
		pass

	def Reopt_size_battery_post(self, args):
		pass
	class SolarResource(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		albedo = tuple
		irrad_mode = float
		sky_model = float
		solar_resource_data = dict
		solar_resource_file = str
		use_wf_albedo = float


	class Losses(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		acwiring_loss = float
		dcoptimizer_loss = float
		en_snow_model = float
		subarray1_dcwiring_loss = float
		subarray1_diodeconn_loss = float
		subarray1_mismatch_loss = float
		subarray1_nameplate_loss = float
		subarray1_rear_irradiance_loss = float
		subarray1_soiling = tuple
		subarray1_tracking_loss = float
		subarray2_dcwiring_loss = float
		subarray2_diodeconn_loss = float
		subarray2_mismatch_loss = float
		subarray2_nameplate_loss = float
		subarray2_rear_irradiance_loss = float
		subarray2_soiling = tuple
		subarray2_tracking_loss = float
		subarray3_dcwiring_loss = float
		subarray3_diodeconn_loss = float
		subarray3_mismatch_loss = float
		subarray3_nameplate_loss = float
		subarray3_rear_irradiance_loss = float
		subarray3_soiling = tuple
		subarray3_tracking_loss = float
		subarray4_dcwiring_loss = float
		subarray4_diodeconn_loss = float
		subarray4_mismatch_loss = float
		subarray4_nameplate_loss = float
		subarray4_rear_irradiance_loss = float
		subarray4_soiling = tuple
		subarray4_tracking_loss = float
		transformer_load_loss = float
		transformer_no_load_loss = float
		transmission_loss = float


	class Lifetime(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		ac_lifetime_losses = tuple
		analysis_period = float
		dc_degradation = tuple
		dc_lifetime_losses = tuple
		en_ac_lifetime_losses = float
		en_dc_lifetime_losses = float
		inflation_rate = float
		save_full_lifetime_variables = float
		system_use_lifetime_output = float


	class SystemDesign(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		enable_mismatch_vmax_calc = float
		inverter_count = float
		subarray1_azimuth = float
		subarray1_backtrack = float
		subarray1_gcr = float
		subarray1_modules_per_string = float
		subarray1_monthly_tilt = tuple
		subarray1_mppt_input = float
		subarray1_nstrings = float
		subarray1_rotlim = float
		subarray1_slope_azm = float
		subarray1_slope_tilt = float
		subarray1_tilt = float
		subarray1_tilt_eq_lat = float
		subarray1_track_mode = float
		subarray2_azimuth = float
		subarray2_backtrack = float
		subarray2_enable = float
		subarray2_gcr = float
		subarray2_modules_per_string = float
		subarray2_monthly_tilt = tuple
		subarray2_mppt_input = float
		subarray2_nstrings = float
		subarray2_rotlim = float
		subarray2_slope_azm = float
		subarray2_slope_tilt = float
		subarray2_tilt = float
		subarray2_tilt_eq_lat = float
		subarray2_track_mode = float
		subarray3_azimuth = float
		subarray3_backtrack = float
		subarray3_enable = float
		subarray3_gcr = float
		subarray3_modules_per_string = float
		subarray3_monthly_tilt = tuple
		subarray3_mppt_input = float
		subarray3_nstrings = float
		subarray3_rotlim = float
		subarray3_slope_azm = float
		subarray3_slope_tilt = float
		subarray3_tilt = float
		subarray3_tilt_eq_lat = float
		subarray3_track_mode = float
		subarray4_azimuth = float
		subarray4_backtrack = float
		subarray4_enable = float
		subarray4_gcr = float
		subarray4_modules_per_string = float
		subarray4_monthly_tilt = tuple
		subarray4_mppt_input = float
		subarray4_nstrings = float
		subarray4_rotlim = float
		subarray4_slope_azm = float
		subarray4_slope_tilt = float
		subarray4_tilt = float
		subarray4_tilt_eq_lat = float
		subarray4_track_mode = float
		system_capacity = float


	class Shading(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		subarray1_shade_mode = float
		subarray1_shading_azal = tuple
		subarray1_shading_diff = float
		subarray1_shading_mxh = tuple
		subarray1_shading_string_option = float
		subarray1_shading_timestep = tuple
		subarray2_shade_mode = float
		subarray2_shading_azal = tuple
		subarray2_shading_diff = float
		subarray2_shading_mxh = tuple
		subarray2_shading_string_option = float
		subarray2_shading_timestep = tuple
		subarray3_shade_mode = float
		subarray3_shading_azal = tuple
		subarray3_shading_diff = float
		subarray3_shading_mxh = tuple
		subarray3_shading_string_option = float
		subarray3_shading_timestep = tuple
		subarray4_shade_mode = float
		subarray4_shading_azal = tuple
		subarray4_shading_diff = float
		subarray4_shading_mxh = tuple
		subarray4_shading_string_option = float
		subarray4_shading_timestep = tuple


	class Layout(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		module_aspect_ratio = float
		subarray1_mod_orient = float
		subarray1_nmodx = float
		subarray1_nmody = float
		subarray2_mod_orient = float
		subarray2_nmodx = float
		subarray2_nmody = float
		subarray3_mod_orient = float
		subarray3_nmodx = float
		subarray3_nmody = float
		subarray4_mod_orient = float
		subarray4_nmodx = float
		subarray4_nmody = float


	class Module(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		module_model = float


	class SimpleEfficiencyModuleModel(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		spe_a = float
		spe_area = float
		spe_b = float
		spe_bifacial_ground_clearance_height = float
		spe_bifacial_transmission_factor = float
		spe_bifaciality = float
		spe_dT = float
		spe_eff0 = float
		spe_eff1 = float
		spe_eff2 = float
		spe_eff3 = float
		spe_eff4 = float
		spe_fd = float
		spe_is_bifacial = float
		spe_module_structure = float
		spe_rad0 = float
		spe_rad1 = float
		spe_rad2 = float
		spe_rad3 = float
		spe_rad4 = float
		spe_reference = float
		spe_temp_coeff = float
		spe_vmp = float
		spe_voc = float


	class CECPerformanceModelWithModuleDatabase(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		cec_a_ref = float
		cec_adjust = float
		cec_alpha_sc = float
		cec_area = float
		cec_array_cols = float
		cec_array_rows = float
		cec_backside_temp = float
		cec_beta_oc = float
		cec_bifacial_ground_clearance_height = float
		cec_bifacial_transmission_factor = float
		cec_bifaciality = float
		cec_gamma_r = float
		cec_gap_spacing = float
		cec_heat_transfer = float
		cec_height = float
		cec_i_l_ref = float
		cec_i_mp_ref = float
		cec_i_o_ref = float
		cec_i_sc_ref = float
		cec_is_bifacial = float
		cec_module_length = float
		cec_module_width = float
		cec_mounting_config = float
		cec_mounting_orientation = float
		cec_n_s = float
		cec_r_s = float
		cec_r_sh_ref = float
		cec_standoff = float
		cec_t_noct = float
		cec_temp_corr_mode = float
		cec_transient_thermal_model_unit_mass = float
		cec_v_mp_ref = float
		cec_v_oc_ref = float


	class CECPerformanceModelWithUserEnteredSpecifications(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		sixpar_aisc = float
		sixpar_area = float
		sixpar_bifacial_ground_clearance_height = float
		sixpar_bifacial_transmission_factor = float
		sixpar_bifaciality = float
		sixpar_bvoc = float
		sixpar_celltech = float
		sixpar_gpmp = float
		sixpar_imp = float
		sixpar_is_bifacial = float
		sixpar_isc = float
		sixpar_mounting = float
		sixpar_nser = float
		sixpar_standoff = float
		sixpar_tnoct = float
		sixpar_transient_thermal_model_unit_mass = float
		sixpar_vmp = float
		sixpar_voc = float


	class SandiaPVArrayPerformanceModelWithModuleDatabase(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		snl_a = float
		snl_a0 = float
		snl_a1 = float
		snl_a2 = float
		snl_a3 = float
		snl_a4 = float
		snl_aimp = float
		snl_aisc = float
		snl_area = float
		snl_b = float
		snl_b0 = float
		snl_b1 = float
		snl_b2 = float
		snl_b3 = float
		snl_b4 = float
		snl_b5 = float
		snl_bvmpo = float
		snl_bvoco = float
		snl_c0 = float
		snl_c1 = float
		snl_c2 = float
		snl_c3 = float
		snl_c4 = float
		snl_c5 = float
		snl_c6 = float
		snl_c7 = float
		snl_dtc = float
		snl_fd = float
		snl_impo = float
		snl_isco = float
		snl_ixo = float
		snl_ixxo = float
		snl_mbvmp = float
		snl_mbvoc = float
		snl_module_structure = float
		snl_n = float
		snl_ref_a = float
		snl_ref_b = float
		snl_ref_dT = float
		snl_series_cells = float
		snl_transient_thermal_model_unit_mass = float
		snl_vmpo = float
		snl_voco = float


	class IEC61853SingleDiodeModel(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		sd11par_AMa0 = float
		sd11par_AMa1 = float
		sd11par_AMa2 = float
		sd11par_AMa3 = float
		sd11par_AMa4 = float
		sd11par_Egref = float
		sd11par_Il = float
		sd11par_Imp0 = float
		sd11par_Io = float
		sd11par_Isc0 = float
		sd11par_Vmp0 = float
		sd11par_Voc0 = float
		sd11par_alphaIsc = float
		sd11par_area = float
		sd11par_c1 = float
		sd11par_c2 = float
		sd11par_c3 = float
		sd11par_d1 = float
		sd11par_d2 = float
		sd11par_d3 = float
		sd11par_glass = float
		sd11par_mounting = float
		sd11par_n = float
		sd11par_nser = float
		sd11par_standoff = float
		sd11par_tnoct = float


	class MermoudLejeuneSingleDiodeModel(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		mlm_AM_c_lp0 = float
		mlm_AM_c_lp1 = float
		mlm_AM_c_lp2 = float
		mlm_AM_c_lp3 = float
		mlm_AM_c_lp4 = float
		mlm_AM_c_lp5 = float
		mlm_AM_c_sa0 = float
		mlm_AM_c_sa1 = float
		mlm_AM_c_sa2 = float
		mlm_AM_c_sa3 = float
		mlm_AM_c_sa4 = float
		mlm_AM_mode = float
		mlm_D2MuTau = float
		mlm_E_g = float
		mlm_IAM_c_as = float
		mlm_IAM_c_cs_iamValue = tuple
		mlm_IAM_c_cs_incAngle = tuple
		mlm_IAM_c_sa0 = float
		mlm_IAM_c_sa1 = float
		mlm_IAM_c_sa2 = float
		mlm_IAM_c_sa3 = float
		mlm_IAM_c_sa4 = float
		mlm_IAM_c_sa5 = float
		mlm_IAM_mode = float
		mlm_I_mp_ref = float
		mlm_I_sc_ref = float
		mlm_Length = float
		mlm_N_diodes = float
		mlm_N_parallel = float
		mlm_N_series = float
		mlm_R_s = float
		mlm_R_sh0 = float
		mlm_R_shexp = float
		mlm_R_shref = float
		mlm_S_ref = float
		mlm_T_c_fa_U0 = float
		mlm_T_c_fa_U1 = float
		mlm_T_c_fa_alpha = float
		mlm_T_c_no_mounting = float
		mlm_T_c_no_standoff = float
		mlm_T_c_no_tnoct = float
		mlm_T_mode = float
		mlm_T_ref = float
		mlm_V_mp_ref = float
		mlm_V_oc_ref = float
		mlm_Width = float
		mlm_alpha_isc = float
		mlm_beta_voc_spec = float
		mlm_bifacial_ground_clearance_height = float
		mlm_bifacial_transmission_factor = float
		mlm_bifaciality = float
		mlm_groundRelfectionFraction = float
		mlm_is_bifacial = float
		mlm_mu_n = float
		mlm_n_0 = float


	class Inverter(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		inv_cec_cg_eff_cec = float
		inv_cec_cg_paco = float
		inv_ds_eff = float
		inv_ds_paco = float
		inv_num_mppt = float
		inv_pd_eff = float
		inv_pd_paco = float
		inv_snl_eff_cec = float
		inv_snl_paco = float
		inverter_count = float
		inverter_model = float
		mppt_hi_inverter = float
		mppt_low_inverter = float


	class InverterCECDatabase(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		inv_snl_c0 = float
		inv_snl_c1 = float
		inv_snl_c2 = float
		inv_snl_c3 = float
		inv_snl_paco = float
		inv_snl_pdco = float
		inv_snl_pnt = float
		inv_snl_pso = float
		inv_snl_vdcmax = float
		inv_snl_vdco = float
		inv_tdc_cec_db = tuple


	class InverterCECCoefficientGenerator(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		inv_cec_cg_c0 = float
		inv_cec_cg_c1 = float
		inv_cec_cg_c2 = float
		inv_cec_cg_c3 = float
		inv_cec_cg_paco = float
		inv_cec_cg_pdco = float
		inv_cec_cg_pnt = float
		inv_cec_cg_psco = float
		inv_cec_cg_vdcmax = float
		inv_cec_cg_vdco = float
		inv_tdc_cec_cg = tuple


	class InverterDatasheet(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		inv_ds_eff = float
		inv_ds_paco = float
		inv_ds_pnt = float
		inv_ds_pso = float
		inv_ds_vdcmax = float
		inv_ds_vdco = float
		inv_tdc_ds = tuple


	class InverterPartLoadCurve(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		inv_pd_efficiency = tuple
		inv_pd_paco = float
		inv_pd_partload = tuple
		inv_pd_pdco = float
		inv_pd_pnt = float
		inv_pd_vdcmax = float
		inv_pd_vdco = float
		inv_tdc_plc = tuple


	class InverterMermoudLejeuneModel(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		ond_Aux_Loss = float
		ond_CompPMax = str
		ond_CompVMax = str
		ond_IMaxAC = float
		ond_IMaxDC = float
		ond_INomAC = float
		ond_INomDC = float
		ond_ModeAffEnum = str
		ond_ModeOper = str
		ond_NbInputs = float
		ond_NbMPPT = float
		ond_Night_Loss = float
		ond_PLim1 = float
		ond_PLimAbs = float
		ond_PMaxDC = float
		ond_PMaxOUT = float
		ond_PNomConv = float
		ond_PNomDC = float
		ond_PSeuil = float
		ond_TPLim1 = float
		ond_TPLimAbs = float
		ond_TPMax = float
		ond_TPNom = float
		ond_VAbsMax = float
		ond_VMPPMax = float
		ond_VMppMin = float
		ond_VNomEff = tuple
		ond_VOutConv = float
		ond_doAllowOverpower = float
		ond_doUseTemperatureLimit = float
		ond_effCurve_Pac = tuple
		ond_effCurve_Pdc = tuple
		ond_effCurve_elements = float
		ond_effCurve_eta = tuple
		ond_lossRAc = float
		ond_lossRDc = float


	class BatterySystem(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		batt_ac_dc_efficiency = float
		batt_ac_or_dc = float
		batt_computed_bank_capacity = float
		batt_computed_series = float
		batt_computed_strings = float
		batt_current_charge_max = float
		batt_current_choice = float
		batt_current_discharge_max = float
		batt_dc_ac_efficiency = float
		batt_dc_dc_efficiency = float
		batt_inverter_efficiency_cutoff = float
		batt_loss_choice = float
		batt_losses = tuple
		batt_losses_charging = tuple
		batt_losses_discharging = tuple
		batt_losses_idle = tuple
		batt_mass = float
		batt_meter_position = float
		batt_power_charge_max_kwac = float
		batt_power_charge_max_kwdc = float
		batt_power_discharge_max_kwac = float
		batt_power_discharge_max_kwdc = float
		batt_replacement_capacity = float
		batt_replacement_option = float
		batt_replacement_schedule_percent = tuple
		batt_surface_area = float
		en_batt = float
		en_standalone_batt = float
		om_replacement_cost1 = tuple


	class Load(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		crit_load = tuple
		crit_load_escalation = tuple
		grid_outage = tuple
		load = tuple
		load_escalation = tuple
		run_resiliency_calcs = float


	class BatteryCell(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		LeadAcid_q10_computed = float
		LeadAcid_q20_computed = float
		LeadAcid_qn_computed = float
		LeadAcid_tn = float
		batt_C_rate = float
		batt_Cp = float
		batt_Qexp = float
		batt_Qfull = float
		batt_Qfull_flow = float
		batt_Qnom = float
		batt_Vcut = float
		batt_Vexp = float
		batt_Vfull = float
		batt_Vnom = float
		batt_Vnom_default = float
		batt_calendar_a = float
		batt_calendar_b = float
		batt_calendar_c = float
		batt_calendar_choice = float
		batt_calendar_lifetime_matrix = tuple
		batt_calendar_q0 = float
		batt_chem = float
		batt_h_to_ambient = float
		batt_initial_SOC = float
		batt_life_model = float
		batt_lifetime_matrix = tuple
		batt_maximum_SOC = float
		batt_minimum_SOC = float
		batt_minimum_modetime = float
		batt_minimum_outage_SOC = float
		batt_resistance = float
		batt_room_temperature_celsius = tuple
		batt_voltage_choice = float
		batt_voltage_matrix = tuple
		cap_vs_temp = tuple


	class BatteryDispatch(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		batt_custom_dispatch = tuple
		batt_cycle_cost = tuple
		batt_cycle_cost_choice = float
		batt_dispatch_auto_btm_can_discharge_to_grid = float
		batt_dispatch_auto_can_charge = float
		batt_dispatch_auto_can_clipcharge = float
		batt_dispatch_auto_can_fuelcellcharge = float
		batt_dispatch_auto_can_gridcharge = float
		batt_dispatch_charge_only_system_exceeds_load = float
		batt_dispatch_choice = float
		batt_dispatch_discharge_only_load_exceeds_system = float
		batt_dispatch_load_forecast_choice = float
		batt_dispatch_pvs_ac_lb = float
		batt_dispatch_pvs_ac_lb_enable = float
		batt_dispatch_pvs_ac_ub = float
		batt_dispatch_pvs_ac_ub_enable = float
		batt_dispatch_pvs_curtail_as_control = float
		batt_dispatch_pvs_curtail_if_violation = float
		batt_dispatch_pvs_forecast_shift_periods = float
		batt_dispatch_pvs_kf = float
		batt_dispatch_pvs_ki = float
		batt_dispatch_pvs_kp = float
		batt_dispatch_pvs_max_ramp = float
		batt_dispatch_pvs_nameplate_ac = float
		batt_dispatch_pvs_short_forecast_enable = float
		batt_dispatch_pvs_soc_rest = float
		batt_dispatch_pvs_timestep_multiplier = float
		batt_dispatch_update_frequency_hours = float
		batt_dispatch_wf_forecast_choice = float
		batt_load_ac_forecast = tuple
		batt_load_ac_forecast_escalation = tuple
		batt_look_ahead_hours = float
		batt_pv_ac_forecast = tuple
		batt_pv_clipping_forecast = tuple
		batt_target_choice = float
		batt_target_power = tuple
		batt_target_power_monthly = tuple
		dispatch_manual_btm_discharge_to_grid = tuple
		dispatch_manual_charge = tuple
		dispatch_manual_discharge = tuple
		dispatch_manual_fuelcellcharge = tuple
		dispatch_manual_gridcharge = tuple
		dispatch_manual_percent_discharge = tuple
		dispatch_manual_percent_gridcharge = tuple
		dispatch_manual_sched = tuple
		dispatch_manual_sched_weekend = tuple


	class SystemCosts(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		om_batt_replacement_cost = tuple
		om_replacement_cost_escal = float


	class FuelCell(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		fuelcell_power = tuple


	class PriceSignal(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		dispatch_factors_ts = tuple
		dispatch_sched_weekday = tuple
		dispatch_sched_weekend = tuple
		dispatch_tod_factors = tuple
		forecast_price_signal_model = float
		mp_ancserv1_revenue = tuple
		mp_ancserv2_revenue = tuple
		mp_ancserv3_revenue = tuple
		mp_ancserv4_revenue = tuple
		mp_enable_ancserv1 = float
		mp_enable_ancserv2 = float
		mp_enable_ancserv3 = float
		mp_enable_ancserv4 = float
		mp_enable_energy_market_revenue = float
		mp_energy_market_revenue = tuple
		ppa_multiplier_model = float
		ppa_price_input = tuple


	class ElectricityRates(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		rate_escalation = tuple
		ur_annual_min_charge = float
		ur_billing_demand_lookback_percentages = tuple
		ur_billing_demand_lookback_period = float
		ur_billing_demand_minimum = float
		ur_dc_billing_demand_periods = tuple
		ur_dc_enable = float
		ur_dc_flat_mat = tuple
		ur_dc_sched_weekday = tuple
		ur_dc_sched_weekend = tuple
		ur_dc_tou_mat = tuple
		ur_ec_sched_weekday = tuple
		ur_ec_sched_weekend = tuple
		ur_ec_tou_mat = tuple
		ur_en_ts_buy_rate = float
		ur_en_ts_sell_rate = float
		ur_enable_billing_demand = float
		ur_metering_option = float
		ur_monthly_fixed_charge = float
		ur_monthly_min_charge = float
		ur_nm_credit_month = float
		ur_nm_credit_rollover = float
		ur_nm_yearend_sell_rate = float
		ur_sell_eq_buy = float
		ur_ts_buy_rate = tuple
		ur_ts_sell_rate = tuple
		ur_yearzero_usage_peaks = tuple


	class GridLimits(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		enable_interconnection_limit = float
		grid_curtailment = tuple
		grid_interconnection_limit_kwac = float


	class AdjustmentFactors(object):
		def assign(self): 
			pass
	
		def export(self): 
			return {}
	
		def __init__(self, *args, **kwargs): # real signature unknown
			pass
	
		constant = float
		dc_constant = float
		dc_hourly = tuple
		dc_periods = tuple
		hourly = tuple
		periods = tuple
		sf_constant = float
		sf_hourly = tuple
		sf_periods = tuple

	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		ac_lifetime_loss = tuple
		ac_loss = float
		ac_perf_adj_loss = tuple
		ac_transmission_loss = tuple
		ac_wiring_loss = tuple
		airmass = tuple
		alb = tuple
		annual_ac_battery_loss_percent = float
		annual_ac_gross = float
		annual_ac_inv_clip_loss_percent = float
		annual_ac_inv_eff_loss_percent = float
		annual_ac_inv_pnt_loss_percent = float
		annual_ac_inv_pso_loss_percent = float
		annual_ac_lifetime_loss_percent = float
		annual_ac_loss_ond = float
		annual_ac_perf_adj_loss_percent = float
		annual_ac_wiring_loss = float
		annual_ac_wiring_loss_percent = float
		annual_crit_load = float
		annual_crit_load_unmet = float
		annual_crit_load_unmet_percentage = float
		annual_dc_battery_loss_percent = float
		annual_dc_diodes_loss = float
		annual_dc_diodes_loss_percent = float
		annual_dc_gross = float
		annual_dc_inv_tdc_loss_percent = float
		annual_dc_invmppt_loss = float
		annual_dc_lifetime_loss_percent = float
		annual_dc_loss_ond = float
		annual_dc_mismatch_loss = float
		annual_dc_mismatch_loss_percent = float
		annual_dc_module_loss_percent = float
		annual_dc_mppt_clip_loss_percent = float
		annual_dc_nameplate_loss = float
		annual_dc_nameplate_loss_percent = float
		annual_dc_net = float
		annual_dc_nominal = float
		annual_dc_optimizer_loss = float
		annual_dc_optimizer_loss_percent = float
		annual_dc_perf_adj_loss_percent = float
		annual_dc_snow_loss_percent = float
		annual_dc_tracking_loss = float
		annual_dc_tracking_loss_percent = float
		annual_dc_wiring_loss = float
		annual_dc_wiring_loss_percent = float
		annual_energy = float
		annual_energy_distribution_time = tuple
		annual_export_to_grid_energy = tuple
		annual_gh = float
		annual_import_to_grid_energy = tuple
		annual_inv_cliploss = float
		annual_inv_pntloss = float
		annual_inv_psoloss = float
		annual_inv_tdcloss = float
		annual_outage_losses_unmet = float
		annual_poa_beam_eff = float
		annual_poa_beam_nom = float
		annual_poa_cover_loss_percent = float
		annual_poa_eff = float
		annual_poa_front = float
		annual_poa_nom = float
		annual_poa_rear = float
		annual_poa_rear_gain_percent = float
		annual_poa_shaded = float
		annual_poa_shaded_soiled = float
		annual_poa_shading_loss_percent = float
		annual_poa_soiling_loss_percent = float
		annual_snow_loss = float
		annual_subarray1_dc_diodes_loss = float
		annual_subarray1_dc_gross = float
		annual_subarray1_dc_mismatch_loss = float
		annual_subarray1_dc_nameplate_loss = float
		annual_subarray1_dc_tracking_loss = float
		annual_subarray1_dc_wiring_loss = float
		annual_subarray2_dc_diodes_loss = float
		annual_subarray2_dc_gross = float
		annual_subarray2_dc_mismatch_loss = float
		annual_subarray2_dc_nameplate_loss = float
		annual_subarray2_dc_tracking_loss = float
		annual_subarray2_dc_wiring_loss = float
		annual_subarray3_dc_diodes_loss = float
		annual_subarray3_dc_gross = float
		annual_subarray3_dc_mismatch_loss = float
		annual_subarray3_dc_nameplate_loss = float
		annual_subarray3_dc_tracking_loss = float
		annual_subarray3_dc_wiring_loss = float
		annual_subarray4_dc_diodes_loss = float
		annual_subarray4_dc_gross = float
		annual_subarray4_dc_mismatch_loss = float
		annual_subarray4_dc_nameplate_loss = float
		annual_subarray4_dc_tracking_loss = float
		annual_subarray4_dc_wiring_loss = float
		annual_total_loss_percent = float
		annual_transmission_loss = float
		annual_transmission_loss_percent = float
		annual_xfmr_loss_percent = float
		average_battery_conversion_efficiency = float
		average_battery_roundtrip_efficiency = float
		avg_critical_load = float
		batt_DOD = tuple
		batt_DOD_cycle_average = tuple
		batt_I = tuple
		batt_SOC = tuple
		batt_annual_charge_energy = tuple
		batt_annual_charge_from_grid = tuple
		batt_annual_charge_from_system = tuple
		batt_annual_discharge_energy = tuple
		batt_annual_energy_loss = tuple
		batt_annual_energy_system_loss = tuple
		batt_bank_installed_capacity = float
		batt_bank_replacement = tuple
		batt_capacity_percent = tuple
		batt_capacity_percent_calendar = tuple
		batt_capacity_percent_cycle = tuple
		batt_capacity_thermal_percent = tuple
		batt_conversion_loss = tuple
		batt_cost_to_cycle = tuple
		batt_cycles = tuple
		batt_dispatch_sched = tuple
		batt_power = tuple
		batt_power_target = tuple
		batt_pvs_PV_ramp_interval = tuple
		batt_pvs_P_pv_ac = tuple
		batt_pvs_battpower = tuple
		batt_pvs_battsoc = tuple
		batt_pvs_curtail = tuple
		batt_pvs_energy_to_grid_percent = float
		batt_pvs_energy_to_grid_percent_sam = float
		batt_pvs_forecast_pv_energy = tuple
		batt_pvs_outpower = tuple
		batt_pvs_violation_count = float
		batt_pvs_violation_list = tuple
		batt_pvs_violation_percent = float
		batt_q0 = tuple
		batt_q1 = tuple
		batt_q2 = tuple
		batt_qmax = tuple
		batt_qmaxI = tuple
		batt_qmax_thermal = tuple
		batt_revenue_charge = tuple
		batt_revenue_clipcharge = tuple
		batt_revenue_discharge = tuple
		batt_revenue_gridcharge = tuple
		batt_system_charge_percent = float
		batt_system_loss = tuple
		batt_temperature = tuple
		batt_to_grid = tuple
		batt_to_load = tuple
		batt_to_system_load = tuple
		batt_voltage = tuple
		batt_voltage_cell = tuple
		capacity_factor = float
		capacity_factor_ac = float
		cdf_of_surviving = tuple
		crit_load = tuple
		crit_load_unmet = tuple
		dc_degrade_factor = tuple
		dc_invmppt_loss = tuple
		dc_net = tuple
		dc_snow_loss = tuple
		df = tuple
		df_calc = tuple
		dn = tuple
		dn_calc = tuple
		fuelcell_to_batt = tuple
		gen = tuple
		gen_without_battery = tuple
		gh = tuple
		gh_calc = tuple
		grid_power = tuple
		grid_power_target = tuple
		grid_to_batt = tuple
		grid_to_load = tuple
		interconnection_loss = tuple
		inv_cliploss = tuple
		inv_eff = tuple
		inv_pntloss = tuple
		inv_psoloss = tuple
		inv_tdcloss = tuple
		inv_total_loss = tuple
		inverterMPPT1_DCVoltage = tuple
		inverterMPPT2_DCVoltage = tuple
		inverterMPPT3_DCVoltage = tuple
		inverterMPPT4_DCVoltage = tuple
		kwh_per_kw = float
		market_sell_rate_series_yr1 = tuple
		monthly_batt_to_grid = tuple
		monthly_batt_to_load = tuple
		monthly_batt_to_system_load = tuple
		monthly_crit_load = tuple
		monthly_crit_load_unmet = tuple
		monthly_crit_load_unmet_percentage = tuple
		monthly_dc = tuple
		monthly_energy = tuple
		monthly_grid_to_batt = tuple
		monthly_grid_to_load = tuple
		monthly_interconnection_loss = tuple
		monthly_outage_losses_unmet = tuple
		monthly_poa_beam_eff = tuple
		monthly_poa_beam_nom = tuple
		monthly_poa_eff = tuple
		monthly_poa_front = tuple
		monthly_poa_nom = tuple
		monthly_poa_rear = tuple
		monthly_snow_loss = tuple
		monthly_system_to_batt = tuple
		monthly_system_to_grid = tuple
		monthly_system_to_load = tuple
		nameplate_dc_rating = float
		outage_durations = tuple
		outage_losses_unmet = tuple
		pdf_of_surviving = tuple
		performance_ratio = float
		poa_beam_eff = tuple
		poa_beam_nom = tuple
		poa_eff = tuple
		poa_front = tuple
		poa_nom = tuple
		poa_rear = tuple
		poa_shaded = tuple
		poa_shaded_soiled = tuple
		resilience_hrs = tuple
		resilience_hrs_avg = float
		resilience_hrs_max = float
		resilience_hrs_min = float
		shadedb_subarray1_shade_frac = tuple
		shadedb_subarray2_shade_frac = tuple
		shadedb_subarray3_shade_frac = tuple
		shadedb_subarray4_shade_frac = tuple
		sixpar_Adj = float
		sixpar_Il = float
		sixpar_Io = float
		sixpar_Rs = float
		sixpar_Rsh = float
		sixpar_a = float
		snowdepth = tuple
		sol_alt = tuple
		sol_azi = tuple
		sol_zen = tuple
		subarray1_aoi = tuple
		subarray1_aoi_modifier = tuple
		subarray1_axisrot = tuple
		subarray1_beam_shading_factor = tuple
		subarray1_celltemp = tuple
		subarray1_celltempSS = tuple
		subarray1_dc_gross = tuple
		subarray1_dc_voltage = tuple
		subarray1_dcloss = float
		subarray1_idealrot = tuple
		subarray1_isc = tuple
		subarray1_linear_derate = tuple
		subarray1_modeff = tuple
		subarray1_poa_eff = tuple
		subarray1_poa_eff_beam = tuple
		subarray1_poa_eff_diff = tuple
		subarray1_poa_front = tuple
		subarray1_poa_nom = tuple
		subarray1_poa_rear = tuple
		subarray1_poa_shaded = tuple
		subarray1_poa_shaded_soiled = tuple
		subarray1_snow_coverage = tuple
		subarray1_snow_loss = tuple
		subarray1_soiling_derate = tuple
		subarray1_ss_derate = tuple
		subarray1_ss_diffuse_derate = tuple
		subarray1_ss_reflected_derate = tuple
		subarray1_surf_azi = tuple
		subarray1_surf_tilt = tuple
		subarray1_voc = tuple
		subarray2_aoi = tuple
		subarray2_aoi_modifier = tuple
		subarray2_axisrot = tuple
		subarray2_beam_shading_factor = tuple
		subarray2_celltemp = tuple
		subarray2_celltempSS = tuple
		subarray2_dc_gross = tuple
		subarray2_dc_voltage = tuple
		subarray2_dcloss = float
		subarray2_idealrot = tuple
		subarray2_isc = tuple
		subarray2_linear_derate = tuple
		subarray2_modeff = tuple
		subarray2_poa_eff = tuple
		subarray2_poa_eff_beam = tuple
		subarray2_poa_eff_diff = tuple
		subarray2_poa_front = tuple
		subarray2_poa_nom = tuple
		subarray2_poa_rear = tuple
		subarray2_poa_shaded = tuple
		subarray2_poa_shaded_soiled = tuple
		subarray2_snow_coverage = tuple
		subarray2_snow_loss = tuple
		subarray2_soiling_derate = tuple
		subarray2_ss_derate = tuple
		subarray2_ss_diffuse_derate = tuple
		subarray2_ss_reflected_derate = tuple
		subarray2_surf_azi = tuple
		subarray2_surf_tilt = tuple
		subarray2_voc = tuple
		subarray3_aoi = tuple
		subarray3_aoi_modifier = tuple
		subarray3_axisrot = tuple
		subarray3_beam_shading_factor = tuple
		subarray3_celltemp = tuple
		subarray3_celltempSS = tuple
		subarray3_dc_gross = tuple
		subarray3_dc_voltage = tuple
		subarray3_dcloss = float
		subarray3_idealrot = tuple
		subarray3_isc = tuple
		subarray3_linear_derate = tuple
		subarray3_modeff = tuple
		subarray3_poa_eff = tuple
		subarray3_poa_eff_beam = tuple
		subarray3_poa_eff_diff = tuple
		subarray3_poa_front = tuple
		subarray3_poa_nom = tuple
		subarray3_poa_rear = tuple
		subarray3_poa_shaded = tuple
		subarray3_poa_shaded_soiled = tuple
		subarray3_snow_coverage = tuple
		subarray3_snow_loss = tuple
		subarray3_soiling_derate = tuple
		subarray3_ss_derate = tuple
		subarray3_ss_diffuse_derate = tuple
		subarray3_ss_reflected_derate = tuple
		subarray3_surf_azi = tuple
		subarray3_surf_tilt = tuple
		subarray3_voc = tuple
		subarray4_aoi = tuple
		subarray4_aoi_modifier = tuple
		subarray4_axisrot = tuple
		subarray4_beam_shading_factor = tuple
		subarray4_celltemp = tuple
		subarray4_celltempSS = tuple
		subarray4_dc_gross = tuple
		subarray4_dc_voltage = tuple
		subarray4_dcloss = float
		subarray4_idealrot = tuple
		subarray4_isc = tuple
		subarray4_linear_derate = tuple
		subarray4_modeff = tuple
		subarray4_poa_eff = tuple
		subarray4_poa_eff_beam = tuple
		subarray4_poa_eff_diff = tuple
		subarray4_poa_front = tuple
		subarray4_poa_nom = tuple
		subarray4_poa_rear = tuple
		subarray4_poa_shaded = tuple
		subarray4_poa_shaded_soiled = tuple
		subarray4_snow_coverage = tuple
		subarray4_snow_loss = tuple
		subarray4_soiling_derate = tuple
		subarray4_ss_derate = tuple
		subarray4_ss_diffuse_derate = tuple
		subarray4_ss_reflected_derate = tuple
		subarray4_surf_azi = tuple
		subarray4_surf_tilt = tuple
		subarray4_voc = tuple
		sunpos_hour = tuple
		sunup = tuple
		survival_function = tuple
		system_to_batt = tuple
		system_to_grid = tuple
		system_to_load = tuple
		tdry = tuple
		ts_shift_hours = float
		wfpoa = tuple
		wspd = tuple
		xfmr_ll_ts = tuple
		xfmr_ll_year1 = float
		xfmr_loss_ts = tuple
		xfmr_loss_year1 = float
		xfmr_nll_ts = tuple
		xfmr_nll_year1 = float




def default(config) -> Pvsamv1:
	pass

def new() -> Pvsamv1:
	pass

def wrap(ssc_data_t) -> Pvsamv1:
	pass

def from_existing(model, config="") -> Pvsamv1:
	pass

__loader__ = None 

__spec__ = None
