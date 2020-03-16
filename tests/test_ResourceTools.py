import pytest
from pathlib import Path

import PySAM.ResourceTools as tools
import PySAM.Windpower as wp


def test_solar():
    solar = str(Path(__file__).parent / "blythe_ca_33.617773_-114.588261_psmv3_60_tmy.csv")
    data = tools.TMY_CSV_to_solar_data(solar)
    assert(data['lat'] == 33.61)
    assert(data['lon'] == -114.58)
    assert(data['dn'][7] == 262)
    assert(data['df'][7] == 16)
    assert(data['gh'][7] == 27)
    assert(data['tdry'][7] == pytest.approx(8.96, 0.1))


def test_wind():
    wind = str(Path(__file__).parent / "AR Northwestern-Flat Lands.srw")
    data = tools.SRW_to_wind_data(wind)
    assert(data['fields'] == [1, 2, 4, 3, 1, 2, 4, 3, 1, 2, 4, 3, 1, 2, 4, 3])
    assert(data['heights'] == [50, 50, 50, 50, 80, 80, 80, 80, 110, 110, 110, 110, 140, 140, 140, 140])
    assert(data['data'][0] == [9.587, 0.953420183, 173, 9.466, 10.247, 0.950086356, 174, 11.637, 10.627, 0.946649889,
                               175, 13.249, 10.997, 0.94340982, 175, 14.509])

    wind_model = wp.new()
    wind_model.Resource.wind_resource_data = data
    returned_data = wind_model.Resource.wind_resource_data['data'][0]
    for i, d in enumerate(data['data'][0]):
        assert(d == pytest.approx(returned_data[i], 1e-3))
