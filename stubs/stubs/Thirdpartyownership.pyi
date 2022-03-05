class Thirdpartyownership(object):
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


	class Financials(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		analysis_period = float
		inflation_rate = float
		real_discount_rate = float


	class FinancialThirdPartyOwnership(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		lease_or_ppa = float


	class Common(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		annual_energy_value = tuple
		gen = tuple


	class AnnualOutput(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		degradation = tuple
		system_use_lifetime_output = float


	class CashFlow(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		lease_escalation = float
		lease_price = float
		ppa_escalation = float
		ppa_price = float


	class ElectricityCost(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		elec_cost_with_system = tuple
		elec_cost_without_system = tuple


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		cf_after_tax_cash_flow = tuple
		cf_after_tax_net_equity_cost_flow = tuple
		cf_agreement_cost = tuple
		cf_cumulative_payback_with_expenses = tuple
		cf_energy_net = tuple
		cf_energy_purchases = tuple
		cf_energy_sales = tuple
		cf_length = float
		cf_nte = tuple
		cf_payback_with_expenses = tuple
		lnte_nom = float
		lnte_real = float
		npv = float
		year1_nte = float




def default(config) -> Thirdpartyownership:
	pass

def new() -> Thirdpartyownership:
	pass

def wrap(ssc_data_t) -> Thirdpartyownership:
	pass

def from_existing(model, config="") -> Thirdpartyownership:
	pass

__loader__ = None 

__spec__ = None
