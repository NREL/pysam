#include <Python.h>

#include <SAM_LcoefcrDesign.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * SystemControl Group
 */ 

static PyTypeObject SystemControl_Type;

static PyObject *
SystemControl_new(SAM_LcoefcrDesign data_ptr)
{
	PyObject* new_obj = SystemControl_Type.tp_alloc(&SystemControl_Type,0);

	VarGroupObject* SystemControl_obj = (VarGroupObject*)new_obj;

	SystemControl_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SystemControl methods */

static PyObject *
SystemControl_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "LcoefcrDesign", "SystemControl")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemControl_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SystemControl_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "LcoefcrDesign", "SystemControl")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemControl_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SystemControl_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SystemControl_methods[] = {
		{"assign",            (PyCFunction)SystemControl_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SystemControl_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SystemControl_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SystemControl_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SystemControl_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemControl_get_sim_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_SystemControl_sim_type_nget, self->data_ptr);
}

static int
SystemControl_set_sim_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LcoefcrDesign_SystemControl_sim_type_nset, self->data_ptr);
}

static PyGetSetDef SystemControl_getset[] = {
{"sim_type", (getter)SystemControl_get_sim_type,(setter)SystemControl_set_sim_type,
	PyDoc_STR("*float*: 1 (default): timeseries, 2: design only\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemControl_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"LcoefcrDesign.SystemControl",             /*tp_name*/
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
		SystemControl_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SystemControl_getset,          /*tp_getset*/
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
 * SimpleLCOE Group
 */ 

static PyTypeObject SimpleLCOE_Type;

static PyObject *
SimpleLCOE_new(SAM_LcoefcrDesign data_ptr)
{
	PyObject* new_obj = SimpleLCOE_Type.tp_alloc(&SimpleLCOE_Type,0);

	VarGroupObject* SimpleLCOE_obj = (VarGroupObject*)new_obj;

	SimpleLCOE_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SimpleLCOE methods */

static PyObject *
SimpleLCOE_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "LcoefcrDesign", "SimpleLCOE")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SimpleLCOE_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SimpleLCOE_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "LcoefcrDesign", "SimpleLCOE")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SimpleLCOE_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SimpleLCOE_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SimpleLCOE_methods[] = {
		{"assign",            (PyCFunction)SimpleLCOE_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SimpleLCOE_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SimpleLCOE_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SimpleLCOE_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SimpleLCOE_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SimpleLCOE_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_SimpleLCOE_annual_energy_nget, self->data_ptr);
}

static int
SimpleLCOE_set_annual_energy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LcoefcrDesign_SimpleLCOE_annual_energy_nset, self->data_ptr);
}

static PyObject *
SimpleLCOE_get_c_construction_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LcoefcrDesign_SimpleLCOE_c_construction_cost_aget, self->data_ptr);
}

static int
SimpleLCOE_set_c_construction_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_LcoefcrDesign_SimpleLCOE_c_construction_cost_aset, self->data_ptr);
}

static PyObject *
SimpleLCOE_get_c_construction_interest(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_SimpleLCOE_c_construction_interest_nget, self->data_ptr);
}

static int
SimpleLCOE_set_c_construction_interest(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LcoefcrDesign_SimpleLCOE_c_construction_interest_nset, self->data_ptr);
}

static PyObject *
SimpleLCOE_get_c_debt_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_SimpleLCOE_c_debt_percent_nget, self->data_ptr);
}

static int
SimpleLCOE_set_c_debt_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LcoefcrDesign_SimpleLCOE_c_debt_percent_nset, self->data_ptr);
}

static PyObject *
SimpleLCOE_get_c_depreciation_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LcoefcrDesign_SimpleLCOE_c_depreciation_schedule_aget, self->data_ptr);
}

static int
SimpleLCOE_set_c_depreciation_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_LcoefcrDesign_SimpleLCOE_c_depreciation_schedule_aset, self->data_ptr);
}

static PyObject *
SimpleLCOE_get_c_equity_return(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_SimpleLCOE_c_equity_return_nget, self->data_ptr);
}

static int
SimpleLCOE_set_c_equity_return(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LcoefcrDesign_SimpleLCOE_c_equity_return_nset, self->data_ptr);
}

static PyObject *
SimpleLCOE_get_c_inflation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_SimpleLCOE_c_inflation_nget, self->data_ptr);
}

static int
SimpleLCOE_set_c_inflation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LcoefcrDesign_SimpleLCOE_c_inflation_nset, self->data_ptr);
}

static PyObject *
SimpleLCOE_get_c_lifetime(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_SimpleLCOE_c_lifetime_nget, self->data_ptr);
}

static int
SimpleLCOE_set_c_lifetime(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LcoefcrDesign_SimpleLCOE_c_lifetime_nset, self->data_ptr);
}

static PyObject *
SimpleLCOE_get_c_nominal_interest_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_SimpleLCOE_c_nominal_interest_rate_nget, self->data_ptr);
}

static int
SimpleLCOE_set_c_nominal_interest_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LcoefcrDesign_SimpleLCOE_c_nominal_interest_rate_nset, self->data_ptr);
}

static PyObject *
SimpleLCOE_get_c_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_SimpleLCOE_c_tax_rate_nget, self->data_ptr);
}

static int
SimpleLCOE_set_c_tax_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LcoefcrDesign_SimpleLCOE_c_tax_rate_nset, self->data_ptr);
}

static PyObject *
SimpleLCOE_get_fixed_operating_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_SimpleLCOE_fixed_operating_cost_nget, self->data_ptr);
}

static int
SimpleLCOE_set_fixed_operating_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LcoefcrDesign_SimpleLCOE_fixed_operating_cost_nset, self->data_ptr);
}

static PyObject *
SimpleLCOE_get_ui_fcr_input_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_SimpleLCOE_ui_fcr_input_option_nget, self->data_ptr);
}

static int
SimpleLCOE_set_ui_fcr_input_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LcoefcrDesign_SimpleLCOE_ui_fcr_input_option_nset, self->data_ptr);
}

static PyObject *
SimpleLCOE_get_ui_fixed_charge_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_SimpleLCOE_ui_fixed_charge_rate_nget, self->data_ptr);
}

static int
SimpleLCOE_set_ui_fixed_charge_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LcoefcrDesign_SimpleLCOE_ui_fixed_charge_rate_nset, self->data_ptr);
}

static PyObject *
SimpleLCOE_get_variable_operating_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_SimpleLCOE_variable_operating_cost_nget, self->data_ptr);
}

static int
SimpleLCOE_set_variable_operating_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LcoefcrDesign_SimpleLCOE_variable_operating_cost_nset, self->data_ptr);
}

static PyGetSetDef SimpleLCOE_getset[] = {
{"annual_energy", (getter)SimpleLCOE_get_annual_energy,(setter)SimpleLCOE_set_annual_energy,
	PyDoc_STR("*float*: Annual energy production [kWh]\n\n**Required:**\nRequired if sim_type=1"),
 	NULL},
{"c_construction_cost", (getter)SimpleLCOE_get_c_construction_cost,(setter)SimpleLCOE_set_c_construction_cost,
	PyDoc_STR("*sequence*: Construction cost schedule [%]\n\n**Required:**\nRequired if ui_fcr_input_option=1"),
 	NULL},
{"c_construction_interest", (getter)SimpleLCOE_get_c_construction_interest,(setter)SimpleLCOE_set_c_construction_interest,
	PyDoc_STR("*float*: Nominal construction interest rate [%]\n\n**Required:**\nRequired if ui_fcr_input_option=1"),
 	NULL},
{"c_debt_percent", (getter)SimpleLCOE_get_c_debt_percent,(setter)SimpleLCOE_set_c_debt_percent,
	PyDoc_STR("*float*: Project term debt (% of capital) [%]\n\n**Required:**\nRequired if ui_fcr_input_option=1"),
 	NULL},
{"c_depreciation_schedule", (getter)SimpleLCOE_get_c_depreciation_schedule,(setter)SimpleLCOE_set_c_depreciation_schedule,
	PyDoc_STR("*sequence*: Depreciation schedule [%]\n\n**Required:**\nRequired if ui_fcr_input_option=1"),
 	NULL},
{"c_equity_return", (getter)SimpleLCOE_get_c_equity_return,(setter)SimpleLCOE_set_c_equity_return,
	PyDoc_STR("*float*: IRR (nominal) [%]\n\n**Required:**\nRequired if ui_fcr_input_option=1"),
 	NULL},
{"c_inflation", (getter)SimpleLCOE_get_c_inflation,(setter)SimpleLCOE_set_c_inflation,
	PyDoc_STR("*float*: Input fixed charge rate [%]\n\n**Required:**\nRequired if ui_fcr_input_option=1"),
 	NULL},
{"c_lifetime", (getter)SimpleLCOE_get_c_lifetime,(setter)SimpleLCOE_set_c_lifetime,
	PyDoc_STR("*float*: Analysis period [years]\n\n**Required:**\nRequired if ui_fcr_input_option=1"),
 	NULL},
{"c_nominal_interest_rate", (getter)SimpleLCOE_get_c_nominal_interest_rate,(setter)SimpleLCOE_set_c_nominal_interest_rate,
	PyDoc_STR("*float*: Nominal debt interest rate [%]\n\n**Required:**\nRequired if ui_fcr_input_option=1"),
 	NULL},
{"c_tax_rate", (getter)SimpleLCOE_get_c_tax_rate,(setter)SimpleLCOE_set_c_tax_rate,
	PyDoc_STR("*float*: Effective tax rate [%]\n\n**Required:**\nRequired if ui_fcr_input_option=1"),
 	NULL},
{"fixed_operating_cost", (getter)SimpleLCOE_get_fixed_operating_cost,(setter)SimpleLCOE_set_fixed_operating_cost,
	PyDoc_STR("*float*: Annual fixed operating cost [$]\n\n**Required:**\nRequired if sim_type=1"),
 	NULL},
{"ui_fcr_input_option", (getter)SimpleLCOE_get_ui_fcr_input_option,(setter)SimpleLCOE_set_ui_fcr_input_option,
	PyDoc_STR("*float*: 0: fixed charge rate; 1: calculate\n\n**Required:**\nTrue"),
 	NULL},
{"ui_fixed_charge_rate", (getter)SimpleLCOE_get_ui_fixed_charge_rate,(setter)SimpleLCOE_set_ui_fixed_charge_rate,
	PyDoc_STR("*float*: Input fixed charge rate\n\n**Required:**\nRequired if ui_fcr_input_option=0"),
 	NULL},
{"variable_operating_cost", (getter)SimpleLCOE_get_variable_operating_cost,(setter)SimpleLCOE_set_variable_operating_cost,
	PyDoc_STR("*float*: Annual variable operating cost [$/kWh]\n\n**Required:**\nRequired if sim_type=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SimpleLCOE_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"LcoefcrDesign.SimpleLCOE",             /*tp_name*/
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
		SimpleLCOE_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SimpleLCOE_getset,          /*tp_getset*/
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
 * SystemCosts Group
 */ 

static PyTypeObject SystemCosts_Type;

static PyObject *
SystemCosts_new(SAM_LcoefcrDesign data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "LcoefcrDesign", "SystemCosts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemCosts_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SystemCosts_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "LcoefcrDesign", "SystemCosts")){
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
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SystemCosts_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SystemCosts_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SystemCosts_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SystemCosts_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemCosts_get_total_installed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_SystemCosts_total_installed_cost_nget, self->data_ptr);
}

static int
SystemCosts_set_total_installed_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LcoefcrDesign_SystemCosts_total_installed_cost_nset, self->data_ptr);
}

static PyGetSetDef SystemCosts_getset[] = {
{"total_installed_cost", (getter)SystemCosts_get_total_installed_cost,(setter)SystemCosts_set_total_installed_cost,
	PyDoc_STR("*float*: Total installed cost [$]\n\n**Required:**\nRequired if sim_type=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"LcoefcrDesign.SystemCosts",             /*tp_name*/
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
 * IPHLCOH Group
 */ 

static PyTypeObject IPHLCOH_Type;

static PyObject *
IPHLCOH_new(SAM_LcoefcrDesign data_ptr)
{
	PyObject* new_obj = IPHLCOH_Type.tp_alloc(&IPHLCOH_Type,0);

	VarGroupObject* IPHLCOH_obj = (VarGroupObject*)new_obj;

	IPHLCOH_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* IPHLCOH methods */

static PyObject *
IPHLCOH_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "LcoefcrDesign", "IPHLCOH")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
IPHLCOH_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &IPHLCOH_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "LcoefcrDesign", "IPHLCOH")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
IPHLCOH_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &IPHLCOH_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef IPHLCOH_methods[] = {
		{"assign",            (PyCFunction)IPHLCOH_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``IPHLCOH_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)IPHLCOH_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``IPHLCOH_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)IPHLCOH_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
IPHLCOH_get_annual_electricity_consumption(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_IPHLCOH_annual_electricity_consumption_nget, self->data_ptr);
}

static int
IPHLCOH_set_annual_electricity_consumption(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LcoefcrDesign_IPHLCOH_annual_electricity_consumption_nset, self->data_ptr);
}

static PyObject *
IPHLCOH_get_electricity_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_IPHLCOH_electricity_rate_nget, self->data_ptr);
}

static int
IPHLCOH_set_electricity_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LcoefcrDesign_IPHLCOH_electricity_rate_nset, self->data_ptr);
}

static PyGetSetDef IPHLCOH_getset[] = {
{"annual_electricity_consumption", (getter)IPHLCOH_get_annual_electricity_consumption,(setter)IPHLCOH_set_annual_electricity_consumption,
	PyDoc_STR("*float*: Annual electricity consumption with avail derate [kWe-hr]\n\n**Required:**\nRequired if sim_type=1"),
 	NULL},
{"electricity_rate", (getter)IPHLCOH_get_electricity_rate,(setter)IPHLCOH_set_electricity_rate,
	PyDoc_STR("*float*: Cost of electricity used to operate pumps and trackers [$/kWe-hr]\n\n**Required:**\nRequired if sim_type=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject IPHLCOH_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"LcoefcrDesign.IPHLCOH",             /*tp_name*/
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
		IPHLCOH_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		IPHLCOH_getset,          /*tp_getset*/
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
Outputs_new(SAM_LcoefcrDesign data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "LcoefcrDesign", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "LcoefcrDesign", "Outputs")){
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
Outputs_get_cfin(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_Outputs_cfin_nget, self->data_ptr);
}

static PyObject *
Outputs_get_crf(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_Outputs_crf_nget, self->data_ptr);
}

static PyObject *
Outputs_get_fixed_charge_rate_calc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_Outputs_fixed_charge_rate_calc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoe_fcr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_Outputs_lcoe_fcr_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pfin(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_Outputs_pfin_nget, self->data_ptr);
}

static PyObject *
Outputs_get_wacc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LcoefcrDesign_Outputs_wacc_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"cfin", (getter)Outputs_get_cfin,(setter)0,
	PyDoc_STR("*float*: Construction financing factor"),
 	NULL},
{"crf", (getter)Outputs_get_crf,(setter)0,
	PyDoc_STR("*float*: Capital recovery factor"),
 	NULL},
{"fixed_charge_rate_calc", (getter)Outputs_get_fixed_charge_rate_calc,(setter)0,
	PyDoc_STR("*float*: Calculated fixed charge rate"),
 	NULL},
{"lcoe_fcr", (getter)Outputs_get_lcoe_fcr,(setter)0,
	PyDoc_STR("*float*: LCOE Levelized cost of energy [$/kWh]"),
 	NULL},
{"pfin", (getter)Outputs_get_pfin,(setter)0,
	PyDoc_STR("*float*: Project financing factor"),
 	NULL},
{"wacc", (getter)Outputs_get_wacc,(setter)0,
	PyDoc_STR("*float*: WACC"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"LcoefcrDesign.Outputs",             /*tp_name*/
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
 * LcoefcrDesign
 */

static PyTypeObject LcoefcrDesign_Type;

static CmodObject *
newLcoefcrDesignObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &LcoefcrDesign_Type);

	PySAM_TECH_ATTR()

	PyObject* SystemControl_obj = SystemControl_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemControl", SystemControl_obj);
	Py_DECREF(SystemControl_obj);

	PyObject* SimpleLCOE_obj = SimpleLCOE_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SimpleLCOE", SimpleLCOE_obj);
	Py_DECREF(SimpleLCOE_obj);

	PyObject* SystemCosts_obj = SystemCosts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemCosts", SystemCosts_obj);
	Py_DECREF(SystemCosts_obj);

	PyObject* IPHLCOH_obj = IPHLCOH_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "IPHLCOH", IPHLCOH_obj);
	Py_DECREF(IPHLCOH_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* LcoefcrDesign methods */

static void
LcoefcrDesign_dealloc(CmodObject *self)
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
LcoefcrDesign_get_data_ptr(CmodObject *self, PyObject *args)
{
	PyObject* ptr = PyLong_FromVoidPtr((void*)self->data_ptr);
	return ptr;
}


static PyObject *
LcoefcrDesign_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_LcoefcrDesign_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
LcoefcrDesign_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "LcoefcrDesign"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
LcoefcrDesign_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "LcoefcrDesign"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
LcoefcrDesign_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
LcoefcrDesign_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
LcoefcrDesign_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef LcoefcrDesign_methods[] = {
		{"execute",           (PyCFunction)LcoefcrDesign_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)LcoefcrDesign_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'System Control': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)LcoefcrDesign_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'System Control': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)LcoefcrDesign_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)LcoefcrDesign_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)LcoefcrDesign_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{"get_data_ptr",           (PyCFunction)LcoefcrDesign_get_data_ptr,  METH_VARARGS,
				PyDoc_STR("get_data_ptr() -> Pointer\n Get ssc_data_t pointer")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
LcoefcrDesign_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
LcoefcrDesign_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject LcoefcrDesign_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"LcoefcrDesign",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)LcoefcrDesign_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)LcoefcrDesign_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)LcoefcrDesign_getattro, /*tp_getattro*/
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
		LcoefcrDesign_methods,      /*tp_methods*/
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


/* Function of no arguments returning new LcoefcrDesign object */

static PyObject *
LcoefcrDesign_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newLcoefcrDesignObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
LcoefcrDesign_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newLcoefcrDesignObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
LcoefcrDesign_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newLcoefcrDesignObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "LcoefcrDesign", def) < 0) {
		LcoefcrDesign_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
LcoefcrDesign_from_existing(PyObject *self, PyObject *args)
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

	rv = newLcoefcrDesignObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "LcoefcrDesign", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef LcoefcrDesignModule_methods[] = {
		{"new",             LcoefcrDesign_new,         METH_VARARGS,
				PyDoc_STR("new() -> LcoefcrDesign")},
		{"default",             LcoefcrDesign_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> LcoefcrDesign\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"MSLFIPHLCOHCalculator\"*\n\n		- *\"MSPTIPHLCOHCalculator\"*\n\n		- *\"PhysicalTroughIPHLCOHCalculator\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             LcoefcrDesign_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> LcoefcrDesign\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   LcoefcrDesign_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> LcoefcrDesign\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "LcoefcrDesign");


static int
LcoefcrDesignModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	LcoefcrDesign_Type.tp_dict = PyDict_New();
	if (!LcoefcrDesign_Type.tp_dict) { goto fail; }

	/// Add the SystemControl type object to LcoefcrDesign_Type
	if (PyType_Ready(&SystemControl_Type) < 0) { goto fail; }
	PyDict_SetItemString(LcoefcrDesign_Type.tp_dict,
				"SystemControl",
				(PyObject*)&SystemControl_Type);
	Py_DECREF(&SystemControl_Type);

	/// Add the SimpleLCOE type object to LcoefcrDesign_Type
	if (PyType_Ready(&SimpleLCOE_Type) < 0) { goto fail; }
	PyDict_SetItemString(LcoefcrDesign_Type.tp_dict,
				"SimpleLCOE",
				(PyObject*)&SimpleLCOE_Type);
	Py_DECREF(&SimpleLCOE_Type);

	/// Add the SystemCosts type object to LcoefcrDesign_Type
	if (PyType_Ready(&SystemCosts_Type) < 0) { goto fail; }
	PyDict_SetItemString(LcoefcrDesign_Type.tp_dict,
				"SystemCosts",
				(PyObject*)&SystemCosts_Type);
	Py_DECREF(&SystemCosts_Type);

	/// Add the IPHLCOH type object to LcoefcrDesign_Type
	if (PyType_Ready(&IPHLCOH_Type) < 0) { goto fail; }
	PyDict_SetItemString(LcoefcrDesign_Type.tp_dict,
				"IPHLCOH",
				(PyObject*)&IPHLCOH_Type);
	Py_DECREF(&IPHLCOH_Type);

	/// Add the Outputs type object to LcoefcrDesign_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(LcoefcrDesign_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the LcoefcrDesign type object to the module
	if (PyType_Ready(&LcoefcrDesign_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"LcoefcrDesign",
				(PyObject*)&LcoefcrDesign_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot LcoefcrDesignModule_slots[] = {
		{Py_mod_exec, LcoefcrDesignModule_exec},
		{0, NULL},
};

static struct PyModuleDef LcoefcrDesignModule = {
		PyModuleDef_HEAD_INIT,
		"LcoefcrDesign",
		module_doc,
		0,
		LcoefcrDesignModule_methods,
		LcoefcrDesignModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_LcoefcrDesign(void)
{
	return PyModuleDef_Init(&LcoefcrDesignModule);
}