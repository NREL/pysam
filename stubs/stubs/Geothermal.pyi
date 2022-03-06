class Geothermal(object):
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


		CT = float
		HTF = float
		P_boil = float
		P_cond_min = float
		P_cond_ratio = float
		T_ITD_des = float
		T_amb_des = float
		T_approach = float
		T_htf_cold_ref = float
		T_htf_hot_ref = float
		ambient_pressure = float
		analysis_type = float
		casing_size = float
		conversion_subtype = float
		conversion_type = float
		dT_cw_ref = float
		decline_type = float
		delta_pressure_equip = float
		design_temp = float
		dt_prod_well = float
		eta_ref = float
		excess_pressure_pump = float
		file_name = str
		fracture_angle = float
		fracture_aperature = float
		fracture_width = float
		geothermal_analysis_period = float
		hc_ctl1 = float
		hc_ctl2 = float
		hc_ctl3 = float
		hc_ctl4 = float
		hc_ctl5 = float
		hc_ctl6 = float
		hc_ctl7 = float
		hc_ctl8 = float
		hc_ctl9 = float
		hr_pl_nlev = float
		hybrid_dispatch_schedule = str
		inj_prod_well_distance = float
		inj_well_diam = float
		model_choice = float
		nameplate = float
		num_fractures = float
		num_wells = float
		num_wells_getem = float
		pb_bd_frac = float
		plant_efficiency_input = float
		pump_efficiency = float
		q_sby_frac = float
		reservoir_height = float
		reservoir_permeability = float
		reservoir_pressure_change = float
		reservoir_pressure_change_type = float
		reservoir_width = float
		resource_depth = float
		resource_potential = float
		resource_temp = float
		resource_type = float
		rock_density = float
		rock_specific_heat = float
		rock_thermal_conductivity = float
		specified_pump_work_amount = float
		specify_pump_work = float
		startup_frac = float
		startup_time = float
		subsurface_water_loss = float
		system_use_lifetime_output = float
		temp_decline_max = float
		temp_decline_rate = float
		ui_calculations_only = float
		well_diameter = float
		well_flow_rate = float
		wet_bulb_temp = float


	class AdjustmentFactors(object):
		def assign(self): 
			pass
	
		def export(self): 
			return {}
	
		def __init__(self, *args, **kwargs): # real signature unknown
			pass
	
		constant = float
		dc_constant = float
		dc_hourly = tuple
		dc_periods = tuple
		hourly = tuple
		periods = tuple
		sf_constant = float
		sf_hourly = tuple
		sf_periods = tuple

	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		GF_flowrate = float
		annual_energy = float
		annual_energy_distribution_time = tuple
		bottom_hole_pressure = float
		capacity_factor = float
		condensate_pump_power = float
		cw_pump_head = float
		cw_pump_work = float
		cwflow = float
		eff_secondlaw = float
		first_year_output = float
		flash_count = float
		gen = tuple
		gross_output = float
		hp_flash_pressure = float
		kwh_per_kw = float
		lifetime_output = float
		lp_flash_pressure = float
		monthly_energy = tuple
		monthly_power = tuple
		monthly_resource_temperature = tuple
		ncg_condensate_pump = float
		num_wells_getem_output = float
		plant_brine_eff = float
		pressure_ratio_1 = float
		pressure_ratio_2 = float
		pressure_ratio_3 = float
		pump_depth_ft = float
		pump_hp = float
		pump_work = float
		qCondenser = float
		qRejectByStage_1 = float
		qRejectByStage_2 = float
		qRejectByStage_3 = float
		qRejectTotal = float
		reservoir_avg_temp = float
		reservoir_pressure = float
		spec_vol = float
		spec_vol_lp = float
		system_lifetime_recapitalize = tuple
		timestep_dry_bulb = tuple
		timestep_pressure = tuple
		timestep_resource_temperature = tuple
		timestep_test_values = tuple
		timestep_wet_bulb = tuple
		v_stage_1 = float
		v_stage_2 = float
		v_stage_3 = float
		x_hp = float
		x_lp = float




def default(config) -> Geothermal:
	pass

def new() -> Geothermal:
	pass

def wrap(ssc_data_t) -> Geothermal:
	pass

def from_existing(model, config="") -> Geothermal:
	pass

__loader__ = None 

__spec__ = None
