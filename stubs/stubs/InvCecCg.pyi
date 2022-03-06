class InvCecCg(object):
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


		inv_cec_cg_paco = float
		inv_cec_cg_sample_power_units = float
		inv_cec_cg_test_samples = tuple


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		Pdco = float
		Pso = float
		Vdco = float
		c0 = float
		c1 = float
		c2 = float
		c3 = float
		inv_cec_cg_C0 = tuple
		inv_cec_cg_C1 = tuple
		inv_cec_cg_C2 = tuple
		inv_cec_cg_C3 = tuple
		inv_cec_cg_Pdco = tuple
		inv_cec_cg_Psco = tuple
		inv_cec_cg_Vdc = tuple
		inv_cec_cg_Vdc_Vnom = tuple
		inv_cec_cg_Vmax = tuple
		inv_cec_cg_Vmax_abc = tuple
		inv_cec_cg_Vmin = tuple
		inv_cec_cg_Vmin_abc = tuple
		inv_cec_cg_Vnom = tuple
		inv_cec_cg_Vnom_abc = tuple




def default(config) -> InvCecCg:
	pass

def new() -> InvCecCg:
	pass

def wrap(ssc_data_t) -> InvCecCg:
	pass

def from_existing(model, config="") -> InvCecCg:
	pass

__loader__ = None 

__spec__ = None
