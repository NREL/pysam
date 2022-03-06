class Hcpv(object):
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

	class SolarResourceData(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		file_name = str


	class PVWatts(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		system_capacity = float


	class HCPVModule(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		module_a = float
		module_a0 = float
		module_a1 = float
		module_a2 = float
		module_a3 = float
		module_a4 = float
		module_alignment_error = float
		module_b = float
		module_cell_area = float
		module_concentration = float
		module_dT = float
		module_flutter_loss_coeff = float
		module_mjeff = tuple
		module_ncells = float
		module_optical_error = float
		module_rad = tuple
		module_reference = float
		module_temp_coeff = float


	class InverterCECDatabase(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		inv_snl_c0 = float
		inv_snl_c1 = float
		inv_snl_c2 = float
		inv_snl_c3 = float
		inv_snl_paco = float
		inv_snl_pdco = float
		inv_snl_pnt = float
		inv_snl_pso = float
		inv_snl_vdcmax = float
		inv_snl_vdco = float


	class HCPVArray(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		array_ac_wiring_loss = float
		array_dc_mismatch_loss = float
		array_dc_wiring_loss = float
		array_diode_conn_loss = float
		array_enable_azalt_sf = float
		array_modules_per_tracker = float
		array_monthly_soiling = tuple
		array_num_inverters = float
		array_num_trackers = float
		array_rlim_az_max = float
		array_rlim_az_min = float
		array_rlim_el_max = float
		array_rlim_el_min = float
		array_tracker_power_fraction = float
		array_tracking_error = float
		array_wind_stow_speed = float
		azaltsf = tuple


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


		ac_loss_tracker_kwh = float
		annual_ac = float
		annual_beam = float
		annual_dc = float
		annual_dc_net = float
		annual_energy = float
		annual_energy_distribution_time = tuple
		annual_input_radiation = float
		capacity_factor = float
		dc_loss_stowing_kwh = float
		dc_nominal = float
		gen = tuple
		hourly_ac = tuple
		hourly_airmass = tuple
		hourly_beam = tuple
		hourly_celleff = tuple
		hourly_dc = tuple
		hourly_dc_net = tuple
		hourly_input_radiation = tuple
		hourly_modeff = tuple
		hourly_poa = tuple
		hourly_sazi = tuple
		hourly_shading_derate = tuple
		hourly_solazi = tuple
		hourly_solzen = tuple
		hourly_stilt = tuple
		hourly_sunup = tuple
		hourly_tcell = tuple
		hourly_tdry = tuple
		hourly_tmod = tuple
		hourly_windspd = tuple
		kwh_per_kw = float
		modeff_ref = float
		monthly_beam = tuple
		monthly_dc_net = tuple
		monthly_energy = tuple
		monthly_input_radiation = tuple
		tracker_nameplate_watts = float




def default(config) -> Hcpv:
	pass

def new() -> Hcpv:
	pass

def wrap(ssc_data_t) -> Hcpv:
	pass

def from_existing(model, config="") -> Hcpv:
	pass

__loader__ = None 

__spec__ = None
