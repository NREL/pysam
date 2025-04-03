import math
from typing import List, Optional
import numpy as np
import PySAM.Pvsamv1 as PVSamv1
import pandas as pd


"""

This file contains all the utilities required to make intermediate calculations of the PV design and layout.

Functions that can be kept separate and self-contained should be here to enable re-use by other scripts and tests.
Making these functions standalone helps clarify the required inputs and function scope.
It also reduces the bulk of the PVPlant classes, making it easier to understand what aggregate logic it performs.

These may include any helper functions for calculating any system variable such as number of inverters, combiner boxes, etc
or for estimating some value given a PV layout

"""
def find_modules_per_string(
    model,
    v_mppt_min: float,
    v_mppt_max: float,
    v_mp_module: float,
    v_oc_module: float,
    inv_vdcmax: float,
    target_relative_string_voltage: float=None,
    ) -> float:
    """
    Helper function for size_electrical_parameters that calculates the number of modules per string to best match target string voltage

    :param model: PySAM.PVsamv1 model
    :param v_mppt_min: lower boundary of inverter maximum-power-point operating window, V
    :param v_mppt_max: upper boundary of inverter maximum-power-point operating window, V
    :param v_mp_module: voltage of module at maximum point point at reference conditions, V
    :param v_oc_module: open circuit voltage of module at reference conditions, V
    :param inv_vdcmax: maximum inverter input DC voltage, V
    :param target_relative_string_voltage: relative string voltage within MPPT voltage window, [0, 1]

    :returns: number of modules per string
    """
    if v_mp_module <= 0:
        raise Exception("Module maximum power point voltage must be greater than 0.")
    if target_relative_string_voltage is None:
        target_relative_string_voltage = 0.5

    target_string_voltage = v_mppt_min + target_relative_string_voltage * (v_mppt_max - v_mppt_min)
    modules_per_string = max(1, round(target_string_voltage / v_mp_module))
    if inv_vdcmax > 0:
        while modules_per_string > 0 and modules_per_string * v_oc_module > inv_vdcmax:
            modules_per_string -= 1
    model.SystemDesign.subarray1_modules_per_string = modules_per_string
    return modules_per_string


def find_inverter_count(
    model,
    dc_ac_ratio: float,
    modules_per_string: float,
    n_strings: float,
    module_power: float,
    inverter_power: float,
    ):
    """
    Helper function for size_electrical_parameters that sizes the number of inverters

    :param model: PySAM.Pvsamv1 model
    :param dc_ac_ratio: DC-to-AC ratio
    :param modules_per_string: modules per string
    :param n_strings: number of strings in array
    :param module_power: module power at maximum point point at reference conditions, kW
    :param inverter_power: inverter maximum AC power, kW

    :returns: number of inverters in array
    """
    n_inverters_frac = modules_per_string * n_strings * module_power / (dc_ac_ratio * inverter_power)
    n_inverters = max(1, round(n_inverters_frac))
    model.SystemDesign.inverter_count = n_inverters
    return n_inverters


def size_electrical_parameters(
    model,
    target_system_capacity: float,
    target_dc_ac_ratio: float,
    vdcmax_inverter: Optional[float]=None,
    n_inputs_inverter: Optional[float]=None,
    n_inputs_combiner: Optional[float]=None,
    ):
    """
    Calculates the number of strings, combiner boxes and inverters to best match target capacity and DC/AC ratio

    :param model: PySAM.Pvsamv1 model
    :param target_system_capacity: target system capacity, kW
    :param target_dc_ac_ratio: target DC-to-AC ratio
    :param vdcmax_inverter: inverter maximum DC voltage, V
    :param n_inputs_inverter: number of DC inputs per inverter
    :param n_inputs_combiner: number of DC inputs per combiner box

    :returns: number of strings, number of combiner boxes, number of inverters, calculated system capacity, kW
    """
    

    module_model = model.Module.module_model
    module_power = 0
    module_vmp = 0
    module_voc = 0
    
    if(module_model==0):
        ref = int(model.SimpleEfficiencyModuleModel.spe_reference)
        eff_list = [model.SimpleEfficiencyModuleModel.spe_eff0, model.SimpleEfficiencyModuleModel.spe_eff1, model.SimpleEfficiencyModuleModel.spe_eff2, model.SimpleEfficiencyModuleModel.spe_eff3, model.SimpleEfficiencyModuleModel.spe_eff4]
        rad_list = [model.SimpleEfficiencyModuleModel.spe_rad0, model.SimpleEfficiencyModuleModel.spe_rad1, model.SimpleEfficiencyModuleModel.spe_rad2, model.SimpleEfficiencyModuleModel.spe_rad3, model.SimpleEfficiencyModuleModel.spe_rad4]
        eff = eff_list[ref]
        rad = rad_list[ref]
        area = model.SimpleEfficiencyModuleModel.spe_area
        module_power = eff / 100.0 * rad * area #Wdc
        module_vmp = model.SimpleEfficiencyModuleModel.spe_vmp
        module_voc = model.SimpleEfficiencyModuleModel.spe_voc
    elif(module_model==1):
        module_power = model.CECPerformanceModelWithModuleDatabase.cec_v_mp_ref * model.CECPerformanceModelWithModuleDatabase.cec_i_mp_ref
        module_vmp = model.CECPerformanceModelWithModuleDatabase.cec_v_mp_ref
        module_voc = model.CECPerformanceModelWithModuleDatabase.cec_v_oc_ref
    elif(module_model==2):
        module_vmp = model.CECPerformanceModelWithUserEnteredSpecifications.sixpar_vmp
        module_voc = model.CECPerformanceModelWithUserEnteredSpecifications.sixpar_voc
        module_power = module_vmp * model.CECPerformanceModelWithUserEnteredSpecifications.sixpar_imp
    elif(module_model==3):
        print('This function does not currently work for the Sandia Array Performance Model')
        '''
        module_power = model.SandiaPVArrayPerformanceModelWithModuleDatabase.snl_ref_pmp
        module_vmp = model.SandiaPVArrayPerformanceModelWithModuleDatabase.snl_ref_vmp
        module_voc = model.SandiaPVArrayPerformanceModelWithModuleDatabase.snl_ref_voc
        '''
        return
    elif(module_model==4):
        module_vmp = model.IEC61853SingleDiodeModel.sd11par_Vmp0
        module_voc = model.IEC61853SingleDiodeModel.sd11par_Voc0
        module_power = module_vmp * model.IEC61853SingleDiodeModel .sd11par_Imp0
    elif(module_model==5):
        module_vmp = model.MermoudLejeuneSingleDiodeModel.mlm_V_mp_ref
        module_voc = model.MermoudLejeuneSingleDiodeModel.mlm_V_oc_ref
        module_power = module_vmp * model.MermoudLejeuneSingleDiodeModel.mlm_I_mp_ref
    else:
        print('The module model is not recognized. Please use a valid module model.')
        return

    inverter_model = model.Inverter.inverter_model
    inv_power = 0
    vdcmax_inv = 0
    v_mppt_max = 0
    v_mppt_min = 0
    
    if(inverter_model==0):
        inv_power = model.InverterCECDatabase.inv_snl_paco
        vdcmax_inv = model.InverterCECDatabase.inv_snl_vdcmax
    elif (inverter_model==1):
        inv_power = model.InverterDatasheet.inv_ds_paco
        vdcmax_inv = model.InverterDatasheet.inv_ds_vdcmax
    elif (inverter_model==1):
        inv_power = model.InverterPartLoadCurve.inv_pd_paco
        vdcmax_inv = model.InverterPartLoadCurve.inv_pd_vdcmax
    elif (inverter_model==1):
        inv_power = model.InverterCECCoefficientGenerator.inv_cec_cg_paco
        vdcmax_inv = model.InverterCECCoefficientGenerator.inv_cec_cg_vdcmax
    elif (inverter_model==1):
        inv_power = model.InverterMermoudLejeuneModel .ond_PMaxOUT
        vdcmax_inv = model.InverterMermoudLejeuneModel .ond_VAbsMax
    else:
        print('The inverter model is not recognized. Please use a valid inverter model.')
        return

    if vdcmax_inverter is not None:
        vdcmax_inv = vdcmax_inverter
    v_mppt_min = model.Inverter.mppt_low_inverter
    v_mppt_max = model.Inverter.mppt_hi_inverter
    modules_per_string = find_modules_per_string(model, v_mppt_min, v_mppt_max, module_vmp, module_voc, vdcmax_inv)

    n_strings_frac = target_system_capacity * 1000.0 / (modules_per_string * module_power) #Wac/Wdc
    n_strings = max(1, round(n_strings_frac))

    if target_dc_ac_ratio < 0:
        target_dc_ac_ratio = 1
    n_inverters = find_inverter_count(
        model,
        dc_ac_ratio=target_dc_ac_ratio,
        modules_per_string=modules_per_string,
        n_strings=n_strings,
        module_power=module_power / 1000.0, #kWdc
        inverter_power=inv_power / 1000.0, #kWac
        )

    if n_inputs_combiner is not None and n_inputs_inverter is not None:
        n_combiners = math.ceil(n_strings / n_inputs_combiner)
        # Ensure there are enough inverters for the number of combiner boxes
        n_inverters = max(n_inverters, math.ceil(n_combiners / n_inputs_inverter))
    else:
        n_combiners = None

    # Verify sizing was close to the target size, otherwise error out
    calculated_system_capacity = verify_capacity_from_electrical_parameters(
        system_capacity_target=target_system_capacity,
        n_strings=[n_strings],
        modules_per_string=[modules_per_string],
        module_power=module_power / 1000.0 #kWac
    )
    model.SystemDesign.subarray1_modules_per_string = modules_per_string
    model.SystemDesign.subarray1_nstrings = n_strings
    model.SystemDesign.system_capacity = calculated_system_capacity
    return n_strings, n_combiners, n_inverters, calculated_system_capacity


def verify_capacity_from_electrical_parameters(
    system_capacity_target: float,
    n_strings: List[int],
    modules_per_string: List[int],
    module_power: float,
    percent_max_deviation: float = 5
    ) -> float:
    """
    Computes system capacity from specified number of strings, modules per string and module power.
    If computed capacity is significantly different than the specified capacity an exception will be thrown.
    
    :param system_capacity_target: target system capacity, kW
    :param n_strings: number of strings in each subarray, -
    :param modules_per_string: modules per string in each subarray, -
    :param module_power: module power at maximum point point at reference conditions, kW
    :param percent_max_deviation: if calculated system capacity differs from target by this percent or more, raise an exception; if None, do not check

    :returns: calculated system capacity, kW
    """
    PERCENT_MAX_DEVIATION = 5       # [%]
    assert len(n_strings) == len(modules_per_string)
    calculated_system_capacity = sum(np.array(n_strings) * np.array(modules_per_string)) * module_power
    if percent_max_deviation is not None and abs((calculated_system_capacity / system_capacity_target - 1)) * 100 > percent_max_deviation:
        raise Exception(f"The specified system capacity of {system_capacity_target} kW is more than " \
                        f"{percent_max_deviation}% from the value calculated from the specified number " \
                        f"of strings, modules per string and module power ({int(calculated_system_capacity)} kW).")

    return calculated_system_capacity


def align_from_capacity(
    system_capacity_target: float,
    dc_ac_ratio: float,
    modules_per_string: float,
    module_power: float,
    inverter_power: float,
    ) -> list:
    """
    Ensure coherence between parameters for detailed PV model (pvsamv1),
    keeping the DC-to-AC ratio approximately the same

    :param system_capacity_target: target system capacity, kW
    :param dc_ac_ratio: DC-to-AC ratio
    :param modules_per_string: modules per string, -
    :param module_power: module power at maximum point point at reference conditions, kW
    :param inverter_power: inverter maximum AC power, kW
    :param n_inverters_orig: original number of inverters

    :returns: number strings, calculated system capacity [kW], number of inverters
    """
    n_strings_frac = system_capacity_target / (modules_per_string * module_power)
    n_strings = max(1, round(n_strings_frac))
    system_capacity = module_power * n_strings * modules_per_string

    if dc_ac_ratio > 0:
        n_inverters_frac = modules_per_string * n_strings * module_power \
                           / (dc_ac_ratio * inverter_power)
    else:
        n_inverters_frac = modules_per_string * n_strings * module_power / inverter_power
    n_inverters = max(1, round(n_inverters_frac))

    return n_strings, system_capacity, n_inverters


def get_num_modules(pvsam_model) -> float:
    """
    Return the number of modules in all subarrays
    """
    n_modules = 0
    en_subarray_list = [ pvsam_model.SystemDesign.subarray1_enable, pvsam_model.SystemDesign.subarray2_enable, pvsam_model.SystemDesign.subarray3_enable, pvsam_model.SystemDesign.subarray4_enable ]
    n_strings_list [ pvsam_model.SystemDesign.subarray1_nstrings, pvsam_model.SystemDesign.subarray2_nstrings, pvsam_model.SystemDesign.subarray3_nstrings, pvsam_model.SystemDesign.subarray4_nstrings ]
    n_modules_per_string_list [ pvsam_model.SystemDesign.subarray1_modules_per_string, pvsam_model.SystemDesign.subarray2_modules_per_string, pvsam_model.SystemDesign.subarray3_modules_per_string, pvsam_model.SystemDesign.subarray4_modules_per_string ]
    for i in range(1, 4+1):
        if i == 1 or en_subarray_list[i+1] == 1:
            n_modules += n_strings_list[i+1] * n_modules_per_string_list[i+1]
    return n_modules

'''
def get_modules_per_string(system_model) -> float:
    if isinstance(system_model, PVSamv1.Pvsamv1):
        return system_model.SystemDesign.subarray1_modules_per_string
    else:
        return pv_module.modules_per_string


def get_inverter_power(pvsam_model: PVSamv1.Pvsamv1) -> float:
    inverter_attribs = get_inverter_attribs(pvsam_model)
    return inverter_attribs['P_ac']
'''

def set_cec_module_library_selection(model, module_name: str) -> dict:
    """
    Return the module values from the CEC Module Database library as a dictionary. Requires module_model = 1.
    
    :param model: Pvsamv1 model to write the module values to
    :param module_name: Name of module for indexing library, str
    
    :returns: dictionary with variable values for selected module
    """
    module_model = model.Module.module_model
    if (module_model != 1):
        print("This function only works if module_model == 1 (CEC Performance Model with Module Database)")
        return

    file = 'https://raw.githubusercontent.com/NREL/SAM/patch/deploy/libraries/CEC%20Modules.csv'
    db = pd.read_csv(file, index_col=0, header=2) # Reading this might take 1 min or so, the database is big.

    print("This function does not set the bifaciality of a module based on the bifacial based on the lib_is_bifacial value. Please change cec_is_bifacial to 1 to make the module bifacial.")

    modfilter = db.index.str.startswith(module_name)
    CECMod = db[modfilter]
    CECParamList = CECMod.values.tolist()

    if (len(CECMod) > 1):
        print("More than 1 module found that matches the module name string. Please be more specific in the module name string.")
        return

    column_names = list(CECMod.columns)
    for columnName, columnData in CECMod.items():
        if (columnName.startswith("cec_") and columnName != 'cec_material' and columnName != 'cec_gamma_pmp'):
            model.value(columnName, columnData.iloc[0])
        else:
            continue
    
    mod_dict = CECMod.to_dict()
    return mod_dict

def set_cec_inverter_library_selection(model, inverter_name: str) -> dict:
    """
    Return the inverter values from the CEC Inverter Database library as a dictionary. Requires inverter_model = 0.
    
    :param model: Pvsamv1 model to write the inverter values to
    :param inverter_name: Name of inverter for indexing library, str
    
    :returns: dictionary with variable values for selected inverter
    """
    inv_model = model.Inverter.inverter_model
    if (inv_model != 0):
        print("This function only works if inverter_model == 1 (Inverter CEC Database)")
        return

    file = 'https://raw.githubusercontent.com/NREL/SAM/patch/deploy/libraries/CEC%20Inverters.csv'
    db = pd.read_csv(file, index_col=0, header=2) # Reading this might take 1 min or so, the database is big.

    print("This function does not see the number of MPPT inputs for the inverter. Please see inv_num_mppt to set the number of mppt inputs for an inverter.")

    invfilter = db.index.str.startswith(inverter_name)
    CECInv = db[invfilter]
    CECParamList = CECInv.values.tolist()
    print(len(CECInv), " inverters selected. Name of 1st entry: ", CECInv.index[0])
    #if (len(CECInv) > 1):
    #    print("More than 1 inverter found that matches the inverter name string. Please be more specific in the inverter name string.")
    #    return

    column_names = list(CECInv.columns)
    unused_cols = ["inv_snl_ac_voltage", "inv_snl_idcmax"]
    for columnName, columnData in CECInv.items():
        if (columnName.startswith("inv_snl") and columnName not in unused_cols):
            if(columnName.startswith("inv_snl_mppt_low")):
                model.Inverter.mppt_low_inverter = columnData.iloc[0]
            elif (columnName.startswith("inv_snl_mppt_hi")):
                model.Inverter.mppt_hi_inverter = columnData.iloc[0]
            else:
                model.value(columnName, columnData.iloc[0])
        else:
            continue
    
    inv_dict = CECInv.to_dict()
    return inv_dict


        
