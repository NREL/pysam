class Snowmodel(object):
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

	class PVSnowModel(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		snowdepth = tuple
		subarray1_nmody = float
		subarray1_poa_shaded = tuple
		subarray1_surf_tilt = tuple
		subarray1_tilt = float
		subarray1_track_mode = float
		tdry = tuple
		wspd = tuple


	class TimeSeries(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		hourly_gen = tuple
		sunup = tuple


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		annual_energy = float
		annual_energy_before_snow = float
		hourly_energy_before_snow = tuple
		hourly_gen = tuple
		monthly_energy = tuple
		monthly_energy_before_snow = tuple




def default(config) -> Snowmodel:
	pass

def new() -> Snowmodel:
	pass

def wrap(ssc_data_t) -> Snowmodel:
	pass

def from_existing(model, config="") -> Snowmodel:
	pass

__loader__ = None 

__spec__ = None
