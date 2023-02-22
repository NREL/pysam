class EtesPtes(object):
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

	class SolarResource(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		solar_resource_file = str


	class SystemControl(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		bop_par = float
		bop_par_0 = float
		bop_par_1 = float
		bop_par_2 = float
		bop_par_f = float
		disp_csu_cost = float
		disp_down_time_min = float
		disp_frequency = float
		disp_horizon = float
		disp_hsu_cost = float
		disp_max_iter = float
		disp_mip_gap = float
		disp_pen_delta_w = float
		disp_reporting = float
		disp_spec_bb = float
		disp_spec_presolve = float
		disp_spec_scaling = float
		disp_steps_per_hour = float
		disp_time_weighting = float
		disp_timeout = float
		disp_up_time_min = float
		is_dispatch = float
		pb_fixed_par = float
		sim_type = float
		time_start = float
		time_steps_per_hour = float
		time_stop = float
		vacuum_arrays = float


	class FinancialModel(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		etes_financial_model = float


	class SystemDesign(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		T_CT_cold_htf_des = float
		T_CT_hot_htf_des = float
		T_HT_cold_htf_des = float
		T_HT_hot_htf_des = float
		W_dot_pc_thermo_des = float
		cop_hp_thermo_des = float
		eta_pc_thermo_des = float
		f_hp_parasitic_des = float
		f_pc_parasitic_des = float
		heater_mult = float
		tshours = float


	class ThermalStorage(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		cold_htf_code = float
		hot_htf_code = float
		ud_cold_htf_props = tuple
		ud_hot_htf_props = tuple


	class Heater(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		f_q_dot_des_allowable_su = float
		f_q_dot_heater_min = float
		hrs_startup_at_max_rate = float


	class PowerCycle(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		CT_pb_pump_coef = float
		cycle_cutoff_frac = float
		cycle_max_frac = float
		heat_pump_CT_HTF_pump_coef = float
		heat_pump_HT_HTF_pump_coef = float
		pb_pump_coef = float
		q_sby_frac = float
		startup_frac = float
		startup_time = float


	class HotThermalStorage(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		cold_tank_Thtr = float
		cold_tank_max_heat = float
		h_tank = float
		h_tank_min = float
		hot_tank_Thtr = float
		hot_tank_max_heat = float
		tank_pairs = float
		tes_init_hot_htf_percent = float
		u_tank = float


	class ColdThermalStorage(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		CT_h_tank = float
		CT_h_tank_min = float
		CT_tank_pairs = float
		CT_u_tank = float


	class TimeOfDeliveryFactors(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		dispatch_factor1 = float
		dispatch_factor2 = float
		dispatch_factor3 = float
		dispatch_factor4 = float
		dispatch_factor5 = float
		dispatch_factor6 = float
		dispatch_factor7 = float
		dispatch_factor8 = float
		dispatch_factor9 = float
		dispatch_factors_ts = tuple
		dispatch_sched_weekday = tuple
		dispatch_sched_weekend = tuple
		ppa_multiplier_model = float


	class Revenue(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		ppa_price_input = tuple


	class SystemCosts(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		CT_tes_spec_cost = float
		bop_spec_cost = float
		contingency_rate = float
		cycle_spec_cost = float
		epc_cost_fixed = float
		epc_cost_per_watt = float
		epc_cost_perc_of_direct = float
		heat_pump_spec_cost = float
		land_cost_fixed = float
		land_cost_per_watt = float
		land_cost_perc_of_direct = float
		sales_tax_frac = float
		tes_spec_cost = float


	class FinancialParameters(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		const_per_interest_rate1 = float
		const_per_interest_rate2 = float
		const_per_interest_rate3 = float
		const_per_interest_rate4 = float
		const_per_interest_rate5 = float
		const_per_months1 = float
		const_per_months2 = float
		const_per_months3 = float
		const_per_months4 = float
		const_per_months5 = float
		const_per_percent1 = float
		const_per_percent2 = float
		const_per_percent3 = float
		const_per_percent4 = float
		const_per_percent5 = float
		const_per_upfront_rate1 = float
		const_per_upfront_rate2 = float
		const_per_upfront_rate3 = float
		const_per_upfront_rate4 = float
		const_per_upfront_rate5 = float
		sales_tax_rate = float


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


		COP_net_des = float
		CT_tes_cost_calc = float
		E_hp_su_des = float
		Q_CT_tes_des = float
		Q_tes_des = float
		T_CT_tes_cold = tuple
		T_CT_tes_hot = tuple
		T_hp_CT_htf_cold_out = tuple
		T_hp_CT_htf_hot_in = tuple
		T_hp_HT_htf_cold_in = tuple
		T_hp_HT_htf_hot_out = tuple
		T_pc_CT_htf_cold_in = tuple
		T_pc_CT_htf_hot_out = tuple
		T_pc_HT_htf_cold_out = tuple
		T_pc_HT_htf_hot_in = tuple
		T_tes_cold = tuple
		T_tes_hot = tuple
		V_CT_tes_htf_avail = float
		V_CT_tes_htf_total = float
		V_tes_htf_avail = float
		V_tes_htf_total = float
		W_dot_bop_design = float
		W_dot_bop_parasitics = tuple
		W_dot_fixed = float
		W_dot_fixed_parasitics = tuple
		W_dot_hp_CT_htf_pump = tuple
		W_dot_hp_CT_htf_pump_des = float
		W_dot_hp_HT_htf_pump = tuple
		W_dot_hp_HT_htf_pump_des = float
		W_dot_hp_elec_parasitic_des = float
		W_dot_hp_in_net_des = float
		W_dot_hp_in_thermo_des = float
		W_dot_hp_net = tuple
		W_dot_hp_parasitics = tuple
		W_dot_hp_thermo = tuple
		W_dot_out_net = tuple
		W_dot_pc_CT_htf_pump = tuple
		W_dot_pc_CT_htf_pump_des = float
		W_dot_pc_HT_htf_pump = tuple
		W_dot_pc_HT_htf_pump_des = float
		W_dot_pc_elec_parasitic_des = float
		W_dot_pc_net_des = float
		W_dot_pc_parasitics = tuple
		W_dot_pc_thermo_out = tuple
		annual_energy = float
		annual_energy_distribution_time = tuple
		avg_suboptimal_rel_mip_gap = float
		bop_cost_calc = float
		charge_capacity = float
		construction_financing_cost = float
		contingency_cost_calc = float
		cop_hot_hp_thermo = tuple
		cp_battery_nameplate = float
		cp_system_nameplate = float
		cycle_cost_calc = float
		d_CT_tank_tes = float
		d_tank_tes = float
		direct_subtotal_cost_calc = float
		disp_iter_ann = float
		disp_obj_relax = tuple
		disp_objective = tuple
		disp_objective_ann = float
		disp_pceff_expected = tuple
		disp_presolve_nconstr = tuple
		disp_presolve_nconstr_ann = float
		disp_presolve_nvar = tuple
		disp_presolve_nvar_ann = float
		disp_qpbsu_expected = tuple
		disp_qsfprod_expected = tuple
		disp_qsfsu_expected = tuple
		disp_rel_mip_gap = tuple
		disp_rev_expected = tuple
		disp_solve_iter = tuple
		disp_solve_state = tuple
		disp_solve_state_ann = float
		disp_solve_time = tuple
		disp_solve_time_ann = float
		disp_subopt_flag = tuple
		disp_tes_expected = tuple
		disp_wpb_expected = tuple
		e_ch_tes = tuple
		elec_purchase_price_mult = tuple
		epc_cost_calc = float
		eta_pc_net_des = float
		eta_pc_thermo = tuple
		flip_target_percent = float
		gen = tuple
		heater_cost_calc = float
		installed_per_cap_cost_calc = float
		land_cost_calc = float
		m_dot_balance = tuple
		m_dot_hp_CT_htf = tuple
		m_dot_hp_CT_htf_des = float
		m_dot_hp_HT_htf = tuple
		m_dot_hp_HT_htf_des = float
		m_dot_pc_CT_htf = tuple
		m_dot_pc_CT_htf_des = float
		m_dot_pc_HT_htf = tuple
		m_dot_pc_HT_htf_des = float
		mass_CT_tes_cold = tuple
		mass_CT_tes_hot = tuple
		mass_tes_cold = tuple
		mass_tes_hot = tuple
		n_op_modes = tuple
		nameplate = float
		op_mode_1 = tuple
		op_mode_2 = tuple
		op_mode_3 = tuple
		ppa_soln_mode = float
		q_balance = tuple
		q_dot_CT_tes_heater = tuple
		q_dot_CT_tes_losses = tuple
		q_dot_ch_tes = tuple
		q_dot_dc_tes = tuple
		q_dot_hp_cold_in_des = float
		q_dot_hp_from_CT_htf = tuple
		q_dot_hp_hot_out_des = float
		q_dot_hp_startup = tuple
		q_dot_hp_to_HT_htf = tuple
		q_dot_loss_CT_tes_des = float
		q_dot_loss_tes_des = float
		q_dot_pc_cold_out_thermo_des = float
		q_dot_pc_cold_to_CTES_des = float
		q_dot_pc_cold_to_surroundings_des = float
		q_dot_pc_from_HT_htf = tuple
		q_dot_pc_hot_in_des = float
		q_dot_pc_rejected = tuple
		q_dot_pc_startup = tuple
		q_dot_pc_thermo_out = tuple
		q_dot_pc_to_CT_htf = tuple
		q_dot_tes_heater = tuple
		q_dot_tes_losses = tuple
		q_pc_target = tuple
		rte_net = float
		rte_thermo = float
		sales_tax_cost_calc = float
		system_capacity = float
		tdry = tuple
		tes_cost_calc = float
		time_hr = tuple
		total_direct_cost_calc = float
		total_indirect_cost_calc = float
		total_installed_cost = float
		tou_period = tuple
		tshours_heater = float
		twet = tuple




def default(config) -> EtesPtes:
	pass

def new() -> EtesPtes:
	pass

def wrap(ssc_data_t) -> EtesPtes:
	pass

def from_existing(model, config="") -> EtesPtes:
	pass

__loader__ = None 

__spec__ = None
