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

	def get_data_ptr(self):
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


		dispatch_manual_fuelcell_sched = tuple
		dispatch_manual_fuelcell_sched_weekend = tuple
		dispatch_manual_fuelcellcharge = tuple
		dispatch_manual_fuelcelldischarge = tuple
		dispatch_manual_percent_fc_discharge = tuple
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


	class HybridCosts(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		add_om_num_types = float
		degradation = tuple
		land_area = float
		om_capacity_escal = float
		om_fixed_escal = float
		om_fuel_cost = tuple
		om_fuel_cost_escal = float
		om_fuelcell_capacity_cost = tuple
		om_fuelcell_fixed_cost = tuple
		om_fuelcell_nameplate = float
		om_fuelcell_replacement_cost = tuple
		om_fuelcell_variable_cost = tuple
		om_land_lease = tuple
		om_land_lease_escal = float
		om_production2_values = tuple
		om_production_escal = float
		om_replacement_cost_escal = float
		total_installed_cost = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		annual_energy_discharged = float
		annual_energy_distribution_time = tuple
		annual_energy_distribution_time_fc = tuple
		annual_fuel_usage = float
		annual_fuel_usage_lifetime = tuple
		cf_battery_replacement_cost_schedule = tuple
		cf_energy_net = tuple
		cf_fuelcell_replacement_cost_schedule = tuple
		cf_land_lease_expense = tuple
		cf_om_capacity = tuple
		cf_om_fixed = tuple
		cf_om_fuel_cost = tuple
		cf_om_land_lease = tuple
		cf_om_production = tuple
		fuelcell_annual_energy_discharged = tuple
		fuelcell_electrical_efficiency = tuple
		fuelcell_fuel_consumption_mcf = tuple
		fuelcell_monthly_energy_discharged = tuple
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
