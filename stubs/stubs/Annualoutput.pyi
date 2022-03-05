class Annualoutput(object):
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

	class AnnualOutput(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		analysis_period = float
		energy_availability = tuple
		energy_curtailment = tuple
		energy_degradation = tuple
		system_hourly_energy = tuple
		system_use_lifetime_output = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		annual_availability = tuple
		annual_degradation = tuple
		annual_energy = tuple
		hourly_energy = tuple
		monthly_energy = tuple




def default(config) -> Annualoutput:
	pass

def new() -> Annualoutput:
	pass

def wrap(ssc_data_t) -> Annualoutput:
	pass

def from_existing(model, config="") -> Annualoutput:
	pass

__loader__ = None 

__spec__ = None
