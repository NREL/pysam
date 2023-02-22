#include <Python.h>

#include <SAM_Utilityrate4.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Common Group
 */ 

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_Utilityrate4 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate4", "Common")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Utilityrate4", "Common")){
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
	return PySAM_double_getter(SAM_Utilityrate4_Common_analysis_period_nget, self->data_ptr);
}

static int
Common_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate4_Common_analysis_period_nset, self->data_ptr);
}

static PyObject *
Common_get_load_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Common_load_escalation_aget, self->data_ptr);
}

static int
Common_set_load_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate4_Common_load_escalation_aset, self->data_ptr);
}

static PyObject *
Common_get_rate_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Common_rate_escalation_aget, self->data_ptr);
}

static int
Common_set_rate_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate4_Common_rate_escalation_aset, self->data_ptr);
}

static PyObject *
Common_get_system_use_lifetime_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate4_Common_system_use_lifetime_output_nget, self->data_ptr);
}

static int
Common_set_system_use_lifetime_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate4_Common_system_use_lifetime_output_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_annual_min_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate4_Common_ur_annual_min_charge_nget, self->data_ptr);
}

static int
Common_set_ur_annual_min_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate4_Common_ur_annual_min_charge_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate4_Common_ur_dc_enable_nget, self->data_ptr);
}

static int
Common_set_ur_dc_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate4_Common_ur_dc_enable_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_flat_mat(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Common_ur_dc_flat_mat_mget, self->data_ptr);
}

static int
Common_set_ur_dc_flat_mat(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate4_Common_ur_dc_flat_mat_mset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Common_ur_dc_sched_weekday_mget, self->data_ptr);
}

static int
Common_set_ur_dc_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate4_Common_ur_dc_sched_weekday_mset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Common_ur_dc_sched_weekend_mget, self->data_ptr);
}

static int
Common_set_ur_dc_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate4_Common_ur_dc_sched_weekend_mset, self->data_ptr);
}

static PyObject *
Common_get_ur_dc_tou_mat(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Common_ur_dc_tou_mat_mget, self->data_ptr);
}

static int
Common_set_ur_dc_tou_mat(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate4_Common_ur_dc_tou_mat_mset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Common_ur_ec_sched_weekday_mget, self->data_ptr);
}

static int
Common_set_ur_ec_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate4_Common_ur_ec_sched_weekday_mset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Common_ur_ec_sched_weekend_mget, self->data_ptr);
}

static int
Common_set_ur_ec_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate4_Common_ur_ec_sched_weekend_mset, self->data_ptr);
}

static PyObject *
Common_get_ur_ec_tou_mat(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Common_ur_ec_tou_mat_mget, self->data_ptr);
}

static int
Common_set_ur_ec_tou_mat(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate4_Common_ur_ec_tou_mat_mset, self->data_ptr);
}

static PyObject *
Common_get_ur_metering_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate4_Common_ur_metering_option_nget, self->data_ptr);
}

static int
Common_set_ur_metering_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate4_Common_ur_metering_option_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_monthly_fixed_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate4_Common_ur_monthly_fixed_charge_nget, self->data_ptr);
}

static int
Common_set_ur_monthly_fixed_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate4_Common_ur_monthly_fixed_charge_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_monthly_min_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate4_Common_ur_monthly_min_charge_nget, self->data_ptr);
}

static int
Common_set_ur_monthly_min_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate4_Common_ur_monthly_min_charge_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_nm_yearend_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate4_Common_ur_nm_yearend_sell_rate_nget, self->data_ptr);
}

static int
Common_set_ur_nm_yearend_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate4_Common_ur_nm_yearend_sell_rate_nset, self->data_ptr);
}

static PyObject *
Common_get_ur_sell_eq_buy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate4_Common_ur_sell_eq_buy_nget, self->data_ptr);
}

static int
Common_set_ur_sell_eq_buy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate4_Common_ur_sell_eq_buy_nset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"analysis_period", (getter)Common_get_analysis_period,(setter)Common_set_analysis_period,
	PyDoc_STR("*float*: Number of years in analysis [years]\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"load_escalation", (getter)Common_get_load_escalation,(setter)Common_set_load_escalation,
	PyDoc_STR("*sequence*: Annual load escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"rate_escalation", (getter)Common_get_rate_escalation,(setter)Common_set_rate_escalation,
	PyDoc_STR("*sequence*: Annual electricity rate escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"system_use_lifetime_output", (getter)Common_get_system_use_lifetime_output,(setter)Common_set_system_use_lifetime_output,
	PyDoc_STR("*float*: Lifetime hourly system outputs [0/1]\n\n**Options:**\n0=hourly first year,1=hourly lifetime\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nTrue"),
 	NULL},
{"ur_annual_min_charge", (getter)Common_get_ur_annual_min_charge,(setter)Common_set_ur_annual_min_charge,
	PyDoc_STR("*float*: Annual minimum charge [$]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_enable", (getter)Common_get_ur_dc_enable,(setter)Common_set_ur_dc_enable,
	PyDoc_STR("*float*: Enable demand charge [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_flat_mat", (getter)Common_get_ur_dc_flat_mat,(setter)Common_set_ur_dc_flat_mat,
	PyDoc_STR("*sequence[sequence]*: Demand rates (flat) table\n\n**Required:**\nRequired if ur_dc_enable=1"),
 	NULL},
{"ur_dc_sched_weekday", (getter)Common_get_ur_dc_sched_weekday,(setter)Common_set_ur_dc_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: Demand charge weekday schedule\n\n**Info:**\n12x24"),
 	NULL},
{"ur_dc_sched_weekend", (getter)Common_get_ur_dc_sched_weekend,(setter)Common_set_ur_dc_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Demand charge weekend schedule\n\n**Info:**\n12x24"),
 	NULL},
{"ur_dc_tou_mat", (getter)Common_get_ur_dc_tou_mat,(setter)Common_set_ur_dc_tou_mat,
	PyDoc_STR("*sequence[sequence]*: Demand rates (TOU) table\n\n**Required:**\nRequired if ur_dc_enable=1"),
 	NULL},
{"ur_ec_sched_weekday", (getter)Common_get_ur_ec_sched_weekday,(setter)Common_set_ur_ec_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: Energy charge weekday schedule\n\n**Info:**\n12x24\n\n**Required:**\nTrue"),
 	NULL},
{"ur_ec_sched_weekend", (getter)Common_get_ur_ec_sched_weekend,(setter)Common_set_ur_ec_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Energy charge weekend schedule\n\n**Info:**\n12x24\n\n**Required:**\nTrue"),
 	NULL},
{"ur_ec_tou_mat", (getter)Common_get_ur_ec_tou_mat,(setter)Common_set_ur_ec_tou_mat,
	PyDoc_STR("*sequence[sequence]*: Energy rates table\n\n**Required:**\nTrue"),
 	NULL},
{"ur_metering_option", (getter)Common_get_ur_metering_option,(setter)Common_set_ur_metering_option,
	PyDoc_STR("*float*: Metering options [0=Single meter with monthly rollover credits in kWh,1=Single meter with monthly rollover credits in $,2=Single meter with no monthly rollover credits,3=Two meters with all generation sold and all load purchased]\n\n**Info:**\nNet metering monthly excess\n\n**Constraints:**\nINTEGER\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
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
{"ur_sell_eq_buy", (getter)Common_get_ur_sell_eq_buy,(setter)Common_set_ur_sell_eq_buy,
	PyDoc_STR("*float*: Set sell rate equal to buy rate [0/1]\n\n**Info:**\nOptional override\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate4.Common",             /*tp_name*/
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
TimeSeries_new(SAM_Utilityrate4 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate4", "TimeSeries")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Utilityrate4", "TimeSeries")){
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
	return PySAM_array_getter(SAM_Utilityrate4_TimeSeries_gen_aget, self->data_ptr);
}

static int
TimeSeries_set_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate4_TimeSeries_gen_aset, self->data_ptr);
}

static PyObject *
TimeSeries_get_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_TimeSeries_load_aget, self->data_ptr);
}

static int
TimeSeries_set_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate4_TimeSeries_load_aset, self->data_ptr);
}

static PyGetSetDef TimeSeries_getset[] = {
{"gen", (getter)TimeSeries_get_gen,(setter)TimeSeries_set_gen,
	PyDoc_STR("*sequence*: System power generated [kW]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Required:**\nTrue"),
 	NULL},
{"load", (getter)TimeSeries_get_load,(setter)TimeSeries_set_load,
	PyDoc_STR("*sequence*: Electricity load (year 1) [kW]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TimeSeries_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate4.TimeSeries",             /*tp_name*/
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
Financials_new(SAM_Utilityrate4 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate4", "Financials")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Utilityrate4", "Financials")){
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
	return PySAM_double_getter(SAM_Utilityrate4_Financials_inflation_rate_nget, self->data_ptr);
}

static int
Financials_set_inflation_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate4_Financials_inflation_rate_nset, self->data_ptr);
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
		"Utilityrate4.Financials",             /*tp_name*/
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
AnnualOutput_new(SAM_Utilityrate4 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate4", "AnnualOutput")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Utilityrate4", "AnnualOutput")){
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
	return PySAM_array_getter(SAM_Utilityrate4_AnnualOutput_degradation_aget, self->data_ptr);
}

static int
AnnualOutput_set_degradation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate4_AnnualOutput_degradation_aset, self->data_ptr);
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
		"Utilityrate4.AnnualOutput",             /*tp_name*/
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
Outputs_new(SAM_Utilityrate4 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate4", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Utilityrate4", "Outputs")){
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
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_annual_electric_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_annual_energy_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_charge_w_sys_dc_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_fixed_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_w_sys_dc_fixed_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_tou(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_charge_w_sys_dc_tou_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_tou_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_w_sys_dc_tou_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_charge_w_sys_ec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_apr_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_w_sys_ec_apr_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_aug_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_w_sys_ec_aug_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_dec_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_w_sys_ec_dec_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_feb_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_w_sys_ec_feb_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jan_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_w_sys_ec_jan_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jul_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_w_sys_ec_jul_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jun_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_w_sys_ec_jun_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_mar_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_w_sys_ec_mar_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_may_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_w_sys_ec_may_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_nov_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_w_sys_ec_nov_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_oct_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_w_sys_ec_oct_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_sep_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_w_sys_ec_sep_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_w_sys_ec_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_charge_w_sys_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_fixed_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_w_sys_fixed_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_minimum(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_charge_w_sys_minimum_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_minimum_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_w_sys_minimum_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_dc_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_fixed_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_dc_fixed_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_tou(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_dc_tou_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_tou_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_dc_tou_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_ec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_apr_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_ec_apr_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_aug_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_ec_aug_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_dec_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_ec_dec_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_feb_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_ec_feb_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jan_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_ec_jan_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jul_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_ec_jul_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jun_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_ec_jun_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_mar_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_ec_mar_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_may_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_ec_may_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_nov_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_ec_nov_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_oct_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_ec_oct_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_sep_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_ec_sep_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_ec_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_fixed_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_fixed_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_minimum(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_minimum_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_minimum_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_charge_wo_sys_minimum_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_elec_cost_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_elec_cost_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_elec_cost_with_system_year1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate4_Outputs_elec_cost_with_system_year1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_elec_cost_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_elec_cost_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_elec_cost_without_system_year1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate4_Outputs_elec_cost_without_system_year1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_apr_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_w_sys_ec_apr_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_aug_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_w_sys_ec_aug_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_dec_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_w_sys_ec_dec_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_feb_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_w_sys_ec_feb_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jan_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_w_sys_ec_jan_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jul_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_w_sys_ec_jul_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jun_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_w_sys_ec_jun_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_mar_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_w_sys_ec_mar_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_may_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_w_sys_ec_may_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_nov_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_w_sys_ec_nov_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_oct_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_w_sys_ec_oct_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_sep_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_w_sys_ec_sep_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_apr_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_wo_sys_ec_apr_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_aug_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_wo_sys_ec_aug_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_dec_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_wo_sys_ec_dec_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_feb_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_wo_sys_ec_feb_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jan_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_wo_sys_ec_jan_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jul_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_wo_sys_ec_jul_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jun_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_wo_sys_ec_jun_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_mar_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_wo_sys_ec_mar_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_may_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_wo_sys_ec_may_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_nov_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_wo_sys_ec_nov_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_oct_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_wo_sys_ec_oct_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_sep_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_energy_wo_sys_ec_sep_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_lifetime_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_lifetime_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_savings_year1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate4_Outputs_savings_year1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_apr_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_surplus_w_sys_ec_apr_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_aug_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_surplus_w_sys_ec_aug_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_dec_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_surplus_w_sys_ec_dec_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_feb_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_surplus_w_sys_ec_feb_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_jan_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_surplus_w_sys_ec_jan_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_jul_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_surplus_w_sys_ec_jul_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_jun_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_surplus_w_sys_ec_jun_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_mar_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_surplus_w_sys_ec_mar_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_may_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_surplus_w_sys_ec_may_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_nov_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_surplus_w_sys_ec_nov_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_oct_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_surplus_w_sys_ec_oct_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_sep_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_surplus_w_sys_ec_sep_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_w_sys(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_utility_bill_w_sys_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_w_sys_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_utility_bill_w_sys_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_wo_sys(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_utility_bill_wo_sys_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_wo_sys_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate4_Outputs_utility_bill_wo_sys_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_electric_load(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate4_Outputs_year1_electric_load_nget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_dc_peak_per_period(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_hourly_dc_peak_per_period_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_dc_tou_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_hourly_dc_tou_schedule_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_dc_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_hourly_dc_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_dc_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_hourly_dc_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_e_fromgrid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_hourly_e_fromgrid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_e_tofromgrid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_hourly_e_tofromgrid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_e_togrid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_hourly_e_togrid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_ec_tou_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_hourly_ec_tou_schedule_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_ec_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_hourly_ec_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_ec_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_hourly_ec_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_p_system_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_hourly_p_system_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_p_tofromgrid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_hourly_p_tofromgrid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_salespurchases_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_hourly_salespurchases_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_salespurchases_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_hourly_salespurchases_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_system_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_hourly_system_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_cumulative_excess_dollars(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_cumulative_excess_dollars_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_cumulative_excess_generation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_cumulative_excess_generation_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_fixed_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_dc_fixed_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_fixed_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_dc_fixed_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_tou_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_dc_tou_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_tou_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_dc_tou_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_ec_charge_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_ec_charge_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_ec_charge_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_ec_charge_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_electricity_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_electricity_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_fixed_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_fixed_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_fixed_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_fixed_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_minimum_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_minimum_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_minimum_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_minimum_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_peak_w_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_peak_w_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_peak_wo_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_peak_wo_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_use_w_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_use_w_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_use_wo_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_use_wo_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_utility_bill_w_sys(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_utility_bill_w_sys_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_utility_bill_wo_sys(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate4_Outputs_year1_monthly_utility_bill_wo_sys_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_electric_load", (getter)Outputs_get_annual_electric_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity load total in each year [kWh]"),
 	NULL},
{"annual_energy_value", (getter)Outputs_get_annual_energy_value,(setter)0,
	PyDoc_STR("*sequence*: Energy value in each year [$]"),
 	NULL},
{"charge_w_sys_dc_fixed", (getter)Outputs_get_charge_w_sys_dc_fixed,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (flat) [$]"),
 	NULL},
{"charge_w_sys_dc_fixed_ym", (getter)Outputs_get_charge_w_sys_dc_fixed_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Demand charge with system (flat) [$]"),
 	NULL},
{"charge_w_sys_dc_tou", (getter)Outputs_get_charge_w_sys_dc_tou,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system (TOU) [$]"),
 	NULL},
{"charge_w_sys_dc_tou_ym", (getter)Outputs_get_charge_w_sys_dc_tou_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Demand charge with system (TOU) [$]"),
 	NULL},
{"charge_w_sys_ec", (getter)Outputs_get_charge_w_sys_ec,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system [$]"),
 	NULL},
{"charge_w_sys_ec_apr_tp", (getter)Outputs_get_charge_w_sys_ec_apr_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge with system Apr [$]"),
 	NULL},
{"charge_w_sys_ec_aug_tp", (getter)Outputs_get_charge_w_sys_ec_aug_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge with system Aug [$]"),
 	NULL},
{"charge_w_sys_ec_dec_tp", (getter)Outputs_get_charge_w_sys_ec_dec_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge with system Dec [$]"),
 	NULL},
{"charge_w_sys_ec_feb_tp", (getter)Outputs_get_charge_w_sys_ec_feb_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge with system Feb [$]"),
 	NULL},
{"charge_w_sys_ec_jan_tp", (getter)Outputs_get_charge_w_sys_ec_jan_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge with system Jan [$]"),
 	NULL},
{"charge_w_sys_ec_jul_tp", (getter)Outputs_get_charge_w_sys_ec_jul_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge with system Jul [$]"),
 	NULL},
{"charge_w_sys_ec_jun_tp", (getter)Outputs_get_charge_w_sys_ec_jun_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge with system Jun [$]"),
 	NULL},
{"charge_w_sys_ec_mar_tp", (getter)Outputs_get_charge_w_sys_ec_mar_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge with system Mar [$]"),
 	NULL},
{"charge_w_sys_ec_may_tp", (getter)Outputs_get_charge_w_sys_ec_may_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge with system May [$]"),
 	NULL},
{"charge_w_sys_ec_nov_tp", (getter)Outputs_get_charge_w_sys_ec_nov_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge with system Nov [$]"),
 	NULL},
{"charge_w_sys_ec_oct_tp", (getter)Outputs_get_charge_w_sys_ec_oct_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge with system Oct [$]"),
 	NULL},
{"charge_w_sys_ec_sep_tp", (getter)Outputs_get_charge_w_sys_ec_sep_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge with system Sep [$]"),
 	NULL},
{"charge_w_sys_ec_ym", (getter)Outputs_get_charge_w_sys_ec_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge with system [$]"),
 	NULL},
{"charge_w_sys_fixed", (getter)Outputs_get_charge_w_sys_fixed,(setter)0,
	PyDoc_STR("*sequence*: Fixed monthly charge with system [$]"),
 	NULL},
{"charge_w_sys_fixed_ym", (getter)Outputs_get_charge_w_sys_fixed_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Fixed monthly charge with system [$]"),
 	NULL},
{"charge_w_sys_minimum", (getter)Outputs_get_charge_w_sys_minimum,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge with system [$]"),
 	NULL},
{"charge_w_sys_minimum_ym", (getter)Outputs_get_charge_w_sys_minimum_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Minimum charge with system [$]"),
 	NULL},
{"charge_wo_sys_dc_fixed", (getter)Outputs_get_charge_wo_sys_dc_fixed,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (flat) [$]"),
 	NULL},
{"charge_wo_sys_dc_fixed_ym", (getter)Outputs_get_charge_wo_sys_dc_fixed_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Demand charge without system (flat) [$]"),
 	NULL},
{"charge_wo_sys_dc_tou", (getter)Outputs_get_charge_wo_sys_dc_tou,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system (TOU) [$]"),
 	NULL},
{"charge_wo_sys_dc_tou_ym", (getter)Outputs_get_charge_wo_sys_dc_tou_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Demand charge without system (TOU) [$]"),
 	NULL},
{"charge_wo_sys_ec", (getter)Outputs_get_charge_wo_sys_ec,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system [$]"),
 	NULL},
{"charge_wo_sys_ec_apr_tp", (getter)Outputs_get_charge_wo_sys_ec_apr_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge without system Apr [$]"),
 	NULL},
{"charge_wo_sys_ec_aug_tp", (getter)Outputs_get_charge_wo_sys_ec_aug_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge without system Aug [$]"),
 	NULL},
{"charge_wo_sys_ec_dec_tp", (getter)Outputs_get_charge_wo_sys_ec_dec_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge without system Dec [$]"),
 	NULL},
{"charge_wo_sys_ec_feb_tp", (getter)Outputs_get_charge_wo_sys_ec_feb_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge without system Feb [$]"),
 	NULL},
{"charge_wo_sys_ec_jan_tp", (getter)Outputs_get_charge_wo_sys_ec_jan_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge without system Jan [$]"),
 	NULL},
{"charge_wo_sys_ec_jul_tp", (getter)Outputs_get_charge_wo_sys_ec_jul_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge without system Jul [$]"),
 	NULL},
{"charge_wo_sys_ec_jun_tp", (getter)Outputs_get_charge_wo_sys_ec_jun_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge without system Jun [$]"),
 	NULL},
{"charge_wo_sys_ec_mar_tp", (getter)Outputs_get_charge_wo_sys_ec_mar_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge without system Mar [$]"),
 	NULL},
{"charge_wo_sys_ec_may_tp", (getter)Outputs_get_charge_wo_sys_ec_may_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge without system May [$]"),
 	NULL},
{"charge_wo_sys_ec_nov_tp", (getter)Outputs_get_charge_wo_sys_ec_nov_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge without system Nov [$]"),
 	NULL},
{"charge_wo_sys_ec_oct_tp", (getter)Outputs_get_charge_wo_sys_ec_oct_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge without system Oct [$]"),
 	NULL},
{"charge_wo_sys_ec_sep_tp", (getter)Outputs_get_charge_wo_sys_ec_sep_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge without system Sep [$]"),
 	NULL},
{"charge_wo_sys_ec_ym", (getter)Outputs_get_charge_wo_sys_ec_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge without system [$]"),
 	NULL},
{"charge_wo_sys_fixed", (getter)Outputs_get_charge_wo_sys_fixed,(setter)0,
	PyDoc_STR("*sequence*: Fixed monthly charge without system [$]"),
 	NULL},
{"charge_wo_sys_fixed_ym", (getter)Outputs_get_charge_wo_sys_fixed_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Fixed monthly charge without system [$]"),
 	NULL},
{"charge_wo_sys_minimum", (getter)Outputs_get_charge_wo_sys_minimum,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge without system [$]"),
 	NULL},
{"charge_wo_sys_minimum_ym", (getter)Outputs_get_charge_wo_sys_minimum_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Minimum charge without system [$]"),
 	NULL},
{"elec_cost_with_system", (getter)Outputs_get_elec_cost_with_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity bill with system [$/yr]"),
 	NULL},
{"elec_cost_with_system_year1", (getter)Outputs_get_elec_cost_with_system_year1,(setter)0,
	PyDoc_STR("*float*: Electricity bill with system (year 1) [$/yr]"),
 	NULL},
{"elec_cost_without_system", (getter)Outputs_get_elec_cost_without_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity bill without system [$/yr]"),
 	NULL},
{"elec_cost_without_system_year1", (getter)Outputs_get_elec_cost_without_system_year1,(setter)0,
	PyDoc_STR("*float*: Electricity bill without system (year 1) [$/yr]"),
 	NULL},
{"energy_w_sys_ec_apr_tp", (getter)Outputs_get_energy_w_sys_ec_apr_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage with system Apr [kWh]"),
 	NULL},
{"energy_w_sys_ec_aug_tp", (getter)Outputs_get_energy_w_sys_ec_aug_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage with system Aug [kWh]"),
 	NULL},
{"energy_w_sys_ec_dec_tp", (getter)Outputs_get_energy_w_sys_ec_dec_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage with system Dec [kWh]"),
 	NULL},
{"energy_w_sys_ec_feb_tp", (getter)Outputs_get_energy_w_sys_ec_feb_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage with system Feb [kWh]"),
 	NULL},
{"energy_w_sys_ec_jan_tp", (getter)Outputs_get_energy_w_sys_ec_jan_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage with system Jan [kWh]"),
 	NULL},
{"energy_w_sys_ec_jul_tp", (getter)Outputs_get_energy_w_sys_ec_jul_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage with system Jul [kWh]"),
 	NULL},
{"energy_w_sys_ec_jun_tp", (getter)Outputs_get_energy_w_sys_ec_jun_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage with system Jun [kWh]"),
 	NULL},
{"energy_w_sys_ec_mar_tp", (getter)Outputs_get_energy_w_sys_ec_mar_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage with system Mar [kWh]"),
 	NULL},
{"energy_w_sys_ec_may_tp", (getter)Outputs_get_energy_w_sys_ec_may_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage with system May [kWh]"),
 	NULL},
{"energy_w_sys_ec_nov_tp", (getter)Outputs_get_energy_w_sys_ec_nov_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage with system Nov [kWh]"),
 	NULL},
{"energy_w_sys_ec_oct_tp", (getter)Outputs_get_energy_w_sys_ec_oct_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage with system Oct [kWh]"),
 	NULL},
{"energy_w_sys_ec_sep_tp", (getter)Outputs_get_energy_w_sys_ec_sep_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage with system Sep [kWh]"),
 	NULL},
{"energy_wo_sys_ec_apr_tp", (getter)Outputs_get_energy_wo_sys_ec_apr_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage without system Apr [kWh]"),
 	NULL},
{"energy_wo_sys_ec_aug_tp", (getter)Outputs_get_energy_wo_sys_ec_aug_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage without system Aug [kWh]"),
 	NULL},
{"energy_wo_sys_ec_dec_tp", (getter)Outputs_get_energy_wo_sys_ec_dec_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage without system Dec [kWh]"),
 	NULL},
{"energy_wo_sys_ec_feb_tp", (getter)Outputs_get_energy_wo_sys_ec_feb_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage without system Feb [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jan_tp", (getter)Outputs_get_energy_wo_sys_ec_jan_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage without system Jan [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jul_tp", (getter)Outputs_get_energy_wo_sys_ec_jul_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage without system Jul [kWh]"),
 	NULL},
{"energy_wo_sys_ec_jun_tp", (getter)Outputs_get_energy_wo_sys_ec_jun_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage without system Jun [kWh]"),
 	NULL},
{"energy_wo_sys_ec_mar_tp", (getter)Outputs_get_energy_wo_sys_ec_mar_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage without system Mar [kWh]"),
 	NULL},
{"energy_wo_sys_ec_may_tp", (getter)Outputs_get_energy_wo_sys_ec_may_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage without system May [kWh]"),
 	NULL},
{"energy_wo_sys_ec_nov_tp", (getter)Outputs_get_energy_wo_sys_ec_nov_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage without system Nov [kWh]"),
 	NULL},
{"energy_wo_sys_ec_oct_tp", (getter)Outputs_get_energy_wo_sys_ec_oct_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage without system Oct [kWh]"),
 	NULL},
{"energy_wo_sys_ec_sep_tp", (getter)Outputs_get_energy_wo_sys_ec_sep_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity usage without system Sep [kWh]"),
 	NULL},
{"lifetime_load", (getter)Outputs_get_lifetime_load,(setter)0,
	PyDoc_STR("*sequence*: Lifetime electricity load [kW]"),
 	NULL},
{"savings_year1", (getter)Outputs_get_savings_year1,(setter)0,
	PyDoc_STR("*float*: Electricity net savings with system (year 1) [$/yr]"),
 	NULL},
{"surplus_w_sys_ec_apr_tp", (getter)Outputs_get_surplus_w_sys_ec_apr_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity exports with system Apr [kWh]"),
 	NULL},
{"surplus_w_sys_ec_aug_tp", (getter)Outputs_get_surplus_w_sys_ec_aug_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity exports with system Aug [kWh]"),
 	NULL},
{"surplus_w_sys_ec_dec_tp", (getter)Outputs_get_surplus_w_sys_ec_dec_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity exports with system Dec [kWh]"),
 	NULL},
{"surplus_w_sys_ec_feb_tp", (getter)Outputs_get_surplus_w_sys_ec_feb_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity exports with system Feb [kWh]"),
 	NULL},
{"surplus_w_sys_ec_jan_tp", (getter)Outputs_get_surplus_w_sys_ec_jan_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity exports with system Jan [kWh]"),
 	NULL},
{"surplus_w_sys_ec_jul_tp", (getter)Outputs_get_surplus_w_sys_ec_jul_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity exports with system Jul [kWh]"),
 	NULL},
{"surplus_w_sys_ec_jun_tp", (getter)Outputs_get_surplus_w_sys_ec_jun_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity exports with system Jun [kWh]"),
 	NULL},
{"surplus_w_sys_ec_mar_tp", (getter)Outputs_get_surplus_w_sys_ec_mar_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity exports with system Mar [kWh]"),
 	NULL},
{"surplus_w_sys_ec_may_tp", (getter)Outputs_get_surplus_w_sys_ec_may_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity exports with system May [kWh]"),
 	NULL},
{"surplus_w_sys_ec_nov_tp", (getter)Outputs_get_surplus_w_sys_ec_nov_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity exports with system Nov [kWh]"),
 	NULL},
{"surplus_w_sys_ec_oct_tp", (getter)Outputs_get_surplus_w_sys_ec_oct_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity exports with system Oct [kWh]"),
 	NULL},
{"surplus_w_sys_ec_sep_tp", (getter)Outputs_get_surplus_w_sys_ec_sep_tp,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity exports with system Sep [kWh]"),
 	NULL},
{"utility_bill_w_sys", (getter)Outputs_get_utility_bill_w_sys,(setter)0,
	PyDoc_STR("*sequence*: Utility bill with system [$]"),
 	NULL},
{"utility_bill_w_sys_ym", (getter)Outputs_get_utility_bill_w_sys_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Utility bill with system [$]"),
 	NULL},
{"utility_bill_wo_sys", (getter)Outputs_get_utility_bill_wo_sys,(setter)0,
	PyDoc_STR("*sequence*: Utility bill without system [$]"),
 	NULL},
{"utility_bill_wo_sys_ym", (getter)Outputs_get_utility_bill_wo_sys_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Utility bill without system [$]"),
 	NULL},
{"year1_electric_load", (getter)Outputs_get_year1_electric_load,(setter)0,
	PyDoc_STR("*float*: Electricity load total (year 1) [kWh/yr]"),
 	NULL},
{"year1_hourly_dc_peak_per_period", (getter)Outputs_get_year1_hourly_dc_peak_per_period,(setter)0,
	PyDoc_STR("*sequence*: Electricity peak from grid per TOU period [kW]"),
 	NULL},
{"year1_hourly_dc_tou_schedule", (getter)Outputs_get_year1_hourly_dc_tou_schedule,(setter)0,
	PyDoc_STR("*sequence*: TOU period for demand charges"),
 	NULL},
{"year1_hourly_dc_with_system", (getter)Outputs_get_year1_hourly_dc_with_system,(setter)0,
	PyDoc_STR("*sequence*: Demand charge with system [$]"),
 	NULL},
{"year1_hourly_dc_without_system", (getter)Outputs_get_year1_hourly_dc_without_system,(setter)0,
	PyDoc_STR("*sequence*: Demand charge without system [$]"),
 	NULL},
{"year1_hourly_e_fromgrid", (getter)Outputs_get_year1_hourly_e_fromgrid,(setter)0,
	PyDoc_STR("*sequence*: Electricity from grid [kWh]"),
 	NULL},
{"year1_hourly_e_tofromgrid", (getter)Outputs_get_year1_hourly_e_tofromgrid,(setter)0,
	PyDoc_STR("*sequence*: Electricity to/from grid [kWh]"),
 	NULL},
{"year1_hourly_e_togrid", (getter)Outputs_get_year1_hourly_e_togrid,(setter)0,
	PyDoc_STR("*sequence*: Electricity to grid [kWh]"),
 	NULL},
{"year1_hourly_ec_tou_schedule", (getter)Outputs_get_year1_hourly_ec_tou_schedule,(setter)0,
	PyDoc_STR("*sequence*: TOU period for energy charges"),
 	NULL},
{"year1_hourly_ec_with_system", (getter)Outputs_get_year1_hourly_ec_with_system,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system [$]"),
 	NULL},
{"year1_hourly_ec_without_system", (getter)Outputs_get_year1_hourly_ec_without_system,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system [$]"),
 	NULL},
{"year1_hourly_p_system_to_load", (getter)Outputs_get_year1_hourly_p_system_to_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity peak from system to load [kW]"),
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
{"year1_hourly_system_to_load", (getter)Outputs_get_year1_hourly_system_to_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity from system to load [kWh]"),
 	NULL},
{"year1_monthly_cumulative_excess_dollars", (getter)Outputs_get_year1_monthly_cumulative_excess_dollars,(setter)0,
	PyDoc_STR("*sequence*: Net metering credit in $ [$/mo]"),
 	NULL},
{"year1_monthly_cumulative_excess_generation", (getter)Outputs_get_year1_monthly_cumulative_excess_generation,(setter)0,
	PyDoc_STR("*sequence*: Net metering credit in kWh [kWh/mo]"),
 	NULL},
{"year1_monthly_dc_fixed_with_system", (getter)Outputs_get_year1_monthly_dc_fixed_with_system,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (flat) with system [$/mo]"),
 	NULL},
{"year1_monthly_dc_fixed_without_system", (getter)Outputs_get_year1_monthly_dc_fixed_without_system,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (flat) without system [$/mo]"),
 	NULL},
{"year1_monthly_dc_tou_with_system", (getter)Outputs_get_year1_monthly_dc_tou_with_system,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (TOU) with system [$/mo]"),
 	NULL},
{"year1_monthly_dc_tou_without_system", (getter)Outputs_get_year1_monthly_dc_tou_without_system,(setter)0,
	PyDoc_STR("*sequence*: Demand charge (TOU) without system [$/mo]"),
 	NULL},
{"year1_monthly_ec_charge_with_system", (getter)Outputs_get_year1_monthly_ec_charge_with_system,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system [$/mo]"),
 	NULL},
{"year1_monthly_ec_charge_without_system", (getter)Outputs_get_year1_monthly_ec_charge_without_system,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system [$/mo]"),
 	NULL},
{"year1_monthly_electricity_to_grid", (getter)Outputs_get_year1_monthly_electricity_to_grid,(setter)0,
	PyDoc_STR("*sequence*: Electricity to/from grid [kWh/mo]"),
 	NULL},
{"year1_monthly_fixed_with_system", (getter)Outputs_get_year1_monthly_fixed_with_system,(setter)0,
	PyDoc_STR("*sequence*: Fixed monthly charge with system [$/mo]"),
 	NULL},
{"year1_monthly_fixed_without_system", (getter)Outputs_get_year1_monthly_fixed_without_system,(setter)0,
	PyDoc_STR("*sequence*: Fixed monthly charge without system [$/mo]"),
 	NULL},
{"year1_monthly_load", (getter)Outputs_get_year1_monthly_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity load [kWh/mo]"),
 	NULL},
{"year1_monthly_minimum_with_system", (getter)Outputs_get_year1_monthly_minimum_with_system,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge with system [$/mo]"),
 	NULL},
{"year1_monthly_minimum_without_system", (getter)Outputs_get_year1_monthly_minimum_without_system,(setter)0,
	PyDoc_STR("*sequence*: Minimum charge without system [$/mo]"),
 	NULL},
{"year1_monthly_peak_w_system", (getter)Outputs_get_year1_monthly_peak_w_system,(setter)0,
	PyDoc_STR("*sequence*: Peak demand with system [kW/mo]"),
 	NULL},
{"year1_monthly_peak_wo_system", (getter)Outputs_get_year1_monthly_peak_wo_system,(setter)0,
	PyDoc_STR("*sequence*: Peak demand without system [kW/mo]"),
 	NULL},
{"year1_monthly_use_w_system", (getter)Outputs_get_year1_monthly_use_w_system,(setter)0,
	PyDoc_STR("*sequence*: Energy use with system [kWh/mo]"),
 	NULL},
{"year1_monthly_use_wo_system", (getter)Outputs_get_year1_monthly_use_wo_system,(setter)0,
	PyDoc_STR("*sequence*: Energy use without system [kWh/mo]"),
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
		"Utilityrate4.Outputs",             /*tp_name*/
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
 * Utilityrate4
 */

static PyTypeObject Utilityrate4_Type;

static CmodObject *
newUtilityrate4Object(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Utilityrate4_Type);

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

/* Utilityrate4 methods */

static void
Utilityrate4_dealloc(CmodObject *self)
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
Utilityrate4_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Utilityrate4_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Utilityrate4_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Utilityrate4"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Utilityrate4_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Utilityrate4"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Utilityrate4_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Utilityrate4_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Utilityrate4_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Utilityrate4_methods[] = {
		{"execute",           (PyCFunction)Utilityrate4_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Utilityrate4_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Common': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Utilityrate4_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Common': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Utilityrate4_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Utilityrate4_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Utilityrate4_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Utilityrate4_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Utilityrate4_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Utilityrate4_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate4",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Utilityrate4_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Utilityrate4_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Utilityrate4_getattro, /*tp_getattro*/
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
		Utilityrate4_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Utilityrate4 object */

static PyObject *
Utilityrate4_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newUtilityrate4Object(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Utilityrate4_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newUtilityrate4Object((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Utilityrate4_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newUtilityrate4Object(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Utilityrate4", def) < 0) {
		Utilityrate4_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Utilityrate4_from_existing(PyObject *self, PyObject *args)
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

	rv = newUtilityrate4Object((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Utilityrate4", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Utilityrate4Module_methods[] = {
		{"new",             Utilityrate4_new,         METH_VARARGS,
				PyDoc_STR("new() -> Utilityrate4")},
		{"default",             Utilityrate4_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Utilityrate4\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Utilityrate4_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Utilityrate4\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Utilityrate4_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Utilityrate4\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Utilityrate4");


static int
Utilityrate4Module_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Utilityrate4_Type.tp_dict = PyDict_New();
	if (!Utilityrate4_Type.tp_dict) { goto fail; }

	/// Add the Common type object to Utilityrate4_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate4_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the TimeSeries type object to Utilityrate4_Type
	if (PyType_Ready(&TimeSeries_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate4_Type.tp_dict,
				"TimeSeries",
				(PyObject*)&TimeSeries_Type);
	Py_DECREF(&TimeSeries_Type);

	/// Add the Financials type object to Utilityrate4_Type
	if (PyType_Ready(&Financials_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate4_Type.tp_dict,
				"Financials",
				(PyObject*)&Financials_Type);
	Py_DECREF(&Financials_Type);

	/// Add the AnnualOutput type object to Utilityrate4_Type
	if (PyType_Ready(&AnnualOutput_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate4_Type.tp_dict,
				"AnnualOutput",
				(PyObject*)&AnnualOutput_Type);
	Py_DECREF(&AnnualOutput_Type);

	/// Add the Outputs type object to Utilityrate4_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate4_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Utilityrate4 type object to the module
	if (PyType_Ready(&Utilityrate4_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Utilityrate4",
				(PyObject*)&Utilityrate4_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Utilityrate4Module_slots[] = {
		{Py_mod_exec, Utilityrate4Module_exec},
		{0, NULL},
};

static struct PyModuleDef Utilityrate4Module = {
		PyModuleDef_HEAD_INIT,
		"Utilityrate4",
		module_doc,
		0,
		Utilityrate4Module_methods,
		Utilityrate4Module_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Utilityrate4(void)
{
	return PyModuleDef_Init(&Utilityrate4Module);
}