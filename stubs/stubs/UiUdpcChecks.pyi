class UserDefinedPowerCycle(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	ud_ind_od = tuple


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	T_amb_des = float
	T_amb_high = float
	T_amb_low = float
	T_htf_des = float
	T_htf_high = float
	T_htf_low = float
	m_dot_des = float
	m_dot_high = float
	m_dot_low = float
	n_T_amb_pars = float
	n_T_htf_pars = float
	n_m_dot_pars = float


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

	def __getattribute__(self, *args, **kwargs):
		pass

	def __init__(self, *args, **kwargs):
		pass

	UserDefinedPowerCycle = UserDefinedPowerCycle
	Outputs = Outputs


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
