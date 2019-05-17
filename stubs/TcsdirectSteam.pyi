class Weather(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	solar_resource_file = str


class DirectSteamTower(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	system_capacity = float


class TouTranslator(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	weekday_schedule = tuple
	weekend_schedule = tuple


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
	washing_frequency = float
	water_usage_per_wash = float


class Receiver(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	H_rec = float
	THT = float


class DsgController(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	A_sf = float
	P_b_in_init = float
	P_cond_init = float
	P_hp_in_des = float
	P_hp_out = float
	P_hp_out_des = float
	T_ITD_des = float
	T_amb_des = float
	T_approach = float
	T_fw_init = float
	T_hp_out = float
	T_rh_out_des = float
	T_rh_target = float
	T_sh_out_des = float
	ct = float
	cycle_max_frac = float
	dT_cw_ref = float
	d_rec = float
	d_rh = float
	d_sh = float
	d_t_boiler = float
	eta_rec_pump = float
	f_mdot_rh_init = float
	f_mdotrh_des = float
	f_pb_cutoff = float
	f_pb_sb = float
	f_rec_min = float
	ffrac = tuple
	flowtype = float
	fossil_mode = float
	h_boiler = float
	h_rh = float
	h_sh = float
	h_tower = float
	hl_ffact = float
	lhv_eff = float
	mat_boiler = float
	mat_rh = float
	mat_sh = float
	n_panels = float
	p_cycle_design = float
	q_aux_max = float
	q_pb_design = float
	q_rec_des = float
	rec_absorptance = float
	rec_emis = float
	rec_qf_delay = float
	rec_su_delay = float
	t_standby_ini = float
	th_rh = float
	th_sh = float
	th_t_boiler = float
	x_b_target = float


class Powerblock(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	F_wc = tuple
	P_boil_des = float
	P_cond_min = float
	P_cond_ratio = float
	P_ref = float
	P_rh_ref = float
	T_ITD_des = float
	T_amb_des = float
	T_cold_ref = float
	T_hot = float
	T_hot_ref = float
	dT_cw_ref = float
	eta_ref = float
	n_pl_inc = float
	pb_bd_frac = float
	q_sby_frac = float
	rh_frac_ref = float
	startup_frac = float
	startup_time = float


class Parasitics(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	Design_power = float
	Piping_length = float
	Piping_loss = float
	aux_par = float
	aux_par_0 = float
	aux_par_1 = float
	aux_par_2 = float
	aux_par_f = float
	bop_par = float
	bop_par_0 = float
	bop_par_1 = float
	bop_par_2 = float
	bop_par_f = float
	design_eff = float
	pb_fixed_par = float
	piping_length_add = float
	piping_length_mult = float


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	P_b_in = tuple
	P_b_out = tuple
	P_cond = tuple
	P_cooling_tower_tot = tuple
	P_cycle = tuple
	P_drop_b = tuple
	P_fixed = tuple
	P_out_net = tuple
	P_parasitics = tuple
	P_piping_tot = tuple
	P_plant_balance_tot = tuple
	P_rh_in = tuple
	P_rh_out = tuple
	P_sh_out = tuple
	T_b_in = tuple
	T_boiling = tuple
	T_fw = tuple
	T_max_b_surf = tuple
	T_max_rh_surf = tuple
	T_max_sh_surf = tuple
	T_rh_in = tuple
	T_rh_out = tuple
	W_dot_boost = tuple
	annual_W_cycle_gross = float
	annual_energy = float
	annual_fuel_usage = float
	annual_total_water_use = float
	beam = tuple
	capacity_factor = float
	conversion_factor = float
	dP_rh = tuple
	dP_sh = tuple
	defocus = tuple
	eta_b = tuple
	eta_field = tuple
	eta_rec = tuple
	eta_rh = tuple
	eta_sh = tuple
	f_bays = tuple
	f_mdot_rh = tuple
	gen = tuple
	hour = tuple
	kwh_per_kw = float
	m_dot_aux = tuple
	m_dot_makeup = tuple
	m_dot_sh = tuple
	month = tuple
	pparasi = tuple
	pres = tuple
	q_abs_rec = tuple
	q_aux = tuple
	q_aux_fuel = tuple
	q_b_abs = tuple
	q_b_conv = tuple
	q_b_rad = tuple
	q_conv_rec = tuple
	q_inc_full = tuple
	q_rad_rec = tuple
	q_rh_abs = tuple
	q_rh_conv = tuple
	q_rh_rad = tuple
	q_sh_abs = tuple
	q_sh_conv = tuple
	q_sh_rad = tuple
	q_therm_in_rec = tuple
	solazi = tuple
	solzen = tuple
	system_heat_rate = float
	tdry = tuple
	tou_value = tuple
	twet = tuple
	v_rh_max = tuple
	v_sh_max = tuple
	wspd = tuple


class TcsdirectSteam(object):
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
	DirectSteamTower = DirectSteamTower
	TouTranslator = TouTranslator
	Heliostat = Heliostat
	Receiver = Receiver
	DsgController = DsgController
	Powerblock = Powerblock
	Parasitics = Parasitics
	Outputs = Outputs


def default(config) -> TcsdirectSteam
	pass

def new() -> TcsdirectSteam
	pass

def wrap(ssc_data_t) -> TcsdirectSteam
	pass

__loader__ = None 

__spec__ = None
