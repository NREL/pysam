#include <Python.h>

#include <SAM_Geothermal.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * GeoHourly Group
 */ 

static PyTypeObject GeoHourly_Type;

static PyObject *
GeoHourly_new(SAM_Geothermal data_ptr)
{
	PyObject* new_obj = GeoHourly_Type.tp_alloc(&GeoHourly_Type,0);

	VarGroupObject* GeoHourly_obj = (VarGroupObject*)new_obj;

	GeoHourly_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* GeoHourly methods */

static PyObject *
GeoHourly_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Geothermal", "GeoHourly")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
GeoHourly_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &GeoHourly_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Geothermal", "GeoHourly")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
GeoHourly_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &GeoHourly_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef GeoHourly_methods[] = {
		{"assign",            (PyCFunction)GeoHourly_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``GeoHourly_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)GeoHourly_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``GeoHourly_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)GeoHourly_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
GeoHourly_get_CT(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_CT_nget, self->data_ptr);
}

static int
GeoHourly_set_CT(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_CT_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_HTF(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_HTF_nget, self->data_ptr);
}

static int
GeoHourly_set_HTF(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_HTF_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_P_boil(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_P_boil_nget, self->data_ptr);
}

static int
GeoHourly_set_P_boil(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_P_boil_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_P_cond_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_P_cond_min_nget, self->data_ptr);
}

static int
GeoHourly_set_P_cond_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_P_cond_min_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_P_cond_ratio(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_P_cond_ratio_nget, self->data_ptr);
}

static int
GeoHourly_set_P_cond_ratio(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_P_cond_ratio_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_T_ITD_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_T_ITD_des_nget, self->data_ptr);
}

static int
GeoHourly_set_T_ITD_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_T_ITD_des_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_T_amb_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_T_amb_des_nget, self->data_ptr);
}

static int
GeoHourly_set_T_amb_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_T_amb_des_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_T_approach(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_T_approach_nget, self->data_ptr);
}

static int
GeoHourly_set_T_approach(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_T_approach_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_T_htf_cold_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_T_htf_cold_ref_nget, self->data_ptr);
}

static int
GeoHourly_set_T_htf_cold_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_T_htf_cold_ref_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_T_htf_hot_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_T_htf_hot_ref_nget, self->data_ptr);
}

static int
GeoHourly_set_T_htf_hot_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_T_htf_hot_ref_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_ambient_pressure(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_ambient_pressure_nget, self->data_ptr);
}

static int
GeoHourly_set_ambient_pressure(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_ambient_pressure_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_analysis_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_analysis_type_nget, self->data_ptr);
}

static int
GeoHourly_set_analysis_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_analysis_type_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_casing_size(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_casing_size_nget, self->data_ptr);
}

static int
GeoHourly_set_casing_size(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_casing_size_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_conversion_subtype(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_conversion_subtype_nget, self->data_ptr);
}

static int
GeoHourly_set_conversion_subtype(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_conversion_subtype_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_conversion_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_conversion_type_nget, self->data_ptr);
}

static int
GeoHourly_set_conversion_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_conversion_type_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_dT_cw_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_dT_cw_ref_nget, self->data_ptr);
}

static int
GeoHourly_set_dT_cw_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_dT_cw_ref_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_decline_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_decline_type_nget, self->data_ptr);
}

static int
GeoHourly_set_decline_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_decline_type_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_delta_pressure_equip(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_delta_pressure_equip_nget, self->data_ptr);
}

static int
GeoHourly_set_delta_pressure_equip(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_delta_pressure_equip_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_design_temp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_design_temp_nget, self->data_ptr);
}

static int
GeoHourly_set_design_temp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_design_temp_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_dt_prod_well(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_dt_prod_well_nget, self->data_ptr);
}

static int
GeoHourly_set_dt_prod_well(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_dt_prod_well_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_eta_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_eta_ref_nget, self->data_ptr);
}

static int
GeoHourly_set_eta_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_eta_ref_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_excess_pressure_pump(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_excess_pressure_pump_nget, self->data_ptr);
}

static int
GeoHourly_set_excess_pressure_pump(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_excess_pressure_pump_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_file_name(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Geothermal_GeoHourly_file_name_sget, self->data_ptr);
}

static int
GeoHourly_set_file_name(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Geothermal_GeoHourly_file_name_sset, self->data_ptr);
}

static PyObject *
GeoHourly_get_fracture_angle(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_fracture_angle_nget, self->data_ptr);
}

static int
GeoHourly_set_fracture_angle(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_fracture_angle_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_fracture_aperature(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_fracture_aperature_nget, self->data_ptr);
}

static int
GeoHourly_set_fracture_aperature(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_fracture_aperature_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_fracture_length(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_fracture_length_nget, self->data_ptr);
}

static int
GeoHourly_set_fracture_length(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_fracture_length_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_fracture_spacing(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_fracture_spacing_nget, self->data_ptr);
}

static int
GeoHourly_set_fracture_spacing(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_fracture_spacing_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_fracture_width(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_fracture_width_nget, self->data_ptr);
}

static int
GeoHourly_set_fracture_width(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_fracture_width_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_geotherm_cost_inj_cost_curve_welltype(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_geotherm_cost_inj_cost_curve_welltype_nget, self->data_ptr);
}

static int
GeoHourly_set_geotherm_cost_inj_cost_curve_welltype(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_geotherm_cost_inj_cost_curve_welltype_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_geotherm_cost_inj_prod_well_ratio(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_geotherm_cost_inj_prod_well_ratio_nget, self->data_ptr);
}

static int
GeoHourly_set_geotherm_cost_inj_prod_well_ratio(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_geotherm_cost_inj_prod_well_ratio_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_geotherm_cost_prod_cost_curve_welltype(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_geotherm_cost_prod_cost_curve_welltype_nget, self->data_ptr);
}

static int
GeoHourly_set_geotherm_cost_prod_cost_curve_welltype(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_geotherm_cost_prod_cost_curve_welltype_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_geothermal_analysis_period(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_geothermal_analysis_period_nget, self->data_ptr);
}

static int
GeoHourly_set_geothermal_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_geothermal_analysis_period_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hc_ctl1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_hc_ctl1_nget, self->data_ptr);
}

static int
GeoHourly_set_hc_ctl1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_hc_ctl1_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hc_ctl2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_hc_ctl2_nget, self->data_ptr);
}

static int
GeoHourly_set_hc_ctl2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_hc_ctl2_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hc_ctl3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_hc_ctl3_nget, self->data_ptr);
}

static int
GeoHourly_set_hc_ctl3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_hc_ctl3_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hc_ctl4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_hc_ctl4_nget, self->data_ptr);
}

static int
GeoHourly_set_hc_ctl4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_hc_ctl4_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hc_ctl5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_hc_ctl5_nget, self->data_ptr);
}

static int
GeoHourly_set_hc_ctl5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_hc_ctl5_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hc_ctl6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_hc_ctl6_nget, self->data_ptr);
}

static int
GeoHourly_set_hc_ctl6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_hc_ctl6_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hc_ctl7(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_hc_ctl7_nget, self->data_ptr);
}

static int
GeoHourly_set_hc_ctl7(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_hc_ctl7_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hc_ctl8(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_hc_ctl8_nget, self->data_ptr);
}

static int
GeoHourly_set_hc_ctl8(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_hc_ctl8_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hc_ctl9(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_hc_ctl9_nget, self->data_ptr);
}

static int
GeoHourly_set_hc_ctl9(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_hc_ctl9_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hr_pl_nlev(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_hr_pl_nlev_nget, self->data_ptr);
}

static int
GeoHourly_set_hr_pl_nlev(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_hr_pl_nlev_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hybrid_dispatch_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Geothermal_GeoHourly_hybrid_dispatch_schedule_sget, self->data_ptr);
}

static int
GeoHourly_set_hybrid_dispatch_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Geothermal_GeoHourly_hybrid_dispatch_schedule_sset, self->data_ptr);
}

static PyObject *
GeoHourly_get_inj_casing_size(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_inj_casing_size_nget, self->data_ptr);
}

static int
GeoHourly_set_inj_casing_size(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_inj_casing_size_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_inj_prod_well_distance(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_inj_prod_well_distance_nget, self->data_ptr);
}

static int
GeoHourly_set_inj_prod_well_distance(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_inj_prod_well_distance_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_inj_well_diam(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_inj_well_diam_nget, self->data_ptr);
}

static int
GeoHourly_set_inj_well_diam(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_inj_well_diam_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_model_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_model_choice_nget, self->data_ptr);
}

static int
GeoHourly_set_model_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_model_choice_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_nameplate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_nameplate_nget, self->data_ptr);
}

static int
GeoHourly_set_nameplate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_nameplate_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_num_fractures(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_num_fractures_nget, self->data_ptr);
}

static int
GeoHourly_set_num_fractures(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_num_fractures_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_num_wells(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_num_wells_nget, self->data_ptr);
}

static int
GeoHourly_set_num_wells(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_num_wells_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_num_wells_getem(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_num_wells_getem_nget, self->data_ptr);
}

static int
GeoHourly_set_num_wells_getem(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_num_wells_getem_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_pb_bd_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_pb_bd_frac_nget, self->data_ptr);
}

static int
GeoHourly_set_pb_bd_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_pb_bd_frac_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_plant_efficiency_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_plant_efficiency_input_nget, self->data_ptr);
}

static int
GeoHourly_set_plant_efficiency_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_plant_efficiency_input_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_prod_well_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_prod_well_choice_nget, self->data_ptr);
}

static int
GeoHourly_set_prod_well_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_prod_well_choice_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_pump_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_pump_efficiency_nget, self->data_ptr);
}

static int
GeoHourly_set_pump_efficiency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_pump_efficiency_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_q_sby_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_q_sby_frac_nget, self->data_ptr);
}

static int
GeoHourly_set_q_sby_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_q_sby_frac_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_reservoir_height(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_reservoir_height_nget, self->data_ptr);
}

static int
GeoHourly_set_reservoir_height(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_reservoir_height_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_reservoir_model_inputs(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Geothermal_GeoHourly_reservoir_model_inputs_mget, self->data_ptr);
}

static int
GeoHourly_set_reservoir_model_inputs(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Geothermal_GeoHourly_reservoir_model_inputs_mset, self->data_ptr);
}

static PyObject *
GeoHourly_get_reservoir_permeability(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_reservoir_permeability_nget, self->data_ptr);
}

static int
GeoHourly_set_reservoir_permeability(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_reservoir_permeability_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_reservoir_pressure_change(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_reservoir_pressure_change_nget, self->data_ptr);
}

static int
GeoHourly_set_reservoir_pressure_change(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_reservoir_pressure_change_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_reservoir_pressure_change_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_reservoir_pressure_change_type_nget, self->data_ptr);
}

static int
GeoHourly_set_reservoir_pressure_change_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_reservoir_pressure_change_type_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_reservoir_width(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_reservoir_width_nget, self->data_ptr);
}

static int
GeoHourly_set_reservoir_width(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_reservoir_width_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_resource_depth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_resource_depth_nget, self->data_ptr);
}

static int
GeoHourly_set_resource_depth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_resource_depth_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_resource_potential(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_resource_potential_nget, self->data_ptr);
}

static int
GeoHourly_set_resource_potential(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_resource_potential_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_resource_temp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_resource_temp_nget, self->data_ptr);
}

static int
GeoHourly_set_resource_temp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_resource_temp_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_resource_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_resource_type_nget, self->data_ptr);
}

static int
GeoHourly_set_resource_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_resource_type_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_rock_density(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_rock_density_nget, self->data_ptr);
}

static int
GeoHourly_set_rock_density(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_rock_density_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_rock_specific_heat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_rock_specific_heat_nget, self->data_ptr);
}

static int
GeoHourly_set_rock_specific_heat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_rock_specific_heat_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_rock_thermal_conductivity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_rock_thermal_conductivity_nget, self->data_ptr);
}

static int
GeoHourly_set_rock_thermal_conductivity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_rock_thermal_conductivity_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_specified_pump_work_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_specified_pump_work_amount_nget, self->data_ptr);
}

static int
GeoHourly_set_specified_pump_work_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_specified_pump_work_amount_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_specify_pump_work(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_specify_pump_work_nget, self->data_ptr);
}

static int
GeoHourly_set_specify_pump_work(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_specify_pump_work_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_startup_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_startup_frac_nget, self->data_ptr);
}

static int
GeoHourly_set_startup_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_startup_frac_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_startup_time(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_startup_time_nget, self->data_ptr);
}

static int
GeoHourly_set_startup_time(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_startup_time_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_subsurface_water_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_subsurface_water_loss_nget, self->data_ptr);
}

static int
GeoHourly_set_subsurface_water_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_subsurface_water_loss_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_system_use_lifetime_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_system_use_lifetime_output_nget, self->data_ptr);
}

static int
GeoHourly_set_system_use_lifetime_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_system_use_lifetime_output_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_temp_decline_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_temp_decline_max_nget, self->data_ptr);
}

static int
GeoHourly_set_temp_decline_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_temp_decline_max_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_temp_decline_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_temp_decline_rate_nget, self->data_ptr);
}

static int
GeoHourly_set_temp_decline_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_temp_decline_rate_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_ui_calculations_only(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_ui_calculations_only_nget, self->data_ptr);
}

static int
GeoHourly_set_ui_calculations_only(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_ui_calculations_only_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_well_diameter(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_well_diameter_nget, self->data_ptr);
}

static int
GeoHourly_set_well_diameter(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_well_diameter_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_well_flow_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_well_flow_rate_nget, self->data_ptr);
}

static int
GeoHourly_set_well_flow_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_well_flow_rate_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_wet_bulb_temp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_GeoHourly_wet_bulb_temp_nget, self->data_ptr);
}

static int
GeoHourly_set_wet_bulb_temp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Geothermal_GeoHourly_wet_bulb_temp_nset, self->data_ptr);
}

static PyGetSetDef GeoHourly_getset[] = {
{"CT", (getter)GeoHourly_get_CT,(setter)GeoHourly_set_CT,
	PyDoc_STR("*float*: Condenser type (Wet, Dry,Hybrid) [(1-3)]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"HTF", (getter)GeoHourly_get_HTF,(setter)GeoHourly_set_HTF,
	PyDoc_STR("*float*: Heat trans fluid type ID [(1-27)]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"P_boil", (getter)GeoHourly_get_P_boil,(setter)GeoHourly_set_P_boil,
	PyDoc_STR("*float*: Design Boiler Pressure [bar]\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"P_cond_min", (getter)GeoHourly_get_P_cond_min,(setter)GeoHourly_set_P_cond_min,
	PyDoc_STR("*float*: Minimum condenser pressure [in Hg]\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"P_cond_ratio", (getter)GeoHourly_get_P_cond_ratio,(setter)GeoHourly_set_P_cond_ratio,
	PyDoc_STR("*float*: Condenser pressure ratio\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"T_ITD_des", (getter)GeoHourly_get_T_ITD_des,(setter)GeoHourly_set_T_ITD_des,
	PyDoc_STR("*float*: Design ITD for dry system [C]\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"T_amb_des", (getter)GeoHourly_get_T_amb_des,(setter)GeoHourly_set_T_amb_des,
	PyDoc_STR("*float*: Design ambient temperature [C]\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"T_approach", (getter)GeoHourly_get_T_approach,(setter)GeoHourly_set_T_approach,
	PyDoc_STR("*float*: Approach Temperature [C]\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"T_htf_cold_ref", (getter)GeoHourly_get_T_htf_cold_ref,(setter)GeoHourly_set_T_htf_cold_ref,
	PyDoc_STR("*float*: Outlet design temp [C]\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"T_htf_hot_ref", (getter)GeoHourly_get_T_htf_hot_ref,(setter)GeoHourly_set_T_htf_hot_ref,
	PyDoc_STR("*float*: Inlet design temp [C]\n\n**Required:**\nRequired if ui_calculations_only=0\n\nThe value of ``T_htf_hot_ref`` depends on the following variables:\n\n\t - design_temp\n\t - resource_temp\n\t - resource_type\n"),
 	NULL},
{"ambient_pressure", (getter)GeoHourly_get_ambient_pressure,(setter)GeoHourly_set_ambient_pressure,
	PyDoc_STR("*float*: Ambient pressure [psi]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``ambient_pressure``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"analysis_type", (getter)GeoHourly_get_analysis_type,(setter)GeoHourly_set_analysis_type,
	PyDoc_STR("*float*: Analysis Type\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``analysis_type``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"casing_size", (getter)GeoHourly_get_casing_size,(setter)GeoHourly_set_casing_size,
	PyDoc_STR("*float*: Production pump casing size [in]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``casing_size``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"conversion_subtype", (getter)GeoHourly_get_conversion_subtype,(setter)GeoHourly_set_conversion_subtype,
	PyDoc_STR("*float*: Conversion Subtype\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``conversion_subtype``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"conversion_type", (getter)GeoHourly_get_conversion_type,(setter)GeoHourly_set_conversion_type,
	PyDoc_STR("*float*: Conversion Type\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``conversion_type``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"dT_cw_ref", (getter)GeoHourly_get_dT_cw_ref,(setter)GeoHourly_set_dT_cw_ref,
	PyDoc_STR("*float*: Design condenser cooling water inlet/outlet T diff [C]\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"decline_type", (getter)GeoHourly_get_decline_type,(setter)GeoHourly_set_decline_type,
	PyDoc_STR("*float*: Temp decline Type\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``decline_type``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"delta_pressure_equip", (getter)GeoHourly_get_delta_pressure_equip,(setter)GeoHourly_set_delta_pressure_equip,
	PyDoc_STR("*float*: Delta pressure across surface equipment [psi]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``delta_pressure_equip``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"design_temp", (getter)GeoHourly_get_design_temp,(setter)GeoHourly_set_design_temp,
	PyDoc_STR("*float*: Power block design temperature [C]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``design_temp``:\n\n\t - T_htf_hot_ref\n\t - num_wells_getem\n\n\nThe value of ``design_temp`` depends on the following variables:\n\n\t - resource_temp\n\t - resource_type\n"),
 	NULL},
{"dt_prod_well", (getter)GeoHourly_get_dt_prod_well,(setter)GeoHourly_set_dt_prod_well,
	PyDoc_STR("*float*: Temperature loss in production well [C]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``dt_prod_well``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"eta_ref", (getter)GeoHourly_get_eta_ref,(setter)GeoHourly_set_eta_ref,
	PyDoc_STR("*float*: Desgin conversion efficiency [%]\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"excess_pressure_pump", (getter)GeoHourly_get_excess_pressure_pump,(setter)GeoHourly_set_excess_pressure_pump,
	PyDoc_STR("*float*: Excess pressure @ pump suction [psi]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``excess_pressure_pump``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"file_name", (getter)GeoHourly_get_file_name,(setter)GeoHourly_set_file_name,
	PyDoc_STR("*str*: local weather file path\n\n**Constraints:**\nLOCAL_FILE\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"fracture_angle", (getter)GeoHourly_get_fracture_angle,(setter)GeoHourly_set_fracture_angle,
	PyDoc_STR("*float*: Fracture angle [deg]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``fracture_angle``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"fracture_aperature", (getter)GeoHourly_get_fracture_aperature,(setter)GeoHourly_set_fracture_aperature,
	PyDoc_STR("*float*: Fracture aperature [m]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``fracture_aperature``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"fracture_length", (getter)GeoHourly_get_fracture_length,(setter)GeoHourly_set_fracture_length,
	PyDoc_STR("*float*: Fracture length [m]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``fracture_length``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"fracture_spacing", (getter)GeoHourly_get_fracture_spacing,(setter)GeoHourly_set_fracture_spacing,
	PyDoc_STR("*float*: Fracture spacing [m]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``fracture_spacing``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"fracture_width", (getter)GeoHourly_get_fracture_width,(setter)GeoHourly_set_fracture_width,
	PyDoc_STR("*float*: Fracture width [m]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``fracture_width``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"geotherm_cost_inj_cost_curve_welltype", (getter)GeoHourly_get_geotherm_cost_inj_cost_curve_welltype,(setter)GeoHourly_set_geotherm_cost_inj_cost_curve_welltype,
	PyDoc_STR("*float*: Injection well type [0/1]\n\n**Required:**\nTrue"),
 	NULL},
{"geotherm_cost_inj_prod_well_ratio", (getter)GeoHourly_get_geotherm_cost_inj_prod_well_ratio,(setter)GeoHourly_set_geotherm_cost_inj_prod_well_ratio,
	PyDoc_STR("*float*: Ratio of injection wells to production wells"),
 	NULL},
{"geotherm_cost_prod_cost_curve_welltype", (getter)GeoHourly_get_geotherm_cost_prod_cost_curve_welltype,(setter)GeoHourly_set_geotherm_cost_prod_cost_curve_welltype,
	PyDoc_STR("*float*: Production well type [0/1]\n\n**Required:**\nTrue"),
 	NULL},
{"geothermal_analysis_period", (getter)GeoHourly_get_geothermal_analysis_period,(setter)GeoHourly_set_geothermal_analysis_period,
	PyDoc_STR("*float*: Analysis Lifetime [years]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``geothermal_analysis_period``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"hc_ctl1", (getter)GeoHourly_get_hc_ctl1,(setter)GeoHourly_set_hc_ctl1,
	PyDoc_STR("*float*: HC Control 1\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"hc_ctl2", (getter)GeoHourly_get_hc_ctl2,(setter)GeoHourly_set_hc_ctl2,
	PyDoc_STR("*float*: HC Control 2\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"hc_ctl3", (getter)GeoHourly_get_hc_ctl3,(setter)GeoHourly_set_hc_ctl3,
	PyDoc_STR("*float*: HC Control 3\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"hc_ctl4", (getter)GeoHourly_get_hc_ctl4,(setter)GeoHourly_set_hc_ctl4,
	PyDoc_STR("*float*: HC Control 4\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"hc_ctl5", (getter)GeoHourly_get_hc_ctl5,(setter)GeoHourly_set_hc_ctl5,
	PyDoc_STR("*float*: HC Control 5\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"hc_ctl6", (getter)GeoHourly_get_hc_ctl6,(setter)GeoHourly_set_hc_ctl6,
	PyDoc_STR("*float*: HC Control 6\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"hc_ctl7", (getter)GeoHourly_get_hc_ctl7,(setter)GeoHourly_set_hc_ctl7,
	PyDoc_STR("*float*: HC Control 7\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"hc_ctl8", (getter)GeoHourly_get_hc_ctl8,(setter)GeoHourly_set_hc_ctl8,
	PyDoc_STR("*float*: HC Control 8\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"hc_ctl9", (getter)GeoHourly_get_hc_ctl9,(setter)GeoHourly_set_hc_ctl9,
	PyDoc_STR("*float*: HC Control 9\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"hr_pl_nlev", (getter)GeoHourly_get_hr_pl_nlev,(setter)GeoHourly_set_hr_pl_nlev,
	PyDoc_STR("*float*: # part-load increments [(0-9)]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nRequired if ui_calculations_only=0\n\nThe value of the following variables depends on ``hr_pl_nlev``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"hybrid_dispatch_schedule", (getter)GeoHourly_get_hybrid_dispatch_schedule,(setter)GeoHourly_set_hybrid_dispatch_schedule,
	PyDoc_STR("*str*: Daily dispatch schedule\n\n**Constraints:**\nTOUSCHED\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"inj_casing_size", (getter)GeoHourly_get_inj_casing_size,(setter)GeoHourly_set_inj_casing_size,
	PyDoc_STR("*float*: Injection pump casing size [in]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``inj_casing_size``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"inj_prod_well_distance", (getter)GeoHourly_get_inj_prod_well_distance,(setter)GeoHourly_set_inj_prod_well_distance,
	PyDoc_STR("*float*: Distance from injection to production wells [m]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``inj_prod_well_distance``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"inj_well_diam", (getter)GeoHourly_get_inj_well_diam,(setter)GeoHourly_set_inj_well_diam,
	PyDoc_STR("*float*: Injection well diameter [in]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``inj_well_diam``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"model_choice", (getter)GeoHourly_get_model_choice,(setter)GeoHourly_set_model_choice,
	PyDoc_STR("*float*: Which model to run (0,1,2)\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``model_choice``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"nameplate", (getter)GeoHourly_get_nameplate,(setter)GeoHourly_set_nameplate,
	PyDoc_STR("*float*: Desired plant output [kW]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``nameplate``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"num_fractures", (getter)GeoHourly_get_num_fractures,(setter)GeoHourly_set_num_fractures,
	PyDoc_STR("*float*: Number of fractures\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``num_fractures``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"num_wells", (getter)GeoHourly_get_num_wells,(setter)GeoHourly_set_num_wells,
	PyDoc_STR("*float*: Number of Wells\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``num_wells``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"num_wells_getem", (getter)GeoHourly_get_num_wells_getem,(setter)GeoHourly_set_num_wells_getem,
	PyDoc_STR("*float*: Number of Wells GETEM calc'd\n\n**Required:**\nRequired if ui_calculations_only=0\n\nThe value of ``num_wells_getem`` depends on the following variables:\n\n\t - ambient_pressure\n\t - analysis_type\n\t - casing_size\n\t - conversion_subtype\n\t - conversion_type\n\t - decline_type\n\t - delta_pressure_equip\n\t - design_temp\n\t - dt_prod_well\n\t - excess_pressure_pump\n\t - fracture_angle\n\t - fracture_aperature\n\t - fracture_length\n\t - fracture_spacing\n\t - fracture_width\n\t - geothermal_analysis_period\n\t - hr_pl_nlev\n\t - inj_casing_size\n\t - inj_prod_well_distance\n\t - inj_well_diam\n\t - model_choice\n\t - nameplate\n\t - num_fractures\n\t - num_wells\n\t - plant_efficiency_input\n\t - prod_well_choice\n\t - pump_efficiency\n\t - reservoir_height\n\t - reservoir_model_inputs\n\t - reservoir_permeability\n\t - reservoir_pressure_change\n\t - reservoir_pressure_change_type\n\t - reservoir_width\n\t - resource_depth\n\t - resource_temp\n\t - resource_type\n\t - rock_density\n\t - rock_specific_heat\n\t - rock_thermal_conductivity\n\t - specified_pump_work_amount\n\t - specify_pump_work\n\t - subsurface_water_loss\n\t - temp_decline_max\n\t - temp_decline_rate\n\t - well_diameter\n\t - well_flow_rate\n\t - wet_bulb_temp\n"),
 	NULL},
{"pb_bd_frac", (getter)GeoHourly_get_pb_bd_frac,(setter)GeoHourly_set_pb_bd_frac,
	PyDoc_STR("*float*: Blowdown steam fraction [%]\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"plant_efficiency_input", (getter)GeoHourly_get_plant_efficiency_input,(setter)GeoHourly_set_plant_efficiency_input,
	PyDoc_STR("*float*: Plant efficiency\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``plant_efficiency_input``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"prod_well_choice", (getter)GeoHourly_get_prod_well_choice,(setter)GeoHourly_set_prod_well_choice,
	PyDoc_STR("*float*: Temperature loss in production well choice [0/1]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``prod_well_choice``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"pump_efficiency", (getter)GeoHourly_get_pump_efficiency,(setter)GeoHourly_set_pump_efficiency,
	PyDoc_STR("*float*: Pump efficiency [%]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``pump_efficiency``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"q_sby_frac", (getter)GeoHourly_get_q_sby_frac,(setter)GeoHourly_set_q_sby_frac,
	PyDoc_STR("*float*: % thermal power for standby mode [%]\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"reservoir_height", (getter)GeoHourly_get_reservoir_height,(setter)GeoHourly_set_reservoir_height,
	PyDoc_STR("*float*: Reservoir height [m]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``reservoir_height``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"reservoir_model_inputs", (getter)GeoHourly_get_reservoir_model_inputs,(setter)GeoHourly_set_reservoir_model_inputs,
	PyDoc_STR("*sequence[sequence]*: Reservoir temperatures over time\n\n**Required:**\nRequired if reservoir_pressure_change_type=3\n\nThe value of the following variables depends on ``reservoir_model_inputs``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"reservoir_permeability", (getter)GeoHourly_get_reservoir_permeability,(setter)GeoHourly_set_reservoir_permeability,
	PyDoc_STR("*float*: Reservoir Permeability [darcys]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``reservoir_permeability``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"reservoir_pressure_change", (getter)GeoHourly_get_reservoir_pressure_change,(setter)GeoHourly_set_reservoir_pressure_change,
	PyDoc_STR("*float*: Pressure change [psi-h/1000lb]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``reservoir_pressure_change``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"reservoir_pressure_change_type", (getter)GeoHourly_get_reservoir_pressure_change_type,(setter)GeoHourly_set_reservoir_pressure_change_type,
	PyDoc_STR("*float*: Reservoir pressure change type\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``reservoir_pressure_change_type``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"reservoir_width", (getter)GeoHourly_get_reservoir_width,(setter)GeoHourly_set_reservoir_width,
	PyDoc_STR("*float*: Reservoir width [m]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``reservoir_width``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"resource_depth", (getter)GeoHourly_get_resource_depth,(setter)GeoHourly_set_resource_depth,
	PyDoc_STR("*float*: Resource Depth [m]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``resource_depth``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"resource_potential", (getter)GeoHourly_get_resource_potential,(setter)GeoHourly_set_resource_potential,
	PyDoc_STR("*float*: Resource Potential [MW]\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"resource_temp", (getter)GeoHourly_get_resource_temp,(setter)GeoHourly_set_resource_temp,
	PyDoc_STR("*float*: Resource Temperature [C]\n\n**Constraints:**\nMAX=373\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``resource_temp``:\n\n\t - T_htf_hot_ref\n\t - design_temp\n\t - num_wells_getem\n"),
 	NULL},
{"resource_type", (getter)GeoHourly_get_resource_type,(setter)GeoHourly_set_resource_type,
	PyDoc_STR("*float*: Type of Resource\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``resource_type``:\n\n\t - T_htf_hot_ref\n\t - design_temp\n\t - num_wells_getem\n"),
 	NULL},
{"rock_density", (getter)GeoHourly_get_rock_density,(setter)GeoHourly_set_rock_density,
	PyDoc_STR("*float*: Rock density [kg/m^3]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``rock_density``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"rock_specific_heat", (getter)GeoHourly_get_rock_specific_heat,(setter)GeoHourly_set_rock_specific_heat,
	PyDoc_STR("*float*: Rock specific heat [J/kg-C]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``rock_specific_heat``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"rock_thermal_conductivity", (getter)GeoHourly_get_rock_thermal_conductivity,(setter)GeoHourly_set_rock_thermal_conductivity,
	PyDoc_STR("*float*: Rock thermal conductivity [J/m-day-C]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``rock_thermal_conductivity``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"specified_pump_work_amount", (getter)GeoHourly_get_specified_pump_work_amount,(setter)GeoHourly_set_specified_pump_work_amount,
	PyDoc_STR("*float*: Pump work specified by user [MW]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``specified_pump_work_amount``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"specify_pump_work", (getter)GeoHourly_get_specify_pump_work,(setter)GeoHourly_set_specify_pump_work,
	PyDoc_STR("*float*: Did user specify pump work? [0 or 1]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``specify_pump_work``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"startup_frac", (getter)GeoHourly_get_startup_frac,(setter)GeoHourly_set_startup_frac,
	PyDoc_STR("*float*: % thermal power for startup [%]\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"startup_time", (getter)GeoHourly_get_startup_time,(setter)GeoHourly_set_startup_time,
	PyDoc_STR("*float*: Hours to start power block [hours]\n\n**Required:**\nRequired if ui_calculations_only=0"),
 	NULL},
{"subsurface_water_loss", (getter)GeoHourly_get_subsurface_water_loss,(setter)GeoHourly_set_subsurface_water_loss,
	PyDoc_STR("*float*: Subsurface water loss [%]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``subsurface_water_loss``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"system_use_lifetime_output", (getter)GeoHourly_get_system_use_lifetime_output,(setter)GeoHourly_set_system_use_lifetime_output,
	PyDoc_STR("*float*: Geothermal lifetime simulation [0/1]\n\n**Options:**\n0=SingleYearRepeated,1=RunEveryYear\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"temp_decline_max", (getter)GeoHourly_get_temp_decline_max,(setter)GeoHourly_set_temp_decline_max,
	PyDoc_STR("*float*: Maximum temperature decline [C]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``temp_decline_max``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"temp_decline_rate", (getter)GeoHourly_get_temp_decline_rate,(setter)GeoHourly_set_temp_decline_rate,
	PyDoc_STR("*float*: Temperature decline rate [%/yr]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``temp_decline_rate``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"ui_calculations_only", (getter)GeoHourly_get_ui_calculations_only,(setter)GeoHourly_set_ui_calculations_only,
	PyDoc_STR("*float*: If = 1, only run UI calculations\n\n**Required:**\nTrue"),
 	NULL},
{"well_diameter", (getter)GeoHourly_get_well_diameter,(setter)GeoHourly_set_well_diameter,
	PyDoc_STR("*float*: Production well diameter [in]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``well_diameter``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"well_flow_rate", (getter)GeoHourly_get_well_flow_rate,(setter)GeoHourly_set_well_flow_rate,
	PyDoc_STR("*float*: Production flow rate per well [kg/s]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``well_flow_rate``:\n\n\t - num_wells_getem\n"),
 	NULL},
{"wet_bulb_temp", (getter)GeoHourly_get_wet_bulb_temp,(setter)GeoHourly_set_wet_bulb_temp,
	PyDoc_STR("*float*: Wet Bulb Temperature [C]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``wet_bulb_temp``:\n\n\t - num_wells_getem\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject GeoHourly_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Geothermal.GeoHourly",             /*tp_name*/
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
		GeoHourly_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		GeoHourly_getset,          /*tp_getset*/
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
Outputs_new(SAM_Geothermal data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Geothermal", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Geothermal", "Outputs")){
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
Outputs_get_GF_flowrate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_GF_flowrate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution_time(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Geothermal_Outputs_annual_energy_distribution_time_mget, self->data_ptr);
}

static PyObject *
Outputs_get_bottom_hole_pressure(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_bottom_hole_pressure_nget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_condensate_pump_power(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_condensate_pump_power_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cw_pump_head(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_cw_pump_head_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cw_pump_work(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_cw_pump_work_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cwflow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_cwflow_nget, self->data_ptr);
}

static PyObject *
Outputs_get_eff_secondlaw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_eff_secondlaw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_first_year_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_first_year_output_nget, self->data_ptr);
}

static PyObject *
Outputs_get_flash_count(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_flash_count_nget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gross_cost_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_gross_cost_output_nget, self->data_ptr);
}

static PyObject *
Outputs_get_gross_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_gross_output_nget, self->data_ptr);
}

static PyObject *
Outputs_get_hp_flash_pressure(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_hp_flash_pressure_nget, self->data_ptr);
}

static PyObject *
Outputs_get_inj_pump_hp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_inj_pump_hp_nget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_kwh_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lifetime_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_lifetime_output_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lp_flash_pressure(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_lp_flash_pressure_nget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_power(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_monthly_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_resource_temperature(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_monthly_resource_temperature_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ncg_condensate_pump(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_ncg_condensate_pump_nget, self->data_ptr);
}

static PyObject *
Outputs_get_num_wells_getem_inj(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_num_wells_getem_inj_nget, self->data_ptr);
}

static PyObject *
Outputs_get_num_wells_getem_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_num_wells_getem_output_nget, self->data_ptr);
}

static PyObject *
Outputs_get_plant_brine_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_plant_brine_eff_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pressure_ratio_1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_pressure_ratio_1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pressure_ratio_2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_pressure_ratio_2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pressure_ratio_3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_pressure_ratio_3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pump_depth_ft(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_pump_depth_ft_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pump_hp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_pump_hp_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pump_watthr_per_lb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_pump_watthr_per_lb_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pump_work(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_pump_work_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pumpwork_inj(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_pumpwork_inj_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pumpwork_prod(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_pumpwork_prod_nget, self->data_ptr);
}

static PyObject *
Outputs_get_qCondenser(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_qCondenser_nget, self->data_ptr);
}

static PyObject *
Outputs_get_qRejectByStage_1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_qRejectByStage_1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_qRejectByStage_2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_qRejectByStage_2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_qRejectByStage_3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_qRejectByStage_3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_qRejectTotal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_qRejectTotal_nget, self->data_ptr);
}

static PyObject *
Outputs_get_reservoir_avg_temp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_reservoir_avg_temp_nget, self->data_ptr);
}

static PyObject *
Outputs_get_reservoir_pressure(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_reservoir_pressure_nget, self->data_ptr);
}

static PyObject *
Outputs_get_spec_vol(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_spec_vol_nget, self->data_ptr);
}

static PyObject *
Outputs_get_spec_vol_lp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_spec_vol_lp_nget, self->data_ptr);
}

static PyObject *
Outputs_get_system_lifetime_recapitalize(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_system_lifetime_recapitalize_aget, self->data_ptr);
}

static PyObject *
Outputs_get_timestep_dry_bulb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_timestep_dry_bulb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_timestep_pressure(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_timestep_pressure_aget, self->data_ptr);
}

static PyObject *
Outputs_get_timestep_resource_temperature(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_timestep_resource_temperature_aget, self->data_ptr);
}

static PyObject *
Outputs_get_timestep_test_values(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_timestep_test_values_aget, self->data_ptr);
}

static PyObject *
Outputs_get_timestep_wet_bulb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_timestep_wet_bulb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_v_stage_1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_v_stage_1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_v_stage_2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_v_stage_2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_v_stage_3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_v_stage_3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_x_hp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_x_hp_nget, self->data_ptr);
}

static PyObject *
Outputs_get_x_lp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Geothermal_Outputs_x_lp_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"GF_flowrate", (getter)Outputs_get_GF_flowrate,(setter)0,
	PyDoc_STR("*float*: GF Flow Rate [lb/h]"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual Energy [kWh]"),
 	NULL},
{"annual_energy_distribution_time", (getter)Outputs_get_annual_energy_distribution_time,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Annual energy production as function of Time"),
 	NULL},
{"bottom_hole_pressure", (getter)Outputs_get_bottom_hole_pressure,(setter)0,
	PyDoc_STR("*float*: Bottom hole pres calculated by GETEM"),
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	PyDoc_STR("*float*: Capacity factor"),
 	NULL},
{"condensate_pump_power", (getter)Outputs_get_condensate_pump_power,(setter)0,
	PyDoc_STR("*float*: hp"),
 	NULL},
{"cw_pump_head", (getter)Outputs_get_cw_pump_head,(setter)0,
	PyDoc_STR("*float*: Cooling Water Pump Head [lb/h]"),
 	NULL},
{"cw_pump_work", (getter)Outputs_get_cw_pump_work,(setter)0,
	PyDoc_STR("*float*: CW Pump Work [kW]"),
 	NULL},
{"cwflow", (getter)Outputs_get_cwflow,(setter)0,
	PyDoc_STR("*float*: Cooling Water Flow [lb/h]"),
 	NULL},
{"eff_secondlaw", (getter)Outputs_get_eff_secondlaw,(setter)0,
	PyDoc_STR("*float*: Second Law Efficiency [C]"),
 	NULL},
{"first_year_output", (getter)Outputs_get_first_year_output,(setter)0,
	PyDoc_STR("*float*: First Year Output [kWh]"),
 	NULL},
{"flash_count", (getter)Outputs_get_flash_count,(setter)0,
	PyDoc_STR("*float*: Flash Count [(1 -2)]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System power generated [kW]"),
 	NULL},
{"gross_cost_output", (getter)Outputs_get_gross_cost_output,(setter)0,
	PyDoc_STR("*float*: Gross output from GETEM for cost"),
 	NULL},
{"gross_output", (getter)Outputs_get_gross_output,(setter)0,
	PyDoc_STR("*float*: Gross output from GETEM"),
 	NULL},
{"hp_flash_pressure", (getter)Outputs_get_hp_flash_pressure,(setter)0,
	PyDoc_STR("*float*: HP Flash Pressure [psia]"),
 	NULL},
{"inj_pump_hp", (getter)Outputs_get_inj_pump_hp,(setter)0,
	PyDoc_STR("*float*: Injection Pump horsepower [hp]"),
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	PyDoc_STR("*float*: First year kWh/kW"),
 	NULL},
{"lifetime_output", (getter)Outputs_get_lifetime_output,(setter)0,
	PyDoc_STR("*float*: Lifetime Output [kWh]"),
 	NULL},
{"lp_flash_pressure", (getter)Outputs_get_lp_flash_pressure,(setter)0,
	PyDoc_STR("*float*: LP Flash Pressure [psia]"),
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	PyDoc_STR("*sequence*: Monthly energy before performance adjustments [kWh]"),
 	NULL},
{"monthly_power", (getter)Outputs_get_monthly_power,(setter)0,
	PyDoc_STR("*sequence*: Monthly power [kW]"),
 	NULL},
{"monthly_resource_temperature", (getter)Outputs_get_monthly_resource_temperature,(setter)0,
	PyDoc_STR("*sequence*: Monthly avg resource temperature [C]"),
 	NULL},
{"ncg_condensate_pump", (getter)Outputs_get_ncg_condensate_pump,(setter)0,
	PyDoc_STR("*float*: Condensate Pump Work [kW]"),
 	NULL},
{"num_wells_getem_inj", (getter)Outputs_get_num_wells_getem_inj,(setter)0,
	PyDoc_STR("*float*: Number of wells calculated by GETEM"),
 	NULL},
{"num_wells_getem_output", (getter)Outputs_get_num_wells_getem_output,(setter)0,
	PyDoc_STR("*float*: Number of wells calculated by GETEM"),
 	NULL},
{"plant_brine_eff", (getter)Outputs_get_plant_brine_eff,(setter)0,
	PyDoc_STR("*float*: Plant Brine Efficiency"),
 	NULL},
{"pressure_ratio_1", (getter)Outputs_get_pressure_ratio_1,(setter)0,
	PyDoc_STR("*float*: Suction Steam Ratio 1"),
 	NULL},
{"pressure_ratio_2", (getter)Outputs_get_pressure_ratio_2,(setter)0,
	PyDoc_STR("*float*: Suction Steam Ratio 2"),
 	NULL},
{"pressure_ratio_3", (getter)Outputs_get_pressure_ratio_3,(setter)0,
	PyDoc_STR("*float*: Suction Steam Ratio 3"),
 	NULL},
{"pump_depth_ft", (getter)Outputs_get_pump_depth_ft,(setter)0,
	PyDoc_STR("*float*: Pump depth calculated by GETEM [ft]"),
 	NULL},
{"pump_hp", (getter)Outputs_get_pump_hp,(setter)0,
	PyDoc_STR("*float*: Pump hp calculated by GETEM [hp]"),
 	NULL},
{"pump_watthr_per_lb", (getter)Outputs_get_pump_watthr_per_lb,(setter)0,
	PyDoc_STR("*float*: Pump work Efficiency"),
 	NULL},
{"pump_work", (getter)Outputs_get_pump_work,(setter)0,
	PyDoc_STR("*float*: Pump work calculated by GETEM [MW]"),
 	NULL},
{"pumpwork_inj", (getter)Outputs_get_pumpwork_inj,(setter)0,
	PyDoc_STR("*float*: Injection Pump work Efficiency"),
 	NULL},
{"pumpwork_prod", (getter)Outputs_get_pumpwork_prod,(setter)0,
	PyDoc_STR("*float*: Production Pump work Efficiency"),
 	NULL},
{"qCondenser", (getter)Outputs_get_qCondenser,(setter)0,
	PyDoc_STR("*float*: Condenser Heat Rejected [btu/h]"),
 	NULL},
{"qRejectByStage_1", (getter)Outputs_get_qRejectByStage_1,(setter)0,
	PyDoc_STR("*float*: Heat Rejected by NCG Condenser Stage 1 [BTU/h]"),
 	NULL},
{"qRejectByStage_2", (getter)Outputs_get_qRejectByStage_2,(setter)0,
	PyDoc_STR("*float*: Heat Rejected by NCG Condenser Stage 2 [BTU/h]"),
 	NULL},
{"qRejectByStage_3", (getter)Outputs_get_qRejectByStage_3,(setter)0,
	PyDoc_STR("*float*: Heat Rejected by NCG Condenser Stage 3 [BTU/h]"),
 	NULL},
{"qRejectTotal", (getter)Outputs_get_qRejectTotal,(setter)0,
	PyDoc_STR("*float*: Total Heat Rejection [btu/h]"),
 	NULL},
{"reservoir_avg_temp", (getter)Outputs_get_reservoir_avg_temp,(setter)0,
	PyDoc_STR("*float*: Avg reservoir temp calculated by GETEM [C]"),
 	NULL},
{"reservoir_pressure", (getter)Outputs_get_reservoir_pressure,(setter)0,
	PyDoc_STR("*float*: Reservoir pres calculated by GETEM"),
 	NULL},
{"spec_vol", (getter)Outputs_get_spec_vol,(setter)0,
	PyDoc_STR("*float*: HP Specific Volume [cft/lb]"),
 	NULL},
{"spec_vol_lp", (getter)Outputs_get_spec_vol_lp,(setter)0,
	PyDoc_STR("*float*: LP Specific Volume [cft/lb]"),
 	NULL},
{"system_lifetime_recapitalize", (getter)Outputs_get_system_lifetime_recapitalize,(setter)0,
	PyDoc_STR("*sequence*: Resource replacement? (1=yes)"),
 	NULL},
{"timestep_dry_bulb", (getter)Outputs_get_timestep_dry_bulb,(setter)0,
	PyDoc_STR("*sequence*: Dry bulb temperature [C]"),
 	NULL},
{"timestep_pressure", (getter)Outputs_get_timestep_pressure,(setter)0,
	PyDoc_STR("*sequence*: Atmospheric pressure [atm]"),
 	NULL},
{"timestep_resource_temperature", (getter)Outputs_get_timestep_resource_temperature,(setter)0,
	PyDoc_STR("*sequence*: Resource temperature [C]"),
 	NULL},
{"timestep_test_values", (getter)Outputs_get_timestep_test_values,(setter)0,
	PyDoc_STR("*sequence*: Test output values in each time step"),
 	NULL},
{"timestep_wet_bulb", (getter)Outputs_get_timestep_wet_bulb,(setter)0,
	PyDoc_STR("*sequence*: Wet bulb temperature [C]"),
 	NULL},
{"v_stage_1", (getter)Outputs_get_v_stage_1,(setter)0,
	PyDoc_STR("*float*: Vacumm Pump Stage 1 [kW]"),
 	NULL},
{"v_stage_2", (getter)Outputs_get_v_stage_2,(setter)0,
	PyDoc_STR("*float*: Vacumm Pump Stage 2 [kW]"),
 	NULL},
{"v_stage_3", (getter)Outputs_get_v_stage_3,(setter)0,
	PyDoc_STR("*float*: Vacumm Pump Stage 3 [kW]"),
 	NULL},
{"x_hp", (getter)Outputs_get_x_hp,(setter)0,
	PyDoc_STR("*float*: HP Mass Fraction [%]"),
 	NULL},
{"x_lp", (getter)Outputs_get_x_lp,(setter)0,
	PyDoc_STR("*float*: LP Mass Fraction [%]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Geothermal.Outputs",             /*tp_name*/
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
 * Geothermal
 */

static PyTypeObject Geothermal_Type;

static CmodObject *
newGeothermalObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Geothermal_Type);

	PySAM_TECH_ATTR()

	PyObject* GeoHourly_obj = GeoHourly_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "GeoHourly", GeoHourly_obj);
	Py_DECREF(GeoHourly_obj);

	PyObject* AdjustmentFactorsModule = PyImport_ImportModule("AdjustmentFactors");

	PyObject* data_cap = PyCapsule_New(self->data_ptr, NULL, NULL);
	PyObject* Adjust_obj = PyObject_CallMethod(AdjustmentFactorsModule, "new", "(O)", data_cap);
	Py_XDECREF(data_cap);
	Py_XDECREF(AdjustmentFactorsModule);

	if (!Adjust_obj){
		PyErr_SetString(PyExc_Exception, "Couldn't create AdjustmentFactorsObject\n");
		return NULL;
	}

	PyDict_SetItemString(attr_dict, "AdjustmentFactors", Adjust_obj);
	Py_DECREF(Adjust_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Geothermal methods */

static void
Geothermal_dealloc(CmodObject *self)
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
Geothermal_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Geothermal_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Geothermal_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Geothermal"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Geothermal_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Geothermal"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Geothermal_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Geothermal_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Geothermal_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Geothermal_methods[] = {
		{"execute",           (PyCFunction)Geothermal_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Geothermal_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'GeoHourly': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Geothermal_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'GeoHourly': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Geothermal_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Geothermal_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Geothermal_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Geothermal_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Geothermal_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Geothermal_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Geothermal",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Geothermal_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Geothermal_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Geothermal_getattro, /*tp_getattro*/
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
		Geothermal_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Geothermal object */

static PyObject *
Geothermal_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newGeothermalObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Geothermal_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newGeothermalObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Geothermal_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newGeothermalObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Geothermal", def) < 0) {
		Geothermal_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Geothermal_from_existing(PyObject *self, PyObject *args)
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

	rv = newGeothermalObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Geothermal", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef GeothermalModule_methods[] = {
		{"new",             Geothermal_new,         METH_VARARGS,
				PyDoc_STR("new() -> Geothermal")},
		{"default",             Geothermal_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Geothermal\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"GeothermalPowerAllEquityPartnershipFlip\"*\n\n		- *\"GeothermalPowerLCOECalculator\"*\n\n		- *\"GeothermalPowerLeveragedPartnershipFlip\"*\n\n		- *\"GeothermalPowerMerchantPlant\"*\n\n		- *\"GeothermalPowerNone\"*\n\n		- *\"GeothermalPowerSaleLeaseback\"*\n\n		- *\"GeothermalPowerSingleOwner\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Geothermal_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Geothermal\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Geothermal_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Geothermal\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Geothermal power model for hydrothermal and EGS systems with flash or binary conversion");


static int
GeothermalModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Geothermal_Type.tp_dict = PyDict_New();
	if (!Geothermal_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to Geothermal_Type
	PyObject* AdjustmentFactorsModule = PyImport_ImportModule("AdjustmentFactors");
	if (!AdjustmentFactorsModule){
		PyErr_SetImportError(PyUnicode_FromString("Could not import AdjustmentFactors module."), NULL, NULL);
	}

	PyTypeObject* AdjustmentFactors_Type = (PyTypeObject*)PyObject_GetAttrString(AdjustmentFactorsModule, "AdjustmentFactors");
	if (!AdjustmentFactors_Type){
		PyErr_SetImportError(PyUnicode_FromString("Could not import AdjustmentFactors type."), NULL, NULL);
	}
	Py_XDECREF(AdjustmentFactorsModule);

	if (PyType_Ready(AdjustmentFactors_Type) < 0) { goto fail; }
	PyDict_SetItemString(Geothermal_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the GeoHourly type object to Geothermal_Type
	if (PyType_Ready(&GeoHourly_Type) < 0) { goto fail; }
	PyDict_SetItemString(Geothermal_Type.tp_dict,
				"GeoHourly",
				(PyObject*)&GeoHourly_Type);
	Py_DECREF(&GeoHourly_Type);

	/// Add the Outputs type object to Geothermal_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Geothermal_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Geothermal type object to the module
	if (PyType_Ready(&Geothermal_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Geothermal",
				(PyObject*)&Geothermal_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot GeothermalModule_slots[] = {
		{Py_mod_exec, GeothermalModule_exec},
		{0, NULL},
};

static struct PyModuleDef GeothermalModule = {
		PyModuleDef_HEAD_INIT,
		"Geothermal",
		module_doc,
		0,
		GeothermalModule_methods,
		GeothermalModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Geothermal(void)
{
	return PyModuleDef_Init(&GeothermalModule);
}