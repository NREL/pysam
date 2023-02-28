"""
This example script shows how to set up the utility rate module using a rate downloaded from the Utility Rate

This example requires an NREL developer key, which can be obtained from https://developer.nrel.gov/signup/

Additional financial models, inputs, and outputs can be found at:
* PV: https://nrel-pysam.readthedocs.io/en/master/modules/Utilityrate5.html

Most recently tested against PySAM 4.1.0
Requires: nrel-pysam, requests

@author: brtietz
"""
import json
import os
import certifi
import requests

import PySAM.Utilityrate5 as utility_rate
import PySAM.UtilityRateTools
import PySAM.LoadTools

# Get a key from https://api.openei.org:443
key = "YOUR_API_KEY"

# Download rate from URDB and save as file. If rate has already been downloaded, use file
def get_urdb_rate_data(page, key):

    # Full API can be viewed at: https://openei.org/services/doc/rest/util_rates/?version=8
    urdb_url = 'https://api.openei.org/utility_rates?format=json&detail=full&version=8'
    get_url = urdb_url + '&api_key={api_key}&getpage={page_id}'.format(api_key=key, page_id=page)
    print(get_url)

    filename = "urdb_rate_{}.json".format(page)
    print(filename)

    if not os.path.isfile(filename):
        print(get_url)
        resp = requests.get(get_url, verify=certifi.where())
        data = resp.text
        # Cache rate as file
        if "error" not in data:
            with open(filename, 'w') as f:
                f.write(json.dumps(data, sort_keys=True, indent=2, separators=(',', ': ')))
    else:
        with open(filename, 'r') as f:
            data = json.load(f)

    return data

if __name__ == "__main__":
    path = os.getcwd() + os.path.sep
    page = "618940545457a35a1c4097ec"  # https://apps.openei.org/USURDB/rate/view/618940545457a35a1c4097ec (DG-R Primary (Above 500kW))
    if "YOUR_API_KEY" in key:
        raise Exception("Please replace the `key` with your URDB API key.")
    urdb_response = get_urdb_rate_data(page, key)
    urdb_response_json = json.loads(urdb_response)
    if 'error' in urdb_response_json.keys():
        raise Exception(urdb_response_json['error'])
    rates = PySAM.UtilityRateTools.URDBv8_to_ElectricityRates(urdb_response_json["items"][0]) 

    ur = utility_rate.new()
    for k, v in rates.items():
        ur.value(k, v)

    # Set up other defaults
    analysis_period = 1 # Number of years to run the simulation
    ur.value("analysis_period", analysis_period) 
    ur.value("system_use_lifetime_output", 0) # Set to 1 if load and gen have length 8760 * analysis_period
    ur.value("inflation_rate", 2.5) # Units of %
    ur.value("degradation", [0] * analysis_period) # AC energy loss per year due to degradation during analysis period (%)

    gen = [0] * 8760 # No renewable generation, run a technology compute module such as PVWatts8 to get this
    load = [100] * 8760 # Constant 100 kW load - this could also be an array imported from CSV

    ur.value("gen", gen) # Hourly kW
    ur.value("load", load) # Hourly kW

    # Not used for the rate above but leave this here for rates with billing demand
    monthly_peaks = PySAM.LoadTools.get_monthly_peaks(load, 1)
    ur.value("ur_yearzero_usage_peaks", monthly_peaks)

    ur.execute() # Run the utility rate module

    print("Total utility bill without system ($): ", ur.Outputs.elec_cost_without_system_year1) 
    print("Average $/kW", ur.Outputs.elec_cost_without_system_year1 / sum(load))


