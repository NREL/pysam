class Simulation(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	analysis_period = float
	percent_complete = float
	system_use_lifetime_output = float


class Battery(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	LeadAcid_q10_computed = float
	LeadAcid_q20_computed = float
	LeadAcid_qn_computed = float
	LeadAcid_tn = float
	annual_energy = float
	batt_C_rate = float
	batt_Cp = float
	batt_Qexp = float
	batt_Qfull = float
	batt_Qfull_flow = float
	batt_Qnom = float
	batt_Vexp = float
	batt_Vfull = float
	batt_Vnom = float
	batt_Vnom_default = float
	batt_ac_dc_efficiency = float
	batt_ac_or_dc = float
	batt_auto_gridcharge_max_daily = float
	batt_calendar_a = float
	batt_calendar_b = float
	batt_calendar_c = float
	batt_calendar_choice = float
	batt_calendar_lifetime_matrix = tuple
	batt_calendar_q0 = float
	batt_chem = float
	batt_computed_bank_capacity = float
	batt_computed_series = float
	batt_computed_strings = float
	batt_current_charge_max = float
	batt_current_choice = float
	batt_current_discharge_max = float
	batt_custom_dispatch = tuple
	batt_cycle_cost = float
	batt_cycle_cost_choice = float
	batt_dc_ac_efficiency = float
	batt_dc_dc_efficiency = float
	batt_dispatch_auto_can_charge = float
	batt_dispatch_auto_can_clipcharge = float
	batt_dispatch_auto_can_fuelcellcharge = float
	batt_dispatch_auto_can_gridcharge = float
	batt_dispatch_choice = float
	batt_dispatch_update_frequency_hours = float
	batt_h_to_ambient = float
	batt_height = float
	batt_initial_SOC = float
	batt_length = float
	batt_lifetime_matrix = tuple
	batt_look_ahead_hours = float
	batt_loss_choice = float
	batt_losses = tuple
	batt_losses_charging = tuple
	batt_losses_discharging = tuple
	batt_losses_idle = tuple
	batt_mass = float
	batt_maximum_SOC = float
	batt_meter_position = float
	batt_minimum_SOC = float
	batt_minimum_modetime = float
	batt_power_charge_max = float
	batt_power_discharge_max = float
	batt_pv_clipping_forecast = tuple
	batt_pv_dc_forecast = tuple
	batt_replacement_capacity = float
	batt_replacement_option = float
	batt_replacement_schedule = tuple
	batt_resistance = float
	batt_room_temperature_celsius = tuple
	batt_target_choice = float
	batt_target_power = tuple
	batt_target_power_monthly = tuple
	batt_voltage_choice = float
	batt_voltage_matrix = tuple
	batt_width = float
	cap_vs_temp = tuple
	dispatch_manual_charge = tuple
	dispatch_manual_discharge = tuple
	dispatch_manual_gridcharge = tuple
	dispatch_manual_percent_discharge = tuple
	dispatch_manual_percent_gridcharge = tuple
	dispatch_manual_sched = tuple
	dispatch_manual_sched_weekend = tuple
	en_batt = float
	om_replacement_cost1 = tuple


class System(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	capacity_factor = float
	gen = tuple


class ElectricLoad(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	load = tuple


class Common(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	inverter_model = float


class Inverter(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
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


class PV(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	dcoptimizer_loss = float


class FuelCell(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	dispatch_manual_fuelcellcharge = tuple
	fuelcell_power = tuple


class ElectricityRate(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	en_electricity_rates = float
	ur_ec_sched_weekday = tuple
	ur_ec_sched_weekend = tuple
	ur_ec_tou_mat = tuple


class EnergyMarket(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	dispatch_sched_weekday = tuple
	dispatch_sched_weekend = tuple
	dispatch_tod_factors = tuple
	ppa_price_input = float


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	annual_export_to_grid_energy = tuple
	annual_import_to_grid_energy = tuple
	average_battery_conversion_efficiency = float
	average_battery_roundtrip_efficiency = float
	batt_DOD = tuple
	batt_I = tuple
	batt_SOC = tuple
	batt_annual_charge_energy = tuple
	batt_annual_charge_from_grid = tuple
	batt_annual_charge_from_pv = tuple
	batt_annual_discharge_energy = tuple
	batt_annual_energy_loss = tuple
	batt_annual_energy_system_loss = tuple
	batt_bank_installed_capacity = float
	batt_bank_replacement = tuple
	batt_capacity_percent = tuple
	batt_capacity_thermal_percent = tuple
	batt_conversion_loss = tuple
	batt_cost_to_cycle = tuple
	batt_cycles = tuple
	batt_dispatch_sched = tuple
	batt_power = tuple
	batt_power_target = tuple
	batt_pv_charge_percent = float
	batt_q0 = tuple
	batt_q1 = tuple
	batt_q2 = tuple
	batt_qmax = tuple
	batt_qmaxI = tuple
	batt_qmax_thermal = tuple
	batt_system_loss = tuple
	batt_temperature = tuple
	batt_to_grid = tuple
	batt_to_load = tuple
	batt_voltage = tuple
	batt_voltage_cell = tuple
	fuelcell_to_batt = tuple
	grid_power = tuple
	grid_power_target = tuple
	grid_to_batt = tuple
	grid_to_load = tuple
	monthly_batt_to_grid = tuple
	monthly_batt_to_load = tuple
	monthly_grid_to_batt = tuple
	monthly_grid_to_load = tuple
	monthly_pv_to_batt = tuple
	monthly_pv_to_grid = tuple
	monthly_pv_to_load = tuple
	pv_to_batt = tuple
	pv_to_grid = tuple
	pv_to_load = tuple


class StandAloneBattery(object):
	def assign(self, dict):
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
	Battery = Battery
	System = System
	ElectricLoad = ElectricLoad
	Common = Common
	Inverter = Inverter
	PV = PV
	FuelCell = FuelCell
	ElectricityRate = ElectricityRate
	EnergyMarket = EnergyMarket
	Outputs = Outputs


def default(config) -> StandAloneBattery
	pass

def new() -> StandAloneBattery
	pass

def wrap(ssc_data_t) -> StandAloneBattery
	pass

__loader__ = None 

__spec__ = None
