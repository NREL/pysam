class GenericSystem(object):
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

	class Plant(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
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
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		analysis_period = float
		generic_degradation = tuple
		system_use_lifetime_output = float


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


		annual_energy = float
		annual_energy_distribution_time = tuple
		annual_fuel_usage = float
		capacity_factor = float
		gen = tuple
		kwh_per_kw = float
		monthly_energy = tuple
		system_heat_rate = float
		water_usage = float




def default(config) -> GenericSystem:
	pass

def new() -> GenericSystem:
	pass

def wrap(ssc_data_t) -> GenericSystem:
	pass

def from_existing(model, config="") -> GenericSystem:
	pass

__loader__ = None 

__spec__ = None
