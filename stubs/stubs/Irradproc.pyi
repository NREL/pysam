class Irradproc(object):
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

	class IrradianceProcessor(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		albedo = tuple
		albedo_const = float
		azimuth = float
		backtrack = float
		beam = tuple
		day = tuple
		diff = tuple
		elevation = float
		gcr = float
		glob = tuple
		hour = tuple
		irrad_mode = float
		lat = float
		lon = float
		minute = tuple
		month = tuple
		pressure = float
		rotlim = float
		sky_model = float
		slope_azm = float
		slope_tilt = float
		tamb = float
		tilt = float
		track_mode = float
		tz = float
		year = tuple


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		axis_rotation = tuple
		bt_diff = tuple
		incidence = tuple
		poa_beam = tuple
		poa_gnddiff = tuple
		poa_skydiff = tuple
		poa_skydiff_cir = tuple
		poa_skydiff_hor = tuple
		poa_skydiff_iso = tuple
		sun_azm = tuple
		sun_dec = tuple
		sun_elv = tuple
		sun_zen = tuple
		surf_azm = tuple
		surf_tilt = tuple




def default(config) -> Irradproc:
	pass

def new() -> Irradproc:
	pass

def wrap(ssc_data_t) -> Irradproc:
	pass

def from_existing(model, config="") -> Irradproc:
	pass

__loader__ = None 

__spec__ = None
