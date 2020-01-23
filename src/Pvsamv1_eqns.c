typedef struct {
    PyObject_HEAD
    PyObject            *x_attr;        /* Attributes dictionary */
    SAM_table   data_ptr;
} PVObject;

static PyObject* Reopt_size_battery_post(PyObject *self, PyObject *args, PyObject *keywds)
{

    PVObject* self_obj = (PVObject*)self;

    SAM_table data = self_obj->data_ptr;
    printf("0\n");

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
        printf("3: %d\n", SAM_table_size(data, NULL));
        SAM_error error = new_error();

        const char* resource_file = SAM_table_get_string(data, "solar_resource_file", &error);
        if (PySAM_has_error(error))
            return NULL;

        if (strlen(resource_file) == 0){
            PyErr_SetString(PySAM_ErrorObject, "Reopt_size_battery_pot error: solar_resource_file or solar_resource_data must be provided.");
            return NULL;
        }
        SAM_table ssc_data = SAM_table_construct(NULL);
        printf("4\n");

        SAM_table_set_string(ssc_data, "file_name", resource_file, NULL);
        SAM_table_set_num(ssc_data, "header_only", 1, NULL);
        error = new_error();
        printf("5.0\n");
        SAM_module_exec("wfreader", ssc_data, 0, &error);
        if (PySAM_has_error(error)){
            SAM_table_destruct(ssc_data, NULL);
            return NULL;
        }
        printf("5.1\n");

        lat = SAM_table_get_num(ssc_data, "lat", NULL);
        lon = SAM_table_get_num(ssc_data, "lon", NULL);
        SAM_table_destruct(ssc_data, NULL);
    }
    printf("5.2, %f, %f\n", lat, lon);

    SAM_table_set_num(data, "lat", lat, NULL);
    SAM_table_set_num(data, "lon", lon, NULL);

    // copy over losses
    double losses;
    error = new_error();
    printf("5.3\n");

    losses = SAM_table_get_num(data, "losses", &error);
    printf("6\n");

    // if 'losses' unassigned, see if the output 'annual_total_loss_percent' is assigned after simulating
    if (PySAM_has_error(error)){
        printf("7\n");

        error = new_error();
        SAM_module_exec("pvsamv1", data, 0, &error);
            printf("8\n");

        if (PySAM_has_error(error))
            return NULL;
        error = new_error();
        losses = SAM_table_get_num(data, "annual_total_loss_percent", &error);
    printf("9\n");

        if (PySAM_has_error(error))
            return NULL;
    }
    SAM_table_set_num(data, "losses", losses, NULL);


    PyObject* reopt_post_obj = NULL;
    error = new_error();
    SAM_Reopt_size_battery_post_eqn(data, &error);

    if (PySAM_has_error(error)){
        printf("6\n");
        return NULL;
    }

    error = new_error();
    SAM_table reopt_post = SAM_table_get_table(data, "reopt_scenario", &error);
    printf("7\n");
    if (PySAM_has_error(error)){
        printf("8\n");

        goto cleanup;
    }

    error = new_error();
    const char* log_msg = SAM_table_get_string(data, "log", &error);
    if (PySAM_has_error(error)){
        printf("9\n");

        goto cleanup;
    }

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
