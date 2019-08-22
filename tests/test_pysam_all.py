import os
import importlib
import PySAM.GenericSystem as GenericSystem
from pympler.tracker import SummaryTracker
import gc
from PySAM.PySSC import PySSC

ssc = PySSC()

check_error_cases = True


def test_functionality():
    n_tests_passed = 0
    round = 0

    while round < 50:   # multiple runs required to check for memory leaks
        if round == 0:
            tracker = SummaryTracker()

        print("\n===Starting Round", round, "===\n\n")
        round += 1

        a = GenericSystem.new()
        b = a.Plant


        # Test setting values with correct types

        a.Plant.derate = 1
        assert (a.Plant.derate == 1)
        assert (b.derate == 1)

        print("Passed test", 0)
        n_tests_passed += 1

        b.energy_output_array = (1, 2)
        assert(a.Plant.energy_output_array == (1, 2))
        assert (b.energy_output_array == (1, 2))
        print("Passed test", 1)
        n_tests_passed += 1

        # Test type checks with errors

        try:
            c = GenericSystem.new()
            c.Plant.energy_output_array = 1
            print("FAIL 2: exception is expected")
        except:
            print("Passed test", 2)
            n_tests_passed += 1


        try:
            c = GenericSystem.new()
            c.Plant.energy_output_array = (1, "2")
            print("FAIL 3: exception is expected")
        except:
            print("Passed test", 3)
            n_tests_passed += 1


        # Test assigning from dictionary

        PlantDict = {'derate': 10,
                          'energy_output_array': (10, 20)}

        b.assign(PlantDict)
        assert(b.derate == 10)
        assert(b.energy_output_array == (10, 20))
        print("Passed test", 4)
        n_tests_passed += 1


        PlantDict = {'derate': 1,
                          'energy_output_array': (2, 2)}
        a.Plant.assign(PlantDict)
        assert(a.Plant.derate == 1 and a.Plant.energy_output_array == (2, 2))
        print("Passed test", 5)
        n_tests_passed += 1

        PlantDict = {'derate': 10,
                          'energy_output_array': (10, 20)}

        try:
            c = GenericSystem.new()
            PlantDict['energy_output_array'] = ()
            c.Plant.assign(PlantDict)
            print("FAIL 1: exception is expected")
        except:
            print("Error caught", 1)
            n_tests_passed += 1

        try:
            c = GenericSystem.new()
            PlantDict['energy_output_array'] = ((12, 20), (1, 1))
            c.Plant.assign(PlantDict)
            print("FAIL 2: exception is expected")
        except:
            print("Error caught", 2)
            n_tests_passed += 1

        try:
            c = GenericSystem.new()
            PlantDict['derate'] = "derate"
            PlantDict['energy_output_array'] = (1, 2)
            c.Plant.assign(PlantDict)
            print("FAIL 3: exception is expected")
        except:
            print("Error caught", 3)
            n_tests_passed += 1


        # exporting to dictionary

        ValDict = b.export()
        assert(ValDict['derate'] == 1 and ValDict['energy_output_array'] == (2, 2))
        print("Passed test", 6)
        n_tests_passed += 1

        # Test shared module (AdjustmentFactors)
        d = a.AdjustmentFactors

        d.constant = 1
        assert(d.constant == 1)
        print("Passed test", 7)
        n_tests_passed += 1

        d.hourly = (1, 2)
        assert(d.hourly == (1, 2))
        print("Passed test", 8)
        n_tests_passed += 1

        d.periods = ((1, 2), (3, 4))
        assert(d.periods == ((1, 2), (3, 4)))
        print("Passed test", 9)
        n_tests_passed += 1

        try:
            d.periods = ((1, 2))
            print("FAIL 4: exception is expected")
        except:
            print("Error caught", 4)
            n_tests_passed += 1

        ValDict = d.export()
        assert(ValDict['constant'] == 1 and ValDict['hourly'] == (1, 2) and ValDict['periods'] == ((1, 2), (3, 4)))
        print("Passed test", 10)
        n_tests_passed += 1

        ValDict = {'constant': 10, "hourly": (10, 20), "periods": ((10, 20), (30, 40))}
        d.assign(ValDict)
        assert(ValDict['constant'] == 10 and ValDict['hourly'] == (10, 20) and ValDict['periods'] == ((10, 20), (30, 40)))
        print("Passed test", 11)
        n_tests_passed += 1


        # Test nested dictionary assignment and export

        TechDict = {'Plant': {'derate': 100,
                                   'energy_output_array': (100, 200)},
                    'AdjustmentFactors': {'constant': 100, "hourly": (100, 200), "periods": ((100, 200), (300, 400))}}
        a.assign(TechDict)
        ValDict = a.Plant.export()
        assert (ValDict['derate'] == 100 and ValDict['energy_output_array'] == (100, 200))
        print("Passed test", 12)
        n_tests_passed += 1

        ValDict = a.AdjustmentFactors.export()
        assert (ValDict['constant'] == 100 and ValDict['hourly'] == (100, 200) and ValDict['periods'] == (
        (100, 200), (300, 400)))
        print("Passed test", 13)
        n_tests_passed += 1


        # Test reading from PySSC

        data = ssc.data_create()
        ssc.data_set_number(data, b'derate', 1000)
        ssc.data_set_array(data, b'energy_output_array', [1000, 2000])
        a = GenericSystem.wrap(data)
        assert(a.Plant.derate == 1000)
        assert(a.Plant.energy_output_array == (1000, 2000))


        # Test strings and tables with error cases
        import PySAM.Pvwattsv5 as Pvwattsv5
        a = Pvwattsv5.new()
        a.LocationAndResource.solar_resource_file = "file"
        assert(a.LocationAndResource.solar_resource_file == "file")
        print("Passed test", 14)
        n_tests_passed += 1

        assert(a.LocationAndResource.export()['solar_resource_file'] == 'file')
        print("Passed test", 15)
        n_tests_passed += 1

        c = Pvwattsv5.new()
        datDict = {'num': 1, 'arr': (1, 2),  'str': 'str', 'mat': ((1, 2), (3, 4)), 'table': {'yo': 0}}
        c.LocationAndResource.solar_resource_data = datDict
        DataDict = c.LocationAndResource.solar_resource_data
        assert(DataDict['num'] == 1 and DataDict['arr'] == (1, 2))
        assert(DataDict['mat'] == ((1.0, 2.0), (3.0, 4.0)))
        assert(DataDict['str'] == 'str')
        assert(DataDict['table'] == {'yo': 0})
        print("Passed test", 16)
        n_tests_passed += 1

        try:
            c = Pvwattsv5.new()
            c.LocationAndResource.solar_resource_file = 100
            print("FAIL 5: exception is expected")
        except:
            print("Error caught", 5)
            n_tests_passed += 1

        try:
            c = Pvwattsv5.new()
            c.LocationAndResource.solar_resource_data = {'num': 1, 'arr': (1, "2"), 'mat': ((1, 2), (3, 4)), 'str': 'str', 'table': {'yo': 0}}
            print("FAIL 6: exception is expected")
        except:
            print("Error caught", 6)
            n_tests_passed += 1

        try:
            c = Pvwattsv5.new()
            c.LocationAndResource.solar_resource_data = {'num': 1, 'arr': (1, 2), 'mat': (("1", 2), (3, 4)), 'str': 'str', 'table': {'yo': 0}}
            print("FAIL 7: exception is expected")
        except:
            print("Error caught", 7)
            n_tests_passed += 1

        a.LocationAndResource.solar_resource_data = {'num': 1, 'arr': (1, 2), 'mat': ((1, 2), (3, 4)), 'str': 'str', 'table': {}}
        assert(a.LocationAndResource.solar_resource_data['table'] == {})
        print("Passed test", 17)
        n_tests_passed += 1



        # Test conversion between technology attributes and nested dictionary

        genDict = a.export()
        assert(genDict['LocationAndResource']['solar_resource_data']['str'] == 'str' )
        print("Passed test", 18)
        n_tests_passed += 1

        a = Pvwattsv5.new()
        assert(a.export()['LocationAndResource'] == {})
        a.assign(genDict)
        assert(a.export() == genDict)
        print("Passed test", 19)
        n_tests_passed += 1

        # Test loading from serialized dict
        a = GenericSystem.default("GenericSystemNone")
        print(a.export())

        if round == 3:
            tracker.print_diff()


        # execution
        # a.execute(1)


    tracker.print_diff()


sf = "../sam/deploy/solar_resource/tucson_az_32.116521_-110.933042_psmv3_60_tmy.csv"
sf2 = "../sam/deploy/solar_resource/phoenix_az_33.450495_-111.983688_psmv3_60_tmy.csv"
sf3 = '../sam/deploy/solar_resource/fargo_nd_46.9_-96.8_mts1_60_tmy.csv'
wf = "../sam/deploy/wind_resource/OH Northern-Lake.srw"

def assign_values(mod, default, i):
    m = i.default(default)
    if mod == "Pvsamv1":
        m.SolarResource.solar_resource_file = sf
    elif mod == "Biomass":
        m.Biopower.file_name = sf3
    elif mod == "Hcpv":
        m.SolarResourceData.file_name = sf
    elif mod == "Pvwattsv5" or mod == "TcsmoltenSalt":
        m.LocationAndResource.solar_resource_file = sf2
    elif mod == "Swh" or mod == "Pvwattsv5Lifetime" or mod == "TcsdirectSteam" or mod == "Tcsiscc":
        m.Weather.solar_resource_file = sf2
    elif mod == "Windpower":
        m.Resource.wind_resource_filename = wf
    elif mod == "GenericSystem":
        pass
    elif mod == "Grid":
        m.Common.gen = [0] * 8760
    else:
        try:
            m.Weather.file_name = sf2
        except:
            pass

    try:
        m.SystemOutput.gen = [1 for i in range(8760)]
        m.SystemOutput.system_capacity = 10000
        m.TimeSeries.gen = [1 for i in range(8760)]
    except:
        pass

    return m


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
    for filename in os.listdir(os.environ['PYSAMDIR']+"/files/defaults"):
        names = os.path.splitext(filename)[0].split('_')
        mod = names[0]
        if mod == 'Battery':
            mod = 'StandAloneBattery'
        if mod == 'Cashloan':
            mod = 'CashloanModel'
        config = names[1]
    try_import(mod, config)


def test_run_all():
    for filename in os.listdir(os.environ['PYSAMDIR']+"/files/defaults"):
        names = os.path.splitext(filename)[0].split('_')
        mod = names[0]
        if mod == 'Battery':
            mod = 'StandAloneBattery'
        if mod == 'Cashloan':
            mod = 'CashloanModel'
        config = names[1]
        mod_name = "PySAM." + mod


        try:
            print("try executing", mod, config, "\n")
            i = importlib.import_module(mod_name)
            m = assign_values(mod, config, i)
            m.execute(0)
        except:
            print("error executing", mod, config, "\n")

