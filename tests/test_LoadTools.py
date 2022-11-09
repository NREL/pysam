import pytest

from PySAM.LoadTools import get_monthly_peaks

def test_monthly_load_hourly():
    steps_per_hour = 1
    load = [100] * 8760 * steps_per_hour

    # Increase load in July, August
    jul_hr = 5080
    aug_hr = 5830
    load[jul_hr * steps_per_hour] = 200
    load[aug_hr * steps_per_hour] = 300

    peaks = get_monthly_peaks(load, steps_per_hour)

    assert(peaks[0] == 100)
    assert(peaks[6] == 200)
    assert(peaks[7] == 300)
    assert(peaks[8] == 100)

