# import os
# os.system("rm -r /Users/dguittet/SAM-Dev/PySAM/build")
#
# from setuptools import sandbox
# sandbox.run_setup('setup.py', ['install'])
import GenericSystem
from pympler.tracker import SummaryTracker


n_tests_passed = 0
round = 0
while n_tests_passed < 1000 and round < 10:
    round += 1

    tracker = SummaryTracker()

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
        print("Passed test", 2)
        n_tests_passed += 1

    # try:
    #     b.energy_output_array = (1, "2")
    #     print("FAIL: exception is expected")
    # except:
    #     print("Passed test", 3)
    #     n_tests_passed += 1
    #
    # PowerPlantDict = {'derate': 1,
    #                   'energy_output_array': ()}
    # # }
    #
    # try:
    #     # b.assign(PowerPlantDict)
    #     print("FAIL 4: exception is expected")
    # except:
    #     print("Passed test", 4)
    #     n_tests_passed += 1
    #
    # PowerPlantDict = {'derate': 1,
    #                   'energy_output_array': ((2, 2), (1, 1))}
    #
    # try:
    #     # b.assign(PowerPlantDict)
    #     print("FAIL 5: exception is expected")
    # except:
    #     print("Passed test", 5)
    #     n_tests_passed += 1
    #
    # PowerPlantDict = {'derate': 1,
    #                   'energy_output_array': (2, 2)}
    #
    # try:
    #     # b.assign(PowerPlantDict)
    #     print("FAIL 6:exception is expected")  # broke here.. errored after 2a and after 8b(PySAM_utils.h:232))
    # except:
    #     print("Passed test", 6)
    #     n_tests_passed += 1
    # print("end")

    # PowerPlantDict = {'derate': 1,
    #                   'energy_output_array': (10,20)}
    # print(b.export())

    # assert(b.energy_output_array == (10, 20) and b.derate == 1)
    # sleep(2)


tracker.print_diff()

