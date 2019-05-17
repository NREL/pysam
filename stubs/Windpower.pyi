class WindResourceFile(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	wind_resource_data = dict
	wind_resource_filename = str


class WindTurbine(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	wind_resource_shear = float
	wind_turbine_hub_ht = float
	wind_turbine_max_cp = float
	wind_turbine_powercurve_powerout = tuple
	wind_turbine_powercurve_windspeeds = tuple
	wind_turbine_rotor_diameter = float


class WindFarm(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	system_capacity = float
	wind_farm_losses_percent = float
	wind_farm_wake_model = float
	wind_farm_xCoordinates = tuple
	wind_farm_yCoordinates = tuple
	wind_resource_turbulence_coeff = float


class WindPower(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	en_icing_cutoff = float
	en_low_temp_cutoff = float
	icing_cutoff_rh = float
	icing_cutoff_temp = float
	low_temp_cutoff = float
	wind_resource_model_choice = float


class WindSpeedWeibullDistribution(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	weibull_k_factor = float
	weibull_reference_height = float
	weibull_wind_speed = float


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	annual_energy = float
	capacity_factor = float
	cutoff_losses = float
	gen = tuple
	kwh_per_kw = float
	monthly_energy = tuple
	pressure = tuple
	temp = tuple
	turbine_output_by_windspeed_bin = tuple
	wind_direction = tuple
	wind_speed = tuple


class Windpower(object):
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

	WindResourceFile = WindResourceFile
	WindTurbine = WindTurbine
	WindFarm = WindFarm
	WindPower = WindPower
	WindSpeedWeibullDistribution = WindSpeedWeibullDistribution
	Outputs = Outputs


def default(config) -> Windpower
	pass

def new() -> Windpower
	pass

def wrap(ssc_data_t) -> Windpower
	pass

__loader__ = None 

__spec__ = None
