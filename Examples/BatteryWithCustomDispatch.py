"""
This example script shows how to set up a stand alone battery with custom dispatch using a default battery model
Any list of length analysis_period * hours_in_year can be used for dispatch

Additional financial models, inputs, and outputs can be found at https://nrel-pysam.readthedocs.io/en/2.0.2/modules/StandAloneBattery.html

Most recently tested against PySAM 2.0.2

@author: brtietz
"""

import PySAM.StandAloneBattery as battery_model
from PySAM.PySSC import *

analysis_period = 1 # years
hours_in_year = 8760
days_in_year = 365

# Create the model
battery = battery_model.default("GenericSystemSingleOwner")

# Set up inputs needed by the model
battery.BatteryCell.batt_room_temperature_celsius = [20] * (hours_in_year * analysis_period) # degrees C. Would normally come from weather file

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

battery.BatteryDispatch.batt_dispatch_choice = 3 # custom dispatch
battery.BatteryDispatch.batt_custom_dispatch = lifetime_dispatch
    
# Run the model    
battery.execute(0)

# Export outputs to a dictionary
output = battery.export()

print("Roundtrip efficiency: " + str(output["Outputs"]["average_battery_roundtrip_efficiency"]))
print("Battery cycles over lifetime: " + str(max(output["Outputs"]["batt_cycles"])))