class Weather(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	azimuth = float
	file_name = str
	tilt = float
	track_mode = float


class SolarField(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	A_aperture = tuple
	AbsorberMaterial = tuple
	AnnulusGas = tuple
	Ave_Focal_Length = tuple
	ColperSCA = tuple
	D_2 = tuple
	D_3 = tuple
	D_4 = tuple
	D_5 = tuple
	D_cpnt = tuple
	D_p = tuple
	Design_loss = tuple
	Dirt_HCE = tuple
	Dirt_mirror = tuple
	Distance_SCA = tuple
	EPSILON_4 = tuple
	EPSILON_5 = tuple
	Error = tuple
	FieldConfig = float
	Flow_type = tuple
	Fluid = float
	GeomEffects = tuple
	GlazingIntactIn = tuple
	HCE_FieldFrac = tuple
	HDR_rough = float
	IAM_matrix = tuple
	I_bn_des = float
	K_cpnt = tuple
	L_SCA = tuple
	L_aperture = tuple
	L_cpnt = tuple
	L_heat_sink_piping = float
	L_rnr_per_xpan = float
	L_xpan_hdr = float
	L_xpan_rnr = float
	Min_rnr_xpans = float
	N_hdr_per_xpan = float
	N_max_hdr_diams = float
	P_a = tuple
	Pipe_hl_coef = float
	Rho_mirror_clean = tuple
	Rough = tuple
	Row_Distance = float
	SCADefocusArray = tuple
	SCAInfoArray = tuple
	SCA_drives_elec = float
	Shadowing = tuple
	T_fp = float
	T_loop_in_des = float
	T_loop_out = float
	Tau_envelope = tuple
	TrackingError = tuple
	Type_cpnt = tuple
	V_hdr_max = float
	V_hdr_min = float
	W_aperture = tuple
	accept_init = float
	accept_loc = float
	accept_mode = float
	alpha_abs = tuple
	alpha_env = tuple
	calc_design_pipe_vals = float
	custom_sf_pipe_sizes = float
	epsilon_3_11 = tuple
	epsilon_3_12 = tuple
	epsilon_3_13 = tuple
	epsilon_3_14 = tuple
	epsilon_3_21 = tuple
	epsilon_3_22 = tuple
	epsilon_3_23 = tuple
	epsilon_3_24 = tuple
	epsilon_3_31 = tuple
	epsilon_3_32 = tuple
	epsilon_3_33 = tuple
	epsilon_3_34 = tuple
	epsilon_3_41 = tuple
	epsilon_3_42 = tuple
	epsilon_3_43 = tuple
	epsilon_3_44 = tuple
	eta_pump = float
	is_model_heat_sink_piping = float
	m_dot_htfmax = float
	m_dot_htfmin = float
	mc_bal_cold = float
	mc_bal_hot = float
	mc_bal_sca = float
	nColt = float
	nHCEVar = float
	nHCEt = float
	nLoops = float
	nSCA = float
	northsouth_field_sep = float
	offset_xpan_hdr = float
	sf_hdr_diams = tuple
	sf_hdr_lengths = tuple
	sf_hdr_wallthicks = tuple
	sf_rnr_diams = tuple
	sf_rnr_lengths = tuple
	sf_rnr_wallthicks = tuple
	solar_mult = float
	theta_dep = float
	theta_stow = float
	washing_frequency = float
	water_usage_per_wash = float
	wind_stow_speed = float


class Controller(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	field_fl_props = tuple
	pb_pump_coef = float
	q_pb_design = float


class SystemDesign(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	tshours = float


class TES(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	cold_tank_Thtr = float
	cold_tank_max_heat = float
	h_tank = float
	init_hot_htf_percent = float
	tank_pairs = float
	u_tank = float


class TES2tank(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	h_tank_min = float
	hot_tank_Thtr = float
	hot_tank_max_heat = float


class Powerblock(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	L_rnr_pb = float


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	CosTh_ave = tuple
	EndLoss_ave = tuple
	EqOpteff = tuple
	IAM_ave = tuple
	RowShadow_ave = tuple
	SCAs_def = tuple
	T_field_cold_in = tuple
	T_field_hot_out = tuple
	T_heat_sink_in = tuple
	T_heat_sink_out = tuple
	T_rec_cold_in = tuple
	T_rec_hot_out = tuple
	T_tes_cold = tuple
	T_tes_hot = tuple
	Theta_ave = tuple
	W_dot_field_pump = tuple
	W_dot_parasitic_tot = tuple
	W_dot_pc_pump = tuple
	W_dot_sca_track = tuple
	annual_electricity_consumption = float
	annual_energy = float
	annual_field_freeze_protection = float
	annual_gross_energy = float
	annual_tes_freeze_protection = float
	annual_thermal_consumption = float
	annual_total_water_use = float
	beam = tuple
	deltaP_field = tuple
	dni_costh = tuple
	e_ch_tes = tuple
	e_dot_field_int_energy = tuple
	hour_day = tuple
	m_dot_balance = tuple
	m_dot_field_delivered = tuple
	m_dot_field_recirc = tuple
	m_dot_htf_heat_sink = tuple
	m_dot_loop = tuple
	m_dot_tes_ch = tuple
	m_dot_tes_dc = tuple
	month = tuple
	op_mode_1 = tuple
	op_mode_2 = tuple
	op_mode_3 = tuple
	pres = tuple
	q_balance = tuple
	q_ch_tes = tuple
	q_dc_tes = tuple
	q_dot_freeze_prot = tuple
	q_dot_htf_sf_out = tuple
	q_dot_piping_loss = tuple
	q_dot_rec_abs = tuple
	q_dot_rec_inc = tuple
	q_dot_rec_thermal_loss = tuple
	q_dot_to_heat_sink = tuple
	q_inc_sf_tot = tuple
	q_tes_heater = tuple
	qinc_costh = tuple
	solazi = tuple
	solzen = tuple
	tank_losses = tuple
	tdry = tuple
	time_hr = tuple
	twet = tuple
	wspd = tuple


class TroughPhysicalProcessHeat(object):
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
	SolarField = SolarField
	Controller = Controller
	SystemDesign = SystemDesign
	TES = TES
	TES2tank = TES2tank
	Powerblock = Powerblock
	Outputs = Outputs


def default(config) -> TroughPhysicalProcessHeat
	pass

def new() -> TroughPhysicalProcessHeat
	pass

def wrap(ssc_data_t) -> TroughPhysicalProcessHeat
	pass

__loader__ = None 

__spec__ = None
