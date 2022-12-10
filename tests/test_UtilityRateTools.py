from pathlib import Path
import json

import PySAM.UtilityRateTools as tools 

def test_urdb():
    urdb = str(Path(__file__).parent / "urdbv7.json") # V7 and V8 are the same for most rates
    with open(urdb, 'r') as file:
        urdb_data = json.load(file)
    ur5 = tools.URDBv8_to_ElectricityRates(urdb_data)

    ec_tou = [1, 1, 100, 0, 0.070768997073173523, 0,
              1, 2, 9.9999996802856925e+37, 0, 0.082948997616767883, 0,
              2, 1, 100, 0, 0.056908998638391495, 0,
              2, 2, 9.9999996802856925e+37, 0, 0.069078996777534485, 0]

    dc_tou = [1, 1, 100, 19.538999557495117,
              1, 2, 9.9999996802856925e+37, 13.093000411987305,
              2, 1, 100, 8.0909996032714844,
              2, 2, 9.9999996802856925e+37, 4.6760001182556152]

    flat_mat = [0, 1, 1e+38, 6.46,
                1, 1, 1e+38, 6.46,
                2, 1, 1e+38, 6.46,
                3, 1, 1e+38, 6.46,
                4, 1, 1e+38, 13.87,
                5, 1, 1e+38, 13.87,
                6, 1, 1e+38, 13.87,
                7, 1, 1e+38, 13.87,
                8, 1, 1e+38, 13.87,
                9, 1, 1e+38, 13.87,
                10, 1, 1e+38, 6.46,
                11, 1, 1e+38, 6.46]

    ec_tou_tested = [item for sublist in ur5['ur_ec_tou_mat'] for item in sublist]
    dc_tou_tested = [item for sublist in ur5['ur_dc_tou_mat'] for item in sublist]
    flat_mat_tested = [item for sublist in ur5['ur_dc_flat_mat'] for item in sublist]

    assert(ec_tou_tested == ec_tou)
    assert(dc_tou_tested == dc_tou)
    assert(flat_mat_tested == flat_mat)


def test_urdb_2():
    urdb = str(Path(__file__).parent / "urdbv7.json") # V7 and V8 are the same for most rates
    with open(urdb, 'r') as file:
        urdb_data = json.load(file)
        urdb_data.pop("flatdemandmonths")
    ur5 = tools.URDBv8_to_ElectricityRates(urdb_data)

    ec_tou = [1, 1, 100, 0, 0.070768997073173523, 0,
              1, 2, 9.9999996802856925e+37, 0, 0.082948997616767883, 0,
              2, 1, 100, 0, 0.056908998638391495, 0,
              2, 2, 9.9999996802856925e+37, 0, 0.069078996777534485, 0]

    dc_tou = [1, 1, 100, 19.538999557495117,
              1, 2, 9.9999996802856925e+37, 13.093000411987305,
              2, 1, 100, 8.0909996032714844,
              2, 2, 9.9999996802856925e+37, 4.6760001182556152]

    ec_tou_tested = [item for sublist in ur5['ur_ec_tou_mat'] for item in sublist]
    dc_tou_tested = [item for sublist in ur5['ur_dc_tou_mat'] for item in sublist]

    assert(ec_tou_tested == ec_tou)
    assert(dc_tou_tested == dc_tou)

def test_dc_flat_mat():
    urdb = str(Path(__file__).parent / "urdb_rate_539f6a23ec4f024411ec8beb.json") # V7 and V8 are the same for most rates
    with open(urdb, 'r') as file:
        urdb_data = json.load(file) # Brings in a string
        urdb_data = json.loads(urdb_data) # Converts string to JSON

    ur5 = tools.URDBv8_to_ElectricityRates(urdb_data['items'][0])

    flat_demand = ur5["ur_dc_flat_mat"]

    assert(len(flat_demand) == 24) # 12 months, 2 tiers per month
    assert(flat_demand[0][2] == 100) # Tier max in kW