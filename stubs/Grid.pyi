class Lifetime(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	analysis_period = float
	system_use_lifetime_output = float


class Common(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	enable_interconnection_limit = float
	gen = tuple
	grid_interconnection_limit_kwac = float
	load = tuple


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	annual_ac_interconnect_loss_kwh = float
	annual_ac_interconnect_loss_percent = float
	annual_energy = float
	annual_energy_pre_interconnect_ac = float
	capacity_factor_interconnect_ac = float
	gen = tuple
	system_pre_interconnect_kwac = tuple


class Grid(object):
	def assign(self, dict):
		pass

	def execute(self, int_verbosity):
		pass

	def export(self):
		pass

	def __getattribute__(self, *args, **kwargs):
		pass

	def __init__(self, *args, **kwargs):
		pass

	Lifetime = Lifetime
	Common = Common
	Outputs = Outputs


def default(config) -> Grid
	pass

def new() -> Grid
	pass

def wrap(ssc_data_t) -> Grid
	pass

__loader__ = None 

__spec__ = None
