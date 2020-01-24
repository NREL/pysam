import pytest

import PySAM.BatteryTools
import PySAM.StandAloneBattery as batt


def test_leadacid():
    model = batt.default("GenericSystemCommercial")
    model.BatteryCell.batt_chem = 0
    assert(model.BatterySystem.batt_computed_bank_capacity == pytest.approx(100, .5))
    assert(model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(50, 0.5))

    PySAM.BatteryTools.battery_model_sizing(model, 100, 400, 500)
    assert(model.BatterySystem.batt_computed_strings == 370)
    assert(model.BatterySystem.batt_computed_series == 139)
    assert(model.BatterySystem.batt_computed_bank_capacity == pytest.approx(416, 1))
    assert(model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(104, 1))

    PySAM.BatteryTools.battery_model_sizing(model, 100, 400, 500, 50, 60, 30)
    assert(model.BatterySystem.batt_computed_bank_capacity == pytest.approx(416, 1))
    assert(model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(104, 1))
    assert(model.BatteryCell.LeadAcid_q10_computed == pytest.approx(50, 5))
    assert(model.BatteryCell.LeadAcid_q20_computed == pytest.approx(60, 5))
    assert(model.BatteryCell.LeadAcid_qn_computed == pytest.approx(30, 5))


def test_liion():
    model = batt.default("GenericSystemCommercial")
    model.BatteryCell.batt_chem = 1
    PySAM.BatteryTools.battery_model_sizing(model, 100, 400, 500)
    assert(model.BatterySystem.batt_computed_bank_capacity == pytest.approx(400, 5))
    assert(model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(100, 20))


def test_dc():
    model = batt.default("GenericSystemCommercial")
    model.BatteryCell.batt_chem = 1
    model.Inverter.inverter_model = 0
    model.Inverter.inv_snl_eff_cec = 50
    model.BatterySystem.batt_ac_or_dc = 0
    PySAM.BatteryTools.battery_model_sizing(model, 100, 400, 500)
    assert (model.BatterySystem.batt_computed_bank_capacity == pytest.approx(400, 5))
    assert (model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(100, 20))
    assert (model.BatterySystem.batt_power_charge_max_kwac == pytest.approx(200, 5))
    assert (model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(100, 2))

    model.Inverter.inv_snl_eff_cec = 100
    model.BatterySystem.batt_ac_or_dc = 0
    PySAM.BatteryTools.battery_model_sizing(model, 100, 400, 500)
    assert (model.BatterySystem.batt_computed_bank_capacity == pytest.approx(400, 1))
    assert (model.BatterySystem.batt_power_charge_max_kwdc == pytest.approx(100, 1))
    print (model.BatterySystem.batt_power_charge_max_kwac)
    print (model.BatterySystem.batt_power_charge_max_kwdc)
