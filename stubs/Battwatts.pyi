class BatteryModelSimple(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	batt_simple_chemistry = float
	batt_simple_dispatch = float
	batt_simple_enable = float
	batt_simple_kw = float
	batt_simple_kwh = float
	batt_simple_meter_position = float


class Common(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	ac = tuple
	dc = tuple
	inverter_efficiency = float
	inverter_model = float


class ElectricLoadOther(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	load = tuple


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
	gen = tuple
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


class Battwatts(object):
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

	BatteryModelSimple = BatteryModelSimple
	Common = Common
	ElectricLoadOther = ElectricLoadOther
	Outputs = Outputs


def default(config) -> Battwatts
	pass

def new() -> Battwatts
	pass

def wrap(ssc_data_t) -> Battwatts
	pass

__loader__ = None 

__spec__ = None
