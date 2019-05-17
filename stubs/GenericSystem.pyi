class Plant(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	conv_eff = float
	derate = float
	energy_output_array = tuple
	heat_rate = float
	spec_mode = float
	system_capacity = float
	user_capacity_factor = float


class Lifetime(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	analysis_period = float
	generic_degradation = tuple
	system_use_lifetime_output = float


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	annual_energy = float
	annual_fuel_usage = float
	capacity_factor = float
	gen = tuple
	kwh_per_kw = float
	monthly_energy = tuple
	system_heat_rate = float
	water_usage = float


class GenericSystem(object):
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

	Plant = Plant
	Lifetime = Lifetime
	Outputs = Outputs


def default(config) -> GenericSystem
	pass

def new() -> GenericSystem
	pass

def wrap(ssc_data_t) -> GenericSystem
	pass

__loader__ = None 

__spec__ = None
