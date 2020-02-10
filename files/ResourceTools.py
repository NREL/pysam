import csv
import os
from collections import defaultdict


def TMY_CSV_to_solar_data(filename):
    """
    Format a TMY csv file as 'solar_resource_data' dictionary for use in PySAM.
    :param: filename:
        any csv resource file formatted according to NSRDB
    :return: dictionary for PySAM.Pvwattsv7.Pvwattsv7.SolarResource, and other models
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
    :param: filename:
        srw wind resource file
    :return: dictionary for PySAM.Windpower.Windpower.Resource
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
    :param: urdb_response
        dictionary with response fields following https://openei.org/services/doc/rest/util_rates/?version=7
    :return: dictionary for PySAM.UtilityRate5.UtilityRate5.ElectricityRates
    """

    def try_get_schedule(urdb_name, data_name):
        if urdb_name in urdb_response.keys():
            data[data_name] = urdb_response[urdb_name]
            for i in range(12):
                for j in range(24):
                    data[data_name][i][j] += 1

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
                    units = ['kwh', 'kw']
                    if 'unit' in entry.keys():
                        if entry['unit'].lower() not in units:
                            raise RuntimeError("UtilityRateDatabase error: unrecognized unit in rate structure")
                    mat.append((i + 1, j + 1, tier_max, 0.0, rate, sell))
            data[data_name] = mat

    data = dict()
    data['en_electricity_rates'] = 1

    rules = urdb_response['dgrules']
    if rules == "Net Metering":
        data['ur_metering_option'] = 0
    elif rules == "Net Billing Instantaneous":
        data['ur_metering_option'] = 2
    elif rules == "Net Billing Hourly":
        data['ur_metering_option'] = 3
    elif rules == "Buy All Sell All":
        data['ur_metering_option'] = 4

    if 'fixedchargefirstmeter' in urdb_response.keys():
        fixed_charge = urdb_response['fixedchargefirstmeter']
        fixed_charge_units = urdb_response['fixedchargeunits']
        if fixed_charge_units == "$/day":
            fixed_charge *= 365/30
        elif fixed_charge_units == "$/year":
            fixed_charge /= 12
        data['ur_fixed_monthly_charge'] = fixed_charge

    if 'mincharge' in urdb_response.keys():
        min_charge = urdb_response['mincharge']
        min_charge_units = urdb_response['minchargeunits']
        if min_charge_units == "$/year":
            data['ur_annual_min_charge'] = min_charge
        else:
            if min_charge_units == "$/day":
                min_charge *= 365 / 30
            data['ur_monthly_min_charge'] = min_charge

    try_get_schedule('energyweekdayschedule', 'ur_ec_sched_weekday')
    try_get_schedule('energyweekendschedule', 'ur_ec_sched_weekend')

    if 'flatdemandmonths' in urdb_response.keys():
        data['ur_dc_enable'] = 1
        flat_mat = []
        flat_demand = urdb_response['flatdemandmonths']
        for i in range(12):
            flat_mat.append([i, 1, 1e38, flat_demand[i]])
        data['ur_dc_flat_mat'] = flat_mat

    try_get_rate_structure('energyratestructure', 'ur_ec_tou_mat')
    try_get_rate_structure('flatdemandstructure', 'ur_dc_flat_mat')
    try_get_rate_structure('demandratestructure', 'ur_dc_tou_mat')
    try_get_schedule('demandweekdayschedule', 'ur_dc_sched_weekday')
    try_get_schedule('demandweekendschedule', 'ur_dc_sched_weekend')

    return data
