class Sco2CompCurves(object):
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


		P_comp_in = float
		T_comp_in = float
		comp_type = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		eta = tuple
		eta_ND = tuple
		eta_norm_design = float
		phi = tuple
		phi_ND = tuple
		phi_design = float
		psi = tuple
		psi_ND = tuple
		psi_design = float




def default(config) -> Sco2CompCurves:
	pass

def new() -> Sco2CompCurves:
	pass

def wrap(ssc_data_t) -> Sco2CompCurves:
	pass

def from_existing(model, config="") -> Sco2CompCurves:
	pass

__loader__ = None 

__spec__ = None
