"""
This example script shows how to set up a stand alone battery with custom dispatch using a default battery model
Any list of floats with length analysis_period * steps_in_year can be used for dispatch

Additional financial models, inputs, and outputs can be found at https://nrel-pysam.readthedocs.io/en/2.0.2/modules/StandAloneBattery.html

Most recently tested against PySAM 2.1.4

@author: brtietz
"""

import PySAM.StandAloneBattery as battery_model
from PySAM.PySSC import *

analysis_period = 1 # years
steps_in_year = 8760 # currently hours in year, multiply this for subhourly tests (example * 12 for 5 minute tests)
days_in_year = 365

# Create the model using PySAM's defaults
battery = battery_model.default("GenericBatterySingleOwner")

# Set up inputs needed by the model.
battery.BatteryCell.batt_room_temperature_celsius = [20] * (steps_in_year * analysis_period) # degrees C, room temperature. Would normally come from weather file

# 24 hours of data to duplicate for the test. Would need to add data here for subhourly
lifetime_generation = []
lifetime_dispatch = []
daily_generation = [0, 0, 0, 0, 0, 0, 0, 200, 400, 600, 800, 1000, 1000, 1000, 1000, 800, 600, 400, 200, 0, 0, 0, 0, 0] # kW
daily_dispatch = [0, 0, 0, 0, 0, 0, 0, -200, -400, -600, -800, -1000, -1000, 0, 0, 200, 400, 600, 800, 1000, 1000, 0, 0, 0] #kW, negative is charging

# Extend daily lists for entire analysis period
for i in range(0, days_in_year * analysis_period):
    lifetime_generation.extend(daily_generation)
    lifetime_dispatch.extend(daily_dispatch)

# Normally output from pvsamv1, need to set up custom system generation here
battery.SystemOutput.gen = lifetime_generation # converts list to tuple

# set the lifetime analysis period to 1
battery.Lifetime.system_use_lifetime_output = 1
battery.Lifetime.analysis_period = 1

# Change from default dispatch to custom dispatch
battery.BatteryDispatch.batt_dispatch_choice = 3 # custom dispatch
battery.BatteryDispatch.batt_custom_dispatch = lifetime_dispatch

# Run the model. Change argument to 1 for verbose
battery.execute(0)

# Export outputs to a dictionary. All outputs on readthedocs page are exported
output = battery.export()

print("Roundtrip efficiency: " + str(output["Outputs"]["average_battery_roundtrip_efficiency"]))
print("Battery cycles over lifetime: " + str(max(output["Outputs"]["batt_cycles"])))
