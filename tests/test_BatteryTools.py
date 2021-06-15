import pytest

import PySAM.BatteryTools as BatteryTools
import PySAM.Battery as batt
import PySAM.BatteryStateful as battstfl


def test_leadacid():
    model = batt.default("GenericBatteryCommercial")
    model.BatteryCell.batt_chem = 0
    assert(model.BatterySystem.batt_computed_bank_capacity != pytest.approx(100, .5))
    assert(model.BatterySystem.batt_power_charge_max_kwdc != pytest.approx(50, 0.5))

    BatteryTools.battery_model_sizing(model, desired_power=100, desired_capacity=400, desired_voltage=500)
    assert(model.BatterySystem.batt_computed_strings == 261)
    assert(model.BatterySystem.batt_computed_series == 139)
    assert(model.BatterySystem.batt_computed_bank_capacity == pytest.approx(417, 1))
    assert(model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(96.29, 1))


def test_liion_ac_connected_ac_sizing():
    model = batt.default("GenericBatteryCommercial")
    model.BatteryCell.batt_chem = 1
    model.BatterySystem.batt_ac_or_dc = 1   # ac
    BatteryTools.battery_model_sizing(model, 100, 400, 500)
    assert(model.BatterySystem.batt_computed_bank_capacity == pytest.approx(417, 1))
    assert(model.BatterySystem.batt_power_discharge_max_kwdc == pytest.approx(104, 1))
    assert(model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(96, 1))
    assert(model.BatterySystem.batt_power_discharge_max_kwac == pytest.approx(100, 1))
    assert(model.BatterySystem.batt_power_charge_max_kwac == pytest.approx(100, 1))
    assert(model.BatterySystem.batt_current_discharge_max == pytest.approx(208, 1))
    assert(model.BatterySystem.batt_current_charge_max == pytest.approx(192, 1))


def test_liion_ac_connected_dc_sizing():
    model = batt.default("GenericBatteryCommercial")
    model.BatteryCell.batt_chem = 1
    model.BatterySystem.batt_ac_or_dc = 1   # ac
    BatteryTools.battery_model_sizing(model, 100, 400, 500, size_by_ac_not_dc=False)
    assert(model.BatterySystem.batt_computed_bank_capacity == pytest.approx(400, 1))
    assert(model.BatterySystem.batt_power_discharge_max_kwdc == pytest.approx(100, 1))
    assert(model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(100, 1))
    assert(model.BatterySystem.batt_power_discharge_max_kwac == pytest.approx(96, 1))
    assert(model.BatterySystem.batt_power_charge_max_kwac == pytest.approx(104, 1))
    assert(model.BatterySystem.batt_current_discharge_max == pytest.approx(200, 1))
    assert(model.BatterySystem.batt_current_charge_max == pytest.approx(200, 1))


def test_liion_dc_connected_dc_sizing():
    model = batt.default("GenericBatteryCommercial")
    model.BatteryCell.batt_chem = 1
    model.Inverter.inverter_model = 0
    model.Inverter.inv_snl_eff_cec = 50
    model.BatterySystem.batt_ac_or_dc = 0
    BatteryTools.battery_model_sizing(model, 100, 400, 500)
    assert (model.BatterySystem.batt_computed_bank_capacity == pytest.approx(400,1 ))
    assert (model.BatterySystem.batt_power_discharge_max_kwdc == pytest.approx(100, 1))
    assert (model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(100, 1))
    assert (model.BatterySystem.batt_power_discharge_max_kwac == pytest.approx(49, 1))
    assert (model.BatterySystem.batt_power_charge_max_kwac == pytest.approx(204, 1))
    assert(model.BatterySystem.batt_current_discharge_max == pytest.approx(200, 1))
    assert(model.BatterySystem.batt_current_charge_max == pytest.approx(200, 1))

    model.Inverter.inv_snl_eff_cec = 100
    model.BatterySystem.batt_ac_or_dc = 0
    BatteryTools.battery_model_sizing(model, 100, 400, 500)
    assert (model.BatterySystem.batt_computed_bank_capacity == pytest.approx(400, 1))
    assert (model.BatterySystem.batt_power_discharge_max_kwdc == pytest.approx(100, 1))
    assert (model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(100, 1))
    assert (model.BatterySystem.batt_power_discharge_max_kwac == pytest.approx(98, 1))
    assert (model.BatterySystem.batt_power_charge_max_kwac == pytest.approx(102, 1))


def test_liion_dc_connected_ac_sizing():
    model = batt.default("GenericBatteryCommercial")
    model.BatteryCell.batt_chem = 1
    model.Inverter.inverter_model = 0
    model.Inverter.inv_snl_eff_cec = 100
    model.BatterySystem.batt_ac_or_dc = 0
    BatteryTools.battery_model_sizing(model, 100, 400, 500, size_by_ac_not_dc=True)
    assert (model.BatterySystem.batt_computed_bank_capacity == pytest.approx(408, 1))
    assert (model.BatterySystem.batt_power_discharge_max_kwdc == pytest.approx(102, 1))
    assert (model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(98, 1))
    assert (model.BatterySystem.batt_power_discharge_max_kwac == pytest.approx(100, 1))
    assert (model.BatterySystem.batt_power_charge_max_kwac == pytest.approx(100, 1))
    assert(model.BatterySystem.batt_current_discharge_max == pytest.approx(204, 1))
    assert(model.BatterySystem.batt_current_charge_max == pytest.approx(196, 1))


def test_calculate_thermal_params():
    input_dict = {
        'mass': 20272.2,
        'surface_area': 23.9614,
        'original_capacity': 4000.323,
        'desired_capacity': 2000
    }
    output = BatteryTools.calculate_thermal_params(input_dict)
    assert(output['mass'] == pytest.approx(10135.28))
    assert(output['surface_area'] == pytest.approx(15.09392))


def test_battery_model_change_chemistry():
    model = batt.default("GenericBatterySingleOwner")
    original_capacity = model.value('batt_computed_bank_capacity')
    original_power = model.BatterySystem.batt_power_discharge_max_kwac

    BatteryTools.battery_model_change_chemistry(model, 'leadacid')

    params_new = battstfl.default('leadacid').export()
    cell_params = params_new['ParamsCell']
    pack_params = params_new['ParamsPack']

    assert(model.value('batt_computed_bank_capacity') == pytest.approx(original_capacity, 0.1))
    assert(model.value('batt_power_discharge_max_kwac') == pytest.approx(original_power, 0.1))
    assert(model.BatteryCell.batt_chem == cell_params['chem'])
    assert(model.BatteryCell.batt_calendar_choice == cell_params['calendar_choice'])
    assert(model.BatteryCell.batt_Vnom_default == cell_params['Vnom_default'])
    assert(model.BatteryCell.LeadAcid_q10_computed == cell_params['leadacid_q10'])
    assert(model.BatteryCell.batt_Cp == pack_params['Cp'])

    BatteryTools.battery_model_change_chemistry(model, 'nmcgraphite')

    params_new = battstfl.default('nmcgraphite').export()
    cell_params = params_new['ParamsCell']
    pack_params = params_new['ParamsPack']

    assert(model.value('batt_computed_bank_capacity') == pytest.approx(original_capacity, 0.1))
    assert(model.value('batt_power_discharge_max_kwac') == pytest.approx(original_power, 0.1))
    assert(model.BatteryCell.batt_C_rate == cell_params['C_rate'])
    assert(model.BatteryCell.batt_Vexp == cell_params['Vexp'])
    assert(model.BatteryCell.batt_Cp == pack_params['Cp'])


def test_batterystateful_model_change_chemistry():
    model = battstfl.default("leadacid")
    original_capacity = model.ParamsPack.nominal_energy

    BatteryTools.battery_model_change_chemistry(model, 'nmcgraphite')

    params_new = battstfl.default('nmcgraphite').export()
    cell_params = params_new['ParamsCell']
    pack_params = params_new['ParamsPack']

    assert(model.value('nominal_energy') == pytest.approx(original_capacity, 0.1))
    assert(model.ParamsCell.Vnom_default == cell_params['Vnom_default'])
    assert(model.ParamsPack.Cp == pack_params['Cp'])
