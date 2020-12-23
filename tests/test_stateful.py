from pytest import approx

import PySAM.BatteryStateful as bt


def test_stateful():
    b = bt.default("NMCGraphite")
    b.Controls.control_mode = 1
    b.Controls.dt_hr = 1
    b.ParamsCell.minimum_SOC = 10
    b.ParamsCell.maximum_SOC = 90
    b.ParamsCell.initial_SOC = 50
    b.Controls.input_power = 0
    b.setup()
    assert(b.StatePack.SOC == approx(50))

    b.Controls.input_power = 0.5
    b.execute(0)
    assert(b.StatePack.SOC == approx(45.9993))


