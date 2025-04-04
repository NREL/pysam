import os
import sys
import pytest
from pathlib import Path
import glob
import importlib
import PySAM.CustomGeneration as CustomGeneration
import PySAM.Pvsamv1 as pvsamv1
import PySAM.Battery as battery
from pympler.tracker import SummaryTracker
from PySAM.PySSC import PySSC
import PySAM.WaveFileReader as wavefile

ssc = PySSC()

check_error_cases = True

def test_adjustment_factors():
    m = CustomGeneration.new()
    adj = m.AdjustmentFactors
    adj.adjust_constant = 0
    adj.adjust_en_timeindex = 0
    adj.adjust_timeindex = [0]
    adj.adjust_en_periods = 0
    adj.adjust_periods = [[0, 0]]
    adj.adjust_en_timeindex = 0
    adj.adjust_timeindex = [0]

    m = battery.new()
    adj = m.AdjustmentFactors
    adj.batt_adjust_constant = 0
    adj.batt_adjust_en_timeindex = 0
    adj.batt_adjust_timeindex = [0]
    adj.batt_adjust_en_periods = 0
    adj.batt_adjust_periods = [[0, 0]]
    adj.batt_adjust_en_timeindex = 0
    adj.batt_adjust_timeindex = [0]

    m = pvsamv1.new()
    adj = m.AdjustmentFactors
    adj.dc_adjust_constant = 0
    adj.dc_adjust_en_timeindex = 0
    adj.dc_adjust_timeindex = [0]
    adj.dc_adjust_en_periods = 0
    adj.dc_adjust_periods = [[0, 0]]
    adj.dc_adjust_en_timeindex = 0
    adj.dc_adjust_timeindex = [0]
    adj.export()

@pytest.mark.parametrize("execution_number", range(10))
def test_pyssc(execution_number: int):
    var = ssc.var_create()
    ssc.var_set_value(var, 0)
    assert int(ssc.var_get_number(var)) == 0
    test_dat = ssc.data_create()
    ssc.data_set_var(test_dat, b"test", var)
    ssc.var_free(var)
    ssc.data_free(test_dat)

    var = ssc.var_create()
    ssc.var_set_value(var, 'zero')
    assert ssc.var_get_string(var) == b'zero'
    test_dat = ssc.data_create()
    ssc.data_set_var(test_dat, b"test", var)
    assert ssc.data_get_string(test_dat, b"test") == b"zero"
    ssc.var_free(var)
    ssc.data_free(test_dat)

    var = ssc.var_create()
    ssc.var_set_value(var, [0, 1])
    assert ssc.var_get_array(var) == [0, 1]
    test_dat = ssc.data_create()
    ssc.data_set_var(test_dat, b"test", var)
    assert ssc.data_get_array(test_dat, b"test") == [0, 1]
    ssc.var_free(var)
    ssc.data_free(test_dat)

    var = ssc.var_create()
    ssc.var_set_value(var, [[0, 0], [1, 1]])
    assert ssc.var_get_matrix(var) == [[0, 0], [1, 1]]
    test_dat = ssc.data_create()
    ssc.data_set_var(test_dat, b"test", var)
    assert ssc.data_get_matrix(test_dat, b"test") == [[0, 0], [1, 1]]
    ssc.var_free(var)
    ssc.data_free(test_dat)

    var = ssc.var_create()
    ssc.var_set_value(var, ["zero", "one"])
    assert ssc.var_get_data_array(var, 0, ssc.STRING) == b"zero"
    assert ssc.var_get_data_array(var, 1, ssc.STRING) == b"one"
    test_dat = ssc.data_create()
    ssc.data_set_var(test_dat, b"test", var)
    var0 = ssc.data_get_data_array(test_dat, b"test", [ssc.STRING, ssc.STRING])
    assert var0 == [b"zero", b"one"]
    ssc.var_free(var)
    ssc.data_free(test_dat)

    var = ssc.var_create()
    ssc.var_set_value(var, [["zero", "one"], ["zero", "one"]])
    assert ssc.var_get_data_matrix(var, 0, 0, ssc.STRING) == b"zero"
    assert ssc.var_get_data_matrix(var, 1, 1, ssc.STRING) == b"one"
    test_dat = ssc.data_create()
    ssc.data_set_var(test_dat, b"test", var)
    var0 = ssc.data_get_data_matrix(test_dat, b"test", [[ssc.STRING, ssc.STRING], [ssc.STRING, ssc.STRING]])
    assert var0 == [[b'zero', b'one'], [b'zero', b'one']]
    ssc.var_free(var)
    ssc.data_free(test_dat)


def test_functionality():
    n_tests_passed = 0
    round = 0

    while round < 50:   # multiple runs required to check for memory leaks
        if round == 0:
            tracker = SummaryTracker()

        round += 1

        a = CustomGeneration.new()
        b = a.Plant

        # Test setting values with correct types

        a.Plant.derate = 1
        assert (a.Plant.derate == 1)
        assert (b.derate == 1)

        n_tests_passed += 1

        b.energy_output_array = (1, 2)
        assert(a.Plant.energy_output_array == (1, 2))
        assert (b.energy_output_array == (1, 2))
        n_tests_passed += 1

        # Test type checks with errors

        try:
            c = CustomGeneration.new()
            c.Plant.energy_output_array = 1
        except:
            n_tests_passed += 1

        try:
            c = CustomGeneration.new()
            c.Plant.energy_output_array = (1, "2")
        except:
            n_tests_passed += 1

        # Test assigning from dictionary

        PlantDict = {'derate': 10,
                          'energy_output_array': (10, 20)}

        b.assign(PlantDict)
        assert(b.derate == 10)
        assert(b.energy_output_array == (10, 20))
        n_tests_passed += 1

        PlantDict = {'derate': 1,
                          'energy_output_array': (2, 2)}
        a.Plant.assign(PlantDict)
        assert(a.Plant.derate == 1 and a.Plant.energy_output_array == (2, 2))
        n_tests_passed += 1

        PlantDict = {'derate': 10,
                          'energy_output_array': (10, 20)}

        try:
            c = CustomGeneration.new()
            PlantDict['energy_output_array'] = ()
            c.Plant.assign(PlantDict)
        except:
            n_tests_passed += 1

        try:
            c = CustomGeneration.new()
            PlantDict['energy_output_array'] = ((12, 20), (1, 1))
            c.Plant.assign(PlantDict)
        except:
            n_tests_passed += 1

        try:
            c = CustomGeneration.new()
            PlantDict['derate'] = "derate"
            PlantDict['energy_output_array'] = (1, 2)
            c.Plant.assign(PlantDict)
        except:
            n_tests_passed += 1

        # exporting to dictionary

        ValDict = b.export()
        assert(ValDict['derate'] == 1 and ValDict['energy_output_array'] == (2, 2))
        n_tests_passed += 1

        # Test shared module (AdjustmentFactors)
        d = a.AdjustmentFactors

        d.adjust_constant = 1
        assert(d.adjust_constant == 1)
        n_tests_passed += 1

        d.adjust_timeindex = (1, 2)
        assert(d.adjust_timeindex == (1, 2))
        n_tests_passed += 1

        d.adjust_periods = ((1, 2), (3, 4))
        assert(d.adjust_periods == ((1, 2), (3, 4)))
        n_tests_passed += 1

        try:
            d.adjust_periods = ((1, 2))
        except:
            n_tests_passed += 1

        ValDict = d.export()
        assert(ValDict['adjust_constant'] == 1 and ValDict['adjust_timeindex'] == (1, 2) and ValDict['adjust_periods'] == ((1, 2), (3, 4)))
        n_tests_passed += 1

        ValDict = {'adjust_constant': 10, "adjust_timeindex": (10, 20), "adjust_periods": ((10, 20), (30, 40))}
        d.assign(ValDict)
        assert(ValDict['adjust_constant'] == 10 and ValDict['adjust_timeindex'] == (10, 20) and ValDict['adjust_periods'] == ((10, 20), (30, 40)))
        n_tests_passed += 1

        # Test nested dictionary assignment, replacement and export
        TechDict = {'Plant': {'derate': 100,
                                   'energy_output_array': (100, 200)},
                    'AdjustmentFactors': {'adjust_constant': 100, "adjust_timeindex": (100, 200), "adjust_periods": ((100, 200), (300, 400))}}
        a.assign(TechDict)
        ValDict = a.Plant.export()
        assert (ValDict['derate'] == 100 and ValDict['energy_output_array'] == (100, 200))
        n_tests_passed += 1

        ValDict = a.AdjustmentFactors.export()
        assert (ValDict['adjust_constant'] == 100 and ValDict['adjust_timeindex'] == (100, 200) and ValDict['adjust_periods'] == (
        (100, 200), (300, 400)))
        n_tests_passed += 1

        TechDict = {'AdjustmentFactors': {'adjust_constant': 0}}
        a.replace(TechDict)
        ValDict = a.AdjustmentFactors.export()
        assert (ValDict['adjust_constant'] == 0 and len(ValDict) == 1)
        n_tests_passed += 1

        # Test reading from PySSC

        data = ssc.data_create()
        ssc.data_set_number(data, b'derate', 1000)
        ssc.data_set_array(data, b'energy_output_array', [1000, 2000])
        a = CustomGeneration.wrap(data)
        assert(a.Plant.derate == 1000)
        assert(a.Plant.energy_output_array == (1000, 2000))

        # Test strings and tables with error cases
        import PySAM.Pvwattsv5 as Pvwattsv5
        a = Pvwattsv5.new()
        a.SolarResource.solar_resource_file = "file"
        assert(a.SolarResource.solar_resource_file == "file")
        n_tests_passed += 1

        assert(a.SolarResource.export()['solar_resource_file'] == 'file')
        n_tests_passed += 1

        c = Pvwattsv5.new()
        datDict = {'num': 1, 'arr': (1, 2), 'str': 'str', 'mat': ((1, 2), (3, 4)), 'table': {'yo': 0}}
        c.SolarResource.solar_resource_data = datDict
        DataDict = c.SolarResource.solar_resource_data
        assert(DataDict['num'] == 1 and DataDict['arr'] == (1, 2))
        assert(DataDict['mat'] == ((1.0, 2.0), (3.0, 4.0)))
        assert(DataDict['str'] == 'str')
        assert(DataDict['table'] == {'yo': 0})
        n_tests_passed += 1

        try:
            c = Pvwattsv5.new()
            c.SolarResource.solar_resource_file = 100
        except:
            n_tests_passed += 1

        try:
            c = Pvwattsv5.new()
            c.SolarResource.solar_resource_data = {'num': 1, 'arr': (1, "2"), 'mat': ((1, 2), (3, 4)), 'str': 'str', 'table': {'yo': 0}}
        except:
            n_tests_passed += 1

        try:
            c = Pvwattsv5.new()
            c.SolarResource.solar_resource_data = {'num': 1, 'arr': (1, 2), 'mat': (("1", 2), (3, 4)), 'str': 'str', 'table': {'yo': 0}}
        except:
            n_tests_passed += 1

        a.SolarResource.solar_resource_data = {'num': 1, 'arr': (1, 2), 'mat': ((1, 2), (3, 4)), 'str': 'str', 'table': {}}
        assert(a.SolarResource.solar_resource_data['table'] == {})
        n_tests_passed += 1

        # Test conversion between technology attributes and nested dictionary

        genDict = a.export()
        assert(genDict['SolarResource']['solar_resource_data']['str'] == 'str')
        n_tests_passed += 1

        a = Pvwattsv5.new()
        assert(a.export()['SolarResource'] == {})
        a.assign(genDict)
        assert(a.export() == genDict)
        n_tests_passed += 1

        # Test loading from serialized dict
        a = CustomGeneration.default("CustomGenerationProfileNone")

        # Test `value` function
        a.value("derate", 1)
        assert(a.value("derate") == 1)

        a.value("energy_output_array", (0, 1, 2))
        assert(a.value("energy_output_array")[0] == 0)
        assert(a.value("energy_output_array")[1] == 1)
        assert(a.value("energy_output_array")[2] == 2)

        # Test `replace` function
        a.Plant.replace({"derate": 0})
        assert(a.Plant.derate == 0)
        try:
            a.Plant.energy_output_array
            assert False
        except:
            n_tests_passed += 1
            assert True

        a = CustomGeneration.default("CustomGenerationProfileNone")
        a.Lifetime.system_use_lifetime_output = 1
        a.replace({"Plant": {"derate": 1}})
        assert(a.Plant.derate == 1)
        try:
            a.Lifetime.system_use_lifetime_output
            assert False
        except:
            n_tests_passed += 1
            assert True

        if round == 3:
            tracker.print_diff()

    tracker.print_diff()


def try_import(mod, config):
    mod_name = "PySAM." + mod
    try:
        i = importlib.import_module(mod_name)
        m = i.default(config)
        return m
    except:
        print("import error", mod, config)
        assert False


def test_import_all():
    for filename in os.listdir(os.environ['SAMNTDIR'] + "/api/api_autogen/library/defaults"):
        if 'Hybrid' in filename:
            continue
        names = os.path.splitext(filename)[0].split('_')
        mod = names[0]
        config = names[1]
        try_import(mod, config)


sf = str(Path(__file__).parent / "blythe_ca_33.617773_-114.588261_psmv3_60_tmy.csv")
wf = str(Path(__file__).parent / "AR Northwestern-Flat Lands.srw")
wave_f = str(Path(__file__).parent / "CalWave_California_Wave Resource _SAM CSV.csv")

wavefile_model = wavefile.new()
wavefile_model.WeatherReader.wave_resource_filename = wave_f
wavefile_model.WeatherReader.wave_resource_model_choice = 0
wavefile_model.execute()
    

def assign_values(mod, i):
    defaults = glob.glob(os.environ['SAMNTDIR'] + "/api/api_autogen/library/defaults/" + mod + "_*.json")

    for default in defaults:
        if 'Hybrid' in default:
            continue
        default = os.path.basename(default).split('.')[0].split('_')[1]
        m = i.default(default)
        if mod == "Pvsamv1" or mod == "Pvwattsv7" or mod == "Pvwattsv5" or mod =="Pvwattsv8":
            m.SolarResource.solar_resource_file = sf
            m.SolarResource.use_wf_albedo = 0
            m.SolarResource.albedo = (0.1,) * 12
        elif mod == "TcsmoltenSalt" or mod == "Swh":
            m.SolarResource.solar_resource_file = sf
        elif mod == "Biomass":
            m.Biopower.file_name = sf
        elif mod == "Hcpv":
            m.SolarResourceData.file_name = sf
        elif mod == "Pvwattsv5Lifetime" or mod == "TcsdirectSteam" or mod == "Tcsiscc":
            m.Weather.solar_resource_file = sf
        elif "Physical" in mod:
            m.Weather.file_name = sf
        elif mod == "Windpower":
            m.Resource.wind_resource_filename = wf
        elif mod == "CustomGeneration":
            m.Lifetime.generic_degradation = [0, ]
        elif mod == "Grid":
            m.SystemOutput.gen = [1 for i in range(8760)]
            m.Lifetime.system_use_lifetime_output = 0
        elif mod == "Battwatts":
            m.value("ac", [1] * 8760)
            m.value("inverter_efficiency", 0.96)
        elif mod == "Battery":
            m.value("gen", [1] * 8760 * 2)
            m.value("energy_hourly_kW", [1] * 8760 * 2)
            m.value("system_use_lifetime_output", 1)
            m.value("analysis_period", 2)
        elif mod == "MhkWave":
            m.value("wave_resource_matrix", wavefile_model.Outputs.wave_resource_matrix)
            m.value("wave_resource_model_choice", 0)
        else:
            try:
                m.value("solar_resource_file", sf)
            except:
                try:
                    m.value("file_name", sf)
                except:
                    pass

        try:
            m.SystemOutput.system_capacity = 10000
            m.TimeSeries.gen = [1 for i in range(8760)]
        except:
            pass
        try:
            if mod != "Battery":
                m.value("analysis_period", 1)
            m.value("batt_dispatch_choice", 0)
        except:
            pass
        try:
            m.execute(0)
        except:
            raise RuntimeError(f"Failed to run {mod} with default {default}")


def test_run_all():
    # only run test on first Python version to be built, since this test is very time consuming
    minor_ver = sys.version_info[1]
    if minor_ver != 8:
        return
    techs = (
        "Battery", "Battwatts", "Biomass", "EtesElectricResistance", "Geothermal", 
        "FresnelPhysical", "FresnelPhysicalIph",
        "LinearFresnelDsgIph", "MhkTidal", "MhkWave",
        "MsptIph",
        "Pvsamv1", "Pvwattsv8", "Pvwattsv7", "Pvwattsv5", "TcsmoltenSalt", "Hcpv", "Swh", "CustomGeneration", "Grid",
        "TcsMSLF", "TcsgenericSolar", "TcslinearFresnel", "TcstroughEmpirical",
        "TroughPhysical", "TroughPhysicalIph", "Windpower")
    for mod in techs:
        mod_name = "PySAM." + mod
        i = importlib.import_module(mod_name)
        m = assign_values(mod, i)
        print(f"{mod} passed")

def test_ssc_exceptions():
    tests_passed = 0
    
    pv = pvsamv1.default("FlatPlatePVSingleOwner")
    # Try to run the PV model without a valid weather file path - expect exception
    try:
        pv.execute()
    except:
        tests_passed += 1

    batt = battery.default("StandaloneBatteryCommercial")
    # Options are 0-2 as of PySAM 6
    batt.BatteryCell.batt_life_model = 99
    try:
        batt.execute()
    except:
        tests_passed += 1

    batt = battery.new()
    # Test prechecks by not setting up required variables
    try:
        batt.execute()
    except:
        tests_passed += 1

    assert(tests_passed == 3)