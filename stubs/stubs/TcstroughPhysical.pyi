class TcstroughPhysical(object):
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

	class Weather(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		azimuth = float
		file_name = str
		tilt = float
		track_mode = float


	class Trough(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		system_capacity = float


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
		D_cpnt = tuple
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
		K_cpnt = tuple
		L_SCA = tuple
		L_aperture = tuple
		L_cpnt = tuple
		L_rnr_pb = float
		L_rnr_per_xpan = float
		L_xpan_hdr = float
		L_xpan_rnr = float
		Min_rnr_xpans = float
		N_hdr_per_xpan = float
		N_max_hdr_diams = float
		P_a = tuple
		P_ref = float
		Pipe_hl_coef = float
		Rho_mirror_clean = tuple
		Rough = tuple
		Row_Distance = float
		SCADefocusArray = tuple
		SCAInfoArray = tuple
		SCA_drives_elec = float
		Shadowing = tuple
		T_fp = float
		T_loop_in_des = float
		T_loop_out = float
		T_startup = float
		Tau_envelope = tuple
		TrackingError = tuple
		Type_cpnt = tuple
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
		fthrctrl = float
		fthrok = float
		m_dot_htfmax = float
		m_dot_htfmin = float
		mc_bal_cold = float
		mc_bal_hot = float
		mc_bal_sca = float
		nColt = float
		nHCEVar = float
		nHCEt = float
		nLoops = float
		nSCA = float
		northsouth_field_sep = float
		offset_xpan_hdr = float
		sf_hdr_diams = tuple
		sf_hdr_lengths = tuple
		sf_hdr_wallthicks = tuple
		sf_rnr_diams = tuple
		sf_rnr_lengths = tuple
		sf_rnr_wallthicks = tuple
		solar_mult = float
		theta_dep = float
		theta_stow = float
		washing_frequency = float
		water_usage_per_wash = float


	class Controller(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		DP_SGS = float
		HDR_rough = float
		T_set_aux = float
		T_tank_cold_ini = float
		T_tank_hot_inlet_min = float
		V_tank_hot_ini = float
		V_tes_des = float
		W_pb_design = float
		aux_array = tuple
		bop_array = tuple
		cold_tank_Thtr = float
		custom_sgs_pipe_sizes = float
		custom_tes_p_loss = float
		cycle_cutoff_frac = float
		cycle_max_frac = float
		dt_cold = float
		dt_hot = float
		eta_pump = float
		f_tc_cold = float
		ffrac = tuple
		field_fl_props = tuple
		fossil_mode = float
		h_tank = float
		h_tank_min = float
		has_hot_tank_bypass = float
		hot_tank_Thtr = float
		hx_config = float
		is_hx = float
		k_tes_loss_coeffs = tuple
		nodes = float
		pb_fixed_par = float
		pb_pump_coef = float
		q_max_aux = float
		q_pb_design = float
		sf_type = float
		sgs_diams = tuple
		sgs_lengths = tuple
		sgs_wallthicks = tuple
		store_fl_props = tuple
		store_fluid = float
		t_ch_out_max = float
		t_dis_out_min = float
		t_standby_reset = float
		tank_max_heat = float
		tank_pairs = float
		tanks_in_parallel = float
		tc_fill = float
		tc_void = float
		tes_pump_coef = float
		tes_type = float
		tshours = float
		tslogic_a = tuple
		tslogic_b = tuple
		tslogic_c = tuple
		u_tank = float
		vol_tank = float


	class TouTranslator(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		weekday_schedule = tuple
		weekend_schedule = tuple


	class Powerblock(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		CT = float
		F_wc = tuple
		P_boil = float
		P_cond_min = float
		P_cond_ratio = float
		T_ITD_des = float
		T_amb_des = float
		T_approach = float
		dT_cw_ref = float
		eta_ref = float
		n_pl_inc = float
		pb_bd_frac = float
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


		ud_T_amb_des = float
		ud_T_amb_high = float
		ud_T_amb_ind_od = tuple
		ud_T_amb_low = float
		ud_T_htf_high = float
		ud_T_htf_ind_od = tuple
		ud_T_htf_low = float
		ud_f_W_dot_cool_des = float
		ud_ind_od = tuple
		ud_m_dot_htf_high = float
		ud_m_dot_htf_ind_od = tuple
		ud_m_dot_htf_low = float
		ud_m_dot_water_cool_des = float


	class Enet(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		eta_lhv = float
		eta_tes_htr = float


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


		CosTh_ave = tuple
		DP_tot = tuple
		E_bal_startup = tuple
		EndLoss_ave = tuple
		EqOpteff = tuple
		Fuel_usage = tuple
		IAM_ave = tuple
		Pipe_hl = tuple
		Q_aux_backup = tuple
		Q_par_sf_fp = tuple
		Q_par_tes_fp = tuple
		RowShadow_ave = tuple
		SCA_par_tot = tuple
		SCAs_def = tuple
		T_field_in = tuple
		T_pb_in = tuple
		T_pb_out = tuple
		T_sys_c = tuple
		T_sys_h = tuple
		T_tank_cold_fin = tuple
		T_tank_cold_in = tuple
		T_tank_hot_fin = tuple
		T_tank_hot_in = tuple
		Theta_ave = tuple
		Ts_cold = tuple
		Ts_hot = tuple
		W_cool_par = tuple
		W_cycle_gross = tuple
		W_dot_pump = tuple
		W_net = tuple
		annual_W_cycle_gross = float
		annual_energy = float
		annual_energy_distribution_time = tuple
		annual_fuel_usage = float
		annual_q_abs_tot = float
		annual_q_aux = float
		annual_q_avail = float
		annual_q_dump = float
		annual_q_inc_sf_tot = float
		annual_q_pb = float
		annual_q_to_tes = float
		annual_total_water_use = float
		aux_par = tuple
		beam = tuple
		bop_par = tuple
		capacity_factor = float
		conversion_factor = float
		dni_costh = tuple
		eta = tuple
		fixed_par = tuple
		gen = tuple
		hour = tuple
		htf_pump_power = tuple
		kwh_per_kw = float
		m_dot_aux = tuple
		m_dot_avail = tuple
		m_dot_charge_field = tuple
		m_dot_discharge_tank = tuple
		m_dot_htf2 = tuple
		m_dot_makeup = tuple
		m_dot_pb = tuple
		mass_tank_cold = tuple
		mass_tank_hot = tuple
		month = tuple
		monthly_Fuel_usage = tuple
		monthly_W_cycle_gross = tuple
		monthly_energy = tuple
		monthly_m_dot_makeup = tuple
		monthly_q_abs_tot = tuple
		monthly_q_avail = tuple
		monthly_q_dump = tuple
		monthly_q_inc_sf_tot = tuple
		monthly_q_pb = tuple
		monthly_q_to_tes = tuple
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
		pipe_sgs_P_dsn = tuple
		pipe_sgs_T_dsn = tuple
		pipe_sgs_diams = tuple
		pipe_sgs_mdot_dsn = tuple
		pipe_sgs_vel_dsn = tuple
		pipe_sgs_wallthk = tuple
		pres = tuple
		q_abs_tot = tuple
		q_avail = tuple
		q_dump = tuple
		q_inc_sf_tot = tuple
		q_loss_spec_tot = tuple
		q_loss_tot = tuple
		q_pb = tuple
		q_to_tes = tuple
		qinc_costh = tuple
		recirculating = tuple
		solazi = tuple
		solzen = tuple
		system_heat_rate = float
		tank_losses = tuple
		tdry = tuple
		tou_value = tuple
		twet = tuple
		vol_tank_cold_fin = tuple
		vol_tank_hot_fin = tuple
		vol_tank_total = tuple
		wspd = tuple




def default(config) -> TcstroughPhysical:
	pass

def new() -> TcstroughPhysical:
	pass

def wrap(ssc_data_t) -> TcstroughPhysical:
	pass

def from_existing(model, config="") -> TcstroughPhysical:
	pass

__loader__ = None 

__spec__ = None
