typedef struct {
    PyObject_HEAD
    SAM_Windpower   data_ptr;
} WindGroupObject;

static PyObject* Turbine_calculate_powercurve(PyObject *self, PyObject *args, PyObject *keywds)
{
    double turbine_size;
    double elev;
    double max_tip_speed;
    double max_tip_sp_ratio;
    double cut_in;
    double cut_out;
    int drive_train;

    int model_choice;
    double rotor_diam, max_cp;

    static char *kwlist[] = {"turbine_size", "elevation", "max_tip_speed", "max_tip_sp_ratio",
                             "cut_in", "cut_out", "drive_train", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, keywds, "ddddddi", kwlist,
                                     &turbine_size, &elev, &max_tip_speed, &max_tip_sp_ratio,
                                     &cut_in, &cut_out, &drive_train))
        return NULL;


    WindGroupObject* self_obj = (WindGroupObject*)self;

    // elevation depends on model choice
    SAM_error error = new_error();
    model_choice = (int)SAM_Windpower_Resource_wind_resource_model_choice_nget(self_obj->data_ptr, &error);
    if (PySAM_has_error(error)){
        printf("Warning: Resource.wind_resource_model_choice not set. Elevation should be 0 if not using Weibull wind characteristics.\n");
    }
    if (model_choice != 0 && model_choice != 1 && model_choice != 2){
        PyErr_SetString(PySAM_ErrorObject, "Resource.wind_resource_model_choice must be 0 or 1");
        return NULL;
    }
    if (model_choice == 0 && elev != 0.){
        printf("elevation set to 0. Equations only correct for elevation if using Weibull wind characteristics.\n");
        elev = 0;
    }

    // rotor diameter and max_cp should be set already
    error = new_error();
    rotor_diam = SAM_Windpower_Turbine_wind_turbine_rotor_diameter_nget(self_obj->data_ptr, &error);
    if (PySAM_has_error(error)){
        PyErr_SetString(PySAM_ErrorObject, "Error: Turbine.wind_turbine_rotor_diameter not set.");
        return NULL;
    }

    error = new_error();
    max_cp = SAM_Windpower_Turbine_wind_turbine_max_cp_nget(self_obj->data_ptr, &error);
    if (PySAM_has_error(error)){
        PyErr_SetString(PySAM_ErrorObject, "Error: Turbine.wind_turbine_max_cp not set.");
        return NULL;
    }

    SAM_table data = SAM_table_construct(NULL);
    SAM_table_set_num(data, "turbine_size", turbine_size, NULL);
    SAM_table_set_num(data, "wind_turbine_rotor_diameter", rotor_diam, NULL);
    SAM_table_set_num(data, "elevation", elev, NULL);
    SAM_table_set_num(data, "wind_turbine_max_cp", max_cp, NULL);
    SAM_table_set_num(data, "max_tip_speed", max_tip_speed, NULL);
    SAM_table_set_num(data, "max_tip_sp_ratio", max_tip_sp_ratio, NULL);
    SAM_table_set_num(data, "cut_in", cut_in, NULL);
    SAM_table_set_num(data, "cut_out", cut_out, NULL);
    SAM_table_set_num(data, "drive_train", drive_train, NULL);

    error = new_error();
    SAM_windpower_turbine_powercurve_eqn(data, &error);

    if (PySAM_has_error(error)){
        return NULL;
    }

    int length;
    error = new_error();

    double* arr = SAM_table_get_array(data, "wind_turbine_powercurve_powerout", &length, &error);

    SAM_Windpower_Turbine_wind_turbine_powercurve_powerout_aset(self_obj->data_ptr, arr, length, &error);

    arr = SAM_table_get_array(data, "wind_turbine_powercurve_windspeeds", &length, &error);

    SAM_Windpower_Turbine_wind_turbine_powercurve_windspeeds_aset(self_obj->data_ptr, arr, length, &error);

    double rated_windspeed = *SAM_table_get_num(data, "rated_wind_speed", &error);

    if (PySAM_has_error(error)){
        return NULL;
    }

    SAM_table_destruct(data, NULL);

    return PyFloat_FromDouble(rated_windspeed);
}
