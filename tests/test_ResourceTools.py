import sys
sys.path.append('.')
import shutil
import pytest
from pathlib import Path
import json

import pandas as pd

import PySAM.ResourceTools as tools  # change back to module import
import PySAM.Windpower as wp
import PySAM.Pvwattsv7 as pv


def test_solar():
    solar = str(Path(__file__).parent / "blythe_ca_33.617773_-114.588261_psmv3_60_tmy.csv")
    data = tools.SAM_CSV_to_solar_data(solar)
    assert (data['lat'] == 33.61)
    assert (data['lon'] == -114.58)
    assert (data['dn'][7] == 262)
    assert (data['df'][7] == 16)
    assert (data['gh'][7] == 27)
    assert (data['tdry'][7] == pytest.approx(8.96, 0.1))
    model = pv.default("PVwattsNone")
    model.SolarResource.solar_resource_data = data
    model.execute()
    aep = model.Outputs.annual_energy
    model.SolarResource.solar_resource_file = solar
    model.execute()
    assert(aep == pytest.approx(model.Outputs.annual_energy, 1))


def test_wind():
    wind = str(Path(__file__).parent / "AR Northwestern-Flat Lands.srw")
    data = tools.SRW_to_wind_data(wind)
    assert (data['fields'] == [1, 2, 4, 3, 1, 2, 4, 3, 1, 2, 4, 3, 1, 2, 4, 3])
    assert (data['heights'] == [50, 50, 50, 50, 80, 80, 80, 80, 110, 110, 110, 110, 140, 140, 140, 140])
    assert (data['data'][0] == [9.587, 0.953420183, 173, 9.466, 10.247, 0.950086356, 174, 11.637, 10.627, 0.946649889,
                                175, 13.249, 10.997, 0.94340982, 175, 14.509])

    wind_model = wp.new()
    wind_model.Resource.wind_resource_data = data
    returned_data = wind_model.Resource.wind_resource_data['data'][0]
    for i, d in enumerate(data['data'][0]):
        assert (d == pytest.approx(returned_data[i], 1e-3))


def test_urdb():
    urdb = str(Path(__file__).parent / "urdbv7.json")
    with open(urdb, 'r') as file:
        urdb_data = json.load(file)
    ur5 = tools.URDBv7_to_ElectricityRates(urdb_data)

    ec_tou = [1, 1, 100, 0, 0.070768997073173523, 0,
              1, 2, 9.9999996802856925e+37, 0, 0.082948997616767883, 0,
              2, 1, 100, 0, 0.056908998638391495, 0,
              2, 2, 9.9999996802856925e+37, 0, 0.069078996777534485, 0]

    dc_tou = [1, 1, 100, 19.538999557495117,
              1, 2, 9.9999996802856925e+37, 13.093000411987305,
              2, 1, 100, 8.0909996032714844,
              2, 2, 9.9999996802856925e+37, 4.6760001182556152]

    flat_mat = [0, 1, 100, 4, 0, 2, 1e+38, 6.46,
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


def test_resourcefilefetcher():

    # please get your own API key from here https://developer.nrel.gov/signup/
    NREL_API_KEY = ''
    NREL_API_EMAIL = ''

    lon_lats = [(-105.1800775, 39.7383155)]  # golden CO

    resource_dir = str(Path(__file__).parent / "tmp")

    # --- fetch solar tmy file from psm3-tmy using default parameters ---
    solarfetcher = tools.FetchResourceFiles(
                    tech='solar',
                    nrel_api_key=NREL_API_KEY,
                    nrel_api_email=NREL_API_EMAIL,
                    resource_dir=resource_dir)
    solarfetcher.fetch(lon_lats)

    # --- read csv and confirm dimensions ---
    solar_path_dict = solarfetcher.resource_file_paths_dict
    solar_fp = solar_path_dict[lon_lats[0]]
    solar_csv = pd.read_csv(solar_fp)
    num_timesteps = 8760
    assert solar_csv.shape[0] == num_timesteps+2

    # --- test legacy 'pv' instead of 'solar'---
    solarfetcher = tools.FetchResourceFiles(
                    tech='pv',
                    nrel_api_key=NREL_API_KEY,
                    nrel_api_email=NREL_API_EMAIL,
                    resource_dir=resource_dir)
    solarfetcher.fetch(lon_lats)

    # --- read csv and confirm dimensions ---
    solar_path_dict = solarfetcher.resource_file_paths_dict
    solar_fp = solar_path_dict[lon_lats[0]]
    solar_csv = pd.read_csv(solar_fp)
    num_timesteps = 8760
    assert solar_csv.shape[0] == num_timesteps+2

    # --- fetch solar single-year 30-min file from psm3 ---
    solarfetcher = tools.FetchResourceFiles(
                    tech='solar',
                    nrel_api_key=NREL_API_KEY,
                    nrel_api_email=NREL_API_EMAIL,
                    resource_dir=resource_dir,
                    resource_type='psm3',
                    resource_year='2018',
                    resource_interval_min=30)
    solarfetcher.fetch(lon_lats)

    # --- read csv and confirm dimensions ---
    solar_path_dict = solarfetcher.resource_file_paths_dict
    solar_fp = solar_path_dict[lon_lats[0]]
    solar_csv = pd.read_csv(solar_fp)
    num_timesteps = 17520
    assert solar_csv.shape[0] == num_timesteps+2

    # --- fetch solar tgy for 2018 from psm3-tmy ---
    solarfetcher = tools.FetchResourceFiles(
                    tech='solar',
                    nrel_api_key=NREL_API_KEY,
                    nrel_api_email=NREL_API_EMAIL,
                    resource_dir=resource_dir,
                    resource_type='psm3-tmy',
                    resource_year='tgy-2018')
    solarfetcher.fetch(lon_lats)

    # --- read csv and confirm dimensions ---
    solar_path_dict = solarfetcher.resource_file_paths_dict
    solar_fp = solar_path_dict[lon_lats[0]]
    solar_csv = pd.read_csv(solar_fp)
    num_timesteps = 8760
    assert solar_csv.shape[0] == num_timesteps+2

    # --- fetch 5-minute data for 2018 from psm3-5min ---
    # this NSRDB API endpoint not working properly as of 8/21/2020
    #solarfetcher = tools.FetchResourceFiles(
    #                tech='solar',
    #                nrel_api_key=NREL_API_KEY,
    #                nrel_api_email=NREL_API_EMAIL,
    #                resource_dir=resource_dir,
    #                resource_type='psm3-5min',
    #                resource_interval_min=5,
    #                resource_year='2018')
    #solarfetcher.fetch(lon_lats)

    # --- read csv and confirm dimensions ---
    #solar_path_dict = solarfetcher.resource_file_paths_dict
    #solar_fp = solar_path_dict[lon_lats[0]]
    #solar_csv = pd.read_csv(solar_fp)
    #num_timesteps = 175200
    #assert solar_csv.shape[0] == num_timesteps+2

    # --- fetch wind ---
    wtkfetcher = tools.FetchResourceFiles(
        tech='wind',
        nrel_api_key=NREL_API_KEY,
        nrel_api_email=NREL_API_EMAIL,
        resource_dir=resource_dir)
    wtkfetcher.fetch(lon_lats)

    # --- read csv and confirm dimensions ---
    wtk_path_dict = wtkfetcher.resource_file_paths_dict
    wtk_fp = wtk_path_dict[lon_lats[0]]
    wtk_csv = pd.read_csv(wtk_fp)
    assert wtk_csv.shape == (8764, 10)

    shutil.rmtree(resource_dir)
