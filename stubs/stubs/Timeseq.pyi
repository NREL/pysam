class Timeseq(object):
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

	class TimeSequence(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		end_time = float
		start_time = float
		time_step = float


	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		day = tuple
		hour = tuple
		minute = tuple
		month = tuple
		time = tuple
		timehr = tuple




def default(config) -> Timeseq:
	pass

def new() -> Timeseq:
	pass

def wrap(ssc_data_t) -> Timeseq:
	pass

def from_existing(model, config="") -> Timeseq:
	pass

__loader__ = None 

__spec__ = None
