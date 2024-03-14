"""
This example script shows how to set up a residential pv battery system with custom dispatch
Any list of floats with length analysis_period * steps_in_year can be used for dispatch (steps_in_year determined by weather file)

This example requires a typical model year (tmy) weather file, which can be downloaded using the SAM GUI

Additional financial models, inputs, and outputs can be found at:
* PV: https://nrel-pysam.readthedocs.io/en/master/modules/Pvsamv1.html
* Battery: https://nrel-pysam.readthedocs.io/en/master/modules/Battery.html

Most recently tested against PySAM 5.1.0

@author: brtietz
"""

import PySAM.Battery as battery_model
import PySAM.Pvsamv1 as pvsam
from PySAM.PySSC import *
from pathlib import Path

if len(sys.argv) > 1:
    weather_file = sys.argv[1]  # .csv weather file with tmy format
else:
    weather_file = str(Path(__file__).parent.parent / "tests" / "blythe_ca_33.617773_-114.588261_nasa_60_tmy.csv")

analysis_period = 1  # years
days_in_year = 365

# Create the detailed residential pv model using PySAM's defaults
system_model = pvsam.default("FlatPlatePVResidential")
# Create the battery model based on the PV defaults
battery = battery_model.from_existing(system_model, "GenericBatteryResidential")

# Default model does not include a weather file, so set that based on the command line path
system_model.SolarResource.solar_resource_file = weather_file
system_model.SolarResource.use_wf_albedo = 0

# 24 hours of dispatch data, duplicated for each day. Would need to extend daily_dispatch for subhourly
lifetime_dispatch = []
daily_dispatch = [0, 0, 0, 0, 0, 0, 0, -2, -2, -2, -2, -2, -1, 0, 0, 0, 0, 2, 4, 2, 2, 0, 0, 0]  # kW, negative is charging
# Extend daily lists for entire analysis period
for i in range(0, days_in_year * analysis_period):
    lifetime_dispatch.extend(daily_dispatch)

# Change from default dispatch to custom dispatch
battery.BatteryDispatch.batt_dispatch_choice = 3  # custom dispatch
battery.BatteryDispatch.batt_custom_dispatch = lifetime_dispatch  # converts list to tuple

# Run the model. Change argument to 1 for verbose
system_model.execute(0)

# Export outputs to a dictionary. All outputs on readthedocs page are exported
output = battery.export()

print("Roundtrip efficiency: " + str(output["Outputs"]["average_battery_roundtrip_efficiency"]))
print(max(output["Outputs"]["batt_cycles"]))
