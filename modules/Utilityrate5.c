#include <Python.h>

#include <SAM_Utilityrate5.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Lifetime Group
 */ 

static PyTypeObject Lifetime_Type;

static PyObject *
Lifetime_new(SAM_Utilityrate5 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate5", "Lifetime")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Utilityrate5", "Lifetime")){
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
	return PySAM_double_getter(SAM_Utilityrate5_Lifetime_analysis_period_nget, self->data_ptr);
}

static int
Lifetime_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate5_Lifetime_analysis_period_nset, self->data_ptr);
}

static PyObject *
Lifetime_get_inflation_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_Lifetime_inflation_rate_nget, self->data_ptr);
}

static int
Lifetime_set_inflation_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate5_Lifetime_inflation_rate_nset, self->data_ptr);
}

static PyObject *
Lifetime_get_system_use_lifetime_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_Lifetime_system_use_lifetime_output_nget, self->data_ptr);
}

static int
Lifetime_set_system_use_lifetime_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate5_Lifetime_system_use_lifetime_output_nset, self->data_ptr);
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
		"Utilityrate5.Lifetime",             /*tp_name*/
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
 * ElectricityRates Group
 */ 

static PyTypeObject ElectricityRates_Type;

static PyObject *
ElectricityRates_new(SAM_Utilityrate5 data_ptr)
{
	PyObject* new_obj = ElectricityRates_Type.tp_alloc(&ElectricityRates_Type,0);

	VarGroupObject* ElectricityRates_obj = (VarGroupObject*)new_obj;

	ElectricityRates_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* ElectricityRates methods */

static PyObject *
ElectricityRates_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate5", "ElectricityRates")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ElectricityRates_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &ElectricityRates_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Utilityrate5", "ElectricityRates")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ElectricityRates_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &ElectricityRates_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ElectricityRates_methods[] = {
		{"assign",            (PyCFunction)ElectricityRates_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``ElectricityRates_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)ElectricityRates_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``ElectricityRates_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)ElectricityRates_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ElectricityRates_get_TOU_demand_single_peak(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_ElectricityRates_TOU_demand_single_peak_nget, self->data_ptr);
}

static int
ElectricityRates_set_TOU_demand_single_peak(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate5_ElectricityRates_TOU_demand_single_peak_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_en_electricity_rates(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_ElectricityRates_en_electricity_rates_nget, self->data_ptr);
}

static int
ElectricityRates_set_en_electricity_rates(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate5_ElectricityRates_en_electricity_rates_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_rate_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_ElectricityRates_rate_escalation_aget, self->data_ptr);
}

static int
ElectricityRates_set_rate_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate5_ElectricityRates_rate_escalation_aset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_annual_min_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_ElectricityRates_ur_annual_min_charge_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_annual_min_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate5_ElectricityRates_ur_annual_min_charge_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_billing_demand_lookback_percentages(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_ElectricityRates_ur_billing_demand_lookback_percentages_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_billing_demand_lookback_percentages(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate5_ElectricityRates_ur_billing_demand_lookback_percentages_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_billing_demand_lookback_period(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_ElectricityRates_ur_billing_demand_lookback_period_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_billing_demand_lookback_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate5_ElectricityRates_ur_billing_demand_lookback_period_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_billing_demand_minimum(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_ElectricityRates_ur_billing_demand_minimum_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_billing_demand_minimum(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate5_ElectricityRates_ur_billing_demand_minimum_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_billing_demand_periods(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_ElectricityRates_ur_dc_billing_demand_periods_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_billing_demand_periods(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate5_ElectricityRates_ur_dc_billing_demand_periods_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_ElectricityRates_ur_dc_enable_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate5_ElectricityRates_ur_dc_enable_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_flat_mat(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_ElectricityRates_ur_dc_flat_mat_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_flat_mat(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate5_ElectricityRates_ur_dc_flat_mat_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_ElectricityRates_ur_dc_sched_weekday_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate5_ElectricityRates_ur_dc_sched_weekday_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_ElectricityRates_ur_dc_sched_weekend_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate5_ElectricityRates_ur_dc_sched_weekend_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_tou_mat(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_ElectricityRates_ur_dc_tou_mat_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_tou_mat(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate5_ElectricityRates_ur_dc_tou_mat_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ec_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_ElectricityRates_ur_ec_sched_weekday_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ec_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate5_ElectricityRates_ur_ec_sched_weekday_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ec_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_ElectricityRates_ur_ec_sched_weekend_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ec_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate5_ElectricityRates_ur_ec_sched_weekend_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ec_tou_mat(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_ElectricityRates_ur_ec_tou_mat_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ec_tou_mat(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrate5_ElectricityRates_ur_ec_tou_mat_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_en_ts_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_ElectricityRates_ur_en_ts_buy_rate_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_en_ts_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate5_ElectricityRates_ur_en_ts_buy_rate_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_en_ts_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_ElectricityRates_ur_en_ts_sell_rate_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_en_ts_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate5_ElectricityRates_ur_en_ts_sell_rate_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_enable_billing_demand(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_ElectricityRates_ur_enable_billing_demand_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_enable_billing_demand(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate5_ElectricityRates_ur_enable_billing_demand_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_metering_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_ElectricityRates_ur_metering_option_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_metering_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate5_ElectricityRates_ur_metering_option_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_monthly_fixed_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_ElectricityRates_ur_monthly_fixed_charge_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_monthly_fixed_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate5_ElectricityRates_ur_monthly_fixed_charge_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_monthly_min_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_ElectricityRates_ur_monthly_min_charge_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_monthly_min_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate5_ElectricityRates_ur_monthly_min_charge_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_nm_credit_month(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_ElectricityRates_ur_nm_credit_month_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_nm_credit_month(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate5_ElectricityRates_ur_nm_credit_month_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_nm_credit_rollover(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_ElectricityRates_ur_nm_credit_rollover_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_nm_credit_rollover(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate5_ElectricityRates_ur_nm_credit_rollover_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_nm_yearend_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_ElectricityRates_ur_nm_yearend_sell_rate_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_nm_yearend_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate5_ElectricityRates_ur_nm_yearend_sell_rate_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_sell_eq_buy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_ElectricityRates_ur_sell_eq_buy_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_sell_eq_buy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrate5_ElectricityRates_ur_sell_eq_buy_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ts_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_ElectricityRates_ur_ts_buy_rate_aget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ts_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate5_ElectricityRates_ur_ts_buy_rate_aset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ts_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_ElectricityRates_ur_ts_sell_rate_aget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ts_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate5_ElectricityRates_ur_ts_sell_rate_aset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_yearzero_usage_peaks(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_ElectricityRates_ur_yearzero_usage_peaks_aget, self->data_ptr);
}

static int
ElectricityRates_set_ur_yearzero_usage_peaks(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate5_ElectricityRates_ur_yearzero_usage_peaks_aset, self->data_ptr);
}

static PyGetSetDef ElectricityRates_getset[] = {
{"TOU_demand_single_peak", (getter)ElectricityRates_get_TOU_demand_single_peak,(setter)ElectricityRates_set_TOU_demand_single_peak,
	PyDoc_STR("*float*: Use single monthly peak for TOU demand charge [0/1]\n\n**Options:**\n0=use TOU peak,1=use flat peak\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"en_electricity_rates", (getter)ElectricityRates_get_en_electricity_rates,(setter)ElectricityRates_set_en_electricity_rates,
	PyDoc_STR("*float*: Optionally enable/disable electricity_rate [years]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1"),
 	NULL},
{"rate_escalation", (getter)ElectricityRates_get_rate_escalation,(setter)ElectricityRates_set_rate_escalation,
	PyDoc_STR("*sequence*: Annual electricity rate escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_annual_min_charge", (getter)ElectricityRates_get_ur_annual_min_charge,(setter)ElectricityRates_set_ur_annual_min_charge,
	PyDoc_STR("*float*: Annual minimum charge [$]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_billing_demand_lookback_percentages", (getter)ElectricityRates_get_ur_billing_demand_lookback_percentages,(setter)ElectricityRates_set_ur_billing_demand_lookback_percentages,
	PyDoc_STR("*sequence[sequence]*: Billing demand lookback percentages by month and consider actual peak demand [%]\n\n**Info:**\n12x2\n\n**Required:**\nRequired if ur_enable_billing_demand=1"),
 	NULL},
{"ur_billing_demand_lookback_period", (getter)ElectricityRates_get_ur_billing_demand_lookback_period,(setter)ElectricityRates_set_ur_billing_demand_lookback_period,
	PyDoc_STR("*float*: Billing demand lookback period [mn]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=12\n\n**Required:**\nRequired if ur_enable_billing_demand=1"),
 	NULL},
{"ur_billing_demand_minimum", (getter)ElectricityRates_get_ur_billing_demand_minimum,(setter)ElectricityRates_set_ur_billing_demand_minimum,
	PyDoc_STR("*float*: Minimum billing demand [kW]\n\n**Required:**\nRequired if ur_enable_billing_demand=1"),
 	NULL},
{"ur_dc_billing_demand_periods", (getter)ElectricityRates_get_ur_dc_billing_demand_periods,(setter)ElectricityRates_set_ur_dc_billing_demand_periods,
	PyDoc_STR("*sequence[sequence]*: Billing demand applicability to a given demand charge time of use period\n\n**Required:**\nRequired if ur_enable_billing_demand=1"),
 	NULL},
{"ur_dc_enable", (getter)ElectricityRates_get_ur_dc_enable,(setter)ElectricityRates_set_ur_dc_enable,
	PyDoc_STR("*float*: Enable demand charge [0/1]\n\n**Options:**\n0=disable,1=enable\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_flat_mat", (getter)ElectricityRates_get_ur_dc_flat_mat,(setter)ElectricityRates_set_ur_dc_flat_mat,
	PyDoc_STR("*sequence[sequence]*: Demand rates (flat) table [col 0=month, col 1=tier no, col 2=tier peak (kW), col 3=charge ($/kW)]\n\n**Info:**\nnx4\n\n**Required:**\nRequired if ur_dc_enable=1"),
 	NULL},
{"ur_dc_sched_weekday", (getter)ElectricityRates_get_ur_dc_sched_weekday,(setter)ElectricityRates_set_ur_dc_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: Demand charge weekday schedule [Periods defined in ur_dc_tou_mat]\n\n**Info:**\n12x24"),
 	NULL},
{"ur_dc_sched_weekend", (getter)ElectricityRates_get_ur_dc_sched_weekend,(setter)ElectricityRates_set_ur_dc_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Demand charge weekend schedule [Periods defined in ur_dc_tou_mat]\n\n**Info:**\n12x24"),
 	NULL},
{"ur_dc_tou_mat", (getter)ElectricityRates_get_ur_dc_tou_mat,(setter)ElectricityRates_set_ur_dc_tou_mat,
	PyDoc_STR("*sequence[sequence]*: Demand rates (TOU) table [col 0=period no, col 1=tier no, col 2=tier peak (kW), col 3=charge ($/kW)]\n\n**Info:**\nnx4\n\n**Required:**\nRequired if ur_dc_enable=1"),
 	NULL},
{"ur_ec_sched_weekday", (getter)ElectricityRates_get_ur_ec_sched_weekday,(setter)ElectricityRates_set_ur_ec_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: Energy charge weekday schedule [Periods defined in ur_ec_tou_mat]\n\n**Info:**\n12x24"),
 	NULL},
{"ur_ec_sched_weekend", (getter)ElectricityRates_get_ur_ec_sched_weekend,(setter)ElectricityRates_set_ur_ec_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Energy charge weekend schedule [Periods defined in ur_ec_tou_mat]\n\n**Info:**\n12x24"),
 	NULL},
{"ur_ec_tou_mat", (getter)ElectricityRates_get_ur_ec_tou_mat,(setter)ElectricityRates_set_ur_ec_tou_mat,
	PyDoc_STR("*sequence[sequence]*: Energy rates table [col 0=period no, col 1=tier no, col 2=max usage, col 3=max usage units (0=kWh, 1=kWh/kW, 2=kWh daily, 3=kWh/kW daily), col 4=buy rate ($/kWh), col 5=sell rate ($/kWh)]\n\n**Info:**\nnx6"),
 	NULL},
{"ur_en_ts_buy_rate", (getter)ElectricityRates_get_ur_en_ts_buy_rate,(setter)ElectricityRates_set_ur_en_ts_buy_rate,
	PyDoc_STR("*float*: Enable time step buy rates [0/1]\n\n**Options:**\n0=disable,1=enable\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_en_ts_sell_rate", (getter)ElectricityRates_get_ur_en_ts_sell_rate,(setter)ElectricityRates_set_ur_en_ts_sell_rate,
	PyDoc_STR("*float*: Enable time step sell rates [0/1]\n\n**Options:**\n0=disable,1=enable\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_enable_billing_demand", (getter)ElectricityRates_get_ur_enable_billing_demand,(setter)ElectricityRates_set_ur_enable_billing_demand,
	PyDoc_STR("*float*: Enable billing demand ratchets [0/1]\n\n**Options:**\n0=disable,1=enable\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_metering_option", (getter)ElectricityRates_get_ur_metering_option,(setter)ElectricityRates_set_ur_metering_option,
	PyDoc_STR("*float*: Metering options [0=net energy metering,1=net energy metering with $ credits,2=net billing,3=net billing with carryover to next month,4=buy all - sell all]\n\n**Info:**\nNet metering monthly excess\n\n**Constraints:**\nINTEGER,MIN=0,MAX=4\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_monthly_fixed_charge", (getter)ElectricityRates_get_ur_monthly_fixed_charge,(setter)ElectricityRates_set_ur_monthly_fixed_charge,
	PyDoc_STR("*float*: Monthly fixed charge [$]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_monthly_min_charge", (getter)ElectricityRates_get_ur_monthly_min_charge,(setter)ElectricityRates_set_ur_monthly_min_charge,
	PyDoc_STR("*float*: Monthly minimum charge [$]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_nm_credit_month", (getter)ElectricityRates_get_ur_nm_credit_month,(setter)ElectricityRates_set_ur_nm_credit_month,
	PyDoc_STR("*float*: Month of year end payout (true-up) [mn]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=11\n\n**Required:**\nFalse. Automatically set to 11 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_nm_credit_rollover", (getter)ElectricityRates_get_ur_nm_credit_rollover,(setter)ElectricityRates_set_ur_nm_credit_rollover,
	PyDoc_STR("*float*: Apply net metering true-up credits to future bills [0/1]\n\n**Options:**\n0=disable,1=enable\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_nm_yearend_sell_rate", (getter)ElectricityRates_get_ur_nm_yearend_sell_rate,(setter)ElectricityRates_set_ur_nm_yearend_sell_rate,
	PyDoc_STR("*float*: Net metering true-up credit sell rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_sell_eq_buy", (getter)ElectricityRates_get_ur_sell_eq_buy,(setter)ElectricityRates_set_ur_sell_eq_buy,
	PyDoc_STR("*float*: Set sell rate equal to buy rate [0/1]\n\n**Info:**\nOptional override\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ts_buy_rate", (getter)ElectricityRates_get_ur_ts_buy_rate,(setter)ElectricityRates_set_ur_ts_buy_rate,
	PyDoc_STR("*sequence*: Time step buy rates [$/kWh]"),
 	NULL},
{"ur_ts_sell_rate", (getter)ElectricityRates_get_ur_ts_sell_rate,(setter)ElectricityRates_set_ur_ts_sell_rate,
	PyDoc_STR("*sequence*: Time step sell rates [$/kWh]"),
 	NULL},
{"ur_yearzero_usage_peaks", (getter)ElectricityRates_get_ur_yearzero_usage_peaks,(setter)ElectricityRates_set_ur_yearzero_usage_peaks,
	PyDoc_STR("*sequence*: Peak usage by month for year zero [kW]\n\n**Info:**\n12\n\n**Required:**\nRequired if ur_enable_billing_demand=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ElectricityRates_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate5.ElectricityRates",             /*tp_name*/
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
		ElectricityRates_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ElectricityRates_getset,          /*tp_getset*/
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
 * SystemOutput Group
 */ 

static PyTypeObject SystemOutput_Type;

static PyObject *
SystemOutput_new(SAM_Utilityrate5 data_ptr)
{
	PyObject* new_obj = SystemOutput_Type.tp_alloc(&SystemOutput_Type,0);

	VarGroupObject* SystemOutput_obj = (VarGroupObject*)new_obj;

	SystemOutput_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SystemOutput methods */

static PyObject *
SystemOutput_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate5", "SystemOutput")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemOutput_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SystemOutput_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Utilityrate5", "SystemOutput")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemOutput_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SystemOutput_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SystemOutput_methods[] = {
		{"assign",            (PyCFunction)SystemOutput_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SystemOutput_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SystemOutput_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SystemOutput_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SystemOutput_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemOutput_get_degradation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_SystemOutput_degradation_aget, self->data_ptr);
}

static int
SystemOutput_set_degradation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate5_SystemOutput_degradation_aset, self->data_ptr);
}

static PyObject *
SystemOutput_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_SystemOutput_gen_aget, self->data_ptr);
}

static int
SystemOutput_set_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate5_SystemOutput_gen_aset, self->data_ptr);
}

static PyGetSetDef SystemOutput_getset[] = {
{"degradation", (getter)SystemOutput_get_degradation,(setter)SystemOutput_set_degradation,
	PyDoc_STR("*sequence*: Annual energy degradation [%]\n\n**Required:**\nTrue"),
 	NULL},
{"gen", (getter)SystemOutput_get_gen,(setter)SystemOutput_set_gen,
	PyDoc_STR("*sequence*: System power generated [kW]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemOutput_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate5.SystemOutput",             /*tp_name*/
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
		SystemOutput_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SystemOutput_getset,          /*tp_getset*/
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
 * Load Group
 */ 

static PyTypeObject Load_Type;

static PyObject *
Load_new(SAM_Utilityrate5 data_ptr)
{
	PyObject* new_obj = Load_Type.tp_alloc(&Load_Type,0);

	VarGroupObject* Load_obj = (VarGroupObject*)new_obj;

	Load_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Load methods */

static PyObject *
Load_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate5", "Load")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Load_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Load_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Utilityrate5", "Load")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Load_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Load_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Load_methods[] = {
		{"assign",            (PyCFunction)Load_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Load_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Load_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Load_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Load_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Load_get_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Load_load_aget, self->data_ptr);
}

static int
Load_set_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate5_Load_load_aset, self->data_ptr);
}

static PyObject *
Load_get_load_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Load_load_escalation_aget, self->data_ptr);
}

static int
Load_set_load_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrate5_Load_load_escalation_aset, self->data_ptr);
}

static PyGetSetDef Load_getset[] = {
{"load", (getter)Load_get_load,(setter)Load_set_load,
	PyDoc_STR("*sequence*: Electricity load (year 1) [kW]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"load_escalation", (getter)Load_get_load_escalation,(setter)Load_set_load_escalation,
	PyDoc_STR("*sequence*: Annual load escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Load_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate5.Load",             /*tp_name*/
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
		Load_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Load_getset,          /*tp_getset*/
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
Outputs_new(SAM_Utilityrate5 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrate5", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Utilityrate5", "Outputs")){
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
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_annual_electric_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_annual_energy_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_bill_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_bill_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_billing_demand_w_sys_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_billing_demand_w_sys_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_billing_demand_wo_sys_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_billing_demand_wo_sys_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_charge_w_sys_dc_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_fixed_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_w_sys_dc_fixed_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_tou(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_charge_w_sys_dc_tou_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_dc_tou_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_w_sys_dc_tou_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_charge_w_sys_ec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_apr_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_w_sys_ec_apr_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_aug_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_w_sys_ec_aug_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_dec_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_w_sys_ec_dec_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_feb_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_w_sys_ec_feb_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_gross_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_w_sys_ec_gross_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jan_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_w_sys_ec_jan_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jul_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_w_sys_ec_jul_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_jun_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_w_sys_ec_jun_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_mar_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_w_sys_ec_mar_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_may_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_w_sys_ec_may_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_nov_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_w_sys_ec_nov_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_oct_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_w_sys_ec_oct_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_sep_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_w_sys_ec_sep_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_ec_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_w_sys_ec_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_charge_w_sys_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_fixed_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_w_sys_fixed_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_minimum(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_charge_w_sys_minimum_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_w_sys_minimum_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_w_sys_minimum_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_dc_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_fixed_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_dc_fixed_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_tou(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_dc_tou_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_dc_tou_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_dc_tou_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_ec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_apr_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_ec_apr_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_aug_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_ec_aug_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_dec_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_ec_dec_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_feb_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_ec_feb_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jan_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_ec_jan_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jul_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_ec_jul_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_jun_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_ec_jun_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_mar_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_ec_mar_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_may_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_ec_may_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_nov_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_ec_nov_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_oct_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_ec_oct_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_sep_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_ec_sep_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_ec_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_ec_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_fixed_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_fixed_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_minimum(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_minimum_aget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_wo_sys_minimum_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_charge_wo_sys_minimum_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_elec_cost_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_elec_cost_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_elec_cost_with_system_year1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_Outputs_elec_cost_with_system_year1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_elec_cost_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_elec_cost_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_elec_cost_without_system_year1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_Outputs_elec_cost_without_system_year1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_apr_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_w_sys_ec_apr_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_aug_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_w_sys_ec_aug_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_dec_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_w_sys_ec_dec_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_feb_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_w_sys_ec_feb_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jan_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_w_sys_ec_jan_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jul_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_w_sys_ec_jul_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_jun_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_w_sys_ec_jun_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_mar_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_w_sys_ec_mar_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_may_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_w_sys_ec_may_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_nov_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_w_sys_ec_nov_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_oct_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_w_sys_ec_oct_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_w_sys_ec_sep_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_w_sys_ec_sep_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_apr_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_wo_sys_ec_apr_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_aug_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_wo_sys_ec_aug_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_dec_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_wo_sys_ec_dec_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_feb_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_wo_sys_ec_feb_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jan_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_wo_sys_ec_jan_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jul_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_wo_sys_ec_jul_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_jun_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_wo_sys_ec_jun_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_mar_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_wo_sys_ec_mar_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_may_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_wo_sys_ec_may_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_nov_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_wo_sys_ec_nov_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_oct_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_wo_sys_ec_oct_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_energy_wo_sys_ec_sep_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_energy_wo_sys_ec_sep_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_excess_kwhs_earned_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_excess_kwhs_earned_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_lifetime_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_lifetime_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_tou_demand_charge_w_sys(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_monthly_tou_demand_charge_w_sys_mget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_tou_demand_charge_wo_sys(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_monthly_tou_demand_charge_wo_sys_mget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_tou_demand_peak_w_sys(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_monthly_tou_demand_peak_w_sys_mget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_tou_demand_peak_wo_sys(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_monthly_tou_demand_peak_wo_sys_mget, self->data_ptr);
}

static PyObject *
Outputs_get_net_billing_credits_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_net_billing_credits_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_nm_dollars_applied_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_nm_dollars_applied_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_savings_year1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_Outputs_savings_year1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_apr_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_surplus_w_sys_ec_apr_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_aug_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_surplus_w_sys_ec_aug_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_dec_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_surplus_w_sys_ec_dec_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_feb_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_surplus_w_sys_ec_feb_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_jan_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_surplus_w_sys_ec_jan_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_jul_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_surplus_w_sys_ec_jul_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_jun_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_surplus_w_sys_ec_jun_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_mar_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_surplus_w_sys_ec_mar_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_may_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_surplus_w_sys_ec_may_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_nov_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_surplus_w_sys_ec_nov_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_oct_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_surplus_w_sys_ec_oct_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_surplus_w_sys_ec_sep_tp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_surplus_w_sys_ec_sep_tp_mget, self->data_ptr);
}

static PyObject *
Outputs_get_true_up_credits_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_true_up_credits_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_two_meter_sales_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_two_meter_sales_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_w_sys(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_utility_bill_w_sys_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_w_sys_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_utility_bill_w_sys_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_wo_sys(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_utility_bill_wo_sys_aget, self->data_ptr);
}

static PyObject *
Outputs_get_utility_bill_wo_sys_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrate5_Outputs_utility_bill_wo_sys_ym_mget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_billing_demand_w_sys(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_billing_demand_w_sys_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_billing_demand_wo_sys(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_billing_demand_wo_sys_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_electric_load(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrate5_Outputs_year1_electric_load_nget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_excess_kwhs_earned(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_excess_kwhs_earned_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_dc_peak_per_period(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_hourly_dc_peak_per_period_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_dc_tou_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_hourly_dc_tou_schedule_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_dc_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_hourly_dc_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_dc_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_hourly_dc_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_e_fromgrid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_hourly_e_fromgrid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_e_tofromgrid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_hourly_e_tofromgrid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_e_togrid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_hourly_e_togrid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_ec_tou_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_hourly_ec_tou_schedule_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_ec_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_hourly_ec_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_ec_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_hourly_ec_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_p_system_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_hourly_p_system_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_p_tofromgrid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_hourly_p_tofromgrid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_salespurchases_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_hourly_salespurchases_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_salespurchases_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_hourly_salespurchases_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_hourly_system_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_hourly_system_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_cumulative_excess_generation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_cumulative_excess_generation_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_fixed_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_dc_fixed_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_fixed_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_dc_fixed_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_tou_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_dc_tou_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_dc_tou_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_dc_tou_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_ec_charge_gross_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_ec_charge_gross_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_ec_charge_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_ec_charge_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_ec_charge_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_ec_charge_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_electricity_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_electricity_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_fixed_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_fixed_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_fixed_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_fixed_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_minimum_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_minimum_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_minimum_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_minimum_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_peak_w_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_peak_w_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_peak_wo_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_peak_wo_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_use_w_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_use_w_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_use_wo_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_use_wo_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_utility_bill_w_sys(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_utility_bill_w_sys_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_monthly_utility_bill_wo_sys(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_monthly_utility_bill_wo_sys_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_net_billing_credits(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_net_billing_credits_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_nm_dollars_applied(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_nm_dollars_applied_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_true_up_credits(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_true_up_credits_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_two_meter_sales(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrate5_Outputs_year1_two_meter_sales_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_electric_load", (getter)Outputs_get_annual_electric_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity load total in each year [kWh]"),
 	NULL},
{"annual_energy_value", (getter)Outputs_get_annual_energy_value,(setter)0,
	PyDoc_STR("*sequence*: Energy value in each year [$]"),
 	NULL},
{"bill_load", (getter)Outputs_get_bill_load,(setter)0,
	PyDoc_STR("*sequence*: Bill load (year 1) [kWh]"),
 	NULL},
{"billing_demand_w_sys_ym", (getter)Outputs_get_billing_demand_w_sys_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Billing demand with system [kW]"),
 	NULL},
{"billing_demand_wo_sys_ym", (getter)Outputs_get_billing_demand_wo_sys_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Billing demand without system [kW]"),
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
{"charge_w_sys_ec_gross_ym", (getter)Outputs_get_charge_w_sys_ec_gross_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Energy charge with system before credits [$]"),
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
{"excess_kwhs_earned_ym", (getter)Outputs_get_excess_kwhs_earned_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Excess generation [kWh]"),
 	NULL},
{"lifetime_load", (getter)Outputs_get_lifetime_load,(setter)0,
	PyDoc_STR("*sequence*: Lifetime electricity load [kW]"),
 	NULL},
{"monthly_tou_demand_charge_w_sys", (getter)Outputs_get_monthly_tou_demand_charge_w_sys,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Demand peak charge with system [$]"),
 	NULL},
{"monthly_tou_demand_charge_wo_sys", (getter)Outputs_get_monthly_tou_demand_charge_wo_sys,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Demand peak charge without system [$]"),
 	NULL},
{"monthly_tou_demand_peak_w_sys", (getter)Outputs_get_monthly_tou_demand_peak_w_sys,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Demand peak with system [kW]"),
 	NULL},
{"monthly_tou_demand_peak_wo_sys", (getter)Outputs_get_monthly_tou_demand_peak_wo_sys,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Demand peak without system [kW]"),
 	NULL},
{"net_billing_credits_ym", (getter)Outputs_get_net_billing_credits_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Net billing credit [$]"),
 	NULL},
{"nm_dollars_applied_ym", (getter)Outputs_get_nm_dollars_applied_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Net metering credit [$]"),
 	NULL},
{"savings_year1", (getter)Outputs_get_savings_year1,(setter)0,
	PyDoc_STR("*float*: Electricity bill savings with system (year 1) [$/yr]"),
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
{"true_up_credits_ym", (getter)Outputs_get_true_up_credits_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Net annual true-up payments [$]"),
 	NULL},
{"two_meter_sales_ym", (getter)Outputs_get_two_meter_sales_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Buy all sell all electricity sales to grid [$]"),
 	NULL},
{"utility_bill_w_sys", (getter)Outputs_get_utility_bill_w_sys,(setter)0,
	PyDoc_STR("*sequence*: Electricity bill with system [$]"),
 	NULL},
{"utility_bill_w_sys_ym", (getter)Outputs_get_utility_bill_w_sys_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity bill with system [$]"),
 	NULL},
{"utility_bill_wo_sys", (getter)Outputs_get_utility_bill_wo_sys,(setter)0,
	PyDoc_STR("*sequence*: Electricity bill without system [$]"),
 	NULL},
{"utility_bill_wo_sys_ym", (getter)Outputs_get_utility_bill_wo_sys_ym,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Electricity bill without system [$]"),
 	NULL},
{"year1_billing_demand_w_sys", (getter)Outputs_get_year1_billing_demand_w_sys,(setter)0,
	PyDoc_STR("*sequence*: Billing demand with system [kW]"),
 	NULL},
{"year1_billing_demand_wo_sys", (getter)Outputs_get_year1_billing_demand_wo_sys,(setter)0,
	PyDoc_STR("*sequence*: Billing demand without system [kW]"),
 	NULL},
{"year1_electric_load", (getter)Outputs_get_year1_electric_load,(setter)0,
	PyDoc_STR("*float*: Electricity load total (year 1) [kWh/yr]"),
 	NULL},
{"year1_excess_kwhs_earned", (getter)Outputs_get_year1_excess_kwhs_earned,(setter)0,
	PyDoc_STR("*sequence*: Excess generation [kWh/mo]"),
 	NULL},
{"year1_hourly_dc_peak_per_period", (getter)Outputs_get_year1_hourly_dc_peak_per_period,(setter)0,
	PyDoc_STR("*sequence*: Electricity peak from grid per TOU period (year 1 hourly) [kW]"),
 	NULL},
{"year1_hourly_dc_tou_schedule", (getter)Outputs_get_year1_hourly_dc_tou_schedule,(setter)0,
	PyDoc_STR("*sequence*: TOU period for demand charges (year 1 hourly)"),
 	NULL},
{"year1_hourly_dc_with_system", (getter)Outputs_get_year1_hourly_dc_with_system,(setter)0,
	PyDoc_STR("*sequence*: Incremental demand charge with system (year 1 hourly) [$]"),
 	NULL},
{"year1_hourly_dc_without_system", (getter)Outputs_get_year1_hourly_dc_without_system,(setter)0,
	PyDoc_STR("*sequence*: Incremental demand charge without system (year 1 hourly) [$]"),
 	NULL},
{"year1_hourly_e_fromgrid", (getter)Outputs_get_year1_hourly_e_fromgrid,(setter)0,
	PyDoc_STR("*sequence*: Electricity from grid (year 1 hourly) [kWh]"),
 	NULL},
{"year1_hourly_e_tofromgrid", (getter)Outputs_get_year1_hourly_e_tofromgrid,(setter)0,
	PyDoc_STR("*sequence*: Electricity to/from grid (year 1 hourly) [kWh]"),
 	NULL},
{"year1_hourly_e_togrid", (getter)Outputs_get_year1_hourly_e_togrid,(setter)0,
	PyDoc_STR("*sequence*: Electricity to grid (year 1 hourly) [kWh]"),
 	NULL},
{"year1_hourly_ec_tou_schedule", (getter)Outputs_get_year1_hourly_ec_tou_schedule,(setter)0,
	PyDoc_STR("*sequence*: TOU period for energy charges (year 1 hourly)"),
 	NULL},
{"year1_hourly_ec_with_system", (getter)Outputs_get_year1_hourly_ec_with_system,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system (year 1 hourly) [$]"),
 	NULL},
{"year1_hourly_ec_without_system", (getter)Outputs_get_year1_hourly_ec_without_system,(setter)0,
	PyDoc_STR("*sequence*: Energy charge without system (year 1 hourly) [$]"),
 	NULL},
{"year1_hourly_p_system_to_load", (getter)Outputs_get_year1_hourly_p_system_to_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity peak from system to load (year 1 hourly) [kW]"),
 	NULL},
{"year1_hourly_p_tofromgrid", (getter)Outputs_get_year1_hourly_p_tofromgrid,(setter)0,
	PyDoc_STR("*sequence*: Electricity to/from grid peak (year 1 hourly) [kW]"),
 	NULL},
{"year1_hourly_salespurchases_with_system", (getter)Outputs_get_year1_hourly_salespurchases_with_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity sales/purchases with system (year 1 hourly) [$]"),
 	NULL},
{"year1_hourly_salespurchases_without_system", (getter)Outputs_get_year1_hourly_salespurchases_without_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity sales/purchases without system (year 1 hourly) [$]"),
 	NULL},
{"year1_hourly_system_to_load", (getter)Outputs_get_year1_hourly_system_to_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity from system to load (year 1 hourly) [kWh]"),
 	NULL},
{"year1_monthly_cumulative_excess_generation", (getter)Outputs_get_year1_monthly_cumulative_excess_generation,(setter)0,
	PyDoc_STR("*sequence*: Net metering cumulative credit for annual true-up [kWh/mo]"),
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
{"year1_monthly_ec_charge_gross_with_system", (getter)Outputs_get_year1_monthly_ec_charge_gross_with_system,(setter)0,
	PyDoc_STR("*sequence*: Energy charge with system before credits [$/mo]"),
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
	PyDoc_STR("*sequence*: Demand peak with system [kW/mo]"),
 	NULL},
{"year1_monthly_peak_wo_system", (getter)Outputs_get_year1_monthly_peak_wo_system,(setter)0,
	PyDoc_STR("*sequence*: Demand peak without system [kW/mo]"),
 	NULL},
{"year1_monthly_use_w_system", (getter)Outputs_get_year1_monthly_use_w_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity use with system [kWh/mo]"),
 	NULL},
{"year1_monthly_use_wo_system", (getter)Outputs_get_year1_monthly_use_wo_system,(setter)0,
	PyDoc_STR("*sequence*: Electricity use without system [kWh/mo]"),
 	NULL},
{"year1_monthly_utility_bill_w_sys", (getter)Outputs_get_year1_monthly_utility_bill_w_sys,(setter)0,
	PyDoc_STR("*sequence*: Electricity bill with system [$/mo]"),
 	NULL},
{"year1_monthly_utility_bill_wo_sys", (getter)Outputs_get_year1_monthly_utility_bill_wo_sys,(setter)0,
	PyDoc_STR("*sequence*: Electricity bill without system [$/mo]"),
 	NULL},
{"year1_net_billing_credits", (getter)Outputs_get_year1_net_billing_credits,(setter)0,
	PyDoc_STR("*sequence*: Net billing credit [$/mo]"),
 	NULL},
{"year1_nm_dollars_applied", (getter)Outputs_get_year1_nm_dollars_applied,(setter)0,
	PyDoc_STR("*sequence*: Net metering credit [$/mo]"),
 	NULL},
{"year1_true_up_credits", (getter)Outputs_get_year1_true_up_credits,(setter)0,
	PyDoc_STR("*sequence*: Net annual true-up payments [$/mo]"),
 	NULL},
{"year1_two_meter_sales", (getter)Outputs_get_year1_two_meter_sales,(setter)0,
	PyDoc_STR("*sequence*: Buy all sell all electricity sales to grid [$/mo]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate5.Outputs",             /*tp_name*/
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
 * Utilityrate5
 */

static PyTypeObject Utilityrate5_Type;

static CmodObject *
newUtilityrate5Object(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Utilityrate5_Type);

	PySAM_TECH_ATTR()

	PyObject* Lifetime_obj = Lifetime_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Lifetime", Lifetime_obj);
	Py_DECREF(Lifetime_obj);

	PyObject* ElectricityRates_obj = ElectricityRates_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ElectricityRates", ElectricityRates_obj);
	Py_DECREF(ElectricityRates_obj);

	PyObject* SystemOutput_obj = SystemOutput_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemOutput", SystemOutput_obj);
	Py_DECREF(SystemOutput_obj);

	PyObject* Load_obj = Load_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Load", Load_obj);
	Py_DECREF(Load_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Utilityrate5 methods */

static void
Utilityrate5_dealloc(CmodObject *self)
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
Utilityrate5_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Utilityrate5_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Utilityrate5_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Utilityrate5"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Utilityrate5_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Utilityrate5"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Utilityrate5_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Utilityrate5_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Utilityrate5_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Utilityrate5_methods[] = {
		{"execute",           (PyCFunction)Utilityrate5_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Utilityrate5_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Lifetime': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Utilityrate5_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Lifetime': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Utilityrate5_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Utilityrate5_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Utilityrate5_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Utilityrate5_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Utilityrate5_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Utilityrate5_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrate5",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Utilityrate5_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Utilityrate5_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Utilityrate5_getattro, /*tp_getattro*/
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
		Utilityrate5_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Utilityrate5 object */

static PyObject *
Utilityrate5_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newUtilityrate5Object(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Utilityrate5_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newUtilityrate5Object((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Utilityrate5_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newUtilityrate5Object(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Utilityrate5", def) < 0) {
		Utilityrate5_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Utilityrate5_from_existing(PyObject *self, PyObject *args)
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

	rv = newUtilityrate5Object((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Utilityrate5", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Utilityrate5Module_methods[] = {
		{"new",             Utilityrate5_new,         METH_VARARGS,
				PyDoc_STR("new() -> Utilityrate5")},
		{"default",             Utilityrate5_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Utilityrate5\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"BiopowerAllEquityPartnershipFlip\"*\n\n		- *\"BiopowerLeveragedPartnershipFlip\"*\n\n		- *\"BiopowerMerchantPlant\"*\n\n		- *\"BiopowerSaleLeaseback\"*\n\n		- *\"BiopowerSingleOwner\"*\n\n		- *\"DSLFAllEquityPartnershipFlip\"*\n\n		- *\"DSLFCommercial\"*\n\n		- *\"DSLFLeveragedPartnershipFlip\"*\n\n		- *\"DSLFMerchantPlant\"*\n\n		- *\"DSLFSaleLeaseback\"*\n\n		- *\"DSLFSingleOwner\"*\n\n		- *\"EmpiricalTroughAllEquityPartnershipFlip\"*\n\n		- *\"EmpiricalTroughCommercial\"*\n\n		- *\"EmpiricalTroughLeveragedPartnershipFlip\"*\n\n		- *\"EmpiricalTroughMerchantPlant\"*\n\n		- *\"EmpiricalTroughSaleLeaseback\"*\n\n		- *\"EmpiricalTroughSingleOwner\"*\n\n		- *\"FlatPlatePVAllEquityPartnershipFlip\"*\n\n		- *\"FlatPlatePVCommercial\"*\n\n		- *\"FlatPlatePVHostDeveloper\"*\n\n		- *\"FlatPlatePVLeveragedPartnershipFlip\"*\n\n		- *\"FlatPlatePVMerchantPlant\"*\n\n		- *\"FlatPlatePVResidential\"*\n\n		- *\"FlatPlatePVSaleLeaseback\"*\n\n		- *\"FlatPlatePVSingleOwner\"*\n\n		- *\"FlatPlatePVThirdParty\"*\n\n		- *\"FuelCellCommercial\"*\n\n		- *\"FuelCellSingleOwner\"*\n\n		- *\"GenericBatteryAllEquityPartnershipFlip\"*\n\n		- *\"GenericBatteryCommercial\"*\n\n		- *\"GenericBatteryHostDeveloper\"*\n\n		- *\"GenericBatteryLeveragedPartnershipFlip\"*\n\n		- *\"GenericBatteryMerchantPlant\"*\n\n		- *\"GenericBatteryResidential\"*\n\n		- *\"GenericBatterySaleLeaseback\"*\n\n		- *\"GenericBatterySingleOwner\"*\n\n		- *\"GenericBatteryThirdParty\"*\n\n		- *\"GenericCSPSystemAllEquityPartnershipFlip\"*\n\n		- *\"GenericCSPSystemCommercial\"*\n\n		- *\"GenericCSPSystemLeveragedPartnershipFlip\"*\n\n		- *\"GenericCSPSystemMerchantPlant\"*\n\n		- *\"GenericCSPSystemSaleLeaseback\"*\n\n		- *\"GenericCSPSystemSingleOwner\"*\n\n		- *\"GenericSystemAllEquityPartnershipFlip\"*\n\n		- *\"GenericSystemCommercial\"*\n\n		- *\"GenericSystemHostDeveloper\"*\n\n		- *\"GenericSystemLeveragedPartnershipFlip\"*\n\n		- *\"GenericSystemMerchantPlant\"*\n\n		- *\"GenericSystemResidential\"*\n\n		- *\"GenericSystemSaleLeaseback\"*\n\n		- *\"GenericSystemSingleOwner\"*\n\n		- *\"GenericSystemThirdParty\"*\n\n		- *\"GeothermalPowerAllEquityPartnershipFlip\"*\n\n		- *\"GeothermalPowerLeveragedPartnershipFlip\"*\n\n		- *\"GeothermalPowerMerchantPlant\"*\n\n		- *\"GeothermalPowerSaleLeaseback\"*\n\n		- *\"GeothermalPowerSingleOwner\"*\n\n		- *\"HighXConcentratingPVAllEquityPartnershipFlip\"*\n\n		- *\"HighXConcentratingPVLeveragedPartnershipFlip\"*\n\n		- *\"HighXConcentratingPVMerchantPlant\"*\n\n		- *\"HighXConcentratingPVSaleLeaseback\"*\n\n		- *\"HighXConcentratingPVSingleOwner\"*\n\n		- *\"MEwaveBatterySingleOwner\"*\n\n		- *\"MEwaveSingleOwner\"*\n\n		- *\"MSLFAllEquityPartnershipFlip\"*\n\n		- *\"MSLFCommercial\"*\n\n		- *\"MSLFLeveragedPartnershipFlip\"*\n\n		- *\"MSLFMerchantPlant\"*\n\n		- *\"MSLFSaleLeaseback\"*\n\n		- *\"MSLFSingleOwner\"*\n\n		- *\"MSPTAllEquityPartnershipFlip\"*\n\n		- *\"MSPTLeveragedPartnershipFlip\"*\n\n		- *\"MSPTMerchantPlant\"*\n\n		- *\"MSPTSaleLeaseback\"*\n\n		- *\"MSPTSingleOwner\"*\n\n		- *\"PVBatteryAllEquityPartnershipFlip\"*\n\n		- *\"PVBatteryCommercial\"*\n\n		- *\"PVBatteryHostDeveloper\"*\n\n		- *\"PVBatteryLeveragedPartnershipFlip\"*\n\n		- *\"PVBatteryMerchantPlant\"*\n\n		- *\"PVBatteryResidential\"*\n\n		- *\"PVBatterySaleLeaseback\"*\n\n		- *\"PVBatterySingleOwner\"*\n\n		- *\"PVBatteryThirdParty\"*\n\n		- *\"PVWattsBatteryCommercial\"*\n\n		- *\"PVWattsBatteryHostDeveloper\"*\n\n		- *\"PVWattsBatteryResidential\"*\n\n		- *\"PVWattsBatteryThirdParty\"*\n\n		- *\"PVWattsAllEquityPartnershipFlip\"*\n\n		- *\"PVWattsCommercial\"*\n\n		- *\"PVWattsHostDeveloper\"*\n\n		- *\"PVWattsLeveragedPartnershipFlip\"*\n\n		- *\"PVWattsMerchantPlant\"*\n\n		- *\"PVWattsResidential\"*\n\n		- *\"PVWattsSaleLeaseback\"*\n\n		- *\"PVWattsSingleOwner\"*\n\n		- *\"PVWattsThirdParty\"*\n\n		- *\"PhysicalTroughAllEquityPartnershipFlip\"*\n\n		- *\"PhysicalTroughLeveragedPartnershipFlip\"*\n\n		- *\"PhysicalTroughMerchantPlant\"*\n\n		- *\"PhysicalTroughSaleLeaseback\"*\n\n		- *\"PhysicalTroughSingleOwner\"*\n\n		- *\"SolarWaterHeatingCommercial\"*\n\n		- *\"SolarWaterHeatingResidential\"*\n\n		- *\"StandaloneBatteryAllEquityPartnershipFlip\"*\n\n		- *\"StandaloneBatteryCommercial\"*\n\n		- *\"StandaloneBatteryHostDeveloper\"*\n\n		- *\"StandaloneBatteryLeveragedPartnershipFlip\"*\n\n		- *\"StandaloneBatteryMerchantPlant\"*\n\n		- *\"StandaloneBatteryResidential\"*\n\n		- *\"StandaloneBatterySaleLeaseback\"*\n\n		- *\"StandaloneBatterySingleOwner\"*\n\n		- *\"StandaloneBatteryThirdParty\"*\n\n		- *\"WindPowerAllEquityPartnershipFlip\"*\n\n		- *\"WindPowerCommercial\"*\n\n		- *\"WindPowerLeveragedPartnershipFlip\"*\n\n		- *\"WindPowerMerchantPlant\"*\n\n		- *\"WindPowerResidential\"*\n\n		- *\"WindPowerSaleLeaseback\"*\n\n		- *\"WindPowerSingleOwner\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Utilityrate5_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Utilityrate5\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Utilityrate5_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Utilityrate5\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Retail electricity bill calculator");


static int
Utilityrate5Module_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Utilityrate5_Type.tp_dict = PyDict_New();
	if (!Utilityrate5_Type.tp_dict) { goto fail; }

	/// Add the Lifetime type object to Utilityrate5_Type
	if (PyType_Ready(&Lifetime_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate5_Type.tp_dict,
				"Lifetime",
				(PyObject*)&Lifetime_Type);
	Py_DECREF(&Lifetime_Type);

	/// Add the ElectricityRates type object to Utilityrate5_Type
	if (PyType_Ready(&ElectricityRates_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate5_Type.tp_dict,
				"ElectricityRates",
				(PyObject*)&ElectricityRates_Type);
	Py_DECREF(&ElectricityRates_Type);

	/// Add the SystemOutput type object to Utilityrate5_Type
	if (PyType_Ready(&SystemOutput_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate5_Type.tp_dict,
				"SystemOutput",
				(PyObject*)&SystemOutput_Type);
	Py_DECREF(&SystemOutput_Type);

	/// Add the Load type object to Utilityrate5_Type
	if (PyType_Ready(&Load_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate5_Type.tp_dict,
				"Load",
				(PyObject*)&Load_Type);
	Py_DECREF(&Load_Type);

	/// Add the Outputs type object to Utilityrate5_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrate5_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Utilityrate5 type object to the module
	if (PyType_Ready(&Utilityrate5_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Utilityrate5",
				(PyObject*)&Utilityrate5_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Utilityrate5Module_slots[] = {
		{Py_mod_exec, Utilityrate5Module_exec},
		{0, NULL},
};

static struct PyModuleDef Utilityrate5Module = {
		PyModuleDef_HEAD_INIT,
		"Utilityrate5",
		module_doc,
		0,
		Utilityrate5Module_methods,
		Utilityrate5Module_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Utilityrate5(void)
{
	return PyModuleDef_Init(&Utilityrate5Module);
}