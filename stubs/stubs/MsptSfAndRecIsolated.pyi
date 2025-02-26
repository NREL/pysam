class MsptSfAndRecIsolated(object):
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

	class Simulation(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		sim_type = float


	class TowerAndReceiver(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		D_rec = float
		Flow_type = float
		N_panels = float
		T_htf_cold_des = float
		T_htf_hot_des = float
		crossover_shift = float
		csp_pt_rec_max_oper_frac = float
		d_tube_out = float
		downc_tm_mult = float
		epsilon = float
		eta_pump = float
		f_rec_min = float
		field_fl_props = tuple
		h_tower = float
		hl_ffact = float
		is_rec_clearsky_control = float
		is_rec_model_trans = float
		mat_tube = float
		piping_length_const = float
		piping_length_mult = float
		piping_loss_coefficient = float
		q_dot_rec_des = float
		rec_height = float
		rec_htf = float
		rec_qf_delay = float
		rec_su_delay = float
		rec_tm_mult = float
		riser_tm_mult = float
		th_riser = float
		th_tube = float
		u_riser = float


	class ReceiverControl(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		T_htf_cold_in_od = tuple
		plant_defocus_od = tuple
		rec_clearsky_fraction = float


	class Timeseries(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		timestep_od = tuple


	class Weather(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		P_amb_od = tuple
		T_amb_od = tuple
		clearsky_to_measured_dni_od = tuple
		deltaT_sky_od = tuple
		v_wind_10_od = tuple


	class Flux(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		flux_map_od = tuple


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		T_htf_rec_out_od = tuple
		W_dot_pump_od = tuple
		eta_rec_od = tuple
		m_dot_rec_des = float
		m_dot_rec_od = tuple
		q_dot_htf_od = tuple
		q_dot_rec_conv_loss = tuple
		q_dot_rec_inc = tuple
		q_dot_rec_inc_pre_defocus = tuple
		q_dot_rec_piping_loss = tuple
		q_dot_rec_rad_loss = tuple
		rec_component_defocus_od = tuple




def default(config) -> MsptSfAndRecIsolated:
	pass

def new() -> MsptSfAndRecIsolated:
	pass

def wrap(ssc_data_t) -> MsptSfAndRecIsolated:
	pass

def from_existing(model, config="") -> MsptSfAndRecIsolated:
	pass

__loader__ = None 

__spec__ = None
