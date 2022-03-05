class DsgFluxPreprocess(object):
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


		CT = float
		P_HP_in = float
		P_HP_out = float
		P_cycle_des = float
		Q_rec_des = float
		T_ITD_des = float
		T_amb_des = float
		T_approach = float
		T_rh_out_ref = float
		T_sh_out_ref = float
		b_q_loss_flux = float
		dT_cooling_ref = float
		eta_cycle_des = float
		max_flux_b = float
		max_flux_rh = float
		max_flux_sh = float
		rh_frac_ref = float
		rh_q_loss_flux = float
		sh_q_loss_flux = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		f_b = float
		f_rh = float
		f_sh = float
		max_flux = float




def default(config) -> DsgFluxPreprocess:
	pass

def new() -> DsgFluxPreprocess:
	pass

def wrap(ssc_data_t) -> DsgFluxPreprocess:
	pass

def from_existing(model, config="") -> DsgFluxPreprocess:
	pass

__loader__ = None 

__spec__ = None
