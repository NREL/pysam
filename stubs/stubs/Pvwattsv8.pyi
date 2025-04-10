class Pvwattsv8(object):
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

	def Reopt_size_battery_post(self, args):
		pass
	class SolarResource(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		albedo = tuple
		albedo_default = float
		albedo_default_snow = float
		solar_resource_data = dict
		solar_resource_file = str
		use_wf_albedo = float


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
		bifaciality = float
		dc_ac_ratio = float
		en_snowloss = float
		enable_wind_stow = float
		gcr = float
		gust_factor = float
		inv_eff = float
		losses = float
		module_type = float
		rotlim = float
		soiling = tuple
		stow_wspd = float
		system_capacity = float
		tilt = float
		wind_stow_angle = float
		xfmr_ll = float
		xfmr_nll = float


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

	class HybridCosts(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		degradation = tuple
		land_area = float
		om_capacity = tuple
		om_capacity_escal = float
		om_fixed = tuple
		om_fixed_escal = float
		om_land_lease = tuple
		om_land_lease_escal = float
		om_production = tuple
		om_production_escal = float
		total_installed_cost = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		ac = tuple
		ac_annual = float
		ac_annual_pre_adjust = float
		ac_monthly = tuple
		ac_pre_adjust = tuple
		alb = tuple
		annual_energy = float
		annual_energy_distribution_time = tuple
		aoi = tuple
		capacity_factor = float
		capacity_factor_ac = float
		cf_battery_replacement_cost_schedule = tuple
		cf_energy_net = tuple
		cf_fuelcell_replacement_cost_schedule = tuple
		cf_land_lease_expense = tuple
		cf_om_capacity = tuple
		cf_om_fixed = tuple
		cf_om_fuel_cost = tuple
		cf_om_land_lease = tuple
		cf_om_production = tuple
		city = str
		dc = tuple
		dc_monthly = tuple
		dcsnowderate = tuple
		df = tuple
		dn = tuple
		elev = float
		gen = tuple
		gh = tuple
		inv_eff_output = tuple
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
		snow = tuple
		snow_cover = tuple
		soiling_f = tuple
		solrad_annual = float
		solrad_monthly = tuple
		ss_beam_factor = tuple
		ss_gnd_diffuse_factor = tuple
		ss_sky_diffuse_factor = tuple
		state = str
		sunup = tuple
		system_capacity_ac = float
		tamb = tuple
		tcell = tuple
		tpoa = tuple
		ts_shift_hours = float
		tz = float
		wspd = tuple




def default(config) -> Pvwattsv8:
	pass

def new() -> Pvwattsv8:
	pass

def wrap(ssc_data_t) -> Pvwattsv8:
	pass

def from_existing(model, config="") -> Pvwattsv8:
	pass

__loader__ = None 

__spec__ = None
