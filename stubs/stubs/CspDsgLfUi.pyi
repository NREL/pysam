class CspDsgLfUi(object):
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

	class Common(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		P_boil = float
		deltaT_subcooled = float
		use_quality_or_subcooled = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		T_hot_out_target = float
		T_saturation = float




def default(config) -> CspDsgLfUi:
	pass

def new() -> CspDsgLfUi:
	pass

def wrap(ssc_data_t) -> CspDsgLfUi:
	pass

def from_existing(model, config="") -> CspDsgLfUi:
	pass

__loader__ = None 

__spec__ = None
