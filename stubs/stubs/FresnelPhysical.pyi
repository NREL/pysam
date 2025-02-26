class FresnelPhysical(object):
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


		disp_inventory_incentive = float
		sim_type = float


	class Weather(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		file_name = str


	class SystemDesign(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		I_bn_des = float
		P_ref = float
		T_loop_in_des = float
		T_loop_out = float
		eta_ref = float
		gross_net_conversion_factor = float
		solar_mult_in = float
		solar_mult_or_Ap = float
		total_Ap_in = float
		tshours = float


	class SolarField(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		FieldConfig = float
		Fluid = float
		HDR_rough = float
		L_rnr_pb = float
		Pipe_hl_coef = float
		SCA_drives_elec = float
		T_amb_sf_des = float
		T_fp = float
		T_startup = float
		V_hdr_max = float
		V_hdr_min = float
		V_wind_des = float
		eta_pump = float
		f_htfmax = float
		f_htfmin = float
		field_fl_props = tuple
		land_mult = float
		m_dot_htfmax = float
		m_dot_htfmin = float
		mc_bal_cold = float
		mc_bal_hot = float
		mc_bal_sca = float
		nMod = float
		p_start = float
		rec_htf_vol = float
		theta_dep = float
		theta_stow = float
		use_abs_or_rel_mdot_limit = float
		washes_per_year = float
		water_per_wash = float


	class ColRec(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		A_aperture = float
		AbsorberMaterial = tuple
		AnnulusGas = tuple
		ColAz = float
		DP_coefs = tuple
		DP_nominal = float
		D_abs_in = tuple
		D_abs_out = tuple
		D_glass_in = tuple
		D_glass_out = tuple
		D_plug = tuple
		Design_loss = tuple
		Dirt_mirror = float
		Error = float
		Flow_type = tuple
		GeomEffects = float
		GlazingIntactIn = tuple
		HCE_FieldFrac = tuple
		HL_T_coefs = tuple
		HL_w_coefs = tuple
		IAM_L_coefs = tuple
		IAM_T_coefs = tuple
		L_crossover = float
		L_mod = float
		L_mod_spacing = float
		OpticalTable = tuple
		P_a = tuple
		Rough = tuple
		Shadowing = tuple
		Tau_envelope = tuple
		TrackingError = float
		alpha_abs = tuple
		alpha_env = tuple
		dirt_env = tuple
		epsilon_abs_1 = tuple
		epsilon_abs_2 = tuple
		epsilon_abs_3 = tuple
		epsilon_abs_4 = tuple
		epsilon_glass = tuple
		nRecVar = float
		opt_model = float
		rec_model = float
		reflectivity = float


	class Powerblock(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		CT = float
		DP_SGS = float
		F_wc = tuple
		P_cond_min = float
		P_cond_ratio = float
		T_ITD_des = float
		T_amb_des = float
		T_approach = float
		cycle_cutoff_frac = float
		cycle_max_frac = float
		dT_cw_ref = float
		n_pl_inc = float
		pb_bd_frac = float
		pb_pump_coef = float
		pc_config = float
		q_sby_frac = float
		startup_frac = float
		startup_time = float
		tech_type = float


	class UserDefinedPC(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		ud_f_W_dot_cool_des = float
		ud_ind_od = tuple
		ud_is_sco2_regr = float
		ud_m_dot_water_cool_des = float


	class Storage(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		V_tes_des = float
		cold_tank_Thtr = float
		cold_tank_max_heat = float
		dt_cold = float
		dt_hot = float
		h_tank = float
		h_tank_min = float
		hot_tank_Thtr = float
		hot_tank_max_heat = float
		init_hot_htf_percent = float
		store_fl_props = tuple
		store_fluid = float
		tank_pairs = float
		tanks_in_parallel = float
		tes_pump_coef = float
		u_tank = float


	class Tou(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		can_cycle_use_standby = float
		disp_reporting = float
		disp_spec_bb = float
		disp_spec_presolve = float
		disp_spec_scaling = float
		disp_steps_per_hour = float
		dispatch_factors_ts = tuple
		f_turb_tou_periods = tuple
		is_timestep_load_fractions = float
		is_tod_pc_target_also_pc_max = float
		ppa_multiplier_model = float
		q_rec_heattrace = float
		q_rec_standby = float
		timestep_load_fractions = tuple


	class SysControl(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		aux_array = tuple
		bop_array = tuple
		disp_csu_cost_rel = float
		disp_frequency = float
		disp_horizon = float
		disp_max_iter = float
		disp_mip_gap = float
		disp_pen_ramping = float
		disp_rsu_cost_rel = float
		disp_time_weighting = float
		disp_timeout = float
		is_dispatch = float
		pb_fixed_par = float
		rec_qf_delay = float
		rec_su_delay = float
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


	class ElectricityRates(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		en_electricity_rates = float


	class TimeOfDeliveryFactors(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		dispatch_sched_weekday = tuple
		dispatch_sched_weekend = tuple
		dispatch_tod_factors = tuple


	class FinancialSolutionMode(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		ppa_price_input = tuple
		ppa_soln_mode = float


	class Revenue(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		mp_energy_market_revenue = tuple


	class CapitalCosts(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		bop_spec_cost = float
		contingency_percent = float
		epc_cost_fixed = float
		epc_cost_per_acre = float
		epc_cost_per_watt = float
		epc_cost_percent_direct = float
		fossil_spec_cost = float
		htf_system_spec_cost = float
		plm_cost_fixed = float
		plm_cost_per_acre = float
		plm_cost_per_watt = float
		plm_cost_percent_direct = float
		power_plant_spec_cost = float
		sales_tax_percent = float
		sales_tax_rate = float
		site_improvements_spec_cost = float
		solar_field_spec_cost = float
		storage_spec_cost = float


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

	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		A_field = float
		A_loop = float
		DP_pressure_loss = float
		EqOpteff = tuple
		P_cooling_tower_tot = tuple
		P_cycle = tuple
		P_fixed = tuple
		P_out_net = tuple
		P_plant_balance_tot = tuple
		Q_field_des_SS = float
		Q_loop_des_SS = float
		Q_loss_hdr_rnr_des_SS = float
		Q_loss_receiver_des_SS = float
		Q_tes_des = float
		SCAs_def = tuple
		T_field_cold_in = tuple
		T_field_hot_out = tuple
		T_field_out_des_SS = float
		T_loop_out_des_SS = float
		T_pc_in = tuple
		T_pc_out = tuple
		T_rec_cold_in = tuple
		T_rec_hot_out = tuple
		T_tes_cold = tuple
		T_tes_hot = tuple
		V_hdr_max_des_SS = float
		V_hdr_min_des_SS = float
		W_dot_bop_design = float
		W_dot_field_pump = tuple
		W_dot_fixed = float
		W_dot_pump_des_SS = float
		W_dot_sca_track = tuple
		annual_W_cycle_gross = float
		annual_energy = float
		annual_field_freeze_protection = float
		annual_tes_freeze_protection = float
		annual_thermal_consumption = float
		annual_total_water_use = float
		aux_design = float
		avg_dt_des = float
		avg_suboptimal_rel_mip_gap = float
		beam = tuple
		bop_cost = float
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
		contingency_cost = float
		conversion_factor = float
		cp_battery_nameplate = float
		cp_system_nameplate = float
		cycle_htf_pump_power = tuple
		dP_field_des_SS = float
		d_tank = float
		defocus = tuple
		deltaP_field = tuple
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
		e_dot_field_int_energy = tuple
		eff_des_SS = float
		eff_loop_des_SS = float
		epc_total_cost = float
		eta = tuple
		eta_optical_des_SS = float
		f_htfmax_actual = float
		f_htfmin_actual = float
		field_area = float
		field_htf_max_temp = float
		field_htf_min_temp = float
		fossil_backup_cost = float
		gen = tuple
		hl_des = float
		hour_day = tuple
		htf_system_cost = float
		installed_per_capacity = float
		is_pc_sb_allowed = tuple
		is_pc_su_allowed = tuple
		is_rec_su_allowed = tuple
		kwh_per_kw = float
		loop_eff = float
		loop_opt_eff = float
		loop_therm_eff = float
		m_dot_balance = tuple
		m_dot_cold_tank_to_hot_tank = tuple
		m_dot_cr_to_tes_hot = tuple
		m_dot_cycle_to_field = tuple
		m_dot_des_SS = float
		m_dot_field_delivered = tuple
		m_dot_field_recirc = tuple
		m_dot_field_to_cycle = tuple
		m_dot_htfmax_actual = float
		m_dot_htfmin_actual = float
		m_dot_loop = tuple
		m_dot_loop_des_SS = float
		m_dot_pc = tuple
		m_dot_pc_to_tes_cold = tuple
		m_dot_tes_cold_out = tuple
		m_dot_tes_hot_out = tuple
		m_dot_water_pc = tuple
		mass_tes_cold = tuple
		mass_tes_hot = tuple
		mdot_cycle_des = float
		mdot_field_des = float
		month = tuple
		monthly_energy = tuple
		nLoops = float
		n_op_modes = tuple
		nameplate = float
		op_mode_1 = tuple
		op_mode_2 = tuple
		op_mode_3 = tuple
		operating_modes_a = tuple
		operating_modes_b = tuple
		operating_modes_c = tuple
		opt_derate = float
		opt_normal = float
		pipe_tes_P_dsn = tuple
		pipe_tes_T_dsn = tuple
		pipe_tes_diams = tuple
		pipe_tes_lengths = tuple
		pipe_tes_mdot_dsn = tuple
		pipe_tes_vel_dsn = tuple
		pipe_tes_wallthk = tuple
		plm_total_cost = float
		power_plant_cost = float
		pres = tuple
		pricing_mult = tuple
		q_balance = tuple
		q_ch_tes = tuple
		q_dc_tes = tuple
		q_dot_cycle_des = float
		q_dot_est_cr_on = tuple
		q_dot_est_cr_su = tuple
		q_dot_est_tes_ch = tuple
		q_dot_est_tes_dc = tuple
		q_dot_freeze_prot = tuple
		q_dot_htf_sf_out = tuple
		q_dot_loss_tes_des = float
		q_dot_pc_max = tuple
		q_dot_pc_min = tuple
		q_dot_pc_sb = tuple
		q_dot_pc_startup = tuple
		q_dot_pc_target = tuple
		q_dot_piping_loss = tuple
		q_dot_rec_abs = tuple
		q_dot_rec_inc = tuple
		q_dot_rec_thermal_loss = tuple
		q_field_des_actual = float
		q_field_des_ideal = float
		q_inc_sf_tot = tuple
		q_pb = tuple
		q_pc_startup = tuple
		q_tes_heater = tuple
		rec_thermal_eff = tuple
		recirculating = tuple
		rh = tuple
		sales_tax_total = float
		sim_duration = float
		site_improvements_cost = float
		sm1_aperture = float
		sm1_nLoops = float
		solar_field_cost = float
		solar_mult = float
		solazi = tuple
		solzen = tuple
		system_capacity = float
		tank_losses = tuple
		tdry = tuple
		tes_htf_cp = float
		tes_htf_dens = float
		tes_htf_max_temp = float
		tes_htf_min_temp = float
		tes_htf_pump_power = tuple
		therm_eff_des_SS = float
		therm_eff_loop_des_SS = float
		time_hr = tuple
		total_Ap = float
		total_direct_cost = float
		total_indirect_cost = float
		total_installed_cost = float
		total_land_area = float
		total_tracking_power = float
		tou_value = tuple
		ts_cost = float
		twet = tuple
		vol_min = float
		vol_tank = float
		wspd = tuple




def default(config) -> FresnelPhysical:
	pass

def new() -> FresnelPhysical:
	pass

def wrap(ssc_data_t) -> FresnelPhysical:
	pass

def from_existing(model, config="") -> FresnelPhysical:
	pass

__loader__ = None 

__spec__ = None
