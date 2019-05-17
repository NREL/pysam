class Weather(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	solar_resource_file = str


class MoltenSaltTower(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	system_capacity = float


class Heliostat(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	N_hel = float
	bop_spec_cost = float
	c_atm_0 = float
	c_atm_1 = float
	c_atm_2 = float
	c_atm_3 = float
	calc_fluxmaps = float
	cant_type = float
	check_max_flux = float
	contingency_rate = float
	cost_sf_fixed = float
	csp_pt_cost_epc_fixed = float
	csp_pt_cost_epc_per_acre = float
	csp_pt_cost_epc_per_watt = float
	csp_pt_cost_epc_percent = float
	csp_pt_cost_plm_fixed = float
	csp_pt_cost_plm_per_acre = float
	csp_pt_cost_plm_per_watt = float
	csp_pt_cost_plm_percent = float
	csp_pt_sf_fixed_land_area = float
	csp_pt_sf_land_overhead_factor = float
	delta_flux_hrs = float
	dens_mirror = float
	dni_des = float
	eta_map = tuple
	flux_maps = tuple
	flux_max = float
	flux_positions = tuple
	focus_type = float
	fossil_spec_cost = float
	h_tower = float
	hel_stow_deploy = float
	helio_active_fraction = float
	helio_aim_points = tuple
	helio_height = float
	helio_optical_error = float
	helio_positions = tuple
	helio_reflectance = float
	helio_width = float
	heliostat_spec_cost = float
	interp_beta = float
	interp_nug = float
	is_optimize = float
	land_bound_list = tuple
	land_bound_table = tuple
	land_bound_type = float
	land_max = float
	land_min = float
	land_spec_cost = float
	n_facet_x = float
	n_facet_y = float
	n_flux_days = float
	n_flux_x = float
	n_flux_y = float
	opt_algorithm = float
	opt_conv_tol = float
	opt_flux_penalty = float
	opt_init_step = float
	opt_max_iter = float
	p_start = float
	p_track = float
	plant_spec_cost = float
	q_design = float
	rec_absorptance = float
	rec_aspect = float
	rec_cost_exp = float
	rec_height = float
	rec_hl_perm2 = float
	rec_ref_area = float
	rec_ref_cost = float
	run_type = float
	sales_tax_frac = float
	sales_tax_rate = float
	site_spec_cost = float
	tes_spec_cost = float
	total_installed_cost = float
	tower_exp = float
	tower_fixed_cost = float
	v_wind_max = float


class Receiver(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	A_sf = float
	D_rec = float
	Flow_type = float
	H_rec = float
	N_panels = float
	Q_rec_des = float
	THT = float
	T_htf_cold_des = float
	T_htf_hot_des = float
	crossover_shift = float
	d_tube_out = float
	epsilon = float
	eta_pump = float
	f_rec_min = float
	field_fl_props = tuple
	hl_ffact = float
	m_dot_htf_max = float
	mat_tube = float
	rec_htf = float
	rec_qf_delay = float
	rec_su_delay = float
	receiver_type = float
	th_tube = float


class Powerblock(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	elev = float
	ngcc_model = float
	pinch_point_coldside = float
	pinch_point_hotside = float
	q_pb_design = float


class Parasitics(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	Q_rec_des = float
	W_dot_solar_des = float
	bop_par = float
	bop_par_0 = float
	bop_par_1 = float
	bop_par_2 = float
	bop_par_f = float
	fossil_output = float
	pb_fixed_par = float
	pb_pump_coef = float
	piping_length = float
	piping_length_const = float
	piping_length_mult = float
	piping_loss = float


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	P_fixed = tuple
	P_plant_balance_tot = tuple
	Q_dot_max = tuple
	Q_solar_total = tuple
	Q_thermal = tuple
	T_htf_cold = tuple
	T_salt_hot = tuple
	T_st_cold = tuple
	T_st_hot = tuple
	W_dot_pc_fossil = tuple
	W_dot_pc_hybrid = tuple
	W_dot_plant_fossil = tuple
	W_dot_plant_hybrid = tuple
	W_dot_plant_solar = tuple
	W_dot_pump = tuple
	annual_energy = float
	annual_fuel_usage = float
	beam = tuple
	capacity_factor = float
	eta_field = tuple
	eta_fuel = tuple
	eta_solar_use = tuple
	eta_therm = tuple
	f_timestep = tuple
	field_eff_adj = tuple
	fuel_use = tuple
	gen = tuple
	hour = tuple
	kwh_per_kw = float
	m_dot_salt_tot = tuple
	m_dot_ss = tuple
	m_dot_steam = tuple
	month = tuple
	pparasi = tuple
	pres = tuple
	q_conv_sum = tuple
	q_rad_sum = tuple
	q_startup = tuple
	solar_fraction = tuple
	solazi = tuple
	solzen = tuple
	system_heat_rate = float
	tdry = tuple
	twet = tuple
	wspd = tuple


class Tcsiscc(object):
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

	Weather = Weather
	MoltenSaltTower = MoltenSaltTower
	Heliostat = Heliostat
	Receiver = Receiver
	Powerblock = Powerblock
	Parasitics = Parasitics
	Outputs = Outputs


def default(config) -> Tcsiscc
	pass

def new() -> Tcsiscc
	pass

def wrap(ssc_data_t) -> Tcsiscc
	pass

__loader__ = None 

__spec__ = None
