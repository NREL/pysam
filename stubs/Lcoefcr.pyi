class SimpleLCOE(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	annual_energy = float
	capital_cost = float
	fixed_charge_rate = float
	fixed_operating_cost = float
	variable_operating_cost = float


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> Dict[Dict]
		pass

	def __init__(self, *args, **kwargs): 
		pass

	lcoe_fcr = float


class Lcoefcr(object):
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

	SimpleLCOE = SimpleLCOE
	Outputs = Outputs


def default(config) -> Lcoefcr
	pass

def new() -> Lcoefcr
	pass

def wrap(ssc_data_t) -> Lcoefcr
	pass

__loader__ = None 

__spec__ = None
