#include <Python.h>

#include <SAM_Geothermal.h>
#include <SAM_api.h>

#include "PySAM_utils.h"



	/*
	 * GeoHourly Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Geothermal   data_ptr;
} GeoHourlyObject;

static PyTypeObject GeoHourly_Type;

static PyObject *
GeoHourly_new(SAM_Geothermal data_ptr)
{
	PyObject* new_obj = GeoHourly_Type.tp_alloc(&GeoHourly_Type,0);

	GeoHourlyObject* GeoHourly_obj = (GeoHourlyObject*)new_obj;

	GeoHourly_obj->data_ptr = data_ptr;

	return new_obj;
}

/* GeoHourly methods */

static PyObject *
GeoHourly_assign(GeoHourlyObject *self, PyObject *args)
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
GeoHourly_export(GeoHourlyObject *self, PyObject *args)
{
	PyTypeObject* tp = &GeoHourly_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef GeoHourly_methods[] = {
		{"assign",            (PyCFunction)GeoHourly_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)GeoHourly_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
GeoHourly_get_CT(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_CT_fget, self->data_ptr);
}

static int
GeoHourly_set_CT(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_CT_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_HTF(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_HTF_fget, self->data_ptr);
}

static int
GeoHourly_set_HTF(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_HTF_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_P_boil(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_P_boil_fget, self->data_ptr);
}

static int
GeoHourly_set_P_boil(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_P_boil_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_P_cond_min(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_P_cond_min_fget, self->data_ptr);
}

static int
GeoHourly_set_P_cond_min(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_P_cond_min_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_P_cond_ratio(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_P_cond_ratio_fget, self->data_ptr);
}

static int
GeoHourly_set_P_cond_ratio(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_P_cond_ratio_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_T_ITD_des(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_T_ITD_des_fget, self->data_ptr);
}

static int
GeoHourly_set_T_ITD_des(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_T_ITD_des_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_T_amb_des(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_T_amb_des_fget, self->data_ptr);
}

static int
GeoHourly_set_T_amb_des(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_T_amb_des_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_T_approach(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_T_approach_fget, self->data_ptr);
}

static int
GeoHourly_set_T_approach(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_T_approach_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_T_htf_cold_ref(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_T_htf_cold_ref_fget, self->data_ptr);
}

static int
GeoHourly_set_T_htf_cold_ref(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_T_htf_cold_ref_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_T_htf_hot_ref(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_T_htf_hot_ref_fget, self->data_ptr);
}

static int
GeoHourly_set_T_htf_hot_ref(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_T_htf_hot_ref_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_ambient_pressure(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_ambient_pressure_fget, self->data_ptr);
}

static int
GeoHourly_set_ambient_pressure(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_ambient_pressure_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_analysis_type(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_analysis_type_fget, self->data_ptr);
}

static int
GeoHourly_set_analysis_type(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_analysis_type_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_casing_size(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_casing_size_fget, self->data_ptr);
}

static int
GeoHourly_set_casing_size(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_casing_size_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_conversion_subtype(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_conversion_subtype_fget, self->data_ptr);
}

static int
GeoHourly_set_conversion_subtype(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_conversion_subtype_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_conversion_type(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_conversion_type_fget, self->data_ptr);
}

static int
GeoHourly_set_conversion_type(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_conversion_type_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_dT_cw_ref(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_dT_cw_ref_fget, self->data_ptr);
}

static int
GeoHourly_set_dT_cw_ref(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_dT_cw_ref_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_decline_type(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_decline_type_fget, self->data_ptr);
}

static int
GeoHourly_set_decline_type(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_decline_type_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_delta_pressure_equip(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_delta_pressure_equip_fget, self->data_ptr);
}

static int
GeoHourly_set_delta_pressure_equip(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_delta_pressure_equip_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_design_temp(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_design_temp_fget, self->data_ptr);
}

static int
GeoHourly_set_design_temp(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_design_temp_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_eta_ref(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_eta_ref_fget, self->data_ptr);
}

static int
GeoHourly_set_eta_ref(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_eta_ref_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_excess_pressure_pump(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_excess_pressure_pump_fget, self->data_ptr);
}

static int
GeoHourly_set_excess_pressure_pump(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_excess_pressure_pump_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_fracture_angle(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_fracture_angle_fget, self->data_ptr);
}

static int
GeoHourly_set_fracture_angle(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_fracture_angle_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_fracture_aperature(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_fracture_aperature_fget, self->data_ptr);
}

static int
GeoHourly_set_fracture_aperature(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_fracture_aperature_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_fracture_width(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_fracture_width_fget, self->data_ptr);
}

static int
GeoHourly_set_fracture_width(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_fracture_width_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_geothermal_analysis_period(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_geothermal_analysis_period_fget, self->data_ptr);
}

static int
GeoHourly_set_geothermal_analysis_period(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_geothermal_analysis_period_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hc_ctl1(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_hc_ctl1_fget, self->data_ptr);
}

static int
GeoHourly_set_hc_ctl1(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_hc_ctl1_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hc_ctl2(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_hc_ctl2_fget, self->data_ptr);
}

static int
GeoHourly_set_hc_ctl2(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_hc_ctl2_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hc_ctl3(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_hc_ctl3_fget, self->data_ptr);
}

static int
GeoHourly_set_hc_ctl3(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_hc_ctl3_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hc_ctl4(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_hc_ctl4_fget, self->data_ptr);
}

static int
GeoHourly_set_hc_ctl4(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_hc_ctl4_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hc_ctl5(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_hc_ctl5_fget, self->data_ptr);
}

static int
GeoHourly_set_hc_ctl5(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_hc_ctl5_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hc_ctl6(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_hc_ctl6_fget, self->data_ptr);
}

static int
GeoHourly_set_hc_ctl6(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_hc_ctl6_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hc_ctl7(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_hc_ctl7_fget, self->data_ptr);
}

static int
GeoHourly_set_hc_ctl7(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_hc_ctl7_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hc_ctl8(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_hc_ctl8_fget, self->data_ptr);
}

static int
GeoHourly_set_hc_ctl8(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_hc_ctl8_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hc_ctl9(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_hc_ctl9_fget, self->data_ptr);
}

static int
GeoHourly_set_hc_ctl9(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_hc_ctl9_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hr_pl_nlev(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_hr_pl_nlev_fget, self->data_ptr);
}

static int
GeoHourly_set_hr_pl_nlev(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_hr_pl_nlev_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hybrid_dispatch_schedule(GeoHourlyObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Geothermal_GeoHourly_file_sget, self->data_ptr);
}

static int
GeoHourly_set_hybrid_dispatch_schedule(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Geothermal_GeoHourly_file_sset, self->data_ptr);
}

static PyObject *
GeoHourly_get_inj_prod_well_distance(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_inj_prod_well_distance_fget, self->data_ptr);
}

static int
GeoHourly_set_inj_prod_well_distance(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_inj_prod_well_distance_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_inj_well_diam(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_inj_well_diam_fget, self->data_ptr);
}

static int
GeoHourly_set_inj_well_diam(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_inj_well_diam_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_model_choice(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_model_choice_fget, self->data_ptr);
}

static int
GeoHourly_set_model_choice(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_model_choice_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_nameplate(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_nameplate_fget, self->data_ptr);
}

static int
GeoHourly_set_nameplate(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_nameplate_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_num_fractures(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_num_fractures_fget, self->data_ptr);
}

static int
GeoHourly_set_num_fractures(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_num_fractures_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_num_wells(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_num_wells_fget, self->data_ptr);
}

static int
GeoHourly_set_num_wells(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_num_wells_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_num_wells_getem(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_num_wells_getem_fget, self->data_ptr);
}

static int
GeoHourly_set_num_wells_getem(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_num_wells_getem_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_pb_bd_frac(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_pb_bd_frac_fget, self->data_ptr);
}

static int
GeoHourly_set_pb_bd_frac(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_pb_bd_frac_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_plant_efficiency_input(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_plant_efficiency_input_fget, self->data_ptr);
}

static int
GeoHourly_set_plant_efficiency_input(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_plant_efficiency_input_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_pump_efficiency(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_pump_efficiency_fget, self->data_ptr);
}

static int
GeoHourly_set_pump_efficiency(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_pump_efficiency_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_q_sby_frac(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_q_sby_frac_fget, self->data_ptr);
}

static int
GeoHourly_set_q_sby_frac(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_q_sby_frac_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_reservoir_height(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_reservoir_height_fget, self->data_ptr);
}

static int
GeoHourly_set_reservoir_height(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_reservoir_height_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_reservoir_permeability(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_reservoir_permeability_fget, self->data_ptr);
}

static int
GeoHourly_set_reservoir_permeability(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_reservoir_permeability_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_reservoir_pressure_change(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_reservoir_pressure_change_fget, self->data_ptr);
}

static int
GeoHourly_set_reservoir_pressure_change(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_reservoir_pressure_change_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_reservoir_pressure_change_type(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_reservoir_pressure_change_type_fget, self->data_ptr);
}

static int
GeoHourly_set_reservoir_pressure_change_type(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_reservoir_pressure_change_type_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_reservoir_width(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_reservoir_width_fget, self->data_ptr);
}

static int
GeoHourly_set_reservoir_width(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_reservoir_width_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_resource_depth(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_resource_depth_fget, self->data_ptr);
}

static int
GeoHourly_set_resource_depth(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_resource_depth_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_resource_potential(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_resource_potential_fget, self->data_ptr);
}

static int
GeoHourly_set_resource_potential(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_resource_potential_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_resource_temp(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_resource_temp_fget, self->data_ptr);
}

static int
GeoHourly_set_resource_temp(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_resource_temp_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_resource_type(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_resource_type_fget, self->data_ptr);
}

static int
GeoHourly_set_resource_type(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_resource_type_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_rock_density(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_rock_density_fget, self->data_ptr);
}

static int
GeoHourly_set_rock_density(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_rock_density_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_rock_specific_heat(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_rock_specific_heat_fget, self->data_ptr);
}

static int
GeoHourly_set_rock_specific_heat(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_rock_specific_heat_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_rock_thermal_conductivity(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_rock_thermal_conductivity_fget, self->data_ptr);
}

static int
GeoHourly_set_rock_thermal_conductivity(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_rock_thermal_conductivity_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_specified_pump_work_amount(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_specified_pump_work_amount_fget, self->data_ptr);
}

static int
GeoHourly_set_specified_pump_work_amount(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_specified_pump_work_amount_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_specify_pump_work(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_specify_pump_work_fget, self->data_ptr);
}

static int
GeoHourly_set_specify_pump_work(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_specify_pump_work_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_startup_frac(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_startup_frac_fget, self->data_ptr);
}

static int
GeoHourly_set_startup_frac(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_startup_frac_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_startup_time(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_startup_time_fget, self->data_ptr);
}

static int
GeoHourly_set_startup_time(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_startup_time_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_subsurface_water_loss(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_subsurface_water_loss_fget, self->data_ptr);
}

static int
GeoHourly_set_subsurface_water_loss(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_subsurface_water_loss_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_temp_decline_max(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_temp_decline_max_fget, self->data_ptr);
}

static int
GeoHourly_set_temp_decline_max(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_temp_decline_max_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_temp_decline_rate(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_temp_decline_rate_fget, self->data_ptr);
}

static int
GeoHourly_set_temp_decline_rate(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_temp_decline_rate_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_ui_calculations_only(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_ui_calculations_only_fget, self->data_ptr);
}

static int
GeoHourly_set_ui_calculations_only(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_ui_calculations_only_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_well_diameter(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_well_diameter_fget, self->data_ptr);
}

static int
GeoHourly_set_well_diameter(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_well_diameter_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_well_flow_rate(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_well_flow_rate_fget, self->data_ptr);
}

static int
GeoHourly_set_well_flow_rate(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_well_flow_rate_fset, self->data_ptr);
}

static PyObject *
GeoHourly_get_wet_bulb_temp(GeoHourlyObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_GeoHourly_wet_bulb_temp_fget, self->data_ptr);
}

static int
GeoHourly_set_wet_bulb_temp(GeoHourlyObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Geothermal_GeoHourly_wet_bulb_temp_fset, self->data_ptr);
}

static PyGetSetDef GeoHourly_getset[] = {
{"CT", (getter)GeoHourly_get_CT,(setter)GeoHourly_set_CT,
	"Condenser type (Wet, Dry,Hybrid) [(1-3)], number.\n Constraints: INTEGER; Required if: ui_calculations_only=0.",
 	NULL},
{"HTF", (getter)GeoHourly_get_HTF,(setter)GeoHourly_set_HTF,
	"Heat trans fluid type ID [(1-27)], number.\n Constraints: INTEGER; Required if: ui_calculations_only=0.",
 	NULL},
{"P_boil", (getter)GeoHourly_get_P_boil,(setter)GeoHourly_set_P_boil,
	"Design Boiler Pressure [bar], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"P_cond_min", (getter)GeoHourly_get_P_cond_min,(setter)GeoHourly_set_P_cond_min,
	"Minimum condenser pressure [in Hg], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"P_cond_ratio", (getter)GeoHourly_get_P_cond_ratio,(setter)GeoHourly_set_P_cond_ratio,
	"Condenser pressure ratio [], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"T_ITD_des", (getter)GeoHourly_get_T_ITD_des,(setter)GeoHourly_set_T_ITD_des,
	"Design ITD for dry system [C], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"T_amb_des", (getter)GeoHourly_get_T_amb_des,(setter)GeoHourly_set_T_amb_des,
	"Design ambient temperature [C], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"T_approach", (getter)GeoHourly_get_T_approach,(setter)GeoHourly_set_T_approach,
	"Approach Temperature [C], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"T_htf_cold_ref", (getter)GeoHourly_get_T_htf_cold_ref,(setter)GeoHourly_set_T_htf_cold_ref,
	"Outlet design temp [C], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"T_htf_hot_ref", (getter)GeoHourly_get_T_htf_hot_ref,(setter)GeoHourly_set_T_htf_hot_ref,
	"Inlet design temp [C], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"ambient_pressure", (getter)GeoHourly_get_ambient_pressure,(setter)GeoHourly_set_ambient_pressure,
	"Ambient pressure [psi], number.\n Required if: *.",
 	NULL},
{"analysis_type", (getter)GeoHourly_get_analysis_type,(setter)GeoHourly_set_analysis_type,
	"Analysis Type [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"casing_size", (getter)GeoHourly_get_casing_size,(setter)GeoHourly_set_casing_size,
	"Production pump casing size [in], number.\n Required if: *.",
 	NULL},
{"conversion_subtype", (getter)GeoHourly_get_conversion_subtype,(setter)GeoHourly_set_conversion_subtype,
	"Conversion Subtype [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"conversion_type", (getter)GeoHourly_get_conversion_type,(setter)GeoHourly_set_conversion_type,
	"Conversion Type [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"dT_cw_ref", (getter)GeoHourly_get_dT_cw_ref,(setter)GeoHourly_set_dT_cw_ref,
	"Design condenser cooling water inlet/outlet T diff [C], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"decline_type", (getter)GeoHourly_get_decline_type,(setter)GeoHourly_set_decline_type,
	"Temp decline Type [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"delta_pressure_equip", (getter)GeoHourly_get_delta_pressure_equip,(setter)GeoHourly_set_delta_pressure_equip,
	"Delta pressure across surface equipment [psi], number.\n Required if: *.",
 	NULL},
{"design_temp", (getter)GeoHourly_get_design_temp,(setter)GeoHourly_set_design_temp,
	"Power block design temperature [C], number.\n Required if: *.",
 	NULL},
{"eta_ref", (getter)GeoHourly_get_eta_ref,(setter)GeoHourly_set_eta_ref,
	"Desgin conversion efficiency [%], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"excess_pressure_pump", (getter)GeoHourly_get_excess_pressure_pump,(setter)GeoHourly_set_excess_pressure_pump,
	"Excess pressure @ pump suction [psi], number.\n Required if: *.",
 	NULL},
{"fracture_angle", (getter)GeoHourly_get_fracture_angle,(setter)GeoHourly_set_fracture_angle,
	"Fracture angle [deg], number.\n Required if: *.",
 	NULL},
{"fracture_aperature", (getter)GeoHourly_get_fracture_aperature,(setter)GeoHourly_set_fracture_aperature,
	"Fracture aperature [m], number.\n Required if: *.",
 	NULL},
{"fracture_width", (getter)GeoHourly_get_fracture_width,(setter)GeoHourly_set_fracture_width,
	"Fracture width [m], number.\n Required if: *.",
 	NULL},
{"geothermal_analysis_period", (getter)GeoHourly_get_geothermal_analysis_period,(setter)GeoHourly_set_geothermal_analysis_period,
	"Analysis Lifetime [years], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"hc_ctl1", (getter)GeoHourly_get_hc_ctl1,(setter)GeoHourly_set_hc_ctl1,
	"HC Control 1 [], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"hc_ctl2", (getter)GeoHourly_get_hc_ctl2,(setter)GeoHourly_set_hc_ctl2,
	"HC Control 2 [], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"hc_ctl3", (getter)GeoHourly_get_hc_ctl3,(setter)GeoHourly_set_hc_ctl3,
	"HC Control 3 [], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"hc_ctl4", (getter)GeoHourly_get_hc_ctl4,(setter)GeoHourly_set_hc_ctl4,
	"HC Control 4 [], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"hc_ctl5", (getter)GeoHourly_get_hc_ctl5,(setter)GeoHourly_set_hc_ctl5,
	"HC Control 5 [], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"hc_ctl6", (getter)GeoHourly_get_hc_ctl6,(setter)GeoHourly_set_hc_ctl6,
	"HC Control 6 [], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"hc_ctl7", (getter)GeoHourly_get_hc_ctl7,(setter)GeoHourly_set_hc_ctl7,
	"HC Control 7 [], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"hc_ctl8", (getter)GeoHourly_get_hc_ctl8,(setter)GeoHourly_set_hc_ctl8,
	"HC Control 8 [], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"hc_ctl9", (getter)GeoHourly_get_hc_ctl9,(setter)GeoHourly_set_hc_ctl9,
	"HC Control 9 [], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"hr_pl_nlev", (getter)GeoHourly_get_hr_pl_nlev,(setter)GeoHourly_set_hr_pl_nlev,
	"# part-load increments [(0-9)], number.\n Constraints: INTEGER; Required if: ui_calculations_only=0.",
 	NULL},
{"hybrid_dispatch_schedule", (getter)GeoHourly_get_hybrid_dispatch_schedule,(setter)GeoHourly_set_hybrid_dispatch_schedule,
	"Daily dispatch schedule [], string.\n Constraints: TOUSCHED; Required if: ui_calculations_only=0.",
 	NULL},
{"inj_prod_well_distance", (getter)GeoHourly_get_inj_prod_well_distance,(setter)GeoHourly_set_inj_prod_well_distance,
	"Distance from injection to production wells [m], number.\n Required if: *.",
 	NULL},
{"inj_well_diam", (getter)GeoHourly_get_inj_well_diam,(setter)GeoHourly_set_inj_well_diam,
	"Injection well diameter [in], number.\n Required if: *.",
 	NULL},
{"model_choice", (getter)GeoHourly_get_model_choice,(setter)GeoHourly_set_model_choice,
	"Which model to run (0,1,2) [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"nameplate", (getter)GeoHourly_get_nameplate,(setter)GeoHourly_set_nameplate,
	"Desired plant output [kW], number.\n Required if: *.",
 	NULL},
{"num_fractures", (getter)GeoHourly_get_num_fractures,(setter)GeoHourly_set_num_fractures,
	"Number of fractures [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"num_wells", (getter)GeoHourly_get_num_wells,(setter)GeoHourly_set_num_wells,
	"Number of Wells [], number.\n Required if: *.",
 	NULL},
{"num_wells_getem", (getter)GeoHourly_get_num_wells_getem,(setter)GeoHourly_set_num_wells_getem,
	"Number of Wells GETEM calc'd [], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"pb_bd_frac", (getter)GeoHourly_get_pb_bd_frac,(setter)GeoHourly_set_pb_bd_frac,
	"Blowdown steam fraction [%], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"plant_efficiency_input", (getter)GeoHourly_get_plant_efficiency_input,(setter)GeoHourly_set_plant_efficiency_input,
	"Plant efficiency [], number.\n Required if: *.",
 	NULL},
{"pump_efficiency", (getter)GeoHourly_get_pump_efficiency,(setter)GeoHourly_set_pump_efficiency,
	"Pump efficiency [%], number.\n Required if: *.",
 	NULL},
{"q_sby_frac", (getter)GeoHourly_get_q_sby_frac,(setter)GeoHourly_set_q_sby_frac,
	"% thermal power for standby mode [%], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"reservoir_height", (getter)GeoHourly_get_reservoir_height,(setter)GeoHourly_set_reservoir_height,
	"Reservoir height [m], number.\n Required if: *.",
 	NULL},
{"reservoir_permeability", (getter)GeoHourly_get_reservoir_permeability,(setter)GeoHourly_set_reservoir_permeability,
	"Reservoir Permeability [darcys], number.\n Required if: *.",
 	NULL},
{"reservoir_pressure_change", (getter)GeoHourly_get_reservoir_pressure_change,(setter)GeoHourly_set_reservoir_pressure_change,
	"Pressure change [psi-h/1000lb], number.\n Required if: *.",
 	NULL},
{"reservoir_pressure_change_type", (getter)GeoHourly_get_reservoir_pressure_change_type,(setter)GeoHourly_set_reservoir_pressure_change_type,
	"Reservoir pressure change type [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"reservoir_width", (getter)GeoHourly_get_reservoir_width,(setter)GeoHourly_set_reservoir_width,
	"Reservoir width [m], number.\n Required if: *.",
 	NULL},
{"resource_depth", (getter)GeoHourly_get_resource_depth,(setter)GeoHourly_set_resource_depth,
	"Resource Depth [m], number.\n Required if: *.",
 	NULL},
{"resource_potential", (getter)GeoHourly_get_resource_potential,(setter)GeoHourly_set_resource_potential,
	"Resource Potential [MW], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"resource_temp", (getter)GeoHourly_get_resource_temp,(setter)GeoHourly_set_resource_temp,
	"Resource Temperature [C], number.\n Required if: *.",
 	NULL},
{"resource_type", (getter)GeoHourly_get_resource_type,(setter)GeoHourly_set_resource_type,
	"Type of Resource [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"rock_density", (getter)GeoHourly_get_rock_density,(setter)GeoHourly_set_rock_density,
	"Rock density [kg/m^3], number.\n Required if: *.",
 	NULL},
{"rock_specific_heat", (getter)GeoHourly_get_rock_specific_heat,(setter)GeoHourly_set_rock_specific_heat,
	"Rock specific heat [J/kg-C], number.\n Required if: *.",
 	NULL},
{"rock_thermal_conductivity", (getter)GeoHourly_get_rock_thermal_conductivity,(setter)GeoHourly_set_rock_thermal_conductivity,
	"Rock thermal conductivity [J/m-day-C], number.\n Required if: *.",
 	NULL},
{"specified_pump_work_amount", (getter)GeoHourly_get_specified_pump_work_amount,(setter)GeoHourly_set_specified_pump_work_amount,
	"Pump work specified by user [MW], number.\n Required if: *.",
 	NULL},
{"specify_pump_work", (getter)GeoHourly_get_specify_pump_work,(setter)GeoHourly_set_specify_pump_work,
	"Did user specify pump work? [0 or 1], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"startup_frac", (getter)GeoHourly_get_startup_frac,(setter)GeoHourly_set_startup_frac,
	"% thermal power for startup [%], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"startup_time", (getter)GeoHourly_get_startup_time,(setter)GeoHourly_set_startup_time,
	"Hours to start power block [hours], number.\n Required if: ui_calculations_only=0.",
 	NULL},
{"subsurface_water_loss", (getter)GeoHourly_get_subsurface_water_loss,(setter)GeoHourly_set_subsurface_water_loss,
	"Subsurface water loss [%], number.\n Required if: *.",
 	NULL},
{"temp_decline_max", (getter)GeoHourly_get_temp_decline_max,(setter)GeoHourly_set_temp_decline_max,
	"Maximum temperature decline [C], number.\n Required if: *.",
 	NULL},
{"temp_decline_rate", (getter)GeoHourly_get_temp_decline_rate,(setter)GeoHourly_set_temp_decline_rate,
	"Temperature decline rate [%/yr], number.\n Required if: *.",
 	NULL},
{"ui_calculations_only", (getter)GeoHourly_get_ui_calculations_only,(setter)GeoHourly_set_ui_calculations_only,
	"If = 1, only run UI calculations [], number.\n Required if: *.",
 	NULL},
{"well_diameter", (getter)GeoHourly_get_well_diameter,(setter)GeoHourly_set_well_diameter,
	"Production well diameter [in], number.\n Required if: *.",
 	NULL},
{"well_flow_rate", (getter)GeoHourly_get_well_flow_rate,(setter)GeoHourly_set_well_flow_rate,
	"Production flow rate per well [kg/s], number.\n Required if: *.",
 	NULL},
{"wet_bulb_temp", (getter)GeoHourly_get_wet_bulb_temp,(setter)GeoHourly_set_wet_bulb_temp,
	"Wet Bulb Temperature [C], number.\n Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject GeoHourly_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Geothermal.GeoHourly",             /*tp_name*/
		sizeof(GeoHourlyObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		GeoHourly_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		GeoHourly_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * Weather Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Geothermal   data_ptr;
} WeatherObject;

static PyTypeObject Weather_Type;

static PyObject *
Weather_new(SAM_Geothermal data_ptr)
{
	PyObject* new_obj = Weather_Type.tp_alloc(&Weather_Type,0);

	WeatherObject* Weather_obj = (WeatherObject*)new_obj;

	Weather_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Weather methods */

static PyObject *
Weather_assign(WeatherObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Geothermal", "Weather")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Weather_export(WeatherObject *self, PyObject *args)
{
	PyTypeObject* tp = &Weather_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Weather_methods[] = {
		{"assign",            (PyCFunction)Weather_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Weather_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Weather_get_file_name(WeatherObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Geothermal_Weather_file_sget, self->data_ptr);
}

static int
Weather_set_file_name(WeatherObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Geothermal_Weather_file_sset, self->data_ptr);
}

static PyGetSetDef Weather_getset[] = {
{"file_name", (getter)Weather_get_file_name,(setter)Weather_set_file_name,
	"local weather file path [], string.\n Constraints: LOCAL_FILE; Required if: ui_calculations_only=0.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Weather_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Geothermal.Weather",             /*tp_name*/
		sizeof(WeatherObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Weather_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Weather_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * Outputs Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Geothermal   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Geothermal data_ptr)
{
	PyObject* new_obj = Outputs_Type.tp_alloc(&Outputs_Type,0);

	OutputsObject* Outputs_obj = (OutputsObject*)new_obj;

	Outputs_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Outputs methods */

static PyObject *
Outputs_assign(OutputsObject *self, PyObject *args)
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
Outputs_export(OutputsObject *self, PyObject *args)
{
	PyTypeObject* tp = &Outputs_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Outputs_methods[] = {
		{"assign",            (PyCFunction)Outputs_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Outputs_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Outputs_get_GF_flowrate(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_GF_flowrate_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_annual_energy_fget, self->data_ptr);
}

static PyObject *
Outputs_get_bottom_hole_pressure(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_bottom_hole_pressure_fget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_capacity_factor_fget, self->data_ptr);
}

static PyObject *
Outputs_get_condensate_pump_power(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_condensate_pump_power_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cw_pump_head(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_cw_pump_head_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cw_pump_work(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_cw_pump_work_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cwflow(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_cwflow_fget, self->data_ptr);
}

static PyObject *
Outputs_get_eff_secondlaw(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_eff_secondlaw_fget, self->data_ptr);
}

static PyObject *
Outputs_get_first_year_output(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_first_year_output_fget, self->data_ptr);
}

static PyObject *
Outputs_get_flash_count(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_flash_count_fget, self->data_ptr);
}

static PyObject *
Outputs_get_gross_output(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_gross_output_fget, self->data_ptr);
}

static PyObject *
Outputs_get_hp_flash_pressure(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_hp_flash_pressure_fget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_kwh_per_kw_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lifetime_output(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_lifetime_output_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lp_flash_pressure(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_lp_flash_pressure_fget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_power(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_monthly_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_resource_temperature(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_monthly_resource_temperature_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ncg_condensate_pump(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_ncg_condensate_pump_fget, self->data_ptr);
}

static PyObject *
Outputs_get_num_wells_getem_output(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_num_wells_getem_output_fget, self->data_ptr);
}

static PyObject *
Outputs_get_plant_brine_eff(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_plant_brine_eff_fget, self->data_ptr);
}

static PyObject *
Outputs_get_pressure_ratio_1(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_pressure_ratio_1_fget, self->data_ptr);
}

static PyObject *
Outputs_get_pressure_ratio_2(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_pressure_ratio_2_fget, self->data_ptr);
}

static PyObject *
Outputs_get_pressure_ratio_3(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_pressure_ratio_3_fget, self->data_ptr);
}

static PyObject *
Outputs_get_pump_depth_ft(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_pump_depth_ft_fget, self->data_ptr);
}

static PyObject *
Outputs_get_pump_hp(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_pump_hp_fget, self->data_ptr);
}

static PyObject *
Outputs_get_pump_work(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_pump_work_fget, self->data_ptr);
}

static PyObject *
Outputs_get_qCondenser(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_qCondenser_fget, self->data_ptr);
}

static PyObject *
Outputs_get_qRejectByStage_1(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_qRejectByStage_1_fget, self->data_ptr);
}

static PyObject *
Outputs_get_qRejectByStage_2(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_qRejectByStage_2_fget, self->data_ptr);
}

static PyObject *
Outputs_get_qRejectByStage_3(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_qRejectByStage_3_fget, self->data_ptr);
}

static PyObject *
Outputs_get_qRejectTotal(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_qRejectTotal_fget, self->data_ptr);
}

static PyObject *
Outputs_get_reservoir_avg_temp(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_reservoir_avg_temp_fget, self->data_ptr);
}

static PyObject *
Outputs_get_reservoir_pressure(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_reservoir_pressure_fget, self->data_ptr);
}

static PyObject *
Outputs_get_spec_vol(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_spec_vol_fget, self->data_ptr);
}

static PyObject *
Outputs_get_spec_vol_lp(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_spec_vol_lp_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_lifetime_recapitalize(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_system_lifetime_recapitalize_aget, self->data_ptr);
}

static PyObject *
Outputs_get_timestep_dry_bulb(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_timestep_dry_bulb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_timestep_power(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_timestep_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_timestep_pressure(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_timestep_pressure_aget, self->data_ptr);
}

static PyObject *
Outputs_get_timestep_resource_temperature(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_timestep_resource_temperature_aget, self->data_ptr);
}

static PyObject *
Outputs_get_timestep_test_values(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_timestep_test_values_aget, self->data_ptr);
}

static PyObject *
Outputs_get_timestep_wet_bulb(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Geothermal_Outputs_timestep_wet_bulb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_v_stage_1(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_v_stage_1_fget, self->data_ptr);
}

static PyObject *
Outputs_get_v_stage_2(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_v_stage_2_fget, self->data_ptr);
}

static PyObject *
Outputs_get_v_stage_3(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_v_stage_3_fget, self->data_ptr);
}

static PyObject *
Outputs_get_x_hp(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_x_hp_fget, self->data_ptr);
}

static PyObject *
Outputs_get_x_lp(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Geothermal_Outputs_x_lp_fget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"GF_flowrate", (getter)Outputs_get_GF_flowrate,(setter)0,
	"GF Flow Rate [lb/h], number.",
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	"Annual Energy [kWh], number.",
 	NULL},
{"bottom_hole_pressure", (getter)Outputs_get_bottom_hole_pressure,(setter)0,
	"Bottom hole pres calculated by GETEM [], number.",
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	"Capacity factor [], number.",
 	NULL},
{"condensate_pump_power", (getter)Outputs_get_condensate_pump_power,(setter)0,
	"hp [], number.",
 	NULL},
{"cw_pump_head", (getter)Outputs_get_cw_pump_head,(setter)0,
	"Cooling Water Pump Head [lb/h], number.",
 	NULL},
{"cw_pump_work", (getter)Outputs_get_cw_pump_work,(setter)0,
	"CW Pump Work [kW], number.",
 	NULL},
{"cwflow", (getter)Outputs_get_cwflow,(setter)0,
	"Cooling Water Flow [lb/h], number.",
 	NULL},
{"eff_secondlaw", (getter)Outputs_get_eff_secondlaw,(setter)0,
	"Second Law Efficiency [C], number.",
 	NULL},
{"first_year_output", (getter)Outputs_get_first_year_output,(setter)0,
	"First Year Output [kWh], number.",
 	NULL},
{"flash_count", (getter)Outputs_get_flash_count,(setter)0,
	"Flash Count [(1 -2)], number.",
 	NULL},
{"gross_output", (getter)Outputs_get_gross_output,(setter)0,
	"Gross output from GETEM [], number.",
 	NULL},
{"hp_flash_pressure", (getter)Outputs_get_hp_flash_pressure,(setter)0,
	"HP Flash Pressure [psia], number.",
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	"First year kWh/kW [], number.",
 	NULL},
{"lifetime_output", (getter)Outputs_get_lifetime_output,(setter)0,
	"Lifetime Output [kWh], number.",
 	NULL},
{"lp_flash_pressure", (getter)Outputs_get_lp_flash_pressure,(setter)0,
	"LP Flash Pressure [psia], number.",
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	"Monthly energy before performance adjustments [kWh], array.",
 	NULL},
{"monthly_power", (getter)Outputs_get_monthly_power,(setter)0,
	"Monthly power [kW], array.",
 	NULL},
{"monthly_resource_temperature", (getter)Outputs_get_monthly_resource_temperature,(setter)0,
	"Monthly avg resource temperature [C], array.",
 	NULL},
{"ncg_condensate_pump", (getter)Outputs_get_ncg_condensate_pump,(setter)0,
	"Condensate Pump Work [kW], number.",
 	NULL},
{"num_wells_getem_output", (getter)Outputs_get_num_wells_getem_output,(setter)0,
	"Number of wells calculated by GETEM [], number.",
 	NULL},
{"plant_brine_eff", (getter)Outputs_get_plant_brine_eff,(setter)0,
	"Plant Brine Efficiency [], number.",
 	NULL},
{"pressure_ratio_1", (getter)Outputs_get_pressure_ratio_1,(setter)0,
	"Suction Steam Ratio 1 [], number.",
 	NULL},
{"pressure_ratio_2", (getter)Outputs_get_pressure_ratio_2,(setter)0,
	"Suction Steam Ratio 2 [], number.",
 	NULL},
{"pressure_ratio_3", (getter)Outputs_get_pressure_ratio_3,(setter)0,
	"Suction Steam Ratio 3 [], number.",
 	NULL},
{"pump_depth_ft", (getter)Outputs_get_pump_depth_ft,(setter)0,
	"Pump depth calculated by GETEM [ft], number.",
 	NULL},
{"pump_hp", (getter)Outputs_get_pump_hp,(setter)0,
	"Pump hp calculated by GETEM [hp], number.",
 	NULL},
{"pump_work", (getter)Outputs_get_pump_work,(setter)0,
	"Pump work calculated by GETEM [MW], number.",
 	NULL},
{"qCondenser", (getter)Outputs_get_qCondenser,(setter)0,
	"Condenser Heat Rejected [btu/h], number.",
 	NULL},
{"qRejectByStage_1", (getter)Outputs_get_qRejectByStage_1,(setter)0,
	"Heat Rejected by NCG Condenser Stage 1 [BTU/h], number.",
 	NULL},
{"qRejectByStage_2", (getter)Outputs_get_qRejectByStage_2,(setter)0,
	"Heat Rejected by NCG Condenser Stage 2 [BTU/h], number.",
 	NULL},
{"qRejectByStage_3", (getter)Outputs_get_qRejectByStage_3,(setter)0,
	"Heat Rejected by NCG Condenser Stage 3 [BTU/h], number.",
 	NULL},
{"qRejectTotal", (getter)Outputs_get_qRejectTotal,(setter)0,
	"Total Heat Rejection [btu/h], number.",
 	NULL},
{"reservoir_avg_temp", (getter)Outputs_get_reservoir_avg_temp,(setter)0,
	"Avg reservoir temp calculated by GETEM [C], number.",
 	NULL},
{"reservoir_pressure", (getter)Outputs_get_reservoir_pressure,(setter)0,
	"Reservoir pres calculated by GETEM [], number.",
 	NULL},
{"spec_vol", (getter)Outputs_get_spec_vol,(setter)0,
	"HP Specific Volume [cft/lb], number.",
 	NULL},
{"spec_vol_lp", (getter)Outputs_get_spec_vol_lp,(setter)0,
	"LP Specific Volume [cft/lb], number.",
 	NULL},
{"system_lifetime_recapitalize", (getter)Outputs_get_system_lifetime_recapitalize,(setter)0,
	"Resource replacement? (1=yes) [], array.",
 	NULL},
{"timestep_dry_bulb", (getter)Outputs_get_timestep_dry_bulb,(setter)0,
	"Dry bulb temperature in each time step [C], array.",
 	NULL},
{"timestep_power", (getter)Outputs_get_timestep_power,(setter)0,
	"Power in each time step [kW], array.",
 	NULL},
{"timestep_pressure", (getter)Outputs_get_timestep_pressure,(setter)0,
	"Atmospheric pressure in each time step [atm], array.",
 	NULL},
{"timestep_resource_temperature", (getter)Outputs_get_timestep_resource_temperature,(setter)0,
	"Resource temperature in each time step [C], array.",
 	NULL},
{"timestep_test_values", (getter)Outputs_get_timestep_test_values,(setter)0,
	"Test output values in each time step [], array.",
 	NULL},
{"timestep_wet_bulb", (getter)Outputs_get_timestep_wet_bulb,(setter)0,
	"Wet bulb temperature in each time step [C], array.",
 	NULL},
{"v_stage_1", (getter)Outputs_get_v_stage_1,(setter)0,
	"Vacumm Pump Stage 1 [kW], number.",
 	NULL},
{"v_stage_2", (getter)Outputs_get_v_stage_2,(setter)0,
	"Vacumm Pump Stage 2 [kW], number.",
 	NULL},
{"v_stage_3", (getter)Outputs_get_v_stage_3,(setter)0,
	"Vacumm Pump Stage 3 [kW], number.",
 	NULL},
{"x_hp", (getter)Outputs_get_x_hp,(setter)0,
	"HP Mass Fraction [%], number.",
 	NULL},
{"x_lp", (getter)Outputs_get_x_lp,(setter)0,
	"LP Mass Fraction [%], number.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Geothermal.Outputs",             /*tp_name*/
		sizeof(OutputsObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Outputs_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Outputs_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};

/*
 * Geothermal
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_Geothermal   data_ptr;
} GeothermalObject;

static PyTypeObject Geothermal_Type;

#define GeothermalObject_Check(v)      (Py_TYPE(v) == &Geothermal_Type)

static GeothermalObject *
newGeothermalObject(void* data_ptr)
{
	GeothermalObject *self;
	self = PyObject_New(GeothermalObject, &Geothermal_Type);

	PySAM_TECH_ATTR("Geothermal", SAM_Geothermal_construct)

PyObject* GeoHourly_obj = GeoHourly_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "GeoHourly", GeoHourly_obj);
	Py_DECREF(GeoHourly_obj);

PyObject* Weather_obj = Weather_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Weather", Weather_obj);
	Py_DECREF(Weather_obj);

PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

PyObject* AdjustmentFactorsModule = PyImport_ImportModule("AdjustmentFactors");

	PyObject* data_cap = PyCapsule_New(self->data_ptr, NULL, NULL);
	PyObject* Adjust_obj = PyObject_CallMethod(AdjustmentFactorsModule, "new", "(O)", data_cap);
	Py_XDECREF(data_cap);
	Py_XDECREF(AdjustmentFactorsModule);

	if (!Adjust_obj){
		PyErr_SetString(PySAM_ErrorObject, "Couldn't create AdjustmentFactorsObject\n");
		return NULL;
	}

	PyDict_SetItemString(attr_dict, "AdjustmentFactors", Adjust_obj);
	Py_DECREF(Adjust_obj);

	return self;
}

/* Geothermal methods */

static void
Geothermal_dealloc(GeothermalObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_Geothermal_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
Geothermal_execute(GeothermalObject *self, PyObject *args)
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
Geothermal_assign(GeothermalObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict(self, self->x_attr, self->data_ptr, dict, "Geothermal"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Geothermal_export(GeothermalObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}


static PyMethodDef Geothermal_methods[] = {
		{"execute",            (PyCFunction)Geothermal_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Geothermal_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs")},
		{"export",            (PyCFunction)Geothermal_export,  METH_VARARGS,
				PyDoc_STR("assign() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Geothermal_getattro(GeothermalObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Geothermal_setattr(GeothermalObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Geothermal_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Geothermal",            /*tp_name*/
		sizeof(GeothermalObject),/*tp_basicsize*/
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
		"see html for help",        /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Geothermal_methods,      /*tp_methods*/
		0,                          /*tp_members*/
		0,       /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
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
	GeothermalObject *rv;
	rv = newGeothermalObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Geothermal_wrap(PyObject *self, PyObject *args)
{
	GeothermalObject *rv;
	long int ptr = 0;
	if (!PyArg_ParseTuple(args, "l:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newGeothermalObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Geothermal_default(PyObject *self, PyObject *args)
{
	GeothermalObject *rv;
	char* fin = 0;
	if (!PyArg_ParseTuple(args, "s:default", &fin)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newGeothermalObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults(rv, rv->x_attr, rv->data_ptr, "Geothermal", fin);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef GeothermalModule_methods[] = {
		{"new",             Geothermal_new,         METH_VARARGS,
				PyDoc_STR("new() -> new Geothermal object")},
		{"wrap",             Geothermal_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> new Geothermal object around existing data")},
		{"default",             Geothermal_default,         METH_VARARGS,
				PyDoc_STR("default(financial) -> new Geothermal object with financial model-specific default attributes")},		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "This is a template module just for instruction.");


static int
GeothermalModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

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

	/// Add the Weather type object to Geothermal_Type
	if (PyType_Ready(&Weather_Type) < 0) { goto fail; }
	PyDict_SetItemString(Geothermal_Type.tp_dict,
				"Weather",
				(PyObject*)&Weather_Type);
	Py_DECREF(&Weather_Type);

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

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error() < 0) goto fail;

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