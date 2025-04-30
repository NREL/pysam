from pathlib import Path
import os
import pyomo.environ as pyo
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import idaes.logger as idaeslog
from pyomo.util.infeasible import log_infeasible_constraints, log_infeasible_bounds, log_close_to_bounds

solve_log = idaeslog.getInitLogger("infeasibility", idaeslog.INFO, tag="properties")
IL_SCALING = 1e8
RSH_SCALING = 1e-3
param_cols = ["a_py","Il_py","Io_py","Rs_py","Rsh_py","Adj_py"]

# 6par_solve.h L 423
def current_at_voltage_cec(Vmodule, IL_ref, IO_ref, RS, A_ref, RSH_ref, I_mp_ref):
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
    I_mp_ref = pyo.value(model.solver.Imp)
    IL_oper, IO_oper, Rs, A_oper, Rsh_oper = cec_model_params_at_condition(model, Irr, T_cell_K)

    y_I = []

    V = np.linspace(0, vmax, npts)
    for i, v in enumerate(V):
        I = current_at_voltage_cec( v, IL_oper, IO_oper, Rs, A_oper, Rsh_oper, I_mp_ref )	
        y_I.append(I)
    return V, y_I
    
def plot_iv_curve(model, linestyle='solid', label=None, plot_anchors=False):
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

    # if plot_anchors:
        # plt.plot(0, I_sc_ref, marker="o", markersize=15, alpha=0.5)
        # plt.plot(V_oc_ref, 0, marker="v", markersize=15, alpha=0.5)
        # plt.plot(V_mp_ref, I_mp_ref, marker="*", markersize=15, alpha=0.5)

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
            I_mp = y_I[mp_ind]
            V_mp = P_mp / I_mp
            # V_mp = x_V[mp_ind]
            # I_mp = P_mp / V_mp
            plt.plot(V_mp, I_mp, marker="*", markersize=10, alpha=0.5, color=curve[2])


def create_model(gamma_curve_dt=3):
    model = pyo.ConcreteModel()
    model.solver = pyo.Block()
    m = model.solver

    m.Vmp = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
    m.Imp = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
    m.Voc = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
    m.Isc = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
    m.aIsc = pyo.Param(domain=pyo.Reals, mutable=True)
    m.bVoc = pyo.Param(domain=pyo.Reals, mutable=True)
    m.gPmp = pyo.Param(domain=pyo.Reals, mutable=True)
    m.Egref = pyo.Param(domain=pyo.NonNegativeReals, mutable=True, initialize=1.121)
    m.Tref = pyo.Param(domain=pyo.NonNegativeReals, mutable=True, units=pyo.units.K)

    # Module6ParNonlinear
    m.par = pyo.Block()
    m.par.a = pyo.Var(domain=pyo.NonNegativeReals, bounds=(0.05, 15), initialize=7.75)
    m.par.Il = pyo.Var(domain=pyo.NonNegativeReals, bounds=(0.5, 20), initialize=10.25)
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
        return (b.pt[t].Pmax_Tc-b.pt[t-1].Pmax_Tc)*100/(m.Vmp*m.Imp*(b.pt[t].Tc-b.pt[t-1].Tc))

    def gamma_blocks(b, i):
        b.Tc = pyo.Param(initialize=temperatures[i - 1])
        b.V_Tc = pyo.Var(domain=pyo.NonNegativeReals)
        b.I_Tc = pyo.Var(domain=pyo.NonNegativeReals)

        # PTnonlinear
        b.a_Tc = pyo.Expression(expr=m.par.a * b.Tc / m.Tref)
        b.Io_Tc = pyo.Expression(expr=m.par.Io* ( b.Tc/m.Tref)**3 * pyo.exp( 11600 * (m.Egref/m.Tref - m.par.Eg/b.Tc)))
        b.Il_Tc = pyo.Expression(expr=m.par.Il + (m.aIsc*(1-m.par.Adj/100))*(b.Tc-m.Tref))
        b.f_5 = pyo.Constraint(expr=b.V_Tc *( b.Io_Tc/b.a_Tc*pyo.exp( (b.V_Tc+b.I_Tc*m.par.Rs)/b.a_Tc ) + 1/m.par.Rsh ) 
                            / ( 1 + m.par.Rs/m.par.Rsh + b.Io_Tc*m.par.Rs/b.a_Tc*pyo.exp( (b.V_Tc+b.I_Tc*m.par.Rs)/b.a_Tc ) ) - b.I_Tc == 0)
        b.f_6 = pyo.Constraint(expr=b.Il_Tc - b.Io_Tc*(pyo.exp( (b.V_Tc+b.I_Tc*m.par.Rs)/b.a_Tc ) - 1) - (b.V_Tc + b.I_Tc*m.par.Rs)/m.par.Rsh - b.I_Tc == 0)
        b.Pmax_Tc = pyo.Expression(expr=b.V_Tc * b.I_Tc)

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


def create_partly_relaxed_model():
    model = pyo.ConcreteModel()
    model.solver = pyo.Block()
    m = model.solver

    m.Vmp = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
    m.Imp = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
    m.Voc = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
    m.Isc = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
    m.aIsc = pyo.Param(domain=pyo.Reals, mutable=True)
    m.bVoc = pyo.Param(domain=pyo.Reals, mutable=True)
    m.gPmp = pyo.Param(domain=pyo.Reals, mutable=True)
    m.Egref = pyo.Param(domain=pyo.NonNegativeReals, mutable=True, initialize=1.121)
    m.Tref = pyo.Param(domain=pyo.NonNegativeReals, mutable=True, units=pyo.units.K)

    # Module6ParNonlinear
    m.par = pyo.Block()
    m.par.a = pyo.Var(domain=pyo.NonNegativeReals, bounds=(0.05, 15), initialize=7.75)
    m.par.Il = pyo.Var(domain=pyo.NonNegativeReals, bounds=(0.5, 20), initialize=10.25)
    m.par.Io = pyo.Var(domain=pyo.NonNegativeReals, bounds=(1e-13, 1e-7), initialize=5e-8) # might need to scale
    m.par.Rs = pyo.Var(domain=pyo.NonNegativeReals, bounds=(0.001, 75), initialize=32.5)
    m.par.Rsh = pyo.Var(domain=pyo.NonNegativeReals, bounds=(1, 1e6), initialize=5e5)
    m.par.Adj = pyo.Var(domain=pyo.Reals, bounds=(-100, 100), initialize=1)

    m.par.f0 = pyo.Expression(expr=m.par.Il - m.par.Io*( pyo.exp( m.Isc*m.par.Rs / m.par.a ) - 1 ) - m.Isc*m.par.Rs/m.par.Rsh - m.Isc)
    # m.par.f0 = pyo.Constraint(expr=m.par.Il - m.par.Io*( pyo.exp( m.Isc*m.par.Rs / m.par.a ) - 1 ) - m.Isc*m.par.Rs/m.par.Rsh - m.Isc == 0)
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
    temperatures = np.arange(-10 + 273.15, 50 + 273.15, 3)
    def gamma_expr(b, t):
        return (b.pt[t].Pmax_Tc-b.pt[t-1].Pmax_Tc)*100/(m.Vmp*m.Imp*(b.pt[t].Tc-b.pt[t-1].Tc))

    def gamma_blocks(b, i):
        b.Tc = pyo.Param(initialize=temperatures[i - 1])
        b.V_Tc = pyo.Var(domain=pyo.NonNegativeReals)
        b.I_Tc = pyo.Var(domain=pyo.NonNegativeReals)

        # PTnonlinear
        b.a_Tc = pyo.Expression(expr=m.par.a * b.Tc / m.Tref)
        b.Io_Tc = pyo.Expression(expr=m.par.Io* ( b.Tc/m.Tref)**3 * pyo.exp( 11600 * (m.Egref/m.Tref - m.par.Eg/b.Tc)))
        b.Il_Tc = pyo.Expression(expr=m.par.Il + (m.aIsc*(1-m.par.Adj/100))*(b.Tc-m.Tref))
        b.f_5 = pyo.Constraint(expr=b.V_Tc *( b.Io_Tc/b.a_Tc*pyo.exp( (b.V_Tc+b.I_Tc*m.par.Rs)/b.a_Tc ) + 1/m.par.Rsh ) 
                            / ( 1 + m.par.Rs/m.par.Rsh + b.Io_Tc*m.par.Rs/b.a_Tc*pyo.exp( (b.V_Tc+b.I_Tc*m.par.Rs)/b.a_Tc ) ) - b.I_Tc == 0)
        b.f_6 = pyo.Constraint(expr=b.Il_Tc - b.Io_Tc*(pyo.exp( (b.V_Tc+b.I_Tc*m.par.Rs)/b.a_Tc ) - 1) - (b.V_Tc + b.I_Tc*m.par.Rs)/m.par.Rsh - b.I_Tc == 0)
        b.Pmax_Tc = pyo.Expression(expr=b.V_Tc * b.I_Tc)

    nTc = len(temperatures)
    m.gamma = pyo.Block()
    g = m.gamma
    g.i = pyo.RangeSet(nTc)
    g.d_i = pyo.RangeSet(2, nTc)
    g.pt = pyo.Block(g.i, rule=gamma_blocks)

    g.gamma_Tc = pyo.Expression(g.d_i, rule=gamma_expr)
    g.gamma_avg = pyo.Expression(expr=pyo.summation(g.gamma_Tc) / len(g.d_i))

    g.f_7 = pyo.Expression(expr=(g.gamma_avg - m.gPmp) ** 2)
    m.f_0_penalty = pyo.Param(initialize=10, mutable=True)
    m.f_0 = pyo.Expression(expr=m.par.f0 ** 2 * m.f_0_penalty)

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

def create_full_relaxed_model():
    model = pyo.ConcreteModel()
    model.solver = pyo.Block()
    m = model.solver

    m.Vmp = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
    m.Imp = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
    m.Voc = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
    m.Isc = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
    m.aIsc = pyo.Param(domain=pyo.Reals, mutable=True)
    m.bVoc = pyo.Param(domain=pyo.Reals, mutable=True)
    m.gPmp = pyo.Param(domain=pyo.Reals, mutable=True)
    m.Egref = pyo.Param(domain=pyo.NonNegativeReals, mutable=True, initialize=1.121)
    m.Tref = pyo.Param(domain=pyo.NonNegativeReals, mutable=True, units=pyo.units.K)

    # Module6ParNonlinear
    m.par = pyo.Block()
    m.par.a = pyo.Var(domain=pyo.NonNegativeReals, bounds=(0.05, 15), initialize=7.75)
    m.par.Il = pyo.Var(domain=pyo.NonNegativeReals, bounds=(0.5, 20), initialize=10.25)
    m.par.Io = pyo.Var(domain=pyo.NonNegativeReals, bounds=(None, 1e-7), initialize=5e-8) # might need to scale
    m.par.Rs = pyo.Var(domain=pyo.NonNegativeReals, bounds=(0.001, 75), initialize=32.5)
    m.par.Rsh = pyo.Var(domain=pyo.NonNegativeReals, bounds=(1, 1e6), initialize=5e5)
    m.par.Adj = pyo.Var(domain=pyo.Reals, bounds=(-100, 100), initialize=1)

    m.par.f0 = pyo.Expression(expr=(m.par.Il - m.par.Io*( pyo.exp( m.Isc*m.par.Rs / m.par.a ) - 1 ) - m.Isc*m.par.Rs/m.par.Rsh - m.Isc))
    m.par.f1 = pyo.Expression(expr=m.par.Io*( pyo.exp( m.Voc/m.par.a ) - 1 ) + m.Voc/m.par.Rsh -m.par.Il)
    m.par.f2 = pyo.Expression(expr=m.par.Il - m.par.Io*( pyo.exp( (m.Vmp + m.Imp*m.par.Rs) / m.par.a ) - 1 ) - (m.Vmp + m.Imp*m.par.Rs)/m.par.Rsh - m.Imp)
    m.par.f3 = pyo.Expression(expr=m.Imp - m.Vmp*(
        ( m.par.Io/m.par.a*pyo.exp( (m.Vmp + m.Imp*m.par.Rs)/m.par.a ) + 1/m.par.Rsh )
        /( 1 + m.par.Io*m.par.Rs/m.par.a*pyo.exp( (m.Vmp + m.Imp*m.par.Rs)/m.par.a ) + m.par.Rs/m.par.Rsh ) ))

    m.par.dT = pyo.Param(initialize=5)

    m.par.aT = pyo.Expression(expr=m.par.a*(m.Tref+m.par.dT)/m.Tref)
    m.par.VocT = pyo.Expression(expr=m.bVoc*(1+m.par.Adj/100.0)*m.par.dT + m.Voc)
    m.par.Eg = pyo.Expression(expr=(1-0.0002677*m.par.dT)*m.Egref)
    m.par.IoT = pyo.Expression(expr=m.par.Io*( (m.Tref+m.par.dT)/m.Tref )**3 *pyo.exp( 11600 * (m.Egref/m.Tref - m.par.Eg/(m.Tref+m.par.dT))))
    m.par.f4 = pyo.Expression(expr=(m.par.Il+m.aIsc*(1-m.par.Adj/100)*m.par.dT - m.par.IoT*(pyo.exp( m.par.VocT/m.par.aT ) - 1 ) - m.par.VocT/m.par.Rsh))


    # mod6par_gamma_approx
    temperatures = np.arange(-10 + 273.15, 50 + 273.15, 3)
    def gamma_expr(b, t):
        return (b.pt[t].Pmax_Tc-b.pt[t-1].Pmax_Tc)*100/(m.Vmp*m.Imp*(b.pt[t].Tc-b.pt[t-1].Tc))

    def gamma_blocks(b, i):
        b.Tc = pyo.Param(initialize=temperatures[i - 1])
        b.V_Tc = pyo.Var(domain=pyo.NonNegativeReals)
        b.I_Tc = pyo.Var(domain=pyo.NonNegativeReals)

        # PTnonlinear
        b.a_Tc = pyo.Expression(expr=m.par.a * b.Tc / m.Tref)
        b.Io_Tc = pyo.Expression(expr=m.par.Io* ( b.Tc/m.Tref)**3 * pyo.exp( 11600 * (m.Egref/m.Tref - m.par.Eg/b.Tc)))
        b.Il_Tc = pyo.Expression(expr=m.par.Il + (m.aIsc*(1-m.par.Adj/100))*(b.Tc-m.Tref))
        b.f_5 = pyo.Constraint(expr=b.V_Tc *( b.Io_Tc/b.a_Tc*pyo.exp( (b.V_Tc+b.I_Tc*m.par.Rs)/b.a_Tc ) + 1/m.par.Rsh ) 
                            / ( 1 + m.par.Rs/m.par.Rsh + b.Io_Tc*m.par.Rs/b.a_Tc*pyo.exp( (b.V_Tc+b.I_Tc*m.par.Rs)/b.a_Tc ) ) - b.I_Tc == 0)
        b.f_6 = pyo.Constraint(expr=b.Il_Tc - b.Io_Tc*(pyo.exp( (b.V_Tc+b.I_Tc*m.par.Rs)/b.a_Tc ) - 1) - (b.V_Tc + b.I_Tc*m.par.Rs)/m.par.Rsh - b.I_Tc == 0)
        b.Pmax_Tc = pyo.Expression(expr=b.V_Tc * b.I_Tc)

    nTc = len(temperatures)
    m.gamma = pyo.Block()
    g = m.gamma
    g.i = pyo.RangeSet(nTc)
    g.d_i = pyo.RangeSet(2, nTc)
    g.pt = pyo.Block(g.i, rule=gamma_blocks)

    g.gamma_Tc = pyo.Expression(g.d_i, rule=gamma_expr)
    g.gamma_avg = pyo.Expression(expr=pyo.summation(g.gamma_Tc) / len(g.d_i))

    g.f_7 = pyo.Expression(expr=(g.gamma_avg - m.gPmp) ** 4)

    m.relaxed_obj = pyo.Objective(expr=(10 * m.par.f0 ** 2 + m.par.f1 ** 2 + m.par.f2 ** 2 + m.par.f3 ** 2 + m.par.f4 ** 2 + m.gamma.f_7) ** 0.5
                                #   + sum([m.gamma.pt[i].f_5 ** 2 / nTc for i in g.i]) ** 0.5 
                                #   + sum([m.gamma.pt[i].f_6 ** 2 / nTc for i in g.i]) ** 0.5
                                  )

    # Sanity checks on current
    model.sanity = pyo.Block()
    s = model.sanity

    s.Imp_calc = pyo.Var(domain=pyo.NonNegativeReals)
    s.f_8 = pyo.Constraint(expr=m.par.Il - s.Imp_calc - m.par.Io * (pyo.exp((m.Vmp + s.Imp_calc * m.par.Rs) / m.par.a) - 1.0) - (m.Vmp + s.Imp_calc * m.par.Rs) / m.par.Rsh == 0)

    s.Ioc_calc = pyo.Var(domain=pyo.NonNegativeReals, initialize=0)
    s.f_9 = pyo.Constraint(expr=m.par.Il - s.Ioc_calc - m.par.Io * (pyo.exp((m.Voc + s.Ioc_calc * m.par.Rs) / m.par.a) - 1.0) - (m.Voc + s.Ioc_calc * m.par.Rs) / m.par.Rsh == 0)

    model.scaling_factor = pyo.Suffix(direction=pyo.Suffix.EXPORT)
    return model


def solve_model(model, solver, tee=False):
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

    # scaled_model.del_component("obj_zero")

    # scaled_model.obj_gamma = pyo.Objective(rule=scaled_model.solver.gamma.f_7 ** 2)

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
        # print("new (gamma - gmp)**2", pyo.value(scaled_model.solver.gamma.f_7), "gPmp", pyo.value(scaled_model.solver.gPmp))

    pyo.TransformationFactory('core.scale_model').propagate_solution(scaled_model, model)
    return res, scaled_model

def get_iterations(log_file):
    with open(log_file, 'r') as f:
        for line in f:
            if "Number of Iterations....:" in line:
                it = line.split(": ")[1]
                it_n = int(it)
                return it_n

def get_constraint_infeas(model):
    if hasattr(model.solver.par, 'f0'):
        vals = (pyo.value(model.solver.par.f0), pyo.value(model.solver.par.f1), pyo.value(model.solver.par.f2), pyo.value(model.solver.par.f3), pyo.value(model.solver.par.f4), pyo.value(model.solver.gamma.f_7))
    else:
        if hasattr(model.solver.gamma, 'f_7'):
            vals = (pyo.value(model.solver.par.scaled_f0), pyo.value(model.solver.par.scaled_f1), pyo.value(model.solver.par.scaled_f2), pyo.value(model.solver.par.scaled_f3), pyo.value(model.solver.par.scaled_f4), pyo.value(model.solver.gamma.f_7))
        else:
            vals = (pyo.value(model.solver.par.scaled_f0), pyo.value(model.solver.par.scaled_f1), pyo.value(model.solver.par.scaled_f2), pyo.value(model.solver.par.scaled_f3), pyo.value(model.solver.par.scaled_f4))
    return [abs(v) for v in vals]

def solve_model_best_solution(model, solver, tee=False):
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
    infeas_old = np.inf

    infeas = sum(get_constraint_infeas(model))
    # while infeas_old >= infeas:
    attempts = 0
    while infeas > 10 and attempts < 10:
        res = solver.solve(scaled_model, tee=tee, logfile='ipopt_output.log')
        infeas = sum(get_constraint_infeas(scaled_model))
        pyo.TransformationFactory('core.scale_model').propagate_solution(scaled_model, model)

    return res, scaled_model


def solve_relaxed_model(model, solver, tee=False):
    model.scaling_factor[model.solver.par.Io] = 10**min(12, -int(np.log10(pyo.value(model.solver.par.Io))))
    model.scaling_factor[model.solver.par.Rsh] = 10**min(5, -int(np.log10(pyo.value(model.solver.par.Rsh))))
    
    scaled_model = pyo.TransformationFactory('core.scale_model').create_using(model)

    res = None
    solver.options['max_iter'] = 3000
    try:
        res = solver.solve(scaled_model, tee=tee)
        pyo.TransformationFactory('core.scale_model').propagate_solution(scaled_model, model)
        
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

    pyo.TransformationFactory('core.scale_model').propagate_solution(scaled_model, model)
    return res, scaled_model

def set_parameters(m, r):
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
    m = model.solver
    m.par.a.set_value(a)
    m.par.Il.set_value(Il)
    m.par.Io.set_value(Io)
    m.par.Rs.set_value(Rs)
    m.par.Rsh.set_value(Rsh)
    m.par.Adj.set_value(Adj)
    model.sanity.Imp_calc.set_value(pyo.value(m.Imp))
    # model.sanity.Ioc_calc.set_value(pyo.value(m.par.c))

def find_closest(df, r):
    diff = (
            (df['V_mp_ref'] - r['V_mp_ref']) ** 2 + 
            (df['I_mp_ref'] - r['I_mp_ref']) ** 2 + 
            (df['V_oc_ref'] - r['V_oc_ref']) ** 2 + 
            (df['I_sc_ref'] - r['I_sc_ref']) ** 2 +
            (df['alpha_sc'] - r['alpha_sc']) ** 2 + 
            (df['beta_oc'] - r['beta_oc']) ** 2 +
            (df['gamma_r'] - r['gamma_r']) ** 2)
        
    cec_closest = df.iloc[diff.argmin()]
    return cec_closest

def get_params_from_model(model):
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


def copy_over_vars(model, scaled_model, model_rel):
    pyo.TransformationFactory('core.scale_model').propagate_solution(scaled_model, model)

    set_initial_guess(model_rel, *get_params_from_model(scaled_model))
    for i, gamma_block in model.solver.gamma.pt.items():
        model_rel.solver.gamma.pt[i].V_Tc.set_value(pyo.value(gamma_block.V_Tc))
        model_rel.solver.gamma.pt[i].I_Tc.set_value(pyo.value(gamma_block.I_Tc))

def get_curve_diffs(r, model):
    x_V, y_I = cec_model_ivcurve(model, 1000, 25 + 273.15, r['V_oc_ref'], 150)
    p = x_V * y_I
    mp_ind = np.argmax(p)
    d_I_sc = (y_I[0] - r['I_sc_ref']) / r['I_sc_ref']
    d_I_mp = (y_I[mp_ind] - r['I_mp_ref']) / r['I_mp_ref']
    d_V_mp = (x_V[mp_ind] - r['V_mp_ref']) / r['V_mp_ref']
    d_P_mp = (p[mp_ind] - r['V_mp_ref'] * r['I_mp_ref']) / (r['V_mp_ref'] * r['I_mp_ref'])
    return d_I_sc, d_I_mp, d_V_mp, d_P_mp


def format_cec_datasheet(filename):
    all_cec_modules_df = pd.read_excel(filename, skiprows=list(range(0, 16)) + [17])
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
    num_cols = ['A_c', 'N_s', 'I_sc_ref', 'V_oc_ref', 'I_mp_ref', 'V_mp_ref', 'T_NOCT',
       'gamma_r', 'alpha_sc', 'beta_oc']
    all_cec_modules_df[num_cols] = all_cec_modules_df[num_cols].astype(float)
    all_cec_modules_df['alpha_sc'] *= all_cec_modules_df['I_sc_ref'] * 1e-2
    all_cec_modules_df['beta_oc'] *= all_cec_modules_df['V_oc_ref'] * 1e-2
    all_cec_modules_df = all_cec_modules_df.drop_duplicates()
    return all_cec_modules_df


def solve_all_without_guess(all_cec_modules_df, plotting):
    for i, r in all_cec_modules_df.iterrows():
        if r['V_mp_ref'] < 0:
            all_cec_modules_df.loc[i, 'Error'] = "Vmp < 0"
            continue
        if r['V_oc_ref'] < r['V_mp_ref']:
            all_cec_modules_df.loc[i, 'Error'] = "Voc < Vmp"
            continue

        model = create_model()
        if not set_parameters(model.solver, r):
            all_cec_modules_df.loc[i, 'Error'] = "Parameter missing or out of bounds"
            continue

        if plotting:
            plt.figure()
        solver.options["max_iter"] = 3000

        res, scaled_model = solve_model(model, solver, tee=False)
        
        print(get_constraint_infeas(model))
        if plotting:
            if res and res.solver.status == 'ok':
                plot_iv_curve(model, linestyle='-', label="Optimal", plot_anchors=True)
            else:
                plot_iv_curve(model, linestyle='dotted', label="Approx", plot_anchors=True)

        if res is None or res.solver.status != 'ok':
            continue

        a, Il, Io, Rs, Rsh, Adj = get_params_from_model(scaled_model)
        all_cec_modules_df.loc[i, param_cols] = [a, Il, Io, Rs, Rsh, Adj]
    all_cec_modules_df.to_csv("cec_modules_params.csv", index=False)


def solve_all_with_guess(all_cec_modules_df, plotting):
    diff_cols = ['d_Isc', 'd_Imp', 'd_Vmp', 'd_Pmp']

    unsolved_df = all_cec_modules_df[all_cec_modules_df['Rsh_py'].isna()]
    solved_df = all_cec_modules_df[~all_cec_modules_df['Rsh_py'].isna()]
    for i, r in unsolved_df.iterrows():
        if r['V_mp_ref'] < 0:
            all_cec_modules_df.loc[i, 'Error'] = "Vmp < 0"
            continue
        if r['V_oc_ref'] < r['V_mp_ref']:
            all_cec_modules_df.loc[i, 'Error'] = "Voc < Vmp"
            continue

        model = create_model(gamma_curve_dt=15)
        if not set_parameters(model.solver, r):
            all_cec_modules_df.loc[i, 'Error'] = "Parameter missing or out of bounds"
            continue

        if plotting:
            plt.figure()
        solver.options["max_iter"] = 3000

        cec_closest = find_closest(solved_df, r)
        set_initial_guess(model, *cec_closest[param_cols])
        if plotting:
            plot_iv_curve(model, linestyle=(0, (1, 10)), label="Closest Guess")

        res, scaled_model = solve_model_best_solution(model, solver, tee=False)
        
        print(get_constraint_infeas(model))
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
        all_cec_modules_df.loc[i, diff_cols] = [d_I_sc, d_I_mp, d_V_mp, d_P_mp]
        all_cec_modules_df.loc[i, param_cols] = [a, Il, Io, Rs, Rsh, Adj]

        if plotting:
            plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
            plt.xlabel("Voltage")
            plt.ylabel("Current")
            plt.title(f"{r['Manufacturer']} {r['Model Number']}")
            plt.tight_layout()
            plt.savefig(output_path / f"IV_curve_{'nosam' if not len(r_sam) else '_'}{i}.png")
            plt.close()

    all_cec_modules_df.to_csv("cec_modules_params_approx.csv", index=False)

if __name__ == "__main__":

    output_path = Path(__file__).parent / "6parsolve_output"
    if not (output_path).exists():
        os.mkdir(output_path)

    solver = pyo.SolverFactory('ipopt')

    filename = "/Users/dguittet/Projects/SAM/sam/samples/CEC Module and Inverter Libraries/CEC Modules/CEC Modules 2024-11-14/CEC Modules 2024-Nov-15_09-53.csv"
    sam_solved_modules_df = pd.read_csv(filename, skiprows=[1, 2])

    all_cec_modules_df = pd.read_csv("cec_modules_params_approx.csv")

    unsolved_df = all_cec_modules_df[all_cec_modules_df['Rsh_py'].isna()]

    solved_df = all_cec_modules_df[~all_cec_modules_df['Rsh_py'].isna()]

    diff_cols = ['d_Isc', 'd_Imp', 'd_Vmp', 'd_Pmp']

    plotting = True
    for i, r in all_cec_modules_df.iterrows():
        if r['V_mp_ref'] < 0:
            all_cec_modules_df.loc[i, 'Error'] = "Vmp < 0"
            continue
        if r['V_oc_ref'] < r['V_mp_ref']:
            all_cec_modules_df.loc[i, 'Error'] = "Voc < Vmp"
            continue

        model = create_model(gamma_curve_dt=15)
        if not set_parameters(model.solver, r):
            all_cec_modules_df.loc[i, 'Error'] = "Parameter missing or out of bounds"
            continue

        if plotting:
            plt.figure()
        solver.options["max_iter"] = 3000

        # plot SAM one
        r_sam = sam_solved_modules_df[(sam_solved_modules_df['Manufacturer'] == r['Manufacturer'].replace(",", "")) 
                                          & (sam_solved_modules_df['Name'].str.contains(r['Model Number'], regex=False))
                                          & (sam_solved_modules_df['PTC'] == r['PTC'])].drop_duplicates()
        if len(r_sam):
            r_sam = r_sam.to_dict('records')[0]
            set_initial_guess(model, r_sam['a_ref'], r_sam['I_L_ref'], r_sam['I_o_ref'], r_sam['R_s'], r_sam['R_sh_ref'], r_sam['Adjust'])
            if plotting:
                plot_iv_curve(model, linestyle='dashed', label="SAM")
        if True:
            cec_closest = find_closest(solved_df, r)
            set_initial_guess(model, *cec_closest[param_cols])
            if plotting:
                plot_iv_curve(model, linestyle=(0, (1, 10)), label="Closest Guess")

        # res, scaled_model = solve_model_best_solution(model, solver, tee=False)
        res, scaled_model = solve_model(model, solver, tee=False)
        
        print(get_constraint_infeas(model))
        if plotting:
            if res and res.solver.status == 'ok':
                plot_iv_curve(model, linestyle='-', label="Optimal", plot_anchors=True)
            else:
                plot_iv_curve(model, linestyle='dotted', label="Approx", plot_anchors=True)

        # if res is None or res.solver.status != 'ok':
            # solver.options['max_iter'] = 1938
            # res = solver.solve(scaled_model, tee=True)

            # model_rel = create_full_relaxed_model()
            # set_parameters(model_rel.solver, r)

            # copy_over_vars(model, scaled_model, model_rel)

            # res_rel, scaled_model_rel = solve_relaxed_model(model_rel, solver, True)
            
            # print(get_constraint_infeas(model_rel))
            # plot_iv_curve(model_rel, linestyle='-', label="Closest", plot_anchors=True)

            # if res_rel is None or res_rel.solver.status != 'ok':
                # continue

        d_I_sc, d_I_mp, d_V_mp, d_P_mp = get_curve_diffs(r, model)

        infeas_sum = np.abs([d_I_sc, d_I_mp, d_V_mp, d_P_mp]).sum()
        infeas_max = np.abs([d_I_sc, d_I_mp, d_V_mp, d_P_mp]).max()

        if infeas_max > 0.5 or infeas_sum > 0.5:
            all_cec_modules_df.loc[i, 'Error'] = "Infeasibility > 0.5"
            if plotting:
                plt.close()
            continue

        a, Il, Io, Rs, Rsh, Adj = get_params_from_model(scaled_model)
        all_cec_modules_df.loc[i, diff_cols] = [d_I_sc, d_I_mp, d_V_mp, d_P_mp]
        all_cec_modules_df.loc[i, param_cols] = [a, Il, Io, Rs, Rsh, Adj]

        if plotting:
            plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
            plt.xlabel("Voltage")
            plt.ylabel("Current")
            plt.title(f"{r['Manufacturer']} {r['Model Number']}")
            plt.tight_layout()
            plt.savefig(output_path / f"IV_curve_{'nosam' if not len(r_sam) else '_'}{i}.png")
            plt.close()

    all_cec_modules_df.to_csv("cec_modules_params_approx.csv", index=False)
    exit()






    filename = "/Users/dguittet/Projects/SAM/sam/samples/CEC Module and Inverter Libraries/CEC Modules/CEC Modules 2024-11-14/CEC Modules 2024-Nov-15_09-53.csv"
    cec_modules_df = pd.read_csv(filename, skiprows=[1, 2])

    filename = "/Users/dguittet/Projects/SAM/sam/samples/CEC Module and Inverter Libraries/CEC Modules/CEC Modules 2024-11-14/Bad Modules 2024-Nov-15_09-53.csv"
    cec_bad_modules_df = pd.read_csv(filename, skiprows=[1, 2])
    cec_bad_modules_df.index = range(len(cec_modules_df), len(cec_modules_df) + len(cec_bad_modules_df))

    cec_bad_modules_df = cec_bad_modules_df.rename(columns={"Model": "Name", "celltype": "Technology", "vmp": "V_mp_ref",
                                                            "imp": "I_mp_ref", "voc": "V_oc_ref", "isc": "I_sc_ref", "alpha_isc": "alpha_sc",
                                                            "beta_voc": "beta_oc", "gamma_pmp": "gamma_r", "n_ser": "N_s", "t_ref": "STC"})
    cec_bad_modules_df = cec_bad_modules_df.drop(columns=["Message"])


    solved_modules = "/Users/dguittet/Projects/SAM/pysam/param_comparison_1.csv"
    solved_modules_df = pd.read_csv(solved_modules, index_col='index').dropna()
    cec_modules_solved_df = cec_modules_df[cec_modules_df.index.isin(solved_modules_df.index)]

    solved_bad_modules = "/Users/dguittet/Projects/SAM/pysam/bad_modules_param_0.csv"
    solved_bad_modules_df = pd.read_csv(solved_bad_modules, index_col='index')
    solved_bad_modules_df.index = range(len(cec_modules_df), len(cec_modules_df) + len(solved_bad_modules_df))
    cec_bad_modules_solved_df = cec_bad_modules_df[cec_bad_modules_df.index.isin(solved_bad_modules_df.index)]

    # read all
    filename = "/Users/dguittet/Projects/SAM/sam/samples/CEC Module and Inverter Libraries/CEC Modules/CEC Modules 2024-11-14/PV_Module_List_Full_Data_ADA-2024-11-12.xlsx"
    all_cec_modules_df = pd.read_excel(filename, skiprows=list(range(0, 16)) + [17])
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
    num_cols = ['A_c', 'N_s', 'I_sc_ref', 'V_oc_ref', 'I_mp_ref', 'V_mp_ref', 'T_NOCT',
       'gamma_r', 'alpha_sc', 'beta_oc']
    all_cec_modules_df[num_cols] = all_cec_modules_df[num_cols].astype(float)
    all_cec_modules_df['alpha_sc'] *= all_cec_modules_df['I_sc_ref'] * 1e-2
    all_cec_modules_df['beta_oc'] *= all_cec_modules_df['V_oc_ref'] * 1e-2
    all_cec_modules_df = all_cec_modules_df.drop_duplicates()
    
    for col in param_cols:
        all_cec_modules_df[col] = None

    for i, row in all_cec_modules_df.iterrows():
        r_sam = cec_modules_solved_df[(cec_modules_solved_df['Manufacturer'] == row['Manufacturer'].replace(",", "")) 
                                          & (cec_modules_solved_df['Name'].str.contains(row['Model Number'], regex=False))
                                          & (cec_modules_solved_df['PTC'] == row['PTC'])].drop_duplicates()
        if len(r_sam) > 1:
            r_sam = r_sam[r_sam['Name'].str.endswith(row['Model Number'])]
            if len(r_sam) > 1:
                print("Duplicate: ", i, row)
                continue
        if len(r_sam) == 1:
            param_row = solved_modules_df.loc[r_sam.index]

        if len(r_sam) == 0:
            r_sam = cec_bad_modules_solved_df[(cec_bad_modules_solved_df['Manufacturer'] == row['Manufacturer'].replace(",", "")) 
                                                  & (cec_bad_modules_solved_df['Name'].str.contains(row['Model Number'], regex=False))
                                                  ].drop_duplicates()
            if len(r_sam) > 1:
                r_sam = r_sam[r_sam['Name'].str.endswith(row['Model Number'])]
                if len(r_sam) > 1:
                    print("Duplicate: ", i, row)
                    continue
            if len(r_sam) == 1:
                param_row = solved_bad_modules_df.loc[r_sam.index]
        
        if len(r_sam) == 0:
            continue

        all_cec_modules_df.loc[i, param_cols] = param_row[param_cols].values[0]
    all_cec_modules_df.to_csv("cec_modules_params.csv") 

    exit()





    param_comparison = {
        "index": [],
        "a_ssc": [],
        "Il_ssc": [],
        "Io_ssc": [],
        "Rs_ssc": [],
        "Rsh_ssc": [],
        "Adj_ssc": [],
        "a_py": [],
        "Il_py": [],
        "Io_py": [],
        "Rs_py": [],
        "Rsh_py": [],
        "Adj_py": []
    }

    for i, r in cec_modules_unsolved_df.iterrows():
        model = create_model()
        m = model.solver
        tech = r['Technology']


        param_comparison['index'].append(i)
        param_comparison['a_ssc'].append(r['a_ref'])
        param_comparison['Il_ssc'].append(r['I_L_ref'])
        param_comparison['Io_ssc'].append(r['I_o_ref'])
        param_comparison['Rs_ssc'].append(r['R_s'])
        param_comparison['Rsh_ssc'].append(r['R_sh_ref'])
        param_comparison['Adj_ssc'].append(r['Adjust'])

        m.Vmp.set_value(r['V_mp_ref'])
        m.Imp.set_value(r['I_mp_ref'])
        m.Voc.set_value(r['V_oc_ref'])
        m.Isc.set_value(r['I_sc_ref'])
        m.aIsc.set_value(r['alpha_sc'])
        m.bVoc.set_value(r['beta_oc'])
        m.gPmp.set_value(r['gamma_r'])
        # m.Tref.set_value(r['STC'])
        m.Tref.set_value(25 + 273.15)

        df = cec_modules_solved_df
        diff = (
            (df['V_mp_ref'] - r['V_mp_ref']) ** 2 + 
            (df['I_mp_ref'] - r['I_mp_ref']) ** 2 + 
            (df['V_oc_ref'] - r['V_oc_ref']) ** 2 + 
            (df['I_sc_ref'] - r['I_sc_ref']) ** 2 +
            (df['alpha_sc'] - r['alpha_sc']) ** 2 + 
            (df['beta_oc'] - r['beta_oc']) ** 2 +
            (df['gamma_r'] - r['gamma_r']) ** 2)
        
        cec_closest = cec_modules_solved_df.iloc[diff.argmin()]

        m.par.a.set_value(cec_closest['a_ref'])
        m.par.Il.set_value(cec_closest['I_L_ref'])
        m.par.Io.set_value(cec_closest['I_o_ref'])
        m.par.Rs.set_value(cec_closest['R_s'])
        m.par.Rsh.set_value(cec_closest['R_sh_ref'])
        m.par.Adj.set_value(cec_closest['Adjust'])

        res, scaled_model = solve_model(model, solver, tee=False)

        if res is None or res.solver.status != 'ok':
            # log_infeasible_constraints(scaled_model, logger=solve_log, tol=1e-5, log_expression=True, log_variables=True)
            # log_infeasible_bounds(scaled_model, logger=solve_log,  tol=1e-5)
            # print(n, pyo.value(scaled_model.solver.gamma.gamma_avg), pyo.value(scaled_model.solver.gPmp))
            # print(pyo.value(scaled_model.solver.gamma.obj))
            param_comparison['a_py'].append(None)
            param_comparison['Il_py'].append(None)
            param_comparison['Io_py'].append(None)
            param_comparison['Rs_py'].append(None)
            param_comparison['Rsh_py'].append(None)
            param_comparison['Adj_py'].append(None)
        else:

            a = pyo.value(scaled_model.solver.par.scaled_a)
            Il = pyo.value(scaled_model.solver.par.scaled_Il)
            Io = pyo.value(scaled_model.solver.par.scaled_Io / IL_SCALING)
            Rs = pyo.value(scaled_model.solver.par.scaled_Rs)
            Rsh = pyo.value(scaled_model.solver.par.scaled_Rsh / RSH_SCALING)
            Adj = pyo.value(scaled_model.solver.par.scaled_Adj)

            param_comparison['a_py'].append(a)
            param_comparison['Il_py'].append(Il)
            param_comparison['Io_py'].append(Io)
            param_comparison['Rs_py'].append(Rs)
            param_comparison['Rsh_py'].append(Rsh)
            param_comparison['Adj_py'].append(Adj)

        # if i % 100 == 0:
        #     comparison_df = pd.DataFrame(param_comparison).set_index('index')
        #     comparison_df['d_a'] = ((comparison_df['a_py'] - comparison_df['a_ssc'])/comparison_df['a_ssc']).abs()
        #     comparison_df['d_Il'] = ((comparison_df['Il_py'] - comparison_df['Il_ssc'])/comparison_df['Il_ssc']).abs()
        #     comparison_df['d_Io'] = ((comparison_df['Io_py'] - comparison_df['Io_ssc'])/comparison_df['Io_ssc']).abs()
        #     comparison_df['d_Rs'] = ((comparison_df['Rs_py'] - comparison_df['Rs_ssc'])/comparison_df['Rs_ssc']).abs()
        #     comparison_df['d_Rsh'] = ((comparison_df['Rsh_py'] - comparison_df['Rsh_ssc'])/comparison_df['Rsh_ssc']).abs()
        #     comparison_df['d_Adj'] = ((comparison_df['Adj_py'] - comparison_df['Adj_ssc'])/comparison_df['Adj_ssc']).abs()

        #     comparison_df = comparison_df.dropna()
        #     cec_modules_solved_df = pd.concat([cec_modules_solved_df, comparison_df])

    comparison_df = pd.DataFrame(param_comparison).set_index('index')
    comparison_df['d_a'] = ((comparison_df['a_py'] - comparison_df['a_ssc'])/comparison_df['a_ssc']).abs()
    comparison_df['d_Il'] = ((comparison_df['Il_py'] - comparison_df['Il_ssc'])/comparison_df['Il_ssc']).abs()
    comparison_df['d_Io'] = ((comparison_df['Io_py'] - comparison_df['Io_ssc'])/comparison_df['Io_ssc']).abs()
    comparison_df['d_Rs'] = ((comparison_df['Rs_py'] - comparison_df['Rs_ssc'])/comparison_df['Rs_ssc']).abs()
    comparison_df['d_Rsh'] = ((comparison_df['Rsh_py'] - comparison_df['Rsh_ssc'])/comparison_df['Rsh_ssc']).abs()
    comparison_df['d_Adj'] = ((comparison_df['Adj_py'] - comparison_df['Adj_ssc'])/comparison_df['Adj_ssc']).abs()

    comparison_df = comparison_df.dropna()
    for i, row in comparison_df.iterrows():
        solved_modules_df.loc[i] = row
    solved_modules_df.to_csv("param_comparison.csv")

    exit()
    filename = "/Users/dguittet/Projects/SAM/sam/samples/CEC Module and Inverter Libraries/CEC Modules/CEC Modules 2024-11-14/Bad Modules 2024-Nov-15_09-53.csv"
    bad_modules_df = pd.read_csv(filename, skiprows=[1, 2])

    param_comparison = {
        "index": [],
        "a_py": [],
        "Il_py": [],
        "Io_py": [],
        "Rs_py": [],
        "Rsh_py": [],
        "Adj_py": []
    }

    tee = False

    for n, r in bad_modules_df.iterrows():
        model = create_model()
        m = model.solver
        tech = r['Technology']

        param_comparison['index'].append(n)

        m.Vmp.set_value(r['vmp'])
        m.Imp.set_value(r['imp'])
        m.Voc.set_value(r['voc'])
        m.Isc.set_value(r['isc'])
        m.aIsc.set_value(r['alpha_isc'])
        m.bVoc.set_value(r['beta_voc'])
        m.gPmp.set_value(r['gamma_pmp'])
        m.Tref.set_value(25 + 273.15)

        res, scaled_model = solve_model(model, solver, tee=tee)

        if res is None or res.solver.status != 'ok':
            # log_infeasible_constraints(scaled_model, logger=solve_log, tol=1e-5, log_expression=True, log_variables=True)
            # log_infeasible_bounds(scaled_model, logger=solve_log,  tol=1e-5)
            # print(n, pyo.value(scaled_model.solver.gamma.gamma_avg), pyo.value(scaled_model.solver.gPmp))
            # print(pyo.value(scaled_model.solver.gamma.obj))
            param_comparison['a_py'].append(None)
            param_comparison['Il_py'].append(None)
            param_comparison['Io_py'].append(None)
            param_comparison['Rs_py'].append(None)
            param_comparison['Rsh_py'].append(None)
            param_comparison['Adj_py'].append(None)
        else:

            a = pyo.value(scaled_model.solver.par.scaled_a)
            Il = pyo.value(scaled_model.solver.par.scaled_Il)
            Io = pyo.value(scaled_model.solver.par.scaled_Io / IL_SCALING)
            Rs = pyo.value(scaled_model.solver.par.scaled_Rs)
            Rsh = pyo.value(scaled_model.solver.par.scaled_Rsh / RSH_SCALING)
            Adj = pyo.value(scaled_model.solver.par.scaled_Adj)

            param_comparison['a_py'].append(a)
            param_comparison['Il_py'].append(Il)
            param_comparison['Io_py'].append(Io)
            param_comparison['Rs_py'].append(Rs)
            param_comparison['Rsh_py'].append(Rsh)
            param_comparison['Adj_py'].append(Adj)

        if n % 10 == 0:
            comparison_df = pd.DataFrame(param_comparison).set_index('index')
            comparison_df.to_csv("bad_modules_param.csv")


def run_solved_modules():
    solver = pyo.SolverFactory('ipopt')
    solver.options["max_iter"] = 5000

    filename = "/Users/dguittet/Projects/SAM/sam/samples/CEC Module and Inverter Libraries/CEC Modules/CEC Modules 2024-11-14/CEC Modules 2024-Nov-15_09-53.csv"
    cec_modules_df = pd.read_csv(filename, skiprows=[1, 2])

    param_comparison = {
        "index": [],
        "a_ssc": [],
        "Il_ssc": [],
        "Io_ssc": [],
        "Rs_ssc": [],
        "Rsh_ssc": [],
        "Adj_ssc": [],
        "a_py": [],
        "Il_py": [],
        "Io_py": [],
        "Rs_py": [],
        "Rsh_py": [],
        "Adj_py": []
    }

    tee = False

    for n, r in cec_modules_df.iterrows():
        model = create_model()
        m = model.solver
        tech = r['Technology']

        # if r['I_mp_ref'] < r['I_sc_ref']:
            # raise ValueError

        param_comparison['index'].append(n)
        param_comparison['a_ssc'].append(r['a_ref'])
        param_comparison['Il_ssc'].append(r['I_L_ref'])
        param_comparison['Io_ssc'].append(r['I_o_ref'])
        param_comparison['Rs_ssc'].append(r['R_s'])
        param_comparison['Rsh_ssc'].append(r['R_sh_ref'])
        param_comparison['Adj_ssc'].append(r['Adjust'])

        m.Vmp.set_value(r['V_mp_ref'])
        m.Imp.set_value(r['I_mp_ref'])
        m.Voc.set_value(r['V_oc_ref'])
        m.Isc.set_value(r['I_sc_ref'])
        m.aIsc.set_value(r['alpha_sc'])
        m.bVoc.set_value(r['beta_oc'])
        m.gPmp.set_value(r['gamma_r'])
        m.Tref.set_value(25 + 273.15)

        # m.par.a.set_value(r['a_ref'])
        # m.par.Il.set_value(r['I_L_ref'])
        # m.par.Io.set_value(r['I_o_ref'])
        # m.par.Rs.set_value(r['R_s'])
        # m.par.Rsh.set_value(r['R_sh_ref'])
        # m.par.Adj.set_value(r['Adjust'])

        res, scaled_model = solve_model(model, solver, tee=tee)

        if res is None or res.solver.status != 'ok':
            # log_infeasible_constraints(scaled_model, logger=solve_log, tol=1e-5, log_expression=True, log_variables=True)
            # log_infeasible_bounds(scaled_model, logger=solve_log,  tol=1e-5)
            # print(n, pyo.value(scaled_model.solver.gamma.gamma_avg), pyo.value(scaled_model.solver.gPmp))
            # print(pyo.value(scaled_model.solver.gamma.obj))
            param_comparison['a_py'].append(None)
            param_comparison['Il_py'].append(None)
            param_comparison['Io_py'].append(None)
            param_comparison['Rs_py'].append(None)
            param_comparison['Rsh_py'].append(None)
            param_comparison['Adj_py'].append(None)
        else:

            a = pyo.value(scaled_model.solver.par.scaled_a)
            Il = pyo.value(scaled_model.solver.par.scaled_Il)
            Io = pyo.value(scaled_model.solver.par.scaled_Io / IL_SCALING)
            Rs = pyo.value(scaled_model.solver.par.scaled_Rs)
            Rsh = pyo.value(scaled_model.solver.par.scaled_Rsh / RSH_SCALING)
            Adj = pyo.value(scaled_model.solver.par.scaled_Adj)

            param_comparison['a_py'].append(a)
            param_comparison['Il_py'].append(Il)
            param_comparison['Io_py'].append(Io)
            param_comparison['Rs_py'].append(Rs)
            param_comparison['Rsh_py'].append(Rsh)
            param_comparison['Adj_py'].append(Adj)

        if n % 10 == 0:
            comparison_df = pd.DataFrame(param_comparison).set_index('index')
            comparison_df['d_a'] = ((comparison_df['a_py'] - comparison_df['a_ssc'])/comparison_df['a_ssc']).abs()
            comparison_df['d_Il'] = ((comparison_df['Il_py'] - comparison_df['Il_ssc'])/comparison_df['Il_ssc']).abs()
            comparison_df['d_Io'] = ((comparison_df['Io_py'] - comparison_df['Io_ssc'])/comparison_df['Io_ssc']).abs()
            comparison_df['d_Rs'] = ((comparison_df['Rs_py'] - comparison_df['Rs_ssc'])/comparison_df['Rs_ssc']).abs()
            comparison_df['d_Rsh'] = ((comparison_df['Rsh_py'] - comparison_df['Rsh_ssc'])/comparison_df['Rsh_ssc']).abs()
            comparison_df['d_Adj'] = ((comparison_df['Adj_py'] - comparison_df['Adj_ssc'])/comparison_df['Adj_ssc']).abs()

            comparison_df.to_csv("param_comparison.csv")
