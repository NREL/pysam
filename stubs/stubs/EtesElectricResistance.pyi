class SolarResource(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	solar_resource_file = str


class SystemControl(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	F_wc = tuple
	bop_par = float
	bop_par_0 = float
	bop_par_1 = float
	bop_par_2 = float
	bop_par_f = float
	is_dispatch = float
	pb_fixed_par = float
	time_start = float
	time_steps_per_hour = float
	time_stop = float
	vacuum_arrays = float


class SystemDesign(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	P_ref = float
	T_htf_cold_des = float
	T_htf_hot_des = float
	design_eff = float
	gross_net_conversion_factor = float
	heater_mult = float
	tshours = float


class PowerCycle(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	cycle_cutoff_frac = float
	cycle_max_frac = float
	pb_pump_coef = float
	pc_config = float
	q_sby_frac = float
	startup_frac = float
	startup_time = float


class RankineCycle(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	CT = float
	P_boil = float
	P_cond_min = float
	P_cond_ratio = float
	T_ITD_des = float
	T_amb_des = float
	T_approach = float
	dT_cw_ref = float
	n_pl_inc = float
	pb_bd_frac = float
	tech_type = float


class UserDefinedPowerCycle(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	ud_f_W_dot_cool_des = float
	ud_ind_od = tuple
	ud_m_dot_water_cool_des = float


class ThermalStorage(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	cold_tank_Thtr = float
	cold_tank_max_heat = float
	csp_pt_tes_init_hot_htf_percent = float
	h_tank = float
	h_tank_min = float
	hot_tank_Thtr = float
	hot_tank_max_heat = float
	tank_pairs = float
	tes_fl_code = float
	u_tank = float
	ud_tes_fl_props = tuple


class TimeOfDeliveryFactors(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	dispatch_factor1 = float
	dispatch_factor2 = float
	dispatch_factor3 = float
	dispatch_factor4 = float
	dispatch_factor5 = float
	dispatch_factor6 = float
	dispatch_factor7 = float
	dispatch_factor8 = float
	dispatch_factor9 = float
	dispatch_factors_ts = tuple
	dispatch_sched_weekday = tuple
	dispatch_sched_weekend = tuple
	ppa_multiplier_model = float


class SystemCost(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	cycle_spec_cost = float


class SystemCosts(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	bop_spec_cost = float
	contingency_rate = float
	epc_cost_fixed = float
	epc_cost_per_watt = float
	epc_cost_perc_of_direct = float
	heater_spec_cost = float
	land_cost_fixed = float
	land_cost_per_watt = float
	land_cost_perc_of_direct = float
	sales_tax_frac = float
	tes_spec_cost = float


class FinancialParameters(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	const_per_interest_rate1 = float
	const_per_interest_rate2 = float
	const_per_interest_rate3 = float
	const_per_interest_rate4 = float
	const_per_interest_rate5 = float
	const_per_months1 = float
	const_per_months2 = float
	const_per_months3 = float
	const_per_months4 = float
	const_per_months5 = float
	const_per_percent1 = float
	const_per_percent2 = float
	const_per_percent3 = float
	const_per_percent4 = float
	const_per_percent5 = float
	const_per_upfront_rate1 = float
	const_per_upfront_rate2 = float
	const_per_upfront_rate3 = float
	const_per_upfront_rate4 = float
	const_per_upfront_rate5 = float
	sales_tax_rate = float


class AdjustmentFactors(object):
	def assign(self): 
		pass

	def export(self): 
		return {}

	def __init__(self, *args, **kwargs): # real signature unknown
		pass

	constant = float
	dc_constant = float
	dc_hourly = tuple
	dc_periods = tuple
	hourly = tuple
	periods = tuple
	sf_constant = float
	sf_hourly = tuple
	sf_periods = tuple

class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	T_tes_cold = tuple
	T_tes_hot = tuple
	W_dot_cycle_gross = tuple
	W_dot_heater = tuple
	W_dot_out_net = tuple
	annual_E_cycle_gross = float
	annual_E_heater = float
	annual_E_tes_heater = float
	annual_Q_cycle_thermal_in = float
	annual_Q_cycle_thermal_startup = float
	annual_Q_heater_startup = float
	annual_Q_heater_to_htf = float
	annual_Q_tes_losses = float
	annual_energy = float
	annual_energy_full_availability = float
	construction_financing_cost = float
	e_ch_tes = tuple
	gen = tuple
	mass_tes_cold = tuple
	mass_tes_hot = tuple
	q_dot_ch_tes = tuple
	q_dot_cycle = tuple
	q_dot_cycle_startup = tuple
	q_dot_dc_tes = tuple
	q_dot_heater_startup = tuple
	q_dot_heater_to_htf = tuple
	q_dot_tes_heater = tuple
	q_dot_tes_losses = tuple
	system_capacity = float
	time_hr = tuple
	total_installed_cost = float


class EtesElectricResistance(object):
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

	SolarResource = SolarResource
	SystemControl = SystemControl
	SystemDesign = SystemDesign
	PowerCycle = PowerCycle
	RankineCycle = RankineCycle
	UserDefinedPowerCycle = UserDefinedPowerCycle
	ThermalStorage = ThermalStorage
	TimeOfDeliveryFactors = TimeOfDeliveryFactors
	SystemCost = SystemCost
	SystemCosts = SystemCosts
	FinancialParameters = FinancialParameters
	AdjustmentFactors = AdjustmentFactors
	Outputs = Outputs


def default(config) -> EtesElectricResistance:
	pass

def new() -> EtesElectricResistance:
	pass

def wrap(ssc_data_t) -> EtesElectricResistance:
	pass

def from_existing(model, config="") -> EtesElectricResistance:
	pass

__loader__ = None 

__spec__ = None
