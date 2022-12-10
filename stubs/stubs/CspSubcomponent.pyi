class CspSubcomponent(object):
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

	class System(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		solar_mult = float
		t_step = float


	class Weather(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		T_amb = tuple


	class TES(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		T_sink_out = tuple
		T_src_out = tuple
		cold_tank_Thtr = float
		cold_tank_max_heat = float
		dt_hot = float
		h_tank = float
		h_tank_min = float
		hot_tank_Thtr = float
		hot_tank_bypassed = tuple
		hot_tank_max_heat = float
		init_hot_htf_percent = float
		mdot_sink = tuple
		mdot_src = tuple
		store_fl_props = tuple
		store_fluid = float
		tank_pairs = float
		tshours = float
		u_tank = float


	class SolarField(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		Fluid = float
		HDR_rough = float
		T_loop_in_des = float
		T_loop_out = float
		calc_design_pipe_vals = float
		eta_pump = float
		field_fl_props = tuple


	class Powerblock(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		P_ref = float
		eta_ref = float
		pb_pump_coef = float


	class Controller(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		DP_SGS = float
		T_tank_hot_inlet_min = float
		V_tes_des = float
		custom_tes_p_loss = float
		custom_tes_pipe_sizes = float
		has_hot_tank_bypass = float
		k_tes_loss_coeffs = tuple
		tanks_in_parallel = float
		tes_diams = tuple
		tes_lengths = tuple
		tes_pump_coef = float
		tes_wallthicks = tuple


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		T_sink_in = tuple
		T_src_in = tuple
		T_tank_cold = tuple
		T_tank_hot = tuple




def default(config) -> CspSubcomponent:
	pass

def new() -> CspSubcomponent:
	pass

def wrap(ssc_data_t) -> CspSubcomponent:
	pass

def from_existing(model, config="") -> CspSubcomponent:
	pass

__loader__ = None 

__spec__ = None
