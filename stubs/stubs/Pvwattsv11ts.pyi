class Pvwattsv11ts(object):
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

	class PVWatts(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		azimuth = float
		beam = float
		day = float
		derate = float
		diffuse = float
		elevation = float
		fd = float
		gamma = float
		hour = float
		i_ref = float
		inv_eff = float
		lat = float
		lon = float
		minute = float
		month = float
		poa = float
		poa_cutin = float
		pressure = float
		rotlim = float
		snow = float
		system_size = float
		t_noct = float
		t_ref = float
		tamb = float
		tcell = float
		tilt = float
		time_step = float
		track_mode = float
		tz = float
		w_stow = float
		wspd = float
		year = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		ac = float
		dc = float




def default(config) -> Pvwattsv11ts:
	pass

def new() -> Pvwattsv11ts:
	pass

def wrap(ssc_data_t) -> Pvwattsv11ts:
	pass

def from_existing(model, config="") -> Pvwattsv11ts:
	pass

__loader__ = None 

__spec__ = None
