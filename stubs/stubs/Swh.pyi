class Swh(object):
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

	class SolarResource(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		solar_resource_data = dict
		solar_resource_file = str


	class SWH(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		FRUL = float
		FRta = float
		T_room = float
		T_set = float
		T_tank_max = float
		U_tank = float
		V_tank = float
		albedo = float
		area_coll = float
		azimuth = float
		custom_mains = tuple
		custom_set = tuple
		fluid = float
		hx_eff = float
		iam = float
		irrad_mode = float
		load = tuple
		load_escalation = tuple
		mdot = float
		ncoll = float
		pipe_diam = float
		pipe_insul = float
		pipe_k = float
		pipe_length = float
		pump_eff = float
		pump_power = float
		scaled_draw = tuple
		sky_model = float
		system_capacity = float
		tank_h2d_ratio = float
		test_flow = float
		test_fluid = float
		tilt = float
		use_custom_mains = float
		use_custom_set = float


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


		I_incident = tuple
		I_transmitted = tuple
		P_pump = tuple
		Q_aux = tuple
		Q_auxonly = tuple
		Q_deliv = tuple
		Q_loss = tuple
		Q_transmitted = tuple
		Q_useful = tuple
		T_amb = tuple
		T_cold = tuple
		T_deliv = tuple
		T_hot = tuple
		T_mains = tuple
		T_tank = tuple
		V_cold = tuple
		V_hot = tuple
		annual_Q_aux = float
		annual_Q_auxonly = float
		annual_Q_deliv = float
		annual_energy = float
		annual_energy_distribution_time = tuple
		beam = tuple
		capacity_factor = float
		diffuse = tuple
		draw = tuple
		gen = tuple
		kwh_per_kw = float
		mode = tuple
		monthly_Q_aux = tuple
		monthly_Q_auxonly = tuple
		monthly_Q_deliv = tuple
		monthly_energy = tuple
		shading_loss = tuple
		solar_fraction = float
		ts_shift_hours = float




def default(config) -> Swh:
	pass

def new() -> Swh:
	pass

def wrap(ssc_data_t) -> Swh:
	pass

def from_existing(model, config="") -> Swh:
	pass

__loader__ = None 

__spec__ = None
