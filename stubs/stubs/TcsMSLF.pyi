class TcsMSLF(object):
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


	class Mslf(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		system_capacity = float


	class TouTranslator(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		weekday_schedule = tuple
		weekend_schedule = tuple


	class Controller(object):
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
		DP_SGS = float
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
		FieldConfig = float
		Flow_type = tuple
		Fluid = float
		GeomEffects = float
		GlazingIntactIn = tuple
		HCE_FieldFrac = tuple
		HDR_rough = float
		HL_T_coefs = tuple
		HL_w_coefs = tuple
		IAM_L_coefs = tuple
		IAM_T_coefs = tuple
		I_b = float
		I_bn_des = float
		L_crossover = float
		L_mod = float
		L_mod_spacing = float
		OpticalTable = tuple
		P_a = tuple
		P_amb = float
		Pipe_hl_coef = float
		Rough = tuple
		SCA_drives_elec = float
		Shadowing = tuple
		T_amb_sf_des = float
		T_cold_in = float
		T_db = float
		T_dp = float
		T_field_in_des = float
		T_field_ini = float
		T_field_out_des = float
		T_fp = float
		T_loop_in_des = float
		T_loop_out = float
		T_set_aux = float
		T_startup = float
		T_tank_cold_ini = float
		T_tank_hot_ini = float
		T_tank_hot_inlet_min = float
		Tau_envelope = tuple
		TrackingError = float
		V_hdr_max = float
		V_hdr_min = float
		V_tank_hot_ini = float
		V_tes_des = float
		V_wind = float
		V_wind_des = float
		W_pb_design = float
		alpha_abs = tuple
		alpha_env = tuple
		aux_array = tuple
		bop_array = tuple
		calc_design_pipe_vals = float
		cold_tank_Thtr = float
		custom_sgs_pipe_sizes = float
		custom_tes_p_loss = float
		cycle_cutoff_frac = float
		cycle_max_frac = float
		defocus = float
		dirt_env = tuple
		dt_cold = float
		dt_hot = float
		epsilon_abs_1 = tuple
		epsilon_abs_2 = tuple
		epsilon_abs_3 = tuple
		epsilon_abs_4 = tuple
		epsilon_glass = tuple
		eta_pump = float
		f_tc_cold = float
		fc_on = float
		ffrac = tuple
		field_fl_props = tuple
		field_fluid = float
		fossil_mode = float
		fthr_ok = float
		fthrctrl = float
		fthrok = float
		h_tank = float
		h_tank_min = float
		has_hot_tank_bypass = float
		hot_tank_Thtr = float
		hx_config = float
		is_hx = float
		k_tes_loss_coeffs = tuple
		m_dot_htfmax = float
		m_dot_htfmin = float
		mc_bal_cold = float
		mc_bal_hot = float
		mc_bal_sca = float
		nLoops = float
		nMod = float
		nRecVar = float
		nSCA = float
		nodes = float
		opt_model = float
		pb_fixed_par = float
		pb_pump_coef = float
		pb_rated_cap = float
		q_max_aux = float
		q_pb_design = float
		rec_htf_vol = float
		rec_model = float
		reflectivity = float
		sgs_diams = tuple
		sgs_lengths = tuple
		sgs_wallthicks = tuple
		solar_mult = float
		solarm = float
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
		tes_temp = float
		tes_type = float
		theta_dep = float
		theta_stow = float
		tshours = float
		tslogic_a = tuple
		tslogic_b = tuple
		tslogic_c = tuple
		u_tank = float
		vol_tank = float


	class SolarField(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		washes_per_year = float
		water_per_wash = float


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
		P_ref = float
		T_ITD_des = float
		T_amb_des = float
		T_approach = float
		T_htf_cold_ref = float
		T_htf_hot_ref = float
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


		ud_f_W_dot_cool_des = float
		ud_ind_od = tuple
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
		fp_mode = float


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


		DP_tot = tuple
		E_bal_startup = tuple
		EqOptEff = tuple
		P_cycle = tuple
		Pipe_hl = tuple
		Q_par_sf_fp = tuple
		Q_par_tes_fp = tuple
		T_pb_in = tuple
		T_pb_out = tuple
		T_sys_c = tuple
		T_sys_h = tuple
		T_tank_cold_fin = tuple
		T_tank_cold_in = tuple
		T_tank_hot_fin = tuple
		T_tank_hot_in = tuple
		Ts_cold = tuple
		Ts_hot = tuple
		W_cool_par = tuple
		W_dot_pump = tuple
		W_net = tuple
		W_par_BOP = tuple
		W_par_aux_boiler = tuple
		annual_W_cycle_gross = float
		annual_energy = float
		annual_energy_distribution_time = tuple
		annual_fuel_usage = float
		annual_total_water_use = float
		beam = tuple
		capacity_factor = float
		conversion_factor = float
		eta = tuple
		eta_optical = tuple
		eta_thermal = tuple
		fixed_par = tuple
		gen = tuple
		hour = tuple
		htf_pump_power = tuple
		kwh_per_kw = float
		m_dot_avail = tuple
		m_dot_charge_field = tuple
		m_dot_discharge_tank = tuple
		m_dot_htf2 = tuple
		m_dot_makeup = tuple
		m_dot_pb = tuple
		mass_tank_cold = tuple
		mass_tank_hot = tuple
		month = tuple
		monthly_energy = tuple
		phi_t = tuple
		pipe_sgs_P_dsn = tuple
		pipe_sgs_T_dsn = tuple
		pipe_sgs_diams = tuple
		pipe_sgs_mdot_dsn = tuple
		pipe_sgs_vel_dsn = tuple
		pipe_sgs_wallthk = tuple
		pres = tuple
		q_abs_tot = tuple
		q_aux_fuel = tuple
		q_avail = tuple
		q_dump = tuple
		q_inc_sf_tot = tuple
		q_loss_spec_tot = tuple
		q_loss_tot = tuple
		q_pb = tuple
		q_to_tes = tuple
		sf_def = tuple
		solazi = tuple
		solzen = tuple
		system_heat_rate = float
		t_loop_outlet = tuple
		tank_losses = tuple
		tdry = tuple
		theta_L = tuple
		tou_value = tuple
		track_par_tot = tuple
		twet = tuple
		vol_tank_cold_fin = tuple
		vol_tank_hot_fin = tuple
		vol_tank_total = tuple
		wspd = tuple




def default(config) -> TcsMSLF:
	pass

def new() -> TcsMSLF:
	pass

def wrap(ssc_data_t) -> TcsMSLF:
	pass

def from_existing(model, config="") -> TcsMSLF:
	pass

__loader__ = None 

__spec__ = None
