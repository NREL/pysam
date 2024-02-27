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


m_wind = wind.from_existing(m_hybrid, "PVWattsWindBatteryHybridSingleOwner")
m_wind.Resource.wind_resource_filename = "/Users/dguittet/Projects/HybridSystems/HOPP/resource_files/wind/33.162_-83.8_windtoolkit_2013_60min_100m_120m.srw"
m_pv = pv.from_existing(m_hybrid, "PVWattsWindBatteryHybridSingleOwner")
m_pv.SolarResource.solar_resource_file = "/Users/dguittet/Projects/HybridSystems/HOPP/resource_files/solar/33.162_-83.8_psmv3_60_2013.csv"
m_batt = batt.from_existing(m_hybrid, "PVWattsWindBatteryHybridSingleOwner")

m_grid = grid.from_existing(m_hybrid, "PVWattsWindBatteryHybridSingleOwner")
m_so = so.from_existing(m_grid, "PVWattsWindBatteryHybridSingleOwner")

p_wind = m_wind.get_data_ptr()
p_pv = m_pv.get_data_ptr()
p_batt = m_batt.get_data_ptr()
p_hybrid = m_grid.get_data_ptr()

m_pv.AdjustmentFactors.constant = 0
m_wind.AdjustmentFactors.constant = 0




# ssc.data_set_string(p_pv, b'solar_resource_filename', b"/Users/dguittet/Projects/SAM/build/sam/SAMOSd.app/Contents/wind_resource/WY Southern-Flat Lands.srw")
print(ssc.data_get_string(p_pv, b'solar_resource_filename'))

# can't retrieve

# ssc.data_set_number(p_wind, b'analysis_period', 25)
# ssc.data_set_variable(p_wind, 'analysis_period', 25)
# ssc.data_set_number(p_wind, b'system_use_lifetime_output', 0)
# ssc.data_set_variable(p_wind, 'system_use_lifetime_output', 0)

# ssc.data_set_number(p_batt, b'system_capacity', m_batt.BatterySystem.batt_computed_bank_capacity)
# ssc.data_set_number(p_batt, b'om_batt_nameplate', m_batt.BatterySystem.batt_computed_bank_capacity)
ssc.data_set_variable(p_batt, 'system_capacity', m_batt.BatterySystem.batt_computed_bank_capacity)
ssc.data_set_variable(p_batt, 'om_batt_nameplate', m_batt.BatterySystem.batt_computed_bank_capacity)

batt_vars = ["om_batt_fixed_cost", "om_batt_variable_cost", "om_batt_capacity_cost"]
for v in batt_vars:
    # ssc.data_set_array(p_batt, v.encode("utf-8"), [0])
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
print("python ssc_data_get_table", ssc.pdll.ssc_data_get_table(c_ulong(input), b'pvwattsv8'))

ssc.data_set_table(input, b'windpower', p_wind)
ssc.data_set_table(input, b'battery', p_batt)
ssc.data_set_table(input, b'hybrid', p_hybrid)

techs = ["pvwattsv8", "windpower", 'battery', 'grid', 'singleowner']
# cmods = ssc.var_create()
# ssc.var_set_value(cmods, techs)
# ssc.data_set_var(input, b'compute_modules', cmods)
ssc.data_set_data_array(input, b'compute_modules', techs)

ssc.data_set_table(data, b'input', input)

print("data", data)

# module = ssc.module_create(b"hybrid")
# ssc.module_exec(module, data)

m_hybrid.execute(0)
m_hybrid.export()

input = ssc.pdll.ssc_data_get_table(c_ulong(data), b'input')
p_pv_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'pvwattsv8')
m_pv.set_data_ptr(p_pv_ret)
print(m_pv.Outputs.export().keys())

p_wind_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'windpower')
m_wind.set_data_ptr(p_wind_ret)
print(m_wind.Outputs.export().keys())

p_batt_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'battery')
m_batt.set_data_ptr(p_batt_ret)
print(m_batt.Outputs.export().keys())

p_grid_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'hybrid')
m_grid.set_data_ptr(p_grid_ret)
print(m_grid.Outputs.export().keys())

p_hybrid_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'hybrid')
m_so.set_data_ptr(p_hybrid_ret)
print(m_hybrid.Outputs.export().keys())

exit()
# ssc.data_free(data)

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
wind_resource_path = SSCDIR / "test/input_cases/general_data/WY_Southern-Flat_Lands.srw"

fin_vars = ['total_installed_cost', 'om_fixed', 'om_batt_fixed_cost', 'om_production', 'om_capacity', 'om_batt_capacity_cost',
            'om_fixed_escal', 'om_production_escal', 'om_capacity_escal', 'degradation']

m_wind = wind.new()
m_wind_fin = so.from_existing(m_wind)
m_wind.Resource.wind_resource_filename = str(wind_resource_path)
for k, v in defs['windpower'].items():
    try:
        m_wind.value(k, v)
    except:
        if k not in fin_vars and k not in fin_vars:
            defs_new['windpower'].pop(k)

m_pv = pv.new()
m_pv.SolarResource.solar_resource_file = str(solar_resource_path)
for k, v in defs['pvwattsv8'].items():
    try:
        m_pv.value(k, v)
    except:
        if k not in fin_vars and k not in fin_vars:
            defs_new['pvwattsv8'].pop(k)

# with open(nfc1, "w") as f:
    # json.dump({'input': defs_new}, f)

m_batt = batt.new()
p_batt = m_batt.get_data_ptr()

batt_vars = ["om_batt_fixed_cost", "om_batt_variable_cost", "om_batt_capacity_cost"]
for v in batt_vars:
    # ssc.data_set_array(p_batt, v.encode("utf-8"), [0])
    ssc.data_set_variable(p_batt, v, defs['battery'][v])

for k, v in defs['battery'].items():
    try:
        m_batt.value(k, v)
    except:
        if k not in batt_vars:
            if k not in fin_vars:
                defs_new['battery'].pop(k)


m_grid = grid.new()
m_so = so.from_existing(m_grid)
for k, v in defs['Hybrid'].items():
    print(k)
    if k in m_grid.GridLimits.__dir__():
        m_grid.value(k, v)
        continue
    try:
        m_so.value(k, v)
    except:
        # try:
            # m_grid.value(k, v)
        # except:
            # print(k)
        if k not in batt_vars:
            if k not in fin_vars:
                if 'total_installed_cost' not in k:
                    defs_new['Hybrid'].pop(k)

# with open(nfc1, "w") as f:
    # json.dump({'input': defs_new}, f)

p_wind = m_wind.get_data_ptr()
p_pv = m_pv.get_data_ptr()
p_hybrid = m_grid.get_data_ptr()

data = ssc.data_create()
input = ssc.data_create()

ssc.data_set_variable(p_batt, 'system_capacity', m_batt.BatterySystem.batt_computed_bank_capacity)
ssc.data_set_variable(p_batt, 'om_batt_nameplate', m_batt.BatterySystem.batt_computed_bank_capacity)


ptrs = [p_wind, p_pv, p_batt]
names = ['windpower', 'pvwattsv8', 'battery']
techs = ['wind', 'pv', 'battery']


for p, name, tech in zip(ptrs, names, techs):
    for v in fin_vars:
        if v != 'total_installed_cost':
            try:
                ssc.data_set_variable(p, v, defs[name][v])
            except:
                print(name, v)
        else:
            ssc.data_set_variable(p, v, defs['Hybrid'][tech + '_' + v])

print(ssc.data_get_number(p_pv, b'om_fixed_escal'))

ssc.data_set_table(input, b'pvwattsv8', p_pv)
print("python ssc_data_get_table", ssc.pdll.ssc_data_get_table(c_ulong(input), b'pvwattsv8'))

ssc.data_set_table(input, b'windpower', p_wind)
ssc.data_set_table(input, b'battery', p_batt)
ssc.data_set_table(input, b'hybrid', p_hybrid)

techs = ["pvwattsv8", "windpower", 'battery', 'grid', 'singleowner']
# cmods = ssc.var_create()
# ssc.var_set_value(cmods, techs)
# ssc.data_set_var(input, b'compute_modules', cmods)
ssc.data_set_data_array(input, b'compute_modules', techs)

ssc.data_set_table(data, b'input', input)

print("data", data)

# module = ssc.module_create(b"hybrid")
# ssc.module_exec(module, data)

m_hybrid = hybrid.wrap(data)
m_hybrid.execute(0)
m_hybrid.export()

input = ssc.pdll.ssc_data_get_table(c_ulong(data), b'input')
p_pv_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'pvwattsv8')
m_pv.set_data_ptr(p_pv_ret)
print(m_pv.Outputs.export().keys())

p_wind_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'windpower')
m_wind.set_data_ptr(p_wind_ret)
print(m_wind.Outputs.export().keys())

p_batt_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'battery')
m_batt.set_data_ptr(p_batt_ret)
print(m_batt.Outputs.export().keys())

p_grid_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'hybrid')
m_grid.set_data_ptr(p_grid_ret)
print(m_grid.Outputs.export().keys())

p_hybrid_ret = ssc.pdll.ssc_data_get_table(c_ulong(input), b'hybrid')
m_grid.set_data_ptr(p_hybrid_ret)
m_so.set_data_ptr(p_hybrid_ret)
print(m_so.Outputs.export().keys())

import pprint
batt_dict = m_batt.export()
batt_dict.pop("Outputs")
pretty_json_str = pprint.pformat(batt_dict, compact=True).replace("'",'"')
with open("batt1.json", 'w') as f:
    # f.write(pretty_json_str)
    json.dump(batt_dict, f)

pvannualenergy = m_pv.Outputs.annual_energy
windannualenergy = m_wind.Outputs.annual_energy
battannualenergy = m_batt.value("annual_energy")
npv = m_so.Outputs.project_return_aftertax_npv

pvannualenergy == pytest.approx(25970, 1e-2)
windannualenergy == pytest.approx(5927, 1e-2)
battannualenergy == pytest.approx(592318937, 1e-2)
npv == pytest.approx(-61506, 1e-2)

