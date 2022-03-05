class Sco2CspUdPcTables(object):
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

	class SystemDesign(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
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
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		HTR_HP_deltaP_des_in = float
		HTR_LP_deltaP_des_in = float
		HTR_UA_des_in = float
		HTR_design_code = float
		HTR_eff_des_in = float
		HTR_min_dT_des_in = float
		HTR_n_sub_hx = float
		HTR_od_model = float
		HT_recup_eff_max = float
		LTR_HP_deltaP_des_in = float
		LTR_LP_deltaP_des_in = float
		LTR_UA_des_in = float
		LTR_design_code = float
		LTR_eff_des_in = float
		LTR_min_dT_des_in = float
		LTR_n_sub_hx = float
		LTR_od_model = float
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


	class Common(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		PHX_co2_deltaP_des_in = float
		P_high_limit = float
		T_amb_high = float
		T_amb_low = float
		T_htf_hot_high = float
		T_htf_hot_low = float
		deltaP_counterHX_frac = float
		eta_isen_mc = float
		eta_isen_pc = float
		eta_isen_rc = float
		eta_isen_t = float
		is_apply_default_htf_mins = float
		is_generate_udpc = float
		m_dot_htf_ND_high = float
		m_dot_htf_ND_low = float
		mc_comp_type = float
		n_T_amb = float
		n_T_htf_hot = float
		n_m_dot_htf_ND = float


	class PHXDesign(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		PHX_n_sub_hx = float
		PHX_od_model = float
		dT_PHX_cold_approach = float


	class AirCoolerDesign(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		N_nodes_air_cooler_pass = float
		deltaP_cooler_frac = float
		eta_air_cooler_fan = float
		fan_power_frac = float
		is_design_air_cooler = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		HTR_HP_T_in_des = float
		HTR_HP_deltaP_des = float
		HTR_LP_T_out_des = float
		HTR_LP_deltaP_des = float
		HTR_UA_assigned = float
		HTR_UA_calculated = float
		HTR_cost = float
		HTR_min_dT = float
		LTR_HP_T_out_des = float
		LTR_HP_deltaP_des = float
		LTR_LP_deltaP_des = float
		LTR_UA_assigned = float
		LTR_UA_calculated = float
		LTR_cost = float
		LTR_min_dT = float
		NTU_HTR = float
		NTU_LTR = float
		NTU_PHX = float
		PHX_co2_deltaP_des = float
		PHX_cost = float
		P_co2_PHX_in = float
		P_comp_in = float
		P_comp_out = float
		P_mc_data = tuple
		P_pc_data = tuple
		P_rc_data = tuple
		P_state_points = tuple
		P_t_data = tuple
		T_HTR_HP_data = tuple
		T_HTR_LP_data = tuple
		T_LTR_HP_data = tuple
		T_LTR_LP_data = tuple
		T_PHX_data = tuple
		T_amb_ind = tuple
		T_co2_PHX_in = float
		T_comp_in = float
		T_htf_cold_des = float
		T_htf_ind = tuple
		T_main_cooler_data = tuple
		T_pre_cooler_data = tuple
		T_state_points = tuple
		T_turb_in = float
		UA_PHX = float
		W_dot_net_less_cooling = float
		c_tot_W_dot = float
		c_tot_cost = float
		cooler_tot_UA = float
		cooler_tot_W_dot_fan = float
		cooler_tot_cost = float
		cycle_cost = float
		cycle_spec_cost = float
		cycle_spec_cost_thermal = float
		deltaT_HTF_PHX = float
		eff_HTR = float
		eff_LTR = float
		eff_PHX = float
		eta_thermal_calc = float
		eta_thermal_net_less_cooling_des = float
		h_mc_data = tuple
		h_pc_data = tuple
		h_rc_data = tuple
		h_state_points = tuple
		h_t_data = tuple
		m_dot_co2_full = float
		m_dot_htf_ND_ind = tuple
		m_dot_htf_des = float
		mc_D = tuple
		mc_N_des = float
		mc_T_out = float
		mc_W_dot = float
		mc_cooler_P_in = float
		mc_cooler_T_in = float
		mc_cooler_UA = float
		mc_cooler_W_dot_fan = float
		mc_cooler_co2_deltaP_des = float
		mc_cooler_cost = float
		mc_cooler_in_isen_deltah_to_P_mc_out = float
		mc_cooler_m_dot_co2 = float
		mc_cooler_q_dot = float
		mc_cooler_rho_in = float
		mc_cost = float
		mc_eta_stages_des = tuple
		mc_ideal_spec_work = float
		mc_m_dot_des = float
		mc_n_stages = float
		mc_phi_des = float
		mc_phi_surge = float
		mc_psi_des = float
		mc_psi_max_at_N_des = float
		mc_rho_in = float
		mc_tip_ratio_des = tuple
		pc_D = tuple
		pc_N_des = float
		pc_P_in_des = float
		pc_T_in_des = float
		pc_W_dot = float
		pc_cooler_P_in = float
		pc_cooler_T_in = float
		pc_cooler_UA = float
		pc_cooler_W_dot_fan = float
		pc_cooler_cost = float
		pc_cooler_m_dot_co2 = float
		pc_cooler_q_dot = float
		pc_cost = float
		pc_eta_stages_des = tuple
		pc_ideal_spec_work_des = float
		pc_m_dot_des = float
		pc_n_stages = float
		pc_phi_des = float
		pc_phi_surge = float
		pc_rho_in_des = float
		pc_tip_ratio_des = tuple
		q_dot_HTR = float
		q_dot_LTR = float
		q_dot_PHX = float
		rc_D = tuple
		rc_N_des = float
		rc_P_in_des = float
		rc_P_out_des = float
		rc_T_in_des = float
		rc_T_out_des = float
		rc_W_dot = float
		rc_cost = float
		rc_eta_stages_des = tuple
		rc_m_dot_des = float
		rc_n_stages = float
		rc_phi_des = float
		rc_phi_surge = float
		rc_psi_des = float
		rc_psi_max_at_N_des = float
		rc_tip_ratio_des = tuple
		recomp_frac = float
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
		t_D = float
		t_N_des = float
		t_P_in_des = float
		t_P_out_des = float
		t_T_out_des = float
		t_W_dot = float
		t_cost = float
		t_delta_h_isen_des = float
		t_m_dot_des = float
		t_nu_des = float
		t_rho_in_des = float
		t_tip_ratio_des = float




def default(config) -> Sco2CspUdPcTables:
	pass

def new() -> Sco2CspUdPcTables:
	pass

def wrap(ssc_data_t) -> Sco2CspUdPcTables:
	pass

def from_existing(model, config="") -> Sco2CspUdPcTables:
	pass

__loader__ = None 

__spec__ = None
