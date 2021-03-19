class IEC61853(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	input = tuple
	param = tuple


class SingleDiodeModel(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	I = float
	T = float


class Outputs(object):
	def assign(self): 
		pass

	def export(self) -> dict:
		pass

	def __init__(self, *args, **kwargs): 
		pass


	Il = float
	Io = float
	Rs = float
	Rsh = float
	a = float


class Iec61853interp(object):
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

	IEC61853 = IEC61853
	SingleDiodeModel = SingleDiodeModel
	Outputs = Outputs


def default(config) -> Iec61853interp:
	pass

def new() -> Iec61853interp:
	pass

def wrap(ssc_data_t) -> Iec61853interp:
	pass

def from_existing(model, config="") -> Iec61853interp:
	pass

__loader__ = None 

__spec__ = None
