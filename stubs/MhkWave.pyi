class MHKWave(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	device_rated_power = float
	loss_additional = float
	loss_array_spacing = float
	loss_downtime = float
	loss_resource_overprediction = float
	loss_transmission = float
	number_devices = float
	system_capacity = float
	wave_power_matrix = tuple
	wave_resource_matrix = tuple


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass


	annual_energy = float
	annual_energy_distribution = tuple
	capacity_factor = float
	device_average_power = float


class MhkWave(object):
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

	MHKWave = MHKWave
	Outputs = Outputs


def default(config) -> MhkWave
	pass

def new() -> MhkWave
	pass

def wrap(ssc_data_t) -> MhkWave
	pass

def from_existing(model, config="") -> MhkWave
	pass

__loader__ = None 

__spec__ = None
