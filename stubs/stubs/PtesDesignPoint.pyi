class PtesDesignPoint(object):
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


		P0 = float
		P1 = float
		T0 = float
		T_compressor_inlet = float
		T_compressor_outlet = float
		alpha = float
		charge_time_hr = float
		cold_fluid_id = float
		cold_ud_fluid_props = tuple
		discharge_time_hr = float
		eta = float
		eta_pump = float
		gen_eff = float
		hot_fluid_id = float
		hot_ud_fluid_props = tuple
		hx_eff = float
		motor_eff = float
		ploss_air = float
		ploss_liquid = float
		ploss_working = float
		power_output = float
		working_fluid_type = str


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		N_pts_charge = float
		N_pts_discharge = float
		Tc_cold = float
		Tc_hot = float
		Th_cold = float
		Th_hot = float
		cycle_eff = float
		hp_COP = float
		hp_cold_pump_power = float
		hp_hot_pump_power = float
		hp_parasitic_fraction = float
		pc_cold_pump_power = float
		pc_hot_pump_power = float
		pc_parasitic_fraction = float
		s_series_charge = tuple
		s_series_discharge = tuple
		temp_series_charge = tuple
		temp_series_discharge = tuple




def default(config) -> PtesDesignPoint:
	pass

def new() -> PtesDesignPoint:
	pass

def wrap(ssc_data_t) -> PtesDesignPoint:
	pass

def from_existing(model, config="") -> PtesDesignPoint:
	pass

__loader__ = None 

__spec__ = None
