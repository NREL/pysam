import PySAM.Battery as batt
import PySAM.Pvwattsv8 as pv
import PySAM.Hybrid as hybrid
import PySAM.Windpower as wind
import PySAM.Singleowner as so
import PySAM.Grid as grid
from PySAM.PySSC import PySSC
from ctypes import *
import pytest

ssc = PySSC()
ssc.pdll.ssc_data_get_table.restype = c_long
ssc.pdll.ssc_data_create.restype = c_long
ssc.pdll.ssc_var_get_number.restype = POINTER(c_float)

data = ssc.data_create()
input = ssc.data_create()
m_hybrid = hybrid.wrap(data)

m_wind = wind.default("PVWattsWindBatteryHybridSingleOwner")
m_wind.Resource.wind_resource_filename = "/Users/dguittet/Projects/HybridSystems/HOPP/resource_files/wind/33.162_-83.8_windtoolkit_2013_60min_100m_120m.srw"

m_pv = pv.default("PVWattsWindBatteryHybridSingleOwner")
m_pv.SolarResource.solar_resource_file = "/Users/dguittet/Projects/HybridSystems/HOPP/resource_files/solar/33.162_-83.8_psmv3_60_2013.csv"

m_batt = batt.default("PVWattsWindBatteryHybridSingleOwner")

m_grid = grid.default("PVWattsWindBatteryHybridSingleOwner")
m_so = so.from_existing(m_grid, "PVWattsWindBatteryHybridSingleOwner")

p_wind = m_wind.get_data_ptr()
p_pv = m_pv.get_data_ptr()
p_batt = m_batt.get_data_ptr()
p_hybrid = m_grid.get_data_ptr()

m_pv.AdjustmentFactors.constant = 0
m_wind.AdjustmentFactors.constant = 0


ssc.data_set_variable(p_batt, 'system_capacity', m_batt.BatterySystem.batt_computed_bank_capacity)
ssc.data_set_variable(p_batt, 'om_batt_nameplate', m_batt.BatterySystem.batt_computed_bank_capacity)

batt_vars = ["om_batt_fixed_cost", "om_batt_variable_cost", "om_batt_capacity_cost"]
for v in batt_vars:
    ssc.data_set_variable(p_batt, v, [0])

ptrs = [p_wind, p_pv, p_batt]
fin_vars = ['total_installed_cost', 'om_fixed', 'om_production', 'om_capacity',
            'om_fixed_escal', 'om_production_escal', 'om_capacity_escal', 'degradation']

for p in ptrs:
    for v in fin_vars:
        if 'om' in v and 'escal' not in v:
            ssc.data_set_variable(p, v, [0])
        elif v == 'degradation': 
            ssc.data_set_variable(p, v, [0])
        else:
            ssc.data_set_variable(p, v, 0)

ssc.data_set_table(input, b'pvwattsv8', p_pv)

ssc.data_set_table(input, b'windpower', p_wind)
ssc.data_set_table(input, b'battery', p_batt)
ssc.data_set_table(input, b'hybrid', p_hybrid)

techs = ["pvwattsv8", "windpower", 'battery', 'grid', 'singleowner']
ssc.data_set_data_array(input, b'compute_modules', techs)

ssc.data_set_table(data, b'input', input)

m_hybrid.execute(0)
m_hybrid.export()

input = ssc.pdll.ssc_data_get_table(c_ulong(data), b'input')
p_pv_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'pvwattsv8')
m_pv.set_data_ptr(p_pv_ret)

p_wind_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'windpower')
m_wind.set_data_ptr(p_wind_ret)

p_batt_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'battery')
m_batt.set_data_ptr(p_batt_ret)

p_grid_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'hybrid')
m_grid.set_data_ptr(p_grid_ret)

p_hybrid_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'hybrid')
m_so.set_data_ptr(p_hybrid_ret)

for m in [m_wind, m_pv, m_batt, m_grid]:
    m.set_data_ptr(0)

m_hybrid = None

# exit()

# Test 1
print("Test 1")

import os
from pathlib import Path
import json
from copy import deepcopy

SSCDIR = Path(os.getenv("SSCDIR"))
nfc1 = SSCDIR / "test/input_json/hybrids/PVWatts Wind Battery Hybrid_Single Owner.json"

with open(nfc1, "r") as f:
    defs = json.load(f)['input']

defs_new = deepcopy(defs)

solar_resource_path = SSCDIR / "test/input_cases/general_data/phoenix_az_33.450495_-111.983688_psmv3_60_tmy.csv"
wind_resource_path = SSCDIR / "test/input_cases/general_data/AZ Eastern-Rolling Hills.srw"

fin_vars = ['total_installed_cost', 'om_fixed', 'om_batt_fixed_cost', 'om_production', 'om_capacity', 'om_batt_capacity_cost',
            'om_fixed_escal', 'om_production_escal', 'om_capacity_escal', 'degradation']

def modify_adjust(k):
    if k.split('_')[0] == 'adjust':
        return k.split('adjust_')[1]
    return k

data = ssc.data_create()
input = ssc.data_create()
m_hybrid = hybrid.wrap(data)

m_wind = wind.new()
for k, v in defs['windpower'].items():
    try:
        k = modify_adjust(k)
        m_wind.value(k, v)
    except:
        print(k)
m_wind.Resource.wind_resource_filename = str(wind_resource_path)

m_pv = pv.new()
for k, v in defs['pvwattsv8'].items():
    try:
        k = modify_adjust(k)
        m_pv.value(k, v)
    except:
        print(k)
m_pv.SolarResource.solar_resource_file = str(solar_resource_path)

m_batt = batt.new()
p_batt = m_batt.get_data_ptr()

batt_vars = ["om_batt_fixed_cost", "om_batt_variable_cost", "om_batt_capacity_cost"]
for v in batt_vars:
    ssc.data_set_variable(p_batt, v, defs['battery'][v])

for k, v in defs['battery'].items():
    try:
        k = modify_adjust(k)
        m_batt.value(k, v)
    except:
        print(k)


m_grid = grid.new()
m_so = so.from_existing(m_grid)
for k, v in defs['hybrid'].items():
    if k in m_grid.GridLimits.__dir__():
        m_grid.value(k, v)
        continue
    try:
        m_so.value(k, v)
    except:
        print(k)


p_wind = m_wind.get_data_ptr()
p_pv = m_pv.get_data_ptr()
p_hybrid = m_grid.get_data_ptr()

ssc.data_set_variable(p_batt, 'system_capacity', m_batt.BatterySystem.batt_computed_bank_capacity)
ssc.data_set_variable(p_batt, 'om_batt_nameplate', m_batt.BatterySystem.batt_computed_bank_capacity)


ptrs = [p_wind, p_pv, p_batt]
names = ['windpower', 'pvwattsv8', 'battery']
techs = ['wind', 'pv', 'battery']

print(ssc.data_get_number(p_pv, b'om_fixed_escal'))

ssc.data_set_table(input, b'pvwattsv8', p_pv)
print("python ssc_data_get_table", ssc.pdll.ssc_data_get_table(c_ulong(input), b'pvwattsv8'))

ssc.data_set_table(input, b'windpower', p_wind)
ssc.data_set_table(input, b'battery', p_batt)
ssc.data_set_table(input, b'hybrid', p_hybrid)

techs = ["pvwattsv8", "windpower", 'battery', 'grid', 'singleowner']
ssc.data_set_data_array(input, b'compute_modules', techs)

ssc.data_set_table(data, b'input', input)

m_hybrid.execute(0)
m_hybrid.export()

input = ssc.pdll.ssc_data_get_table(c_ulong(data), b'input')
p_pv_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'pvwattsv8')
m_pv.set_data_ptr(p_pv_ret)

p_wind_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'windpower')
m_wind.set_data_ptr(p_wind_ret)

p_batt_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'battery')
m_batt.set_data_ptr(p_batt_ret)

p_grid_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'hybrid')
m_grid.set_data_ptr(p_grid_ret)

p_hybrid_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'hybrid')
m_grid.set_data_ptr(p_hybrid_ret)
m_so.set_data_ptr(p_hybrid_ret)

pvannualenergy = m_pv.Outputs.annual_energy
windannualenergy = m_wind.Outputs.annual_energy
battannualenergy = m_batt.value("annual_energy")
npv = m_so.Outputs.project_return_aftertax_npv

assert pvannualenergy == pytest.approx(211907455, 1e-2)
assert windannualenergy == pytest.approx(366975552, 1e-2)
assert battannualenergy == pytest.approx(570565000, 1e-2)
assert npv == pytest.approx(-242777472, 1e-2)

for m in [m_wind, m_pv, m_batt, m_grid]:
    m.set_data_ptr(0)
    
m_hybrid = None

# Test 2
import PySAM.Utilityrate5 as ur
import PySAM.HostDeveloper as hd

print("Test 2")

nfc1 = SSCDIR / "test/input_json/hybrids/PVWatts Wind Battery Hybrid_Host Developer.json"

with open(nfc1, "r") as f:
    defs = json.load(f)['input']

defs_new = deepcopy(defs)

data = ssc.data_create()
input = ssc.data_create()
m_hybrid = hybrid.wrap(data)

m_wind = wind.new()
for k, v in defs['windpower'].items():
    try:
        k = modify_adjust(k)
        m_wind.value(k, v)
    except:
        print(k)
m_wind.Resource.wind_resource_filename = str(wind_resource_path)

m_pv = pv.new()
for k, v in defs['pvwattsv8'].items():
    try:
        k = modify_adjust(k)
        m_pv.value(k, v)
    except:
        print(k)
m_pv.SolarResource.solar_resource_file = str(solar_resource_path)

m_batt = batt.new()
p_batt = m_batt.get_data_ptr()

batt_vars = ["om_batt_fixed_cost", "om_batt_variable_cost", "om_batt_capacity_cost"]
for v in batt_vars:
    ssc.data_set_variable(p_batt, v, defs['battery'][v])

for k, v in defs['battery'].items():
    try:
        k = modify_adjust(k)
        m_batt.value(k, v)
    except:
        print(k)

m_grid = grid.new()

m_ur = ur.from_existing(m_grid)
m_hd = hd.from_existing(m_grid)
for k, v in defs['hybrid'].items():
    if k in m_grid.GridLimits.__dir__() or k in m_grid.Load.__dir__():
        m_grid.value(k, v)
    elif k in m_ur.ElectricityRates.__dir__() or k in m_ur.Lifetime.__dir__() or k in m_ur.SystemOutput.__dir__():
        m_ur.value(k, v)
    else:
        try:
            m_hd.value(k, v)
        except:
            print(k)

p_wind = m_wind.get_data_ptr()
p_pv = m_pv.get_data_ptr()
p_hybrid = m_grid.get_data_ptr()


ssc.data_set_variable(p_batt, 'system_capacity', m_batt.BatterySystem.batt_computed_bank_capacity)
ssc.data_set_variable(p_batt, 'om_batt_nameplate', m_batt.BatterySystem.batt_computed_bank_capacity)


ptrs = [p_wind, p_pv, p_batt]
names = ['windpower', 'pvwattsv8', 'battery']
techs = ['wind', 'pv', 'battery']

ssc.data_set_table(input, b'pvwattsv8', p_pv)

ssc.data_set_table(input, b'windpower', p_wind)
ssc.data_set_table(input, b'battery', p_batt)
ssc.data_set_table(input, b'hybrid', p_hybrid)

techs = ["pvwattsv8", "windpower", 'battery', 'grid', 'utilityrate5', 'host_developer']
ssc.data_set_data_array(input, b'compute_modules', techs)

ssc.data_set_table(data, b'input', input)

m_hybrid.execute(0)
m_hybrid.export()

input = ssc.pdll.ssc_data_get_table(c_ulong(data), b'input')
p_pv_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'pvwattsv8')
m_pv.set_data_ptr(p_pv_ret)

p_wind_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'windpower')
m_wind.set_data_ptr(p_wind_ret)

p_batt_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'battery')
m_batt.set_data_ptr(p_batt_ret)

p_grid_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'hybrid')
m_grid.set_data_ptr(p_grid_ret)

p_hybrid_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'hybrid')
m_grid.set_data_ptr(p_hybrid_ret)
m_so.set_data_ptr(p_hybrid_ret)

pvannualenergy = m_pv.Outputs.annual_energy
windannualenergy = m_wind.Outputs.annual_energy
battannualenergy = m_batt.value("annual_energy")
npv = m_so.Outputs.project_return_aftertax_npv

assert pvannualenergy == pytest.approx(938557, 1e-2)
assert windannualenergy == pytest.approx(187767, 1e-2)
assert npv == pytest.approx(-174953, 1e-2)

for m in [m_wind, m_pv, m_batt, m_grid]:
    m.set_data_ptr(0)
