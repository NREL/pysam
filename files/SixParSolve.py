import pyomo.environ as pyo
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import idaes.logger as idaeslog
from pyomo.util.infeasible import log_infeasible_constraints, log_infeasible_bounds, log_close_to_bounds

solve_log = idaeslog.getInitLogger("infeasibility", idaeslog.INFO, tag="properties")

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
    Tc_ref = pyo.value(model.Tref)
    a = pyo.value(model.par.a)
    Io = pyo.value(model.par.Io)
    eg0 = pyo.value(model.Egref)
    Adj = pyo.value(model.par.Adj)
    alpha = pyo.value(model.aIsc)
    Il = pyo.value(model.par.Il)
    Io = pyo.value(model.par.Io)
    Rs = pyo.value(model.par.Rs)
    Rsh = pyo.value(model.par.Rsh)

    q = 1.6e-19
    KB = 1.38e-23

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
    I_mp_ref = pyo.value(model.Imp)
    IL_oper, IO_oper, Rs, A_oper, Rsh_oper = cec_model_params_at_condition(model, Irr, T_cell_K)

    y_I = []

    V = np.linspace(0, vmax, npts)
    for i, v in enumerate(V):
        I = current_at_voltage_cec( v, IL_oper, IO_oper, Rs, A_oper, Rsh_oper, I_mp_ref )	
        y_I.append(I)
    return V, y_I
    
def plot_iv_curve(model):
    curves = [ [ 1000, 25, 'black' ],
               [ 800,  25, 'blue' ],
               [ 600,  25, 'red' ],
               [ 400,  25, 'green' ],
               [ 200,  25, 'orange' ] ]
        
    alpha = pyo.value(model.aIsc)
    beta = pyo.value(model.bVoc)
    vmax = pyo.value(model.Voc)
    imax = pyo.value(model.Isc)
    I_mp_ref = pyo.value(model.Imp)

    npts = 150
    for curve in curves:
        Irr = curve[0]
        Tc = curve[1]

        x_V, y_I = cec_model_ivcurve(model, Irr, Tc + 273.15, vmax, npts)
        plt.plot(x_V, y_I, label=f"{Irr} W/m^2", color=curve[2])


def create_model():
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
    m.par.a = pyo.Var(domain=pyo.NonNegativeReals, bounds=(0.05, 15))
    m.par.Il = pyo.Var(domain=pyo.NonNegativeReals, bounds=(0.5, 20))
    m.par.Io = pyo.Var(domain=pyo.NonNegativeReals, bounds=(None, 1e-7)) # might need to scale
    m.par.Rs = pyo.Var(domain=pyo.NonNegativeReals, bounds=(0.001, 75))
    m.par.Rsh = pyo.Var(domain=pyo.NonNegativeReals, bounds=(1, 1e6))
    m.par.Adj = pyo.Var(domain=pyo.Reals, bounds=(-100, 100))

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
    temperatures = np.arange(-10 + 273.15, 50 + 273.15, 3)
    def gamma_expr(b, t):
        if t == 1:
            return 0
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
    g.pt = pyo.Block(g.i, rule=gamma_blocks)

    g.gamma_Tc = pyo.Expression(g.i, rule=gamma_expr)
    g.gamma_avg = pyo.Expression(expr=pyo.summation(g.gamma_Tc) / (nTc - 1))

    g.f_7 = pyo.Expression(expr=(g.gamma_avg - m.gPmp) ** 2)

    # Sanity checks on current
    model.sanity = pyo.Block()
    s = model.sanity

    s.Imp_calc = pyo.Var(domain=pyo.NonNegativeReals)
    s.f_8 = pyo.Constraint(expr=m.par.Il - s.Imp_calc - m.par.Io * (pyo.exp((m.Vmp + s.Imp_calc * m.par.Rs) / m.par.a) - 1.0) - (m.Vmp + s.Imp_calc * m.par.Rs) / m.par.Rsh == 0)

    s.Ioc_calc = pyo.Var(domain=pyo.NonNegativeReals)
    s.f_9 = pyo.Constraint(expr=m.par.Il - s.Ioc_calc - m.par.Io * (pyo.exp((m.Voc + s.Ioc_calc * m.par.Rs) / m.par.a) - 1.0) - (m.Voc + s.Ioc_calc * m.par.Rs) / m.par.Rsh == 0)

    # Sanity checks on max_slope
    # v_range = np.linspace(0.015 * m.Voc.value, 0.98 * m.Voc.value, 100)
    model.slope = pyo.Block()
    

    # examine solved modules
    model.obj = pyo.Objective(rule=g.f_7)
    model.scaling_factor = pyo.Suffix(direction=pyo.Suffix.EXPORT)
    return model

if __name__ == "__main__":

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
    IL_SCALING = 1e9
    RSH_SCALING = 1e-3
    for n, r in cec_modules_df.iterrows():
        model = create_model()
        m = model.solver
        tech = r['Technology']

        # if r['I_mp_ref'] < r['I_sc_ref']:
            # raise ValueError

        m.Vmp.set_value(r['V_mp_ref'])
        m.Imp.set_value(r['I_mp_ref'])
        m.Voc.set_value(r['V_oc_ref'])
        m.Isc.set_value(r['I_sc_ref'])
        m.aIsc.set_value(r['alpha_sc'])
        m.bVoc.set_value(r['beta_oc'])
        m.gPmp.set_value(r['gamma_r'])
        m.Tref.set_value(25 + 273.15)

        m.par.a.set_value(r['a_ref'])
        m.par.Il.set_value(r['I_L_ref'])
        m.par.Io.set_value(r['I_o_ref'])
        m.par.Rs.set_value(r['R_s'])
        m.par.Rsh.set_value(r['R_sh_ref'])
        m.par.Adj.set_value(r['Adjust'])

        model.scaling_factor[model.solver.par.Io] = IL_SCALING
        model.scaling_factor[model.solver.par.Rsh] = RSH_SCALING
        scaled_model = pyo.TransformationFactory('core.scale_model').create_using(model)

        scaled_model.solver.par.obj = pyo.Objective(rule=0)

        # log_infeasible_constraints(scaled_model.solver.par, logger=solve_log, tol=1e-5, log_expression=True, log_variables=True)
        # log_infeasible_bounds(scaled_model.solver.par, logger=solve_log,  tol=1e-5)

        scaled_model.solver.par.del_component('obj')

        solver.solve(scaled_model.solver.par, tee=tee)

        scaled_model.solver.gamma.obj = pyo.Objective(rule=model.solver.gamma.f_7)

        solver.solve(scaled_model.solver.gamma, tee=tee)
        # print(pyo.value(scaled_model.solver.gamma.gamma_avg), pyo.value(scaled_model.solver.gPmp))
        # print(pyo.value(scaled_model.solver.gamma.obj))

        scaled_model.solver.gamma.del_component('obj')

        solver.solve(scaled_model.sanity, tee=tee)
        
        try:
            res = solver.solve(scaled_model, tee=tee)
        except:
            pass 

        if res.solver.status != 'ok':
            # log_infeasible_constraints(scaled_model, logger=solve_log, tol=1e-5, log_expression=True, log_variables=True)
            # log_infeasible_bounds(scaled_model, logger=solve_log,  tol=1e-5)
            print(n, pyo.value(scaled_model.solver.gamma.gamma_avg), pyo.value(scaled_model.solver.gPmp))
            # print(pyo.value(scaled_model.solver.gamma.obj))
        else:
            param_comparison['index'].append(n)
            param_comparison['a_ssc'].append(r['a_ref'])
            param_comparison['Il_ssc'].append(r['I_L_ref'])
            param_comparison['Io_ssc'].append(r['I_o_ref'])
            param_comparison['Rs_ssc'].append(r['R_s'])
            param_comparison['Rsh_ssc'].append(r['R_sh_ref'])
            param_comparison['Adj_ssc'].append(r['Adjust'])
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

    comparison_df = pd.DataFrame(param_comparison).set_index('index')
    comparison_df['d_a'] = ((comparison_df['a_py'] - comparison_df['a_ssc'])/comparison_df['a_ssc']).abs()
    comparison_df['d_Il'] = ((comparison_df['Il_py'] - comparison_df['Il_ssc'])/comparison_df['Il_ssc']).abs()
    comparison_df['d_Io'] = ((comparison_df['Io_py'] - comparison_df['Io_ssc'])/comparison_df['Io_ssc']).abs()
    comparison_df['d_Rs'] = ((comparison_df['Rs_py'] - comparison_df['Rs_ssc'])/comparison_df['Rs_ssc']).abs()
    comparison_df['d_Rsh'] = ((comparison_df['Rsh_py'] - comparison_df['Rsh_ssc'])/comparison_df['Rsh_ssc']).abs()
    comparison_df['d_Adj'] = ((comparison_df['Adj_py'] - comparison_df['Adj_ssc'])/comparison_df['Adj_ssc']).abs()

    comparison_df.to_csv("param_comparison.csv")