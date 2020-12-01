#include <Python.h>

#include <SAM_Utilityrate2.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Common Group
 */ 

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_Utilityrate2 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate2", "Common")){
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
	return PySAM_double_getter(SAM_Utilityrate2_Common_analysis_period_nget, self->data_ptr);
}

static int
Common_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_analysis_period_nset, self->data_ptr);
}

static PyObject *
Common_get_e_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Common_e_load_aget, self->data_ptr);
}

static int
Common_set_e_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate2_Common_e_load_aset, self->data_ptr);
}

static PyObject *
Common_get_hourly_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Common_hourly_gen_aget, self->data_ptr);
}

static int
Common_set_hourly_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate2_Common_hourly_gen_aset, self->data_ptr);
}

static PyObject *
Common_get_load_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Common_load_escalation_aget, self->data_ptr);
}

static int
Common_set_load_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate2_Common_load_escalation_aset, self->data_ptr);
}

static PyObject *
Common_get_p_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Common_p_load_aget, self->data_ptr);
}

static int
Common_set_p_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate2_Common_p_load_aset, self->data_ptr);
}

static PyObject *
Common_get_p_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Common_p_with_system_aget, self->data_ptr);
}

static int
Common_set_p_with_system(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate2_Common_p_with_system_aset, self->data_ptr);
}

static PyObject *
Common_get_rate_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Common_rate_escalation_aget, self->data_ptr);
}

static int
Common_set_rate_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate2_Common_rate_escalation_aset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_apr_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_apr_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_apr_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_apr_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_apr_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_apr_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_apr_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_apr_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_apr_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_apr_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_apr_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_apr_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_apr_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_apr_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_apr_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_apr_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_apr_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_apr_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_apr_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_apr_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_apr_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_apr_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_apr_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_apr_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_apr_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_apr_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_aug_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_aug_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_aug_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_aug_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_aug_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_aug_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_aug_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_aug_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_aug_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_aug_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_aug_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_aug_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_aug_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_aug_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_aug_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_aug_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_aug_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_aug_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_aug_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_aug_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_aug_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_aug_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_aug_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_aug_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_aug_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_aug_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_dec_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_dec_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_dec_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_dec_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_dec_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_dec_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_dec_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_dec_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_dec_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_dec_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_dec_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_dec_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_dec_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_dec_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_dec_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_dec_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_dec_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_dec_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_dec_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_dec_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_dec_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_dec_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_dec_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_dec_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_dec_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_dec_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_enable_nget, self->data_ptr);
}

static int
Common_set_ur_dc_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_enable_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_feb_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_feb_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_feb_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_feb_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_feb_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_feb_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_feb_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_feb_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_feb_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_feb_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_feb_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_feb_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_feb_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_feb_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_feb_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_feb_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_feb_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_feb_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_feb_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_feb_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_feb_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_feb_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_feb_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_feb_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_feb_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_feb_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jan_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jan_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jan_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jan_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jan_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jan_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jan_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jan_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jan_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jan_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jan_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jan_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jan_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jan_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jan_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jan_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jan_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jan_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jan_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jan_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jan_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jan_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jan_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jan_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jan_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jan_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jul_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jul_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jul_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jul_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jul_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jul_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jul_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jul_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jul_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jul_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jul_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jul_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jul_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jul_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jul_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jul_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jul_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jul_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jul_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jul_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jul_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jul_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jul_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jul_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jul_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jul_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jun_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jun_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jun_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jun_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jun_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jun_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jun_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jun_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jun_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jun_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jun_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jun_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jun_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jun_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jun_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jun_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jun_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jun_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jun_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jun_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jun_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jun_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_jun_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_jun_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_jun_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_jun_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_mar_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_mar_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_mar_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_mar_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_mar_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_mar_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_mar_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_mar_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_mar_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_mar_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_mar_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_mar_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_mar_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_mar_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_mar_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_mar_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_mar_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_mar_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_mar_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_mar_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_mar_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_mar_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_mar_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_mar_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_mar_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_mar_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_may_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_may_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_may_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_may_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_may_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_may_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_may_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_may_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_may_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_may_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_may_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_may_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_may_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_may_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_may_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_may_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_may_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_may_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_may_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_may_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_may_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_may_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_may_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_may_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_may_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_may_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_nov_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_nov_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_nov_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_nov_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_nov_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_nov_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_nov_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_nov_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_nov_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_nov_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_nov_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_nov_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_nov_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_nov_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_nov_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_nov_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_nov_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_nov_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_nov_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_nov_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_nov_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_nov_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_nov_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_nov_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_nov_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_nov_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_oct_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_oct_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_oct_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_oct_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_oct_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_oct_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_oct_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_oct_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_oct_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_oct_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_oct_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_oct_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_oct_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_oct_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_oct_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_oct_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_oct_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_oct_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_oct_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_oct_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_oct_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_oct_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_oct_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_oct_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_oct_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_oct_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p10_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p10_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p10_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p10_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p10_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p10_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p10_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p10_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p10_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p10_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p10_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p10_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p10_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p10_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p10_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p10_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p10_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p10_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p10_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p10_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p10_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p10_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p10_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p10_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p10_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p10_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p11_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p11_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p11_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p11_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p11_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p11_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p11_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p11_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p11_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p11_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p11_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p11_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p11_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p11_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p11_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p11_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p11_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p11_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p11_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p11_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p11_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p11_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p11_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p11_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p11_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p11_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p12_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p12_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p12_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p12_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p12_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p12_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p12_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p12_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p12_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p12_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p12_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p12_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p12_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p12_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p12_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p12_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p12_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p12_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p12_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p12_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p12_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p12_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p12_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p12_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p12_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p12_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p1_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p1_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p1_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p1_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p1_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p1_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p1_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p1_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p1_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p1_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p1_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p1_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p1_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p1_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p1_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p1_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p1_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p1_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p1_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p1_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p1_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p1_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p1_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p1_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p1_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p1_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p2_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p2_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p2_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p2_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p2_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p2_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p2_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p2_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p2_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p2_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p2_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p2_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p2_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p2_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p2_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p2_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p2_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p2_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p2_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p2_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p2_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p2_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p2_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p2_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p2_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p2_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p3_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p3_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p3_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p3_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p3_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p3_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p3_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p3_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p3_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p3_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p3_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p3_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p3_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p3_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p3_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p3_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p3_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p3_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p3_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p3_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p3_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p3_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p3_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p3_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p3_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p3_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p4_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p4_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p4_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p4_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p4_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p4_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p4_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p4_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p4_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p4_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p4_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p4_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p4_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p4_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p4_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p4_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p4_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p4_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p4_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p4_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p4_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p4_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p4_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p4_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p4_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p4_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p5_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p5_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p5_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p5_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p5_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p5_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p5_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p5_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p5_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p5_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p5_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p5_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p5_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p5_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p5_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p5_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p5_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p5_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p5_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p5_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p5_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p5_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p5_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p5_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p5_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p5_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p6_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p6_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p6_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p6_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p6_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p6_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p6_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p6_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p6_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p6_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p6_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p6_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p6_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p6_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p6_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p6_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p6_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p6_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p6_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p6_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p6_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p6_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p6_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p6_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p6_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p6_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p7_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p7_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p7_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p7_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p7_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p7_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p7_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p7_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p7_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p7_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p7_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p7_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p7_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p7_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p7_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p7_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p7_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p7_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p7_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p7_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p7_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p7_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p7_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p7_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p7_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p7_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p8_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p8_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p8_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p8_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p8_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p8_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p8_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p8_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p8_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p8_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p8_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p8_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p8_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p8_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p8_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p8_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p8_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p8_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p8_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p8_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p8_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p8_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p8_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p8_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p8_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p8_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p9_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p9_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p9_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p9_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p9_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p9_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p9_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p9_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p9_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p9_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p9_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p9_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p9_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p9_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p9_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p9_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p9_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p9_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p9_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p9_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p9_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p9_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_p9_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_p9_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_p9_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_p9_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate2_Common_ur_dc_sched_weekday_mget, self->data_ptr);
}

static int
Common_set_ur_dc_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate2_Common_ur_dc_sched_weekday_mset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate2_Common_ur_dc_sched_weekend_mget, self->data_ptr);
}

static int
Common_set_ur_dc_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate2_Common_ur_dc_sched_weekend_mset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t1_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_sep_t1_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t1_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_sep_t1_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_sep_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_sep_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t2_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_sep_t2_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t2_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_sep_t2_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_sep_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_sep_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t3_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_sep_t3_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t3_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_sep_t3_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_sep_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_sep_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t4_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_sep_t4_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t4_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_sep_t4_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_sep_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_sep_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t5_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_sep_t5_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t5_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_sep_t5_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_sep_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_sep_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t6_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_sep_t6_dc_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t6_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_sep_t6_dc_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sep_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_dc_sep_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_dc_sep_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_dc_sep_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_enable_nget, self->data_ptr);
}

static int
Common_set_ur_ec_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_enable_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p10_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p10_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p10_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p10_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p10_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p10_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p10_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p10_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p10_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p10_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p10_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p10_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p10_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p10_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p10_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p10_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p10_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p10_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p10_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p10_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p10_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p10_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p10_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p10_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p10_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p10_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p10_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p10_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p10_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p10_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p10_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p10_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p10_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p10_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p10_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p10_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p10_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p10_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p11_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p11_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p11_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p11_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p11_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p11_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p11_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p11_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p11_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p11_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p11_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p11_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p11_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p11_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p11_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p11_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p11_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p11_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p11_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p11_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p11_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p11_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p11_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p11_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p11_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p11_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p11_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p11_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p11_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p11_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p11_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p11_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p11_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p11_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p11_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p11_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p11_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p11_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p12_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p12_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p12_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p12_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p12_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p12_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p12_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p12_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p12_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p12_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p12_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p12_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p12_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p12_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p12_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p12_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p12_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p12_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p12_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p12_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p12_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p12_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p12_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p12_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p12_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p12_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p12_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p12_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p12_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p12_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p12_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p12_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p12_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p12_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p12_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p12_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p12_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p12_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p1_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p1_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p1_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p1_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p1_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p1_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p1_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p1_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p1_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p1_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p1_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p1_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p1_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p1_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p1_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p1_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p1_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p1_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p1_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p1_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p1_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p1_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p1_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p1_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p1_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p1_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p1_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p1_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p1_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p1_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p1_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p1_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p1_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p1_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p1_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p1_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p1_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p1_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p2_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p2_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p2_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p2_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p2_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p2_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p2_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p2_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p2_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p2_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p2_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p2_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p2_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p2_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p2_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p2_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p2_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p2_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p2_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p2_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p2_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p2_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p2_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p2_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p2_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p2_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p2_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p2_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p2_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p2_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p2_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p2_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p2_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p2_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p2_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p2_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p2_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p2_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p3_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p3_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p3_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p3_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p3_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p3_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p3_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p3_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p3_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p3_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p3_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p3_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p3_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p3_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p3_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p3_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p3_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p3_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p3_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p3_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p3_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p3_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p3_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p3_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p3_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p3_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p3_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p3_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p3_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p3_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p3_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p3_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p3_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p3_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p3_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p3_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p3_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p3_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p4_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p4_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p4_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p4_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p4_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p4_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p4_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p4_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p4_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p4_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p4_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p4_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p4_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p4_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p4_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p4_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p4_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p4_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p4_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p4_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p4_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p4_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p4_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p4_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p4_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p4_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p4_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p4_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p4_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p4_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p4_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p4_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p4_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p4_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p4_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p4_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p4_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p4_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p5_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p5_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p5_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p5_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p5_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p5_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p5_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p5_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p5_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p5_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p5_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p5_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p5_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p5_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p5_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p5_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p5_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p5_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p5_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p5_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p5_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p5_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p5_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p5_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p5_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p5_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p5_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p5_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p5_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p5_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p5_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p5_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p5_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p5_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p5_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p5_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p5_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p5_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p6_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p6_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p6_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p6_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p6_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p6_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p6_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p6_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p6_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p6_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p6_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p6_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p6_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p6_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p6_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p6_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p6_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p6_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p6_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p6_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p6_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p6_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p6_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p6_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p6_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p6_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p6_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p6_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p6_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p6_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p6_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p6_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p6_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p6_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p6_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p6_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p6_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p6_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p7_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p7_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p7_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p7_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p7_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p7_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p7_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p7_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p7_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p7_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p7_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p7_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p7_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p7_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p7_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p7_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p7_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p7_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p7_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p7_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p7_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p7_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p7_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p7_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p7_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p7_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p7_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p7_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p7_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p7_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p7_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p7_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p7_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p7_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p7_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p7_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p7_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p7_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p8_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p8_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p8_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p8_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p8_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p8_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p8_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p8_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p8_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p8_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p8_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p8_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p8_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p8_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p8_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p8_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p8_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p8_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p8_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p8_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p8_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p8_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p8_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p8_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p8_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p8_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p8_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p8_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p8_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p8_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p8_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p8_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p8_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p8_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p8_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p8_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p8_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p8_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t1_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p9_t1_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t1_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p9_t1_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t1_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p9_t1_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t1_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p9_t1_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t1_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p9_t1_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t1_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p9_t1_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t2_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p9_t2_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t2_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p9_t2_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t2_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p9_t2_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t2_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p9_t2_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t2_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p9_t2_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t2_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p9_t2_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t3_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p9_t3_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t3_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p9_t3_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t3_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p9_t3_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t3_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p9_t3_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t3_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p9_t3_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t3_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p9_t3_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t4_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p9_t4_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t4_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p9_t4_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t4_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p9_t4_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t4_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p9_t4_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t4_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p9_t4_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t4_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p9_t4_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t5_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p9_t5_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t5_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p9_t5_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t5_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p9_t5_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t5_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p9_t5_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t5_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p9_t5_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t5_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p9_t5_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t6_br(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p9_t6_br_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t6_br(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p9_t6_br_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t6_sr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p9_t6_sr_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t6_sr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p9_t6_sr_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_p9_t6_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_ec_p9_t6_ub_nget, self->data_ptr);
}

static int
Common_set_ur_ec_p9_t6_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_ec_p9_t6_ub_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate2_Common_ur_ec_sched_weekday_mget, self->data_ptr);
}

static int
Common_set_ur_ec_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate2_Common_ur_ec_sched_weekday_mset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate2_Common_ur_ec_sched_weekend_mget, self->data_ptr);
}

static int
Common_set_ur_ec_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate2_Common_ur_ec_sched_weekend_mset, self->data_ptr);
}

static PyObject *
Common_get_ur_enable_net_metering(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_enable_net_metering_nget, self->data_ptr);
}

static int
Common_set_ur_enable_net_metering(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_enable_net_metering_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_flat_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_flat_buy_rate_nget, self->data_ptr);
}

static int
Common_set_ur_flat_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_flat_buy_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_flat_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_flat_sell_rate_nget, self->data_ptr);
}

static int
Common_set_ur_flat_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_flat_sell_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_monthly_fixed_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_monthly_fixed_charge_nget, self->data_ptr);
}

static int
Common_set_ur_monthly_fixed_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_monthly_fixed_charge_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_nm_yearend_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate2_Common_ur_nm_yearend_sell_rate_nget, self->data_ptr);
}

static int
Common_set_ur_nm_yearend_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate2_Common_ur_nm_yearend_sell_rate_nset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"analysis_period", (getter)Common_get_analysis_period,(setter)Common_set_analysis_period,
	PyDoc_STR("*float*: Number of years in analysis [years]\n\n*Constraints*: INTEGER,POSITIVE\n\n*Required*: True"),
 	NULL},
{"e_load", (getter)Common_get_e_load,(setter)Common_set_e_load,
	PyDoc_STR("*sequence*: Energy at grid without system (load only) [kWh]\n\n*Constraints*: LENGTH=8760\n\n*Required*: False"),
 	NULL},
{"hourly_gen", (getter)Common_get_hourly_gen,(setter)Common_set_hourly_gen,
	PyDoc_STR("*sequence*: Energy at grid with system [kWh]\n\n*Constraints*: LENGTH=8760\n\n*Required*: True"),
 	NULL},
{"load_escalation", (getter)Common_get_load_escalation,(setter)Common_set_load_escalation,
	PyDoc_STR("*sequence*: Annual load escalation [%/year]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"p_load", (getter)Common_get_p_load,(setter)Common_set_p_load,
	PyDoc_STR("*sequence*: Max power at grid without system (load only) [kW]\n\n*Constraints*: LENGTH=8760\n\n*Required*: False"),
 	NULL},
{"p_with_system", (getter)Common_get_p_with_system,(setter)Common_set_p_with_system,
	PyDoc_STR("*sequence*: Max power at grid with system [kW]\n\n*Constraints*: LENGTH=8760\n\n*Required*: False"),
 	NULL},
{"rate_escalation", (getter)Common_get_rate_escalation,(setter)Common_set_rate_escalation,
	PyDoc_STR("*sequence*: Annual utility rate escalation [%/year]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ur_dc_apr_t1_dc", (getter)Common_get_ur_dc_apr_t1_dc,(setter)Common_set_ur_dc_apr_t1_dc,
	PyDoc_STR("*float*: April Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_apr_t1_ub", (getter)Common_get_ur_dc_apr_t1_ub,(setter)Common_set_ur_dc_apr_t1_ub,
	PyDoc_STR("*float*: April Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_apr_t2_dc", (getter)Common_get_ur_dc_apr_t2_dc,(setter)Common_set_ur_dc_apr_t2_dc,
	PyDoc_STR("*float*: April Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_apr_t2_ub", (getter)Common_get_ur_dc_apr_t2_ub,(setter)Common_set_ur_dc_apr_t2_ub,
	PyDoc_STR("*float*: April Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_apr_t3_dc", (getter)Common_get_ur_dc_apr_t3_dc,(setter)Common_set_ur_dc_apr_t3_dc,
	PyDoc_STR("*float*: April Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_apr_t3_ub", (getter)Common_get_ur_dc_apr_t3_ub,(setter)Common_set_ur_dc_apr_t3_ub,
	PyDoc_STR("*float*: April Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_apr_t4_dc", (getter)Common_get_ur_dc_apr_t4_dc,(setter)Common_set_ur_dc_apr_t4_dc,
	PyDoc_STR("*float*: April Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_apr_t4_ub", (getter)Common_get_ur_dc_apr_t4_ub,(setter)Common_set_ur_dc_apr_t4_ub,
	PyDoc_STR("*float*: April Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_apr_t5_dc", (getter)Common_get_ur_dc_apr_t5_dc,(setter)Common_set_ur_dc_apr_t5_dc,
	PyDoc_STR("*float*: April Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_apr_t5_ub", (getter)Common_get_ur_dc_apr_t5_ub,(setter)Common_set_ur_dc_apr_t5_ub,
	PyDoc_STR("*float*: April Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_apr_t6_dc", (getter)Common_get_ur_dc_apr_t6_dc,(setter)Common_set_ur_dc_apr_t6_dc,
	PyDoc_STR("*float*: April Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_apr_t6_ub", (getter)Common_get_ur_dc_apr_t6_ub,(setter)Common_set_ur_dc_apr_t6_ub,
	PyDoc_STR("*float*: April Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_aug_t1_dc", (getter)Common_get_ur_dc_aug_t1_dc,(setter)Common_set_ur_dc_aug_t1_dc,
	PyDoc_STR("*float*: August Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_aug_t1_ub", (getter)Common_get_ur_dc_aug_t1_ub,(setter)Common_set_ur_dc_aug_t1_ub,
	PyDoc_STR("*float*: August Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_aug_t2_dc", (getter)Common_get_ur_dc_aug_t2_dc,(setter)Common_set_ur_dc_aug_t2_dc,
	PyDoc_STR("*float*: August Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_aug_t2_ub", (getter)Common_get_ur_dc_aug_t2_ub,(setter)Common_set_ur_dc_aug_t2_ub,
	PyDoc_STR("*float*: August Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_aug_t3_dc", (getter)Common_get_ur_dc_aug_t3_dc,(setter)Common_set_ur_dc_aug_t3_dc,
	PyDoc_STR("*float*: August Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_aug_t3_ub", (getter)Common_get_ur_dc_aug_t3_ub,(setter)Common_set_ur_dc_aug_t3_ub,
	PyDoc_STR("*float*: August Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_aug_t4_dc", (getter)Common_get_ur_dc_aug_t4_dc,(setter)Common_set_ur_dc_aug_t4_dc,
	PyDoc_STR("*float*: August Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_aug_t4_ub", (getter)Common_get_ur_dc_aug_t4_ub,(setter)Common_set_ur_dc_aug_t4_ub,
	PyDoc_STR("*float*: August Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_aug_t5_dc", (getter)Common_get_ur_dc_aug_t5_dc,(setter)Common_set_ur_dc_aug_t5_dc,
	PyDoc_STR("*float*: August Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_aug_t5_ub", (getter)Common_get_ur_dc_aug_t5_ub,(setter)Common_set_ur_dc_aug_t5_ub,
	PyDoc_STR("*float*: August Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_aug_t6_dc", (getter)Common_get_ur_dc_aug_t6_dc,(setter)Common_set_ur_dc_aug_t6_dc,
	PyDoc_STR("*float*: August Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_aug_t6_ub", (getter)Common_get_ur_dc_aug_t6_ub,(setter)Common_set_ur_dc_aug_t6_ub,
	PyDoc_STR("*float*: August Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_dec_t1_dc", (getter)Common_get_ur_dc_dec_t1_dc,(setter)Common_set_ur_dc_dec_t1_dc,
	PyDoc_STR("*float*: December Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_dec_t1_ub", (getter)Common_get_ur_dc_dec_t1_ub,(setter)Common_set_ur_dc_dec_t1_ub,
	PyDoc_STR("*float*: December Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_dec_t2_dc", (getter)Common_get_ur_dc_dec_t2_dc,(setter)Common_set_ur_dc_dec_t2_dc,
	PyDoc_STR("*float*: December Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_dec_t2_ub", (getter)Common_get_ur_dc_dec_t2_ub,(setter)Common_set_ur_dc_dec_t2_ub,
	PyDoc_STR("*float*: December Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_dec_t3_dc", (getter)Common_get_ur_dc_dec_t3_dc,(setter)Common_set_ur_dc_dec_t3_dc,
	PyDoc_STR("*float*: December Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_dec_t3_ub", (getter)Common_get_ur_dc_dec_t3_ub,(setter)Common_set_ur_dc_dec_t3_ub,
	PyDoc_STR("*float*: December Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_dec_t4_dc", (getter)Common_get_ur_dc_dec_t4_dc,(setter)Common_set_ur_dc_dec_t4_dc,
	PyDoc_STR("*float*: December Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_dec_t4_ub", (getter)Common_get_ur_dc_dec_t4_ub,(setter)Common_set_ur_dc_dec_t4_ub,
	PyDoc_STR("*float*: December Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_dec_t5_dc", (getter)Common_get_ur_dc_dec_t5_dc,(setter)Common_set_ur_dc_dec_t5_dc,
	PyDoc_STR("*float*: December Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_dec_t5_ub", (getter)Common_get_ur_dc_dec_t5_ub,(setter)Common_set_ur_dc_dec_t5_ub,
	PyDoc_STR("*float*: December Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_dec_t6_dc", (getter)Common_get_ur_dc_dec_t6_dc,(setter)Common_set_ur_dc_dec_t6_dc,
	PyDoc_STR("*float*: December Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_dec_t6_ub", (getter)Common_get_ur_dc_dec_t6_ub,(setter)Common_set_ur_dc_dec_t6_ub,
	PyDoc_STR("*float*: December Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_enable", (getter)Common_get_ur_dc_enable,(setter)Common_set_ur_dc_enable,
	PyDoc_STR("*float*: Enable Demand Charge [0/1]\n\n*Constraints*: BOOLEAN\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ur_dc_feb_t1_dc", (getter)Common_get_ur_dc_feb_t1_dc,(setter)Common_set_ur_dc_feb_t1_dc,
	PyDoc_STR("*float*: February Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_feb_t1_ub", (getter)Common_get_ur_dc_feb_t1_ub,(setter)Common_set_ur_dc_feb_t1_ub,
	PyDoc_STR("*float*: February Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_feb_t2_dc", (getter)Common_get_ur_dc_feb_t2_dc,(setter)Common_set_ur_dc_feb_t2_dc,
	PyDoc_STR("*float*: February Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_feb_t2_ub", (getter)Common_get_ur_dc_feb_t2_ub,(setter)Common_set_ur_dc_feb_t2_ub,
	PyDoc_STR("*float*: February Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_feb_t3_dc", (getter)Common_get_ur_dc_feb_t3_dc,(setter)Common_set_ur_dc_feb_t3_dc,
	PyDoc_STR("*float*: February Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_feb_t3_ub", (getter)Common_get_ur_dc_feb_t3_ub,(setter)Common_set_ur_dc_feb_t3_ub,
	PyDoc_STR("*float*: February Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_feb_t4_dc", (getter)Common_get_ur_dc_feb_t4_dc,(setter)Common_set_ur_dc_feb_t4_dc,
	PyDoc_STR("*float*: February Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_feb_t4_ub", (getter)Common_get_ur_dc_feb_t4_ub,(setter)Common_set_ur_dc_feb_t4_ub,
	PyDoc_STR("*float*: February Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_feb_t5_dc", (getter)Common_get_ur_dc_feb_t5_dc,(setter)Common_set_ur_dc_feb_t5_dc,
	PyDoc_STR("*float*: February Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_feb_t5_ub", (getter)Common_get_ur_dc_feb_t5_ub,(setter)Common_set_ur_dc_feb_t5_ub,
	PyDoc_STR("*float*: February Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_feb_t6_dc", (getter)Common_get_ur_dc_feb_t6_dc,(setter)Common_set_ur_dc_feb_t6_dc,
	PyDoc_STR("*float*: February Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_feb_t6_ub", (getter)Common_get_ur_dc_feb_t6_ub,(setter)Common_set_ur_dc_feb_t6_ub,
	PyDoc_STR("*float*: February Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jan_t1_dc", (getter)Common_get_ur_dc_jan_t1_dc,(setter)Common_set_ur_dc_jan_t1_dc,
	PyDoc_STR("*float*: January Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jan_t1_ub", (getter)Common_get_ur_dc_jan_t1_ub,(setter)Common_set_ur_dc_jan_t1_ub,
	PyDoc_STR("*float*: January Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jan_t2_dc", (getter)Common_get_ur_dc_jan_t2_dc,(setter)Common_set_ur_dc_jan_t2_dc,
	PyDoc_STR("*float*: January Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jan_t2_ub", (getter)Common_get_ur_dc_jan_t2_ub,(setter)Common_set_ur_dc_jan_t2_ub,
	PyDoc_STR("*float*: January Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jan_t3_dc", (getter)Common_get_ur_dc_jan_t3_dc,(setter)Common_set_ur_dc_jan_t3_dc,
	PyDoc_STR("*float*: January Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jan_t3_ub", (getter)Common_get_ur_dc_jan_t3_ub,(setter)Common_set_ur_dc_jan_t3_ub,
	PyDoc_STR("*float*: January Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jan_t4_dc", (getter)Common_get_ur_dc_jan_t4_dc,(setter)Common_set_ur_dc_jan_t4_dc,
	PyDoc_STR("*float*: January Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jan_t4_ub", (getter)Common_get_ur_dc_jan_t4_ub,(setter)Common_set_ur_dc_jan_t4_ub,
	PyDoc_STR("*float*: January Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jan_t5_dc", (getter)Common_get_ur_dc_jan_t5_dc,(setter)Common_set_ur_dc_jan_t5_dc,
	PyDoc_STR("*float*: January Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jan_t5_ub", (getter)Common_get_ur_dc_jan_t5_ub,(setter)Common_set_ur_dc_jan_t5_ub,
	PyDoc_STR("*float*: January Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jan_t6_dc", (getter)Common_get_ur_dc_jan_t6_dc,(setter)Common_set_ur_dc_jan_t6_dc,
	PyDoc_STR("*float*: January Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jan_t6_ub", (getter)Common_get_ur_dc_jan_t6_ub,(setter)Common_set_ur_dc_jan_t6_ub,
	PyDoc_STR("*float*: January Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jul_t1_dc", (getter)Common_get_ur_dc_jul_t1_dc,(setter)Common_set_ur_dc_jul_t1_dc,
	PyDoc_STR("*float*: July Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jul_t1_ub", (getter)Common_get_ur_dc_jul_t1_ub,(setter)Common_set_ur_dc_jul_t1_ub,
	PyDoc_STR("*float*: July Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jul_t2_dc", (getter)Common_get_ur_dc_jul_t2_dc,(setter)Common_set_ur_dc_jul_t2_dc,
	PyDoc_STR("*float*: July Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jul_t2_ub", (getter)Common_get_ur_dc_jul_t2_ub,(setter)Common_set_ur_dc_jul_t2_ub,
	PyDoc_STR("*float*: July Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jul_t3_dc", (getter)Common_get_ur_dc_jul_t3_dc,(setter)Common_set_ur_dc_jul_t3_dc,
	PyDoc_STR("*float*: July Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jul_t3_ub", (getter)Common_get_ur_dc_jul_t3_ub,(setter)Common_set_ur_dc_jul_t3_ub,
	PyDoc_STR("*float*: July Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jul_t4_dc", (getter)Common_get_ur_dc_jul_t4_dc,(setter)Common_set_ur_dc_jul_t4_dc,
	PyDoc_STR("*float*: July Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jul_t4_ub", (getter)Common_get_ur_dc_jul_t4_ub,(setter)Common_set_ur_dc_jul_t4_ub,
	PyDoc_STR("*float*: July Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jul_t5_dc", (getter)Common_get_ur_dc_jul_t5_dc,(setter)Common_set_ur_dc_jul_t5_dc,
	PyDoc_STR("*float*: July Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jul_t5_ub", (getter)Common_get_ur_dc_jul_t5_ub,(setter)Common_set_ur_dc_jul_t5_ub,
	PyDoc_STR("*float*: July Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jul_t6_dc", (getter)Common_get_ur_dc_jul_t6_dc,(setter)Common_set_ur_dc_jul_t6_dc,
	PyDoc_STR("*float*: July Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jul_t6_ub", (getter)Common_get_ur_dc_jul_t6_ub,(setter)Common_set_ur_dc_jul_t6_ub,
	PyDoc_STR("*float*: July Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jun_t1_dc", (getter)Common_get_ur_dc_jun_t1_dc,(setter)Common_set_ur_dc_jun_t1_dc,
	PyDoc_STR("*float*: June Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jun_t1_ub", (getter)Common_get_ur_dc_jun_t1_ub,(setter)Common_set_ur_dc_jun_t1_ub,
	PyDoc_STR("*float*: June Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jun_t2_dc", (getter)Common_get_ur_dc_jun_t2_dc,(setter)Common_set_ur_dc_jun_t2_dc,
	PyDoc_STR("*float*: June Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jun_t2_ub", (getter)Common_get_ur_dc_jun_t2_ub,(setter)Common_set_ur_dc_jun_t2_ub,
	PyDoc_STR("*float*: June Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jun_t3_dc", (getter)Common_get_ur_dc_jun_t3_dc,(setter)Common_set_ur_dc_jun_t3_dc,
	PyDoc_STR("*float*: June Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jun_t3_ub", (getter)Common_get_ur_dc_jun_t3_ub,(setter)Common_set_ur_dc_jun_t3_ub,
	PyDoc_STR("*float*: June Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jun_t4_dc", (getter)Common_get_ur_dc_jun_t4_dc,(setter)Common_set_ur_dc_jun_t4_dc,
	PyDoc_STR("*float*: June Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jun_t4_ub", (getter)Common_get_ur_dc_jun_t4_ub,(setter)Common_set_ur_dc_jun_t4_ub,
	PyDoc_STR("*float*: June Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jun_t5_dc", (getter)Common_get_ur_dc_jun_t5_dc,(setter)Common_set_ur_dc_jun_t5_dc,
	PyDoc_STR("*float*: June Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jun_t5_ub", (getter)Common_get_ur_dc_jun_t5_ub,(setter)Common_set_ur_dc_jun_t5_ub,
	PyDoc_STR("*float*: June Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jun_t6_dc", (getter)Common_get_ur_dc_jun_t6_dc,(setter)Common_set_ur_dc_jun_t6_dc,
	PyDoc_STR("*float*: June Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_jun_t6_ub", (getter)Common_get_ur_dc_jun_t6_ub,(setter)Common_set_ur_dc_jun_t6_ub,
	PyDoc_STR("*float*: June Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_mar_t1_dc", (getter)Common_get_ur_dc_mar_t1_dc,(setter)Common_set_ur_dc_mar_t1_dc,
	PyDoc_STR("*float*: March Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_mar_t1_ub", (getter)Common_get_ur_dc_mar_t1_ub,(setter)Common_set_ur_dc_mar_t1_ub,
	PyDoc_STR("*float*: March Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_mar_t2_dc", (getter)Common_get_ur_dc_mar_t2_dc,(setter)Common_set_ur_dc_mar_t2_dc,
	PyDoc_STR("*float*: March Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_mar_t2_ub", (getter)Common_get_ur_dc_mar_t2_ub,(setter)Common_set_ur_dc_mar_t2_ub,
	PyDoc_STR("*float*: March Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_mar_t3_dc", (getter)Common_get_ur_dc_mar_t3_dc,(setter)Common_set_ur_dc_mar_t3_dc,
	PyDoc_STR("*float*: March Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_mar_t3_ub", (getter)Common_get_ur_dc_mar_t3_ub,(setter)Common_set_ur_dc_mar_t3_ub,
	PyDoc_STR("*float*: March Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_mar_t4_dc", (getter)Common_get_ur_dc_mar_t4_dc,(setter)Common_set_ur_dc_mar_t4_dc,
	PyDoc_STR("*float*: March Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_mar_t4_ub", (getter)Common_get_ur_dc_mar_t4_ub,(setter)Common_set_ur_dc_mar_t4_ub,
	PyDoc_STR("*float*: March Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_mar_t5_dc", (getter)Common_get_ur_dc_mar_t5_dc,(setter)Common_set_ur_dc_mar_t5_dc,
	PyDoc_STR("*float*: March Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_mar_t5_ub", (getter)Common_get_ur_dc_mar_t5_ub,(setter)Common_set_ur_dc_mar_t5_ub,
	PyDoc_STR("*float*: March Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_mar_t6_dc", (getter)Common_get_ur_dc_mar_t6_dc,(setter)Common_set_ur_dc_mar_t6_dc,
	PyDoc_STR("*float*: March Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_mar_t6_ub", (getter)Common_get_ur_dc_mar_t6_ub,(setter)Common_set_ur_dc_mar_t6_ub,
	PyDoc_STR("*float*: March Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_may_t1_dc", (getter)Common_get_ur_dc_may_t1_dc,(setter)Common_set_ur_dc_may_t1_dc,
	PyDoc_STR("*float*: May Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_may_t1_ub", (getter)Common_get_ur_dc_may_t1_ub,(setter)Common_set_ur_dc_may_t1_ub,
	PyDoc_STR("*float*: May Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_may_t2_dc", (getter)Common_get_ur_dc_may_t2_dc,(setter)Common_set_ur_dc_may_t2_dc,
	PyDoc_STR("*float*: May Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_may_t2_ub", (getter)Common_get_ur_dc_may_t2_ub,(setter)Common_set_ur_dc_may_t2_ub,
	PyDoc_STR("*float*: May Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_may_t3_dc", (getter)Common_get_ur_dc_may_t3_dc,(setter)Common_set_ur_dc_may_t3_dc,
	PyDoc_STR("*float*: May Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_may_t3_ub", (getter)Common_get_ur_dc_may_t3_ub,(setter)Common_set_ur_dc_may_t3_ub,
	PyDoc_STR("*float*: May Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_may_t4_dc", (getter)Common_get_ur_dc_may_t4_dc,(setter)Common_set_ur_dc_may_t4_dc,
	PyDoc_STR("*float*: May Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_may_t4_ub", (getter)Common_get_ur_dc_may_t4_ub,(setter)Common_set_ur_dc_may_t4_ub,
	PyDoc_STR("*float*: May Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_may_t5_dc", (getter)Common_get_ur_dc_may_t5_dc,(setter)Common_set_ur_dc_may_t5_dc,
	PyDoc_STR("*float*: May Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_may_t5_ub", (getter)Common_get_ur_dc_may_t5_ub,(setter)Common_set_ur_dc_may_t5_ub,
	PyDoc_STR("*float*: May Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_may_t6_dc", (getter)Common_get_ur_dc_may_t6_dc,(setter)Common_set_ur_dc_may_t6_dc,
	PyDoc_STR("*float*: May Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_may_t6_ub", (getter)Common_get_ur_dc_may_t6_ub,(setter)Common_set_ur_dc_may_t6_ub,
	PyDoc_STR("*float*: May Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_nov_t1_dc", (getter)Common_get_ur_dc_nov_t1_dc,(setter)Common_set_ur_dc_nov_t1_dc,
	PyDoc_STR("*float*: November Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_nov_t1_ub", (getter)Common_get_ur_dc_nov_t1_ub,(setter)Common_set_ur_dc_nov_t1_ub,
	PyDoc_STR("*float*: November Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_nov_t2_dc", (getter)Common_get_ur_dc_nov_t2_dc,(setter)Common_set_ur_dc_nov_t2_dc,
	PyDoc_STR("*float*: November Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_nov_t2_ub", (getter)Common_get_ur_dc_nov_t2_ub,(setter)Common_set_ur_dc_nov_t2_ub,
	PyDoc_STR("*float*: November Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_nov_t3_dc", (getter)Common_get_ur_dc_nov_t3_dc,(setter)Common_set_ur_dc_nov_t3_dc,
	PyDoc_STR("*float*: November Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_nov_t3_ub", (getter)Common_get_ur_dc_nov_t3_ub,(setter)Common_set_ur_dc_nov_t3_ub,
	PyDoc_STR("*float*: November Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_nov_t4_dc", (getter)Common_get_ur_dc_nov_t4_dc,(setter)Common_set_ur_dc_nov_t4_dc,
	PyDoc_STR("*float*: November Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_nov_t4_ub", (getter)Common_get_ur_dc_nov_t4_ub,(setter)Common_set_ur_dc_nov_t4_ub,
	PyDoc_STR("*float*: November Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_nov_t5_dc", (getter)Common_get_ur_dc_nov_t5_dc,(setter)Common_set_ur_dc_nov_t5_dc,
	PyDoc_STR("*float*: November Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_nov_t5_ub", (getter)Common_get_ur_dc_nov_t5_ub,(setter)Common_set_ur_dc_nov_t5_ub,
	PyDoc_STR("*float*: November Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_nov_t6_dc", (getter)Common_get_ur_dc_nov_t6_dc,(setter)Common_set_ur_dc_nov_t6_dc,
	PyDoc_STR("*float*: November Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_nov_t6_ub", (getter)Common_get_ur_dc_nov_t6_ub,(setter)Common_set_ur_dc_nov_t6_ub,
	PyDoc_STR("*float*: November Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_oct_t1_dc", (getter)Common_get_ur_dc_oct_t1_dc,(setter)Common_set_ur_dc_oct_t1_dc,
	PyDoc_STR("*float*: October Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_oct_t1_ub", (getter)Common_get_ur_dc_oct_t1_ub,(setter)Common_set_ur_dc_oct_t1_ub,
	PyDoc_STR("*float*: October Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_oct_t2_dc", (getter)Common_get_ur_dc_oct_t2_dc,(setter)Common_set_ur_dc_oct_t2_dc,
	PyDoc_STR("*float*: October Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_oct_t2_ub", (getter)Common_get_ur_dc_oct_t2_ub,(setter)Common_set_ur_dc_oct_t2_ub,
	PyDoc_STR("*float*: October Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_oct_t3_dc", (getter)Common_get_ur_dc_oct_t3_dc,(setter)Common_set_ur_dc_oct_t3_dc,
	PyDoc_STR("*float*: October Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_oct_t3_ub", (getter)Common_get_ur_dc_oct_t3_ub,(setter)Common_set_ur_dc_oct_t3_ub,
	PyDoc_STR("*float*: October Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_oct_t4_dc", (getter)Common_get_ur_dc_oct_t4_dc,(setter)Common_set_ur_dc_oct_t4_dc,
	PyDoc_STR("*float*: October Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_oct_t4_ub", (getter)Common_get_ur_dc_oct_t4_ub,(setter)Common_set_ur_dc_oct_t4_ub,
	PyDoc_STR("*float*: October Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_oct_t5_dc", (getter)Common_get_ur_dc_oct_t5_dc,(setter)Common_set_ur_dc_oct_t5_dc,
	PyDoc_STR("*float*: October Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_oct_t5_ub", (getter)Common_get_ur_dc_oct_t5_ub,(setter)Common_set_ur_dc_oct_t5_ub,
	PyDoc_STR("*float*: October Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_oct_t6_dc", (getter)Common_get_ur_dc_oct_t6_dc,(setter)Common_set_ur_dc_oct_t6_dc,
	PyDoc_STR("*float*: October Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_oct_t6_ub", (getter)Common_get_ur_dc_oct_t6_ub,(setter)Common_set_ur_dc_oct_t6_ub,
	PyDoc_STR("*float*: October Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p10_t1_dc", (getter)Common_get_ur_dc_p10_t1_dc,(setter)Common_set_ur_dc_p10_t1_dc,
	PyDoc_STR("*float*: Period 10 Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p10_t1_ub", (getter)Common_get_ur_dc_p10_t1_ub,(setter)Common_set_ur_dc_p10_t1_ub,
	PyDoc_STR("*float*: Period 10 Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p10_t2_dc", (getter)Common_get_ur_dc_p10_t2_dc,(setter)Common_set_ur_dc_p10_t2_dc,
	PyDoc_STR("*float*: Period 10 Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p10_t2_ub", (getter)Common_get_ur_dc_p10_t2_ub,(setter)Common_set_ur_dc_p10_t2_ub,
	PyDoc_STR("*float*: Period 10 Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p10_t3_dc", (getter)Common_get_ur_dc_p10_t3_dc,(setter)Common_set_ur_dc_p10_t3_dc,
	PyDoc_STR("*float*: Period 10 Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p10_t3_ub", (getter)Common_get_ur_dc_p10_t3_ub,(setter)Common_set_ur_dc_p10_t3_ub,
	PyDoc_STR("*float*: Period 10 Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p10_t4_dc", (getter)Common_get_ur_dc_p10_t4_dc,(setter)Common_set_ur_dc_p10_t4_dc,
	PyDoc_STR("*float*: Period 10 Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p10_t4_ub", (getter)Common_get_ur_dc_p10_t4_ub,(setter)Common_set_ur_dc_p10_t4_ub,
	PyDoc_STR("*float*: Period 10 Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p10_t5_dc", (getter)Common_get_ur_dc_p10_t5_dc,(setter)Common_set_ur_dc_p10_t5_dc,
	PyDoc_STR("*float*: Period 10 Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p10_t5_ub", (getter)Common_get_ur_dc_p10_t5_ub,(setter)Common_set_ur_dc_p10_t5_ub,
	PyDoc_STR("*float*: Period 10 Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p10_t6_dc", (getter)Common_get_ur_dc_p10_t6_dc,(setter)Common_set_ur_dc_p10_t6_dc,
	PyDoc_STR("*float*: Period 10 Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p10_t6_ub", (getter)Common_get_ur_dc_p10_t6_ub,(setter)Common_set_ur_dc_p10_t6_ub,
	PyDoc_STR("*float*: Period 10 Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p11_t1_dc", (getter)Common_get_ur_dc_p11_t1_dc,(setter)Common_set_ur_dc_p11_t1_dc,
	PyDoc_STR("*float*: Period 11 Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p11_t1_ub", (getter)Common_get_ur_dc_p11_t1_ub,(setter)Common_set_ur_dc_p11_t1_ub,
	PyDoc_STR("*float*: Period 11 Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p11_t2_dc", (getter)Common_get_ur_dc_p11_t2_dc,(setter)Common_set_ur_dc_p11_t2_dc,
	PyDoc_STR("*float*: Period 11 Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p11_t2_ub", (getter)Common_get_ur_dc_p11_t2_ub,(setter)Common_set_ur_dc_p11_t2_ub,
	PyDoc_STR("*float*: Period 11 Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p11_t3_dc", (getter)Common_get_ur_dc_p11_t3_dc,(setter)Common_set_ur_dc_p11_t3_dc,
	PyDoc_STR("*float*: Period 11 Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p11_t3_ub", (getter)Common_get_ur_dc_p11_t3_ub,(setter)Common_set_ur_dc_p11_t3_ub,
	PyDoc_STR("*float*: Period 11 Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p11_t4_dc", (getter)Common_get_ur_dc_p11_t4_dc,(setter)Common_set_ur_dc_p11_t4_dc,
	PyDoc_STR("*float*: Period 11 Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p11_t4_ub", (getter)Common_get_ur_dc_p11_t4_ub,(setter)Common_set_ur_dc_p11_t4_ub,
	PyDoc_STR("*float*: Period 11 Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p11_t5_dc", (getter)Common_get_ur_dc_p11_t5_dc,(setter)Common_set_ur_dc_p11_t5_dc,
	PyDoc_STR("*float*: Period 11 Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p11_t5_ub", (getter)Common_get_ur_dc_p11_t5_ub,(setter)Common_set_ur_dc_p11_t5_ub,
	PyDoc_STR("*float*: Period 11 Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p11_t6_dc", (getter)Common_get_ur_dc_p11_t6_dc,(setter)Common_set_ur_dc_p11_t6_dc,
	PyDoc_STR("*float*: Period 11 Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p11_t6_ub", (getter)Common_get_ur_dc_p11_t6_ub,(setter)Common_set_ur_dc_p11_t6_ub,
	PyDoc_STR("*float*: Period 11 Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p12_t1_dc", (getter)Common_get_ur_dc_p12_t1_dc,(setter)Common_set_ur_dc_p12_t1_dc,
	PyDoc_STR("*float*: Period 12 Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p12_t1_ub", (getter)Common_get_ur_dc_p12_t1_ub,(setter)Common_set_ur_dc_p12_t1_ub,
	PyDoc_STR("*float*: Period 12 Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p12_t2_dc", (getter)Common_get_ur_dc_p12_t2_dc,(setter)Common_set_ur_dc_p12_t2_dc,
	PyDoc_STR("*float*: Period 12 Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p12_t2_ub", (getter)Common_get_ur_dc_p12_t2_ub,(setter)Common_set_ur_dc_p12_t2_ub,
	PyDoc_STR("*float*: Period 12 Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p12_t3_dc", (getter)Common_get_ur_dc_p12_t3_dc,(setter)Common_set_ur_dc_p12_t3_dc,
	PyDoc_STR("*float*: Period 12 Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p12_t3_ub", (getter)Common_get_ur_dc_p12_t3_ub,(setter)Common_set_ur_dc_p12_t3_ub,
	PyDoc_STR("*float*: Period 12 Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p12_t4_dc", (getter)Common_get_ur_dc_p12_t4_dc,(setter)Common_set_ur_dc_p12_t4_dc,
	PyDoc_STR("*float*: Period 12 Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p12_t4_ub", (getter)Common_get_ur_dc_p12_t4_ub,(setter)Common_set_ur_dc_p12_t4_ub,
	PyDoc_STR("*float*: Period 12 Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p12_t5_dc", (getter)Common_get_ur_dc_p12_t5_dc,(setter)Common_set_ur_dc_p12_t5_dc,
	PyDoc_STR("*float*: Period 12 Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p12_t5_ub", (getter)Common_get_ur_dc_p12_t5_ub,(setter)Common_set_ur_dc_p12_t5_ub,
	PyDoc_STR("*float*: Period 12 Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p12_t6_dc", (getter)Common_get_ur_dc_p12_t6_dc,(setter)Common_set_ur_dc_p12_t6_dc,
	PyDoc_STR("*float*: Period 12 Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p12_t6_ub", (getter)Common_get_ur_dc_p12_t6_ub,(setter)Common_set_ur_dc_p12_t6_ub,
	PyDoc_STR("*float*: Period 12 Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p1_t1_dc", (getter)Common_get_ur_dc_p1_t1_dc,(setter)Common_set_ur_dc_p1_t1_dc,
	PyDoc_STR("*float*: Period 1 Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p1_t1_ub", (getter)Common_get_ur_dc_p1_t1_ub,(setter)Common_set_ur_dc_p1_t1_ub,
	PyDoc_STR("*float*: Period 1 Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p1_t2_dc", (getter)Common_get_ur_dc_p1_t2_dc,(setter)Common_set_ur_dc_p1_t2_dc,
	PyDoc_STR("*float*: Period 1 Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p1_t2_ub", (getter)Common_get_ur_dc_p1_t2_ub,(setter)Common_set_ur_dc_p1_t2_ub,
	PyDoc_STR("*float*: Period 1 Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p1_t3_dc", (getter)Common_get_ur_dc_p1_t3_dc,(setter)Common_set_ur_dc_p1_t3_dc,
	PyDoc_STR("*float*: Period 1 Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p1_t3_ub", (getter)Common_get_ur_dc_p1_t3_ub,(setter)Common_set_ur_dc_p1_t3_ub,
	PyDoc_STR("*float*: Period 1 Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p1_t4_dc", (getter)Common_get_ur_dc_p1_t4_dc,(setter)Common_set_ur_dc_p1_t4_dc,
	PyDoc_STR("*float*: Period 1 Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p1_t4_ub", (getter)Common_get_ur_dc_p1_t4_ub,(setter)Common_set_ur_dc_p1_t4_ub,
	PyDoc_STR("*float*: Period 1 Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p1_t5_dc", (getter)Common_get_ur_dc_p1_t5_dc,(setter)Common_set_ur_dc_p1_t5_dc,
	PyDoc_STR("*float*: Period 1 Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p1_t5_ub", (getter)Common_get_ur_dc_p1_t5_ub,(setter)Common_set_ur_dc_p1_t5_ub,
	PyDoc_STR("*float*: Period 1 Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p1_t6_dc", (getter)Common_get_ur_dc_p1_t6_dc,(setter)Common_set_ur_dc_p1_t6_dc,
	PyDoc_STR("*float*: Period 1 Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p1_t6_ub", (getter)Common_get_ur_dc_p1_t6_ub,(setter)Common_set_ur_dc_p1_t6_ub,
	PyDoc_STR("*float*: Period 1 Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p2_t1_dc", (getter)Common_get_ur_dc_p2_t1_dc,(setter)Common_set_ur_dc_p2_t1_dc,
	PyDoc_STR("*float*: Period 2 Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p2_t1_ub", (getter)Common_get_ur_dc_p2_t1_ub,(setter)Common_set_ur_dc_p2_t1_ub,
	PyDoc_STR("*float*: Period 2 Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p2_t2_dc", (getter)Common_get_ur_dc_p2_t2_dc,(setter)Common_set_ur_dc_p2_t2_dc,
	PyDoc_STR("*float*: Period 2 Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p2_t2_ub", (getter)Common_get_ur_dc_p2_t2_ub,(setter)Common_set_ur_dc_p2_t2_ub,
	PyDoc_STR("*float*: Period 2 Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p2_t3_dc", (getter)Common_get_ur_dc_p2_t3_dc,(setter)Common_set_ur_dc_p2_t3_dc,
	PyDoc_STR("*float*: Period 2 Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p2_t3_ub", (getter)Common_get_ur_dc_p2_t3_ub,(setter)Common_set_ur_dc_p2_t3_ub,
	PyDoc_STR("*float*: Period 2 Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p2_t4_dc", (getter)Common_get_ur_dc_p2_t4_dc,(setter)Common_set_ur_dc_p2_t4_dc,
	PyDoc_STR("*float*: Period 2 Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p2_t4_ub", (getter)Common_get_ur_dc_p2_t4_ub,(setter)Common_set_ur_dc_p2_t4_ub,
	PyDoc_STR("*float*: Period 2 Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p2_t5_dc", (getter)Common_get_ur_dc_p2_t5_dc,(setter)Common_set_ur_dc_p2_t5_dc,
	PyDoc_STR("*float*: Period 2 Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p2_t5_ub", (getter)Common_get_ur_dc_p2_t5_ub,(setter)Common_set_ur_dc_p2_t5_ub,
	PyDoc_STR("*float*: Period 2 Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p2_t6_dc", (getter)Common_get_ur_dc_p2_t6_dc,(setter)Common_set_ur_dc_p2_t6_dc,
	PyDoc_STR("*float*: Period 2 Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p2_t6_ub", (getter)Common_get_ur_dc_p2_t6_ub,(setter)Common_set_ur_dc_p2_t6_ub,
	PyDoc_STR("*float*: Period 2 Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p3_t1_dc", (getter)Common_get_ur_dc_p3_t1_dc,(setter)Common_set_ur_dc_p3_t1_dc,
	PyDoc_STR("*float*: Period 3 Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p3_t1_ub", (getter)Common_get_ur_dc_p3_t1_ub,(setter)Common_set_ur_dc_p3_t1_ub,
	PyDoc_STR("*float*: Period 3 Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p3_t2_dc", (getter)Common_get_ur_dc_p3_t2_dc,(setter)Common_set_ur_dc_p3_t2_dc,
	PyDoc_STR("*float*: Period 3 Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p3_t2_ub", (getter)Common_get_ur_dc_p3_t2_ub,(setter)Common_set_ur_dc_p3_t2_ub,
	PyDoc_STR("*float*: Period 3 Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p3_t3_dc", (getter)Common_get_ur_dc_p3_t3_dc,(setter)Common_set_ur_dc_p3_t3_dc,
	PyDoc_STR("*float*: Period 3 Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p3_t3_ub", (getter)Common_get_ur_dc_p3_t3_ub,(setter)Common_set_ur_dc_p3_t3_ub,
	PyDoc_STR("*float*: Period 3 Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p3_t4_dc", (getter)Common_get_ur_dc_p3_t4_dc,(setter)Common_set_ur_dc_p3_t4_dc,
	PyDoc_STR("*float*: Period 3 Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p3_t4_ub", (getter)Common_get_ur_dc_p3_t4_ub,(setter)Common_set_ur_dc_p3_t4_ub,
	PyDoc_STR("*float*: Period 3 Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p3_t5_dc", (getter)Common_get_ur_dc_p3_t5_dc,(setter)Common_set_ur_dc_p3_t5_dc,
	PyDoc_STR("*float*: Period 3 Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p3_t5_ub", (getter)Common_get_ur_dc_p3_t5_ub,(setter)Common_set_ur_dc_p3_t5_ub,
	PyDoc_STR("*float*: Period 3 Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p3_t6_dc", (getter)Common_get_ur_dc_p3_t6_dc,(setter)Common_set_ur_dc_p3_t6_dc,
	PyDoc_STR("*float*: Period 3 Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p3_t6_ub", (getter)Common_get_ur_dc_p3_t6_ub,(setter)Common_set_ur_dc_p3_t6_ub,
	PyDoc_STR("*float*: Period 3 Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p4_t1_dc", (getter)Common_get_ur_dc_p4_t1_dc,(setter)Common_set_ur_dc_p4_t1_dc,
	PyDoc_STR("*float*: Period 4 Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p4_t1_ub", (getter)Common_get_ur_dc_p4_t1_ub,(setter)Common_set_ur_dc_p4_t1_ub,
	PyDoc_STR("*float*: Period 4 Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p4_t2_dc", (getter)Common_get_ur_dc_p4_t2_dc,(setter)Common_set_ur_dc_p4_t2_dc,
	PyDoc_STR("*float*: Period 4 Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p4_t2_ub", (getter)Common_get_ur_dc_p4_t2_ub,(setter)Common_set_ur_dc_p4_t2_ub,
	PyDoc_STR("*float*: Period 4 Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p4_t3_dc", (getter)Common_get_ur_dc_p4_t3_dc,(setter)Common_set_ur_dc_p4_t3_dc,
	PyDoc_STR("*float*: Period 4 Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p4_t3_ub", (getter)Common_get_ur_dc_p4_t3_ub,(setter)Common_set_ur_dc_p4_t3_ub,
	PyDoc_STR("*float*: Period 4 Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p4_t4_dc", (getter)Common_get_ur_dc_p4_t4_dc,(setter)Common_set_ur_dc_p4_t4_dc,
	PyDoc_STR("*float*: Period 4 Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p4_t4_ub", (getter)Common_get_ur_dc_p4_t4_ub,(setter)Common_set_ur_dc_p4_t4_ub,
	PyDoc_STR("*float*: Period 4 Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p4_t5_dc", (getter)Common_get_ur_dc_p4_t5_dc,(setter)Common_set_ur_dc_p4_t5_dc,
	PyDoc_STR("*float*: Period 4 Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p4_t5_ub", (getter)Common_get_ur_dc_p4_t5_ub,(setter)Common_set_ur_dc_p4_t5_ub,
	PyDoc_STR("*float*: Period 4 Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p4_t6_dc", (getter)Common_get_ur_dc_p4_t6_dc,(setter)Common_set_ur_dc_p4_t6_dc,
	PyDoc_STR("*float*: Period 4 Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p4_t6_ub", (getter)Common_get_ur_dc_p4_t6_ub,(setter)Common_set_ur_dc_p4_t6_ub,
	PyDoc_STR("*float*: Period 4 Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p5_t1_dc", (getter)Common_get_ur_dc_p5_t1_dc,(setter)Common_set_ur_dc_p5_t1_dc,
	PyDoc_STR("*float*: Period 5 Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p5_t1_ub", (getter)Common_get_ur_dc_p5_t1_ub,(setter)Common_set_ur_dc_p5_t1_ub,
	PyDoc_STR("*float*: Period 5 Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p5_t2_dc", (getter)Common_get_ur_dc_p5_t2_dc,(setter)Common_set_ur_dc_p5_t2_dc,
	PyDoc_STR("*float*: Period 5 Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p5_t2_ub", (getter)Common_get_ur_dc_p5_t2_ub,(setter)Common_set_ur_dc_p5_t2_ub,
	PyDoc_STR("*float*: Period 5 Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p5_t3_dc", (getter)Common_get_ur_dc_p5_t3_dc,(setter)Common_set_ur_dc_p5_t3_dc,
	PyDoc_STR("*float*: Period 5 Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p5_t3_ub", (getter)Common_get_ur_dc_p5_t3_ub,(setter)Common_set_ur_dc_p5_t3_ub,
	PyDoc_STR("*float*: Period 5 Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p5_t4_dc", (getter)Common_get_ur_dc_p5_t4_dc,(setter)Common_set_ur_dc_p5_t4_dc,
	PyDoc_STR("*float*: Period 5 Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p5_t4_ub", (getter)Common_get_ur_dc_p5_t4_ub,(setter)Common_set_ur_dc_p5_t4_ub,
	PyDoc_STR("*float*: Period 5 Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p5_t5_dc", (getter)Common_get_ur_dc_p5_t5_dc,(setter)Common_set_ur_dc_p5_t5_dc,
	PyDoc_STR("*float*: Period 5 Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p5_t5_ub", (getter)Common_get_ur_dc_p5_t5_ub,(setter)Common_set_ur_dc_p5_t5_ub,
	PyDoc_STR("*float*: Period 5 Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p5_t6_dc", (getter)Common_get_ur_dc_p5_t6_dc,(setter)Common_set_ur_dc_p5_t6_dc,
	PyDoc_STR("*float*: Period 5 Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p5_t6_ub", (getter)Common_get_ur_dc_p5_t6_ub,(setter)Common_set_ur_dc_p5_t6_ub,
	PyDoc_STR("*float*: Period 5 Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p6_t1_dc", (getter)Common_get_ur_dc_p6_t1_dc,(setter)Common_set_ur_dc_p6_t1_dc,
	PyDoc_STR("*float*: Period 6 Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p6_t1_ub", (getter)Common_get_ur_dc_p6_t1_ub,(setter)Common_set_ur_dc_p6_t1_ub,
	PyDoc_STR("*float*: Period 6 Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p6_t2_dc", (getter)Common_get_ur_dc_p6_t2_dc,(setter)Common_set_ur_dc_p6_t2_dc,
	PyDoc_STR("*float*: Period 6 Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p6_t2_ub", (getter)Common_get_ur_dc_p6_t2_ub,(setter)Common_set_ur_dc_p6_t2_ub,
	PyDoc_STR("*float*: Period 6 Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p6_t3_dc", (getter)Common_get_ur_dc_p6_t3_dc,(setter)Common_set_ur_dc_p6_t3_dc,
	PyDoc_STR("*float*: Period 6 Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p6_t3_ub", (getter)Common_get_ur_dc_p6_t3_ub,(setter)Common_set_ur_dc_p6_t3_ub,
	PyDoc_STR("*float*: Period 6 Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p6_t4_dc", (getter)Common_get_ur_dc_p6_t4_dc,(setter)Common_set_ur_dc_p6_t4_dc,
	PyDoc_STR("*float*: Period 6 Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p6_t4_ub", (getter)Common_get_ur_dc_p6_t4_ub,(setter)Common_set_ur_dc_p6_t4_ub,
	PyDoc_STR("*float*: Period 6 Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p6_t5_dc", (getter)Common_get_ur_dc_p6_t5_dc,(setter)Common_set_ur_dc_p6_t5_dc,
	PyDoc_STR("*float*: Period 6 Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p6_t5_ub", (getter)Common_get_ur_dc_p6_t5_ub,(setter)Common_set_ur_dc_p6_t5_ub,
	PyDoc_STR("*float*: Period 6 Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p6_t6_dc", (getter)Common_get_ur_dc_p6_t6_dc,(setter)Common_set_ur_dc_p6_t6_dc,
	PyDoc_STR("*float*: Period 6 Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p6_t6_ub", (getter)Common_get_ur_dc_p6_t6_ub,(setter)Common_set_ur_dc_p6_t6_ub,
	PyDoc_STR("*float*: Period 6 Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p7_t1_dc", (getter)Common_get_ur_dc_p7_t1_dc,(setter)Common_set_ur_dc_p7_t1_dc,
	PyDoc_STR("*float*: Period 7 Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p7_t1_ub", (getter)Common_get_ur_dc_p7_t1_ub,(setter)Common_set_ur_dc_p7_t1_ub,
	PyDoc_STR("*float*: Period 7 Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p7_t2_dc", (getter)Common_get_ur_dc_p7_t2_dc,(setter)Common_set_ur_dc_p7_t2_dc,
	PyDoc_STR("*float*: Period 7 Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p7_t2_ub", (getter)Common_get_ur_dc_p7_t2_ub,(setter)Common_set_ur_dc_p7_t2_ub,
	PyDoc_STR("*float*: Period 7 Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p7_t3_dc", (getter)Common_get_ur_dc_p7_t3_dc,(setter)Common_set_ur_dc_p7_t3_dc,
	PyDoc_STR("*float*: Period 7 Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p7_t3_ub", (getter)Common_get_ur_dc_p7_t3_ub,(setter)Common_set_ur_dc_p7_t3_ub,
	PyDoc_STR("*float*: Period 7 Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p7_t4_dc", (getter)Common_get_ur_dc_p7_t4_dc,(setter)Common_set_ur_dc_p7_t4_dc,
	PyDoc_STR("*float*: Period 7 Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p7_t4_ub", (getter)Common_get_ur_dc_p7_t4_ub,(setter)Common_set_ur_dc_p7_t4_ub,
	PyDoc_STR("*float*: Period 7 Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p7_t5_dc", (getter)Common_get_ur_dc_p7_t5_dc,(setter)Common_set_ur_dc_p7_t5_dc,
	PyDoc_STR("*float*: Period 7 Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p7_t5_ub", (getter)Common_get_ur_dc_p7_t5_ub,(setter)Common_set_ur_dc_p7_t5_ub,
	PyDoc_STR("*float*: Period 7 Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p7_t6_dc", (getter)Common_get_ur_dc_p7_t6_dc,(setter)Common_set_ur_dc_p7_t6_dc,
	PyDoc_STR("*float*: Period 7 Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p7_t6_ub", (getter)Common_get_ur_dc_p7_t6_ub,(setter)Common_set_ur_dc_p7_t6_ub,
	PyDoc_STR("*float*: Period 7 Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p8_t1_dc", (getter)Common_get_ur_dc_p8_t1_dc,(setter)Common_set_ur_dc_p8_t1_dc,
	PyDoc_STR("*float*: Period 8 Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p8_t1_ub", (getter)Common_get_ur_dc_p8_t1_ub,(setter)Common_set_ur_dc_p8_t1_ub,
	PyDoc_STR("*float*: Period 8 Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p8_t2_dc", (getter)Common_get_ur_dc_p8_t2_dc,(setter)Common_set_ur_dc_p8_t2_dc,
	PyDoc_STR("*float*: Period 8 Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p8_t2_ub", (getter)Common_get_ur_dc_p8_t2_ub,(setter)Common_set_ur_dc_p8_t2_ub,
	PyDoc_STR("*float*: Period 8 Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p8_t3_dc", (getter)Common_get_ur_dc_p8_t3_dc,(setter)Common_set_ur_dc_p8_t3_dc,
	PyDoc_STR("*float*: Period 8 Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p8_t3_ub", (getter)Common_get_ur_dc_p8_t3_ub,(setter)Common_set_ur_dc_p8_t3_ub,
	PyDoc_STR("*float*: Period 8 Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p8_t4_dc", (getter)Common_get_ur_dc_p8_t4_dc,(setter)Common_set_ur_dc_p8_t4_dc,
	PyDoc_STR("*float*: Period 8 Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p8_t4_ub", (getter)Common_get_ur_dc_p8_t4_ub,(setter)Common_set_ur_dc_p8_t4_ub,
	PyDoc_STR("*float*: Period 8 Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p8_t5_dc", (getter)Common_get_ur_dc_p8_t5_dc,(setter)Common_set_ur_dc_p8_t5_dc,
	PyDoc_STR("*float*: Period 8 Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p8_t5_ub", (getter)Common_get_ur_dc_p8_t5_ub,(setter)Common_set_ur_dc_p8_t5_ub,
	PyDoc_STR("*float*: Period 8 Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p8_t6_dc", (getter)Common_get_ur_dc_p8_t6_dc,(setter)Common_set_ur_dc_p8_t6_dc,
	PyDoc_STR("*float*: Period 8 Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p8_t6_ub", (getter)Common_get_ur_dc_p8_t6_ub,(setter)Common_set_ur_dc_p8_t6_ub,
	PyDoc_STR("*float*: Period 8 Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p9_t1_dc", (getter)Common_get_ur_dc_p9_t1_dc,(setter)Common_set_ur_dc_p9_t1_dc,
	PyDoc_STR("*float*: Period 9 Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p9_t1_ub", (getter)Common_get_ur_dc_p9_t1_ub,(setter)Common_set_ur_dc_p9_t1_ub,
	PyDoc_STR("*float*: Period 9 Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p9_t2_dc", (getter)Common_get_ur_dc_p9_t2_dc,(setter)Common_set_ur_dc_p9_t2_dc,
	PyDoc_STR("*float*: Period 9 Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p9_t2_ub", (getter)Common_get_ur_dc_p9_t2_ub,(setter)Common_set_ur_dc_p9_t2_ub,
	PyDoc_STR("*float*: Period 9 Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p9_t3_dc", (getter)Common_get_ur_dc_p9_t3_dc,(setter)Common_set_ur_dc_p9_t3_dc,
	PyDoc_STR("*float*: Period 9 Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p9_t3_ub", (getter)Common_get_ur_dc_p9_t3_ub,(setter)Common_set_ur_dc_p9_t3_ub,
	PyDoc_STR("*float*: Period 9 Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p9_t4_dc", (getter)Common_get_ur_dc_p9_t4_dc,(setter)Common_set_ur_dc_p9_t4_dc,
	PyDoc_STR("*float*: Period 9 Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p9_t4_ub", (getter)Common_get_ur_dc_p9_t4_ub,(setter)Common_set_ur_dc_p9_t4_ub,
	PyDoc_STR("*float*: Period 9 Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p9_t5_dc", (getter)Common_get_ur_dc_p9_t5_dc,(setter)Common_set_ur_dc_p9_t5_dc,
	PyDoc_STR("*float*: Period 9 Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p9_t5_ub", (getter)Common_get_ur_dc_p9_t5_ub,(setter)Common_set_ur_dc_p9_t5_ub,
	PyDoc_STR("*float*: Period 9 Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p9_t6_dc", (getter)Common_get_ur_dc_p9_t6_dc,(setter)Common_set_ur_dc_p9_t6_dc,
	PyDoc_STR("*float*: Period 9 Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_p9_t6_ub", (getter)Common_get_ur_dc_p9_t6_ub,(setter)Common_set_ur_dc_p9_t6_ub,
	PyDoc_STR("*float*: Period 9 Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_sched_weekday", (getter)Common_get_ur_dc_sched_weekday,(setter)Common_set_ur_dc_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: Demend Charge Weekday Schedule\n\n*Info*: 12x24\n\n*Required*: True if ur_dc_enable=1"),
 	NULL},
{"ur_dc_sched_weekend", (getter)Common_get_ur_dc_sched_weekend,(setter)Common_set_ur_dc_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Demend Charge Weekend Schedule\n\n*Info*: 12x24\n\n*Required*: True if ur_dc_enable=1"),
 	NULL},
{"ur_dc_sep_t1_dc", (getter)Common_get_ur_dc_sep_t1_dc,(setter)Common_set_ur_dc_sep_t1_dc,
	PyDoc_STR("*float*: September Tier 1 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_sep_t1_ub", (getter)Common_get_ur_dc_sep_t1_ub,(setter)Common_set_ur_dc_sep_t1_ub,
	PyDoc_STR("*float*: September Tier 1 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_sep_t2_dc", (getter)Common_get_ur_dc_sep_t2_dc,(setter)Common_set_ur_dc_sep_t2_dc,
	PyDoc_STR("*float*: September Tier 2 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_sep_t2_ub", (getter)Common_get_ur_dc_sep_t2_ub,(setter)Common_set_ur_dc_sep_t2_ub,
	PyDoc_STR("*float*: September Tier 2 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_sep_t3_dc", (getter)Common_get_ur_dc_sep_t3_dc,(setter)Common_set_ur_dc_sep_t3_dc,
	PyDoc_STR("*float*: September Tier 3 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_sep_t3_ub", (getter)Common_get_ur_dc_sep_t3_ub,(setter)Common_set_ur_dc_sep_t3_ub,
	PyDoc_STR("*float*: September Tier 3 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_sep_t4_dc", (getter)Common_get_ur_dc_sep_t4_dc,(setter)Common_set_ur_dc_sep_t4_dc,
	PyDoc_STR("*float*: September Tier 4 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_sep_t4_ub", (getter)Common_get_ur_dc_sep_t4_ub,(setter)Common_set_ur_dc_sep_t4_ub,
	PyDoc_STR("*float*: September Tier 4 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_sep_t5_dc", (getter)Common_get_ur_dc_sep_t5_dc,(setter)Common_set_ur_dc_sep_t5_dc,
	PyDoc_STR("*float*: September Tier 5 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_sep_t5_ub", (getter)Common_get_ur_dc_sep_t5_ub,(setter)Common_set_ur_dc_sep_t5_ub,
	PyDoc_STR("*float*: September Tier 5 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_sep_t6_dc", (getter)Common_get_ur_dc_sep_t6_dc,(setter)Common_set_ur_dc_sep_t6_dc,
	PyDoc_STR("*float*: September Tier 6 Demand Charge [$/kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_dc_sep_t6_ub", (getter)Common_get_ur_dc_sep_t6_ub,(setter)Common_set_ur_dc_sep_t6_ub,
	PyDoc_STR("*float*: September Tier 6 Peak Demand [kW]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_enable", (getter)Common_get_ur_ec_enable,(setter)Common_set_ur_ec_enable,
	PyDoc_STR("*float*: Enable energy charge [0/1]\n\n*Constraints*: BOOLEAN\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ur_ec_p10_t1_br", (getter)Common_get_ur_ec_p10_t1_br,(setter)Common_set_ur_ec_p10_t1_br,
	PyDoc_STR("*float*: Period 10 Tier 1 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p10_t1_sr", (getter)Common_get_ur_ec_p10_t1_sr,(setter)Common_set_ur_ec_p10_t1_sr,
	PyDoc_STR("*float*: Period 10 Tier 1 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p10_t1_ub", (getter)Common_get_ur_ec_p10_t1_ub,(setter)Common_set_ur_ec_p10_t1_ub,
	PyDoc_STR("*float*: Period 10 Tier 1 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p10_t2_br", (getter)Common_get_ur_ec_p10_t2_br,(setter)Common_set_ur_ec_p10_t2_br,
	PyDoc_STR("*float*: Period 10 Tier 2 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p10_t2_sr", (getter)Common_get_ur_ec_p10_t2_sr,(setter)Common_set_ur_ec_p10_t2_sr,
	PyDoc_STR("*float*: Period 10 Tier 2 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p10_t2_ub", (getter)Common_get_ur_ec_p10_t2_ub,(setter)Common_set_ur_ec_p10_t2_ub,
	PyDoc_STR("*float*: Period 10 Tier 2 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p10_t3_br", (getter)Common_get_ur_ec_p10_t3_br,(setter)Common_set_ur_ec_p10_t3_br,
	PyDoc_STR("*float*: Period 10 Tier 3 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p10_t3_sr", (getter)Common_get_ur_ec_p10_t3_sr,(setter)Common_set_ur_ec_p10_t3_sr,
	PyDoc_STR("*float*: Period 10 Tier 3 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p10_t3_ub", (getter)Common_get_ur_ec_p10_t3_ub,(setter)Common_set_ur_ec_p10_t3_ub,
	PyDoc_STR("*float*: Period 10 Tier 3 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p10_t4_br", (getter)Common_get_ur_ec_p10_t4_br,(setter)Common_set_ur_ec_p10_t4_br,
	PyDoc_STR("*float*: Period 10 Tier 4 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p10_t4_sr", (getter)Common_get_ur_ec_p10_t4_sr,(setter)Common_set_ur_ec_p10_t4_sr,
	PyDoc_STR("*float*: Period 10 Tier 4 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p10_t4_ub", (getter)Common_get_ur_ec_p10_t4_ub,(setter)Common_set_ur_ec_p10_t4_ub,
	PyDoc_STR("*float*: Period 10 Tier 4 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p10_t5_br", (getter)Common_get_ur_ec_p10_t5_br,(setter)Common_set_ur_ec_p10_t5_br,
	PyDoc_STR("*float*: Period 10 Tier 5 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p10_t5_sr", (getter)Common_get_ur_ec_p10_t5_sr,(setter)Common_set_ur_ec_p10_t5_sr,
	PyDoc_STR("*float*: Period 10 Tier 5 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p10_t5_ub", (getter)Common_get_ur_ec_p10_t5_ub,(setter)Common_set_ur_ec_p10_t5_ub,
	PyDoc_STR("*float*: Period 10 Tier 5 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p10_t6_br", (getter)Common_get_ur_ec_p10_t6_br,(setter)Common_set_ur_ec_p10_t6_br,
	PyDoc_STR("*float*: Period 10 Tier 6 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p10_t6_sr", (getter)Common_get_ur_ec_p10_t6_sr,(setter)Common_set_ur_ec_p10_t6_sr,
	PyDoc_STR("*float*: Period 10 Tier 6 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p10_t6_ub", (getter)Common_get_ur_ec_p10_t6_ub,(setter)Common_set_ur_ec_p10_t6_ub,
	PyDoc_STR("*float*: Period 10 Tier 6 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p11_t1_br", (getter)Common_get_ur_ec_p11_t1_br,(setter)Common_set_ur_ec_p11_t1_br,
	PyDoc_STR("*float*: Period 11 Tier 1 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p11_t1_sr", (getter)Common_get_ur_ec_p11_t1_sr,(setter)Common_set_ur_ec_p11_t1_sr,
	PyDoc_STR("*float*: Period 11 Tier 1 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p11_t1_ub", (getter)Common_get_ur_ec_p11_t1_ub,(setter)Common_set_ur_ec_p11_t1_ub,
	PyDoc_STR("*float*: Period 11 Tier 1 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p11_t2_br", (getter)Common_get_ur_ec_p11_t2_br,(setter)Common_set_ur_ec_p11_t2_br,
	PyDoc_STR("*float*: Period 11 Tier 2 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p11_t2_sr", (getter)Common_get_ur_ec_p11_t2_sr,(setter)Common_set_ur_ec_p11_t2_sr,
	PyDoc_STR("*float*: Period 11 Tier 2 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p11_t2_ub", (getter)Common_get_ur_ec_p11_t2_ub,(setter)Common_set_ur_ec_p11_t2_ub,
	PyDoc_STR("*float*: Period 11 Tier 2 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p11_t3_br", (getter)Common_get_ur_ec_p11_t3_br,(setter)Common_set_ur_ec_p11_t3_br,
	PyDoc_STR("*float*: Period 11 Tier 3 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p11_t3_sr", (getter)Common_get_ur_ec_p11_t3_sr,(setter)Common_set_ur_ec_p11_t3_sr,
	PyDoc_STR("*float*: Period 11 Tier 3 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p11_t3_ub", (getter)Common_get_ur_ec_p11_t3_ub,(setter)Common_set_ur_ec_p11_t3_ub,
	PyDoc_STR("*float*: Period 11 Tier 3 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p11_t4_br", (getter)Common_get_ur_ec_p11_t4_br,(setter)Common_set_ur_ec_p11_t4_br,
	PyDoc_STR("*float*: Period 11 Tier 4 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p11_t4_sr", (getter)Common_get_ur_ec_p11_t4_sr,(setter)Common_set_ur_ec_p11_t4_sr,
	PyDoc_STR("*float*: Period 11 Tier 4 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p11_t4_ub", (getter)Common_get_ur_ec_p11_t4_ub,(setter)Common_set_ur_ec_p11_t4_ub,
	PyDoc_STR("*float*: Period 11 Tier 4 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p11_t5_br", (getter)Common_get_ur_ec_p11_t5_br,(setter)Common_set_ur_ec_p11_t5_br,
	PyDoc_STR("*float*: Period 11 Tier 5 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p11_t5_sr", (getter)Common_get_ur_ec_p11_t5_sr,(setter)Common_set_ur_ec_p11_t5_sr,
	PyDoc_STR("*float*: Period 11 Tier 5 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p11_t5_ub", (getter)Common_get_ur_ec_p11_t5_ub,(setter)Common_set_ur_ec_p11_t5_ub,
	PyDoc_STR("*float*: Period 11 Tier 5 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p11_t6_br", (getter)Common_get_ur_ec_p11_t6_br,(setter)Common_set_ur_ec_p11_t6_br,
	PyDoc_STR("*float*: Period 11 Tier 6 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p11_t6_sr", (getter)Common_get_ur_ec_p11_t6_sr,(setter)Common_set_ur_ec_p11_t6_sr,
	PyDoc_STR("*float*: Period 11 Tier 6 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p11_t6_ub", (getter)Common_get_ur_ec_p11_t6_ub,(setter)Common_set_ur_ec_p11_t6_ub,
	PyDoc_STR("*float*: Period 11 Tier 6 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p12_t1_br", (getter)Common_get_ur_ec_p12_t1_br,(setter)Common_set_ur_ec_p12_t1_br,
	PyDoc_STR("*float*: Period 12 Tier 1 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p12_t1_sr", (getter)Common_get_ur_ec_p12_t1_sr,(setter)Common_set_ur_ec_p12_t1_sr,
	PyDoc_STR("*float*: Period 12 Tier 1 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p12_t1_ub", (getter)Common_get_ur_ec_p12_t1_ub,(setter)Common_set_ur_ec_p12_t1_ub,
	PyDoc_STR("*float*: Period 12 Tier 1 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p12_t2_br", (getter)Common_get_ur_ec_p12_t2_br,(setter)Common_set_ur_ec_p12_t2_br,
	PyDoc_STR("*float*: Period 12 Tier 2 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p12_t2_sr", (getter)Common_get_ur_ec_p12_t2_sr,(setter)Common_set_ur_ec_p12_t2_sr,
	PyDoc_STR("*float*: Period 12 Tier 2 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p12_t2_ub", (getter)Common_get_ur_ec_p12_t2_ub,(setter)Common_set_ur_ec_p12_t2_ub,
	PyDoc_STR("*float*: Period 12 Tier 2 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p12_t3_br", (getter)Common_get_ur_ec_p12_t3_br,(setter)Common_set_ur_ec_p12_t3_br,
	PyDoc_STR("*float*: Period 12 Tier 3 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p12_t3_sr", (getter)Common_get_ur_ec_p12_t3_sr,(setter)Common_set_ur_ec_p12_t3_sr,
	PyDoc_STR("*float*: Period 12 Tier 3 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p12_t3_ub", (getter)Common_get_ur_ec_p12_t3_ub,(setter)Common_set_ur_ec_p12_t3_ub,
	PyDoc_STR("*float*: Period 12 Tier 3 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p12_t4_br", (getter)Common_get_ur_ec_p12_t4_br,(setter)Common_set_ur_ec_p12_t4_br,
	PyDoc_STR("*float*: Period 12 Tier 4 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p12_t4_sr", (getter)Common_get_ur_ec_p12_t4_sr,(setter)Common_set_ur_ec_p12_t4_sr,
	PyDoc_STR("*float*: Period 12 Tier 4 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p12_t4_ub", (getter)Common_get_ur_ec_p12_t4_ub,(setter)Common_set_ur_ec_p12_t4_ub,
	PyDoc_STR("*float*: Period 12 Tier 4 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p12_t5_br", (getter)Common_get_ur_ec_p12_t5_br,(setter)Common_set_ur_ec_p12_t5_br,
	PyDoc_STR("*float*: Period 12 Tier 5 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p12_t5_sr", (getter)Common_get_ur_ec_p12_t5_sr,(setter)Common_set_ur_ec_p12_t5_sr,
	PyDoc_STR("*float*: Period 12 Tier 5 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p12_t5_ub", (getter)Common_get_ur_ec_p12_t5_ub,(setter)Common_set_ur_ec_p12_t5_ub,
	PyDoc_STR("*float*: Period 12 Tier 5 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p12_t6_br", (getter)Common_get_ur_ec_p12_t6_br,(setter)Common_set_ur_ec_p12_t6_br,
	PyDoc_STR("*float*: Period 12 Tier 6 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p12_t6_sr", (getter)Common_get_ur_ec_p12_t6_sr,(setter)Common_set_ur_ec_p12_t6_sr,
	PyDoc_STR("*float*: Period 12 Tier 6 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p12_t6_ub", (getter)Common_get_ur_ec_p12_t6_ub,(setter)Common_set_ur_ec_p12_t6_ub,
	PyDoc_STR("*float*: Period 12 Tier 6 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p1_t1_br", (getter)Common_get_ur_ec_p1_t1_br,(setter)Common_set_ur_ec_p1_t1_br,
	PyDoc_STR("*float*: Period 1 Tier 1 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p1_t1_sr", (getter)Common_get_ur_ec_p1_t1_sr,(setter)Common_set_ur_ec_p1_t1_sr,
	PyDoc_STR("*float*: Period 1 Tier 1 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p1_t1_ub", (getter)Common_get_ur_ec_p1_t1_ub,(setter)Common_set_ur_ec_p1_t1_ub,
	PyDoc_STR("*float*: Period 1 Tier 1 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p1_t2_br", (getter)Common_get_ur_ec_p1_t2_br,(setter)Common_set_ur_ec_p1_t2_br,
	PyDoc_STR("*float*: Period 1 Tier 2 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p1_t2_sr", (getter)Common_get_ur_ec_p1_t2_sr,(setter)Common_set_ur_ec_p1_t2_sr,
	PyDoc_STR("*float*: Period 1 Tier 2 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p1_t2_ub", (getter)Common_get_ur_ec_p1_t2_ub,(setter)Common_set_ur_ec_p1_t2_ub,
	PyDoc_STR("*float*: Period 1 Tier 2 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p1_t3_br", (getter)Common_get_ur_ec_p1_t3_br,(setter)Common_set_ur_ec_p1_t3_br,
	PyDoc_STR("*float*: Period 1 Tier 3 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p1_t3_sr", (getter)Common_get_ur_ec_p1_t3_sr,(setter)Common_set_ur_ec_p1_t3_sr,
	PyDoc_STR("*float*: Period 1 Tier 3 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p1_t3_ub", (getter)Common_get_ur_ec_p1_t3_ub,(setter)Common_set_ur_ec_p1_t3_ub,
	PyDoc_STR("*float*: Period 1 Tier 3 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p1_t4_br", (getter)Common_get_ur_ec_p1_t4_br,(setter)Common_set_ur_ec_p1_t4_br,
	PyDoc_STR("*float*: Period 1 Tier 4 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p1_t4_sr", (getter)Common_get_ur_ec_p1_t4_sr,(setter)Common_set_ur_ec_p1_t4_sr,
	PyDoc_STR("*float*: Period 1 Tier 4 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p1_t4_ub", (getter)Common_get_ur_ec_p1_t4_ub,(setter)Common_set_ur_ec_p1_t4_ub,
	PyDoc_STR("*float*: Period 1 Tier 4 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p1_t5_br", (getter)Common_get_ur_ec_p1_t5_br,(setter)Common_set_ur_ec_p1_t5_br,
	PyDoc_STR("*float*: Period 1 Tier 5 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p1_t5_sr", (getter)Common_get_ur_ec_p1_t5_sr,(setter)Common_set_ur_ec_p1_t5_sr,
	PyDoc_STR("*float*: Period 1 Tier 5 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p1_t5_ub", (getter)Common_get_ur_ec_p1_t5_ub,(setter)Common_set_ur_ec_p1_t5_ub,
	PyDoc_STR("*float*: Period 1 Tier 5 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p1_t6_br", (getter)Common_get_ur_ec_p1_t6_br,(setter)Common_set_ur_ec_p1_t6_br,
	PyDoc_STR("*float*: Period 1 Tier 6 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p1_t6_sr", (getter)Common_get_ur_ec_p1_t6_sr,(setter)Common_set_ur_ec_p1_t6_sr,
	PyDoc_STR("*float*: Period 1 Tier 6 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p1_t6_ub", (getter)Common_get_ur_ec_p1_t6_ub,(setter)Common_set_ur_ec_p1_t6_ub,
	PyDoc_STR("*float*: Period 1 Tier 6 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p2_t1_br", (getter)Common_get_ur_ec_p2_t1_br,(setter)Common_set_ur_ec_p2_t1_br,
	PyDoc_STR("*float*: Period 2 Tier 1 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p2_t1_sr", (getter)Common_get_ur_ec_p2_t1_sr,(setter)Common_set_ur_ec_p2_t1_sr,
	PyDoc_STR("*float*: Period 2 Tier 1 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p2_t1_ub", (getter)Common_get_ur_ec_p2_t1_ub,(setter)Common_set_ur_ec_p2_t1_ub,
	PyDoc_STR("*float*: Period 2 Tier 1 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p2_t2_br", (getter)Common_get_ur_ec_p2_t2_br,(setter)Common_set_ur_ec_p2_t2_br,
	PyDoc_STR("*float*: Period 2 Tier 2 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p2_t2_sr", (getter)Common_get_ur_ec_p2_t2_sr,(setter)Common_set_ur_ec_p2_t2_sr,
	PyDoc_STR("*float*: Period 2 Tier 2 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p2_t2_ub", (getter)Common_get_ur_ec_p2_t2_ub,(setter)Common_set_ur_ec_p2_t2_ub,
	PyDoc_STR("*float*: Period 2 Tier 2 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p2_t3_br", (getter)Common_get_ur_ec_p2_t3_br,(setter)Common_set_ur_ec_p2_t3_br,
	PyDoc_STR("*float*: Period 2 Tier 3 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p2_t3_sr", (getter)Common_get_ur_ec_p2_t3_sr,(setter)Common_set_ur_ec_p2_t3_sr,
	PyDoc_STR("*float*: Period 2 Tier 3 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p2_t3_ub", (getter)Common_get_ur_ec_p2_t3_ub,(setter)Common_set_ur_ec_p2_t3_ub,
	PyDoc_STR("*float*: Period 2 Tier 3 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p2_t4_br", (getter)Common_get_ur_ec_p2_t4_br,(setter)Common_set_ur_ec_p2_t4_br,
	PyDoc_STR("*float*: Period 2 Tier 4 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p2_t4_sr", (getter)Common_get_ur_ec_p2_t4_sr,(setter)Common_set_ur_ec_p2_t4_sr,
	PyDoc_STR("*float*: Period 2 Tier 4 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p2_t4_ub", (getter)Common_get_ur_ec_p2_t4_ub,(setter)Common_set_ur_ec_p2_t4_ub,
	PyDoc_STR("*float*: Period 2 Tier 4 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p2_t5_br", (getter)Common_get_ur_ec_p2_t5_br,(setter)Common_set_ur_ec_p2_t5_br,
	PyDoc_STR("*float*: Period 2 Tier 5 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p2_t5_sr", (getter)Common_get_ur_ec_p2_t5_sr,(setter)Common_set_ur_ec_p2_t5_sr,
	PyDoc_STR("*float*: Period 2 Tier 5 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p2_t5_ub", (getter)Common_get_ur_ec_p2_t5_ub,(setter)Common_set_ur_ec_p2_t5_ub,
	PyDoc_STR("*float*: Period 2 Tier 5 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p2_t6_br", (getter)Common_get_ur_ec_p2_t6_br,(setter)Common_set_ur_ec_p2_t6_br,
	PyDoc_STR("*float*: Period 2 Tier 6 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p2_t6_sr", (getter)Common_get_ur_ec_p2_t6_sr,(setter)Common_set_ur_ec_p2_t6_sr,
	PyDoc_STR("*float*: Period 2 Tier 6 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p2_t6_ub", (getter)Common_get_ur_ec_p2_t6_ub,(setter)Common_set_ur_ec_p2_t6_ub,
	PyDoc_STR("*float*: Period 2 Tier 6 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p3_t1_br", (getter)Common_get_ur_ec_p3_t1_br,(setter)Common_set_ur_ec_p3_t1_br,
	PyDoc_STR("*float*: Period 3 Tier 1 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p3_t1_sr", (getter)Common_get_ur_ec_p3_t1_sr,(setter)Common_set_ur_ec_p3_t1_sr,
	PyDoc_STR("*float*: Period 3 Tier 1 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p3_t1_ub", (getter)Common_get_ur_ec_p3_t1_ub,(setter)Common_set_ur_ec_p3_t1_ub,
	PyDoc_STR("*float*: Period 3 Tier 1 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p3_t2_br", (getter)Common_get_ur_ec_p3_t2_br,(setter)Common_set_ur_ec_p3_t2_br,
	PyDoc_STR("*float*: Period 3 Tier 2 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p3_t2_sr", (getter)Common_get_ur_ec_p3_t2_sr,(setter)Common_set_ur_ec_p3_t2_sr,
	PyDoc_STR("*float*: Period 3 Tier 2 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p3_t2_ub", (getter)Common_get_ur_ec_p3_t2_ub,(setter)Common_set_ur_ec_p3_t2_ub,
	PyDoc_STR("*float*: Period 3 Tier 2 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p3_t3_br", (getter)Common_get_ur_ec_p3_t3_br,(setter)Common_set_ur_ec_p3_t3_br,
	PyDoc_STR("*float*: Period 3 Tier 3 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p3_t3_sr", (getter)Common_get_ur_ec_p3_t3_sr,(setter)Common_set_ur_ec_p3_t3_sr,
	PyDoc_STR("*float*: Period 3 Tier 3 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p3_t3_ub", (getter)Common_get_ur_ec_p3_t3_ub,(setter)Common_set_ur_ec_p3_t3_ub,
	PyDoc_STR("*float*: Period 3 Tier 3 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p3_t4_br", (getter)Common_get_ur_ec_p3_t4_br,(setter)Common_set_ur_ec_p3_t4_br,
	PyDoc_STR("*float*: Period 3 Tier 4 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p3_t4_sr", (getter)Common_get_ur_ec_p3_t4_sr,(setter)Common_set_ur_ec_p3_t4_sr,
	PyDoc_STR("*float*: Period 3 Tier 4 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p3_t4_ub", (getter)Common_get_ur_ec_p3_t4_ub,(setter)Common_set_ur_ec_p3_t4_ub,
	PyDoc_STR("*float*: Period 3 Tier 4 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p3_t5_br", (getter)Common_get_ur_ec_p3_t5_br,(setter)Common_set_ur_ec_p3_t5_br,
	PyDoc_STR("*float*: Period 3 Tier 5 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p3_t5_sr", (getter)Common_get_ur_ec_p3_t5_sr,(setter)Common_set_ur_ec_p3_t5_sr,
	PyDoc_STR("*float*: Period 3 Tier 5 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p3_t5_ub", (getter)Common_get_ur_ec_p3_t5_ub,(setter)Common_set_ur_ec_p3_t5_ub,
	PyDoc_STR("*float*: Period 3 Tier 5 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p3_t6_br", (getter)Common_get_ur_ec_p3_t6_br,(setter)Common_set_ur_ec_p3_t6_br,
	PyDoc_STR("*float*: Period 3 Tier 6 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p3_t6_sr", (getter)Common_get_ur_ec_p3_t6_sr,(setter)Common_set_ur_ec_p3_t6_sr,
	PyDoc_STR("*float*: Period 3 Tier 6 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p3_t6_ub", (getter)Common_get_ur_ec_p3_t6_ub,(setter)Common_set_ur_ec_p3_t6_ub,
	PyDoc_STR("*float*: Period 3 Tier 6 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p4_t1_br", (getter)Common_get_ur_ec_p4_t1_br,(setter)Common_set_ur_ec_p4_t1_br,
	PyDoc_STR("*float*: Period 4 Tier 1 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p4_t1_sr", (getter)Common_get_ur_ec_p4_t1_sr,(setter)Common_set_ur_ec_p4_t1_sr,
	PyDoc_STR("*float*: Period 4 Tier 1 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p4_t1_ub", (getter)Common_get_ur_ec_p4_t1_ub,(setter)Common_set_ur_ec_p4_t1_ub,
	PyDoc_STR("*float*: Period 4 Tier 1 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p4_t2_br", (getter)Common_get_ur_ec_p4_t2_br,(setter)Common_set_ur_ec_p4_t2_br,
	PyDoc_STR("*float*: Period 4 Tier 2 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p4_t2_sr", (getter)Common_get_ur_ec_p4_t2_sr,(setter)Common_set_ur_ec_p4_t2_sr,
	PyDoc_STR("*float*: Period 4 Tier 2 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p4_t2_ub", (getter)Common_get_ur_ec_p4_t2_ub,(setter)Common_set_ur_ec_p4_t2_ub,
	PyDoc_STR("*float*: Period 4 Tier 2 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p4_t3_br", (getter)Common_get_ur_ec_p4_t3_br,(setter)Common_set_ur_ec_p4_t3_br,
	PyDoc_STR("*float*: Period 4 Tier 3 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p4_t3_sr", (getter)Common_get_ur_ec_p4_t3_sr,(setter)Common_set_ur_ec_p4_t3_sr,
	PyDoc_STR("*float*: Period 4 Tier 3 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p4_t3_ub", (getter)Common_get_ur_ec_p4_t3_ub,(setter)Common_set_ur_ec_p4_t3_ub,
	PyDoc_STR("*float*: Period 4 Tier 3 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p4_t4_br", (getter)Common_get_ur_ec_p4_t4_br,(setter)Common_set_ur_ec_p4_t4_br,
	PyDoc_STR("*float*: Period 4 Tier 4 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p4_t4_sr", (getter)Common_get_ur_ec_p4_t4_sr,(setter)Common_set_ur_ec_p4_t4_sr,
	PyDoc_STR("*float*: Period 4 Tier 4 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p4_t4_ub", (getter)Common_get_ur_ec_p4_t4_ub,(setter)Common_set_ur_ec_p4_t4_ub,
	PyDoc_STR("*float*: Period 4 Tier 4 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p4_t5_br", (getter)Common_get_ur_ec_p4_t5_br,(setter)Common_set_ur_ec_p4_t5_br,
	PyDoc_STR("*float*: Period 4 Tier 5 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p4_t5_sr", (getter)Common_get_ur_ec_p4_t5_sr,(setter)Common_set_ur_ec_p4_t5_sr,
	PyDoc_STR("*float*: Period 4 Tier 5 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p4_t5_ub", (getter)Common_get_ur_ec_p4_t5_ub,(setter)Common_set_ur_ec_p4_t5_ub,
	PyDoc_STR("*float*: Period 4 Tier 5 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p4_t6_br", (getter)Common_get_ur_ec_p4_t6_br,(setter)Common_set_ur_ec_p4_t6_br,
	PyDoc_STR("*float*: Period 4 Tier 6 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p4_t6_sr", (getter)Common_get_ur_ec_p4_t6_sr,(setter)Common_set_ur_ec_p4_t6_sr,
	PyDoc_STR("*float*: Period 4 Tier 6 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p4_t6_ub", (getter)Common_get_ur_ec_p4_t6_ub,(setter)Common_set_ur_ec_p4_t6_ub,
	PyDoc_STR("*float*: Period 4 Tier 6 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p5_t1_br", (getter)Common_get_ur_ec_p5_t1_br,(setter)Common_set_ur_ec_p5_t1_br,
	PyDoc_STR("*float*: Period 5 Tier 1 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p5_t1_sr", (getter)Common_get_ur_ec_p5_t1_sr,(setter)Common_set_ur_ec_p5_t1_sr,
	PyDoc_STR("*float*: Period 5 Tier 1 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p5_t1_ub", (getter)Common_get_ur_ec_p5_t1_ub,(setter)Common_set_ur_ec_p5_t1_ub,
	PyDoc_STR("*float*: Period 5 Tier 1 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p5_t2_br", (getter)Common_get_ur_ec_p5_t2_br,(setter)Common_set_ur_ec_p5_t2_br,
	PyDoc_STR("*float*: Period 5 Tier 2 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p5_t2_sr", (getter)Common_get_ur_ec_p5_t2_sr,(setter)Common_set_ur_ec_p5_t2_sr,
	PyDoc_STR("*float*: Period 5 Tier 2 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p5_t2_ub", (getter)Common_get_ur_ec_p5_t2_ub,(setter)Common_set_ur_ec_p5_t2_ub,
	PyDoc_STR("*float*: Period 5 Tier 2 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p5_t3_br", (getter)Common_get_ur_ec_p5_t3_br,(setter)Common_set_ur_ec_p5_t3_br,
	PyDoc_STR("*float*: Period 5 Tier 3 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p5_t3_sr", (getter)Common_get_ur_ec_p5_t3_sr,(setter)Common_set_ur_ec_p5_t3_sr,
	PyDoc_STR("*float*: Period 5 Tier 3 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p5_t3_ub", (getter)Common_get_ur_ec_p5_t3_ub,(setter)Common_set_ur_ec_p5_t3_ub,
	PyDoc_STR("*float*: Period 5 Tier 3 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p5_t4_br", (getter)Common_get_ur_ec_p5_t4_br,(setter)Common_set_ur_ec_p5_t4_br,
	PyDoc_STR("*float*: Period 5 Tier 4 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p5_t4_sr", (getter)Common_get_ur_ec_p5_t4_sr,(setter)Common_set_ur_ec_p5_t4_sr,
	PyDoc_STR("*float*: Period 5 Tier 4 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p5_t4_ub", (getter)Common_get_ur_ec_p5_t4_ub,(setter)Common_set_ur_ec_p5_t4_ub,
	PyDoc_STR("*float*: Period 5 Tier 4 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p5_t5_br", (getter)Common_get_ur_ec_p5_t5_br,(setter)Common_set_ur_ec_p5_t5_br,
	PyDoc_STR("*float*: Period 5 Tier 5 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p5_t5_sr", (getter)Common_get_ur_ec_p5_t5_sr,(setter)Common_set_ur_ec_p5_t5_sr,
	PyDoc_STR("*float*: Period 5 Tier 5 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p5_t5_ub", (getter)Common_get_ur_ec_p5_t5_ub,(setter)Common_set_ur_ec_p5_t5_ub,
	PyDoc_STR("*float*: Period 5 Tier 5 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p5_t6_br", (getter)Common_get_ur_ec_p5_t6_br,(setter)Common_set_ur_ec_p5_t6_br,
	PyDoc_STR("*float*: Period 5 Tier 6 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p5_t6_sr", (getter)Common_get_ur_ec_p5_t6_sr,(setter)Common_set_ur_ec_p5_t6_sr,
	PyDoc_STR("*float*: Period 5 Tier 6 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p5_t6_ub", (getter)Common_get_ur_ec_p5_t6_ub,(setter)Common_set_ur_ec_p5_t6_ub,
	PyDoc_STR("*float*: Period 5 Tier 6 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p6_t1_br", (getter)Common_get_ur_ec_p6_t1_br,(setter)Common_set_ur_ec_p6_t1_br,
	PyDoc_STR("*float*: Period 6 Tier 1 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p6_t1_sr", (getter)Common_get_ur_ec_p6_t1_sr,(setter)Common_set_ur_ec_p6_t1_sr,
	PyDoc_STR("*float*: Period 6 Tier 1 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p6_t1_ub", (getter)Common_get_ur_ec_p6_t1_ub,(setter)Common_set_ur_ec_p6_t1_ub,
	PyDoc_STR("*float*: Period 6 Tier 1 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p6_t2_br", (getter)Common_get_ur_ec_p6_t2_br,(setter)Common_set_ur_ec_p6_t2_br,
	PyDoc_STR("*float*: Period 6 Tier 2 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p6_t2_sr", (getter)Common_get_ur_ec_p6_t2_sr,(setter)Common_set_ur_ec_p6_t2_sr,
	PyDoc_STR("*float*: Period 6 Tier 2 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p6_t2_ub", (getter)Common_get_ur_ec_p6_t2_ub,(setter)Common_set_ur_ec_p6_t2_ub,
	PyDoc_STR("*float*: Period 6 Tier 2 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p6_t3_br", (getter)Common_get_ur_ec_p6_t3_br,(setter)Common_set_ur_ec_p6_t3_br,
	PyDoc_STR("*float*: Period 6 Tier 3 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p6_t3_sr", (getter)Common_get_ur_ec_p6_t3_sr,(setter)Common_set_ur_ec_p6_t3_sr,
	PyDoc_STR("*float*: Period 6 Tier 3 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p6_t3_ub", (getter)Common_get_ur_ec_p6_t3_ub,(setter)Common_set_ur_ec_p6_t3_ub,
	PyDoc_STR("*float*: Period 6 Tier 3 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p6_t4_br", (getter)Common_get_ur_ec_p6_t4_br,(setter)Common_set_ur_ec_p6_t4_br,
	PyDoc_STR("*float*: Period 6 Tier 4 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p6_t4_sr", (getter)Common_get_ur_ec_p6_t4_sr,(setter)Common_set_ur_ec_p6_t4_sr,
	PyDoc_STR("*float*: Period 6 Tier 4 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p6_t4_ub", (getter)Common_get_ur_ec_p6_t4_ub,(setter)Common_set_ur_ec_p6_t4_ub,
	PyDoc_STR("*float*: Period 6 Tier 4 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p6_t5_br", (getter)Common_get_ur_ec_p6_t5_br,(setter)Common_set_ur_ec_p6_t5_br,
	PyDoc_STR("*float*: Period 6 Tier 5 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p6_t5_sr", (getter)Common_get_ur_ec_p6_t5_sr,(setter)Common_set_ur_ec_p6_t5_sr,
	PyDoc_STR("*float*: Period 6 Tier 5 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p6_t5_ub", (getter)Common_get_ur_ec_p6_t5_ub,(setter)Common_set_ur_ec_p6_t5_ub,
	PyDoc_STR("*float*: Period 6 Tier 5 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p6_t6_br", (getter)Common_get_ur_ec_p6_t6_br,(setter)Common_set_ur_ec_p6_t6_br,
	PyDoc_STR("*float*: Period 6 Tier 6 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p6_t6_sr", (getter)Common_get_ur_ec_p6_t6_sr,(setter)Common_set_ur_ec_p6_t6_sr,
	PyDoc_STR("*float*: Period 6 Tier 6 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p6_t6_ub", (getter)Common_get_ur_ec_p6_t6_ub,(setter)Common_set_ur_ec_p6_t6_ub,
	PyDoc_STR("*float*: Period 6 Tier 6 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p7_t1_br", (getter)Common_get_ur_ec_p7_t1_br,(setter)Common_set_ur_ec_p7_t1_br,
	PyDoc_STR("*float*: Period 7 Tier 1 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p7_t1_sr", (getter)Common_get_ur_ec_p7_t1_sr,(setter)Common_set_ur_ec_p7_t1_sr,
	PyDoc_STR("*float*: Period 7 Tier 1 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p7_t1_ub", (getter)Common_get_ur_ec_p7_t1_ub,(setter)Common_set_ur_ec_p7_t1_ub,
	PyDoc_STR("*float*: Period 7 Tier 1 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p7_t2_br", (getter)Common_get_ur_ec_p7_t2_br,(setter)Common_set_ur_ec_p7_t2_br,
	PyDoc_STR("*float*: Period 7 Tier 2 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p7_t2_sr", (getter)Common_get_ur_ec_p7_t2_sr,(setter)Common_set_ur_ec_p7_t2_sr,
	PyDoc_STR("*float*: Period 7 Tier 2 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p7_t2_ub", (getter)Common_get_ur_ec_p7_t2_ub,(setter)Common_set_ur_ec_p7_t2_ub,
	PyDoc_STR("*float*: Period 7 Tier 2 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p7_t3_br", (getter)Common_get_ur_ec_p7_t3_br,(setter)Common_set_ur_ec_p7_t3_br,
	PyDoc_STR("*float*: Period 7 Tier 3 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p7_t3_sr", (getter)Common_get_ur_ec_p7_t3_sr,(setter)Common_set_ur_ec_p7_t3_sr,
	PyDoc_STR("*float*: Period 7 Tier 3 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p7_t3_ub", (getter)Common_get_ur_ec_p7_t3_ub,(setter)Common_set_ur_ec_p7_t3_ub,
	PyDoc_STR("*float*: Period 7 Tier 3 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p7_t4_br", (getter)Common_get_ur_ec_p7_t4_br,(setter)Common_set_ur_ec_p7_t4_br,
	PyDoc_STR("*float*: Period 7 Tier 4 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p7_t4_sr", (getter)Common_get_ur_ec_p7_t4_sr,(setter)Common_set_ur_ec_p7_t4_sr,
	PyDoc_STR("*float*: Period 7 Tier 4 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p7_t4_ub", (getter)Common_get_ur_ec_p7_t4_ub,(setter)Common_set_ur_ec_p7_t4_ub,
	PyDoc_STR("*float*: Period 7 Tier 4 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p7_t5_br", (getter)Common_get_ur_ec_p7_t5_br,(setter)Common_set_ur_ec_p7_t5_br,
	PyDoc_STR("*float*: Period 7 Tier 5 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p7_t5_sr", (getter)Common_get_ur_ec_p7_t5_sr,(setter)Common_set_ur_ec_p7_t5_sr,
	PyDoc_STR("*float*: Period 7 Tier 5 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p7_t5_ub", (getter)Common_get_ur_ec_p7_t5_ub,(setter)Common_set_ur_ec_p7_t5_ub,
	PyDoc_STR("*float*: Period 7 Tier 5 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p7_t6_br", (getter)Common_get_ur_ec_p7_t6_br,(setter)Common_set_ur_ec_p7_t6_br,
	PyDoc_STR("*float*: Period 7 Tier 6 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p7_t6_sr", (getter)Common_get_ur_ec_p7_t6_sr,(setter)Common_set_ur_ec_p7_t6_sr,
	PyDoc_STR("*float*: Period 7 Tier 6 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p7_t6_ub", (getter)Common_get_ur_ec_p7_t6_ub,(setter)Common_set_ur_ec_p7_t6_ub,
	PyDoc_STR("*float*: Period 7 Tier 6 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p8_t1_br", (getter)Common_get_ur_ec_p8_t1_br,(setter)Common_set_ur_ec_p8_t1_br,
	PyDoc_STR("*float*: Period 8 Tier 1 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p8_t1_sr", (getter)Common_get_ur_ec_p8_t1_sr,(setter)Common_set_ur_ec_p8_t1_sr,
	PyDoc_STR("*float*: Period 8 Tier 1 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p8_t1_ub", (getter)Common_get_ur_ec_p8_t1_ub,(setter)Common_set_ur_ec_p8_t1_ub,
	PyDoc_STR("*float*: Period 8 Tier 1 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p8_t2_br", (getter)Common_get_ur_ec_p8_t2_br,(setter)Common_set_ur_ec_p8_t2_br,
	PyDoc_STR("*float*: Period 8 Tier 2 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p8_t2_sr", (getter)Common_get_ur_ec_p8_t2_sr,(setter)Common_set_ur_ec_p8_t2_sr,
	PyDoc_STR("*float*: Period 8 Tier 2 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p8_t2_ub", (getter)Common_get_ur_ec_p8_t2_ub,(setter)Common_set_ur_ec_p8_t2_ub,
	PyDoc_STR("*float*: Period 8 Tier 2 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p8_t3_br", (getter)Common_get_ur_ec_p8_t3_br,(setter)Common_set_ur_ec_p8_t3_br,
	PyDoc_STR("*float*: Period 8 Tier 3 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p8_t3_sr", (getter)Common_get_ur_ec_p8_t3_sr,(setter)Common_set_ur_ec_p8_t3_sr,
	PyDoc_STR("*float*: Period 8 Tier 3 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p8_t3_ub", (getter)Common_get_ur_ec_p8_t3_ub,(setter)Common_set_ur_ec_p8_t3_ub,
	PyDoc_STR("*float*: Period 8 Tier 3 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p8_t4_br", (getter)Common_get_ur_ec_p8_t4_br,(setter)Common_set_ur_ec_p8_t4_br,
	PyDoc_STR("*float*: Period 8 Tier 4 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p8_t4_sr", (getter)Common_get_ur_ec_p8_t4_sr,(setter)Common_set_ur_ec_p8_t4_sr,
	PyDoc_STR("*float*: Period 8 Tier 4 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p8_t4_ub", (getter)Common_get_ur_ec_p8_t4_ub,(setter)Common_set_ur_ec_p8_t4_ub,
	PyDoc_STR("*float*: Period 8 Tier 4 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p8_t5_br", (getter)Common_get_ur_ec_p8_t5_br,(setter)Common_set_ur_ec_p8_t5_br,
	PyDoc_STR("*float*: Period 8 Tier 5 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p8_t5_sr", (getter)Common_get_ur_ec_p8_t5_sr,(setter)Common_set_ur_ec_p8_t5_sr,
	PyDoc_STR("*float*: Period 8 Tier 5 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p8_t5_ub", (getter)Common_get_ur_ec_p8_t5_ub,(setter)Common_set_ur_ec_p8_t5_ub,
	PyDoc_STR("*float*: Period 8 Tier 5 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p8_t6_br", (getter)Common_get_ur_ec_p8_t6_br,(setter)Common_set_ur_ec_p8_t6_br,
	PyDoc_STR("*float*: Period 8 Tier 6 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p8_t6_sr", (getter)Common_get_ur_ec_p8_t6_sr,(setter)Common_set_ur_ec_p8_t6_sr,
	PyDoc_STR("*float*: Period 8 Tier 6 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p8_t6_ub", (getter)Common_get_ur_ec_p8_t6_ub,(setter)Common_set_ur_ec_p8_t6_ub,
	PyDoc_STR("*float*: Period 8 Tier 6 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p9_t1_br", (getter)Common_get_ur_ec_p9_t1_br,(setter)Common_set_ur_ec_p9_t1_br,
	PyDoc_STR("*float*: Period 9 Tier 1 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p9_t1_sr", (getter)Common_get_ur_ec_p9_t1_sr,(setter)Common_set_ur_ec_p9_t1_sr,
	PyDoc_STR("*float*: Period 9 Tier 1 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p9_t1_ub", (getter)Common_get_ur_ec_p9_t1_ub,(setter)Common_set_ur_ec_p9_t1_ub,
	PyDoc_STR("*float*: Period 9 Tier 1 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p9_t2_br", (getter)Common_get_ur_ec_p9_t2_br,(setter)Common_set_ur_ec_p9_t2_br,
	PyDoc_STR("*float*: Period 9 Tier 2 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p9_t2_sr", (getter)Common_get_ur_ec_p9_t2_sr,(setter)Common_set_ur_ec_p9_t2_sr,
	PyDoc_STR("*float*: Period 9 Tier 2 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p9_t2_ub", (getter)Common_get_ur_ec_p9_t2_ub,(setter)Common_set_ur_ec_p9_t2_ub,
	PyDoc_STR("*float*: Period 9 Tier 2 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p9_t3_br", (getter)Common_get_ur_ec_p9_t3_br,(setter)Common_set_ur_ec_p9_t3_br,
	PyDoc_STR("*float*: Period 9 Tier 3 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p9_t3_sr", (getter)Common_get_ur_ec_p9_t3_sr,(setter)Common_set_ur_ec_p9_t3_sr,
	PyDoc_STR("*float*: Period 9 Tier 3 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p9_t3_ub", (getter)Common_get_ur_ec_p9_t3_ub,(setter)Common_set_ur_ec_p9_t3_ub,
	PyDoc_STR("*float*: Period 9 Tier 3 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p9_t4_br", (getter)Common_get_ur_ec_p9_t4_br,(setter)Common_set_ur_ec_p9_t4_br,
	PyDoc_STR("*float*: Period 9 Tier 4 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p9_t4_sr", (getter)Common_get_ur_ec_p9_t4_sr,(setter)Common_set_ur_ec_p9_t4_sr,
	PyDoc_STR("*float*: Period 9 Tier 4 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p9_t4_ub", (getter)Common_get_ur_ec_p9_t4_ub,(setter)Common_set_ur_ec_p9_t4_ub,
	PyDoc_STR("*float*: Period 9 Tier 4 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p9_t5_br", (getter)Common_get_ur_ec_p9_t5_br,(setter)Common_set_ur_ec_p9_t5_br,
	PyDoc_STR("*float*: Period 9 Tier 5 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p9_t5_sr", (getter)Common_get_ur_ec_p9_t5_sr,(setter)Common_set_ur_ec_p9_t5_sr,
	PyDoc_STR("*float*: Period 9 Tier 5 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p9_t5_ub", (getter)Common_get_ur_ec_p9_t5_ub,(setter)Common_set_ur_ec_p9_t5_ub,
	PyDoc_STR("*float*: Period 9 Tier 5 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p9_t6_br", (getter)Common_get_ur_ec_p9_t6_br,(setter)Common_set_ur_ec_p9_t6_br,
	PyDoc_STR("*float*: Period 9 Tier 6 Energy Buy Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p9_t6_sr", (getter)Common_get_ur_ec_p9_t6_sr,(setter)Common_set_ur_ec_p9_t6_sr,
	PyDoc_STR("*float*: Period 9 Tier 6 Energy Sell Rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_p9_t6_ub", (getter)Common_get_ur_ec_p9_t6_ub,(setter)Common_set_ur_ec_p9_t6_ub,
	PyDoc_STR("*float*: Period 9 Tier 6 Maximum Energy Usage [kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"ur_ec_sched_weekday", (getter)Common_get_ur_ec_sched_weekday,(setter)Common_set_ur_ec_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: Energy Charge Weekday Schedule\n\n*Info*: 12x24\n\n*Required*: True if ur_ec_enable=1"),
 	NULL},
{"ur_ec_sched_weekend", (getter)Common_get_ur_ec_sched_weekend,(setter)Common_set_ur_ec_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Energy Charge Weekend Schedule\n\n*Info*: 12x24\n\n*Required*: True if ur_ec_enable=1"),
 	NULL},
{"ur_enable_net_metering", (getter)Common_get_ur_enable_net_metering,(setter)Common_set_ur_enable_net_metering,
	PyDoc_STR("*float*: Enable net metering [0/1]\n\n*Info*: Enforce net metering\n\n*Constraints*: BOOLEAN\n\n*Required*: If not provided, assumed to be 1"),
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
{"ur_nm_yearend_sell_rate", (getter)Common_get_ur_nm_yearend_sell_rate,(setter)Common_set_ur_nm_yearend_sell_rate,
	PyDoc_STR("*float*: Year end sell rate [$/kWh]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate2.Common",             /*tp_name*/
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
 * AnnualOutput Group
 */ 

static PyTypeObject AnnualOutput_Type;

static PyObject *
AnnualOutput_new(SAM_Utilityrate2 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate2", "AnnualOutput")){
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
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``AnnualOutput_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)AnnualOutput_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
AnnualOutput_get_degradation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_AnnualOutput_degradation_aget, self->data_ptr);
}

static int
AnnualOutput_set_degradation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate2_AnnualOutput_degradation_aset, self->data_ptr);
}

static PyGetSetDef AnnualOutput_getset[] = {
{"degradation", (getter)AnnualOutput_get_degradation,(setter)AnnualOutput_set_degradation,
	PyDoc_STR("*sequence*: Annual energy degradation [%]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject AnnualOutput_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate2.AnnualOutput",             /*tp_name*/
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
Outputs_new(SAM_Utilityrate2 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate2", "Outputs")){
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
Outputs_get_annual_energy_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_annual_energy_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_fixed_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_fixed_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_fixed_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_fixed_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_fixed_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_fixed_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_fixed_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_fixed_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_fixed_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_fixed_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_fixed_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_fixed_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_fixed_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_tou_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_tou_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_tou_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_tou_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_tou_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_tou_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_tou_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_tou_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_tou_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_tou_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_tou_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_dc_tou_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_dc_tou_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_ec_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_ec_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_ec_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_ec_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_ec_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_ec_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_ec_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_ec_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_ec_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_ec_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_ec_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_ec_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_ec_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_ec_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_ec_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_ec_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_ec_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_ec_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_ec_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_ec_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_ec_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_ec_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_ec_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_charge_ec_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_elec_cost_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_elec_cost_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_elec_cost_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_elec_cost_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_dc_tou_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_hourly_dc_tou_schedule_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_dc_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_hourly_dc_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_dc_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_hourly_dc_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_e_tofromgrid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_hourly_e_tofromgrid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_ec_tou_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_hourly_ec_tou_schedule_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_hourly_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_p_system_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_hourly_p_system_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_p_tofromgrid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_hourly_p_tofromgrid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_salespurchases_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_hourly_salespurchases_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_salespurchases_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_hourly_salespurchases_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_cumulative_excess_generation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_monthly_cumulative_excess_generation_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_fixed_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_monthly_dc_fixed_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_fixed_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_monthly_dc_fixed_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_tou_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_monthly_dc_tou_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_tou_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_monthly_dc_tou_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_ec_charge_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_monthly_ec_charge_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_ec_charge_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_monthly_ec_charge_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_electricity_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_monthly_electricity_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_monthly_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_salespurchases(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_monthly_salespurchases_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_salespurchases_wo_sys(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate2_Outputs_year1_monthly_salespurchases_wo_sys_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_energy_value", (getter)Outputs_get_annual_energy_value,(setter)0,
	PyDoc_STR("*sequence*: Energy value in each year [$]"),
 	NULL},
{"charge_dc_fixed_apr", (getter)Outputs_get_charge_dc_fixed_apr,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (Fixed) in Apr [$]"),
 	NULL},
{"charge_dc_fixed_aug", (getter)Outputs_get_charge_dc_fixed_aug,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (Fixed) in Aug [$]"),
 	NULL},
{"charge_dc_fixed_dec", (getter)Outputs_get_charge_dc_fixed_dec,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (Fixed) in Dec [$]"),
 	NULL},
{"charge_dc_fixed_feb", (getter)Outputs_get_charge_dc_fixed_feb,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (Fixed) in Feb [$]"),
 	NULL},
{"charge_dc_fixed_jan", (getter)Outputs_get_charge_dc_fixed_jan,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (Fixed) in Jan [$]"),
 	NULL},
{"charge_dc_fixed_jul", (getter)Outputs_get_charge_dc_fixed_jul,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (Fixed) in Jul [$]"),
 	NULL},
{"charge_dc_fixed_jun", (getter)Outputs_get_charge_dc_fixed_jun,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (Fixed) in Jun [$]"),
 	NULL},
{"charge_dc_fixed_mar", (getter)Outputs_get_charge_dc_fixed_mar,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (Fixed) in Mar [$]"),
 	NULL},
{"charge_dc_fixed_may", (getter)Outputs_get_charge_dc_fixed_may,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (Fixed) in May [$]"),
 	NULL},
{"charge_dc_fixed_nov", (getter)Outputs_get_charge_dc_fixed_nov,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (Fixed) in Nov [$]"),
 	NULL},
{"charge_dc_fixed_oct", (getter)Outputs_get_charge_dc_fixed_oct,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (Fixed) in Oct [$]"),
 	NULL},
{"charge_dc_fixed_sep", (getter)Outputs_get_charge_dc_fixed_sep,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (Fixed) in Sep [$]"),
 	NULL},
{"charge_dc_tou_apr", (getter)Outputs_get_charge_dc_tou_apr,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (TOU) in Apr [$]"),
 	NULL},
{"charge_dc_tou_aug", (getter)Outputs_get_charge_dc_tou_aug,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (TOU) in Aug [$]"),
 	NULL},
{"charge_dc_tou_dec", (getter)Outputs_get_charge_dc_tou_dec,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (TOU) in Dec [$]"),
 	NULL},
{"charge_dc_tou_feb", (getter)Outputs_get_charge_dc_tou_feb,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (TOU) in Feb [$]"),
 	NULL},
{"charge_dc_tou_jan", (getter)Outputs_get_charge_dc_tou_jan,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (TOU) in Jan [$]"),
 	NULL},
{"charge_dc_tou_jul", (getter)Outputs_get_charge_dc_tou_jul,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (TOU) in Jul [$]"),
 	NULL},
{"charge_dc_tou_jun", (getter)Outputs_get_charge_dc_tou_jun,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (TOU) in Jun [$]"),
 	NULL},
{"charge_dc_tou_mar", (getter)Outputs_get_charge_dc_tou_mar,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (TOU) in Mar [$]"),
 	NULL},
{"charge_dc_tou_may", (getter)Outputs_get_charge_dc_tou_may,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (TOU) in May [$]"),
 	NULL},
{"charge_dc_tou_nov", (getter)Outputs_get_charge_dc_tou_nov,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (TOU) in Nov [$]"),
 	NULL},
{"charge_dc_tou_oct", (getter)Outputs_get_charge_dc_tou_oct,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (TOU) in Oct [$]"),
 	NULL},
{"charge_dc_tou_sep", (getter)Outputs_get_charge_dc_tou_sep,(setter)0,
	PyDoc_STR("*sequence*: Demand Charge (TOU) in Sep [$]"),
 	NULL},
{"charge_ec_apr", (getter)Outputs_get_charge_ec_apr,(setter)0,
	PyDoc_STR("*sequence*: Energy Charge in Apr [$]"),
 	NULL},
{"charge_ec_aug", (getter)Outputs_get_charge_ec_aug,(setter)0,
	PyDoc_STR("*sequence*: Energy Charge in Aug [$]"),
 	NULL},
{"charge_ec_dec", (getter)Outputs_get_charge_ec_dec,(setter)0,
	PyDoc_STR("*sequence*: Energy Charge in Dec [$]"),
 	NULL},
{"charge_ec_feb", (getter)Outputs_get_charge_ec_feb,(setter)0,
	PyDoc_STR("*sequence*: Energy Charge in Feb [$]"),
 	NULL},
{"charge_ec_jan", (getter)Outputs_get_charge_ec_jan,(setter)0,
	PyDoc_STR("*sequence*: Energy Charge in Jan [$]"),
 	NULL},
{"charge_ec_jul", (getter)Outputs_get_charge_ec_jul,(setter)0,
	PyDoc_STR("*sequence*: Energy Charge in Jul [$]"),
 	NULL},
{"charge_ec_jun", (getter)Outputs_get_charge_ec_jun,(setter)0,
	PyDoc_STR("*sequence*: Energy Charge in Jun [$]"),
 	NULL},
{"charge_ec_mar", (getter)Outputs_get_charge_ec_mar,(setter)0,
	PyDoc_STR("*sequence*: Energy Charge in Mar [$]"),
 	NULL},
{"charge_ec_may", (getter)Outputs_get_charge_ec_may,(setter)0,
	PyDoc_STR("*sequence*: Energy Charge in May [$]"),
 	NULL},
{"charge_ec_nov", (getter)Outputs_get_charge_ec_nov,(setter)0,
	PyDoc_STR("*sequence*: Energy Charge in Nov [$]"),
 	NULL},
{"charge_ec_oct", (getter)Outputs_get_charge_ec_oct,(setter)0,
	PyDoc_STR("*sequence*: Energy Charge in Oct [$]"),
 	NULL},
{"charge_ec_sep", (getter)Outputs_get_charge_ec_sep,(setter)0,
	PyDoc_STR("*sequence*: Energy Charge in Sep [$]"),
 	NULL},
{"elec_cost_with_system", (getter)Outputs_get_elec_cost_with_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity cost with system [$/yr]"),
 	NULL},
{"elec_cost_without_system", (getter)Outputs_get_elec_cost_without_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity cost without system [$/yr]"),
 	NULL},
{"year1_hourly_dc_tou_schedule", (getter)Outputs_get_year1_hourly_dc_tou_schedule,(setter)0,
	PyDoc_STR("*sequence*: Hourly demand charge TOU period"),
 	NULL},
{"year1_hourly_dc_with_system", (getter)Outputs_get_year1_hourly_dc_with_system,(setter)0,
	PyDoc_STR("*sequence*: Year 1 demand charge by hour with system [$/kW]"),
 	NULL},
{"year1_hourly_dc_without_system", (getter)Outputs_get_year1_hourly_dc_without_system,(setter)0,
	PyDoc_STR("*sequence*: Year 1 demand charge by hour without system [$/kW]"),
 	NULL},
{"year1_hourly_e_tofromgrid", (getter)Outputs_get_year1_hourly_e_tofromgrid,(setter)0,
	PyDoc_STR("*sequence*: Year 1 electricity to/from grid [kWh]"),
 	NULL},
{"year1_hourly_ec_tou_schedule", (getter)Outputs_get_year1_hourly_ec_tou_schedule,(setter)0,
	PyDoc_STR("*sequence*: Hourly energy charge TOU period"),
 	NULL},
{"year1_hourly_load", (getter)Outputs_get_year1_hourly_load,(setter)0,
	PyDoc_STR("*sequence*: Year 1 hourly electric load [kWh]"),
 	NULL},
{"year1_hourly_p_system_to_load", (getter)Outputs_get_year1_hourly_p_system_to_load,(setter)0,
	PyDoc_STR("*sequence*: Year 1 subhourly peak load [kW]"),
 	NULL},
{"year1_hourly_p_tofromgrid", (getter)Outputs_get_year1_hourly_p_tofromgrid,(setter)0,
	PyDoc_STR("*sequence*: Year 1 subhourly peak to/from grid [kW]"),
 	NULL},
{"year1_hourly_salespurchases_with_system", (getter)Outputs_get_year1_hourly_salespurchases_with_system,(setter)0,
	PyDoc_STR("*sequence*: Year 1 hourly sales/purchases with sytem [$]"),
 	NULL},
{"year1_hourly_salespurchases_without_system", (getter)Outputs_get_year1_hourly_salespurchases_without_system,(setter)0,
	PyDoc_STR("*sequence*: Year 1 hourly sales/purchases without sytem [$]"),
 	NULL},
{"year1_monthly_cumulative_excess_generation", (getter)Outputs_get_year1_monthly_cumulative_excess_generation,(setter)0,
	PyDoc_STR("*sequence*: Year 1 monthly net metering credit [kWh]"),
 	NULL},
{"year1_monthly_dc_fixed_with_system", (getter)Outputs_get_year1_monthly_dc_fixed_with_system,(setter)0,
	PyDoc_STR("*sequence*: Year 1 monthly demand charge (Fixed) with system [$]"),
 	NULL},
{"year1_monthly_dc_fixed_without_system", (getter)Outputs_get_year1_monthly_dc_fixed_without_system,(setter)0,
	PyDoc_STR("*sequence*: Year 1 monthly demand charge (Fixed) without system [$]"),
 	NULL},
{"year1_monthly_dc_tou_with_system", (getter)Outputs_get_year1_monthly_dc_tou_with_system,(setter)0,
	PyDoc_STR("*sequence*: Year 1 monthly demand charge (TOU) with system [$]"),
 	NULL},
{"year1_monthly_dc_tou_without_system", (getter)Outputs_get_year1_monthly_dc_tou_without_system,(setter)0,
	PyDoc_STR("*sequence*: Year 1 monthly demand charge (TOU) without system [$]"),
 	NULL},
{"year1_monthly_ec_charge_with_system", (getter)Outputs_get_year1_monthly_ec_charge_with_system,(setter)0,
	PyDoc_STR("*sequence*: Year 1 monthly energy charge with system [$]"),
 	NULL},
{"year1_monthly_ec_charge_without_system", (getter)Outputs_get_year1_monthly_ec_charge_without_system,(setter)0,
	PyDoc_STR("*sequence*: Year 1 monthly energy charge without system [$]"),
 	NULL},
{"year1_monthly_electricity_to_grid", (getter)Outputs_get_year1_monthly_electricity_to_grid,(setter)0,
	PyDoc_STR("*sequence*: Year 1 monthly electricity to/from grid [kWh]"),
 	NULL},
{"year1_monthly_load", (getter)Outputs_get_year1_monthly_load,(setter)0,
	PyDoc_STR("*sequence*: Year 1 monthly electric load [kWh]"),
 	NULL},
{"year1_monthly_salespurchases", (getter)Outputs_get_year1_monthly_salespurchases,(setter)0,
	PyDoc_STR("*sequence*: Year 1 monthly sales/purchases with system [$]"),
 	NULL},
{"year1_monthly_salespurchases_wo_sys", (getter)Outputs_get_year1_monthly_salespurchases_wo_sys,(setter)0,
	PyDoc_STR("*sequence*: Year 1 monthly sales/purchases without system [$]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate2.Outputs",             /*tp_name*/
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
 * Utilityrate2
 */

static PyTypeObject Utilityrate2_Type;

static CmodObject *
newUtilityrate2Object(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Utilityrate2_Type);

	PySAM_TECH_ATTR()

	PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

	PyObject* AnnualOutput_obj = AnnualOutput_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "AnnualOutput", AnnualOutput_obj);
	Py_DECREF(AnnualOutput_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Utilityrate2 methods */

static void
Utilityrate2_dealloc(CmodObject *self)
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
Utilityrate2_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Utilityrate2_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Utilityrate2_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Utilityrate2"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Utilityrate2_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Utilityrate2_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef Utilityrate2_methods[] = {
		{"execute",            (PyCFunction)Utilityrate2_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Utilityrate2_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Common': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Utilityrate2_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Utilityrate2_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Utilityrate2_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Utilityrate2_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Utilityrate2_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate2",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Utilityrate2_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Utilityrate2_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Utilityrate2_getattro, /*tp_getattro*/
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
		Utilityrate2_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Utilityrate2 object */

static PyObject *
Utilityrate2_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newUtilityrate2Object(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Utilityrate2_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newUtilityrate2Object((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Utilityrate2_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newUtilityrate2Object(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Utilityrate2", def);

	return (PyObject *)rv;
}

static PyObject *
Utilityrate2_from_existing(PyObject *self, PyObject *args)
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

	rv = newUtilityrate2Object((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Utilityrate2", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Utilityrate2Module_methods[] = {
		{"new",             Utilityrate2_new,         METH_VARARGS,
				PyDoc_STR("new() -> Utilityrate2")},
		{"default",             Utilityrate2_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Utilityrate2\n\nUse default attributes\n"
				"None")},
		{"wrap",             Utilityrate2_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Utilityrate2\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   Utilityrate2_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Utilityrate2\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Utilityrate2");


static int
Utilityrate2Module_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Utilityrate2_Type.tp_dict = PyDict_New();
	if (!Utilityrate2_Type.tp_dict) { goto fail; }

	/// Add the Common type object to Utilityrate2_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate2_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the AnnualOutput type object to Utilityrate2_Type
	if (PyType_Ready(&AnnualOutput_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate2_Type.tp_dict,
				"AnnualOutput",
				(PyObject*)&AnnualOutput_Type);
	Py_DECREF(&AnnualOutput_Type);

	/// Add the Outputs type object to Utilityrate2_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate2_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Utilityrate2 type object to the module
	if (PyType_Ready(&Utilityrate2_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Utilityrate2",
				(PyObject*)&Utilityrate2_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Utilityrate2Module_slots[] = {
		{Py_mod_exec, Utilityrate2Module_exec},
		{0, NULL},
};

static struct PyModuleDef Utilityrate2Module = {
		PyModuleDef_HEAD_INIT,
		"Utilityrate2",
		module_doc,
		0,
		Utilityrate2Module_methods,
		Utilityrate2Module_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Utilityrate2(void)
{
	return PyModuleDef_Init(&Utilityrate2Module);
}