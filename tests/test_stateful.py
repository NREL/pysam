from pytest import approx

import PySAM.BatteryStateful as bt


def test_stateful_nmc():
    b = bt.default("NMCGraphite")
    b.Controls.control_mode = 1
    b.Controls.dt_hr = 1
    b.ParamsCell.minimum_SOC = 10
    b.ParamsCell.maximum_SOC = 90
    b.ParamsCell.initial_SOC = 50
    b.Controls.input_power = 0
    b.ParamsCell.life_model = 1
    b.setup()
    assert (b.StatePack.SOC == approx(50))

    b.Controls.input_power = 0.5
    b.execute(0)
    assert (b.StatePack.SOC == approx(44.811, 1e-2))
    assert (b.StateCell.DOD_max == approx(0.5518, 1e-2))


def test_stateful_lead():
    b = bt.default("LeadAcid")
    b.Controls.control_mode = 1
    b.Controls.dt_hr = 1
    b.ParamsCell.minimum_SOC = 10
    b.ParamsCell.maximum_SOC = 90
    b.ParamsCell.initial_SOC = 50
    b.Controls.input_power = 0
    b.setup()
    assert (b.StatePack.SOC == approx(50))

    b.Controls.input_power = 0.5
    b.execute(0)
    assert (b.StatePack.SOC == approx(11.77, 1e-2))


def test_stateful_from_data():
    b = bt.new()
    d = {'Controls': {'control_mode': 1.0, 'dt_hr': 0.016666666666666666, 'input_power': 0.0},
         'ParamsCell': {'C_rate': 0.2, 'Qexp': 2.584, 'Qfull': 3.2, 'Qnom': 3.126, 'Vexp': 3.53, 'Vfull': 4.2,
                        'Vnom': 3.342, 'Vcut': 0, 'Vnom_default': 3.6, 'life_model': 1, 'chem': 1.0,
                        'cycling_matrix': ((10.0, 0.0, 100.85333333333334), (10.0, 1250.0, 94.88402967051991),
                                           (10.0, 2500.0, 88.91472600735459), (10.0, 3750.0, 82.94542234383735),
                                           (10.0, 5000.0, 76.97611867996821), (20.0, 0.0, 100.85333333333334),
                                           (20.0, 1250.0, 94.87983534903533), (20.0, 2500.0, 88.90633717426442),
                                           (20.0, 3750.0, 82.93283880899575), (20.0, 5000.0, 76.95934025320447),
                                           (40.0, 0.0, 100.85333333333334), (40.0, 1250.0, 94.78221121806645),
                                           (40.0, 2500.0, 88.71098572007159), (40.0, 3750.0, 82.63965652437861),
                                           (40.0, 5000.0, 76.56822331441485), (80.0, 0.0, 100.85333333333334),
                                           (80.0, 1250.0, 92.48380979037378), (80.0, 2500.0, 84.0542799046757),
                                           (80.0, 3750.0, 75.5600050138485), (80.0, 5000.0, 66.99558786034476),
                                           (100.0, 0.0, 100.85333333333334), (100.0, 1250.0, 88.12558851005116),
                                           (100.0, 2500.0, 74.87324171194942), (100.0, 3750.0, 60.95107257220129),
                                           (100.0, 5000.0, 46.13117125424217)), 'initial_SOC': 50.0,
                        'maximum_SOC': 90.0, 'minimum_SOC': 10.0, 'resistance': 0.001155, 'voltage_choice': 0.0},
         'ParamsPack': {'Cp': 1500.0, 'T_room_init': 12.717792686395654,
                        'cap_vs_temp': ((0.0, 80.2), (23.0, 100.0), (30.0, 103.1), (45.0, 105.4)), 'h': 7.5,
                        'mass': 6470.406178696914, 'nominal_energy': 653.5763816865569, 'nominal_voltage': 500.0,
                        'surface_area': 33.602970087562625}, 'StatePack': {}, 'StateCell': {}}
    dd = dict()
    for gr, vr in d.items():
        for k, v in vr.items():
            dd[k] = v
    b.assign(d)
    b.setup()
    assert b.Controls.control_mode == 1
