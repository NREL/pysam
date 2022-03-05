class TcstroughEmpirical(object):
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

	class Weather(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		azimuth = float
		file_name = str
		tilt = float
		track_mode = float


	class Trough(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		system_capacity = float


	class TouTranslator(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		weekday_schedule = tuple
		weekend_schedule = tuple


	class Solarfield(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		DepAngle = float
		Distance_SCA = float
		HTFFluid = float
		HtfGalArea = float
		MinHtfTemp = float
		NumScas = float
		Row_Distance = float
		SFTempInit = float
		SfInTempD = float
		SfOutTempD = float
		SfPipeHl1 = float
		SfPipeHl2 = float
		SfPipeHl3 = float
		SfPipeHl300 = float
		Solar_Field_Area = float
		Solar_Field_Mult = float
		Stow_Angle = float
		i_SfTi = float


	class Sca(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		Ave_Focal_Length = float
		ConcFac = float
		GeoAcc = float
		IamF0 = float
		IamF1 = float
		IamF2 = float
		MirCln = float
		MirRef = float
		SCA_aper = float
		ScaLen = float
		SfAvail = float
		TrkTwstErr = float


	class Hce(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		HCEBelShad = tuple
		HCEEnvTrans = tuple
		HCEFrac = tuple
		HCE_A0 = tuple
		HCE_A1 = tuple
		HCE_A2 = tuple
		HCE_A3 = tuple
		HCE_A4 = tuple
		HCE_A5 = tuple
		HCE_A6 = tuple
		HCEabs = tuple
		HCEdust = tuple
		HCEmisc = tuple
		HCEtype = tuple
		NumHCETypes = float
		PerfFac = tuple
		RefMirrAper = tuple


	class Pwrb(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		E2TPLF0 = float
		E2TPLF1 = float
		E2TPLF2 = float
		E2TPLF3 = float
		E2TPLF4 = float
		LHVBoilEff = float
		MaxGrOut = float
		MinGrOut = float
		PTTMAX = float
		PTTMIN = float
		T2EPLF0 = float
		T2EPLF1 = float
		T2EPLF2 = float
		T2EPLF3 = float
		T2EPLF4 = float
		TempCorr0 = float
		TempCorr1 = float
		TempCorr2 = float
		TempCorr3 = float
		TempCorr4 = float
		TempCorrF = float
		TurSUE = float
		TurbEffG = float
		TurbOutG = float


	class Tes(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		E_tes_ini = float
		FossilFill = tuple
		NUMTOU = float
		PFSmax = float
		PTSmax = float
		TSHOURS = float
		TSLogic = tuple
		TnkHL = float
		TurTesEffAdj = float
		TurTesOutAdj = float


	class Parasitic(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		AntiFrPar = float
		BOPPar = float
		BOPParF0 = float
		BOPParF1 = float
		BOPParF2 = float
		BOPParPF = float
		CHTFParF0 = float
		CHTFParF1 = float
		CHTFParF2 = float
		ChtfPar = float
		ChtfParPF = float
		CtOpF = float
		CtPar = float
		CtParF0 = float
		CtParF1 = float
		CtParF2 = float
		CtParPF = float
		HhtfPar = float
		HhtfParF0 = float
		HhtfParF1 = float
		HhtfParF2 = float
		HhtfParPF = float
		HtrPar = float
		HtrParF0 = float
		HtrParF1 = float
		HtrParF2 = float
		HtrParPF = float
		PbFixPar = float
		SfPar = float
		SfParPF = float


	class AdjustmentFactors(object):
		def assign(self): 
			pass
	
		def export(self): 
			return {}
	
		def __init__(self, *args, **kwargs): # real signature unknown
			pass
	
		constant = float
		dc_constant = float
		dc_hourly = tuple
		dc_periods = tuple
		hourly = tuple
		periods = tuple
		sf_constant = float
		sf_hourly = tuple
		sf_periods = tuple

	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		AveSfTemp = tuple
		ColEff = tuple
		CosTheta = tuple
		Egr = tuple
		EgrFos = tuple
		EgrSol = tuple
		EndLoss = tuple
		Enet = tuple
		Epar = tuple
		EparAnti = tuple
		EparBOP = tuple
		EparCHTF = tuple
		EparCT = tuple
		EparHhtf = tuple
		EparHtr = tuple
		EparOffLine = tuple
		EparOnLine = tuple
		EparPB = tuple
		EparSf = tuple
		Ets = tuple
		Ftrack = tuple
		IAM = tuple
		QTsFull = tuple
		QTsHl = tuple
		QTurSu = tuple
		Qdni = tuple
		Qdump = tuple
		Qfts = tuple
		Qgas = tuple
		QhtfFpHtr = tuple
		QhtfFpTES = tuple
		QhtfFreezeProt = tuple
		Qmin = tuple
		QnipCosTh = tuple
		Qsf = tuple
		QsfAbs = tuple
		QsfHceHL = tuple
		QsfPipeHL = tuple
		QsfWarmup = tuple
		Qsfnipcosth = tuple
		Qtpb = tuple
		Qtts = tuple
		RecHl = tuple
		RowShadow = tuple
		SfMassFlow = tuple
		SfTo = tuple
		Theta = tuple
		TrackAngle = tuple
		annual_W_cycle_gross = float
		annual_energy = float
		annual_energy_distribution_time = tuple
		annual_fuel_usage = float
		beam = tuple
		capacity_factor = float
		conversion_factor = float
		gen = tuple
		hour = tuple
		kwh_per_kw = float
		month = tuple
		monthly_energy = tuple
		o_SfTi = tuple
		pres = tuple
		solazi = tuple
		solzen = tuple
		system_heat_rate = float
		system_use_lifetime_output = float
		tdry = tuple
		tou_value = tuple
		twet = tuple
		wspd = tuple




def default(config) -> TcstroughEmpirical:
	pass

def new() -> TcstroughEmpirical:
	pass

def wrap(ssc_data_t) -> TcstroughEmpirical:
	pass

def from_existing(model, config="") -> TcstroughEmpirical:
	pass

__loader__ = None 

__spec__ = None
