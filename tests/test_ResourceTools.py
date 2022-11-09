import sys
import os
sys.path.append('.')
import shutil
import pytest
from pathlib import Path
import json

from dotenv import load_dotenv
import csv

import PySAM.ResourceTools as tools  # change back to module import
import PySAM.Windpower as wp
import PySAM.Pvwattsv8 as pv


def test_solar_nrel():
    solar = str(Path(__file__).parent / "blythe_ca_33.617773_-114.588261_psmv3_60_tmy.csv")
    data = tools.SAM_CSV_to_solar_data(solar)
    assert (data['lat'] == 33.61)
    assert (data['lon'] == -114.58)
    assert (data['dn'][7] == 262)
    assert (data['df'][7] == 16)
    assert (data['gh'][7] == 27)
    assert (data['tdry'][7] == pytest.approx(8.96, 0.1))
    assert (data['tdew'][7] == pytest.approx(-0.03, 0.1))
    assert (data['rhum'][7] == pytest.approx(25.0, 0.1))
    assert (data['wdir'][7] == pytest.approx(351, 0.1))

    model = pv.default("PVwattsNone")
    model.SolarResource.solar_resource_data = data
    model.execute()
    aep = model.Outputs.annual_energy
    model.SolarResource.solar_resource_file = solar
    model.execute()
    assert(aep == pytest.approx(model.Outputs.annual_energy, 1))

def test_solar_nasa():
    solar = str(Path(__file__).parent / "blythe_ca_33.617773_-114.588261_nasa_60_tmy.csv")
    data = tools.SAM_CSV_to_solar_data(solar)
    assert (data['lat'] == 33.617773)
    assert (data['lon'] == -114.588261)
    assert (data['dn'][7] == 43.727)
    assert (data['df'][7] == 70.734)
    assert (data['gh'][7] == 76.75)
    assert (data['tdry'][7] == pytest.approx(7.94, 0.1))
    assert (data['tdew'][7] == pytest.approx(-4.66, 0.1))
    assert (data['rhum'][7] == pytest.approx(40.06, 0.1))
    assert (data['wdir'][7] == pytest.approx(84.77, 0.1))

    model = pv.default("PVwattsNone")
    model.SolarResource.solar_resource_data = data
    model.execute()
    aep = model.Outputs.annual_energy
    model.SolarResource.solar_resource_file = solar
    model.execute()
    assert(aep == pytest.approx(model.Outputs.annual_energy, 1))


def test_wind_nrel():
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

def test_wind_nasa():
    wind = str(Path(__file__).parent / "nasa_blythe_test_wind_data.srw")
    data = tools.SRW_to_wind_data(wind)
    assert (data['fields'] == [1, 2, 3, 4, 3, 4, 3, 4, 3, 2])
    assert (data['heights'] == [2, 2, 2, 2, 10, 10, 50, 50, 80.0, 80.0])
    assert (data['data'][0] == [17.569, 0.97, 0.338, 146.31, 0.514, 151.876, 0.709, 154.564, 1.84, 0.996])

    wind_model = wp.new()
    wind_model.Resource.wind_resource_data = data
    returned_data = wind_model.Resource.wind_resource_data['data'][0]
    for i, d in enumerate(data['data'][0]):
        assert (d == pytest.approx(returned_data[i], 1e-3))


def test_resourcefilefetcher():
    load_dotenv()
    # please get your own API key from here https://developer.nrel.gov/signup/
    NREL_API_KEY = os.environ.get('NREL_API_KEY')
    NREL_API_EMAIL = os.environ.get('NREL_API_EMAIL')

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
    with open(solar_fp, mode='r') as f:
        reader = csv.DictReader(f)
        list(reader)
        num_timesteps = 8760
        assert reader.line_num == num_timesteps + 3

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
    with open(solar_fp, mode='r') as f:
        solar_csv = csv.DictReader(f)
        list(solar_csv)
        num_timesteps = 8760
        assert solar_csv.line_num == num_timesteps + 3

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
    with open(solar_fp, mode='r') as f:
        solar_csv = csv.DictReader(f)
        list(solar_csv)
        num_timesteps = 17520
        assert solar_csv.line_num == num_timesteps + 3

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
    with open(solar_fp, mode='r') as f:
        solar_csv = csv.DictReader(f)
        list(solar_csv)
        num_timesteps = 8760
        assert solar_csv.line_num == num_timesteps + 3

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
    with open(wtk_fp, mode='r') as f:
        wtk_csv = csv.DictReader(f)
        list(wtk_csv)
        assert wtk_csv.line_num == 8764 + 1

    shutil.rmtree(resource_dir)
