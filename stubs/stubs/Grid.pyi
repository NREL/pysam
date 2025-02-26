class Grid(object):
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


	class SystemOutput(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		annual_energy = float
		energy_hourly_kW = tuple
		gen = tuple


	class Load(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		crit_load = tuple
		grid_outage = tuple
		load = tuple
		load_escalation = tuple


	class Monthly(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		monthly_energy = tuple


	class GridLimits(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		enable_interconnection_limit = float
		grid_curtailment = tuple
		grid_interconnection_limit_kwac = float


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


		annual_ac_curtailment_loss_kwh = float
		annual_ac_curtailment_loss_percent = float
		annual_ac_interconnect_loss_kwh = float
		annual_ac_interconnect_loss_percent = float
		annual_energy_distribution_time = tuple
		annual_energy_pre_curtailment_ac = float
		annual_energy_pre_interconnect_ac = float
		capacity_factor_curtailment_ac = float
		capacity_factor_interconnect_ac = float
		cf_land_lease_expense = tuple
		full_load = tuple
		gen = tuple
		system_pre_curtailment_kwac = tuple
		system_pre_interconnect_kwac = tuple




def default(config) -> Grid:
	pass

def new() -> Grid:
	pass

def wrap(ssc_data_t) -> Grid:
	pass

def from_existing(model, config="") -> Grid:
	pass

__loader__ = None 

__spec__ = None
