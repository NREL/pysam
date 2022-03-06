class Layoutarea(object):
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


		positions = tuple


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		area = float
		convex_hull = tuple




def default(config) -> Layoutarea:
	pass

def new() -> Layoutarea:
	pass

def wrap(ssc_data_t) -> Layoutarea:
	pass

def from_existing(model, config="") -> Layoutarea:
	pass

__loader__ = None 

__spec__ = None
