import os
os.system("rm -r /Users/dguittet/SAM-Dev/PySAM/build")

from setuptools import sandbox
sandbox.run_setup('setup.py', ['clean', 'install'])

import GenericSystem

n_tests_passed = 0

a = GenericSystem.new()

b = a.PowerPlant

# Test setting values with type checks

a.PowerPlant.derate = 1
assert(a.PowerPlant.derate == 1)
print("Passed test", 0)
n_tests_passed += 1

b.energy_output_array = (1, 2)
assert(b.energy_output_array == (1, 2))
print("Passed test", 1)
n_tests_passed += 1

try:
    b.energy_output_array = 1
    print("FAIL: exception is expected")
except:
    print("Passed test", 2)
    n_tests_passed += 1

try:
    b.energy_output_array = (1, "2")
    print("FAIL: exception is expected")
except:
    print("Passed test", 3)
    n_tests_passed += 1


PowerPlantDict = {'derate': 1,
                  'energy_output_array': ()}

try:
    b.assign(PowerPlantDict)
    print("FAIL: exception is expected")
except:
    print("Passed test", 4)
    n_tests_passed += 1

PowerPlantDict = {'derate': 1,
                  'energy_output_array': ((2,2), (1))}

try:
    b.assign(PowerPlantDict)
    print("FAIL: exception is expected")
except:
    print("Passed test", 5)
    n_tests_passed += 1

PowerPlantDict = {'derate': 1,
                  'energy_output_array': (2,"2")}

try:
    b.assign(PowerPlantDict)
    print("exception is expected")
except:
    print("Passed test", 6)
    n_tests_passed += 1

assert(b.energy_output_array == (10, 20))