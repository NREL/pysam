class Utilityrate(object):
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

	class Common(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		analysis_period = float
		e_with_system = tuple
		e_without_system = tuple
		load_escalation = tuple
		p_with_system = tuple
		p_without_system = tuple
		rate_escalation = tuple
		system_availability = tuple
		system_degradation = tuple
		ur_dc_enable = float
		ur_dc_fixed_m1 = float
		ur_dc_fixed_m10 = float
		ur_dc_fixed_m11 = float
		ur_dc_fixed_m12 = float
		ur_dc_fixed_m2 = float
		ur_dc_fixed_m3 = float
		ur_dc_fixed_m4 = float
		ur_dc_fixed_m5 = float
		ur_dc_fixed_m6 = float
		ur_dc_fixed_m7 = float
		ur_dc_fixed_m8 = float
		ur_dc_fixed_m9 = float
		ur_dc_p1 = float
		ur_dc_p2 = float
		ur_dc_p3 = float
		ur_dc_p4 = float
		ur_dc_p5 = float
		ur_dc_p6 = float
		ur_dc_p7 = float
		ur_dc_p8 = float
		ur_dc_p9 = float
		ur_dc_sched_weekday = str
		ur_dc_sched_weekend = str
		ur_flat_buy_rate = float
		ur_flat_sell_rate = float
		ur_monthly_fixed_charge = float
		ur_sell_eq_buy = float
		ur_tou_enable = float
		ur_tou_p1_buy_rate = float
		ur_tou_p1_sell_rate = float
		ur_tou_p2_buy_rate = float
		ur_tou_p2_sell_rate = float
		ur_tou_p3_buy_rate = float
		ur_tou_p3_sell_rate = float
		ur_tou_p4_buy_rate = float
		ur_tou_p4_sell_rate = float
		ur_tou_p5_buy_rate = float
		ur_tou_p5_sell_rate = float
		ur_tou_p6_buy_rate = float
		ur_tou_p6_sell_rate = float
		ur_tou_p7_buy_rate = float
		ur_tou_p7_sell_rate = float
		ur_tou_p8_buy_rate = float
		ur_tou_p8_sell_rate = float
		ur_tou_p9_buy_rate = float
		ur_tou_p9_sell_rate = float
		ur_tou_sched_weekday = str
		ur_tou_sched_weekend = str
		ur_tr_enable = float
		ur_tr_s1_energy_ub1 = float
		ur_tr_s1_energy_ub2 = float
		ur_tr_s1_energy_ub3 = float
		ur_tr_s1_energy_ub4 = float
		ur_tr_s1_energy_ub5 = float
		ur_tr_s1_energy_ub6 = float
		ur_tr_s1_rate1 = float
		ur_tr_s1_rate2 = float
		ur_tr_s1_rate3 = float
		ur_tr_s1_rate4 = float
		ur_tr_s1_rate5 = float
		ur_tr_s1_rate6 = float
		ur_tr_s2_energy_ub1 = float
		ur_tr_s2_energy_ub2 = float
		ur_tr_s2_energy_ub3 = float
		ur_tr_s2_energy_ub4 = float
		ur_tr_s2_energy_ub5 = float
		ur_tr_s2_energy_ub6 = float
		ur_tr_s2_rate1 = float
		ur_tr_s2_rate2 = float
		ur_tr_s2_rate3 = float
		ur_tr_s2_rate4 = float
		ur_tr_s2_rate5 = float
		ur_tr_s2_rate6 = float
		ur_tr_s3_energy_ub1 = float
		ur_tr_s3_energy_ub2 = float
		ur_tr_s3_energy_ub3 = float
		ur_tr_s3_energy_ub4 = float
		ur_tr_s3_energy_ub5 = float
		ur_tr_s3_energy_ub6 = float
		ur_tr_s3_rate1 = float
		ur_tr_s3_rate2 = float
		ur_tr_s3_rate3 = float
		ur_tr_s3_rate4 = float
		ur_tr_s3_rate5 = float
		ur_tr_s3_rate6 = float
		ur_tr_s4_energy_ub1 = float
		ur_tr_s4_energy_ub2 = float
		ur_tr_s4_energy_ub3 = float
		ur_tr_s4_energy_ub4 = float
		ur_tr_s4_energy_ub5 = float
		ur_tr_s4_energy_ub6 = float
		ur_tr_s4_rate1 = float
		ur_tr_s4_rate2 = float
		ur_tr_s4_rate3 = float
		ur_tr_s4_rate4 = float
		ur_tr_s4_rate5 = float
		ur_tr_s4_rate6 = float
		ur_tr_s5_energy_ub1 = float
		ur_tr_s5_energy_ub2 = float
		ur_tr_s5_energy_ub3 = float
		ur_tr_s5_energy_ub4 = float
		ur_tr_s5_energy_ub5 = float
		ur_tr_s5_energy_ub6 = float
		ur_tr_s5_rate1 = float
		ur_tr_s5_rate2 = float
		ur_tr_s5_rate3 = float
		ur_tr_s5_rate4 = float
		ur_tr_s5_rate5 = float
		ur_tr_s5_rate6 = float
		ur_tr_s6_energy_ub1 = float
		ur_tr_s6_energy_ub2 = float
		ur_tr_s6_energy_ub3 = float
		ur_tr_s6_energy_ub4 = float
		ur_tr_s6_energy_ub5 = float
		ur_tr_s6_energy_ub6 = float
		ur_tr_s6_rate1 = float
		ur_tr_s6_rate2 = float
		ur_tr_s6_rate3 = float
		ur_tr_s6_rate4 = float
		ur_tr_s6_rate5 = float
		ur_tr_s6_rate6 = float
		ur_tr_sched_m1 = float
		ur_tr_sched_m10 = float
		ur_tr_sched_m11 = float
		ur_tr_sched_m12 = float
		ur_tr_sched_m2 = float
		ur_tr_sched_m3 = float
		ur_tr_sched_m4 = float
		ur_tr_sched_m5 = float
		ur_tr_sched_m6 = float
		ur_tr_sched_m7 = float
		ur_tr_sched_m8 = float
		ur_tr_sched_m9 = float
		ur_tr_sell_mode = float
		ur_tr_sell_rate = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		charge_dc_fixed_apr = tuple
		charge_dc_fixed_aug = tuple
		charge_dc_fixed_dec = tuple
		charge_dc_fixed_feb = tuple
		charge_dc_fixed_jan = tuple
		charge_dc_fixed_jul = tuple
		charge_dc_fixed_jun = tuple
		charge_dc_fixed_mar = tuple
		charge_dc_fixed_may = tuple
		charge_dc_fixed_nov = tuple
		charge_dc_fixed_oct = tuple
		charge_dc_fixed_sep = tuple
		charge_dc_tou_apr = tuple
		charge_dc_tou_aug = tuple
		charge_dc_tou_dec = tuple
		charge_dc_tou_feb = tuple
		charge_dc_tou_jan = tuple
		charge_dc_tou_jul = tuple
		charge_dc_tou_jun = tuple
		charge_dc_tou_mar = tuple
		charge_dc_tou_may = tuple
		charge_dc_tou_nov = tuple
		charge_dc_tou_oct = tuple
		charge_dc_tou_sep = tuple
		charge_tr_apr = tuple
		charge_tr_aug = tuple
		charge_tr_dec = tuple
		charge_tr_feb = tuple
		charge_tr_jan = tuple
		charge_tr_jul = tuple
		charge_tr_jun = tuple
		charge_tr_mar = tuple
		charge_tr_may = tuple
		charge_tr_nov = tuple
		charge_tr_oct = tuple
		charge_tr_sep = tuple
		elec_cost_with_system = tuple
		elec_cost_without_system = tuple
		energy_net = tuple
		energy_value = tuple
		revenue_with_system = tuple
		revenue_without_system = tuple
		year1_hourly_e_demand = tuple
		year1_hourly_e_grid = tuple
		year1_hourly_income_with_system = tuple
		year1_hourly_income_without_system = tuple
		year1_hourly_p_demand = tuple
		year1_hourly_p_grid = tuple
		year1_hourly_p_system_to_load = tuple
		year1_hourly_payment_with_system = tuple
		year1_hourly_payment_without_system = tuple
		year1_hourly_price_with_system = tuple
		year1_hourly_price_without_system = tuple
		year1_hourly_revenue_with_system = tuple
		year1_hourly_revenue_without_system = tuple
		year1_hourly_system_output = tuple
		year1_hourly_system_to_grid = tuple
		year1_hourly_system_to_load = tuple
		year1_monthly_dc_fixed_with_system = tuple
		year1_monthly_dc_fixed_without_system = tuple
		year1_monthly_dc_tou_with_system = tuple
		year1_monthly_dc_tou_without_system = tuple
		year1_monthly_tr_charge_with_system = tuple
		year1_monthly_tr_charge_without_system = tuple
		year1_monthly_tr_rate_with_system = tuple
		year1_monthly_tr_rate_without_system = tuple




def default(config) -> Utilityrate:
	pass

def new() -> Utilityrate:
	pass

def wrap(ssc_data_t) -> Utilityrate:
	pass

def from_existing(model, config="") -> Utilityrate:
	pass

__loader__ = None 

__spec__ = None
