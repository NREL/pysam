class Common(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	system_use_lifetime_output = float


class FinancialAnalysisParameters(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	analysis_period = float


class LifetimePV(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	dc_degradation = tuple


class Weather(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	solar_resource_data = dict
	solar_resource_file = str


class PVWatts(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	array_type = float
	azimuth = float
	dc_ac_ratio = float
	gcr = float
	inv_eff = float
	losses = float
	module_type = float
	shading_azal = tuple
	shading_diff = float
	shading_mxh = tuple
	shading_timestep = tuple
	system_capacity = float
	tilt = float


class Battwatts(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	batt_simple_enable = float


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	ac = tuple
	ac_annual = float
	ac_monthly = tuple
	annual_energy = float
	aoi = tuple
	capacity_factor = float
	city = str
	dc = tuple
	dc_monthly = tuple
	df = tuple
	dn = tuple
	elev = float
	gh = tuple
	inverter_efficiency = float
	inverter_model = float
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


class Pvwattsv5Lifetime(object):
	def assign(self, dict):
		pass

	def execute(self, int_verbosity):
		pass

	def export(self):
		pass

	def __getattribute__(self, *args, **kwargs):
		pass

	def __init__(self, *args, **kwargs):
		pass

	Common = Common
	FinancialAnalysisParameters = FinancialAnalysisParameters
	LifetimePV = LifetimePV
	Weather = Weather
	PVWatts = PVWatts
	Battwatts = Battwatts
	Outputs = Outputs


def default(config) -> Pvwattsv5Lifetime
	pass

def new() -> Pvwattsv5Lifetime
	pass

def wrap(ssc_data_t) -> Pvwattsv5Lifetime
	pass

__loader__ = None 

__spec__ = None
