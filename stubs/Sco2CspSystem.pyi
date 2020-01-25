class SystemDesign(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	T_amb_des = float
	T_htf_hot_des = float
	W_dot_net_des = float
	dT_PHX_hot_approach = float
	dT_mc_approach = float
	design_method = float
	eta_thermal_des = float
	htf = float
	htf_props = tuple
	site_elevation = float


class HeatExchangerDesign(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	HTR_HP_deltaP_des_in = float
	HTR_LP_deltaP_des_in = float
	HTR_UA_des_in = float
	HTR_design_code = float
	HTR_eff_des_in = float
	HTR_min_dT_des_in = float
	HT_recup_eff_max = float
	LTR_HP_deltaP_des_in = float
	LTR_LP_deltaP_des_in = float
	LTR_UA_des_in = float
	LTR_design_code = float
	LTR_eff_des_in = float
	LTR_min_dT_des_in = float
	LT_recup_eff_max = float
	UA_recup_tot_des = float
	cycle_config = float
	des_objective = float
	is_IP_fixed = float
	is_PR_fixed = float
	is_P_high_fixed = float
	is_recomp_ok = float
	min_phx_deltaT = float
	rel_tol = float


class CycleDesign(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	PHX_co2_deltaP_des_in = float
	P_high_limit = float
	deltaP_counterHX_frac = float
	eta_isen_mc = float
	eta_isen_pc = float
	eta_isen_rc = float
	eta_isen_t = float


class PHXDesign(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	dT_PHX_cold_approach = float


class AirCoolerDesign(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	deltaP_cooler_frac = float
	fan_power_frac = float
	is_design_air_cooler = float


class Common(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	is_gen_od_polynomials = float
	od_P_mc_in_sweep = tuple
	od_T_t_in_mode = float
	od_cases = tuple
	od_generate_udpc = tuple
	od_set_control = tuple


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	HTR_HP_T_in_des = float
	HTR_HP_T_in_od = tuple
	HTR_HP_deltaP_des = float
	HTR_HP_deltaP_od = tuple
	HTR_LP_T_out_des = float
	HTR_LP_T_out_od = tuple
	HTR_LP_deltaP_des = float
	HTR_LP_deltaP_od = tuple
	HTR_UA_assigned = float
	HTR_UA_calculated = float
	HTR_cost = float
	HTR_min_dT = float
	HTR_min_dT_od = tuple
	IP_cooler_P_in = float
	IP_cooler_T_in = float
	IP_cooler_UA = float
	IP_cooler_W_dot_fan = float
	IP_cooler_W_dot_fan_od = tuple
	IP_cooler_cost = float
	IP_cooler_m_dot_co2 = float
	IP_cooler_q_dot = float
	LP_cooler_P_in = float
	LP_cooler_T_in = float
	LP_cooler_T_in_od = tuple
	LP_cooler_UA = float
	LP_cooler_W_dot_fan = float
	LP_cooler_W_dot_fan_od = tuple
	LP_cooler_co2_deltaP_des = float
	LP_cooler_co2_deltaP_od = tuple
	LP_cooler_cost = float
	LP_cooler_in_isen_deltah_to_P_mc_out = float
	LP_cooler_in_isen_deltah_to_P_mc_out_od = tuple
	LP_cooler_m_dot_co2 = float
	LP_cooler_q_dot = float
	LP_cooler_rho_in = float
	LP_cooler_rho_in_od = tuple
	LTR_HP_T_out_des = float
	LTR_HP_T_out_od = tuple
	LTR_HP_deltaP_des = float
	LTR_HP_deltaP_od = tuple
	LTR_LP_deltaP_des = float
	LTR_LP_deltaP_od = tuple
	LTR_UA_assigned = float
	LTR_UA_calculated = float
	LTR_cost = float
	LTR_min_dT = float
	LTR_min_dT_od = tuple
	NTU_HTR = float
	NTU_LTR = float
	NTU_PHX = float
	PHX_co2_deltaP_des = float
	PHX_cost = float
	P_co2_PHX_in = float
	P_co2_PHX_in_od = tuple
	P_comp_in = float
	P_comp_in_od = tuple
	P_comp_out = float
	P_mc_data = tuple
	P_mc_out_od = tuple
	P_pc_data = tuple
	P_rc_data = tuple
	P_state_points = tuple
	P_t_data = tuple
	Q_dot_od = tuple
	T_HTR_HP_data = tuple
	T_HTR_LP_data = tuple
	T_LTR_HP_data = tuple
	T_LTR_LP_data = tuple
	T_PHX_data = tuple
	T_amb_od = tuple
	T_co2_PHX_in = float
	T_co2_PHX_in_od = tuple
	T_co2_PHX_out_od = tuple
	T_comp_in = float
	T_htf_cold_des = float
	T_htf_cold_od = tuple
	T_htf_hot_od = tuple
	T_main_cooler_data = tuple
	T_mc_in_od = tuple
	T_pre_cooler_data = tuple
	T_state_points = tuple
	T_turb_in = float
	UA_PHX = float
	W_dot_net_od = tuple
	c_tot_W_dot = float
	c_tot_W_dot_od = tuple
	c_tot_cost = float
	cooler_tot_UA = float
	cooler_tot_W_dot_fan = float
	cooler_tot_W_dot_fan_od = tuple
	cooler_tot_cost = float
	cycle_cost = float
	cycle_spec_cost = float
	cycle_spec_cost_thermal = float
	deltaT_HTF_PHX = float
	deltaT_HTF_PHX_od = tuple
	diff_E_cycle = tuple
	diff_Q_HTR = tuple
	diff_Q_LTR = tuple
	diff_m_dot_od = tuple
	eff_HTR = float
	eff_HTR_od = tuple
	eff_LTR = float
	eff_LTR_od = tuple
	eff_PHX = float
	eta_thermal_calc = float
	eta_thermal_od = tuple
	h_mc_data = tuple
	h_pc_data = tuple
	h_rc_data = tuple
	h_state_points = tuple
	h_t_data = tuple
	m_dot_co2_full = float
	m_dot_co2_full_od = tuple
	m_dot_htf_des = float
	m_dot_htf_fracs = tuple
	mc_D = tuple
	mc_N_des = float
	mc_N_od = tuple
	mc_T_out = float
	mc_T_out_od = tuple
	mc_W_dot = float
	mc_W_dot_od = tuple
	mc_cost = float
	mc_eta_od = tuple
	mc_eta_stages_des = tuple
	mc_eta_stages_od = tuple
	mc_f_bypass_od = tuple
	mc_ideal_spec_work = float
	mc_ideal_spec_work_od = tuple
	mc_m_dot_des = float
	mc_m_dot_od = tuple
	mc_n_stages = float
	mc_phi_des = float
	mc_phi_od = tuple
	mc_phi_surge = float
	mc_psi_des = float
	mc_psi_max_at_N_des = float
	mc_psi_od = tuple
	mc_rho_in = float
	mc_rho_in_od = tuple
	mc_tip_ratio_des = tuple
	mc_tip_ratio_od = tuple
	od_code = tuple
	od_opt_conv_tol = tuple
	od_opt_obj_code = tuple
	pc_D = tuple
	pc_N_des = float
	pc_N_od = tuple
	pc_P_in_des = float
	pc_P_in_od = tuple
	pc_T_in_des = float
	pc_T_in_od = tuple
	pc_W_dot = float
	pc_W_dot_od = tuple
	pc_cost = float
	pc_eta_od = tuple
	pc_eta_stages_des = tuple
	pc_eta_stages_od = tuple
	pc_f_bypass_od = tuple
	pc_ideal_spec_work_des = float
	pc_ideal_spec_work_od = tuple
	pc_m_dot_des = float
	pc_m_dot_od = tuple
	pc_n_stages = float
	pc_phi_des = float
	pc_phi_od = tuple
	pc_phi_surge = float
	pc_rho_in_des = float
	pc_rho_in_od = tuple
	pc_tip_ratio_des = tuple
	pc_tip_ratio_od = tuple
	phx_co2_deltaP_od = tuple
	phx_eff_od = tuple
	q_dot_HTR = float
	q_dot_HTR_od = tuple
	q_dot_LTR = float
	q_dot_LTR_od = tuple
	q_dot_PHX = float
	rc_D = tuple
	rc_N_des = float
	rc_N_od = tuple
	rc_P_in_des = float
	rc_P_in_od = tuple
	rc_P_out_des = float
	rc_P_out_od = tuple
	rc_T_in_des = float
	rc_T_in_od = tuple
	rc_T_out_des = float
	rc_T_out_od = tuple
	rc_W_dot = float
	rc_W_dot_od = tuple
	rc_cost = float
	rc_eta_od = tuple
	rc_eta_stages_des = tuple
	rc_eta_stages_od = tuple
	rc_m_dot_des = float
	rc_m_dot_od = tuple
	rc_n_stages = float
	rc_phi_des = float
	rc_phi_od = tuple
	rc_phi_surge = float
	rc_psi_des = float
	rc_psi_max_at_N_des = float
	rc_psi_od = tuple
	rc_tip_ratio_des = tuple
	rc_tip_ratio_od = tuple
	recomp_frac = float
	recomp_frac_od = tuple
	recup_LTR_UA_frac = float
	recup_total_UA_assigned = float
	recup_total_UA_calculated = float
	recup_total_cost = float
	s_HTR_HP_data = tuple
	s_HTR_LP_data = tuple
	s_LTR_HP_data = tuple
	s_LTR_LP_data = tuple
	s_PHX_data = tuple
	s_main_cooler_data = tuple
	s_pre_cooler_data = tuple
	s_state_points = tuple
	sim_time_od = tuple
	t_D = float
	t_N_des = float
	t_N_od = tuple
	t_P_in_des = float
	t_P_in_od = tuple
	t_P_out_des = float
	t_P_out_od = tuple
	t_T_out_des = float
	t_T_out_od = tuple
	t_W_dot = float
	t_W_dot_od = tuple
	t_cost = float
	t_eta_od = tuple
	t_m_dot_des = float
	t_m_dot_od = tuple
	t_nu_des = float
	t_nu_od = tuple
	t_tip_ratio_des = float
	t_tip_ratio_od = tuple
	udpc_n_T_amb = float
	udpc_n_T_htf = float
	udpc_n_m_dot_htf = float
	udpc_table = tuple


class Sco2CspSystem(object):
	def assign(self, dict):
		pass

	def value(self, name, value=None):
		pass

	def execute(self, int_verbosity):
		pass

	def export(self):
		pass

	def __getattribute__(self, *args, **kwargs):
		pass

	def __init__(self, *args, **kwargs):
		pass

	SystemDesign = SystemDesign
	HeatExchangerDesign = HeatExchangerDesign
	CycleDesign = CycleDesign
	PHXDesign = PHXDesign
	AirCoolerDesign = AirCoolerDesign
	Common = Common
	Outputs = Outputs


def default(config) -> Sco2CspSystem
	pass

def new() -> Sco2CspSystem
	pass

def wrap(ssc_data_t) -> Sco2CspSystem
	pass

def from_existing(model, config="") -> Sco2CspSystem
	pass

__loader__ = None 

__spec__ = None
