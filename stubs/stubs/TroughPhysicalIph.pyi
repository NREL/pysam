class TroughPhysicalIph(object):
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

	def get_data_ptr(self):
		pass

	def __getattribute__(self, *args, **kwargs):
		pass

	def __init__(self, *args, **kwargs):
		pass

	class SystemControl(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		is_dispatch = float
		is_parallel_htr = float
		sim_type = float


	class Weather(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		file_name = str
		solar_resource_data = dict


	class SystemDesign(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		q_pb_design = float


	class SolarField(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		A_aperture = tuple
		AbsorberMaterial = tuple
		AnnulusGas = tuple
		Ave_Focal_Length = tuple
		ColperSCA = tuple
		D_2 = tuple
		D_3 = tuple
		D_4 = tuple
		D_5 = tuple
		D_p = tuple
		Design_loss = tuple
		Dirt_HCE = tuple
		Dirt_mirror = tuple
		Distance_SCA = tuple
		EPSILON_4 = tuple
		EPSILON_5 = tuple
		Error = tuple
		FieldConfig = float
		Flow_type = tuple
		Fluid = float
		GeomEffects = tuple
		GlazingIntactIn = tuple
		HCE_FieldFrac = tuple
		HDR_rough = float
		IAM_matrix = tuple
		I_bn_des = float
		L_SCA = tuple
		L_aperture = tuple
		L_rnr_per_xpan = float
		L_xpan_hdr = float
		L_xpan_rnr = float
		Min_rnr_xpans = float
		N_hdr_per_xpan = float
		N_max_hdr_diams = float
		P_a = tuple
		Pipe_hl_coef = float
		Rho_mirror_clean = tuple
		Rough = tuple
		Row_Distance = float
		SCA_drives_elec = float
		Shadowing = tuple
		T_fp = float
		T_loop_in_des = float
		T_loop_out = float
		T_shutdown = float
		T_startup = float
		Tau_envelope = tuple
		TrackingError = tuple
		V_hdr_cold_max = float
		V_hdr_cold_min = float
		V_hdr_hot_max = float
		V_hdr_hot_min = float
		W_aperture = tuple
		accept_init = float
		accept_loc = float
		accept_mode = float
		alpha_abs = tuple
		alpha_env = tuple
		azimuth = float
		calc_design_pipe_vals = float
		custom_sf_pipe_sizes = float
		epsilon_3_11 = tuple
		epsilon_3_12 = tuple
		epsilon_3_13 = tuple
		epsilon_3_14 = tuple
		epsilon_3_21 = tuple
		epsilon_3_22 = tuple
		epsilon_3_23 = tuple
		epsilon_3_24 = tuple
		epsilon_3_31 = tuple
		epsilon_3_32 = tuple
		epsilon_3_33 = tuple
		epsilon_3_34 = tuple
		epsilon_3_41 = tuple
		epsilon_3_42 = tuple
		epsilon_3_43 = tuple
		epsilon_3_44 = tuple
		eta_pump = float
		f_htfmax = float
		f_htfmin = float
		field_fl_props = tuple
		m_dot_htfmax = float
		m_dot_htfmin = float
		mc_bal_cold = float
		mc_bal_hot = float
		mc_bal_sca = float
		nColt = float
		nHCEVar = float
		nHCEt = float
		northsouth_field_sep = float
		offset_xpan_hdr = float
		p_start = float
		rec_qf_delay = float
		rec_su_delay = float
		sf_hdr_diams = tuple
		sf_hdr_lengths = tuple
		sf_hdr_wallthicks = tuple
		sf_rnr_diams = tuple
		sf_rnr_lengths = tuple
		sf_rnr_wallthicks = tuple
		theta_dep = float
		theta_stow = float
		tilt = float
		use_abs_or_rel_mdot_limit = float
		wind_stow_speed = float


	class HeatSink(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		hs_phys_N_sub = float
		hs_phys_P_steam_hot_des = float
		hs_phys_Q_steam_hot_des = float
		hs_phys_T_steam_cold_des = float
		hs_phys_f_mdot_steam_max = float
		hs_phys_f_mdot_steam_min = float
		hs_phys_tol = float
		hs_type = float
		pb_pump_coef = float


	class ParallelHeater(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		f_q_dot_des_allowable_su = float
		f_q_dot_heater_min = float
		heater_efficiency = float
		heater_mult = float
		hrs_startup_at_max_rate = float


	class SystemCosts(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		allow_heater_no_dispatch_opt = float
		heater_spec_cost = float


	class TES(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		cold_tank_Thtr = float
		cold_tank_max_heat = float
		d_tank_in = float
		dt_hot = float
		h_tank_in = float
		h_tank_min = float
		hot_tank_Thtr = float
		hot_tank_max_heat = float
		init_hot_htf_percent = float
		is_h_tank_fixed = float
		store_fl_props = tuple
		store_fluid = float
		tank_pairs = float
		tes_cyl_piston_loss_poly = tuple
		tes_cyl_tank_cp = float
		tes_cyl_tank_dens = float
		tes_cyl_tank_insul_percent = float
		tes_cyl_tank_thick = float
		tes_n_tsteps = float
		tes_pb_T_charge_min = float
		tes_pb_T_cold_delta = float
		tes_pb_T_hot_delta = float
		tes_pb_cp_solid = float
		tes_pb_dens_solid = float
		tes_pb_f_oversize = float
		tes_pb_k_eff = float
		tes_pb_n_xsteps = float
		tes_pb_void_frac = float
		tes_type = float
		tshours = float
		u_tank = float


	class Controller(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		T_tank_hot_inlet_min = float
		V_tes_des = float
		custom_tes_p_loss = float
		custom_tes_pipe_sizes = float
		has_hot_tank_bypass = float
		k_tes_loss_coeffs = tuple
		non_solar_field_land_area_multiplier = float
		specified_solar_multiple = float
		specified_total_aperture = float
		tanks_in_parallel = float
		tes_diams = tuple
		tes_lengths = tuple
		tes_pump_coef = float
		tes_wallthicks = tuple
		trough_loop_control = tuple
		use_solar_mult_or_aperture_area = float


	class SysControl(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		disp_frequency = float
		disp_horizon = float
		disp_max_iter = float
		disp_mip_gap = float
		disp_time_weighting = float
		disp_timeout = float


	class Tou(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		disp_reporting = float
		disp_spec_bb = float
		disp_spec_presolve = float
		disp_spec_scaling = float
		disp_steps_per_hour = float
		dispatch_factors_ts = tuple
		dispatch_sched_weekday = tuple
		dispatch_sched_weekend = tuple
		f_turb_tou_periods = tuple
		is_timestep_load_fractions = float
		is_tod_pc_target_also_pc_max = float
		ppa_multiplier_model = float
		timestep_load_abs = tuple
		timestep_load_abs_factor = float
		timestep_load_fractions = tuple
		weekday_schedule = tuple
		weekend_schedule = tuple


	class FinancialModel(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		csp_financial_model = float


	class FinancialSolutionMode(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		ppa_soln_mode = float


	class Revenue(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		ppa_price_input_heat_btu = tuple


	class TimeOfDeliveryFactors(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		dispatch_tod_factors = tuple


	class System(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		aux_array = tuple
		bop_array = tuple
		pb_fixed_par = float
		washing_frequency = float
		water_usage_per_wash = float


	class Powerblock(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		L_rnr_pb = float


	class CapitalCosts(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		csp_dtr_cost_bop_per_kwe = float
		csp_dtr_cost_contingency_percent = float
		csp_dtr_cost_epc_fixed = float
		csp_dtr_cost_epc_per_acre = float
		csp_dtr_cost_epc_per_watt = float
		csp_dtr_cost_epc_percent = float
		csp_dtr_cost_heat_sink_cost_per_kwe = float
		csp_dtr_cost_htf_system_cost_per_m2 = float
		csp_dtr_cost_plm_fixed = float
		csp_dtr_cost_plm_per_acre = float
		csp_dtr_cost_plm_per_watt = float
		csp_dtr_cost_plm_percent = float
		csp_dtr_cost_sales_tax_percent = float
		csp_dtr_cost_site_improvements_cost_per_m2 = float
		csp_dtr_cost_solar_field_cost_per_m2 = float
		csp_dtr_cost_storage_cost_per_kwht = float
		sales_tax_rate = float


	class FinancialParameters(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		const_per_interest_rate1 = float
		const_per_interest_rate2 = float
		const_per_interest_rate3 = float
		const_per_interest_rate4 = float
		const_per_interest_rate5 = float
		const_per_months1 = float
		const_per_months2 = float
		const_per_months3 = float
		const_per_months4 = float
		const_per_months5 = float
		const_per_percent1 = float
		const_per_percent2 = float
		const_per_percent3 = float
		const_per_percent4 = float
		const_per_percent5 = float
		const_per_upfront_rate1 = float
		const_per_upfront_rate2 = float
		const_per_upfront_rate3 = float
		const_per_upfront_rate4 = float
		const_per_upfront_rate5 = float


	class AdjustmentFactors(object):
		def assign(self): 
			pass
	
		def export(self): 
			return {}
	
		def __init__(self, *args, **kwargs): # real signature unknown
			pass
	
		adjust_constant = float
		adjust_en_hourly = float
		adjust_en_periods = float
		adjust_en_timeindex = float
		adjust_hourly = tuple
		adjust_periods = tuple
		adjust_timeindex = tuple
		dc_adjust_constant = float
		dc_adjust_en_hourly = float
		dc_adjust_en_periods = float
		dc_adjust_en_timeindex = float
		dc_adjust_hourly = tuple
		dc_adjust_periods = tuple
		dc_adjust_timeindex = tuple
		sf_adjust_constant = float
		sf_adjust_en_hourly = float
		sf_adjust_en_periods = float
		sf_adjust_en_timeindex = float
		sf_adjust_hourly = tuple
		sf_adjust_periods = tuple
		sf_adjust_timeindex = tuple

	class ElectricityRates(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		en_electricity_rates = float
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
		ur_nb_apply_credit_current_month = float
		ur_nb_credit_expire = float
		ur_nm_credit_month = float
		ur_nm_credit_rollover = float
		ur_nm_yearend_sell_rate = float
		ur_sell_eq_buy = float
		ur_ts_buy_rate = tuple
		ur_ts_sell_rate = tuple
		ur_yearzero_usage_peaks = tuple


	class Lifetime(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		inflation_rate = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		CosTh_ave = tuple
		D_cpnt = tuple
		E_heater_su_des = float
		EndLoss_ave = tuple
		EqOpteff = tuple
		IAM_ave = tuple
		K_cpnt = tuple
		L_cpnt = tuple
		P_fixed = tuple
		P_plant_balance_tot = tuple
		RowShadow_ave = tuple
		SCADefocusArray = tuple
		SCAInfoArray = tuple
		SCAs_def = tuple
		T_field_cold_in = tuple
		T_field_hot_out = tuple
		T_grad_0 = tuple
		T_grad_1 = tuple
		T_grad_2 = tuple
		T_grad_3 = tuple
		T_grad_4 = tuple
		T_grad_5 = tuple
		T_grad_6 = tuple
		T_grad_7 = tuple
		T_grad_8 = tuple
		T_grad_9 = tuple
		T_heat_sink_in = tuple
		T_heat_sink_out = tuple
		T_htf_heater_in = tuple
		T_htf_heater_out = tuple
		T_rec_cold_in = tuple
		T_rec_hot_out = tuple
		T_tes_cold = tuple
		T_tes_hot = tuple
		Theta_ave = tuple
		Type_cpnt = tuple
		V_tank_hot_ini = float
		W_dot_field_pump = tuple
		W_dot_heater = tuple
		W_dot_heater_des = float
		W_dot_par_tot_haf = tuple
		W_dot_parasitic_tot = tuple
		W_dot_pc_pump = tuple
		W_dot_pump_SS = float
		W_dot_sca_track = tuple
		annual_electricity_consumption = float
		annual_energy = float
		annual_energy_distribution_time = tuple
		annual_energy_heat_btu = float
		annual_field_freeze_protection = float
		annual_tes_freeze_protection = float
		annual_thermal_consumption = float
		annual_total_water_use = float
		aux_design = float
		avg_suboptimal_rel_mip_gap = float
		beam = tuple
		bop_design = float
		capacity_factor = float
		const_per_interest1 = float
		const_per_interest2 = float
		const_per_interest3 = float
		const_per_interest4 = float
		const_per_interest5 = float
		const_per_interest_total = float
		const_per_percent_total = float
		const_per_principal1 = float
		const_per_principal2 = float
		const_per_principal3 = float
		const_per_principal4 = float
		const_per_principal5 = float
		const_per_principal_total = float
		const_per_total1 = float
		const_per_total2 = float
		const_per_total3 = float
		const_per_total4 = float
		const_per_total5 = float
		construction_financing_cost = float
		cp_battery_nameplate = float
		cp_system_nameplate = float
		csp_dtr_cost_bop = float
		csp_dtr_cost_contingency = float
		csp_dtr_cost_epc_total = float
		csp_dtr_cost_heat_sink = float
		csp_dtr_cost_htf_system = float
		csp_dtr_cost_installed_per_capacity = float
		csp_dtr_cost_plm_total = float
		csp_dtr_cost_sales_tax_total = float
		csp_dtr_cost_site_improvements = float
		csp_dtr_cost_solar_field = float
		csp_dtr_cost_storage = float
		csp_dtr_hce_design_heat_losses = tuple
		csp_dtr_hce_optical_effs = tuple
		csp_dtr_loop_hce_heat_loss = float
		csp_dtr_sca_ap_lengths = tuple
		csp_dtr_sca_calc_costh = float
		csp_dtr_sca_calc_end_gains = tuple
		csp_dtr_sca_calc_end_losses = tuple
		csp_dtr_sca_calc_iams = tuple
		csp_dtr_sca_calc_latitude = float
		csp_dtr_sca_calc_sca_effs = tuple
		csp_dtr_sca_calc_theta = float
		csp_dtr_sca_calc_zenith = float
		csp_pt_tes_htf_density = float
		csp_pt_tes_tank_diameter = float
		csp_pt_tes_tank_height = float
		dP_sf_SS = float
		defocus = tuple
		deltaP_field = tuple
		direct_subtotal = float
		disp_obj_relax = tuple
		disp_objective = tuple
		disp_presolve_nconstr = tuple
		disp_presolve_nvar = tuple
		disp_qsf_expected = tuple
		disp_qsfprod_expected = tuple
		disp_qsfsu_expected = tuple
		disp_rel_mip_gap = tuple
		disp_solve_iter = tuple
		disp_solve_state = tuple
		disp_solve_time = tuple
		disp_subopt_flag = tuple
		disp_tes_expected = tuple
		disp_thermeff_expected = tuple
		dni_costh = tuple
		e_ch_tes = tuple
		e_dot_field_int_energy = tuple
		elec_price_out = tuple
		f_htfmax_actual = float
		f_htfmin_actual = float
		field_htf_cp_avg_des = float
		field_htf_max_temp = float
		field_htf_min_temp = float
		field_thermal_output_actual = float
		field_thermal_output_ideal = float
		fixed_land_area = float
		gen = tuple
		gen_heat = tuple
		gen_heat_btu = tuple
		heat_load_capacity_factor = float
		hour_day = tuple
		is_PAR_HTR_allowed = tuple
		is_hx = float
		is_pc_sb_allowed = tuple
		is_pc_su_allowed = tuple
		is_rec_su_allowed = tuple
		kwh_per_kw = float
		loop_optical_efficiency = float
		m_dot_balance = tuple
		m_dot_cold_tank_to_hot_tank = tuple
		m_dot_cr_to_tes_hot = tuple
		m_dot_cycle_to_field = tuple
		m_dot_field_delivered = tuple
		m_dot_field_recirc = tuple
		m_dot_field_to_cycle = tuple
		m_dot_htf_heat_sink = tuple
		m_dot_htf_heater = tuple
		m_dot_htfmax_actual = float
		m_dot_htfmin_actual = float
		m_dot_loop = tuple
		m_dot_pc_to_tes_cold = tuple
		m_dot_tes_cold_out = tuple
		m_dot_tes_hot_out = tuple
		mass_tes_cold = tuple
		mass_tes_hot = tuple
		max_field_flow_velocity = float
		max_loop_flow_vel_des = float
		min_field_flow_velocity = float
		min_inner_diameter = float
		min_loop_flow_vel_des = float
		month = tuple
		monthly_energy = tuple
		monthly_energy_heat_btu = tuple
		nLoops = float
		nSCA = float
		n_op_modes = tuple
		nameplate = float
		op_mode_1 = tuple
		op_mode_2 = tuple
		op_mode_3 = tuple
		operating_modes_a = tuple
		operating_modes_b = tuple
		operating_modes_c = tuple
		pipe_header_P_dsn = tuple
		pipe_header_T_dsn = tuple
		pipe_header_diams = tuple
		pipe_header_expansions = tuple
		pipe_header_lengths = tuple
		pipe_header_mdot_dsn = tuple
		pipe_header_vel_dsn = tuple
		pipe_header_wallthk = tuple
		pipe_loop_P_dsn = tuple
		pipe_loop_T_dsn = tuple
		pipe_runner_P_dsn = tuple
		pipe_runner_T_dsn = tuple
		pipe_runner_diams = tuple
		pipe_runner_expansions = tuple
		pipe_runner_lengths = tuple
		pipe_runner_mdot_dsn = tuple
		pipe_runner_vel_dsn = tuple
		pipe_runner_wallthk = tuple
		pipe_tes_P_dsn = tuple
		pipe_tes_T_dsn = tuple
		pipe_tes_diams = tuple
		pipe_tes_lengths = tuple
		pipe_tes_mdot_dsn = tuple
		pipe_tes_vel_dsn = tuple
		pipe_tes_wallthk = tuple
		ppa_price_input = tuple
		pres = tuple
		pricing_mult = tuple
		q_balance = tuple
		q_ch_tes = tuple
		q_dc_tes = tuple
		q_dot_elec_to_PAR_HTR = tuple
		q_dot_est_cr_on = tuple
		q_dot_est_cr_su = tuple
		q_dot_est_tes_ch = tuple
		q_dot_est_tes_dc = tuple
		q_dot_freeze_prot = tuple
		q_dot_heater_des = float
		q_dot_heater_startup = tuple
		q_dot_heater_to_htf = tuple
		q_dot_htf_sf_out = tuple
		q_dot_pc_max = tuple
		q_dot_pc_min = tuple
		q_dot_pc_sb = tuple
		q_dot_pc_target = tuple
		q_dot_piping_loss = tuple
		q_dot_rec_abs = tuple
		q_dot_rec_inc = tuple
		q_dot_rec_thermal_loss = tuple
		q_dot_tes_est = float
		q_dot_to_heat_sink = tuple
		q_inc_sf_tot = tuple
		q_tes = float
		q_tes_heater = tuple
		qinc_costh = tuple
		recirculating = tuple
		required_number_of_loops_for_SM1 = float
		rh = tuple
		sim_duration = float
		single_loop_aperture = float
		solar_mult = float
		solazi = tuple
		solzen = tuple
		system_capacity = float
		tank_losses = tuple
		tdry = tuple
		tes_SA_cold = tuple
		tes_SA_hot = tuple
		tes_SA_tot = tuple
		tes_avail_vol = float
		tes_cold_vol_frac = tuple
		tes_error = tuple
		tes_error_corrected = tuple
		tes_error_percent = tuple
		tes_htf_avg_temp = float
		tes_htf_max_temp = float
		tes_htf_min_temp = float
		tes_htf_pump_power = tuple
		tes_leak_error = tuple
		tes_mass_tot = tuple
		tes_piston_frac = tuple
		tes_piston_loc = tuple
		tes_wall_error = tuple
		thermal_load_heat_btu = tuple
		time_hr = tuple
		timestep_load_abs_calc = tuple
		timestep_load_fractions_calc = tuple
		total_aperture = float
		total_direct_cost = float
		total_indirect_cost = float
		total_installed_cost = float
		total_land_area = float
		total_loop_conversion_efficiency = float
		total_required_aperture_for_SM1 = float
		total_tracking_power = float
		tou_value = tuple
		tshours_field = float
		tshours_heater = float
		twet = tuple
		vel_loop_max = tuple
		vel_loop_min = tuple
		vol_min = float
		vol_tank = float
		vol_tes_cold = tuple
		vol_tes_hot = tuple
		vol_tes_tot = tuple
		wspd = tuple




def default(config) -> TroughPhysicalIph:
	pass

def new() -> TroughPhysicalIph:
	pass

def wrap(ssc_data_t) -> TroughPhysicalIph:
	pass

def from_existing(model, config="") -> TroughPhysicalIph:
	pass

__loader__ = None 

__spec__ = None
