#include <Python.h>

#include <SAM_Utilityrate3.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Common Group
 */ 

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_Utilityrate3 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate3", "Common")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Common_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Common_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Utilityrate3", "Common")){
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
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Common_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Common_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Common_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Common_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Common_get_analysis_period(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_analysis_period_nget, self->data_ptr);
}

static int
Common_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_analysis_period_nset, self->data_ptr);
}

static PyObject *
Common_get_load_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Common_load_escalation_aget, self->data_ptr);
}

static int
Common_set_load_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate3_Common_load_escalation_aset, self->data_ptr);
}

static PyObject *
Common_get_rate_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Common_rate_escalation_aget, self->data_ptr);
}

static int
Common_set_rate_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate3_Common_rate_escalation_aset, self->data_ptr);
}

static PyObject *
Common_get_system_use_lifetime_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_system_use_lifetime_output_nget, self->data_ptr);
}

static int
Common_set_system_use_lifetime_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_system_use_lifetime_output_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_annual_min_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_annual_min_charge_nget, self->data_ptr);
}

static int
Common_set_ur_annual_min_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_annual_min_charge_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_apr_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_apr_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_apr_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_apr_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_apr_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_apr_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_apr_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_apr_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_apr_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_apr_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_apr_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_apr_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_apr_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_apr_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_apr_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_apr_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_apr_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_apr_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_apr_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_apr_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_apr_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_apr_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_apr_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_apr_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_aug_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_aug_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_aug_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_aug_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_aug_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_aug_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_aug_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_aug_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_aug_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_aug_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_aug_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_aug_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_aug_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_aug_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_aug_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_aug_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_aug_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_aug_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_aug_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_aug_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_aug_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_aug_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_aug_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_aug_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_dec_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_dec_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_dec_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_dec_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_dec_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_dec_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_dec_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_dec_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_dec_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_dec_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_dec_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_dec_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_dec_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_dec_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_dec_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_dec_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_dec_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_dec_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_dec_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_dec_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_dec_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_dec_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_dec_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_dec_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_enable_nget, self->data_ptr);
}

static int
Common_set_ur_dc_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_enable_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_feb_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_feb_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_feb_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_feb_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_feb_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_feb_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_feb_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_feb_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_feb_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_feb_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_feb_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_feb_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_feb_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_feb_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_feb_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_feb_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_feb_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_feb_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_feb_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_feb_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_feb_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_feb_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_feb_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_feb_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jan_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jan_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jan_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jan_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jan_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jan_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jan_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jan_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jan_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jan_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jan_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jan_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jan_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jan_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jan_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jan_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jan_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jan_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jan_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jan_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jan_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jan_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jan_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jan_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jul_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jul_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jul_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jul_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jul_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jul_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jul_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jul_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jul_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jul_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jul_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jul_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jul_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jul_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jul_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jul_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jul_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jul_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jul_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jul_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jul_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jul_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jul_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jul_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jun_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jun_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jun_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jun_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jun_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jun_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jun_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jun_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jun_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jun_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jun_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jun_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jun_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jun_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jun_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jun_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jun_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jun_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jun_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jun_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jun_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jun_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_jun_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_jun_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_mar_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_mar_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_mar_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_mar_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_mar_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_mar_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_mar_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_mar_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_mar_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_mar_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_mar_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_mar_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_mar_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_mar_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_mar_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_mar_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_mar_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_mar_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_mar_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_mar_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_mar_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_mar_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_mar_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_mar_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_may_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_may_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_may_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_may_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_may_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_may_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_may_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_may_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_may_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_may_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_may_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_may_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_may_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_may_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_may_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_may_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_may_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_may_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_may_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_may_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_may_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_may_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_may_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_may_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_nov_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_nov_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_nov_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_nov_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_nov_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_nov_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_nov_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_nov_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_nov_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_nov_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_nov_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_nov_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_nov_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_nov_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_nov_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_nov_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_nov_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_nov_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_nov_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_nov_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_nov_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_nov_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_nov_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_nov_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_oct_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_oct_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_oct_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_oct_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_oct_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_oct_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_oct_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_oct_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_oct_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_oct_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_oct_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_oct_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_oct_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_oct_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_oct_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_oct_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_oct_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_oct_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_oct_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_oct_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_oct_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_oct_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_oct_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_oct_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p10_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p10_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p10_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p10_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p10_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p10_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p10_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p10_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p10_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p10_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p10_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p10_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p10_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p10_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p10_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p10_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p10_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p10_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p10_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p10_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p10_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p10_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p10_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p10_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p11_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p11_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p11_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p11_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p11_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p11_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p11_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p11_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p11_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p11_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p11_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p11_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p11_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p11_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p11_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p11_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p11_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p11_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p11_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p11_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p11_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p11_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p11_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p11_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p12_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p12_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p12_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p12_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p12_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p12_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p12_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p12_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p12_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p12_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p12_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p12_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p12_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p12_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p12_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p12_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p12_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p12_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p12_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p12_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p12_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p12_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p12_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p12_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p1_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p1_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p1_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p1_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p1_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p1_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p1_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p1_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p1_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p1_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p1_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p1_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p1_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p1_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p1_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p1_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p1_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p1_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p1_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p1_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p1_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p1_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p1_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p1_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p2_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p2_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p2_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p2_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p2_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p2_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p2_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p2_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p2_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p2_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p2_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p2_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p2_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p2_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p2_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p2_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p2_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p2_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p2_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p2_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p2_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p2_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p2_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p2_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p3_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p3_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p3_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p3_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p3_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p3_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p3_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p3_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p3_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p3_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p3_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p3_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p3_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p3_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p3_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p3_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p3_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p3_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p3_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p3_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p3_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p3_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p3_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p3_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p4_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p4_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p4_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p4_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p4_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p4_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p4_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p4_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p4_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p4_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p4_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p4_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p4_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p4_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p4_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p4_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p4_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p4_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p4_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p4_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p4_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p4_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p4_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p4_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p5_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p5_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p5_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p5_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p5_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p5_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p5_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p5_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p5_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p5_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p5_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p5_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p5_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p5_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p5_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p5_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p5_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p5_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p5_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p5_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p5_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p5_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p5_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p5_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p6_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p6_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p6_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p6_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p6_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p6_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p6_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p6_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p6_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p6_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p6_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p6_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p6_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p6_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p6_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p6_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p6_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p6_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p6_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p6_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p6_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p6_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p6_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p6_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p7_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p7_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p7_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p7_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p7_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p7_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p7_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p7_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p7_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p7_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p7_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p7_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p7_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p7_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p7_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p7_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p7_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p7_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p7_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p7_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p7_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p7_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p7_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p7_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p8_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p8_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p8_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p8_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p8_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p8_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p8_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p8_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p8_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p8_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p8_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p8_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p8_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p8_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p8_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p8_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p8_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p8_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p8_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p8_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p8_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p8_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p8_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p8_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p9_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p9_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p9_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p9_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p9_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p9_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p9_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p9_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p9_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p9_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p9_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p9_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p9_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p9_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p9_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p9_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p9_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p9_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p9_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p9_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p9_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p9_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_p9_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_p9_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate3_Common_ur_dc_sched_weekday_mget, self->data_ptr);
}

static int
Common_set_ur_dc_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate3_Common_ur_dc_sched_weekday_mset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate3_Common_ur_dc_sched_weekend_mget, self->data_ptr);
}

static int
Common_set_ur_dc_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate3_Common_ur_dc_sched_weekend_mset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_sep_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_sep_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_sep_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_sep_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_sep_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_sep_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_sep_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_sep_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_sep_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_sep_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_sep_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_sep_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_sep_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_sep_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_sep_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_sep_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_sep_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_sep_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_sep_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_sep_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_sep_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_sep_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_dc_sep_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_dc_sep_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_enable_nget, self->data_ptr);
}

static int
Common_set_ur_ec_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_enable_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p10_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p10_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p10_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p10_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p10_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p10_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p10_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p10_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p10_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p10_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p10_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p10_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p10_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p10_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p10_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p10_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p10_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p10_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p10_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p10_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p10_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p10_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p10_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p10_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p10_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p10_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p10_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p10_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p10_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p10_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p10_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p10_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p10_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p10_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p10_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p10_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p11_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p11_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p11_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p11_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p11_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p11_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p11_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p11_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p11_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p11_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p11_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p11_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p11_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p11_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p11_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p11_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p11_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p11_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p11_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p11_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p11_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p11_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p11_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p11_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p11_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p11_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p11_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p11_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p11_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p11_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p11_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p11_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p11_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p11_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p11_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p11_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p12_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p12_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p12_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p12_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p12_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p12_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p12_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p12_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p12_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p12_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p12_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p12_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p12_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p12_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p12_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p12_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p12_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p12_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p12_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p12_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p12_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p12_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p12_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p12_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p12_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p12_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p12_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p12_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p12_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p12_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p12_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p12_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p12_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p12_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p12_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p12_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p1_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p1_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p1_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p1_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p1_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p1_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p1_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p1_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p1_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p1_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p1_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p1_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p1_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p1_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p1_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p1_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p1_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p1_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p1_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p1_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p1_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p1_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p1_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p1_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p1_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p1_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p1_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p1_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p1_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p1_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p1_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p1_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p1_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p1_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p1_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p1_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p2_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p2_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p2_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p2_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p2_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p2_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p2_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p2_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p2_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p2_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p2_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p2_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p2_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p2_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p2_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p2_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p2_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p2_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p2_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p2_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p2_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p2_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p2_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p2_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p2_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p2_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p2_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p2_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p2_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p2_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p2_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p2_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p2_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p2_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p2_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p2_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p3_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p3_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p3_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p3_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p3_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p3_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p3_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p3_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p3_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p3_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p3_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p3_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p3_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p3_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p3_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p3_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p3_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p3_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p3_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p3_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p3_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p3_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p3_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p3_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p3_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p3_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p3_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p3_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p3_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p3_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p3_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p3_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p3_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p3_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p3_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p3_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p4_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p4_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p4_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p4_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p4_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p4_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p4_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p4_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p4_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p4_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p4_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p4_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p4_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p4_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p4_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p4_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p4_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p4_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p4_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p4_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p4_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p4_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p4_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p4_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p4_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p4_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p4_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p4_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p4_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p4_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p4_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p4_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p4_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p4_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p4_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p4_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p5_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p5_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p5_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p5_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p5_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p5_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p5_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p5_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p5_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p5_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p5_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p5_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p5_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p5_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p5_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p5_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p5_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p5_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p5_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p5_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p5_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p5_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p5_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p5_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p5_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p5_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p5_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p5_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p5_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p5_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p5_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p5_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p5_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p5_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p5_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p5_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p6_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p6_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p6_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p6_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p6_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p6_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p6_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p6_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p6_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p6_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p6_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p6_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p6_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p6_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p6_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p6_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p6_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p6_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p6_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p6_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p6_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p6_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p6_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p6_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p6_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p6_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p6_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p6_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p6_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p6_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p6_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p6_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p6_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p6_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p6_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p6_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p7_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p7_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p7_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p7_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p7_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p7_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p7_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p7_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p7_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p7_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p7_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p7_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p7_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p7_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p7_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p7_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p7_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p7_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p7_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p7_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p7_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p7_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p7_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p7_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p7_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p7_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p7_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p7_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p7_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p7_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p7_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p7_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p7_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p7_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p7_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p7_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p8_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p8_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p8_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p8_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p8_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p8_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p8_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p8_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p8_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p8_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p8_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p8_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p8_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p8_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p8_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p8_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p8_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p8_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p8_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p8_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p8_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p8_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p8_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p8_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p8_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p8_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p8_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p8_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p8_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p8_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p8_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p8_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p8_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p8_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p8_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p8_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p9_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p9_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p9_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p9_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p9_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p9_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p9_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p9_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p9_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p9_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p9_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p9_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p9_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p9_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p9_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p9_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p9_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p9_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p9_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p9_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p9_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p9_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p9_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p9_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p9_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p9_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p9_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p9_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p9_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p9_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p9_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p9_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p9_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p9_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_ec_p9_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_ec_p9_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate3_Common_ur_ec_sched_weekday_mget, self->data_ptr);
}

static int
Common_set_ur_ec_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate3_Common_ur_ec_sched_weekday_mset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate3_Common_ur_ec_sched_weekend_mget, self->data_ptr);
}

static int
Common_set_ur_ec_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate3_Common_ur_ec_sched_weekend_mset, self->data_ptr);
}

static PyObject *
Common_get_ur_enable_net_metering(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_enable_net_metering_nget, self->data_ptr);
}

static int
Common_set_ur_enable_net_metering(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_enable_net_metering_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_excess_monthly_energy_or_dollars(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_excess_monthly_energy_or_dollars_nget, self->data_ptr);
}

static int
Common_set_ur_excess_monthly_energy_or_dollars(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_excess_monthly_energy_or_dollars_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_flat_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_flat_buy_rate_nget, self->data_ptr);
}

static int
Common_set_ur_flat_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_flat_buy_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_flat_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_flat_sell_rate_nget, self->data_ptr);
}

static int
Common_set_ur_flat_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_flat_sell_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_monthly_fixed_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_monthly_fixed_charge_nget, self->data_ptr);
}

static int
Common_set_ur_monthly_fixed_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_monthly_fixed_charge_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_monthly_min_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_monthly_min_charge_nget, self->data_ptr);
}

static int
Common_set_ur_monthly_min_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_monthly_min_charge_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_nm_yearend_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Common_ur_nm_yearend_sell_rate_nget, self->data_ptr);
}

static int
Common_set_ur_nm_yearend_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Common_ur_nm_yearend_sell_rate_nset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"analysis_period", (getter)Common_get_analysis_period,(setter)Common_set_analysis_period,
	PyDoc_STR("*float*: Number of years in analysis [years]\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"load_escalation", (getter)Common_get_load_escalation,(setter)Common_set_load_escalation,
	PyDoc_STR("*sequence*: Annual load escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"rate_escalation", (getter)Common_get_rate_escalation,(setter)Common_set_rate_escalation,
	PyDoc_STR("*sequence*: Annual utility rate escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"system_use_lifetime_output", (getter)Common_get_system_use_lifetime_output,(setter)Common_set_system_use_lifetime_output,
	PyDoc_STR("*float*: Lifetime hourly system outputs [0/1]\n\n**Options:**\n0=hourly first year,1=hourly lifetime\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nTrue"),
 	NULL},
{"ur_annual_min_charge", (getter)Common_get_ur_annual_min_charge,(setter)Common_set_ur_annual_min_charge,
	PyDoc_STR("*float*: Annual minimum charge [$]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_apr_t1_dc", (getter)Common_get_ur_dc_apr_t1_dc,(setter)Common_set_ur_dc_apr_t1_dc,
	PyDoc_STR("*float*: April Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_apr_t1_ub", (getter)Common_get_ur_dc_apr_t1_ub,(setter)Common_set_ur_dc_apr_t1_ub,
	PyDoc_STR("*float*: April Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_apr_t2_dc", (getter)Common_get_ur_dc_apr_t2_dc,(setter)Common_set_ur_dc_apr_t2_dc,
	PyDoc_STR("*float*: April Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_apr_t2_ub", (getter)Common_get_ur_dc_apr_t2_ub,(setter)Common_set_ur_dc_apr_t2_ub,
	PyDoc_STR("*float*: April Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_apr_t3_dc", (getter)Common_get_ur_dc_apr_t3_dc,(setter)Common_set_ur_dc_apr_t3_dc,
	PyDoc_STR("*float*: April Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_apr_t3_ub", (getter)Common_get_ur_dc_apr_t3_ub,(setter)Common_set_ur_dc_apr_t3_ub,
	PyDoc_STR("*float*: April Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_apr_t4_dc", (getter)Common_get_ur_dc_apr_t4_dc,(setter)Common_set_ur_dc_apr_t4_dc,
	PyDoc_STR("*float*: April Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_apr_t4_ub", (getter)Common_get_ur_dc_apr_t4_ub,(setter)Common_set_ur_dc_apr_t4_ub,
	PyDoc_STR("*float*: April Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_apr_t5_dc", (getter)Common_get_ur_dc_apr_t5_dc,(setter)Common_set_ur_dc_apr_t5_dc,
	PyDoc_STR("*float*: April Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_apr_t5_ub", (getter)Common_get_ur_dc_apr_t5_ub,(setter)Common_set_ur_dc_apr_t5_ub,
	PyDoc_STR("*float*: April Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_apr_t6_dc", (getter)Common_get_ur_dc_apr_t6_dc,(setter)Common_set_ur_dc_apr_t6_dc,
	PyDoc_STR("*float*: April Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_apr_t6_ub", (getter)Common_get_ur_dc_apr_t6_ub,(setter)Common_set_ur_dc_apr_t6_ub,
	PyDoc_STR("*float*: April Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_aug_t1_dc", (getter)Common_get_ur_dc_aug_t1_dc,(setter)Common_set_ur_dc_aug_t1_dc,
	PyDoc_STR("*float*: August Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_aug_t1_ub", (getter)Common_get_ur_dc_aug_t1_ub,(setter)Common_set_ur_dc_aug_t1_ub,
	PyDoc_STR("*float*: August Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_aug_t2_dc", (getter)Common_get_ur_dc_aug_t2_dc,(setter)Common_set_ur_dc_aug_t2_dc,
	PyDoc_STR("*float*: August Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_aug_t2_ub", (getter)Common_get_ur_dc_aug_t2_ub,(setter)Common_set_ur_dc_aug_t2_ub,
	PyDoc_STR("*float*: August Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_aug_t3_dc", (getter)Common_get_ur_dc_aug_t3_dc,(setter)Common_set_ur_dc_aug_t3_dc,
	PyDoc_STR("*float*: August Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_aug_t3_ub", (getter)Common_get_ur_dc_aug_t3_ub,(setter)Common_set_ur_dc_aug_t3_ub,
	PyDoc_STR("*float*: August Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_aug_t4_dc", (getter)Common_get_ur_dc_aug_t4_dc,(setter)Common_set_ur_dc_aug_t4_dc,
	PyDoc_STR("*float*: August Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_aug_t4_ub", (getter)Common_get_ur_dc_aug_t4_ub,(setter)Common_set_ur_dc_aug_t4_ub,
	PyDoc_STR("*float*: August Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_aug_t5_dc", (getter)Common_get_ur_dc_aug_t5_dc,(setter)Common_set_ur_dc_aug_t5_dc,
	PyDoc_STR("*float*: August Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_aug_t5_ub", (getter)Common_get_ur_dc_aug_t5_ub,(setter)Common_set_ur_dc_aug_t5_ub,
	PyDoc_STR("*float*: August Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_aug_t6_dc", (getter)Common_get_ur_dc_aug_t6_dc,(setter)Common_set_ur_dc_aug_t6_dc,
	PyDoc_STR("*float*: August Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_aug_t6_ub", (getter)Common_get_ur_dc_aug_t6_ub,(setter)Common_set_ur_dc_aug_t6_ub,
	PyDoc_STR("*float*: August Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_dec_t1_dc", (getter)Common_get_ur_dc_dec_t1_dc,(setter)Common_set_ur_dc_dec_t1_dc,
	PyDoc_STR("*float*: December Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_dec_t1_ub", (getter)Common_get_ur_dc_dec_t1_ub,(setter)Common_set_ur_dc_dec_t1_ub,
	PyDoc_STR("*float*: December Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_dec_t2_dc", (getter)Common_get_ur_dc_dec_t2_dc,(setter)Common_set_ur_dc_dec_t2_dc,
	PyDoc_STR("*float*: December Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_dec_t2_ub", (getter)Common_get_ur_dc_dec_t2_ub,(setter)Common_set_ur_dc_dec_t2_ub,
	PyDoc_STR("*float*: December Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_dec_t3_dc", (getter)Common_get_ur_dc_dec_t3_dc,(setter)Common_set_ur_dc_dec_t3_dc,
	PyDoc_STR("*float*: December Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_dec_t3_ub", (getter)Common_get_ur_dc_dec_t3_ub,(setter)Common_set_ur_dc_dec_t3_ub,
	PyDoc_STR("*float*: December Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_dec_t4_dc", (getter)Common_get_ur_dc_dec_t4_dc,(setter)Common_set_ur_dc_dec_t4_dc,
	PyDoc_STR("*float*: December Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_dec_t4_ub", (getter)Common_get_ur_dc_dec_t4_ub,(setter)Common_set_ur_dc_dec_t4_ub,
	PyDoc_STR("*float*: December Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_dec_t5_dc", (getter)Common_get_ur_dc_dec_t5_dc,(setter)Common_set_ur_dc_dec_t5_dc,
	PyDoc_STR("*float*: December Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_dec_t5_ub", (getter)Common_get_ur_dc_dec_t5_ub,(setter)Common_set_ur_dc_dec_t5_ub,
	PyDoc_STR("*float*: December Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_dec_t6_dc", (getter)Common_get_ur_dc_dec_t6_dc,(setter)Common_set_ur_dc_dec_t6_dc,
	PyDoc_STR("*float*: December Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_dec_t6_ub", (getter)Common_get_ur_dc_dec_t6_ub,(setter)Common_set_ur_dc_dec_t6_ub,
	PyDoc_STR("*float*: December Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_enable", (getter)Common_get_ur_dc_enable,(setter)Common_set_ur_dc_enable,
	PyDoc_STR("*float*: Enable Demand Charge [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_feb_t1_dc", (getter)Common_get_ur_dc_feb_t1_dc,(setter)Common_set_ur_dc_feb_t1_dc,
	PyDoc_STR("*float*: February Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_feb_t1_ub", (getter)Common_get_ur_dc_feb_t1_ub,(setter)Common_set_ur_dc_feb_t1_ub,
	PyDoc_STR("*float*: February Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_feb_t2_dc", (getter)Common_get_ur_dc_feb_t2_dc,(setter)Common_set_ur_dc_feb_t2_dc,
	PyDoc_STR("*float*: February Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_feb_t2_ub", (getter)Common_get_ur_dc_feb_t2_ub,(setter)Common_set_ur_dc_feb_t2_ub,
	PyDoc_STR("*float*: February Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_feb_t3_dc", (getter)Common_get_ur_dc_feb_t3_dc,(setter)Common_set_ur_dc_feb_t3_dc,
	PyDoc_STR("*float*: February Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_feb_t3_ub", (getter)Common_get_ur_dc_feb_t3_ub,(setter)Common_set_ur_dc_feb_t3_ub,
	PyDoc_STR("*float*: February Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_feb_t4_dc", (getter)Common_get_ur_dc_feb_t4_dc,(setter)Common_set_ur_dc_feb_t4_dc,
	PyDoc_STR("*float*: February Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_feb_t4_ub", (getter)Common_get_ur_dc_feb_t4_ub,(setter)Common_set_ur_dc_feb_t4_ub,
	PyDoc_STR("*float*: February Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_feb_t5_dc", (getter)Common_get_ur_dc_feb_t5_dc,(setter)Common_set_ur_dc_feb_t5_dc,
	PyDoc_STR("*float*: February Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_feb_t5_ub", (getter)Common_get_ur_dc_feb_t5_ub,(setter)Common_set_ur_dc_feb_t5_ub,
	PyDoc_STR("*float*: February Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_feb_t6_dc", (getter)Common_get_ur_dc_feb_t6_dc,(setter)Common_set_ur_dc_feb_t6_dc,
	PyDoc_STR("*float*: February Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_feb_t6_ub", (getter)Common_get_ur_dc_feb_t6_ub,(setter)Common_set_ur_dc_feb_t6_ub,
	PyDoc_STR("*float*: February Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jan_t1_dc", (getter)Common_get_ur_dc_jan_t1_dc,(setter)Common_set_ur_dc_jan_t1_dc,
	PyDoc_STR("*float*: January Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jan_t1_ub", (getter)Common_get_ur_dc_jan_t1_ub,(setter)Common_set_ur_dc_jan_t1_ub,
	PyDoc_STR("*float*: January Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jan_t2_dc", (getter)Common_get_ur_dc_jan_t2_dc,(setter)Common_set_ur_dc_jan_t2_dc,
	PyDoc_STR("*float*: January Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jan_t2_ub", (getter)Common_get_ur_dc_jan_t2_ub,(setter)Common_set_ur_dc_jan_t2_ub,
	PyDoc_STR("*float*: January Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jan_t3_dc", (getter)Common_get_ur_dc_jan_t3_dc,(setter)Common_set_ur_dc_jan_t3_dc,
	PyDoc_STR("*float*: January Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jan_t3_ub", (getter)Common_get_ur_dc_jan_t3_ub,(setter)Common_set_ur_dc_jan_t3_ub,
	PyDoc_STR("*float*: January Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jan_t4_dc", (getter)Common_get_ur_dc_jan_t4_dc,(setter)Common_set_ur_dc_jan_t4_dc,
	PyDoc_STR("*float*: January Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jan_t4_ub", (getter)Common_get_ur_dc_jan_t4_ub,(setter)Common_set_ur_dc_jan_t4_ub,
	PyDoc_STR("*float*: January Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jan_t5_dc", (getter)Common_get_ur_dc_jan_t5_dc,(setter)Common_set_ur_dc_jan_t5_dc,
	PyDoc_STR("*float*: January Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jan_t5_ub", (getter)Common_get_ur_dc_jan_t5_ub,(setter)Common_set_ur_dc_jan_t5_ub,
	PyDoc_STR("*float*: January Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jan_t6_dc", (getter)Common_get_ur_dc_jan_t6_dc,(setter)Common_set_ur_dc_jan_t6_dc,
	PyDoc_STR("*float*: January Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jan_t6_ub", (getter)Common_get_ur_dc_jan_t6_ub,(setter)Common_set_ur_dc_jan_t6_ub,
	PyDoc_STR("*float*: January Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jul_t1_dc", (getter)Common_get_ur_dc_jul_t1_dc,(setter)Common_set_ur_dc_jul_t1_dc,
	PyDoc_STR("*float*: July Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jul_t1_ub", (getter)Common_get_ur_dc_jul_t1_ub,(setter)Common_set_ur_dc_jul_t1_ub,
	PyDoc_STR("*float*: July Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jul_t2_dc", (getter)Common_get_ur_dc_jul_t2_dc,(setter)Common_set_ur_dc_jul_t2_dc,
	PyDoc_STR("*float*: July Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jul_t2_ub", (getter)Common_get_ur_dc_jul_t2_ub,(setter)Common_set_ur_dc_jul_t2_ub,
	PyDoc_STR("*float*: July Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jul_t3_dc", (getter)Common_get_ur_dc_jul_t3_dc,(setter)Common_set_ur_dc_jul_t3_dc,
	PyDoc_STR("*float*: July Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jul_t3_ub", (getter)Common_get_ur_dc_jul_t3_ub,(setter)Common_set_ur_dc_jul_t3_ub,
	PyDoc_STR("*float*: July Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jul_t4_dc", (getter)Common_get_ur_dc_jul_t4_dc,(setter)Common_set_ur_dc_jul_t4_dc,
	PyDoc_STR("*float*: July Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jul_t4_ub", (getter)Common_get_ur_dc_jul_t4_ub,(setter)Common_set_ur_dc_jul_t4_ub,
	PyDoc_STR("*float*: July Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jul_t5_dc", (getter)Common_get_ur_dc_jul_t5_dc,(setter)Common_set_ur_dc_jul_t5_dc,
	PyDoc_STR("*float*: July Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jul_t5_ub", (getter)Common_get_ur_dc_jul_t5_ub,(setter)Common_set_ur_dc_jul_t5_ub,
	PyDoc_STR("*float*: July Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jul_t6_dc", (getter)Common_get_ur_dc_jul_t6_dc,(setter)Common_set_ur_dc_jul_t6_dc,
	PyDoc_STR("*float*: July Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jul_t6_ub", (getter)Common_get_ur_dc_jul_t6_ub,(setter)Common_set_ur_dc_jul_t6_ub,
	PyDoc_STR("*float*: July Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jun_t1_dc", (getter)Common_get_ur_dc_jun_t1_dc,(setter)Common_set_ur_dc_jun_t1_dc,
	PyDoc_STR("*float*: June Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jun_t1_ub", (getter)Common_get_ur_dc_jun_t1_ub,(setter)Common_set_ur_dc_jun_t1_ub,
	PyDoc_STR("*float*: June Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jun_t2_dc", (getter)Common_get_ur_dc_jun_t2_dc,(setter)Common_set_ur_dc_jun_t2_dc,
	PyDoc_STR("*float*: June Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jun_t2_ub", (getter)Common_get_ur_dc_jun_t2_ub,(setter)Common_set_ur_dc_jun_t2_ub,
	PyDoc_STR("*float*: June Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jun_t3_dc", (getter)Common_get_ur_dc_jun_t3_dc,(setter)Common_set_ur_dc_jun_t3_dc,
	PyDoc_STR("*float*: June Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jun_t3_ub", (getter)Common_get_ur_dc_jun_t3_ub,(setter)Common_set_ur_dc_jun_t3_ub,
	PyDoc_STR("*float*: June Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jun_t4_dc", (getter)Common_get_ur_dc_jun_t4_dc,(setter)Common_set_ur_dc_jun_t4_dc,
	PyDoc_STR("*float*: June Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jun_t4_ub", (getter)Common_get_ur_dc_jun_t4_ub,(setter)Common_set_ur_dc_jun_t4_ub,
	PyDoc_STR("*float*: June Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jun_t5_dc", (getter)Common_get_ur_dc_jun_t5_dc,(setter)Common_set_ur_dc_jun_t5_dc,
	PyDoc_STR("*float*: June Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jun_t5_ub", (getter)Common_get_ur_dc_jun_t5_ub,(setter)Common_set_ur_dc_jun_t5_ub,
	PyDoc_STR("*float*: June Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jun_t6_dc", (getter)Common_get_ur_dc_jun_t6_dc,(setter)Common_set_ur_dc_jun_t6_dc,
	PyDoc_STR("*float*: June Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_jun_t6_ub", (getter)Common_get_ur_dc_jun_t6_ub,(setter)Common_set_ur_dc_jun_t6_ub,
	PyDoc_STR("*float*: June Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_mar_t1_dc", (getter)Common_get_ur_dc_mar_t1_dc,(setter)Common_set_ur_dc_mar_t1_dc,
	PyDoc_STR("*float*: March Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_mar_t1_ub", (getter)Common_get_ur_dc_mar_t1_ub,(setter)Common_set_ur_dc_mar_t1_ub,
	PyDoc_STR("*float*: March Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_mar_t2_dc", (getter)Common_get_ur_dc_mar_t2_dc,(setter)Common_set_ur_dc_mar_t2_dc,
	PyDoc_STR("*float*: March Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_mar_t2_ub", (getter)Common_get_ur_dc_mar_t2_ub,(setter)Common_set_ur_dc_mar_t2_ub,
	PyDoc_STR("*float*: March Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_mar_t3_dc", (getter)Common_get_ur_dc_mar_t3_dc,(setter)Common_set_ur_dc_mar_t3_dc,
	PyDoc_STR("*float*: March Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_mar_t3_ub", (getter)Common_get_ur_dc_mar_t3_ub,(setter)Common_set_ur_dc_mar_t3_ub,
	PyDoc_STR("*float*: March Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_mar_t4_dc", (getter)Common_get_ur_dc_mar_t4_dc,(setter)Common_set_ur_dc_mar_t4_dc,
	PyDoc_STR("*float*: March Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_mar_t4_ub", (getter)Common_get_ur_dc_mar_t4_ub,(setter)Common_set_ur_dc_mar_t4_ub,
	PyDoc_STR("*float*: March Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_mar_t5_dc", (getter)Common_get_ur_dc_mar_t5_dc,(setter)Common_set_ur_dc_mar_t5_dc,
	PyDoc_STR("*float*: March Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_mar_t5_ub", (getter)Common_get_ur_dc_mar_t5_ub,(setter)Common_set_ur_dc_mar_t5_ub,
	PyDoc_STR("*float*: March Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_mar_t6_dc", (getter)Common_get_ur_dc_mar_t6_dc,(setter)Common_set_ur_dc_mar_t6_dc,
	PyDoc_STR("*float*: March Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_mar_t6_ub", (getter)Common_get_ur_dc_mar_t6_ub,(setter)Common_set_ur_dc_mar_t6_ub,
	PyDoc_STR("*float*: March Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_may_t1_dc", (getter)Common_get_ur_dc_may_t1_dc,(setter)Common_set_ur_dc_may_t1_dc,
	PyDoc_STR("*float*: May Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_may_t1_ub", (getter)Common_get_ur_dc_may_t1_ub,(setter)Common_set_ur_dc_may_t1_ub,
	PyDoc_STR("*float*: May Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_may_t2_dc", (getter)Common_get_ur_dc_may_t2_dc,(setter)Common_set_ur_dc_may_t2_dc,
	PyDoc_STR("*float*: May Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_may_t2_ub", (getter)Common_get_ur_dc_may_t2_ub,(setter)Common_set_ur_dc_may_t2_ub,
	PyDoc_STR("*float*: May Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_may_t3_dc", (getter)Common_get_ur_dc_may_t3_dc,(setter)Common_set_ur_dc_may_t3_dc,
	PyDoc_STR("*float*: May Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_may_t3_ub", (getter)Common_get_ur_dc_may_t3_ub,(setter)Common_set_ur_dc_may_t3_ub,
	PyDoc_STR("*float*: May Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_may_t4_dc", (getter)Common_get_ur_dc_may_t4_dc,(setter)Common_set_ur_dc_may_t4_dc,
	PyDoc_STR("*float*: May Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_may_t4_ub", (getter)Common_get_ur_dc_may_t4_ub,(setter)Common_set_ur_dc_may_t4_ub,
	PyDoc_STR("*float*: May Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_may_t5_dc", (getter)Common_get_ur_dc_may_t5_dc,(setter)Common_set_ur_dc_may_t5_dc,
	PyDoc_STR("*float*: May Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_may_t5_ub", (getter)Common_get_ur_dc_may_t5_ub,(setter)Common_set_ur_dc_may_t5_ub,
	PyDoc_STR("*float*: May Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_may_t6_dc", (getter)Common_get_ur_dc_may_t6_dc,(setter)Common_set_ur_dc_may_t6_dc,
	PyDoc_STR("*float*: May Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_may_t6_ub", (getter)Common_get_ur_dc_may_t6_ub,(setter)Common_set_ur_dc_may_t6_ub,
	PyDoc_STR("*float*: May Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_nov_t1_dc", (getter)Common_get_ur_dc_nov_t1_dc,(setter)Common_set_ur_dc_nov_t1_dc,
	PyDoc_STR("*float*: November Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_nov_t1_ub", (getter)Common_get_ur_dc_nov_t1_ub,(setter)Common_set_ur_dc_nov_t1_ub,
	PyDoc_STR("*float*: November Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_nov_t2_dc", (getter)Common_get_ur_dc_nov_t2_dc,(setter)Common_set_ur_dc_nov_t2_dc,
	PyDoc_STR("*float*: November Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_nov_t2_ub", (getter)Common_get_ur_dc_nov_t2_ub,(setter)Common_set_ur_dc_nov_t2_ub,
	PyDoc_STR("*float*: November Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_nov_t3_dc", (getter)Common_get_ur_dc_nov_t3_dc,(setter)Common_set_ur_dc_nov_t3_dc,
	PyDoc_STR("*float*: November Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_nov_t3_ub", (getter)Common_get_ur_dc_nov_t3_ub,(setter)Common_set_ur_dc_nov_t3_ub,
	PyDoc_STR("*float*: November Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_nov_t4_dc", (getter)Common_get_ur_dc_nov_t4_dc,(setter)Common_set_ur_dc_nov_t4_dc,
	PyDoc_STR("*float*: November Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_nov_t4_ub", (getter)Common_get_ur_dc_nov_t4_ub,(setter)Common_set_ur_dc_nov_t4_ub,
	PyDoc_STR("*float*: November Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_nov_t5_dc", (getter)Common_get_ur_dc_nov_t5_dc,(setter)Common_set_ur_dc_nov_t5_dc,
	PyDoc_STR("*float*: November Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_nov_t5_ub", (getter)Common_get_ur_dc_nov_t5_ub,(setter)Common_set_ur_dc_nov_t5_ub,
	PyDoc_STR("*float*: November Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_nov_t6_dc", (getter)Common_get_ur_dc_nov_t6_dc,(setter)Common_set_ur_dc_nov_t6_dc,
	PyDoc_STR("*float*: November Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_nov_t6_ub", (getter)Common_get_ur_dc_nov_t6_ub,(setter)Common_set_ur_dc_nov_t6_ub,
	PyDoc_STR("*float*: November Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_oct_t1_dc", (getter)Common_get_ur_dc_oct_t1_dc,(setter)Common_set_ur_dc_oct_t1_dc,
	PyDoc_STR("*float*: October Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_oct_t1_ub", (getter)Common_get_ur_dc_oct_t1_ub,(setter)Common_set_ur_dc_oct_t1_ub,
	PyDoc_STR("*float*: October Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_oct_t2_dc", (getter)Common_get_ur_dc_oct_t2_dc,(setter)Common_set_ur_dc_oct_t2_dc,
	PyDoc_STR("*float*: October Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_oct_t2_ub", (getter)Common_get_ur_dc_oct_t2_ub,(setter)Common_set_ur_dc_oct_t2_ub,
	PyDoc_STR("*float*: October Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_oct_t3_dc", (getter)Common_get_ur_dc_oct_t3_dc,(setter)Common_set_ur_dc_oct_t3_dc,
	PyDoc_STR("*float*: October Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_oct_t3_ub", (getter)Common_get_ur_dc_oct_t3_ub,(setter)Common_set_ur_dc_oct_t3_ub,
	PyDoc_STR("*float*: October Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_oct_t4_dc", (getter)Common_get_ur_dc_oct_t4_dc,(setter)Common_set_ur_dc_oct_t4_dc,
	PyDoc_STR("*float*: October Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_oct_t4_ub", (getter)Common_get_ur_dc_oct_t4_ub,(setter)Common_set_ur_dc_oct_t4_ub,
	PyDoc_STR("*float*: October Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_oct_t5_dc", (getter)Common_get_ur_dc_oct_t5_dc,(setter)Common_set_ur_dc_oct_t5_dc,
	PyDoc_STR("*float*: October Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_oct_t5_ub", (getter)Common_get_ur_dc_oct_t5_ub,(setter)Common_set_ur_dc_oct_t5_ub,
	PyDoc_STR("*float*: October Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_oct_t6_dc", (getter)Common_get_ur_dc_oct_t6_dc,(setter)Common_set_ur_dc_oct_t6_dc,
	PyDoc_STR("*float*: October Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_oct_t6_ub", (getter)Common_get_ur_dc_oct_t6_ub,(setter)Common_set_ur_dc_oct_t6_ub,
	PyDoc_STR("*float*: October Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p10_t1_dc", (getter)Common_get_ur_dc_p10_t1_dc,(setter)Common_set_ur_dc_p10_t1_dc,
	PyDoc_STR("*float*: Period 10 Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p10_t1_ub", (getter)Common_get_ur_dc_p10_t1_ub,(setter)Common_set_ur_dc_p10_t1_ub,
	PyDoc_STR("*float*: Period 10 Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p10_t2_dc", (getter)Common_get_ur_dc_p10_t2_dc,(setter)Common_set_ur_dc_p10_t2_dc,
	PyDoc_STR("*float*: Period 10 Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p10_t2_ub", (getter)Common_get_ur_dc_p10_t2_ub,(setter)Common_set_ur_dc_p10_t2_ub,
	PyDoc_STR("*float*: Period 10 Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p10_t3_dc", (getter)Common_get_ur_dc_p10_t3_dc,(setter)Common_set_ur_dc_p10_t3_dc,
	PyDoc_STR("*float*: Period 10 Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p10_t3_ub", (getter)Common_get_ur_dc_p10_t3_ub,(setter)Common_set_ur_dc_p10_t3_ub,
	PyDoc_STR("*float*: Period 10 Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p10_t4_dc", (getter)Common_get_ur_dc_p10_t4_dc,(setter)Common_set_ur_dc_p10_t4_dc,
	PyDoc_STR("*float*: Period 10 Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p10_t4_ub", (getter)Common_get_ur_dc_p10_t4_ub,(setter)Common_set_ur_dc_p10_t4_ub,
	PyDoc_STR("*float*: Period 10 Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p10_t5_dc", (getter)Common_get_ur_dc_p10_t5_dc,(setter)Common_set_ur_dc_p10_t5_dc,
	PyDoc_STR("*float*: Period 10 Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p10_t5_ub", (getter)Common_get_ur_dc_p10_t5_ub,(setter)Common_set_ur_dc_p10_t5_ub,
	PyDoc_STR("*float*: Period 10 Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p10_t6_dc", (getter)Common_get_ur_dc_p10_t6_dc,(setter)Common_set_ur_dc_p10_t6_dc,
	PyDoc_STR("*float*: Period 10 Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p10_t6_ub", (getter)Common_get_ur_dc_p10_t6_ub,(setter)Common_set_ur_dc_p10_t6_ub,
	PyDoc_STR("*float*: Period 10 Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p11_t1_dc", (getter)Common_get_ur_dc_p11_t1_dc,(setter)Common_set_ur_dc_p11_t1_dc,
	PyDoc_STR("*float*: Period 11 Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p11_t1_ub", (getter)Common_get_ur_dc_p11_t1_ub,(setter)Common_set_ur_dc_p11_t1_ub,
	PyDoc_STR("*float*: Period 11 Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p11_t2_dc", (getter)Common_get_ur_dc_p11_t2_dc,(setter)Common_set_ur_dc_p11_t2_dc,
	PyDoc_STR("*float*: Period 11 Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p11_t2_ub", (getter)Common_get_ur_dc_p11_t2_ub,(setter)Common_set_ur_dc_p11_t2_ub,
	PyDoc_STR("*float*: Period 11 Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p11_t3_dc", (getter)Common_get_ur_dc_p11_t3_dc,(setter)Common_set_ur_dc_p11_t3_dc,
	PyDoc_STR("*float*: Period 11 Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p11_t3_ub", (getter)Common_get_ur_dc_p11_t3_ub,(setter)Common_set_ur_dc_p11_t3_ub,
	PyDoc_STR("*float*: Period 11 Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p11_t4_dc", (getter)Common_get_ur_dc_p11_t4_dc,(setter)Common_set_ur_dc_p11_t4_dc,
	PyDoc_STR("*float*: Period 11 Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p11_t4_ub", (getter)Common_get_ur_dc_p11_t4_ub,(setter)Common_set_ur_dc_p11_t4_ub,
	PyDoc_STR("*float*: Period 11 Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p11_t5_dc", (getter)Common_get_ur_dc_p11_t5_dc,(setter)Common_set_ur_dc_p11_t5_dc,
	PyDoc_STR("*float*: Period 11 Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p11_t5_ub", (getter)Common_get_ur_dc_p11_t5_ub,(setter)Common_set_ur_dc_p11_t5_ub,
	PyDoc_STR("*float*: Period 11 Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p11_t6_dc", (getter)Common_get_ur_dc_p11_t6_dc,(setter)Common_set_ur_dc_p11_t6_dc,
	PyDoc_STR("*float*: Period 11 Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p11_t6_ub", (getter)Common_get_ur_dc_p11_t6_ub,(setter)Common_set_ur_dc_p11_t6_ub,
	PyDoc_STR("*float*: Period 11 Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p12_t1_dc", (getter)Common_get_ur_dc_p12_t1_dc,(setter)Common_set_ur_dc_p12_t1_dc,
	PyDoc_STR("*float*: Period 12 Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p12_t1_ub", (getter)Common_get_ur_dc_p12_t1_ub,(setter)Common_set_ur_dc_p12_t1_ub,
	PyDoc_STR("*float*: Period 12 Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p12_t2_dc", (getter)Common_get_ur_dc_p12_t2_dc,(setter)Common_set_ur_dc_p12_t2_dc,
	PyDoc_STR("*float*: Period 12 Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p12_t2_ub", (getter)Common_get_ur_dc_p12_t2_ub,(setter)Common_set_ur_dc_p12_t2_ub,
	PyDoc_STR("*float*: Period 12 Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p12_t3_dc", (getter)Common_get_ur_dc_p12_t3_dc,(setter)Common_set_ur_dc_p12_t3_dc,
	PyDoc_STR("*float*: Period 12 Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p12_t3_ub", (getter)Common_get_ur_dc_p12_t3_ub,(setter)Common_set_ur_dc_p12_t3_ub,
	PyDoc_STR("*float*: Period 12 Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p12_t4_dc", (getter)Common_get_ur_dc_p12_t4_dc,(setter)Common_set_ur_dc_p12_t4_dc,
	PyDoc_STR("*float*: Period 12 Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p12_t4_ub", (getter)Common_get_ur_dc_p12_t4_ub,(setter)Common_set_ur_dc_p12_t4_ub,
	PyDoc_STR("*float*: Period 12 Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p12_t5_dc", (getter)Common_get_ur_dc_p12_t5_dc,(setter)Common_set_ur_dc_p12_t5_dc,
	PyDoc_STR("*float*: Period 12 Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p12_t5_ub", (getter)Common_get_ur_dc_p12_t5_ub,(setter)Common_set_ur_dc_p12_t5_ub,
	PyDoc_STR("*float*: Period 12 Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p12_t6_dc", (getter)Common_get_ur_dc_p12_t6_dc,(setter)Common_set_ur_dc_p12_t6_dc,
	PyDoc_STR("*float*: Period 12 Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p12_t6_ub", (getter)Common_get_ur_dc_p12_t6_ub,(setter)Common_set_ur_dc_p12_t6_ub,
	PyDoc_STR("*float*: Period 12 Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p1_t1_dc", (getter)Common_get_ur_dc_p1_t1_dc,(setter)Common_set_ur_dc_p1_t1_dc,
	PyDoc_STR("*float*: Period 1 Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p1_t1_ub", (getter)Common_get_ur_dc_p1_t1_ub,(setter)Common_set_ur_dc_p1_t1_ub,
	PyDoc_STR("*float*: Period 1 Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p1_t2_dc", (getter)Common_get_ur_dc_p1_t2_dc,(setter)Common_set_ur_dc_p1_t2_dc,
	PyDoc_STR("*float*: Period 1 Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p1_t2_ub", (getter)Common_get_ur_dc_p1_t2_ub,(setter)Common_set_ur_dc_p1_t2_ub,
	PyDoc_STR("*float*: Period 1 Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p1_t3_dc", (getter)Common_get_ur_dc_p1_t3_dc,(setter)Common_set_ur_dc_p1_t3_dc,
	PyDoc_STR("*float*: Period 1 Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p1_t3_ub", (getter)Common_get_ur_dc_p1_t3_ub,(setter)Common_set_ur_dc_p1_t3_ub,
	PyDoc_STR("*float*: Period 1 Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p1_t4_dc", (getter)Common_get_ur_dc_p1_t4_dc,(setter)Common_set_ur_dc_p1_t4_dc,
	PyDoc_STR("*float*: Period 1 Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p1_t4_ub", (getter)Common_get_ur_dc_p1_t4_ub,(setter)Common_set_ur_dc_p1_t4_ub,
	PyDoc_STR("*float*: Period 1 Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p1_t5_dc", (getter)Common_get_ur_dc_p1_t5_dc,(setter)Common_set_ur_dc_p1_t5_dc,
	PyDoc_STR("*float*: Period 1 Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p1_t5_ub", (getter)Common_get_ur_dc_p1_t5_ub,(setter)Common_set_ur_dc_p1_t5_ub,
	PyDoc_STR("*float*: Period 1 Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p1_t6_dc", (getter)Common_get_ur_dc_p1_t6_dc,(setter)Common_set_ur_dc_p1_t6_dc,
	PyDoc_STR("*float*: Period 1 Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p1_t6_ub", (getter)Common_get_ur_dc_p1_t6_ub,(setter)Common_set_ur_dc_p1_t6_ub,
	PyDoc_STR("*float*: Period 1 Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p2_t1_dc", (getter)Common_get_ur_dc_p2_t1_dc,(setter)Common_set_ur_dc_p2_t1_dc,
	PyDoc_STR("*float*: Period 2 Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p2_t1_ub", (getter)Common_get_ur_dc_p2_t1_ub,(setter)Common_set_ur_dc_p2_t1_ub,
	PyDoc_STR("*float*: Period 2 Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p2_t2_dc", (getter)Common_get_ur_dc_p2_t2_dc,(setter)Common_set_ur_dc_p2_t2_dc,
	PyDoc_STR("*float*: Period 2 Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p2_t2_ub", (getter)Common_get_ur_dc_p2_t2_ub,(setter)Common_set_ur_dc_p2_t2_ub,
	PyDoc_STR("*float*: Period 2 Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p2_t3_dc", (getter)Common_get_ur_dc_p2_t3_dc,(setter)Common_set_ur_dc_p2_t3_dc,
	PyDoc_STR("*float*: Period 2 Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p2_t3_ub", (getter)Common_get_ur_dc_p2_t3_ub,(setter)Common_set_ur_dc_p2_t3_ub,
	PyDoc_STR("*float*: Period 2 Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p2_t4_dc", (getter)Common_get_ur_dc_p2_t4_dc,(setter)Common_set_ur_dc_p2_t4_dc,
	PyDoc_STR("*float*: Period 2 Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p2_t4_ub", (getter)Common_get_ur_dc_p2_t4_ub,(setter)Common_set_ur_dc_p2_t4_ub,
	PyDoc_STR("*float*: Period 2 Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p2_t5_dc", (getter)Common_get_ur_dc_p2_t5_dc,(setter)Common_set_ur_dc_p2_t5_dc,
	PyDoc_STR("*float*: Period 2 Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p2_t5_ub", (getter)Common_get_ur_dc_p2_t5_ub,(setter)Common_set_ur_dc_p2_t5_ub,
	PyDoc_STR("*float*: Period 2 Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p2_t6_dc", (getter)Common_get_ur_dc_p2_t6_dc,(setter)Common_set_ur_dc_p2_t6_dc,
	PyDoc_STR("*float*: Period 2 Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p2_t6_ub", (getter)Common_get_ur_dc_p2_t6_ub,(setter)Common_set_ur_dc_p2_t6_ub,
	PyDoc_STR("*float*: Period 2 Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p3_t1_dc", (getter)Common_get_ur_dc_p3_t1_dc,(setter)Common_set_ur_dc_p3_t1_dc,
	PyDoc_STR("*float*: Period 3 Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p3_t1_ub", (getter)Common_get_ur_dc_p3_t1_ub,(setter)Common_set_ur_dc_p3_t1_ub,
	PyDoc_STR("*float*: Period 3 Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p3_t2_dc", (getter)Common_get_ur_dc_p3_t2_dc,(setter)Common_set_ur_dc_p3_t2_dc,
	PyDoc_STR("*float*: Period 3 Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p3_t2_ub", (getter)Common_get_ur_dc_p3_t2_ub,(setter)Common_set_ur_dc_p3_t2_ub,
	PyDoc_STR("*float*: Period 3 Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p3_t3_dc", (getter)Common_get_ur_dc_p3_t3_dc,(setter)Common_set_ur_dc_p3_t3_dc,
	PyDoc_STR("*float*: Period 3 Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p3_t3_ub", (getter)Common_get_ur_dc_p3_t3_ub,(setter)Common_set_ur_dc_p3_t3_ub,
	PyDoc_STR("*float*: Period 3 Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p3_t4_dc", (getter)Common_get_ur_dc_p3_t4_dc,(setter)Common_set_ur_dc_p3_t4_dc,
	PyDoc_STR("*float*: Period 3 Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p3_t4_ub", (getter)Common_get_ur_dc_p3_t4_ub,(setter)Common_set_ur_dc_p3_t4_ub,
	PyDoc_STR("*float*: Period 3 Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p3_t5_dc", (getter)Common_get_ur_dc_p3_t5_dc,(setter)Common_set_ur_dc_p3_t5_dc,
	PyDoc_STR("*float*: Period 3 Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p3_t5_ub", (getter)Common_get_ur_dc_p3_t5_ub,(setter)Common_set_ur_dc_p3_t5_ub,
	PyDoc_STR("*float*: Period 3 Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p3_t6_dc", (getter)Common_get_ur_dc_p3_t6_dc,(setter)Common_set_ur_dc_p3_t6_dc,
	PyDoc_STR("*float*: Period 3 Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p3_t6_ub", (getter)Common_get_ur_dc_p3_t6_ub,(setter)Common_set_ur_dc_p3_t6_ub,
	PyDoc_STR("*float*: Period 3 Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p4_t1_dc", (getter)Common_get_ur_dc_p4_t1_dc,(setter)Common_set_ur_dc_p4_t1_dc,
	PyDoc_STR("*float*: Period 4 Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p4_t1_ub", (getter)Common_get_ur_dc_p4_t1_ub,(setter)Common_set_ur_dc_p4_t1_ub,
	PyDoc_STR("*float*: Period 4 Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p4_t2_dc", (getter)Common_get_ur_dc_p4_t2_dc,(setter)Common_set_ur_dc_p4_t2_dc,
	PyDoc_STR("*float*: Period 4 Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p4_t2_ub", (getter)Common_get_ur_dc_p4_t2_ub,(setter)Common_set_ur_dc_p4_t2_ub,
	PyDoc_STR("*float*: Period 4 Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p4_t3_dc", (getter)Common_get_ur_dc_p4_t3_dc,(setter)Common_set_ur_dc_p4_t3_dc,
	PyDoc_STR("*float*: Period 4 Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p4_t3_ub", (getter)Common_get_ur_dc_p4_t3_ub,(setter)Common_set_ur_dc_p4_t3_ub,
	PyDoc_STR("*float*: Period 4 Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p4_t4_dc", (getter)Common_get_ur_dc_p4_t4_dc,(setter)Common_set_ur_dc_p4_t4_dc,
	PyDoc_STR("*float*: Period 4 Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p4_t4_ub", (getter)Common_get_ur_dc_p4_t4_ub,(setter)Common_set_ur_dc_p4_t4_ub,
	PyDoc_STR("*float*: Period 4 Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p4_t5_dc", (getter)Common_get_ur_dc_p4_t5_dc,(setter)Common_set_ur_dc_p4_t5_dc,
	PyDoc_STR("*float*: Period 4 Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p4_t5_ub", (getter)Common_get_ur_dc_p4_t5_ub,(setter)Common_set_ur_dc_p4_t5_ub,
	PyDoc_STR("*float*: Period 4 Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p4_t6_dc", (getter)Common_get_ur_dc_p4_t6_dc,(setter)Common_set_ur_dc_p4_t6_dc,
	PyDoc_STR("*float*: Period 4 Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p4_t6_ub", (getter)Common_get_ur_dc_p4_t6_ub,(setter)Common_set_ur_dc_p4_t6_ub,
	PyDoc_STR("*float*: Period 4 Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p5_t1_dc", (getter)Common_get_ur_dc_p5_t1_dc,(setter)Common_set_ur_dc_p5_t1_dc,
	PyDoc_STR("*float*: Period 5 Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p5_t1_ub", (getter)Common_get_ur_dc_p5_t1_ub,(setter)Common_set_ur_dc_p5_t1_ub,
	PyDoc_STR("*float*: Period 5 Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p5_t2_dc", (getter)Common_get_ur_dc_p5_t2_dc,(setter)Common_set_ur_dc_p5_t2_dc,
	PyDoc_STR("*float*: Period 5 Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p5_t2_ub", (getter)Common_get_ur_dc_p5_t2_ub,(setter)Common_set_ur_dc_p5_t2_ub,
	PyDoc_STR("*float*: Period 5 Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p5_t3_dc", (getter)Common_get_ur_dc_p5_t3_dc,(setter)Common_set_ur_dc_p5_t3_dc,
	PyDoc_STR("*float*: Period 5 Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p5_t3_ub", (getter)Common_get_ur_dc_p5_t3_ub,(setter)Common_set_ur_dc_p5_t3_ub,
	PyDoc_STR("*float*: Period 5 Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p5_t4_dc", (getter)Common_get_ur_dc_p5_t4_dc,(setter)Common_set_ur_dc_p5_t4_dc,
	PyDoc_STR("*float*: Period 5 Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p5_t4_ub", (getter)Common_get_ur_dc_p5_t4_ub,(setter)Common_set_ur_dc_p5_t4_ub,
	PyDoc_STR("*float*: Period 5 Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p5_t5_dc", (getter)Common_get_ur_dc_p5_t5_dc,(setter)Common_set_ur_dc_p5_t5_dc,
	PyDoc_STR("*float*: Period 5 Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p5_t5_ub", (getter)Common_get_ur_dc_p5_t5_ub,(setter)Common_set_ur_dc_p5_t5_ub,
	PyDoc_STR("*float*: Period 5 Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p5_t6_dc", (getter)Common_get_ur_dc_p5_t6_dc,(setter)Common_set_ur_dc_p5_t6_dc,
	PyDoc_STR("*float*: Period 5 Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p5_t6_ub", (getter)Common_get_ur_dc_p5_t6_ub,(setter)Common_set_ur_dc_p5_t6_ub,
	PyDoc_STR("*float*: Period 5 Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p6_t1_dc", (getter)Common_get_ur_dc_p6_t1_dc,(setter)Common_set_ur_dc_p6_t1_dc,
	PyDoc_STR("*float*: Period 6 Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p6_t1_ub", (getter)Common_get_ur_dc_p6_t1_ub,(setter)Common_set_ur_dc_p6_t1_ub,
	PyDoc_STR("*float*: Period 6 Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p6_t2_dc", (getter)Common_get_ur_dc_p6_t2_dc,(setter)Common_set_ur_dc_p6_t2_dc,
	PyDoc_STR("*float*: Period 6 Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p6_t2_ub", (getter)Common_get_ur_dc_p6_t2_ub,(setter)Common_set_ur_dc_p6_t2_ub,
	PyDoc_STR("*float*: Period 6 Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p6_t3_dc", (getter)Common_get_ur_dc_p6_t3_dc,(setter)Common_set_ur_dc_p6_t3_dc,
	PyDoc_STR("*float*: Period 6 Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p6_t3_ub", (getter)Common_get_ur_dc_p6_t3_ub,(setter)Common_set_ur_dc_p6_t3_ub,
	PyDoc_STR("*float*: Period 6 Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p6_t4_dc", (getter)Common_get_ur_dc_p6_t4_dc,(setter)Common_set_ur_dc_p6_t4_dc,
	PyDoc_STR("*float*: Period 6 Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p6_t4_ub", (getter)Common_get_ur_dc_p6_t4_ub,(setter)Common_set_ur_dc_p6_t4_ub,
	PyDoc_STR("*float*: Period 6 Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p6_t5_dc", (getter)Common_get_ur_dc_p6_t5_dc,(setter)Common_set_ur_dc_p6_t5_dc,
	PyDoc_STR("*float*: Period 6 Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p6_t5_ub", (getter)Common_get_ur_dc_p6_t5_ub,(setter)Common_set_ur_dc_p6_t5_ub,
	PyDoc_STR("*float*: Period 6 Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p6_t6_dc", (getter)Common_get_ur_dc_p6_t6_dc,(setter)Common_set_ur_dc_p6_t6_dc,
	PyDoc_STR("*float*: Period 6 Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p6_t6_ub", (getter)Common_get_ur_dc_p6_t6_ub,(setter)Common_set_ur_dc_p6_t6_ub,
	PyDoc_STR("*float*: Period 6 Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p7_t1_dc", (getter)Common_get_ur_dc_p7_t1_dc,(setter)Common_set_ur_dc_p7_t1_dc,
	PyDoc_STR("*float*: Period 7 Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p7_t1_ub", (getter)Common_get_ur_dc_p7_t1_ub,(setter)Common_set_ur_dc_p7_t1_ub,
	PyDoc_STR("*float*: Period 7 Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p7_t2_dc", (getter)Common_get_ur_dc_p7_t2_dc,(setter)Common_set_ur_dc_p7_t2_dc,
	PyDoc_STR("*float*: Period 7 Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p7_t2_ub", (getter)Common_get_ur_dc_p7_t2_ub,(setter)Common_set_ur_dc_p7_t2_ub,
	PyDoc_STR("*float*: Period 7 Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p7_t3_dc", (getter)Common_get_ur_dc_p7_t3_dc,(setter)Common_set_ur_dc_p7_t3_dc,
	PyDoc_STR("*float*: Period 7 Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p7_t3_ub", (getter)Common_get_ur_dc_p7_t3_ub,(setter)Common_set_ur_dc_p7_t3_ub,
	PyDoc_STR("*float*: Period 7 Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p7_t4_dc", (getter)Common_get_ur_dc_p7_t4_dc,(setter)Common_set_ur_dc_p7_t4_dc,
	PyDoc_STR("*float*: Period 7 Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p7_t4_ub", (getter)Common_get_ur_dc_p7_t4_ub,(setter)Common_set_ur_dc_p7_t4_ub,
	PyDoc_STR("*float*: Period 7 Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p7_t5_dc", (getter)Common_get_ur_dc_p7_t5_dc,(setter)Common_set_ur_dc_p7_t5_dc,
	PyDoc_STR("*float*: Period 7 Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p7_t5_ub", (getter)Common_get_ur_dc_p7_t5_ub,(setter)Common_set_ur_dc_p7_t5_ub,
	PyDoc_STR("*float*: Period 7 Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p7_t6_dc", (getter)Common_get_ur_dc_p7_t6_dc,(setter)Common_set_ur_dc_p7_t6_dc,
	PyDoc_STR("*float*: Period 7 Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p7_t6_ub", (getter)Common_get_ur_dc_p7_t6_ub,(setter)Common_set_ur_dc_p7_t6_ub,
	PyDoc_STR("*float*: Period 7 Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p8_t1_dc", (getter)Common_get_ur_dc_p8_t1_dc,(setter)Common_set_ur_dc_p8_t1_dc,
	PyDoc_STR("*float*: Period 8 Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p8_t1_ub", (getter)Common_get_ur_dc_p8_t1_ub,(setter)Common_set_ur_dc_p8_t1_ub,
	PyDoc_STR("*float*: Period 8 Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p8_t2_dc", (getter)Common_get_ur_dc_p8_t2_dc,(setter)Common_set_ur_dc_p8_t2_dc,
	PyDoc_STR("*float*: Period 8 Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p8_t2_ub", (getter)Common_get_ur_dc_p8_t2_ub,(setter)Common_set_ur_dc_p8_t2_ub,
	PyDoc_STR("*float*: Period 8 Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p8_t3_dc", (getter)Common_get_ur_dc_p8_t3_dc,(setter)Common_set_ur_dc_p8_t3_dc,
	PyDoc_STR("*float*: Period 8 Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p8_t3_ub", (getter)Common_get_ur_dc_p8_t3_ub,(setter)Common_set_ur_dc_p8_t3_ub,
	PyDoc_STR("*float*: Period 8 Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p8_t4_dc", (getter)Common_get_ur_dc_p8_t4_dc,(setter)Common_set_ur_dc_p8_t4_dc,
	PyDoc_STR("*float*: Period 8 Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p8_t4_ub", (getter)Common_get_ur_dc_p8_t4_ub,(setter)Common_set_ur_dc_p8_t4_ub,
	PyDoc_STR("*float*: Period 8 Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p8_t5_dc", (getter)Common_get_ur_dc_p8_t5_dc,(setter)Common_set_ur_dc_p8_t5_dc,
	PyDoc_STR("*float*: Period 8 Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p8_t5_ub", (getter)Common_get_ur_dc_p8_t5_ub,(setter)Common_set_ur_dc_p8_t5_ub,
	PyDoc_STR("*float*: Period 8 Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p8_t6_dc", (getter)Common_get_ur_dc_p8_t6_dc,(setter)Common_set_ur_dc_p8_t6_dc,
	PyDoc_STR("*float*: Period 8 Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p8_t6_ub", (getter)Common_get_ur_dc_p8_t6_ub,(setter)Common_set_ur_dc_p8_t6_ub,
	PyDoc_STR("*float*: Period 8 Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p9_t1_dc", (getter)Common_get_ur_dc_p9_t1_dc,(setter)Common_set_ur_dc_p9_t1_dc,
	PyDoc_STR("*float*: Period 9 Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p9_t1_ub", (getter)Common_get_ur_dc_p9_t1_ub,(setter)Common_set_ur_dc_p9_t1_ub,
	PyDoc_STR("*float*: Period 9 Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p9_t2_dc", (getter)Common_get_ur_dc_p9_t2_dc,(setter)Common_set_ur_dc_p9_t2_dc,
	PyDoc_STR("*float*: Period 9 Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p9_t2_ub", (getter)Common_get_ur_dc_p9_t2_ub,(setter)Common_set_ur_dc_p9_t2_ub,
	PyDoc_STR("*float*: Period 9 Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p9_t3_dc", (getter)Common_get_ur_dc_p9_t3_dc,(setter)Common_set_ur_dc_p9_t3_dc,
	PyDoc_STR("*float*: Period 9 Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p9_t3_ub", (getter)Common_get_ur_dc_p9_t3_ub,(setter)Common_set_ur_dc_p9_t3_ub,
	PyDoc_STR("*float*: Period 9 Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p9_t4_dc", (getter)Common_get_ur_dc_p9_t4_dc,(setter)Common_set_ur_dc_p9_t4_dc,
	PyDoc_STR("*float*: Period 9 Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p9_t4_ub", (getter)Common_get_ur_dc_p9_t4_ub,(setter)Common_set_ur_dc_p9_t4_ub,
	PyDoc_STR("*float*: Period 9 Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p9_t5_dc", (getter)Common_get_ur_dc_p9_t5_dc,(setter)Common_set_ur_dc_p9_t5_dc,
	PyDoc_STR("*float*: Period 9 Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p9_t5_ub", (getter)Common_get_ur_dc_p9_t5_ub,(setter)Common_set_ur_dc_p9_t5_ub,
	PyDoc_STR("*float*: Period 9 Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p9_t6_dc", (getter)Common_get_ur_dc_p9_t6_dc,(setter)Common_set_ur_dc_p9_t6_dc,
	PyDoc_STR("*float*: Period 9 Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_p9_t6_ub", (getter)Common_get_ur_dc_p9_t6_ub,(setter)Common_set_ur_dc_p9_t6_ub,
	PyDoc_STR("*float*: Period 9 Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_sched_weekday", (getter)Common_get_ur_dc_sched_weekday,(setter)Common_set_ur_dc_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: Demend Charge Weekday Schedule\n\n**Info:**\n12x24"),
 	NULL},
{"ur_dc_sched_weekend", (getter)Common_get_ur_dc_sched_weekend,(setter)Common_set_ur_dc_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Demend Charge Weekend Schedule\n\n**Info:**\n12x24"),
 	NULL},
{"ur_dc_sep_t1_dc", (getter)Common_get_ur_dc_sep_t1_dc,(setter)Common_set_ur_dc_sep_t1_dc,
	PyDoc_STR("*float*: September Tier 1 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_sep_t1_ub", (getter)Common_get_ur_dc_sep_t1_ub,(setter)Common_set_ur_dc_sep_t1_ub,
	PyDoc_STR("*float*: September Tier 1 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_sep_t2_dc", (getter)Common_get_ur_dc_sep_t2_dc,(setter)Common_set_ur_dc_sep_t2_dc,
	PyDoc_STR("*float*: September Tier 2 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_sep_t2_ub", (getter)Common_get_ur_dc_sep_t2_ub,(setter)Common_set_ur_dc_sep_t2_ub,
	PyDoc_STR("*float*: September Tier 2 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_sep_t3_dc", (getter)Common_get_ur_dc_sep_t3_dc,(setter)Common_set_ur_dc_sep_t3_dc,
	PyDoc_STR("*float*: September Tier 3 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_sep_t3_ub", (getter)Common_get_ur_dc_sep_t3_ub,(setter)Common_set_ur_dc_sep_t3_ub,
	PyDoc_STR("*float*: September Tier 3 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_sep_t4_dc", (getter)Common_get_ur_dc_sep_t4_dc,(setter)Common_set_ur_dc_sep_t4_dc,
	PyDoc_STR("*float*: September Tier 4 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_sep_t4_ub", (getter)Common_get_ur_dc_sep_t4_ub,(setter)Common_set_ur_dc_sep_t4_ub,
	PyDoc_STR("*float*: September Tier 4 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_sep_t5_dc", (getter)Common_get_ur_dc_sep_t5_dc,(setter)Common_set_ur_dc_sep_t5_dc,
	PyDoc_STR("*float*: September Tier 5 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_sep_t5_ub", (getter)Common_get_ur_dc_sep_t5_ub,(setter)Common_set_ur_dc_sep_t5_ub,
	PyDoc_STR("*float*: September Tier 5 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_sep_t6_dc", (getter)Common_get_ur_dc_sep_t6_dc,(setter)Common_set_ur_dc_sep_t6_dc,
	PyDoc_STR("*float*: September Tier 6 Demand Charge [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_sep_t6_ub", (getter)Common_get_ur_dc_sep_t6_ub,(setter)Common_set_ur_dc_sep_t6_ub,
	PyDoc_STR("*float*: September Tier 6 Peak Demand [kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_enable", (getter)Common_get_ur_ec_enable,(setter)Common_set_ur_ec_enable,
	PyDoc_STR("*float*: Enable energy charge [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p10_t1_br", (getter)Common_get_ur_ec_p10_t1_br,(setter)Common_set_ur_ec_p10_t1_br,
	PyDoc_STR("*float*: Period 10 Tier 1 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p10_t1_sr", (getter)Common_get_ur_ec_p10_t1_sr,(setter)Common_set_ur_ec_p10_t1_sr,
	PyDoc_STR("*float*: Period 10 Tier 1 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p10_t1_ub", (getter)Common_get_ur_ec_p10_t1_ub,(setter)Common_set_ur_ec_p10_t1_ub,
	PyDoc_STR("*float*: Period 10 Tier 1 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p10_t2_br", (getter)Common_get_ur_ec_p10_t2_br,(setter)Common_set_ur_ec_p10_t2_br,
	PyDoc_STR("*float*: Period 10 Tier 2 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p10_t2_sr", (getter)Common_get_ur_ec_p10_t2_sr,(setter)Common_set_ur_ec_p10_t2_sr,
	PyDoc_STR("*float*: Period 10 Tier 2 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p10_t2_ub", (getter)Common_get_ur_ec_p10_t2_ub,(setter)Common_set_ur_ec_p10_t2_ub,
	PyDoc_STR("*float*: Period 10 Tier 2 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p10_t3_br", (getter)Common_get_ur_ec_p10_t3_br,(setter)Common_set_ur_ec_p10_t3_br,
	PyDoc_STR("*float*: Period 10 Tier 3 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p10_t3_sr", (getter)Common_get_ur_ec_p10_t3_sr,(setter)Common_set_ur_ec_p10_t3_sr,
	PyDoc_STR("*float*: Period 10 Tier 3 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p10_t3_ub", (getter)Common_get_ur_ec_p10_t3_ub,(setter)Common_set_ur_ec_p10_t3_ub,
	PyDoc_STR("*float*: Period 10 Tier 3 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p10_t4_br", (getter)Common_get_ur_ec_p10_t4_br,(setter)Common_set_ur_ec_p10_t4_br,
	PyDoc_STR("*float*: Period 10 Tier 4 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p10_t4_sr", (getter)Common_get_ur_ec_p10_t4_sr,(setter)Common_set_ur_ec_p10_t4_sr,
	PyDoc_STR("*float*: Period 10 Tier 4 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p10_t4_ub", (getter)Common_get_ur_ec_p10_t4_ub,(setter)Common_set_ur_ec_p10_t4_ub,
	PyDoc_STR("*float*: Period 10 Tier 4 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p10_t5_br", (getter)Common_get_ur_ec_p10_t5_br,(setter)Common_set_ur_ec_p10_t5_br,
	PyDoc_STR("*float*: Period 10 Tier 5 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p10_t5_sr", (getter)Common_get_ur_ec_p10_t5_sr,(setter)Common_set_ur_ec_p10_t5_sr,
	PyDoc_STR("*float*: Period 10 Tier 5 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p10_t5_ub", (getter)Common_get_ur_ec_p10_t5_ub,(setter)Common_set_ur_ec_p10_t5_ub,
	PyDoc_STR("*float*: Period 10 Tier 5 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p10_t6_br", (getter)Common_get_ur_ec_p10_t6_br,(setter)Common_set_ur_ec_p10_t6_br,
	PyDoc_STR("*float*: Period 10 Tier 6 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p10_t6_sr", (getter)Common_get_ur_ec_p10_t6_sr,(setter)Common_set_ur_ec_p10_t6_sr,
	PyDoc_STR("*float*: Period 10 Tier 6 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p10_t6_ub", (getter)Common_get_ur_ec_p10_t6_ub,(setter)Common_set_ur_ec_p10_t6_ub,
	PyDoc_STR("*float*: Period 10 Tier 6 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p11_t1_br", (getter)Common_get_ur_ec_p11_t1_br,(setter)Common_set_ur_ec_p11_t1_br,
	PyDoc_STR("*float*: Period 11 Tier 1 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p11_t1_sr", (getter)Common_get_ur_ec_p11_t1_sr,(setter)Common_set_ur_ec_p11_t1_sr,
	PyDoc_STR("*float*: Period 11 Tier 1 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p11_t1_ub", (getter)Common_get_ur_ec_p11_t1_ub,(setter)Common_set_ur_ec_p11_t1_ub,
	PyDoc_STR("*float*: Period 11 Tier 1 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p11_t2_br", (getter)Common_get_ur_ec_p11_t2_br,(setter)Common_set_ur_ec_p11_t2_br,
	PyDoc_STR("*float*: Period 11 Tier 2 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p11_t2_sr", (getter)Common_get_ur_ec_p11_t2_sr,(setter)Common_set_ur_ec_p11_t2_sr,
	PyDoc_STR("*float*: Period 11 Tier 2 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p11_t2_ub", (getter)Common_get_ur_ec_p11_t2_ub,(setter)Common_set_ur_ec_p11_t2_ub,
	PyDoc_STR("*float*: Period 11 Tier 2 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p11_t3_br", (getter)Common_get_ur_ec_p11_t3_br,(setter)Common_set_ur_ec_p11_t3_br,
	PyDoc_STR("*float*: Period 11 Tier 3 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p11_t3_sr", (getter)Common_get_ur_ec_p11_t3_sr,(setter)Common_set_ur_ec_p11_t3_sr,
	PyDoc_STR("*float*: Period 11 Tier 3 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p11_t3_ub", (getter)Common_get_ur_ec_p11_t3_ub,(setter)Common_set_ur_ec_p11_t3_ub,
	PyDoc_STR("*float*: Period 11 Tier 3 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p11_t4_br", (getter)Common_get_ur_ec_p11_t4_br,(setter)Common_set_ur_ec_p11_t4_br,
	PyDoc_STR("*float*: Period 11 Tier 4 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p11_t4_sr", (getter)Common_get_ur_ec_p11_t4_sr,(setter)Common_set_ur_ec_p11_t4_sr,
	PyDoc_STR("*float*: Period 11 Tier 4 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p11_t4_ub", (getter)Common_get_ur_ec_p11_t4_ub,(setter)Common_set_ur_ec_p11_t4_ub,
	PyDoc_STR("*float*: Period 11 Tier 4 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p11_t5_br", (getter)Common_get_ur_ec_p11_t5_br,(setter)Common_set_ur_ec_p11_t5_br,
	PyDoc_STR("*float*: Period 11 Tier 5 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p11_t5_sr", (getter)Common_get_ur_ec_p11_t5_sr,(setter)Common_set_ur_ec_p11_t5_sr,
	PyDoc_STR("*float*: Period 11 Tier 5 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p11_t5_ub", (getter)Common_get_ur_ec_p11_t5_ub,(setter)Common_set_ur_ec_p11_t5_ub,
	PyDoc_STR("*float*: Period 11 Tier 5 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p11_t6_br", (getter)Common_get_ur_ec_p11_t6_br,(setter)Common_set_ur_ec_p11_t6_br,
	PyDoc_STR("*float*: Period 11 Tier 6 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p11_t6_sr", (getter)Common_get_ur_ec_p11_t6_sr,(setter)Common_set_ur_ec_p11_t6_sr,
	PyDoc_STR("*float*: Period 11 Tier 6 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p11_t6_ub", (getter)Common_get_ur_ec_p11_t6_ub,(setter)Common_set_ur_ec_p11_t6_ub,
	PyDoc_STR("*float*: Period 11 Tier 6 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p12_t1_br", (getter)Common_get_ur_ec_p12_t1_br,(setter)Common_set_ur_ec_p12_t1_br,
	PyDoc_STR("*float*: Period 12 Tier 1 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p12_t1_sr", (getter)Common_get_ur_ec_p12_t1_sr,(setter)Common_set_ur_ec_p12_t1_sr,
	PyDoc_STR("*float*: Period 12 Tier 1 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p12_t1_ub", (getter)Common_get_ur_ec_p12_t1_ub,(setter)Common_set_ur_ec_p12_t1_ub,
	PyDoc_STR("*float*: Period 12 Tier 1 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p12_t2_br", (getter)Common_get_ur_ec_p12_t2_br,(setter)Common_set_ur_ec_p12_t2_br,
	PyDoc_STR("*float*: Period 12 Tier 2 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p12_t2_sr", (getter)Common_get_ur_ec_p12_t2_sr,(setter)Common_set_ur_ec_p12_t2_sr,
	PyDoc_STR("*float*: Period 12 Tier 2 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p12_t2_ub", (getter)Common_get_ur_ec_p12_t2_ub,(setter)Common_set_ur_ec_p12_t2_ub,
	PyDoc_STR("*float*: Period 12 Tier 2 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p12_t3_br", (getter)Common_get_ur_ec_p12_t3_br,(setter)Common_set_ur_ec_p12_t3_br,
	PyDoc_STR("*float*: Period 12 Tier 3 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p12_t3_sr", (getter)Common_get_ur_ec_p12_t3_sr,(setter)Common_set_ur_ec_p12_t3_sr,
	PyDoc_STR("*float*: Period 12 Tier 3 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p12_t3_ub", (getter)Common_get_ur_ec_p12_t3_ub,(setter)Common_set_ur_ec_p12_t3_ub,
	PyDoc_STR("*float*: Period 12 Tier 3 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p12_t4_br", (getter)Common_get_ur_ec_p12_t4_br,(setter)Common_set_ur_ec_p12_t4_br,
	PyDoc_STR("*float*: Period 12 Tier 4 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p12_t4_sr", (getter)Common_get_ur_ec_p12_t4_sr,(setter)Common_set_ur_ec_p12_t4_sr,
	PyDoc_STR("*float*: Period 12 Tier 4 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p12_t4_ub", (getter)Common_get_ur_ec_p12_t4_ub,(setter)Common_set_ur_ec_p12_t4_ub,
	PyDoc_STR("*float*: Period 12 Tier 4 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p12_t5_br", (getter)Common_get_ur_ec_p12_t5_br,(setter)Common_set_ur_ec_p12_t5_br,
	PyDoc_STR("*float*: Period 12 Tier 5 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p12_t5_sr", (getter)Common_get_ur_ec_p12_t5_sr,(setter)Common_set_ur_ec_p12_t5_sr,
	PyDoc_STR("*float*: Period 12 Tier 5 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p12_t5_ub", (getter)Common_get_ur_ec_p12_t5_ub,(setter)Common_set_ur_ec_p12_t5_ub,
	PyDoc_STR("*float*: Period 12 Tier 5 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p12_t6_br", (getter)Common_get_ur_ec_p12_t6_br,(setter)Common_set_ur_ec_p12_t6_br,
	PyDoc_STR("*float*: Period 12 Tier 6 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p12_t6_sr", (getter)Common_get_ur_ec_p12_t6_sr,(setter)Common_set_ur_ec_p12_t6_sr,
	PyDoc_STR("*float*: Period 12 Tier 6 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p12_t6_ub", (getter)Common_get_ur_ec_p12_t6_ub,(setter)Common_set_ur_ec_p12_t6_ub,
	PyDoc_STR("*float*: Period 12 Tier 6 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p1_t1_br", (getter)Common_get_ur_ec_p1_t1_br,(setter)Common_set_ur_ec_p1_t1_br,
	PyDoc_STR("*float*: Period 1 Tier 1 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p1_t1_sr", (getter)Common_get_ur_ec_p1_t1_sr,(setter)Common_set_ur_ec_p1_t1_sr,
	PyDoc_STR("*float*: Period 1 Tier 1 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p1_t1_ub", (getter)Common_get_ur_ec_p1_t1_ub,(setter)Common_set_ur_ec_p1_t1_ub,
	PyDoc_STR("*float*: Period 1 Tier 1 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p1_t2_br", (getter)Common_get_ur_ec_p1_t2_br,(setter)Common_set_ur_ec_p1_t2_br,
	PyDoc_STR("*float*: Period 1 Tier 2 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p1_t2_sr", (getter)Common_get_ur_ec_p1_t2_sr,(setter)Common_set_ur_ec_p1_t2_sr,
	PyDoc_STR("*float*: Period 1 Tier 2 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p1_t2_ub", (getter)Common_get_ur_ec_p1_t2_ub,(setter)Common_set_ur_ec_p1_t2_ub,
	PyDoc_STR("*float*: Period 1 Tier 2 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p1_t3_br", (getter)Common_get_ur_ec_p1_t3_br,(setter)Common_set_ur_ec_p1_t3_br,
	PyDoc_STR("*float*: Period 1 Tier 3 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p1_t3_sr", (getter)Common_get_ur_ec_p1_t3_sr,(setter)Common_set_ur_ec_p1_t3_sr,
	PyDoc_STR("*float*: Period 1 Tier 3 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p1_t3_ub", (getter)Common_get_ur_ec_p1_t3_ub,(setter)Common_set_ur_ec_p1_t3_ub,
	PyDoc_STR("*float*: Period 1 Tier 3 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p1_t4_br", (getter)Common_get_ur_ec_p1_t4_br,(setter)Common_set_ur_ec_p1_t4_br,
	PyDoc_STR("*float*: Period 1 Tier 4 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p1_t4_sr", (getter)Common_get_ur_ec_p1_t4_sr,(setter)Common_set_ur_ec_p1_t4_sr,
	PyDoc_STR("*float*: Period 1 Tier 4 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p1_t4_ub", (getter)Common_get_ur_ec_p1_t4_ub,(setter)Common_set_ur_ec_p1_t4_ub,
	PyDoc_STR("*float*: Period 1 Tier 4 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p1_t5_br", (getter)Common_get_ur_ec_p1_t5_br,(setter)Common_set_ur_ec_p1_t5_br,
	PyDoc_STR("*float*: Period 1 Tier 5 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p1_t5_sr", (getter)Common_get_ur_ec_p1_t5_sr,(setter)Common_set_ur_ec_p1_t5_sr,
	PyDoc_STR("*float*: Period 1 Tier 5 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p1_t5_ub", (getter)Common_get_ur_ec_p1_t5_ub,(setter)Common_set_ur_ec_p1_t5_ub,
	PyDoc_STR("*float*: Period 1 Tier 5 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p1_t6_br", (getter)Common_get_ur_ec_p1_t6_br,(setter)Common_set_ur_ec_p1_t6_br,
	PyDoc_STR("*float*: Period 1 Tier 6 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p1_t6_sr", (getter)Common_get_ur_ec_p1_t6_sr,(setter)Common_set_ur_ec_p1_t6_sr,
	PyDoc_STR("*float*: Period 1 Tier 6 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p1_t6_ub", (getter)Common_get_ur_ec_p1_t6_ub,(setter)Common_set_ur_ec_p1_t6_ub,
	PyDoc_STR("*float*: Period 1 Tier 6 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p2_t1_br", (getter)Common_get_ur_ec_p2_t1_br,(setter)Common_set_ur_ec_p2_t1_br,
	PyDoc_STR("*float*: Period 2 Tier 1 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p2_t1_sr", (getter)Common_get_ur_ec_p2_t1_sr,(setter)Common_set_ur_ec_p2_t1_sr,
	PyDoc_STR("*float*: Period 2 Tier 1 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p2_t1_ub", (getter)Common_get_ur_ec_p2_t1_ub,(setter)Common_set_ur_ec_p2_t1_ub,
	PyDoc_STR("*float*: Period 2 Tier 1 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p2_t2_br", (getter)Common_get_ur_ec_p2_t2_br,(setter)Common_set_ur_ec_p2_t2_br,
	PyDoc_STR("*float*: Period 2 Tier 2 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p2_t2_sr", (getter)Common_get_ur_ec_p2_t2_sr,(setter)Common_set_ur_ec_p2_t2_sr,
	PyDoc_STR("*float*: Period 2 Tier 2 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p2_t2_ub", (getter)Common_get_ur_ec_p2_t2_ub,(setter)Common_set_ur_ec_p2_t2_ub,
	PyDoc_STR("*float*: Period 2 Tier 2 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p2_t3_br", (getter)Common_get_ur_ec_p2_t3_br,(setter)Common_set_ur_ec_p2_t3_br,
	PyDoc_STR("*float*: Period 2 Tier 3 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p2_t3_sr", (getter)Common_get_ur_ec_p2_t3_sr,(setter)Common_set_ur_ec_p2_t3_sr,
	PyDoc_STR("*float*: Period 2 Tier 3 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p2_t3_ub", (getter)Common_get_ur_ec_p2_t3_ub,(setter)Common_set_ur_ec_p2_t3_ub,
	PyDoc_STR("*float*: Period 2 Tier 3 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p2_t4_br", (getter)Common_get_ur_ec_p2_t4_br,(setter)Common_set_ur_ec_p2_t4_br,
	PyDoc_STR("*float*: Period 2 Tier 4 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p2_t4_sr", (getter)Common_get_ur_ec_p2_t4_sr,(setter)Common_set_ur_ec_p2_t4_sr,
	PyDoc_STR("*float*: Period 2 Tier 4 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p2_t4_ub", (getter)Common_get_ur_ec_p2_t4_ub,(setter)Common_set_ur_ec_p2_t4_ub,
	PyDoc_STR("*float*: Period 2 Tier 4 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p2_t5_br", (getter)Common_get_ur_ec_p2_t5_br,(setter)Common_set_ur_ec_p2_t5_br,
	PyDoc_STR("*float*: Period 2 Tier 5 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p2_t5_sr", (getter)Common_get_ur_ec_p2_t5_sr,(setter)Common_set_ur_ec_p2_t5_sr,
	PyDoc_STR("*float*: Period 2 Tier 5 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p2_t5_ub", (getter)Common_get_ur_ec_p2_t5_ub,(setter)Common_set_ur_ec_p2_t5_ub,
	PyDoc_STR("*float*: Period 2 Tier 5 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p2_t6_br", (getter)Common_get_ur_ec_p2_t6_br,(setter)Common_set_ur_ec_p2_t6_br,
	PyDoc_STR("*float*: Period 2 Tier 6 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p2_t6_sr", (getter)Common_get_ur_ec_p2_t6_sr,(setter)Common_set_ur_ec_p2_t6_sr,
	PyDoc_STR("*float*: Period 2 Tier 6 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p2_t6_ub", (getter)Common_get_ur_ec_p2_t6_ub,(setter)Common_set_ur_ec_p2_t6_ub,
	PyDoc_STR("*float*: Period 2 Tier 6 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p3_t1_br", (getter)Common_get_ur_ec_p3_t1_br,(setter)Common_set_ur_ec_p3_t1_br,
	PyDoc_STR("*float*: Period 3 Tier 1 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p3_t1_sr", (getter)Common_get_ur_ec_p3_t1_sr,(setter)Common_set_ur_ec_p3_t1_sr,
	PyDoc_STR("*float*: Period 3 Tier 1 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p3_t1_ub", (getter)Common_get_ur_ec_p3_t1_ub,(setter)Common_set_ur_ec_p3_t1_ub,
	PyDoc_STR("*float*: Period 3 Tier 1 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p3_t2_br", (getter)Common_get_ur_ec_p3_t2_br,(setter)Common_set_ur_ec_p3_t2_br,
	PyDoc_STR("*float*: Period 3 Tier 2 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p3_t2_sr", (getter)Common_get_ur_ec_p3_t2_sr,(setter)Common_set_ur_ec_p3_t2_sr,
	PyDoc_STR("*float*: Period 3 Tier 2 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p3_t2_ub", (getter)Common_get_ur_ec_p3_t2_ub,(setter)Common_set_ur_ec_p3_t2_ub,
	PyDoc_STR("*float*: Period 3 Tier 2 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p3_t3_br", (getter)Common_get_ur_ec_p3_t3_br,(setter)Common_set_ur_ec_p3_t3_br,
	PyDoc_STR("*float*: Period 3 Tier 3 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p3_t3_sr", (getter)Common_get_ur_ec_p3_t3_sr,(setter)Common_set_ur_ec_p3_t3_sr,
	PyDoc_STR("*float*: Period 3 Tier 3 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p3_t3_ub", (getter)Common_get_ur_ec_p3_t3_ub,(setter)Common_set_ur_ec_p3_t3_ub,
	PyDoc_STR("*float*: Period 3 Tier 3 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p3_t4_br", (getter)Common_get_ur_ec_p3_t4_br,(setter)Common_set_ur_ec_p3_t4_br,
	PyDoc_STR("*float*: Period 3 Tier 4 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p3_t4_sr", (getter)Common_get_ur_ec_p3_t4_sr,(setter)Common_set_ur_ec_p3_t4_sr,
	PyDoc_STR("*float*: Period 3 Tier 4 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p3_t4_ub", (getter)Common_get_ur_ec_p3_t4_ub,(setter)Common_set_ur_ec_p3_t4_ub,
	PyDoc_STR("*float*: Period 3 Tier 4 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p3_t5_br", (getter)Common_get_ur_ec_p3_t5_br,(setter)Common_set_ur_ec_p3_t5_br,
	PyDoc_STR("*float*: Period 3 Tier 5 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p3_t5_sr", (getter)Common_get_ur_ec_p3_t5_sr,(setter)Common_set_ur_ec_p3_t5_sr,
	PyDoc_STR("*float*: Period 3 Tier 5 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p3_t5_ub", (getter)Common_get_ur_ec_p3_t5_ub,(setter)Common_set_ur_ec_p3_t5_ub,
	PyDoc_STR("*float*: Period 3 Tier 5 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p3_t6_br", (getter)Common_get_ur_ec_p3_t6_br,(setter)Common_set_ur_ec_p3_t6_br,
	PyDoc_STR("*float*: Period 3 Tier 6 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p3_t6_sr", (getter)Common_get_ur_ec_p3_t6_sr,(setter)Common_set_ur_ec_p3_t6_sr,
	PyDoc_STR("*float*: Period 3 Tier 6 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p3_t6_ub", (getter)Common_get_ur_ec_p3_t6_ub,(setter)Common_set_ur_ec_p3_t6_ub,
	PyDoc_STR("*float*: Period 3 Tier 6 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p4_t1_br", (getter)Common_get_ur_ec_p4_t1_br,(setter)Common_set_ur_ec_p4_t1_br,
	PyDoc_STR("*float*: Period 4 Tier 1 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p4_t1_sr", (getter)Common_get_ur_ec_p4_t1_sr,(setter)Common_set_ur_ec_p4_t1_sr,
	PyDoc_STR("*float*: Period 4 Tier 1 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p4_t1_ub", (getter)Common_get_ur_ec_p4_t1_ub,(setter)Common_set_ur_ec_p4_t1_ub,
	PyDoc_STR("*float*: Period 4 Tier 1 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p4_t2_br", (getter)Common_get_ur_ec_p4_t2_br,(setter)Common_set_ur_ec_p4_t2_br,
	PyDoc_STR("*float*: Period 4 Tier 2 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p4_t2_sr", (getter)Common_get_ur_ec_p4_t2_sr,(setter)Common_set_ur_ec_p4_t2_sr,
	PyDoc_STR("*float*: Period 4 Tier 2 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p4_t2_ub", (getter)Common_get_ur_ec_p4_t2_ub,(setter)Common_set_ur_ec_p4_t2_ub,
	PyDoc_STR("*float*: Period 4 Tier 2 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p4_t3_br", (getter)Common_get_ur_ec_p4_t3_br,(setter)Common_set_ur_ec_p4_t3_br,
	PyDoc_STR("*float*: Period 4 Tier 3 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p4_t3_sr", (getter)Common_get_ur_ec_p4_t3_sr,(setter)Common_set_ur_ec_p4_t3_sr,
	PyDoc_STR("*float*: Period 4 Tier 3 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p4_t3_ub", (getter)Common_get_ur_ec_p4_t3_ub,(setter)Common_set_ur_ec_p4_t3_ub,
	PyDoc_STR("*float*: Period 4 Tier 3 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p4_t4_br", (getter)Common_get_ur_ec_p4_t4_br,(setter)Common_set_ur_ec_p4_t4_br,
	PyDoc_STR("*float*: Period 4 Tier 4 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p4_t4_sr", (getter)Common_get_ur_ec_p4_t4_sr,(setter)Common_set_ur_ec_p4_t4_sr,
	PyDoc_STR("*float*: Period 4 Tier 4 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p4_t4_ub", (getter)Common_get_ur_ec_p4_t4_ub,(setter)Common_set_ur_ec_p4_t4_ub,
	PyDoc_STR("*float*: Period 4 Tier 4 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p4_t5_br", (getter)Common_get_ur_ec_p4_t5_br,(setter)Common_set_ur_ec_p4_t5_br,
	PyDoc_STR("*float*: Period 4 Tier 5 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p4_t5_sr", (getter)Common_get_ur_ec_p4_t5_sr,(setter)Common_set_ur_ec_p4_t5_sr,
	PyDoc_STR("*float*: Period 4 Tier 5 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p4_t5_ub", (getter)Common_get_ur_ec_p4_t5_ub,(setter)Common_set_ur_ec_p4_t5_ub,
	PyDoc_STR("*float*: Period 4 Tier 5 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p4_t6_br", (getter)Common_get_ur_ec_p4_t6_br,(setter)Common_set_ur_ec_p4_t6_br,
	PyDoc_STR("*float*: Period 4 Tier 6 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p4_t6_sr", (getter)Common_get_ur_ec_p4_t6_sr,(setter)Common_set_ur_ec_p4_t6_sr,
	PyDoc_STR("*float*: Period 4 Tier 6 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p4_t6_ub", (getter)Common_get_ur_ec_p4_t6_ub,(setter)Common_set_ur_ec_p4_t6_ub,
	PyDoc_STR("*float*: Period 4 Tier 6 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p5_t1_br", (getter)Common_get_ur_ec_p5_t1_br,(setter)Common_set_ur_ec_p5_t1_br,
	PyDoc_STR("*float*: Period 5 Tier 1 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p5_t1_sr", (getter)Common_get_ur_ec_p5_t1_sr,(setter)Common_set_ur_ec_p5_t1_sr,
	PyDoc_STR("*float*: Period 5 Tier 1 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p5_t1_ub", (getter)Common_get_ur_ec_p5_t1_ub,(setter)Common_set_ur_ec_p5_t1_ub,
	PyDoc_STR("*float*: Period 5 Tier 1 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p5_t2_br", (getter)Common_get_ur_ec_p5_t2_br,(setter)Common_set_ur_ec_p5_t2_br,
	PyDoc_STR("*float*: Period 5 Tier 2 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p5_t2_sr", (getter)Common_get_ur_ec_p5_t2_sr,(setter)Common_set_ur_ec_p5_t2_sr,
	PyDoc_STR("*float*: Period 5 Tier 2 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p5_t2_ub", (getter)Common_get_ur_ec_p5_t2_ub,(setter)Common_set_ur_ec_p5_t2_ub,
	PyDoc_STR("*float*: Period 5 Tier 2 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p5_t3_br", (getter)Common_get_ur_ec_p5_t3_br,(setter)Common_set_ur_ec_p5_t3_br,
	PyDoc_STR("*float*: Period 5 Tier 3 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p5_t3_sr", (getter)Common_get_ur_ec_p5_t3_sr,(setter)Common_set_ur_ec_p5_t3_sr,
	PyDoc_STR("*float*: Period 5 Tier 3 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p5_t3_ub", (getter)Common_get_ur_ec_p5_t3_ub,(setter)Common_set_ur_ec_p5_t3_ub,
	PyDoc_STR("*float*: Period 5 Tier 3 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p5_t4_br", (getter)Common_get_ur_ec_p5_t4_br,(setter)Common_set_ur_ec_p5_t4_br,
	PyDoc_STR("*float*: Period 5 Tier 4 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p5_t4_sr", (getter)Common_get_ur_ec_p5_t4_sr,(setter)Common_set_ur_ec_p5_t4_sr,
	PyDoc_STR("*float*: Period 5 Tier 4 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p5_t4_ub", (getter)Common_get_ur_ec_p5_t4_ub,(setter)Common_set_ur_ec_p5_t4_ub,
	PyDoc_STR("*float*: Period 5 Tier 4 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p5_t5_br", (getter)Common_get_ur_ec_p5_t5_br,(setter)Common_set_ur_ec_p5_t5_br,
	PyDoc_STR("*float*: Period 5 Tier 5 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p5_t5_sr", (getter)Common_get_ur_ec_p5_t5_sr,(setter)Common_set_ur_ec_p5_t5_sr,
	PyDoc_STR("*float*: Period 5 Tier 5 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p5_t5_ub", (getter)Common_get_ur_ec_p5_t5_ub,(setter)Common_set_ur_ec_p5_t5_ub,
	PyDoc_STR("*float*: Period 5 Tier 5 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p5_t6_br", (getter)Common_get_ur_ec_p5_t6_br,(setter)Common_set_ur_ec_p5_t6_br,
	PyDoc_STR("*float*: Period 5 Tier 6 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p5_t6_sr", (getter)Common_get_ur_ec_p5_t6_sr,(setter)Common_set_ur_ec_p5_t6_sr,
	PyDoc_STR("*float*: Period 5 Tier 6 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p5_t6_ub", (getter)Common_get_ur_ec_p5_t6_ub,(setter)Common_set_ur_ec_p5_t6_ub,
	PyDoc_STR("*float*: Period 5 Tier 6 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p6_t1_br", (getter)Common_get_ur_ec_p6_t1_br,(setter)Common_set_ur_ec_p6_t1_br,
	PyDoc_STR("*float*: Period 6 Tier 1 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p6_t1_sr", (getter)Common_get_ur_ec_p6_t1_sr,(setter)Common_set_ur_ec_p6_t1_sr,
	PyDoc_STR("*float*: Period 6 Tier 1 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p6_t1_ub", (getter)Common_get_ur_ec_p6_t1_ub,(setter)Common_set_ur_ec_p6_t1_ub,
	PyDoc_STR("*float*: Period 6 Tier 1 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p6_t2_br", (getter)Common_get_ur_ec_p6_t2_br,(setter)Common_set_ur_ec_p6_t2_br,
	PyDoc_STR("*float*: Period 6 Tier 2 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p6_t2_sr", (getter)Common_get_ur_ec_p6_t2_sr,(setter)Common_set_ur_ec_p6_t2_sr,
	PyDoc_STR("*float*: Period 6 Tier 2 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p6_t2_ub", (getter)Common_get_ur_ec_p6_t2_ub,(setter)Common_set_ur_ec_p6_t2_ub,
	PyDoc_STR("*float*: Period 6 Tier 2 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p6_t3_br", (getter)Common_get_ur_ec_p6_t3_br,(setter)Common_set_ur_ec_p6_t3_br,
	PyDoc_STR("*float*: Period 6 Tier 3 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p6_t3_sr", (getter)Common_get_ur_ec_p6_t3_sr,(setter)Common_set_ur_ec_p6_t3_sr,
	PyDoc_STR("*float*: Period 6 Tier 3 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p6_t3_ub", (getter)Common_get_ur_ec_p6_t3_ub,(setter)Common_set_ur_ec_p6_t3_ub,
	PyDoc_STR("*float*: Period 6 Tier 3 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p6_t4_br", (getter)Common_get_ur_ec_p6_t4_br,(setter)Common_set_ur_ec_p6_t4_br,
	PyDoc_STR("*float*: Period 6 Tier 4 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p6_t4_sr", (getter)Common_get_ur_ec_p6_t4_sr,(setter)Common_set_ur_ec_p6_t4_sr,
	PyDoc_STR("*float*: Period 6 Tier 4 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p6_t4_ub", (getter)Common_get_ur_ec_p6_t4_ub,(setter)Common_set_ur_ec_p6_t4_ub,
	PyDoc_STR("*float*: Period 6 Tier 4 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p6_t5_br", (getter)Common_get_ur_ec_p6_t5_br,(setter)Common_set_ur_ec_p6_t5_br,
	PyDoc_STR("*float*: Period 6 Tier 5 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p6_t5_sr", (getter)Common_get_ur_ec_p6_t5_sr,(setter)Common_set_ur_ec_p6_t5_sr,
	PyDoc_STR("*float*: Period 6 Tier 5 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p6_t5_ub", (getter)Common_get_ur_ec_p6_t5_ub,(setter)Common_set_ur_ec_p6_t5_ub,
	PyDoc_STR("*float*: Period 6 Tier 5 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p6_t6_br", (getter)Common_get_ur_ec_p6_t6_br,(setter)Common_set_ur_ec_p6_t6_br,
	PyDoc_STR("*float*: Period 6 Tier 6 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p6_t6_sr", (getter)Common_get_ur_ec_p6_t6_sr,(setter)Common_set_ur_ec_p6_t6_sr,
	PyDoc_STR("*float*: Period 6 Tier 6 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p6_t6_ub", (getter)Common_get_ur_ec_p6_t6_ub,(setter)Common_set_ur_ec_p6_t6_ub,
	PyDoc_STR("*float*: Period 6 Tier 6 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p7_t1_br", (getter)Common_get_ur_ec_p7_t1_br,(setter)Common_set_ur_ec_p7_t1_br,
	PyDoc_STR("*float*: Period 7 Tier 1 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p7_t1_sr", (getter)Common_get_ur_ec_p7_t1_sr,(setter)Common_set_ur_ec_p7_t1_sr,
	PyDoc_STR("*float*: Period 7 Tier 1 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p7_t1_ub", (getter)Common_get_ur_ec_p7_t1_ub,(setter)Common_set_ur_ec_p7_t1_ub,
	PyDoc_STR("*float*: Period 7 Tier 1 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p7_t2_br", (getter)Common_get_ur_ec_p7_t2_br,(setter)Common_set_ur_ec_p7_t2_br,
	PyDoc_STR("*float*: Period 7 Tier 2 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p7_t2_sr", (getter)Common_get_ur_ec_p7_t2_sr,(setter)Common_set_ur_ec_p7_t2_sr,
	PyDoc_STR("*float*: Period 7 Tier 2 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p7_t2_ub", (getter)Common_get_ur_ec_p7_t2_ub,(setter)Common_set_ur_ec_p7_t2_ub,
	PyDoc_STR("*float*: Period 7 Tier 2 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p7_t3_br", (getter)Common_get_ur_ec_p7_t3_br,(setter)Common_set_ur_ec_p7_t3_br,
	PyDoc_STR("*float*: Period 7 Tier 3 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p7_t3_sr", (getter)Common_get_ur_ec_p7_t3_sr,(setter)Common_set_ur_ec_p7_t3_sr,
	PyDoc_STR("*float*: Period 7 Tier 3 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p7_t3_ub", (getter)Common_get_ur_ec_p7_t3_ub,(setter)Common_set_ur_ec_p7_t3_ub,
	PyDoc_STR("*float*: Period 7 Tier 3 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p7_t4_br", (getter)Common_get_ur_ec_p7_t4_br,(setter)Common_set_ur_ec_p7_t4_br,
	PyDoc_STR("*float*: Period 7 Tier 4 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p7_t4_sr", (getter)Common_get_ur_ec_p7_t4_sr,(setter)Common_set_ur_ec_p7_t4_sr,
	PyDoc_STR("*float*: Period 7 Tier 4 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p7_t4_ub", (getter)Common_get_ur_ec_p7_t4_ub,(setter)Common_set_ur_ec_p7_t4_ub,
	PyDoc_STR("*float*: Period 7 Tier 4 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p7_t5_br", (getter)Common_get_ur_ec_p7_t5_br,(setter)Common_set_ur_ec_p7_t5_br,
	PyDoc_STR("*float*: Period 7 Tier 5 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p7_t5_sr", (getter)Common_get_ur_ec_p7_t5_sr,(setter)Common_set_ur_ec_p7_t5_sr,
	PyDoc_STR("*float*: Period 7 Tier 5 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p7_t5_ub", (getter)Common_get_ur_ec_p7_t5_ub,(setter)Common_set_ur_ec_p7_t5_ub,
	PyDoc_STR("*float*: Period 7 Tier 5 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p7_t6_br", (getter)Common_get_ur_ec_p7_t6_br,(setter)Common_set_ur_ec_p7_t6_br,
	PyDoc_STR("*float*: Period 7 Tier 6 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p7_t6_sr", (getter)Common_get_ur_ec_p7_t6_sr,(setter)Common_set_ur_ec_p7_t6_sr,
	PyDoc_STR("*float*: Period 7 Tier 6 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p7_t6_ub", (getter)Common_get_ur_ec_p7_t6_ub,(setter)Common_set_ur_ec_p7_t6_ub,
	PyDoc_STR("*float*: Period 7 Tier 6 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p8_t1_br", (getter)Common_get_ur_ec_p8_t1_br,(setter)Common_set_ur_ec_p8_t1_br,
	PyDoc_STR("*float*: Period 8 Tier 1 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p8_t1_sr", (getter)Common_get_ur_ec_p8_t1_sr,(setter)Common_set_ur_ec_p8_t1_sr,
	PyDoc_STR("*float*: Period 8 Tier 1 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p8_t1_ub", (getter)Common_get_ur_ec_p8_t1_ub,(setter)Common_set_ur_ec_p8_t1_ub,
	PyDoc_STR("*float*: Period 8 Tier 1 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p8_t2_br", (getter)Common_get_ur_ec_p8_t2_br,(setter)Common_set_ur_ec_p8_t2_br,
	PyDoc_STR("*float*: Period 8 Tier 2 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p8_t2_sr", (getter)Common_get_ur_ec_p8_t2_sr,(setter)Common_set_ur_ec_p8_t2_sr,
	PyDoc_STR("*float*: Period 8 Tier 2 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p8_t2_ub", (getter)Common_get_ur_ec_p8_t2_ub,(setter)Common_set_ur_ec_p8_t2_ub,
	PyDoc_STR("*float*: Period 8 Tier 2 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p8_t3_br", (getter)Common_get_ur_ec_p8_t3_br,(setter)Common_set_ur_ec_p8_t3_br,
	PyDoc_STR("*float*: Period 8 Tier 3 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p8_t3_sr", (getter)Common_get_ur_ec_p8_t3_sr,(setter)Common_set_ur_ec_p8_t3_sr,
	PyDoc_STR("*float*: Period 8 Tier 3 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p8_t3_ub", (getter)Common_get_ur_ec_p8_t3_ub,(setter)Common_set_ur_ec_p8_t3_ub,
	PyDoc_STR("*float*: Period 8 Tier 3 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p8_t4_br", (getter)Common_get_ur_ec_p8_t4_br,(setter)Common_set_ur_ec_p8_t4_br,
	PyDoc_STR("*float*: Period 8 Tier 4 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p8_t4_sr", (getter)Common_get_ur_ec_p8_t4_sr,(setter)Common_set_ur_ec_p8_t4_sr,
	PyDoc_STR("*float*: Period 8 Tier 4 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p8_t4_ub", (getter)Common_get_ur_ec_p8_t4_ub,(setter)Common_set_ur_ec_p8_t4_ub,
	PyDoc_STR("*float*: Period 8 Tier 4 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p8_t5_br", (getter)Common_get_ur_ec_p8_t5_br,(setter)Common_set_ur_ec_p8_t5_br,
	PyDoc_STR("*float*: Period 8 Tier 5 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p8_t5_sr", (getter)Common_get_ur_ec_p8_t5_sr,(setter)Common_set_ur_ec_p8_t5_sr,
	PyDoc_STR("*float*: Period 8 Tier 5 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p8_t5_ub", (getter)Common_get_ur_ec_p8_t5_ub,(setter)Common_set_ur_ec_p8_t5_ub,
	PyDoc_STR("*float*: Period 8 Tier 5 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p8_t6_br", (getter)Common_get_ur_ec_p8_t6_br,(setter)Common_set_ur_ec_p8_t6_br,
	PyDoc_STR("*float*: Period 8 Tier 6 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p8_t6_sr", (getter)Common_get_ur_ec_p8_t6_sr,(setter)Common_set_ur_ec_p8_t6_sr,
	PyDoc_STR("*float*: Period 8 Tier 6 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p8_t6_ub", (getter)Common_get_ur_ec_p8_t6_ub,(setter)Common_set_ur_ec_p8_t6_ub,
	PyDoc_STR("*float*: Period 8 Tier 6 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p9_t1_br", (getter)Common_get_ur_ec_p9_t1_br,(setter)Common_set_ur_ec_p9_t1_br,
	PyDoc_STR("*float*: Period 9 Tier 1 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p9_t1_sr", (getter)Common_get_ur_ec_p9_t1_sr,(setter)Common_set_ur_ec_p9_t1_sr,
	PyDoc_STR("*float*: Period 9 Tier 1 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p9_t1_ub", (getter)Common_get_ur_ec_p9_t1_ub,(setter)Common_set_ur_ec_p9_t1_ub,
	PyDoc_STR("*float*: Period 9 Tier 1 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p9_t2_br", (getter)Common_get_ur_ec_p9_t2_br,(setter)Common_set_ur_ec_p9_t2_br,
	PyDoc_STR("*float*: Period 9 Tier 2 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p9_t2_sr", (getter)Common_get_ur_ec_p9_t2_sr,(setter)Common_set_ur_ec_p9_t2_sr,
	PyDoc_STR("*float*: Period 9 Tier 2 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p9_t2_ub", (getter)Common_get_ur_ec_p9_t2_ub,(setter)Common_set_ur_ec_p9_t2_ub,
	PyDoc_STR("*float*: Period 9 Tier 2 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p9_t3_br", (getter)Common_get_ur_ec_p9_t3_br,(setter)Common_set_ur_ec_p9_t3_br,
	PyDoc_STR("*float*: Period 9 Tier 3 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p9_t3_sr", (getter)Common_get_ur_ec_p9_t3_sr,(setter)Common_set_ur_ec_p9_t3_sr,
	PyDoc_STR("*float*: Period 9 Tier 3 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p9_t3_ub", (getter)Common_get_ur_ec_p9_t3_ub,(setter)Common_set_ur_ec_p9_t3_ub,
	PyDoc_STR("*float*: Period 9 Tier 3 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p9_t4_br", (getter)Common_get_ur_ec_p9_t4_br,(setter)Common_set_ur_ec_p9_t4_br,
	PyDoc_STR("*float*: Period 9 Tier 4 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p9_t4_sr", (getter)Common_get_ur_ec_p9_t4_sr,(setter)Common_set_ur_ec_p9_t4_sr,
	PyDoc_STR("*float*: Period 9 Tier 4 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p9_t4_ub", (getter)Common_get_ur_ec_p9_t4_ub,(setter)Common_set_ur_ec_p9_t4_ub,
	PyDoc_STR("*float*: Period 9 Tier 4 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p9_t5_br", (getter)Common_get_ur_ec_p9_t5_br,(setter)Common_set_ur_ec_p9_t5_br,
	PyDoc_STR("*float*: Period 9 Tier 5 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p9_t5_sr", (getter)Common_get_ur_ec_p9_t5_sr,(setter)Common_set_ur_ec_p9_t5_sr,
	PyDoc_STR("*float*: Period 9 Tier 5 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p9_t5_ub", (getter)Common_get_ur_ec_p9_t5_ub,(setter)Common_set_ur_ec_p9_t5_ub,
	PyDoc_STR("*float*: Period 9 Tier 5 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p9_t6_br", (getter)Common_get_ur_ec_p9_t6_br,(setter)Common_set_ur_ec_p9_t6_br,
	PyDoc_STR("*float*: Period 9 Tier 6 Energy Buy Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p9_t6_sr", (getter)Common_get_ur_ec_p9_t6_sr,(setter)Common_set_ur_ec_p9_t6_sr,
	PyDoc_STR("*float*: Period 9 Tier 6 Energy Sell Rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_p9_t6_ub", (getter)Common_get_ur_ec_p9_t6_ub,(setter)Common_set_ur_ec_p9_t6_ub,
	PyDoc_STR("*float*: Period 9 Tier 6 Maximum Energy Usage [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ec_sched_weekday", (getter)Common_get_ur_ec_sched_weekday,(setter)Common_set_ur_ec_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: Energy Charge Weekday Schedule\n\n**Info:**\n12x24\n\n**Required:**\nRequired if ur_ec_enable=1"),
 	NULL},
{"ur_ec_sched_weekend", (getter)Common_get_ur_ec_sched_weekend,(setter)Common_set_ur_ec_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Energy Charge Weekend Schedule\n\n**Info:**\n12x24\n\n**Required:**\nRequired if ur_ec_enable=1"),
 	NULL},
{"ur_enable_net_metering", (getter)Common_get_ur_enable_net_metering,(setter)Common_set_ur_enable_net_metering,
	PyDoc_STR("*float*: Enable net metering [0/1]\n\n**Info:**\nEnforce net metering\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_excess_monthly_energy_or_dollars", (getter)Common_get_ur_excess_monthly_energy_or_dollars,(setter)Common_set_ur_excess_monthly_energy_or_dollars,
	PyDoc_STR("*float*: Net metering handling of monthly excess [0=Rollover energy,1=Rollover dollars]\n\n**Info:**\nNet metering monthly excess\n\n**Constraints:**\nINTEGER\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_flat_buy_rate", (getter)Common_get_ur_flat_buy_rate,(setter)Common_set_ur_flat_buy_rate,
	PyDoc_STR("*float*: Flat rate (buy) [$/kWh]\n\n**Required:**\nTrue"),
 	NULL},
{"ur_flat_sell_rate", (getter)Common_get_ur_flat_sell_rate,(setter)Common_set_ur_flat_sell_rate,
	PyDoc_STR("*float*: Flat rate (sell) [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_monthly_fixed_charge", (getter)Common_get_ur_monthly_fixed_charge,(setter)Common_set_ur_monthly_fixed_charge,
	PyDoc_STR("*float*: Monthly fixed charge [$]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_monthly_min_charge", (getter)Common_get_ur_monthly_min_charge,(setter)Common_set_ur_monthly_min_charge,
	PyDoc_STR("*float*: Monthly minimum charge [$]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_nm_yearend_sell_rate", (getter)Common_get_ur_nm_yearend_sell_rate,(setter)Common_set_ur_nm_yearend_sell_rate,
	PyDoc_STR("*float*: Year end sell rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate3.Common",             /*tp_name*/
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
 * TimeSeries Group
 */ 

static PyTypeObject TimeSeries_Type;

static PyObject *
TimeSeries_new(SAM_Utilityrate3 data_ptr)
{
	PyObject* new_obj = TimeSeries_Type.tp_alloc(&TimeSeries_Type,0);

	VarGroupObject* TimeSeries_obj = (VarGroupObject*)new_obj;

	TimeSeries_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* TimeSeries methods */

static PyObject *
TimeSeries_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate3", "TimeSeries")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TimeSeries_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &TimeSeries_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Utilityrate3", "TimeSeries")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TimeSeries_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &TimeSeries_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TimeSeries_methods[] = {
		{"assign",            (PyCFunction)TimeSeries_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``TimeSeries_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)TimeSeries_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``TimeSeries_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)TimeSeries_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TimeSeries_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_TimeSeries_gen_aget, self->data_ptr);
}

static int
TimeSeries_set_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate3_TimeSeries_gen_aset, self->data_ptr);
}

static PyObject *
TimeSeries_get_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_TimeSeries_load_aget, self->data_ptr);
}

static int
TimeSeries_set_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate3_TimeSeries_load_aset, self->data_ptr);
}

static PyGetSetDef TimeSeries_getset[] = {
{"gen", (getter)TimeSeries_get_gen,(setter)TimeSeries_set_gen,
	PyDoc_STR("*sequence*: System power generated [kW]\n\n**Required:**\nTrue"),
 	NULL},
{"load", (getter)TimeSeries_get_load,(setter)TimeSeries_set_load,
	PyDoc_STR("*sequence*: Electricity load (year 1) [kW]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TimeSeries_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate3.TimeSeries",             /*tp_name*/
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
		TimeSeries_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TimeSeries_getset,          /*tp_getset*/
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
 * Financials Group
 */ 

static PyTypeObject Financials_Type;

static PyObject *
Financials_new(SAM_Utilityrate3 data_ptr)
{
	PyObject* new_obj = Financials_Type.tp_alloc(&Financials_Type,0);

	VarGroupObject* Financials_obj = (VarGroupObject*)new_obj;

	Financials_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Financials methods */

static PyObject *
Financials_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate3", "Financials")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Financials_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Financials_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Utilityrate3", "Financials")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Financials_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Financials_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Financials_methods[] = {
		{"assign",            (PyCFunction)Financials_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Financials_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Financials_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Financials_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Financials_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Financials_get_inflation_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Financials_inflation_rate_nget, self->data_ptr);
}

static int
Financials_set_inflation_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate3_Financials_inflation_rate_nset, self->data_ptr);
}

static PyGetSetDef Financials_getset[] = {
{"inflation_rate", (getter)Financials_get_inflation_rate,(setter)Financials_set_inflation_rate,
	PyDoc_STR("*float*: Inflation rate [%]\n\n**Constraints:**\nMIN=-99\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Financials_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate3.Financials",             /*tp_name*/
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
		Financials_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Financials_getset,          /*tp_getset*/
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
 * AnnualOutput Group
 */ 

static PyTypeObject AnnualOutput_Type;

static PyObject *
AnnualOutput_new(SAM_Utilityrate3 data_ptr)
{
	PyObject* new_obj = AnnualOutput_Type.tp_alloc(&AnnualOutput_Type,0);

	VarGroupObject* AnnualOutput_obj = (VarGroupObject*)new_obj;

	AnnualOutput_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* AnnualOutput methods */

static PyObject *
AnnualOutput_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate3", "AnnualOutput")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
AnnualOutput_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &AnnualOutput_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Utilityrate3", "AnnualOutput")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
AnnualOutput_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &AnnualOutput_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef AnnualOutput_methods[] = {
		{"assign",            (PyCFunction)AnnualOutput_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``AnnualOutput_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)AnnualOutput_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``AnnualOutput_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)AnnualOutput_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
AnnualOutput_get_degradation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_AnnualOutput_degradation_aget, self->data_ptr);
}

static int
AnnualOutput_set_degradation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate3_AnnualOutput_degradation_aset, self->data_ptr);
}

static PyGetSetDef AnnualOutput_getset[] = {
{"degradation", (getter)AnnualOutput_get_degradation,(setter)AnnualOutput_set_degradation,
	PyDoc_STR("*sequence*: Annual energy degradation [%]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject AnnualOutput_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate3.AnnualOutput",             /*tp_name*/
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
		AnnualOutput_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		AnnualOutput_getset,          /*tp_getset*/
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
Outputs_new(SAM_Utilityrate3 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate3", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Utilityrate3", "Outputs")){
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
Outputs_get_annual_electric_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_annual_electric_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_annual_energy_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_fixed_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_fixed_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_fixed_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_fixed_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_fixed_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_fixed_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_fixed_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_fixed_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_fixed_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_fixed_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_fixed_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_fixed_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_fixed_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_fixed_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_fixed_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_fixed_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_fixed_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_fixed_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_fixed_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_fixed_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_fixed_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_fixed_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_fixed_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_fixed_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_tou(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_tou_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_tou_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_tou_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_tou_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_tou_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_tou_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_tou_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_tou_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_tou_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_tou_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_tou_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_tou_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_tou_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_tou_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_tou_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_tou_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_tou_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_tou_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_tou_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_tou_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_tou_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_tou_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_tou_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_tou_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_dc_tou_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_apr_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_apr_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_apr_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_apr_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_apr_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_apr_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_apr_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_apr_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_apr_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_apr_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_apr_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_apr_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_apr_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_apr_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_apr_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_apr_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_apr_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_apr_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_apr_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_apr_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_apr_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_apr_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_apr_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_apr_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_aug_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_aug_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_aug_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_aug_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_aug_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_aug_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_aug_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_aug_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_aug_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_aug_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_aug_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_aug_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_aug_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_aug_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_aug_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_aug_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_aug_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_aug_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_aug_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_aug_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_aug_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_aug_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_aug_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_aug_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_dec_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_dec_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_dec_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_dec_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_dec_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_dec_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_dec_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_dec_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_dec_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_dec_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_dec_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_dec_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_dec_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_dec_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_dec_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_dec_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_dec_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_dec_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_dec_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_dec_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_dec_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_dec_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_dec_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_dec_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_feb_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_feb_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_feb_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_feb_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_feb_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_feb_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_feb_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_feb_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_feb_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_feb_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_feb_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_feb_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_feb_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_feb_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_feb_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_feb_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_feb_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_feb_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_feb_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_feb_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_feb_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_feb_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_feb_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_feb_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_flat(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_flat_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_flat_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_flat_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_flat_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_flat_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_flat_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_flat_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_flat_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_flat_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_flat_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_flat_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_flat_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_flat_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_flat_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_flat_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_flat_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_flat_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_flat_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_flat_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_flat_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_flat_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_flat_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_flat_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_flat_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_flat_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jan_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jan_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jan_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jan_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jan_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jan_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jan_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jan_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jan_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jan_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jan_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jan_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jan_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jan_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jan_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jan_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jan_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jan_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jan_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jan_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jan_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jan_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jan_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jan_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jul_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jul_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jul_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jul_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jul_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jul_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jul_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jul_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jul_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jul_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jul_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jul_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jul_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jul_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jul_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jul_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jul_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jul_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jul_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jul_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jul_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jul_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jul_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jul_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jun_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jun_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jun_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jun_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jun_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jun_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jun_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jun_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jun_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jun_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jun_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jun_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jun_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jun_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jun_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jun_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jun_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jun_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jun_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jun_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jun_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jun_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jun_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_jun_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_mar_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_mar_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_mar_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_mar_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_mar_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_mar_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_mar_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_mar_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_mar_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_mar_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_mar_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_mar_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_mar_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_mar_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_mar_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_mar_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_mar_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_mar_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_mar_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_mar_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_mar_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_mar_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_mar_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_mar_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_may_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_may_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_may_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_may_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_may_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_may_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_may_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_may_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_may_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_may_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_may_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_may_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_may_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_may_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_may_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_may_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_may_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_may_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_may_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_may_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_may_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_may_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_may_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_may_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_nov_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_nov_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_nov_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_nov_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_nov_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_nov_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_nov_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_nov_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_nov_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_nov_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_nov_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_nov_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_nov_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_nov_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_nov_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_nov_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_nov_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_nov_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_nov_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_nov_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_nov_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_nov_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_nov_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_nov_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_oct_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_oct_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_oct_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_oct_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_oct_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_oct_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_oct_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_oct_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_oct_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_oct_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_oct_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_oct_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_oct_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_oct_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_oct_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_oct_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_oct_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_oct_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_oct_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_oct_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_oct_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_oct_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_oct_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_oct_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_sep_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_sep_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_sep_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_sep_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_sep_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_sep_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_sep_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_sep_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_sep_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_sep_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_sep_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_sep_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_sep_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_sep_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_sep_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_sep_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_sep_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_sep_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_sep_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_sep_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_sep_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_sep_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_sep_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_ec_sep_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_fixed_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_fixed_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_fixed_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_fixed_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_fixed_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_fixed_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_fixed_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_fixed_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_fixed_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_fixed_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_fixed_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_fixed_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_fixed_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_fixed_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_fixed_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_fixed_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_fixed_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_fixed_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_fixed_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_fixed_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_fixed_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_fixed_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_fixed_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_fixed_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_minimum(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_minimum_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_minimum_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_minimum_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_minimum_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_minimum_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_minimum_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_minimum_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_minimum_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_minimum_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_minimum_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_minimum_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_minimum_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_minimum_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_minimum_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_minimum_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_minimum_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_minimum_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_minimum_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_minimum_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_minimum_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_minimum_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_minimum_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_minimum_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_minimum_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_w_sys_minimum_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_fixed_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_fixed_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_fixed_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_fixed_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_fixed_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_fixed_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_fixed_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_fixed_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_fixed_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_fixed_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_fixed_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_fixed_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_fixed_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_fixed_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_fixed_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_fixed_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_fixed_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_fixed_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_fixed_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_fixed_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_fixed_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_fixed_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_fixed_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_fixed_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_tou(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_tou_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_tou_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_tou_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_tou_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_tou_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_tou_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_tou_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_tou_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_tou_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_tou_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_tou_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_tou_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_tou_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_tou_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_tou_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_tou_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_tou_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_tou_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_tou_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_tou_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_tou_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_tou_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_tou_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_tou_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_dc_tou_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_apr_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_apr_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_apr_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_apr_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_apr_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_apr_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_apr_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_apr_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_apr_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_apr_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_apr_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_apr_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_apr_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_apr_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_apr_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_apr_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_apr_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_apr_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_apr_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_apr_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_apr_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_apr_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_apr_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_apr_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_aug_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_aug_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_aug_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_aug_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_aug_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_aug_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_aug_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_aug_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_aug_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_aug_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_aug_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_aug_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_aug_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_aug_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_aug_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_aug_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_aug_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_aug_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_aug_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_aug_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_aug_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_aug_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_aug_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_aug_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_dec_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_dec_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_dec_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_dec_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_dec_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_dec_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_dec_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_dec_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_dec_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_dec_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_dec_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_dec_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_dec_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_dec_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_dec_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_dec_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_dec_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_dec_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_dec_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_dec_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_dec_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_dec_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_dec_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_dec_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_feb_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_feb_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_feb_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_feb_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_feb_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_feb_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_feb_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_feb_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_feb_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_feb_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_feb_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_feb_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_feb_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_feb_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_feb_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_feb_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_feb_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_feb_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_feb_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_feb_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_feb_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_feb_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_feb_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_feb_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_flat(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_flat_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_flat_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_flat_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_flat_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_flat_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_flat_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_flat_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_flat_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_flat_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_flat_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_flat_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_flat_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_flat_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_flat_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_flat_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_flat_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_flat_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_flat_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_flat_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_flat_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_flat_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_flat_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_flat_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_flat_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_flat_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jan_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jan_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jan_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jan_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jan_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jan_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jan_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jan_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jan_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jan_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jan_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jan_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jan_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jan_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jan_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jan_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jan_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jan_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jan_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jan_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jan_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jan_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jan_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jan_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jul_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jul_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jul_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jul_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jul_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jul_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jul_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jul_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jul_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jul_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jul_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jul_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jul_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jul_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jul_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jul_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jul_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jul_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jul_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jul_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jul_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jul_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jul_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jul_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jun_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jun_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jun_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jun_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jun_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jun_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jun_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jun_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jun_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jun_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jun_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jun_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jun_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jun_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jun_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jun_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jun_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jun_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jun_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jun_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jun_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jun_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jun_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_jun_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_mar_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_mar_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_mar_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_mar_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_mar_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_mar_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_mar_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_mar_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_mar_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_mar_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_mar_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_mar_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_mar_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_mar_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_mar_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_mar_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_mar_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_mar_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_mar_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_mar_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_mar_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_mar_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_mar_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_mar_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_may_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_may_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_may_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_may_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_may_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_may_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_may_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_may_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_may_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_may_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_may_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_may_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_may_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_may_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_may_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_may_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_may_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_may_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_may_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_may_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_may_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_may_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_may_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_may_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_nov_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_nov_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_nov_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_nov_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_nov_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_nov_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_nov_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_nov_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_nov_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_nov_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_nov_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_nov_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_nov_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_nov_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_nov_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_nov_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_nov_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_nov_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_nov_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_nov_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_nov_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_nov_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_nov_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_nov_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_oct_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_oct_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_oct_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_oct_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_oct_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_oct_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_oct_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_oct_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_oct_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_oct_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_oct_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_oct_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_oct_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_oct_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_oct_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_oct_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_oct_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_oct_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_oct_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_oct_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_oct_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_oct_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_oct_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_oct_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_sep_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_sep_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_sep_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_sep_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_sep_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_sep_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_sep_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_sep_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_sep_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_sep_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_sep_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_sep_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_sep_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_sep_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_sep_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_sep_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_sep_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_sep_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_sep_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_sep_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_sep_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_sep_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_sep_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_ec_sep_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_fixed_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_fixed_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_fixed_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_fixed_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_fixed_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_fixed_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_fixed_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_fixed_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_fixed_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_fixed_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_fixed_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_fixed_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_fixed_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_fixed_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_fixed_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_fixed_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_fixed_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_fixed_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_fixed_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_fixed_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_fixed_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_fixed_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_fixed_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_fixed_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_minimum(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_minimum_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_minimum_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_minimum_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_minimum_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_minimum_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_minimum_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_minimum_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_minimum_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_minimum_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_minimum_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_minimum_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_minimum_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_minimum_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_minimum_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_minimum_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_minimum_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_minimum_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_minimum_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_minimum_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_minimum_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_minimum_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_minimum_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_minimum_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_minimum_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_charge_wo_sys_minimum_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_elec_cost_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_elec_cost_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_elec_cost_with_system_year1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Outputs_elec_cost_with_system_year1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_elec_cost_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_elec_cost_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_elec_cost_without_system_year1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Outputs_elec_cost_without_system_year1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_apr_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_apr_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_apr_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_apr_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_apr_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_apr_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_apr_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_apr_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_apr_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_apr_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_apr_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_apr_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_apr_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_apr_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_apr_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_apr_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_apr_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_apr_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_apr_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_apr_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_apr_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_apr_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_apr_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_apr_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_aug_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_aug_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_aug_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_aug_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_aug_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_aug_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_aug_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_aug_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_aug_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_aug_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_aug_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_aug_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_aug_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_aug_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_aug_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_aug_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_aug_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_aug_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_aug_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_aug_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_aug_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_aug_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_aug_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_aug_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_dec_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_dec_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_dec_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_dec_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_dec_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_dec_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_dec_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_dec_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_dec_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_dec_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_dec_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_dec_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_dec_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_dec_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_dec_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_dec_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_dec_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_dec_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_dec_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_dec_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_dec_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_dec_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_dec_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_dec_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_feb_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_feb_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_feb_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_feb_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_feb_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_feb_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_feb_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_feb_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_feb_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_feb_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_feb_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_feb_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_feb_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_feb_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_feb_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_feb_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_feb_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_feb_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_feb_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_feb_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_feb_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_feb_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_feb_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_feb_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jan_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jan_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jan_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jan_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jan_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jan_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jan_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jan_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jan_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jan_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jan_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jan_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jan_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jan_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jan_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jan_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jan_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jan_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jan_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jan_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jan_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jan_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jan_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jan_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jul_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jul_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jul_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jul_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jul_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jul_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jul_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jul_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jul_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jul_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jul_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jul_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jul_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jul_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jul_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jul_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jul_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jul_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jul_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jul_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jul_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jul_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jul_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jul_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jun_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jun_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jun_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jun_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jun_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jun_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jun_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jun_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jun_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jun_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jun_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jun_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jun_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jun_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jun_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jun_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jun_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jun_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jun_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jun_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jun_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jun_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jun_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_jun_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_mar_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_mar_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_mar_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_mar_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_mar_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_mar_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_mar_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_mar_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_mar_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_mar_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_mar_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_mar_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_mar_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_mar_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_mar_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_mar_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_mar_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_mar_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_mar_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_mar_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_mar_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_mar_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_mar_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_mar_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_may_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_may_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_may_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_may_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_may_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_may_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_may_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_may_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_may_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_may_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_may_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_may_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_may_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_may_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_may_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_may_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_may_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_may_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_may_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_may_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_may_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_may_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_may_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_may_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_nov_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_nov_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_nov_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_nov_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_nov_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_nov_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_nov_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_nov_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_nov_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_nov_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_nov_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_nov_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_nov_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_nov_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_nov_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_nov_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_nov_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_nov_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_nov_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_nov_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_nov_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_nov_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_nov_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_nov_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_oct_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_oct_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_oct_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_oct_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_oct_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_oct_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_oct_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_oct_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_oct_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_oct_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_oct_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_oct_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_oct_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_oct_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_oct_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_oct_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_oct_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_oct_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_oct_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_oct_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_oct_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_oct_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_oct_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_oct_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_sep_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_sep_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_sep_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_sep_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_sep_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_sep_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_sep_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_sep_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_sep_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_sep_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_sep_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_sep_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_sep_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_sep_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_sep_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_sep_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_sep_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_sep_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_sep_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_sep_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_sep_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_sep_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_sep_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_w_sys_ec_sep_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_apr_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_apr_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_apr_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_apr_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_apr_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_apr_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_apr_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_apr_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_apr_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_apr_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_apr_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_apr_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_apr_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_apr_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_apr_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_apr_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_apr_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_apr_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_apr_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_apr_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_apr_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_apr_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_apr_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_apr_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_aug_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_aug_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_aug_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_aug_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_aug_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_aug_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_aug_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_aug_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_aug_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_aug_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_aug_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_aug_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_aug_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_aug_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_aug_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_aug_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_aug_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_aug_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_aug_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_aug_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_aug_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_aug_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_aug_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_aug_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_dec_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_dec_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_dec_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_dec_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_dec_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_dec_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_dec_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_dec_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_dec_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_dec_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_dec_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_dec_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_dec_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_dec_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_dec_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_dec_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_dec_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_dec_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_dec_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_dec_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_dec_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_dec_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_dec_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_dec_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_feb_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_feb_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_feb_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_feb_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_feb_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_feb_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_feb_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_feb_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_feb_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_feb_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_feb_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_feb_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_feb_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_feb_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_feb_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_feb_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_feb_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_feb_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_feb_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_feb_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_feb_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_feb_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_feb_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_feb_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jan_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jan_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jan_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jan_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jan_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jan_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jan_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jan_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jan_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jan_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jan_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jan_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jan_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jan_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jan_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jan_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jan_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jan_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jan_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jan_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jan_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jan_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jan_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jan_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jul_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jul_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jul_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jul_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jul_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jul_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jul_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jul_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jul_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jul_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jul_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jul_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jul_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jul_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jul_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jul_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jul_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jul_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jul_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jul_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jul_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jul_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jul_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jul_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jun_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jun_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jun_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jun_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jun_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jun_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jun_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jun_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jun_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jun_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jun_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jun_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jun_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jun_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jun_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jun_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jun_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jun_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jun_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jun_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jun_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jun_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jun_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_jun_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_mar_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_mar_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_mar_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_mar_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_mar_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_mar_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_mar_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_mar_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_mar_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_mar_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_mar_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_mar_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_mar_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_mar_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_mar_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_mar_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_mar_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_mar_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_mar_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_mar_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_mar_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_mar_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_mar_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_mar_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_may_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_may_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_may_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_may_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_may_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_may_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_may_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_may_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_may_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_may_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_may_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_may_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_may_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_may_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_may_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_may_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_may_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_may_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_may_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_may_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_may_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_may_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_may_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_may_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_nov_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_nov_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_nov_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_nov_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_nov_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_nov_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_nov_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_nov_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_nov_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_nov_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_nov_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_nov_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_nov_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_nov_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_nov_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_nov_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_nov_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_nov_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_nov_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_nov_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_nov_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_nov_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_nov_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_nov_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_oct_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_oct_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_oct_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_oct_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_oct_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_oct_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_oct_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_oct_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_oct_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_oct_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_oct_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_oct_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_oct_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_oct_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_oct_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_oct_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_oct_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_oct_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_oct_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_oct_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_oct_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_oct_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_oct_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_oct_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_sep_p1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_sep_p1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_sep_p10(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_sep_p10_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_sep_p11(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_sep_p11_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_sep_p12(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_sep_p12_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_sep_p2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_sep_p2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_sep_p3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_sep_p3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_sep_p4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_sep_p4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_sep_p5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_sep_p5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_sep_p6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_sep_p6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_sep_p7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_sep_p7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_sep_p8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_sep_p8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_sep_p9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_energy_wo_sys_ec_sep_p9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_lifetime_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_lifetime_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_savings_year1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Outputs_savings_year1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_w_sys(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_w_sys_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_w_sys_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_w_sys_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_w_sys_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_w_sys_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_w_sys_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_w_sys_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_w_sys_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_w_sys_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_w_sys_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_w_sys_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_w_sys_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_w_sys_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_w_sys_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_w_sys_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_w_sys_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_w_sys_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_w_sys_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_w_sys_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_w_sys_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_w_sys_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_w_sys_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_w_sys_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_w_sys_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_w_sys_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_wo_sys(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_wo_sys_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_wo_sys_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_wo_sys_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_wo_sys_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_wo_sys_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_wo_sys_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_wo_sys_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_wo_sys_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_wo_sys_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_wo_sys_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_wo_sys_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_wo_sys_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_wo_sys_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_wo_sys_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_wo_sys_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_wo_sys_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_wo_sys_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_wo_sys_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_wo_sys_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_wo_sys_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_wo_sys_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_wo_sys_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_wo_sys_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_wo_sys_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_utility_bill_wo_sys_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_electric_load(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate3_Outputs_year1_electric_load_nget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_dc_peak_per_period(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_hourly_dc_peak_per_period_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_dc_tou_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_hourly_dc_tou_schedule_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_dc_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_hourly_dc_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_dc_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_hourly_dc_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_e_tofromgrid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_hourly_e_tofromgrid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_ec_tou_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_hourly_ec_tou_schedule_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_ec_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_hourly_ec_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_ec_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_hourly_ec_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_hourly_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_p_system_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_hourly_p_system_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_p_tofromgrid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_hourly_p_tofromgrid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_salespurchases_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_hourly_salespurchases_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_salespurchases_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_hourly_salespurchases_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_cumulative_excess_dollars(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_monthly_cumulative_excess_dollars_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_cumulative_excess_generation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_monthly_cumulative_excess_generation_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_fixed_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_monthly_dc_fixed_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_fixed_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_monthly_dc_fixed_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_tou_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_monthly_dc_tou_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_tou_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_monthly_dc_tou_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_ec_charge_flat_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_monthly_ec_charge_flat_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_ec_charge_flat_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_monthly_ec_charge_flat_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_ec_charge_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_monthly_ec_charge_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_ec_charge_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_monthly_ec_charge_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_electricity_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_monthly_electricity_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_fixed_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_monthly_fixed_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_fixed_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_monthly_fixed_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_monthly_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_minimum_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_monthly_minimum_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_minimum_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_monthly_minimum_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_utility_bill_w_sys(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_monthly_utility_bill_w_sys_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_utility_bill_wo_sys(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate3_Outputs_year1_monthly_utility_bill_wo_sys_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_electric_load", (getter)Outputs_get_annual_electric_load,(setter)0,
	PyDoc_STR("*sequence*: Total electric load in each year [kWh]"),
 	NULL},
{"annual_energy_value", (getter)Outputs_get_annual_energy_value,(setter)0,
	PyDoc_STR("*sequence*: Energy value in each year [$]"),
 	NULL},
{"charge_w_sys_dc_fixed", (getter)Outputs_get_charge_w_sys_dc_fixed,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (fixed) [$]"),
 	NULL},
{"charge_w_sys_dc_fixed_apr", (getter)Outputs_get_charge_w_sys_dc_fixed_apr,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (fixed) in Apr [$]"),
 	NULL},
{"charge_w_sys_dc_fixed_aug", (getter)Outputs_get_charge_w_sys_dc_fixed_aug,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (fixed) in Aug [$]"),
 	NULL},
{"charge_w_sys_dc_fixed_dec", (getter)Outputs_get_charge_w_sys_dc_fixed_dec,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (fixed) in Dec [$]"),
 	NULL},
{"charge_w_sys_dc_fixed_feb", (getter)Outputs_get_charge_w_sys_dc_fixed_feb,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (fixed) in Feb [$]"),
 	NULL},
{"charge_w_sys_dc_fixed_jan", (getter)Outputs_get_charge_w_sys_dc_fixed_jan,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (fixed) in Jan [$]"),
 	NULL},
{"charge_w_sys_dc_fixed_jul", (getter)Outputs_get_charge_w_sys_dc_fixed_jul,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (fixed) in Jul [$]"),
 	NULL},
{"charge_w_sys_dc_fixed_jun", (getter)Outputs_get_charge_w_sys_dc_fixed_jun,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (fixed) in Jun [$]"),
 	NULL},
{"charge_w_sys_dc_fixed_mar", (getter)Outputs_get_charge_w_sys_dc_fixed_mar,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (fixed) in Mar [$]"),
 	NULL},
{"charge_w_sys_dc_fixed_may", (getter)Outputs_get_charge_w_sys_dc_fixed_may,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (fixed) in May [$]"),
 	NULL},
{"charge_w_sys_dc_fixed_nov", (getter)Outputs_get_charge_w_sys_dc_fixed_nov,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (fixed) in Nov [$]"),
 	NULL},
{"charge_w_sys_dc_fixed_oct", (getter)Outputs_get_charge_w_sys_dc_fixed_oct,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (fixed) in Oct [$]"),
 	NULL},
{"charge_w_sys_dc_fixed_sep", (getter)Outputs_get_charge_w_sys_dc_fixed_sep,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (fixed) in Sep [$]"),
 	NULL},
{"charge_w_sys_dc_tou", (getter)Outputs_get_charge_w_sys_dc_tou,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (TOU) [$]"),
 	NULL},
{"charge_w_sys_dc_tou_apr", (getter)Outputs_get_charge_w_sys_dc_tou_apr,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (TOU) in Apr [$]"),
 	NULL},
{"charge_w_sys_dc_tou_aug", (getter)Outputs_get_charge_w_sys_dc_tou_aug,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (TOU) in Aug [$]"),
 	NULL},
{"charge_w_sys_dc_tou_dec", (getter)Outputs_get_charge_w_sys_dc_tou_dec,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (TOU) in Dec [$]"),
 	NULL},
{"charge_w_sys_dc_tou_feb", (getter)Outputs_get_charge_w_sys_dc_tou_feb,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (TOU) in Feb [$]"),
 	NULL},
{"charge_w_sys_dc_tou_jan", (getter)Outputs_get_charge_w_sys_dc_tou_jan,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (TOU) in Jan [$]"),
 	NULL},
{"charge_w_sys_dc_tou_jul", (getter)Outputs_get_charge_w_sys_dc_tou_jul,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (TOU) in Jul [$]"),
 	NULL},
{"charge_w_sys_dc_tou_jun", (getter)Outputs_get_charge_w_sys_dc_tou_jun,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (TOU) in Jun [$]"),
 	NULL},
{"charge_w_sys_dc_tou_mar", (getter)Outputs_get_charge_w_sys_dc_tou_mar,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (TOU) in Mar [$]"),
 	NULL},
{"charge_w_sys_dc_tou_may", (getter)Outputs_get_charge_w_sys_dc_tou_may,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (TOU) in May [$]"),
 	NULL},
{"charge_w_sys_dc_tou_nov", (getter)Outputs_get_charge_w_sys_dc_tou_nov,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (TOU) in Nov [$]"),
 	NULL},
{"charge_w_sys_dc_tou_oct", (getter)Outputs_get_charge_w_sys_dc_tou_oct,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (TOU) in Oct [$]"),
 	NULL},
{"charge_w_sys_dc_tou_sep", (getter)Outputs_get_charge_w_sys_dc_tou_sep,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (TOU) in Sep [$]"),
 	NULL},
{"charge_w_sys_ec", (getter)Outputs_get_charge_w_sys_ec,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) [$]"),
 	NULL},
{"charge_w_sys_ec_apr", (getter)Outputs_get_charge_w_sys_ec_apr,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Apr [$]"),
 	NULL},
{"charge_w_sys_ec_apr_p1", (getter)Outputs_get_charge_w_sys_ec_apr_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Apr for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_apr_p10", (getter)Outputs_get_charge_w_sys_ec_apr_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Apr for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_apr_p11", (getter)Outputs_get_charge_w_sys_ec_apr_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Apr for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_apr_p12", (getter)Outputs_get_charge_w_sys_ec_apr_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Apr for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_apr_p2", (getter)Outputs_get_charge_w_sys_ec_apr_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Apr for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_apr_p3", (getter)Outputs_get_charge_w_sys_ec_apr_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Apr for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_apr_p4", (getter)Outputs_get_charge_w_sys_ec_apr_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Apr for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_apr_p5", (getter)Outputs_get_charge_w_sys_ec_apr_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Apr for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_apr_p6", (getter)Outputs_get_charge_w_sys_ec_apr_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Apr for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_apr_p7", (getter)Outputs_get_charge_w_sys_ec_apr_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Apr for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_apr_p8", (getter)Outputs_get_charge_w_sys_ec_apr_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Apr for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_apr_p9", (getter)Outputs_get_charge_w_sys_ec_apr_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Apr for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_aug", (getter)Outputs_get_charge_w_sys_ec_aug,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Aug [$]"),
 	NULL},
{"charge_w_sys_ec_aug_p1", (getter)Outputs_get_charge_w_sys_ec_aug_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Aug for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_aug_p10", (getter)Outputs_get_charge_w_sys_ec_aug_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Aug for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_aug_p11", (getter)Outputs_get_charge_w_sys_ec_aug_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Aug for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_aug_p12", (getter)Outputs_get_charge_w_sys_ec_aug_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Aug for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_aug_p2", (getter)Outputs_get_charge_w_sys_ec_aug_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Aug for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_aug_p3", (getter)Outputs_get_charge_w_sys_ec_aug_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Aug for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_aug_p4", (getter)Outputs_get_charge_w_sys_ec_aug_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Aug for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_aug_p5", (getter)Outputs_get_charge_w_sys_ec_aug_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Aug for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_aug_p6", (getter)Outputs_get_charge_w_sys_ec_aug_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Aug for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_aug_p7", (getter)Outputs_get_charge_w_sys_ec_aug_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Aug for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_aug_p8", (getter)Outputs_get_charge_w_sys_ec_aug_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Aug for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_aug_p9", (getter)Outputs_get_charge_w_sys_ec_aug_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Aug for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_dec", (getter)Outputs_get_charge_w_sys_ec_dec,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Dec [$]"),
 	NULL},
{"charge_w_sys_ec_dec_p1", (getter)Outputs_get_charge_w_sys_ec_dec_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Dec for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_dec_p10", (getter)Outputs_get_charge_w_sys_ec_dec_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Dec for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_dec_p11", (getter)Outputs_get_charge_w_sys_ec_dec_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Dec for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_dec_p12", (getter)Outputs_get_charge_w_sys_ec_dec_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Dec for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_dec_p2", (getter)Outputs_get_charge_w_sys_ec_dec_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Dec for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_dec_p3", (getter)Outputs_get_charge_w_sys_ec_dec_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Dec for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_dec_p4", (getter)Outputs_get_charge_w_sys_ec_dec_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Dec for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_dec_p5", (getter)Outputs_get_charge_w_sys_ec_dec_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Dec for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_dec_p6", (getter)Outputs_get_charge_w_sys_ec_dec_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Dec for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_dec_p7", (getter)Outputs_get_charge_w_sys_ec_dec_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Dec for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_dec_p8", (getter)Outputs_get_charge_w_sys_ec_dec_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Dec for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_dec_p9", (getter)Outputs_get_charge_w_sys_ec_dec_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Dec for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_feb", (getter)Outputs_get_charge_w_sys_ec_feb,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Feb [$]"),
 	NULL},
{"charge_w_sys_ec_feb_p1", (getter)Outputs_get_charge_w_sys_ec_feb_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Feb for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_feb_p10", (getter)Outputs_get_charge_w_sys_ec_feb_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Feb for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_feb_p11", (getter)Outputs_get_charge_w_sys_ec_feb_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Feb for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_feb_p12", (getter)Outputs_get_charge_w_sys_ec_feb_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Feb for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_feb_p2", (getter)Outputs_get_charge_w_sys_ec_feb_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Feb for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_feb_p3", (getter)Outputs_get_charge_w_sys_ec_feb_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Feb for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_feb_p4", (getter)Outputs_get_charge_w_sys_ec_feb_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Feb for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_feb_p5", (getter)Outputs_get_charge_w_sys_ec_feb_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Feb for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_feb_p6", (getter)Outputs_get_charge_w_sys_ec_feb_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Feb for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_feb_p7", (getter)Outputs_get_charge_w_sys_ec_feb_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Feb for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_feb_p8", (getter)Outputs_get_charge_w_sys_ec_feb_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Feb for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_feb_p9", (getter)Outputs_get_charge_w_sys_ec_feb_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Feb for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_flat", (getter)Outputs_get_charge_w_sys_ec_flat,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (flat) [$]"),
 	NULL},
{"charge_w_sys_ec_flat_apr", (getter)Outputs_get_charge_w_sys_ec_flat_apr,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (flat) in Apr [$]"),
 	NULL},
{"charge_w_sys_ec_flat_aug", (getter)Outputs_get_charge_w_sys_ec_flat_aug,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (flat) in Aug [$]"),
 	NULL},
{"charge_w_sys_ec_flat_dec", (getter)Outputs_get_charge_w_sys_ec_flat_dec,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (flat) in Dec [$]"),
 	NULL},
{"charge_w_sys_ec_flat_feb", (getter)Outputs_get_charge_w_sys_ec_flat_feb,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (flat) in Feb [$]"),
 	NULL},
{"charge_w_sys_ec_flat_jan", (getter)Outputs_get_charge_w_sys_ec_flat_jan,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (flat) in Jan [$]"),
 	NULL},
{"charge_w_sys_ec_flat_jul", (getter)Outputs_get_charge_w_sys_ec_flat_jul,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (flat) in Jul [$]"),
 	NULL},
{"charge_w_sys_ec_flat_jun", (getter)Outputs_get_charge_w_sys_ec_flat_jun,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (flat) in Jun [$]"),
 	NULL},
{"charge_w_sys_ec_flat_mar", (getter)Outputs_get_charge_w_sys_ec_flat_mar,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (flat) in Mar [$]"),
 	NULL},
{"charge_w_sys_ec_flat_may", (getter)Outputs_get_charge_w_sys_ec_flat_may,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (flat) in May [$]"),
 	NULL},
{"charge_w_sys_ec_flat_nov", (getter)Outputs_get_charge_w_sys_ec_flat_nov,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (flat) in Nov [$]"),
 	NULL},
{"charge_w_sys_ec_flat_oct", (getter)Outputs_get_charge_w_sys_ec_flat_oct,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (flat) in Oct [$]"),
 	NULL},
{"charge_w_sys_ec_flat_sep", (getter)Outputs_get_charge_w_sys_ec_flat_sep,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (flat) in Sep [$]"),
 	NULL},
{"charge_w_sys_ec_jan", (getter)Outputs_get_charge_w_sys_ec_jan,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jan [$]"),
 	NULL},
{"charge_w_sys_ec_jan_p1", (getter)Outputs_get_charge_w_sys_ec_jan_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jan for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jan_p10", (getter)Outputs_get_charge_w_sys_ec_jan_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jan for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jan_p11", (getter)Outputs_get_charge_w_sys_ec_jan_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jan for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jan_p12", (getter)Outputs_get_charge_w_sys_ec_jan_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jan for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jan_p2", (getter)Outputs_get_charge_w_sys_ec_jan_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jan for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jan_p3", (getter)Outputs_get_charge_w_sys_ec_jan_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jan for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jan_p4", (getter)Outputs_get_charge_w_sys_ec_jan_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jan for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jan_p5", (getter)Outputs_get_charge_w_sys_ec_jan_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jan for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jan_p6", (getter)Outputs_get_charge_w_sys_ec_jan_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jan for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jan_p7", (getter)Outputs_get_charge_w_sys_ec_jan_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jan for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jan_p8", (getter)Outputs_get_charge_w_sys_ec_jan_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jan for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jan_p9", (getter)Outputs_get_charge_w_sys_ec_jan_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jan for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jul", (getter)Outputs_get_charge_w_sys_ec_jul,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jul [$]"),
 	NULL},
{"charge_w_sys_ec_jul_p1", (getter)Outputs_get_charge_w_sys_ec_jul_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jul for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jul_p10", (getter)Outputs_get_charge_w_sys_ec_jul_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jul for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jul_p11", (getter)Outputs_get_charge_w_sys_ec_jul_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jul for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jul_p12", (getter)Outputs_get_charge_w_sys_ec_jul_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jul for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jul_p2", (getter)Outputs_get_charge_w_sys_ec_jul_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jul for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jul_p3", (getter)Outputs_get_charge_w_sys_ec_jul_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jul for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jul_p4", (getter)Outputs_get_charge_w_sys_ec_jul_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jul for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jul_p5", (getter)Outputs_get_charge_w_sys_ec_jul_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jul for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jul_p6", (getter)Outputs_get_charge_w_sys_ec_jul_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jul for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jul_p7", (getter)Outputs_get_charge_w_sys_ec_jul_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jul for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jul_p8", (getter)Outputs_get_charge_w_sys_ec_jul_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jul for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jul_p9", (getter)Outputs_get_charge_w_sys_ec_jul_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jul for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jun", (getter)Outputs_get_charge_w_sys_ec_jun,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jun [$]"),
 	NULL},
{"charge_w_sys_ec_jun_p1", (getter)Outputs_get_charge_w_sys_ec_jun_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jun for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jun_p10", (getter)Outputs_get_charge_w_sys_ec_jun_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jun for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jun_p11", (getter)Outputs_get_charge_w_sys_ec_jun_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jun for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jun_p12", (getter)Outputs_get_charge_w_sys_ec_jun_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jun for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jun_p2", (getter)Outputs_get_charge_w_sys_ec_jun_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jun for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jun_p3", (getter)Outputs_get_charge_w_sys_ec_jun_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jun for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jun_p4", (getter)Outputs_get_charge_w_sys_ec_jun_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jun for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jun_p5", (getter)Outputs_get_charge_w_sys_ec_jun_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jun for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jun_p6", (getter)Outputs_get_charge_w_sys_ec_jun_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jun for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jun_p7", (getter)Outputs_get_charge_w_sys_ec_jun_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jun for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jun_p8", (getter)Outputs_get_charge_w_sys_ec_jun_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jun for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_jun_p9", (getter)Outputs_get_charge_w_sys_ec_jun_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Jun for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_mar", (getter)Outputs_get_charge_w_sys_ec_mar,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Mar [$]"),
 	NULL},
{"charge_w_sys_ec_mar_p1", (getter)Outputs_get_charge_w_sys_ec_mar_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Mar for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_mar_p10", (getter)Outputs_get_charge_w_sys_ec_mar_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Mar for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_mar_p11", (getter)Outputs_get_charge_w_sys_ec_mar_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Mar for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_mar_p12", (getter)Outputs_get_charge_w_sys_ec_mar_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Mar for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_mar_p2", (getter)Outputs_get_charge_w_sys_ec_mar_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Mar for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_mar_p3", (getter)Outputs_get_charge_w_sys_ec_mar_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Mar for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_mar_p4", (getter)Outputs_get_charge_w_sys_ec_mar_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Mar for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_mar_p5", (getter)Outputs_get_charge_w_sys_ec_mar_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Mar for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_mar_p6", (getter)Outputs_get_charge_w_sys_ec_mar_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Mar for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_mar_p7", (getter)Outputs_get_charge_w_sys_ec_mar_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Mar for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_mar_p8", (getter)Outputs_get_charge_w_sys_ec_mar_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Mar for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_mar_p9", (getter)Outputs_get_charge_w_sys_ec_mar_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Mar for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_may", (getter)Outputs_get_charge_w_sys_ec_may,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in May [$]"),
 	NULL},
{"charge_w_sys_ec_may_p1", (getter)Outputs_get_charge_w_sys_ec_may_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in May for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_may_p10", (getter)Outputs_get_charge_w_sys_ec_may_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in May for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_may_p11", (getter)Outputs_get_charge_w_sys_ec_may_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in May for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_may_p12", (getter)Outputs_get_charge_w_sys_ec_may_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in May for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_may_p2", (getter)Outputs_get_charge_w_sys_ec_may_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in May for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_may_p3", (getter)Outputs_get_charge_w_sys_ec_may_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in May for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_may_p4", (getter)Outputs_get_charge_w_sys_ec_may_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in May for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_may_p5", (getter)Outputs_get_charge_w_sys_ec_may_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in May for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_may_p6", (getter)Outputs_get_charge_w_sys_ec_may_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in May for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_may_p7", (getter)Outputs_get_charge_w_sys_ec_may_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in May for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_may_p8", (getter)Outputs_get_charge_w_sys_ec_may_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in May for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_may_p9", (getter)Outputs_get_charge_w_sys_ec_may_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in May for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_nov", (getter)Outputs_get_charge_w_sys_ec_nov,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Nov [$]"),
 	NULL},
{"charge_w_sys_ec_nov_p1", (getter)Outputs_get_charge_w_sys_ec_nov_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Nov for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_nov_p10", (getter)Outputs_get_charge_w_sys_ec_nov_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Nov for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_nov_p11", (getter)Outputs_get_charge_w_sys_ec_nov_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Nov for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_nov_p12", (getter)Outputs_get_charge_w_sys_ec_nov_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Nov for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_nov_p2", (getter)Outputs_get_charge_w_sys_ec_nov_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Nov for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_nov_p3", (getter)Outputs_get_charge_w_sys_ec_nov_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Nov for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_nov_p4", (getter)Outputs_get_charge_w_sys_ec_nov_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Nov for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_nov_p5", (getter)Outputs_get_charge_w_sys_ec_nov_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Nov for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_nov_p6", (getter)Outputs_get_charge_w_sys_ec_nov_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Nov for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_nov_p7", (getter)Outputs_get_charge_w_sys_ec_nov_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Nov for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_nov_p8", (getter)Outputs_get_charge_w_sys_ec_nov_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Nov for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_nov_p9", (getter)Outputs_get_charge_w_sys_ec_nov_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Nov for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_oct", (getter)Outputs_get_charge_w_sys_ec_oct,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Oct [$]"),
 	NULL},
{"charge_w_sys_ec_oct_p1", (getter)Outputs_get_charge_w_sys_ec_oct_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Oct for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_oct_p10", (getter)Outputs_get_charge_w_sys_ec_oct_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Oct for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_oct_p11", (getter)Outputs_get_charge_w_sys_ec_oct_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Oct for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_oct_p12", (getter)Outputs_get_charge_w_sys_ec_oct_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Oct for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_oct_p2", (getter)Outputs_get_charge_w_sys_ec_oct_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Oct for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_oct_p3", (getter)Outputs_get_charge_w_sys_ec_oct_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Oct for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_oct_p4", (getter)Outputs_get_charge_w_sys_ec_oct_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Oct for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_oct_p5", (getter)Outputs_get_charge_w_sys_ec_oct_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Oct for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_oct_p6", (getter)Outputs_get_charge_w_sys_ec_oct_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Oct for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_oct_p7", (getter)Outputs_get_charge_w_sys_ec_oct_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Oct for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_oct_p8", (getter)Outputs_get_charge_w_sys_ec_oct_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Oct for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_oct_p9", (getter)Outputs_get_charge_w_sys_ec_oct_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Oct for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_sep", (getter)Outputs_get_charge_w_sys_ec_sep,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Sep [$]"),
 	NULL},
{"charge_w_sys_ec_sep_p1", (getter)Outputs_get_charge_w_sys_ec_sep_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Sep for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_sep_p10", (getter)Outputs_get_charge_w_sys_ec_sep_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Sep for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_sep_p11", (getter)Outputs_get_charge_w_sys_ec_sep_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Sep for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_sep_p12", (getter)Outputs_get_charge_w_sys_ec_sep_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Sep for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_sep_p2", (getter)Outputs_get_charge_w_sys_ec_sep_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Sep for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_sep_p3", (getter)Outputs_get_charge_w_sys_ec_sep_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Sep for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_sep_p4", (getter)Outputs_get_charge_w_sys_ec_sep_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Sep for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_sep_p5", (getter)Outputs_get_charge_w_sys_ec_sep_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Sep for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_sep_p6", (getter)Outputs_get_charge_w_sys_ec_sep_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Sep for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_sep_p7", (getter)Outputs_get_charge_w_sys_ec_sep_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Sep for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_sep_p8", (getter)Outputs_get_charge_w_sys_ec_sep_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Sep for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_ec_sep_p9", (getter)Outputs_get_charge_w_sys_ec_sep_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (TOU) in Sep for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_w_sys_fixed", (getter)Outputs_get_charge_w_sys_fixed,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge with system [$]"),
 	NULL},
{"charge_w_sys_fixed_apr", (getter)Outputs_get_charge_w_sys_fixed_apr,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge with system in Apr [$]"),
 	NULL},
{"charge_w_sys_fixed_aug", (getter)Outputs_get_charge_w_sys_fixed_aug,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge with system in Aug [$]"),
 	NULL},
{"charge_w_sys_fixed_dec", (getter)Outputs_get_charge_w_sys_fixed_dec,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge with system in Dec [$]"),
 	NULL},
{"charge_w_sys_fixed_feb", (getter)Outputs_get_charge_w_sys_fixed_feb,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge with system in Feb [$]"),
 	NULL},
{"charge_w_sys_fixed_jan", (getter)Outputs_get_charge_w_sys_fixed_jan,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge with system in Jan [$]"),
 	NULL},
{"charge_w_sys_fixed_jul", (getter)Outputs_get_charge_w_sys_fixed_jul,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge with system in Jul [$]"),
 	NULL},
{"charge_w_sys_fixed_jun", (getter)Outputs_get_charge_w_sys_fixed_jun,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge with system in Jun [$]"),
 	NULL},
{"charge_w_sys_fixed_mar", (getter)Outputs_get_charge_w_sys_fixed_mar,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge with system in Mar [$]"),
 	NULL},
{"charge_w_sys_fixed_may", (getter)Outputs_get_charge_w_sys_fixed_may,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge with system in May [$]"),
 	NULL},
{"charge_w_sys_fixed_nov", (getter)Outputs_get_charge_w_sys_fixed_nov,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge with system in Nov [$]"),
 	NULL},
{"charge_w_sys_fixed_oct", (getter)Outputs_get_charge_w_sys_fixed_oct,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge with system in Oct [$]"),
 	NULL},
{"charge_w_sys_fixed_sep", (getter)Outputs_get_charge_w_sys_fixed_sep,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge with system in Sep [$]"),
 	NULL},
{"charge_w_sys_minimum", (getter)Outputs_get_charge_w_sys_minimum,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge with system [$]"),
 	NULL},
{"charge_w_sys_minimum_apr", (getter)Outputs_get_charge_w_sys_minimum_apr,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge with system in Apr [$]"),
 	NULL},
{"charge_w_sys_minimum_aug", (getter)Outputs_get_charge_w_sys_minimum_aug,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge with system in Aug [$]"),
 	NULL},
{"charge_w_sys_minimum_dec", (getter)Outputs_get_charge_w_sys_minimum_dec,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge with system in Dec [$]"),
 	NULL},
{"charge_w_sys_minimum_feb", (getter)Outputs_get_charge_w_sys_minimum_feb,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge with system in Feb [$]"),
 	NULL},
{"charge_w_sys_minimum_jan", (getter)Outputs_get_charge_w_sys_minimum_jan,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge with system in Jan [$]"),
 	NULL},
{"charge_w_sys_minimum_jul", (getter)Outputs_get_charge_w_sys_minimum_jul,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge with system in Jul [$]"),
 	NULL},
{"charge_w_sys_minimum_jun", (getter)Outputs_get_charge_w_sys_minimum_jun,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge with system in Jun [$]"),
 	NULL},
{"charge_w_sys_minimum_mar", (getter)Outputs_get_charge_w_sys_minimum_mar,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge with system in Mar [$]"),
 	NULL},
{"charge_w_sys_minimum_may", (getter)Outputs_get_charge_w_sys_minimum_may,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge with system in May [$]"),
 	NULL},
{"charge_w_sys_minimum_nov", (getter)Outputs_get_charge_w_sys_minimum_nov,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge with system in Nov [$]"),
 	NULL},
{"charge_w_sys_minimum_oct", (getter)Outputs_get_charge_w_sys_minimum_oct,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge with system in Oct [$]"),
 	NULL},
{"charge_w_sys_minimum_sep", (getter)Outputs_get_charge_w_sys_minimum_sep,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge with system in Sep [$]"),
 	NULL},
{"charge_wo_sys_dc_fixed", (getter)Outputs_get_charge_wo_sys_dc_fixed,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (fixed) [$]"),
 	NULL},
{"charge_wo_sys_dc_fixed_apr", (getter)Outputs_get_charge_wo_sys_dc_fixed_apr,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (fixed) in Apr [$]"),
 	NULL},
{"charge_wo_sys_dc_fixed_aug", (getter)Outputs_get_charge_wo_sys_dc_fixed_aug,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (fixed) in Aug [$]"),
 	NULL},
{"charge_wo_sys_dc_fixed_dec", (getter)Outputs_get_charge_wo_sys_dc_fixed_dec,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (fixed) in Dec [$]"),
 	NULL},
{"charge_wo_sys_dc_fixed_feb", (getter)Outputs_get_charge_wo_sys_dc_fixed_feb,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (fixed) in Feb [$]"),
 	NULL},
{"charge_wo_sys_dc_fixed_jan", (getter)Outputs_get_charge_wo_sys_dc_fixed_jan,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (fixed) in Jan [$]"),
 	NULL},
{"charge_wo_sys_dc_fixed_jul", (getter)Outputs_get_charge_wo_sys_dc_fixed_jul,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (fixed) in Jul [$]"),
 	NULL},
{"charge_wo_sys_dc_fixed_jun", (getter)Outputs_get_charge_wo_sys_dc_fixed_jun,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (fixed) in Jun [$]"),
 	NULL},
{"charge_wo_sys_dc_fixed_mar", (getter)Outputs_get_charge_wo_sys_dc_fixed_mar,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (fixed) in Mar [$]"),
 	NULL},
{"charge_wo_sys_dc_fixed_may", (getter)Outputs_get_charge_wo_sys_dc_fixed_may,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (fixed) in May [$]"),
 	NULL},
{"charge_wo_sys_dc_fixed_nov", (getter)Outputs_get_charge_wo_sys_dc_fixed_nov,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (fixed) in Nov [$]"),
 	NULL},
{"charge_wo_sys_dc_fixed_oct", (getter)Outputs_get_charge_wo_sys_dc_fixed_oct,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (fixed) in Oct [$]"),
 	NULL},
{"charge_wo_sys_dc_fixed_sep", (getter)Outputs_get_charge_wo_sys_dc_fixed_sep,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (fixed) in Sep [$]"),
 	NULL},
{"charge_wo_sys_dc_tou", (getter)Outputs_get_charge_wo_sys_dc_tou,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (TOU) [$]"),
 	NULL},
{"charge_wo_sys_dc_tou_apr", (getter)Outputs_get_charge_wo_sys_dc_tou_apr,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (TOU) in Apr [$]"),
 	NULL},
{"charge_wo_sys_dc_tou_aug", (getter)Outputs_get_charge_wo_sys_dc_tou_aug,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (TOU) in Aug [$]"),
 	NULL},
{"charge_wo_sys_dc_tou_dec", (getter)Outputs_get_charge_wo_sys_dc_tou_dec,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (TOU) in Dec [$]"),
 	NULL},
{"charge_wo_sys_dc_tou_feb", (getter)Outputs_get_charge_wo_sys_dc_tou_feb,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (TOU) in Feb [$]"),
 	NULL},
{"charge_wo_sys_dc_tou_jan", (getter)Outputs_get_charge_wo_sys_dc_tou_jan,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (TOU) in Jan [$]"),
 	NULL},
{"charge_wo_sys_dc_tou_jul", (getter)Outputs_get_charge_wo_sys_dc_tou_jul,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (TOU) in Jul [$]"),
 	NULL},
{"charge_wo_sys_dc_tou_jun", (getter)Outputs_get_charge_wo_sys_dc_tou_jun,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (TOU) in Jun [$]"),
 	NULL},
{"charge_wo_sys_dc_tou_mar", (getter)Outputs_get_charge_wo_sys_dc_tou_mar,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (TOU) in Mar [$]"),
 	NULL},
{"charge_wo_sys_dc_tou_may", (getter)Outputs_get_charge_wo_sys_dc_tou_may,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (TOU) in May [$]"),
 	NULL},
{"charge_wo_sys_dc_tou_nov", (getter)Outputs_get_charge_wo_sys_dc_tou_nov,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (TOU) in Nov [$]"),
 	NULL},
{"charge_wo_sys_dc_tou_oct", (getter)Outputs_get_charge_wo_sys_dc_tou_oct,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (TOU) in Oct [$]"),
 	NULL},
{"charge_wo_sys_dc_tou_sep", (getter)Outputs_get_charge_wo_sys_dc_tou_sep,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (TOU) in Sep [$]"),
 	NULL},
{"charge_wo_sys_ec", (getter)Outputs_get_charge_wo_sys_ec,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) [$]"),
 	NULL},
{"charge_wo_sys_ec_apr", (getter)Outputs_get_charge_wo_sys_ec_apr,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Apr [$]"),
 	NULL},
{"charge_wo_sys_ec_apr_p1", (getter)Outputs_get_charge_wo_sys_ec_apr_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Apr for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_apr_p10", (getter)Outputs_get_charge_wo_sys_ec_apr_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Apr for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_apr_p11", (getter)Outputs_get_charge_wo_sys_ec_apr_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Apr for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_apr_p12", (getter)Outputs_get_charge_wo_sys_ec_apr_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Apr for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_apr_p2", (getter)Outputs_get_charge_wo_sys_ec_apr_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Apr for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_apr_p3", (getter)Outputs_get_charge_wo_sys_ec_apr_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Apr for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_apr_p4", (getter)Outputs_get_charge_wo_sys_ec_apr_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Apr for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_apr_p5", (getter)Outputs_get_charge_wo_sys_ec_apr_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Apr for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_apr_p6", (getter)Outputs_get_charge_wo_sys_ec_apr_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Apr for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_apr_p7", (getter)Outputs_get_charge_wo_sys_ec_apr_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Apr for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_apr_p8", (getter)Outputs_get_charge_wo_sys_ec_apr_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Apr for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_apr_p9", (getter)Outputs_get_charge_wo_sys_ec_apr_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Apr for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_aug", (getter)Outputs_get_charge_wo_sys_ec_aug,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Aug [$]"),
 	NULL},
{"charge_wo_sys_ec_aug_p1", (getter)Outputs_get_charge_wo_sys_ec_aug_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Aug for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_aug_p10", (getter)Outputs_get_charge_wo_sys_ec_aug_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Aug for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_aug_p11", (getter)Outputs_get_charge_wo_sys_ec_aug_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Aug for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_aug_p12", (getter)Outputs_get_charge_wo_sys_ec_aug_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Aug for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_aug_p2", (getter)Outputs_get_charge_wo_sys_ec_aug_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Aug for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_aug_p3", (getter)Outputs_get_charge_wo_sys_ec_aug_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Aug for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_aug_p4", (getter)Outputs_get_charge_wo_sys_ec_aug_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Aug for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_aug_p5", (getter)Outputs_get_charge_wo_sys_ec_aug_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Aug for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_aug_p6", (getter)Outputs_get_charge_wo_sys_ec_aug_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Aug for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_aug_p7", (getter)Outputs_get_charge_wo_sys_ec_aug_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Aug for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_aug_p8", (getter)Outputs_get_charge_wo_sys_ec_aug_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Aug for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_aug_p9", (getter)Outputs_get_charge_wo_sys_ec_aug_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Aug for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_dec", (getter)Outputs_get_charge_wo_sys_ec_dec,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Dec [$]"),
 	NULL},
{"charge_wo_sys_ec_dec_p1", (getter)Outputs_get_charge_wo_sys_ec_dec_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Dec for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_dec_p10", (getter)Outputs_get_charge_wo_sys_ec_dec_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Dec for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_dec_p11", (getter)Outputs_get_charge_wo_sys_ec_dec_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Dec for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_dec_p12", (getter)Outputs_get_charge_wo_sys_ec_dec_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Dec for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_dec_p2", (getter)Outputs_get_charge_wo_sys_ec_dec_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Dec for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_dec_p3", (getter)Outputs_get_charge_wo_sys_ec_dec_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Dec for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_dec_p4", (getter)Outputs_get_charge_wo_sys_ec_dec_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Dec for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_dec_p5", (getter)Outputs_get_charge_wo_sys_ec_dec_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Dec for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_dec_p6", (getter)Outputs_get_charge_wo_sys_ec_dec_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Dec for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_dec_p7", (getter)Outputs_get_charge_wo_sys_ec_dec_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Dec for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_dec_p8", (getter)Outputs_get_charge_wo_sys_ec_dec_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Dec for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_dec_p9", (getter)Outputs_get_charge_wo_sys_ec_dec_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Dec for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_feb", (getter)Outputs_get_charge_wo_sys_ec_feb,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Feb [$]"),
 	NULL},
{"charge_wo_sys_ec_feb_p1", (getter)Outputs_get_charge_wo_sys_ec_feb_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Feb for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_feb_p10", (getter)Outputs_get_charge_wo_sys_ec_feb_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Feb for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_feb_p11", (getter)Outputs_get_charge_wo_sys_ec_feb_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Feb for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_feb_p12", (getter)Outputs_get_charge_wo_sys_ec_feb_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Feb for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_feb_p2", (getter)Outputs_get_charge_wo_sys_ec_feb_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Feb for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_feb_p3", (getter)Outputs_get_charge_wo_sys_ec_feb_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Feb for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_feb_p4", (getter)Outputs_get_charge_wo_sys_ec_feb_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Feb for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_feb_p5", (getter)Outputs_get_charge_wo_sys_ec_feb_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Feb for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_feb_p6", (getter)Outputs_get_charge_wo_sys_ec_feb_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Feb for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_feb_p7", (getter)Outputs_get_charge_wo_sys_ec_feb_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Feb for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_feb_p8", (getter)Outputs_get_charge_wo_sys_ec_feb_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Feb for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_feb_p9", (getter)Outputs_get_charge_wo_sys_ec_feb_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Feb for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_flat", (getter)Outputs_get_charge_wo_sys_ec_flat,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (flat) [$]"),
 	NULL},
{"charge_wo_sys_ec_flat_apr", (getter)Outputs_get_charge_wo_sys_ec_flat_apr,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (flat) in Apr [$]"),
 	NULL},
{"charge_wo_sys_ec_flat_aug", (getter)Outputs_get_charge_wo_sys_ec_flat_aug,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (flat) in Aug [$]"),
 	NULL},
{"charge_wo_sys_ec_flat_dec", (getter)Outputs_get_charge_wo_sys_ec_flat_dec,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (flat) in Dec [$]"),
 	NULL},
{"charge_wo_sys_ec_flat_feb", (getter)Outputs_get_charge_wo_sys_ec_flat_feb,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (flat) in Feb [$]"),
 	NULL},
{"charge_wo_sys_ec_flat_jan", (getter)Outputs_get_charge_wo_sys_ec_flat_jan,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (flat) in Jan [$]"),
 	NULL},
{"charge_wo_sys_ec_flat_jul", (getter)Outputs_get_charge_wo_sys_ec_flat_jul,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (flat) in Jul [$]"),
 	NULL},
{"charge_wo_sys_ec_flat_jun", (getter)Outputs_get_charge_wo_sys_ec_flat_jun,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (flat) in Jun [$]"),
 	NULL},
{"charge_wo_sys_ec_flat_mar", (getter)Outputs_get_charge_wo_sys_ec_flat_mar,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (flat) in Mar [$]"),
 	NULL},
{"charge_wo_sys_ec_flat_may", (getter)Outputs_get_charge_wo_sys_ec_flat_may,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (flat) in May [$]"),
 	NULL},
{"charge_wo_sys_ec_flat_nov", (getter)Outputs_get_charge_wo_sys_ec_flat_nov,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (flat) in Nov [$]"),
 	NULL},
{"charge_wo_sys_ec_flat_oct", (getter)Outputs_get_charge_wo_sys_ec_flat_oct,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (flat) in Oct [$]"),
 	NULL},
{"charge_wo_sys_ec_flat_sep", (getter)Outputs_get_charge_wo_sys_ec_flat_sep,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (flat) in Sep [$]"),
 	NULL},
{"charge_wo_sys_ec_jan", (getter)Outputs_get_charge_wo_sys_ec_jan,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jan [$]"),
 	NULL},
{"charge_wo_sys_ec_jan_p1", (getter)Outputs_get_charge_wo_sys_ec_jan_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jan for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jan_p10", (getter)Outputs_get_charge_wo_sys_ec_jan_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jan for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jan_p11", (getter)Outputs_get_charge_wo_sys_ec_jan_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jan for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jan_p12", (getter)Outputs_get_charge_wo_sys_ec_jan_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jan for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jan_p2", (getter)Outputs_get_charge_wo_sys_ec_jan_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jan for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jan_p3", (getter)Outputs_get_charge_wo_sys_ec_jan_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jan for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jan_p4", (getter)Outputs_get_charge_wo_sys_ec_jan_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jan for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jan_p5", (getter)Outputs_get_charge_wo_sys_ec_jan_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jan for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jan_p6", (getter)Outputs_get_charge_wo_sys_ec_jan_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jan for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jan_p7", (getter)Outputs_get_charge_wo_sys_ec_jan_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jan for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jan_p8", (getter)Outputs_get_charge_wo_sys_ec_jan_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jan for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jan_p9", (getter)Outputs_get_charge_wo_sys_ec_jan_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jan for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jul", (getter)Outputs_get_charge_wo_sys_ec_jul,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jul [$]"),
 	NULL},
{"charge_wo_sys_ec_jul_p1", (getter)Outputs_get_charge_wo_sys_ec_jul_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jul for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jul_p10", (getter)Outputs_get_charge_wo_sys_ec_jul_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jul for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jul_p11", (getter)Outputs_get_charge_wo_sys_ec_jul_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jul for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jul_p12", (getter)Outputs_get_charge_wo_sys_ec_jul_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jul for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jul_p2", (getter)Outputs_get_charge_wo_sys_ec_jul_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jul for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jul_p3", (getter)Outputs_get_charge_wo_sys_ec_jul_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jul for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jul_p4", (getter)Outputs_get_charge_wo_sys_ec_jul_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jul for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jul_p5", (getter)Outputs_get_charge_wo_sys_ec_jul_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jul for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jul_p6", (getter)Outputs_get_charge_wo_sys_ec_jul_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jul for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jul_p7", (getter)Outputs_get_charge_wo_sys_ec_jul_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jul for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jul_p8", (getter)Outputs_get_charge_wo_sys_ec_jul_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jul for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jul_p9", (getter)Outputs_get_charge_wo_sys_ec_jul_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jul for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jun", (getter)Outputs_get_charge_wo_sys_ec_jun,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jun [$]"),
 	NULL},
{"charge_wo_sys_ec_jun_p1", (getter)Outputs_get_charge_wo_sys_ec_jun_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jun for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jun_p10", (getter)Outputs_get_charge_wo_sys_ec_jun_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jun for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jun_p11", (getter)Outputs_get_charge_wo_sys_ec_jun_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jun for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jun_p12", (getter)Outputs_get_charge_wo_sys_ec_jun_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jun for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jun_p2", (getter)Outputs_get_charge_wo_sys_ec_jun_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jun for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jun_p3", (getter)Outputs_get_charge_wo_sys_ec_jun_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jun for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jun_p4", (getter)Outputs_get_charge_wo_sys_ec_jun_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jun for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jun_p5", (getter)Outputs_get_charge_wo_sys_ec_jun_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jun for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jun_p6", (getter)Outputs_get_charge_wo_sys_ec_jun_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jun for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jun_p7", (getter)Outputs_get_charge_wo_sys_ec_jun_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jun for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jun_p8", (getter)Outputs_get_charge_wo_sys_ec_jun_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jun for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_jun_p9", (getter)Outputs_get_charge_wo_sys_ec_jun_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Jun for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_mar", (getter)Outputs_get_charge_wo_sys_ec_mar,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Mar [$]"),
 	NULL},
{"charge_wo_sys_ec_mar_p1", (getter)Outputs_get_charge_wo_sys_ec_mar_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Mar for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_mar_p10", (getter)Outputs_get_charge_wo_sys_ec_mar_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Mar for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_mar_p11", (getter)Outputs_get_charge_wo_sys_ec_mar_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Mar for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_mar_p12", (getter)Outputs_get_charge_wo_sys_ec_mar_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Mar for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_mar_p2", (getter)Outputs_get_charge_wo_sys_ec_mar_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Mar for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_mar_p3", (getter)Outputs_get_charge_wo_sys_ec_mar_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Mar for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_mar_p4", (getter)Outputs_get_charge_wo_sys_ec_mar_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Mar for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_mar_p5", (getter)Outputs_get_charge_wo_sys_ec_mar_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Mar for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_mar_p6", (getter)Outputs_get_charge_wo_sys_ec_mar_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Mar for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_mar_p7", (getter)Outputs_get_charge_wo_sys_ec_mar_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Mar for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_mar_p8", (getter)Outputs_get_charge_wo_sys_ec_mar_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Mar for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_mar_p9", (getter)Outputs_get_charge_wo_sys_ec_mar_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Mar for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_may", (getter)Outputs_get_charge_wo_sys_ec_may,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in May [$]"),
 	NULL},
{"charge_wo_sys_ec_may_p1", (getter)Outputs_get_charge_wo_sys_ec_may_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in May for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_may_p10", (getter)Outputs_get_charge_wo_sys_ec_may_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in May for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_may_p11", (getter)Outputs_get_charge_wo_sys_ec_may_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in May for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_may_p12", (getter)Outputs_get_charge_wo_sys_ec_may_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in May for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_may_p2", (getter)Outputs_get_charge_wo_sys_ec_may_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in May for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_may_p3", (getter)Outputs_get_charge_wo_sys_ec_may_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in May for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_may_p4", (getter)Outputs_get_charge_wo_sys_ec_may_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in May for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_may_p5", (getter)Outputs_get_charge_wo_sys_ec_may_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in May for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_may_p6", (getter)Outputs_get_charge_wo_sys_ec_may_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in May for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_may_p7", (getter)Outputs_get_charge_wo_sys_ec_may_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in May for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_may_p8", (getter)Outputs_get_charge_wo_sys_ec_may_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in May for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_may_p9", (getter)Outputs_get_charge_wo_sys_ec_may_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in May for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_nov", (getter)Outputs_get_charge_wo_sys_ec_nov,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Nov [$]"),
 	NULL},
{"charge_wo_sys_ec_nov_p1", (getter)Outputs_get_charge_wo_sys_ec_nov_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Nov for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_nov_p10", (getter)Outputs_get_charge_wo_sys_ec_nov_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Nov for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_nov_p11", (getter)Outputs_get_charge_wo_sys_ec_nov_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Nov for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_nov_p12", (getter)Outputs_get_charge_wo_sys_ec_nov_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Nov for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_nov_p2", (getter)Outputs_get_charge_wo_sys_ec_nov_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Nov for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_nov_p3", (getter)Outputs_get_charge_wo_sys_ec_nov_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Nov for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_nov_p4", (getter)Outputs_get_charge_wo_sys_ec_nov_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Nov for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_nov_p5", (getter)Outputs_get_charge_wo_sys_ec_nov_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Nov for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_nov_p6", (getter)Outputs_get_charge_wo_sys_ec_nov_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Nov for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_nov_p7", (getter)Outputs_get_charge_wo_sys_ec_nov_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Nov for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_nov_p8", (getter)Outputs_get_charge_wo_sys_ec_nov_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Nov for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_nov_p9", (getter)Outputs_get_charge_wo_sys_ec_nov_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Nov for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_oct", (getter)Outputs_get_charge_wo_sys_ec_oct,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Oct [$]"),
 	NULL},
{"charge_wo_sys_ec_oct_p1", (getter)Outputs_get_charge_wo_sys_ec_oct_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Oct for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_oct_p10", (getter)Outputs_get_charge_wo_sys_ec_oct_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Oct for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_oct_p11", (getter)Outputs_get_charge_wo_sys_ec_oct_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Oct for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_oct_p12", (getter)Outputs_get_charge_wo_sys_ec_oct_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Oct for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_oct_p2", (getter)Outputs_get_charge_wo_sys_ec_oct_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Oct for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_oct_p3", (getter)Outputs_get_charge_wo_sys_ec_oct_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Oct for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_oct_p4", (getter)Outputs_get_charge_wo_sys_ec_oct_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Oct for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_oct_p5", (getter)Outputs_get_charge_wo_sys_ec_oct_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Oct for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_oct_p6", (getter)Outputs_get_charge_wo_sys_ec_oct_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Oct for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_oct_p7", (getter)Outputs_get_charge_wo_sys_ec_oct_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Oct for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_oct_p8", (getter)Outputs_get_charge_wo_sys_ec_oct_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Oct for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_oct_p9", (getter)Outputs_get_charge_wo_sys_ec_oct_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Oct for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_sep", (getter)Outputs_get_charge_wo_sys_ec_sep,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Sep [$]"),
 	NULL},
{"charge_wo_sys_ec_sep_p1", (getter)Outputs_get_charge_wo_sys_ec_sep_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Sep for period 1 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_sep_p10", (getter)Outputs_get_charge_wo_sys_ec_sep_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Sep for period 10 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_sep_p11", (getter)Outputs_get_charge_wo_sys_ec_sep_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Sep for period 11 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_sep_p12", (getter)Outputs_get_charge_wo_sys_ec_sep_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Sep for period 12 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_sep_p2", (getter)Outputs_get_charge_wo_sys_ec_sep_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Sep for period 2 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_sep_p3", (getter)Outputs_get_charge_wo_sys_ec_sep_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Sep for period 3 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_sep_p4", (getter)Outputs_get_charge_wo_sys_ec_sep_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Sep for period 4 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_sep_p5", (getter)Outputs_get_charge_wo_sys_ec_sep_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Sep for period 5 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_sep_p6", (getter)Outputs_get_charge_wo_sys_ec_sep_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Sep for period 6 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_sep_p7", (getter)Outputs_get_charge_wo_sys_ec_sep_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Sep for period 7 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_sep_p8", (getter)Outputs_get_charge_wo_sys_ec_sep_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Sep for period 8 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_ec_sep_p9", (getter)Outputs_get_charge_wo_sys_ec_sep_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (TOU) in Sep for period 9 and tiers 1 through 6 [$]"),
 	NULL},
{"charge_wo_sys_fixed", (getter)Outputs_get_charge_wo_sys_fixed,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge without system [$]"),
 	NULL},
{"charge_wo_sys_fixed_apr", (getter)Outputs_get_charge_wo_sys_fixed_apr,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge without system in Apr [$]"),
 	NULL},
{"charge_wo_sys_fixed_aug", (getter)Outputs_get_charge_wo_sys_fixed_aug,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge without system in Aug [$]"),
 	NULL},
{"charge_wo_sys_fixed_dec", (getter)Outputs_get_charge_wo_sys_fixed_dec,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge without system in Dec [$]"),
 	NULL},
{"charge_wo_sys_fixed_feb", (getter)Outputs_get_charge_wo_sys_fixed_feb,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge without system in Feb [$]"),
 	NULL},
{"charge_wo_sys_fixed_jan", (getter)Outputs_get_charge_wo_sys_fixed_jan,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge without system in Jan [$]"),
 	NULL},
{"charge_wo_sys_fixed_jul", (getter)Outputs_get_charge_wo_sys_fixed_jul,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge without system in Jul [$]"),
 	NULL},
{"charge_wo_sys_fixed_jun", (getter)Outputs_get_charge_wo_sys_fixed_jun,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge without system in Jun [$]"),
 	NULL},
{"charge_wo_sys_fixed_mar", (getter)Outputs_get_charge_wo_sys_fixed_mar,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge without system in Mar [$]"),
 	NULL},
{"charge_wo_sys_fixed_may", (getter)Outputs_get_charge_wo_sys_fixed_may,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge without system in May [$]"),
 	NULL},
{"charge_wo_sys_fixed_nov", (getter)Outputs_get_charge_wo_sys_fixed_nov,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge without system in Nov [$]"),
 	NULL},
{"charge_wo_sys_fixed_oct", (getter)Outputs_get_charge_wo_sys_fixed_oct,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge without system in Oct [$]"),
 	NULL},
{"charge_wo_sys_fixed_sep", (getter)Outputs_get_charge_wo_sys_fixed_sep,(setter)0,
	PyDoc_STR("*sequence*: Fixed charge without system in Sep [$]"),
 	NULL},
{"charge_wo_sys_minimum", (getter)Outputs_get_charge_wo_sys_minimum,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge without system [$]"),
 	NULL},
{"charge_wo_sys_minimum_apr", (getter)Outputs_get_charge_wo_sys_minimum_apr,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge without system in Apr [$]"),
 	NULL},
{"charge_wo_sys_minimum_aug", (getter)Outputs_get_charge_wo_sys_minimum_aug,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge without system in Aug [$]"),
 	NULL},
{"charge_wo_sys_minimum_dec", (getter)Outputs_get_charge_wo_sys_minimum_dec,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge without system in Dec [$]"),
 	NULL},
{"charge_wo_sys_minimum_feb", (getter)Outputs_get_charge_wo_sys_minimum_feb,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge without system in Feb [$]"),
 	NULL},
{"charge_wo_sys_minimum_jan", (getter)Outputs_get_charge_wo_sys_minimum_jan,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge without system in Jan [$]"),
 	NULL},
{"charge_wo_sys_minimum_jul", (getter)Outputs_get_charge_wo_sys_minimum_jul,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge without system in Jul [$]"),
 	NULL},
{"charge_wo_sys_minimum_jun", (getter)Outputs_get_charge_wo_sys_minimum_jun,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge without system in Jun [$]"),
 	NULL},
{"charge_wo_sys_minimum_mar", (getter)Outputs_get_charge_wo_sys_minimum_mar,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge without system in Mar [$]"),
 	NULL},
{"charge_wo_sys_minimum_may", (getter)Outputs_get_charge_wo_sys_minimum_may,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge without system in May [$]"),
 	NULL},
{"charge_wo_sys_minimum_nov", (getter)Outputs_get_charge_wo_sys_minimum_nov,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge without system in Nov [$]"),
 	NULL},
{"charge_wo_sys_minimum_oct", (getter)Outputs_get_charge_wo_sys_minimum_oct,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge without system in Oct [$]"),
 	NULL},
{"charge_wo_sys_minimum_sep", (getter)Outputs_get_charge_wo_sys_minimum_sep,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge without system in Sep [$]"),
 	NULL},
{"elec_cost_with_system", (getter)Outputs_get_elec_cost_with_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity cost with system [$/yr]"),
 	NULL},
{"elec_cost_with_system_year1", (getter)Outputs_get_elec_cost_with_system_year1,(setter)0,
	PyDoc_STR("*float*: Electricity cost with system [$/yr]"),
 	NULL},
{"elec_cost_without_system", (getter)Outputs_get_elec_cost_without_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity cost without system [$/yr]"),
 	NULL},
{"elec_cost_without_system_year1", (getter)Outputs_get_elec_cost_without_system_year1,(setter)0,
	PyDoc_STR("*float*: Electricity cost without system [$/yr]"),
 	NULL},
{"energy_w_sys_ec_apr_p1", (getter)Outputs_get_energy_w_sys_ec_apr_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Apr for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_apr_p10", (getter)Outputs_get_energy_w_sys_ec_apr_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Apr for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_apr_p11", (getter)Outputs_get_energy_w_sys_ec_apr_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Apr for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_apr_p12", (getter)Outputs_get_energy_w_sys_ec_apr_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Apr for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_apr_p2", (getter)Outputs_get_energy_w_sys_ec_apr_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Apr for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_apr_p3", (getter)Outputs_get_energy_w_sys_ec_apr_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Apr for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_apr_p4", (getter)Outputs_get_energy_w_sys_ec_apr_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Apr for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_apr_p5", (getter)Outputs_get_energy_w_sys_ec_apr_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Apr for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_apr_p6", (getter)Outputs_get_energy_w_sys_ec_apr_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Apr for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_apr_p7", (getter)Outputs_get_energy_w_sys_ec_apr_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Apr for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_apr_p8", (getter)Outputs_get_energy_w_sys_ec_apr_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Apr for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_apr_p9", (getter)Outputs_get_energy_w_sys_ec_apr_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Apr for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_aug_p1", (getter)Outputs_get_energy_w_sys_ec_aug_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Aug for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_aug_p10", (getter)Outputs_get_energy_w_sys_ec_aug_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Aug for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_aug_p11", (getter)Outputs_get_energy_w_sys_ec_aug_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Aug for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_aug_p12", (getter)Outputs_get_energy_w_sys_ec_aug_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Aug for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_aug_p2", (getter)Outputs_get_energy_w_sys_ec_aug_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Aug for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_aug_p3", (getter)Outputs_get_energy_w_sys_ec_aug_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Aug for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_aug_p4", (getter)Outputs_get_energy_w_sys_ec_aug_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Aug for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_aug_p5", (getter)Outputs_get_energy_w_sys_ec_aug_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Aug for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_aug_p6", (getter)Outputs_get_energy_w_sys_ec_aug_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Aug for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_aug_p7", (getter)Outputs_get_energy_w_sys_ec_aug_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Aug for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_aug_p8", (getter)Outputs_get_energy_w_sys_ec_aug_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Aug for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_aug_p9", (getter)Outputs_get_energy_w_sys_ec_aug_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Aug for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_dec_p1", (getter)Outputs_get_energy_w_sys_ec_dec_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Dec for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_dec_p10", (getter)Outputs_get_energy_w_sys_ec_dec_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Dec for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_dec_p11", (getter)Outputs_get_energy_w_sys_ec_dec_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Dec for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_dec_p12", (getter)Outputs_get_energy_w_sys_ec_dec_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Dec for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_dec_p2", (getter)Outputs_get_energy_w_sys_ec_dec_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Dec for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_dec_p3", (getter)Outputs_get_energy_w_sys_ec_dec_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Dec for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_dec_p4", (getter)Outputs_get_energy_w_sys_ec_dec_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Dec for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_dec_p5", (getter)Outputs_get_energy_w_sys_ec_dec_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Dec for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_dec_p6", (getter)Outputs_get_energy_w_sys_ec_dec_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Dec for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_dec_p7", (getter)Outputs_get_energy_w_sys_ec_dec_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Dec for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_dec_p8", (getter)Outputs_get_energy_w_sys_ec_dec_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Dec for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_dec_p9", (getter)Outputs_get_energy_w_sys_ec_dec_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Dec for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_feb_p1", (getter)Outputs_get_energy_w_sys_ec_feb_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Feb for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_feb_p10", (getter)Outputs_get_energy_w_sys_ec_feb_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Feb for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_feb_p11", (getter)Outputs_get_energy_w_sys_ec_feb_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Feb for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_feb_p12", (getter)Outputs_get_energy_w_sys_ec_feb_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Feb for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_feb_p2", (getter)Outputs_get_energy_w_sys_ec_feb_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Feb for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_feb_p3", (getter)Outputs_get_energy_w_sys_ec_feb_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Feb for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_feb_p4", (getter)Outputs_get_energy_w_sys_ec_feb_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Feb for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_feb_p5", (getter)Outputs_get_energy_w_sys_ec_feb_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Feb for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_feb_p6", (getter)Outputs_get_energy_w_sys_ec_feb_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Feb for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_feb_p7", (getter)Outputs_get_energy_w_sys_ec_feb_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Feb for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_feb_p8", (getter)Outputs_get_energy_w_sys_ec_feb_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Feb for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_feb_p9", (getter)Outputs_get_energy_w_sys_ec_feb_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Feb for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jan_p1", (getter)Outputs_get_energy_w_sys_ec_jan_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jan for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jan_p10", (getter)Outputs_get_energy_w_sys_ec_jan_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jan for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jan_p11", (getter)Outputs_get_energy_w_sys_ec_jan_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jan for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jan_p12", (getter)Outputs_get_energy_w_sys_ec_jan_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jan for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jan_p2", (getter)Outputs_get_energy_w_sys_ec_jan_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jan for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jan_p3", (getter)Outputs_get_energy_w_sys_ec_jan_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jan for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jan_p4", (getter)Outputs_get_energy_w_sys_ec_jan_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jan for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jan_p5", (getter)Outputs_get_energy_w_sys_ec_jan_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jan for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jan_p6", (getter)Outputs_get_energy_w_sys_ec_jan_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jan for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jan_p7", (getter)Outputs_get_energy_w_sys_ec_jan_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jan for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jan_p8", (getter)Outputs_get_energy_w_sys_ec_jan_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jan for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jan_p9", (getter)Outputs_get_energy_w_sys_ec_jan_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jan for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jul_p1", (getter)Outputs_get_energy_w_sys_ec_jul_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jul for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jul_p10", (getter)Outputs_get_energy_w_sys_ec_jul_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jul for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jul_p11", (getter)Outputs_get_energy_w_sys_ec_jul_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jul for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jul_p12", (getter)Outputs_get_energy_w_sys_ec_jul_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jul for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jul_p2", (getter)Outputs_get_energy_w_sys_ec_jul_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jul for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jul_p3", (getter)Outputs_get_energy_w_sys_ec_jul_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jul for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jul_p4", (getter)Outputs_get_energy_w_sys_ec_jul_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jul for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jul_p5", (getter)Outputs_get_energy_w_sys_ec_jul_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jul for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jul_p6", (getter)Outputs_get_energy_w_sys_ec_jul_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jul for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jul_p7", (getter)Outputs_get_energy_w_sys_ec_jul_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jul for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jul_p8", (getter)Outputs_get_energy_w_sys_ec_jul_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jul for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jul_p9", (getter)Outputs_get_energy_w_sys_ec_jul_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jul for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jun_p1", (getter)Outputs_get_energy_w_sys_ec_jun_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jun for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jun_p10", (getter)Outputs_get_energy_w_sys_ec_jun_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jun for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jun_p11", (getter)Outputs_get_energy_w_sys_ec_jun_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jun for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jun_p12", (getter)Outputs_get_energy_w_sys_ec_jun_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jun for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jun_p2", (getter)Outputs_get_energy_w_sys_ec_jun_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jun for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jun_p3", (getter)Outputs_get_energy_w_sys_ec_jun_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jun for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jun_p4", (getter)Outputs_get_energy_w_sys_ec_jun_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jun for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jun_p5", (getter)Outputs_get_energy_w_sys_ec_jun_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jun for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jun_p6", (getter)Outputs_get_energy_w_sys_ec_jun_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jun for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jun_p7", (getter)Outputs_get_energy_w_sys_ec_jun_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jun for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jun_p8", (getter)Outputs_get_energy_w_sys_ec_jun_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jun for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_jun_p9", (getter)Outputs_get_energy_w_sys_ec_jun_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Jun for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_mar_p1", (getter)Outputs_get_energy_w_sys_ec_mar_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Mar for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_mar_p10", (getter)Outputs_get_energy_w_sys_ec_mar_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Mar for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_mar_p11", (getter)Outputs_get_energy_w_sys_ec_mar_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Mar for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_mar_p12", (getter)Outputs_get_energy_w_sys_ec_mar_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Mar for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_mar_p2", (getter)Outputs_get_energy_w_sys_ec_mar_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Mar for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_mar_p3", (getter)Outputs_get_energy_w_sys_ec_mar_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Mar for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_mar_p4", (getter)Outputs_get_energy_w_sys_ec_mar_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Mar for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_mar_p5", (getter)Outputs_get_energy_w_sys_ec_mar_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Mar for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_mar_p6", (getter)Outputs_get_energy_w_sys_ec_mar_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Mar for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_mar_p7", (getter)Outputs_get_energy_w_sys_ec_mar_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Mar for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_mar_p8", (getter)Outputs_get_energy_w_sys_ec_mar_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Mar for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_mar_p9", (getter)Outputs_get_energy_w_sys_ec_mar_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Mar for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_may_p1", (getter)Outputs_get_energy_w_sys_ec_may_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in May for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_may_p10", (getter)Outputs_get_energy_w_sys_ec_may_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in May for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_may_p11", (getter)Outputs_get_energy_w_sys_ec_may_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in May for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_may_p12", (getter)Outputs_get_energy_w_sys_ec_may_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in May for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_may_p2", (getter)Outputs_get_energy_w_sys_ec_may_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in May for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_may_p3", (getter)Outputs_get_energy_w_sys_ec_may_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in May for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_may_p4", (getter)Outputs_get_energy_w_sys_ec_may_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in May for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_may_p5", (getter)Outputs_get_energy_w_sys_ec_may_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in May for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_may_p6", (getter)Outputs_get_energy_w_sys_ec_may_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in May for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_may_p7", (getter)Outputs_get_energy_w_sys_ec_may_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in May for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_may_p8", (getter)Outputs_get_energy_w_sys_ec_may_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in May for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_may_p9", (getter)Outputs_get_energy_w_sys_ec_may_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in May for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_nov_p1", (getter)Outputs_get_energy_w_sys_ec_nov_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Nov for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_nov_p10", (getter)Outputs_get_energy_w_sys_ec_nov_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Nov for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_nov_p11", (getter)Outputs_get_energy_w_sys_ec_nov_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Nov for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_nov_p12", (getter)Outputs_get_energy_w_sys_ec_nov_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Nov for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_nov_p2", (getter)Outputs_get_energy_w_sys_ec_nov_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Nov for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_nov_p3", (getter)Outputs_get_energy_w_sys_ec_nov_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Nov for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_nov_p4", (getter)Outputs_get_energy_w_sys_ec_nov_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Nov for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_nov_p5", (getter)Outputs_get_energy_w_sys_ec_nov_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Nov for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_nov_p6", (getter)Outputs_get_energy_w_sys_ec_nov_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Nov for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_nov_p7", (getter)Outputs_get_energy_w_sys_ec_nov_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Nov for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_nov_p8", (getter)Outputs_get_energy_w_sys_ec_nov_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Nov for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_nov_p9", (getter)Outputs_get_energy_w_sys_ec_nov_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Nov for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_oct_p1", (getter)Outputs_get_energy_w_sys_ec_oct_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Oct for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_oct_p10", (getter)Outputs_get_energy_w_sys_ec_oct_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Oct for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_oct_p11", (getter)Outputs_get_energy_w_sys_ec_oct_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Oct for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_oct_p12", (getter)Outputs_get_energy_w_sys_ec_oct_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Oct for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_oct_p2", (getter)Outputs_get_energy_w_sys_ec_oct_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Oct for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_oct_p3", (getter)Outputs_get_energy_w_sys_ec_oct_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Oct for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_oct_p4", (getter)Outputs_get_energy_w_sys_ec_oct_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Oct for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_oct_p5", (getter)Outputs_get_energy_w_sys_ec_oct_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Oct for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_oct_p6", (getter)Outputs_get_energy_w_sys_ec_oct_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Oct for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_oct_p7", (getter)Outputs_get_energy_w_sys_ec_oct_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Oct for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_oct_p8", (getter)Outputs_get_energy_w_sys_ec_oct_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Oct for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_oct_p9", (getter)Outputs_get_energy_w_sys_ec_oct_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Oct for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_sep_p1", (getter)Outputs_get_energy_w_sys_ec_sep_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Sep for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_sep_p10", (getter)Outputs_get_energy_w_sys_ec_sep_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Sep for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_sep_p11", (getter)Outputs_get_energy_w_sys_ec_sep_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Sep for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_sep_p12", (getter)Outputs_get_energy_w_sys_ec_sep_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Sep for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_sep_p2", (getter)Outputs_get_energy_w_sys_ec_sep_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Sep for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_sep_p3", (getter)Outputs_get_energy_w_sys_ec_sep_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Sep for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_sep_p4", (getter)Outputs_get_energy_w_sys_ec_sep_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Sep for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_sep_p5", (getter)Outputs_get_energy_w_sys_ec_sep_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Sep for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_sep_p6", (getter)Outputs_get_energy_w_sys_ec_sep_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Sep for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_sep_p7", (getter)Outputs_get_energy_w_sys_ec_sep_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Sep for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_sep_p8", (getter)Outputs_get_energy_w_sys_ec_sep_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Sep for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_w_sys_ec_sep_p9", (getter)Outputs_get_energy_w_sys_ec_sep_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy with system (TOU) in Sep for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_apr_p1", (getter)Outputs_get_energy_wo_sys_ec_apr_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Apr for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_apr_p10", (getter)Outputs_get_energy_wo_sys_ec_apr_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Apr for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_apr_p11", (getter)Outputs_get_energy_wo_sys_ec_apr_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Apr for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_apr_p12", (getter)Outputs_get_energy_wo_sys_ec_apr_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Apr for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_apr_p2", (getter)Outputs_get_energy_wo_sys_ec_apr_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Apr for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_apr_p3", (getter)Outputs_get_energy_wo_sys_ec_apr_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Apr for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_apr_p4", (getter)Outputs_get_energy_wo_sys_ec_apr_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Apr for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_apr_p5", (getter)Outputs_get_energy_wo_sys_ec_apr_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Apr for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_apr_p6", (getter)Outputs_get_energy_wo_sys_ec_apr_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Apr for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_apr_p7", (getter)Outputs_get_energy_wo_sys_ec_apr_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Apr for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_apr_p8", (getter)Outputs_get_energy_wo_sys_ec_apr_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Apr for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_apr_p9", (getter)Outputs_get_energy_wo_sys_ec_apr_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Apr for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_aug_p1", (getter)Outputs_get_energy_wo_sys_ec_aug_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Aug for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_aug_p10", (getter)Outputs_get_energy_wo_sys_ec_aug_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Aug for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_aug_p11", (getter)Outputs_get_energy_wo_sys_ec_aug_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Aug for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_aug_p12", (getter)Outputs_get_energy_wo_sys_ec_aug_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Aug for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_aug_p2", (getter)Outputs_get_energy_wo_sys_ec_aug_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Aug for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_aug_p3", (getter)Outputs_get_energy_wo_sys_ec_aug_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Aug for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_aug_p4", (getter)Outputs_get_energy_wo_sys_ec_aug_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Aug for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_aug_p5", (getter)Outputs_get_energy_wo_sys_ec_aug_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Aug for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_aug_p6", (getter)Outputs_get_energy_wo_sys_ec_aug_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Aug for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_aug_p7", (getter)Outputs_get_energy_wo_sys_ec_aug_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Aug for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_aug_p8", (getter)Outputs_get_energy_wo_sys_ec_aug_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Aug for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_aug_p9", (getter)Outputs_get_energy_wo_sys_ec_aug_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Aug for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_dec_p1", (getter)Outputs_get_energy_wo_sys_ec_dec_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Dec for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_dec_p10", (getter)Outputs_get_energy_wo_sys_ec_dec_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Dec for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_dec_p11", (getter)Outputs_get_energy_wo_sys_ec_dec_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Dec for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_dec_p12", (getter)Outputs_get_energy_wo_sys_ec_dec_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Dec for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_dec_p2", (getter)Outputs_get_energy_wo_sys_ec_dec_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Dec for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_dec_p3", (getter)Outputs_get_energy_wo_sys_ec_dec_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Dec for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_dec_p4", (getter)Outputs_get_energy_wo_sys_ec_dec_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Dec for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_dec_p5", (getter)Outputs_get_energy_wo_sys_ec_dec_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Dec for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_dec_p6", (getter)Outputs_get_energy_wo_sys_ec_dec_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Dec for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_dec_p7", (getter)Outputs_get_energy_wo_sys_ec_dec_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Dec for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_dec_p8", (getter)Outputs_get_energy_wo_sys_ec_dec_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Dec for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_dec_p9", (getter)Outputs_get_energy_wo_sys_ec_dec_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Dec for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_feb_p1", (getter)Outputs_get_energy_wo_sys_ec_feb_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Feb for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_feb_p10", (getter)Outputs_get_energy_wo_sys_ec_feb_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Feb for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_feb_p11", (getter)Outputs_get_energy_wo_sys_ec_feb_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Feb for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_feb_p12", (getter)Outputs_get_energy_wo_sys_ec_feb_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Feb for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_feb_p2", (getter)Outputs_get_energy_wo_sys_ec_feb_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Feb for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_feb_p3", (getter)Outputs_get_energy_wo_sys_ec_feb_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Feb for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_feb_p4", (getter)Outputs_get_energy_wo_sys_ec_feb_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Feb for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_feb_p5", (getter)Outputs_get_energy_wo_sys_ec_feb_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Feb for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_feb_p6", (getter)Outputs_get_energy_wo_sys_ec_feb_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Feb for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_feb_p7", (getter)Outputs_get_energy_wo_sys_ec_feb_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Feb for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_feb_p8", (getter)Outputs_get_energy_wo_sys_ec_feb_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Feb for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_feb_p9", (getter)Outputs_get_energy_wo_sys_ec_feb_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Feb for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jan_p1", (getter)Outputs_get_energy_wo_sys_ec_jan_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jan for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jan_p10", (getter)Outputs_get_energy_wo_sys_ec_jan_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jan for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jan_p11", (getter)Outputs_get_energy_wo_sys_ec_jan_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jan for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jan_p12", (getter)Outputs_get_energy_wo_sys_ec_jan_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jan for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jan_p2", (getter)Outputs_get_energy_wo_sys_ec_jan_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jan for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jan_p3", (getter)Outputs_get_energy_wo_sys_ec_jan_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jan for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jan_p4", (getter)Outputs_get_energy_wo_sys_ec_jan_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jan for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jan_p5", (getter)Outputs_get_energy_wo_sys_ec_jan_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jan for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jan_p6", (getter)Outputs_get_energy_wo_sys_ec_jan_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jan for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jan_p7", (getter)Outputs_get_energy_wo_sys_ec_jan_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jan for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jan_p8", (getter)Outputs_get_energy_wo_sys_ec_jan_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jan for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jan_p9", (getter)Outputs_get_energy_wo_sys_ec_jan_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jan for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jul_p1", (getter)Outputs_get_energy_wo_sys_ec_jul_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jul for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jul_p10", (getter)Outputs_get_energy_wo_sys_ec_jul_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jul for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jul_p11", (getter)Outputs_get_energy_wo_sys_ec_jul_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jul for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jul_p12", (getter)Outputs_get_energy_wo_sys_ec_jul_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jul for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jul_p2", (getter)Outputs_get_energy_wo_sys_ec_jul_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jul for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jul_p3", (getter)Outputs_get_energy_wo_sys_ec_jul_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jul for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jul_p4", (getter)Outputs_get_energy_wo_sys_ec_jul_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jul for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jul_p5", (getter)Outputs_get_energy_wo_sys_ec_jul_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jul for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jul_p6", (getter)Outputs_get_energy_wo_sys_ec_jul_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jul for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jul_p7", (getter)Outputs_get_energy_wo_sys_ec_jul_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jul for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jul_p8", (getter)Outputs_get_energy_wo_sys_ec_jul_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jul for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jul_p9", (getter)Outputs_get_energy_wo_sys_ec_jul_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jul for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jun_p1", (getter)Outputs_get_energy_wo_sys_ec_jun_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jun for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jun_p10", (getter)Outputs_get_energy_wo_sys_ec_jun_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jun for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jun_p11", (getter)Outputs_get_energy_wo_sys_ec_jun_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jun for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jun_p12", (getter)Outputs_get_energy_wo_sys_ec_jun_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jun for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jun_p2", (getter)Outputs_get_energy_wo_sys_ec_jun_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jun for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jun_p3", (getter)Outputs_get_energy_wo_sys_ec_jun_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jun for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jun_p4", (getter)Outputs_get_energy_wo_sys_ec_jun_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jun for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jun_p5", (getter)Outputs_get_energy_wo_sys_ec_jun_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jun for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jun_p6", (getter)Outputs_get_energy_wo_sys_ec_jun_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jun for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jun_p7", (getter)Outputs_get_energy_wo_sys_ec_jun_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jun for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jun_p8", (getter)Outputs_get_energy_wo_sys_ec_jun_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jun for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jun_p9", (getter)Outputs_get_energy_wo_sys_ec_jun_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Jun for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_mar_p1", (getter)Outputs_get_energy_wo_sys_ec_mar_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Mar for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_mar_p10", (getter)Outputs_get_energy_wo_sys_ec_mar_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Mar for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_mar_p11", (getter)Outputs_get_energy_wo_sys_ec_mar_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Mar for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_mar_p12", (getter)Outputs_get_energy_wo_sys_ec_mar_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Mar for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_mar_p2", (getter)Outputs_get_energy_wo_sys_ec_mar_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Mar for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_mar_p3", (getter)Outputs_get_energy_wo_sys_ec_mar_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Mar for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_mar_p4", (getter)Outputs_get_energy_wo_sys_ec_mar_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Mar for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_mar_p5", (getter)Outputs_get_energy_wo_sys_ec_mar_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Mar for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_mar_p6", (getter)Outputs_get_energy_wo_sys_ec_mar_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Mar for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_mar_p7", (getter)Outputs_get_energy_wo_sys_ec_mar_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Mar for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_mar_p8", (getter)Outputs_get_energy_wo_sys_ec_mar_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Mar for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_mar_p9", (getter)Outputs_get_energy_wo_sys_ec_mar_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Mar for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_may_p1", (getter)Outputs_get_energy_wo_sys_ec_may_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in May for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_may_p10", (getter)Outputs_get_energy_wo_sys_ec_may_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in May for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_may_p11", (getter)Outputs_get_energy_wo_sys_ec_may_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in May for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_may_p12", (getter)Outputs_get_energy_wo_sys_ec_may_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in May for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_may_p2", (getter)Outputs_get_energy_wo_sys_ec_may_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in May for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_may_p3", (getter)Outputs_get_energy_wo_sys_ec_may_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in May for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_may_p4", (getter)Outputs_get_energy_wo_sys_ec_may_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in May for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_may_p5", (getter)Outputs_get_energy_wo_sys_ec_may_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in May for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_may_p6", (getter)Outputs_get_energy_wo_sys_ec_may_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in May for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_may_p7", (getter)Outputs_get_energy_wo_sys_ec_may_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in May for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_may_p8", (getter)Outputs_get_energy_wo_sys_ec_may_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in May for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_may_p9", (getter)Outputs_get_energy_wo_sys_ec_may_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in May for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_nov_p1", (getter)Outputs_get_energy_wo_sys_ec_nov_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Nov for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_nov_p10", (getter)Outputs_get_energy_wo_sys_ec_nov_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Nov for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_nov_p11", (getter)Outputs_get_energy_wo_sys_ec_nov_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Nov for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_nov_p12", (getter)Outputs_get_energy_wo_sys_ec_nov_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Nov for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_nov_p2", (getter)Outputs_get_energy_wo_sys_ec_nov_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Nov for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_nov_p3", (getter)Outputs_get_energy_wo_sys_ec_nov_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Nov for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_nov_p4", (getter)Outputs_get_energy_wo_sys_ec_nov_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Nov for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_nov_p5", (getter)Outputs_get_energy_wo_sys_ec_nov_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Nov for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_nov_p6", (getter)Outputs_get_energy_wo_sys_ec_nov_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Nov for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_nov_p7", (getter)Outputs_get_energy_wo_sys_ec_nov_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Nov for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_nov_p8", (getter)Outputs_get_energy_wo_sys_ec_nov_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Nov for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_nov_p9", (getter)Outputs_get_energy_wo_sys_ec_nov_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Nov for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_oct_p1", (getter)Outputs_get_energy_wo_sys_ec_oct_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Oct for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_oct_p10", (getter)Outputs_get_energy_wo_sys_ec_oct_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Oct for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_oct_p11", (getter)Outputs_get_energy_wo_sys_ec_oct_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Oct for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_oct_p12", (getter)Outputs_get_energy_wo_sys_ec_oct_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Oct for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_oct_p2", (getter)Outputs_get_energy_wo_sys_ec_oct_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Oct for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_oct_p3", (getter)Outputs_get_energy_wo_sys_ec_oct_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Oct for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_oct_p4", (getter)Outputs_get_energy_wo_sys_ec_oct_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Oct for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_oct_p5", (getter)Outputs_get_energy_wo_sys_ec_oct_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Oct for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_oct_p6", (getter)Outputs_get_energy_wo_sys_ec_oct_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Oct for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_oct_p7", (getter)Outputs_get_energy_wo_sys_ec_oct_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Oct for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_oct_p8", (getter)Outputs_get_energy_wo_sys_ec_oct_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Oct for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_oct_p9", (getter)Outputs_get_energy_wo_sys_ec_oct_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Oct for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_sep_p1", (getter)Outputs_get_energy_wo_sys_ec_sep_p1,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Sep for period 1 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_sep_p10", (getter)Outputs_get_energy_wo_sys_ec_sep_p10,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Sep for period 10 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_sep_p11", (getter)Outputs_get_energy_wo_sys_ec_sep_p11,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Sep for period 11 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_sep_p12", (getter)Outputs_get_energy_wo_sys_ec_sep_p12,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Sep for period 12 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_sep_p2", (getter)Outputs_get_energy_wo_sys_ec_sep_p2,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Sep for period 2 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_sep_p3", (getter)Outputs_get_energy_wo_sys_ec_sep_p3,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Sep for period 3 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_sep_p4", (getter)Outputs_get_energy_wo_sys_ec_sep_p4,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Sep for period 4 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_sep_p5", (getter)Outputs_get_energy_wo_sys_ec_sep_p5,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Sep for period 5 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_sep_p6", (getter)Outputs_get_energy_wo_sys_ec_sep_p6,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Sep for period 6 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_sep_p7", (getter)Outputs_get_energy_wo_sys_ec_sep_p7,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Sep for period 7 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_sep_p8", (getter)Outputs_get_energy_wo_sys_ec_sep_p8,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Sep for period 8 and tiers 1 through 6 [kWh]"),
 	NULL},
{"energy_wo_sys_ec_sep_p9", (getter)Outputs_get_energy_wo_sys_ec_sep_p9,(setter)0,
	PyDoc_STR("*sequence*: Energy without system (TOU) in Sep for period 9 and tiers 1 through 6 [kWh]"),
 	NULL},
{"lifetime_load", (getter)Outputs_get_lifetime_load,(setter)0,
	PyDoc_STR("*sequence*: Lifetime electricity load [kW]"),
 	NULL},
{"savings_year1", (getter)Outputs_get_savings_year1,(setter)0,
	PyDoc_STR("*float*: Electricity savings [$/yr]"),
 	NULL},
{"utility_bill_w_sys", (getter)Outputs_get_utility_bill_w_sys,(setter)0,
	PyDoc_STR("*sequence*: Utility bill with system [$]"),
 	NULL},
{"utility_bill_w_sys_apr", (getter)Outputs_get_utility_bill_w_sys_apr,(setter)0,
	PyDoc_STR("*sequence*: Utility bill with system in Apr [$]"),
 	NULL},
{"utility_bill_w_sys_aug", (getter)Outputs_get_utility_bill_w_sys_aug,(setter)0,
	PyDoc_STR("*sequence*: Utility bill with system in Aug [$]"),
 	NULL},
{"utility_bill_w_sys_dec", (getter)Outputs_get_utility_bill_w_sys_dec,(setter)0,
	PyDoc_STR("*sequence*: Utility bill with system in Dec [$]"),
 	NULL},
{"utility_bill_w_sys_feb", (getter)Outputs_get_utility_bill_w_sys_feb,(setter)0,
	PyDoc_STR("*sequence*: Utility bill with system in Feb [$]"),
 	NULL},
{"utility_bill_w_sys_jan", (getter)Outputs_get_utility_bill_w_sys_jan,(setter)0,
	PyDoc_STR("*sequence*: Utility bill with system in Jan [$]"),
 	NULL},
{"utility_bill_w_sys_jul", (getter)Outputs_get_utility_bill_w_sys_jul,(setter)0,
	PyDoc_STR("*sequence*: Utility bill with system in Jul [$]"),
 	NULL},
{"utility_bill_w_sys_jun", (getter)Outputs_get_utility_bill_w_sys_jun,(setter)0,
	PyDoc_STR("*sequence*: Utility bill with system in Jun [$]"),
 	NULL},
{"utility_bill_w_sys_mar", (getter)Outputs_get_utility_bill_w_sys_mar,(setter)0,
	PyDoc_STR("*sequence*: Utility bill with system in Mar [$]"),
 	NULL},
{"utility_bill_w_sys_may", (getter)Outputs_get_utility_bill_w_sys_may,(setter)0,
	PyDoc_STR("*sequence*: Utility bill with system in May [$]"),
 	NULL},
{"utility_bill_w_sys_nov", (getter)Outputs_get_utility_bill_w_sys_nov,(setter)0,
	PyDoc_STR("*sequence*: Utility bill with system in Nov [$]"),
 	NULL},
{"utility_bill_w_sys_oct", (getter)Outputs_get_utility_bill_w_sys_oct,(setter)0,
	PyDoc_STR("*sequence*: Utility bill with system in Oct [$]"),
 	NULL},
{"utility_bill_w_sys_sep", (getter)Outputs_get_utility_bill_w_sys_sep,(setter)0,
	PyDoc_STR("*sequence*: Utility bill with system in Sep [$]"),
 	NULL},
{"utility_bill_wo_sys", (getter)Outputs_get_utility_bill_wo_sys,(setter)0,
	PyDoc_STR("*sequence*: Utility bill without system [$]"),
 	NULL},
{"utility_bill_wo_sys_apr", (getter)Outputs_get_utility_bill_wo_sys_apr,(setter)0,
	PyDoc_STR("*sequence*: Utility bill without system in Apr [$]"),
 	NULL},
{"utility_bill_wo_sys_aug", (getter)Outputs_get_utility_bill_wo_sys_aug,(setter)0,
	PyDoc_STR("*sequence*: Utility bill without system in Aug [$]"),
 	NULL},
{"utility_bill_wo_sys_dec", (getter)Outputs_get_utility_bill_wo_sys_dec,(setter)0,
	PyDoc_STR("*sequence*: Utility bill without system in Dec [$]"),
 	NULL},
{"utility_bill_wo_sys_feb", (getter)Outputs_get_utility_bill_wo_sys_feb,(setter)0,
	PyDoc_STR("*sequence*: Utility bill without system in Feb [$]"),
 	NULL},
{"utility_bill_wo_sys_jan", (getter)Outputs_get_utility_bill_wo_sys_jan,(setter)0,
	PyDoc_STR("*sequence*: Utility bill without system in Jan [$]"),
 	NULL},
{"utility_bill_wo_sys_jul", (getter)Outputs_get_utility_bill_wo_sys_jul,(setter)0,
	PyDoc_STR("*sequence*: Utility bill without system in Jul [$]"),
 	NULL},
{"utility_bill_wo_sys_jun", (getter)Outputs_get_utility_bill_wo_sys_jun,(setter)0,
	PyDoc_STR("*sequence*: Utility bill without system in Jun [$]"),
 	NULL},
{"utility_bill_wo_sys_mar", (getter)Outputs_get_utility_bill_wo_sys_mar,(setter)0,
	PyDoc_STR("*sequence*: Utility bill without system in Mar [$]"),
 	NULL},
{"utility_bill_wo_sys_may", (getter)Outputs_get_utility_bill_wo_sys_may,(setter)0,
	PyDoc_STR("*sequence*: Utility bill without system in May [$]"),
 	NULL},
{"utility_bill_wo_sys_nov", (getter)Outputs_get_utility_bill_wo_sys_nov,(setter)0,
	PyDoc_STR("*sequence*: Utility bill without system in Nov [$]"),
 	NULL},
{"utility_bill_wo_sys_oct", (getter)Outputs_get_utility_bill_wo_sys_oct,(setter)0,
	PyDoc_STR("*sequence*: Utility bill without system in Oct [$]"),
 	NULL},
{"utility_bill_wo_sys_sep", (getter)Outputs_get_utility_bill_wo_sys_sep,(setter)0,
	PyDoc_STR("*sequence*: Utility bill without system in Sep [$]"),
 	NULL},
{"year1_electric_load", (getter)Outputs_get_year1_electric_load,(setter)0,
	PyDoc_STR("*float*: Electricity load [kWh/yr]"),
 	NULL},
{"year1_hourly_dc_peak_per_period", (getter)Outputs_get_year1_hourly_dc_peak_per_period,(setter)0,
	PyDoc_STR("*sequence*: Electricity from grid peak per TOU period [kW]"),
 	NULL},
{"year1_hourly_dc_tou_schedule", (getter)Outputs_get_year1_hourly_dc_tou_schedule,(setter)0,
	PyDoc_STR("*sequence*: Electricity TOU period for demand charges"),
 	NULL},
{"year1_hourly_dc_with_system", (getter)Outputs_get_year1_hourly_dc_with_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity demand charge with system [$]"),
 	NULL},
{"year1_hourly_dc_without_system", (getter)Outputs_get_year1_hourly_dc_without_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity demand charge without system [$]"),
 	NULL},
{"year1_hourly_e_tofromgrid", (getter)Outputs_get_year1_hourly_e_tofromgrid,(setter)0,
	PyDoc_STR("*sequence*: Electricity to/from grid [kWh]"),
 	NULL},
{"year1_hourly_ec_tou_schedule", (getter)Outputs_get_year1_hourly_ec_tou_schedule,(setter)0,
	PyDoc_STR("*sequence*: Electricity TOU period for energy charges"),
 	NULL},
{"year1_hourly_ec_with_system", (getter)Outputs_get_year1_hourly_ec_with_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity energy charge with system [$]"),
 	NULL},
{"year1_hourly_ec_without_system", (getter)Outputs_get_year1_hourly_ec_without_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity energy charge without system [$]"),
 	NULL},
{"year1_hourly_load", (getter)Outputs_get_year1_hourly_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity load (year 1) [kW]"),
 	NULL},
{"year1_hourly_p_system_to_load", (getter)Outputs_get_year1_hourly_p_system_to_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity peak load met by system [kW]"),
 	NULL},
{"year1_hourly_p_tofromgrid", (getter)Outputs_get_year1_hourly_p_tofromgrid,(setter)0,
	PyDoc_STR("*sequence*: Electricity to/from grid peak [kW]"),
 	NULL},
{"year1_hourly_salespurchases_with_system", (getter)Outputs_get_year1_hourly_salespurchases_with_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity sales/purchases with sytem [$]"),
 	NULL},
{"year1_hourly_salespurchases_without_system", (getter)Outputs_get_year1_hourly_salespurchases_without_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity sales/purchases without sytem [$]"),
 	NULL},
{"year1_monthly_cumulative_excess_dollars", (getter)Outputs_get_year1_monthly_cumulative_excess_dollars,(setter)0,
	PyDoc_STR("*sequence*: Dollar net metering credit [$/mo]"),
 	NULL},
{"year1_monthly_cumulative_excess_generation", (getter)Outputs_get_year1_monthly_cumulative_excess_generation,(setter)0,
	PyDoc_STR("*sequence*: Electricity net metering credit [kWh/mo]"),
 	NULL},
{"year1_monthly_dc_fixed_with_system", (getter)Outputs_get_year1_monthly_dc_fixed_with_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity demand charge (fixed) with system [$/mo]"),
 	NULL},
{"year1_monthly_dc_fixed_without_system", (getter)Outputs_get_year1_monthly_dc_fixed_without_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity demand charge (fixed) without system [$/mo]"),
 	NULL},
{"year1_monthly_dc_tou_with_system", (getter)Outputs_get_year1_monthly_dc_tou_with_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity demand charge (TOU) with system [$/mo]"),
 	NULL},
{"year1_monthly_dc_tou_without_system", (getter)Outputs_get_year1_monthly_dc_tou_without_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity demand charge (TOU) without system [$/mo]"),
 	NULL},
{"year1_monthly_ec_charge_flat_with_system", (getter)Outputs_get_year1_monthly_ec_charge_flat_with_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity energy charge (flat) with system [$/mo]"),
 	NULL},
{"year1_monthly_ec_charge_flat_without_system", (getter)Outputs_get_year1_monthly_ec_charge_flat_without_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity energy charge (flat) without system [$/mo]"),
 	NULL},
{"year1_monthly_ec_charge_with_system", (getter)Outputs_get_year1_monthly_ec_charge_with_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity energy charge (TOU) with system [$/mo]"),
 	NULL},
{"year1_monthly_ec_charge_without_system", (getter)Outputs_get_year1_monthly_ec_charge_without_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity energy charge (TOU) without system [$/mo]"),
 	NULL},
{"year1_monthly_electricity_to_grid", (getter)Outputs_get_year1_monthly_electricity_to_grid,(setter)0,
	PyDoc_STR("*sequence*: Electricity to/from grid [kWh/mo]"),
 	NULL},
{"year1_monthly_fixed_with_system", (getter)Outputs_get_year1_monthly_fixed_with_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity charge (fixed) with system [$/mo]"),
 	NULL},
{"year1_monthly_fixed_without_system", (getter)Outputs_get_year1_monthly_fixed_without_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity charge (fixed) without system [$/mo]"),
 	NULL},
{"year1_monthly_load", (getter)Outputs_get_year1_monthly_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity load [kWh/mo]"),
 	NULL},
{"year1_monthly_minimum_with_system", (getter)Outputs_get_year1_monthly_minimum_with_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity charge (minimum) with system [$/mo]"),
 	NULL},
{"year1_monthly_minimum_without_system", (getter)Outputs_get_year1_monthly_minimum_without_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity charge (minimum) without system [$/mo]"),
 	NULL},
{"year1_monthly_utility_bill_w_sys", (getter)Outputs_get_year1_monthly_utility_bill_w_sys,(setter)0,
	PyDoc_STR("*sequence*: Utility bill with system [$/mo]"),
 	NULL},
{"year1_monthly_utility_bill_wo_sys", (getter)Outputs_get_year1_monthly_utility_bill_wo_sys,(setter)0,
	PyDoc_STR("*sequence*: Utility bill without system [$/mo]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate3.Outputs",             /*tp_name*/
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
 * Utilityrate3
 */

static PyTypeObject Utilityrate3_Type;

static CmodObject *
newUtilityrate3Object(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Utilityrate3_Type);

	PySAM_TECH_ATTR()

	PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

	PyObject* TimeSeries_obj = TimeSeries_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TimeSeries", TimeSeries_obj);
	Py_DECREF(TimeSeries_obj);

	PyObject* Financials_obj = Financials_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Financials", Financials_obj);
	Py_DECREF(Financials_obj);

	PyObject* AnnualOutput_obj = AnnualOutput_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "AnnualOutput", AnnualOutput_obj);
	Py_DECREF(AnnualOutput_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Utilityrate3 methods */

static void
Utilityrate3_dealloc(CmodObject *self)
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
Utilityrate3_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Utilityrate3_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Utilityrate3_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Utilityrate3"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Utilityrate3_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Utilityrate3"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Utilityrate3_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Utilityrate3_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Utilityrate3_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Utilityrate3_methods[] = {
		{"execute",           (PyCFunction)Utilityrate3_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Utilityrate3_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Common': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Utilityrate3_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Common': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Utilityrate3_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Utilityrate3_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Utilityrate3_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Utilityrate3_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Utilityrate3_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Utilityrate3_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate3",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Utilityrate3_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Utilityrate3_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Utilityrate3_getattro, /*tp_getattro*/
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
		Utilityrate3_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Utilityrate3 object */

static PyObject *
Utilityrate3_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newUtilityrate3Object(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Utilityrate3_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newUtilityrate3Object((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Utilityrate3_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newUtilityrate3Object(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Utilityrate3", def) < 0) {
		Utilityrate3_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Utilityrate3_from_existing(PyObject *self, PyObject *args)
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

	rv = newUtilityrate3Object((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Utilityrate3", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Utilityrate3Module_methods[] = {
		{"new",             Utilityrate3_new,         METH_VARARGS,
				PyDoc_STR("new() -> Utilityrate3")},
		{"default",             Utilityrate3_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Utilityrate3\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Utilityrate3_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Utilityrate3\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Utilityrate3_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Utilityrate3\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Utilityrate3");


static int
Utilityrate3Module_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Utilityrate3_Type.tp_dict = PyDict_New();
	if (!Utilityrate3_Type.tp_dict) { goto fail; }

	/// Add the Common type object to Utilityrate3_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate3_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the TimeSeries type object to Utilityrate3_Type
	if (PyType_Ready(&TimeSeries_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate3_Type.tp_dict,
				"TimeSeries",
				(PyObject*)&TimeSeries_Type);
	Py_DECREF(&TimeSeries_Type);

	/// Add the Financials type object to Utilityrate3_Type
	if (PyType_Ready(&Financials_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate3_Type.tp_dict,
				"Financials",
				(PyObject*)&Financials_Type);
	Py_DECREF(&Financials_Type);

	/// Add the AnnualOutput type object to Utilityrate3_Type
	if (PyType_Ready(&AnnualOutput_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate3_Type.tp_dict,
				"AnnualOutput",
				(PyObject*)&AnnualOutput_Type);
	Py_DECREF(&AnnualOutput_Type);

	/// Add the Outputs type object to Utilityrate3_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate3_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Utilityrate3 type object to the module
	if (PyType_Ready(&Utilityrate3_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Utilityrate3",
				(PyObject*)&Utilityrate3_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Utilityrate3Module_slots[] = {
		{Py_mod_exec, Utilityrate3Module_exec},
		{0, NULL},
};

static struct PyModuleDef Utilityrate3Module = {
		PyModuleDef_HEAD_INIT,
		"Utilityrate3",
		module_doc,
		0,
		Utilityrate3Module_methods,
		Utilityrate3Module_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Utilityrate3(void)
{
	return PyModuleDef_Init(&Utilityrate3Module);
}