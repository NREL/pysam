class FinancialParameters(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	analysis_period = float
	debt_fraction = float
	federal_tax_rate = tuple
	inflation_rate = float
	insurance_rate = float
	loan_rate = float
	loan_term = float
	prop_tax_assessed_decline = float
	prop_tax_cost_assessed_percent = float
	property_tax_rate = float
	real_discount_rate = float
	state_tax_rate = tuple
	system_capacity = float
	system_heat_rate = float


class SystemCosts(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	add_om_num_types = float
	annual_fuel_usage = float
	om_capacity = tuple
	om_capacity1 = tuple
	om_capacity1_nameplate = float
	om_capacity2 = tuple
	om_capacity2_nameplate = float
	om_capacity_escal = float
	om_fixed = tuple
	om_fixed1 = tuple
	om_fixed2 = tuple
	om_fixed_escal = float
	om_fuel_cost = tuple
	om_fuel_cost_escal = float
	om_opt_fuel_1_cost = tuple
	om_opt_fuel_1_cost_escal = float
	om_opt_fuel_1_usage = float
	om_opt_fuel_2_cost = tuple
	om_opt_fuel_2_cost_escal = float
	om_opt_fuel_2_usage = float
	om_production = tuple
	om_production1 = tuple
	om_production1_values = tuple
	om_production2 = tuple
	om_production2_values = tuple
	om_production_escal = float
	om_replacement_cost1 = tuple
	om_replacement_cost2 = tuple
	om_replacement_cost_escal = float


class Depreciation(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	depr_fed_custom = tuple
	depr_fed_sl_years = float
	depr_fed_type = float
	depr_sta_custom = tuple
	depr_sta_sl_years = float
	depr_sta_type = float


class TaxCreditIncentives(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	itc_fed_amount = float
	itc_fed_amount_deprbas_fed = float
	itc_fed_amount_deprbas_sta = float
	itc_fed_percent = float
	itc_fed_percent_deprbas_fed = float
	itc_fed_percent_deprbas_sta = float
	itc_fed_percent_maxvalue = float
	itc_sta_amount = float
	itc_sta_amount_deprbas_fed = float
	itc_sta_amount_deprbas_sta = float
	itc_sta_percent = float
	itc_sta_percent_deprbas_fed = float
	itc_sta_percent_deprbas_sta = float
	itc_sta_percent_maxvalue = float
	ptc_fed_amount = tuple
	ptc_fed_escal = float
	ptc_fed_term = float
	ptc_sta_amount = tuple
	ptc_sta_escal = float
	ptc_sta_term = float


class PaymentIncentives(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	cbi_fed_amount = float
	cbi_fed_deprbas_fed = float
	cbi_fed_deprbas_sta = float
	cbi_fed_maxvalue = float
	cbi_fed_tax_fed = float
	cbi_fed_tax_sta = float
	cbi_oth_amount = float
	cbi_oth_deprbas_fed = float
	cbi_oth_deprbas_sta = float
	cbi_oth_maxvalue = float
	cbi_oth_tax_fed = float
	cbi_oth_tax_sta = float
	cbi_sta_amount = float
	cbi_sta_deprbas_fed = float
	cbi_sta_deprbas_sta = float
	cbi_sta_maxvalue = float
	cbi_sta_tax_fed = float
	cbi_sta_tax_sta = float
	cbi_uti_amount = float
	cbi_uti_deprbas_fed = float
	cbi_uti_deprbas_sta = float
	cbi_uti_maxvalue = float
	cbi_uti_tax_fed = float
	cbi_uti_tax_sta = float
	ibi_fed_amount = float
	ibi_fed_amount_deprbas_fed = float
	ibi_fed_amount_deprbas_sta = float
	ibi_fed_amount_tax_fed = float
	ibi_fed_amount_tax_sta = float
	ibi_fed_percent = float
	ibi_fed_percent_deprbas_fed = float
	ibi_fed_percent_deprbas_sta = float
	ibi_fed_percent_maxvalue = float
	ibi_fed_percent_tax_fed = float
	ibi_fed_percent_tax_sta = float
	ibi_oth_amount = float
	ibi_oth_amount_deprbas_fed = float
	ibi_oth_amount_deprbas_sta = float
	ibi_oth_amount_tax_fed = float
	ibi_oth_amount_tax_sta = float
	ibi_oth_percent = float
	ibi_oth_percent_deprbas_fed = float
	ibi_oth_percent_deprbas_sta = float
	ibi_oth_percent_maxvalue = float
	ibi_oth_percent_tax_fed = float
	ibi_oth_percent_tax_sta = float
	ibi_sta_amount = float
	ibi_sta_amount_deprbas_fed = float
	ibi_sta_amount_deprbas_sta = float
	ibi_sta_amount_tax_fed = float
	ibi_sta_amount_tax_sta = float
	ibi_sta_percent = float
	ibi_sta_percent_deprbas_fed = float
	ibi_sta_percent_deprbas_sta = float
	ibi_sta_percent_maxvalue = float
	ibi_sta_percent_tax_fed = float
	ibi_sta_percent_tax_sta = float
	ibi_uti_amount = float
	ibi_uti_amount_deprbas_fed = float
	ibi_uti_amount_deprbas_sta = float
	ibi_uti_amount_tax_fed = float
	ibi_uti_amount_tax_sta = float
	ibi_uti_percent = float
	ibi_uti_percent_deprbas_fed = float
	ibi_uti_percent_deprbas_sta = float
	ibi_uti_percent_maxvalue = float
	ibi_uti_percent_tax_fed = float
	ibi_uti_percent_tax_sta = float
	pbi_fed_amount = tuple
	pbi_fed_escal = float
	pbi_fed_tax_fed = float
	pbi_fed_tax_sta = float
	pbi_fed_term = float
	pbi_oth_amount = tuple
	pbi_oth_escal = float
	pbi_oth_tax_fed = float
	pbi_oth_tax_sta = float
	pbi_oth_term = float
	pbi_sta_amount = tuple
	pbi_sta_escal = float
	pbi_sta_tax_fed = float
	pbi_sta_tax_sta = float
	pbi_sta_term = float
	pbi_uti_amount = tuple
	pbi_uti_escal = float
	pbi_uti_tax_fed = float
	pbi_uti_tax_sta = float
	pbi_uti_term = float


class Battery(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	batt_bank_replacement = tuple
	batt_computed_bank_capacity = float
	batt_replacement_option = float
	batt_replacement_schedule = tuple
	battery_per_kWh = float
	en_batt = float


class FuelCell(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	en_fuelcell = float
	fuelcell_computed_bank_capacity = float
	fuelcell_per_kWh = float
	fuelcell_replacement = tuple
	fuelcell_replacement_option = float
	fuelcell_replacement_schedule = tuple


class Cashloan(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	annual_energy_value = tuple
	annual_themal_value = tuple
	market = float
	mortgage = float
	salvage_percentage = float
	total_installed_cost = float


class SystemOutput(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	degradation = tuple
	gen = tuple


class Lifetime(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	system_use_lifetime_output = float


class ThirdPartyOwnership(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	elec_cost_with_system = tuple
	elec_cost_without_system = tuple


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	adjusted_installed_cost = float
	cbi_total = float
	cbi_total_fed = float
	cbi_total_oth = float
	cbi_total_sta = float
	cbi_total_uti = float
	cf_after_tax_cash_flow = tuple
	cf_after_tax_net_equity_cost_flow = tuple
	cf_battery_replacement_cost = tuple
	cf_battery_replacement_cost_schedule = tuple
	cf_cumulative_payback_with_expenses = tuple
	cf_cumulative_payback_without_expenses = tuple
	cf_debt_balance = tuple
	cf_debt_payment_interest = tuple
	cf_debt_payment_principal = tuple
	cf_debt_payment_total = tuple
	cf_deductible_expenses = tuple
	cf_discounted_costs = tuple
	cf_discounted_cumulative_payback = tuple
	cf_discounted_payback = tuple
	cf_discounted_savings = tuple
	cf_effective_tax_frac = tuple
	cf_energy_net = tuple
	cf_energy_value = tuple
	cf_fed_depr_sched = tuple
	cf_fed_depreciation = tuple
	cf_fed_incentive_income_less_deductions = tuple
	cf_fed_tax_savings = tuple
	cf_fed_taxable_income_less_deductions = tuple
	cf_federal_tax_frac = tuple
	cf_fuelcell_replacement_cost = tuple
	cf_fuelcell_replacement_cost_schedule = tuple
	cf_insurance_expense = tuple
	cf_length = float
	cf_net_salvage_value = tuple
	cf_nte = tuple
	cf_om_capacity1_expense = tuple
	cf_om_capacity2_expense = tuple
	cf_om_capacity_expense = tuple
	cf_om_fixed1_expense = tuple
	cf_om_fixed2_expense = tuple
	cf_om_fixed_expense = tuple
	cf_om_fuel_expense = tuple
	cf_om_opt_fuel_1_expense = tuple
	cf_om_opt_fuel_2_expense = tuple
	cf_om_production1_expense = tuple
	cf_om_production2_expense = tuple
	cf_om_production_expense = tuple
	cf_operating_expenses = tuple
	cf_payback_with_expenses = tuple
	cf_payback_without_expenses = tuple
	cf_pbi_total = tuple
	cf_pbi_total_fed = tuple
	cf_pbi_total_oth = tuple
	cf_pbi_total_sta = tuple
	cf_pbi_total_uti = tuple
	cf_property_tax_assessed_value = tuple
	cf_property_tax_expense = tuple
	cf_ptc_fed = tuple
	cf_ptc_sta = tuple
	cf_ptc_total = tuple
	cf_sta_and_fed_tax_savings = tuple
	cf_sta_depr_sched = tuple
	cf_sta_depreciation = tuple
	cf_sta_incentive_income_less_deductions = tuple
	cf_sta_tax_savings = tuple
	cf_sta_taxable_income_less_deductions = tuple
	cf_state_tax_frac = tuple
	cf_thermal_value = tuple
	cf_value_added = tuple
	discounted_payback = float
	effective_tax_rate = float
	first_cost = float
	ibi_total = float
	ibi_total_fed = float
	ibi_total_oth = float
	ibi_total_sta = float
	ibi_total_uti = float
	itc_total = float
	itc_total_fed = float
	itc_total_sta = float
	lcoe_nom = float
	lcoe_real = float
	lcoptc_fed_nom = float
	lcoptc_fed_real = float
	lcoptc_sta_nom = float
	lcoptc_sta_real = float
	lnte_nom = float
	lnte_real = float
	loan_amount = float
	npv = float
	payback = float
	present_value_fuel = float
	present_value_insandproptax = float
	present_value_oandm = float
	present_value_oandm_nonfuel = float
	total_cost = float
	wacc = float
	year1_nte = float


class CashloanModel(object):
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

	FinancialParameters = FinancialParameters
	SystemCosts = SystemCosts
	Depreciation = Depreciation
	TaxCreditIncentives = TaxCreditIncentives
	PaymentIncentives = PaymentIncentives
	Battery = Battery
	FuelCell = FuelCell
	Cashloan = Cashloan
	SystemOutput = SystemOutput
	Lifetime = Lifetime
	ThirdPartyOwnership = ThirdPartyOwnership
	Outputs = Outputs


def default(config) -> CashloanModel
	pass

def new() -> CashloanModel
	pass

def wrap(ssc_data_t) -> CashloanModel
	pass

__loader__ = None 

__spec__ = None
