class SCO2PowerCycle(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	I_N_t_des = float
	I_P_high_limit = float
	I_T_mc_in_des = float
	I_T_t_in_des = float
	I_UA_total_des = float
	I_W_dot_net_des = float
	I_eta_mc = float
	I_eta_rc = float
	I_eta_t = float
	I_opt_tol = float
	I_tol = float


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	O_LT_frac_des = float
	O_N_mc_des = float
	O_PR_mc_des = float
	O_P_mc_out_des = float
	O_T_array_des = tuple
	O_eta_thermal_des = float
	O_m_dot_PHX = float
	O_recomp_frac_des = float


class Sco2DesignCycle(object):
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

	SCO2PowerCycle = SCO2PowerCycle
	Outputs = Outputs


def default(config) -> Sco2DesignCycle:
	pass

def new() -> Sco2DesignCycle:
	pass

def wrap(ssc_data_t) -> Sco2DesignCycle:
	pass

def from_existing(model, config="") -> Sco2DesignCycle:
	pass

__loader__ = None 

__spec__ = None
