import pytest

import PySAM.BatteryTools as BatteryTools
import PySAM.StandAloneBattery as batt


def test_leadacid():
    model = batt.default("GenericBatteryCommercial")
    model.BatteryCell.batt_chem = 0
    assert(model.BatterySystem.batt_computed_bank_capacity != pytest.approx(100, .5))
    assert(model.BatterySystem.batt_power_charge_max_kwdc != pytest.approx(50, 0.5))

    BatteryTools.battery_model_sizing(model, 100, 400, 500)
    assert(model.BatterySystem.batt_computed_strings == 371)
    assert(model.BatterySystem.batt_computed_series == 139)
    assert(model.BatterySystem.batt_computed_bank_capacity == pytest.approx(416, 1))
    assert(model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(104, 1))

    BatteryTools.battery_model_sizing(model, 100, 400, 500, 50, 60, 30)
    assert(model.BatterySystem.batt_computed_bank_capacity == pytest.approx(416, 1))
    assert(model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(104, 1))
    assert(model.BatteryCell.LeadAcid_q10_computed == pytest.approx(50, 5))
    assert(model.BatteryCell.LeadAcid_q20_computed == pytest.approx(60, 5))
    assert(model.BatteryCell.LeadAcid_qn_computed == pytest.approx(30, 5))


def test_liion_ac_connected_ac_sizing():
    model = batt.default("GenericBatteryCommercial")
    model.BatteryCell.batt_chem = 1
    model.BatterySystem.batt_ac_or_dc = 1   # ac
    BatteryTools.battery_model_sizing(model, 100, 400, 500)
    assert(model.BatterySystem.batt_computed_bank_capacity == pytest.approx(417.7089))
    assert(model.BatterySystem.batt_power_discharge_max_kwdc == pytest.approx(104.4272))
    assert(model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(96.2401))
    assert(model.BatterySystem.batt_power_discharge_max_kwac == pytest.approx(100.2501))
    assert(model.BatterySystem.batt_power_charge_max_kwac == pytest.approx(100.2501))
    assert(model.BatterySystem.batt_current_discharge_max == pytest.approx(208.6875))
    assert(model.BatterySystem.batt_current_charge_max == pytest.approx(192.3263))


def test_liion_ac_connected_dc_sizing():
    model = batt.default("GenericBatteryCommercial")
    model.BatteryCell.batt_chem = 1
    model.BatterySystem.batt_ac_or_dc = 1   # ac
    BatteryTools.battery_model_sizing(model, 100, 400, 500, size_by_ac_not_dc=False)
    assert(model.BatterySystem.batt_computed_bank_capacity == pytest.approx(400.8204))
    assert(model.BatterySystem.batt_power_discharge_max_kwdc == pytest.approx(100.2051))
    assert(model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(100.2051))
    assert(model.BatterySystem.batt_power_discharge_max_kwac == pytest.approx(96.1968))
    assert(model.BatterySystem.batt_power_charge_max_kwac == pytest.approx(104.3803))
    assert(model.BatterySystem.batt_current_discharge_max == pytest.approx(200.2499))
    assert(model.BatterySystem.batt_current_charge_max == pytest.approx(200.2499))


def test_liion_dc_connected_dc_sizing():
    model = batt.default("GenericBatteryCommercial")
    model.BatteryCell.batt_chem = 1
    model.Inverter.inverter_model = 0
    model.Inverter.inv_snl_eff_cec = 50
    model.BatterySystem.batt_ac_or_dc = 0
    BatteryTools.battery_model_sizing(model, 100, 400, 500)
    assert (model.BatterySystem.batt_computed_bank_capacity == pytest.approx(400.8204))
    assert (model.BatterySystem.batt_power_discharge_max_kwdc == pytest.approx(100.2051))
    assert (model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(100.2051))
    assert (model.BatterySystem.batt_power_discharge_max_kwac == pytest.approx(49.1005))
    assert (model.BatterySystem.batt_power_charge_max_kwac == pytest.approx(204.5002))
    assert(model.BatterySystem.batt_current_discharge_max == pytest.approx(200.2499))
    assert(model.BatterySystem.batt_current_charge_max == pytest.approx(200.2499))

    model.Inverter.inv_snl_eff_cec = 100
    model.BatterySystem.batt_ac_or_dc = 0
    BatteryTools.battery_model_sizing(model, 100, 400, 500)
    assert (model.BatterySystem.batt_computed_bank_capacity == pytest.approx(400.8204))
    assert (model.BatterySystem.batt_power_discharge_max_kwdc == pytest.approx(100.2051))
    assert (model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(100.2051))
    assert (model.BatterySystem.batt_power_discharge_max_kwac == pytest.approx(98.2009))
    assert (model.BatterySystem.batt_power_charge_max_kwac == pytest.approx(102.2501))


def test_liion_dc_connected_ac_sizing():
    model = batt.default("GenericBatteryCommercial")
    model.BatteryCell.batt_chem = 1
    model.Inverter.inverter_model = 0
    model.Inverter.inv_snl_eff_cec = 100
    model.BatterySystem.batt_ac_or_dc = 0
    BatteryTools.battery_model_sizing(model, 100, 400, 500, size_by_ac_not_dc=True)
    assert (model.BatterySystem.batt_computed_bank_capacity == pytest.approx(408.7017))
    assert (model.BatterySystem.batt_power_discharge_max_kwdc == pytest.approx(102.1754))
    assert (model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(98.1292))
    assert (model.BatterySystem.batt_power_discharge_max_kwac == pytest.approx(100.1319))
    assert (model.BatterySystem.batt_power_charge_max_kwac == pytest.approx(100.1319))
    assert(model.BatterySystem.batt_current_discharge_max == pytest.approx(204.1876))
    assert(model.BatterySystem.batt_current_charge_max == pytest.approx(196.1016))
