import json
import os
import requests
import numpy as np
import pandas as pd
import certifi
from pathlib import Path

import PySAM.Utilityrateforecast as utility_rate_forecast
import PySAM.UtilityRateTools

"""
This script provides an example of downloading a rate from URDB and processing it in "forecast" mode
The forecast code looks at the step-by-step (default hourly) costs of the rate, based on forecasts of generation and load
This can either be run with all of the steps at once (single call to execute()) to generate an array of prices
or by calling execute repeateadly, potentially in the loop with a model-predictive controller for energy storage
"""

# Get a key from https://api.openei.org:443
key = "<YOUR_API_KEY>"

# Download rate from URDB and save as file. If rate has already been downloaded, use file
def get_urdb_rate_data(page, key):

    # Full API can be viewed at: https://openei.org/services/doc/rest/util_rates/?version=8
    urdb_url = 'https://api.openei.org/utility_rates?format=json&detail=full&version=8'
    get_url = urdb_url + '&api_key={api_key}&getpage={page_id}'.format(api_key=key, page_id=page)

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
    page = "618940545457a35a1c4097ec"  # https://apps.openei.org/USURDB/rate/view/618940545457a35a1c4097ec Residential time of use from Xcel Colorado
    urdb_response = get_urdb_rate_data(page, key)
    urdb_response_json = json.loads(urdb_response)["items"][0]
    rates = PySAM.UtilityRateTools.URDBv8_to_ElectricityRates(urdb_response_json) 

    rate_forecast = utility_rate_forecast.new()
    for k, v in rates.items():
        try:
            rate_forecast.value(k, v)
        except AttributeError:
            pass # rates has more items that rate forecast uses. Ignore these errors

    # Set up other defaults
    analysis_period = 1 # Number of years to run the simulation
    rate_forecast.value("analysis_period", analysis_period) 
    rate_forecast.value("inflation_rate", 2.5) # Units of %
    rate_forecast.value("steps_per_hour", 1) 

    df = pd.read_csv(str(Path(__file__).parent /"sample_load.csv"), dtype=float)
    load = pd.to_numeric(df.iloc[:, 0]).values # Consider checking length of array in case of subhourly data

    # Lifetime length for the forecast class
    gen = [0] * int(8760 * analysis_period)# No renewable generation, run a technology compute module such as PVWatts8 to get this
    load = load * analysis_period # Repeat the load every year (could consider load escalation in the future)
    grid_power = -1 * load # Grid usage is the same as load. One could also use an array of "-1" to generate per-kWh pricing

    rate_forecast.value("gen", gen) # Hourly kW
    rate_forecast.value("load", load) # Hourly kW
    rate_forecast.value("grid_power", grid_power[0:8760]) # Hourly kW
    rate_forecast.value("idx", 0)

    # Default example - call once and get back an array or total bill
    rate_forecast.setup()
    rate_forecast.execute()
    print(rate_forecast.export().keys()) # High level dictionary keys
    print(rate_forecast.export()["Outputs"]["ur_total_bill"]) # Note that this does not include fixed charges

    price_series = rate_forecast.export()["Outputs"]["ur_price_series"]
    print(sum(np.array(price_series))) # Since grid usage is the same as load, this is the same as ur_total_bill