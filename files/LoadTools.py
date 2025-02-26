"""
A list of hour of year that ends each month. Given an hourly array,
hourly_data[max_hrs[0]:max_hrs[1]] would return all of the data from January.
Multiply indicies by steps per hour to do subhourly data.
"""
max_hrs = [0, 744, 1416, 2160, 2880, 3624, 4344, 5088, 5832, 6552, 7296, 8016, 8760]

def get_monthly_peaks(load_profile, steps_per_hour):
    """
    Get a list of monthly peaks from a grid usage profile
    Developed to create year 0 peaks for billing demand functions in utility rate code

    :param: load_profile:
        list of one year of load data in floats. Length is 8760 * steps_per_hour
    :param: steps_per_hour:
        integer of steps per hour. 1=hourly data, 4=15 min data, etc
    :return: list of peak values, length 12
    """
    peaks = []
    for i in range(0, 12):
        peaks.append(max(load_profile[max_hrs[i]:max_hrs[i + 1]]))
    return peaks
