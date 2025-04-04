class CspHeatsink(object):
	def assign(self, dict):
		pass

	def replace(self, dict):
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

	class System(object):
		def assign(self, dict): 
			pass
	
		def replace(self, dict): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		t_step = float


	class Outputs(object):
		def assign(self, dict): 
			pass
	
		def replace(self, dict): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass






def default(config) -> CspHeatsink:
	pass

def new() -> CspHeatsink:
	pass

def wrap(ssc_data_t) -> CspHeatsink:
	pass

def from_existing(model, config="") -> CspHeatsink:
	pass

__loader__ = None 

__spec__ = None
