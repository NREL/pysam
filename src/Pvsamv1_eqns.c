typedef struct {
    PyObject_HEAD
    PyObject            *x_attr;        /* Attributes dictionary */
    SAM_table   data_ptr;
} PVObject;

const char* const Reopt_size_battery_post_doc =
        "Given a PV system with Utilityrate5 parameters, get the optimal battery size. Wind and additional PV are disabled.\n"
        "Maps SAM compute module inputs to those of the ReOpt Lite API:\n"
        "Pvsamv1 model linked with StandAloneBattery, Utilityrate5, with Cashloan optional.\n\n"
        "For more information on which PySAM variables are used, see: https://github.com/NREL/ssc/blob/develop/ssc/cmod_pvsamv1_eqns.h\n\n"
        "For an example, see the 'Examples' readthedocs page.";



static PyObject* Reopt_size_battery_post(PyObject *self, PyObject *args, PyObject *keywds)
{

    CmodObject* self_obj = (CmodObject*)self;

    SAM_table data = self_obj->data_ptr;

    // get lat and lon
    double lat, lon;
    SAM_error error = new_error();
    SAM_table resource_data = SAM_table_get_table(data, "solar_resource_data", &error);

    if (!PySAM_has_error(error)){
        SAM_error error = new_error();
        lat = SAM_table_get_num(resource_data, "lat", &error);

        if (PySAM_has_error(error))
            return NULL;
        error = new_error();
        lon = SAM_table_get_num(resource_data, "lon", &error);
        if (PySAM_has_error(error))
            return NULL;
    }
    else{
        PyErr_Clear();
        SAM_error error = new_error();

        const char* resource_file = SAM_table_get_string(data, "solar_resource_file", &error);
        if (PySAM_has_error(error))
            return NULL;

        if (strlen(resource_file) == 0){
            PyErr_SetString(PySAM_ErrorObject, "Reopt_size_battery_pot error: solar_resource_file or solar_resource_data must be provided.");
            return NULL;
        }
        SAM_table ssc_data = SAM_table_construct(NULL);

        SAM_table_set_string(ssc_data, "file_name", resource_file, NULL);
        SAM_table_set_num(ssc_data, "header_only", 1, NULL);
        error = new_error();
        SAM_module_exec("wfreader", ssc_data, 0, &error);
        if (PySAM_has_error(error)){
            SAM_table_destruct(ssc_data, NULL);
            return NULL;
        }

        lat = SAM_table_get_num(ssc_data, "lat", NULL);
        lon = SAM_table_get_num(ssc_data, "lon", NULL);
        SAM_table_destruct(ssc_data, NULL);
    }

    SAM_table_set_num(data, "lat", lat, NULL);
    SAM_table_set_num(data, "lon", lon, NULL);

    // copy over losses
    error = new_error();
    SAM_module_exec("pvsamv1", data, 0, &error);
    if (PySAM_has_error(error))
        return NULL;
    error = new_error();
    double losses = SAM_table_get_num(data, "annual_total_loss_percent", &error);
    if (PySAM_has_error(error))
        return NULL;
    SAM_table_set_num(data, "losses", losses, NULL);

    PyObject* reopt_post_obj = NULL;
    error = new_error();
    SAM_Reopt_size_battery_post_eqn(data, &error);

    if (PySAM_has_error(error)){
        return NULL;
    }

    error = new_error();
    SAM_table reopt_post = SAM_table_get_table(data, "reopt_scenario", &error);
    if (PySAM_has_error(error))
        goto cleanup;

    error = new_error();
    const char* log_msg = SAM_table_get_string(data, "log", &error);
    if (PySAM_has_error(error))
        goto cleanup;

    SAM_table results = SAM_table_construct(NULL);
    SAM_table_set_table(results, "reopt_post", reopt_post, NULL);
    SAM_table_set_string(results, "messages", log_msg, NULL);
    reopt_post_obj = PySAM_table_to_dict(results);
    SAM_table_destruct(results, NULL);

    cleanup:
    SAM_table_unassign_entry(data, "reopt_scenario", NULL);
    SAM_table_unassign_entry(data, "log", NULL);
    return reopt_post_obj;
}
