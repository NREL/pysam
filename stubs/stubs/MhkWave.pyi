class MHKWave(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	balance_of_system_cost_total = float
	device_costs_total = float
	device_rated_power = float
	financial_cost_total = float
	fixed_charge_rate = float
	loss_additional = float
	loss_array_spacing = float
	loss_downtime = float
	loss_resource_overprediction = float
	loss_transmission = float
	number_devices = float
	system_capacity = float
	total_operating_cost = float
	wave_power_matrix = tuple
	wave_resource_matrix = tuple


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	annual_energy = float
	annual_energy_distribution = tuple
	capacity_factor = float
	device_average_power = float
	total_bos_cost_kwh = float
	total_bos_cost_lcoe = float
	total_capital_cost_kwh = float
	total_capital_cost_lcoe = float
	total_device_cost_kwh = float
	total_device_cost_lcoe = float
	total_financial_cost_kwh = float
	total_financial_cost_lcoe = float
	total_om_cost_kwh = float
	total_om_cost_lcoe = float
	wave_power_end_height = float
	wave_power_end_period = float
	wave_power_start_height = float
	wave_power_start_period = float
	wave_resource_end_height = float
	wave_resource_end_period = float
	wave_resource_start_height = float
	wave_resource_start_period = float


class MhkWave(object):
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

	MHKWave = MHKWave
	Outputs = Outputs


def default(config) -> MhkWave:
	pass

def new() -> MhkWave:
	pass

def wrap(ssc_data_t) -> MhkWave:
	pass

def from_existing(model, config="") -> MhkWave:
	pass

__loader__ = None 

__spec__ = None
