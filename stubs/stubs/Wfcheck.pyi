class Wfcheck(object):
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

	class WeatherFileChecker(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		input_file = str


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass






def default(config) -> Wfcheck:
	pass

def new() -> Wfcheck:
	pass

def wrap(ssc_data_t) -> Wfcheck:
	pass

def from_existing(model, config="") -> Wfcheck:
	pass

__loader__ = None 

__spec__ = None
