class LinearFresnelDsgIph(object):
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


		file_name = str
		solar_resource_data = dict


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
		I_bn_des = float
		L_col = tuple
		OptCharType = tuple
		P_a = tuple
		P_turb_des = float
		Pipe_hl_coef = float
		Rough = tuple
		SCA_drives_elec = float
		Shadowing = tuple
		T_amb_des_sf = float
		T_fp = float
		Tau_envelope = tuple
		TrackingError = tuple
		V_wind_max = float
		alpha_abs = tuple
		alpha_env = tuple
		b_OpticalTable = tuple
		b_eps_HCE1 = tuple
		b_eps_HCE2 = tuple
		b_eps_HCE3 = tuple
		b_eps_HCE4 = tuple
		dirt_mirror = tuple
		e_startup = float
		error = tuple
		eta_pump = float
		fP_hdr_c = float
		fP_hdr_h = float
		fP_sf_boil = float
		nLoops = float
		nModBoil = float
		q_pb_des = float
		rho_mirror_clean = tuple
		sh_OpticalTable = tuple
		sh_eps_HCE1 = tuple
		sh_eps_HCE2 = tuple
		sh_eps_HCE3 = tuple
		sh_eps_HCE4 = tuple
		theta_dep = float
		theta_stow = float
		x_b_des = float


	class Powerblock(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		T_cold_ref = float
		T_hot = float


	class Heliostat(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		csp_lf_sf_washes_per_year = float
		csp_lf_sf_water_per_wash = float


	class HeatSink(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		heat_sink_dP_frac = float


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


		T_field_cold_in = tuple
		T_field_hot_out = tuple
		T_rec_cold_in = tuple
		T_rec_hot_out = tuple
		W_dot_field_pump = tuple
		W_dot_heat_sink_pump = tuple
		W_dot_parasitic_tot = tuple
		W_dot_sca_track = tuple
		annual_electricity_consumption = float
		annual_energy = float
		annual_energy_distribution_time = tuple
		annual_field_energy = float
		annual_thermal_consumption = float
		annual_total_water_use = float
		beam = tuple
		capacity_factor = float
		defocus = tuple
		deltaP_field = tuple
		e_dot_field_int_energy = tuple
		eta_opt_ave = tuple
		gen = tuple
		hour_day = tuple
		kwh_per_kw = float
		m_dot_field = tuple
		m_dot_loop = tuple
		month = tuple
		op_mode_1 = tuple
		op_mode_2 = tuple
		op_mode_3 = tuple
		pres = tuple
		q_dot_freeze_prot = tuple
		q_dot_piping_loss = tuple
		q_dot_rec_abs = tuple
		q_dot_rec_inc = tuple
		q_dot_rec_thermal_loss = tuple
		q_dot_sf_out = tuple
		q_dot_to_heat_sink = tuple
		q_inc_sf_tot = tuple
		solazi = tuple
		solzen = tuple
		tdry = tuple
		theta_longitudinal = tuple
		theta_traverse = tuple
		time_hr = tuple
		twet = tuple
		wspd = tuple
		x_field_hot_out = tuple
		x_rec_hot_out = tuple




def default(config) -> LinearFresnelDsgIph:
	pass

def new() -> LinearFresnelDsgIph:
	pass

def wrap(ssc_data_t) -> LinearFresnelDsgIph:
	pass

def from_existing(model, config="") -> LinearFresnelDsgIph:
	pass

__loader__ = None 

__spec__ = None
