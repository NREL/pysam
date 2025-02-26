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

	def get_data_ptr(self):
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
		T_tank_cold_ini = float
		T_tank_hot_ini = float
		cold_tank_Thtr = float
		cold_tank_max_heat = float
		d_tank_in = float
		dt_hot = float
		h_tank_in = float
		h_tank_min = float
		hot_tank_Thtr = float
		hot_tank_bypassed = tuple
		hot_tank_max_heat = float
		init_hot_htf_percent = float
		is_h_tank_fixed = float
		mdot_sink = tuple
		mdot_src = tuple
		store_fl_props = tuple
		store_fluid = float
		tank_pairs = float
		tes_cyl_piston_loss_poly = tuple
		tes_cyl_tank_cp = float
		tes_cyl_tank_dens = float
		tes_cyl_tank_insul_percent = float
		tes_cyl_tank_thick = float
		tes_n_tsteps = float
		tes_pb_T_charge_min = float
		tes_pb_T_cold_delta = float
		tes_pb_T_grad_ini = tuple
		tes_pb_T_hot_delta = float
		tes_pb_cp_solid = float
		tes_pb_dens_solid = float
		tes_pb_f_oversize = float
		tes_pb_k_eff = float
		tes_pb_n_xsteps = float
		tes_pb_void_frac = float
		tes_type = float
		tshours = float
		u_tank = float


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


		T_grad_final = tuple
		T_sink_in = tuple
		T_src_in = tuple
		T_tank_cold = tuple
		T_tank_hot = tuple
		hot_tank_mass_perc = tuple
		hot_tank_vol_frac = tuple
		piston_frac = tuple
		piston_loc = tuple
		q_ch_from_htf = tuple
		q_dc_to_htf = tuple
		q_dot_ch_from_htf = tuple
		q_dot_dc_to_htf = tuple
		tes_E_cold = tuple
		tes_E_hot = tuple
		tes_V_cold = tuple
		tes_V_hot = tuple
		tes_diameter = float
		tes_error = tuple
		tes_error_corrected = tuple
		tes_error_percent = tuple
		tes_exp_length = tuple
		tes_exp_wall_mass = tuple
		tes_height = float
		tes_leak_error = tuple
		tes_mass_cold = tuple
		tes_mass_hot = tuple
		tes_radius = float
		tes_wall_error = tuple




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
