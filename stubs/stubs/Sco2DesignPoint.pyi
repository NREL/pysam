class Common(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	P_high_limit = float
	T_amb_array = tuple
	T_amb_des = float
	T_htf_hot_des = float
	W_dot_net_des = float
	deltaT_ACC = float
	deltaT_PHX = float
	eta_c = float
	eta_des = float
	eta_t = float
	part_load_fracs = tuple
	run_off_des_study = float


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	P_comp_in = float
	P_comp_out = float
	T_amb_array_out = tuple
	T_amb_coefs = tuple
	T_amb_eta = tuple
	T_amb_r_squared = float
	T_htf_cold = float
	UA_total = float
	eta_thermal_calc = float
	part_load_coefs = tuple
	part_load_eta = tuple
	part_load_fracs_out = tuple
	part_load_r_squared = float
	recomp_frac = float


class Sco2DesignPoint(object):
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

	Common = Common
	Outputs = Outputs


def default(config) -> Sco2DesignPoint:
	pass

def new() -> Sco2DesignPoint:
	pass

def wrap(ssc_data_t) -> Sco2DesignPoint:
	pass

def from_existing(model, config="") -> Sco2DesignPoint:
	pass

__loader__ = None 

__spec__ = None
