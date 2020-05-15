# --- python built ins ---
import csv
import os
from collections import defaultdict
import concurrent.futures as cf
import itertools
import io
import requests
import copy
from requests.adapters import HTTPAdapter
from requests.packages.urllib3.util.retry import Retry

# --- external libraries ---
import pandas as pd
import numpy as np


def TMY_CSV_to_solar_data(filename):
    """
    Format a TMY csv file as 'solar_resource_data' dictionary for use in PySAM.
    For more information about TMY CSV file format, see https://sam.nrel.gov/weather-data/weather-data-publications.html

    :param filename: Any csv resource file formatted according to NSRDB

    :return: Dictionary for PySAM.Pvwattsv7.Pvwattsv7.SolarResource, and other models
    """
    if not os.path.isfile(filename):
        raise FileNotFoundError(filename + " does not exist.")
    wfd = defaultdict(list)
    with open(filename) as file_in:
        info = []
        for i in range(2):
            info.append(file_in.readline())
            info[i] = info[i].split(",")
        if "Time Zone" not in info[0]:
            raise ValueError("`Time Zone` field not found in solar resource file.")
        latitude = info[1][info[0].index("Latitude")]
        longitude = info[1][info[0].index("Longitude")]
        tz = info[1][info[0].index("Time Zone")]
        elev = info[1][info[0].index("Elevation")]
        reader = csv.DictReader(file_in)
        for row in reader:
            for col, dat in row.items():
                if len(col) > 0:
                    wfd[col].append(float(dat))

        weather = dict()
        weather['tz'] = float(tz)
        weather['elev'] = float(elev)
        weather['lat'] = float(latitude)
        weather['lon'] = float(longitude)
        weather['year'] = wfd.pop('Year')
        weather['month'] = wfd.pop('Month')
        weather['day'] = wfd.pop('Day')
        weather['hour'] = wfd.pop('Hour')
        weather['minute'] = wfd.pop('Minute')
        weather['dn'] = wfd.pop('DNI')
        weather['df'] = wfd.pop('DHI')
        weather['gh'] = wfd.pop('GHI')
        weather['wspd'] = wfd.pop('Wind Speed')
        weather['tdry'] = wfd.pop('Temperature')

        return weather


def SRW_to_wind_data(filename):
    """
    Format as 'wind_resource_data' dictionary for use in PySAM.
    For more information about SRW file format, see https://sam.nrel.gov/weather-data/weather-data-publications.html

    :param filename: A .srw wind resource file

    :return: Dictionary for PySAM.Windpower.Windpower.Resource
    """
    if not os.path.isfile(filename):
        raise FileNotFoundError(filename + " does not exist.")
    data_dict = dict()
    field_names = ('Temperature', 'Pressure', 'Speed', 'Direction')
    fields_id = (1, 2, 3, 4)
    with open(filename) as file_in:
        file_in.readline()
        file_in.readline()
        fields = str(file_in.readline().strip()).split(',')
        file_in.readline()
        heights = str(file_in.readline().strip()).split(',')
        data_dict['heights'] = [float(i) for i in heights]
        data_dict['fields'] = []

        for field_name in fields:
            if field_name not in field_names:
                raise ValueError(field_name + " required for wind data")
            data_dict['fields'].append(field_names.index(field_name) + 1)

        data_dict['data'] = []
        reader = csv.reader(file_in)
        for row in reader:
            data_dict['data'].append([float(i) for i in row])

        return data_dict


def URDBv7_to_ElectricityRates(urdb_response):
    """
    Formats response from Utility Rate Database API version 7 for use in PySAM
        i.e.
            model = PySAM.UtilityRate5.new()
            rates = PySAM.ResourceTools.URDBv7_to_ElectricityRates(urdb_response)
            model.ElectricityRates.assign(rates)

    :param: urdb_response:
        dictionary with response fields following https://openei.org/services/doc/rest/util_rates/?version=7
    :return: dictionary for PySAM.UtilityRate5.UtilityRate5.ElectricityRates
    """
    urdb_data = dict()
    urdb_data['en_electricity_rates'] = 1

    def try_get_schedule(urdb_name, data_name):
        if urdb_name in urdb_response.keys():
            urdb_data[data_name] = urdb_response[urdb_name]
            for i in range(12):
                for j in range(24):
                    urdb_data[data_name][i][j] += 1

    def try_get_rate_structure(urdb_name, data_name):
        mat = []
        if urdb_name in urdb_response.keys():
            structure = urdb_response[urdb_name]
            for i, period in enumerate(structure):
                for j, entry in enumerate(period):
                    rate = entry['rate']
                    if 'adj' in entry.keys():
                        rate += entry['adj']
                    tier_max = 1e38
                    if 'max' in entry.keys():
                        tier_max = entry['max']
                    sell = 0
                    if 'sell' in entry.keys():
                        sell = entry['sell']
                    if 'unit' in entry.keys():
                        if entry['unit'].lower() != "kWh".lower():
                            raise RuntimeError("UtilityRateDatabase error: unrecognized unit in rate structure")
                    mat.append((i + 1, j + 1, tier_max, 0.0, rate, sell))
            urdb_data[data_name] = mat

    def try_get_demand_structure(urdb_name, data_name):
        mat = []
        if urdb_name in urdb_response.keys():
            structure = urdb_response[urdb_name]
            for i, period in enumerate(structure):
                for j, entry in enumerate(period):
                    rate = entry['rate']
                    if 'adj' in entry.keys():
                        rate += entry['adj']
                    tier_max = 1e38
                    if 'max' in entry.keys():
                        tier_max = entry['max']
                    if 'unit' in entry.keys():
                        if entry['unit'].lower() != "kW".lower():
                            raise RuntimeError("UtilityRateDatabase error: unrecognized unit in rate structure")
                    mat.append((i + 1, j + 1, tier_max, rate))
            if data_name:
                urdb_data[data_name] = mat
            else:
                return mat

    if "dgrules" in urdb_response.keys():
        rules = urdb_response['dgrules']  # dgrules
        if rules == "Net Metering":
            urdb_data['ur_metering_option'] = 0
        elif rules == "Net Billing Instantaneous":
            urdb_data['ur_metering_option'] = 2
        elif rules == "Net Billing Hourly":
            urdb_data['ur_metering_option'] = 3
        elif rules == "Buy All Sell All":
            urdb_data['ur_metering_option'] = 4
    else:
        # if no metering option provided, assume Net Metering
        urdb_data['ur_metering_option'] = 0

    if 'fixedchargefirstmeter' in urdb_response.keys() and 'fixedchargeunits' in urdb_response.keys():
        fixed_charge = urdb_response['fixedchargefirstmeter']
        fixed_charge_units = urdb_response['fixedchargeunits']
        if fixed_charge_units == "$/day":
            fixed_charge *= 365 / 30
        elif fixed_charge_units == "$/year":
            fixed_charge /= 12
        urdb_data['ur_monthly_fixed_charge'] = fixed_charge

    if 'mincharge' in urdb_response.keys():
        min_charge = urdb_response['mincharge']
        min_charge_units = urdb_response['minchargeunits']
        if min_charge_units == "$/year":
            urdb_data['ur_annual_min_charge'] = min_charge
        else:
            if min_charge_units == "$/day":
                min_charge *= 365 / 30
            urdb_data['ur_monthly_min_charge'] = min_charge

    try_get_schedule('energyweekdayschedule', 'ur_ec_sched_weekday')
    try_get_schedule('energyweekendschedule', 'ur_ec_sched_weekend')
    try_get_rate_structure('energyratestructure', 'ur_ec_tou_mat')

    try_get_demand_structure('demandratestructure', 'ur_dc_tou_mat')
    try_get_schedule('demandweekdayschedule', 'ur_dc_sched_weekday')
    try_get_schedule('demandweekendschedule', 'ur_dc_sched_weekend')

    flat_demand_structure = try_get_demand_structure('flatdemandstructure', None)

    if 'flatdemandmonths' in urdb_response.keys():
        urdb_data['ur_dc_enable'] = 1
        flat_mat = []
        flat_demand = urdb_response['flatdemandmonths']
        for month, tier in enumerate(flat_demand):
            periods = [r for r in flat_demand_structure if r[0] == int(tier + 1)]
            month_row = []
            for p in periods:
                month_row.append(month)
                month_row += [p[i] for i in (1, 2, 3)]
            flat_mat.append(month_row)
        urdb_data['ur_dc_flat_mat'] = flat_mat

    return urdb_data


class FetchResourceFiles():
    """
    Download U.S. solar and wind resource data for SAM from NRELs developer network
    https://developer.nrel.gov/

    :param: tech (str): one of 'wind' or 'pv'
    :param: workers (int): number of threads to use when parellelizing downloads
    :param: resource_year (int): year to grab resources from.
        can be 'tmy' for solar
    :param: resource_interval_min (int): time interval of resource data
    :param: nrel_api_key (str): NREL developer API key, available here https://developer.nrel.gov/signup/
    nrel_api_email (str): email associated with nrel_api_key

    """

    def __init__(self, tech, nrel_api_key, nrel_api_email,
                 workers=1,
                 resource_year='tmy',
                 resource_interval_min=60,
                 resource_dir=None):

        self.tech = tech
        self.nrel_api_key = nrel_api_key
        self.nrel_api_email = nrel_api_email

        self.resource_year = resource_year
        self.resource_interval_min = resource_interval_min
        self.workers = workers

        # --- Make folder to store resource_files ---
        self.SAM_resource_dir = resource_dir
        if not self.SAM_resource_dir:
            self.SAM_resource_dir = os.path.join(os.getcwd(), 'data', 'PySAM Downloaded Weather Files')
        if not os.path.exists(self.SAM_resource_dir):
            os.makedirs(self.SAM_resource_dir)

        if tech == 'pv':
            self.data_function = self._NSRDB_worker
        elif tech == 'wind':
            self.data_function = self._windtk_worker

            if self.resource_year == 'tmy':  # tmy not available for wind
                self.resource_year = 2012

        else:
            raise NotImplementedError('Please write a wrapper to fetch data for the new technology type {}'.format(tech))

    def _requests_retry_session(self, retries=10,
                                backoff_factor=1,
                                status_forcelist=(429, 500, 502, 504),
                                session=None):
        """https://www.peterbe.com/plog/best-practice-with-retries-with-requests"""
        session = session or requests.Session()
        session.verify = False
        retry = Retry(
            total=retries,
            read=retries,
            connect=retries,
            backoff_factor=backoff_factor,
            status_forcelist=status_forcelist,
        )
        adapter = HTTPAdapter(max_retries=retry)
        session.mount('http://', adapter)
        session.mount('https://', adapter)
        return session

    def _csv_to_srw(self, raw_csv):
        #TODO: convert gen profiles to local tz

        # --- grab df ---
        for_df = copy.deepcopy(raw_csv)
        df = pd.read_csv(for_df, header=3)

        # --- grab header data ---
        for_header = copy.deepcopy(raw_csv)
        header = pd.read_csv(for_header, nrows=3, header=None).values
        site_id = header[0, 1]
        site_tz = header[0, 3]
        site_lon = header[1, 1]
        site_lat = header[2, 1]
        site_year = df.iloc[0]['Year']

        # --- create header lines ---
        h1 = np.array([int(site_id), 'city??', 'state??', 'USA', site_year,
                       site_lat, site_lon, 'elevation??', 1, 8760])  # meta info
        h2 = np.array(["WTK .csv converted to .srw for SAM", None, None,
                       None, None, None, None, None, None, None])  # descriptive text
        h3 = np.array(['temperature', 'pressure', 'direction',
                       'speed', None, None, None, None, None, None])  # variables
        h4 = np.array(['C', 'atm', 'degrees', 'm/s', None,
                       None, None, None, None, None])  # units
        h5 = np.array([100, 100, 100, 100, None, None,
                       None, None, None, None])  # hubheight
        header = pd.DataFrame(np.vstack([h1, h2, h3, h4, h5]))
        assert header.shape == (5, 10)

        # --- resample to 8760 ---
        df['datetime'] = pd.to_datetime(
            df[['Year', 'Month', 'Day', 'Hour', 'Minute']])
        df.set_index('datetime', inplace=True)
        df = df.resample('H').first()

        # --- drop leap days ---
        df = df.loc[~((df.index.month == 2) & (df.index.day == 29))]

        # --- convert K to celsius ---
        df['temperature'] = df['air temperature at 2m (K)'] - 273.15

        # --- convert PA to atm ---
        df['pressure'] = df['surface air pressure (Pa)'] / 101325

        # --- rename ---
        rename_dict = {'wind speed at 100m (m/s)': 'speed',
                       'wind direction at 100m (deg)': 'direction'}
        df.rename(rename_dict, inplace=True, axis='columns')

        # --- clean up ---
        df = df[['temperature', 'pressure', 'direction', 'speed']]
        df.columns = [0, 1, 2, 3]
        assert df.shape == (8760, 4)

        out = pd.concat([header, df], axis='rows')
        out.reset_index(drop=True, inplace=True)
        return out

    def _NSRDB_worker(self, job):
        """Query NSRDB to save .csv 8760 of TMY solar data. To be applied on row with a 'lat' and 'long column."""

        # --- unpack job ---
        lon, lat = job

        # --- initialize sesson ---
        retry_session = self._requests_retry_session()

        # --- Intialize File Path ---
        file_path = os.path.join(
            self.SAM_resource_dir, "{}_{}_psm3_{}_{}.csv".format(lat, lon, self.resource_interval_min, self.resource_year))

        # --- See if file path already exists ---
        if os.path.exists(file_path):
            return file_path  # file already exists, just return path...

        else:
            print("Downloading NSRDB file for {}_{}...".format(lat, lon))

            # --- Find url for closest point ---
            lookup_base_url = 'https://developer.nrel.gov/api/solar/'
            lookup_query_url = "nsrdb_data_query.json?api_key={}&wkt=POINT({}+{})".format(self.nrel_api_key, lon, lat)
            lookup_url = lookup_base_url + lookup_query_url
            lookup_response = retry_session.get(lookup_url)

            if lookup_response.ok:
                lookup_json = lookup_response.json()
                links = lookup_json['outputs'][0]['links']
                year_url_dict = {d['year']: d['link'] for d in links if d['interval'] == self.resource_interval_min}
                year_url = year_url_dict[self.resource_year]
                year_url = year_url.replace('yourapikey', self.nrel_api_key).replace(
                    'youremail', self.nrel_api_email)

                # --- Get year data ---
                year_response = retry_session.get(year_url)
                if year_response.ok:
                    # --- Convert response to string, read as pandas df, write to csv ---
                    csv = io.StringIO(year_response.text)
                    df = pd.read_csv(csv)
                    df.to_csv(file_path, index=False)
                    return file_path
                else:
                    return 'error at year_response'

            else:
                return 'error at lookup_response'

    def _windtk_worker(self, job):

        # --- unpack job ---
        lon, lat = job

        # --- initialize sesson ---
        retry_session = self._requests_retry_session()

        # --- Intialize File Path ---
        file_path = os.path.join(
            self.SAM_resource_dir, "{}_{}_wtk_{}_{}.srw".format(lat, lon, self.resource_interval_min, self.resource_year))

        # --- See if file path already exists ---
        if os.path.exists(file_path):
            return file_path  # file already exists, just return path...

        else:
            print("Downloading wind toolkit file for {}_{}...".format(lat, lon))

            # --- Find url for closest point ---
            year_base_url = 'https://developer.nrel.gov/api/wind-toolkit/wind/'
            year_query_url = "wtk_download.csv?api_key={}&wkt=POINT({}+{})&attributes=wind_speed,wind_direction,power,temperature,pressure&names={}&utc=true&email={}".format(
                self.nrel_api_key, lon, lat, self.resource_year, self.nrel_api_email)
            year_url = year_base_url + year_query_url
            year_response = retry_session.get(year_url)

            if year_response.ok:
                # --- Convert response to string, read as pandas df, write to csv ---
                raw_csv = io.StringIO(year_response.text)
                df = self._csv_to_srw(raw_csv)
                df.to_csv(file_path, index=False, header=False, na_rep='')
                return file_path
            else:
                return 'error at year_response'

    def fetch(self, points):
        """
        Creates dict with {region:path_to_SAM_resource_file}.

        Input
        -----
        points(iterable): iterable of lon/lat tuples, i.e. Shapely Points
        """

        print('\n')
        print('Beginning data download for {} using {} thread workers'.format(self.tech, self.workers))

        # --- Initialize Session w/ retries ---
        if self.workers > 1:
            with cf.ThreadPoolExecutor(max_workers=self.workers) as executor:
                futures = [executor.submit(self.data_function, job) for job in points]
                results = [f.result() for f in futures]

        else:
            results = []
            for job in points:
                results.append(self.data_function(job))

        self.resource_file_paths = results
        self.resource_file_paths_dict = dict(zip(points, results))
        return self
