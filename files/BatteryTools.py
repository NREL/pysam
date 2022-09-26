from typing import Union
import math

import PySAM.Pvsamv1 as PVBatt
import PySAM.Battery as Batt
import PySAM.BatteryStateful as BattStfl

available_chems = ['leadacid', 'lfpgraphite', 'nmcgraphite', 'lmolto']


def battery_model_sizing(model, desired_power, desired_capacity, desired_voltage, size_by_ac_not_dc=None, module_specs: dict=None):
    """Sizes the battery model using its current configuration such as chemistry, cell properties, etc and modifies the model's power, capacity and voltage without changing its fundamental properties. The battery's thermal parameters (surface area and mass) are modified according to assumptions
    about the mass and volume per specific energy and assuming the battery is a cube. If the battery's thermal parameters should be sized according to a particular module's capacity and surface area,
    use the module_specs input.
    
    :param model: PySAM.Battery.Battery or PySAM.BatteryStateful.BatteryStateful
    :param float desired_power: For Battery, kWAC if AC-connected, kWDC otherwise. For BatteryStateful, battery kWDC.
    :param float desired_capacity: For Battery, kWhAC if AC-connected, kWhDC otherwise. For BatteryStateful, battery kWhDC.
    :param float desired_voltage: Volts
    :param bool, optional size_by_ac_not_dc: Sizes for power and capacity are on AC side not DC side of battery-inverter regardless of connection type.
    :param dict, optional module_specs: {capacity (float), surface_area (float)} Dictionary of battery module specifications for scaling surface area, assuming the battery is made of individual modules.

        capacity: float
            Capacity of a single battery module. For the Battery model, use kWhAC if AC-connected, use kWhDC otherwise. For the BatteryStateful model, use battery kWhDC.
        surface_area: float
            Surface area of as single battery module in m^2.
    """


    if module_specs is not None:
        if not module_specs.keys() == {'capacity', 'surface_area'}:
            raise TypeError("module_specs must contain 'capacity' and 'surface_area' keys only." )

    if type(model) == Batt.Battery or type(model) == PVBatt.Pvsamv1:
        size_battery(model, desired_power, desired_capacity, desired_voltage, size_by_ac_not_dc, module_dict=module_specs)
    elif type(model) == BattStfl.BatteryStateful:
        size_batterystateful(model, desired_power, desired_capacity, desired_voltage, module_dict=module_specs)
    else:
        raise TypeError


def battery_model_change_chemistry(model, chem):
    """Changes the chemistry and cell properties of the battery to use defaults for that chemistry from BatteryStateful
    
    :param model: PySAM.Battery.Battery or PySAM.BatteryStateful.BatteryStateful
    :param str chem: Battery chemistry, 'leadacid', 'lfpgraphite', 'nmcgraphite', or 'lmolto'.
    """

    chem = chem.lower()
    if chem not in available_chems:
        raise NotImplementedError

    if type(model) == Batt.Battery or type(model) == PVBatt.Pvsamv1:
        chem_battery(model, chem)
    elif type(model) == BattStfl.BatteryStateful:
        chem_batterystateful(model, chem)
    else:
        raise TypeError


def size_battery(model, desired_power, desired_capacity, desired_voltage, size_by_ac_not_dc=None, module_dict=None):
    """Helper function for battery_model_sizing. Modifies Battery model with new sizing. For BatteryStateful use size_batterystateful.
    
    :param model: PySAM.Battery model
    :param float desired_power: Desired battery power, kWAC if AC-connected, kWDC otherwise.
    :param float desired_capacity: Desired battery capacity,  kWhAC if AC-connected, kWhDC otherwise.
    :param float desired_voltage: Desired battery voltage, V.
    :param bool,optional size_by_ac_not_dc: `True` sizes for power and capacity based on AC cpacities, `False` sizes for DC capacities.
    :param dict module_dict: {capacity (float), surface_area (float)} Battery module specs for scaling surface area.

        capacity: float
            Capacity of a single battery module in kWhAC if AC-connected or kWhDC if DC-connected.
        surface_area: float
            Surface area is of single battery module in m^2.
    
    :returns: Dictionary of of sizing parameters.
    :rtype: dict
    """

    if type(model) != Batt.Battery and type(model) != PVBatt.Pvsamv1:
        raise TypeError

    #
    # calculate size
    #
    sizing_inputs = dict()

    original_capacity = model.value('batt_computed_bank_capacity')
    chem = int(model.BatteryCell.batt_chem)

    # lead acid specific parameters, reuse them if new ones aren't provided
    if chem == 0:
        string_cap_ratio = model.BatterySystem.batt_computed_strings * model.BatteryCell.batt_Qfull * 0.01
        leadacid_q10 = model.BatteryCell.LeadAcid_q10_computed
        leadacid_q20 = model.BatteryCell.LeadAcid_q20_computed
        leadacid_qn = model.BatteryCell.LeadAcid_qn_computed
        leadacid_tn = model.BatteryCell.LeadAcid_tn
        sizing_inputs['LeadAcid_q10'] = leadacid_q10
        sizing_inputs['LeadAcid_q20'] = leadacid_q20
        sizing_inputs['LeadAcid_qn'] = leadacid_qn
        sizing_inputs['LeadAcid_tn'] = leadacid_tn

    input_names = ('batt_chem', 'batt_Qfull', 'batt_Vnom_default', 'batt_ac_or_dc',
                   'batt_dc_ac_efficiency', 'batt_dc_dc_efficiency')

    for name in input_names:
        sizing_inputs[name] = model.value(name)

    sizing_inputs['desired_power'] = desired_power
    sizing_inputs['desired_capacity'] = desired_capacity
    sizing_inputs['desired_voltage'] = desired_voltage
    if size_by_ac_not_dc is not None:
        sizing_inputs['size_by_ac_not_dc'] = size_by_ac_not_dc
    else:
        sizing_inputs['size_by_ac_not_dc'] = sizing_inputs['batt_ac_or_dc']

    if not sizing_inputs['batt_ac_or_dc']:
        inv_model = int(model.Inverter.inverter_model)
        if inv_model == 0:
            sizing_inputs['inverter_eff'] = model.Inverter.inv_snl_eff_cec
        elif inv_model == 1:
            sizing_inputs['inverter_eff'] = model.Inverter.inv_ds_eff
        elif inv_model == 2:
            sizing_inputs['inverter_eff'] = model.Inverter.inv_pd_eff
        elif inv_model == 3:
            sizing_inputs['inverter_eff'] = model.Inverter.inv_cec_cg_eff_cec
        else:
            raise ValueError

    sizing_outputs = calculate_battery_size(sizing_inputs)

    computed_inputs = ('batt_computed_bank_capacity', 'batt_computed_series', 'batt_computed_strings',
                       'batt_current_charge_max', 'batt_current_discharge_max', 'batt_power_charge_max_kwac',
                       'batt_power_discharge_max_kwac', 'batt_power_charge_max_kwdc', 'batt_power_discharge_max_kwdc')

    for name in computed_inputs:
        model.value(name, sizing_outputs[name])

    #
    # calculate thermal
    #
    thermal_inputs = {
        'mass': model.value('batt_mass'),
        'surface_area': model.value('batt_surface_area'),
        'original_capacity': original_capacity,
        'desired_capacity': sizing_outputs['batt_computed_bank_capacity']
    }
    if module_dict is not None:
        module_dict = {'module_'+k: v for k, v in module_dict.items()}
        thermal_inputs.update(module_dict)

    thermal_outputs = calculate_thermal_params(thermal_inputs)

    model.value('batt_mass', thermal_outputs['mass'])
    model.value('batt_surface_area', thermal_outputs['surface_area'])

    return sizing_outputs.update(thermal_outputs)


def size_batterystateful(model: BattStfl.BatteryStateful, _, desired_capacity, desired_voltage, module_dict=None):
    """Helper function for ``battery_model_sizing()``. Modifies BatteryStateful model with new sizing. For Battery model, use ``size_battery()`` instead. Only battery side DC sizing.
    
    :param model: PySAM.Battery model
    :param _: Not used.
    :param float desired_capacity: kWhAC if AC-connected, kWhDC otherwise.
    :param float desired_voltage: Volts.
    :param dict module_dict: {capacity (float), surface_area (float)} Optional, module specs for scaling surface area.
    
        capacity: float
            Capacity of a single battery module in kWhAC if AC-connected, kWhDC otherwise.
        surface_area: float
            Surface area is of single battery module in m^2.

    :returns: Dictionary of sizing parameters.
    :rtype: dict
    """

    #
    # calculate size
    #
    if type(model) != BattStfl.BatteryStateful:
        raise TypeError

    original_capacity = model.ParamsPack.nominal_energy

    model.ParamsPack.nominal_voltage = desired_voltage
    model.ParamsPack.nominal_energy = desired_capacity

    #
    # calculate thermal
    #
    thermal_inputs = {
        'mass': model.ParamsPack.mass,
        'surface_area': model.ParamsPack.surface_area,
        'original_capacity': original_capacity,
        'desired_capacity': desired_capacity
    }
    if module_dict is not None:
        module_dict = {'module_'+k: v for k, v in module_dict.items()}
        thermal_inputs.update(module_dict)

    thermal_outputs = calculate_thermal_params(thermal_inputs)

    model.ParamsPack.mass = thermal_outputs['mass']
    model.ParamsPack.surface_area = thermal_outputs['surface_area']


def calculate_battery_size(input_dict):
    """Helper function to battery_model_sizing. All efficiencies and rates in percentages, 0-100. Inverter efficiency depends on which inverter model is being used, inverter_model.
    
    :param dict input_dict: Dictionary of battery parameters. {batt_chem (int), batt_Qfull (float), batt_Vnom_default (float)} 

        batt_chem: int
            Lithium-ion (1) or Lead acid (0)
        batt_Qfull: float
            capacity of single cell in Ah
        batt_Vnom_default: float
            voltage of single cell in V
    :param bool batt_ac_or_dc:
    :param float desired_power:
    :param float desired_capacity:
    :param float desired_voltage:
    :param bool size_by_ac_not_dc:
    :param float batt_dc_ac_efficiency:
    :param float inverter_eff: 
    :param float batt_dc_dc_efficiency:
    :param float LeadAcid_q10: *Required if batt_chem = 0*. 10-hour disharge rate in Ah, between 0 and 100.
    :param float LeadAcid_q20: *Required if batt_chem = 0*. 20-hour discharge rate in Ah, between 0 and 100.
    :param float LeadAcid_qn: *Required if batt_chem = 0*. n-hour discharge rate in Ah, between 0 and 100.
    :param int LeadAcid_tn: *Required if batt_chem = 0*. Hour for custom hour discharge rate.
    :param bool batt_ac_or_dc: Set to True if ac-connected, set to False otherwise.
    :param float desired_power: Power of the battery in kW.
    :param float desired_capacity: Desired battery capacity in kWh.
    :param float desired_voltage: Desired battery voltage in V.
    :param bool size_by_ac_not_dc: Set to True for sizing battery as kWAC and kWhAC. Default is False.
    :param float batt_dc_ac_efficiency: *Required only if size_by_ac_not_dc = True* AC to DC power in conversion, between 0 and 100.
    :param float inverter_eff: Required only if batt_ac_or_dc = False. Inverter DC to AC conversion efficiency, between 0 and 100.
    :param float, optional batt_dc_dc_efficiency: DC to DC power conversion in battery management system, between 0 and 100.

    
    :returns: Dictionary of battery size parameters.
    :rtype: dict {voltage (float), power (float), batt_computed_bank_capacity (float), batt_computed_series (int), batt_computed_string0250s (int), time_capacity (float), batt_current_charge_max (float), batt_current_discharge_max (float), batt_power_charge_max_kwac (float), batt_power_discharge_max_kwac (float), batt_power_charge_max_kwdc (float), 
        batt_power_discharge_max_kwdc (float), LeadAcid_q10_computed (float), LeadAcid_q20_computed (float), LeadAcid_qn_computed (float)}

        voltage: float
            Computed voltage.
        power: float
            Computed power.
        batt_computed_bank_capacity: float
            Computed bank capacity.
        batt_computed_series: int
            Computed number of cells connected in series.
        batt_computed_strings: int
            Computed number of cell strings connected in parallel.
        time_capacity: float
            0-1
        batt_current_charge_max: float
            A
        batt_current_discharge_max: float
            A
        batt_power_charge_max_kwac: float
            kWAC
        batt_power_discharge_max_kwac: float
            kWAC
        batt_power_charge_max_kwdc: float
            kWDC
        batt_power_discharge_max_kwdc: float
            kWDC
        Lead acid parameters returned if batt_chem = 0:
            LeadAcid_q10_computed, LeadAcid_q20_computed, LeadAcid_qn_computed, all in Ah between 0 and 100.
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

    check_keys(('batt_Qfull', 'batt_Vnom_default', 'desired_voltage'))

    batt_Qfull = input_dict['batt_Qfull']
    batt_Vnom_default = input_dict['batt_Vnom_default']
    desired_voltage = input_dict['desired_voltage']

    output_dict = dict()

    def size_from_strings(capacity):
        num_series = math.ceil(desired_voltage / batt_Vnom_default)
        num_strings = math.ceil(capacity * 1000 / (batt_Qfull * batt_Vnom_default * num_series))
        computed_voltage = batt_Vnom_default * num_series
        computed_capacity = batt_Qfull * computed_voltage * num_strings * 0.001
        max_rate = desired_power / desired_capacity
        computed_power = computed_capacity * max_rate
        output_dict['voltage'] = computed_voltage
        output_dict['batt_computed_series'] = num_series
        output_dict['batt_computed_strings'] = num_strings
        output_dict['power'] = computed_capacity * max_rate
        output_dict['batt_computed_bank_capacity'] = computed_capacity
        output_dict['time_capacity'] = computed_capacity / computed_power
        if abs(computed_capacity - capacity) / capacity > 0.05:
            raise ValueError("Could not meet desired battery capacity. Consider adjusting the desired voltage, "
                             "or battery cell properties")
        return computed_capacity, computed_power, max_rate

    # convert all the sizing values to DC via conversion efficiencies
    if ac_connected:
        for key in ('size_by_ac_not_dc', 'batt_dc_ac_efficiency'):
            if key not in input_dict or input_dict[key] > 100:
                raise ValueError
        conv_eff = input_dict['batt_dc_ac_efficiency'] * 0.01
    else:
        if 'inverter_eff' not in input_dict:
            raise ValueError
        conv_eff = input_dict['inverter_eff'] * 0.01
        if conv_eff > 1:
            raise ValueError
        if 'batt_dc_dc_efficiency' in input_dict:
            batt_dc_dc_efficiency = input_dict['batt_dc_dc_efficiency'] * 0.01
            conv_eff *= batt_dc_dc_efficiency

    # sizes are AC side
    if size_by_ac_not_dc:
        desired_capacity /= conv_eff
        desired_power /= conv_eff

        batt_capacity, batt_power, max_rate = size_from_strings(desired_capacity)
        batt_bank_power_discharge_ac = batt_power * conv_eff
        batt_bank_power_charge_ac = batt_power * conv_eff
        batt_bank_power_discharge_dc = batt_bank_power_discharge_ac / conv_eff
        batt_bank_power_charge_dc = batt_bank_power_charge_ac * conv_eff
    else:
        batt_capacity, batt_power, max_rate = size_from_strings(desired_capacity)
        batt_bank_power_discharge_dc = batt_bank_power_charge_dc = batt_power
        batt_bank_power_discharge_ac = batt_bank_power_discharge_dc * conv_eff
        batt_bank_power_charge_ac = batt_bank_power_charge_dc / conv_eff

    output_dict['batt_power_discharge_max_kwdc'] = batt_bank_power_discharge_dc
    output_dict['batt_power_charge_max_kwdc'] = batt_bank_power_charge_dc
    output_dict['batt_current_charge_max'] = batt_bank_power_charge_dc / output_dict['voltage'] * 1000
    output_dict['batt_current_discharge_max'] = batt_bank_power_discharge_dc / output_dict['voltage'] * 1000
    output_dict['batt_power_discharge_max_kwac'] = batt_bank_power_discharge_ac
    output_dict['batt_power_charge_max_kwac'] = batt_bank_power_charge_ac

    return output_dict


def calculate_thermal_params(input_dict):
    """Calculates the mass and surface area of a battery by calculating from its current parameters the
    mass / specific energy and volume / specific energy ratios. If module_capacity and module_surface_area are provided, battery surface area is calculated by
    scaling module_surface_area by the number of modules required to fulfill desired capacity.
   
    :param dict input_dict: A dictionary of battery thermal parameters at original size. {mass (float), surface_area (float), original_capacity (float), desired_capacity (float), module_capacity (float, optional), surface_area (float, optional)}

        mass: float
            kg of battery at original size
        surface_area: float
            m^2 of battery at original size
        original_capacity: float
            Wh of battery
        desired_capacity: float
            Wh of new battery size
        module_capacity: float, optional
            Wh of module battery size
        module_surface_area: float, optional
            m^2 of module battery

    :returns: Dictionary of battery mass and surface area at desired size.
    :rtype: dict {mass (float), surface_area (float)} 

        mass: float
            kg of battery at desired size
        surface_area: float
            m^2 of battery at desired size
    """

    mass = input_dict['mass']
    surface_area = input_dict['surface_area']
    original_capacity = input_dict['original_capacity']
    desired_capacity = input_dict['desired_capacity']

    mass_per_specific_energy = mass / original_capacity

    volume = (surface_area / 6) ** (3/2)

    volume_per_specific_energy = volume / original_capacity

    output_dict = {
        'mass': mass_per_specific_energy * desired_capacity,
        'surface_area': (volume_per_specific_energy * desired_capacity) ** (2/3) * 6,
    }

    if input_dict.keys() >= {'module_capacity', 'module_surface_area'}:
        module_capacity = input_dict['module_capacity']
        module_surface_area = input_dict['module_surface_area']
        output_dict['surface_area'] = module_surface_area*desired_capacity/module_capacity

    return output_dict


def chem_battery(model: Union[Batt.Battery, PVBatt.Pvsamv1], chem):
    """Helper function for battery_model_change_chemistry().
    """

    if type(model) != Batt.Battery and type(model) != PVBatt.Pvsamv1:
        raise TypeError

    chem = chem.lower()
    if chem not in available_chems:
        raise NotImplementedError

    if chem == 'leadacid':
        model.BatteryCell.batt_chem = 0
    else:
        model.BatteryCell.batt_chem = 1

    original_capacity = model.value('batt_computed_bank_capacity')
    original_voltage = model.BatteryCell.batt_Vnom_default * model.BatterySystem.batt_computed_series
    if model.BatterySystem.batt_ac_or_dc:
        original_power = model.BatterySystem.batt_power_discharge_max_kwac
    else:
        original_power = model.BatterySystem.batt_power_discharge_max_kwdc

    params_dict = BattStfl.default(chem).export()

    for group in ('ParamsCell', 'ParamsPack'):
        for k, v in params_dict[group].items():
            if k == 'nominal_voltage' or k == "T_room_init":
                continue
            elif k == 'cycling_matrix':
                k = 'batt_lifetime_matrix'
            elif 'leadacid' in k:
                k = 'LeadAcid' + k[8:]
                if 'tn' not in k:
                    k += '_computed'
            elif k == 'h':
                k = 'batt_h_to_ambient'
            elif k == 'nominal_energy':
                k = 'batt_computed_bank_capacity'
            elif k == 'cap_vs_temp':
                pass
            else:
                k = 'batt_' + k

            model.value(k, v)

    battery_model_sizing(model, original_power, original_capacity, original_voltage)


def chem_batterystateful(model: BattStfl.BatteryStateful, chem):
    """
    Helper function for battery_model_change_chemistry
    """

    if type(model) != BattStfl.BatteryStateful:
        raise TypeError

    chem = chem.lower()

    if chem not in available_chems:
        raise NotImplementedError

    if chem == 'leadacid':
        model.ParamsCell.chem = 0
    else:
        model.ParamsCell.chem = 1

    original_capacity = model.ParamsPack.nominal_energy
    original_voltage = model.ParamsPack.nominal_voltage

    params_dict = BattStfl.default(chem).export()

    for group in ('ParamsCell', 'ParamsPack'):
        for k, v in params_dict[group].items():
            model.value(k, v)

    battery_model_sizing(model, -1, original_capacity, original_voltage)
