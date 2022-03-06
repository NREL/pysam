class TcsgenericSolar(object):
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

	class Weather(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		azimuth = float
		file_name = str
		tilt = float
		track_mode = float


	class GenericSolar(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		system_capacity = float


	class TouTranslator(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		weekday_schedule = tuple
		weekend_schedule = tuple


	class Type260(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		OpticalTable = tuple
		PC_T_corr = float
		T_pcdes = float
		T_sfdes = float
		Wpar_prodD_coefs = tuple
		Wpar_prodQ_coefs = tuple
		Wpar_prodT_coefs = tuple
		diswos = tuple
		disws = tuple
		etaQ_coefs = tuple
		etaT_coefs = tuple
		eta_des = float
		eta_lhv = float
		eta_opt_gen = float
		eta_opt_soil = float
		exergy_table = tuple
		f_Wpar_fixed = float
		f_Wpar_prod = float
		f_charge = float
		f_disch = float
		f_etes_0 = float
		f_sfhl_ref = float
		f_startup = float
		f_teshl_ref = float
		f_wmax = float
		f_wmin = float
		fdisp = tuple
		hrs_tes = float
		ibh = float
		ibn = float
		interp_arr = float
		irr_des = float
		istableunsorted = float
		itoth = float
		latitude = float
		longitude = float
		ntod = float
		qdisp = tuple
		qsf_des = float
		rad_type = float
		sfhlQ_coefs = tuple
		sfhlT_coefs = tuple
		sfhlV_coefs = tuple
		solarm = float
		storage_config = float
		tdb = float
		teshlT_coefs = tuple
		teshlX_coefs = tuple
		theta_dep = float
		theta_stow = float
		timezone = float
		twb = float
		vwind = float
		w_des = float


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


		annual_energy = float
		annual_energy_distribution_time = tuple
		annual_fuel_usage = float
		annual_q_dump_tot = float
		annual_q_fossil = float
		annual_q_from_tes = float
		annual_q_hl_sf = float
		annual_q_hl_tes = float
		annual_q_sf = float
		annual_q_startup = float
		annual_q_to_pb = float
		annual_q_to_tes = float
		annual_w_gr = float
		beam = tuple
		capacity_factor = float
		conversion_factor = float
		diff = tuple
		e_in_tes = tuple
		enet = tuple
		eta_cycle = tuple
		eta_opt_sf = tuple
		f_effpc_qtpb = tuple
		f_effpc_tamb = tuple
		f_sfhl_qdni = tuple
		f_sfhl_tamb = tuple
		f_sfhl_vwind = tuple
		gen = tuple
		hour = tuple
		kwh_per_kw = float
		month = tuple
		monthly_energy = tuple
		monthly_q_dump_tot = tuple
		monthly_q_fossil = tuple
		monthly_q_from_tes = tuple
		monthly_q_hl_sf = tuple
		monthly_q_hl_tes = tuple
		monthly_q_sf = tuple
		monthly_q_startup = tuple
		monthly_q_to_pb = tuple
		monthly_q_to_tes = tuple
		monthly_w_gr = tuple
		pres = tuple
		q_dump_teschg = tuple
		q_dump_tesfull = tuple
		q_dump_tot = tuple
		q_dump_umin = tuple
		q_fossil = tuple
		q_from_tes = tuple
		q_gas = tuple
		q_hl_sf = tuple
		q_hl_tes = tuple
		q_inc = tuple
		q_sf = tuple
		q_startup = tuple
		q_to_pb = tuple
		q_to_tes = tuple
		solazi = tuple
		solzen = tuple
		system_heat_rate = float
		tdry = tuple
		twet = tuple
		w_gr = tuple
		w_gr_fossil = tuple
		w_gr_solar = tuple
		w_par_fixed = tuple
		w_par_offline = tuple
		w_par_online = tuple
		w_par_prod = tuple
		w_par_tot = tuple
		wspd = tuple




def default(config) -> TcsgenericSolar:
	pass

def new() -> TcsgenericSolar:
	pass

def wrap(ssc_data_t) -> TcsgenericSolar:
	pass

def from_existing(model, config="") -> TcsgenericSolar:
	pass

__loader__ = None 

__spec__ = None
