class Wfreader(object):
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

	class WeatherReader(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		file_name = str
		header_only = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		albedo = tuple
		annual_albedo = float
		annual_beam = float
		annual_diff = float
		annual_glob = float
		annual_snow = float
		annual_tdry = float
		annual_wspd = float
		beam = tuple
		city = str
		country = str
		day = tuple
		description = str
		diff = tuple
		elev = float
		format = str
		glob = tuple
		hour = tuple
		lat = float
		location = str
		lon = float
		minute = tuple
		month = tuple
		nrecords = float
		poa = tuple
		pres = tuple
		rhum = tuple
		snow = tuple
		source = str
		start = float
		state = str
		step = float
		tdew = tuple
		tdry = tuple
		twet = tuple
		tz = float
		url = str
		wdir = tuple
		wspd = tuple
		year = tuple




def default(config) -> Wfreader:
	pass

def new() -> Wfreader:
	pass

def wrap(ssc_data_t) -> Wfreader:
	pass

def from_existing(model, config="") -> Wfreader:
	pass

__loader__ = None 

__spec__ = None
