class TidalFileReader(object):
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

	class WeatherReader(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		tidal_resource_filename = str
		tidal_resource_model_choice = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		average_power_flux = float
		bathymetry = str
		city = str
		country = str
		data_source = str
		day = tuple
		distance_to_shore_file = float
		hour = tuple
		lat = float
		location = str
		location_id = str
		lon = float
		minute = tuple
		month = tuple
		name = str
		nearby_buoy_number = str
		notes = str
		number_hours = float
		number_records = float
		sea_bed = str
		significant_wave_height = tuple
		state = str
		tidal_velocity = tuple
		tz = float
		water_depth_file = float
		year = tuple




def default(config) -> TidalFileReader:
	pass

def new() -> TidalFileReader:
	pass

def wrap(ssc_data_t) -> TidalFileReader:
	pass

def from_existing(model, config="") -> TidalFileReader:
	pass

__loader__ = None 

__spec__ = None
