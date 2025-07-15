class GeothermalCosts(object):
	def assign(self, dict):
		pass

	def replace(self, dict):
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

	def getem_om_cost_calc(self, args):
		pass
	class GeoHourly(object):
		def assign(self, dict): 
			pass
	
		def replace(self, dict): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		GF_flowrate = float
		calc_drill_costs = float
		condensate_pump_power = float
		conversion_type = float
		cw_pump_head = float
		cw_pump_work = float
		cwflow = float
		design_temp = float
		dt_prod_well = float
		eff_secondlaw = float
		flash_count = float
		geotherm_cost_conf_multiplier = float
		geotherm_cost_conf_non_drill = float
		geotherm_cost_conf_num_wells = float
		geotherm_cost_expl_multiplier = float
		geotherm_cost_expl_non_drill = float
		geotherm_cost_expl_num_wells = float
		geotherm_cost_inj_cost_curve = float
		geotherm_cost_inj_cost_curve_welldiam = float
		geotherm_cost_inj_cost_curve_welltype = float
		geotherm_cost_prod_cost_curve = float
		geotherm_cost_prod_cost_curve_welldiam = float
		geotherm_cost_prod_cost_curve_welltype = float
		geotherm_cost_pump_casing_cost = float
		geotherm_cost_pump_fixed = float
		geotherm_cost_pump_per_foot = float
		geotherm_cost_stim_non_drill = float
		gross_cost_output = float
		gross_output = float
		hp_flash_pressure = float
		inj_pump_hp = float
		lp_flash_pressure = float
		ncg_condensate_pump = float
		num_wells_getem = float
		num_wells_getem_inj_drilled = float
		num_wells_getem_prod_drilled = float
		num_wells_getem_prod_failed = float
		ppi_base_year = float
		pressure_ratio_1 = float
		pressure_ratio_2 = float
		pressure_ratio_3 = float
		pump_depth_ft = float
		pump_size_hp = float
		qCondenser = float
		qRejectByStage_1 = float
		qRejectByStage_2 = float
		qRejectByStage_3 = float
		qRejectTotal = float
		resource_depth = float
		spec_vol = float
		spec_vol_lp = float
		stimulation_type = float
		v_stage_1 = float
		v_stage_2 = float
		v_stage_3 = float
		x_hp = float
		x_lp = float


	class Outputs(object):
		def assign(self, dict): 
			pass
	
		def replace(self, dict): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		baseline_cost = float
		conf_drilling_cost = float
		conf_total_cost = float
		expl_drilling_cost = float
		expl_total_cost = float
		field_gathering_num_wells = float
		indirect_pump_cost = float
		indirect_pump_gathering_cost = float
		inj_num_pumps = float
		inj_pump_cost = float
		inj_pump_cost_per_pump = float
		inj_total_cost = float
		inj_well_cost = float
		piping_cost_per_well = float
		prod_pump_cost = float
		prod_pump_cost_per_well = float
		prod_total_cost = float
		prod_well_cost = float
		pump_cost_install = float
		pump_only_cost = float
		stim_cost_non_drill = float
		stim_cost_per_well = float
		total_drilling_cost = float
		total_gathering_cost = float
		total_pump_cost = float
		total_pump_gathering_cost = float
		total_surface_equipment_cost = float




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
