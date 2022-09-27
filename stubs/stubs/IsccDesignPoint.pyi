class IsccDesignPoint(object):
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


		HTF_code = float
		elev = float
		field_fl_props = tuple
		ngcc_model = float
		pinch_point_cold = float
		pinch_point_hot = float
		q_pb_design = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		T_htf_cold = float
		T_st_inject = float
		W_dot_fossil = float
		W_dot_solar = float
		q_solar_max = float




def default(config) -> IsccDesignPoint:
	pass

def new() -> IsccDesignPoint:
	pass

def wrap(ssc_data_t) -> IsccDesignPoint:
	pass

def from_existing(model, config="") -> IsccDesignPoint:
	pass

__loader__ = None 

__spec__ = None
