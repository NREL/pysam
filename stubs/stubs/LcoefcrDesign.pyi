class LcoefcrDesign(object):
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

	class SystemControl(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		sim_type = float


	class SimpleLCOE(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		annual_energy = float
		c_construction_cost = tuple
		c_construction_interest = float
		c_debt_percent = float
		c_depreciation_schedule = tuple
		c_equity_return = float
		c_inflation = float
		c_lifetime = float
		c_nominal_interest_rate = float
		c_tax_rate = float
		fixed_operating_cost = float
		ui_fcr_input_option = float
		ui_fixed_charge_rate = float
		variable_operating_cost = float


	class SystemCosts(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		total_installed_cost = float


	class IPHLCOH(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		annual_electricity_consumption = float
		electricity_rate = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		cfin = float
		crf = float
		fixed_charge_rate_calc = float
		lcoe_fcr = float
		pfin = float
		wacc = float




def default(config) -> LcoefcrDesign:
	pass

def new() -> LcoefcrDesign:
	pass

def wrap(ssc_data_t) -> LcoefcrDesign:
	pass

def from_existing(model, config="") -> LcoefcrDesign:
	pass

__loader__ = None 

__spec__ = None
