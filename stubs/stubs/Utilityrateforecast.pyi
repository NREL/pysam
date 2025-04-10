class Utilityrateforecast(object):
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

	class ElectricityRates(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		en_electricity_rates = float
		gen = tuple
		grid_power = tuple
		load = tuple
		rate_escalation = tuple
		ur_annual_min_charge = float
		ur_billing_demand_lookback_percentages = tuple
		ur_billing_demand_lookback_period = float
		ur_billing_demand_minimum = float
		ur_dc_billing_demand_periods = tuple
		ur_dc_enable = float
		ur_dc_flat_mat = tuple
		ur_dc_peaks = tuple
		ur_dc_sched_weekday = tuple
		ur_dc_sched_weekend = tuple
		ur_dc_tou_mat = tuple
		ur_ec_sched_weekday = tuple
		ur_ec_sched_weekend = tuple
		ur_ec_tou_mat = tuple
		ur_en_ts_buy_rate = float
		ur_en_ts_sell_rate = float
		ur_enable_billing_demand = float
		ur_energy_use = tuple
		ur_metering_option = float
		ur_monthly_fixed_charge = float
		ur_monthly_min_charge = float
		ur_nb_apply_credit_current_month = float
		ur_nb_credit_expire = float
		ur_nm_credit_month = float
		ur_nm_credit_rollover = float
		ur_nm_yearend_sell_rate = float
		ur_sell_eq_buy = float
		ur_ts_buy_rate = tuple
		ur_ts_sell_rate = tuple
		ur_yearzero_usage_peaks = tuple


	class Lifetime(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		analysis_period = float
		inflation_rate = float


	class Controls(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		idx = float
		steps_per_hour = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		ur_price_series = tuple
		ur_total_bill = float




def default(config) -> Utilityrateforecast:
	pass

def new() -> Utilityrateforecast:
	pass

def wrap(ssc_data_t) -> Utilityrateforecast:
	pass

def from_existing(model, config="") -> Utilityrateforecast:
	pass

__loader__ = None 

__spec__ = None
