class MHKTidal(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	loss_additional = float
	loss_array_spacing = float
	loss_downtime = float
	loss_resource_overprediction = float
	loss_transmission = float
	number_devices = float
	tidal_power_curve = tuple
	tidal_resource = tuple


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	annual_cumulative_energy_distribution = tuple
	annual_energy = float
	annual_energy_distribution = tuple
	capacity_factor = float
	device_average_power = float
	device_rated_capacity = float


class MhkTidal(object):
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

	MHKTidal = MHKTidal
	Outputs = Outputs


def default(config) -> MhkTidal
	pass

def new() -> MhkTidal
	pass

def wrap(ssc_data_t) -> MhkTidal
	pass

def from_existing(model, config="") -> MhkTidal
	pass

__loader__ = None 

__spec__ = None
