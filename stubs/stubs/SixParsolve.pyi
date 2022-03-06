class SixParsolve(object):
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

	class SixParameterSolver(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		Imp = float
		Isc = float
		Nser = float
		Tref = float
		Vmp = float
		Voc = float
		alpha_isc = float
		beta_voc = float
		celltype = str
		gamma_pmp = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		Adj = float
		Il = float
		Io = float
		Rs = float
		Rsh = float
		a = float




def default(config) -> SixParsolve:
	pass

def new() -> SixParsolve:
	pass

def wrap(ssc_data_t) -> SixParsolve:
	pass

def from_existing(model, config="") -> SixParsolve:
	pass

__loader__ = None 

__spec__ = None
