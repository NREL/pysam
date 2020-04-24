"""
This example script shows how to set up a residential pv battery system with custom dispatch
Any list of length analysis_period * hours_in_year can be used for dispatch

This example requires a typical model year (tmy) weather file, which can be downloaded using the SAM GUI

Additional financial models, inputs, and outputs can be found at https://nrel-pysam.readthedocs.io/en/2.0.2/modules/StandAloneBattery.html

Most recently tested against PySAM 2.0.2

@author: brtietz
"""

import PySAM.StandAloneBattery as battery_model
import PySAM.Pvsamv1 as pvsam
from PySAM.PySSC import *

weather_file = sys.argv[1] #.csv weather file with tmy format

analysis_period = 1 # years
hours_in_year = 8760
days_in_year = 365

# Create the pv model
system_model = pvsam.default("FlatPlatePVResidential")
# Create the battery model based on the PV defaults
battery = battery_model.from_existing(system_model, "BatteryNone")

system_model.SolarResource.solar_resource_file = weather_file

lifetime_dispatch = []
daily_dispatch = [0, 0, 0, 0, 0, 0, 0, -2, -2, -2, -2, -2, -1, 0, 0, 0, 0, 2, 4, 2, 2, 0, 0, 0] #kW, negative is charging
# Extend daily lists for entire analysis period
for i in range(0, days_in_year * analysis_period):
    lifetime_dispatch.extend(daily_dispatch)

battery.BatteryDispatch.batt_dispatch_choice = 3 # custom dispatch
battery.BatteryDispatch.batt_custom_dispatch = lifetime_dispatch

# Run the model 
system_model.execute(0)

# Export outputs to a dictionary
output = battery.export()

print("Roundtrip efficiency: " + str(output["Outputs"]["average_battery_roundtrip_efficiency"]))
print(max(output["Outputs"]["batt_cycles"]))