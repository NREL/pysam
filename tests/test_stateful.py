def stateful():
    import PySAM.BatteryStateful as bt

    b = bt.new()

    params = {"control_mode": 0, "input_current": 1, "chem": 1, "nominal_energy": 10, "nominal_voltage": 500,
              "initial_SOC": 50.000, "maximum_SOC": 95.000, "minimum_SOC": 5.000, "dt_hr": 1.000, "leadacid_tn": 0.000,
              "leadacid_qn": 0.000, "leadacid_q10": 0.000, "leadacid_q20": 0.000, "voltage_choice": 0,
              "Vnom_default": 3.600, "resistance": 0.0001, "Vfull": 4.100, "Vexp": 4.050, "Vnom": 3.400, "Qfull": 2.250,
              "Qexp": 0.040, "Qnom": 2.000, "C_rate": 0.200, "mass": 507.000, "surface_area": 2.018, "Cp": 1004.000,
              "h": 20.000, "cap_vs_temp": [[-10, 60], [0, 80], [25, 1E+2], [40, 1E+2]], "T_room_init": 20,
              "cycling_matrix": [[20, 0, 1E+2], [20, 5E+3, 80], [20, 1E+4, 60], [80, 0, 1E+2], [80, 1E+3, 80],
                                 [80, 2E+3, 60]], "calendar_choice": 1, "calendar_q0": 1.020, "calendar_a": 0.003,
              "calendar_b": -7280.000, "calendar_c": 930.000, "calendar_matrix": [[-3.1E+231]], "loss_choice": 0,
              "monthly_charge_loss": [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11],
              "monthly_discharge_loss": [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11],
              "monthly_idle_loss": [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11], "schedule_loss": [], "replacement_option": 0,
              "replacement_capacity": 0.000, "replacement_schedule": [], "replacement_schedule_percent": []}

    for k, v in params.items():
        b.value(k, v)

    b.setup()
    b.execute()
    print(b.StatePack.export())
    b.execute()
    print(b.StatePack.export())

    b.setup()
    b.execute()
    print(b.StatePack.export())
    b.execute()
    print(b.StatePack.export())
