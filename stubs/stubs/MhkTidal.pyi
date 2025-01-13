class MhkTidal(object):
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

	class MHKTidal(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		balance_of_system_cost_total = float
		device_costs_total = float
		financial_cost_total = float
		fixed_charge_rate = float
		loss_additional = float
		loss_array_spacing = float
		loss_downtime = float
		loss_resource_overprediction = float
		loss_transmission = float
		number_devices = float
		system_capacity = float
		tidal_power_curve = tuple
		tidal_resource = tuple
		tidal_resource_model_choice = float
		tidal_velocity = tuple
		total_operating_cost = float


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


		annual_cumulative_energy_distribution = tuple
		annual_energy = float
		annual_energy_distribution = tuple
		capacity_factor = float
		device_average_power = float
		device_rated_capacity = float
		gen = tuple
		tidal_power_end_velocity = float
		tidal_power_start_velocity = float
		tidal_resource_end_velocity = float
		tidal_resource_start_velocity = float
		total_bos_cost_kwh = float
		total_bos_cost_lcoe = float
		total_bos_cost_per_kw = float
		total_capital_cost_kwh = float
		total_capital_cost_lcoe = float
		total_capital_cost_per_kw = float
		total_device_cost_kwh = float
		total_device_cost_lcoe = float
		total_device_cost_per_kw = float
		total_financial_cost_kwh = float
		total_financial_cost_lcoe = float
		total_financial_cost_per_kw = float
		total_om_cost_kwh = float
		total_om_cost_lcoe = float
		total_operations_cost_per_kw = float




def default(config) -> MhkTidal:
	pass

def new() -> MhkTidal:
	pass

def wrap(ssc_data_t) -> MhkTidal:
	pass

def from_existing(model, config="") -> MhkTidal:
	pass

__loader__ = None 

__spec__ = None
