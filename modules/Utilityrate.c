#include <Python.h>

#include <SAM_Utilityrate.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Common Group
 */ 

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_Utilityrate data_ptr)
{
	PyObject* new_obj = Common_Type.tp_alloc(&Common_Type,0);

	VarGroupObject* Common_obj = (VarGroupObject*)new_obj;

	Common_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Common methods */

static PyObject *
Common_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate", "Common")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Common_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Common_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Common_methods[] = {
		{"assign",            (PyCFunction)Common_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Common_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Common_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Common_get_analysis_period(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_analysis_period_nget, self->data_ptr);
}

static int
Common_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_analysis_period_nset, self->data_ptr);
}

static PyObject *
Common_get_e_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Common_e_with_system_aget, self->data_ptr);
}

static int
Common_set_e_with_system(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate_Common_e_with_system_aset, self->data_ptr);
}

static PyObject *
Common_get_e_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Common_e_without_system_aget, self->data_ptr);
}

static int
Common_set_e_without_system(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate_Common_e_without_system_aset, self->data_ptr);
}

static PyObject *
Common_get_load_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Common_load_escalation_aget, self->data_ptr);
}

static int
Common_set_load_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate_Common_load_escalation_aset, self->data_ptr);
}

static PyObject *
Common_get_p_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Common_p_with_system_aget, self->data_ptr);
}

static int
Common_set_p_with_system(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate_Common_p_with_system_aset, self->data_ptr);
}

static PyObject *
Common_get_p_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Common_p_without_system_aget, self->data_ptr);
}

static int
Common_set_p_without_system(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate_Common_p_without_system_aset, self->data_ptr);
}

static PyObject *
Common_get_rate_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Common_rate_escalation_aget, self->data_ptr);
}

static int
Common_set_rate_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate_Common_rate_escalation_aset, self->data_ptr);
}

static PyObject *
Common_get_system_availability(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Common_system_availability_aget, self->data_ptr);
}

static int
Common_set_system_availability(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate_Common_system_availability_aset, self->data_ptr);
}

static PyObject *
Common_get_system_degradation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Common_system_degradation_aget, self->data_ptr);
}

static int
Common_set_system_degradation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate_Common_system_degradation_aset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_enable_nget, self->data_ptr);
}

static int
Common_set_ur_dc_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_enable_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_fixed_m1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_fixed_m1_nget, self->data_ptr);
}

static int
Common_set_ur_dc_fixed_m1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_fixed_m1_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_fixed_m10(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_fixed_m10_nget, self->data_ptr);
}

static int
Common_set_ur_dc_fixed_m10(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_fixed_m10_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_fixed_m11(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_fixed_m11_nget, self->data_ptr);
}

static int
Common_set_ur_dc_fixed_m11(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_fixed_m11_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_fixed_m12(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_fixed_m12_nget, self->data_ptr);
}

static int
Common_set_ur_dc_fixed_m12(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_fixed_m12_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_fixed_m2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_fixed_m2_nget, self->data_ptr);
}

static int
Common_set_ur_dc_fixed_m2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_fixed_m2_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_fixed_m3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_fixed_m3_nget, self->data_ptr);
}

static int
Common_set_ur_dc_fixed_m3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_fixed_m3_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_fixed_m4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_fixed_m4_nget, self->data_ptr);
}

static int
Common_set_ur_dc_fixed_m4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_fixed_m4_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_fixed_m5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_fixed_m5_nget, self->data_ptr);
}

static int
Common_set_ur_dc_fixed_m5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_fixed_m5_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_fixed_m6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_fixed_m6_nget, self->data_ptr);
}

static int
Common_set_ur_dc_fixed_m6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_fixed_m6_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_fixed_m7(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_fixed_m7_nget, self->data_ptr);
}

static int
Common_set_ur_dc_fixed_m7(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_fixed_m7_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_fixed_m8(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_fixed_m8_nget, self->data_ptr);
}

static int
Common_set_ur_dc_fixed_m8(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_fixed_m8_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_fixed_m9(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_fixed_m9_nget, self->data_ptr);
}

static int
Common_set_ur_dc_fixed_m9(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_fixed_m9_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_p1_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_p1_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_p2_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_p2_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_p3_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_p3_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_p4_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_p4_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_p5_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_p5_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_p6_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_p6_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_p7_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_p7_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_p8_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_p8_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_dc_p9_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_dc_p9_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Utilityrate_Common_ur_dc_sched_weekday_sget, self->data_ptr);
}

static int
Common_set_ur_dc_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Utilityrate_Common_ur_dc_sched_weekday_sset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Utilityrate_Common_ur_dc_sched_weekend_sget, self->data_ptr);
}

static int
Common_set_ur_dc_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Utilityrate_Common_ur_dc_sched_weekend_sset, self->data_ptr);
}

static PyObject *
Common_get_ur_flat_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_flat_buy_rate_nget, self->data_ptr);
}

static int
Common_set_ur_flat_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_flat_buy_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_flat_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_flat_sell_rate_nget, self->data_ptr);
}

static int
Common_set_ur_flat_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_flat_sell_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_monthly_fixed_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_monthly_fixed_charge_nget, self->data_ptr);
}

static int
Common_set_ur_monthly_fixed_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_monthly_fixed_charge_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_sell_eq_buy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_sell_eq_buy_nget, self->data_ptr);
}

static int
Common_set_ur_sell_eq_buy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_sell_eq_buy_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tou_enable_nget, self->data_ptr);
}

static int
Common_set_ur_tou_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tou_enable_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_p1_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tou_p1_buy_rate_nget, self->data_ptr);
}

static int
Common_set_ur_tou_p1_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tou_p1_buy_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_p1_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tou_p1_sell_rate_nget, self->data_ptr);
}

static int
Common_set_ur_tou_p1_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tou_p1_sell_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_p2_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tou_p2_buy_rate_nget, self->data_ptr);
}

static int
Common_set_ur_tou_p2_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tou_p2_buy_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_p2_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tou_p2_sell_rate_nget, self->data_ptr);
}

static int
Common_set_ur_tou_p2_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tou_p2_sell_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_p3_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tou_p3_buy_rate_nget, self->data_ptr);
}

static int
Common_set_ur_tou_p3_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tou_p3_buy_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_p3_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tou_p3_sell_rate_nget, self->data_ptr);
}

static int
Common_set_ur_tou_p3_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tou_p3_sell_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_p4_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tou_p4_buy_rate_nget, self->data_ptr);
}

static int
Common_set_ur_tou_p4_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tou_p4_buy_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_p4_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tou_p4_sell_rate_nget, self->data_ptr);
}

static int
Common_set_ur_tou_p4_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tou_p4_sell_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_p5_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tou_p5_buy_rate_nget, self->data_ptr);
}

static int
Common_set_ur_tou_p5_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tou_p5_buy_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_p5_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tou_p5_sell_rate_nget, self->data_ptr);
}

static int
Common_set_ur_tou_p5_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tou_p5_sell_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_p6_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tou_p6_buy_rate_nget, self->data_ptr);
}

static int
Common_set_ur_tou_p6_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tou_p6_buy_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_p6_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tou_p6_sell_rate_nget, self->data_ptr);
}

static int
Common_set_ur_tou_p6_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tou_p6_sell_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_p7_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tou_p7_buy_rate_nget, self->data_ptr);
}

static int
Common_set_ur_tou_p7_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tou_p7_buy_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_p7_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tou_p7_sell_rate_nget, self->data_ptr);
}

static int
Common_set_ur_tou_p7_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tou_p7_sell_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_p8_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tou_p8_buy_rate_nget, self->data_ptr);
}

static int
Common_set_ur_tou_p8_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tou_p8_buy_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_p8_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tou_p8_sell_rate_nget, self->data_ptr);
}

static int
Common_set_ur_tou_p8_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tou_p8_sell_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_p9_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tou_p9_buy_rate_nget, self->data_ptr);
}

static int
Common_set_ur_tou_p9_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tou_p9_buy_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_p9_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tou_p9_sell_rate_nget, self->data_ptr);
}

static int
Common_set_ur_tou_p9_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tou_p9_sell_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Utilityrate_Common_ur_tou_sched_weekday_sget, self->data_ptr);
}

static int
Common_set_ur_tou_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Utilityrate_Common_ur_tou_sched_weekday_sset, self->data_ptr);
}

static PyObject *
Common_get_ur_tou_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Utilityrate_Common_ur_tou_sched_weekend_sget, self->data_ptr);
}

static int
Common_set_ur_tou_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Utilityrate_Common_ur_tou_sched_weekend_sset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_enable_nget, self->data_ptr);
}

static int
Common_set_ur_tr_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_enable_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s1_energy_ub1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s1_energy_ub1_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s1_energy_ub1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s1_energy_ub1_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s1_energy_ub2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s1_energy_ub2_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s1_energy_ub2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s1_energy_ub2_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s1_energy_ub3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s1_energy_ub3_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s1_energy_ub3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s1_energy_ub3_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s1_energy_ub4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s1_energy_ub4_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s1_energy_ub4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s1_energy_ub4_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s1_energy_ub5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s1_energy_ub5_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s1_energy_ub5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s1_energy_ub5_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s1_energy_ub6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s1_energy_ub6_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s1_energy_ub6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s1_energy_ub6_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s1_rate1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s1_rate1_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s1_rate1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s1_rate1_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s1_rate2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s1_rate2_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s1_rate2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s1_rate2_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s1_rate3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s1_rate3_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s1_rate3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s1_rate3_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s1_rate4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s1_rate4_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s1_rate4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s1_rate4_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s1_rate5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s1_rate5_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s1_rate5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s1_rate5_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s1_rate6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s1_rate6_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s1_rate6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s1_rate6_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s2_energy_ub1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s2_energy_ub1_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s2_energy_ub1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s2_energy_ub1_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s2_energy_ub2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s2_energy_ub2_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s2_energy_ub2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s2_energy_ub2_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s2_energy_ub3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s2_energy_ub3_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s2_energy_ub3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s2_energy_ub3_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s2_energy_ub4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s2_energy_ub4_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s2_energy_ub4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s2_energy_ub4_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s2_energy_ub5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s2_energy_ub5_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s2_energy_ub5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s2_energy_ub5_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s2_energy_ub6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s2_energy_ub6_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s2_energy_ub6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s2_energy_ub6_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s2_rate1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s2_rate1_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s2_rate1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s2_rate1_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s2_rate2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s2_rate2_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s2_rate2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s2_rate2_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s2_rate3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s2_rate3_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s2_rate3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s2_rate3_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s2_rate4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s2_rate4_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s2_rate4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s2_rate4_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s2_rate5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s2_rate5_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s2_rate5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s2_rate5_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s2_rate6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s2_rate6_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s2_rate6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s2_rate6_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s3_energy_ub1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s3_energy_ub1_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s3_energy_ub1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s3_energy_ub1_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s3_energy_ub2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s3_energy_ub2_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s3_energy_ub2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s3_energy_ub2_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s3_energy_ub3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s3_energy_ub3_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s3_energy_ub3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s3_energy_ub3_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s3_energy_ub4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s3_energy_ub4_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s3_energy_ub4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s3_energy_ub4_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s3_energy_ub5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s3_energy_ub5_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s3_energy_ub5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s3_energy_ub5_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s3_energy_ub6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s3_energy_ub6_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s3_energy_ub6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s3_energy_ub6_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s3_rate1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s3_rate1_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s3_rate1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s3_rate1_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s3_rate2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s3_rate2_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s3_rate2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s3_rate2_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s3_rate3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s3_rate3_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s3_rate3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s3_rate3_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s3_rate4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s3_rate4_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s3_rate4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s3_rate4_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s3_rate5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s3_rate5_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s3_rate5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s3_rate5_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s3_rate6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s3_rate6_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s3_rate6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s3_rate6_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s4_energy_ub1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s4_energy_ub1_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s4_energy_ub1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s4_energy_ub1_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s4_energy_ub2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s4_energy_ub2_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s4_energy_ub2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s4_energy_ub2_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s4_energy_ub3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s4_energy_ub3_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s4_energy_ub3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s4_energy_ub3_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s4_energy_ub4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s4_energy_ub4_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s4_energy_ub4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s4_energy_ub4_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s4_energy_ub5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s4_energy_ub5_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s4_energy_ub5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s4_energy_ub5_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s4_energy_ub6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s4_energy_ub6_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s4_energy_ub6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s4_energy_ub6_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s4_rate1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s4_rate1_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s4_rate1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s4_rate1_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s4_rate2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s4_rate2_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s4_rate2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s4_rate2_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s4_rate3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s4_rate3_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s4_rate3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s4_rate3_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s4_rate4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s4_rate4_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s4_rate4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s4_rate4_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s4_rate5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s4_rate5_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s4_rate5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s4_rate5_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s4_rate6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s4_rate6_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s4_rate6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s4_rate6_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s5_energy_ub1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s5_energy_ub1_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s5_energy_ub1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s5_energy_ub1_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s5_energy_ub2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s5_energy_ub2_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s5_energy_ub2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s5_energy_ub2_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s5_energy_ub3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s5_energy_ub3_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s5_energy_ub3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s5_energy_ub3_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s5_energy_ub4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s5_energy_ub4_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s5_energy_ub4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s5_energy_ub4_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s5_energy_ub5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s5_energy_ub5_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s5_energy_ub5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s5_energy_ub5_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s5_energy_ub6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s5_energy_ub6_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s5_energy_ub6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s5_energy_ub6_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s5_rate1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s5_rate1_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s5_rate1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s5_rate1_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s5_rate2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s5_rate2_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s5_rate2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s5_rate2_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s5_rate3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s5_rate3_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s5_rate3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s5_rate3_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s5_rate4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s5_rate4_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s5_rate4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s5_rate4_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s5_rate5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s5_rate5_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s5_rate5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s5_rate5_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s5_rate6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s5_rate6_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s5_rate6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s5_rate6_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s6_energy_ub1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s6_energy_ub1_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s6_energy_ub1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s6_energy_ub1_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s6_energy_ub2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s6_energy_ub2_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s6_energy_ub2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s6_energy_ub2_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s6_energy_ub3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s6_energy_ub3_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s6_energy_ub3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s6_energy_ub3_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s6_energy_ub4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s6_energy_ub4_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s6_energy_ub4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s6_energy_ub4_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s6_energy_ub5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s6_energy_ub5_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s6_energy_ub5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s6_energy_ub5_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s6_energy_ub6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s6_energy_ub6_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s6_energy_ub6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s6_energy_ub6_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s6_rate1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s6_rate1_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s6_rate1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s6_rate1_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s6_rate2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s6_rate2_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s6_rate2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s6_rate2_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s6_rate3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s6_rate3_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s6_rate3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s6_rate3_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s6_rate4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s6_rate4_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s6_rate4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s6_rate4_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s6_rate5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s6_rate5_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s6_rate5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s6_rate5_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_s6_rate6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_s6_rate6_nget, self->data_ptr);
}

static int
Common_set_ur_tr_s6_rate6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_s6_rate6_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_sched_m1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_sched_m1_nget, self->data_ptr);
}

static int
Common_set_ur_tr_sched_m1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_sched_m1_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_sched_m10(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_sched_m10_nget, self->data_ptr);
}

static int
Common_set_ur_tr_sched_m10(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_sched_m10_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_sched_m11(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_sched_m11_nget, self->data_ptr);
}

static int
Common_set_ur_tr_sched_m11(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_sched_m11_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_sched_m12(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_sched_m12_nget, self->data_ptr);
}

static int
Common_set_ur_tr_sched_m12(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_sched_m12_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_sched_m2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_sched_m2_nget, self->data_ptr);
}

static int
Common_set_ur_tr_sched_m2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_sched_m2_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_sched_m3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_sched_m3_nget, self->data_ptr);
}

static int
Common_set_ur_tr_sched_m3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_sched_m3_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_sched_m4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_sched_m4_nget, self->data_ptr);
}

static int
Common_set_ur_tr_sched_m4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_sched_m4_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_sched_m5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_sched_m5_nget, self->data_ptr);
}

static int
Common_set_ur_tr_sched_m5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_sched_m5_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_sched_m6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_sched_m6_nget, self->data_ptr);
}

static int
Common_set_ur_tr_sched_m6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_sched_m6_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_sched_m7(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_sched_m7_nget, self->data_ptr);
}

static int
Common_set_ur_tr_sched_m7(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_sched_m7_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_sched_m8(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_sched_m8_nget, self->data_ptr);
}

static int
Common_set_ur_tr_sched_m8(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_sched_m8_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_sched_m9(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_sched_m9_nget, self->data_ptr);
}

static int
Common_set_ur_tr_sched_m9(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_sched_m9_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_sell_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_sell_mode_nget, self->data_ptr);
}

static int
Common_set_ur_tr_sell_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_sell_mode_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_tr_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate_Common_ur_tr_sell_rate_nget, self->data_ptr);
}

static int
Common_set_ur_tr_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate_Common_ur_tr_sell_rate_nset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"analysis_period", (getter)Common_get_analysis_period,(setter)Common_set_analysis_period,
	PyDoc_STR("*float*: Number of years in analysis [years]\n\n*Constraints*: INTEGER,POSITIVE\n\n*Required*: True"),
 	NULL},
{"e_with_system", (getter)Common_get_e_with_system,(setter)Common_set_e_with_system,
	PyDoc_STR("*sequence*: Energy at grid with system [kWh]\n\n*Constraints*: LENGTH=8760\n\n*Required*: True"),
 	NULL},
{"e_without_system", (getter)Common_get_e_without_system,(setter)Common_set_e_without_system,
	PyDoc_STR("*sequence*: Energy at grid without system (load only) [kWh]\n\n*Constraints*: LENGTH=8760\n\n*Required*: False"),
 	NULL},
{"load_escalation", (getter)Common_get_load_escalation,(setter)Common_set_load_escalation,
	PyDoc_STR("*sequence*: Annual load escalation [%/year]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"p_with_system", (getter)Common_get_p_with_system,(setter)Common_set_p_with_system,
	PyDoc_STR("*sequence*: Max power at grid with system [kW]\n\n*Constraints*: LENGTH=8760\n\n*Required*: False"),
 	NULL},
{"p_without_system", (getter)Common_get_p_without_system,(setter)Common_set_p_without_system,
	PyDoc_STR("*sequence*: Max power at grid without system (load only) [kW]\n\n*Constraints*: LENGTH=8760\n\n*Required*: False"),
 	NULL},
{"rate_escalation", (getter)Common_get_rate_escalation,(setter)Common_set_rate_escalation,
	PyDoc_STR("*sequence*: Annual utility rate escalation [%/year]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"system_availability", (getter)Common_get_system_availability,(setter)Common_set_system_availability,
	PyDoc_STR("*sequence*: Annual availability of system [%/year]\n\n*Required*: If not provided, assumed to be 100"),
 	NULL},
{"system_degradation", (getter)Common_get_system_degradation,(setter)Common_set_system_degradation,
	PyDoc_STR("*sequence*: Annual degradation of system [%/year]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ur_dc_enable", (getter)Common_get_ur_dc_enable,(setter)Common_set_ur_dc_enable,
	PyDoc_STR("*float*: Enable demand charges [0/1]\n\n*Constraints*: BOOLEAN\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ur_dc_fixed_m1", (getter)Common_get_ur_dc_fixed_m1,(setter)Common_set_ur_dc_fixed_m1,
	PyDoc_STR("*float*: DC fixed rate January [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_fixed_m10", (getter)Common_get_ur_dc_fixed_m10,(setter)Common_set_ur_dc_fixed_m10,
	PyDoc_STR("*float*: DC fixed rate October [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_fixed_m11", (getter)Common_get_ur_dc_fixed_m11,(setter)Common_set_ur_dc_fixed_m11,
	PyDoc_STR("*float*: DC fixed rate November [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_fixed_m12", (getter)Common_get_ur_dc_fixed_m12,(setter)Common_set_ur_dc_fixed_m12,
	PyDoc_STR("*float*: DC fixed rate December [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_fixed_m2", (getter)Common_get_ur_dc_fixed_m2,(setter)Common_set_ur_dc_fixed_m2,
	PyDoc_STR("*float*: DC fixed rate February [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_fixed_m3", (getter)Common_get_ur_dc_fixed_m3,(setter)Common_set_ur_dc_fixed_m3,
	PyDoc_STR("*float*: DC fixed rate March [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_fixed_m4", (getter)Common_get_ur_dc_fixed_m4,(setter)Common_set_ur_dc_fixed_m4,
	PyDoc_STR("*float*: DC fixed rate April [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_fixed_m5", (getter)Common_get_ur_dc_fixed_m5,(setter)Common_set_ur_dc_fixed_m5,
	PyDoc_STR("*float*: DC fixed rate May [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_fixed_m6", (getter)Common_get_ur_dc_fixed_m6,(setter)Common_set_ur_dc_fixed_m6,
	PyDoc_STR("*float*: DC fixed rate June [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_fixed_m7", (getter)Common_get_ur_dc_fixed_m7,(setter)Common_set_ur_dc_fixed_m7,
	PyDoc_STR("*float*: DC fixed rate July [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_fixed_m8", (getter)Common_get_ur_dc_fixed_m8,(setter)Common_set_ur_dc_fixed_m8,
	PyDoc_STR("*float*: DC fixed rate August [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_fixed_m9", (getter)Common_get_ur_dc_fixed_m9,(setter)Common_set_ur_dc_fixed_m9,
	PyDoc_STR("*float*: DC fixed rate September [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p1", (getter)Common_get_ur_dc_p1,(setter)Common_set_ur_dc_p1,
	PyDoc_STR("*float*: DC TOU rate period 1 [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p2", (getter)Common_get_ur_dc_p2,(setter)Common_set_ur_dc_p2,
	PyDoc_STR("*float*: DC TOU rate period 2 [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p3", (getter)Common_get_ur_dc_p3,(setter)Common_set_ur_dc_p3,
	PyDoc_STR("*float*: DC TOU rate period 3 [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p4", (getter)Common_get_ur_dc_p4,(setter)Common_set_ur_dc_p4,
	PyDoc_STR("*float*: DC TOU rate period 4 [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p5", (getter)Common_get_ur_dc_p5,(setter)Common_set_ur_dc_p5,
	PyDoc_STR("*float*: DC TOU rate period 5 [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p6", (getter)Common_get_ur_dc_p6,(setter)Common_set_ur_dc_p6,
	PyDoc_STR("*float*: DC TOU rate period 6 [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p7", (getter)Common_get_ur_dc_p7,(setter)Common_set_ur_dc_p7,
	PyDoc_STR("*float*: DC TOU rate period 7 [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p8", (getter)Common_get_ur_dc_p8,(setter)Common_set_ur_dc_p8,
	PyDoc_STR("*float*: DC TOU rate period 8 [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p9", (getter)Common_get_ur_dc_p9,(setter)Common_set_ur_dc_p9,
	PyDoc_STR("*float*: DC TOU rate period 9 [$/kW,pk]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_sched_weekday", (getter)Common_get_ur_dc_sched_weekday,(setter)Common_set_ur_dc_sched_weekday,
	PyDoc_STR("*str*: DC TOU weekday schedule\n\n*Info*: 288 digits 0-9, 24x12\n\n*Constraints*: TOUSCHED\n\n*Required*: True if ur_dc_enable=1"),
 	NULL},
{"ur_dc_sched_weekend", (getter)Common_get_ur_dc_sched_weekend,(setter)Common_set_ur_dc_sched_weekend,
	PyDoc_STR("*str*: DC TOU weekend schedule\n\n*Info*: 288 digits 0-9, 24x12\n\n*Constraints*: TOUSCHED\n\n*Required*: True if ur_dc_enable=1"),
 	NULL},
{"ur_flat_buy_rate", (getter)Common_get_ur_flat_buy_rate,(setter)Common_set_ur_flat_buy_rate,
	PyDoc_STR("*float*: Flat rate (buy) [$/kWh]\n\n*Required*: True"),
 	NULL},
{"ur_flat_sell_rate", (getter)Common_get_ur_flat_sell_rate,(setter)Common_set_ur_flat_sell_rate,
	PyDoc_STR("*float*: Flat rate (sell) [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_monthly_fixed_charge", (getter)Common_get_ur_monthly_fixed_charge,(setter)Common_set_ur_monthly_fixed_charge,
	PyDoc_STR("*float*: Monthly fixed charge [$]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_sell_eq_buy", (getter)Common_get_ur_sell_eq_buy,(setter)Common_set_ur_sell_eq_buy,
	PyDoc_STR("*float*: Force sell rate equal to buy [0/1]\n\n*Info*: Enforce net metering\n\n*Constraints*: BOOLEAN\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"ur_tou_enable", (getter)Common_get_ur_tou_enable,(setter)Common_set_ur_tou_enable,
	PyDoc_STR("*float*: Enable time-of-use rates [0/1]\n\n*Constraints*: BOOLEAN\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ur_tou_p1_buy_rate", (getter)Common_get_ur_tou_p1_buy_rate,(setter)Common_set_ur_tou_p1_buy_rate,
	PyDoc_STR("*float*: TOU period 1 rate (buy) [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tou_p1_sell_rate", (getter)Common_get_ur_tou_p1_sell_rate,(setter)Common_set_ur_tou_p1_sell_rate,
	PyDoc_STR("*float*: TOU period 1 rate (sell) [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tou_p2_buy_rate", (getter)Common_get_ur_tou_p2_buy_rate,(setter)Common_set_ur_tou_p2_buy_rate,
	PyDoc_STR("*float*: TOU period 2 rate (buy) [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tou_p2_sell_rate", (getter)Common_get_ur_tou_p2_sell_rate,(setter)Common_set_ur_tou_p2_sell_rate,
	PyDoc_STR("*float*: TOU period 2 rate (sell) [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tou_p3_buy_rate", (getter)Common_get_ur_tou_p3_buy_rate,(setter)Common_set_ur_tou_p3_buy_rate,
	PyDoc_STR("*float*: TOU period 3 rate (buy) [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tou_p3_sell_rate", (getter)Common_get_ur_tou_p3_sell_rate,(setter)Common_set_ur_tou_p3_sell_rate,
	PyDoc_STR("*float*: TOU period 3 rate (sell) [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tou_p4_buy_rate", (getter)Common_get_ur_tou_p4_buy_rate,(setter)Common_set_ur_tou_p4_buy_rate,
	PyDoc_STR("*float*: TOU period 4 rate (buy) [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tou_p4_sell_rate", (getter)Common_get_ur_tou_p4_sell_rate,(setter)Common_set_ur_tou_p4_sell_rate,
	PyDoc_STR("*float*: TOU period 4 rate (sell) [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tou_p5_buy_rate", (getter)Common_get_ur_tou_p5_buy_rate,(setter)Common_set_ur_tou_p5_buy_rate,
	PyDoc_STR("*float*: TOU period 5 rate (buy) [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tou_p5_sell_rate", (getter)Common_get_ur_tou_p5_sell_rate,(setter)Common_set_ur_tou_p5_sell_rate,
	PyDoc_STR("*float*: TOU period 5 rate (sell) [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tou_p6_buy_rate", (getter)Common_get_ur_tou_p6_buy_rate,(setter)Common_set_ur_tou_p6_buy_rate,
	PyDoc_STR("*float*: TOU period 6 rate (buy) [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tou_p6_sell_rate", (getter)Common_get_ur_tou_p6_sell_rate,(setter)Common_set_ur_tou_p6_sell_rate,
	PyDoc_STR("*float*: TOU period 6 rate (sell) [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tou_p7_buy_rate", (getter)Common_get_ur_tou_p7_buy_rate,(setter)Common_set_ur_tou_p7_buy_rate,
	PyDoc_STR("*float*: TOU period 7 rate (buy) [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tou_p7_sell_rate", (getter)Common_get_ur_tou_p7_sell_rate,(setter)Common_set_ur_tou_p7_sell_rate,
	PyDoc_STR("*float*: TOU period 7 rate (sell) [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tou_p8_buy_rate", (getter)Common_get_ur_tou_p8_buy_rate,(setter)Common_set_ur_tou_p8_buy_rate,
	PyDoc_STR("*float*: TOU period 8 rate (buy) [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tou_p8_sell_rate", (getter)Common_get_ur_tou_p8_sell_rate,(setter)Common_set_ur_tou_p8_sell_rate,
	PyDoc_STR("*float*: TOU period 8 rate (sell) [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tou_p9_buy_rate", (getter)Common_get_ur_tou_p9_buy_rate,(setter)Common_set_ur_tou_p9_buy_rate,
	PyDoc_STR("*float*: TOU period 9 rate (buy) [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tou_p9_sell_rate", (getter)Common_get_ur_tou_p9_sell_rate,(setter)Common_set_ur_tou_p9_sell_rate,
	PyDoc_STR("*float*: TOU period 9 rate (sell) [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tou_sched_weekday", (getter)Common_get_ur_tou_sched_weekday,(setter)Common_set_ur_tou_sched_weekday,
	PyDoc_STR("*str*: TOU weekday schedule\n\n*Info*: 288 digits 0-9, 24x12\n\n*Constraints*: TOUSCHED\n\n*Required*: True if ur_tou_enable=1"),
 	NULL},
{"ur_tou_sched_weekend", (getter)Common_get_ur_tou_sched_weekend,(setter)Common_set_ur_tou_sched_weekend,
	PyDoc_STR("*str*: TOU weekend schedule\n\n*Info*: 288 digits 0-9, 24x12\n\n*Constraints*: TOUSCHED\n\n*Required*: True if ur_tou_enable=1"),
 	NULL},
{"ur_tr_enable", (getter)Common_get_ur_tr_enable,(setter)Common_set_ur_tr_enable,
	PyDoc_STR("*float*: Enable tiered rates [0/1]\n\n*Constraints*: BOOLEAN\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ur_tr_s1_energy_ub1", (getter)Common_get_ur_tr_s1_energy_ub1,(setter)Common_set_ur_tr_s1_energy_ub1,
	PyDoc_STR("*float*: Tiered struct. 1 Energy UB 1 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s1_energy_ub2", (getter)Common_get_ur_tr_s1_energy_ub2,(setter)Common_set_ur_tr_s1_energy_ub2,
	PyDoc_STR("*float*: Tiered struct. 1 Energy UB 2 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s1_energy_ub3", (getter)Common_get_ur_tr_s1_energy_ub3,(setter)Common_set_ur_tr_s1_energy_ub3,
	PyDoc_STR("*float*: Tiered struct. 1 Energy UB 3 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s1_energy_ub4", (getter)Common_get_ur_tr_s1_energy_ub4,(setter)Common_set_ur_tr_s1_energy_ub4,
	PyDoc_STR("*float*: Tiered struct. 1 Energy UB 4 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s1_energy_ub5", (getter)Common_get_ur_tr_s1_energy_ub5,(setter)Common_set_ur_tr_s1_energy_ub5,
	PyDoc_STR("*float*: Tiered struct. 1 Energy UB 5 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s1_energy_ub6", (getter)Common_get_ur_tr_s1_energy_ub6,(setter)Common_set_ur_tr_s1_energy_ub6,
	PyDoc_STR("*float*: Tiered struct. 1 Energy UB 6 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s1_rate1", (getter)Common_get_ur_tr_s1_rate1,(setter)Common_set_ur_tr_s1_rate1,
	PyDoc_STR("*float*: Tiered struct. 1 Rate 1 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s1_rate2", (getter)Common_get_ur_tr_s1_rate2,(setter)Common_set_ur_tr_s1_rate2,
	PyDoc_STR("*float*: Tiered struct. 1 Rate 2 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s1_rate3", (getter)Common_get_ur_tr_s1_rate3,(setter)Common_set_ur_tr_s1_rate3,
	PyDoc_STR("*float*: Tiered struct. 1 Rate 3 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s1_rate4", (getter)Common_get_ur_tr_s1_rate4,(setter)Common_set_ur_tr_s1_rate4,
	PyDoc_STR("*float*: Tiered struct. 1 Rate 4 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s1_rate5", (getter)Common_get_ur_tr_s1_rate5,(setter)Common_set_ur_tr_s1_rate5,
	PyDoc_STR("*float*: Tiered struct. 1 Rate 5 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s1_rate6", (getter)Common_get_ur_tr_s1_rate6,(setter)Common_set_ur_tr_s1_rate6,
	PyDoc_STR("*float*: Tiered struct. 1 Rate 6 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s2_energy_ub1", (getter)Common_get_ur_tr_s2_energy_ub1,(setter)Common_set_ur_tr_s2_energy_ub1,
	PyDoc_STR("*float*: Tiered struct. 2 Energy UB 1 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s2_energy_ub2", (getter)Common_get_ur_tr_s2_energy_ub2,(setter)Common_set_ur_tr_s2_energy_ub2,
	PyDoc_STR("*float*: Tiered struct. 2 Energy UB 2 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s2_energy_ub3", (getter)Common_get_ur_tr_s2_energy_ub3,(setter)Common_set_ur_tr_s2_energy_ub3,
	PyDoc_STR("*float*: Tiered struct. 2 Energy UB 3 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s2_energy_ub4", (getter)Common_get_ur_tr_s2_energy_ub4,(setter)Common_set_ur_tr_s2_energy_ub4,
	PyDoc_STR("*float*: Tiered struct. 2 Energy UB 4 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s2_energy_ub5", (getter)Common_get_ur_tr_s2_energy_ub5,(setter)Common_set_ur_tr_s2_energy_ub5,
	PyDoc_STR("*float*: Tiered struct. 2 Energy UB 5 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s2_energy_ub6", (getter)Common_get_ur_tr_s2_energy_ub6,(setter)Common_set_ur_tr_s2_energy_ub6,
	PyDoc_STR("*float*: Tiered struct. 2 Energy UB 6 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s2_rate1", (getter)Common_get_ur_tr_s2_rate1,(setter)Common_set_ur_tr_s2_rate1,
	PyDoc_STR("*float*: Tiered struct. 2 Rate 1 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s2_rate2", (getter)Common_get_ur_tr_s2_rate2,(setter)Common_set_ur_tr_s2_rate2,
	PyDoc_STR("*float*: Tiered struct. 2 Rate 2 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s2_rate3", (getter)Common_get_ur_tr_s2_rate3,(setter)Common_set_ur_tr_s2_rate3,
	PyDoc_STR("*float*: Tiered struct. 2 Rate 3 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s2_rate4", (getter)Common_get_ur_tr_s2_rate4,(setter)Common_set_ur_tr_s2_rate4,
	PyDoc_STR("*float*: Tiered struct. 2 Rate 4 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s2_rate5", (getter)Common_get_ur_tr_s2_rate5,(setter)Common_set_ur_tr_s2_rate5,
	PyDoc_STR("*float*: Tiered struct. 2 Rate 5 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s2_rate6", (getter)Common_get_ur_tr_s2_rate6,(setter)Common_set_ur_tr_s2_rate6,
	PyDoc_STR("*float*: Tiered struct. 2 Rate 6 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s3_energy_ub1", (getter)Common_get_ur_tr_s3_energy_ub1,(setter)Common_set_ur_tr_s3_energy_ub1,
	PyDoc_STR("*float*: Tiered struct. 3 Energy UB 1 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s3_energy_ub2", (getter)Common_get_ur_tr_s3_energy_ub2,(setter)Common_set_ur_tr_s3_energy_ub2,
	PyDoc_STR("*float*: Tiered struct. 3 Energy UB 2 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s3_energy_ub3", (getter)Common_get_ur_tr_s3_energy_ub3,(setter)Common_set_ur_tr_s3_energy_ub3,
	PyDoc_STR("*float*: Tiered struct. 3 Energy UB 3 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s3_energy_ub4", (getter)Common_get_ur_tr_s3_energy_ub4,(setter)Common_set_ur_tr_s3_energy_ub4,
	PyDoc_STR("*float*: Tiered struct. 3 Energy UB 4 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s3_energy_ub5", (getter)Common_get_ur_tr_s3_energy_ub5,(setter)Common_set_ur_tr_s3_energy_ub5,
	PyDoc_STR("*float*: Tiered struct. 3 Energy UB 5 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s3_energy_ub6", (getter)Common_get_ur_tr_s3_energy_ub6,(setter)Common_set_ur_tr_s3_energy_ub6,
	PyDoc_STR("*float*: Tiered struct. 3 Energy UB 6 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s3_rate1", (getter)Common_get_ur_tr_s3_rate1,(setter)Common_set_ur_tr_s3_rate1,
	PyDoc_STR("*float*: Tiered struct. 3 Rate 1 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s3_rate2", (getter)Common_get_ur_tr_s3_rate2,(setter)Common_set_ur_tr_s3_rate2,
	PyDoc_STR("*float*: Tiered struct. 3 Rate 2 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s3_rate3", (getter)Common_get_ur_tr_s3_rate3,(setter)Common_set_ur_tr_s3_rate3,
	PyDoc_STR("*float*: Tiered struct. 3 Rate 3 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s3_rate4", (getter)Common_get_ur_tr_s3_rate4,(setter)Common_set_ur_tr_s3_rate4,
	PyDoc_STR("*float*: Tiered struct. 3 Rate 4 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s3_rate5", (getter)Common_get_ur_tr_s3_rate5,(setter)Common_set_ur_tr_s3_rate5,
	PyDoc_STR("*float*: Tiered struct. 3 Rate 5 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s3_rate6", (getter)Common_get_ur_tr_s3_rate6,(setter)Common_set_ur_tr_s3_rate6,
	PyDoc_STR("*float*: Tiered struct. 3 Rate 6 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s4_energy_ub1", (getter)Common_get_ur_tr_s4_energy_ub1,(setter)Common_set_ur_tr_s4_energy_ub1,
	PyDoc_STR("*float*: Tiered struct. 4 Energy UB 1 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s4_energy_ub2", (getter)Common_get_ur_tr_s4_energy_ub2,(setter)Common_set_ur_tr_s4_energy_ub2,
	PyDoc_STR("*float*: Tiered struct. 4 Energy UB 2 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s4_energy_ub3", (getter)Common_get_ur_tr_s4_energy_ub3,(setter)Common_set_ur_tr_s4_energy_ub3,
	PyDoc_STR("*float*: Tiered struct. 4 Energy UB 3 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s4_energy_ub4", (getter)Common_get_ur_tr_s4_energy_ub4,(setter)Common_set_ur_tr_s4_energy_ub4,
	PyDoc_STR("*float*: Tiered struct. 4 Energy UB 4 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s4_energy_ub5", (getter)Common_get_ur_tr_s4_energy_ub5,(setter)Common_set_ur_tr_s4_energy_ub5,
	PyDoc_STR("*float*: Tiered struct. 4 Energy UB 5 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s4_energy_ub6", (getter)Common_get_ur_tr_s4_energy_ub6,(setter)Common_set_ur_tr_s4_energy_ub6,
	PyDoc_STR("*float*: Tiered struct. 4 Energy UB 6 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s4_rate1", (getter)Common_get_ur_tr_s4_rate1,(setter)Common_set_ur_tr_s4_rate1,
	PyDoc_STR("*float*: Tiered struct. 4 Rate 1 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s4_rate2", (getter)Common_get_ur_tr_s4_rate2,(setter)Common_set_ur_tr_s4_rate2,
	PyDoc_STR("*float*: Tiered struct. 4 Rate 2 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s4_rate3", (getter)Common_get_ur_tr_s4_rate3,(setter)Common_set_ur_tr_s4_rate3,
	PyDoc_STR("*float*: Tiered struct. 4 Rate 3 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s4_rate4", (getter)Common_get_ur_tr_s4_rate4,(setter)Common_set_ur_tr_s4_rate4,
	PyDoc_STR("*float*: Tiered struct. 4 Rate 4 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s4_rate5", (getter)Common_get_ur_tr_s4_rate5,(setter)Common_set_ur_tr_s4_rate5,
	PyDoc_STR("*float*: Tiered struct. 4 Rate 5 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s4_rate6", (getter)Common_get_ur_tr_s4_rate6,(setter)Common_set_ur_tr_s4_rate6,
	PyDoc_STR("*float*: Tiered struct. 4 Rate 6 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s5_energy_ub1", (getter)Common_get_ur_tr_s5_energy_ub1,(setter)Common_set_ur_tr_s5_energy_ub1,
	PyDoc_STR("*float*: Tiered struct. 5 Energy UB 1 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s5_energy_ub2", (getter)Common_get_ur_tr_s5_energy_ub2,(setter)Common_set_ur_tr_s5_energy_ub2,
	PyDoc_STR("*float*: Tiered struct. 5 Energy UB 2 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s5_energy_ub3", (getter)Common_get_ur_tr_s5_energy_ub3,(setter)Common_set_ur_tr_s5_energy_ub3,
	PyDoc_STR("*float*: Tiered struct. 5 Energy UB 3 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s5_energy_ub4", (getter)Common_get_ur_tr_s5_energy_ub4,(setter)Common_set_ur_tr_s5_energy_ub4,
	PyDoc_STR("*float*: Tiered struct. 5 Energy UB 4 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s5_energy_ub5", (getter)Common_get_ur_tr_s5_energy_ub5,(setter)Common_set_ur_tr_s5_energy_ub5,
	PyDoc_STR("*float*: Tiered struct. 5 Energy UB 5 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s5_energy_ub6", (getter)Common_get_ur_tr_s5_energy_ub6,(setter)Common_set_ur_tr_s5_energy_ub6,
	PyDoc_STR("*float*: Tiered struct. 5 Energy UB 6 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s5_rate1", (getter)Common_get_ur_tr_s5_rate1,(setter)Common_set_ur_tr_s5_rate1,
	PyDoc_STR("*float*: Tiered struct. 5 Rate 1 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s5_rate2", (getter)Common_get_ur_tr_s5_rate2,(setter)Common_set_ur_tr_s5_rate2,
	PyDoc_STR("*float*: Tiered struct. 5 Rate 2 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s5_rate3", (getter)Common_get_ur_tr_s5_rate3,(setter)Common_set_ur_tr_s5_rate3,
	PyDoc_STR("*float*: Tiered struct. 5 Rate 3 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s5_rate4", (getter)Common_get_ur_tr_s5_rate4,(setter)Common_set_ur_tr_s5_rate4,
	PyDoc_STR("*float*: Tiered struct. 5 Rate 4 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s5_rate5", (getter)Common_get_ur_tr_s5_rate5,(setter)Common_set_ur_tr_s5_rate5,
	PyDoc_STR("*float*: Tiered struct. 5 Rate 5 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s5_rate6", (getter)Common_get_ur_tr_s5_rate6,(setter)Common_set_ur_tr_s5_rate6,
	PyDoc_STR("*float*: Tiered struct. 5 Rate 6 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s6_energy_ub1", (getter)Common_get_ur_tr_s6_energy_ub1,(setter)Common_set_ur_tr_s6_energy_ub1,
	PyDoc_STR("*float*: Tiered struct. 6 Energy UB 1 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s6_energy_ub2", (getter)Common_get_ur_tr_s6_energy_ub2,(setter)Common_set_ur_tr_s6_energy_ub2,
	PyDoc_STR("*float*: Tiered struct. 6 Energy UB 2 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s6_energy_ub3", (getter)Common_get_ur_tr_s6_energy_ub3,(setter)Common_set_ur_tr_s6_energy_ub3,
	PyDoc_STR("*float*: Tiered struct. 6 Energy UB 3 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s6_energy_ub4", (getter)Common_get_ur_tr_s6_energy_ub4,(setter)Common_set_ur_tr_s6_energy_ub4,
	PyDoc_STR("*float*: Tiered struct. 6 Energy UB 4 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s6_energy_ub5", (getter)Common_get_ur_tr_s6_energy_ub5,(setter)Common_set_ur_tr_s6_energy_ub5,
	PyDoc_STR("*float*: Tiered struct. 6 Energy UB 5 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s6_energy_ub6", (getter)Common_get_ur_tr_s6_energy_ub6,(setter)Common_set_ur_tr_s6_energy_ub6,
	PyDoc_STR("*float*: Tiered struct. 6 Energy UB 6 [kWh]\n\n*Required*: If not provided, assumed to be 1e99"),
 	NULL},
{"ur_tr_s6_rate1", (getter)Common_get_ur_tr_s6_rate1,(setter)Common_set_ur_tr_s6_rate1,
	PyDoc_STR("*float*: Tiered struct. 6 Rate 1 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s6_rate2", (getter)Common_get_ur_tr_s6_rate2,(setter)Common_set_ur_tr_s6_rate2,
	PyDoc_STR("*float*: Tiered struct. 6 Rate 2 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s6_rate3", (getter)Common_get_ur_tr_s6_rate3,(setter)Common_set_ur_tr_s6_rate3,
	PyDoc_STR("*float*: Tiered struct. 6 Rate 3 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s6_rate4", (getter)Common_get_ur_tr_s6_rate4,(setter)Common_set_ur_tr_s6_rate4,
	PyDoc_STR("*float*: Tiered struct. 6 Rate 4 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s6_rate5", (getter)Common_get_ur_tr_s6_rate5,(setter)Common_set_ur_tr_s6_rate5,
	PyDoc_STR("*float*: Tiered struct. 6 Rate 5 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_s6_rate6", (getter)Common_get_ur_tr_s6_rate6,(setter)Common_set_ur_tr_s6_rate6,
	PyDoc_STR("*float*: Tiered struct. 6 Rate 6 [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_tr_sched_m1", (getter)Common_get_ur_tr_sched_m1,(setter)Common_set_ur_tr_sched_m1,
	PyDoc_STR("*float*: Tiered structure for January [0-5]\n\n*Info*: tiered structure #\n\n*Constraints*: INTEGER,MIN=0,MAX=5\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ur_tr_sched_m10", (getter)Common_get_ur_tr_sched_m10,(setter)Common_set_ur_tr_sched_m10,
	PyDoc_STR("*float*: Tiered structure for October [0-5]\n\n*Info*: tiered structure #\n\n*Constraints*: INTEGER,MIN=0,MAX=5\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ur_tr_sched_m11", (getter)Common_get_ur_tr_sched_m11,(setter)Common_set_ur_tr_sched_m11,
	PyDoc_STR("*float*: Tiered structure for November [0-5]\n\n*Info*: tiered structure #\n\n*Constraints*: INTEGER,MIN=0,MAX=5\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ur_tr_sched_m12", (getter)Common_get_ur_tr_sched_m12,(setter)Common_set_ur_tr_sched_m12,
	PyDoc_STR("*float*: Tiered structure for December [0-5]\n\n*Info*: tiered structure #\n\n*Constraints*: INTEGER,MIN=0,MAX=5\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ur_tr_sched_m2", (getter)Common_get_ur_tr_sched_m2,(setter)Common_set_ur_tr_sched_m2,
	PyDoc_STR("*float*: Tiered structure for February [0-5]\n\n*Info*: tiered structure #\n\n*Constraints*: INTEGER,MIN=0,MAX=5\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ur_tr_sched_m3", (getter)Common_get_ur_tr_sched_m3,(setter)Common_set_ur_tr_sched_m3,
	PyDoc_STR("*float*: Tiered structure for March [0-5]\n\n*Info*: tiered structure #\n\n*Constraints*: INTEGER,MIN=0,MAX=5\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ur_tr_sched_m4", (getter)Common_get_ur_tr_sched_m4,(setter)Common_set_ur_tr_sched_m4,
	PyDoc_STR("*float*: Tiered structure for April [0-5]\n\n*Info*: tiered structure #\n\n*Constraints*: INTEGER,MIN=0,MAX=5\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ur_tr_sched_m5", (getter)Common_get_ur_tr_sched_m5,(setter)Common_set_ur_tr_sched_m5,
	PyDoc_STR("*float*: Tiered structure for May [0-5]\n\n*Info*: tiered structure #\n\n*Constraints*: INTEGER,MIN=0,MAX=5\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ur_tr_sched_m6", (getter)Common_get_ur_tr_sched_m6,(setter)Common_set_ur_tr_sched_m6,
	PyDoc_STR("*float*: Tiered structure for June [0-5]\n\n*Info*: tiered structure #\n\n*Constraints*: INTEGER,MIN=0,MAX=5\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ur_tr_sched_m7", (getter)Common_get_ur_tr_sched_m7,(setter)Common_set_ur_tr_sched_m7,
	PyDoc_STR("*float*: Tiered structure for July [0-5]\n\n*Info*: tiered structure #\n\n*Constraints*: INTEGER,MIN=0,MAX=5\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ur_tr_sched_m8", (getter)Common_get_ur_tr_sched_m8,(setter)Common_set_ur_tr_sched_m8,
	PyDoc_STR("*float*: Tiered structure for August [0-5]\n\n*Info*: tiered structure #\n\n*Constraints*: INTEGER,MIN=0,MAX=5\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ur_tr_sched_m9", (getter)Common_get_ur_tr_sched_m9,(setter)Common_set_ur_tr_sched_m9,
	PyDoc_STR("*float*: Tiered structure for September [0-5]\n\n*Info*: tiered structure #\n\n*Constraints*: INTEGER,MIN=0,MAX=5\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ur_tr_sell_mode", (getter)Common_get_ur_tr_sell_mode,(setter)Common_set_ur_tr_sell_mode,
	PyDoc_STR("*float*: Tiered rate sell mode [0,1,2]\n\n*Options*: 0=specified,1=tier1,2=lowest\n\n*Constraints*: INTEGER,MIN=0,MAX=2\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"ur_tr_sell_rate", (getter)Common_get_ur_tr_sell_rate,(setter)Common_set_ur_tr_sell_rate,
	PyDoc_STR("*float*: Specified tiered sell rate [$/kW]\n\n*Required*: True if ur_tr_sell_mode=0"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate.Common",             /*tp_name*/
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
		Common_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Common_getset,          /*tp_getset*/
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
Outputs_new(SAM_Utilityrate data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate", "Outputs")){
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
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Outputs_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Outputs_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Outputs_get_charge_dc_fixed_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_fixed_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_fixed_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_fixed_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_fixed_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_fixed_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_fixed_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_fixed_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_fixed_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_fixed_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_fixed_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_fixed_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_fixed_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_tou_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_tou_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_tou_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_tou_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_tou_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_tou_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_tou_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_tou_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_tou_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_tou_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_tou_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_dc_tou_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_tr_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_tr_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_tr_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_tr_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_tr_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_tr_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_tr_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_tr_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_tr_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_tr_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_tr_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_tr_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_tr_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_tr_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_tr_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_tr_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_tr_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_tr_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_tr_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_tr_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_tr_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_tr_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_tr_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_charge_tr_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_elec_cost_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_elec_cost_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_elec_cost_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_elec_cost_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_net(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_energy_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_energy_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_revenue_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_revenue_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_revenue_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_revenue_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_e_demand(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_hourly_e_demand_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_e_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_hourly_e_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_income_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_hourly_income_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_income_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_hourly_income_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_p_demand(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_hourly_p_demand_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_p_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_hourly_p_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_p_system_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_hourly_p_system_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_payment_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_hourly_payment_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_payment_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_hourly_payment_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_price_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_hourly_price_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_price_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_hourly_price_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_revenue_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_hourly_revenue_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_revenue_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_hourly_revenue_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_system_output(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_hourly_system_output_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_system_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_hourly_system_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_system_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_hourly_system_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_fixed_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_monthly_dc_fixed_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_fixed_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_monthly_dc_fixed_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_tou_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_monthly_dc_tou_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_tou_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_monthly_dc_tou_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_tr_charge_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_monthly_tr_charge_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_tr_charge_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_monthly_tr_charge_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_tr_rate_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_monthly_tr_rate_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_tr_rate_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate_Outputs_year1_monthly_tr_rate_without_system_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"charge_dc_fixed_apr", (getter)Outputs_get_charge_dc_fixed_apr,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (fixed) in Apr [$]"),
 	NULL},
{"charge_dc_fixed_aug", (getter)Outputs_get_charge_dc_fixed_aug,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (fixed) in Aug [$]"),
 	NULL},
{"charge_dc_fixed_dec", (getter)Outputs_get_charge_dc_fixed_dec,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (fixed) in Dec [$]"),
 	NULL},
{"charge_dc_fixed_feb", (getter)Outputs_get_charge_dc_fixed_feb,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (fixed) in Feb [$]"),
 	NULL},
{"charge_dc_fixed_jan", (getter)Outputs_get_charge_dc_fixed_jan,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (fixed) in Jan [$]"),
 	NULL},
{"charge_dc_fixed_jul", (getter)Outputs_get_charge_dc_fixed_jul,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (fixed) in Jul [$]"),
 	NULL},
{"charge_dc_fixed_jun", (getter)Outputs_get_charge_dc_fixed_jun,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (fixed) in Jun [$]"),
 	NULL},
{"charge_dc_fixed_mar", (getter)Outputs_get_charge_dc_fixed_mar,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (fixed) in Mar [$]"),
 	NULL},
{"charge_dc_fixed_may", (getter)Outputs_get_charge_dc_fixed_may,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (fixed) in May [$]"),
 	NULL},
{"charge_dc_fixed_nov", (getter)Outputs_get_charge_dc_fixed_nov,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (fixed) in Nov [$]"),
 	NULL},
{"charge_dc_fixed_oct", (getter)Outputs_get_charge_dc_fixed_oct,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (fixed) in Oct [$]"),
 	NULL},
{"charge_dc_fixed_sep", (getter)Outputs_get_charge_dc_fixed_sep,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (fixed) in Sep [$]"),
 	NULL},
{"charge_dc_tou_apr", (getter)Outputs_get_charge_dc_tou_apr,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (TOU) in Apr [$]"),
 	NULL},
{"charge_dc_tou_aug", (getter)Outputs_get_charge_dc_tou_aug,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (TOU) in Aug [$]"),
 	NULL},
{"charge_dc_tou_dec", (getter)Outputs_get_charge_dc_tou_dec,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (TOU) in Dec [$]"),
 	NULL},
{"charge_dc_tou_feb", (getter)Outputs_get_charge_dc_tou_feb,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (TOU) in Feb [$]"),
 	NULL},
{"charge_dc_tou_jan", (getter)Outputs_get_charge_dc_tou_jan,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (TOU) in Jan [$]"),
 	NULL},
{"charge_dc_tou_jul", (getter)Outputs_get_charge_dc_tou_jul,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (TOU) in Jul [$]"),
 	NULL},
{"charge_dc_tou_jun", (getter)Outputs_get_charge_dc_tou_jun,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (TOU) in Jun [$]"),
 	NULL},
{"charge_dc_tou_mar", (getter)Outputs_get_charge_dc_tou_mar,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (TOU) in Mar [$]"),
 	NULL},
{"charge_dc_tou_may", (getter)Outputs_get_charge_dc_tou_may,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (TOU) in May [$]"),
 	NULL},
{"charge_dc_tou_nov", (getter)Outputs_get_charge_dc_tou_nov,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (TOU) in Nov [$]"),
 	NULL},
{"charge_dc_tou_oct", (getter)Outputs_get_charge_dc_tou_oct,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (TOU) in Oct [$]"),
 	NULL},
{"charge_dc_tou_sep", (getter)Outputs_get_charge_dc_tou_sep,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (TOU) in Sep [$]"),
 	NULL},
{"charge_tr_apr", (getter)Outputs_get_charge_tr_apr,(setter)0,
	PyDoc_STR("*sequence*: Tiered rate charge in Apr [$]"),
 	NULL},
{"charge_tr_aug", (getter)Outputs_get_charge_tr_aug,(setter)0,
	PyDoc_STR("*sequence*: Tiered rate charge in Aug [$]"),
 	NULL},
{"charge_tr_dec", (getter)Outputs_get_charge_tr_dec,(setter)0,
	PyDoc_STR("*sequence*: Tiered rate charge in Dec [$]"),
 	NULL},
{"charge_tr_feb", (getter)Outputs_get_charge_tr_feb,(setter)0,
	PyDoc_STR("*sequence*: Tiered rate charge in Feb [$]"),
 	NULL},
{"charge_tr_jan", (getter)Outputs_get_charge_tr_jan,(setter)0,
	PyDoc_STR("*sequence*: Tiered rate charge in Jan [$]"),
 	NULL},
{"charge_tr_jul", (getter)Outputs_get_charge_tr_jul,(setter)0,
	PyDoc_STR("*sequence*: Tiered rate charge in Jul [$]"),
 	NULL},
{"charge_tr_jun", (getter)Outputs_get_charge_tr_jun,(setter)0,
	PyDoc_STR("*sequence*: Tiered rate charge in Jun [$]"),
 	NULL},
{"charge_tr_mar", (getter)Outputs_get_charge_tr_mar,(setter)0,
	PyDoc_STR("*sequence*: Tiered rate charge in Mar [$]"),
 	NULL},
{"charge_tr_may", (getter)Outputs_get_charge_tr_may,(setter)0,
	PyDoc_STR("*sequence*: Tiered rate charge in May [$]"),
 	NULL},
{"charge_tr_nov", (getter)Outputs_get_charge_tr_nov,(setter)0,
	PyDoc_STR("*sequence*: Tiered rate charge in Nov [$]"),
 	NULL},
{"charge_tr_oct", (getter)Outputs_get_charge_tr_oct,(setter)0,
	PyDoc_STR("*sequence*: Tiered rate charge in Oct [$]"),
 	NULL},
{"charge_tr_sep", (getter)Outputs_get_charge_tr_sep,(setter)0,
	PyDoc_STR("*sequence*: Tiered rate charge in Sep [$]"),
 	NULL},
{"elec_cost_with_system", (getter)Outputs_get_elec_cost_with_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity cost with system [$/yr]"),
 	NULL},
{"elec_cost_without_system", (getter)Outputs_get_elec_cost_without_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity cost without system [$/yr]"),
 	NULL},
{"energy_net", (getter)Outputs_get_energy_net,(setter)0,
	PyDoc_STR("*sequence*: Energy by each year [kW]"),
 	NULL},
{"energy_value", (getter)Outputs_get_energy_value,(setter)0,
	PyDoc_STR("*sequence*: Energy value by each year [$]"),
 	NULL},
{"revenue_with_system", (getter)Outputs_get_revenue_with_system,(setter)0,
	PyDoc_STR("*sequence*: Total revenue with system [$]"),
 	NULL},
{"revenue_without_system", (getter)Outputs_get_revenue_without_system,(setter)0,
	PyDoc_STR("*sequence*: Total revenue without system [$]"),
 	NULL},
{"year1_hourly_e_demand", (getter)Outputs_get_year1_hourly_e_demand,(setter)0,
	PyDoc_STR("*sequence*: Electricity from grid [kWh]"),
 	NULL},
{"year1_hourly_e_grid", (getter)Outputs_get_year1_hourly_e_grid,(setter)0,
	PyDoc_STR("*sequence*: Electricity at grid [kWh]"),
 	NULL},
{"year1_hourly_income_with_system", (getter)Outputs_get_year1_hourly_income_with_system,(setter)0,
	PyDoc_STR("*sequence*: Income with system [$]"),
 	NULL},
{"year1_hourly_income_without_system", (getter)Outputs_get_year1_hourly_income_without_system,(setter)0,
	PyDoc_STR("*sequence*: Income without system [$]"),
 	NULL},
{"year1_hourly_p_demand", (getter)Outputs_get_year1_hourly_p_demand,(setter)0,
	PyDoc_STR("*sequence*: Peak from grid [kW]"),
 	NULL},
{"year1_hourly_p_grid", (getter)Outputs_get_year1_hourly_p_grid,(setter)0,
	PyDoc_STR("*sequence*: Peak at grid  [kW]"),
 	NULL},
{"year1_hourly_p_system_to_load", (getter)Outputs_get_year1_hourly_p_system_to_load,(setter)0,
	PyDoc_STR("*sequence*: Peak to load  [kW]"),
 	NULL},
{"year1_hourly_payment_with_system", (getter)Outputs_get_year1_hourly_payment_with_system,(setter)0,
	PyDoc_STR("*sequence*: Payment with system [$]"),
 	NULL},
{"year1_hourly_payment_without_system", (getter)Outputs_get_year1_hourly_payment_without_system,(setter)0,
	PyDoc_STR("*sequence*: Payment without system [$]"),
 	NULL},
{"year1_hourly_price_with_system", (getter)Outputs_get_year1_hourly_price_with_system,(setter)0,
	PyDoc_STR("*sequence*: Price with system [$]"),
 	NULL},
{"year1_hourly_price_without_system", (getter)Outputs_get_year1_hourly_price_without_system,(setter)0,
	PyDoc_STR("*sequence*: Price without system [$]"),
 	NULL},
{"year1_hourly_revenue_with_system", (getter)Outputs_get_year1_hourly_revenue_with_system,(setter)0,
	PyDoc_STR("*sequence*: Revenue with system [$]"),
 	NULL},
{"year1_hourly_revenue_without_system", (getter)Outputs_get_year1_hourly_revenue_without_system,(setter)0,
	PyDoc_STR("*sequence*: Revenue without system [$]"),
 	NULL},
{"year1_hourly_system_output", (getter)Outputs_get_year1_hourly_system_output,(setter)0,
	PyDoc_STR("*sequence*: Electricity from system [kWh]"),
 	NULL},
{"year1_hourly_system_to_grid", (getter)Outputs_get_year1_hourly_system_to_grid,(setter)0,
	PyDoc_STR("*sequence*: Electricity to grid [kWh]"),
 	NULL},
{"year1_hourly_system_to_load", (getter)Outputs_get_year1_hourly_system_to_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity to load [kWh]"),
 	NULL},
{"year1_monthly_dc_fixed_with_system", (getter)Outputs_get_year1_monthly_dc_fixed_with_system,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (fixed) with system [$]"),
 	NULL},
{"year1_monthly_dc_fixed_without_system", (getter)Outputs_get_year1_monthly_dc_fixed_without_system,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (fixed) without system [$]"),
 	NULL},
{"year1_monthly_dc_tou_with_system", (getter)Outputs_get_year1_monthly_dc_tou_with_system,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (TOU) with system [$]"),
 	NULL},
{"year1_monthly_dc_tou_without_system", (getter)Outputs_get_year1_monthly_dc_tou_without_system,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (TOU) without system [$]"),
 	NULL},
{"year1_monthly_tr_charge_with_system", (getter)Outputs_get_year1_monthly_tr_charge_with_system,(setter)0,
	PyDoc_STR("*sequence*: Tiered charge with system [$]"),
 	NULL},
{"year1_monthly_tr_charge_without_system", (getter)Outputs_get_year1_monthly_tr_charge_without_system,(setter)0,
	PyDoc_STR("*sequence*: Tiered charge without system [$]"),
 	NULL},
{"year1_monthly_tr_rate_with_system", (getter)Outputs_get_year1_monthly_tr_rate_with_system,(setter)0,
	PyDoc_STR("*sequence*: Tiered rate with system [$]"),
 	NULL},
{"year1_monthly_tr_rate_without_system", (getter)Outputs_get_year1_monthly_tr_rate_without_system,(setter)0,
	PyDoc_STR("*sequence*: Tiered rate without system [$]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate.Outputs",             /*tp_name*/
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
 * Utilityrate
 */

static PyTypeObject Utilityrate_Type;

static CmodObject *
newUtilityrateObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Utilityrate_Type);

	PySAM_TECH_ATTR()

	PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Utilityrate methods */

static void
Utilityrate_dealloc(CmodObject *self)
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
Utilityrate_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Utilityrate_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Utilityrate_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Utilityrate"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Utilityrate_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Utilityrate_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef Utilityrate_methods[] = {
		{"execute",            (PyCFunction)Utilityrate_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Utilityrate_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Common': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Utilityrate_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Utilityrate_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Utilityrate_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Utilityrate_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Utilityrate_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Utilityrate_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Utilityrate_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Utilityrate_getattro, /*tp_getattro*/
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
		Utilityrate_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Utilityrate object */

static PyObject *
Utilityrate_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newUtilityrateObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Utilityrate_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newUtilityrateObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Utilityrate_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newUtilityrateObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Utilityrate", def);

	return (PyObject *)rv;
}

static PyObject *
Utilityrate_from_existing(PyObject *self, PyObject *args)
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

	rv = newUtilityrateObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Utilityrate", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef UtilityrateModule_methods[] = {
		{"new",             Utilityrate_new,         METH_VARARGS,
				PyDoc_STR("new() -> Utilityrate")},
		{"default",             Utilityrate_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Utilityrate\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             Utilityrate_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Utilityrate\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   Utilityrate_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Utilityrate\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Utilityrate");


static int
UtilityrateModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Utilityrate_Type.tp_dict = PyDict_New();
	if (!Utilityrate_Type.tp_dict) { goto fail; }

	/// Add the Common type object to Utilityrate_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the Outputs type object to Utilityrate_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Utilityrate type object to the module
	if (PyType_Ready(&Utilityrate_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Utilityrate",
				(PyObject*)&Utilityrate_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot UtilityrateModule_slots[] = {
		{Py_mod_exec, UtilityrateModule_exec},
		{0, NULL},
};

static struct PyModuleDef UtilityrateModule = {
		PyModuleDef_HEAD_INIT,
		"Utilityrate",
		module_doc,
		0,
		UtilityrateModule_methods,
		UtilityrateModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Utilityrate(void)
{
	return PyModuleDef_Init(&UtilityrateModule);
}