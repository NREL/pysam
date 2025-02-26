class Thermalrate(object):
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

	class ThermalRate(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		en_thermal_rates = float
		fuelcell_power_thermal = tuple
		thermal_buy_rate = tuple
		thermal_buy_rate_flat = float
		thermal_buy_rate_option = float
		thermal_degradation = tuple
		thermal_load = tuple
		thermal_load_escalation = tuple
		thermal_rate_escalation = tuple
		thermal_sell_rate = tuple
		thermal_sell_rate_flat = float
		thermal_sell_rate_option = float


	class Lifetime(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		analysis_period = float
		inflation_rate = float
		system_use_lifetime_output = float


	class HybridCosts(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		degradation = tuple
		land_area = float
		om_capacity = tuple
		om_capacity_escal = float
		om_fixed = tuple
		om_fixed_escal = float
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


		annual_thermal_value = tuple
		cf_land_lease_expense = tuple
		thermal_cost_with_system = tuple
		thermal_cost_with_system_year1 = float
		thermal_cost_without_system = tuple
		thermal_cost_without_system_year1 = float
		thermal_load_year1 = float
		thermal_revenue_with_system = tuple
		thermal_revenue_without_system = tuple
		thermal_savings_year1 = float




def default(config) -> Thermalrate:
	pass

def new() -> Thermalrate:
	pass

def wrap(ssc_data_t) -> Thermalrate:
	pass

def from_existing(model, config="") -> Thermalrate:
	pass

__loader__ = None 

__spec__ = None
