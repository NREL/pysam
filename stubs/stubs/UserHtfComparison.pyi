class UserHtfComparison(object):
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


		HTF_code1 = float
		HTF_code2 = float
		fl_props1 = tuple
		fl_props2 = tuple


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		are_equal = float




def default(config) -> UserHtfComparison:
	pass

def new() -> UserHtfComparison:
	pass

def wrap(ssc_data_t) -> UserHtfComparison:
	pass

def from_existing(model, config="") -> UserHtfComparison:
	pass

__loader__ = None 

__spec__ = None
