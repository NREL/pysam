class Wfcsvconv(object):
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

	class WeatherFileConverter(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		input_file = str
		output_file = str
		output_filename_format = str
		output_folder = str


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass






def default(config) -> Wfcsvconv:
	pass

def new() -> Wfcsvconv:
	pass

def wrap(ssc_data_t) -> Wfcsvconv:
	pass

def from_existing(model, config="") -> Wfcsvconv:
	pass

__loader__ = None 

__spec__ = None
