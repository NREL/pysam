class EtesElectricResistance(object):
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

	def get_data_ptr(self):
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


		P_ref = float
		T_htf_cold_des = float
		T_htf_hot_des = float
		design_eff = float
		heater_mult = float
		tshours = float


	class PowerCycle(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		cycle_cutoff_frac = float
		cycle_max_frac = float
		pb_pump_coef = float
		pc_config = float
		q_sby_frac = float
		startup_frac = float
		startup_time = float


	class RankineCycle(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		CT = float
		P_boil = float
		P_cond_min = float
		P_cond_ratio = float
		T_ITD_des = float
		T_amb_des = float
		T_approach = float
		dT_cw_ref = float
		n_pl_inc = float
		pb_bd_frac = float
		tech_type = float


	class UserDefinedPowerCycle(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		ud_f_W_dot_cool_des = float
		ud_ind_od = tuple
		ud_is_sco2_regr = float
		ud_m_dot_water_cool_des = float


	class ThermalStorage(object):
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
		hot_htf_code = float
		hot_tank_Thtr = float
		hot_tank_max_heat = float
		tank_pairs = float
		tes_init_hot_htf_percent = float
		u_tank = float
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
		heater_efficiency = float
		hrs_startup_at_max_rate = float


	class TimeOfDeliveryFactors(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		dispatch_factors_ts = tuple
		dispatch_sched_weekday = tuple
		dispatch_sched_weekend = tuple
		dispatch_tod_factors = tuple
		ppa_multiplier_model = float


	class Revenue(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		mp_energy_market_revenue = tuple
		ppa_price_input = tuple


	class SystemCost(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		cycle_spec_cost = float


	class SystemCosts(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		bop_spec_cost = float
		contingency_rate = float
		epc_cost_fixed = float
		epc_cost_per_watt = float
		epc_cost_perc_of_direct = float
		heater_spec_cost = float
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
	
		adjust_constant = float
		adjust_en_hourly = float
		adjust_en_periods = float
		adjust_en_timeindex = float
		adjust_hourly = tuple
		adjust_periods = tuple
		adjust_timeindex = tuple
		dc_adjust_constant = float
		dc_adjust_en_hourly = float
		dc_adjust_en_periods = float
		dc_adjust_en_timeindex = float
		dc_adjust_hourly = tuple
		dc_adjust_periods = tuple
		dc_adjust_timeindex = tuple
		sf_adjust_constant = float
		sf_adjust_en_hourly = float
		sf_adjust_en_periods = float
		sf_adjust_en_timeindex = float
		sf_adjust_hourly = tuple
		sf_adjust_periods = tuple
		sf_adjust_timeindex = tuple

	class Outputs(object):
		def assign(self): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		E_heater_su_des = float
		Q_dot_HTF_ND_des_calc = float
		Q_tes_des = float
		T_amb_high_calc = float
		T_amb_low_calc = float
		T_amb_ref_calc = float
		T_htf_cycle_in = tuple
		T_htf_cycle_out = tuple
		T_htf_heater_in = tuple
		T_htf_heater_out = tuple
		T_htf_high_calc = float
		T_htf_low_calc = float
		T_htf_ref_calc = float
		T_tes_cold = tuple
		T_tes_hot = tuple
		V_tes_htf_avail = float
		V_tes_htf_total = float
		W_dot_bop_design = float
		W_dot_bop_parasitics = tuple
		W_dot_cooling_ND_des_calc = float
		W_dot_cycle_cooling = tuple
		W_dot_cycle_gross = tuple
		W_dot_cycle_htf_pump = tuple
		W_dot_cycle_net = tuple
		W_dot_fixed_parasitics = tuple
		W_dot_gross_ND_des_calc = float
		W_dot_heater = tuple
		W_dot_heater_des = float
		W_dot_out_net = tuple
		annual_E_cycle_gross = float
		annual_E_heater = float
		annual_E_tes_heater = float
		annual_Q_cycle_thermal_in = float
		annual_Q_cycle_thermal_startup = float
		annual_Q_heater_startup = float
		annual_Q_heater_to_htf = float
		annual_Q_tes_losses = float
		annual_energy = float
		annual_energy_distribution_time = tuple
		annual_energy_full_availability = float
		avg_suboptimal_rel_mip_gap = float
		bop_cost_calc = float
		construction_financing_cost = float
		contingency_cost_calc = float
		cp_battery_nameplate = float
		cp_htf_cycle_des = float
		cp_system_nameplate = float
		cycle_cost_calc = float
		d_tank_tes = float
		dens_store_htf_at_T_ave = float
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
		eta_cycle_gross = tuple
		eta_cycle_net = tuple
		flip_target_percent = float
		gen = tuple
		heater_cost_calc = float
		installed_per_cap_cost_calc = float
		land_cost_calc = float
		m_dot_balance = tuple
		m_dot_htf_ND_high_calc = float
		m_dot_htf_ND_low_calc = float
		m_dot_htf_ND_ref_calc = float
		m_dot_htf_cycle = tuple
		m_dot_htf_cycle_des = float
		m_dot_htf_heater = tuple
		m_dot_water_ND_des_calc = float
		m_dot_water_cycle = tuple
		mass_tes_cold = tuple
		mass_tes_hot = tuple
		n_T_amb_pars_calc = float
		n_T_htf_pars_calc = float
		n_m_dot_pars_calc = float
		n_op_modes = tuple
		nameplate = float
		op_mode_1 = tuple
		op_mode_2 = tuple
		op_mode_3 = tuple
		operating_modes_a = tuple
		operating_modes_b = tuple
		operating_modes_c = tuple
		ppa_soln_mode = float
		q_balance = tuple
		q_dot_ch_tes = tuple
		q_dot_cycle = tuple
		q_dot_cycle_startup = tuple
		q_dot_dc_tes = tuple
		q_dot_heater_design = float
		q_dot_heater_startup = tuple
		q_dot_heater_to_htf = tuple
		q_dot_loss_tes_des = float
		q_dot_tes_heater = tuple
		q_dot_tes_losses = tuple
		q_pb_design = float
		sales_tax_cost_calc = float
		sim_cpu_run_time = float
		system_capacity = float
		tdry = tuple
		tes_cost_calc = float
		time_hr = tuple
		total_direct_cost_calc = float
		total_indirect_cost_calc = float
		total_installed_cost = float
		total_land_area = float
		tou_period = tuple
		tshours_heater = float
		twet = tuple




def default(config) -> EtesElectricResistance:
	pass

def new() -> EtesElectricResistance:
	pass

def wrap(ssc_data_t) -> EtesElectricResistance:
	pass

def from_existing(model, config="") -> EtesElectricResistance:
	pass

__loader__ = None 

__spec__ = None
