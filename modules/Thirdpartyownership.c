#include <Python.h>

#include <SAM_Thirdpartyownership.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Depreciation Group
 */ 

static PyTypeObject Depreciation_Type;

static PyObject *
Depreciation_new(SAM_Thirdpartyownership data_ptr)
{
	PyObject* new_obj = Depreciation_Type.tp_alloc(&Depreciation_Type,0);

	VarGroupObject* Depreciation_obj = (VarGroupObject*)new_obj;

	Depreciation_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Depreciation methods */

static PyObject *
Depreciation_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thirdpartyownership", "Depreciation")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Depreciation_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Depreciation_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Thirdpartyownership", "Depreciation")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Depreciation_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Depreciation_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Depreciation_methods[] = {
		{"assign",            (PyCFunction)Depreciation_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Depreciation_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Depreciation_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Depreciation_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Depreciation_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Depreciation_get_depr_fed_custom(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Depreciation_depr_fed_custom_aget, self->data_ptr);
}

static int
Depreciation_set_depr_fed_custom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Thirdpartyownership_Depreciation_depr_fed_custom_aset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_fed_sl_years(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Thirdpartyownership_Depreciation_depr_fed_sl_years_nget, self->data_ptr);
}

static int
Depreciation_set_depr_fed_sl_years(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Thirdpartyownership_Depreciation_depr_fed_sl_years_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_fed_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Thirdpartyownership_Depreciation_depr_fed_type_nget, self->data_ptr);
}

static int
Depreciation_set_depr_fed_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Thirdpartyownership_Depreciation_depr_fed_type_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_sta_custom(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Depreciation_depr_sta_custom_aget, self->data_ptr);
}

static int
Depreciation_set_depr_sta_custom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Thirdpartyownership_Depreciation_depr_sta_custom_aset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_sta_sl_years(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Thirdpartyownership_Depreciation_depr_sta_sl_years_nget, self->data_ptr);
}

static int
Depreciation_set_depr_sta_sl_years(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Thirdpartyownership_Depreciation_depr_sta_sl_years_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_sta_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Thirdpartyownership_Depreciation_depr_sta_type_nget, self->data_ptr);
}

static int
Depreciation_set_depr_sta_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Thirdpartyownership_Depreciation_depr_sta_type_nset, self->data_ptr);
}

static PyGetSetDef Depreciation_getset[] = {
{"depr_fed_custom", (getter)Depreciation_get_depr_fed_custom,(setter)Depreciation_set_depr_fed_custom,
	PyDoc_STR("*sequence*: Federal custom depreciation [%/year]\n\n**Required:**\nRequired if depr_fed_type=3"),
 	NULL},
{"depr_fed_sl_years", (getter)Depreciation_get_depr_fed_sl_years,(setter)Depreciation_set_depr_fed_sl_years,
	PyDoc_STR("*float*: Federal depreciation straight-line Years [years]\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nRequired if depr_fed_type=2"),
 	NULL},
{"depr_fed_type", (getter)Depreciation_get_depr_fed_type,(setter)Depreciation_set_depr_fed_type,
	PyDoc_STR("*float*: Federal depreciation type\n\n**Options:**\n0=none,1=macrs_half_year,2=sl,3=custom\n\n**Constraints:**\nINTEGER,MIN=0,MAX=3\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_sta_custom", (getter)Depreciation_get_depr_sta_custom,(setter)Depreciation_set_depr_sta_custom,
	PyDoc_STR("*sequence*: State custom depreciation [%/year]\n\n**Required:**\nRequired if depr_sta_type=3"),
 	NULL},
{"depr_sta_sl_years", (getter)Depreciation_get_depr_sta_sl_years,(setter)Depreciation_set_depr_sta_sl_years,
	PyDoc_STR("*float*: State depreciation straight-line years [years]\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nRequired if depr_sta_type=2"),
 	NULL},
{"depr_sta_type", (getter)Depreciation_get_depr_sta_type,(setter)Depreciation_set_depr_sta_type,
	PyDoc_STR("*float*: State depreciation type\n\n**Options:**\n0=none,1=macrs_half_year,2=sl,3=custom\n\n**Constraints:**\nINTEGER,MIN=0,MAX=3\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Depreciation_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thirdpartyownership.Depreciation",             /*tp_name*/
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
		Depreciation_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Depreciation_getset,          /*tp_getset*/
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
Financials_new(SAM_Thirdpartyownership data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thirdpartyownership", "Financials")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Thirdpartyownership", "Financials")){
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
Financials_get_analysis_period(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Thirdpartyownership_Financials_analysis_period_nget, self->data_ptr);
}

static int
Financials_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Thirdpartyownership_Financials_analysis_period_nset, self->data_ptr);
}

static PyObject *
Financials_get_inflation_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Thirdpartyownership_Financials_inflation_rate_nget, self->data_ptr);
}

static int
Financials_set_inflation_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Thirdpartyownership_Financials_inflation_rate_nset, self->data_ptr);
}

static PyObject *
Financials_get_real_discount_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Thirdpartyownership_Financials_real_discount_rate_nget, self->data_ptr);
}

static int
Financials_set_real_discount_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Thirdpartyownership_Financials_real_discount_rate_nset, self->data_ptr);
}

static PyGetSetDef Financials_getset[] = {
{"analysis_period", (getter)Financials_get_analysis_period,(setter)Financials_set_analysis_period,
	PyDoc_STR("*float*: Analyis period [years]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=50\n\n**Required:**\nFalse. Automatically set to 30 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"inflation_rate", (getter)Financials_get_inflation_rate,(setter)Financials_set_inflation_rate,
	PyDoc_STR("*float*: Inflation rate [%]\n\n**Constraints:**\nMIN=-99\n\n**Required:**\nTrue"),
 	NULL},
{"real_discount_rate", (getter)Financials_get_real_discount_rate,(setter)Financials_set_real_discount_rate,
	PyDoc_STR("*float*: Real discount rate [%]\n\n**Constraints:**\nMIN=-99\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Financials_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thirdpartyownership.Financials",             /*tp_name*/
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
 * FinancialThirdPartyOwnership Group
 */ 

static PyTypeObject FinancialThirdPartyOwnership_Type;

static PyObject *
FinancialThirdPartyOwnership_new(SAM_Thirdpartyownership data_ptr)
{
	PyObject* new_obj = FinancialThirdPartyOwnership_Type.tp_alloc(&FinancialThirdPartyOwnership_Type,0);

	VarGroupObject* FinancialThirdPartyOwnership_obj = (VarGroupObject*)new_obj;

	FinancialThirdPartyOwnership_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* FinancialThirdPartyOwnership methods */

static PyObject *
FinancialThirdPartyOwnership_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thirdpartyownership", "FinancialThirdPartyOwnership")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialThirdPartyOwnership_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &FinancialThirdPartyOwnership_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Thirdpartyownership", "FinancialThirdPartyOwnership")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialThirdPartyOwnership_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &FinancialThirdPartyOwnership_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef FinancialThirdPartyOwnership_methods[] = {
		{"assign",            (PyCFunction)FinancialThirdPartyOwnership_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``FinancialThirdPartyOwnership_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)FinancialThirdPartyOwnership_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``FinancialThirdPartyOwnership_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)FinancialThirdPartyOwnership_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
FinancialThirdPartyOwnership_get_lease_or_ppa(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Thirdpartyownership_FinancialThirdPartyOwnership_lease_or_ppa_nget, self->data_ptr);
}

static int
FinancialThirdPartyOwnership_set_lease_or_ppa(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Thirdpartyownership_FinancialThirdPartyOwnership_lease_or_ppa_nset, self->data_ptr);
}

static PyGetSetDef FinancialThirdPartyOwnership_getset[] = {
{"lease_or_ppa", (getter)FinancialThirdPartyOwnership_get_lease_or_ppa,(setter)FinancialThirdPartyOwnership_set_lease_or_ppa,
	PyDoc_STR("*float*: Lease or PPA agreement [0/1]\n\n**Options:**\n0=lease,1=ppa\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FinancialThirdPartyOwnership_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thirdpartyownership.FinancialThirdPartyOwnership",             /*tp_name*/
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
		FinancialThirdPartyOwnership_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		FinancialThirdPartyOwnership_getset,          /*tp_getset*/
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
 * Common Group
 */ 

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_Thirdpartyownership data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thirdpartyownership", "Common")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Thirdpartyownership", "Common")){
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
Common_get_annual_energy_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Common_annual_energy_value_aget, self->data_ptr);
}

static int
Common_set_annual_energy_value(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Thirdpartyownership_Common_annual_energy_value_aset, self->data_ptr);
}

static PyObject *
Common_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Common_gen_aget, self->data_ptr);
}

static int
Common_set_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Thirdpartyownership_Common_gen_aset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"annual_energy_value", (getter)Common_get_annual_energy_value,(setter)Common_set_annual_energy_value,
	PyDoc_STR("*sequence*: Energy value [$]\n\n**Required:**\nTrue"),
 	NULL},
{"gen", (getter)Common_get_gen,(setter)Common_set_gen,
	PyDoc_STR("*sequence*: Power generated by renewable resource [kW]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thirdpartyownership.Common",             /*tp_name*/
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
AnnualOutput_new(SAM_Thirdpartyownership data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thirdpartyownership", "AnnualOutput")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Thirdpartyownership", "AnnualOutput")){
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
	return PySAM_array_getter(SAM_Thirdpartyownership_AnnualOutput_degradation_aget, self->data_ptr);
}

static int
AnnualOutput_set_degradation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Thirdpartyownership_AnnualOutput_degradation_aset, self->data_ptr);
}

static PyObject *
AnnualOutput_get_system_use_lifetime_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Thirdpartyownership_AnnualOutput_system_use_lifetime_output_nget, self->data_ptr);
}

static int
AnnualOutput_set_system_use_lifetime_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Thirdpartyownership_AnnualOutput_system_use_lifetime_output_nset, self->data_ptr);
}

static PyGetSetDef AnnualOutput_getset[] = {
{"degradation", (getter)AnnualOutput_get_degradation,(setter)AnnualOutput_set_degradation,
	PyDoc_STR("*sequence*: Annual degradation [%]\n\n**Required:**\nTrue"),
 	NULL},
{"system_use_lifetime_output", (getter)AnnualOutput_get_system_use_lifetime_output,(setter)AnnualOutput_set_system_use_lifetime_output,
	PyDoc_STR("*float*: Lifetime hourly system outputs [0/1]\n\n**Options:**\n0=hourly first year,1=hourly lifetime\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject AnnualOutput_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thirdpartyownership.AnnualOutput",             /*tp_name*/
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
 * CashFlow Group
 */ 

static PyTypeObject CashFlow_Type;

static PyObject *
CashFlow_new(SAM_Thirdpartyownership data_ptr)
{
	PyObject* new_obj = CashFlow_Type.tp_alloc(&CashFlow_Type,0);

	VarGroupObject* CashFlow_obj = (VarGroupObject*)new_obj;

	CashFlow_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* CashFlow methods */

static PyObject *
CashFlow_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thirdpartyownership", "CashFlow")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
CashFlow_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &CashFlow_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Thirdpartyownership", "CashFlow")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
CashFlow_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &CashFlow_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef CashFlow_methods[] = {
		{"assign",            (PyCFunction)CashFlow_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``CashFlow_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)CashFlow_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``CashFlow_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)CashFlow_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
CashFlow_get_lease_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Thirdpartyownership_CashFlow_lease_escalation_nget, self->data_ptr);
}

static int
CashFlow_set_lease_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Thirdpartyownership_CashFlow_lease_escalation_nset, self->data_ptr);
}

static PyObject *
CashFlow_get_lease_price(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Thirdpartyownership_CashFlow_lease_price_nget, self->data_ptr);
}

static int
CashFlow_set_lease_price(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Thirdpartyownership_CashFlow_lease_price_nset, self->data_ptr);
}

static PyObject *
CashFlow_get_ppa_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Thirdpartyownership_CashFlow_ppa_escalation_nget, self->data_ptr);
}

static int
CashFlow_set_ppa_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Thirdpartyownership_CashFlow_ppa_escalation_nset, self->data_ptr);
}

static PyObject *
CashFlow_get_ppa_price(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Thirdpartyownership_CashFlow_ppa_price_nget, self->data_ptr);
}

static int
CashFlow_set_ppa_price(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Thirdpartyownership_CashFlow_ppa_price_nset, self->data_ptr);
}

static PyGetSetDef CashFlow_getset[] = {
{"lease_escalation", (getter)CashFlow_get_lease_escalation,(setter)CashFlow_set_lease_escalation,
	PyDoc_STR("*float*: Monthly lease escalation [%/year]\n\n**Required:**\nRequired if lease_or_ppa=0"),
 	NULL},
{"lease_price", (getter)CashFlow_get_lease_price,(setter)CashFlow_set_lease_price,
	PyDoc_STR("*float*: Monthly lease price [$/month]\n\n**Required:**\nRequired if lease_or_ppa=0"),
 	NULL},
{"ppa_escalation", (getter)CashFlow_get_ppa_escalation,(setter)CashFlow_set_ppa_escalation,
	PyDoc_STR("*float*: Monthly lease escalation [%/year]\n\n**Required:**\nRequired if lease_or_ppa=1"),
 	NULL},
{"ppa_price", (getter)CashFlow_get_ppa_price,(setter)CashFlow_set_ppa_price,
	PyDoc_STR("*float*: Monthly lease price [$/month]\n\n**Required:**\nRequired if lease_or_ppa=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject CashFlow_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thirdpartyownership.CashFlow",             /*tp_name*/
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
		CashFlow_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		CashFlow_getset,          /*tp_getset*/
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
 * ElectricityCost Group
 */ 

static PyTypeObject ElectricityCost_Type;

static PyObject *
ElectricityCost_new(SAM_Thirdpartyownership data_ptr)
{
	PyObject* new_obj = ElectricityCost_Type.tp_alloc(&ElectricityCost_Type,0);

	VarGroupObject* ElectricityCost_obj = (VarGroupObject*)new_obj;

	ElectricityCost_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* ElectricityCost methods */

static PyObject *
ElectricityCost_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thirdpartyownership", "ElectricityCost")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ElectricityCost_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &ElectricityCost_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Thirdpartyownership", "ElectricityCost")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ElectricityCost_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &ElectricityCost_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ElectricityCost_methods[] = {
		{"assign",            (PyCFunction)ElectricityCost_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``ElectricityCost_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)ElectricityCost_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``ElectricityCost_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)ElectricityCost_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ElectricityCost_get_elec_cost_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_ElectricityCost_elec_cost_with_system_aget, self->data_ptr);
}

static int
ElectricityCost_set_elec_cost_with_system(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Thirdpartyownership_ElectricityCost_elec_cost_with_system_aset, self->data_ptr);
}

static PyObject *
ElectricityCost_get_elec_cost_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_ElectricityCost_elec_cost_without_system_aget, self->data_ptr);
}

static int
ElectricityCost_set_elec_cost_without_system(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Thirdpartyownership_ElectricityCost_elec_cost_without_system_aset, self->data_ptr);
}

static PyGetSetDef ElectricityCost_getset[] = {
{"elec_cost_with_system", (getter)ElectricityCost_get_elec_cost_with_system,(setter)ElectricityCost_set_elec_cost_with_system,
	PyDoc_STR("*sequence*: Energy value [$]\n\n**Required:**\nTrue"),
 	NULL},
{"elec_cost_without_system", (getter)ElectricityCost_get_elec_cost_without_system,(setter)ElectricityCost_set_elec_cost_without_system,
	PyDoc_STR("*sequence*: Energy value [$]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ElectricityCost_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thirdpartyownership.ElectricityCost",             /*tp_name*/
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
		ElectricityCost_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ElectricityCost_getset,          /*tp_getset*/
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
Outputs_new(SAM_Thirdpartyownership data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thirdpartyownership", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Thirdpartyownership", "Outputs")){
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
Outputs_get_cf_after_tax_cash_flow(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Outputs_cf_after_tax_cash_flow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_after_tax_net_equity_cost_flow(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Outputs_cf_after_tax_net_equity_cost_flow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_agreement_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Outputs_cf_agreement_cost_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_cumulative_payback_with_expenses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Outputs_cf_cumulative_payback_with_expenses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Outputs_cf_energy_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_purchases(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Outputs_cf_energy_purchases_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Outputs_cf_energy_sales_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_length(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Thirdpartyownership_Outputs_cf_length_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_nte(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Outputs_cf_nte_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_payback_with_expenses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Outputs_cf_payback_with_expenses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_lnte_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Thirdpartyownership_Outputs_lnte_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lnte_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Thirdpartyownership_Outputs_lnte_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_npv(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Thirdpartyownership_Outputs_npv_nget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_nte(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Thirdpartyownership_Outputs_year1_nte_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"cf_after_tax_cash_flow", (getter)Outputs_get_cf_after_tax_cash_flow,(setter)0,
	PyDoc_STR("*sequence*: After-tax cash flow [$]"),
 	NULL},
{"cf_after_tax_net_equity_cost_flow", (getter)Outputs_get_cf_after_tax_net_equity_cost_flow,(setter)0,
	PyDoc_STR("*sequence*: After-tax annual costs [$]"),
 	NULL},
{"cf_agreement_cost", (getter)Outputs_get_cf_agreement_cost,(setter)0,
	PyDoc_STR("*sequence*: Agreement cost [$]"),
 	NULL},
{"cf_cumulative_payback_with_expenses", (getter)Outputs_get_cf_cumulative_payback_with_expenses,(setter)0,
	PyDoc_STR("*sequence*: Cumulative simple payback with expenses [$]"),
 	NULL},
{"cf_energy_net", (getter)Outputs_get_cf_energy_net,(setter)0,
	PyDoc_STR("*sequence*: Electricity net generation [kWh]"),
 	NULL},
{"cf_energy_purchases", (getter)Outputs_get_cf_energy_purchases,(setter)0,
	PyDoc_STR("*sequence*: Electricity from grid to system [kWh]"),
 	NULL},
{"cf_energy_sales", (getter)Outputs_get_cf_energy_sales,(setter)0,
	PyDoc_STR("*sequence*: Electricity generation [kWh]"),
 	NULL},
{"cf_length", (getter)Outputs_get_cf_length,(setter)0,
	PyDoc_STR("*float*: Agreement period"),
 	NULL},
{"cf_nte", (getter)Outputs_get_cf_nte,(setter)0,
	PyDoc_STR("*sequence*: Host indifference point by year [cents/kWh]"),
 	NULL},
{"cf_payback_with_expenses", (getter)Outputs_get_cf_payback_with_expenses,(setter)0,
	PyDoc_STR("*sequence*: Simple payback with expenses [$]"),
 	NULL},
{"lnte_nom", (getter)Outputs_get_lnte_nom,(setter)0,
	PyDoc_STR("*float*: Host indifference point real levelized value [cents/kWh]"),
 	NULL},
{"lnte_real", (getter)Outputs_get_lnte_real,(setter)0,
	PyDoc_STR("*float*: Host indifference point nominal levelized value [cents/kWh]"),
 	NULL},
{"npv", (getter)Outputs_get_npv,(setter)0,
	PyDoc_STR("*float*: NPV Net present value [$]"),
 	NULL},
{"year1_nte", (getter)Outputs_get_year1_nte,(setter)0,
	PyDoc_STR("*float*: Host indifference point in Year 1 [cents/kWh]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thirdpartyownership.Outputs",             /*tp_name*/
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
 * Thirdpartyownership
 */

static PyTypeObject Thirdpartyownership_Type;

static CmodObject *
newThirdpartyownershipObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Thirdpartyownership_Type);

	PySAM_TECH_ATTR()

	PyObject* Depreciation_obj = Depreciation_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Depreciation", Depreciation_obj);
	Py_DECREF(Depreciation_obj);

	PyObject* Financials_obj = Financials_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Financials", Financials_obj);
	Py_DECREF(Financials_obj);

	PyObject* FinancialThirdPartyOwnership_obj = FinancialThirdPartyOwnership_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FinancialThirdPartyOwnership", FinancialThirdPartyOwnership_obj);
	Py_DECREF(FinancialThirdPartyOwnership_obj);

	PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

	PyObject* AnnualOutput_obj = AnnualOutput_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "AnnualOutput", AnnualOutput_obj);
	Py_DECREF(AnnualOutput_obj);

	PyObject* CashFlow_obj = CashFlow_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "CashFlow", CashFlow_obj);
	Py_DECREF(CashFlow_obj);

	PyObject* ElectricityCost_obj = ElectricityCost_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ElectricityCost", ElectricityCost_obj);
	Py_DECREF(ElectricityCost_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Thirdpartyownership methods */

static void
Thirdpartyownership_dealloc(CmodObject *self)
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
Thirdpartyownership_get_data_ptr(CmodObject *self, PyObject *args)
{
	PyObject* ptr = PyLong_FromVoidPtr((void*)self->data_ptr);
	return ptr;
}


static PyObject *
Thirdpartyownership_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Thirdpartyownership_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Thirdpartyownership_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Thirdpartyownership"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Thirdpartyownership_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Thirdpartyownership"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Thirdpartyownership_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Thirdpartyownership_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Thirdpartyownership_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Thirdpartyownership_methods[] = {
		{"execute",           (PyCFunction)Thirdpartyownership_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Thirdpartyownership_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Depreciation': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Thirdpartyownership_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Depreciation': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Thirdpartyownership_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Thirdpartyownership_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Thirdpartyownership_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{"get_data_ptr",           (PyCFunction)Thirdpartyownership_get_data_ptr,  METH_VARARGS,
				PyDoc_STR("get_data_ptr() -> Pointer\n Get ssc_data_t pointer")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Thirdpartyownership_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Thirdpartyownership_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Thirdpartyownership_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thirdpartyownership",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Thirdpartyownership_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Thirdpartyownership_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Thirdpartyownership_getattro, /*tp_getattro*/
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
		Thirdpartyownership_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Thirdpartyownership object */

static PyObject *
Thirdpartyownership_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newThirdpartyownershipObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Thirdpartyownership_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newThirdpartyownershipObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Thirdpartyownership_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newThirdpartyownershipObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Thirdpartyownership", def) < 0) {
		Thirdpartyownership_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Thirdpartyownership_from_existing(PyObject *self, PyObject *args)
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

	rv = newThirdpartyownershipObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Thirdpartyownership", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef ThirdpartyownershipModule_methods[] = {
		{"new",             Thirdpartyownership_new,         METH_VARARGS,
				PyDoc_STR("new() -> Thirdpartyownership")},
		{"default",             Thirdpartyownership_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Thirdpartyownership\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"CustomGenerationBatteryThirdParty\"*\n\n		- *\"CustomGenerationProfileThirdParty\"*\n\n		- *\"FlatPlatePVThirdParty\"*\n\n		- *\"PVBatteryThirdParty\"*\n\n		- *\"PVWattsBatteryThirdParty\"*\n\n		- *\"PVWattsThirdParty\"*\n\n		- *\"StandaloneBatteryThirdParty\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Thirdpartyownership_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Thirdpartyownership\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Thirdpartyownership_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Thirdpartyownership\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Third party ownership with PPA or lease agreement financial model from host perspective");


static int
ThirdpartyownershipModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Thirdpartyownership_Type.tp_dict = PyDict_New();
	if (!Thirdpartyownership_Type.tp_dict) { goto fail; }

	/// Add the Depreciation type object to Thirdpartyownership_Type
	if (PyType_Ready(&Depreciation_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thirdpartyownership_Type.tp_dict,
				"Depreciation",
				(PyObject*)&Depreciation_Type);
	Py_DECREF(&Depreciation_Type);

	/// Add the Financials type object to Thirdpartyownership_Type
	if (PyType_Ready(&Financials_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thirdpartyownership_Type.tp_dict,
				"Financials",
				(PyObject*)&Financials_Type);
	Py_DECREF(&Financials_Type);

	/// Add the FinancialThirdPartyOwnership type object to Thirdpartyownership_Type
	if (PyType_Ready(&FinancialThirdPartyOwnership_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thirdpartyownership_Type.tp_dict,
				"FinancialThirdPartyOwnership",
				(PyObject*)&FinancialThirdPartyOwnership_Type);
	Py_DECREF(&FinancialThirdPartyOwnership_Type);

	/// Add the Common type object to Thirdpartyownership_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thirdpartyownership_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the AnnualOutput type object to Thirdpartyownership_Type
	if (PyType_Ready(&AnnualOutput_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thirdpartyownership_Type.tp_dict,
				"AnnualOutput",
				(PyObject*)&AnnualOutput_Type);
	Py_DECREF(&AnnualOutput_Type);

	/// Add the CashFlow type object to Thirdpartyownership_Type
	if (PyType_Ready(&CashFlow_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thirdpartyownership_Type.tp_dict,
				"CashFlow",
				(PyObject*)&CashFlow_Type);
	Py_DECREF(&CashFlow_Type);

	/// Add the ElectricityCost type object to Thirdpartyownership_Type
	if (PyType_Ready(&ElectricityCost_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thirdpartyownership_Type.tp_dict,
				"ElectricityCost",
				(PyObject*)&ElectricityCost_Type);
	Py_DECREF(&ElectricityCost_Type);

	/// Add the Outputs type object to Thirdpartyownership_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thirdpartyownership_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Thirdpartyownership type object to the module
	if (PyType_Ready(&Thirdpartyownership_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Thirdpartyownership",
				(PyObject*)&Thirdpartyownership_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot ThirdpartyownershipModule_slots[] = {
		{Py_mod_exec, ThirdpartyownershipModule_exec},
		{0, NULL},
};

static struct PyModuleDef ThirdpartyownershipModule = {
		PyModuleDef_HEAD_INIT,
		"Thirdpartyownership",
		module_doc,
		0,
		ThirdpartyownershipModule_methods,
		ThirdpartyownershipModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Thirdpartyownership(void)
{
	return PyModuleDef_Init(&ThirdpartyownershipModule);
}