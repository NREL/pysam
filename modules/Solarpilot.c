#include <Python.h>

#include <SAM_Solarpilot.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * SolarPILOT Group
 */ 

static PyTypeObject SolarPILOT_Type;

static PyObject *
SolarPILOT_new(SAM_Solarpilot data_ptr)
{
	PyObject* new_obj = SolarPILOT_Type.tp_alloc(&SolarPILOT_Type,0);

	VarGroupObject* SolarPILOT_obj = (VarGroupObject*)new_obj;

	SolarPILOT_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SolarPILOT methods */

static PyObject *
SolarPILOT_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Solarpilot", "SolarPILOT")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SolarPILOT_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SolarPILOT_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Solarpilot", "SolarPILOT")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SolarPILOT_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SolarPILOT_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SolarPILOT_methods[] = {
		{"assign",            (PyCFunction)SolarPILOT_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SolarPILOT_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SolarPILOT_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SolarPILOT_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SolarPILOT_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SolarPILOT_get_c_atm_0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_c_atm_0_nget, self->data_ptr);
}

static int
SolarPILOT_set_c_atm_0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_c_atm_0_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_c_atm_1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_c_atm_1_nget, self->data_ptr);
}

static int
SolarPILOT_set_c_atm_1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_c_atm_1_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_c_atm_2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_c_atm_2_nget, self->data_ptr);
}

static int
SolarPILOT_set_c_atm_2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_c_atm_2_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_c_atm_3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_c_atm_3_nget, self->data_ptr);
}

static int
SolarPILOT_set_c_atm_3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_c_atm_3_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_calc_fluxmaps(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_calc_fluxmaps_nget, self->data_ptr);
}

static int
SolarPILOT_set_calc_fluxmaps(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_calc_fluxmaps_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_cant_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_cant_type_nget, self->data_ptr);
}

static int
SolarPILOT_set_cant_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_cant_type_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_cav_rec_height(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_cav_rec_height_nget, self->data_ptr);
}

static int
SolarPILOT_set_cav_rec_height(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_cav_rec_height_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_cav_rec_span(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_cav_rec_span_nget, self->data_ptr);
}

static int
SolarPILOT_set_cav_rec_span(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_cav_rec_span_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_cav_rec_width(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_cav_rec_width_nget, self->data_ptr);
}

static int
SolarPILOT_set_cav_rec_width(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_cav_rec_width_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_check_max_flux(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_check_max_flux_nget, self->data_ptr);
}

static int
SolarPILOT_set_check_max_flux(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_check_max_flux_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_contingency_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_contingency_rate_nget, self->data_ptr);
}

static int
SolarPILOT_set_contingency_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_contingency_rate_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_cost_sf_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_cost_sf_fixed_nget, self->data_ptr);
}

static int
SolarPILOT_set_cost_sf_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_cost_sf_fixed_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_csp_pt_sf_fixed_land_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_csp_pt_sf_fixed_land_area_nget, self->data_ptr);
}

static int
SolarPILOT_set_csp_pt_sf_fixed_land_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_csp_pt_sf_fixed_land_area_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_csp_pt_sf_land_overhead_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_csp_pt_sf_land_overhead_factor_nget, self->data_ptr);
}

static int
SolarPILOT_set_csp_pt_sf_land_overhead_factor(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_csp_pt_sf_land_overhead_factor_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_delta_flux_hrs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_delta_flux_hrs_nget, self->data_ptr);
}

static int
SolarPILOT_set_delta_flux_hrs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_delta_flux_hrs_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_dens_mirror(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_dens_mirror_nget, self->data_ptr);
}

static int
SolarPILOT_set_dens_mirror(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_dens_mirror_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_dni_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_dni_des_nget, self->data_ptr);
}

static int
SolarPILOT_set_dni_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_dni_des_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_flux_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_flux_max_nget, self->data_ptr);
}

static int
SolarPILOT_set_flux_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_flux_max_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_focus_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_focus_type_nget, self->data_ptr);
}

static int
SolarPILOT_set_focus_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_focus_type_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_h_tower(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_h_tower_nget, self->data_ptr);
}

static int
SolarPILOT_set_h_tower(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_h_tower_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_helio_active_fraction(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_helio_active_fraction_nget, self->data_ptr);
}

static int
SolarPILOT_set_helio_active_fraction(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_helio_active_fraction_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_helio_height(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_helio_height_nget, self->data_ptr);
}

static int
SolarPILOT_set_helio_height(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_helio_height_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_helio_optical_error(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_helio_optical_error_nget, self->data_ptr);
}

static int
SolarPILOT_set_helio_optical_error(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_helio_optical_error_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_helio_positions_in(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Solarpilot_SolarPILOT_helio_positions_in_mget, self->data_ptr);
}

static int
SolarPILOT_set_helio_positions_in(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Solarpilot_SolarPILOT_helio_positions_in_mset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_helio_reflectance(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_helio_reflectance_nget, self->data_ptr);
}

static int
SolarPILOT_set_helio_reflectance(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_helio_reflectance_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_helio_width(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_helio_width_nget, self->data_ptr);
}

static int
SolarPILOT_set_helio_width(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_helio_width_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_heliostat_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_heliostat_spec_cost_nget, self->data_ptr);
}

static int
SolarPILOT_set_heliostat_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_heliostat_spec_cost_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_is_optimize(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_is_optimize_nget, self->data_ptr);
}

static int
SolarPILOT_set_is_optimize(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_is_optimize_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_land_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_land_max_nget, self->data_ptr);
}

static int
SolarPILOT_set_land_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_land_max_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_land_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_land_min_nget, self->data_ptr);
}

static int
SolarPILOT_set_land_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_land_min_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_land_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_land_spec_cost_nget, self->data_ptr);
}

static int
SolarPILOT_set_land_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_land_spec_cost_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_n_cav_rec_panels(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_n_cav_rec_panels_nget, self->data_ptr);
}

static int
SolarPILOT_set_n_cav_rec_panels(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_n_cav_rec_panels_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_n_facet_x(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_n_facet_x_nget, self->data_ptr);
}

static int
SolarPILOT_set_n_facet_x(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_n_facet_x_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_n_facet_y(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_n_facet_y_nget, self->data_ptr);
}

static int
SolarPILOT_set_n_facet_y(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_n_facet_y_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_n_flux_days(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_n_flux_days_nget, self->data_ptr);
}

static int
SolarPILOT_set_n_flux_days(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_n_flux_days_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_n_flux_x(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_n_flux_x_nget, self->data_ptr);
}

static int
SolarPILOT_set_n_flux_x(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_n_flux_x_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_n_flux_y(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_n_flux_y_nget, self->data_ptr);
}

static int
SolarPILOT_set_n_flux_y(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_n_flux_y_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_opt_algorithm(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_opt_algorithm_nget, self->data_ptr);
}

static int
SolarPILOT_set_opt_algorithm(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_opt_algorithm_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_opt_conv_tol(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_opt_conv_tol_nget, self->data_ptr);
}

static int
SolarPILOT_set_opt_conv_tol(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_opt_conv_tol_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_opt_flux_penalty(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_opt_flux_penalty_nget, self->data_ptr);
}

static int
SolarPILOT_set_opt_flux_penalty(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_opt_flux_penalty_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_opt_init_step(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_opt_init_step_nget, self->data_ptr);
}

static int
SolarPILOT_set_opt_init_step(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_opt_init_step_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_opt_max_iter(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_opt_max_iter_nget, self->data_ptr);
}

static int
SolarPILOT_set_opt_max_iter(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_opt_max_iter_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_q_design(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_q_design_nget, self->data_ptr);
}

static int
SolarPILOT_set_q_design(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_q_design_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_rec_absorptance(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_rec_absorptance_nget, self->data_ptr);
}

static int
SolarPILOT_set_rec_absorptance(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_rec_absorptance_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_rec_aspect(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_rec_aspect_nget, self->data_ptr);
}

static int
SolarPILOT_set_rec_aspect(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_rec_aspect_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_rec_cost_exp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_rec_cost_exp_nget, self->data_ptr);
}

static int
SolarPILOT_set_rec_cost_exp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_rec_cost_exp_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_rec_height(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_rec_height_nget, self->data_ptr);
}

static int
SolarPILOT_set_rec_height(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_rec_height_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_rec_hl_perm2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_rec_hl_perm2_nget, self->data_ptr);
}

static int
SolarPILOT_set_rec_hl_perm2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_rec_hl_perm2_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_rec_ref_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_rec_ref_area_nget, self->data_ptr);
}

static int
SolarPILOT_set_rec_ref_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_rec_ref_area_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_rec_ref_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_rec_ref_cost_nget, self->data_ptr);
}

static int
SolarPILOT_set_rec_ref_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_rec_ref_cost_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_receiver_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_receiver_type_nget, self->data_ptr);
}

static int
SolarPILOT_set_receiver_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_receiver_type_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_sales_tax_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_sales_tax_frac_nget, self->data_ptr);
}

static int
SolarPILOT_set_sales_tax_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_sales_tax_frac_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_sales_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_sales_tax_rate_nget, self->data_ptr);
}

static int
SolarPILOT_set_sales_tax_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_sales_tax_rate_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_site_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_site_spec_cost_nget, self->data_ptr);
}

static int
SolarPILOT_set_site_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_site_spec_cost_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_solar_resource_file(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Solarpilot_SolarPILOT_solar_resource_file_sget, self->data_ptr);
}

static int
SolarPILOT_set_solar_resource_file(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Solarpilot_SolarPILOT_solar_resource_file_sset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_tower_exp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_tower_exp_nget, self->data_ptr);
}

static int
SolarPILOT_set_tower_exp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_tower_exp_nset, self->data_ptr);
}

static PyObject *
SolarPILOT_get_tower_fixed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_SolarPILOT_tower_fixed_cost_nget, self->data_ptr);
}

static int
SolarPILOT_set_tower_fixed_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Solarpilot_SolarPILOT_tower_fixed_cost_nset, self->data_ptr);
}

static PyGetSetDef SolarPILOT_getset[] = {
{"c_atm_0", (getter)SolarPILOT_get_c_atm_0,(setter)SolarPILOT_set_c_atm_0,
	PyDoc_STR("*float*: Attenuation coefficient 0\n\n**Required:**\nFalse. Automatically set to 0.006789 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"c_atm_1", (getter)SolarPILOT_get_c_atm_1,(setter)SolarPILOT_set_c_atm_1,
	PyDoc_STR("*float*: Attenuation coefficient 1\n\n**Required:**\nFalse. Automatically set to 0.1046 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"c_atm_2", (getter)SolarPILOT_get_c_atm_2,(setter)SolarPILOT_set_c_atm_2,
	PyDoc_STR("*float*: Attenuation coefficient 2\n\n**Required:**\nFalse. Automatically set to -0.0107 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"c_atm_3", (getter)SolarPILOT_get_c_atm_3,(setter)SolarPILOT_set_c_atm_3,
	PyDoc_STR("*float*: Attenuation coefficient 3\n\n**Required:**\nFalse. Automatically set to 0.002845 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"calc_fluxmaps", (getter)SolarPILOT_get_calc_fluxmaps,(setter)SolarPILOT_set_calc_fluxmaps,
	PyDoc_STR("*float*: Include fluxmap calculations\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cant_type", (getter)SolarPILOT_get_cant_type,(setter)SolarPILOT_set_cant_type,
	PyDoc_STR("*float*: Heliostat cant method\n\n**Required:**\nTrue"),
 	NULL},
{"cav_rec_height", (getter)SolarPILOT_get_cav_rec_height,(setter)SolarPILOT_set_cav_rec_height,
	PyDoc_STR("*float*: Cavity receiver height [m]\n\n**Required:**\nRequired if receiver_type=1"),
 	NULL},
{"cav_rec_span", (getter)SolarPILOT_get_cav_rec_span,(setter)SolarPILOT_set_cav_rec_span,
	PyDoc_STR("*float*: Cavity receiver span angle [deg]\n\n**Required:**\nRequired if receiver_type=1"),
 	NULL},
{"cav_rec_width", (getter)SolarPILOT_get_cav_rec_width,(setter)SolarPILOT_set_cav_rec_width,
	PyDoc_STR("*float*: Cavity receiver width [m]\n\n**Required:**\nRequired if receiver_type=1"),
 	NULL},
{"check_max_flux", (getter)SolarPILOT_get_check_max_flux,(setter)SolarPILOT_set_check_max_flux,
	PyDoc_STR("*float*: Check max flux at design point\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"contingency_rate", (getter)SolarPILOT_get_contingency_rate,(setter)SolarPILOT_set_contingency_rate,
	PyDoc_STR("*float*: Contingency for cost overrun [%]\n\n**Required:**\nTrue"),
 	NULL},
{"cost_sf_fixed", (getter)SolarPILOT_get_cost_sf_fixed,(setter)SolarPILOT_set_cost_sf_fixed,
	PyDoc_STR("*float*: Solar field fixed cost [$]\n\n**Required:**\nTrue"),
 	NULL},
{"csp_pt_sf_fixed_land_area", (getter)SolarPILOT_get_csp_pt_sf_fixed_land_area,(setter)SolarPILOT_set_csp_pt_sf_fixed_land_area,
	PyDoc_STR("*float*: Fixed land area [acre]\n\n**Required:**\nTrue"),
 	NULL},
{"csp_pt_sf_land_overhead_factor", (getter)SolarPILOT_get_csp_pt_sf_land_overhead_factor,(setter)SolarPILOT_set_csp_pt_sf_land_overhead_factor,
	PyDoc_STR("*float*: Land overhead factor\n\n**Required:**\nTrue"),
 	NULL},
{"delta_flux_hrs", (getter)SolarPILOT_get_delta_flux_hrs,(setter)SolarPILOT_set_delta_flux_hrs,
	PyDoc_STR("*float*: Hourly frequency in flux map lookup\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dens_mirror", (getter)SolarPILOT_get_dens_mirror,(setter)SolarPILOT_set_dens_mirror,
	PyDoc_STR("*float*: Ratio of reflective area to profile [frac]\n\n**Required:**\nTrue"),
 	NULL},
{"dni_des", (getter)SolarPILOT_get_dni_des,(setter)SolarPILOT_set_dni_des,
	PyDoc_STR("*float*: Design-point DNI [W/m2]\n\n**Required:**\nTrue"),
 	NULL},
{"flux_max", (getter)SolarPILOT_get_flux_max,(setter)SolarPILOT_set_flux_max,
	PyDoc_STR("*float*: Maximum allowable flux\n\n**Required:**\nFalse. Automatically set to 1000 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"focus_type", (getter)SolarPILOT_get_focus_type,(setter)SolarPILOT_set_focus_type,
	PyDoc_STR("*float*: Heliostat focus method\n\n**Required:**\nTrue"),
 	NULL},
{"h_tower", (getter)SolarPILOT_get_h_tower,(setter)SolarPILOT_set_h_tower,
	PyDoc_STR("*float*: Tower height [m]\n\n**Required:**\nTrue"),
 	NULL},
{"helio_active_fraction", (getter)SolarPILOT_get_helio_active_fraction,(setter)SolarPILOT_set_helio_active_fraction,
	PyDoc_STR("*float*: Active fraction of reflective area [frac]\n\n**Required:**\nTrue"),
 	NULL},
{"helio_height", (getter)SolarPILOT_get_helio_height,(setter)SolarPILOT_set_helio_height,
	PyDoc_STR("*float*: Heliostat height [m]\n\n**Required:**\nTrue"),
 	NULL},
{"helio_optical_error", (getter)SolarPILOT_get_helio_optical_error,(setter)SolarPILOT_set_helio_optical_error,
	PyDoc_STR("*float*: Optical error [rad]\n\n**Required:**\nTrue"),
 	NULL},
{"helio_positions_in", (getter)SolarPILOT_get_helio_positions_in,(setter)SolarPILOT_set_helio_positions_in,
	PyDoc_STR("*sequence[sequence]*: Heliostat position table"),
 	NULL},
{"helio_reflectance", (getter)SolarPILOT_get_helio_reflectance,(setter)SolarPILOT_set_helio_reflectance,
	PyDoc_STR("*float*: Mirror reflectance [frac]\n\n**Required:**\nTrue"),
 	NULL},
{"helio_width", (getter)SolarPILOT_get_helio_width,(setter)SolarPILOT_set_helio_width,
	PyDoc_STR("*float*: Heliostat width [m]\n\n**Required:**\nTrue"),
 	NULL},
{"heliostat_spec_cost", (getter)SolarPILOT_get_heliostat_spec_cost,(setter)SolarPILOT_set_heliostat_spec_cost,
	PyDoc_STR("*float*: Heliostat field cost [$/m2]\n\n**Required:**\nTrue"),
 	NULL},
{"is_optimize", (getter)SolarPILOT_get_is_optimize,(setter)SolarPILOT_set_is_optimize,
	PyDoc_STR("*float*: Do SolarPILOT optimization\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"land_max", (getter)SolarPILOT_get_land_max,(setter)SolarPILOT_set_land_max,
	PyDoc_STR("*float*: Max heliostat-dist-to-tower-height ratio\n\n**Required:**\nTrue"),
 	NULL},
{"land_min", (getter)SolarPILOT_get_land_min,(setter)SolarPILOT_set_land_min,
	PyDoc_STR("*float*: Min heliostat-dist-to-tower-height ratio\n\n**Required:**\nTrue"),
 	NULL},
{"land_spec_cost", (getter)SolarPILOT_get_land_spec_cost,(setter)SolarPILOT_set_land_spec_cost,
	PyDoc_STR("*float*: Total land area cost [$/acre]\n\n**Required:**\nTrue"),
 	NULL},
{"n_cav_rec_panels", (getter)SolarPILOT_get_n_cav_rec_panels,(setter)SolarPILOT_set_n_cav_rec_panels,
	PyDoc_STR("*float*: Cavity receiver number of panels\n\n**Required:**\nRequired if receiver_type=1"),
 	NULL},
{"n_facet_x", (getter)SolarPILOT_get_n_facet_x,(setter)SolarPILOT_set_n_facet_x,
	PyDoc_STR("*float*: Number of heliostat facets - X\n\n**Required:**\nTrue"),
 	NULL},
{"n_facet_y", (getter)SolarPILOT_get_n_facet_y,(setter)SolarPILOT_set_n_facet_y,
	PyDoc_STR("*float*: Number of heliostat facets - Y\n\n**Required:**\nTrue"),
 	NULL},
{"n_flux_days", (getter)SolarPILOT_get_n_flux_days,(setter)SolarPILOT_set_n_flux_days,
	PyDoc_STR("*float*: No. days in flux map lookup\n\n**Required:**\nFalse. Automatically set to 8 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"n_flux_x", (getter)SolarPILOT_get_n_flux_x,(setter)SolarPILOT_set_n_flux_x,
	PyDoc_STR("*float*: Flux map X resolution\n\n**Required:**\nFalse. Automatically set to 12 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"n_flux_y", (getter)SolarPILOT_get_n_flux_y,(setter)SolarPILOT_set_n_flux_y,
	PyDoc_STR("*float*: Flux map Y resolution\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"opt_algorithm", (getter)SolarPILOT_get_opt_algorithm,(setter)SolarPILOT_set_opt_algorithm,
	PyDoc_STR("*float*: Optimization algorithm\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"opt_conv_tol", (getter)SolarPILOT_get_opt_conv_tol,(setter)SolarPILOT_set_opt_conv_tol,
	PyDoc_STR("*float*: Optimization convergence tol\n\n**Required:**\nFalse. Automatically set to 0.001 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"opt_flux_penalty", (getter)SolarPILOT_get_opt_flux_penalty,(setter)SolarPILOT_set_opt_flux_penalty,
	PyDoc_STR("*float*: Optimization flux overage penalty\n\n**Required:**\nTrue"),
 	NULL},
{"opt_init_step", (getter)SolarPILOT_get_opt_init_step,(setter)SolarPILOT_set_opt_init_step,
	PyDoc_STR("*float*: Optimization initial step size\n\n**Required:**\nFalse. Automatically set to 0.05 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"opt_max_iter", (getter)SolarPILOT_get_opt_max_iter,(setter)SolarPILOT_set_opt_max_iter,
	PyDoc_STR("*float*: Max. number iteration steps\n\n**Required:**\nFalse. Automatically set to 200 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"q_design", (getter)SolarPILOT_get_q_design,(setter)SolarPILOT_set_q_design,
	PyDoc_STR("*float*: Receiver thermal design power [MW]\n\n**Required:**\nTrue"),
 	NULL},
{"rec_absorptance", (getter)SolarPILOT_get_rec_absorptance,(setter)SolarPILOT_set_rec_absorptance,
	PyDoc_STR("*float*: Absorptance [frac]\n\n**Required:**\nTrue"),
 	NULL},
{"rec_aspect", (getter)SolarPILOT_get_rec_aspect,(setter)SolarPILOT_set_rec_aspect,
	PyDoc_STR("*float*: External receiver aspect ratio (H/W) [frac]\n\n**Required:**\nRequired if receiver_type=0"),
 	NULL},
{"rec_cost_exp", (getter)SolarPILOT_get_rec_cost_exp,(setter)SolarPILOT_set_rec_cost_exp,
	PyDoc_STR("*float*: Receiver cost scaling exponent\n\n**Required:**\nTrue"),
 	NULL},
{"rec_height", (getter)SolarPILOT_get_rec_height,(setter)SolarPILOT_set_rec_height,
	PyDoc_STR("*float*: External receiver height [m]\n\n**Required:**\nRequired if receiver_type=0"),
 	NULL},
{"rec_hl_perm2", (getter)SolarPILOT_get_rec_hl_perm2,(setter)SolarPILOT_set_rec_hl_perm2,
	PyDoc_STR("*float*: Receiver design heat loss [kW/m2]\n\n**Required:**\nTrue"),
 	NULL},
{"rec_ref_area", (getter)SolarPILOT_get_rec_ref_area,(setter)SolarPILOT_set_rec_ref_area,
	PyDoc_STR("*float*: Receiver reference area for cost scale\n\n**Required:**\nTrue"),
 	NULL},
{"rec_ref_cost", (getter)SolarPILOT_get_rec_ref_cost,(setter)SolarPILOT_set_rec_ref_cost,
	PyDoc_STR("*float*: Receiver reference cost [$]\n\n**Required:**\nTrue"),
 	NULL},
{"receiver_type", (getter)SolarPILOT_get_receiver_type,(setter)SolarPILOT_set_receiver_type,
	PyDoc_STR("*float*: 0: external (default), 1; cavity\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"sales_tax_frac", (getter)SolarPILOT_get_sales_tax_frac,(setter)SolarPILOT_set_sales_tax_frac,
	PyDoc_STR("*float*: Percent of cost to which sales tax applies [%]\n\n**Required:**\nTrue"),
 	NULL},
{"sales_tax_rate", (getter)SolarPILOT_get_sales_tax_rate,(setter)SolarPILOT_set_sales_tax_rate,
	PyDoc_STR("*float*: Sales tax rate [%]\n\n**Required:**\nTrue"),
 	NULL},
{"site_spec_cost", (getter)SolarPILOT_get_site_spec_cost,(setter)SolarPILOT_set_site_spec_cost,
	PyDoc_STR("*float*: Site improvement cost [$/m2]\n\n**Required:**\nTrue"),
 	NULL},
{"solar_resource_file", (getter)SolarPILOT_get_solar_resource_file,(setter)SolarPILOT_set_solar_resource_file,
	PyDoc_STR("*str*: Solar weather data file\n\n**Constraints:**\nLOCAL_FILE\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"tower_exp", (getter)SolarPILOT_get_tower_exp,(setter)SolarPILOT_set_tower_exp,
	PyDoc_STR("*float*: Tower cost scaling exponent\n\n**Required:**\nTrue"),
 	NULL},
{"tower_fixed_cost", (getter)SolarPILOT_get_tower_fixed_cost,(setter)SolarPILOT_set_tower_fixed_cost,
	PyDoc_STR("*float*: Tower fixed cost [$]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SolarPILOT_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Solarpilot.SolarPILOT",             /*tp_name*/
		sizeof(VarGroupObject),          /*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		0,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		0,                          /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		0,                          /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		0,                          /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistofnset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		SolarPILOT_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SolarPILOT_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictofnset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


/*
 * Outputs Group
 */ 

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Solarpilot data_ptr)
{
	PyObject* new_obj = Outputs_Type.tp_alloc(&Outputs_Type,0);

	VarGroupObject* Outputs_obj = (VarGroupObject*)new_obj;

	Outputs_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Outputs methods */

static PyObject *
Outputs_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Solarpilot", "Outputs")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Outputs_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Outputs_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Solarpilot", "Outputs")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Outputs_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Outputs_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Outputs_methods[] = {
		{"assign",            (PyCFunction)Outputs_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Outputs_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Outputs_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Outputs_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Outputs_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Outputs_get_area_sf(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_Outputs_area_sf_nget, self->data_ptr);
}

static PyObject *
Outputs_get_base_land_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_Outputs_base_land_area_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cav_rec_aper_width_opt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_Outputs_cav_rec_aper_width_opt_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cost_land_tot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_Outputs_cost_land_tot_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cost_rec_tot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_Outputs_cost_rec_tot_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cost_sf_tot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_Outputs_cost_sf_tot_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cost_site_tot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_Outputs_cost_site_tot_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cost_tower_tot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_Outputs_cost_tower_tot_nget, self->data_ptr);
}

static PyObject *
Outputs_get_flux_max_observed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_Outputs_flux_max_observed_nget, self->data_ptr);
}

static PyObject *
Outputs_get_flux_table(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Solarpilot_Outputs_flux_table_mget, self->data_ptr);
}

static PyObject *
Outputs_get_h_tower_opt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_Outputs_h_tower_opt_nget, self->data_ptr);
}

static PyObject *
Outputs_get_heliostat_positions(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Solarpilot_Outputs_heliostat_positions_mget, self->data_ptr);
}

static PyObject *
Outputs_get_land_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_Outputs_land_area_nget, self->data_ptr);
}

static PyObject *
Outputs_get_number_heliostats(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_Outputs_number_heliostats_nget, self->data_ptr);
}

static PyObject *
Outputs_get_opteff_table(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Solarpilot_Outputs_opteff_table_mget, self->data_ptr);
}

static PyObject *
Outputs_get_rec_aspect_opt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_Outputs_rec_aspect_opt_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rec_height_opt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Solarpilot_Outputs_rec_height_opt_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"area_sf", (getter)Outputs_get_area_sf,(setter)0,
	PyDoc_STR("*float*: Total reflective heliostat area [m^2]"),
 	NULL},
{"base_land_area", (getter)Outputs_get_base_land_area,(setter)0,
	PyDoc_STR("*float*: Land area occupied by heliostats [acre]"),
 	NULL},
{"cav_rec_aper_width_opt", (getter)Outputs_get_cav_rec_aper_width_opt,(setter)0,
	PyDoc_STR("*float*: Optimized cavity receiver aperture width [-]"),
 	NULL},
{"cost_land_tot", (getter)Outputs_get_cost_land_tot,(setter)0,
	PyDoc_STR("*float*: Total land cost [$]"),
 	NULL},
{"cost_rec_tot", (getter)Outputs_get_cost_rec_tot,(setter)0,
	PyDoc_STR("*float*: Total receiver cost [$]"),
 	NULL},
{"cost_sf_tot", (getter)Outputs_get_cost_sf_tot,(setter)0,
	PyDoc_STR("*float*: Total heliostat field cost [$]"),
 	NULL},
{"cost_site_tot", (getter)Outputs_get_cost_site_tot,(setter)0,
	PyDoc_STR("*float*: Total site cost [$]"),
 	NULL},
{"cost_tower_tot", (getter)Outputs_get_cost_tower_tot,(setter)0,
	PyDoc_STR("*float*: Total tower cost [$]"),
 	NULL},
{"flux_max_observed", (getter)Outputs_get_flux_max_observed,(setter)0,
	PyDoc_STR("*float*: Maximum observed flux at design [kW/m2]"),
 	NULL},
{"flux_table", (getter)Outputs_get_flux_table,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Flux intensity table (flux(X) x (flux(y) x position) [frac]"),
 	NULL},
{"h_tower_opt", (getter)Outputs_get_h_tower_opt,(setter)0,
	PyDoc_STR("*float*: Optimized tower height [m]"),
 	NULL},
{"heliostat_positions", (getter)Outputs_get_heliostat_positions,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Heliostat positions (x,y) [m]"),
 	NULL},
{"land_area", (getter)Outputs_get_land_area,(setter)0,
	PyDoc_STR("*float*: Total land area [acre]"),
 	NULL},
{"number_heliostats", (getter)Outputs_get_number_heliostats,(setter)0,
	PyDoc_STR("*float*: Number of heliostats"),
 	NULL},
{"opteff_table", (getter)Outputs_get_opteff_table,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Optical efficiency (azi, zen, eff x nsim)"),
 	NULL},
{"rec_aspect_opt", (getter)Outputs_get_rec_aspect_opt,(setter)0,
	PyDoc_STR("*float*: Optimized receiver aspect ratio [-]"),
 	NULL},
{"rec_height_opt", (getter)Outputs_get_rec_height_opt,(setter)0,
	PyDoc_STR("*float*: Optimized receiver height [m]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Solarpilot.Outputs",             /*tp_name*/
		sizeof(VarGroupObject),          /*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		0,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		0,                          /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		0,                          /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		0,                          /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistofnset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Outputs_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Outputs_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictofnset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};

/*
 * Solarpilot
 */

static PyTypeObject Solarpilot_Type;

static CmodObject *
newSolarpilotObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Solarpilot_Type);

	PySAM_TECH_ATTR()

	PyObject* SolarPILOT_obj = SolarPILOT_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SolarPILOT", SolarPILOT_obj);
	Py_DECREF(SolarPILOT_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Solarpilot methods */

static void
Solarpilot_dealloc(CmodObject *self)
{
	Py_XDECREF(self->x_attr);

	if (!self->data_owner_ptr) {
		SAM_error error = new_error();
		SAM_table_destruct(self->data_ptr, &error);
		PySAM_has_error(error);
	}
	PyObject_Del(self);
}


static PyObject *
Solarpilot_get_data_ptr(CmodObject *self, PyObject *args)
{
	PyObject* ptr = PyLong_FromVoidPtr((void*)self->data_ptr);
	return ptr;
}


static PyObject *
Solarpilot_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Solarpilot_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Solarpilot_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Solarpilot"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Solarpilot_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Solarpilot"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Solarpilot_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Solarpilot_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Solarpilot_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Solarpilot_methods[] = {
		{"execute",           (PyCFunction)Solarpilot_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Solarpilot_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'SolarPILOT': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Solarpilot_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'SolarPILOT': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Solarpilot_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Solarpilot_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Solarpilot_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{"get_data_ptr",           (PyCFunction)Solarpilot_get_data_ptr,  METH_VARARGS,
				PyDoc_STR("get_data_ptr() -> Pointer\n Get ssc_data_t pointer")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Solarpilot_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Solarpilot_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Solarpilot_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Solarpilot",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Solarpilot_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Solarpilot_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Solarpilot_getattro, /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		"This class contains all the variable information for running a simulation. Variables are grouped together in the subclasses as properties. If property assignments are the wrong type, an error is thrown.",        /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistofnset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Solarpilot_methods,      /*tp_methods*/
		0,                          /*tp_members*/
		0,       /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictofnset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,                          /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};

/* --------------------------------------------------------------------- */


/* Function of no arguments returning new Solarpilot object */

static PyObject *
Solarpilot_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newSolarpilotObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Solarpilot_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSolarpilotObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Solarpilot_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSolarpilotObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Solarpilot", def) < 0) {
		Solarpilot_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Solarpilot_from_existing(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	PyObject * module = 0;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "O|s:from_existing", &module, &def)){
		PyErr_BadArgument();
		return NULL;
	}
	CmodObject *module_obj = (CmodObject *)module;
	SAM_table ptr = module_obj->data_ptr;

	// do a rough validity check on the data by checking its size
	SAM_error error = new_error();
	int data_size = SAM_table_size(ptr, &error);
	if (PySAM_has_error(error))
		goto fail;
	if (data_size < 0)
		goto fail;

	rv = newSolarpilotObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Solarpilot", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef SolarpilotModule_methods[] = {
		{"new",             Solarpilot_new,         METH_VARARGS,
				PyDoc_STR("new() -> Solarpilot")},
		{"default",             Solarpilot_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Solarpilot\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Solarpilot_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Solarpilot\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Solarpilot_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Solarpilot\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Solarpilot");


static int
SolarpilotModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Solarpilot_Type.tp_dict = PyDict_New();
	if (!Solarpilot_Type.tp_dict) { goto fail; }

	/// Add the SolarPILOT type object to Solarpilot_Type
	if (PyType_Ready(&SolarPILOT_Type) < 0) { goto fail; }
	PyDict_SetItemString(Solarpilot_Type.tp_dict,
				"SolarPILOT",
				(PyObject*)&SolarPILOT_Type);
	Py_DECREF(&SolarPILOT_Type);

	/// Add the Outputs type object to Solarpilot_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Solarpilot_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Solarpilot type object to the module
	if (PyType_Ready(&Solarpilot_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Solarpilot",
				(PyObject*)&Solarpilot_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot SolarpilotModule_slots[] = {
		{Py_mod_exec, SolarpilotModule_exec},
		{0, NULL},
};

static struct PyModuleDef SolarpilotModule = {
		PyModuleDef_HEAD_INIT,
		"Solarpilot",
		module_doc,
		0,
		SolarpilotModule_methods,
		SolarpilotModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Solarpilot(void)
{
	return PyModuleDef_Init(&SolarpilotModule);
}