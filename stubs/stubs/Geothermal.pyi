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

	def get_data_ptr(self):
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
		allow_reservoir_replacements = float
		ambient_pressure = float
		analysis_type = float
		conversion_subtype = float
		conversion_type = float
		dT_cw_ref = float
		decline_type = float
		delta_pressure_equip = float
		design_temp = float
		drilling_success_rate = float
		dt_prod_well = float
		eta_ref = float
		excess_pressure_pump = float
		exploration_wells_production = float
		failed_prod_flow_ratio = float
		file_name = str
		fracture_angle = float
		fracture_aperature = float
		fracture_length = float
		fracture_spacing = float
		fracture_width = float
		geotherm_cost_inj_cost_curve_welldiam = float
		geotherm_cost_inj_cost_curve_welltype = float
		geotherm_cost_inj_prod_well_ratio = float
		geotherm_cost_prod_cost_curve_welldiam = float
		geotherm_cost_prod_cost_curve_welltype = float
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
		injectivity_index = float
		model_choice = float
		nameplate = float
		num_fractures = float
		num_wells = float
		num_wells_getem = float
		pb_bd_frac = float
		plant_efficiency_input = float
		prod_well_choice = float
		pump_efficiency = float
		q_sby_frac = float
		reservoir_height = float
		reservoir_model_inputs = tuple
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
		stim_success_rate = float
		subsurface_water_loss = float
		system_use_lifetime_output = float
		temp_decline_max = float
		temp_decline_rate = float
		ui_calculations_only = float
		use_weather_file_conditions = float
		well_flow_rate = float
		wet_bulb_temp = float


	class AdjustmentFactors(object):
		def assign(self): 
			pass
	
		def export(self): 
			return {}
	
		def __init__(self, *args, **kwargs): # real signature unknown
			pass
	
		adjust_constant = float
		adjust_en_hourly = float
		adjust_en_periods = float
		adjust_en_timeindex = float
		adjust_hourly = tuple
		adjust_periods = tuple
		adjust_timeindex = tuple
		dc_adjust_constant = float
		dc_adjust_en_hourly = float
		dc_adjust_en_periods = float
		dc_adjust_en_timeindex = float
		dc_adjust_hourly = tuple
		dc_adjust_periods = tuple
		dc_adjust_timeindex = tuple
		sf_adjust_constant = float
		sf_adjust_en_hourly = float
		sf_adjust_en_periods = float
		sf_adjust_en_timeindex = float
		sf_adjust_hourly = tuple
		sf_adjust_periods = tuple
		sf_adjust_timeindex = tuple

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
		gross_cost_output = float
		gross_output = float
		hp_flash_pressure = float
		inj_pump_hp = float
		kwh_per_kw = float
		lifetime_output = float
		lp_flash_pressure = float
		monthly_energy = tuple
		monthly_energy_lifetime = tuple
		monthly_power = tuple
		monthly_resource_temperature = tuple
		ncg_condensate_pump = float
		num_wells_getem_inj = float
		num_wells_getem_output = float
		plant_brine_eff = float
		pressure_ratio_1 = float
		pressure_ratio_2 = float
		pressure_ratio_3 = float
		pump_depth_ft = float
		pump_hp = float
		pump_watthr_per_lb = float
		pump_work = float
		pumpwork_inj = float
		pumpwork_prod = float
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
