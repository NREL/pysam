class Common(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	P_co2_hot_in = float
	T_amb = float
	T_co2_cold_out = float
	T_co2_hot_in = float
	W_dot_fan = float
	deltaP = float
	q_dot_reject = float
	site_elevation = float


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	UA_total = float
	d_tube_in = float
	d_tube_out = float
	depth_footprint = float
	length = float
	m_V_hx_material = float
	n_passes_series = float
	number_of_tubes = float
	parallel_paths = float
	width_footprint = float


class Sco2AirCooler(object):
	def assign(self, dict):
		pass

	def value(self, name, value=None):
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
	Outputs = Outputs


def default(config) -> Sco2AirCooler
	pass

def new() -> Sco2AirCooler
	pass

def wrap(ssc_data_t) -> Sco2AirCooler
	pass

def from_existing(model, config="") -> Sco2AirCooler
	pass

__loader__ = None 

__spec__ = None
