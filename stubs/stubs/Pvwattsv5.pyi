class Pvwattsv5(object):
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

	class Lifetime(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		analysis_period = float
		dc_degradation = tuple
		system_use_lifetime_output = float


	class SolarResource(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		solar_resource_data = dict
		solar_resource_file = str


	class SystemDesign(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		array_type = float
		azimuth = float
		batt_simple_enable = float
		dc_ac_ratio = float
		gcr = float
		inv_eff = float
		losses = float
		module_type = float
		system_capacity = float
		tilt = float


	class Shading(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		shading_azal = tuple
		shading_diff = float
		shading_en_azal = float
		shading_en_diff = float
		shading_en_mxh = float
		shading_en_string_option = float
		shading_en_timestep = float
		shading_mxh = tuple
		shading_string_option = float
		shading_timestep = tuple


	class AdjustmentFactors(object):
		def assign(self): 
			pass
	
		def export(self): 
			return {}
	
		def __init__(self, *args, **kwargs): # real signature unknown
			pass
	
		adjust_constant = float
		adjust_en_hourly = float
		adjust_en_periods = float
		adjust_en_timeindex = float
		adjust_hourly = tuple
		adjust_periods = tuple
		adjust_timeindex = tuple
		dc_adjust_constant = float
		dc_adjust_en_hourly = float
		dc_adjust_en_periods = float
		dc_adjust_en_timeindex = float
		dc_adjust_hourly = tuple
		dc_adjust_periods = tuple
		dc_adjust_timeindex = tuple
		sf_adjust_constant = float
		sf_adjust_en_hourly = float
		sf_adjust_en_periods = float
		sf_adjust_en_timeindex = float
		sf_adjust_hourly = tuple
		sf_adjust_periods = tuple
		sf_adjust_timeindex = tuple

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
		aoi = tuple
		capacity_factor = float
		city = str
		dc = tuple
		dc_monthly = tuple
		df = tuple
		dn = tuple
		elev = float
		gen = tuple
		gh = tuple
		inverter_count = float
		inverter_efficiency = float
		kwh_per_kw = float
		lat = float
		location = str
		lon = float
		monthly_energy = tuple
		percent_complete = float
		poa = tuple
		poa_monthly = tuple
		shad_beam_factor = tuple
		solrad_annual = float
		solrad_monthly = tuple
		state = str
		sunup = tuple
		tamb = tuple
		tcell = tuple
		tpoa = tuple
		ts_shift_hours = float
		tz = float
		wspd = tuple




def default(config) -> Pvwattsv5:
	pass

def new() -> Pvwattsv5:
	pass

def wrap(ssc_data_t) -> Pvwattsv5:
	pass

def from_existing(model, config="") -> Pvwattsv5:
	pass

__loader__ = None 

__spec__ = None
