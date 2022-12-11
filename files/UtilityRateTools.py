def URDBv8_to_ElectricityRates(urdb_response):
    """
    Formats response from Utility Rate Database API version 8 for use in PySAM
        i.e.
            model = PySAM.UtilityRate5.new()
            rates = PySAM.ResourceTools.URDBv8_to_ElectricityRates(urdb_response)
            model.ElectricityRates.assign(rates)

    This function does the additional processing when these rate features
    are present. 

    :param: urdb_response:
        dictionary with response fields following
        https://openei.org/services/doc/rest/util_rates/?version=8
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
        supported_units = {
            "kwh" : 0,
            "kwh/kw" : 1,
            "kwh daily" : 2,
            "kwh/kw daily" : 3
        }
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
                    units = 0
                    if 'unit' in entry.keys():
                        try:
                            units = supported_units[entry['unit'].lower()]
                        except KeyError:
                            raise RuntimeError("UtilityRateDatabase error: unrecognized unit in rate structure")
                    mat.append((i + 1, j + 1, tier_max, units, rate, sell))
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
        for month, period in enumerate(flat_demand):
            tiers = []
            for r in flat_demand_structure:
                if r[0] == int(period + 1):
                    tiers.append(r)
                    
            if len(tiers) == 0:
                raise ValueError("flatdemandstructure missing period number ", period)
            for t in tiers:
                month_row = []
                month_row.append(month)
                month_row += [t[i] for i in (1, 2, 3)]
                flat_mat.append(month_row)
        urdb_data['ur_dc_flat_mat'] = flat_mat
    # Fill out an empty flat rate structure if the rate has TOU demand but not flat demand    
    elif "demandratestructure" in urdb_response.keys():
        urdb_data['ur_dc_enable'] = 1
        # Enumerate a dc_flat table with $0/kW in 12 months
        flat_mat = []
        for i in range(0, 12):
            month_mat = [i, 1, 1e38, 0]
            flat_mat.append(month_mat)
        urdb_data['ur_dc_flat_mat'] = flat_mat
    else:
        urdb_data['ur_dc_enable'] = 0

    if urdb_data['ur_dc_enable'] == 1 and "ur_dc_tou_mat" not in urdb_data.keys():
        urdb_data['ur_dc_tou_mat'] = [[1, 1, 1e38, 0], ]
        urdb_data['ur_dc_sched_weekday'] = [[1] * 24 for i in range(12)]
        urdb_data['ur_dc_sched_weekend'] = urdb_data['ur_dc_sched_weekday']

    has_billing_demand = False

    lookback_range = 0
    if 'lookbackrange' in urdb_response.keys():
        lookback_range = urdb_response['lookbackrange']
        urdb_data['ur_billing_demand_lookback_period'] = lookback_range 
    
    lbp = 0
    if 'lookbackpercent' in urdb_response.keys():
        lbp = urdb_response['lookbackpercent'] * 100.0
        
        # Some demand ratchets apply in every month - use this as the default if lookbackmonths is not specified
        lbm = [True] * 12
        if 'lookbackmonths' in urdb_response.keys():
            lbm = urdb_response['lookbackmonths']
        
        lookback_percentages = [ [0, 0] ] * 12
        for i in range(0, len(lookback_percentages)):
            if lbm[i]:
                lookback_percentages[i][0] = lbp

        urdb_data['ur_billing_demand_lookback_percentages'] = lookback_percentages
    
    has_billing_demand = lookback_range > 0 or lbp > 0

    if has_billing_demand:
        urdb_data['ur_enable_billing_demand'] = True
        # Handle variables that aren't currently in URDB but are in SAM
        urdb_data['ur_billing_demand_minimum'] = 0

        dc_tou = urdb_data['ur_dc_tou_mat']
        max_period = 0
        for i in range(0, len(dc_tou)):
            if dc_tou[i][0] > max_period:
                max_period = dc_tou[i][0] 
        
        bd_periods = []
        for i in range(0, max_period):
            bd_periods.append([i+1, 1])
        
        urdb_data['ur_dc_billing_demand_periods'] = bd_periods

        print("Billing Demand Notice.\nThis rate includes billing demand adjustments and/or demand ratchets that may not be accurately reflected in the data downloaded from the URDB. Please check the information in the Description under Description and Applicability and review the rate sheet to be sure the billing demand inputs are correct.")
    else:
        urdb_data['ur_enable_billing_demand'] = False

    return urdb_data