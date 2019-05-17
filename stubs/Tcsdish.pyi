class Weather(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	file_name = str


class Dish(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	system_capacity = float


class Type295(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	A_proj = float
	A_total = float
	I_cut_in = float
	d_ap = float
	d_ap_test = float
	ew_dish_sep = float
	h_slot_gap = float
	n_ew = float
	n_ns = float
	ns_dish_sep = float
	rho = float
	slope_ew = float
	slope_ns = float
	test_L_focal = float
	test_if = float
	w_slot_gap = float
	wind_stow_speed = float


class Type296(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	A_absorber = float
	A_wall = float
	DELTA_T_DIR = float
	DELTA_T_REFLUX = float
	L_cav = float
	L_insulation = float
	P_cav = float
	T_heater_head_high = float
	T_heater_head_low = float
	alpha_absorber = float
	alpha_wall = float
	d_cav = float
	k_insulation = float
	rec_type = float
	transmittance_cover = float


class Type297(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	Beale_const_coef = float
	Beale_first_coef = float
	Beale_fourth_coef = float
	Beale_square_coef = float
	Beale_third_coef = float
	Pressure_coef = float
	Pressure_first = float
	T_compression_in = float
	V_displaced = float
	engine_speed = float


class Type298(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	P_controls = float
	P_tower_fan = float
	T_cool_speed2 = float
	T_cool_speed3 = float
	Tower_water_outlet_temp = float
	b_cooler = float
	b_radiator = float
	cooling_fluid = float
	cooling_tower_on = float
	d_pipe_tower = float
	epsilon_cooler_test = float
	epsilon_power_test = float
	epsilon_radiator_test = float
	eta_tower_pump = float
	ew_dish_separation = float
	fan_control_signal = float
	fan_speed1 = float
	fan_speed2 = float
	fan_speed3 = float
	ns_dish_separation = float
	pump_speed = float
	system_availability = float
	test_P_fan = float
	test_P_pump = float
	test_T_fluid = float
	test_V_dot_fluid = float
	test_cooling_fluid = float
	test_fan_cfm = float
	test_fan_rho_air = float
	test_fan_speed = float
	test_pump_speed = float
	tower_m_dot_water = float
	tower_m_dot_water_test = float
	tower_mode = float
	tower_pipe_material = float


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	Collector_Losses = tuple
	P_SE_losses = tuple
	P_out_SE = tuple
	P_out_rec = tuple
	P_parasitic = tuple
	Phi_shade = tuple
	Power_in_collector = tuple
	Power_in_rec = tuple
	Power_out_col = tuple
	Q_rec_losses = tuple
	T_compression = tuple
	T_heater_head_operate = tuple
	T_tower_in = tuple
	T_tower_out = tuple
	annual_Collector_Losses = float
	annual_P_out_SE = float
	annual_P_out_rec = float
	annual_P_parasitic = float
	annual_Power_in_collector = float
	annual_Power_in_rec = float
	annual_Power_out_col = float
	annual_Q_rec_losses = float
	annual_energy = float
	beam = tuple
	capacity_factor = float
	conversion_factor = float
	engine_pressure = tuple
	eta_SE = tuple
	eta_collector = tuple
	eta_net = tuple
	eta_rec = tuple
	gen = tuple
	hour = tuple
	hourly_Collector_Losses = tuple
	hourly_P_out_SE = tuple
	hourly_P_out_rec = tuple
	hourly_P_parasitic = tuple
	hourly_Power_in_collector = tuple
	hourly_Power_in_rec = tuple
	hourly_Power_out_col = tuple
	hourly_Q_rec_losses = tuple
	kwh_per_kw = float
	month = tuple
	monthly_Collector_Losses = tuple
	monthly_P_out_SE = tuple
	monthly_P_out_rec = tuple
	monthly_P_parasitic = tuple
	monthly_Power_in_collector = tuple
	monthly_Power_in_rec = tuple
	monthly_Power_out_col = tuple
	monthly_Q_rec_losses = tuple
	monthly_energy = tuple
	net_power = tuple
	pres = tuple
	solazi = tuple
	solzen = tuple
	tdry = tuple
	twet = tuple
	wspd = tuple


class Tcsdish(object):
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
	Dish = Dish
	Type295 = Type295
	Type296 = Type296
	Type297 = Type297
	Type298 = Type298
	Outputs = Outputs


def default(config) -> Tcsdish
	pass

def new() -> Tcsdish
	pass

def wrap(ssc_data_t) -> Tcsdish
	pass

__loader__ = None 

__spec__ = None
