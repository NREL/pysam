class LocationAndResource(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	solar_resource_data = dict
	solar_resource_file = str


class TimeOfDeliveryFactors(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	dispatch_factor1 = float
	dispatch_factor2 = float
	dispatch_factor3 = float
	dispatch_factor4 = float
	dispatch_factor5 = float
	dispatch_factor6 = float
	dispatch_factor7 = float
	dispatch_factor8 = float
	dispatch_factor9 = float
	dispatch_factors_ts = tuple
	dispatch_sched_weekday = tuple
	dispatch_sched_weekend = tuple
	ppa_multiplier_model = float


class HeliostatField(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	A_sf_in = float
	N_hel = float
	c_atm_0 = float
	c_atm_1 = float
	c_atm_2 = float
	c_atm_3 = float
	calc_fluxmaps = float
	cant_type = float
	check_max_flux = float
	csp_pt_sf_fixed_land_area = float
	csp_pt_sf_land_overhead_factor = float
	dens_mirror = float
	eta_map = tuple
	eta_map_aod_format = float
	field_model_type = float
	flux_maps = tuple
	focus_type = float
	hel_stow_deploy = float
	helio_active_fraction = float
	helio_aim_points = tuple
	helio_height = float
	helio_optical_error_mrad = float
	helio_positions = tuple
	helio_reflectance = float
	helio_width = float
	interp_beta = float
	interp_nug = float
	land_area_base = float
	land_bound_list = tuple
	land_bound_table = tuple
	land_max = float
	land_min = float
	n_facet_x = float
	n_facet_y = float
	opt_algorithm = float
	opt_conv_tol = float
	opt_flux_penalty = float
	opt_init_step = float
	opt_max_iter = float
	p_start = float
	p_track = float
	v_wind_max = float
	washing_frequency = float
	water_usage_per_wash = float


class SystemDesign(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	P_ref = float
	T_htf_cold_des = float
	T_htf_hot_des = float
	design_eff = float
	dni_des = float
	gross_net_conversion_factor = float
	sf_excess = float
	solarm = float
	tshours = float


class TowerAndReceiver(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	D_rec = float
	Flow_type = float
	N_panels = float
	crossover_shift = float
	csp_pt_rec_max_oper_frac = float
	d_tube_out = float
	delta_flux_hrs = float
	epsilon = float
	eta_pump = float
	f_rec_min = float
	field_fl_props = tuple
	flux_max = float
	h_tower = float
	hl_ffact = float
	mat_tube = float
	n_flux_days = float
	piping_length_const = float
	piping_length_mult = float
	piping_loss = float
	rec_absorptance = float
	rec_height = float
	rec_hl_perm2 = float
	rec_htf = float
	rec_qf_delay = float
	rec_su_delay = float
	th_tube = float


class SystemCosts(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	bop_spec_cost = float
	contingency_rate = float
	cost_sf_fixed = float
	csp_pt_cost_epc_fixed = float
	csp_pt_cost_epc_per_acre = float
	csp_pt_cost_epc_per_watt = float
	csp_pt_cost_epc_percent = float
	csp_pt_cost_plm_fixed = float
	csp_pt_cost_plm_per_watt = float
	csp_pt_cost_plm_percent = float
	fossil_spec_cost = float
	heliostat_spec_cost = float
	land_spec_cost = float
	plant_spec_cost = float
	rec_cost_exp = float
	rec_ref_area = float
	rec_ref_cost = float
	sales_tax_frac = float
	site_spec_cost = float
	tes_spec_cost = float
	tower_exp = float
	tower_fixed_cost = float


class FinancialParameters(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	const_per_interest_rate1 = float
	const_per_interest_rate2 = float
	const_per_interest_rate3 = float
	const_per_interest_rate4 = float
	const_per_interest_rate5 = float
	const_per_months1 = float
	const_per_months2 = float
	const_per_months3 = float
	const_per_months4 = float
	const_per_months5 = float
	const_per_percent1 = float
	const_per_percent2 = float
	const_per_percent3 = float
	const_per_percent4 = float
	const_per_percent5 = float
	const_per_upfront_rate1 = float
	const_per_upfront_rate2 = float
	const_per_upfront_rate3 = float
	const_per_upfront_rate4 = float
	const_per_upfront_rate5 = float
	sales_tax_rate = float


class ThermalStorage(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	cold_tank_Thtr = float
	cold_tank_max_heat = float
	csp_pt_tes_init_hot_htf_percent = float
	h_tank = float
	h_tank_min = float
	hot_tank_Thtr = float
	hot_tank_max_heat = float
	tank_pairs = float
	u_tank = float


class RADCOOL(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	D_rad_tubes = float
	L_rad = float
	L_rad_sections = float
	T_ctes_cold_design = float
	T_ctes_cold_ini = float
	T_ctes_warm_design = float
	T_ctes_warm_ini = float
	W_rad_tubes = float
	ctes_cost = float
	ctes_field_fl = float
	ctes_tankpairs = float
	ctes_tshours = float
	ctes_type = float
	epsilon_radHX = float
	epsilon_radbot = float
	epsilon_radgrnd = float
	epsilon_radtop = float
	f_ctes_warm_ini = float
	h_ctes_tank = float
	h_ctes_tank_min = float
	helio_area_tot = float
	k_panel = float
	m_dot_radpanel = float
	n_rad_tubes = float
	rad_multiplier = float
	rad_pressuredrop = float
	radfluid_vol_ratio = float
	radiator_fluidcost = float
	radiator_installcost = float
	radiator_unitcost = float
	th_rad_panel = float
	u_ctes_tank = float


class PowerCycle(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	cycle_cutoff_frac = float
	cycle_max_frac = float
	pb_pump_coef = float
	pc_config = float
	q_sby_frac = float
	startup_frac = float
	startup_time = float


class RankineCycle(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	CT = float
	P_boil = float
	P_cond_min = float
	P_cond_ratio = float
	T_ITD_des = float
	T_amb_des = float
	T_approach = float
	dT_cw_ref = float
	n_pl_inc = float
	pb_bd_frac = float
	tech_type = float


class SystemControl(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	F_wc = tuple
	ampl_data_dir = str
	ampl_exec_call = str
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
	disp_csu_cost = float
	disp_frequency = float
	disp_horizon = float
	disp_max_iter = float
	disp_mip_gap = float
	disp_pen_delta_w = float
	disp_reporting = float
	disp_rsu_cost = float
	disp_spec_bb = float
	disp_spec_presolve = float
	disp_spec_scaling = float
	disp_steps_per_hour = float
	disp_time_weighting = float
	disp_timeout = float
	dispatch_series = tuple
	f_turb_tou_periods = tuple
	is_ampl_engine = float
	is_dispatch = float
	is_dispatch_series = float
	is_wlim_series = float
	is_write_ampl_dat = float
	pb_fixed_par = float
	q_rec_heattrace = float
	q_rec_standby = float
	time_start = float
	time_steps_per_hour = float
	time_stop = float
	vacuum_arrays = float
	weekday_schedule = tuple
	weekend_schedule = tuple
	wlim_series = tuple


class UserDefinedPowerCycle(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	ud_T_amb_des = float
	ud_T_amb_high = float
	ud_T_amb_ind_od = tuple
	ud_T_amb_low = float
	ud_T_htf_high = float
	ud_T_htf_ind_od = tuple
	ud_T_htf_low = float
	ud_f_W_dot_cool_des = float
	ud_ind_od = tuple
	ud_m_dot_htf_high = float
	ud_m_dot_htf_ind_od = tuple
	ud_m_dot_htf_low = float
	ud_m_dot_water_cool_des = float


class SCO2Cycle(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	P_high_limit = float
	_sco2_P_high_limit = float
	_sco2_P_ref = float
	_sco2_T_amb_des = float
	_sco2_T_approach = float
	_sco2_T_htf_hot_des = float
	_sco2_deltaT_PHX = float
	_sco2_design_eff = float
	_sco2_eta_c = float
	_sco2_eta_t = float
	_sco2_recup_eff_max = float
	deltaT_PHX = float
	eta_c = float
	eta_t = float
	fan_power_perc_net = float
	is_sco2_preprocess = float
	recup_eff_max = float
	sco2_T_amb_des = float
	sco2_T_approach = float
	sco2_cycle_config = float
	sco2ud_T_amb_high = float
	sco2ud_T_amb_ind_od = tuple
	sco2ud_T_amb_low = float
	sco2ud_T_htf_cold_calc = float
	sco2ud_T_htf_high = float
	sco2ud_T_htf_ind_od = tuple
	sco2ud_T_htf_low = float
	sco2ud_m_dot_htf_high = float
	sco2ud_m_dot_htf_ind_od = tuple
	sco2ud_m_dot_htf_low = float


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	A_radfield = float
	A_sf = float
	P_cond = tuple
	P_cooling_tower_tot = tuple
	P_cycle = tuple
	P_fixed = tuple
	P_out_net = tuple
	P_plant_balance_tot = tuple
	P_tower_pump = tuple
	Q_thermal = tuple
	T_cold = tuple
	T_cond_out = tuple
	T_pc_in = tuple
	T_pc_out = tuple
	T_rad_out = tuple
	T_rec_in = tuple
	T_rec_out = tuple
	T_tes_cold = tuple
	T_tes_hot = tuple
	T_warm = tuple
	annual_W_cooling_tower = float
	annual_W_cycle_gross = float
	annual_energy = float
	annual_total_water_use = float
	beam = tuple
	capacity_factor = float
	const_per_interest1 = float
	const_per_interest2 = float
	const_per_interest3 = float
	const_per_interest4 = float
	const_per_interest5 = float
	const_per_interest_total = float
	const_per_percent_total = float
	const_per_principal1 = float
	const_per_principal2 = float
	const_per_principal3 = float
	const_per_principal4 = float
	const_per_principal5 = float
	const_per_principal_total = float
	const_per_total1 = float
	const_per_total2 = float
	const_per_total3 = float
	const_per_total4 = float
	const_per_total5 = float
	construction_financing_cost = float
	conversion_factor = float
	csp_pt_cost_bop = float
	csp_pt_cost_contingency = float
	csp_pt_cost_epc_total = float
	csp_pt_cost_fossil = float
	csp_pt_cost_heliostats = float
	csp_pt_cost_installed_per_capacity = float
	csp_pt_cost_plm_total = float
	csp_pt_cost_power_block = float
	csp_pt_cost_rad_field = float
	csp_pt_cost_rad_fluid = float
	csp_pt_cost_rad_storage = float
	csp_pt_cost_receiver = float
	csp_pt_cost_sales_tax_total = float
	csp_pt_cost_site_improvements = float
	csp_pt_cost_storage = float
	csp_pt_cost_total_land_area = float
	csp_pt_cost_tower = float
	defocus = tuple
	disp_iter_ann = float
	disp_obj_relax = tuple
	disp_objective = tuple
	disp_objective_ann = float
	disp_pceff_expected = tuple
	disp_presolve_nconstr = tuple
	disp_presolve_nconstr_ann = float
	disp_presolve_nvar = tuple
	disp_presolve_nvar_ann = float
	disp_qpbsu_expected = tuple
	disp_qsf_expected = tuple
	disp_qsfprod_expected = tuple
	disp_qsfsu_expected = tuple
	disp_rev_expected = tuple
	disp_solve_iter = tuple
	disp_solve_state = tuple
	disp_solve_time = tuple
	disp_solve_time_ann = float
	disp_tes_expected = tuple
	disp_thermeff_expected = tuple
	disp_wpb_expected = tuple
	e_ch_tes = tuple
	eta = tuple
	eta_field = tuple
	eta_map_out = tuple
	eta_therm = tuple
	flux_maps_out = tuple
	gen = tuple
	htf_pump_power = tuple
	is_pc_sb_allowed = tuple
	is_pc_su_allowed = tuple
	is_rec_su_allowed = tuple
	kwh_per_kw = float
	m_cold = tuple
	m_dot_balance = tuple
	m_dot_pc = tuple
	m_dot_rec = tuple
	m_dot_tes_ch = tuple
	m_dot_tes_dc = tuple
	m_dot_water_pc = tuple
	m_warm = tuple
	n_op_modes = tuple
	op_mode_1 = tuple
	op_mode_2 = tuple
	op_mode_3 = tuple
	operating_modes_a = tuple
	operating_modes_b = tuple
	operating_modes_c = tuple
	pparasi = tuple
	pricing_mult = tuple
	q_balance = tuple
	q_ch_tes = tuple
	q_dc_tes = tuple
	q_dot_est_cr_on = tuple
	q_dot_est_cr_su = tuple
	q_dot_est_tes_ch = tuple
	q_dot_est_tes_dc = tuple
	q_dot_pc_max = tuple
	q_dot_pc_min = tuple
	q_dot_pc_sb = tuple
	q_dot_pc_startup = tuple
	q_dot_pc_target = tuple
	q_dot_rec_inc = tuple
	q_heater = tuple
	q_pb = tuple
	q_pc_startup = tuple
	q_piping_losses = tuple
	q_sf_inc = tuple
	q_startup = tuple
	q_thermal_loss = tuple
	radcool_control = tuple
	rh = tuple
	sf_adjust_out = tuple
	solaz = tuple
	solzen = tuple
	tank_losses = tuple
	tdry = tuple
	time_hr = tuple
	total_direct_cost = float
	total_indirect_cost = float
	total_installed_cost = float
	tou_value = tuple
	twet = tuple
	ud_T_amb_ind_od_out = tuple
	ud_T_htf_ind_od_out = tuple
	ud_m_dot_htf_ind_od_out = tuple
	ui_direct_subtotal = float
	wspd = tuple


class TcsmoltenSalt(object):
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

	LocationAndResource = LocationAndResource
	TimeOfDeliveryFactors = TimeOfDeliveryFactors
	HeliostatField = HeliostatField
	SystemDesign = SystemDesign
	TowerAndReceiver = TowerAndReceiver
	SystemCosts = SystemCosts
	FinancialParameters = FinancialParameters
	ThermalStorage = ThermalStorage
	RADCOOL = RADCOOL
	PowerCycle = PowerCycle
	RankineCycle = RankineCycle
	SystemControl = SystemControl
	UserDefinedPowerCycle = UserDefinedPowerCycle
	SCO2Cycle = SCO2Cycle
	Outputs = Outputs


def default(config) -> TcsmoltenSalt
	pass

def new() -> TcsmoltenSalt
	pass

def wrap(ssc_data_t) -> TcsmoltenSalt
	pass

__loader__ = None 

__spec__ = None
