class Pvwattsv1Poa(object):
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

	class Weather(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		beam = tuple
		incidence = tuple
		poa_beam = tuple
		poa_gnddiff = tuple
		poa_skydiff = tuple
		tdry = tuple
		wspd = tuple


	class PVWatts(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		derate = float
		gamma = float
		inoct = float
		inv_eff = float
		step = float
		system_size = float
		t_ref = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		ac = tuple
		dc = tuple
		tcell = tuple




def default(config) -> Pvwattsv1Poa:
	pass

def new() -> Pvwattsv1Poa:
	pass

def wrap(ssc_data_t) -> Pvwattsv1Poa:
	pass

def from_existing(model, config="") -> Pvwattsv1Poa:
	pass

__loader__ = None 

__spec__ = None
