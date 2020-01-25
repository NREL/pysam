class Common(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	TES_HTF_code = float
	TES_HTF_props = tuple
	T_HTF_cold = float
	T_HTF_hot = float
	W_dot_pb_des = float
	eta_pb_des = float
	h_tank = float
	h_tank_min = float
	tank_pairs = float
	tes_hrs = float
	u_tank = float


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	HTF_dens = float
	d_tank = float
	q_dot_loss = float
	q_tes_des = float
	vol_one_temp_avail = float
	vol_one_temp_total = float


class UiTesCalcs(object):
	def assign(self, dict):
		pass

	def value(self, name, value=None):
		pass

	def execute(self, int_verbosity):
		pass

	def export(self):
		pass

	def __getattribute__(self, *args, **kwargs):
		pass

	def __init__(self, *args, **kwargs):
		pass

	Common = Common
	Outputs = Outputs


def default(config) -> UiTesCalcs
	pass

def new() -> UiTesCalcs
	pass

def wrap(ssc_data_t) -> UiTesCalcs
	pass

def from_existing(model, config="") -> UiTesCalcs
	pass

__loader__ = None 

__spec__ = None
