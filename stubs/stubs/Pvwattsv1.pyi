class Pvwattsv1(object):
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

	class Weather(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		solar_resource_file = str


	class PVWatts(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		albedo = float
		ar_glass = float
		azimuth = float
		concen = float
		derate = float
		enable_user_poa = float
		fd = float
		fhconv = float
		gamma = float
		gcr = float
		i_ref = float
		inoct = float
		inv_eff = float
		poa_cutin = float
		rotlim = float
		shade_mode_1x = float
		shading_azal = tuple
		shading_diff = float
		shading_mxh = tuple
		shading_timestep = tuple
		system_size = float
		tilt = float
		tilt_eq_lat = float
		track_mode = float
		tref = float
		u0 = float
		u1 = float
		user_poa = tuple
		w_stow = float


	class AdjustmentFactors(object):
		def assign(self): 
			pass
	
		def export(self): 
			return {}
	
		def __init__(self, *args, **kwargs): # real signature unknown
			pass
	
		constant = float
		dc_constant = float
		dc_hourly = tuple
		dc_periods = tuple
		hourly = tuple
		periods = tuple
		sf_constant = float
		sf_hourly = tuple
		sf_periods = tuple

	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		ac = tuple
		ac_annual = float
		ac_monthly = tuple
		annual_energy = float
		annual_energy_distribution_time = tuple
		city = str
		dc = tuple
		dc_monthly = tuple
		df = tuple
		dn = tuple
		elev = float
		gen = tuple
		gh = tuple
		lat = float
		location = str
		lon = float
		monthly_energy = tuple
		poa = tuple
		poa_monthly = tuple
		shad_beam_factor = tuple
		solrad_annual = float
		solrad_monthly = tuple
		state = str
		sunup = tuple
		tamb = tuple
		tcell = tuple
		tdew = tuple
		tpoa = tuple
		tz = float
		wspd = tuple




def default(config) -> Pvwattsv1:
	pass

def new() -> Pvwattsv1:
	pass

def wrap(ssc_data_t) -> Pvwattsv1:
	pass

def from_existing(model, config="") -> Pvwattsv1:
	pass

__loader__ = None 

__spec__ = None
