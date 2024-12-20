class MsptIph(object):
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

	class SolarResource(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		solar_resource_data = dict
		solar_resource_file = str


	class SystemControl(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		aux_par = float
		aux_par_0 = float
		aux_par_1 = float
		aux_par_2 = float
		aux_par_f = float
		bop_par = float
		bop_par_0 = float
		bop_par_1 = float
		bop_par_2 = float
		bop_par_f = float
		disp_frequency = float
		disp_horizon = float
		disp_hsu_cost_rel = float
		disp_inventory_incentive = float
		disp_max_iter = float
		disp_mip_gap = float
		disp_reporting = float
		disp_rsu_cost_rel = float
		disp_spec_bb = float
		disp_spec_presolve = float
		disp_spec_scaling = float
		disp_steps_per_hour = float
		disp_time_weighting = float
		disp_timeout = float
		f_turb_tou_periods = tuple
		is_dispatch = float
		is_parallel_htr = float
		is_timestep_load_fractions = float
		is_tod_pc_target_also_pc_max = float
		pb_fixed_par = float
		q_rec_heattrace = float
		q_rec_standby = float
		sim_type = float
		time_start = float
		time_steps_per_hour = float
		time_stop = float
		timestep_load_fractions = tuple
		vacuum_arrays = float
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


	class SystemDesign(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		T_htf_cold_des = float
		T_htf_hot_des = float
		dni_des = float
		q_pb_design = float
		sf_excess = float
		solarm = float
		tshours = float


	class HeliostatField(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		A_sf_in = float
		N_hel = float
		c_atm_0 = float
		c_atm_1 = float
		c_atm_2 = float
		c_atm_3 = float
		cant_type = float
		check_max_flux = float
		csp_pt_sf_fixed_land_area = float
		csp_pt_sf_land_overhead_factor = float
		dens_mirror = float
		eta_map = tuple
		eta_map_aod_format = float
		field_model_type = float
		flux_maps = tuple
		focus_type = float
		hel_stow_deploy = float
		helio_active_fraction = float
		helio_aim_points = tuple
		helio_height = float
		helio_optical_error_mrad = float
		helio_positions = tuple
		helio_reflectance = float
		helio_width = float
		interp_beta = float
		interp_nug = float
		land_bound_list = tuple
		land_bound_table = tuple
		land_max = float
		land_min = float
		n_facet_x = float
		n_facet_y = float
		opt_algorithm = float
		opt_conv_tol = float
		opt_flux_penalty = float
		opt_init_step = float
		opt_max_iter = float
		p_start = float
		p_track = float
		receiver_type = float
		total_land_area_before_rad_cooling_in = float
		v_wind_max = float
		washing_frequency = float
		water_usage_per_wash = float


	class TowerAndReceiver(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		D_rec = float
		Flow_type = float
		N_panels = float
		cav_rec_height = float
		cav_rec_passive_abs = float
		cav_rec_passive_eps = float
		cav_rec_span = float
		cav_rec_width = float
		crossover_shift = float
		csp_pt_rec_max_oper_frac = float
		d_tube_out = float
		delta_flux_hrs = float
		downc_tm_mult = float
		epsilon = float
		eta_pump = float
		f_rec_min = float
		field_fl_props = tuple
		flux_max = float
		h_tower = float
		heat_trace_power = float
		hl_ffact = float
		is_rec_enforce_min_startup = float
		is_rec_model_trans = float
		is_rec_startup_from_T_soln = float
		is_rec_startup_trans = float
		mat_tube = float
		min_fill_time = float
		min_preheat_time = float
		n_cav_rec_panels = float
		n_flux_days = float
		piping_length_const = float
		piping_length_mult = float
		piping_loss_coefficient = float
		preheat_flux = float
		rec_absorptance = float
		rec_clearsky_dni = tuple
		rec_clearsky_fraction = float
		rec_clearsky_model = float
		rec_height = float
		rec_hl_perm2 = float
		rec_htf = float
		rec_qf_delay = float
		rec_su_delay = float
		rec_tm_mult = float
		riser_tm_mult = float
		startup_ramp_time = float
		startup_target_Tdiff = float
		th_riser = float
		th_tube = float
		u_riser = float


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
		bop_spec_cost = float
		contingency_rate = float
		cost_sf_fixed = float
		csp_pt_cost_epc_fixed = float
		csp_pt_cost_epc_per_acre = float
		csp_pt_cost_epc_per_watt = float
		csp_pt_cost_epc_percent = float
		csp_pt_cost_plm_fixed = float
		csp_pt_cost_plm_per_watt = float
		csp_pt_cost_plm_percent = float
		heater_spec_cost = float
		heliostat_spec_cost = float
		land_spec_cost = float
		rec_cost_exp = float
		rec_ref_area = float
		rec_ref_cost = float
		sales_tax_frac = float
		site_spec_cost = float
		tes_spec_cost = float
		tower_exp = float
		tower_fixed_cost = float


	class ThermalStorage(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		cold_tank_Thtr = float
		cold_tank_max_heat = float
		h_tank = float
		h_tank_min = float
		hot_tank_Thtr = float
		hot_tank_max_heat = float
		tank_pairs = float
		tanks_in_parallel = float
		tes_init_hot_htf_percent = float
		u_tank = float


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


	class TimeOfDeliveryFactors(object):
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
		ppa_multiplier_model = float


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
		sales_tax_rate = float


	class Deprecated(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		P_boil = float
		csp_pt_tes_init_hot_htf_percent = float
		disp_csu_cost = float
		disp_pen_delta_w = float
		disp_rsu_cost = float
		piping_loss = float


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

	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		A_rec = float
		A_sf = float
		D_rec_calc = float
		E_heater_su_des = float
		L_tower_piping_calc = float
		N_hel_calc = float
		P_fixed = tuple
		P_plant_balance_tot = tuple
		P_rec_heattrace = tuple
		P_tower_pump = tuple
		Q_tes_des = float
		Q_thermal = tuple
		Q_thermal_ss = tuple
		Q_thermal_ss_csky = tuple
		T_heat_sink_in = tuple
		T_heat_sink_out = tuple
		T_htf_heater_in = tuple
		T_htf_heater_out = tuple
		T_panel_out_max = tuple
		T_rec_in = tuple
		T_rec_out = tuple
		T_rec_out_end = tuple
		T_rec_out_max = tuple
		T_tes_cold = tuple
		T_tes_hot = tuple
		T_wall_downcomer = tuple
		T_wall_rec_inlet = tuple
		T_wall_rec_outlet = tuple
		T_wall_riser = tuple
		V_tes_htf_avail_des = float
		V_tes_htf_total_des = float
		W_dot_bop_design = float
		W_dot_col_tracking_des = float
		W_dot_fixed = float
		W_dot_heater = tuple
		W_dot_heater_des = float
		W_dot_parasitic_tot = tuple
		W_dot_pc_pump = tuple
		W_dot_rec_pump_des = float
		W_dot_rec_pump_rec_share_des = float
		W_dot_rec_pump_tower_share_des = float
		annual_E_tower_pump = float
		annual_electricity_consumption = float
		annual_energy = float
		annual_energy_distribution_time = tuple
		annual_energy_heat_btu = float
		annual_eta_rec_th = float
		annual_eta_rec_th_incl_refl = float
		annual_q_defocus_est = float
		annual_q_piping_loss = float
		annual_q_rec_htf = float
		annual_q_rec_inc = float
		annual_q_rec_loss = float
		annual_q_rec_startup = float
		annual_total_water_use = float
		average_attenuation = float
		beam = tuple
		capacity_factor = float
		cav_panel_width = float
		cav_radius = float
		cav_rec_area = float
		cav_rec_height_calc = float
		cav_rec_width_calc = float
		clearsky = tuple
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
		csp_pt_cost_bop = float
		csp_pt_cost_contingency = float
		csp_pt_cost_epc_total = float
		csp_pt_cost_fossil = float
		csp_pt_cost_heliostats = float
		csp_pt_cost_installed_per_capacity = float
		csp_pt_cost_plm_total = float
		csp_pt_cost_power_block = float
		csp_pt_cost_receiver = float
		csp_pt_cost_sales_tax_total = float
		csp_pt_cost_site_improvements = float
		csp_pt_cost_storage = float
		csp_pt_cost_tower = float
		d_tank_tes = float
		defocus = tuple
		dens_store_htf_at_T_ave = float
		disp_obj_relax = tuple
		disp_objective = tuple
		disp_pceff_expected = tuple
		disp_presolve_nconstr = tuple
		disp_presolve_nvar = tuple
		disp_qpbsu_expected = tuple
		disp_qsf_expected = tuple
		disp_qsfprod_expected = tuple
		disp_qsfsu_expected = tuple
		disp_rel_mip_gap = tuple
		disp_rev_expected = tuple
		disp_solve_iter = tuple
		disp_solve_state = tuple
		disp_solve_time = tuple
		disp_subopt_flag = tuple
		disp_tes_expected = tuple
		disp_thermeff_expected = tuple
		disp_wpb_expected = tuple
		e_ch_tes = tuple
		eta_field = tuple
		eta_map_out = tuple
		eta_rec_thermal_des = float
		eta_therm = tuple
		ext_rec_area = float
		ext_rec_aspect = float
		flux_maps_for_import = tuple
		flux_maps_out = tuple
		gen = tuple
		gen_heat = tuple
		gen_heat_btu = tuple
		h_rec_input_to_cost_model = float
		h_tower_calc = float
		heater_cost = float
		helio_positions_calc = tuple
		heliostat_area = float
		is_PAR_HTR_allowed = tuple
		is_pc_sb_allowed = tuple
		is_pc_su_allowed = tuple
		is_rec_su_allowed = tuple
		kwh_per_kw = float
		land_area_base_calc = float
		land_max_abs = float
		land_min_abs = float
		m_dot_balance = tuple
		m_dot_cr_to_tes_hot = tuple
		m_dot_cycle_to_field = tuple
		m_dot_field_to_cycle = tuple
		m_dot_htf_heat_sink = tuple
		m_dot_htf_heater = tuple
		m_dot_htf_rec_des = float
		m_dot_htf_rec_max = float
		m_dot_pc_to_tes_cold = tuple
		m_dot_rec = tuple
		m_dot_tes_cold_out = tuple
		m_dot_tes_hot_out = tuple
		mass_tes_cold = tuple
		mass_tes_hot = tuple
		n_op_modes = tuple
		nameplate = float
		od_tube_calc = float
		op_mode_1 = tuple
		op_mode_2 = tuple
		op_mode_3 = tuple
		operating_modes_a = tuple
		operating_modes_b = tuple
		operating_modes_c = tuple
		ppa_price_input = tuple
		pparasi = tuple
		pricing_mult = tuple
		q_balance = tuple
		q_ch_tes = tuple
		q_dc_tes = tuple
		q_dot_elec_to_PAR_HTR = tuple
		q_dot_est_cr_on = tuple
		q_dot_est_cr_su = tuple
		q_dot_est_tes_ch = tuple
		q_dot_est_tes_dc = tuple
		q_dot_heater_des = float
		q_dot_heater_startup = tuple
		q_dot_heater_to_htf = tuple
		q_dot_loss_tes_des = float
		q_dot_pc_max = tuple
		q_dot_pc_min = tuple
		q_dot_pc_sb = tuple
		q_dot_pc_target = tuple
		q_dot_piping_loss_des = float
		q_dot_rec_des = float
		q_dot_rec_inc = tuple
		q_dot_reflection_loss = tuple
		q_dot_tes_heater = tuple
		q_dot_to_heat_sink = tuple
		q_piping_losses = tuple
		q_sf_inc = tuple
		q_startup = tuple
		q_thermal_loss = tuple
		rec_defocus = tuple
		rec_height_calc = float
		refl_image_error = float
		rh = tuple
		sf_adjust_out = tuple
		sim_cpu_run_time = float
		solaz = tuple
		solzen = tuple
		system_capacity = float
		tank_losses = tuple
		tdry = tuple
		tes_htf_pump_power = tuple
		time_hr = tuple
		total_direct_cost = float
		total_indirect_cost = float
		total_installed_cost = float
		total_land_area = float
		total_land_area_before_rad_cooling_calc = float
		tou_value = tuple
		tshours_heater = float
		tshours_rec = float
		twet = tuple
		ui_direct_subtotal = float
		vel_rec_htf_des = float
		wspd = tuple




def default(config) -> MsptIph:
	pass

def new() -> MsptIph:
	pass

def wrap(ssc_data_t) -> MsptIph:
	pass

def from_existing(model, config="") -> MsptIph:
	pass

__loader__ = None 

__spec__ = None
