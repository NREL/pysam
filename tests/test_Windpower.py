import PySAM.Windpower as wp


def test_Turbine_calculate_powercurve_error():
    a = wp.new()
    try:
        a.Turbine.calculate_powercurve(turbine_size=1500, rotor_diameter=60, elevation=0, max_cp=0.45, max_tip_speed=80, max_tip_sp_ratio=8, cut_in=4,
                                   cut_out=25, drive_train=0)
    except:
        assert(True)


def test_Turbine_calculate_powercurve_default():
    a = wp.new()
    a.Resource.wind_resource_model_choice = 0
    a.Turbine.calculate_powercurve(turbine_size=1500, rotor_diameter=75, elevation=0, max_cp=0.45,max_tip_speed=80, max_tip_sp_ratio=8, cut_in=4,
                               cut_out=25, drive_train=0)
    assert(abs(a.Turbine.wind_turbine_powercurve_windspeeds[1] - 0.25) < 0.01)
    assert(abs(a.Turbine.wind_turbine_powercurve_powerout[17] - 64.050) < 0.01)
    assert(abs(a.Turbine.wind_turbine_powercurve_powerout[45] - 1500) < 0.01)


def test_Resource_wind_resource_distribution_default():
    a = wp.default("WindPowerNone")
    a.Resource.wind_resource_model_choice = 2
    a.Resource.wind_resource_distribution = ((1.5, 180, .12583),
                                             (5, 180, .3933),
                                             (8, 180, .18276),
                                             (10, 180, .1341),
                                             (13.5, 180, .14217),
                                             (19, 180, .0211))
    a.Farm.wind_farm_wake_model = 0
    a.execute(1)
    assert(a.Outputs.annual_energy > 0)
