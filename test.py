import GenericSystem

a = GenericSystem.new()

print(dir(a))
print(dir(a.PowerPlant))

b = a.PowerPlant

print(a.PowerPlant)
print(b)
a.PowerPlant.derate = 1
print(a.PowerPlant.derate)
