class Lcoefcr(object):
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

	class SimpleLCOE(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		annual_energy = float
		capital_cost = float
		fixed_charge_rate = float
		fixed_operating_cost = float
		variable_operating_cost = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		lcoe_fcr = float




def default(config) -> Lcoefcr:
	pass

def new() -> Lcoefcr:
	pass

def wrap(ssc_data_t) -> Lcoefcr:
	pass

def from_existing(model, config="") -> Lcoefcr:
	pass

__loader__ = None 

__spec__ = None
