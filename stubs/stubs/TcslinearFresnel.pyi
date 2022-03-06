class TcslinearFresnel(object):
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


	class LinearFresnelr(object):
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


	class Solarfield(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		A_aperture = tuple
		AbsorberMaterial = tuple
		AnnulusGas = tuple
		ColAz = float
		D_2 = tuple
		D_3 = tuple
		D_4 = tuple
		D_5 = tuple
		D_p = tuple
		Design_loss = tuple
		Dirt_HCE = tuple
		EPSILON_4 = tuple
		Flow_type = tuple
		GeomEffects = tuple
		GlazingIntactIn = tuple
		HCE_FieldFrac = tuple
		HLCharType = tuple
		HL_W = tuple
		HL_dT = tuple
		IAM_L = tuple
		IAM_T = tuple
		I_bn = float
		I_bn_des = float
		LHV_eff = float
		L_col = tuple
		OptCharType = tuple
		PB_fixed_par = float
		PB_pump_coef = float
		P_a = tuple
		P_amb = float
		P_turb_des = float
		Pipe_hl_coef = float
		Rough = tuple
		SCA_drives_elec = float
		Shadowing = tuple
		SolarAz_init = float
		SolarZen = float
		T_amb_des_sf = float
		T_db = float
		T_dp = float
		T_fp = float
		T_pb_out_init = float
		Tau_envelope = tuple
		TrackingError = tuple
		V_wind = float
		V_wind_max = float
		alpha_abs = tuple
		alpha_env = tuple
		aux_array = tuple
		b_OpticalTable = tuple
		b_eps_HCE1 = tuple
		b_eps_HCE2 = tuple
		b_eps_HCE3 = tuple
		b_eps_HCE4 = tuple
		bop_array = tuple
		cycle_cutoff_frac = float
		cycle_max_fraction = float
		dirt_mirror = tuple
		dnifc = float
		e_startup = float
		error = tuple
		eta_pump = float
		fP_boil_to_sh = float
		fP_hdr_c = float
		fP_hdr_h = float
		fP_sf_boil = float
		fP_sf_sh = float
		ffrac = tuple
		fossil_mode = float
		is_multgeom = float
		is_oncethru = float
		is_sh = float
		latitude = float
		m_dot_htf_ref = float
		m_dot_min = float
		m_pb_demand = float
		nLoops = float
		nModBoil = float
		nModSH = float
		q_max_aux = float
		q_pb_des = float
		q_sby_frac = float
		rho_mirror_clean = tuple
		sh_OpticalTable = tuple
		sh_eps_HCE1 = tuple
		sh_eps_HCE2 = tuple
		sh_eps_HCE3 = tuple
		sh_eps_HCE4 = tuple
		shift = float
		solarm = float
		t_sby = float
		tes_hours = float
		theta_dep = float
		theta_stow = float
		x_b_des = float


	class Heliostat(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		csp_lf_sf_washes_per_year = float
		csp_lf_sf_water_per_wash = float


	class Powerblock(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		CT = float
		F_wc = tuple
		P_amb_pwb = float
		P_boil_des = float
		P_cond_min = float
		P_cond_ratio = float
		P_rh_ref = float
		T_ITD_des = float
		T_amb_des = float
		T_approach = float
		T_cold_ref = float
		T_db_pwb = float
		T_hot = float
		T_wb = float
		dT_cw_ref = float
		demand_var = float
		dp_b = float
		dp_rh = float
		dp_sh = float
		eta_ref = float
		f_recSU = float
		m_dot_st = float
		n_pl_inc = float
		pb_bd_frac = float
		pc_mode = float
		q_sby_frac = float
		relhum = float
		rh_frac_ref = float
		standby_control = float
		startup_frac = float
		startup_time = float


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


		E_bal_startup = tuple
		P_cond = tuple
		P_sf_in = tuple
		P_turb_in = tuple
		T_field_in = tuple
		T_field_out = tuple
		T_loop_out = tuple
		T_pb_in = tuple
		T_pb_out = tuple
		W_cool_par = tuple
		W_cycle_gross = tuple
		W_dot_aux = tuple
		W_dot_bop = tuple
		W_dot_col = tuple
		W_dot_fixed = tuple
		W_dot_pump = tuple
		W_net = tuple
		annual_W_cycle_gross = float
		annual_energy = float
		annual_energy_distribution_time = tuple
		annual_fuel_usage = float
		annual_total_water_use = float
		beam = tuple
		capacity_factor = float
		conversion_factor = float
		dP_tot = tuple
		defocus = tuple
		eta = tuple
		eta_opt_ave = tuple
		eta_sf = tuple
		eta_thermal = tuple
		f_bays = tuple
		gen = tuple
		hour = tuple
		kwh_per_kw = float
		m_dot = tuple
		m_dot_aux = tuple
		m_dot_b_tot = tuple
		m_dot_field = tuple
		m_dot_makeup = tuple
		m_dot_to_pb = tuple
		month = tuple
		monthly_energy = tuple
		pres = tuple
		q_aux_fluid = tuple
		q_aux_fuel = tuple
		q_dump = tuple
		q_field_delivered = tuple
		q_inc_tot = tuple
		q_loss_piping = tuple
		q_loss_rec = tuple
		q_loss_sf = tuple
		q_to_pb = tuple
		solazi = tuple
		solzen = tuple
		system_heat_rate = float
		tdry = tuple
		tou_value = tuple
		twet = tuple
		wspd = tuple




def default(config) -> TcslinearFresnel:
	pass

def new() -> TcslinearFresnel:
	pass

def wrap(ssc_data_t) -> TcslinearFresnel:
	pass

def from_existing(model, config="") -> TcslinearFresnel:
	pass

__loader__ = None 

__spec__ = None
