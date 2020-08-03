class WeatherReader(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	file_name = str
	header_only = float


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	albedo = tuple
	annual_albedo = float
	annual_beam = float
	annual_diffuse = float
	annual_global = float
	annual_snow = float
	annual_tdry = float
	annual_wspd = float
	beam = tuple
	city = str
	country = str
	day = tuple
	description = str
	diffuse = tuple
	elev = float
	format = str
	global = tuple
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


class Wfreader(object):
	def assign(self, dict):
		pass

	def value(self, name, value=None):
		pass

	def execute(self, int_verbosity):
		pass

	def export(self):
		pass

	def __getattribute__(self, *args, **kwargs):
		pass

	def __init__(self, *args, **kwargs):
		pass

	WeatherReader = WeatherReader
	Outputs = Outputs


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
