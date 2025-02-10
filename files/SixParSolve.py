import pyomo.environ as pyo
import pandas as pd
import numpy as np
import idaes.logger as idaeslog
from pyomo.util.infeasible import log_infeasible_constraints, log_infeasible_bounds, log_close_to_bounds

solve_log = idaeslog.getInitLogger("infeasibility", idaeslog.INFO, tag="properties")

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
m.Tref = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)

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
        return pyo.Expression.Skip
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
g.gamma_avg = pyo.Expression(expr=sum(g.gamma_Tc) / nTc)

g.f_7 = pyo.Constraint(expr=g.gamma_avg - m.gPmp == 0)

# Sanity checks on current
model.sanity = pyo.Block()
s = model.sanity

s.Imp_calc = pyo.Var(domain=pyo.NonNegativeReals)
s.f_8 = pyo.Constraint(expr=m.par.Il - s.Imp_calc - m.par.Io * (pyo.exp((m.Vmp + s.Imp_calc * m.par.Rs) / m.par.a) - 1.0) - (m.Vmp + s.Imp_calc * m.par.Rs) / m.par.Rsh == 0)

s.Ioc_calc = pyo.Var(domain=pyo.NonNegativeReals)
s.f_9 = pyo.Constraint(expr=m.par.Il - s.Ioc_calc - m.par.Io * (pyo.exp((m.Voc + s.Ioc_calc * m.par.Rs) / m.par.a) - 1.0) - (m.Voc + s.Ioc_calc * m.par.Rs) / m.par.Rsh == 0)

# Sanity checks on max_slope
# v_range = np.linspace(0.015 * m.Voc.value, 0.98 * m.Voc.value, 100)

# examine solved modules
model.obj = pyo.Objective(expr=0)

solver = pyo.SolverFactory('ipopt')
 
filename = "/Users/dguittet/Projects/SAM/sam/samples/CEC Module and Inverter Libraries/CEC Modules/CEC Modules 2024-11-14/CEC Modules 2024-Nov-15_09-53.csv"
cec_modules_df = pd.read_csv(filename, skiprows=[1, 2])

for n, r in cec_modules_df.iterrows():
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

    log_infeasible_constraints(m.par, logger=solve_log, tol=1e-5, log_expression=True, log_variables=True)
    log_infeasible_bounds(m.par, logger=solve_log,  tol=1e-5)

    solver.solve(m.par, tee=True)

