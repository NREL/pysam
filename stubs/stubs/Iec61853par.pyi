class Iec61853par(object):
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

	class IEC61853(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		input = tuple
		nser = float
		type = float
		verbose = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		C1 = float
		C2 = float
		C3 = float
		D1 = float
		D2 = float
		D3 = float
		Egref = float
		Il = float
		Io = float
		alphaIsc = float
		betaVoc = float
		gammaPmp = float
		n = float




def default(config) -> Iec61853par:
	pass

def new() -> Iec61853par:
	pass

def wrap(ssc_data_t) -> Iec61853par:
	pass

def from_existing(model, config="") -> Iec61853par:
	pass

__loader__ = None 

__spec__ = None
