import pytest

import PySAM.BatteryTools as BatteryTools
import PySAM.StandAloneBattery as batt


def test_leadacid():
    model = batt.default("GenericBatteryCommercial")
    model.BatteryCell.batt_chem = 0
    assert(model.BatterySystem.batt_computed_bank_capacity != pytest.approx(100, .5))
    assert(model.BatterySystem.batt_power_charge_max_kwdc != pytest.approx(50, 0.5))

    BatteryTools.battery_model_sizing(model, 100, 400, 500)
    assert(model.BatterySystem.batt_computed_strings == 370)
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
    assert(model.BatterySystem.batt_computed_bank_capacity == pytest.approx(416.583))
    assert(model.BatterySystem.batt_power_discharge_max_kwdc == pytest.approx(104.1457))
    assert(model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(95.9807))
    assert(model.BatterySystem.batt_power_discharge_max_kwac == pytest.approx(99.9799))
    assert(model.BatterySystem.batt_power_charge_max_kwac == pytest.approx(99.9799))
    assert(model.BatterySystem.batt_current_discharge_max == pytest.approx(208.1250))
    assert(model.BatterySystem.batt_current_charge_max == pytest.approx(191.808))


def test_liion_ac_connected_dc_sizing():
    model = batt.default("GenericBatteryCommercial")
    model.BatteryCell.batt_chem = 1
    model.BatterySystem.batt_ac_or_dc = 1   # ac
    BatteryTools.battery_model_sizing(model, 100, 400, 500, size_by_ac_not_dc=False)
    assert(model.BatterySystem.batt_computed_bank_capacity == pytest.approx(399.6945))
    assert(model.BatterySystem.batt_power_discharge_max_kwdc == pytest.approx(99.9236))
    assert(model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(99.9236))
    assert(model.BatterySystem.batt_power_discharge_max_kwac == pytest.approx(95.9266))
    assert(model.BatterySystem.batt_power_charge_max_kwac == pytest.approx(104.0871))
    assert(model.BatterySystem.batt_current_discharge_max == pytest.approx(199.6875))
    assert(model.BatterySystem.batt_current_charge_max == pytest.approx(199.6875))


def test_liion_dc_connected_dc_sizing():
    model = batt.default("GenericBatteryCommercial")
    model.BatteryCell.batt_chem = 1
    model.Inverter.inverter_model = 0
    model.Inverter.inv_snl_eff_cec = 50
    model.BatterySystem.batt_ac_or_dc = 0
    BatteryTools.battery_model_sizing(model, 100, 400, 500)
    assert (model.BatterySystem.batt_computed_bank_capacity == pytest.approx(399.6945))
    assert (model.BatterySystem.batt_power_discharge_max_kwdc == pytest.approx(99.9236))
    assert (model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(99.9236))
    assert (model.BatterySystem.batt_power_discharge_max_kwac == pytest.approx(48.9626))
    assert (model.BatterySystem.batt_power_charge_max_kwac == pytest.approx(203.9257))
    assert(model.BatterySystem.batt_current_discharge_max == pytest.approx(199.6875))
    assert(model.BatterySystem.batt_current_charge_max == pytest.approx(199.6875))

    model.Inverter.inv_snl_eff_cec = 100
    model.BatterySystem.batt_ac_or_dc = 0
    BatteryTools.battery_model_sizing(model, 100, 400, 500)
    assert (model.BatterySystem.batt_computed_bank_capacity == pytest.approx(399.6945))
    assert (model.BatterySystem.batt_power_discharge_max_kwdc == pytest.approx(99.9236))
    assert (model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(99.9236))
    assert (model.BatterySystem.batt_power_discharge_max_kwac == pytest.approx(97.9251))
    assert (model.BatterySystem.batt_power_charge_max_kwac == pytest.approx(101.9628))


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
