class GeothermalCosts(object):
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

	class GeoHourly(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		GF_flowrate = float
		condensate_pump_power = float
		conversion_type = float
		cw_pump_head = float
		cw_pump_work = float
		cwflow = float
		design_temp = float
		eff_secondlaw = float
		flash_count = float
		gross_output = float
		hp_flash_pressure = float
		lp_flash_pressure = float
		ncg_condensate_pump = float
		pressure_ratio_1 = float
		pressure_ratio_2 = float
		pressure_ratio_3 = float
		qCondenser = float
		qRejectByStage_1 = float
		qRejectByStage_2 = float
		qRejectByStage_3 = float
		qRejectTotal = float
		spec_vol = float
		spec_vol_lp = float
		v_stage_1 = float
		v_stage_2 = float
		v_stage_3 = float
		x_hp = float
		x_lp = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		baseline_cost = float




def default(config) -> GeothermalCosts:
	pass

def new() -> GeothermalCosts:
	pass

def wrap(ssc_data_t) -> GeothermalCosts:
	pass

def from_existing(model, config="") -> GeothermalCosts:
	pass

__loader__ = None 

__spec__ = None
