class HostDeveloper(object):
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

	class Revenue(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		dispatch_factors_ts = tuple
		dispatch_sched_weekday = tuple
		dispatch_sched_weekend = tuple
		dispatch_tod_factors = tuple
		flip_target_percent = float
		flip_target_year = float
		ppa_escalation = float
		ppa_multiplier_model = float
		ppa_price_input = tuple
		ppa_soln_max = float
		ppa_soln_max_iterations = float
		ppa_soln_min = float
		ppa_soln_mode = float
		ppa_soln_tolerance = float


	class FinancialParameters(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		analysis_period = float
		cost_debt_closing = float
		cost_debt_fee = float
		cost_other_financing = float
		debt_option = float
		debt_percent = float
		dscr = float
		dscr_limit_debt_fraction = float
		dscr_maximum_debt_fraction = float
		dscr_reserve_months = float
		equip1_reserve_cost = float
		equip1_reserve_freq = float
		equip2_reserve_cost = float
		equip2_reserve_freq = float
		equip3_reserve_cost = float
		equip3_reserve_freq = float
		equip_reserve_depr_fed = float
		equip_reserve_depr_sta = float
		federal_tax_rate = tuple
		inflation_rate = float
		insurance_rate = float
		months_receivables_reserve = float
		months_working_reserve = float
		payment_option = float
		prop_tax_assessed_decline = float
		prop_tax_cost_assessed_percent = float
		property_tax_rate = float
		real_discount_rate = float
		reserves_interest = float
		salvage_percentage = float
		state_tax_rate = tuple
		system_capacity = float
		system_heat_rate = float
		term_int_rate = float
		term_tenor = float


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
		total_installed_cost = float


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


	class TaxCreditIncentives(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		itc_fed_amount = tuple
		itc_fed_amount_deprbas_fed = float
		itc_fed_amount_deprbas_sta = float
		itc_fed_percent = tuple
		itc_fed_percent_deprbas_fed = float
		itc_fed_percent_deprbas_sta = float
		itc_fed_percent_maxvalue = tuple
		itc_sta_amount = tuple
		itc_sta_amount_deprbas_fed = float
		itc_sta_amount_deprbas_sta = float
		itc_sta_percent = tuple
		itc_sta_percent_deprbas_fed = float
		itc_sta_percent_deprbas_sta = float
		itc_sta_percent_maxvalue = tuple
		ptc_fed_amount = tuple
		ptc_fed_escal = float
		ptc_fed_term = float
		ptc_sta_amount = tuple
		ptc_sta_escal = float
		ptc_sta_term = float


	class Depreciation(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		depr_alloc_custom_percent = float
		depr_alloc_macrs_15_percent = float
		depr_alloc_macrs_5_percent = float
		depr_alloc_sl_15_percent = float
		depr_alloc_sl_20_percent = float
		depr_alloc_sl_39_percent = float
		depr_alloc_sl_5_percent = float
		depr_bonus_fed = float
		depr_bonus_fed_custom = float
		depr_bonus_fed_macrs_15 = float
		depr_bonus_fed_macrs_5 = float
		depr_bonus_fed_sl_15 = float
		depr_bonus_fed_sl_20 = float
		depr_bonus_fed_sl_39 = float
		depr_bonus_fed_sl_5 = float
		depr_bonus_sta = float
		depr_bonus_sta_custom = float
		depr_bonus_sta_macrs_15 = float
		depr_bonus_sta_macrs_5 = float
		depr_bonus_sta_sl_15 = float
		depr_bonus_sta_sl_20 = float
		depr_bonus_sta_sl_39 = float
		depr_bonus_sta_sl_5 = float
		depr_custom_schedule = tuple
		depr_fedbas_method = float
		depr_itc_fed_custom = float
		depr_itc_fed_macrs_15 = float
		depr_itc_fed_macrs_5 = float
		depr_itc_fed_sl_15 = float
		depr_itc_fed_sl_20 = float
		depr_itc_fed_sl_39 = float
		depr_itc_fed_sl_5 = float
		depr_itc_sta_custom = float
		depr_itc_sta_macrs_15 = float
		depr_itc_sta_macrs_5 = float
		depr_itc_sta_sl_15 = float
		depr_itc_sta_sl_20 = float
		depr_itc_sta_sl_39 = float
		depr_itc_sta_sl_5 = float
		depr_stabas_method = float


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
		pbi_fed_for_ds = float
		pbi_fed_tax_fed = float
		pbi_fed_tax_sta = float
		pbi_fed_term = float
		pbi_oth_amount = tuple
		pbi_oth_escal = float
		pbi_oth_for_ds = float
		pbi_oth_tax_fed = float
		pbi_oth_tax_sta = float
		pbi_oth_term = float
		pbi_sta_amount = tuple
		pbi_sta_escal = float
		pbi_sta_for_ds = float
		pbi_sta_tax_fed = float
		pbi_sta_tax_sta = float
		pbi_sta_term = float
		pbi_uti_amount = tuple
		pbi_uti_escal = float
		pbi_uti_for_ds = float
		pbi_uti_tax_fed = float
		pbi_uti_tax_sta = float
		pbi_uti_term = float


	class Host(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		annual_energy_value = tuple
		elec_cost_with_system = tuple
		elec_cost_without_system = tuple
		host_real_discount_rate = float


	class TimeSeries(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		year1_hourly_dc_with_system = tuple
		year1_hourly_e_fromgrid = tuple
		year1_hourly_ec_with_system = tuple


	class ChargesByMonth(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		charge_w_sys_dc_tou_ym = tuple
		charge_w_sys_ec_ym = tuple
		charge_w_sys_fixed_ym = tuple
		net_billing_credits_ym = tuple
		nm_dollars_applied_ym = tuple
		true_up_credits_ym = tuple
		utility_bill_w_sys = tuple


	class SystemOutput(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		annual_thermal_value = tuple
		degradation = tuple
		gen = tuple
		gen_purchases = tuple
		system_capacity = float


	class Moratorium(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		loan_moratorium = float


	class Recapitalization(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		system_lifetime_recapitalize = tuple
		system_recapitalization_cost = float
		system_recapitalization_escalation = float
		system_use_recapitalization = float


	class TimeOfDelivery(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		system_use_lifetime_output = float


	class ConstructionFinancing(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		construction_financing_cost = float


	class BatterySystem(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		batt_bank_replacement = tuple
		batt_computed_bank_capacity = float
		batt_replacement_option = float
		batt_replacement_schedule_percent = tuple
		battery_per_kWh = float
		en_batt = float
		en_standalone_batt = float
		en_wave_batt = float


	class LCOS(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		batt_annual_charge_energy = tuple
		batt_annual_charge_from_system = tuple
		batt_annual_discharge_energy = tuple
		batt_capacity_percent = tuple
		batt_salvage_percentage = float
		battery_total_cost_lcos = float
		charge_w_sys_ec_ym = tuple
		grid_to_batt = tuple
		monthly_batt_to_grid = tuple
		monthly_grid_to_batt = tuple
		monthly_grid_to_load = tuple
		monthly_system_to_grid = tuple
		true_up_credits_ym = tuple
		year1_monthly_ec_charge_gross_with_system = tuple
		year1_monthly_ec_charge_with_system = tuple
		year1_monthly_electricity_to_grid = tuple


	class ElectricityRates(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		rate_escalation = tuple


	class HybridFin(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		cf_hybrid_om_sum = tuple
		is_hybrid = float


	class Monthly(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		monthly_energy = tuple


	class FuelCell(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		annual_fuel_usage_lifetime = tuple
		fuelcell_annual_energy_discharged = tuple
		fuelcell_replacement = tuple


	class HybridCosts(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		degradation = tuple
		total_installed_cost = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		adjusted_installed_cost = float
		analysis_period_irr = float
		cash_for_debt_service = float
		cbi_fedtax_total = float
		cbi_statax_total = float
		cbi_total = float
		cbi_total_fed = float
		cbi_total_oth = float
		cbi_total_sta = float
		cbi_total_uti = float
		cf_after_tax_cash_flow = tuple
		cf_after_tax_net_equity_cost_flow = tuple
		cf_agreement_cost = tuple
		cf_annual_cost_lcos = tuple
		cf_annual_costs = tuple
		cf_annual_discharge_lcos = tuple
		cf_battery_replacement_cost = tuple
		cf_battery_replacement_cost_schedule = tuple
		cf_cash_for_ds = tuple
		cf_charging_cost_grid = tuple
		cf_charging_cost_grid_month = tuple
		cf_charging_cost_pv = tuple
		cf_cumulative_payback_with_expenses = tuple
		cf_debt_balance = tuple
		cf_debt_payment_interest = tuple
		cf_debt_payment_principal = tuple
		cf_debt_payment_total = tuple
		cf_debt_size = tuple
		cf_disbursement_debtservice = tuple
		cf_disbursement_equip1 = tuple
		cf_disbursement_equip2 = tuple
		cf_disbursement_equip3 = tuple
		cf_disbursement_om = tuple
		cf_disbursement_receivables = tuple
		cf_ebitda = tuple
		cf_effective_tax_frac = tuple
		cf_energy_net = tuple
		cf_energy_purchases = tuple
		cf_energy_sales = tuple
		cf_energy_sales_apr = tuple
		cf_energy_sales_aug = tuple
		cf_energy_sales_dec = tuple
		cf_energy_sales_dispatch1 = tuple
		cf_energy_sales_dispatch2 = tuple
		cf_energy_sales_dispatch3 = tuple
		cf_energy_sales_dispatch4 = tuple
		cf_energy_sales_dispatch5 = tuple
		cf_energy_sales_dispatch6 = tuple
		cf_energy_sales_dispatch7 = tuple
		cf_energy_sales_dispatch8 = tuple
		cf_energy_sales_dispatch9 = tuple
		cf_energy_sales_feb = tuple
		cf_energy_sales_jan = tuple
		cf_energy_sales_jul = tuple
		cf_energy_sales_jun = tuple
		cf_energy_sales_mar = tuple
		cf_energy_sales_may = tuple
		cf_energy_sales_monthly_firstyear_TOD1 = tuple
		cf_energy_sales_monthly_firstyear_TOD2 = tuple
		cf_energy_sales_monthly_firstyear_TOD3 = tuple
		cf_energy_sales_monthly_firstyear_TOD4 = tuple
		cf_energy_sales_monthly_firstyear_TOD5 = tuple
		cf_energy_sales_monthly_firstyear_TOD6 = tuple
		cf_energy_sales_monthly_firstyear_TOD7 = tuple
		cf_energy_sales_monthly_firstyear_TOD8 = tuple
		cf_energy_sales_monthly_firstyear_TOD9 = tuple
		cf_energy_sales_nov = tuple
		cf_energy_sales_oct = tuple
		cf_energy_sales_sep = tuple
		cf_energy_value = tuple
		cf_energy_without_battery = tuple
		cf_feddepr_custom = tuple
		cf_feddepr_macrs_15 = tuple
		cf_feddepr_macrs_5 = tuple
		cf_feddepr_me1 = tuple
		cf_feddepr_me2 = tuple
		cf_feddepr_me3 = tuple
		cf_feddepr_sl_15 = tuple
		cf_feddepr_sl_20 = tuple
		cf_feddepr_sl_39 = tuple
		cf_feddepr_sl_5 = tuple
		cf_feddepr_total = tuple
		cf_federal_tax_frac = tuple
		cf_fedtax = tuple
		cf_fedtax_income_prior_incentives = tuple
		cf_fedtax_income_with_incentives = tuple
		cf_fedtax_taxable_incentives = tuple
		cf_funding_debtservice = tuple
		cf_funding_equip1 = tuple
		cf_funding_equip2 = tuple
		cf_funding_equip3 = tuple
		cf_funding_om = tuple
		cf_funding_receivables = tuple
		cf_insurance_expense = tuple
		cf_itc_fed = tuple
		cf_itc_fed_amount = tuple
		cf_itc_fed_percent_amount = tuple
		cf_itc_sta = tuple
		cf_itc_sta_amount = tuple
		cf_itc_sta_percent_amount = tuple
		cf_itc_total = tuple
		cf_land_lease_expense = tuple
		cf_length = float
		cf_net_salvage_value = tuple
		cf_nte = tuple
		cf_om_batt_capacity_expense = tuple
		cf_om_batt_fixed_expense = tuple
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
		cf_parasitic_cost = tuple
		cf_payback_with_expenses = tuple
		cf_pbi_fedtax_total = tuple
		cf_pbi_statax_total = tuple
		cf_pbi_total = tuple
		cf_pbi_total_fed = tuple
		cf_pbi_total_oth = tuple
		cf_pbi_total_sta = tuple
		cf_pbi_total_uti = tuple
		cf_ppa_price = tuple
		cf_pretax_cashflow = tuple
		cf_pretax_dscr = tuple
		cf_project_dsra = tuple
		cf_project_financing_activities = tuple
		cf_project_investing_activities = tuple
		cf_project_me1cs = tuple
		cf_project_me1ra = tuple
		cf_project_me2cs = tuple
		cf_project_me2ra = tuple
		cf_project_me3cs = tuple
		cf_project_me3ra = tuple
		cf_project_mecs = tuple
		cf_project_operating_activities = tuple
		cf_project_ra = tuple
		cf_project_receivablesra = tuple
		cf_project_return_aftertax = tuple
		cf_project_return_aftertax_cash = tuple
		cf_project_return_aftertax_irr = tuple
		cf_project_return_aftertax_max_irr = tuple
		cf_project_return_aftertax_npv = tuple
		cf_project_return_pretax = tuple
		cf_project_return_pretax_irr = tuple
		cf_project_return_pretax_npv = tuple
		cf_project_wcra = tuple
		cf_property_tax_assessed_value = tuple
		cf_property_tax_expense = tuple
		cf_ptc_fed = tuple
		cf_ptc_sta = tuple
		cf_pv_cash_for_ds = tuple
		cf_pv_interest_factor = tuple
		cf_recapitalization = tuple
		cf_reserve_debtservice = tuple
		cf_reserve_equip1 = tuple
		cf_reserve_equip2 = tuple
		cf_reserve_equip3 = tuple
		cf_reserve_interest = tuple
		cf_reserve_om = tuple
		cf_reserve_receivables = tuple
		cf_reserve_total = tuple
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
		cf_salvage_cost_lcos = tuple
		cf_stadepr_custom = tuple
		cf_stadepr_macrs_15 = tuple
		cf_stadepr_macrs_5 = tuple
		cf_stadepr_me1 = tuple
		cf_stadepr_me2 = tuple
		cf_stadepr_me3 = tuple
		cf_stadepr_sl_15 = tuple
		cf_stadepr_sl_20 = tuple
		cf_stadepr_sl_39 = tuple
		cf_stadepr_sl_5 = tuple
		cf_stadepr_total = tuple
		cf_statax = tuple
		cf_statax_income_prior_incentives = tuple
		cf_statax_income_with_incentives = tuple
		cf_statax_taxable_incentives = tuple
		cf_state_tax_frac = tuple
		cf_total_revenue = tuple
		cf_util_escal_rate = tuple
		cost_debt_upfront = float
		cost_financing = float
		cost_installed = float
		cost_installedperwatt = float
		cost_prefinancing = float
		debt_fraction = float
		depr_alloc_custom = float
		depr_alloc_macrs_15 = float
		depr_alloc_macrs_5 = float
		depr_alloc_none = float
		depr_alloc_none_percent = float
		depr_alloc_sl_15 = float
		depr_alloc_sl_20 = float
		depr_alloc_sl_39 = float
		depr_alloc_sl_5 = float
		depr_alloc_total = float
		depr_fedbas_after_itc_custom = float
		depr_fedbas_after_itc_macrs_15 = float
		depr_fedbas_after_itc_macrs_5 = float
		depr_fedbas_after_itc_sl_15 = float
		depr_fedbas_after_itc_sl_20 = float
		depr_fedbas_after_itc_sl_39 = float
		depr_fedbas_after_itc_sl_5 = float
		depr_fedbas_after_itc_total = float
		depr_fedbas_cbi_reduc_custom = float
		depr_fedbas_cbi_reduc_macrs_15 = float
		depr_fedbas_cbi_reduc_macrs_5 = float
		depr_fedbas_cbi_reduc_sl_15 = float
		depr_fedbas_cbi_reduc_sl_20 = float
		depr_fedbas_cbi_reduc_sl_39 = float
		depr_fedbas_cbi_reduc_sl_5 = float
		depr_fedbas_cbi_reduc_total = float
		depr_fedbas_custom = float
		depr_fedbas_first_year_bonus_custom = float
		depr_fedbas_first_year_bonus_macrs_15 = float
		depr_fedbas_first_year_bonus_macrs_5 = float
		depr_fedbas_first_year_bonus_sl_15 = float
		depr_fedbas_first_year_bonus_sl_20 = float
		depr_fedbas_first_year_bonus_sl_39 = float
		depr_fedbas_first_year_bonus_sl_5 = float
		depr_fedbas_first_year_bonus_total = float
		depr_fedbas_fixed_amount_custom = float
		depr_fedbas_fixed_amount_macrs_15 = float
		depr_fedbas_fixed_amount_macrs_5 = float
		depr_fedbas_fixed_amount_sl_15 = float
		depr_fedbas_fixed_amount_sl_20 = float
		depr_fedbas_fixed_amount_sl_39 = float
		depr_fedbas_fixed_amount_sl_5 = float
		depr_fedbas_fixed_amount_total = float
		depr_fedbas_ibi_reduc_custom = float
		depr_fedbas_ibi_reduc_macrs_15 = float
		depr_fedbas_ibi_reduc_macrs_5 = float
		depr_fedbas_ibi_reduc_sl_15 = float
		depr_fedbas_ibi_reduc_sl_20 = float
		depr_fedbas_ibi_reduc_sl_39 = float
		depr_fedbas_ibi_reduc_sl_5 = float
		depr_fedbas_ibi_reduc_total = float
		depr_fedbas_itc_fed_reduction_custom = float
		depr_fedbas_itc_fed_reduction_macrs_15 = float
		depr_fedbas_itc_fed_reduction_macrs_5 = float
		depr_fedbas_itc_fed_reduction_sl_15 = float
		depr_fedbas_itc_fed_reduction_sl_20 = float
		depr_fedbas_itc_fed_reduction_sl_39 = float
		depr_fedbas_itc_fed_reduction_sl_5 = float
		depr_fedbas_itc_fed_reduction_total = float
		depr_fedbas_itc_sta_reduction_custom = float
		depr_fedbas_itc_sta_reduction_macrs_15 = float
		depr_fedbas_itc_sta_reduction_macrs_5 = float
		depr_fedbas_itc_sta_reduction_sl_15 = float
		depr_fedbas_itc_sta_reduction_sl_20 = float
		depr_fedbas_itc_sta_reduction_sl_39 = float
		depr_fedbas_itc_sta_reduction_sl_5 = float
		depr_fedbas_itc_sta_reduction_total = float
		depr_fedbas_macrs_15 = float
		depr_fedbas_macrs_5 = float
		depr_fedbas_percent_amount_custom = float
		depr_fedbas_percent_amount_macrs_15 = float
		depr_fedbas_percent_amount_macrs_5 = float
		depr_fedbas_percent_amount_sl_15 = float
		depr_fedbas_percent_amount_sl_20 = float
		depr_fedbas_percent_amount_sl_39 = float
		depr_fedbas_percent_amount_sl_5 = float
		depr_fedbas_percent_amount_total = float
		depr_fedbas_percent_custom = float
		depr_fedbas_percent_macrs_15 = float
		depr_fedbas_percent_macrs_5 = float
		depr_fedbas_percent_qual_custom = float
		depr_fedbas_percent_qual_macrs_15 = float
		depr_fedbas_percent_qual_macrs_5 = float
		depr_fedbas_percent_qual_sl_15 = float
		depr_fedbas_percent_qual_sl_20 = float
		depr_fedbas_percent_qual_sl_39 = float
		depr_fedbas_percent_qual_sl_5 = float
		depr_fedbas_percent_qual_total = float
		depr_fedbas_percent_sl_15 = float
		depr_fedbas_percent_sl_20 = float
		depr_fedbas_percent_sl_39 = float
		depr_fedbas_percent_sl_5 = float
		depr_fedbas_percent_total = float
		depr_fedbas_prior_itc_custom = float
		depr_fedbas_prior_itc_macrs_15 = float
		depr_fedbas_prior_itc_macrs_5 = float
		depr_fedbas_prior_itc_sl_15 = float
		depr_fedbas_prior_itc_sl_20 = float
		depr_fedbas_prior_itc_sl_39 = float
		depr_fedbas_prior_itc_sl_5 = float
		depr_fedbas_prior_itc_total = float
		depr_fedbas_sl_15 = float
		depr_fedbas_sl_20 = float
		depr_fedbas_sl_39 = float
		depr_fedbas_sl_5 = float
		depr_fedbas_total = float
		depr_stabas_after_itc_custom = float
		depr_stabas_after_itc_macrs_15 = float
		depr_stabas_after_itc_macrs_5 = float
		depr_stabas_after_itc_sl_15 = float
		depr_stabas_after_itc_sl_20 = float
		depr_stabas_after_itc_sl_39 = float
		depr_stabas_after_itc_sl_5 = float
		depr_stabas_after_itc_total = float
		depr_stabas_cbi_reduc_custom = float
		depr_stabas_cbi_reduc_macrs_15 = float
		depr_stabas_cbi_reduc_macrs_5 = float
		depr_stabas_cbi_reduc_sl_15 = float
		depr_stabas_cbi_reduc_sl_20 = float
		depr_stabas_cbi_reduc_sl_39 = float
		depr_stabas_cbi_reduc_sl_5 = float
		depr_stabas_cbi_reduc_total = float
		depr_stabas_custom = float
		depr_stabas_first_year_bonus_custom = float
		depr_stabas_first_year_bonus_macrs_15 = float
		depr_stabas_first_year_bonus_macrs_5 = float
		depr_stabas_first_year_bonus_sl_15 = float
		depr_stabas_first_year_bonus_sl_20 = float
		depr_stabas_first_year_bonus_sl_39 = float
		depr_stabas_first_year_bonus_sl_5 = float
		depr_stabas_first_year_bonus_total = float
		depr_stabas_fixed_amount_custom = float
		depr_stabas_fixed_amount_macrs_15 = float
		depr_stabas_fixed_amount_macrs_5 = float
		depr_stabas_fixed_amount_sl_15 = float
		depr_stabas_fixed_amount_sl_20 = float
		depr_stabas_fixed_amount_sl_39 = float
		depr_stabas_fixed_amount_sl_5 = float
		depr_stabas_fixed_amount_total = float
		depr_stabas_ibi_reduc_custom = float
		depr_stabas_ibi_reduc_macrs_15 = float
		depr_stabas_ibi_reduc_macrs_5 = float
		depr_stabas_ibi_reduc_sl_15 = float
		depr_stabas_ibi_reduc_sl_20 = float
		depr_stabas_ibi_reduc_sl_39 = float
		depr_stabas_ibi_reduc_sl_5 = float
		depr_stabas_ibi_reduc_total = float
		depr_stabas_itc_fed_reduction_custom = float
		depr_stabas_itc_fed_reduction_macrs_15 = float
		depr_stabas_itc_fed_reduction_macrs_5 = float
		depr_stabas_itc_fed_reduction_sl_15 = float
		depr_stabas_itc_fed_reduction_sl_20 = float
		depr_stabas_itc_fed_reduction_sl_39 = float
		depr_stabas_itc_fed_reduction_sl_5 = float
		depr_stabas_itc_fed_reduction_total = float
		depr_stabas_itc_sta_reduction_custom = float
		depr_stabas_itc_sta_reduction_macrs_15 = float
		depr_stabas_itc_sta_reduction_macrs_5 = float
		depr_stabas_itc_sta_reduction_sl_15 = float
		depr_stabas_itc_sta_reduction_sl_20 = float
		depr_stabas_itc_sta_reduction_sl_39 = float
		depr_stabas_itc_sta_reduction_sl_5 = float
		depr_stabas_itc_sta_reduction_total = float
		depr_stabas_macrs_15 = float
		depr_stabas_macrs_5 = float
		depr_stabas_percent_amount_custom = float
		depr_stabas_percent_amount_macrs_15 = float
		depr_stabas_percent_amount_macrs_5 = float
		depr_stabas_percent_amount_sl_15 = float
		depr_stabas_percent_amount_sl_20 = float
		depr_stabas_percent_amount_sl_39 = float
		depr_stabas_percent_amount_sl_5 = float
		depr_stabas_percent_amount_total = float
		depr_stabas_percent_custom = float
		depr_stabas_percent_macrs_15 = float
		depr_stabas_percent_macrs_5 = float
		depr_stabas_percent_qual_custom = float
		depr_stabas_percent_qual_macrs_15 = float
		depr_stabas_percent_qual_macrs_5 = float
		depr_stabas_percent_qual_sl_15 = float
		depr_stabas_percent_qual_sl_20 = float
		depr_stabas_percent_qual_sl_39 = float
		depr_stabas_percent_qual_sl_5 = float
		depr_stabas_percent_qual_total = float
		depr_stabas_percent_sl_15 = float
		depr_stabas_percent_sl_20 = float
		depr_stabas_percent_sl_39 = float
		depr_stabas_percent_sl_5 = float
		depr_stabas_percent_total = float
		depr_stabas_prior_itc_custom = float
		depr_stabas_prior_itc_macrs_15 = float
		depr_stabas_prior_itc_macrs_5 = float
		depr_stabas_prior_itc_sl_15 = float
		depr_stabas_prior_itc_sl_20 = float
		depr_stabas_prior_itc_sl_39 = float
		depr_stabas_prior_itc_sl_5 = float
		depr_stabas_prior_itc_total = float
		depr_stabas_sl_15 = float
		depr_stabas_sl_20 = float
		depr_stabas_sl_39 = float
		depr_stabas_sl_5 = float
		depr_stabas_total = float
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
		flip_actual_irr = float
		flip_actual_year = float
		flip_target_irr = float
		flip_target_year = float
		host_nominal_discount_rate = float
		ibi_fedtax_total = float
		ibi_statax_total = float
		ibi_total = float
		ibi_total_fed = float
		ibi_total_oth = float
		ibi_total_sta = float
		ibi_total_uti = float
		issuance_of_equity = float
		itc_disallow_fed_fixed_custom = float
		itc_disallow_fed_fixed_macrs_15 = float
		itc_disallow_fed_fixed_macrs_5 = float
		itc_disallow_fed_fixed_sl_15 = float
		itc_disallow_fed_fixed_sl_20 = float
		itc_disallow_fed_fixed_sl_39 = float
		itc_disallow_fed_fixed_sl_5 = float
		itc_disallow_fed_fixed_total = float
		itc_disallow_fed_percent_custom = float
		itc_disallow_fed_percent_macrs_15 = float
		itc_disallow_fed_percent_macrs_5 = float
		itc_disallow_fed_percent_sl_15 = float
		itc_disallow_fed_percent_sl_20 = float
		itc_disallow_fed_percent_sl_39 = float
		itc_disallow_fed_percent_sl_5 = float
		itc_disallow_fed_percent_total = float
		itc_disallow_sta_fixed_custom = float
		itc_disallow_sta_fixed_macrs_15 = float
		itc_disallow_sta_fixed_macrs_5 = float
		itc_disallow_sta_fixed_sl_15 = float
		itc_disallow_sta_fixed_sl_20 = float
		itc_disallow_sta_fixed_sl_39 = float
		itc_disallow_sta_fixed_sl_5 = float
		itc_disallow_sta_fixed_total = float
		itc_disallow_sta_percent_custom = float
		itc_disallow_sta_percent_macrs_15 = float
		itc_disallow_sta_percent_macrs_5 = float
		itc_disallow_sta_percent_sl_15 = float
		itc_disallow_sta_percent_sl_20 = float
		itc_disallow_sta_percent_sl_39 = float
		itc_disallow_sta_percent_sl_5 = float
		itc_disallow_sta_percent_total = float
		itc_fed_fixed_total = float
		itc_fed_percent_total = float
		itc_fed_qual_custom = float
		itc_fed_qual_macrs_15 = float
		itc_fed_qual_macrs_5 = float
		itc_fed_qual_sl_15 = float
		itc_fed_qual_sl_20 = float
		itc_fed_qual_sl_39 = float
		itc_fed_qual_sl_5 = float
		itc_fed_qual_total = float
		itc_sta_fixed_total = float
		itc_sta_percent_total = float
		itc_sta_qual_custom = float
		itc_sta_qual_macrs_15 = float
		itc_sta_qual_macrs_5 = float
		itc_sta_qual_sl_15 = float
		itc_sta_qual_sl_20 = float
		itc_sta_qual_sl_39 = float
		itc_sta_qual_sl_5 = float
		itc_sta_qual_total = float
		itc_total = float
		itc_total_fed = float
		itc_total_sta = float
		lcoe_nom = float
		lcoe_real = float
		lcoptc_fed_nom = float
		lcoptc_fed_real = float
		lcoptc_sta_nom = float
		lcoptc_sta_real = float
		lcos_nom = float
		lcos_real = float
		lnte_nom = float
		lnte_real = float
		lppa_nom = float
		lppa_real = float
		min_dscr = float
		nominal_discount_rate = float
		npv = float
		npv_annual_costs = float
		npv_annual_costs_lcos = float
		npv_energy_lcos_nom = float
		npv_energy_lcos_real = float
		npv_energy_nom = float
		npv_energy_real = float
		npv_ppa_revenue = float
		ppa = float
		ppa_escalation = float
		ppa_multipliers = tuple
		ppa_price = float
		pre_depr_alloc_basis = float
		pre_itc_qual_basis = float
		present_value_fuel = float
		present_value_insandproptax = float
		present_value_oandm = float
		present_value_oandm_nonfuel = float
		project_return_aftertax_irr = float
		project_return_aftertax_npv = float
		prop_tax_assessed_value = float
		purchase_of_property = float
		pv_cafds = float
		salvage_value = float
		size_of_debt = float
		size_of_equity = float
		wacc = float
		year1_nte = float




def default(config) -> HostDeveloper:
	pass

def new() -> HostDeveloper:
	pass

def wrap(ssc_data_t) -> HostDeveloper:
	pass

def from_existing(model, config="") -> HostDeveloper:
	pass

__loader__ = None 

__spec__ = None
