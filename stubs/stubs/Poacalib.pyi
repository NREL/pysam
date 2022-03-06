class Poacalib(object):
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

	class POACalibrate(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		albedo = float
		array_az = float
		array_tilt = float
		beam = tuple
		diffuse = tuple
		elevation = float
		latitude = float
		longitude = float
		poa = tuple
		pressure = float
		tamb = float
		time_zone = float
		year = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		pcalc = tuple




def default(config) -> Poacalib:
	pass

def new() -> Poacalib:
	pass

def wrap(ssc_data_t) -> Poacalib:
	pass

def from_existing(model, config="") -> Poacalib:
	pass

__loader__ = None 

__spec__ = None
