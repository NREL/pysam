from pytest import approx
import sys
from pathlib import Path
sys.path.append(str(Path(__file__).parent.parent))
from files.SixParSolve import *

def test_default_sam_cec_user():
    # SunPower SPR-E19-310-COM
    Vmp = 54.7
    Imp = 5.67
    Voc = 64.4
    Isc = 6.05
    bVoc = -0.175619
    aIsc = 0.00373527
    gamma = -0.386
    # Tref = 46 + 273.15
    Tref = 25 + 273.15

    a = 2.5776
    Il = 6.054
    Io = 8.360453e-11
    Rs = 3.081202e-01
    Rsh = 500.069
    Adj = 22.909

    model = create_model()
    m = model.solver
    m.Vmp.set_value(Vmp)
    m.Imp.set_value(Imp)
    m.Voc.set_value(Voc)
    m.Isc.set_value(Isc)
    m.bVoc.set_value(bVoc)
    m.aIsc.set_value(aIsc)
    m.gPmp.set_value(gamma)
    m.Tref.set_value(Tref)

    m.par.a.set_value(a)
    m.par.Il.set_value(Il)
    m.par.Io.set_value(Io)
    m.par.Rs.set_value(Rs)
    m.par.Rsh.set_value(Rsh)
    m.par.Adj.set_value(Adj)

    IL_oper, IO_oper, Rs, A_oper, Rsh_oper = cec_model_params_at_condition(m, 1000, 25+275.15)
    assert IL_oper == approx(6.059759, rel=1e-5) 
    assert IO_oper == approx(1.1674203993060455e-10, rel=1e-5) 
    assert Rs == approx(0.3081202, rel=1e-5) 
    assert A_oper == approx(2.5948906, rel=1e-5) 
    assert Rsh_oper == approx(500.069, rel=1e-5) 

    plot_iv_curve(m)


def test_cec_model_ivcurve_default():
    vmax = 64.4
    muIsc = 0.00287955
    EG = 1.12
    IL_oper = 6.05373
    IO_oper = 8.36045e-11
    Rs = 0.30812
    A_oper = 2.57764
    Rsh_oper = 500.069
    I_mp_ref = 5.67

    y_I = []

    V = np.linspace(0, vmax, 150)
    for i, v in enumerate(V):
        I = current_at_voltage_cec( v, IL_oper, IO_oper, Rs, A_oper, Rsh_oper, I_mp_ref )	
        y_I.append(I)

    assert V[1] == approx(0.43221, rel=1e-3) 
    assert V[-1] == approx(64.4, rel=1e-3) 
    assert y_I[0] == approx(6.05, rel=1e-3) 
    assert y_I[1] == approx(6.04913, rel=1e-3) 
    assert y_I[-1] == approx(5.770225265737295e-06, rel=1e-3) 

test_cec_model_ivcurve_default()
test_default_sam_cec_user()