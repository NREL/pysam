class IphToLcoefcr(object):
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

	class IPHLCOH(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		annual_electricity_consumption = float
		electricity_rate = float


	class SimpleLCOE(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		fixed_operating_cost = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass






def default(config) -> IphToLcoefcr:
	pass

def new() -> IphToLcoefcr:
	pass

def wrap(ssc_data_t) -> IphToLcoefcr:
	pass

def from_existing(model, config="") -> IphToLcoefcr:
	pass

__loader__ = None 

__spec__ = None
