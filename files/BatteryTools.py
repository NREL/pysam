import math


def size_li_ion_battery(input_dict):
    """
    All efficiencies and rates in percentages, 0-100.

    Inverter efficiency depends on which inverter model is being used, `inverter_model`.

    :param input_dict:
        batt_chem: int
            Lithium-ion (1) or Lead-Acid (0)
        batt_Qfull: float, Ah
            capacity of single cell
        batt_Vnom_default: float, V
            voltage of single cell

        Required only if batt_chem is False:
            LeadAcid_q10: float 0-100, Ah
                10 hour discharge rate
            LeadAcid_q20: float 0-100, Ah
                20 hour discharge rate
            LeadAcid_tn: int, hour
                hour for custom hour discharge rate
            LeadAcid_qn: float 0-100, Ah
                n-hour discharge rate

        batt_ac_or_dc: bool
            True if ac-connected
        desired_power: float, kW
            power of the battery
        desired_capacity: float, kWh
            capacity
        desired_voltage: float, V
            voltage
        size_by_ac_not_dc: bool, default False
            True for sizing battery as kWAC and kWhAC
        batt_dc_ac_efficiency: float 0-100, required only if size_by_ac_not_dc is True
            AC to DC power in conversion
        inverter_eff: float 0-100, required only if batt_ac_or_dc is False
            AC to DC power from inverter
        batt_dc_dc_efficiency: float 0-100, optional
            DC to DC power conversion in battery management system

    :return: output_dict:
        voltage: float, V
            computed
        power: float
            computed
        batt_computed_bank_capacity: float
            computed
        batt_computed_series: int
            number of cells connected in series
        batt_computed_strings: int
            number of strings connected in parallel
        time_capacity: float 0-1

        batt_current_charge_max: float, A

        batt_current_discharge_max: float, A

        batt_power_charge_max_kwac: float, kWAC

        batt_power_discharge_max_kwac: float, kWAC

        batt_power_charge_max_kwdc: float, kWDC

        batt_power_discharge_max_kwdc: float, kWDC

        only if batt_chem is False:
            LeadAcid_q10_computed: float 0-100, Ah

            LeadAcid_q20_computed: float 0-100, Ah

            LeadAcid_qn_computed: float 0-100, Ah
    """

    def check_keys(keys):
        for k in keys:
            if k not in input_dict:
                raise ValueError

    check_keys(('size_by_ac_not_dc', 'batt_ac_or_dc', 'desired_power', 'desired_capacity'))
    desired_power = input_dict['desired_power']
    desired_capacity = input_dict['desired_capacity']
    ac_connected = bool(input_dict['batt_ac_or_dc'])
    size_by_ac_not_dc = bool(input_dict['size_by_ac_not_dc'])

    # convert all the sizing values to DC via conversion efficiencies
    if ac_connected:
        for key in ('size_by_ac_not_dc', 'batt_dc_ac_efficiency'):
            if key not in input_dict or input_dict[key] > 100:
                raise ValueError
        batt_dc_ac_efficiency = input_dict['batt_dc_ac_efficiency'] * 0.01
        if size_by_ac_not_dc:
            desired_capacity /= batt_dc_ac_efficiency
            desired_power /= batt_dc_ac_efficiency
    else:
        if 'inverter_eff' not in input_dict:
            raise ValueError
        inv_eff = input_dict['inverter_eff'] * 0.01
        if inv_eff > 1:
            raise ValueError
        if 'batt_dc_dc_efficiency' in input_dict:
            batt_dc_dc_efficiency = input_dict['batt_dc_dc_efficiency'] * 0.01
            inv_eff *= batt_dc_dc_efficiency
        if size_by_ac_not_dc:
            desired_capacity /= inv_eff
            desired_power /= inv_eff

    check_keys(('batt_Qfull', 'batt_Vnom_default', 'desired_voltage'))

    batt_Qfull = input_dict['batt_Qfull']
    batt_Vnom_default = input_dict['batt_Vnom_default']
    desired_voltage = input_dict['desired_voltage']

    max_rate_discharge = desired_power / desired_capacity
    max_rate_charge = max_rate_discharge
    num_series = math.ceil(desired_voltage / batt_Vnom_default)
    num_strings = round(desired_capacity * 1000 / (batt_Qfull * batt_Vnom_default * num_series))

    computed_voltage = batt_Vnom_default * num_series
    batt_capacity = batt_Qfull * computed_voltage * num_strings * 0.001
    batt_power = batt_capacity * max_rate_discharge

    output_dict = dict()
    output_dict['voltage'] = computed_voltage
    output_dict['power'] = batt_capacity * max_rate_discharge
    output_dict['batt_computed_bank_capacity'] = batt_capacity
    output_dict['batt_computed_series'] = num_series
    output_dict['batt_computed_strings'] = num_strings
    output_dict['time_capacity'] = batt_capacity / batt_power
    output_dict['batt_current_charge_max'] = batt_Qfull * num_strings * max_rate_charge
    output_dict['batt_current_discharge_max'] = batt_Qfull * num_strings * max_rate_discharge
    output_dict['batt_power_discharge_max_kwdc'] = batt_power
    output_dict['batt_power_charge_max_kwdc'] = batt_capacity * max_rate_charge

    # Now update AC power limit
    if ac_connected:
        if size_by_ac_not_dc:
            batt_bank_power_discharge_ac = desired_power
            batt_bank_power_charge_ac = desired_power
        else:
            batt_bank_power_discharge_ac = desired_power * batt_dc_ac_efficiency
            batt_bank_power_charge_ac =  desired_power / batt_dc_ac_efficiency
    else:
        if size_by_ac_not_dc:
            batt_bank_power_discharge_ac = desired_power
            batt_bank_power_charge_ac = desired_power
        else:
            batt_bank_power_discharge_ac = desired_power * inv_eff
            batt_bank_power_charge_ac = desired_power / inv_eff

    output_dict['batt_power_discharge_max_kwac'] = batt_bank_power_discharge_ac
    output_dict['batt_power_charge_max_kwac'] = batt_bank_power_charge_ac

    batt_chem = True
    if 'batt_chem' in input_dict:
        batt_chem = bool(input_dict['batt_chem'])

    if batt_chem == 0:
        check_keys(('LeadAcid_q10', 'LeadAcid_q20', 'LeadAcid_qn', 'LeadAcid_tn'))
        q10_computed = num_strings * input_dict['LeadAcid_q10'] * batt_Qfull * 0.01
        q20_computed = num_strings * input_dict['LeadAcid_q20'] * batt_Qfull * 0.01
        qn_computed = num_strings * input_dict['LeadAcid_qn'] * batt_Qfull * 0.01

        output_dict['LeadAcid_q10_computed'] = q10_computed
        output_dict['LeadAcid_q20_computed'] = q20_computed
        output_dict['LeadAcid_qn_computed'] = qn_computed

    return output_dict


def battery_model_sizing(model, desired_power, desired_capacity, desired_voltage,
                         leadacid_q10=None, leadacid_q20=None, leadacid_qn=None, leadacid_tn=None):
    """
    Modifies model with new sizing

    :param model: PySAM.StandAloneBattery model
    :param desired_power: float
        kWAC if AC-connected, kWDC otherwise
    :param desired_capacity: float
        kWhAC if AC-connected, kWhDC otherwise
    :param desired_voltage: float
        volts
    :param leadacid_q10: optional float
        new Capacity at 10-hour discharge rate
    :param leadacid_q20: optional float
        new Capacity at 20-hour discharge rate
    :param leadacid_qn: optional float
        new Capacity at n-hour discharge rate
    :param leadacid_tn: optional float
        Hour for leadacid_qn
    :return: output_dictionary of sizing parameters
    """
    input_dict = dict()

    chem = int(model.BatteryCell.batt_chem)

    # lead acid specific parameters, reuse them if new ones aren't provided
    if chem == 0:
        string_cap_ratio = model.BatterySystem.batt_computed_strings * model.BatteryCell.batt_Qfull * 0.01
        if leadacid_q10 is None:
            leadacid_q10 = model.BatteryCell.LeadAcid_q10_computed
        else:
            leadacid_q10 /= string_cap_ratio
        if leadacid_q20 is None:
            leadacid_q20 = model.BatteryCell.LeadAcid_q20_computed
        else:
            leadacid_q20 /= string_cap_ratio
        if leadacid_qn is None:
            leadacid_qn = model.BatteryCell.LeadAcid_qn_computed
        else:
            leadacid_qn /= string_cap_ratio
        if leadacid_tn is None:
            leadacid_tn = model.BatteryCell.LeadAcid_tn
        input_dict['LeadAcid_q10'] = leadacid_q10
        input_dict['LeadAcid_q20'] = leadacid_q20
        input_dict['LeadAcid_qn'] = leadacid_qn
        input_dict['LeadAcid_tn'] = leadacid_tn

    input_names = ('batt_chem', 'batt_Qfull', 'batt_Vnom_default', 'batt_ac_or_dc',
                   'batt_dc_ac_efficiency', 'batt_dc_dc_efficiency')

    for name in input_names:
        input_dict[name] = model.value(name)

    input_dict['desired_power'] = desired_power
    input_dict['desired_capacity'] = desired_capacity
    input_dict['desired_voltage'] = desired_voltage
    input_dict['size_by_ac_not_dc'] = input_dict['batt_ac_or_dc']

    if not input_dict['size_by_ac_not_dc']:
        inv_model = int(model.Inverter.inverter_model)
        if inv_model == 0:
            input_dict['inverter_eff'] = model.Inverter.inv_snl_eff_cec
        elif inv_model == 1:
            input_dict['inverter_eff'] = model.Inverter.inv_ds_eff
        elif inv_model == 2:
            input_dict['inverter_eff'] = model.Inverter.inv_pd_eff
        elif inv_model == 3:
            input_dict['inverter_eff'] = model.Inverter.inv_cec_cg_eff_cec
        else:
            raise ValueError

    output_dict = size_li_ion_battery(input_dict)

    computed_inputs = ('batt_computed_bank_capacity', 'batt_computed_series', 'batt_computed_strings',
                       'batt_current_charge_max', 'batt_current_discharge_max', 'batt_power_charge_max_kwac',
                       'batt_power_discharge_max_kwac', 'batt_power_charge_max_kwdc', 'batt_power_discharge_max_kwdc')

    if input_dict['batt_chem'] == 0:
        computed_inputs += ('LeadAcid_q10_computed', 'LeadAcid_q20_computed', 'LeadAcid_qn_computed')
        model.BatteryCell.LeadAcid_tn = leadacid_tn

    for name in computed_inputs:
        model.value(name, output_dict[name])

    return output_dict
