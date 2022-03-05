class PvGetShadeLossMpp(object):
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

	class PVShadeLossDB(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		diffuse_irrad = tuple
		global_poa_irrad = tuple
		mods_per_string = tuple
		pv_cell_temp = tuple
		str_shade_fracs = tuple
		str_vmp_stc = tuple
		v_mppt_high = tuple
		v_mppt_low = tuple


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		N = tuple
		S = tuple
		d = tuple
		shade_loss = tuple
		t = tuple




def default(config) -> PvGetShadeLossMpp:
	pass

def new() -> PvGetShadeLossMpp:
	pass

def wrap(ssc_data_t) -> PvGetShadeLossMpp:
	pass

def from_existing(model, config="") -> PvGetShadeLossMpp:
	pass

__loader__ = None 

__spec__ = None
