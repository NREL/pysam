class Singlediode(object):
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

	class SingleDiodeModel(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		Il = float
		Io = float
		Rs = float
		Rsh = float
		Vop = float
		a = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		I = float
		Isc = float
		V = float
		Voc = float




def default(config) -> Singlediode:
	pass

def new() -> Singlediode:
	pass

def wrap(ssc_data_t) -> Singlediode:
	pass

def from_existing(model, config="") -> Singlediode:
	pass

__loader__ = None 

__spec__ = None
