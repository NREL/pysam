from pathlib import Path
import os
import sys
import pyomo.environ as pyo
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import idaes.logger as idaeslog
from pyomo.util.infeasible import log_infeasible_constraints, log_infeasible_bounds, log_close_to_bounds
import logging
from datetime import datetime

logging.getLogger('pyomo.core').setLevel(logging.ERROR)
solve_log = logging.getLogger('solve_log')
solve_log.setLevel(logging.INFO)
solve_log = logging.LoggerAdapter(solve_log, {"tag": solve_log})

IL_SCALING = 1e8
RSH_SCALING = 1e-3
test_data_cols = ['A_c', 'N_s', 'I_sc_ref', 'V_oc_ref', 'I_mp_ref', 'V_mp_ref', 'T_NOCT',
                  'gamma_r', 'alpha_sc', 'beta_oc']
model_param_cols = ["a_py", "Il_py", "Io_py", "Rs_py", "Rsh_py", "Adj_py"]
model_param_cols_ssc = ["a_ssc", "Il_ssc", "Io_ssc","Rs_ssc","Rsh_ssc","Adj_ssc"]
iv_diff_cols = ['d_Isc', 'd_Imp', 'd_Vmp', 'd_Pmp']

# 6par_solve.h L 423
def current_at_voltage_cec(Vmodule, IL_ref, IO_ref, RS, A_ref, RSH_ref, I_mp_ref):
    """
    Solve for the current at the voltage Vmodule, given the single diode parameters which could have been modified for non-STC condition
    """
    F = 0
    Fprime = 0
    Iold = 0.0
    Inew = I_mp_ref

    it = 0
    maxit = 4000
    while (abs(Inew - Iold) > 1.0e-4 and it < maxit ):
        Iold = Inew

        F = IL_ref - Iold - IO_ref * \
            (np.exp((Vmodule + Iold * RS) / A_ref) - 1.0) - \
            (Vmodule + Iold * RS) / RSH_ref

        Fprime = -1.0 - IO_ref * (RS / A_ref) * \
            np.exp((Vmodule + Iold * RS) / A_ref) - \
            (RS / RSH_ref)

        Inew = max(0.0, (Iold - (F / Fprime)))

    return Inew

def cec_model_params_at_condition(model, Irr, T_cell_K):
    """
    Get the single diode parameters at a given condition
    """
    m = model.solver
    Tc_ref = pyo.value(m.Tref)
    a = pyo.value(m.par.a)
    Io = pyo.value(m.par.Io)
    eg0 = pyo.value(m.Egref)
    Adj = pyo.value(m.par.Adj)
    alpha = pyo.value(m.aIsc)
    Il = pyo.value(m.par.Il)
    Io = pyo.value(m.par.Io)
    Rs = pyo.value(m.par.Rs)
    Rsh = pyo.value(m.par.Rsh)

    I_ref = 1000
    muIsc = alpha * (1-Adj/100)
    
    A_oper = a * T_cell_K / Tc_ref
    EG = eg0 * (1-0.0002677*(T_cell_K-Tc_ref))
    # instead of 1/KB, is 11600 in L129
    IO_oper = Io * np.power(T_cell_K/Tc_ref, 3) * np.exp( 11600 *(eg0/Tc_ref - EG/T_cell_K) )
    
    Rsh_oper = Rsh*(I_ref/Irr)
    IL_oper = Irr/I_ref *( Il + muIsc*(T_cell_K-Tc_ref) )
    if IL_oper < 0.0:
        IL_oper = 0.0
    
    return IL_oper, IO_oper, Rs, A_oper, Rsh_oper


def cec_model_ivcurve(model, Irr, T_cell_K, vmax, npts):
    """
    Calculate the IV curve with voltage on x-axis and current on y-axis at the given irradiance and temperature
    """
    I_mp_ref = pyo.value(model.solver.Imp)
    IL_oper, IO_oper, Rs, A_oper, Rsh_oper = cec_model_params_at_condition(model, Irr, T_cell_K)

    y_I = []

    V = np.linspace(0, vmax, npts)
    for i, v in enumerate(V):
        I = current_at_voltage_cec( v, IL_oper, IO_oper, Rs, A_oper, Rsh_oper, I_mp_ref )	
        y_I.append(I)
    return V, y_I
    
def plot_iv_curve(model, linestyle='solid', label=None, plot_anchors=False):
    """
    Plot IV curves for a range of conditions using a model from `create_model` with all the test and model parameters populated

    Model must have populated data from `test_data_cols` and `model_param_cols`
    """
    curves = [ [ 1000, 25, 'black' ],
               [ 800,  25, 'blue' ],
               [ 600,  25, 'red' ],
               [ 400,  25, 'green' ],
               [ 200,  25, 'orange' ] ]

    curves = [ [ 1000, 2, 'black' ],
               [ 1000,  25, 'red' ],
               [ 1000,  47, 'orange' ],
               [ 800,  0, 'blue' ],
               [ 400,  0, 'green' ],
               ]
        
    vmax = pyo.value(model.solver.Voc)
    alpha_sc = pyo.value(model.solver.aIsc)
    I_sc_ref = pyo.value(model.solver.Isc)
    beta_oc = pyo.value(model.solver.bVoc)
    V_oc_ref = pyo.value(model.solver.Voc)
    gamma_r = pyo.value(model.solver.gPmp)
    V_mp_ref = pyo.value(model.solver.Vmp)
    I_mp_ref = pyo.value(model.solver.Imp)

    npts = 150
    for curve in curves:
        Irr = curve[0]
        Tc = curve[1]

        V_oc = beta_oc * (Tc - 25) + V_oc_ref
        x_V, y_I = cec_model_ivcurve(model, Irr, Tc + 273.15, V_oc, npts)
        plt.plot(x_V, y_I, label=f"{label} {Irr} W/m^2 {Tc} C", color=curve[2], linestyle=linestyle)

        if plot_anchors and Irr == 1000:
            I_sc = alpha_sc * (Tc - 25) + I_sc_ref
            plt.plot(0, I_sc, marker="o", markersize=10, alpha=0.5, color=curve[2])
            plt.plot(V_oc, 0, marker="v", markersize=10, alpha=0.5, color=curve[2])
            
            P_mp = (gamma_r * (Tc - 25) * 1e-2 + 1) * (V_mp_ref * I_mp_ref)
            mp_ind = np.argmax(x_V * y_I)
            if Tc == 25:
                I_mp = I_mp_ref
                V_mp = V_mp_ref
            else:
                I_mp = y_I[mp_ind]
                V_mp = P_mp / I_mp
            plt.plot(V_mp, I_mp, marker="*", markersize=10, alpha=0.5, color=curve[2])


def create_model(gamma_curve_dt=3):
    """
    Create a pyomo model for a single diode model with a set of non-STC temperatures.
    The set of non-STC temperatures are used to fit the model to the gamma Pmp test parameter
    This set of temperatures is sampled using the `gamma_curve_dt` parameter, which is the interval between each temperature sample
    """
    model = pyo.ConcreteModel()
    model.solver = pyo.Block()
    m = model.solver

    m.Vmp = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
    m.Imp = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
    m.Voc = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
    m.Isc = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
    m.aIsc = pyo.Param(domain=pyo.Reals, mutable=True, units=pyo.units.A/pyo.units.K)
    m.bVoc = pyo.Param(domain=pyo.Reals, mutable=True, units=pyo.units.V/pyo.units.K)
    m.gPmp = pyo.Param(domain=pyo.Reals, mutable=True, units=pyo.units.percent/pyo.units.K)
    m.Egref = pyo.Param(domain=pyo.NonNegativeReals, mutable=True, initialize=1.121)
    m.Tref = pyo.Param(domain=pyo.NonNegativeReals, mutable=True, units=pyo.units.K)

    # Module6ParNonlinear
    m.par = pyo.Block()
    m.par.a = pyo.Var(domain=pyo.NonNegativeReals, bounds=(0.05, 15), initialize=7.75)
    m.par.Il = pyo.Var(domain=pyo.NonNegativeReals, bounds=(0.01, 20), initialize=10.25)
    m.par.Io = pyo.Var(domain=pyo.NonNegativeReals, bounds=(1e-13, 1e-7), initialize=5e-8) # might need to scale
    m.par.Rs = pyo.Var(domain=pyo.NonNegativeReals, bounds=(0.001, 75), initialize=32.5)
    m.par.Rsh = pyo.Var(domain=pyo.NonNegativeReals, bounds=(1, 1e6), initialize=5e5)
    m.par.Adj = pyo.Var(domain=pyo.Reals, bounds=(-100, 100), initialize=1)

    m.par.f0 = pyo.Constraint(expr=m.par.Il - m.par.Io*( pyo.exp( m.Isc*m.par.Rs / m.par.a ) - 1 ) - m.Isc*m.par.Rs/m.par.Rsh - m.Isc == 0)
    m.par.f1 = pyo.Constraint(expr=m.par.Io*( pyo.exp( m.Voc/m.par.a ) - 1 ) + m.Voc/m.par.Rsh -m.par.Il == 0)
    m.par.f2 = pyo.Constraint(expr=m.par.Il - m.par.Io*( pyo.exp( (m.Vmp + m.Imp*m.par.Rs) / m.par.a ) - 1 ) - (m.Vmp + m.Imp*m.par.Rs)/m.par.Rsh - m.Imp == 0)
    m.par.f3 = pyo.Constraint(expr=m.Imp - m.Vmp*(
        ( m.par.Io/m.par.a*pyo.exp( (m.Vmp + m.Imp*m.par.Rs)/m.par.a ) + 1/m.par.Rsh )
        /( 1 + m.par.Io*m.par.Rs/m.par.a*pyo.exp( (m.Vmp + m.Imp*m.par.Rs)/m.par.a ) + m.par.Rs/m.par.Rsh ) ) == 0)

    m.par.dT = pyo.Param(initialize=5)

    m.par.aT = pyo.Expression(expr=m.par.a*(m.Tref+m.par.dT)/m.Tref)
    m.par.VocT = pyo.Expression(expr=m.bVoc*(1+m.par.Adj/100.0)*m.par.dT + m.Voc)
    m.par.Eg = pyo.Expression(expr=(1-0.0002677*m.par.dT)*m.Egref)
    m.par.IoT = pyo.Expression(expr=m.par.Io*( (m.Tref+m.par.dT)/m.Tref )**3 *pyo.exp( 11600 * (m.Egref/m.Tref - m.par.Eg/(m.Tref+m.par.dT))))
    m.par.f4 = pyo.Constraint(expr=m.par.Il+m.aIsc*(1-m.par.Adj/100)*m.par.dT - m.par.IoT*(pyo.exp( m.par.VocT/m.par.aT ) - 1 ) - m.par.VocT/m.par.Rsh == 0)

    # mod6par_gamma_approx
    temperatures = np.arange(-10 + 273.15, 50 + 273.15, gamma_curve_dt)
    def gamma_expr(b, t):
        return (b.pt[t].Pmp_Tc-b.pt[t-1].Pmp_Tc)*100/(m.Vmp*m.Imp*(b.pt[t].Tc-b.pt[t-1].Tc))

    def gamma_blocks(b, i):
        b.Tc = pyo.Param(initialize=temperatures[i - 1])
        b.Vmp_Tc = pyo.Var(domain=pyo.NonNegativeReals)
        b.Imp_Tc = pyo.Var(domain=pyo.NonNegativeReals)

        # PTnonlinear
        b.a_Tc = pyo.Expression(expr=m.par.a * b.Tc / m.Tref)
        b.Eg_Tc = pyo.Expression(expr=m.Egref * (1-0.0002677*(b.Tc-m.Tref)))
        b.Io_Tc = pyo.Expression(expr=m.par.Io* ( b.Tc/m.Tref)**3 * pyo.exp( 11600 * (m.Egref/m.Tref - b.Eg_Tc/b.Tc)))
        b.Il_Tc = pyo.Expression(expr=m.par.Il + (m.aIsc*(1-m.par.Adj/100))*(b.Tc-m.Tref))
        b.f_5 = pyo.Constraint(expr=b.Vmp_Tc *( b.Io_Tc/b.a_Tc*pyo.exp( (b.Vmp_Tc+b.Imp_Tc*m.par.Rs)/b.a_Tc ) + 1/m.par.Rsh ) 
                            / ( 1 + m.par.Rs/m.par.Rsh + b.Io_Tc*m.par.Rs/b.a_Tc*pyo.exp( (b.Vmp_Tc+b.Imp_Tc*m.par.Rs)/b.a_Tc ) ) - b.Imp_Tc == 0)
        b.f_6 = pyo.Constraint(expr=b.Il_Tc - b.Io_Tc*(pyo.exp( (b.Vmp_Tc+b.Imp_Tc*m.par.Rs)/b.a_Tc ) - 1) - (b.Vmp_Tc + b.Imp_Tc*m.par.Rs)/m.par.Rsh - b.Imp_Tc == 0)
        b.Pmp_Tc = pyo.Expression(expr=b.Vmp_Tc * b.Imp_Tc)

    nTc = len(temperatures)
    m.gamma = pyo.Block()
    g = m.gamma
    g.i = pyo.RangeSet(nTc)
    g.d_i = pyo.RangeSet(2, nTc)
    g.pt = pyo.Block(g.i, rule=gamma_blocks)

    g.gamma_Tc = pyo.Expression(g.d_i, rule=gamma_expr)
    g.gamma_avg = pyo.Expression(expr=pyo.summation(g.gamma_Tc) / len(g.d_i))

    g.f_7 = pyo.Constraint(expr=(g.gamma_avg - m.gPmp) == 0)

    # Sanity checks on current
    model.sanity = pyo.Block()
    s = model.sanity

    s.Imp_calc = pyo.Var(domain=pyo.NonNegativeReals)
    s.f_8 = pyo.Constraint(expr=m.par.Il - s.Imp_calc - m.par.Io * (pyo.exp((m.Vmp + s.Imp_calc * m.par.Rs) / m.par.a) - 1.0) - (m.Vmp + s.Imp_calc * m.par.Rs) / m.par.Rsh == 0)

    s.Ioc_calc = pyo.Var(domain=pyo.NonNegativeReals, initialize=0)
    s.f_9 = pyo.Constraint(expr=m.par.Il - s.Ioc_calc - m.par.Io * (pyo.exp((m.Voc + s.Ioc_calc * m.par.Rs) / m.par.a) - 1.0) - (m.Voc + s.Ioc_calc * m.par.Rs) / m.par.Rsh == 0)

    # Sanity checks on max_slope
    # v_range = np.linspace(0.015 * m.Voc.value, 0.98 * m.Voc.value, 100)
    model.slope = pyo.Block()
    
    # examine solved modules
    model.scaling_factor = pyo.Suffix(direction=pyo.Suffix.EXPORT)
    return model


def solve_model(model, solver, tee=False):
    """
    Solve the model with scaling factors, multiple tries and separating steps

    Solution may not be optimal! Solutions may have slight infeasibility. 
    Caller needs to check whether it is above an acceptable threshold using the log functions by setting tee=True,
    or after the function, using `get_constraint_infeas` or `get_curve_diffs`.
    """
    model.scaling_factor[model.solver.par.Io] = IL_SCALING
    model.scaling_factor[model.solver.par.Rsh] = RSH_SCALING
    
    scaled_model = pyo.TransformationFactory('core.scale_model').create_using(model)

    scaled_model.obj_zero = pyo.Objective(rule=0)
    res = None
    try:
        res = solver.solve(scaled_model, tee=tee)
    except Exception as e:
        if tee:
            log_infeasible_bounds(scaled_model, logger=solve_log, tol=1e-7)
            log_infeasible_constraints(scaled_model, logger=solve_log, tol=1e-7)
        if res:
            pyo.TransformationFactory('core.scale_model').propagate_solution(scaled_model, model)
            return res, scaled_model
        else:
            return None, scaled_model

    if res.solver.status != "ok":
        try:
            res = solver.solve(scaled_model, tee=tee)
        except:
            return None, scaled_model

        if res.solver.status != "ok":
            scaled_model.solver.gamma.deactivate()
            try:
                res = solver.solve(scaled_model, tee=tee)
            except:
                return None, scaled_model

            scaled_model.solver.gamma.activate()
            if res.solver.status != "ok":
                if tee:
                    log_infeasible_bounds(scaled_model, logger=solve_log, tol=1e-7)
                    log_infeasible_constraints(scaled_model, logger=solve_log, tol=1e-7)
                if res:
                    pyo.TransformationFactory('core.scale_model').propagate_solution(scaled_model, model)
                    return res, scaled_model
                else:
                    return None, scaled_model

    if res is None or res.solver.status != 'ok':
        res = None
        try:
            res = solver.solve(scaled_model, tee=tee)
        except Exception as e:
            solver.options["tol"] = 1e-5
            try:
                res = solver.solve(scaled_model, tee=tee)
            except:
                return None, scaled_model

            solver.options["tol"] = 1e-9

            if tee:
                log_infeasible_bounds(scaled_model, logger=solve_log, tol=1e-7)
                log_infeasible_constraints(scaled_model, logger=solve_log, tol=1e-7)

        if res.solver.status != "ok":
            if tee:
                log_infeasible_bounds(scaled_model, logger=solve_log, tol=1e-7)
                log_infeasible_constraints(scaled_model, logger=solve_log, tol=1e-7)
            if res:
                pyo.TransformationFactory('core.scale_model').propagate_solution(scaled_model, model)
                return res, scaled_model
            else:
                return None, scaled_model

    pyo.TransformationFactory('core.scale_model').propagate_solution(scaled_model, model)
    return res, scaled_model


def get_iterations(log_file):
    """
    Get the number of IPOPT iterations from the log file
    """
    with open(log_file, 'r') as f:
        for line in f:
            if "Number of Iterations....:" in line:
                it = line.split(": ")[1]
                it_n = int(it)
                return it_n


def get_constraint_infeas(model):
    """
    Get the magnitude of infeasibility for each constraint in the pyomo model. Model can be the original or the scaled version
    """
    if hasattr(model.solver.par, 'f0'):
        vals = (pyo.value(model.solver.par.f0), pyo.value(model.solver.par.f1), pyo.value(model.solver.par.f2), pyo.value(model.solver.par.f3), pyo.value(model.solver.par.f4), pyo.value(model.solver.gamma.f_7))
    else:
        if hasattr(model.solver.gamma, 'f_7'):
            vals = (pyo.value(model.solver.par.scaled_f0), pyo.value(model.solver.par.scaled_f1), pyo.value(model.solver.par.scaled_f2), pyo.value(model.solver.par.scaled_f3), pyo.value(model.solver.par.scaled_f4), pyo.value(model.solver.gamma.f_7))
        else:
            vals = (pyo.value(model.solver.par.scaled_f0), pyo.value(model.solver.par.scaled_f1), pyo.value(model.solver.par.scaled_f2), pyo.value(model.solver.par.scaled_f3), pyo.value(model.solver.par.scaled_f4))
    return [abs(v) for v in vals]


def solve_model_best_solution(model, solver, tee=False):
    """
    Solve the model and return the best solution regardless of regardless of whether IPOPT has converged or exited gracefully

    Solution may not be optimal! Solutions may have a lot of infeasibility. 
    Caller needs to check whether it is above an acceptable threshold using the log functions by setting tee=True,
    or after the function, using `get_constraint_infeas` or `get_curve_diffs`.
    """
    try:
        il_scaling = 10**min(12, -int(np.log10(pyo.value(model.solver.par.Io))))
        rsh_scaling = 10**min(5, -int(np.log10(pyo.value(model.solver.par.Rsh))))
    except:
        il_scaling = IL_SCALING
        rsh_scaling = RSH_SCALING
    model.scaling_factor[model.solver.par.Io] = il_scaling
    model.scaling_factor[model.solver.par.Rsh] = rsh_scaling
    
    scaled_model = pyo.TransformationFactory('core.scale_model').create_using(model)

    if hasattr(scaled_model.solver, "f_0"):
        scaled_model.obj_gamma = pyo.Objective(rule=scaled_model.solver.gamma.f_7 ** 0.5 + scaled_model.solver.f_0 ** 0.5)
    elif hasattr(scaled_model.solver.gamma, "f_7"):
        scaled_model.obj_gamma = pyo.Objective(rule=scaled_model.solver.gamma.f_7 ** 0.5)

    scaled_model.sanity.scaled_f_9.deactivate()
    
    res = None
    try:
        res = solver.solve(scaled_model, tee=tee, logfile='ipopt_output.log')
    except Exception as e:
        pass

    if res is not None and res.solver.status == "ok":
        pyo.TransformationFactory('core.scale_model').propagate_solution(scaled_model, model)
        return res, scaled_model

    it_n = get_iterations('ipopt_output.log')

    solver.options['max_iter'] = it_n - 1             

    try:
        res = solver.solve(scaled_model, tee=tee, logfile='ipopt_output.log')
    except:
        pass

    while 'infeasible' in res.solver.message:
        it_n = get_iterations('ipopt_output.log')
        solver.options['max_iter'] = it_n - 1     
        res = solver.solve(scaled_model, tee=tee, logfile='ipopt_output.log')

    pyo.TransformationFactory('core.scale_model').propagate_solution(scaled_model, model)

    # get somewhat stable params
    infeas = sum(get_constraint_infeas(model))
    attempts = 0
    while infeas > 10 and attempts < 10:
        res = solver.solve(scaled_model, tee=tee, logfile='ipopt_output.log')
        infeas = sum(get_constraint_infeas(scaled_model))
        pyo.TransformationFactory('core.scale_model').propagate_solution(scaled_model, model)
        attempts += 1

    return res, scaled_model


def set_parameters(m, r: pd.Series):
    """
    Set the test data parameters for the model.solver block from a pandas Series
    """
    try:
        m.Vmp.set_value(r['V_mp_ref'])
        m.Imp.set_value(r['I_mp_ref'])
        m.Voc.set_value(r['V_oc_ref'])
        m.Isc.set_value(r['I_sc_ref'])
        m.aIsc.set_value(r['alpha_sc'])
        m.bVoc.set_value(r['beta_oc'])
        m.gPmp.set_value(r['gamma_r'])
        m.Tref.set_value(25 + 273.15)
        return True
    except:
        return False

def set_initial_guess(model, a, Il, Io, Rs, Rsh, Adj):
    """
    Set the model parameters from a guess
    """
    m = model.solver
    m.par.a.set_value(a)
    m.par.Il.set_value(Il)
    m.par.Io.set_value(Io)
    m.par.Rs.set_value(Rs)
    m.par.Rsh.set_value(Rsh)
    m.par.Adj.set_value(Adj)
    model.sanity.Imp_calc.set_value(pyo.value(m.Imp))

# intercept, coefficients
Voc_Vmp_to_a = [0.22328699, 0.03106774, 0.00738466]
Isc_Imp_to_Il = [0.0153132, 0.96058469, 0.04133798]
Isc_Imp_Voc_Vmp_to_Rs = [0.28969838, 0.61785177, -0.6759943, 0.02241771, 0.0218622]

def set_empirical_initial_guess(model):
    """
    Set the model parameters from an empirical equation based on previously-solved modules
    """
    m = model.solver

    Vmp = pyo.value(m.Vmp)
    Imp = pyo.value(m.Imp)
    Voc = pyo.value(m.Voc)
    Isc = pyo.value(m.Isc)
    aIsc = pyo.value(m.aIsc)
    bVoc = pyo.value(m.bVoc)
    gPmp = pyo.value(m.gPmp)

    a = Voc_Vmp_to_a[0] + Voc_Vmp_to_a[1] * Voc + Voc_Vmp_to_a[2] * Vmp
    Il = Isc_Imp_to_Il[0] + Isc_Imp_to_Il[1] * Isc + Isc_Imp_to_Il[2] * Imp
    Rs = Isc_Imp_Voc_Vmp_to_Rs[0] + Isc_Imp_Voc_Vmp_to_Rs[1] * Isc + Isc_Imp_Voc_Vmp_to_Rs[2] * Imp \
        + Isc_Imp_Voc_Vmp_to_Rs[3] * Voc + Isc_Imp_Voc_Vmp_to_Rs[4] * Vmp
    
    m.par.a.set_value(a)
    m.par.Il.set_value(Il)
    m.par.Rs.set_value(Rs)


def find_closest(df_solved: pd.DataFrame, r: pd.Series):
    """
    Given a dataframe of solved modules, find the module that is closest to the one in row r and return the parameters
    """
    diff = (
            (df_solved['V_mp_ref'] - r['V_mp_ref']) ** 2 + 
            (df_solved['I_mp_ref'] - r['I_mp_ref']) ** 2 + 
            (df_solved['V_oc_ref'] - r['V_oc_ref']) ** 2 + 
            (df_solved['I_sc_ref'] - r['I_sc_ref']) ** 2 +
            (df_solved['alpha_sc'] - r['alpha_sc']) ** 2 + 
            (df_solved['beta_oc'] - r['beta_oc']) ** 2 +
            (df_solved['gamma_r'] - r['gamma_r']) ** 2)
        
    params_closest = df_solved.iloc[diff.argmin()]
    return params_closest


def get_params_from_model(model):
    """
    Extract the model parameters from the pyomo model
    """
    if hasattr(model.solver.par, 'scaled_a'):
        a = pyo.value(model.solver.par.scaled_a)
        Il = pyo.value(model.solver.par.scaled_Il)
        Io = pyo.value(model.solver.par.scaled_Io / IL_SCALING)
        Rs = pyo.value(model.solver.par.scaled_Rs)
        Rsh = pyo.value(model.solver.par.scaled_Rsh / RSH_SCALING)
        Adj = pyo.value(model.solver.par.scaled_Adj)
    else:
        a = pyo.value(model.solver.par.a)
        Il = pyo.value(model.solver.par.Il)
        Io = pyo.value(model.solver.par.Io)
        Rs = pyo.value(model.solver.par.Rs)
        Rsh = pyo.value(model.solver.par.Rsh)
        Adj = pyo.value(model.solver.par.Adj)
    return a, Il, Io, Rs, Rsh, Adj


def get_curve_diffs(r, model):
    """
    Calculate the normalized difference in I_sc, I_mp, V_mp and P_mp at 1000 irradiance and 25 C
    """
    x_V, y_I = cec_model_ivcurve(model, 1000, 25 + 273.15, r['V_oc_ref'], 150)
    p = x_V * y_I
    mp_ind = np.argmax(p)
    d_I_sc = (y_I[0] - r['I_sc_ref']) / r['I_sc_ref']
    d_I_mp = (y_I[mp_ind] - r['I_mp_ref']) / r['I_mp_ref']
    d_V_mp = (x_V[mp_ind] - r['V_mp_ref']) / r['V_mp_ref']
    d_P_mp = (p[mp_ind] - r['V_mp_ref'] * r['I_mp_ref']) / (r['V_mp_ref'] * r['I_mp_ref'])
    return d_I_sc, d_I_mp, d_V_mp, d_P_mp


def read_prepare_file(xlsx_file):
    """
    Read the CEC Module Excel Spreadsheet and prepare the file
    """
    all_cec_modules_df = pd.read_excel(xlsx_file, skiprows=list(range(0, 16)) + [17])
    all_cec_modules_df = all_cec_modules_df.drop(columns=["Description", 'Safety Certification',
       'Nameplate Pmax', 'Notes',
       'Design Qualification Certification\n(Optional Submission)',
       'Performance Evaluation (Optional Submission)', 'Family', 
       'N_p',  'αIpmax', 'βVpmax', 'IPmax, low', 'VPmax, low', 'IPmax, NOCT',
       'VPmax, NOCT', 'Mounting', 'Type', 'Short Side', 'Long Side',
       'Geometric Multiplier', 'P2/Pref', 'CEC Listing Date', 'Last Update'])
    all_cec_modules_df = all_cec_modules_df.rename(columns={
        'Nameplate Isc': "I_sc_ref", 'Nameplate Voc': "V_oc_ref",
       'Nameplate Ipmax': "I_mp_ref", 'Nameplate Vpmax': "V_mp_ref", 'Average NOCT': "T_NOCT", 
       'γPmax': "gamma_r", 'αIsc': "alpha_sc",
       'βVoc': "beta_oc",
    })
    all_cec_modules_df[test_data_cols] = all_cec_modules_df[test_data_cols].astype(float)
    all_cec_modules_df['alpha_sc'] *= all_cec_modules_df['I_sc_ref'] * 1e-2
    all_cec_modules_df['beta_oc'] *= all_cec_modules_df['V_oc_ref'] * 1e-2
    all_cec_modules_df = all_cec_modules_df.drop_duplicates()
    
    for col in model_param_cols:
        all_cec_modules_df[col] = None
    return all_cec_modules_df


def run_solve_first_pass(all_cec_modules_df):
    """
    Solve for all the modules in the DataFrame, using the empirical initial guess
    """
    solver = pyo.SolverFactory('ipopt')

    for i, r in all_cec_modules_df.iterrows():
        if r['V_mp_ref'] < 0:
            all_cec_modules_df.loc[i, 'Error'] = "Vmp < 0"
            continue
        if r['V_oc_ref'] < r['V_mp_ref']:
            all_cec_modules_df.loc[i, 'Error'] = "Voc < Vmp"
            continue

        model = create_model(gamma_curve_dt=3)
        if not set_parameters(model.solver, r):
            all_cec_modules_df.loc[i, 'Error'] = f"Parameter missing or out of bounds for row {i}"
            continue

        if plotting:
            plt.figure()
        solver.options["max_iter"] = 3000

        set_empirical_initial_guess(model)

        res, scaled_model = solve_model(model, solver, tee=False)
        
        if plotting:
            if res and res.solver.status == 'ok':
                plot_iv_curve(model, linestyle='-', label="Optimal", plot_anchors=True)
            else:
                plot_iv_curve(model, linestyle='dotted', label="Approx", plot_anchors=True)

        d_I_sc, d_I_mp, d_V_mp, d_P_mp = get_curve_diffs(r, model)

        infeas_sum = np.abs([d_I_sc, d_I_mp, d_V_mp, d_P_mp]).sum()
        infeas_max = np.abs([d_I_sc, d_I_mp, d_V_mp, d_P_mp]).max()

        if infeas_max > 0.5 or infeas_sum > 0.5:
            all_cec_modules_df.loc[i, 'Error'] = "Infeasibility > 0.5"
            if plotting:
                plt.close()
            continue

        a, Il, Io, Rs, Rsh, Adj = get_params_from_model(scaled_model)
        all_cec_modules_df.loc[i, iv_diff_cols] = [d_I_sc, d_I_mp, d_V_mp, d_P_mp]
        all_cec_modules_df.loc[i, model_param_cols] = [a, Il, Io, Rs, Rsh, Adj]

        if plotting:
            plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
            plt.xlabel("Voltage")
            plt.ylabel("Current")
            plt.title(f"{r['Manufacturer']} {r['Model Number']}")
            plt.tight_layout()
            plt.savefig(plot_output_path / f"IV_curve_{i}.png")
            plt.close()
    return all_cec_modules_df


def run_solve_bootstrapping(all_cec_modules_df, solved_df, unsolved_df):
    """
    Solve for all the modules in the DataFrame, using the `find_closest` to provide the initial guess
    """
    solver = pyo.SolverFactory('ipopt')

    for i, r in unsolved_df.iterrows():
        if r['V_mp_ref'] < 0:
            all_cec_modules_df.loc[i, 'Error'] = "Vmp < 0"
            continue
        if r['V_oc_ref'] < r['V_mp_ref']:
            all_cec_modules_df.loc[i, 'Error'] = "Voc < Vmp"
            continue

        model = create_model(gamma_curve_dt=3)
        if not set_parameters(model.solver, r):
            all_cec_modules_df.loc[i, 'Error'] = f"Parameter missing or out of bounds for row {i}"
            continue

        if plotting:
            plt.figure()
        solver.options["max_iter"] = 3000

        cec_closest = find_closest(solved_df, r)
        set_initial_guess(model, *cec_closest[model_param_cols])
        if plotting:
            plot_iv_curve(model, linestyle=(0, (1, 10)), label="Closest Guess")

        res, scaled_model = solve_model(model, solver, tee=False)
        
        if plotting:
            if res and res.solver.status == 'ok':
                plot_iv_curve(model, linestyle='-', label="Optimal", plot_anchors=True)
            else:
                plot_iv_curve(model, linestyle='dotted', label="Approx", plot_anchors=True)

        d_I_sc, d_I_mp, d_V_mp, d_P_mp = get_curve_diffs(r, model)

        infeas_sum = np.abs([d_I_sc, d_I_mp, d_V_mp, d_P_mp]).sum()
        infeas_max = np.abs([d_I_sc, d_I_mp, d_V_mp, d_P_mp]).max()

        if infeas_max > 0.5 or infeas_sum > 0.5:
            all_cec_modules_df.loc[i, 'Error'] = "Infeasibility > 0.5"
            if plotting:
                plt.close()
            continue

        a, Il, Io, Rs, Rsh, Adj = get_params_from_model(scaled_model)
        all_cec_modules_df.loc[i, iv_diff_cols] = [d_I_sc, d_I_mp, d_V_mp, d_P_mp]
        all_cec_modules_df.loc[i, model_param_cols] = [a, Il, Io, Rs, Rsh, Adj]
        all_cec_modules_df.loc[i, 'Error'] = None

        if plotting:
            plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
            plt.xlabel("Voltage")
            plt.ylabel("Current")
            plt.title(f"{r['Manufacturer']} {r['Model Number']}")
            plt.tight_layout()
            plt.savefig(plot_output_path / f"IV_curve_{i}.png")
            plt.close()
    return all_cec_modules_df


def run_solve_bootstrapping_reduced(all_cec_modules_df, solved_df, unsolved_df):
    """
    Solve for all the modules in the DataFrame, using the closest initial guess and reducing the number of temperature samples to fit gamma
    """
    solver = pyo.SolverFactory('ipopt')

    for i, r in unsolved_df.iterrows():
        if r['V_mp_ref'] < 0:
            all_cec_modules_df.loc[i, 'Error'] = "Vmp < 0"
            continue
        if r['V_oc_ref'] < r['V_mp_ref']:
            all_cec_modules_df.loc[i, 'Error'] = "Voc < Vmp"
            continue

        model = create_model(gamma_curve_dt=15)
        if not set_parameters(model.solver, r):
            all_cec_modules_df.loc[i, 'Error'] = f"Parameter missing or out of bounds for row {i}"
            continue

        if plotting:
            plt.figure()
        solver.options["max_iter"] = 3000

        cec_closest = find_closest(solved_df, r)
        set_initial_guess(model, *cec_closest[model_param_cols])
        if plotting:
            plot_iv_curve(model, linestyle=(0, (1, 10)), label="Closest Guess")

        res, scaled_model = solve_model(model, solver, tee=False)
        
        if plotting:
            if res and res.solver.status == 'ok':
                plot_iv_curve(model, linestyle='-', label="Optimal", plot_anchors=True)
            else:
                plot_iv_curve(model, linestyle='dotted', label="Approx", plot_anchors=True)

        d_I_sc, d_I_mp, d_V_mp, d_P_mp = get_curve_diffs(r, model)

        infeas_sum = np.abs([d_I_sc, d_I_mp, d_V_mp, d_P_mp]).sum()
        infeas_max = np.abs([d_I_sc, d_I_mp, d_V_mp, d_P_mp]).max()

        if infeas_max > 0.5 or infeas_sum > 0.5:
            all_cec_modules_df.loc[i, 'Error'] = "Infeasibility > 0.5"
            if plotting:
                plt.close()
            continue

        a, Il, Io, Rs, Rsh, Adj = get_params_from_model(scaled_model)
        all_cec_modules_df.loc[i, iv_diff_cols] = [d_I_sc, d_I_mp, d_V_mp, d_P_mp]
        all_cec_modules_df.loc[i, model_param_cols] = [a, Il, Io, Rs, Rsh, Adj]
        all_cec_modules_df.loc[i, 'Error'] = None

        if plotting:
            plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
            plt.xlabel("Voltage")
            plt.ylabel("Current")
            plt.title(f"{r['Manufacturer']} {r['Model Number']}")
            plt.tight_layout()
            plt.savefig(plot_output_path / f"IV_curve_{i}.png")
            plt.close()
    return all_cec_modules_df


def solve_bootstrapping_reduced_approx(all_cec_modules_df, solved_df, unsolved_df):
    """
    Solve for all the modules in the DataFrame, using the closest initial guess, reducing the number of temperature samples to fit gamma,
    and using `solve_model_best_solution`

    Not recommended to use this function unless an approximate solution is desperately needed. 
    Accuracy of IV curve to test data should be examined visually. This can be done with `create_model_with_solution` and `plot_iv_curve`
    """
    solver = pyo.SolverFactory('ipopt')

    for i, r in unsolved_df.iterrows():
        if r['V_mp_ref'] < 0:
            all_cec_modules_df.loc[i, 'Error'] = "Vmp < 0"
            continue
        if r['V_oc_ref'] < r['V_mp_ref']:
            all_cec_modules_df.loc[i, 'Error'] = "Voc < Vmp"
            continue

        model = create_model(gamma_curve_dt=15)
        if not set_parameters(model.solver, r):
            all_cec_modules_df.loc[i, 'Error'] = f"Parameter missing or out of bounds for row {i}"
            continue

        if plotting:
            plt.figure()
        solver.options["max_iter"] = 3000

        cec_closest = find_closest(solved_df, r)
        set_initial_guess(model, *cec_closest[model_param_cols])
        if plotting:
            plot_iv_curve(model, linestyle=(0, (1, 10)), label="Closest Guess")

        res, scaled_model = solve_model_best_solution(model, solver, tee=False)
        
        if plotting:
            if res and res.solver.status == 'ok':
                plot_iv_curve(model, linestyle='-', label="Optimal", plot_anchors=True)
            else:
                plot_iv_curve(model, linestyle='dotted', label="Approx", plot_anchors=True)

        d_I_sc, d_I_mp, d_V_mp, d_P_mp = get_curve_diffs(r, model)

        infeas_sum = np.abs([d_I_sc, d_I_mp, d_V_mp, d_P_mp]).sum()
        infeas_max = np.abs([d_I_sc, d_I_mp, d_V_mp, d_P_mp]).max()

        if infeas_max > 0.5 or infeas_sum > 0.5:
            all_cec_modules_df.loc[i, 'Error'] = "Infeasibility > 0.5"
            if plotting:
                plt.close()
            continue

        a, Il, Io, Rs, Rsh, Adj = get_params_from_model(scaled_model)
        all_cec_modules_df.loc[i, iv_diff_cols] = [d_I_sc, d_I_mp, d_V_mp, d_P_mp]
        all_cec_modules_df.loc[i, model_param_cols] = [a, Il, Io, Rs, Rsh, Adj]
        all_cec_modules_df.loc[i, 'Error'] = None

        if plotting:
            plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
            plt.xlabel("Voltage")
            plt.ylabel("Current")
            plt.title(f"{r['Manufacturer']} {r['Model Number']}")
            plt.tight_layout()
            plt.savefig(plot_output_path / f"IV_curve_{i}.png")
            plt.close()
    return all_cec_modules_df


def create_model_with_solution(sol_row):
    """
    Create a model with the parameters from the tests and for the single-diode model. Can then be used for `plot_iv_curve`
    
    sol_row must contain columns from `test_data_cols` and `model_param_cols`
    """
    model = create_model(gamma_curve_dt=3)
    if type(sol_row) == pd.Series:
        if not set_parameters(model.solver, sol_row):
            raise RuntimeError("Test data parameters could not be set")
        set_initial_guess(model, *sol_row[model_param_cols])
    elif type(sol_row) == pd.DataFrame:
        if not set_parameters(model.solver, sol_row.to_dict('records')[0]):
            raise RuntimeError("Test data parameters could not be set")
        set_initial_guess(model, *sol_row[model_param_cols].values[0])
    return model


if __name__ == "__main__":
    filename = None

    if len(sys.argv) > 1:
        filename = Path(sys.argv[1])

    if not filename.exists():
        raise RuntimeError(f"CEC Module Excel Spreadsheet file path does not exist. {filename}")
    
    filename_date = filename.stem.split("-")
    filename_date = f"{filename_date[-3]}-{filename_date[-2]}-{filename_date[-1]}"
    all_cec_modules_df = read_prepare_file(filename)

    plotting = False

    if plotting:
        plot_output_path = Path(__file__).parent / "6parsolve_output"
        if not (plot_output_path).exists():
            os.mkdir(plot_output_path)

    print(f"{datetime.now().strftime('%Y-%m-%d %H:%M:%S')}: Solving for {len(all_cec_modules_df)} Modules")

    # solve attempt #1
    print("Starting First Pass Solve")
    all_cec_modules_df = run_solve_first_pass(all_cec_modules_df)
    all_cec_modules_df.to_csv(f"cec_modules_params_{filename_date}.csv", index=False)
    
    solved_df = all_cec_modules_df[~all_cec_modules_df['Rsh_py'].isna()]
    unsolved_df = all_cec_modules_df[all_cec_modules_df['Rsh_py'].isna()]
    print(f"{datetime.now().strftime('%Y-%m-%d %H:%M:%S')}: Solved {len(solved_df)}. {len(unsolved_df)} remaining.")

    # solve with bootstrapping
    print("{datetime.now().strftime('%Y-%m-%d %H:%M:%S')}: Starting Second Pass Solve")
    all_cec_modules_df = run_solve_bootstrapping(all_cec_modules_df, solved_df, unsolved_df)
    all_cec_modules_df.to_csv(f"cec_modules_params_{filename_date}.csv", index=False)

    solved_df = all_cec_modules_df[~all_cec_modules_df['Rsh_py'].isna()]
    unsolved_df = all_cec_modules_df[all_cec_modules_df['Rsh_py'].isna()]
    print(f"{datetime.now().strftime('%Y-%m-%d %H:%M:%S')}: Solved {len(solved_df)}. {len(unsolved_df)} remaining.")

    # solve with bootstrapping & reduced number of temperature samples
    print("{datetime.now().strftime('%Y-%m-%d %H:%M:%S')}: Starting Final Pass Solve")
    all_cec_modules_df = run_solve_bootstrapping_reduced(all_cec_modules_df, solved_df, unsolved_df)
    all_cec_modules_df.to_csv(f"cec_modules_params_{filename_date}.csv", index=False)

    solved_df = all_cec_modules_df[~all_cec_modules_df['Rsh_py'].isna()]
    unsolved_df = all_cec_modules_df[all_cec_modules_df['Rsh_py'].isna()]
    print(f"{datetime.now().strftime('%Y-%m-%d %H:%M:%S')}: Solved {len(solved_df)}. {len(unsolved_df)} unsolved.")
    