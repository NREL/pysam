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


	load_escalation = tuple


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
	gen = tuple
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

	def __getattribute__(self, *args, **kwargs):
		pass

	def __init__(self, *args, **kwargs):
		pass

	Lifetime = Lifetime
	Battery = Battery
	Load = Load
	Outputs = Outputs


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
