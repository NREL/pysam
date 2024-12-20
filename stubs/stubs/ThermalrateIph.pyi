class ThermalrateIph(object):
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
		gen_heat = tuple
		thermal_buy_rate_flat_heat_btu = float
		thermal_buy_rate_option = float
		thermal_conversion_efficiency = float
		thermal_degradation = tuple
		thermal_load_escalation = tuple
		thermal_load_heat_btu = tuple
		thermal_monthly_buy_rate_heat_btu = tuple
		thermal_monthly_sell_rate_heat_btu = tuple
		thermal_rate_escalation = tuple
		thermal_sell_rate_flat_heat_btu = float
		thermal_sell_rate_option = float
		thermal_timestep_buy_rate_heat_btu = tuple
		thermal_timestep_sell_rate_heat_btu = tuple


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


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		annual_thermal_value = tuple
		thermal_cost_with_system = tuple
		thermal_cost_with_system_year1 = float
		thermal_cost_without_system = tuple
		thermal_cost_without_system_year1 = float
		thermal_load_year1 = float
		thermal_revenue_with_system = tuple
		thermal_revenue_without_system = tuple
		thermal_savings_year1 = float
		year1_monthly_load_heat = tuple




def default(config) -> ThermalrateIph:
	pass

def new() -> ThermalrateIph:
	pass

def wrap(ssc_data_t) -> ThermalrateIph:
	pass

def from_existing(model, config="") -> ThermalrateIph:
	pass

__loader__ = None 

__spec__ = None
