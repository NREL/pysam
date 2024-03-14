class UiUdpcChecks(object):
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

	class UserDefinedPowerCycle(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		ud_ind_od = tuple


	class Common(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		T_htf_cold_des = float
		T_htf_des_in = float
		cooler_tot_W_dot_fan = float
		is_calc_m_dot_vs_T_amb = float


	class SystemDesign(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		W_dot_net_des = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		Q_dot_HTF_ND_des = float
		T_amb_HT = float
		T_amb_LT = float
		T_amb_des = float
		T_amb_high = float
		T_amb_low = float
		T_amb_pars = tuple
		T_amb_sweep = tuple
		T_htf_des = float
		T_htf_high = float
		T_htf_low = float
		T_htf_pars = tuple
		W_dot_ND_regr_vs_T_amb__T_HTF_low_level = tuple
		W_dot_ND_regr_vs_m_dot__T_amb_HT = tuple
		W_dot_ND_regr_vs_m_dot__T_amb_LT = tuple
		W_dot_ND_regr_vs_m_dot__T_amb_design = tuple
		W_dot_ND_regr_vs_m_dot__T_amb_high_level = tuple
		W_dot_ND_regr_vs_m_dot__T_amb_low_level = tuple
		W_dot_ND_vs_m_dot__T_amb_HT = tuple
		W_dot_ND_vs_m_dot__T_amb_LT = tuple
		W_dot_cooling_ND_des = float
		W_dot_gross_ND_des = float
		W_dot_htf_ND_max_at_T_amb_HT_regr = float
		W_dot_htf_ND_max_at_T_amb_HT_rule0 = float
		W_dot_htf_ND_max_at_T_amb_LT_regr = float
		W_dot_htf_ND_max_at_T_amb_LT_rule0 = float
		W_dot_htf_ND_max_at_T_amb_design_regr = float
		W_dot_htf_ND_max_at_T_amb_design_rule0 = float
		W_dot_htf_ND_max_at_T_amb_high_level_regr = float
		W_dot_htf_ND_max_at_T_amb_high_level_rule0 = float
		W_dot_htf_ND_max_at_T_amb_low_level_regr = float
		W_dot_htf_ND_max_at_T_amb_low_level_rule0 = float
		eta_ND_max_at_T_amb_HT_regr = float
		eta_ND_max_at_T_amb_HT_rule0 = float
		eta_ND_max_at_T_amb_LT_regr = float
		eta_ND_max_at_T_amb_LT_rule0 = float
		eta_ND_max_at_T_amb_design_regr = float
		eta_ND_max_at_T_amb_design_rule0 = float
		eta_ND_max_at_T_amb_high_level_regr = float
		eta_ND_max_at_T_amb_high_level_rule0 = float
		eta_ND_max_at_T_amb_low_level_regr = float
		eta_ND_max_at_T_amb_low_level_rule0 = float
		eta_ND_regr_vs_T_amb__T_HTF_low_level = tuple
		eta_ND_regr_vs_m_dot__T_amb_HT = tuple
		eta_ND_regr_vs_m_dot__T_amb_LT = tuple
		eta_ND_regr_vs_m_dot__T_amb_design = tuple
		eta_ND_regr_vs_m_dot__T_amb_high_level = tuple
		eta_ND_regr_vs_m_dot__T_amb_low_level = tuple
		eta_ND_vs_m_dot__T_amb_HT = tuple
		eta_ND_vs_m_dot__T_amb_LT = tuple
		m_dot_des = float
		m_dot_high = float
		m_dot_htf_ND_max_at_T_amb_HT_regr = float
		m_dot_htf_ND_max_at_T_amb_HT_rule0 = float
		m_dot_htf_ND_max_at_T_amb_LT_regr = float
		m_dot_htf_ND_max_at_T_amb_LT_rule0 = float
		m_dot_htf_ND_max_at_T_amb_design_regr = float
		m_dot_htf_ND_max_at_T_amb_design_rule0 = float
		m_dot_htf_ND_max_at_T_amb_high_level_regr = float
		m_dot_htf_ND_max_at_T_amb_high_level_rule0 = float
		m_dot_htf_ND_max_at_T_amb_low_level_regr = float
		m_dot_htf_ND_max_at_T_amb_low_level_rule0 = float
		m_dot_htf_ND_max_vs_T_amb_rule0 = tuple
		m_dot_low = float
		m_dot_pars = tuple
		m_dot_water_ND_des = float
		n_T_amb_pars = float
		n_T_htf_pars = float
		n_m_dot_pars = float
		q_dot_ND_regr_vs_T_amb__T_HTF_low_level = tuple
		q_dot_ND_regr_vs_m_dot__T_amb_HT = tuple
		q_dot_ND_regr_vs_m_dot__T_amb_LT = tuple
		q_dot_ND_regr_vs_m_dot__T_amb_design = tuple
		q_dot_ND_regr_vs_m_dot__T_amb_high_level = tuple
		q_dot_ND_regr_vs_m_dot__T_amb_low_level = tuple
		q_dot_ND_vs_m_dot__T_amb_HT = tuple
		q_dot_ND_vs_m_dot__T_amb_LT = tuple
		q_dot_htf_ND_max_at_T_amb_HT_regr = float
		q_dot_htf_ND_max_at_T_amb_HT_rule0 = float
		q_dot_htf_ND_max_at_T_amb_LT_regr = float
		q_dot_htf_ND_max_at_T_amb_LT_rule0 = float
		q_dot_htf_ND_max_at_T_amb_design_regr = float
		q_dot_htf_ND_max_at_T_amb_design_rule0 = float
		q_dot_htf_ND_max_at_T_amb_high_level_regr = float
		q_dot_htf_ND_max_at_T_amb_high_level_rule0 = float
		q_dot_htf_ND_max_at_T_amb_low_level_regr = float
		q_dot_htf_ND_max_at_T_amb_low_level_rule0 = float




def default(config) -> UiUdpcChecks:
	pass

def new() -> UiUdpcChecks:
	pass

def wrap(ssc_data_t) -> UiUdpcChecks:
	pass

def from_existing(model, config="") -> UiUdpcChecks:
	pass

__loader__ = None 

__spec__ = None
