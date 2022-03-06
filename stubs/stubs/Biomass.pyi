class Biomass(object):
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

	class Biopower(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		biopwr_emissions_avoided_cred = float
		biopwr_emissions_collection_fuel = float
		biopwr_emissions_grid_intensity = float
		biopwr_emissions_pre_chipopt = float
		biopwr_emissions_pre_grindopt = float
		biopwr_emissions_pre_pelletopt = float
		biopwr_emissions_transport_fuel = float
		biopwr_emissions_transport_legs = float
		biopwr_emissions_transport_long = float
		biopwr_emissions_transport_longmiles = float
		biopwr_emissions_transport_longopt = float
		biopwr_emissions_transport_predist = float
		biopwr_feedstock_additional_opt = float
		biopwr_feedstock_bagasse_frac = float
		biopwr_feedstock_bagasse_moisture = float
		biopwr_feedstock_barley_frac = float
		biopwr_feedstock_barley_moisture = float
		biopwr_feedstock_bit_frac = float
		biopwr_feedstock_bit_moisture = float
		biopwr_feedstock_collection_radius = float
		biopwr_feedstock_feedstock1_c = float
		biopwr_feedstock_feedstock1_frac = float
		biopwr_feedstock_feedstock1_h = float
		biopwr_feedstock_feedstock1_hhv = float
		biopwr_feedstock_feedstock1_moisture = float
		biopwr_feedstock_feedstock1_resource = float
		biopwr_feedstock_feedstock2_c = float
		biopwr_feedstock_feedstock2_frac = float
		biopwr_feedstock_feedstock2_h = float
		biopwr_feedstock_feedstock2_hhv = float
		biopwr_feedstock_feedstock2_moisture = float
		biopwr_feedstock_feedstock2_resource = float
		biopwr_feedstock_forest_frac = float
		biopwr_feedstock_forest_moisture = float
		biopwr_feedstock_herb_c = float
		biopwr_feedstock_herb_frac = float
		biopwr_feedstock_herb_moisture = float
		biopwr_feedstock_lig_frac = float
		biopwr_feedstock_lig_moisture = float
		biopwr_feedstock_mill_c = float
		biopwr_feedstock_mill_frac = float
		biopwr_feedstock_mill_moisture = float
		biopwr_feedstock_rice_frac = float
		biopwr_feedstock_rice_moisture = float
		biopwr_feedstock_stover_frac = float
		biopwr_feedstock_stover_moisture = float
		biopwr_feedstock_subbit_frac = float
		biopwr_feedstock_subbit_moisture = float
		biopwr_feedstock_total = float
		biopwr_feedstock_total_biomass = float
		biopwr_feedstock_total_biomass_c = float
		biopwr_feedstock_total_c = float
		biopwr_feedstock_total_coal = float
		biopwr_feedstock_total_h = float
		biopwr_feedstock_total_hhv = float
		biopwr_feedstock_total_lhv = float
		biopwr_feedstock_total_moisture = float
		biopwr_feedstock_urban_c = float
		biopwr_feedstock_urban_frac = float
		biopwr_feedstock_urban_moisture = float
		biopwr_feedstock_wheat_frac = float
		biopwr_feedstock_wheat_moisture = float
		biopwr_feedstock_woody_c = float
		biopwr_feedstock_woody_frac = float
		biopwr_feedstock_woody_moisture = float
		biopwr_plant_boiler_air_feed = float
		biopwr_plant_boiler_cap_per_boiler = float
		biopwr_plant_boiler_flue_temp = float
		biopwr_plant_boiler_num = float
		biopwr_plant_boiler_over_design = float
		biopwr_plant_boiler_steam_enthalpy = float
		biopwr_plant_boiler_steam_pressure = float
		biopwr_plant_combustor_type = float
		biopwr_plant_cycle_design_temp = float
		biopwr_plant_disp_power = tuple
		biopwr_plant_drying_method = float
		biopwr_plant_drying_spec = float
		biopwr_plant_max_over_design = float
		biopwr_plant_min_load = float
		biopwr_plant_nameplate = float
		biopwr_plant_par_percent = float
		biopwr_plant_pl_eff_f0 = float
		biopwr_plant_pl_eff_f1 = float
		biopwr_plant_pl_eff_f2 = float
		biopwr_plant_pl_eff_f3 = float
		biopwr_plant_pl_eff_f4 = float
		biopwr_plant_ramp_rate = float
		biopwr_plant_rated_eff = float
		biopwr_plant_temp_corr_mode = float
		biopwr_plant_temp_eff_f0 = float
		biopwr_plant_temp_eff_f1 = float
		biopwr_plant_temp_eff_f2 = float
		biopwr_plant_temp_eff_f3 = float
		biopwr_plant_temp_eff_f4 = float
		biopwr_plant_tou_grid = str
		biopwr_plant_tou_option = float
		file_name = str
		system_capacity = float


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


		annual_energy = float
		annual_energy_distribution_time = tuple
		annual_fuel_usage = float
		annual_watter_usage = float
		capacity_factor = float
		gen = tuple
		hourly_boiler_eff = tuple
		hourly_pbeta = tuple
		hourly_q_to_pb = tuple
		kwh_per_kw = float
		monthly_bagasse_emc = tuple
		monthly_barley_emc = tuple
		monthly_boiler_eff = tuple
		monthly_energy = tuple
		monthly_forest_emc = tuple
		monthly_herb_emc = tuple
		monthly_hhv_heatrate = tuple
		monthly_lhv_heatrate = tuple
		monthly_mill_emc = tuple
		monthly_moist = tuple
		monthly_pb_eta = tuple
		monthly_q_to_pb = tuple
		monthly_rh = tuple
		monthly_rice_emc = tuple
		monthly_stover_emc = tuple
		monthly_temp_c = tuple
		monthly_urban_emc = tuple
		monthly_wheat_emc = tuple
		monthly_woody_emc = tuple
		system_annual_ash = float
		system_annual_biomass = float
		system_annual_boiler_loss_dry = float
		system_annual_boiler_loss_dry_kwh = float
		system_annual_boiler_loss_fuel = float
		system_annual_boiler_loss_fuel_kwh = float
		system_annual_boiler_loss_manu = float
		system_annual_boiler_loss_manu_kwh = float
		system_annual_boiler_loss_rad = float
		system_annual_boiler_loss_rad_kwh = float
		system_annual_boiler_loss_total = float
		system_annual_boiler_loss_total_kwh = float
		system_annual_boiler_loss_unburn = float
		system_annual_boiler_loss_unburn_kwh = float
		system_annual_boiler_loss_wet = float
		system_annual_boiler_loss_wet_kwh = float
		system_annual_boiler_output = float
		system_annual_coal = float
		system_annual_e_net = float
		system_annual_par_loss = float
		system_annual_par_loss_kwh = float
		system_annual_pb_eta = float
		system_annual_pb_eta_kwh = float
		system_annual_qtoboil_tot = float
		system_annual_qtopb_tot = float
		system_annual_turbine_output = float
		system_capfactor = float
		system_emissions_avoided = float
		system_emissions_biodiesel = float
		system_emissions_bunker = float
		system_emissions_combustion = float
		system_emissions_diesel = float
		system_emissions_drying = float
		system_emissions_ems_per_lb = float
		system_emissions_growth = float
		system_emissions_lime = float
		system_emissions_naturalgas = float
		system_emissions_nitrogen = float
		system_emissions_oil = float
		system_emissions_phosphorus = float
		system_emissions_potassium = float
		system_emissions_preprocessing = float
		system_emissions_total_sum = float
		system_emissions_transport = float
		system_emissions_uptake = float
		system_heat_rate = float
		system_hhv_heatrate = float
		system_hhv_thermeff = float
		system_lhv_heatrate = float
		system_lhv_thermeff = float
		system_total_moisture = float




def default(config) -> Biomass:
	pass

def new() -> Biomass:
	pass

def wrap(ssc_data_t) -> Biomass:
	pass

def from_existing(model, config="") -> Biomass:
	pass

__loader__ = None 

__spec__ = None
