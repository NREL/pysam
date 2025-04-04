import pytest
from pathlib import Path
import PySAM.GeothermalCosts as getem


def test_geothermal_costs():
    baseline_cost = 1
    drilling_cost = 1
    field_gathering_system_cost = 1
    num_wells = 1
    water_loss = 1
    total_installed_cost = 1
    pump_cost_install = 1
    pump_only_cost = 1
    pump_type = 1
    pump_depth = 1

    sys = getem.new()
    sys.GeoHourly.gross_output = 1
    sys.GeoHourly.conversion_type = 1
    sys.GeoHourly.ppi_base_year = 1
    sys.GeoHourly.cwflow = 1
    sys.GeoHourly.GF_flowrate = 1

    total_getem_om_cost = sys.getem_om_cost_calc(baseline_cost=baseline_cost,
                                                drilling_cost=drilling_cost,
                                                field_gathering_system_cost=field_gathering_system_cost,
                                                num_wells=num_wells,
                                                water_loss=water_loss,
                                                total_installed_cost=total_installed_cost,
                                                pump_cost_install=pump_cost_install,
                                                pump_only_cost=pump_only_cost,
                                                pump_type=pump_type,
                                                pump_depth=pump_depth)

    assert(int(total_getem_om_cost) == 110050)
