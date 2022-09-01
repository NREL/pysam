import pytest
from pympler.tracker import SummaryTracker
from pathlib import Path
import PySAM.Pvwattsv8 as pv
import PySAM.Battwatts as bt
import PySAM.Utilityrate5 as ur
import PySAM.Pvsamv1 as pvsam
import PySAM.Battery as stbt


@pytest.fixture
def solar_resource():
    return str(Path(__file__).parent / "blythe_ca_33.617773_-114.588261_psmv3_60_tmy.csv")


def test_reopt_sizing_pvwatts(solar_resource):
    round = 0

    tracker = SummaryTracker()
    while round < 25:   # multiple runs required to check for memory leaks
        round += 1

        sys = pv.default("PVWattsBatteryCommercial")
        sys.SolarResource.solar_resource_file = solar_resource
        batt = bt.from_existing(sys, "PVWattsBatteryCommercial")
        sys.SolarResource.solar_resource_data = dict({'lat': 3, 'lon': 3})
        batt.Battery.crit_load = [0] * 8760
        fin = ur.from_existing(sys, "PVWattsBatteryCommercial")

        post = sys.Reopt_size_battery_post()

    assert('Scenario' in post['reopt_post'])
    assert(post['reopt_post']['Scenario']['Site']['latitude'] == pytest.approx(3, 0.1))
    tracker_diff = tracker.diff()
    tracker.print_diff()


def test_reopt_sizing_pvsam(solar_resource):
    import PySAM.Utilityrate5 as ur
    sys = pvsam.default("FlatPlatePVCommercial")
    fin = ur.from_existing(sys, "FlatPlatePVCommercial")
    bt = stbt.from_existing(sys, "GenericBatteryCommercial")

    sys.SolarResource.use_wf_albedo = 0
    sys.SolarResource.solar_resource_file = solar_resource
    bt.Load.crit_load = [0] * 8760
    post = sys.Reopt_size_battery_post()

    assert('Scenario' in post['reopt_post'])
    assert(post['reopt_post']['Scenario']['Site']['latitude'] == pytest.approx(33.6, 0.1))

