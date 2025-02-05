class CustomGeneration(object):
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
	
		adjust_constant = float
		adjust_en_hourly = float
		adjust_en_periods = float
		adjust_en_timeindex = float
		adjust_hourly = tuple
		adjust_periods = tuple
		adjust_timeindex = tuple
		dc_adjust_constant = float
		dc_adjust_en_hourly = float
		dc_adjust_en_periods = float
		dc_adjust_en_timeindex = float
		dc_adjust_hourly = tuple
		dc_adjust_periods = tuple
		dc_adjust_timeindex = tuple
		sf_adjust_constant = float
		sf_adjust_en_hourly = float
		sf_adjust_en_periods = float
		sf_adjust_en_timeindex = float
		sf_adjust_hourly = tuple
		sf_adjust_periods = tuple
		sf_adjust_timeindex = tuple

	class HybridCosts(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		annual_fuel_usage_lifetime = tuple
		degradation = tuple
		land_area = float
		om_capacity = tuple
		om_capacity_escal = float
		om_fixed = tuple
		om_fixed_escal = float
		om_fuel_cost = tuple
		om_fuel_cost_escal = float
		om_land_lease = tuple
		om_land_lease_escal = float
		om_production = tuple
		om_production_escal = float
		total_installed_cost = float


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
		cf_battery_replacement_cost_schedule = tuple
		cf_energy_net = tuple
		cf_fuelcell_replacement_cost_schedule = tuple
		cf_land_lease_expense = tuple
		cf_om_capacity = tuple
		cf_om_fixed = tuple
		cf_om_fuel_cost = tuple
		cf_om_land_lease = tuple
		cf_om_production = tuple
		gen = tuple
		kwh_per_kw = float
		monthly_energy = tuple
		system_heat_rate = float
		water_usage = float




def default(config) -> CustomGeneration:
	pass

def new() -> CustomGeneration:
	pass

def wrap(ssc_data_t) -> CustomGeneration:
	pass

def from_existing(model, config="") -> CustomGeneration:
	pass

__loader__ = None 

__spec__ = None
