#include <Python.h>

#include <SAM_ThermalrateIph.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * ThermalRate Group
 */ 

static PyTypeObject ThermalRate_Type;

static PyObject *
ThermalRate_new(SAM_ThermalrateIph data_ptr)
{
	PyObject* new_obj = ThermalRate_Type.tp_alloc(&ThermalRate_Type,0);

	VarGroupObject* ThermalRate_obj = (VarGroupObject*)new_obj;

	ThermalRate_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* ThermalRate methods */

static PyObject *
ThermalRate_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "ThermalrateIph", "ThermalRate")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ThermalRate_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &ThermalRate_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "ThermalrateIph", "ThermalRate")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ThermalRate_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &ThermalRate_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ThermalRate_methods[] = {
		{"assign",            (PyCFunction)ThermalRate_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``ThermalRate_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)ThermalRate_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``ThermalRate_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)ThermalRate_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ThermalRate_get_en_thermal_rates(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_ThermalrateIph_ThermalRate_en_thermal_rates_nget, self->data_ptr);
}

static int
ThermalRate_set_en_thermal_rates(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_ThermalrateIph_ThermalRate_en_thermal_rates_nset, self->data_ptr);
}

static PyObject *
ThermalRate_get_gen_heat(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_ThermalrateIph_ThermalRate_gen_heat_aget, self->data_ptr);
}

static int
ThermalRate_set_gen_heat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_ThermalrateIph_ThermalRate_gen_heat_aset, self->data_ptr);
}

static PyObject *
ThermalRate_get_thermal_buy_rate_flat_heat_btu(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_ThermalrateIph_ThermalRate_thermal_buy_rate_flat_heat_btu_nget, self->data_ptr);
}

static int
ThermalRate_set_thermal_buy_rate_flat_heat_btu(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_ThermalrateIph_ThermalRate_thermal_buy_rate_flat_heat_btu_nset, self->data_ptr);
}

static PyObject *
ThermalRate_get_thermal_buy_rate_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_ThermalrateIph_ThermalRate_thermal_buy_rate_option_nget, self->data_ptr);
}

static int
ThermalRate_set_thermal_buy_rate_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_ThermalrateIph_ThermalRate_thermal_buy_rate_option_nset, self->data_ptr);
}

static PyObject *
ThermalRate_get_thermal_conversion_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_ThermalrateIph_ThermalRate_thermal_conversion_efficiency_nget, self->data_ptr);
}

static int
ThermalRate_set_thermal_conversion_efficiency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_ThermalrateIph_ThermalRate_thermal_conversion_efficiency_nset, self->data_ptr);
}

static PyObject *
ThermalRate_get_thermal_degradation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_ThermalrateIph_ThermalRate_thermal_degradation_aget, self->data_ptr);
}

static int
ThermalRate_set_thermal_degradation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_ThermalrateIph_ThermalRate_thermal_degradation_aset, self->data_ptr);
}

static PyObject *
ThermalRate_get_thermal_load_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_ThermalrateIph_ThermalRate_thermal_load_escalation_aget, self->data_ptr);
}

static int
ThermalRate_set_thermal_load_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_ThermalrateIph_ThermalRate_thermal_load_escalation_aset, self->data_ptr);
}

static PyObject *
ThermalRate_get_thermal_load_heat_btu(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_ThermalrateIph_ThermalRate_thermal_load_heat_btu_aget, self->data_ptr);
}

static int
ThermalRate_set_thermal_load_heat_btu(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_ThermalrateIph_ThermalRate_thermal_load_heat_btu_aset, self->data_ptr);
}

static PyObject *
ThermalRate_get_thermal_monthly_buy_rate_heat_btu(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_ThermalrateIph_ThermalRate_thermal_monthly_buy_rate_heat_btu_aget, self->data_ptr);
}

static int
ThermalRate_set_thermal_monthly_buy_rate_heat_btu(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_ThermalrateIph_ThermalRate_thermal_monthly_buy_rate_heat_btu_aset, self->data_ptr);
}

static PyObject *
ThermalRate_get_thermal_monthly_sell_rate_heat_btu(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_ThermalrateIph_ThermalRate_thermal_monthly_sell_rate_heat_btu_aget, self->data_ptr);
}

static int
ThermalRate_set_thermal_monthly_sell_rate_heat_btu(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_ThermalrateIph_ThermalRate_thermal_monthly_sell_rate_heat_btu_aset, self->data_ptr);
}

static PyObject *
ThermalRate_get_thermal_rate_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_ThermalrateIph_ThermalRate_thermal_rate_escalation_aget, self->data_ptr);
}

static int
ThermalRate_set_thermal_rate_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_ThermalrateIph_ThermalRate_thermal_rate_escalation_aset, self->data_ptr);
}

static PyObject *
ThermalRate_get_thermal_sell_rate_flat_heat_btu(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_ThermalrateIph_ThermalRate_thermal_sell_rate_flat_heat_btu_nget, self->data_ptr);
}

static int
ThermalRate_set_thermal_sell_rate_flat_heat_btu(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_ThermalrateIph_ThermalRate_thermal_sell_rate_flat_heat_btu_nset, self->data_ptr);
}

static PyObject *
ThermalRate_get_thermal_sell_rate_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_ThermalrateIph_ThermalRate_thermal_sell_rate_option_nget, self->data_ptr);
}

static int
ThermalRate_set_thermal_sell_rate_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_ThermalrateIph_ThermalRate_thermal_sell_rate_option_nset, self->data_ptr);
}

static PyObject *
ThermalRate_get_thermal_timestep_buy_rate_heat_btu(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_ThermalrateIph_ThermalRate_thermal_timestep_buy_rate_heat_btu_aget, self->data_ptr);
}

static int
ThermalRate_set_thermal_timestep_buy_rate_heat_btu(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_ThermalrateIph_ThermalRate_thermal_timestep_buy_rate_heat_btu_aset, self->data_ptr);
}

static PyObject *
ThermalRate_get_thermal_timestep_sell_rate_heat_btu(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_ThermalrateIph_ThermalRate_thermal_timestep_sell_rate_heat_btu_aget, self->data_ptr);
}

static int
ThermalRate_set_thermal_timestep_sell_rate_heat_btu(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_ThermalrateIph_ThermalRate_thermal_timestep_sell_rate_heat_btu_aset, self->data_ptr);
}

static PyGetSetDef ThermalRate_getset[] = {
{"en_thermal_rates", (getter)ThermalRate_get_en_thermal_rates,(setter)ThermalRate_set_en_thermal_rates,
	PyDoc_STR("*float*: Optionally enable/disable thermal_rate [years]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1"),
 	NULL},
{"gen_heat", (getter)ThermalRate_get_gen_heat,(setter)ThermalRate_set_gen_heat,
	PyDoc_STR("*sequence*: Thermal power generated [kWt]\n\n**Required:**\nTrue"),
 	NULL},
{"thermal_buy_rate_flat_heat_btu", (getter)ThermalRate_get_thermal_buy_rate_flat_heat_btu,(setter)ThermalRate_set_thermal_buy_rate_flat_heat_btu,
	PyDoc_STR("*float*: Thermal buy rate flat [$/MMBtu]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"thermal_buy_rate_option", (getter)ThermalRate_get_thermal_buy_rate_option,(setter)ThermalRate_set_thermal_buy_rate_option,
	PyDoc_STR("*float*: Thermal buy rate option [0-2]\n\n**Options:**\n0=flat,1=timestep,2=monthly\n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"thermal_conversion_efficiency", (getter)ThermalRate_get_thermal_conversion_efficiency,(setter)ThermalRate_set_thermal_conversion_efficiency,
	PyDoc_STR("*float*: Heat conversion efficiency (buy) [%]\n\n**Required:**\nFalse. Automatically set to 100 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"thermal_degradation", (getter)ThermalRate_get_thermal_degradation,(setter)ThermalRate_set_thermal_degradation,
	PyDoc_STR("*sequence*: Annual energy degradation [%]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"thermal_load_escalation", (getter)ThermalRate_get_thermal_load_escalation,(setter)ThermalRate_set_thermal_load_escalation,
	PyDoc_STR("*sequence*: Annual load escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"thermal_load_heat_btu", (getter)ThermalRate_get_thermal_load_heat_btu,(setter)ThermalRate_set_thermal_load_heat_btu,
	PyDoc_STR("*sequence*: Thermal load (year 1) [MMBtu/hr]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"thermal_monthly_buy_rate_heat_btu", (getter)ThermalRate_get_thermal_monthly_buy_rate_heat_btu,(setter)ThermalRate_set_thermal_monthly_buy_rate_heat_btu,
	PyDoc_STR("*sequence*: Monthly thermal buy rate [$/MMBtu]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"thermal_monthly_sell_rate_heat_btu", (getter)ThermalRate_get_thermal_monthly_sell_rate_heat_btu,(setter)ThermalRate_set_thermal_monthly_sell_rate_heat_btu,
	PyDoc_STR("*sequence*: Thermal sell rate monthly [$/MMBtu]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"thermal_rate_escalation", (getter)ThermalRate_get_thermal_rate_escalation,(setter)ThermalRate_set_thermal_rate_escalation,
	PyDoc_STR("*sequence*: Annual thermal rate escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"thermal_sell_rate_flat_heat_btu", (getter)ThermalRate_get_thermal_sell_rate_flat_heat_btu,(setter)ThermalRate_set_thermal_sell_rate_flat_heat_btu,
	PyDoc_STR("*float*: Thermal sell rate flat [$/MMBtu]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"thermal_sell_rate_option", (getter)ThermalRate_get_thermal_sell_rate_option,(setter)ThermalRate_set_thermal_sell_rate_option,
	PyDoc_STR("*float*: Thermal sell rate option [0-2]\n\n**Options:**\n0=flat,1=timestep,2=monthly\n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"thermal_timestep_buy_rate_heat_btu", (getter)ThermalRate_get_thermal_timestep_buy_rate_heat_btu,(setter)ThermalRate_set_thermal_timestep_buy_rate_heat_btu,
	PyDoc_STR("*sequence*: Thermal buy rate [$/MMBtu]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"thermal_timestep_sell_rate_heat_btu", (getter)ThermalRate_get_thermal_timestep_sell_rate_heat_btu,(setter)ThermalRate_set_thermal_timestep_sell_rate_heat_btu,
	PyDoc_STR("*sequence*: Thermal sell rate timestep [$/MMBtu]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ThermalRate_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"ThermalrateIph.ThermalRate",             /*tp_name*/
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
		ThermalRate_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ThermalRate_getset,          /*tp_getset*/
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
 * Lifetime Group
 */ 

static PyTypeObject Lifetime_Type;

static PyObject *
Lifetime_new(SAM_ThermalrateIph data_ptr)
{
	PyObject* new_obj = Lifetime_Type.tp_alloc(&Lifetime_Type,0);

	VarGroupObject* Lifetime_obj = (VarGroupObject*)new_obj;

	Lifetime_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Lifetime methods */

static PyObject *
Lifetime_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "ThermalrateIph", "Lifetime")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Lifetime_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Lifetime_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "ThermalrateIph", "Lifetime")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Lifetime_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Lifetime_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Lifetime_methods[] = {
		{"assign",            (PyCFunction)Lifetime_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Lifetime_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Lifetime_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Lifetime_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Lifetime_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Lifetime_get_analysis_period(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_ThermalrateIph_Lifetime_analysis_period_nget, self->data_ptr);
}

static int
Lifetime_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_ThermalrateIph_Lifetime_analysis_period_nset, self->data_ptr);
}

static PyObject *
Lifetime_get_inflation_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_ThermalrateIph_Lifetime_inflation_rate_nget, self->data_ptr);
}

static int
Lifetime_set_inflation_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_ThermalrateIph_Lifetime_inflation_rate_nset, self->data_ptr);
}

static PyObject *
Lifetime_get_system_use_lifetime_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_ThermalrateIph_Lifetime_system_use_lifetime_output_nget, self->data_ptr);
}

static int
Lifetime_set_system_use_lifetime_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_ThermalrateIph_Lifetime_system_use_lifetime_output_nset, self->data_ptr);
}

static PyGetSetDef Lifetime_getset[] = {
{"analysis_period", (getter)Lifetime_get_analysis_period,(setter)Lifetime_set_analysis_period,
	PyDoc_STR("*float*: Number of years in analysis [years]\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"inflation_rate", (getter)Lifetime_get_inflation_rate,(setter)Lifetime_set_inflation_rate,
	PyDoc_STR("*float*: Inflation rate [%]\n\n**Constraints:**\nMIN=-99\n\n**Required:**\nTrue"),
 	NULL},
{"system_use_lifetime_output", (getter)Lifetime_get_system_use_lifetime_output,(setter)Lifetime_set_system_use_lifetime_output,
	PyDoc_STR("*float*: Lifetime hourly system outputs [0/1]\n\n**Options:**\n0=hourly first year,1=hourly lifetime\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Lifetime_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"ThermalrateIph.Lifetime",             /*tp_name*/
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
		Lifetime_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Lifetime_getset,          /*tp_getset*/
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
Outputs_new(SAM_ThermalrateIph data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "ThermalrateIph", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "ThermalrateIph", "Outputs")){
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
Outputs_get_annual_thermal_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_ThermalrateIph_Outputs_annual_thermal_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_thermal_cost_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_ThermalrateIph_Outputs_thermal_cost_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_thermal_cost_with_system_year1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_ThermalrateIph_Outputs_thermal_cost_with_system_year1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_thermal_cost_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_ThermalrateIph_Outputs_thermal_cost_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_thermal_cost_without_system_year1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_ThermalrateIph_Outputs_thermal_cost_without_system_year1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_thermal_load_year1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_ThermalrateIph_Outputs_thermal_load_year1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_thermal_revenue_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_ThermalrateIph_Outputs_thermal_revenue_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_thermal_revenue_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_ThermalrateIph_Outputs_thermal_revenue_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_thermal_savings_year1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_ThermalrateIph_Outputs_thermal_savings_year1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_load_heat(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_ThermalrateIph_Outputs_year1_monthly_load_heat_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_thermal_value", (getter)Outputs_get_annual_thermal_value,(setter)0,
	PyDoc_STR("*sequence*: Thermal value [$]"),
 	NULL},
{"thermal_cost_with_system", (getter)Outputs_get_thermal_cost_with_system,(setter)0,
	PyDoc_STR("*sequence*: Thermal cost with system [$]"),
 	NULL},
{"thermal_cost_with_system_year1", (getter)Outputs_get_thermal_cost_with_system_year1,(setter)0,
	PyDoc_STR("*float*: Thermal cost with sytem (year 1) [$]"),
 	NULL},
{"thermal_cost_without_system", (getter)Outputs_get_thermal_cost_without_system,(setter)0,
	PyDoc_STR("*sequence*: Thermal cost without system [$]"),
 	NULL},
{"thermal_cost_without_system_year1", (getter)Outputs_get_thermal_cost_without_system_year1,(setter)0,
	PyDoc_STR("*float*: Thermal cost without system (year 1) [$]"),
 	NULL},
{"thermal_load_year1", (getter)Outputs_get_thermal_load_year1,(setter)0,
	PyDoc_STR("*float*: Thermal load total [MMBtu/hr]"),
 	NULL},
{"thermal_revenue_with_system", (getter)Outputs_get_thermal_revenue_with_system,(setter)0,
	PyDoc_STR("*sequence*: Thermal revenue with system [$]"),
 	NULL},
{"thermal_revenue_without_system", (getter)Outputs_get_thermal_revenue_without_system,(setter)0,
	PyDoc_STR("*sequence*: Thermal revenue without system [$]"),
 	NULL},
{"thermal_savings_year1", (getter)Outputs_get_thermal_savings_year1,(setter)0,
	PyDoc_STR("*float*: Thermal savings (year 1) [$]"),
 	NULL},
{"year1_monthly_load_heat", (getter)Outputs_get_year1_monthly_load_heat,(setter)0,
	PyDoc_STR("*sequence*: Thermal load [kWht/mo]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"ThermalrateIph.Outputs",             /*tp_name*/
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
 * ThermalrateIph
 */

static PyTypeObject ThermalrateIph_Type;

static CmodObject *
newThermalrateIphObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &ThermalrateIph_Type);

	PySAM_TECH_ATTR()

	PyObject* ThermalRate_obj = ThermalRate_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ThermalRate", ThermalRate_obj);
	Py_DECREF(ThermalRate_obj);

	PyObject* Lifetime_obj = Lifetime_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Lifetime", Lifetime_obj);
	Py_DECREF(Lifetime_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* ThermalrateIph methods */

static void
ThermalrateIph_dealloc(CmodObject *self)
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
ThermalrateIph_get_data_ptr(CmodObject *self, PyObject *args)
{
	PyObject* ptr = PyLong_FromVoidPtr((void*)self->data_ptr);
	return ptr;
}


static PyObject *
ThermalrateIph_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_ThermalrateIph_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
ThermalrateIph_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "ThermalrateIph"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ThermalrateIph_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "ThermalrateIph"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ThermalrateIph_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
ThermalrateIph_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
ThermalrateIph_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef ThermalrateIph_methods[] = {
		{"execute",           (PyCFunction)ThermalrateIph_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)ThermalrateIph_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Thermal Rate': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)ThermalrateIph_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Thermal Rate': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)ThermalrateIph_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)ThermalrateIph_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)ThermalrateIph_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{"get_data_ptr",           (PyCFunction)ThermalrateIph_get_data_ptr,  METH_VARARGS,
				PyDoc_STR("get_data_ptr() -> Pointer\n Get ssc_data_t pointer")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ThermalrateIph_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
ThermalrateIph_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject ThermalrateIph_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"ThermalrateIph",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)ThermalrateIph_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)ThermalrateIph_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)ThermalrateIph_getattro, /*tp_getattro*/
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
		ThermalrateIph_methods,      /*tp_methods*/
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


/* Function of no arguments returning new ThermalrateIph object */

static PyObject *
ThermalrateIph_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newThermalrateIphObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
ThermalrateIph_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newThermalrateIphObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
ThermalrateIph_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newThermalrateIphObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "ThermalrateIph", def) < 0) {
		ThermalrateIph_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
ThermalrateIph_from_existing(PyObject *self, PyObject *args)
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

	rv = newThermalrateIphObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "ThermalrateIph", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef ThermalrateIphModule_methods[] = {
		{"new",             ThermalrateIph_new,         METH_VARARGS,
				PyDoc_STR("new() -> ThermalrateIph")},
		{"default",             ThermalrateIph_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> ThermalrateIph\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"MSLFIPHCommercial\"*\n\n		- *\"PhysicalTroughIPHCommercial\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             ThermalrateIph_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> ThermalrateIph\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   ThermalrateIph_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> ThermalrateIph\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "ThermalrateIph");


static int
ThermalrateIphModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	ThermalrateIph_Type.tp_dict = PyDict_New();
	if (!ThermalrateIph_Type.tp_dict) { goto fail; }

	/// Add the ThermalRate type object to ThermalrateIph_Type
	if (PyType_Ready(&ThermalRate_Type) < 0) { goto fail; }
	PyDict_SetItemString(ThermalrateIph_Type.tp_dict,
				"ThermalRate",
				(PyObject*)&ThermalRate_Type);
	Py_DECREF(&ThermalRate_Type);

	/// Add the Lifetime type object to ThermalrateIph_Type
	if (PyType_Ready(&Lifetime_Type) < 0) { goto fail; }
	PyDict_SetItemString(ThermalrateIph_Type.tp_dict,
				"Lifetime",
				(PyObject*)&Lifetime_Type);
	Py_DECREF(&Lifetime_Type);

	/// Add the Outputs type object to ThermalrateIph_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(ThermalrateIph_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the ThermalrateIph type object to the module
	if (PyType_Ready(&ThermalrateIph_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"ThermalrateIph",
				(PyObject*)&ThermalrateIph_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot ThermalrateIphModule_slots[] = {
		{Py_mod_exec, ThermalrateIphModule_exec},
		{0, NULL},
};

static struct PyModuleDef ThermalrateIphModule = {
		PyModuleDef_HEAD_INIT,
		"ThermalrateIph",
		module_doc,
		0,
		ThermalrateIphModule_methods,
		ThermalrateIphModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_ThermalrateIph(void)
{
	return PyModuleDef_Init(&ThermalrateIphModule);
}