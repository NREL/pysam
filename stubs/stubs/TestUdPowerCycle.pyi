class TestUdPowerCycle(object):
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

	class Common(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		q_pb_design = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		udpc_table_out = tuple




def default(config) -> TestUdPowerCycle:
	pass

def new() -> TestUdPowerCycle:
	pass

def wrap(ssc_data_t) -> TestUdPowerCycle:
	pass

def from_existing(model, config="") -> TestUdPowerCycle:
	pass

__loader__ = None 

__spec__ = None
