#include <Python.h>

#include <SAM_CbConstructionFinancing.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * SystemCosts Group
 */ 

static PyTypeObject SystemCosts_Type;

static PyObject *
SystemCosts_new(SAM_CbConstructionFinancing data_ptr)
{
	PyObject* new_obj = SystemCosts_Type.tp_alloc(&SystemCosts_Type,0);

	VarGroupObject* SystemCosts_obj = (VarGroupObject*)new_obj;

	SystemCosts_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SystemCosts methods */

static PyObject *
SystemCosts_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CbConstructionFinancing", "SystemCosts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemCosts_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SystemCosts_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SystemCosts_methods[] = {
		{"assign",            (PyCFunction)SystemCosts_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``SystemCosts_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SystemCosts_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemCosts_get_total_installed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_SystemCosts_total_installed_cost_nget, self->data_ptr);
}

static int
SystemCosts_set_total_installed_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_SystemCosts_total_installed_cost_nset, self->data_ptr);
}

static PyGetSetDef SystemCosts_getset[] = {
{"total_installed_cost", (getter)SystemCosts_get_total_installed_cost,(setter)SystemCosts_set_total_installed_cost,
	PyDoc_STR("*float*: Total installed cost [$]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CbConstructionFinancing.SystemCosts",             /*tp_name*/
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
		SystemCosts_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SystemCosts_getset,          /*tp_getset*/
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
 * FinancialParameters Group
 */ 

static PyTypeObject FinancialParameters_Type;

static PyObject *
FinancialParameters_new(SAM_CbConstructionFinancing data_ptr)
{
	PyObject* new_obj = FinancialParameters_Type.tp_alloc(&FinancialParameters_Type,0);

	VarGroupObject* FinancialParameters_obj = (VarGroupObject*)new_obj;

	FinancialParameters_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* FinancialParameters methods */

static PyObject *
FinancialParameters_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CbConstructionFinancing", "FinancialParameters")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialParameters_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &FinancialParameters_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef FinancialParameters_methods[] = {
		{"assign",            (PyCFunction)FinancialParameters_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``FinancialParameters_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)FinancialParameters_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
FinancialParameters_get_const_per_interest_rate1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_interest_rate1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_interest_rate1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_interest_rate2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_interest_rate2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_interest_rate3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_interest_rate3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_interest_rate4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_interest_rate4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_interest_rate5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_interest_rate5_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_months1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_months1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_months2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_months2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_months3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_months3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_months4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_months4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_months5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_months5_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_percent1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_percent1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_percent2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_percent2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_percent3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_percent3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_percent4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_percent4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_percent5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_percent5_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_upfront_rate1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_upfront_rate1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_upfront_rate2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_upfront_rate2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_upfront_rate3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_upfront_rate3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_upfront_rate4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_upfront_rate4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_FinancialParameters_const_per_upfront_rate5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbConstructionFinancing_FinancialParameters_const_per_upfront_rate5_nset, self->data_ptr);
}

static PyGetSetDef FinancialParameters_getset[] = {
{"const_per_interest_rate1", (getter)FinancialParameters_get_const_per_interest_rate1,(setter)FinancialParameters_set_const_per_interest_rate1,
	PyDoc_STR("*float*: Interest rate, loan 1 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_interest_rate2", (getter)FinancialParameters_get_const_per_interest_rate2,(setter)FinancialParameters_set_const_per_interest_rate2,
	PyDoc_STR("*float*: Interest rate, loan 2 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_interest_rate3", (getter)FinancialParameters_get_const_per_interest_rate3,(setter)FinancialParameters_set_const_per_interest_rate3,
	PyDoc_STR("*float*: Interest rate, loan 3 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_interest_rate4", (getter)FinancialParameters_get_const_per_interest_rate4,(setter)FinancialParameters_set_const_per_interest_rate4,
	PyDoc_STR("*float*: Interest rate, loan 4 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_interest_rate5", (getter)FinancialParameters_get_const_per_interest_rate5,(setter)FinancialParameters_set_const_per_interest_rate5,
	PyDoc_STR("*float*: Interest rate, loan 5 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_months1", (getter)FinancialParameters_get_const_per_months1,(setter)FinancialParameters_set_const_per_months1,
	PyDoc_STR("*float*: Months prior to operation, loan 1\n\n*Required*: True"),
 	NULL},
{"const_per_months2", (getter)FinancialParameters_get_const_per_months2,(setter)FinancialParameters_set_const_per_months2,
	PyDoc_STR("*float*: Months prior to operation, loan 2\n\n*Required*: True"),
 	NULL},
{"const_per_months3", (getter)FinancialParameters_get_const_per_months3,(setter)FinancialParameters_set_const_per_months3,
	PyDoc_STR("*float*: Months prior to operation, loan 3\n\n*Required*: True"),
 	NULL},
{"const_per_months4", (getter)FinancialParameters_get_const_per_months4,(setter)FinancialParameters_set_const_per_months4,
	PyDoc_STR("*float*: Months prior to operation, loan 4\n\n*Required*: True"),
 	NULL},
{"const_per_months5", (getter)FinancialParameters_get_const_per_months5,(setter)FinancialParameters_set_const_per_months5,
	PyDoc_STR("*float*: Months prior to operation, loan 5\n\n*Required*: True"),
 	NULL},
{"const_per_percent1", (getter)FinancialParameters_get_const_per_percent1,(setter)FinancialParameters_set_const_per_percent1,
	PyDoc_STR("*float*: Percent of tot. installed cost, loan 1 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_percent2", (getter)FinancialParameters_get_const_per_percent2,(setter)FinancialParameters_set_const_per_percent2,
	PyDoc_STR("*float*: Percent of tot. installed cost, loan 2 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_percent3", (getter)FinancialParameters_get_const_per_percent3,(setter)FinancialParameters_set_const_per_percent3,
	PyDoc_STR("*float*: Percent of tot. installed cost, loan 3 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_percent4", (getter)FinancialParameters_get_const_per_percent4,(setter)FinancialParameters_set_const_per_percent4,
	PyDoc_STR("*float*: Percent of tot. installed cost, loan 4 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_percent5", (getter)FinancialParameters_get_const_per_percent5,(setter)FinancialParameters_set_const_per_percent5,
	PyDoc_STR("*float*: Percent of tot. installed cost, loan 5 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_upfront_rate1", (getter)FinancialParameters_get_const_per_upfront_rate1,(setter)FinancialParameters_set_const_per_upfront_rate1,
	PyDoc_STR("*float*: Upfront fee on principal, loan 1 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_upfront_rate2", (getter)FinancialParameters_get_const_per_upfront_rate2,(setter)FinancialParameters_set_const_per_upfront_rate2,
	PyDoc_STR("*float*: Upfront fee on principal, loan 2 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_upfront_rate3", (getter)FinancialParameters_get_const_per_upfront_rate3,(setter)FinancialParameters_set_const_per_upfront_rate3,
	PyDoc_STR("*float*: Upfront fee on principal, loan 3 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_upfront_rate4", (getter)FinancialParameters_get_const_per_upfront_rate4,(setter)FinancialParameters_set_const_per_upfront_rate4,
	PyDoc_STR("*float*: Upfront fee on principal, loan 4 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_upfront_rate5", (getter)FinancialParameters_get_const_per_upfront_rate5,(setter)FinancialParameters_set_const_per_upfront_rate5,
	PyDoc_STR("*float*: Upfront fee on principal, loan 5 [%]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FinancialParameters_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CbConstructionFinancing.FinancialParameters",             /*tp_name*/
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
		FinancialParameters_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		FinancialParameters_getset,          /*tp_getset*/
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
Outputs_new(SAM_CbConstructionFinancing data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CbConstructionFinancing", "Outputs")){
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
Outputs_get_const_per_interest1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_Outputs_const_per_interest1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_Outputs_const_per_interest2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_Outputs_const_per_interest3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_Outputs_const_per_interest4_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_Outputs_const_per_interest5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_Outputs_const_per_interest_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_percent_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_Outputs_const_per_percent_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_Outputs_const_per_principal1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_Outputs_const_per_principal2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_Outputs_const_per_principal3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_Outputs_const_per_principal4_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_Outputs_const_per_principal5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_Outputs_const_per_principal_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_Outputs_const_per_total1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_Outputs_const_per_total2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_Outputs_const_per_total3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_Outputs_const_per_total4_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_Outputs_const_per_total5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_construction_financing_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbConstructionFinancing_Outputs_construction_financing_cost_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"const_per_interest1", (getter)Outputs_get_const_per_interest1,(setter)0,
	PyDoc_STR("*float*: Interest cost, loan 1 [$]"),
 	NULL},
{"const_per_interest2", (getter)Outputs_get_const_per_interest2,(setter)0,
	PyDoc_STR("*float*: Interest cost, loan 2 [$]"),
 	NULL},
{"const_per_interest3", (getter)Outputs_get_const_per_interest3,(setter)0,
	PyDoc_STR("*float*: Interest cost, loan 3 [$]"),
 	NULL},
{"const_per_interest4", (getter)Outputs_get_const_per_interest4,(setter)0,
	PyDoc_STR("*float*: Interest cost, loan 4 [$]"),
 	NULL},
{"const_per_interest5", (getter)Outputs_get_const_per_interest5,(setter)0,
	PyDoc_STR("*float*: Interest cost, loan 5 [$]"),
 	NULL},
{"const_per_interest_total", (getter)Outputs_get_const_per_interest_total,(setter)0,
	PyDoc_STR("*float*: Total interest costs, all loans [$]"),
 	NULL},
{"const_per_percent_total", (getter)Outputs_get_const_per_percent_total,(setter)0,
	PyDoc_STR("*float*: Total percent of installed costs, all loans [%]"),
 	NULL},
{"const_per_principal1", (getter)Outputs_get_const_per_principal1,(setter)0,
	PyDoc_STR("*float*: Principal, loan 1 [$]"),
 	NULL},
{"const_per_principal2", (getter)Outputs_get_const_per_principal2,(setter)0,
	PyDoc_STR("*float*: Principal, loan 2 [$]"),
 	NULL},
{"const_per_principal3", (getter)Outputs_get_const_per_principal3,(setter)0,
	PyDoc_STR("*float*: Principal, loan 3 [$]"),
 	NULL},
{"const_per_principal4", (getter)Outputs_get_const_per_principal4,(setter)0,
	PyDoc_STR("*float*: Principal, loan 4 [$]"),
 	NULL},
{"const_per_principal5", (getter)Outputs_get_const_per_principal5,(setter)0,
	PyDoc_STR("*float*: Principal, loan 5 [$]"),
 	NULL},
{"const_per_principal_total", (getter)Outputs_get_const_per_principal_total,(setter)0,
	PyDoc_STR("*float*: Total principal, all loans [$]"),
 	NULL},
{"const_per_total1", (getter)Outputs_get_const_per_total1,(setter)0,
	PyDoc_STR("*float*: Total financing cost, loan 1 [$]"),
 	NULL},
{"const_per_total2", (getter)Outputs_get_const_per_total2,(setter)0,
	PyDoc_STR("*float*: Total financing cost, loan 2 [$]"),
 	NULL},
{"const_per_total3", (getter)Outputs_get_const_per_total3,(setter)0,
	PyDoc_STR("*float*: Total financing cost, loan 3 [$]"),
 	NULL},
{"const_per_total4", (getter)Outputs_get_const_per_total4,(setter)0,
	PyDoc_STR("*float*: Total financing cost, loan 4 [$]"),
 	NULL},
{"const_per_total5", (getter)Outputs_get_const_per_total5,(setter)0,
	PyDoc_STR("*float*: Total financing cost, loan 5 [$]"),
 	NULL},
{"construction_financing_cost", (getter)Outputs_get_construction_financing_cost,(setter)0,
	PyDoc_STR("*float*: Total construction financing cost [$]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CbConstructionFinancing.Outputs",             /*tp_name*/
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
 * CbConstructionFinancing
 */

static PyTypeObject CbConstructionFinancing_Type;

static CmodObject *
newCbConstructionFinancingObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &CbConstructionFinancing_Type);

	PySAM_TECH_ATTR()

	PyObject* SystemCosts_obj = SystemCosts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemCosts", SystemCosts_obj);
	Py_DECREF(SystemCosts_obj);

	PyObject* FinancialParameters_obj = FinancialParameters_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FinancialParameters", FinancialParameters_obj);
	Py_DECREF(FinancialParameters_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* CbConstructionFinancing methods */

static void
CbConstructionFinancing_dealloc(CmodObject *self)
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
CbConstructionFinancing_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_CbConstructionFinancing_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
CbConstructionFinancing_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "CbConstructionFinancing"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
CbConstructionFinancing_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
CbConstructionFinancing_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef CbConstructionFinancing_methods[] = {
		{"execute",            (PyCFunction)CbConstructionFinancing_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)CbConstructionFinancing_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'system costs': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)CbConstructionFinancing_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)CbConstructionFinancing_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
CbConstructionFinancing_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
CbConstructionFinancing_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject CbConstructionFinancing_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CbConstructionFinancing",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)CbConstructionFinancing_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)CbConstructionFinancing_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)CbConstructionFinancing_getattro, /*tp_getattro*/
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
		CbConstructionFinancing_methods,      /*tp_methods*/
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


/* Function of no arguments returning new CbConstructionFinancing object */

static PyObject *
CbConstructionFinancing_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newCbConstructionFinancingObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
CbConstructionFinancing_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newCbConstructionFinancingObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
CbConstructionFinancing_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newCbConstructionFinancingObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "CbConstructionFinancing", def);

	return (PyObject *)rv;
}

static PyObject *
CbConstructionFinancing_from_existing(PyObject *self, PyObject *args)
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

	rv = newCbConstructionFinancingObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "CbConstructionFinancing", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef CbConstructionFinancingModule_methods[] = {
		{"new",             CbConstructionFinancing_new,         METH_VARARGS,
				PyDoc_STR("new() -> CbConstructionFinancing")},
		{"default",             CbConstructionFinancing_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> CbConstructionFinancing\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             CbConstructionFinancing_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> CbConstructionFinancing\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   CbConstructionFinancing_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> CbConstructionFinancing\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "CbConstructionFinancing");


static int
CbConstructionFinancingModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	CbConstructionFinancing_Type.tp_dict = PyDict_New();
	if (!CbConstructionFinancing_Type.tp_dict) { goto fail; }

	/// Add the SystemCosts type object to CbConstructionFinancing_Type
	if (PyType_Ready(&SystemCosts_Type) < 0) { goto fail; }
	PyDict_SetItemString(CbConstructionFinancing_Type.tp_dict,
				"SystemCosts",
				(PyObject*)&SystemCosts_Type);
	Py_DECREF(&SystemCosts_Type);

	/// Add the FinancialParameters type object to CbConstructionFinancing_Type
	if (PyType_Ready(&FinancialParameters_Type) < 0) { goto fail; }
	PyDict_SetItemString(CbConstructionFinancing_Type.tp_dict,
				"FinancialParameters",
				(PyObject*)&FinancialParameters_Type);
	Py_DECREF(&FinancialParameters_Type);

	/// Add the Outputs type object to CbConstructionFinancing_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(CbConstructionFinancing_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the CbConstructionFinancing type object to the module
	if (PyType_Ready(&CbConstructionFinancing_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"CbConstructionFinancing",
				(PyObject*)&CbConstructionFinancing_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot CbConstructionFinancingModule_slots[] = {
		{Py_mod_exec, CbConstructionFinancingModule_exec},
		{0, NULL},
};

static struct PyModuleDef CbConstructionFinancingModule = {
		PyModuleDef_HEAD_INIT,
		"CbConstructionFinancing",
		module_doc,
		0,
		CbConstructionFinancingModule_methods,
		CbConstructionFinancingModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_CbConstructionFinancing(void)
{
	return PyModuleDef_Init(&CbConstructionFinancingModule);
}