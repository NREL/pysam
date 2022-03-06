class Ippppa(object):
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

	class FinancialParameters(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
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
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		add_om_num_types = float
		annual_fuel_usage = float
		annual_fuel_usage_lifetime = tuple
		fuelcell_annual_energy_discharged = tuple
		om_batt_capacity_cost = tuple
		om_batt_fixed_cost = tuple
		om_batt_nameplate = float
		om_batt_replacement_cost = tuple
		om_batt_variable_cost = tuple
		om_capacity = tuple
		om_capacity_escal = float
		om_fixed = tuple
		om_fixed_escal = float
		om_fuel_cost = tuple
		om_fuel_cost_escal = float
		om_fuelcell_capacity_cost = tuple
		om_fuelcell_fixed_cost = tuple
		om_fuelcell_nameplate = float
		om_fuelcell_replacement_cost = tuple
		om_fuelcell_variable_cost = tuple
		om_opt_fuel_1_cost = tuple
		om_opt_fuel_1_cost_escal = float
		om_opt_fuel_1_usage = float
		om_opt_fuel_2_cost = tuple
		om_opt_fuel_2_cost_escal = float
		om_opt_fuel_2_usage = float
		om_production = tuple
		om_production1_values = tuple
		om_production2_values = tuple
		om_production_escal = float
		om_replacement_cost_escal = float


	class LandLease(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		land_area = float
		om_land_lease = tuple
		om_land_lease_escal = float


	class Depreciation(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
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
	
		def export(self) -> dict:
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
	
		def export(self) -> dict:
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


	class Common(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		bid_price = tuple
		bid_price_esc = float
		construction_financing_cost = float
		degradation = tuple
		dispatch_factor1 = float
		dispatch_factor2 = float
		dispatch_factor3 = float
		dispatch_factor4 = float
		dispatch_factor5 = float
		dispatch_factor6 = float
		dispatch_factor7 = float
		dispatch_factor8 = float
		dispatch_factor9 = float
		dispatch_sched_weekday = tuple
		dispatch_sched_weekend = tuple
		gen = tuple
		market = float
		min_dscr_required = float
		min_dscr_target = float
		min_irr_target = float
		optimize_lcoe_wrt_debt_fraction = float
		optimize_lcoe_wrt_ppa_escalation = float
		positive_cashflow_required = float
		ppa_escalation = float
		ppa_soln_max = float
		ppa_soln_max_iterations = float
		ppa_soln_min = float
		ppa_soln_tolerance = float
		salvage_percentage = float
		soln_mode = float
		system_capacity = float
		system_recapitalization_boolean = tuple
		system_recapitalization_cost = float
		system_recapitalization_escalation = float
		system_use_lifetime_output = float
		system_use_recapitalization = float
		total_installed_cost = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		actual_debt_frac = float
		actual_ppa_escalation = float
		cbi_fedtax_total = float
		cbi_statax_total = float
		cbi_total = float
		cbi_total_fed = float
		cbi_total_oth = float
		cbi_total_sta = float
		cbi_total_uti = float
		cf_after_tax_cash_flow = tuple
		cf_after_tax_net_equity_cash_flow = tuple
		cf_after_tax_net_equity_cost_flow = tuple
		cf_debt_balance = tuple
		cf_debt_payment_interest = tuple
		cf_debt_payment_principal = tuple
		cf_debt_payment_total = tuple
		cf_deductible_expenses = tuple
		cf_degradation = tuple
		cf_effective_tax_frac = tuple
		cf_energy_net = tuple
		cf_energy_net_apr = tuple
		cf_energy_net_aug = tuple
		cf_energy_net_dec = tuple
		cf_energy_net_dispatch1 = tuple
		cf_energy_net_dispatch2 = tuple
		cf_energy_net_dispatch3 = tuple
		cf_energy_net_dispatch4 = tuple
		cf_energy_net_dispatch5 = tuple
		cf_energy_net_dispatch6 = tuple
		cf_energy_net_dispatch7 = tuple
		cf_energy_net_dispatch8 = tuple
		cf_energy_net_dispatch9 = tuple
		cf_energy_net_feb = tuple
		cf_energy_net_jan = tuple
		cf_energy_net_jul = tuple
		cf_energy_net_jun = tuple
		cf_energy_net_mar = tuple
		cf_energy_net_may = tuple
		cf_energy_net_monthly_firstyear_TOD1 = tuple
		cf_energy_net_monthly_firstyear_TOD2 = tuple
		cf_energy_net_monthly_firstyear_TOD3 = tuple
		cf_energy_net_monthly_firstyear_TOD4 = tuple
		cf_energy_net_monthly_firstyear_TOD5 = tuple
		cf_energy_net_monthly_firstyear_TOD6 = tuple
		cf_energy_net_monthly_firstyear_TOD7 = tuple
		cf_energy_net_monthly_firstyear_TOD8 = tuple
		cf_energy_net_monthly_firstyear_TOD9 = tuple
		cf_energy_net_nov = tuple
		cf_energy_net_oct = tuple
		cf_energy_net_sep = tuple
		cf_energy_price = tuple
		cf_energy_value = tuple
		cf_fed_depr_sched = tuple
		cf_fed_depreciation = tuple
		cf_fed_incentive_income_less_deductions = tuple
		cf_fed_income_taxes = tuple
		cf_fed_tax_savings = tuple
		cf_fed_taxable_income_less_deductions = tuple
		cf_federal_tax_frac = tuple
		cf_insurance_expense = tuple
		cf_land_lease_expense = tuple
		cf_length = float
		cf_net_salvage_value = tuple
		cf_om_capacity_expense = tuple
		cf_om_fixed_expense = tuple
		cf_om_fuel_expense = tuple
		cf_om_opt_fuel_1_expense = tuple
		cf_om_opt_fuel_2_expense = tuple
		cf_om_production_expense = tuple
		cf_operating_expenses = tuple
		cf_operating_income = tuple
		cf_pbi_fedtax_total = tuple
		cf_pbi_statax_total = tuple
		cf_pbi_total = tuple
		cf_pbi_total_fed = tuple
		cf_pbi_total_oth = tuple
		cf_pbi_total_sta = tuple
		cf_pbi_total_uti = tuple
		cf_ppa_price = tuple
		cf_pretax_dscr = tuple
		cf_property_tax_assessed_value = tuple
		cf_property_tax_expense = tuple
		cf_ptc_fed = tuple
		cf_ptc_sta = tuple
		cf_ptc_total = tuple
		cf_recapitalization = tuple
		cf_revenue_apr = tuple
		cf_revenue_aug = tuple
		cf_revenue_dec = tuple
		cf_revenue_dispatch1 = tuple
		cf_revenue_dispatch2 = tuple
		cf_revenue_dispatch3 = tuple
		cf_revenue_dispatch4 = tuple
		cf_revenue_dispatch5 = tuple
		cf_revenue_dispatch6 = tuple
		cf_revenue_dispatch7 = tuple
		cf_revenue_dispatch8 = tuple
		cf_revenue_dispatch9 = tuple
		cf_revenue_feb = tuple
		cf_revenue_jan = tuple
		cf_revenue_jul = tuple
		cf_revenue_jun = tuple
		cf_revenue_mar = tuple
		cf_revenue_may = tuple
		cf_revenue_monthly_firstyear_TOD1 = tuple
		cf_revenue_monthly_firstyear_TOD2 = tuple
		cf_revenue_monthly_firstyear_TOD3 = tuple
		cf_revenue_monthly_firstyear_TOD4 = tuple
		cf_revenue_monthly_firstyear_TOD5 = tuple
		cf_revenue_monthly_firstyear_TOD6 = tuple
		cf_revenue_monthly_firstyear_TOD7 = tuple
		cf_revenue_monthly_firstyear_TOD8 = tuple
		cf_revenue_monthly_firstyear_TOD9 = tuple
		cf_revenue_nov = tuple
		cf_revenue_oct = tuple
		cf_revenue_sep = tuple
		cf_sta_and_fed_tax_savings = tuple
		cf_sta_depr_sched = tuple
		cf_sta_depreciation = tuple
		cf_sta_incentive_income_less_deductions = tuple
		cf_sta_income_taxes = tuple
		cf_sta_tax_savings = tuple
		cf_sta_taxable_income_less_deductions = tuple
		cf_state_tax_frac = tuple
		debt_fraction = float
		effective_tax_rate = float
		firstyear_energy_dispatch1 = float
		firstyear_energy_dispatch2 = float
		firstyear_energy_dispatch3 = float
		firstyear_energy_dispatch4 = float
		firstyear_energy_dispatch5 = float
		firstyear_energy_dispatch6 = float
		firstyear_energy_dispatch7 = float
		firstyear_energy_dispatch8 = float
		firstyear_energy_dispatch9 = float
		firstyear_energy_price1 = float
		firstyear_energy_price2 = float
		firstyear_energy_price3 = float
		firstyear_energy_price4 = float
		firstyear_energy_price5 = float
		firstyear_energy_price6 = float
		firstyear_energy_price7 = float
		firstyear_energy_price8 = float
		firstyear_energy_price9 = float
		firstyear_revenue_dispatch1 = float
		firstyear_revenue_dispatch2 = float
		firstyear_revenue_dispatch3 = float
		firstyear_revenue_dispatch4 = float
		firstyear_revenue_dispatch5 = float
		firstyear_revenue_dispatch6 = float
		firstyear_revenue_dispatch7 = float
		firstyear_revenue_dispatch8 = float
		firstyear_revenue_dispatch9 = float
		ibi_fedtax_total = float
		ibi_statax_total = float
		ibi_total = float
		ibi_total_fed = float
		ibi_total_oth = float
		ibi_total_sta = float
		ibi_total_uti = float
		irr = float
		itc_fed_total = float
		itc_sta_total = float
		itc_total = float
		itc_total_fed = float
		itc_total_sta = float
		latcf_nom = float
		latcf_real = float
		lcoe_nom = float
		lcoe_real = float
		lcoptc_fed_nom = float
		lcoptc_fed_real = float
		lcoptc_sta_nom = float
		lcoptc_sta_real = float
		lppa_nom = float
		lppa_real = float
		min_cashflow = float
		min_dscr = float
		npv = float
		ppa = float
		ppa_escalation = float
		present_value_fuel = float
		present_value_insandproptax = float
		present_value_oandm = float
		present_value_oandm_nonfuel = float
		wacc = float




def default(config) -> Ippppa:
	pass

def new() -> Ippppa:
	pass

def wrap(ssc_data_t) -> Ippppa:
	pass

def from_existing(model, config="") -> Ippppa:
	pass

__loader__ = None 

__spec__ = None
