class Windcsm(object):
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

	class WindCsm(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		hub_height = float
		machine_rating = float
		num_bearings = float
		num_blades = float
		onboard_crane = float
		rotor_torque = float
		turbine_carbon_blades = float
		turbine_class = float
		turbine_rotor_diameter = float
		turbine_user_exponent = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		bedplate_cost = float
		blade_cost = float
		controls_cost = float
		drivetrain_cost = float
		drivetrain_mass = float
		electrical_connections_cost = float
		gearbox_cost = float
		generator_cost = float
		high_speed_side_cost = float
		hub_cost = float
		hvac_cost = float
		low_speed_side_cost = float
		main_bearings_cost = float
		mainframe_cost = float
		pitch_cost = float
		rotor_cost = float
		rotor_mass = float
		spinner_cost = float
		tower_cost = float
		tower_mass = float
		transformer_cost = float
		turbine_cost = float
		variable_speed_electronics_cost = float
		yaw_system_cost = float




def default(config) -> Windcsm:
	pass

def new() -> Windcsm:
	pass

def wrap(ssc_data_t) -> Windcsm:
	pass

def from_existing(model, config="") -> Windcsm:
	pass

__loader__ = None 

__spec__ = None
