class Belpe(object):
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

	class LoadProfileEstimator(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		Monthly_util = tuple
		Occ_Schedule = tuple
		Occupants = float
		Retrofits = float
		Stories = float
		TCool = float
		TCoolSB = float
		THeat = float
		THeatSB = float
		T_Sched = tuple
		YrBuilt = float
		en_belpe = float
		en_cool = float
		en_dish = float
		en_dry = float
		en_fridge = float
		en_heat = float
		en_mels = float
		en_range = float
		en_wash = float
		floor_area = float
		load = tuple
		solar_resource_file = str


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass






def default(config) -> Belpe:
	pass

def new() -> Belpe:
	pass

def wrap(ssc_data_t) -> Belpe:
	pass

def from_existing(model, config="") -> Belpe:
	pass

__loader__ = None 

__spec__ = None
