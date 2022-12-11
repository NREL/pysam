import pytest
import json
from pathlib import Path
import numpy as np
import pandas as pd
import PySAM.Utilityrateforecast as utility_rate_forecast
import PySAM.UtilityRateTools

@pytest.fixture
def setup_rate():
    urdb = str(Path(__file__).parent / "urdbv7.json")
    with open(urdb, 'r') as file:
        urdb_data = json.load(file)
    rates = PySAM.UtilityRateTools.URDBv8_to_ElectricityRates(urdb_data)

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

    return rate_forecast

def test_bill_equivalence(setup_rate):

    analysis_period = 1 # Number of years to run the simulation
    sample_load = str(Path(__file__).parent / "sample_load.csv")
    df = pd.read_csv(sample_load, dtype=float)
    load = pd.to_numeric(df.iloc[:, 0]).values # Consider checking length of array in case of subhourly data

    # Lifetime length for the forecast class
    gen = [0] * int(8760 * analysis_period)# No renewable generation, run a technology compute module such as PVWatts8 to get this
    load = load * analysis_period # Repeat the load every year (could consider load escalation in the future)
    grid_power = -1 * load # Grid usage is the same as load. One could also use an array of "-1" to generate per-kWh pricing

    setup_rate.value("gen", gen) # Hourly kW
    setup_rate.value("load", load) # Hourly kW
    setup_rate.value("grid_power", grid_power[0:8760]) # Hourly kW
    setup_rate.value("idx", 0)

    # Default example - call once and get back an array or total bill
    setup_rate.setup()
    setup_rate.execute()
    
    price_series = setup_rate.export()["Outputs"]["ur_price_series"]
    assert(setup_rate.export()["Outputs"]["ur_total_bill"] == sum(np.array(price_series))) # Note that this does not include fixed charges

def test_multiple_execute_calls(setup_rate):
    analysis_period = 1 # Number of years to run the simulation
    sample_load = str(Path(__file__).parent / "sample_load.csv")
    df = pd.read_csv(sample_load, dtype=float)
    load = pd.to_numeric(df.iloc[:, 0]).values # Consider checking length of array in case of subhourly data

    # Lifetime length for the forecast class
    gen = [0] * int(8760 * analysis_period)# No renewable generation, run a technology compute module such as PVWatts8 to get this
    load = load * analysis_period # Repeat the load every year (could consider load escalation in the future)
    grid_power = -1 * load # Grid usage is the same as load. One could also use an array of "-1" to generate per-kWh pricing

    setup_rate.value("gen", gen) # Hourly kW
    setup_rate.value("load", load) # Hourly kW

    setup_rate.setup()

    total_cost = 0
    idx = 0
    for power in load:
        setup_rate.value("idx", idx)
        setup_rate.value("grid_power", [-1.0 * power])
        setup_rate.execute()
        price_series = setup_rate.export()["Outputs"]["ur_price_series"]
        total_cost += price_series[0]
        idx += 1

    assert(total_cost == pytest.approx(1603.08, 0.01)) # Equivalent to "ur_total_bill" in test_bill_equivalence
