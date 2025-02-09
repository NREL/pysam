import pyomo.environ as pyo
import pandas as pd
import numpy as np

m = pyo.ConcreteModel()

m.Vmp = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
m.Imp = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
m.Voc = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
m.Isc = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
m.bVoc = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
m.aIsc = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
m.gPmp = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
m.Egref = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)
m.Tref = pyo.Param(domain=pyo.NonNegativeReals, mutable=True)

m.a = pyo.Var(domain=pyo.NonNegativeReals, bounds=(0.05, 15))
m.Il = pyo.Var(domain=pyo.NonNegativeReals, bounds=(0.5, 20))
m.Io = pyo.Var(domain=pyo.NonNegativeReals, bounds=(None, 1e-7)) # might need to scale
m.Rs = pyo.Var(domain=pyo.NonNegativeReals, bounds=(0.001, 75))
m.Rsh = pyo.Var(domain=pyo.NonNegativeReals, bounds=(1, 1e6))
m.Adj = pyo.Var(domain=pyo.Reals, bounds=(-100, 100))

m.Tc = pyo.RangeSet(-10 + 273.15, 50 + 273.15, 3)
m.nTc = pyo.Param(len(m.Tc))
m.V_Tc = pyo.Var(m.Tc, domain=pyo.NonNegativeReals)
m.I_Tc = pyo.Var(m.Tc, domain=pyo.NonNegativeReals)

m.f0 = pyo.Constraint(expr=m.Il - m.Io*( pyo.exp( m.Isc*m.Rs / m.a ) - 1 ) - m.Isc*m.Rs/m.Rsh - m.Isc == 0)
m.f1 = pyo.Constraint(expr=m.Io*( pyo.exp( m.Voc/m.a ) - 1 ) + m.Voc/m.Rsh -m.Il == 0)
m.f2 = pyo.Constraint(expr=m.Il - m.Io*( pyo.exp( (m.Vmp + m.Imp*m.Rs) / m.a ) - 1 ) - (m.Vmp + m.Imp*m.Rs)/m.Rsh - m.Imp == 0)
m.f3 = pyo.Constraint(expr=m.Imp - m.Vmp*(
    ( m.Io/m.a*pyo.exp( (m.Vmp + m.Imp*m.Rs)/m.a ) + 1/m.Rsh )
    /( 1 + m.Io*m.Rs/m.a*pyo.exp( (m.Vmp + m.Imp*m.Rs)/m.a ) + m.Rs/m.Rsh ) ) == 0)

m.dT = pyo.Param(5)

m.aT = pyo.Expression(expr=m.a*(m.Tref+m.dT)/m.Tref)
m.VocT = pyo.Expression(expr=m.bVoc*(1+m.Adj/100.0)*m.dT + m.Voc)
m.Eg = pyo.Expression(expr=(1-0.0002677*m.dT)*m.Egref)
m.IoT = pyo.Expression(expr=m.Io*( (m.Tref+m.dT)/m.Tref )**3 *pyo.exp( 11600 * (m.Egref/m.Tref - m.Eg/(m.Tref+m.dT))))

m.f4 = pyo.Expression(expr=m.Il+m.aIsc*(1-m.Adj/100)*m.dT - m.IoT*(pyo.exp( m.VocT/m.aT ) - 1 ) - m.VocT/m.Rsh)

m.a_Tc = pyo.Expression(m.Tc, rule=lambda t: m.a * m.Tc[t] / m.Tref)
m.Io_Tc = pyo.Expression(m.Tc, rule=lambda t: m.Io* ( m.Tc[t]/m.Tref)**3 * pyo.exp( 11600 * (m.Egref/m.Tref - m.Eg/m.Tc[t])))
m.Il_Tc = pyo.Expression(m.Tc, rule=lambda t: m.Il + (m.aIsc*(1-m.Adj/100))*(m.Tc[t]-m.Tref))
m.f_5 = pyo.Constraint(m.Tc, rule=lambda t: m.V_Tc[t] *( m.Io_Tc[t]/m.a_Tc[t]*pyo.exp( (m.V_Tc[t]+m.I_Tc[t]*m.Rs)/m.a_Tc[t] ) + 1/m.Rsh ) 
                       / ( 1 + m.Rs/m.Rsh + m.Io_Tc[t]*m.Rs/m.a_Tc[t]*pyo.exp( (m.V_Tc[t]+m.I_Tc[t]*m.Rs)/m.a_Tc[t] ) ) - m.I_Tc[t] == 0)
m.f_6 = pyo.Constraint(m.Tc, rule=lambda t: m.Il_Tc[t] - m.Io_Tc[t]*(pyo.exp( (m.V_Tc[t]+m.I_Tc[t]*m.Rs)/m.a_Tc[t] ) - 1) - (m.V_Tc[t] + m.I_Tc[t]*m.Rs)/m.Rsh - m.I_Tc[t])
m.Pmax_Tc = pyo.Expression(m.Tc, rule=lambda t: m.V_Tc[t] * m.I_Tc[t])

def gamma_rule(m, t):
    if t >= m.nTc:
        return pyo.Constraint.Skip
    return (m.Pmax_Tc[t]-m.Pmax_Tc[t-1])*100/(m.Vmp*m.Imp*(m.Tc[t]-m.Tc[t-1]))

m.gamma_Tc = pyo.Expression(m.Tc, rule=gamma_rule)
m.gamma = pyo.Expression(expr=sum(m.gamma_Tc[t] for t in m.Tc) / m.nTc)

m.f_7 = pyo.Constraint(expr=m.gamma - m.gPmp == 0)

# Sanity checks on current

m.Imp = pyo.Var(domain=pyo.NonNegativeReals)
m.f_8 = pyo.Constraint(expr=m.Il - m.Imp - m.Io * (pyo.exp((m.Vmp + m.Imp * m.Rs) / m.a) - 1.0) - (m.Vmp + m.Imp * m.Rs) / m.Rsh)

m.Ioc = pyo.Var(domain=pyo.NonNegativeReals)
m.f_9 = pyo.Constraint(expr=m.Il - m.Ioc - m.Io * (pyo.exp((m.Voc + m.Ioc * m.Rs) / m.a) - 1.0) - (m.Voc + m.Ioc * m.Rs) / m.Rsh)

# Sanity checks on slope
v_range = np.linspace(0.015 * m.Voc, 0.98 * m.Voc, 100)

filename = "/Users/dguittet/Projects/SAM/sam/samples/CEC Module and Inverter Libraries/CEC Modules/CEC Modules 2024-11-14/CEC Modules 2024-Nov-15_09-53.csv"
with open(filename, 'r') as f:
    
if Imp < Isc:
    raise ValueError

Vmp.set_value()
Imp.set_value()
Voc.set_value()
Isc.set_value()
bVoc.set_value()
aIsc.set_value()
gPmp.set_value()
Egref.set_value()
Tref.set_value()

