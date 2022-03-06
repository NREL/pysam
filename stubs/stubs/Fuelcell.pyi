class Fuelcell(object):
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

	class Lifetime(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		analysis_period = float
		system_use_lifetime_output = float


	class Common(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		annual_energy = float
		capacity_factor = float
		gen = tuple


	class Load(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		load = tuple


	class FuelCell(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		dispatch_manual_fuelcellcharge = tuple
		dispatch_manual_fuelcelldischarge = tuple
		dispatch_manual_percent_fc_discharge = tuple
		dispatch_manual_sched = tuple
		dispatch_manual_sched_weekend = tuple
		dispatch_manual_units_fc_discharge = tuple
		fuelcell_availability_schedule = tuple
		fuelcell_degradation = float
		fuelcell_degradation_restart = float
		fuelcell_degradation_restart_schedule = float
		fuelcell_degradation_restarts_per_year = float
		fuelcell_dispatch = tuple
		fuelcell_dispatch_choice = float
		fuelcell_dynamic_response_down = float
		fuelcell_dynamic_response_up = float
		fuelcell_efficiency = tuple
		fuelcell_efficiency_choice = float
		fuelcell_fixed_pct = float
		fuelcell_fuel_available = float
		fuelcell_fuel_price = float
		fuelcell_fuel_type = float
		fuelcell_is_started = float
		fuelcell_lhv = float
		fuelcell_number_of_units = float
		fuelcell_operation_options = float
		fuelcell_replacement_option = float
		fuelcell_replacement_percent = float
		fuelcell_replacement_schedule = tuple
		fuelcell_shutdown_time = float
		fuelcell_startup_time = float
		fuelcell_type = float
		fuelcell_unit_max_power = float
		fuelcell_unit_min_power = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		annual_energy_distribution_time = tuple
		annual_energy_distribution_time_fc = tuple
		annual_fuel_usage = float
		annual_fuel_usage_lifetime = tuple
		fuelcell_annual_energy_discharged = tuple
		fuelcell_electrical_efficiency = tuple
		fuelcell_fuel_consumption_mcf = tuple
		fuelcell_percent_load = tuple
		fuelcell_power = tuple
		fuelcell_power_max_percent = tuple
		fuelcell_power_thermal = tuple
		fuelcell_replacement = tuple
		fuelcell_to_grid = tuple
		fuelcell_to_load = tuple
		gen = tuple
		system_heat_rate = float




def default(config) -> Fuelcell:
	pass

def new() -> Fuelcell:
	pass

def wrap(ssc_data_t) -> Fuelcell:
	pass

def from_existing(model, config="") -> Fuelcell:
	pass

__loader__ = None 

__spec__ = None
