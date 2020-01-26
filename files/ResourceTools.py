import csv
import os
from collections import defaultdict, OrderedDict

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
