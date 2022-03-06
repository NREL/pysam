class CbMsptSystemCosts(object):
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

	class Heliostat(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		A_sf = float


	class SystemCosts(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		bop_spec_cost = float
		contingency_rate = float
		csp_pt_cost_epc_fixed = float
		csp_pt_cost_epc_per_acre = float
		csp_pt_cost_epc_per_watt = float
		csp_pt_cost_epc_percent = float
		csp_pt_cost_fixed_sf = float
		csp_pt_cost_plm_fixed = float
		csp_pt_cost_plm_per_acre = float
		csp_pt_cost_plm_per_watt = float
		csp_pt_cost_plm_percent = float
		csp_pt_cost_power_block_per_kwe = float
		csp_pt_cost_total_land_area = float
		fossil_spec_cost = float
		heliostat_spec_cost = float
		rec_cost_exp = float
		rec_ref_area = float
		rec_ref_cost = float
		sales_tax_frac = float
		sales_tax_rate = float
		site_spec_cost = float
		tes_spec_cost = float
		tower_exp = float
		tower_fixed_cost = float


	class Receiver(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		H_rec = float
		csp_pt_cost_receiver_area = float
		h_tower = float
		helio_height = float


	class TES(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		csp_pt_cost_storage_mwht = float


	class SystemDesign(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		P_ref = float
		system_capacity = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		csp_pt_cost_bop = float
		csp_pt_cost_contingency = float
		csp_pt_cost_epc_total = float
		csp_pt_cost_fossil = float
		csp_pt_cost_heliostats = float
		csp_pt_cost_installed_per_capacity = float
		csp_pt_cost_plm_total = float
		csp_pt_cost_power_block = float
		csp_pt_cost_receiver = float
		csp_pt_cost_sales_tax_total = float
		csp_pt_cost_site_improvements = float
		csp_pt_cost_storage = float
		csp_pt_cost_tower = float
		total_direct_cost = float
		total_indirect_cost = float
		total_installed_cost = float
		ui_direct_subtotal = float




def default(config) -> CbMsptSystemCosts:
	pass

def new() -> CbMsptSystemCosts:
	pass

def wrap(ssc_data_t) -> CbMsptSystemCosts:
	pass

def from_existing(model, config="") -> CbMsptSystemCosts:
	pass

__loader__ = None 

__spec__ = None
