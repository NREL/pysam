#include "SAM_eqns.h"

char Reopt_size_standalone_battery_post_doc[] =
        "Given a PV system with Utilityrate5 parameters, get the optimal battery size.\n"
        "Maps SAM compute module inputs to those of the ReOpt API:\n"
        "Pvsamv1 model linked with Battery, Utilityrate5, with Cashloan optional.\n\n"
        "For more information on which PySAM variables are used, see: https://github.com/NREL/ssc/blob/develop/ssc/cmod_battery_eqns.h\n\n"
        "For an example, see the 'Examples' readthedocs page.";

static PyObject* Reopt_size_standalone_battery_post(PyObject *self, PyObject *args, PyObject *keywds)
{

    CmodObject* self_obj = (CmodObject*)self;

    SAM_table data = self_obj->data_ptr;

    SAM_error error = new_error();

    PyObject* reopt_post_obj = NULL;
    error = new_error();
    SAM_Reopt_size_standalone_battery_post_eqn(data, &error);

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
