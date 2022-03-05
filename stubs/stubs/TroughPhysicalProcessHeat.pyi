class TroughPhysicalProcessHeat(object):
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
		solar_resource_data = dict
		tilt = float
		track_mode = float


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
		L_heat_sink_piping = float
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
		is_model_heat_sink_piping = float
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
		theta_dep = float
		theta_stow = float
		washing_frequency = float
		water_usage_per_wash = float
		wind_stow_speed = float


	class Controller(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		disp_wlim_maxspec = float
		field_fl_props = tuple
		non_solar_field_land_area_multiplier = float
		pb_pump_coef = float
		q_pb_design = float
		specified_solar_multiple = float
		tanks_in_parallel = float
		trough_loop_control = tuple


	class SystemDesign(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		tshours = float


	class TES(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		cold_tank_Thtr = float
		cold_tank_max_heat = float
		h_tank = float
		init_hot_htf_percent = float
		tank_pairs = float
		u_tank = float


	class TES2tank(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		h_tank_min = float
		hot_tank_Thtr = float
		hot_tank_max_heat = float


	class Tou(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		ampl_data_dir = str
		ampl_exec_call = str
		disp_csu_cost = float
		disp_frequency = float
		disp_horizon = float
		disp_max_iter = float
		disp_mip_gap = float
		disp_pen_delta_w = float
		disp_reporting = float
		disp_rsu_cost = float
		disp_spec_bb = float
		disp_spec_presolve = float
		disp_spec_scaling = float
		disp_steps_per_hour = float
		disp_time_weighting = float
		disp_timeout = float
		dispatch_factor1 = float
		dispatch_factor2 = float
		dispatch_factor3 = float
		dispatch_factor4 = float
		dispatch_factor5 = float
		dispatch_factor6 = float
		dispatch_factor7 = float
		dispatch_factor8 = float
		dispatch_factor9 = float
		dispatch_factors_ts = tuple
		dispatch_sched_weekday = tuple
		dispatch_sched_weekend = tuple
		dispatch_series = tuple
		f_turb_tou_periods = tuple
		is_ampl_engine = float
		is_dispatch = float
		is_dispatch_series = float
		is_tod_pc_target_also_pc_max = float
		is_wlim_series = float
		is_write_ampl_dat = float
		ppa_multiplier_model = float
		q_rec_heattrace = float
		q_rec_standby = float
		timestep_load_fractions = tuple
		weekday_schedule = tuple
		weekend_schedule = tuple
		wlim_series = tuple


	class SystemControl(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		disp_inventory_incentive = float


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


	class Powerblock(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		L_rnr_pb = float


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
		EndLoss_ave = tuple
		EqOpteff = tuple
		IAM_ave = tuple
		RowShadow_ave = tuple
		SCAs_def = tuple
		T_field_cold_in = tuple
		T_field_hot_out = tuple
		T_heat_sink_in = tuple
		T_heat_sink_out = tuple
		T_rec_cold_in = tuple
		T_rec_hot_out = tuple
		T_tes_cold = tuple
		T_tes_hot = tuple
		Theta_ave = tuple
		W_dot_field_pump = tuple
		W_dot_parasitic_tot = tuple
		W_dot_pc_pump = tuple
		W_dot_sca_track = tuple
		annual_electricity_consumption = float
		annual_energy = float
		annual_energy_distribution_time = tuple
		annual_field_freeze_protection = float
		annual_gross_energy = float
		annual_tes_freeze_protection = float
		annual_thermal_consumption = float
		annual_total_water_use = float
		beam = tuple
		capacity_factor = float
		deltaP_field = tuple
		dni_costh = tuple
		e_ch_tes = tuple
		e_dot_field_int_energy = tuple
		gen = tuple
		hour_day = tuple
		kwh_per_kw = float
		m_dot_balance = tuple
		m_dot_cr_to_tes_hot = tuple
		m_dot_cycle_to_field = tuple
		m_dot_field_delivered = tuple
		m_dot_field_recirc = tuple
		m_dot_field_to_cycle = tuple
		m_dot_htf_heat_sink = tuple
		m_dot_loop = tuple
		m_dot_pc_to_tes_cold = tuple
		m_dot_tes_cold_out = tuple
		m_dot_tes_hot_out = tuple
		mass_tes_cold = tuple
		mass_tes_hot = tuple
		month = tuple
		op_mode_1 = tuple
		op_mode_2 = tuple
		op_mode_3 = tuple
		pres = tuple
		q_balance = tuple
		q_ch_tes = tuple
		q_dc_tes = tuple
		q_dot_freeze_prot = tuple
		q_dot_htf_sf_out = tuple
		q_dot_piping_loss = tuple
		q_dot_rec_abs = tuple
		q_dot_rec_inc = tuple
		q_dot_rec_thermal_loss = tuple
		q_dot_to_heat_sink = tuple
		q_inc_sf_tot = tuple
		q_tes_heater = tuple
		qinc_costh = tuple
		solar_multiple_actual = float
		solazi = tuple
		solzen = tuple
		tank_losses = tuple
		tdry = tuple
		time_hr = tuple
		twet = tuple
		wspd = tuple




def default(config) -> TroughPhysicalProcessHeat:
	pass

def new() -> TroughPhysicalProcessHeat:
	pass

def wrap(ssc_data_t) -> TroughPhysicalProcessHeat:
	pass

def from_existing(model, config="") -> TroughPhysicalProcessHeat:
	pass

__loader__ = None 

__spec__ = None
