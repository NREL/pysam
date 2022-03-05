class Sco2AirCooler(object):
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

	class Common(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		P_co2_hot_des = float
		T_amb_des = float
		T_co2_cold_des = float
		T_co2_hot_des = float
		W_dot_fan_des = float
		deltaP_co2_des = float
		od_calc_T_co2_cold = tuple
		od_calc_W_dot_fan = tuple
		q_dot_des = float
		site_elevation = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		P_co2_cold_od = tuple
		P_co2_hot_od = tuple
		T_amb_od = tuple
		T_co2_cold_od = tuple
		T_co2_hot_od = tuple
		UA_total = float
		W_dot_fan_od = tuple
		W_dot_fan_od_ND = tuple
		d_tube_in = float
		d_tube_out = float
		deltaP_co2_od = tuple
		depth_footprint = float
		length = float
		m_V_hx_material = float
		m_dot_co2_od_ND = tuple
		n_passes_series = float
		number_of_tubes = float
		parallel_paths = float
		q_dot_od = tuple
		q_dot_od_ND = tuple
		width_footprint = float




def default(config) -> Sco2AirCooler:
	pass

def new() -> Sco2AirCooler:
	pass

def wrap(ssc_data_t) -> Sco2AirCooler:
	pass

def from_existing(model, config="") -> Sco2AirCooler:
	pass

__loader__ = None 

__spec__ = None
