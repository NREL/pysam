import GenericSystem

a = GenericSystem.new()

print(dir(a))
print(dir(a.PowerPlant))

b = a.PowerPlant

print(a.PowerPlant)
print(help(b))
a.PowerPlant.derate = 1
print(a.PowerPlant.derate)

b.energy_output_array = (1, 2)
print(b.energy_output_array)

b.energy_output_array = (1, "2")
print(b.energy_output_array)

system = {'PowerPlant':
              {'derate': 1,
               'energy_output_array': ((10, 20),(1, 1))}}

print(system['PowerPlant'])


b.assign(system['PowerPlant'])

print("\n", b.energy_output_array)