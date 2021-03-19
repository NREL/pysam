class Simulation(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	percent_complete = float


class Lifetime(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	analysis_period = float
	inflation_rate = float
	system_use_lifetime_output = float


class BatterySystem(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	batt_ac_dc_efficiency = float
	batt_ac_or_dc = float
	batt_computed_bank_capacity = float
	batt_computed_series = float
	batt_computed_strings = float
	batt_current_charge_max = float
	batt_current_choice = float
	batt_current_discharge_max = float
	batt_dc_ac_efficiency = float
	batt_dc_dc_efficiency = float
	batt_inverter_efficiency_cutoff = float
	batt_loss_choice = float
	batt_losses = tuple
	batt_losses_charging = tuple
	batt_losses_discharging = tuple
	batt_losses_idle = tuple
	batt_mass = float
	batt_meter_position = float
	batt_power_charge_max_kwac = float
	batt_power_charge_max_kwdc = float
	batt_power_discharge_max_kwac = float
	batt_power_discharge_max_kwdc = float
	batt_replacement_capacity = float
	batt_replacement_option = float
	batt_replacement_schedule_percent = tuple
	batt_surface_area = float
	en_batt = float
	om_replacement_cost1 = tuple


class SystemOutput(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	annual_energy = float
	capacity_factor = float
	gen = tuple


class Load(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	crit_load = tuple
	load = tuple
	load_escalation = tuple


class BatteryCell(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	LeadAcid_q10_computed = float
	LeadAcid_q20_computed = float
	LeadAcid_qn_computed = float
	LeadAcid_tn = float
	batt_C_rate = float
	batt_Cp = float
	batt_Qexp = float
	batt_Qfull = float
	batt_Qfull_flow = float
	batt_Qnom = float
	batt_Vcut = float
	batt_Vexp = float
	batt_Vfull = float
	batt_Vnom = float
	batt_Vnom_default = float
	batt_calendar_a = float
	batt_calendar_b = float
	batt_calendar_c = float
	batt_calendar_choice = float
	batt_calendar_lifetime_matrix = tuple
	batt_calendar_q0 = float
	batt_chem = float
	batt_h_to_ambient = float
	batt_initial_SOC = float
	batt_life_model = float
	batt_lifetime_matrix = tuple
	batt_maximum_SOC = float
	batt_minimum_SOC = float
	batt_minimum_modetime = float
	batt_resistance = float
	batt_room_temperature_celsius = tuple
	batt_voltage_choice = float
	batt_voltage_matrix = tuple
	cap_vs_temp = tuple


class Inverter(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	inv_cec_cg_eff_cec = float
	inv_cec_cg_paco = float
	inv_ds_eff = float
	inv_ds_paco = float
	inv_pd_eff = float
	inv_pd_paco = float
	inv_snl_eff_cec = float
	inv_snl_paco = float
	inverter_count = float
	inverter_model = float


class Losses(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	dcoptimizer_loss = float


class BatteryDispatch(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	batt_auto_gridcharge_max_daily = float
	batt_custom_dispatch = tuple
	batt_cycle_cost = tuple
	batt_cycle_cost_choice = float
	batt_dispatch_auto_can_charge = float
	batt_dispatch_auto_can_clipcharge = float
	batt_dispatch_auto_can_fuelcellcharge = float
	batt_dispatch_auto_can_gridcharge = float
	batt_dispatch_choice = float
	batt_dispatch_update_frequency_hours = float
	batt_look_ahead_hours = float
	batt_pv_ac_forecast = tuple
	batt_pv_clipping_forecast = tuple
	batt_target_choice = float
	batt_target_power = tuple
	batt_target_power_monthly = tuple
	dispatch_manual_charge = tuple
	dispatch_manual_discharge = tuple
	dispatch_manual_fuelcellcharge = tuple
	dispatch_manual_gridcharge = tuple
	dispatch_manual_percent_discharge = tuple
	dispatch_manual_percent_gridcharge = tuple
	dispatch_manual_sched = tuple
	dispatch_manual_sched_weekend = tuple


class FuelCell(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	fuelcell_power = tuple


class PriceSignal(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	dispatch_factors_ts = tuple
	dispatch_sched_weekday = tuple
	dispatch_sched_weekend = tuple
	dispatch_tod_factors = tuple
	forecast_price_signal_model = float
	mp_ancserv1_revenue = tuple
	mp_ancserv2_revenue = tuple
	mp_ancserv3_revenue = tuple
	mp_ancserv4_revenue = tuple
	mp_enable_ancserv1 = float
	mp_enable_ancserv2 = float
	mp_enable_ancserv3 = float
	mp_enable_ancserv4 = float
	mp_enable_energy_market_revenue = float
	mp_energy_market_revenue = tuple
	ppa_multiplier_model = float
	ppa_price_input = tuple


class ElectricityRates(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	rate_escalation = tuple
	ur_annual_min_charge = float
	ur_dc_enable = float
	ur_dc_flat_mat = tuple
	ur_dc_sched_weekday = tuple
	ur_dc_sched_weekend = tuple
	ur_dc_tou_mat = tuple
	ur_ec_sched_weekday = tuple
	ur_ec_sched_weekend = tuple
	ur_ec_tou_mat = tuple
	ur_en_ts_buy_rate = float
	ur_en_ts_sell_rate = float
	ur_metering_option = float
	ur_monthly_fixed_charge = float
	ur_monthly_min_charge = float
	ur_nm_credit_month = float
	ur_nm_credit_rollover = float
	ur_nm_yearend_sell_rate = float
	ur_sell_eq_buy = float
	ur_ts_buy_rate = tuple
	ur_ts_sell_rate = tuple


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	annual_export_to_grid_energy = tuple
	annual_import_to_grid_energy = tuple
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
	batt_power = tuple
	batt_power_target = tuple
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
	batt_to_load = tuple
	batt_voltage = tuple
	batt_voltage_cell = tuple
	cdf_of_surviving = tuple
	fuelcell_to_batt = tuple
	gen_without_battery = tuple
	grid_power = tuple
	grid_power_target = tuple
	grid_to_batt = tuple
	grid_to_load = tuple
	market_sell_rate_series_yr1 = tuple
	monthly_batt_to_grid = tuple
	monthly_batt_to_load = tuple
	monthly_grid_to_batt = tuple
	monthly_grid_to_load = tuple
	monthly_system_to_batt = tuple
	monthly_system_to_grid = tuple
	monthly_system_to_load = tuple
	outage_durations = tuple
	pdf_of_surviving = tuple
	resilience_hrs = tuple
	resilience_hrs_avg = float
	resilience_hrs_max = float
	resilience_hrs_min = float
	survival_function = tuple
	system_to_batt = tuple
	system_to_grid = tuple
	system_to_load = tuple


class Battery(object):
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

	Simulation = Simulation
	Lifetime = Lifetime
	BatterySystem = BatterySystem
	SystemOutput = SystemOutput
	Load = Load
	BatteryCell = BatteryCell
	Inverter = Inverter
	Losses = Losses
	BatteryDispatch = BatteryDispatch
	FuelCell = FuelCell
	PriceSignal = PriceSignal
	ElectricityRates = ElectricityRates
	Outputs = Outputs


def default(config) -> Battery:
	pass

def new() -> Battery:
	pass

def wrap(ssc_data_t) -> Battery:
	pass

def from_existing(model, config="") -> Battery:
	pass

__loader__ = None 

__spec__ = None
