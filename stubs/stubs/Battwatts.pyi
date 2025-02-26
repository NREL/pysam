class Battwatts(object):
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

	class Lifetime(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		analysis_period = float
		system_use_lifetime_output = float


	class Battery(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		ac = tuple
		batt_custom_dispatch = tuple
		batt_simple_chemistry = float
		batt_simple_dispatch = float
		batt_simple_enable = float
		batt_simple_kw = float
		batt_simple_kwh = float
		batt_simple_meter_position = float
		crit_load = tuple
		dc = tuple
		inverter_efficiency = float
		load = tuple


	class Load(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		grid_outage = tuple
		load_escalation = tuple
		run_resiliency_calcs = float


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

	class GridLimits(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		enable_interconnection_limit = float
		grid_curtailment = tuple
		grid_interconnection_limit_kwac = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		annual_crit_load = float
		annual_crit_load_unmet = float
		annual_crit_load_unmet_percentage = float
		annual_energy_distribution_time = tuple
		annual_export_to_grid_energy = tuple
		annual_import_to_grid_energy = tuple
		annual_outage_losses_unmet = float
		average_battery_conversion_efficiency = float
		average_battery_roundtrip_efficiency = float
		avg_critical_load = float
		batt_DOD = tuple
		batt_DOD_cycle_average = tuple
		batt_I = tuple
		batt_SOC = tuple
		batt_annual_charge_energy = tuple
		batt_annual_charge_from_grid = tuple
		batt_annual_charge_from_system = tuple
		batt_annual_discharge_energy = tuple
		batt_annual_energy_loss = tuple
		batt_annual_energy_system_loss = tuple
		batt_availability_loss = tuple
		batt_bank_installed_capacity = float
		batt_bank_replacement = tuple
		batt_capacity_percent = tuple
		batt_capacity_percent_calendar = tuple
		batt_capacity_percent_cycle = tuple
		batt_capacity_thermal_percent = tuple
		batt_conversion_loss = tuple
		batt_cost_to_cycle = tuple
		batt_cycles = tuple
		batt_dispatch_sched = tuple
		batt_grid_charge_percent = float
		batt_power = tuple
		batt_power_dc = tuple
		batt_power_target = tuple
		batt_pvs_PV_ramp_interval = tuple
		batt_pvs_P_pv_ac = tuple
		batt_pvs_battpower = tuple
		batt_pvs_battsoc = tuple
		batt_pvs_curtail = tuple
		batt_pvs_energy_to_grid_percent = float
		batt_pvs_energy_to_grid_percent_sam = float
		batt_pvs_forecast_pv_energy = tuple
		batt_pvs_outpower = tuple
		batt_pvs_violation_count = float
		batt_pvs_violation_list = tuple
		batt_pvs_violation_percent = float
		batt_q0 = tuple
		batt_q1 = tuple
		batt_q2 = tuple
		batt_qmax = tuple
		batt_qmaxI = tuple
		batt_qmax_thermal = tuple
		batt_revenue_charge = tuple
		batt_revenue_clipcharge = tuple
		batt_revenue_discharge = tuple
		batt_revenue_gridcharge = tuple
		batt_system_charge_percent = float
		batt_system_loss = tuple
		batt_temperature = tuple
		batt_to_grid = tuple
		batt_to_inverter_dc = tuple
		batt_to_load = tuple
		batt_to_system_load = tuple
		batt_voltage = tuple
		batt_voltage_cell = tuple
		batt_year1_charge_from_grid = float
		batt_year1_charge_from_system = float
		cdf_of_surviving = tuple
		crit_load = tuple
		crit_load_unmet = tuple
		fuelcell_to_batt = tuple
		gen = tuple
		gen_without_battery = tuple
		grid_power = tuple
		grid_power_target = tuple
		grid_to_batt = tuple
		grid_to_load = tuple
		interconnection_loss = tuple
		market_sell_rate_series_yr1 = tuple
		monthly_batt_to_grid = tuple
		monthly_batt_to_load = tuple
		monthly_batt_to_system_load = tuple
		monthly_crit_load = tuple
		monthly_crit_load_unmet = tuple
		monthly_crit_load_unmet_percentage = tuple
		monthly_grid_to_batt = tuple
		monthly_grid_to_load = tuple
		monthly_interconnection_loss = tuple
		monthly_outage_losses_unmet = tuple
		monthly_system_to_batt = tuple
		monthly_system_to_grid = tuple
		monthly_system_to_load = tuple
		num_ts_load_met_by_system_lifetime = float
		num_ts_load_met_by_system_yr1 = float
		outage_durations = tuple
		outage_losses_unmet = tuple
		pdf_of_surviving = tuple
		percent_ts_load_met_by_system_lifetime = float
		percent_ts_load_met_by_system_yr1 = float
		resilience_hrs = tuple
		resilience_hrs_avg = float
		resilience_hrs_max = float
		resilience_hrs_min = float
		survival_function = tuple
		system_to_batt = tuple
		system_to_batt_dc = tuple
		system_to_grid = tuple
		system_to_load = tuple




def default(config) -> Battwatts:
	pass

def new() -> Battwatts:
	pass

def wrap(ssc_data_t) -> Battwatts:
	pass

def from_existing(model, config="") -> Battwatts:
	pass

__loader__ = None 

__spec__ = None
