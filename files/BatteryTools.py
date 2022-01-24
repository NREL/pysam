from typing import Union
import math

import PySAM.Pvsamv1 as PVBatt
import PySAM.Battery as Batt
import PySAM.BatteryStateful as BattStfl

available_chems = ['leadacid', 'lfpgraphite', 'nmcgraphite', 'lmolto']


def battery_model_sizing(model, desired_power, desired_capacity, desired_voltage, size_by_ac_not_dc=None, module_specs: dict=None):
    """
    Sizes the battery model using its current configuration such as chemistry, cell properties, etc
    and modifies the model's power, capacity and voltage without changing its fundamental properties

    The battery's thermal parameters (surface area and mass) are modified according to assumptions
    about the mass and volume per specific energy and assuming the battery is a cube. If the battery's
    thermal parameters should be sized according to a particular module's capacity and surface area,
    use the module_specs input.

    :param model: PySAM.Battery.Battery or PySAM.BatteryStateful.BatteryStateful
    :param desired_power: float
        Battery: kWAC if AC-connected, kWDC otherwise. BatteryStateful: battery kWDC
    :param desired_capacity: float
        Battery: kWhAC if AC-connected, kWhDC otherwise. BatteryStateful: battery kWhDC
    :param desired_voltage: float
        volts
    :param size_by_ac_not_dc: optional bool
        Sizes for power and capacity are on AC side not DC side of battery-inverter regardless of connection type
    :param module_specs: optional dict
        Module specifications for scaling surface area assuming the battery is made of inividual modules.
            capacity: float
                Single battery module capacity for scaling surface area
                Battery: kWhAC if AC-connected, kWhDC otherwise
                BatteryStateful: battery kWhDC
            surface_area: float
                Single battery module surface area m^2
                m^2 of module battery
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
    """
    Changes the chemistry and cell properties of the battery to use defaults for that chemistry from BatteryStateful

    :param model: PySAM.Battery.Battery or PySAM.BatteryStateful.BatteryStateful
    :param chem: string
        'leadacid', 'lfpgraphite', 'nmcgraphite', 'lmolto'
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
    """
    Helper function for battery_model_sizing
    Modifies Battery model with new sizing. For BatteryStateful use size_batterystateful

    :param model: PySAM.Battery model
    :param desired_power: float
        kWAC if AC-connected, kWDC otherwise
    :param desired_capacity: float
        kWhAC if AC-connected, kWhDC otherwise
    :param desired_voltage: float
        volts
    :param size_by_ac_not_dc: optional bool
        Sizes for power and capacity are on AC side not DC side of battery-inverter
    :param module_dict: optional dict
        Module specs for scaling surface area
            capacity: float
                Single battery module capacity for scaling surface area
                kWhAC if AC-connected, kWhDC otherwise
            surface_area: float
                Single battery module surface area m^2
                m^2 of module battery
    :return: output_dictionary of sizing parameters
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
    """
    Helper function for battery_model_sizing

    Modifies BatteryStateful model with new sizing. For Battery use size_battery

    Only battery side DC sizing

    :param model: PySAM.Battery model
    :param _: not used
    :param desired_capacity: float
        kWhAC if AC-connected, kWhDC otherwise
    :param desired_voltage: float
        volts
    :param module_dict: optional dict
        Module specs for scaling surface area
            capacity: float
                Single battery module capacity for scaling surface area
                kWhAC if AC-connected, kWhDC otherwise
            surface_area: float
                Single battery module surface area m^2
                m^2 of module battery
    :return: output_dictionary of sizing parameters
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
    """
    Helper function to `battery_model_sizing`

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
    """
    Calculates the mass and surface area of a battery by calculating from its current parameters the
    mass / specific energy and volume / specific energy ratios.

    If module_capacity and module_surface_area are provided, battery surface area is calculated by
    scaling module_surface_area by the number of modules required to fulfill desired capacity.

    :param:
        input_dict:
            mass: float
                kg of battery at original size
            surface_area: float
                m^2 of battery at original size
            original_capacity: float
                Wh of battery
            desired_capacity: float
                Wh of new battery size
            module_capacity: optional float
                Wh of module battery size
            module_surface_area: optional float
                m^2 of module battery
    Returns:
        output_dict:
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
    """
    Helper function for battery_model_change_chemistry
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
