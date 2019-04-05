# import os
# os.system("rm -r /Users/dguittet/SAM-Dev/PySAM/build")
#
# from setuptools import sandbox
# sandbox.run_setup('setup.py', ['install'])


from sscapi import PySSC
def trytrough():
    ssc = PySSC()
    print('Current folder = /Users/dguittet/Temp')
    print('SSC Version = ', ssc.version())
    ssc.module_exec_set_print(0)
    data = ssc.data_create()
    ssc.data_set_string(data, b'file_name',
                        b'/Users/dguittet/SAM-Dev/sam/SAMd.app/Contents/solar_resource/tucson_az_32.116521_-110.933042_psmv3_60_tmy.csv');
    ssc.data_set_number(data, b'track_mode', 1)
    ssc.data_set_number(data, b'tilt', 0)
    ssc.data_set_number(data, b'azimuth', 0)
    ssc.data_set_number(data, b'I_bn_des', 950)
    ssc.data_set_number(data, b'solar_mult', 2.6771607398986816)
    ssc.data_set_number(data, b'T_loop_in_des', 90)
    ssc.data_set_number(data, b'T_loop_out', 150)
    ssc.data_set_number(data, b'q_pb_design', 5.1879100799560547)
    ssc.data_set_number(data, b'tshours', 6)
    ssc.data_set_number(data, b'nSCA', 4)
    ssc.data_set_number(data, b'nHCEt', 4)
    ssc.data_set_number(data, b'nColt', 4)
    ssc.data_set_number(data, b'nHCEVar', 4)
    ssc.data_set_number(data, b'nLoops', 8)
    ssc.data_set_number(data, b'eta_pump', 0.85000002384185791)
    ssc.data_set_number(data, b'HDR_rough', 4.6000001020729542e-05)
    ssc.data_set_number(data, b'theta_stow', 170)
    ssc.data_set_number(data, b'theta_dep', 10)
    ssc.data_set_number(data, b'Row_Distance', 15)
    ssc.data_set_number(data, b'FieldConfig', 1)
    ssc.data_set_number(data, b'is_model_heat_sink_piping', 0)
    ssc.data_set_number(data, b'L_heat_sink_piping', 50)
    ssc.data_set_number(data, b'm_dot_htfmin', 1)
    ssc.data_set_number(data, b'm_dot_htfmax', 12)
    ssc.data_set_number(data, b'Fluid', 31)
    ssc.data_set_number(data, b'wind_stow_speed', 25)
    field_fl_props = [
        [20, 4.179999828338623, 999, 0.0010000000474974513, 9.9999999747524271e-07, 0.58700001239776611,
         85.300003051757812],
        [40, 4.179999828338623, 993, 0.000653000024612993, 6.5799997628346318e-07, 0.61799997091293335, 169],
        [60, 4.179999828338623, 984, 0.00046700000530108809, 4.7500000732725312e-07, 0.64200001955032349, 252],
        [80, 4.190000057220459, 972, 0.00035499999648891389, 3.6500000533123966e-07, 0.65700000524520874, 336],
        [100, 4.2100000381469727, 959, 0.00028199999360367656, 2.9399998879853229e-07, 0.66600000858306885, 420],
        [120, 4.25, 944, 0.00023299999884329736, 2.4600001324870391e-07, 0.67000001668930054, 505],
        [140, 4.2800002098083496, 927, 0.00019700000120792538, 2.1200000333010394e-07, 0.67000001668930054, 590],
        [160, 4.3400001525878906, 908, 0.00017100000695791095, 1.8800000134433503e-07, 0.66699999570846558, 676],
        [180, 4.4000000953674316, 887, 0.0001500000071246177, 1.6900000332498166e-07, 0.66100001335144043, 764],
        [200, 4.4899997711181641, 865, 0.0001340000017080456, 1.5499999506118911e-07, 0.65100002288818359, 852],
        [220, 4.5799999237060547, 842, 0.00011800000356743112, 1.4100000100825127e-07, 0.64099997282028198, 941]];
    ssc.data_set_matrix(data, b'field_fl_props', field_fl_props);
    ssc.data_set_number(data, b'T_fp', 10)
    ssc.data_set_number(data, b'V_hdr_max', 3)
    ssc.data_set_number(data, b'V_hdr_min', 2)
    ssc.data_set_number(data, b'Pipe_hl_coef', 0.44999998807907104)
    ssc.data_set_number(data, b'SCA_drives_elec', 125)
    ssc.data_set_number(data, b'water_usage_per_wash', 0.69999998807907104)
    ssc.data_set_number(data, b'washing_frequency', 12)
    ssc.data_set_number(data, b'accept_mode', 0)
    ssc.data_set_number(data, b'accept_init', 0)
    ssc.data_set_number(data, b'accept_loc', 1)
    ssc.data_set_number(data, b'mc_bal_hot', 0.20000000298023224)
    ssc.data_set_number(data, b'mc_bal_cold', 0.20000000298023224)
    ssc.data_set_number(data, b'mc_bal_sca', 4.5)
    W_aperture = [6, 6, 6, 6];
    ssc.data_set_array(data, b'W_aperture', W_aperture);
    A_aperture = [656, 656, 656, 656];
    ssc.data_set_array(data, b'A_aperture', A_aperture);
    TrackingError = [0.98799997568130493, 0.98799997568130493, 0.98799997568130493, 0.98799997568130493];
    ssc.data_set_array(data, b'TrackingError', TrackingError);
    GeomEffects = [0.95200002193450928, 0.95200002193450928, 0.95200002193450928, 0.95200002193450928];
    ssc.data_set_array(data, b'GeomEffects', GeomEffects);
    Rho_mirror_clean = [0.93000000715255737, 0.93000000715255737, 0.93000000715255737, 0.93000000715255737];
    ssc.data_set_array(data, b'Rho_mirror_clean', Rho_mirror_clean);
    Dirt_mirror = [0.97000002861022949, 0.97000002861022949, 0.97000002861022949, 0.97000002861022949];
    ssc.data_set_array(data, b'Dirt_mirror', Dirt_mirror);
    Error = [1, 1, 1, 1];
    ssc.data_set_array(data, b'Error', Error);
    Ave_Focal_Length = [2.1500000953674316, 2.1500000953674316, 2.1500000953674316, 2.1500000953674316];
    ssc.data_set_array(data, b'Ave_Focal_Length', Ave_Focal_Length);
    L_SCA = [115, 115, 115, 115];
    ssc.data_set_array(data, b'L_SCA', L_SCA);
    L_aperture = [14.375, 14.375, 14.375, 14.375];
    ssc.data_set_array(data, b'L_aperture', L_aperture);
    ColperSCA = [8, 8, 8, 8];
    ssc.data_set_array(data, b'ColperSCA', ColperSCA);
    Distance_SCA = [1, 1, 1, 1];
    ssc.data_set_array(data, b'Distance_SCA', Distance_SCA);
    IAM_matrix = [[1, 0.032699998468160629, -0.13510000705718994], [1, 0.032699998468160629, -0.13510000705718994],
                  [1, 0.032699998468160629, -0.13510000705718994], [1, 0.032699998468160629, -0.13510000705718994]];
    ssc.data_set_matrix(data, b'IAM_matrix', IAM_matrix);
    HCE_FieldFrac = [[1, 0, 0, 0], [1, 0, 0, 0], [1, 0, 0, 0], [1, 0, 0, 0]];
    ssc.data_set_matrix(data, b'HCE_FieldFrac', HCE_FieldFrac);
    D_2 = [[0.075999997556209564, 0.075999997556209564, 0.075999997556209564, 0.075999997556209564],
           [0.075999997556209564, 0.075999997556209564, 0.075999997556209564, 0.075999997556209564],
           [0.075999997556209564, 0.075999997556209564, 0.075999997556209564, 0.075999997556209564],
           [0.075999997556209564, 0.075999997556209564, 0.075999997556209564, 0.075999997556209564]];
    ssc.data_set_matrix(data, b'D_2', D_2);
    D_3 = [[0.079999998211860657, 0.079999998211860657, 0.079999998211860657, 0.079999998211860657],
           [0.079999998211860657, 0.079999998211860657, 0.079999998211860657, 0.079999998211860657],
           [0.079999998211860657, 0.079999998211860657, 0.079999998211860657, 0.079999998211860657],
           [0.079999998211860657, 0.079999998211860657, 0.079999998211860657, 0.079999998211860657]];
    ssc.data_set_matrix(data, b'D_3', D_3);
    D_4 = [[0.11500000208616257, 0.11500000208616257, 0.11500000208616257, 0.11500000208616257],
           [0.11500000208616257, 0.11500000208616257, 0.11500000208616257, 0.11500000208616257],
           [0.11500000208616257, 0.11500000208616257, 0.11500000208616257, 0.11500000208616257],
           [0.11500000208616257, 0.11500000208616257, 0.11500000208616257, 0.11500000208616257]];
    ssc.data_set_matrix(data, b'D_4', D_4);
    D_5 = [[0.11999999731779099, 0.11999999731779099, 0.11999999731779099, 0.11999999731779099],
           [0.11999999731779099, 0.11999999731779099, 0.11999999731779099, 0.11999999731779099],
           [0.11999999731779099, 0.11999999731779099, 0.11999999731779099, 0.11999999731779099],
           [0.11999999731779099, 0.11999999731779099, 0.11999999731779099, 0.11999999731779099]];
    ssc.data_set_matrix(data, b'D_5', D_5);
    D_p = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]];
    ssc.data_set_matrix(data, b'D_p', D_p);
    Flow_type = [[1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1]];
    ssc.data_set_matrix(data, b'Flow_type', Flow_type);
    Rough = [[4.5000000682193786e-05, 4.5000000682193786e-05, 4.5000000682193786e-05, 4.5000000682193786e-05],
             [4.5000000682193786e-05, 4.5000000682193786e-05, 4.5000000682193786e-05, 4.5000000682193786e-05],
             [4.5000000682193786e-05, 4.5000000682193786e-05, 4.5000000682193786e-05, 4.5000000682193786e-05],
             [4.5000000682193786e-05, 4.5000000682193786e-05, 4.5000000682193786e-05, 4.5000000682193786e-05]];
    ssc.data_set_matrix(data, b'Rough', Rough);
    alpha_env = [[0.019999999552965164, 0.019999999552965164, 0, 0],
                 [0.019999999552965164, 0.019999999552965164, 0, 0],
                 [0.019999999552965164, 0.019999999552965164, 0, 0],
                 [0.019999999552965164, 0.019999999552965164, 0, 0]];
    ssc.data_set_matrix(data, b'alpha_env', alpha_env);
    epsilon_3_11 = [[100, 0.064000003039836884], [150, 0.066500000655651093], [200, 0.070000000298023224],
                    [250, 0.074500001966953278], [300, 0.079999998211860657], [350, 0.086499996483325958],
                    [400, 0.093999996781349182], [450, 0.10249999910593033], [500, 0.1120000034570694]];
    ssc.data_set_matrix(data, b'epsilon_3_11', epsilon_3_11);
    epsilon_3_12 = [[0.64999997615814209]];
    ssc.data_set_matrix(data, b'epsilon_3_12', epsilon_3_12);
    epsilon_3_13 = [[0.64999997615814209]];
    ssc.data_set_matrix(data, b'epsilon_3_13', epsilon_3_13);
    epsilon_3_14 = [[0]];
    ssc.data_set_matrix(data, b'epsilon_3_14', epsilon_3_14);
    epsilon_3_21 = [[100, 0.064000003039836884], [150, 0.066500000655651093], [200, 0.070000000298023224],
                    [250, 0.074500001966953278], [300, 0.079999998211860657], [350, 0.086499996483325958],
                    [400, 0.093999996781349182], [450, 0.10249999910593033], [500, 0.1120000034570694]];
    ssc.data_set_matrix(data, b'epsilon_3_21', epsilon_3_21);
    epsilon_3_22 = [[0.64999997615814209]];
    ssc.data_set_matrix(data, b'epsilon_3_22', epsilon_3_22);
    epsilon_3_23 = [[0.64999997615814209]];
    ssc.data_set_matrix(data, b'epsilon_3_23', epsilon_3_23);
    epsilon_3_24 = [[0]];
    ssc.data_set_matrix(data, b'epsilon_3_24', epsilon_3_24);
    epsilon_3_31 = [[100, 0.064000003039836884], [150, 0.066500000655651093], [200, 0.070000000298023224],
                    [250, 0.074500001966953278], [300, 0.079999998211860657], [350, 0.086499996483325958],
                    [400, 0.093999996781349182], [450, 0.10249999910593033], [500, 0.1120000034570694]];
    ssc.data_set_matrix(data, b'epsilon_3_31', epsilon_3_31);
    epsilon_3_32 = [[0.64999997615814209]];
    ssc.data_set_matrix(data, b'epsilon_3_32', epsilon_3_32);
    epsilon_3_33 = [[0.64999997615814209]];
    ssc.data_set_matrix(data, b'epsilon_3_33', epsilon_3_33);
    epsilon_3_34 = [[0]];
    ssc.data_set_matrix(data, b'epsilon_3_34', epsilon_3_34);
    epsilon_3_41 = [[100, 0.064000003039836884], [150, 0.066500000655651093], [200, 0.070000000298023224],
                    [250, 0.074500001966953278], [300, 0.079999998211860657], [350, 0.086499996483325958],
                    [400, 0.093999996781349182], [450, 0.10249999910593033], [500, 0.1120000034570694]];
    ssc.data_set_matrix(data, b'epsilon_3_41', epsilon_3_41);
    epsilon_3_42 = [[0.64999997615814209]];
    ssc.data_set_matrix(data, b'epsilon_3_42', epsilon_3_42);
    epsilon_3_43 = [[0.64999997615814209]];
    ssc.data_set_matrix(data, b'epsilon_3_43', epsilon_3_43);
    epsilon_3_44 = [[0]];
    ssc.data_set_matrix(data, b'epsilon_3_44', epsilon_3_44);
    alpha_abs = [[0.96299999952316284, 0.96299999952316284, 0.80000001192092896, 0],
                 [0.96299999952316284, 0.96299999952316284, 0.80000001192092896, 0],
                 [0.96299999952316284, 0.96299999952316284, 0.80000001192092896, 0],
                 [0.96299999952316284, 0.96299999952316284, 0.80000001192092896, 0]];
    ssc.data_set_matrix(data, b'alpha_abs', alpha_abs);
    Tau_envelope = [[0.96399998664855957, 0.96399998664855957, 1, 0],
                    [0.96399998664855957, 0.96399998664855957, 1, 0],
                    [0.96399998664855957, 0.96399998664855957, 1, 0],
                    [0.96399998664855957, 0.96399998664855957, 1, 0]];
    ssc.data_set_matrix(data, b'Tau_envelope', Tau_envelope);
    EPSILON_4 = [[0.86000001430511475, 0.86000001430511475, 1, 0], [0.86000001430511475, 0.86000001430511475, 1, 0],
                 [0.86000001430511475, 0.86000001430511475, 1, 0],
                 [0.86000001430511475, 0.86000001430511475, 1, 0]];
    ssc.data_set_matrix(data, b'EPSILON_4', EPSILON_4);
    EPSILON_5 = [[0.86000001430511475, 0.86000001430511475, 1, 0], [0.86000001430511475, 0.86000001430511475, 1, 0],
                 [0.86000001430511475, 0.86000001430511475, 1, 0],
                 [0.86000001430511475, 0.86000001430511475, 1, 0]];
    ssc.data_set_matrix(data, b'EPSILON_5', EPSILON_5);
    GlazingIntactIn = [[1, 1, 0, 1], [1, 1, 0, 1], [1, 1, 0, 1], [1, 1, 0, 1]];
    ssc.data_set_matrix(data, b'GlazingIntactIn', GlazingIntactIn);
    P_a = [[9.9999997473787516e-05, 750, 750, 0], [9.9999997473787516e-05, 750, 750, 0],
           [9.9999997473787516e-05, 750, 750, 0], [9.9999997473787516e-05, 750, 750, 0]];
    ssc.data_set_matrix(data, b'P_a', P_a);
    AnnulusGas = [[27, 1, 1, 1], [27, 1, 1, 1], [27, 1, 1, 27], [27, 1, 1, 27]];
    ssc.data_set_matrix(data, b'AnnulusGas', AnnulusGas);
    AbsorberMaterial = [[1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1]];
    ssc.data_set_matrix(data, b'AbsorberMaterial', AbsorberMaterial);
    Shadowing = [[0.93500000238418579, 0.93500000238418579, 0.93500000238418579, 0.96299999952316284],
                 [0.93500000238418579, 0.93500000238418579, 0.93500000238418579, 0.96299999952316284],
                 [0.93500000238418579, 0.93500000238418579, 0.93500000238418579, 0.96299999952316284],
                 [0.93500000238418579, 0.93500000238418579, 0.93500000238418579, 0.96299999952316284]];
    ssc.data_set_matrix(data, b'Shadowing', Shadowing);
    Dirt_HCE = [[0.98000001907348633, 0.98000001907348633, 1, 0.98000001907348633],
                [0.98000001907348633, 0.98000001907348633, 1, 0.98000001907348633],
                [0.98000001907348633, 0.98000001907348633, 1, 0.98000001907348633],
                [0.98000001907348633, 0.98000001907348633, 1, 0.98000001907348633]];
    ssc.data_set_matrix(data, b'Dirt_HCE', Dirt_HCE);
    Design_loss = [[190, 1270, 1500, 0], [190, 1270, 1500, 0], [190, 1270, 1500, 0], [190, 1270, 1500, 0]];
    ssc.data_set_matrix(data, b'Design_loss', Design_loss);
    SCAInfoArray = [[1, 1], [1, 1], [1, 1], [1, 1]];
    ssc.data_set_matrix(data, b'SCAInfoArray', SCAInfoArray);
    SCADefocusArray = [4, 3, 2, 1];
    ssc.data_set_array(data, b'SCADefocusArray', SCADefocusArray);
    ssc.data_set_number(data, b'pb_pump_coef', 0.55000001192092896)
    ssc.data_set_number(data, b'init_hot_htf_percent', 30)
    ssc.data_set_number(data, b'h_tank', 15)
    ssc.data_set_number(data, b'cold_tank_max_heat', 0.5)
    ssc.data_set_number(data, b'u_tank', 0.30000001192092896)
    ssc.data_set_number(data, b'tank_pairs', 1)
    ssc.data_set_number(data, b'cold_tank_Thtr', 60)
    ssc.data_set_number(data, b'h_tank_min', 0.5)
    ssc.data_set_number(data, b'hot_tank_Thtr', 110)
    ssc.data_set_number(data, b'hot_tank_max_heat', 1)
    ssc.data_set_number(data, b'calc_design_pipe_vals', 1)
    ssc.data_set_number(data, b'N_max_hdr_diams', 10)
    ssc.data_set_number(data, b'L_rnr_pb', 25)
    ssc.data_set_number(data, b'L_rnr_per_xpan', 70)
    ssc.data_set_number(data, b'L_xpan_hdr', 20)
    ssc.data_set_number(data, b'L_xpan_rnr', 20)
    ssc.data_set_number(data, b'Min_rnr_xpans', 1)
    ssc.data_set_number(data, b'northsouth_field_sep', 20)
    ssc.data_set_number(data, b'N_hdr_per_xpan', 2)
    ssc.data_set_number(data, b'offset_xpan_hdr', 1)
    K_cpnt = [[0.89999997615814209, 0, 0.18999999761581421, 0, 0.89999997615814209, -1, -1, -1, -1, -1, -1],
              [0, 0.60000002384185791, 0.05000000074505806, 0, 0.60000002384185791, 0, 0.60000002384185791, 0,
               0.41999998688697815, 0, 0.15000000596046448],
              [0.05000000074505806, 0, 0.41999998688697815, 0, 0.60000002384185791, 0, 0.60000002384185791, 0,
               0.41999998688697815, 0, 0.15000000596046448],
              [0.05000000074505806, 0, 0.41999998688697815, 0, 0.60000002384185791, 0, 0.60000002384185791, 0,
               0.41999998688697815, 0, 0.15000000596046448],
              [0.05000000074505806, 0, 0.41999998688697815, 0, 0.60000002384185791, 0, 0.60000002384185791, 0,
               0.41999998688697815, 0, 0.15000000596046448],
              [0.05000000074505806, 0, 0.41999998688697815, 0, 0.60000002384185791, 0, 0.60000002384185791, 0,
               0.15000000596046448, 0.60000002384185791, 0],
              [0.89999997615814209, 0, 0.18999999761581421, 0, 0.89999997615814209, -1, -1, -1, -1, -1, -1]];
    ssc.data_set_matrix(data, b'K_cpnt', K_cpnt);
    D_cpnt = [[0.085000000894069672, 0.063500002026557922, 0.085000000894069672, 0.063500002026557922,
               0.085000000894069672, -1, -1, -1, -1, -1, -1],
              [0.085000000894069672, 0.085000000894069672, 0.085000000894069672, 0.063500002026557922,
               0.063500002026557922, 0.063500002026557922, 0.063500002026557922, 0.063500002026557922,
               0.063500002026557922, 0.063500002026557922, 0.085000000894069672],
              [0.085000000894069672, 0.063500002026557922, 0.063500002026557922, 0.063500002026557922,
               0.063500002026557922, 0.063500002026557922, 0.063500002026557922, 0.063500002026557922,
               0.063500002026557922, 0.063500002026557922, 0.085000000894069672],
              [0.085000000894069672, 0.063500002026557922, 0.063500002026557922, 0.063500002026557922,
               0.063500002026557922, 0.063500002026557922, 0.063500002026557922, 0.063500002026557922,
               0.063500002026557922, 0.063500002026557922, 0.085000000894069672],
              [0.085000000894069672, 0.063500002026557922, 0.063500002026557922, 0.063500002026557922,
               0.063500002026557922, 0.063500002026557922, 0.063500002026557922, 0.063500002026557922,
               0.063500002026557922, 0.063500002026557922, 0.085000000894069672],
              [0.085000000894069672, 0.063500002026557922, 0.063500002026557922, 0.063500002026557922,
               0.063500002026557922, 0.063500002026557922, 0.063500002026557922, 0.063500002026557922,
               0.085000000894069672, 0.085000000894069672, 0.085000000894069672],
              [0.085000000894069672, 0.063500002026557922, 0.085000000894069672, 0.063500002026557922,
               0.085000000894069672, -1, -1, -1, -1, -1, -1]];
    ssc.data_set_matrix(data, b'D_cpnt', D_cpnt);
    L_cpnt = [[0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1], [0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0],
              [0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0], [0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0],
              [0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0], [0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0],
              [0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1]];
    ssc.data_set_matrix(data, b'L_cpnt', L_cpnt);
    Type_cpnt = [[0, 1, 0, 1, 0, -1, -1, -1, -1, -1, -1], [1, 0, 0, 2, 0, 1, 0, 2, 0, 2, 0],
                 [0, 2, 0, 2, 0, 1, 0, 2, 0, 2, 0], [0, 2, 0, 2, 0, 1, 0, 2, 0, 2, 0],
                 [0, 2, 0, 2, 0, 1, 0, 2, 0, 2, 0], [0, 2, 0, 2, 0, 1, 0, 2, 0, 0, 1],
                 [0, 1, 0, 1, 0, -1, -1, -1, -1, -1, -1]];
    ssc.data_set_matrix(data, b'Type_cpnt', Type_cpnt);
    ssc.data_set_number(data, b'custom_sf_pipe_sizes', 0)
    sf_rnr_diams = [[-1]];
    ssc.data_set_matrix(data, b'sf_rnr_diams', sf_rnr_diams);
    sf_rnr_wallthicks = [[-1]];
    ssc.data_set_matrix(data, b'sf_rnr_wallthicks', sf_rnr_wallthicks);
    sf_rnr_lengths = [[-1]];
    ssc.data_set_matrix(data, b'sf_rnr_lengths', sf_rnr_lengths);
    sf_hdr_diams = [[-1]];
    ssc.data_set_matrix(data, b'sf_hdr_diams', sf_hdr_diams);
    sf_hdr_wallthicks = [[-1]];
    ssc.data_set_matrix(data, b'sf_hdr_wallthicks', sf_hdr_wallthicks);
    sf_hdr_lengths = [[-1]];
    ssc.data_set_matrix(data, b'sf_hdr_lengths', sf_hdr_lengths);
    ssc.data_set_number(data, b'adjust:constant', 4)


    import TroughPhysicalProcessHeat
    a = TroughPhysicalProcessHeat.wrap(data)
    print(a.export())
    a.execute()


    module = ssc.module_create(b'trough_physical_process_heat')
    ssc.module_exec_set_print(0);
    if ssc.module_exec(module, data) == 0:
        print('trough_physical_process_heat simulation error')
        idx = 1
        msg = ssc.module_log(module, 0)
        while (msg != None):
            print('	: ' + msg.decode("utf - 8"))
            msg = ssc.module_log(module, idx)
            idx = idx + 1
        SystemExit("Simulation Error");
    ssc.module_free(module)
    annual_energy = ssc.data_get_number(data, b'annual_energy');
    print('Annual net energy (year 1) = ', annual_energy)
    annual_gross_energy = ssc.data_get_number(data, b'annual_gross_energy');
    print('Annual gross energy (year 1) = ', annual_gross_energy)
    annual_thermal_consumption = ssc.data_get_number(data, b'annual_thermal_consumption');
    print('Annual thermal freeze protection (year 1) = ', annual_thermal_consumption)
    annual_electricity_consumption = ssc.data_get_number(data, b'annual_electricity_consumption');
    print('Annual electricity load (year 1) = ', annual_electricity_consumption)
    ssc.data_free(data);

# trytrough()
# quit()

import GenericSystem
from pympler.tracker import SummaryTracker
import gc
from sscapi import PySSC

ssc = PySSC()

check_error_cases = True

n_tests_passed = 0
round = 0
while round < 1:

    if round == 0:
        tracker = SummaryTracker()

    print("\n===Starting Round", round, "===\n\n")
    round += 1

    a = GenericSystem.new()
    b = a.Plant


    # Test setting values with correct types

    a.Plant.derate = 1
    assert (a.Plant.derate == 1)
    assert (b.derate == 1)

    print("Passed test", 0)
    n_tests_passed += 1

    b.energy_output_array = (1, 2)
    assert(a.Plant.energy_output_array == (1, 2))
    assert (b.energy_output_array == (1, 2))
    print("Passed test", 1)
    n_tests_passed += 1

    # Test type checks with errors

    try:
        c = GenericSystem.new()
        c.Plant.energy_output_array = 1
        print("FAIL 2: exception is expected")
    except:
        print("Passed test", 2)
        n_tests_passed += 1


    try:
        c = GenericSystem.new()
        c.Plant.energy_output_array = (1, "2")
        print("FAIL 3: exception is expected")
    except:
        print("Passed test", 3)
        n_tests_passed += 1


    # Test assigning from dictionary

    PlantDict = {'derate': 10,
                      'energy_output_array': (10, 20)}

    b.assign(PlantDict)
    assert(b.derate == 10)
    assert(b.energy_output_array == (10, 20))
    print("Passed test", 4)
    n_tests_passed += 1


    PlantDict = {'derate': 1,
                      'energy_output_array': (2, 2)}
    a.Plant.assign(PlantDict)
    assert(a.Plant.derate == 1 and a.Plant.energy_output_array == (2, 2))
    print("Passed test", 5)
    n_tests_passed += 1

    PlantDict = {'derate': 10,
                      'energy_output_array': (10, 20)}

    try:
        c = GenericSystem.new()
        PlantDict['energy_output_array'] = ()
        c.Plant.assign(PlantDict)
        print("FAIL 1: exception is expected")
    except:
        print("Error caught", 1)
        n_tests_passed += 1

    try:
        c = GenericSystem.new()
        PlantDict['energy_output_array'] = ((12, 20), (1, 1))
        c.Plant.assign(PlantDict)
        print("FAIL 2: exception is expected")
    except:
        print("Error caught", 2)
        n_tests_passed += 1

    try:
        c = GenericSystem.new()
        PlantDict['derate'] = "derate"
        PlantDict['energy_output_array'] = (1, 2)
        c.Plant.assign(PlantDict)
        print("FAIL 3: exception is expected")
    except:
        print("Error caught", 3)
        n_tests_passed += 1


    # exporting to dictionary

    ValDict = b.export()
    assert(ValDict['derate'] == 1 and ValDict['energy_output_array'] == (2, 2))
    print("Passed test", 6)
    n_tests_passed += 1




    # Test shared module (AdjustmentFactors)
    d = a.AdjustmentFactors

    d.constant = 1
    assert(d.constant == 1)
    print("Passed test", 7)
    n_tests_passed += 1

    d.hourly = (1, 2)
    assert(d.hourly == (1, 2))
    print("Passed test", 8)
    n_tests_passed += 1

    d.periods = ((1, 2), (3, 4))
    assert(d.periods == ((1, 2), (3, 4)))
    print("Passed test", 9)
    n_tests_passed += 1

    try:
        d.periods = ((1, 2))
        print("FAIL 4: exception is expected")
    except:
        print("Error caught", 4)
        n_tests_passed += 1

    ValDict = d.export()
    assert(ValDict['constant'] == 1 and ValDict['hourly'] == (1, 2) and ValDict['periods'] == ((1, 2), (3, 4)))
    print("Passed test", 10)
    n_tests_passed += 1

    ValDict = {'constant': 10, "hourly": (10, 20), "periods": ((10, 20), (30, 40))}
    d.assign(ValDict)
    assert(ValDict['constant'] == 10 and ValDict['hourly'] == (10, 20) and ValDict['periods'] == ((10, 20), (30, 40)))
    print("Passed test", 11)
    n_tests_passed += 1


    # Test nested dictionary assignment and export

    TechDict = {'Plant': {'derate': 100,
                               'energy_output_array': (100, 200)},
                'AdjustmentFactors': {'constant': 100, "hourly": (100, 200), "periods": ((100, 200), (300, 400))}}
    a.assign(TechDict)
    ValDict = a.Plant.export()
    assert (ValDict['derate'] == 100 and ValDict['energy_output_array'] == (100, 200))
    print("Passed test", 12)
    n_tests_passed += 1

    ValDict = a.AdjustmentFactors.export()
    assert (ValDict['constant'] == 100 and ValDict['hourly'] == (100, 200) and ValDict['periods'] == (
    (100, 200), (300, 400)))
    print("Passed test", 13)
    n_tests_passed += 1


    # Test reading from PySSC

    data = ssc.data_create()
    ssc.data_set_number(data, b'derate', 1000)
    ssc.data_set_array(data, b'energy_output_array', [1000, 2000])
    a = GenericSystem.wrap(data)
    assert(a.Plant.derate == 1000)
    assert(a.Plant.energy_output_array == (1000, 2000))


    # Test strings and tables with error cases

    # a.Plant.file = "file"
    # assert(a.Plant.file == "file")
    # print("Passed test", 14)
    # n_tests_passed += 1
    #
    # assert(a.Plant.export()['file'] == 'file')
    # print("Passed test", 15)
    # n_tests_passed += 1
    #
    # c = GenericSystem.new()
    # dat = {'yo': 0}
    # datDict = {'num': 1, 'arr': (1, 2),  'str': 'str', 'mat': ((1, 2), (3, 4)), 'table': dat}
    # c.Plant.data = datDict
    # DataDict = c.Plant.data
    # assert(DataDict['num'] == 1 and DataDict['arr'] == (1, 2))
    # assert(DataDict['mat'] == ((1.0, 2.0), (3.0, 4.0)))
    # assert(DataDict['str'] == 'str')
    # assert(DataDict['table'] == dat)
    # print("Passed test", 16)
    # n_tests_passed += 1
    #
    # try:
    #     a.Plant.file = 100
    #     print("FAIL 5: exception is expected")
    # except:
    #     print("Error caught", 5)
    #     n_tests_passed += 1
    #
    # try:
    #     c.Plant.data = {'num': 1, 'arr': (1, "2"), 'mat': ((1, 2), (3, 4)), 'str': 'str', 'table': dat}
    #     print("FAIL 6: exception is expected")
    # except:
    #     print("Error caught", 6)
    #     n_tests_passed += 1
    #
    # try:
    #     c.Plant.data = {'num': 1, 'arr': (1, 2), 'mat': (("1",2 ), (3, 4)), 'str': 'str', 'table': dat}
    #     print("FAIL 7: exception is expected")
    # except:
    #     print("Error caught", 7)
    #     n_tests_passed += 1
    #
    # a.Plant.data = {'num': 1, 'arr': (1, 2), 'mat': ((1, 2), (3, 4)), 'str': 'str', 'table': {}}
    # assert(a.Plant.data['table'] == {})
    # print("Passed test", 17)
    # n_tests_passed += 1
    #
    #
    #
    # # Test conversion between technology attributes and nested dictionary
    #
    # genDict = a.export()
    # assert(genDict['Plant']['data']['str'] == 'str' and genDict['AdjustmentFactors'] == {} and genDict['Outputs'])
    # print("Passed test", 18)
    # n_tests_passed += 1
    #
    # a = GenericSystem.new()
    # assert(a.export()['Plant'] == {})
    # a.assign(genDict)
    # assert(a.export() == genDict)
    # print("Passed test", 19)
    # n_tests_passed += 1

    # Test loading from serialized dict
    a = GenericSystem.default("None")
    print(a.export())

    if round == 3:
        tracker.print_diff()


    # execution
    # a.execute(1)


tracker.print_diff()

# test importing of all modules
modules = ["Geothermal", "Pvsamv1", "TcsMSLF", "TcslinearFresnel", "TcstroughPhysical", "Biomass", "Hcpv",
           "Pvwattsv5", "Tcsdish", "TcsmoltenSalt", "GenericSystem", "LinearFresnelDsgIph", "Swh", "TcsgenericSolar",
           "TcstroughEmpirical", "Windpower", "TroughPhysicalProcessHeat"]

sf = "/Users/dguittet/SAM-Dev/sam/deploy/solar_resource/tucson_az_32.116521_-110.933042_psmv3_60_tmy.csv"
wf = "/Users/dguittet/SAM-Dev/sam/deploy/wind_resource/OH Northern-Lake.srw"
for mod in modules:
    import importlib
    print("Loaded module " + mod + "\n")
    i = importlib.import_module(mod)
    if mod == "TcsmoltenSalt":
        m = i.default("SingleOwner")
    else:
        m = i.default("None")
    print(m.export())
    if mod == "Pvsamv1":
        m.SolarResource.solar_resource_file = sf
    elif mod == "Biomass":
        m.Biopower.file_name = sf
    elif mod == "Hcpv":
        m.SolarResourceData.file_name = sf
    elif mod == "Pvwattsv5" or mod == "TcsmoltenSalt":
        m.LocationAndResource.solar_resource_file = sf
    elif mod == "Swh":
        m.Weather.solar_resource_file = sf
    elif mod == "Windpower":
        m.WindResourceFile.wind_resource_filename = wf
    elif mod == "GenericSystem":
        pass
    else:
        m.Weather.file_name = sf

    m.execute(0)
    print(m.Outputs.export())

