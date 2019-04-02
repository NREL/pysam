# import os
# os.system("rm -r /Users/dguittet/SAM-Dev/PySAM/build")
#
# from setuptools import sandbox
# sandbox.run_setup('setup.py', ['install'])
import GenericSystem
from pympler.tracker import SummaryTracker

check_error_cases = True

n_tests_passed = 0
round = 0
while round < 1:

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

    if round == 3:
        tracker.print_diff()


    # execution
    # a.execute(1)


    # Test shared module (AdjustmentFactors)
    d = a.AdjustmentFactors

    d.ac_constant = 1
    assert(d.ac_constant == 1)
    print("Passed test", 7)
    n_tests_passed += 1

    d.ac_hourly = (1, 2)
    assert(d.ac_hourly == (1, 2))
    print("Passed test", 8)
    n_tests_passed += 1

    d.ac_periods = ((1, 2), (3, 4))
    assert(d.ac_periods == ((1, 2), (3, 4)))
    print("Passed test", 9)
    n_tests_passed += 1

    ValDict = d.export()
    assert(ValDict['ac_constant'] == 1 and ValDict['ac_hourly'] == (1, 2) and ValDict['ac_periods'] == ((1, 2), (3, 4)))
    print("Passed test", 10)
    n_tests_passed += 1

    ValDict = {'ac_constant': 10, "ac_hourly": (10, 20), "ac_periods": ((10, 20), (30, 40))}
    d.assign(ValDict)
    assert(ValDict['ac_constant'] == 10 and ValDict['ac_hourly'] == (10, 20) and ValDict['ac_periods'] == ((10, 20), (30, 40)))
    print("Passed test", 11)
    n_tests_passed += 1

    # Test nested dictionary assignment and export
    TechDict = {'Plant': {'derate': 100,
                               'energy_output_array': (100, 200)},
                'AdjustmentFactors': {'ac_constant': 100, "ac_hourly": (100, 200), "ac_periods": ((100, 200), (300, 400))}}
    a.assign(TechDict)
    ValDict = a.Plant.export()
    assert (ValDict['derate'] == 100 and ValDict['energy_output_array'] == (100, 200))
    print("Passed test", 12)
    n_tests_passed += 1

    ValDict = a.AdjustmentFactors.export()
    assert (ValDict['ac_constant'] == 100 and ValDict['ac_hourly'] == (100, 200) and ValDict['ac_periods'] == (
    (100, 200), (300, 400)))
    print("Passed test", 13)
    n_tests_passed += 1

    # Test reading from PySSC
    from sscapi import PySSC

    ssc = PySSC()
    data = ssc.data_create()
    ssc.data_set_number(data, b'derate', 1000)
    ssc.data_set_array(data, b'energy_output_array', [1000, 2000])
    a = GenericSystem.new(data)
    assert(a.Plant.derate == 1000)
    assert(a.Plant.energy_output_array == (1000, 2000))

    # Test strings and tables with error cases

    a.Plant.file = "file"
    assert(a.Plant.file == "file")
    print("Passed test", 14)
    n_tests_passed += 1

    assert(a.Plant.export()['file'] == 'file')
    print("Passed test", 15)
    n_tests_passed += 1

    c = GenericSystem.new()
    dat = {'yo': 0}
    c.Plant.data = {'num': 1, 'arr': (1, 2), 'mat': ((1,2 ), (3, 4)), 'str': 'str', 'table': dat}
    DataDict = c.Plant.data
    assert(DataDict['num'] == 1 and DataDict['arr'] == (1,2) and DataDict['mat'] == ((1, 2), (3, 4)) and DataDict['str'] == 'str')
    assert(DataDict['table'] == dat)
    print("Passed test", 16)
    n_tests_passed += 1

    try:
        a.Plant.file = 100
        print("FAIL 17: exception is expected")
    except:
        print("Error caught", 17)
        n_tests_passed += 1

    try:
        c.Plant.data = {'num': 1, 'arr': (1, "2"), 'mat': ((1,2 ), (3, 4)), 'str': 'str', 'table': dat}
        print("FAIL 18: exception is expected")
    except:
        print("Error caught", 18)
        n_tests_passed += 1

    try:
        c.Plant.data = {'num': 1, 'arr': (1, 2), 'mat': (("1",2 ), (3, 4)), 'str': 'str', 'table': dat}
        print("FAIL 19: exception is expected")
    except:
        print("Error caught", 19)
        n_tests_passed += 1



tracker.print_diff()
