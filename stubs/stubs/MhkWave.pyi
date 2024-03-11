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

	def get_data_ptr(self):
		pass

	def __getattribute__(self, *args, **kwargs):
		pass

	def __init__(self, *args, **kwargs):
		pass

	class MHKWave(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		balance_of_system_cost_total = float
		day = tuple
		device_costs_total = float
		device_rated_power = float
		energy_period = tuple
		financial_cost_total = float
		fixed_charge_rate = float
		hour = tuple
		loss_additional = float
		loss_array_spacing = float
		loss_downtime = float
		loss_resource_overprediction = float
		loss_transmission = float
		minute = tuple
		month = tuple
		number_devices = float
		number_hours = float
		number_records = float
		significant_wave_height = tuple
		system_capacity = float
		total_operating_cost = float
		wave_power_matrix = tuple
		wave_resource_data = dict
		wave_resource_matrix = tuple
		wave_resource_model_choice = float
		year = tuple


	class AdjustmentFactors(object):
		def assign(self): 
			pass
	
		def export(self): 
			return {}
	
		def __init__(self, *args, **kwargs): # real signature unknown
			pass
	
		constant = float
		en_hourly = float
		en_periods = float
		en_timeindex = float
		hourly = tuple
		periods = tuple
		imeindex = tuple
		dc_constant = float
		dc_en_hourly = float
		dc_en_periods = float
		dc_en_timeindex = float
		dc_hourly = tuple
		dc_periods = tuple
		dc_imeindex = tuple
		sf_constant = float
		sf_en_hourly = float
		sf_en_periods = float
		sf_en_timeindex = float
		sf_hourly = tuple
		sf_periods = tuple
		sf_timeindex = tuple

	class Lifetime(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		analysis_period = float
		generic_degradation = tuple
		system_use_lifetime_output = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		annual_energy = float
		annual_energy_distribution = tuple
		annual_energy_distribution_time = tuple
		capacity_factor = float
		device_average_power = float
		energy_hourly_kW = tuple
		energy_hourly_kWh = tuple
		energy_period_data = tuple
		energy_period_index_mat = tuple
		gen = tuple
		numberHours = float
		numberRecords = float
		sig_wave_height_data = tuple
		sig_wave_height_index_mat = tuple
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
		wave_power_end_height = float
		wave_power_end_period = float
		wave_power_index_mat = tuple
		wave_power_start_height = float
		wave_power_start_period = float
		wave_resource_end_height = float
		wave_resource_end_period = float
		wave_resource_start_height = float
		wave_resource_start_period = float




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
