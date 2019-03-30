# import os
# os.system("rm -r /Users/dguittet/SAM-Dev/PySAM/build")
#
# from setuptools import sandbox
# sandbox.run_setup('setup.py', ['install'])
import GenericSystem
from pympler.tracker import SummaryTracker


n_tests_passed = 0
round = 0
while n_tests_passed < 1000 and round < 5:

    if round == 0:
        tracker = SummaryTracker()

    print("\n===Starting Round", round, "===\n\n")
    round += 1

    a = GenericSystem.new()

    b = a.PowerPlant


    # Test setting values with correct types

    a.PowerPlant.derate = 1
    assert (a.PowerPlant.derate == 1)
    assert (b.derate == 1)

    print("Passed test", 0)
    n_tests_passed += 1

    b.energy_output_array = (1, 2)
    assert(a.PowerPlant.energy_output_array == (1,2))
    assert (b.energy_output_array == (1, 2))
    print("Passed test", 1)
    n_tests_passed += 1

    # Test type checks with errors

    try:
        b.energy_output_array = 1
        print("FAIL 2: exception is expected")
    except:
        assert(b.energy_output_array == (1, 2))
        print("Passed test", 2)
        n_tests_passed += 1


    try:
        b.energy_output_array = (1, "2")
        print("FAIL 3: exception is expected")
    except:
        assert(b.energy_output_array == (1, 2))
        print("Passed test", 3)
        n_tests_passed += 1


    # Test assigning from dictionary

    PowerPlantDict = {'derate': 10,
                      'energy_output_array': (10, 20)}

    b.assign(PowerPlantDict)
    assert(b.derate == 10)
    assert(b.energy_output_array == (10, 20))
    print("Passed test", 4)
    n_tests_passed += 1


    PowerPlantDict = {'derate': 1,
                      'energy_output_array': (2, 2)}
    a.PowerPlant.assign(PowerPlantDict)
    assert(a.PowerPlant.derate == 1 and a.PowerPlant.energy_output_array == (2, 2))
    print("Passed test", 5)
    n_tests_passed += 1


    # assigning to dictionary

    ValDict = b.export()
    assert(ValDict['derate'] == 1 and ValDict['energy_output_array'] == (2, 2))
    print("Passed test", 6)
    n_tests_passed += 1

    if round == 3:
        tracker.print_diff()

tracker.print_diff()


# error cases

PowerPlantDict = {'derate': 10,
                      'energy_output_array': (10, 20)}

try:
    PowerPlantDict['energy_output_array'] = ()
    b.assign(PowerPlantDict)
    print("FAIL 1: exception is expected")
    print(b.energy_output_array)
except:
    print("Error caught", 1)
    n_tests_passed += 1

try:
    PowerPlantDict['energy_output_array'] = ((12, 20), (1, 1))
    b.assign(PowerPlantDict)
    print("FAIL 2: exception is expected")
except:
    print("Error caught", 2)
    n_tests_passed += 1

try:
    PowerPlantDict['derate'] = "derate"
    PowerPlantDict['energy_output_array'] = (1, 2)
    b.assign(PowerPlantDict)
    print("FAIL 3: exception is expected")
except:
    print("Error caught", 3)
    n_tests_passed += 1