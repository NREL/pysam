#include <Python.h>

#include <SAM_Utilityrateforecast.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * ElectricityRates Group
 */ 

static PyTypeObject ElectricityRates_Type;

static PyObject *
ElectricityRates_new(SAM_Utilityrateforecast data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrateforecast", "ElectricityRates")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Utilityrateforecast", "ElectricityRates")){
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
ElectricityRates_get_en_electricity_rates(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrateforecast_ElectricityRates_en_electricity_rates_nget, self->data_ptr);
}

static int
ElectricityRates_set_en_electricity_rates(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrateforecast_ElectricityRates_en_electricity_rates_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrateforecast_ElectricityRates_gen_aget, self->data_ptr);
}

static int
ElectricityRates_set_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrateforecast_ElectricityRates_gen_aset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_grid_power(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrateforecast_ElectricityRates_grid_power_aget, self->data_ptr);
}

static int
ElectricityRates_set_grid_power(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrateforecast_ElectricityRates_grid_power_aset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrateforecast_ElectricityRates_load_aget, self->data_ptr);
}

static int
ElectricityRates_set_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrateforecast_ElectricityRates_load_aset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_rate_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrateforecast_ElectricityRates_rate_escalation_aget, self->data_ptr);
}

static int
ElectricityRates_set_rate_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrateforecast_ElectricityRates_rate_escalation_aset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_annual_min_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrateforecast_ElectricityRates_ur_annual_min_charge_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_annual_min_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_annual_min_charge_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_billing_demand_lookback_percentages(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrateforecast_ElectricityRates_ur_billing_demand_lookback_percentages_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_billing_demand_lookback_percentages(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_billing_demand_lookback_percentages_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_billing_demand_lookback_period(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrateforecast_ElectricityRates_ur_billing_demand_lookback_period_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_billing_demand_lookback_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_billing_demand_lookback_period_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_billing_demand_minimum(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrateforecast_ElectricityRates_ur_billing_demand_minimum_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_billing_demand_minimum(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_billing_demand_minimum_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_billing_demand_periods(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrateforecast_ElectricityRates_ur_dc_billing_demand_periods_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_billing_demand_periods(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_dc_billing_demand_periods_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrateforecast_ElectricityRates_ur_dc_enable_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_dc_enable_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_flat_mat(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrateforecast_ElectricityRates_ur_dc_flat_mat_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_flat_mat(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_dc_flat_mat_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_peaks(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrateforecast_ElectricityRates_ur_dc_peaks_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_peaks(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_dc_peaks_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrateforecast_ElectricityRates_ur_dc_sched_weekday_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_dc_sched_weekday_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrateforecast_ElectricityRates_ur_dc_sched_weekend_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_dc_sched_weekend_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_tou_mat(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrateforecast_ElectricityRates_ur_dc_tou_mat_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_tou_mat(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_dc_tou_mat_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ec_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrateforecast_ElectricityRates_ur_ec_sched_weekday_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ec_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_ec_sched_weekday_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ec_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrateforecast_ElectricityRates_ur_ec_sched_weekend_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ec_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_ec_sched_weekend_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ec_tou_mat(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrateforecast_ElectricityRates_ur_ec_tou_mat_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ec_tou_mat(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_ec_tou_mat_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_en_ts_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrateforecast_ElectricityRates_ur_en_ts_buy_rate_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_en_ts_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_en_ts_buy_rate_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_en_ts_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrateforecast_ElectricityRates_ur_en_ts_sell_rate_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_en_ts_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_en_ts_sell_rate_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_enable_billing_demand(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrateforecast_ElectricityRates_ur_enable_billing_demand_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_enable_billing_demand(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_enable_billing_demand_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_energy_use(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Utilityrateforecast_ElectricityRates_ur_energy_use_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_energy_use(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_energy_use_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_metering_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrateforecast_ElectricityRates_ur_metering_option_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_metering_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_metering_option_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_monthly_fixed_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrateforecast_ElectricityRates_ur_monthly_fixed_charge_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_monthly_fixed_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_monthly_fixed_charge_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_monthly_min_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrateforecast_ElectricityRates_ur_monthly_min_charge_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_monthly_min_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_monthly_min_charge_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_nm_credit_month(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrateforecast_ElectricityRates_ur_nm_credit_month_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_nm_credit_month(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_nm_credit_month_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_nm_credit_rollover(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrateforecast_ElectricityRates_ur_nm_credit_rollover_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_nm_credit_rollover(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_nm_credit_rollover_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_nm_yearend_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrateforecast_ElectricityRates_ur_nm_yearend_sell_rate_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_nm_yearend_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_nm_yearend_sell_rate_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_sell_eq_buy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrateforecast_ElectricityRates_ur_sell_eq_buy_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_sell_eq_buy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_sell_eq_buy_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ts_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrateforecast_ElectricityRates_ur_ts_buy_rate_aget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ts_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_ts_buy_rate_aset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ts_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrateforecast_ElectricityRates_ur_ts_sell_rate_aget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ts_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_ts_sell_rate_aset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_yearzero_usage_peaks(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrateforecast_ElectricityRates_ur_yearzero_usage_peaks_aget, self->data_ptr);
}

static int
ElectricityRates_set_ur_yearzero_usage_peaks(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Utilityrateforecast_ElectricityRates_ur_yearzero_usage_peaks_aset, self->data_ptr);
}

static PyGetSetDef ElectricityRates_getset[] = {
{"en_electricity_rates", (getter)ElectricityRates_get_en_electricity_rates,(setter)ElectricityRates_set_en_electricity_rates,
	PyDoc_STR("*float*: Optionally enable/disable electricity_rate [years]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1"),
 	NULL},
{"gen", (getter)ElectricityRates_get_gen,(setter)ElectricityRates_set_gen,
	PyDoc_STR("*sequence*: Lifetime generation forecast"),
 	NULL},
{"grid_power", (getter)ElectricityRates_get_grid_power,(setter)ElectricityRates_set_grid_power,
	PyDoc_STR("*sequence*: Electricity to/from grid"),
 	NULL},
{"load", (getter)ElectricityRates_get_load,(setter)ElectricityRates_set_load,
	PyDoc_STR("*sequence*: Lifetime load forecast"),
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
{"ur_dc_peaks", (getter)ElectricityRates_get_ur_dc_peaks,(setter)ElectricityRates_set_ur_dc_peaks,
	PyDoc_STR("*sequence[sequence]*: Peak demand by month and period\n\n**INOUT:** This variable is both an input and an output to the compute module."),
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
{"ur_energy_use", (getter)ElectricityRates_get_ur_energy_use,(setter)ElectricityRates_set_ur_energy_use,
	PyDoc_STR("*sequence[sequence]*: Energy use or surplus by month and period\n\n**INOUT:** This variable is both an input and an output to the compute module."),
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
		"Utilityrateforecast.ElectricityRates",             /*tp_name*/
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
 * Lifetime Group
 */ 

static PyTypeObject Lifetime_Type;

static PyObject *
Lifetime_new(SAM_Utilityrateforecast data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrateforecast", "Lifetime")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Utilityrateforecast", "Lifetime")){
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
	return PySAM_double_getter(SAM_Utilityrateforecast_Lifetime_analysis_period_nget, self->data_ptr);
}

static int
Lifetime_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrateforecast_Lifetime_analysis_period_nset, self->data_ptr);
}

static PyObject *
Lifetime_get_inflation_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrateforecast_Lifetime_inflation_rate_nget, self->data_ptr);
}

static int
Lifetime_set_inflation_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrateforecast_Lifetime_inflation_rate_nset, self->data_ptr);
}

static PyGetSetDef Lifetime_getset[] = {
{"analysis_period", (getter)Lifetime_get_analysis_period,(setter)Lifetime_set_analysis_period,
	PyDoc_STR("*float*: Number of years in escalation and forecast [years]\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"inflation_rate", (getter)Lifetime_get_inflation_rate,(setter)Lifetime_set_inflation_rate,
	PyDoc_STR("*float*: Inflation rate [%]\n\n**Constraints:**\nMIN=-99\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Lifetime_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrateforecast.Lifetime",             /*tp_name*/
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
 * Controls Group
 */ 

static PyTypeObject Controls_Type;

static PyObject *
Controls_new(SAM_Utilityrateforecast data_ptr)
{
	PyObject* new_obj = Controls_Type.tp_alloc(&Controls_Type,0);

	VarGroupObject* Controls_obj = (VarGroupObject*)new_obj;

	Controls_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Controls methods */

static PyObject *
Controls_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrateforecast", "Controls")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Controls_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Controls_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Utilityrateforecast", "Controls")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Controls_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Controls_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Controls_methods[] = {
		{"assign",            (PyCFunction)Controls_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Controls_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Controls_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Controls_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Controls_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Controls_get_idx(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrateforecast_Controls_idx_nget, self->data_ptr);
}

static int
Controls_set_idx(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrateforecast_Controls_idx_nset, self->data_ptr);
}

static PyObject *
Controls_get_steps_per_hour(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrateforecast_Controls_steps_per_hour_nget, self->data_ptr);
}

static int
Controls_set_steps_per_hour(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Utilityrateforecast_Controls_steps_per_hour_nset, self->data_ptr);
}

static PyGetSetDef Controls_getset[] = {
{"idx", (getter)Controls_get_idx,(setter)Controls_set_idx,
	PyDoc_STR("*float*: Starting index (lifetime)\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"steps_per_hour", (getter)Controls_get_steps_per_hour,(setter)Controls_set_steps_per_hour,
	PyDoc_STR("*float*: Steps per hour [hr]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Controls_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrateforecast.Controls",             /*tp_name*/
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
		Controls_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Controls_getset,          /*tp_getset*/
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
Outputs_new(SAM_Utilityrateforecast data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Utilityrateforecast", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Utilityrateforecast", "Outputs")){
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
Outputs_get_ur_price_series(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Utilityrateforecast_Outputs_ur_price_series_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ur_total_bill(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Utilityrateforecast_Outputs_ur_total_bill_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"ur_price_series", (getter)Outputs_get_ur_price_series,(setter)0,
	PyDoc_STR("*sequence*: Estimated cost of each timestep [$]"),
 	NULL},
{"ur_total_bill", (getter)Outputs_get_ur_total_bill,(setter)0,
	PyDoc_STR("*float*: Total cost for the calculated period [$]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrateforecast.Outputs",             /*tp_name*/
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
 * Utilityrateforecast
 */

static PyTypeObject Utilityrateforecast_Type;

static CmodStatefulObject *
newUtilityrateforecastObject(void* data_ptr)
{
	CmodStatefulObject *self;
	self = PyObject_New(CmodStatefulObject, &Utilityrateforecast_Type);

	PySAM_TECH_ATTR()

	PyObject* ElectricityRates_obj = ElectricityRates_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ElectricityRates", ElectricityRates_obj);
	Py_DECREF(ElectricityRates_obj);

	PyObject* Lifetime_obj = Lifetime_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Lifetime", Lifetime_obj);
	Py_DECREF(Lifetime_obj);

	PyObject* Controls_obj = Controls_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Controls", Controls_obj);
	Py_DECREF(Controls_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Utilityrateforecast methods */

static void
Utilityrateforecast_dealloc(CmodStatefulObject *self)
{
	Py_XDECREF(self->x_attr);

	if (!self->data_owner_ptr) {
		SAM_error error = new_error();
		SAM_table_destruct(self->data_ptr, &error);
		PySAM_has_error(error);
	}
	if (self->cmod_ptr) {
		SAM_error error = new_error();
		SAM_module_destruct(self->cmod_ptr, &error);
		PySAM_has_error(error);
	}
	PyObject_Del(self);
}


static PyObject *
Utilityrateforecast_setup(CmodStatefulObject *self, PyObject *args)
{
	SAM_error error = new_error();
	self->cmod_ptr = SAM_Utilityrateforecast_setup(self->data_ptr, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Utilityrateforecast_execute(CmodStatefulObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_stateful_module_exec(self->cmod_ptr, self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Utilityrateforecast_assign(CmodStatefulObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Utilityrateforecast"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Utilityrateforecast_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Utilityrateforecast"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Utilityrateforecast_export(CmodStatefulObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Utilityrateforecast_value(CmodStatefulObject *self, PyObject *args)
{
	return CmodStateful_value(self, args);
}

static PyObject *
Utilityrateforecast_unassign(CmodStatefulObject *self, PyObject *args)
{
	return CmodStateful_unassign(self, args);
}

static PyMethodDef Utilityrateforecast_methods[] = {
		{"setup",            (PyCFunction)Utilityrateforecast_setup,  METH_VARARGS,
				PyDoc_STR("setup() -> None\n Setup parameters in simulation")},
		{"execute",           (PyCFunction)Utilityrateforecast_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Utilityrateforecast_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Electricity Rates': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Utilityrateforecast_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Electricity Rates': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Utilityrateforecast_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Utilityrateforecast_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Utilityrateforecast_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Utilityrateforecast_getattro(CmodStatefulObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Utilityrateforecast_setattr(CmodStatefulObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Utilityrateforecast_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Utilityrateforecast",            /*tp_name*/
		sizeof(CmodStatefulObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Utilityrateforecast_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Utilityrateforecast_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Utilityrateforecast_getattro, /*tp_getattro*/
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
		Utilityrateforecast_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Utilityrateforecast object */

static PyObject *
Utilityrateforecast_new(PyObject *self, PyObject *args)
{
	CmodStatefulObject *rv;
	rv = newUtilityrateforecastObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	rv->cmod_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Utilityrateforecast_wrap(PyObject *self, PyObject *args)
{
	CmodStatefulObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newUtilityrateforecastObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	rv->cmod_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Utilityrateforecast_default(PyObject *self, PyObject *args)
{
	CmodStatefulObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newUtilityrateforecastObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Utilityrateforecast", def) < 0) {
		Utilityrateforecast_dealloc(rv);
		return NULL;
	}
	rv->cmod_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Utilityrateforecast_from_existing(PyObject *self, PyObject *args)
{
	CmodStatefulObject *rv;
	PyObject * module = 0;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "O|s:from_existing", &module, &def)){
		PyErr_BadArgument();
		return NULL;
	}
	CmodStatefulObject *module_obj = (CmodStatefulObject *)module;
	SAM_table ptr = module_obj->data_ptr;

	// do a rough validity check on the data by checking its size
	SAM_error error = new_error();
	int data_size = SAM_table_size(ptr, &error);
	if (PySAM_has_error(error))
		goto fail;
	if (data_size < 0)
		goto fail;

	rv = newUtilityrateforecastObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	rv->cmod_ptr = NULL;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Utilityrateforecast", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef UtilityrateforecastModule_methods[] = {
		{"new",             Utilityrateforecast_new,         METH_VARARGS,
				PyDoc_STR("new() -> Utilityrateforecast")},
		{"default",             Utilityrateforecast_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Utilityrateforecast\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Utilityrateforecast_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Utilityrateforecast\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Utilityrateforecast_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Utilityrateforecast\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Utilityrateforecast");


static int
UtilityrateforecastModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Utilityrateforecast_Type.tp_dict = PyDict_New();
	if (!Utilityrateforecast_Type.tp_dict) { goto fail; }

	/// Add the ElectricityRates type object to Utilityrateforecast_Type
	if (PyType_Ready(&ElectricityRates_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrateforecast_Type.tp_dict,
				"ElectricityRates",
				(PyObject*)&ElectricityRates_Type);
	Py_DECREF(&ElectricityRates_Type);

	/// Add the Lifetime type object to Utilityrateforecast_Type
	if (PyType_Ready(&Lifetime_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrateforecast_Type.tp_dict,
				"Lifetime",
				(PyObject*)&Lifetime_Type);
	Py_DECREF(&Lifetime_Type);

	/// Add the Controls type object to Utilityrateforecast_Type
	if (PyType_Ready(&Controls_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrateforecast_Type.tp_dict,
				"Controls",
				(PyObject*)&Controls_Type);
	Py_DECREF(&Controls_Type);

	/// Add the Outputs type object to Utilityrateforecast_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Utilityrateforecast_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Utilityrateforecast type object to the module
	if (PyType_Ready(&Utilityrateforecast_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Utilityrateforecast",
				(PyObject*)&Utilityrateforecast_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot UtilityrateforecastModule_slots[] = {
		{Py_mod_exec, UtilityrateforecastModule_exec},
		{0, NULL},
};

static struct PyModuleDef UtilityrateforecastModule = {
		PyModuleDef_HEAD_INIT,
		"Utilityrateforecast",
		module_doc,
		0,
		UtilityrateforecastModule_methods,
		UtilityrateforecastModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Utilityrateforecast(void)
{
	return PyModuleDef_Init(&UtilityrateforecastModule);
}