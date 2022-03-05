class Utilityrate5(object):
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

	class ElectricityRates(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		TOU_demand_single_peak = float
		en_electricity_rates = float
		rate_escalation = tuple
		ur_annual_min_charge = float
		ur_billing_demand_lookback_percentages = tuple
		ur_billing_demand_lookback_period = float
		ur_billing_demand_minimum = float
		ur_dc_billing_demand_periods = tuple
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
		ur_enable_billing_demand = float
		ur_metering_option = float
		ur_monthly_fixed_charge = float
		ur_monthly_min_charge = float
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
		system_use_lifetime_output = float


	class SystemOutput(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		degradation = tuple
		gen = tuple


	class Load(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		load = tuple
		load_escalation = tuple


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		annual_electric_load = tuple
		annual_energy_value = tuple
		bill_load = tuple
		billing_demand_w_sys_ym = tuple
		billing_demand_wo_sys_ym = tuple
		charge_w_sys_dc_fixed = tuple
		charge_w_sys_dc_fixed_ym = tuple
		charge_w_sys_dc_tou = tuple
		charge_w_sys_dc_tou_ym = tuple
		charge_w_sys_ec = tuple
		charge_w_sys_ec_apr_tp = tuple
		charge_w_sys_ec_aug_tp = tuple
		charge_w_sys_ec_dec_tp = tuple
		charge_w_sys_ec_feb_tp = tuple
		charge_w_sys_ec_gross_ym = tuple
		charge_w_sys_ec_jan_tp = tuple
		charge_w_sys_ec_jul_tp = tuple
		charge_w_sys_ec_jun_tp = tuple
		charge_w_sys_ec_mar_tp = tuple
		charge_w_sys_ec_may_tp = tuple
		charge_w_sys_ec_nov_tp = tuple
		charge_w_sys_ec_oct_tp = tuple
		charge_w_sys_ec_sep_tp = tuple
		charge_w_sys_ec_ym = tuple
		charge_w_sys_fixed = tuple
		charge_w_sys_fixed_ym = tuple
		charge_w_sys_minimum = tuple
		charge_w_sys_minimum_ym = tuple
		charge_wo_sys_dc_fixed = tuple
		charge_wo_sys_dc_fixed_ym = tuple
		charge_wo_sys_dc_tou = tuple
		charge_wo_sys_dc_tou_ym = tuple
		charge_wo_sys_ec = tuple
		charge_wo_sys_ec_apr_tp = tuple
		charge_wo_sys_ec_aug_tp = tuple
		charge_wo_sys_ec_dec_tp = tuple
		charge_wo_sys_ec_feb_tp = tuple
		charge_wo_sys_ec_jan_tp = tuple
		charge_wo_sys_ec_jul_tp = tuple
		charge_wo_sys_ec_jun_tp = tuple
		charge_wo_sys_ec_mar_tp = tuple
		charge_wo_sys_ec_may_tp = tuple
		charge_wo_sys_ec_nov_tp = tuple
		charge_wo_sys_ec_oct_tp = tuple
		charge_wo_sys_ec_sep_tp = tuple
		charge_wo_sys_ec_ym = tuple
		charge_wo_sys_fixed = tuple
		charge_wo_sys_fixed_ym = tuple
		charge_wo_sys_minimum = tuple
		charge_wo_sys_minimum_ym = tuple
		elec_cost_with_system = tuple
		elec_cost_with_system_year1 = float
		elec_cost_without_system = tuple
		elec_cost_without_system_year1 = float
		energy_w_sys_ec_apr_tp = tuple
		energy_w_sys_ec_aug_tp = tuple
		energy_w_sys_ec_dec_tp = tuple
		energy_w_sys_ec_feb_tp = tuple
		energy_w_sys_ec_jan_tp = tuple
		energy_w_sys_ec_jul_tp = tuple
		energy_w_sys_ec_jun_tp = tuple
		energy_w_sys_ec_mar_tp = tuple
		energy_w_sys_ec_may_tp = tuple
		energy_w_sys_ec_nov_tp = tuple
		energy_w_sys_ec_oct_tp = tuple
		energy_w_sys_ec_sep_tp = tuple
		energy_wo_sys_ec_apr_tp = tuple
		energy_wo_sys_ec_aug_tp = tuple
		energy_wo_sys_ec_dec_tp = tuple
		energy_wo_sys_ec_feb_tp = tuple
		energy_wo_sys_ec_jan_tp = tuple
		energy_wo_sys_ec_jul_tp = tuple
		energy_wo_sys_ec_jun_tp = tuple
		energy_wo_sys_ec_mar_tp = tuple
		energy_wo_sys_ec_may_tp = tuple
		energy_wo_sys_ec_nov_tp = tuple
		energy_wo_sys_ec_oct_tp = tuple
		energy_wo_sys_ec_sep_tp = tuple
		excess_kwhs_earned_ym = tuple
		lifetime_load = tuple
		monthly_tou_demand_charge_w_sys = tuple
		monthly_tou_demand_charge_wo_sys = tuple
		monthly_tou_demand_peak_w_sys = tuple
		monthly_tou_demand_peak_wo_sys = tuple
		net_billing_credits_ym = tuple
		nm_dollars_applied_ym = tuple
		savings_year1 = float
		surplus_w_sys_ec_apr_tp = tuple
		surplus_w_sys_ec_aug_tp = tuple
		surplus_w_sys_ec_dec_tp = tuple
		surplus_w_sys_ec_feb_tp = tuple
		surplus_w_sys_ec_jan_tp = tuple
		surplus_w_sys_ec_jul_tp = tuple
		surplus_w_sys_ec_jun_tp = tuple
		surplus_w_sys_ec_mar_tp = tuple
		surplus_w_sys_ec_may_tp = tuple
		surplus_w_sys_ec_nov_tp = tuple
		surplus_w_sys_ec_oct_tp = tuple
		surplus_w_sys_ec_sep_tp = tuple
		true_up_credits_ym = tuple
		two_meter_sales_ym = tuple
		utility_bill_w_sys = tuple
		utility_bill_w_sys_ym = tuple
		utility_bill_wo_sys = tuple
		utility_bill_wo_sys_ym = tuple
		year1_billing_demand_w_sys = tuple
		year1_billing_demand_wo_sys = tuple
		year1_electric_load = float
		year1_excess_kwhs_earned = tuple
		year1_hourly_dc_peak_per_period = tuple
		year1_hourly_dc_tou_schedule = tuple
		year1_hourly_dc_with_system = tuple
		year1_hourly_dc_without_system = tuple
		year1_hourly_e_fromgrid = tuple
		year1_hourly_e_tofromgrid = tuple
		year1_hourly_e_togrid = tuple
		year1_hourly_ec_tou_schedule = tuple
		year1_hourly_ec_with_system = tuple
		year1_hourly_ec_without_system = tuple
		year1_hourly_p_system_to_load = tuple
		year1_hourly_p_tofromgrid = tuple
		year1_hourly_salespurchases_with_system = tuple
		year1_hourly_salespurchases_without_system = tuple
		year1_hourly_system_to_load = tuple
		year1_monthly_cumulative_excess_generation = tuple
		year1_monthly_dc_fixed_with_system = tuple
		year1_monthly_dc_fixed_without_system = tuple
		year1_monthly_dc_tou_with_system = tuple
		year1_monthly_dc_tou_without_system = tuple
		year1_monthly_ec_charge_gross_with_system = tuple
		year1_monthly_ec_charge_with_system = tuple
		year1_monthly_ec_charge_without_system = tuple
		year1_monthly_electricity_to_grid = tuple
		year1_monthly_fixed_with_system = tuple
		year1_monthly_fixed_without_system = tuple
		year1_monthly_load = tuple
		year1_monthly_minimum_with_system = tuple
		year1_monthly_minimum_without_system = tuple
		year1_monthly_peak_w_system = tuple
		year1_monthly_peak_wo_system = tuple
		year1_monthly_use_w_system = tuple
		year1_monthly_use_wo_system = tuple
		year1_monthly_utility_bill_w_sys = tuple
		year1_monthly_utility_bill_wo_sys = tuple
		year1_net_billing_credits = tuple
		year1_nm_dollars_applied = tuple
		year1_true_up_credits = tuple
		year1_two_meter_sales = tuple




def default(config) -> Utilityrate5:
	pass

def new() -> Utilityrate5:
	pass

def wrap(ssc_data_t) -> Utilityrate5:
	pass

def from_existing(model, config="") -> Utilityrate5:
	pass

__loader__ = None 

__spec__ = None
