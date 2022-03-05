class Pv6parmod(object):
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


		elev = float
		incidence = tuple
		poa_beam = tuple
		poa_gnddiff = tuple
		poa_skydiff = tuple
		sun_zen = tuple
		surf_tilt = tuple
		tdry = tuple
		wdir = tuple
		wspd = tuple


	class CEC6ParameterPVModuleModel(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		Adj = float
		Il = float
		Imp = float
		Io = float
		Isc = float
		Rs = float
		Rsh = float
		Vmp = float
		Voc = float
		a = float
		alpha_isc = float
		area = float
		beta_voc = float
		gamma_pmp = float
		height = float
		opvoltage = tuple
		standoff = float
		tnoct = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		dc = tuple
		dc_current = tuple
		dc_voltage = tuple
		eff = tuple
		tcell = tuple




def default(config) -> Pv6parmod:
	pass

def new() -> Pv6parmod:
	pass

def wrap(ssc_data_t) -> Pv6parmod:
	pass

def from_existing(model, config="") -> Pv6parmod:
	pass

__loader__ = None 

__spec__ = None
