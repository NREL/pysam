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
