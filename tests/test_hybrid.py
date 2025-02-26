import pytest
from pathlib import Path
import os
import json

from PySAM.Hybrids import *
import PySAM.Battery as batt
import PySAM.Windpower as wind
import PySAM.Pvwattsv8 as pv
import PySAM.Pvsamv1 as pvsam
import PySAM.CustomGeneration as custom
import PySAM.Fuelcell as fuelcell
import PySAM.Singleowner as so
import PySAM.HostDeveloper as hd
import PySAM.Utilityrate5 as ur
from PySAM.Hybrids.HybridSystem import HybridSystem


test_dir = Path(__file__).parent
solar_resource_path = test_dir / "phoenix_az_33.450495_-111.983688_psmv3_60_tmy.csv"
wind_resource_path = test_dir / "AZ Eastern-Rolling Hills.srw"

def test_PhotovoltaicWindBatteryHybridSingleOwner():
    m = HybridSystem([pvsam, wind, batt], 'singleowner')
    m.default("PhotovoltaicWindBatteryHybridSingleOwner")
    m.pv.SolarResource.solar_resource_file = str(solar_resource_path)
    m.wind.Resource.wind_resource_filename = str(wind_resource_path)

    m.execute()

    pvannualenergy = m.pv.Outputs.annual_energy
    windannualenergy = m.wind.Outputs.annual_energy
    battannualenergy = m.battery.value("annual_energy")
    npv = m.singleowner.Outputs.project_return_aftertax_npv

    assert pvannualenergy == pytest.approx(235721657, 1e-2)
    assert windannualenergy == pytest.approx(366975555, 1e-2)
    assert battannualenergy == pytest.approx(598789802, 1e-2)
    assert npv == pytest.approx(-154982178, 1e-2)


def test_PVWattsv8WindBatterySingleOwner():
    nfc1 = test_dir / "PVWatts Wind Battery Hybrid_Single Owner.json"

    with open(nfc1, "r") as f:
        defs = json.load(f)['input']

    m = HybridSystem([pv, wind, batt], 'singleowner')
    m.new()
    m.pvwatts.SolarResource.solar_resource_file = str(solar_resource_path)
    m.wind.Resource.wind_resource_filename = str(wind_resource_path)

    unassigned = m.assign(defs)
    assert len(unassigned) <= 4

    m.execute()

    pvannualenergy = m.pvwatts.Outputs.annual_energy
    windannualenergy = m.wind.Outputs.annual_energy
    battannualenergy = m.battery.value("annual_energy")
    npv = m.singleowner.Outputs.project_return_aftertax_npv

    assert pvannualenergy == pytest.approx(211907455, 1e-2)
    assert windannualenergy == pytest.approx(366975552, 1e-2)
    assert battannualenergy == pytest.approx(570565000, 1e-2)
    assert npv == pytest.approx(-227222606, 1e-2)


def test_PVWattsv8WindBatteryHostDeveloper():
    nfc1 = test_dir / "PVWatts Wind Battery Hybrid_Host Developer.json"

    with open(nfc1, "r") as f:
        defs = json.load(f)['input']

    m = HybridSystem([pv, wind, batt], 'hostdeveloper')
    m.new()
    m.pvwatts.SolarResource.solar_resource_file = str(solar_resource_path)
    m.wind.Resource.wind_resource_filename = str(wind_resource_path)

    unassigned = m.assign(defs)
    assert len(unassigned) <= 4

    m.execute()

    pvannualenergy = m.pvwatts.Outputs.annual_energy
    windannualenergy = m.wind.Outputs.annual_energy
    battannualenergy = m.battery.value("annual_energy")
    npv = m.host_developer.Outputs.project_return_aftertax_npv

    assert pvannualenergy == pytest.approx(938557, 1e-2)
    assert windannualenergy == pytest.approx(187767, 1e-2)
    assert battannualenergy == pytest.approx(1118877, 1e-2)
    assert npv == pytest.approx(-168769, 1e-2)

def test_GenericPVWattsWindFuelCellBatteryHybrid_SingleOwner():
    nfc1 = test_dir / "Generic PVWatts Wind FuelCell Battery Hybrid_Single Owner.json"

    with open(nfc1, "r") as f:
        defs = json.load(f)['input']

    m = HybridSystem([custom, pv, wind, fuelcell, batt], 'singleowner')
    m.new()
    m.pvwatts.SolarResource.solar_resource_file = str(solar_resource_path)
    m.wind.Resource.wind_resource_filename = str(wind_resource_path)

    unassigned = m.assign(defs)
    assert len(unassigned) <= 6

    m.execute()

    customannualenergy = m.custom.Outputs.annual_energy
    pvannualenergy = m.pvwatts.Outputs.annual_energy
    windannualenergy = m.wind.Outputs.annual_energy
    battannualenergy = m.battery.value("annual_energy")
    npv = m.singleowner.Outputs.project_return_aftertax_npv

    assert customannualenergy == pytest.approx(756864000, 1e-2)
    assert pvannualenergy == pytest.approx(211907456, 1e-2)
    assert windannualenergy == pytest.approx(366975552, 1e-2)
    assert battannualenergy == pytest.approx(1331720000, 1e-2)
    assert npv == pytest.approx(-1748593536, 1e-2)
