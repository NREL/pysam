class UiTesCalcs(object):
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


		P_ref = float
		T_htf_cold_des = float
		T_htf_hot_des = float
		design_eff = float
		dt_hot = float
		field_fl_props = tuple
		field_fluid = float
		h_tank = float
		h_tank_min = float
		store_fl_props = tuple
		store_fluid = float
		tank_pairs = float
		tshours = float
		u_tank = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		are_htfs_equal = float
		csp_pt_tes_htf_density = float
		csp_pt_tes_tank_diameter = float
		q_dot_tes_est = float
		q_tes = float
		tes_avail_vol = float
		vol_tank = float




def default(config) -> UiTesCalcs:
	pass

def new() -> UiTesCalcs:
	pass

def wrap(ssc_data_t) -> UiTesCalcs:
	pass

def from_existing(model, config="") -> UiTesCalcs:
	pass

__loader__ = None 

__spec__ = None
