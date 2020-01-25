import csv
import os
from collections import defaultdict

import numpy as np


def TMY_CSV_to_solar_data(filename):
    """
    Format a TMY csv file as 'solar_resource_data' dictionary for use in PySAM.
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
        weather['lat'] = latitude
        weather['lon'] = longitude
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
    """
    if not os.path.isfile(filename):
        raise FileNotFoundError(filename + " does not exist.")
    data_dict = defaultdict(defaultdict)
    with open(filename) as file_in:
        file_in.readline()
        file_in.readline()
        reader = csv.DictReader(file_in)
        line = 0
        for row in reader:
            if line == 1:
                heights = list(row.values())
                heights_keys = [str(i) for i in heights]
                for key in set(heights_keys):
                    data_dict[key] = defaultdict(list)
            if line > 1:
                n = 0
                for col, dat in row.items():
                    height_dict = data_dict[heights_keys[n]]
                    height_dict[col].append(float(dat))
                    n += 1
            line += 1

    n_records = []
    heights = data_dict.keys()
    n_heights = len(heights)
    field_names = ('Temperature', 'Pressure', 'Speed', 'Direction')
    for height, meas in data_dict.items():
        for key in field_names:
            if key not in meas.keys():
                raise ValueError(key + " required for wind data at hub height " + height)
            n_records.append(len(meas[key]))

    n_records = set(n_records)
    if len(n_records) > 1:
        raise ValueError("All arrays must be same length, corresponding to number of data records.")
    n_records = n_records.pop()

    wind_data_matrix = np.zeros((n_records, 4 * n_heights))
    heights_id = []
    fields_id = []
    for height in heights:
        heights_id += [int(height)] * 4
        for col in range(4):
            wind_data_matrix[:, col] = data_dict[height][field_names[col]]
            fields_id.append(col + 1)

    return dict({'heights': heights_id, 'fields': fields_id, 'data': wind_data_matrix.tolist()})
