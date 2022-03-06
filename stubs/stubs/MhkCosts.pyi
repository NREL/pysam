class MhkCosts(object):
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

	class MHKCosts(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		array_cable_system_cost_input = float
		array_cable_system_cost_method = float
		assembly_and_install_cost_input = float
		assembly_and_install_cost_method = float
		development_cost_input = float
		development_cost_method = float
		device_rated_power = float
		devices_per_row = float
		eng_and_mgmt_cost_input = float
		eng_and_mgmt_cost_method = float
		export_cable_length = float
		export_cable_system_cost_input = float
		export_cable_system_cost_method = float
		inter_array_cable_length = float
		lib_wave_device = str
		library_or_input_wec = float
		marine_energy_tech = float
		mooring_found_substruc_cost_input = float
		mooring_found_substruc_cost_method = float
		offshore_substation_cost_input = float
		offshore_substation_cost_method = float
		onshore_substation_cost_input = float
		onshore_substation_cost_method = float
		other_elec_infra_cost_input = float
		other_elec_infra_cost_method = float
		other_infrastructure_cost_input = float
		other_infrastructure_cost_method = float
		power_takeoff_system_cost_input = float
		power_takeoff_system_cost_method = float
		riser_cable_length = float
		structural_assembly_cost_input = float
		structural_assembly_cost_method = float
		system_capacity = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		array_cable_system_cost_modeled = float
		assembly_and_install_cost_modeled = float
		development_cost_modeled = float
		eng_and_mgmt_cost_modeled = float
		export_cable_system_cost_modeled = float
		insurance_during_construction = float
		maintenance_cost = float
		mooring_found_substruc_cost_modeled = float
		offshore_substation_cost_modeled = float
		onshore_substation_cost_modeled = float
		operations_cost = float
		other_elec_infra_cost_modeled = float
		other_infrastructure_cost_modeled = float
		plant_commissioning_cost_modeled = float
		power_takeoff_system_cost_modeled = float
		project_contingency = float
		reserve_accounts = float
		site_access_port_staging_cost_modeled = float
		structural_assembly_cost_modeled = float




def default(config) -> MhkCosts:
	pass

def new() -> MhkCosts:
	pass

def wrap(ssc_data_t) -> MhkCosts:
	pass

def from_existing(model, config="") -> MhkCosts:
	pass

__loader__ = None 

__spec__ = None
