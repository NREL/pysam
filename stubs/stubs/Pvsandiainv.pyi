class Pvsandiainv(object):
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

	class SandiaInverterModel(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		c0 = float
		c1 = float
		c2 = float
		c3 = float
		dc = tuple
		dc_voltage = tuple
		paco = float
		pdco = float
		pntare = float
		pso = float
		vdco = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		ac = tuple
		acpar = tuple
		cliploss = tuple
		eff_inv = tuple
		ntloss = tuple
		plr = tuple
		soloss = tuple




def default(config) -> Pvsandiainv:
	pass

def new() -> Pvsandiainv:
	pass

def wrap(ssc_data_t) -> Pvsandiainv:
	pass

def from_existing(model, config="") -> Pvsandiainv:
	pass

__loader__ = None 

__spec__ = None
