class TroughPhysicalCspSolver(object):
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


	class TimeOfDelivery(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		dispatch_factors_ts = tuple
		ppa_multiplier_model = float


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
		V_hdr_max = float
		V_hdr_min = float
		W_aperture = tuple
		accept_init = float
		accept_loc = float
		accept_mode = float
		alpha_abs = tuple
		alpha_env = tuple
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


		T_set_aux = float
		T_tank_cold_ini = float
		V_tank_hot_ini = float
		W_pb_design = float
		aux_array = tuple
		bop_array = tuple
		cold_tank_Thtr = float
		cycle_cutoff_frac = float
		cycle_max_frac = float
		dt_cold = float
		dt_hot = float
		f_tc_cold = float
		ffrac = tuple
		field_fl_props = tuple
		fossil_mode = float
		h_tank = float
		h_tank_min = float
		hot_tank_Thtr = float
		hx_config = float
		is_hx = float
		nodes = float
		pb_fixed_par = float
		pb_pump_coef = float
		q_max_aux = float
		q_pb_design = float
		q_sby_frac = float
		sf_type = float
		store_fl_props = tuple
		store_fluid = float
		t_ch_out_max = float
		t_dis_out_min = float
		t_standby_reset = float
		tank_max_heat = float
		tank_pairs = float
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


		P_cooling_tower_tot = tuple
		P_fixed = tuple
		P_out_net = tuple
		P_plant_balance_tot = tuple
		P_tower_pump = tuple
		Q_thermal = tuple
		T_tes_cold = tuple
		T_tes_hot = tuple
		annual_W_cycle_gross = float
		annual_energy = float
		annual_energy_distribution_time = tuple
		annual_total_water_use = float
		beam = tuple
		capacity_factor = float
		conversion_factor = float
		defocus = tuple
		disp_iter_ann = float
		disp_obj_relax = tuple
		disp_objective = tuple
		disp_objective_ann = float
		disp_pceff_expected = tuple
		disp_presolve_nconstr = tuple
		disp_presolve_nconstr_ann = float
		disp_presolve_nvar = tuple
		disp_presolve_nvar_ann = float
		disp_qpbsu_expected = tuple
		disp_qsf_expected = tuple
		disp_qsfprod_expected = tuple
		disp_qsfsu_expected = tuple
		disp_rel_mip_gap = tuple
		disp_rev_expected = tuple
		disp_solve_iter = tuple
		disp_solve_state = tuple
		disp_solve_time = tuple
		disp_solve_time_ann = float
		disp_subopt_flag = tuple
		disp_tes_expected = tuple
		disp_thermeff_expected = tuple
		disp_wpb_expected = tuple
		e_ch_tes = tuple
		eta_map_out = tuple
		flux_maps_out = tuple
		gen = tuple
		htf_pump_power = tuple
		is_pc_sb_allowed = tuple
		is_pc_su_allowed = tuple
		is_rec_su_allowed = tuple
		kwh_per_kw = float
		m_dot_balance = tuple
		m_dot_pc = tuple
		m_dot_rec = tuple
		m_dot_tes_ch = tuple
		m_dot_tes_dc = tuple
		n_op_modes = tuple
		op_mode_1 = tuple
		op_mode_2 = tuple
		op_mode_3 = tuple
		operating_modes_a = tuple
		operating_modes_b = tuple
		operating_modes_c = tuple
		pparasi = tuple
		pricing_mult = tuple
		q_balance = tuple
		q_ch_tes = tuple
		q_dc_tes = tuple
		q_dot_est_cr_on = tuple
		q_dot_est_cr_su = tuple
		q_dot_est_tes_ch = tuple
		q_dot_est_tes_dc = tuple
		q_dot_pc_max = tuple
		q_dot_pc_min = tuple
		q_dot_pc_sb = tuple
		q_dot_pc_startup = tuple
		q_dot_pc_target = tuple
		q_heater = tuple
		q_pb = tuple
		q_pc_startup = tuple
		solzen = tuple
		tank_losses = tuple
		time_hr = tuple
		tou_value = tuple




def default(config) -> TroughPhysicalCspSolver:
	pass

def new() -> TroughPhysicalCspSolver:
	pass

def wrap(ssc_data_t) -> TroughPhysicalCspSolver:
	pass

def from_existing(model, config="") -> TroughPhysicalCspSolver:
	pass

__loader__ = None 

__spec__ = None
