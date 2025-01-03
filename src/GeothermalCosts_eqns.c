#include "SAM_eqns.h"

char getem_om_cost_calc_doc[] =
    "Add documentation here \\n\\n"
    "Input: var_table with key-value pairs\\n"
    "     'baseline_cost': double [$] \\n"
    "     'drilling_cost': double [$] \\n"
    "     'field_gathering_system_cost': double [units] \\n"
    "     'num_wells': double [units] \\n"
    "     'water_loss': double [units] \\n"
    "     'total_installed_cost': double [$] \\n"
    "     'pump_cost_install': double [units] \\n"
    "     'pump_only_cost': double [units] \\n"
    "     'pump_type': double [units] \\n"
    "     'pump_depth': double \\n"
    "Output: key-value pairs added to var_table\\n"
    "     'total_getem_om_cost': double [$]";

static PyObject* getem_om_cost_calc(PyObject *self, PyObject *args, PyObject *keywds)
{
    double baseline_cost;
    double drilling_cost;
    double field_gathering_system_cost;
    double num_wells;
    double water_loss;
    double total_installed_cost;
    double pump_cost_install;
    double pump_only_cost;
    double pump_type;
    double pump_depth;

    static char *kwlist[] = {"baseline_cost", "drilling_cost", 
                             "field_gathering_system_cost", "num_wells", "water_loss", "total_installed_cost", 
                             "pump_cost_install", "pump_only_cost", "pump_type", "pump_depth", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, keywds, "dddddddddd", kwlist,
                                    &baseline_cost, &drilling_cost,
                                    &field_gathering_system_cost, &num_wells, &water_loss, &total_installed_cost, 
                                    &pump_cost_install, &pump_only_cost, &pump_type, &pump_depth))
        return NULL;

    // these variables are ones available as inputs to Geothermal_costs. So use those values directly 
    // instead of expecting user to provide them
    double gross_output;
    double conversion_type;
    double ppi_base_year;
    double cwflow;
    double GF_flowrate;

    VarGroupObject* self_obj = (VarGroupObject*)self;
    SAM_error error = new_error();
    gross_output = (int)SAM_GeothermalCosts_GeoHourly_gross_output_nget(self_obj->data_ptr, &error);
    if (PySAM_has_error(error)){
        return NULL;
    }
    error = new_error();
    conversion_type = (int)SAM_GeothermalCosts_GeoHourly_conversion_type_nget(self_obj->data_ptr, &error);
    if (PySAM_has_error(error)){
        return NULL;
    }
    error = new_error();
    ppi_base_year = (int)SAM_GeothermalCosts_GeoHourly_ppi_base_year_nget(self_obj->data_ptr, &error);
    if (PySAM_has_error(error)){
        return NULL;
    }
    error = new_error();
    cwflow = (int)SAM_GeothermalCosts_GeoHourly_cwflow_nget(self_obj->data_ptr, &error);
    if (PySAM_has_error(error)){
        return NULL;
    }
    error = new_error();
    GF_flowrate = (int)SAM_GeothermalCosts_GeoHourly_GF_flowrate_nget(self_obj->data_ptr, &error);
    if (PySAM_has_error(error)){
        return NULL;
    }

    SAM_table data = SAM_table_construct(NULL);
    SAM_table_set_num(data, "gross_output", gross_output, NULL);
    SAM_table_set_num(data, "conversion_type", conversion_type, NULL);
    SAM_table_set_num(data, "baseline_cost", baseline_cost, NULL);
    SAM_table_set_num(data, "ppi_base_year", ppi_base_year, NULL);
    SAM_table_set_num(data, "cwflow", cwflow, NULL);
    SAM_table_set_num(data, "drilling_cost", drilling_cost, NULL);
    SAM_table_set_num(data, "GF_flowrate", GF_flowrate, NULL);
    SAM_table_set_num(data, "field_gathering_system_cost", field_gathering_system_cost, NULL);
    SAM_table_set_num(data, "num_wells", num_wells, NULL);
    SAM_table_set_num(data, "water_loss", water_loss, NULL);
    SAM_table_set_num(data, "total_installed_cost", total_installed_cost, NULL);
    SAM_table_set_num(data, "pump_cost_install", pump_cost_install, NULL);
    SAM_table_set_num(data, "pump_only_cost", pump_only_cost, NULL);
    SAM_table_set_num(data, "pump_type", pump_type, NULL);
    SAM_table_set_num(data, "pump_depth", pump_depth, NULL);

    error = new_error();
    SAM_getem_om_cost_calc_eqn(data, &error);

    if (PySAM_has_error(error)){
        return NULL;
    }

    error = new_error();
    double total_getem_om_cost = SAM_table_get_num(data, "total_getem_om_cost", &error);

    if (PySAM_has_error(error)){
        return NULL;
    }

    SAM_table_destruct(data, NULL);

    return PyFloat_FromDouble(total_getem_om_cost);
}
