import pytest

import PySAM.Pvsamv1Tools
import PySAM.Pvsamv1 as pvsamv1


def test_default_system_sizing():
    model = pvsamv1.default("FlatPlatePVSingleOwner")
    model.SolarResource.solar_resource_file = 'phoenix_az_33.450495_-111.983688_psmv3_60_tmy.csv'
    model.Lifetime.analysis_period = 1
    n_strings, n_combiners, n_inverters, calculated_system_capacity = PySAM.Pvsamv1Tools.size_electrical_parameters(model, 130000, 1.2)
    assert(n_strings == 8748)
    assert(n_inverters == 43)
    assert(calculated_system_capacity == pytest.approx(130004, abs = 1))
    assert(model.SystemDesign.subarray1_modules_per_string == 28)
    assert(model.SystemDesign.system_capacity == pytest.approx(130004, abs = 1))

def test_spe_system_sizing():
    model = pvsamv1.default("FlatPlatePVSingleOwner")
    model.SolarResource.solar_resource_file = 'phoenix_az_33.450495_-111.983688_psmv3_60_tmy.csv'
    model.Module.module_model = 0 #SPE Model
    model.Lifetime.analysis_period = 1
    n_strings, n_combiners, n_inverters, calculated_system_capacity = PySAM.Pvsamv1Tools.size_electrical_parameters(model, 130000, 1.2)
    assert(n_strings == 8778)
    assert(n_inverters == 43)
    assert(calculated_system_capacity == pytest.approx(129995, abs = 1))
    assert(model.SystemDesign.subarray1_modules_per_string == 28)
    assert(model.SystemDesign.system_capacity == pytest.approx(129995, abs = 1))

def test_6par_system_sizing():
    model = pvsamv1.default("FlatPlatePVSingleOwner")
    model.Lifetime.analysis_period = 1
    n_strings, n_combiners, n_inverters, calculated_system_capacity = PySAM.Pvsamv1Tools.size_electrical_parameters(model, 130000, 1.2)
    assert(n_strings == 8748)
    assert(n_inverters == 43)
    assert(calculated_system_capacity == pytest.approx(130004, abs = 1))
    assert(model.SystemDesign.subarray1_modules_per_string == 28)
    assert(model.SystemDesign.system_capacity == pytest.approx(130004, abs = 1))

def test_cec_module_library_selection():
    model = pvsamv1.default("FlatPlatePVSingleOwner")
    mod_dict = PySAM.Pvsamv1Tools.set_cec_module_library_selection(model, "AIMS Power PV555MONO")
    assert(model.CECPerformanceModelWithModuleDatabase.cec_v_mp_ref == 43.3)
    assert(model.CECPerformanceModelWithModuleDatabase.cec_i_mp_ref == 12.81)
    assert(model.CECPerformanceModelWithModuleDatabase.cec_v_oc_ref == 49.9)
    assert(model.CECPerformanceModelWithModuleDatabase.cec_i_sc_ref == 13.74)

def test_cec_inverter_library_selection():
    model = pvsamv1.default("FlatPlatePVSingleOwner")
    inv_dict = PySAM.Pvsamv1Tools.set_cec_inverter_library_selection(model, "NEXTRACKER LLC: NXPCS3340K-HUD [800V]")
    assert(model.InverterCECDatabase.inv_snl_paco == 3347800)
    assert(model.Inverter.mppt_hi_inverter == 1500)
    assert(model.Inverter.mppt_low_inverter == 1200)
    assert(model.InverterCECDatabase.inv_snl_vdcmax == 1500)


