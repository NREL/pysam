class Lifetime(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	analysis_period = float
	system_use_lifetime_output = float


class Grid(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	enable_interconnection_limit = float
	grid_curtailment = tuple
	grid_interconnection_limit_kwac = float


class SystemOutput(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	annual_energy = float
	gen = tuple


class Load(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	load = tuple


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	annual_ac_curtailment_loss_kwh = float
	annual_ac_curtailment_loss_percent = float
	annual_ac_interconnect_loss_kwh = float
	annual_ac_interconnect_loss_percent = float
	annual_energy_pre_curtailment_ac = float
	annual_energy_pre_interconnect_ac = float
	capacity_factor_curtailment_ac = float
	capacity_factor_interconnect_ac = float
	gen = tuple
	system_pre_curtailment_kwac = tuple
	system_pre_interconnect_kwac = tuple


class GridModel(object):
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
	Grid = Grid
	SystemOutput = SystemOutput
	Load = Load
	Outputs = Outputs


def default(config) -> GridModel
	pass

def new() -> GridModel
	pass

def wrap(ssc_data_t) -> GridModel
	pass

__loader__ = None 

__spec__ = None
