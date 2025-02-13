#include <Python.h>

#include <SAM_HostDeveloper.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Revenue Group
 */ 

static PyTypeObject Revenue_Type;

static PyObject *
Revenue_new(SAM_HostDeveloper data_ptr)
{
	PyObject* new_obj = Revenue_Type.tp_alloc(&Revenue_Type,0);

	VarGroupObject* Revenue_obj = (VarGroupObject*)new_obj;

	Revenue_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Revenue methods */

static PyObject *
Revenue_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "Revenue")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Revenue_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Revenue_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "Revenue")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Revenue_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Revenue_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Revenue_methods[] = {
		{"assign",            (PyCFunction)Revenue_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Revenue_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Revenue_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Revenue_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Revenue_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Revenue_get_dispatch_factors_ts(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Revenue_dispatch_factors_ts_aget, self->data_ptr);
}

static int
Revenue_set_dispatch_factors_ts(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_Revenue_dispatch_factors_ts_aset, self->data_ptr);
}

static PyObject *
Revenue_get_dispatch_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_HostDeveloper_Revenue_dispatch_sched_weekday_mget, self->data_ptr);
}

static int
Revenue_set_dispatch_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_HostDeveloper_Revenue_dispatch_sched_weekday_mset, self->data_ptr);
}

static PyObject *
Revenue_get_dispatch_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_HostDeveloper_Revenue_dispatch_sched_weekend_mget, self->data_ptr);
}

static int
Revenue_set_dispatch_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_HostDeveloper_Revenue_dispatch_sched_weekend_mset, self->data_ptr);
}

static PyObject *
Revenue_get_dispatch_tod_factors(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Revenue_dispatch_tod_factors_aget, self->data_ptr);
}

static int
Revenue_set_dispatch_tod_factors(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_Revenue_dispatch_tod_factors_aset, self->data_ptr);
}

static PyObject *
Revenue_get_flip_target_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Revenue_flip_target_percent_nget, self->data_ptr);
}

static int
Revenue_set_flip_target_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Revenue_flip_target_percent_nset, self->data_ptr);
}

static PyObject *
Revenue_get_flip_target_year(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Revenue_flip_target_year_nget, self->data_ptr);
}

static int
Revenue_set_flip_target_year(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Revenue_flip_target_year_nset, self->data_ptr);
}

static PyObject *
Revenue_get_ppa_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Revenue_ppa_escalation_nget, self->data_ptr);
}

static int
Revenue_set_ppa_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Revenue_ppa_escalation_nset, self->data_ptr);
}

static PyObject *
Revenue_get_ppa_multiplier_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Revenue_ppa_multiplier_model_nget, self->data_ptr);
}

static int
Revenue_set_ppa_multiplier_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Revenue_ppa_multiplier_model_nset, self->data_ptr);
}

static PyObject *
Revenue_get_ppa_price_input(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Revenue_ppa_price_input_aget, self->data_ptr);
}

static int
Revenue_set_ppa_price_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_Revenue_ppa_price_input_aset, self->data_ptr);
}

static PyObject *
Revenue_get_ppa_soln_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Revenue_ppa_soln_max_nget, self->data_ptr);
}

static int
Revenue_set_ppa_soln_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Revenue_ppa_soln_max_nset, self->data_ptr);
}

static PyObject *
Revenue_get_ppa_soln_max_iterations(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Revenue_ppa_soln_max_iterations_nget, self->data_ptr);
}

static int
Revenue_set_ppa_soln_max_iterations(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Revenue_ppa_soln_max_iterations_nset, self->data_ptr);
}

static PyObject *
Revenue_get_ppa_soln_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Revenue_ppa_soln_min_nget, self->data_ptr);
}

static int
Revenue_set_ppa_soln_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Revenue_ppa_soln_min_nset, self->data_ptr);
}

static PyObject *
Revenue_get_ppa_soln_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Revenue_ppa_soln_mode_nget, self->data_ptr);
}

static int
Revenue_set_ppa_soln_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Revenue_ppa_soln_mode_nset, self->data_ptr);
}

static PyObject *
Revenue_get_ppa_soln_tolerance(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Revenue_ppa_soln_tolerance_nget, self->data_ptr);
}

static int
Revenue_set_ppa_soln_tolerance(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Revenue_ppa_soln_tolerance_nset, self->data_ptr);
}

static PyGetSetDef Revenue_getset[] = {
{"dispatch_factors_ts", (getter)Revenue_get_dispatch_factors_ts,(setter)Revenue_set_dispatch_factors_ts,
	PyDoc_STR("*sequence*: Dispatch payment factor array\n\n**Required:**\nRequired if ppa_multiplier_model=1"),
 	NULL},
{"dispatch_sched_weekday", (getter)Revenue_get_dispatch_sched_weekday,(setter)Revenue_set_dispatch_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: Diurnal weekday TOD periods [1..9]\n\n**Info:**\n12 x 24 matrix\n\n**Required:**\nRequired if ppa_multiplier_model=0"),
 	NULL},
{"dispatch_sched_weekend", (getter)Revenue_get_dispatch_sched_weekend,(setter)Revenue_set_dispatch_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Diurnal weekend TOD periods [1..9]\n\n**Info:**\n12 x 24 matrix\n\n**Required:**\nRequired if ppa_multiplier_model=0"),
 	NULL},
{"dispatch_tod_factors", (getter)Revenue_get_dispatch_tod_factors,(setter)Revenue_set_dispatch_tod_factors,
	PyDoc_STR("*sequence*: TOD factors for periods 1 through 9\n\n**Required:**\nRequired if ppa_multiplier_model=0"),
 	NULL},
{"flip_target_percent", (getter)Revenue_get_flip_target_percent,(setter)Revenue_set_flip_target_percent,
	PyDoc_STR("*float*: After-tax IRR target [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 11 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"flip_target_year", (getter)Revenue_get_flip_target_year,(setter)Revenue_set_flip_target_year,
	PyDoc_STR("*float*: IRR target year [Year]\n\n**Constraints:**\nMIN=1\n\n**Required:**\nFalse. Automatically set to 11 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ppa_escalation", (getter)Revenue_get_ppa_escalation,(setter)Revenue_set_ppa_escalation,
	PyDoc_STR("*float*: PPA escalation rate [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ppa_multiplier_model", (getter)Revenue_get_ppa_multiplier_model,(setter)Revenue_set_ppa_multiplier_model,
	PyDoc_STR("*float*: PPA multiplier model [0/1]\n\n**Options:**\n0=diurnal,1=timestep\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ppa_price_input", (getter)Revenue_get_ppa_price_input,(setter)Revenue_set_ppa_price_input,
	PyDoc_STR("*sequence*: PPA price in first year input [$/kWh]\n\n**Required:**\nTrue"),
 	NULL},
{"ppa_soln_max", (getter)Revenue_get_ppa_soln_max,(setter)Revenue_set_ppa_soln_max,
	PyDoc_STR("*float*: PPA solution maximum ppa [cents/kWh]\n\n**Required:**\nFalse. Automatically set to 100 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ppa_soln_max_iterations", (getter)Revenue_get_ppa_soln_max_iterations,(setter)Revenue_set_ppa_soln_max_iterations,
	PyDoc_STR("*float*: PPA solution maximum number of iterations\n\n**Constraints:**\nINTEGER,MIN=1\n\n**Required:**\nFalse. Automatically set to 100 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ppa_soln_min", (getter)Revenue_get_ppa_soln_min,(setter)Revenue_set_ppa_soln_min,
	PyDoc_STR("*float*: PPA solution minimum ppa [cents/kWh]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ppa_soln_mode", (getter)Revenue_get_ppa_soln_mode,(setter)Revenue_set_ppa_soln_mode,
	PyDoc_STR("*float*: PPA solution mode [0/1]\n\n**Options:**\n0=solve ppa,1=specify ppa\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ppa_soln_tolerance", (getter)Revenue_get_ppa_soln_tolerance,(setter)Revenue_set_ppa_soln_tolerance,
	PyDoc_STR("*float*: PPA solution tolerance\n\n**Required:**\nFalse. Automatically set to 1e-5 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Revenue_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.Revenue",             /*tp_name*/
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
		Revenue_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Revenue_getset,          /*tp_getset*/
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
FinancialParameters_new(SAM_HostDeveloper data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "FinancialParameters")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialParameters_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &FinancialParameters_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "FinancialParameters")){
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
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``FinancialParameters_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)FinancialParameters_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``FinancialParameters_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)FinancialParameters_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
FinancialParameters_get_analysis_period(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_analysis_period_nget, self->data_ptr);
}

static int
FinancialParameters_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_analysis_period_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_cost_debt_closing(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_cost_debt_closing_nget, self->data_ptr);
}

static int
FinancialParameters_set_cost_debt_closing(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_cost_debt_closing_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_cost_debt_fee(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_cost_debt_fee_nget, self->data_ptr);
}

static int
FinancialParameters_set_cost_debt_fee(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_cost_debt_fee_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_cost_other_financing(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_cost_other_financing_nget, self->data_ptr);
}

static int
FinancialParameters_set_cost_other_financing(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_cost_other_financing_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_debt_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_debt_option_nget, self->data_ptr);
}

static int
FinancialParameters_set_debt_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_debt_option_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_debt_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_debt_percent_nget, self->data_ptr);
}

static int
FinancialParameters_set_debt_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_debt_percent_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_dscr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_dscr_nget, self->data_ptr);
}

static int
FinancialParameters_set_dscr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_dscr_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_dscr_limit_debt_fraction(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_dscr_limit_debt_fraction_nget, self->data_ptr);
}

static int
FinancialParameters_set_dscr_limit_debt_fraction(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_dscr_limit_debt_fraction_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_dscr_maximum_debt_fraction(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_dscr_maximum_debt_fraction_nget, self->data_ptr);
}

static int
FinancialParameters_set_dscr_maximum_debt_fraction(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_dscr_maximum_debt_fraction_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_dscr_reserve_months(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_dscr_reserve_months_nget, self->data_ptr);
}

static int
FinancialParameters_set_dscr_reserve_months(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_dscr_reserve_months_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_equip1_reserve_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_equip1_reserve_cost_nget, self->data_ptr);
}

static int
FinancialParameters_set_equip1_reserve_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_equip1_reserve_cost_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_equip1_reserve_freq(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_equip1_reserve_freq_nget, self->data_ptr);
}

static int
FinancialParameters_set_equip1_reserve_freq(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_equip1_reserve_freq_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_equip2_reserve_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_equip2_reserve_cost_nget, self->data_ptr);
}

static int
FinancialParameters_set_equip2_reserve_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_equip2_reserve_cost_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_equip2_reserve_freq(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_equip2_reserve_freq_nget, self->data_ptr);
}

static int
FinancialParameters_set_equip2_reserve_freq(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_equip2_reserve_freq_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_equip3_reserve_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_equip3_reserve_cost_nget, self->data_ptr);
}

static int
FinancialParameters_set_equip3_reserve_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_equip3_reserve_cost_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_equip3_reserve_freq(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_equip3_reserve_freq_nget, self->data_ptr);
}

static int
FinancialParameters_set_equip3_reserve_freq(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_equip3_reserve_freq_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_equip_reserve_depr_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_equip_reserve_depr_fed_nget, self->data_ptr);
}

static int
FinancialParameters_set_equip_reserve_depr_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_equip_reserve_depr_fed_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_equip_reserve_depr_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_equip_reserve_depr_sta_nget, self->data_ptr);
}

static int
FinancialParameters_set_equip_reserve_depr_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_equip_reserve_depr_sta_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_federal_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_FinancialParameters_federal_tax_rate_aget, self->data_ptr);
}

static int
FinancialParameters_set_federal_tax_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_FinancialParameters_federal_tax_rate_aset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_inflation_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_inflation_rate_nget, self->data_ptr);
}

static int
FinancialParameters_set_inflation_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_inflation_rate_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_insurance_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_insurance_rate_nget, self->data_ptr);
}

static int
FinancialParameters_set_insurance_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_insurance_rate_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_months_receivables_reserve(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_months_receivables_reserve_nget, self->data_ptr);
}

static int
FinancialParameters_set_months_receivables_reserve(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_months_receivables_reserve_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_months_working_reserve(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_months_working_reserve_nget, self->data_ptr);
}

static int
FinancialParameters_set_months_working_reserve(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_months_working_reserve_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_payment_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_payment_option_nget, self->data_ptr);
}

static int
FinancialParameters_set_payment_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_payment_option_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_prop_tax_assessed_decline(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_prop_tax_assessed_decline_nget, self->data_ptr);
}

static int
FinancialParameters_set_prop_tax_assessed_decline(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_prop_tax_assessed_decline_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_prop_tax_cost_assessed_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_prop_tax_cost_assessed_percent_nget, self->data_ptr);
}

static int
FinancialParameters_set_prop_tax_cost_assessed_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_prop_tax_cost_assessed_percent_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_property_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_property_tax_rate_nget, self->data_ptr);
}

static int
FinancialParameters_set_property_tax_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_property_tax_rate_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_real_discount_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_real_discount_rate_nget, self->data_ptr);
}

static int
FinancialParameters_set_real_discount_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_real_discount_rate_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_reserves_interest(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_reserves_interest_nget, self->data_ptr);
}

static int
FinancialParameters_set_reserves_interest(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_reserves_interest_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_salvage_percentage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_salvage_percentage_nget, self->data_ptr);
}

static int
FinancialParameters_set_salvage_percentage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_salvage_percentage_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_state_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_FinancialParameters_state_tax_rate_aget, self->data_ptr);
}

static int
FinancialParameters_set_state_tax_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_FinancialParameters_state_tax_rate_aset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_system_capacity_nget, self->data_ptr);
}

static int
FinancialParameters_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_system_capacity_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_system_heat_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_system_heat_rate_nget, self->data_ptr);
}

static int
FinancialParameters_set_system_heat_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_system_heat_rate_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_term_int_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_term_int_rate_nget, self->data_ptr);
}

static int
FinancialParameters_set_term_int_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_term_int_rate_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_term_tenor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_FinancialParameters_term_tenor_nget, self->data_ptr);
}

static int
FinancialParameters_set_term_tenor(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_FinancialParameters_term_tenor_nset, self->data_ptr);
}

static PyGetSetDef FinancialParameters_getset[] = {
{"analysis_period", (getter)FinancialParameters_get_analysis_period,(setter)FinancialParameters_set_analysis_period,
	PyDoc_STR("*float*: Analyis period [years]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=50\n\n**Required:**\nFalse. Automatically set to 30 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cost_debt_closing", (getter)FinancialParameters_get_cost_debt_closing,(setter)FinancialParameters_set_cost_debt_closing,
	PyDoc_STR("*float*: Debt closing cost [$]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 250000 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cost_debt_fee", (getter)FinancialParameters_get_cost_debt_fee,(setter)FinancialParameters_set_cost_debt_fee,
	PyDoc_STR("*float*: Debt closing fee (% of total debt amount) [%]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 1.5 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cost_other_financing", (getter)FinancialParameters_get_cost_other_financing,(setter)FinancialParameters_set_cost_other_financing,
	PyDoc_STR("*float*: Other financing cost [$]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 150000 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"debt_option", (getter)FinancialParameters_get_debt_option,(setter)FinancialParameters_set_debt_option,
	PyDoc_STR("*float*: Debt option [0/1]\n\n**Options:**\n0=debt percent,1=dscr\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"debt_percent", (getter)FinancialParameters_get_debt_percent,(setter)FinancialParameters_set_debt_percent,
	PyDoc_STR("*float*: Debt percent [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 50 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dscr", (getter)FinancialParameters_get_dscr,(setter)FinancialParameters_set_dscr,
	PyDoc_STR("*float*: Debt service coverage ratio\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 1.5 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dscr_limit_debt_fraction", (getter)FinancialParameters_get_dscr_limit_debt_fraction,(setter)FinancialParameters_set_dscr_limit_debt_fraction,
	PyDoc_STR("*float*: Limit debt fraction [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dscr_maximum_debt_fraction", (getter)FinancialParameters_get_dscr_maximum_debt_fraction,(setter)FinancialParameters_set_dscr_maximum_debt_fraction,
	PyDoc_STR("*float*: Maximum debt fraction [%]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nFalse. Automatically set to 100 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dscr_reserve_months", (getter)FinancialParameters_get_dscr_reserve_months,(setter)FinancialParameters_set_dscr_reserve_months,
	PyDoc_STR("*float*: Debt service reserve account [months P&I]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 6 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"equip1_reserve_cost", (getter)FinancialParameters_get_equip1_reserve_cost,(setter)FinancialParameters_set_equip1_reserve_cost,
	PyDoc_STR("*float*: Major equipment reserve 1 cost [$/W]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 0.25 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"equip1_reserve_freq", (getter)FinancialParameters_get_equip1_reserve_freq,(setter)FinancialParameters_set_equip1_reserve_freq,
	PyDoc_STR("*float*: Major equipment reserve 1 frequency [years]\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nFalse. Automatically set to 12 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"equip2_reserve_cost", (getter)FinancialParameters_get_equip2_reserve_cost,(setter)FinancialParameters_set_equip2_reserve_cost,
	PyDoc_STR("*float*: Major equipment reserve 2 cost [$/W]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"equip2_reserve_freq", (getter)FinancialParameters_get_equip2_reserve_freq,(setter)FinancialParameters_set_equip2_reserve_freq,
	PyDoc_STR("*float*: Major equipment reserve 2 frequency [years]\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nFalse. Automatically set to 15 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"equip3_reserve_cost", (getter)FinancialParameters_get_equip3_reserve_cost,(setter)FinancialParameters_set_equip3_reserve_cost,
	PyDoc_STR("*float*: Major equipment reserve 3 cost [$/W]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"equip3_reserve_freq", (getter)FinancialParameters_get_equip3_reserve_freq,(setter)FinancialParameters_set_equip3_reserve_freq,
	PyDoc_STR("*float*: Major equipment reserve 3 frequency [years]\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nFalse. Automatically set to 20 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"equip_reserve_depr_fed", (getter)FinancialParameters_get_equip_reserve_depr_fed,(setter)FinancialParameters_set_equip_reserve_depr_fed,
	PyDoc_STR("*float*: Major equipment reserve federal depreciation\n\n**Options:**\n0=5yr MACRS,1=15yr MACRS,2=5yr SL,3=15yr SL, 4=20yr SL,5=39yr SL,6=Custom\n\n**Constraints:**\nINTEGER,MIN=0,MAX=6\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"equip_reserve_depr_sta", (getter)FinancialParameters_get_equip_reserve_depr_sta,(setter)FinancialParameters_set_equip_reserve_depr_sta,
	PyDoc_STR("*float*: Major equipment reserve state depreciation\n\n**Options:**\n0=5yr MACRS,1=15yr MACRS,2=5yr SL,3=15yr SL, 4=20yr SL,5=39yr SL,6=Custom\n\n**Constraints:**\nINTEGER,MIN=0,MAX=6\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"federal_tax_rate", (getter)FinancialParameters_get_federal_tax_rate,(setter)FinancialParameters_set_federal_tax_rate,
	PyDoc_STR("*sequence*: Federal income tax rate [%]\n\n**Required:**\nTrue"),
 	NULL},
{"inflation_rate", (getter)FinancialParameters_get_inflation_rate,(setter)FinancialParameters_set_inflation_rate,
	PyDoc_STR("*float*: Inflation rate [%]\n\n**Constraints:**\nMIN=-99\n\n**Required:**\nTrue"),
 	NULL},
{"insurance_rate", (getter)FinancialParameters_get_insurance_rate,(setter)FinancialParameters_set_insurance_rate,
	PyDoc_STR("*float*: Insurance rate [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"months_receivables_reserve", (getter)FinancialParameters_get_months_receivables_reserve,(setter)FinancialParameters_set_months_receivables_reserve,
	PyDoc_STR("*float*: Receivables reserve months of PPA revenue [months]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"months_working_reserve", (getter)FinancialParameters_get_months_working_reserve,(setter)FinancialParameters_set_months_working_reserve,
	PyDoc_STR("*float*: Working capital reserve months of operating costs [months]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 6 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"payment_option", (getter)FinancialParameters_get_payment_option,(setter)FinancialParameters_set_payment_option,
	PyDoc_STR("*float*: Debt repayment option [0/1]\n\n**Options:**\n0=Equal payments (standard amortization),1=Fixed principal declining interest\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"prop_tax_assessed_decline", (getter)FinancialParameters_get_prop_tax_assessed_decline,(setter)FinancialParameters_set_prop_tax_assessed_decline,
	PyDoc_STR("*float*: Assessed value annual decline [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 5 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"prop_tax_cost_assessed_percent", (getter)FinancialParameters_get_prop_tax_cost_assessed_percent,(setter)FinancialParameters_set_prop_tax_cost_assessed_percent,
	PyDoc_STR("*float*: Percent of pre-financing costs assessed [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 95 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"property_tax_rate", (getter)FinancialParameters_get_property_tax_rate,(setter)FinancialParameters_set_property_tax_rate,
	PyDoc_STR("*float*: Property tax rate [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"real_discount_rate", (getter)FinancialParameters_get_real_discount_rate,(setter)FinancialParameters_set_real_discount_rate,
	PyDoc_STR("*float*: Real discount rate [%]\n\n**Constraints:**\nMIN=-99\n\n**Required:**\nTrue"),
 	NULL},
{"reserves_interest", (getter)FinancialParameters_get_reserves_interest,(setter)FinancialParameters_set_reserves_interest,
	PyDoc_STR("*float*: Interest on reserves [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 1.75 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"salvage_percentage", (getter)FinancialParameters_get_salvage_percentage,(setter)FinancialParameters_set_salvage_percentage,
	PyDoc_STR("*float*: Net pre-tax cash salvage value [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 10 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"state_tax_rate", (getter)FinancialParameters_get_state_tax_rate,(setter)FinancialParameters_set_state_tax_rate,
	PyDoc_STR("*sequence*: State income tax rate [%]\n\n**Required:**\nTrue"),
 	NULL},
{"system_capacity", (getter)FinancialParameters_get_system_capacity,(setter)FinancialParameters_set_system_capacity,
	PyDoc_STR("*float*: System nameplate capacity [kW]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``system_capacity``:\n\n\t - battery_total_cost_lcos\n\t - construction_financing_cost\n\t - land_area\n\t - total_installed_cost\n"),
 	NULL},
{"system_heat_rate", (getter)FinancialParameters_get_system_heat_rate,(setter)FinancialParameters_set_system_heat_rate,
	PyDoc_STR("*float*: System heat rate [MMBTus/MWh]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"term_int_rate", (getter)FinancialParameters_get_term_int_rate,(setter)FinancialParameters_set_term_int_rate,
	PyDoc_STR("*float*: Term financing interest rate [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 8.5 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"term_tenor", (getter)FinancialParameters_get_term_tenor,(setter)FinancialParameters_set_term_tenor,
	PyDoc_STR("*float*: Term financing period [years]\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nFalse. Automatically set to 10 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FinancialParameters_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.FinancialParameters",             /*tp_name*/
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
 * SystemCosts Group
 */ 

static PyTypeObject SystemCosts_Type;

static PyObject *
SystemCosts_new(SAM_HostDeveloper data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "SystemCosts")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "SystemCosts")){
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
SystemCosts_get_add_om_num_types(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_SystemCosts_add_om_num_types_nget, self->data_ptr);
}

static int
SystemCosts_set_add_om_num_types(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_SystemCosts_add_om_num_types_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_annual_fuel_usage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_SystemCosts_annual_fuel_usage_nget, self->data_ptr);
}

static int
SystemCosts_set_annual_fuel_usage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_SystemCosts_annual_fuel_usage_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_annual_fuel_usage_lifetime(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemCosts_annual_fuel_usage_lifetime_aget, self->data_ptr);
}

static int
SystemCosts_set_annual_fuel_usage_lifetime(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemCosts_annual_fuel_usage_lifetime_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_batt_capacity_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemCosts_om_batt_capacity_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_batt_capacity_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemCosts_om_batt_capacity_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_batt_fixed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemCosts_om_batt_fixed_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_batt_fixed_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemCosts_om_batt_fixed_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_batt_nameplate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_SystemCosts_om_batt_nameplate_nget, self->data_ptr);
}

static int
SystemCosts_set_om_batt_nameplate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_SystemCosts_om_batt_nameplate_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_batt_replacement_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemCosts_om_batt_replacement_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_batt_replacement_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemCosts_om_batt_replacement_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_batt_variable_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemCosts_om_batt_variable_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_batt_variable_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemCosts_om_batt_variable_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemCosts_om_capacity_aget, self->data_ptr);
}

static int
SystemCosts_set_om_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemCosts_om_capacity_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_capacity_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_SystemCosts_om_capacity_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_capacity_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_SystemCosts_om_capacity_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemCosts_om_fixed_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemCosts_om_fixed_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fixed_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_SystemCosts_om_fixed_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_fixed_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_SystemCosts_om_fixed_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuel_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemCosts_om_fuel_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fuel_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemCosts_om_fuel_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuel_cost_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_SystemCosts_om_fuel_cost_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_fuel_cost_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_SystemCosts_om_fuel_cost_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuelcell_capacity_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemCosts_om_fuelcell_capacity_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fuelcell_capacity_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemCosts_om_fuelcell_capacity_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuelcell_fixed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemCosts_om_fuelcell_fixed_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fuelcell_fixed_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemCosts_om_fuelcell_fixed_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuelcell_nameplate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_SystemCosts_om_fuelcell_nameplate_nget, self->data_ptr);
}

static int
SystemCosts_set_om_fuelcell_nameplate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_SystemCosts_om_fuelcell_nameplate_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuelcell_replacement_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemCosts_om_fuelcell_replacement_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fuelcell_replacement_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemCosts_om_fuelcell_replacement_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuelcell_variable_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemCosts_om_fuelcell_variable_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fuelcell_variable_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemCosts_om_fuelcell_variable_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_1_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemCosts_om_opt_fuel_1_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_1_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemCosts_om_opt_fuel_1_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_1_cost_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_SystemCosts_om_opt_fuel_1_cost_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_1_cost_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_SystemCosts_om_opt_fuel_1_cost_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_1_usage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_SystemCosts_om_opt_fuel_1_usage_nget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_1_usage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_SystemCosts_om_opt_fuel_1_usage_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_2_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemCosts_om_opt_fuel_2_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_2_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemCosts_om_opt_fuel_2_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_2_cost_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_SystemCosts_om_opt_fuel_2_cost_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_2_cost_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_SystemCosts_om_opt_fuel_2_cost_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_2_usage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_SystemCosts_om_opt_fuel_2_usage_nget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_2_usage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_SystemCosts_om_opt_fuel_2_usage_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemCosts_om_production_aget, self->data_ptr);
}

static int
SystemCosts_set_om_production(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemCosts_om_production_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production1_values(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemCosts_om_production1_values_aget, self->data_ptr);
}

static int
SystemCosts_set_om_production1_values(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemCosts_om_production1_values_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production2_values(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemCosts_om_production2_values_aget, self->data_ptr);
}

static int
SystemCosts_set_om_production2_values(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemCosts_om_production2_values_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_SystemCosts_om_production_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_production_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_SystemCosts_om_production_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_replacement_cost_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_SystemCosts_om_replacement_cost_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_replacement_cost_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_SystemCosts_om_replacement_cost_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_total_installed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_SystemCosts_total_installed_cost_nget, self->data_ptr);
}

static int
SystemCosts_set_total_installed_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_SystemCosts_total_installed_cost_nset, self->data_ptr);
}

static PyGetSetDef SystemCosts_getset[] = {
{"add_om_num_types", (getter)SystemCosts_get_add_om_num_types,(setter)SystemCosts_set_add_om_num_types,
	PyDoc_STR("*float*: Number of O and M types\n\n**Info:**\nbattery,fuelcell\n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"annual_fuel_usage", (getter)SystemCosts_get_annual_fuel_usage,(setter)SystemCosts_set_annual_fuel_usage,
	PyDoc_STR("*float*: Fuel usage (yr 1) [kWht]\n\n**Info:**\ncustom_generation,fuelcell,tcslinearfresnel,tcstroughempirical,tcsgenericsolar,fresnelphysical\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"annual_fuel_usage_lifetime", (getter)SystemCosts_get_annual_fuel_usage_lifetime,(setter)SystemCosts_set_annual_fuel_usage_lifetime,
	PyDoc_STR("*sequence*: Fuel usage (lifetime) [kWht]\n\n**Info:**\ncustom_generation,fuelcell,tcslinearfresnel,tcstroughempirical,tcsgenericsolar,fresnelphysical"),
 	NULL},
{"om_batt_capacity_cost", (getter)SystemCosts_get_om_batt_capacity_cost,(setter)SystemCosts_set_om_batt_capacity_cost,
	PyDoc_STR("*sequence*: Battery capacity-based System Costs amount [$/kWcap]\n\n**Info:**\nbattery\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_batt_fixed_cost", (getter)SystemCosts_get_om_batt_fixed_cost,(setter)SystemCosts_set_om_batt_fixed_cost,
	PyDoc_STR("*sequence*: Battery fixed System Costs annual amount [$/year]\n\n**Info:**\nbattery\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_batt_nameplate", (getter)SystemCosts_get_om_batt_nameplate,(setter)SystemCosts_set_om_batt_nameplate,
	PyDoc_STR("*float*: Battery capacity for System Costs values [kW]\n\n**Info:**\nbattery\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_batt_replacement_cost", (getter)SystemCosts_get_om_batt_replacement_cost,(setter)SystemCosts_set_om_batt_replacement_cost,
	PyDoc_STR("*sequence*: Replacement cost 1 [$/kWh]\n\n**Info:**\nbattery\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_batt_variable_cost", (getter)SystemCosts_get_om_batt_variable_cost,(setter)SystemCosts_set_om_batt_variable_cost,
	PyDoc_STR("*sequence*: Battery production-based System Costs amount [$/MWh]\n\n**Info:**\nbattery\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_capacity", (getter)SystemCosts_get_om_capacity,(setter)SystemCosts_set_om_capacity,
	PyDoc_STR("*sequence*: Capacity-based O&M amount [$/kWcap]\n\n**Info:**\n!battery,!fuelcell\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_capacity_escal", (getter)SystemCosts_get_om_capacity_escal,(setter)SystemCosts_set_om_capacity_escal,
	PyDoc_STR("*float*: Capacity-based O&M escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_fixed", (getter)SystemCosts_get_om_fixed,(setter)SystemCosts_set_om_fixed,
	PyDoc_STR("*sequence*: Fixed O&M annual amount [$/year]\n\n**Info:**\n!battery,!fuelcell\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_fixed_escal", (getter)SystemCosts_get_om_fixed_escal,(setter)SystemCosts_set_om_fixed_escal,
	PyDoc_STR("*float*: Fixed O&M escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_fuel_cost", (getter)SystemCosts_get_om_fuel_cost,(setter)SystemCosts_set_om_fuel_cost,
	PyDoc_STR("*sequence*: Fuel cost [$/MMBtu]\n\n**Info:**\ncustom_generation,fuelcell,tcslinearfresnel,tcstroughempirical,tcsgenericsolar,fresnelphysical\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_fuel_cost_escal", (getter)SystemCosts_get_om_fuel_cost_escal,(setter)SystemCosts_set_om_fuel_cost_escal,
	PyDoc_STR("*float*: Fuel cost escalation [%/year]\n\n**Info:**\ncustom_generation,fuelcell,tcslinearfresnel,tcstroughempirical,tcsgenericsolar,fresnelphysical\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_fuelcell_capacity_cost", (getter)SystemCosts_get_om_fuelcell_capacity_cost,(setter)SystemCosts_set_om_fuelcell_capacity_cost,
	PyDoc_STR("*sequence*: Fuel cell capacity-based System Costs amount [$/kWcap]\n\n**Info:**\nfuelcell\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_fuelcell_fixed_cost", (getter)SystemCosts_get_om_fuelcell_fixed_cost,(setter)SystemCosts_set_om_fuelcell_fixed_cost,
	PyDoc_STR("*sequence*: Fuel cell fixed System Costs annual amount [$/year]\n\n**Info:**\nfuelcell\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_fuelcell_nameplate", (getter)SystemCosts_get_om_fuelcell_nameplate,(setter)SystemCosts_set_om_fuelcell_nameplate,
	PyDoc_STR("*float*: Fuel cell capacity for System Costs values [kW]\n\n**Info:**\nfuelcell\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_fuelcell_replacement_cost", (getter)SystemCosts_get_om_fuelcell_replacement_cost,(setter)SystemCosts_set_om_fuelcell_replacement_cost,
	PyDoc_STR("*sequence*: Replacement cost 2 [$/kW]\n\n**Info:**\nfuelcell\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_fuelcell_variable_cost", (getter)SystemCosts_get_om_fuelcell_variable_cost,(setter)SystemCosts_set_om_fuelcell_variable_cost,
	PyDoc_STR("*sequence*: Fuel cell production-based System Costs amount [$/MWh]\n\n**Info:**\nfuelcell\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_opt_fuel_1_cost", (getter)SystemCosts_get_om_opt_fuel_1_cost,(setter)SystemCosts_set_om_opt_fuel_1_cost,
	PyDoc_STR("*sequence*: Biomass feedstock cost [$/unit]\n\n**Info:**\nbiomass\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_opt_fuel_1_cost_escal", (getter)SystemCosts_get_om_opt_fuel_1_cost_escal,(setter)SystemCosts_set_om_opt_fuel_1_cost_escal,
	PyDoc_STR("*float*: Biomass feedstock cost escalation [%/year]\n\n**Info:**\nbiomass\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_opt_fuel_1_usage", (getter)SystemCosts_get_om_opt_fuel_1_usage,(setter)SystemCosts_set_om_opt_fuel_1_usage,
	PyDoc_STR("*float*: Biomass feedstock usage [unit]\n\n**Info:**\nbiomass\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_opt_fuel_2_cost", (getter)SystemCosts_get_om_opt_fuel_2_cost,(setter)SystemCosts_set_om_opt_fuel_2_cost,
	PyDoc_STR("*sequence*: Coal feedstock cost [$/unit]\n\n**Info:**\nbiomass\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_opt_fuel_2_cost_escal", (getter)SystemCosts_get_om_opt_fuel_2_cost_escal,(setter)SystemCosts_set_om_opt_fuel_2_cost_escal,
	PyDoc_STR("*float*: Coal feedstock cost escalation [%/year]\n\n**Info:**\nbiomass\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_opt_fuel_2_usage", (getter)SystemCosts_get_om_opt_fuel_2_usage,(setter)SystemCosts_set_om_opt_fuel_2_usage,
	PyDoc_STR("*float*: Coal feedstock usage [unit]\n\n**Info:**\nbiomass\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_production", (getter)SystemCosts_get_om_production,(setter)SystemCosts_set_om_production,
	PyDoc_STR("*sequence*: Production-based O&M amount [$/MWh]\n\n**Info:**\n!battery,!fuelcell\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_production1_values", (getter)SystemCosts_get_om_production1_values,(setter)SystemCosts_set_om_production1_values,
	PyDoc_STR("*sequence*: Battery production for System Costs values [kWh]\n\n**Info:**\nbattery\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_production2_values", (getter)SystemCosts_get_om_production2_values,(setter)SystemCosts_set_om_production2_values,
	PyDoc_STR("*sequence*: Fuel cell production for System Costs values [kWh]\n\n**Info:**\nfuelcell\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_production_escal", (getter)SystemCosts_get_om_production_escal,(setter)SystemCosts_set_om_production_escal,
	PyDoc_STR("*float*: Production-based O&M escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_replacement_cost_escal", (getter)SystemCosts_get_om_replacement_cost_escal,(setter)SystemCosts_set_om_replacement_cost_escal,
	PyDoc_STR("*float*: Replacement cost escalation [%/year]\n\n**Info:**\nbattery,fuelcell\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"total_installed_cost", (getter)SystemCosts_get_total_installed_cost,(setter)SystemCosts_set_total_installed_cost,
	PyDoc_STR("*float*: Installed cost [$]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``total_installed_cost``:\n\n\t - battery_total_cost_lcos\n\t - construction_financing_cost\n\n\nThe value of ``total_installed_cost`` depends on the following variables:\n\n\t - battery_per_kWh\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.SystemCosts",             /*tp_name*/
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
 * LandLease Group
 */ 

static PyTypeObject LandLease_Type;

static PyObject *
LandLease_new(SAM_HostDeveloper data_ptr)
{
	PyObject* new_obj = LandLease_Type.tp_alloc(&LandLease_Type,0);

	VarGroupObject* LandLease_obj = (VarGroupObject*)new_obj;

	LandLease_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* LandLease methods */

static PyObject *
LandLease_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "LandLease")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
LandLease_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &LandLease_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "LandLease")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
LandLease_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &LandLease_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef LandLease_methods[] = {
		{"assign",            (PyCFunction)LandLease_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``LandLease_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)LandLease_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``LandLease_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)LandLease_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
LandLease_get_land_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_LandLease_land_area_nget, self->data_ptr);
}

static int
LandLease_set_land_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_LandLease_land_area_nset, self->data_ptr);
}

static PyObject *
LandLease_get_om_land_lease(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_LandLease_om_land_lease_aget, self->data_ptr);
}

static int
LandLease_set_om_land_lease(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_LandLease_om_land_lease_aset, self->data_ptr);
}

static PyObject *
LandLease_get_om_land_lease_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_LandLease_om_land_lease_escal_nget, self->data_ptr);
}

static int
LandLease_set_om_land_lease_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_LandLease_om_land_lease_escal_nset, self->data_ptr);
}

static PyGetSetDef LandLease_getset[] = {
{"land_area", (getter)LandLease_get_land_area,(setter)LandLease_set_land_area,
	PyDoc_STR("*float*: Total land area [acres]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_land_lease", (getter)LandLease_get_om_land_lease,(setter)LandLease_set_om_land_lease,
	PyDoc_STR("*sequence*: Land lease cost [$/acre]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_land_lease_escal", (getter)LandLease_get_om_land_lease_escal,(setter)LandLease_set_om_land_lease_escal,
	PyDoc_STR("*float*: Land lease cost escalation [%/yr]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject LandLease_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.LandLease",             /*tp_name*/
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
		LandLease_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		LandLease_getset,          /*tp_getset*/
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
 * TaxCreditIncentives Group
 */ 

static PyTypeObject TaxCreditIncentives_Type;

static PyObject *
TaxCreditIncentives_new(SAM_HostDeveloper data_ptr)
{
	PyObject* new_obj = TaxCreditIncentives_Type.tp_alloc(&TaxCreditIncentives_Type,0);

	VarGroupObject* TaxCreditIncentives_obj = (VarGroupObject*)new_obj;

	TaxCreditIncentives_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* TaxCreditIncentives methods */

static PyObject *
TaxCreditIncentives_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "TaxCreditIncentives")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TaxCreditIncentives_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &TaxCreditIncentives_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "TaxCreditIncentives")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TaxCreditIncentives_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &TaxCreditIncentives_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TaxCreditIncentives_methods[] = {
		{"assign",            (PyCFunction)TaxCreditIncentives_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``TaxCreditIncentives_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)TaxCreditIncentives_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``TaxCreditIncentives_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)TaxCreditIncentives_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TaxCreditIncentives_get_itc_fed_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_TaxCreditIncentives_itc_fed_amount_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_TaxCreditIncentives_itc_fed_amount_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_amount_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_TaxCreditIncentives_itc_fed_amount_deprbas_fed_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_amount_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_TaxCreditIncentives_itc_fed_amount_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_amount_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_TaxCreditIncentives_itc_fed_amount_deprbas_sta_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_amount_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_TaxCreditIncentives_itc_fed_amount_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_TaxCreditIncentives_itc_fed_percent_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_TaxCreditIncentives_itc_fed_percent_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_TaxCreditIncentives_itc_fed_percent_deprbas_fed_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_TaxCreditIncentives_itc_fed_percent_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_TaxCreditIncentives_itc_fed_percent_deprbas_sta_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_TaxCreditIncentives_itc_fed_percent_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_TaxCreditIncentives_itc_fed_percent_maxvalue_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_TaxCreditIncentives_itc_fed_percent_maxvalue_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_TaxCreditIncentives_itc_sta_amount_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_TaxCreditIncentives_itc_sta_amount_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_amount_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_TaxCreditIncentives_itc_sta_amount_deprbas_fed_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_amount_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_TaxCreditIncentives_itc_sta_amount_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_amount_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_TaxCreditIncentives_itc_sta_amount_deprbas_sta_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_amount_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_TaxCreditIncentives_itc_sta_amount_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_TaxCreditIncentives_itc_sta_percent_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_TaxCreditIncentives_itc_sta_percent_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_TaxCreditIncentives_itc_sta_percent_deprbas_fed_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_TaxCreditIncentives_itc_sta_percent_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_TaxCreditIncentives_itc_sta_percent_deprbas_sta_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_TaxCreditIncentives_itc_sta_percent_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_TaxCreditIncentives_itc_sta_percent_maxvalue_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_TaxCreditIncentives_itc_sta_percent_maxvalue_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_fed_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_TaxCreditIncentives_ptc_fed_amount_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_fed_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_TaxCreditIncentives_ptc_fed_amount_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_fed_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_TaxCreditIncentives_ptc_fed_escal_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_fed_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_TaxCreditIncentives_ptc_fed_escal_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_fed_term(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_TaxCreditIncentives_ptc_fed_term_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_fed_term(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_TaxCreditIncentives_ptc_fed_term_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_sta_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_TaxCreditIncentives_ptc_sta_amount_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_sta_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_TaxCreditIncentives_ptc_sta_amount_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_sta_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_TaxCreditIncentives_ptc_sta_escal_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_sta_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_TaxCreditIncentives_ptc_sta_escal_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_sta_term(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_TaxCreditIncentives_ptc_sta_term_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_sta_term(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_TaxCreditIncentives_ptc_sta_term_nset, self->data_ptr);
}

static PyGetSetDef TaxCreditIncentives_getset[] = {
{"itc_fed_amount", (getter)TaxCreditIncentives_get_itc_fed_amount,(setter)TaxCreditIncentives_set_itc_fed_amount,
	PyDoc_STR("*sequence*: Federal amount-based ITC amount [$]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"itc_fed_amount_deprbas_fed", (getter)TaxCreditIncentives_get_itc_fed_amount_deprbas_fed,(setter)TaxCreditIncentives_set_itc_fed_amount_deprbas_fed,
	PyDoc_STR("*float*: Federal amount-based ITC reduces federal depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"itc_fed_amount_deprbas_sta", (getter)TaxCreditIncentives_get_itc_fed_amount_deprbas_sta,(setter)TaxCreditIncentives_set_itc_fed_amount_deprbas_sta,
	PyDoc_STR("*float*: Federal amount-based ITC reduces state depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"itc_fed_percent", (getter)TaxCreditIncentives_get_itc_fed_percent,(setter)TaxCreditIncentives_set_itc_fed_percent,
	PyDoc_STR("*sequence*: Federal percentage-based ITC percent [%]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"itc_fed_percent_deprbas_fed", (getter)TaxCreditIncentives_get_itc_fed_percent_deprbas_fed,(setter)TaxCreditIncentives_set_itc_fed_percent_deprbas_fed,
	PyDoc_STR("*float*: Federal percentage-based ITC reduces federal depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"itc_fed_percent_deprbas_sta", (getter)TaxCreditIncentives_get_itc_fed_percent_deprbas_sta,(setter)TaxCreditIncentives_set_itc_fed_percent_deprbas_sta,
	PyDoc_STR("*float*: Federal percentage-based ITC reduces state depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"itc_fed_percent_maxvalue", (getter)TaxCreditIncentives_get_itc_fed_percent_maxvalue,(setter)TaxCreditIncentives_set_itc_fed_percent_maxvalue,
	PyDoc_STR("*sequence*: Federal percentage-based ITC maximum value [$]\n\n**Required:**\nFalse. Automatically set to 1e99 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"itc_sta_amount", (getter)TaxCreditIncentives_get_itc_sta_amount,(setter)TaxCreditIncentives_set_itc_sta_amount,
	PyDoc_STR("*sequence*: State amount-based ITC amount [$]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"itc_sta_amount_deprbas_fed", (getter)TaxCreditIncentives_get_itc_sta_amount_deprbas_fed,(setter)TaxCreditIncentives_set_itc_sta_amount_deprbas_fed,
	PyDoc_STR("*float*: State amount-based ITC reduces federal depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"itc_sta_amount_deprbas_sta", (getter)TaxCreditIncentives_get_itc_sta_amount_deprbas_sta,(setter)TaxCreditIncentives_set_itc_sta_amount_deprbas_sta,
	PyDoc_STR("*float*: State amount-based ITC reduces state depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"itc_sta_percent", (getter)TaxCreditIncentives_get_itc_sta_percent,(setter)TaxCreditIncentives_set_itc_sta_percent,
	PyDoc_STR("*sequence*: State percentage-based ITC percent [%]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"itc_sta_percent_deprbas_fed", (getter)TaxCreditIncentives_get_itc_sta_percent_deprbas_fed,(setter)TaxCreditIncentives_set_itc_sta_percent_deprbas_fed,
	PyDoc_STR("*float*: State percentage-based ITC reduces federal depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"itc_sta_percent_deprbas_sta", (getter)TaxCreditIncentives_get_itc_sta_percent_deprbas_sta,(setter)TaxCreditIncentives_set_itc_sta_percent_deprbas_sta,
	PyDoc_STR("*float*: State percentage-based ITC reduces state depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"itc_sta_percent_maxvalue", (getter)TaxCreditIncentives_get_itc_sta_percent_maxvalue,(setter)TaxCreditIncentives_set_itc_sta_percent_maxvalue,
	PyDoc_STR("*sequence*: State percentage-based ITC maximum Value [$]\n\n**Required:**\nFalse. Automatically set to 1e99 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ptc_fed_amount", (getter)TaxCreditIncentives_get_ptc_fed_amount,(setter)TaxCreditIncentives_set_ptc_fed_amount,
	PyDoc_STR("*sequence*: Federal PTC amount [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ptc_fed_escal", (getter)TaxCreditIncentives_get_ptc_fed_escal,(setter)TaxCreditIncentives_set_ptc_fed_escal,
	PyDoc_STR("*float*: Federal PTC escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ptc_fed_term", (getter)TaxCreditIncentives_get_ptc_fed_term,(setter)TaxCreditIncentives_set_ptc_fed_term,
	PyDoc_STR("*float*: Federal PTC term [years]\n\n**Required:**\nFalse. Automatically set to 10 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ptc_sta_amount", (getter)TaxCreditIncentives_get_ptc_sta_amount,(setter)TaxCreditIncentives_set_ptc_sta_amount,
	PyDoc_STR("*sequence*: State PTC amount [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ptc_sta_escal", (getter)TaxCreditIncentives_get_ptc_sta_escal,(setter)TaxCreditIncentives_set_ptc_sta_escal,
	PyDoc_STR("*float*: State PTC escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ptc_sta_term", (getter)TaxCreditIncentives_get_ptc_sta_term,(setter)TaxCreditIncentives_set_ptc_sta_term,
	PyDoc_STR("*float*: State PTC term [years]\n\n**Required:**\nFalse. Automatically set to 10 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TaxCreditIncentives_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.TaxCreditIncentives",             /*tp_name*/
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
		TaxCreditIncentives_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TaxCreditIncentives_getset,          /*tp_getset*/
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
 * Depreciation Group
 */ 

static PyTypeObject Depreciation_Type;

static PyObject *
Depreciation_new(SAM_HostDeveloper data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "Depreciation")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "Depreciation")){
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
Depreciation_get_depr_alloc_custom_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_alloc_custom_percent_nget, self->data_ptr);
}

static int
Depreciation_set_depr_alloc_custom_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_alloc_custom_percent_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_alloc_macrs_15_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_alloc_macrs_15_percent_nget, self->data_ptr);
}

static int
Depreciation_set_depr_alloc_macrs_15_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_alloc_macrs_15_percent_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_alloc_macrs_5_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_alloc_macrs_5_percent_nget, self->data_ptr);
}

static int
Depreciation_set_depr_alloc_macrs_5_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_alloc_macrs_5_percent_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_alloc_sl_15_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_alloc_sl_15_percent_nget, self->data_ptr);
}

static int
Depreciation_set_depr_alloc_sl_15_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_alloc_sl_15_percent_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_alloc_sl_20_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_alloc_sl_20_percent_nget, self->data_ptr);
}

static int
Depreciation_set_depr_alloc_sl_20_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_alloc_sl_20_percent_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_alloc_sl_39_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_alloc_sl_39_percent_nget, self->data_ptr);
}

static int
Depreciation_set_depr_alloc_sl_39_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_alloc_sl_39_percent_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_alloc_sl_5_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_alloc_sl_5_percent_nget, self->data_ptr);
}

static int
Depreciation_set_depr_alloc_sl_5_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_alloc_sl_5_percent_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_bonus_fed_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_bonus_fed_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_fed_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_bonus_fed_custom_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_fed_custom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_bonus_fed_custom_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_fed_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_bonus_fed_macrs_15_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_fed_macrs_15(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_bonus_fed_macrs_15_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_fed_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_bonus_fed_macrs_5_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_fed_macrs_5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_bonus_fed_macrs_5_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_fed_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_bonus_fed_sl_15_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_fed_sl_15(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_bonus_fed_sl_15_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_fed_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_bonus_fed_sl_20_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_fed_sl_20(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_bonus_fed_sl_20_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_fed_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_bonus_fed_sl_39_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_fed_sl_39(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_bonus_fed_sl_39_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_fed_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_bonus_fed_sl_5_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_fed_sl_5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_bonus_fed_sl_5_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_bonus_sta_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_bonus_sta_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_sta_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_bonus_sta_custom_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_sta_custom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_bonus_sta_custom_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_sta_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_bonus_sta_macrs_15_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_sta_macrs_15(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_bonus_sta_macrs_15_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_sta_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_bonus_sta_macrs_5_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_sta_macrs_5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_bonus_sta_macrs_5_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_sta_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_bonus_sta_sl_15_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_sta_sl_15(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_bonus_sta_sl_15_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_sta_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_bonus_sta_sl_20_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_sta_sl_20(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_bonus_sta_sl_20_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_sta_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_bonus_sta_sl_39_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_sta_sl_39(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_bonus_sta_sl_39_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_sta_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_bonus_sta_sl_5_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_sta_sl_5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_bonus_sta_sl_5_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_custom_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Depreciation_depr_custom_schedule_aget, self->data_ptr);
}

static int
Depreciation_set_depr_custom_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_Depreciation_depr_custom_schedule_aset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_fedbas_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_fedbas_method_nget, self->data_ptr);
}

static int
Depreciation_set_depr_fedbas_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_fedbas_method_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_fed_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_itc_fed_custom_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_fed_custom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_itc_fed_custom_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_fed_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_itc_fed_macrs_15_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_fed_macrs_15(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_itc_fed_macrs_15_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_fed_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_itc_fed_macrs_5_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_fed_macrs_5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_itc_fed_macrs_5_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_fed_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_itc_fed_sl_15_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_fed_sl_15(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_itc_fed_sl_15_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_fed_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_itc_fed_sl_20_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_fed_sl_20(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_itc_fed_sl_20_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_fed_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_itc_fed_sl_39_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_fed_sl_39(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_itc_fed_sl_39_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_fed_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_itc_fed_sl_5_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_fed_sl_5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_itc_fed_sl_5_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_sta_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_itc_sta_custom_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_sta_custom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_itc_sta_custom_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_sta_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_itc_sta_macrs_15_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_sta_macrs_15(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_itc_sta_macrs_15_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_sta_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_itc_sta_macrs_5_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_sta_macrs_5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_itc_sta_macrs_5_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_sta_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_itc_sta_sl_15_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_sta_sl_15(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_itc_sta_sl_15_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_sta_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_itc_sta_sl_20_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_sta_sl_20(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_itc_sta_sl_20_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_sta_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_itc_sta_sl_39_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_sta_sl_39(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_itc_sta_sl_39_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_sta_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_itc_sta_sl_5_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_sta_sl_5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_itc_sta_sl_5_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_stabas_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Depreciation_depr_stabas_method_nget, self->data_ptr);
}

static int
Depreciation_set_depr_stabas_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Depreciation_depr_stabas_method_nset, self->data_ptr);
}

static PyGetSetDef Depreciation_getset[] = {
{"depr_alloc_custom_percent", (getter)Depreciation_get_depr_alloc_custom_percent,(setter)Depreciation_set_depr_alloc_custom_percent,
	PyDoc_STR("*float*: Custom depreciation federal and state allocation [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_alloc_macrs_15_percent", (getter)Depreciation_get_depr_alloc_macrs_15_percent,(setter)Depreciation_set_depr_alloc_macrs_15_percent,
	PyDoc_STR("*float*: 15-yr MACRS depreciation federal and state allocation [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 1.5 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_alloc_macrs_5_percent", (getter)Depreciation_get_depr_alloc_macrs_5_percent,(setter)Depreciation_set_depr_alloc_macrs_5_percent,
	PyDoc_STR("*float*: 5-yr MACRS depreciation federal and state allocation [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 89 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_alloc_sl_15_percent", (getter)Depreciation_get_depr_alloc_sl_15_percent,(setter)Depreciation_set_depr_alloc_sl_15_percent,
	PyDoc_STR("*float*: 15-yr straight line depreciation federal and state allocation [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 3 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_alloc_sl_20_percent", (getter)Depreciation_get_depr_alloc_sl_20_percent,(setter)Depreciation_set_depr_alloc_sl_20_percent,
	PyDoc_STR("*float*: 20-yr straight line depreciation federal and state allocation [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 3 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_alloc_sl_39_percent", (getter)Depreciation_get_depr_alloc_sl_39_percent,(setter)Depreciation_set_depr_alloc_sl_39_percent,
	PyDoc_STR("*float*: 39-yr straight line depreciation federal and state allocation [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0.5 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_alloc_sl_5_percent", (getter)Depreciation_get_depr_alloc_sl_5_percent,(setter)Depreciation_set_depr_alloc_sl_5_percent,
	PyDoc_STR("*float*: 5-yr straight line depreciation federal and state allocation [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_bonus_fed", (getter)Depreciation_get_depr_bonus_fed,(setter)Depreciation_set_depr_bonus_fed,
	PyDoc_STR("*float*: Federal bonus depreciation [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_bonus_fed_custom", (getter)Depreciation_get_depr_bonus_fed_custom,(setter)Depreciation_set_depr_bonus_fed_custom,
	PyDoc_STR("*float*: Federal bonus depreciation custom [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_bonus_fed_macrs_15", (getter)Depreciation_get_depr_bonus_fed_macrs_15,(setter)Depreciation_set_depr_bonus_fed_macrs_15,
	PyDoc_STR("*float*: Federal bonus depreciation 15-yr MACRS [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_bonus_fed_macrs_5", (getter)Depreciation_get_depr_bonus_fed_macrs_5,(setter)Depreciation_set_depr_bonus_fed_macrs_5,
	PyDoc_STR("*float*: Federal bonus depreciation 5-yr MACRS [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_bonus_fed_sl_15", (getter)Depreciation_get_depr_bonus_fed_sl_15,(setter)Depreciation_set_depr_bonus_fed_sl_15,
	PyDoc_STR("*float*: Federal bonus depreciation 15-yr straight line [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_bonus_fed_sl_20", (getter)Depreciation_get_depr_bonus_fed_sl_20,(setter)Depreciation_set_depr_bonus_fed_sl_20,
	PyDoc_STR("*float*: Federal bonus depreciation 20-yr straight line [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_bonus_fed_sl_39", (getter)Depreciation_get_depr_bonus_fed_sl_39,(setter)Depreciation_set_depr_bonus_fed_sl_39,
	PyDoc_STR("*float*: Federal bonus depreciation 39-yr straight line [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_bonus_fed_sl_5", (getter)Depreciation_get_depr_bonus_fed_sl_5,(setter)Depreciation_set_depr_bonus_fed_sl_5,
	PyDoc_STR("*float*: Federal bonus depreciation 5-yr straight line [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_bonus_sta", (getter)Depreciation_get_depr_bonus_sta,(setter)Depreciation_set_depr_bonus_sta,
	PyDoc_STR("*float*: State bonus depreciation [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_bonus_sta_custom", (getter)Depreciation_get_depr_bonus_sta_custom,(setter)Depreciation_set_depr_bonus_sta_custom,
	PyDoc_STR("*float*: State bonus depreciation custom [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_bonus_sta_macrs_15", (getter)Depreciation_get_depr_bonus_sta_macrs_15,(setter)Depreciation_set_depr_bonus_sta_macrs_15,
	PyDoc_STR("*float*: State bonus depreciation 15-yr MACRS [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_bonus_sta_macrs_5", (getter)Depreciation_get_depr_bonus_sta_macrs_5,(setter)Depreciation_set_depr_bonus_sta_macrs_5,
	PyDoc_STR("*float*: State bonus depreciation 5-yr MACRS [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_bonus_sta_sl_15", (getter)Depreciation_get_depr_bonus_sta_sl_15,(setter)Depreciation_set_depr_bonus_sta_sl_15,
	PyDoc_STR("*float*: State bonus depreciation 15-yr straight line [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_bonus_sta_sl_20", (getter)Depreciation_get_depr_bonus_sta_sl_20,(setter)Depreciation_set_depr_bonus_sta_sl_20,
	PyDoc_STR("*float*: State bonus depreciation 20-yr straight line [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_bonus_sta_sl_39", (getter)Depreciation_get_depr_bonus_sta_sl_39,(setter)Depreciation_set_depr_bonus_sta_sl_39,
	PyDoc_STR("*float*: State bonus depreciation 39-yr straight line [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_bonus_sta_sl_5", (getter)Depreciation_get_depr_bonus_sta_sl_5,(setter)Depreciation_set_depr_bonus_sta_sl_5,
	PyDoc_STR("*float*: State bonus depreciation 5-yr straight line [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_custom_schedule", (getter)Depreciation_get_depr_custom_schedule,(setter)Depreciation_set_depr_custom_schedule,
	PyDoc_STR("*sequence*: Custom depreciation schedule [%]\n\n**Required:**\nTrue"),
 	NULL},
{"depr_fedbas_method", (getter)Depreciation_get_depr_fedbas_method,(setter)Depreciation_set_depr_fedbas_method,
	PyDoc_STR("*float*: Method of federal depreciation reduction\n\n**Options:**\n0=5yr MACRS,1=Proportional\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_itc_fed_custom", (getter)Depreciation_get_depr_itc_fed_custom,(setter)Depreciation_set_depr_itc_fed_custom,
	PyDoc_STR("*float*: Federal ITC depreciation custom [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_itc_fed_macrs_15", (getter)Depreciation_get_depr_itc_fed_macrs_15,(setter)Depreciation_set_depr_itc_fed_macrs_15,
	PyDoc_STR("*float*: Federal ITC depreciation 15-yr MACRS [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_itc_fed_macrs_5", (getter)Depreciation_get_depr_itc_fed_macrs_5,(setter)Depreciation_set_depr_itc_fed_macrs_5,
	PyDoc_STR("*float*: Federal ITC depreciation 5-yr MACRS [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_itc_fed_sl_15", (getter)Depreciation_get_depr_itc_fed_sl_15,(setter)Depreciation_set_depr_itc_fed_sl_15,
	PyDoc_STR("*float*: Federal ITC depreciation 15-yr straight line [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_itc_fed_sl_20", (getter)Depreciation_get_depr_itc_fed_sl_20,(setter)Depreciation_set_depr_itc_fed_sl_20,
	PyDoc_STR("*float*: Federal ITC depreciation 20-yr straight line [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_itc_fed_sl_39", (getter)Depreciation_get_depr_itc_fed_sl_39,(setter)Depreciation_set_depr_itc_fed_sl_39,
	PyDoc_STR("*float*: Federal ITC depreciation 39-yr straight line [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_itc_fed_sl_5", (getter)Depreciation_get_depr_itc_fed_sl_5,(setter)Depreciation_set_depr_itc_fed_sl_5,
	PyDoc_STR("*float*: Federal ITC depreciation 5-yr straight line [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_itc_sta_custom", (getter)Depreciation_get_depr_itc_sta_custom,(setter)Depreciation_set_depr_itc_sta_custom,
	PyDoc_STR("*float*: State ITC depreciation custom [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_itc_sta_macrs_15", (getter)Depreciation_get_depr_itc_sta_macrs_15,(setter)Depreciation_set_depr_itc_sta_macrs_15,
	PyDoc_STR("*float*: State ITC depreciation 15-yr MACRS [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_itc_sta_macrs_5", (getter)Depreciation_get_depr_itc_sta_macrs_5,(setter)Depreciation_set_depr_itc_sta_macrs_5,
	PyDoc_STR("*float*: State ITC depreciation 5-yr MACRS [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_itc_sta_sl_15", (getter)Depreciation_get_depr_itc_sta_sl_15,(setter)Depreciation_set_depr_itc_sta_sl_15,
	PyDoc_STR("*float*: State ITC depreciation 15-yr straight line [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_itc_sta_sl_20", (getter)Depreciation_get_depr_itc_sta_sl_20,(setter)Depreciation_set_depr_itc_sta_sl_20,
	PyDoc_STR("*float*: State ITC depreciation 20-yr straight line [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_itc_sta_sl_39", (getter)Depreciation_get_depr_itc_sta_sl_39,(setter)Depreciation_set_depr_itc_sta_sl_39,
	PyDoc_STR("*float*: State ITC depreciation 39-yr straight line [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_itc_sta_sl_5", (getter)Depreciation_get_depr_itc_sta_sl_5,(setter)Depreciation_set_depr_itc_sta_sl_5,
	PyDoc_STR("*float*: State ITC depreciation 5-yr straight line [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"depr_stabas_method", (getter)Depreciation_get_depr_stabas_method,(setter)Depreciation_set_depr_stabas_method,
	PyDoc_STR("*float*: Method of state depreciation reduction\n\n**Options:**\n0=5yr MACRS,1=Proportional\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Depreciation_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.Depreciation",             /*tp_name*/
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
 * PaymentIncentives Group
 */ 

static PyTypeObject PaymentIncentives_Type;

static PyObject *
PaymentIncentives_new(SAM_HostDeveloper data_ptr)
{
	PyObject* new_obj = PaymentIncentives_Type.tp_alloc(&PaymentIncentives_Type,0);

	VarGroupObject* PaymentIncentives_obj = (VarGroupObject*)new_obj;

	PaymentIncentives_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* PaymentIncentives methods */

static PyObject *
PaymentIncentives_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "PaymentIncentives")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PaymentIncentives_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &PaymentIncentives_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "PaymentIncentives")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PaymentIncentives_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &PaymentIncentives_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef PaymentIncentives_methods[] = {
		{"assign",            (PyCFunction)PaymentIncentives_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``PaymentIncentives_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)PaymentIncentives_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``PaymentIncentives_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)PaymentIncentives_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
PaymentIncentives_get_cbi_fed_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_fed_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_fed_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_fed_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_fed_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_fed_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_fed_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_fed_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_fed_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_fed_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_fed_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_fed_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_fed_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_oth_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_oth_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_oth_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_oth_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_oth_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_oth_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_oth_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_oth_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_oth_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_oth_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_oth_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_oth_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_sta_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_sta_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_sta_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_sta_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_sta_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_sta_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_sta_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_sta_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_sta_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_sta_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_sta_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_sta_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_uti_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_uti_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_uti_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_uti_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_uti_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_uti_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_uti_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_uti_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_uti_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_uti_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_cbi_uti_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_cbi_uti_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_fed_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_fed_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_fed_amount_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_fed_amount_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_fed_amount_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_fed_amount_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_fed_amount_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_fed_amount_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_fed_amount_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_fed_amount_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_fed_percent_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_fed_percent_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_fed_percent_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_fed_percent_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_fed_percent_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_fed_percent_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_fed_percent_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_fed_percent_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_fed_percent_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_fed_percent_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_fed_percent_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_fed_percent_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_oth_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_oth_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_oth_amount_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_oth_amount_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_oth_amount_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_oth_amount_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_oth_amount_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_oth_amount_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_oth_amount_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_oth_amount_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_oth_percent_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_oth_percent_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_oth_percent_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_oth_percent_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_oth_percent_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_oth_percent_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_oth_percent_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_oth_percent_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_oth_percent_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_oth_percent_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_oth_percent_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_oth_percent_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_sta_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_sta_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_sta_amount_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_sta_amount_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_sta_amount_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_sta_amount_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_sta_amount_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_sta_amount_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_sta_amount_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_sta_amount_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_sta_percent_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_sta_percent_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_sta_percent_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_sta_percent_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_sta_percent_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_sta_percent_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_sta_percent_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_sta_percent_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_sta_percent_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_sta_percent_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_sta_percent_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_sta_percent_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_uti_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_uti_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_uti_amount_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_uti_amount_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_uti_amount_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_uti_amount_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_uti_amount_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_uti_amount_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_uti_amount_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_uti_amount_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_uti_percent_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_uti_percent_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_uti_percent_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_uti_percent_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_uti_percent_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_uti_percent_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_uti_percent_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_uti_percent_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_uti_percent_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_uti_percent_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_ibi_uti_percent_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_ibi_uti_percent_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_PaymentIncentives_pbi_fed_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_fed_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_fed_escal_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_fed_escal_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_for_ds(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_fed_for_ds_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_for_ds(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_fed_for_ds_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_fed_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_fed_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_fed_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_fed_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_term(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_fed_term_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_term(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_fed_term_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_PaymentIncentives_pbi_oth_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_oth_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_oth_escal_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_oth_escal_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_for_ds(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_oth_for_ds_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_for_ds(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_oth_for_ds_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_oth_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_oth_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_oth_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_oth_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_term(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_oth_term_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_term(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_oth_term_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_PaymentIncentives_pbi_sta_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_sta_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_sta_escal_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_sta_escal_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_for_ds(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_sta_for_ds_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_for_ds(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_sta_for_ds_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_sta_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_sta_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_sta_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_sta_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_term(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_sta_term_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_term(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_sta_term_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_PaymentIncentives_pbi_uti_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_uti_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_uti_escal_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_uti_escal_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_for_ds(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_uti_for_ds_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_for_ds(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_uti_for_ds_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_uti_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_uti_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_uti_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_uti_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_term(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_PaymentIncentives_pbi_uti_term_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_term(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_PaymentIncentives_pbi_uti_term_nset, self->data_ptr);
}

static PyGetSetDef PaymentIncentives_getset[] = {
{"cbi_fed_amount", (getter)PaymentIncentives_get_cbi_fed_amount,(setter)PaymentIncentives_set_cbi_fed_amount,
	PyDoc_STR("*float*: Federal CBI amount [$/Watt]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_fed_deprbas_fed", (getter)PaymentIncentives_get_cbi_fed_deprbas_fed,(setter)PaymentIncentives_set_cbi_fed_deprbas_fed,
	PyDoc_STR("*float*: Federal CBI reduces federal depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_fed_deprbas_sta", (getter)PaymentIncentives_get_cbi_fed_deprbas_sta,(setter)PaymentIncentives_set_cbi_fed_deprbas_sta,
	PyDoc_STR("*float*: Federal CBI reduces state depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_fed_maxvalue", (getter)PaymentIncentives_get_cbi_fed_maxvalue,(setter)PaymentIncentives_set_cbi_fed_maxvalue,
	PyDoc_STR("*float*: Federal CBI maximum [$]\n\n**Required:**\nFalse. Automatically set to 1e99 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_fed_tax_fed", (getter)PaymentIncentives_get_cbi_fed_tax_fed,(setter)PaymentIncentives_set_cbi_fed_tax_fed,
	PyDoc_STR("*float*: Federal CBI federal taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_fed_tax_sta", (getter)PaymentIncentives_get_cbi_fed_tax_sta,(setter)PaymentIncentives_set_cbi_fed_tax_sta,
	PyDoc_STR("*float*: Federal CBI state taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_oth_amount", (getter)PaymentIncentives_get_cbi_oth_amount,(setter)PaymentIncentives_set_cbi_oth_amount,
	PyDoc_STR("*float*: Other CBI amount [$/Watt]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_oth_deprbas_fed", (getter)PaymentIncentives_get_cbi_oth_deprbas_fed,(setter)PaymentIncentives_set_cbi_oth_deprbas_fed,
	PyDoc_STR("*float*: Other CBI reduces federal depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_oth_deprbas_sta", (getter)PaymentIncentives_get_cbi_oth_deprbas_sta,(setter)PaymentIncentives_set_cbi_oth_deprbas_sta,
	PyDoc_STR("*float*: Other CBI reduces state depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_oth_maxvalue", (getter)PaymentIncentives_get_cbi_oth_maxvalue,(setter)PaymentIncentives_set_cbi_oth_maxvalue,
	PyDoc_STR("*float*: Other CBI maximum [$]\n\n**Required:**\nFalse. Automatically set to 1e99 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_oth_tax_fed", (getter)PaymentIncentives_get_cbi_oth_tax_fed,(setter)PaymentIncentives_set_cbi_oth_tax_fed,
	PyDoc_STR("*float*: Other CBI federal taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_oth_tax_sta", (getter)PaymentIncentives_get_cbi_oth_tax_sta,(setter)PaymentIncentives_set_cbi_oth_tax_sta,
	PyDoc_STR("*float*: Other CBI state taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_sta_amount", (getter)PaymentIncentives_get_cbi_sta_amount,(setter)PaymentIncentives_set_cbi_sta_amount,
	PyDoc_STR("*float*: State CBI amount [$/Watt]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_sta_deprbas_fed", (getter)PaymentIncentives_get_cbi_sta_deprbas_fed,(setter)PaymentIncentives_set_cbi_sta_deprbas_fed,
	PyDoc_STR("*float*: State CBI reduces federal depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_sta_deprbas_sta", (getter)PaymentIncentives_get_cbi_sta_deprbas_sta,(setter)PaymentIncentives_set_cbi_sta_deprbas_sta,
	PyDoc_STR("*float*: State CBI reduces state depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_sta_maxvalue", (getter)PaymentIncentives_get_cbi_sta_maxvalue,(setter)PaymentIncentives_set_cbi_sta_maxvalue,
	PyDoc_STR("*float*: State CBI maximum [$]\n\n**Required:**\nFalse. Automatically set to 1e99 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_sta_tax_fed", (getter)PaymentIncentives_get_cbi_sta_tax_fed,(setter)PaymentIncentives_set_cbi_sta_tax_fed,
	PyDoc_STR("*float*: State CBI federal taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_sta_tax_sta", (getter)PaymentIncentives_get_cbi_sta_tax_sta,(setter)PaymentIncentives_set_cbi_sta_tax_sta,
	PyDoc_STR("*float*: State CBI state taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_uti_amount", (getter)PaymentIncentives_get_cbi_uti_amount,(setter)PaymentIncentives_set_cbi_uti_amount,
	PyDoc_STR("*float*: Utility CBI amount [$/Watt]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_uti_deprbas_fed", (getter)PaymentIncentives_get_cbi_uti_deprbas_fed,(setter)PaymentIncentives_set_cbi_uti_deprbas_fed,
	PyDoc_STR("*float*: Utility CBI reduces federal depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_uti_deprbas_sta", (getter)PaymentIncentives_get_cbi_uti_deprbas_sta,(setter)PaymentIncentives_set_cbi_uti_deprbas_sta,
	PyDoc_STR("*float*: Utility CBI reduces state depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_uti_maxvalue", (getter)PaymentIncentives_get_cbi_uti_maxvalue,(setter)PaymentIncentives_set_cbi_uti_maxvalue,
	PyDoc_STR("*float*: Utility CBI maximum [$]\n\n**Required:**\nFalse. Automatically set to 1e99 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_uti_tax_fed", (getter)PaymentIncentives_get_cbi_uti_tax_fed,(setter)PaymentIncentives_set_cbi_uti_tax_fed,
	PyDoc_STR("*float*: Utility CBI federal taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cbi_uti_tax_sta", (getter)PaymentIncentives_get_cbi_uti_tax_sta,(setter)PaymentIncentives_set_cbi_uti_tax_sta,
	PyDoc_STR("*float*: Utility CBI state taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_fed_amount", (getter)PaymentIncentives_get_ibi_fed_amount,(setter)PaymentIncentives_set_ibi_fed_amount,
	PyDoc_STR("*float*: Federal amount-based IBI amount [$]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_fed_amount_deprbas_fed", (getter)PaymentIncentives_get_ibi_fed_amount_deprbas_fed,(setter)PaymentIncentives_set_ibi_fed_amount_deprbas_fed,
	PyDoc_STR("*float*: Federal amount-based IBI reduces federal depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_fed_amount_deprbas_sta", (getter)PaymentIncentives_get_ibi_fed_amount_deprbas_sta,(setter)PaymentIncentives_set_ibi_fed_amount_deprbas_sta,
	PyDoc_STR("*float*: Federal amount-based IBI reduces state depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_fed_amount_tax_fed", (getter)PaymentIncentives_get_ibi_fed_amount_tax_fed,(setter)PaymentIncentives_set_ibi_fed_amount_tax_fed,
	PyDoc_STR("*float*: Federal amount-based IBI federal taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_fed_amount_tax_sta", (getter)PaymentIncentives_get_ibi_fed_amount_tax_sta,(setter)PaymentIncentives_set_ibi_fed_amount_tax_sta,
	PyDoc_STR("*float*: Federal amount-based IBI state taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_fed_percent", (getter)PaymentIncentives_get_ibi_fed_percent,(setter)PaymentIncentives_set_ibi_fed_percent,
	PyDoc_STR("*float*: Federal percentage-based IBI percent [%]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_fed_percent_deprbas_fed", (getter)PaymentIncentives_get_ibi_fed_percent_deprbas_fed,(setter)PaymentIncentives_set_ibi_fed_percent_deprbas_fed,
	PyDoc_STR("*float*: Federal percentage-based IBI reduces federal depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_fed_percent_deprbas_sta", (getter)PaymentIncentives_get_ibi_fed_percent_deprbas_sta,(setter)PaymentIncentives_set_ibi_fed_percent_deprbas_sta,
	PyDoc_STR("*float*: Federal percentage-based IBI reduces state depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_fed_percent_maxvalue", (getter)PaymentIncentives_get_ibi_fed_percent_maxvalue,(setter)PaymentIncentives_set_ibi_fed_percent_maxvalue,
	PyDoc_STR("*float*: Federal percentage-based IBI maximum value [$]\n\n**Required:**\nFalse. Automatically set to 1e99 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_fed_percent_tax_fed", (getter)PaymentIncentives_get_ibi_fed_percent_tax_fed,(setter)PaymentIncentives_set_ibi_fed_percent_tax_fed,
	PyDoc_STR("*float*: Federal percentage-based IBI federal taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_fed_percent_tax_sta", (getter)PaymentIncentives_get_ibi_fed_percent_tax_sta,(setter)PaymentIncentives_set_ibi_fed_percent_tax_sta,
	PyDoc_STR("*float*: Federal percentage-based IBI state taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_oth_amount", (getter)PaymentIncentives_get_ibi_oth_amount,(setter)PaymentIncentives_set_ibi_oth_amount,
	PyDoc_STR("*float*: Other amount-based IBI amount [$]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_oth_amount_deprbas_fed", (getter)PaymentIncentives_get_ibi_oth_amount_deprbas_fed,(setter)PaymentIncentives_set_ibi_oth_amount_deprbas_fed,
	PyDoc_STR("*float*: Other amount-based IBI reduces federal depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_oth_amount_deprbas_sta", (getter)PaymentIncentives_get_ibi_oth_amount_deprbas_sta,(setter)PaymentIncentives_set_ibi_oth_amount_deprbas_sta,
	PyDoc_STR("*float*: Other amount-based IBI reduces state depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_oth_amount_tax_fed", (getter)PaymentIncentives_get_ibi_oth_amount_tax_fed,(setter)PaymentIncentives_set_ibi_oth_amount_tax_fed,
	PyDoc_STR("*float*: Other amount-based IBI federal taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_oth_amount_tax_sta", (getter)PaymentIncentives_get_ibi_oth_amount_tax_sta,(setter)PaymentIncentives_set_ibi_oth_amount_tax_sta,
	PyDoc_STR("*float*: Other amount-based IBI state taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_oth_percent", (getter)PaymentIncentives_get_ibi_oth_percent,(setter)PaymentIncentives_set_ibi_oth_percent,
	PyDoc_STR("*float*: Other percentage-based IBI percent [%]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_oth_percent_deprbas_fed", (getter)PaymentIncentives_get_ibi_oth_percent_deprbas_fed,(setter)PaymentIncentives_set_ibi_oth_percent_deprbas_fed,
	PyDoc_STR("*float*: Other percentage-based IBI reduces federal depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_oth_percent_deprbas_sta", (getter)PaymentIncentives_get_ibi_oth_percent_deprbas_sta,(setter)PaymentIncentives_set_ibi_oth_percent_deprbas_sta,
	PyDoc_STR("*float*: Other percentage-based IBI reduces state depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_oth_percent_maxvalue", (getter)PaymentIncentives_get_ibi_oth_percent_maxvalue,(setter)PaymentIncentives_set_ibi_oth_percent_maxvalue,
	PyDoc_STR("*float*: Other percentage-based IBI maximum value [$]\n\n**Required:**\nFalse. Automatically set to 1e99 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_oth_percent_tax_fed", (getter)PaymentIncentives_get_ibi_oth_percent_tax_fed,(setter)PaymentIncentives_set_ibi_oth_percent_tax_fed,
	PyDoc_STR("*float*: Other percentage-based IBI federal taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_oth_percent_tax_sta", (getter)PaymentIncentives_get_ibi_oth_percent_tax_sta,(setter)PaymentIncentives_set_ibi_oth_percent_tax_sta,
	PyDoc_STR("*float*: Other percentage-based IBI state taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_sta_amount", (getter)PaymentIncentives_get_ibi_sta_amount,(setter)PaymentIncentives_set_ibi_sta_amount,
	PyDoc_STR("*float*: State amount-based IBI amount [$]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_sta_amount_deprbas_fed", (getter)PaymentIncentives_get_ibi_sta_amount_deprbas_fed,(setter)PaymentIncentives_set_ibi_sta_amount_deprbas_fed,
	PyDoc_STR("*float*: State amount-based IBI reduces federal depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_sta_amount_deprbas_sta", (getter)PaymentIncentives_get_ibi_sta_amount_deprbas_sta,(setter)PaymentIncentives_set_ibi_sta_amount_deprbas_sta,
	PyDoc_STR("*float*: State amount-based IBI reduces state depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_sta_amount_tax_fed", (getter)PaymentIncentives_get_ibi_sta_amount_tax_fed,(setter)PaymentIncentives_set_ibi_sta_amount_tax_fed,
	PyDoc_STR("*float*: State amount-based IBI federal taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_sta_amount_tax_sta", (getter)PaymentIncentives_get_ibi_sta_amount_tax_sta,(setter)PaymentIncentives_set_ibi_sta_amount_tax_sta,
	PyDoc_STR("*float*: State amount-based IBI state taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_sta_percent", (getter)PaymentIncentives_get_ibi_sta_percent,(setter)PaymentIncentives_set_ibi_sta_percent,
	PyDoc_STR("*float*: State percentage-based IBI percent [%]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_sta_percent_deprbas_fed", (getter)PaymentIncentives_get_ibi_sta_percent_deprbas_fed,(setter)PaymentIncentives_set_ibi_sta_percent_deprbas_fed,
	PyDoc_STR("*float*: State percentage-based IBI reduces federal depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_sta_percent_deprbas_sta", (getter)PaymentIncentives_get_ibi_sta_percent_deprbas_sta,(setter)PaymentIncentives_set_ibi_sta_percent_deprbas_sta,
	PyDoc_STR("*float*: State percentage-based IBI reduces state depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_sta_percent_maxvalue", (getter)PaymentIncentives_get_ibi_sta_percent_maxvalue,(setter)PaymentIncentives_set_ibi_sta_percent_maxvalue,
	PyDoc_STR("*float*: State percentage-based IBI maximum value [$]\n\n**Required:**\nFalse. Automatically set to 1e99 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_sta_percent_tax_fed", (getter)PaymentIncentives_get_ibi_sta_percent_tax_fed,(setter)PaymentIncentives_set_ibi_sta_percent_tax_fed,
	PyDoc_STR("*float*: State percentage-based IBI federal taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_sta_percent_tax_sta", (getter)PaymentIncentives_get_ibi_sta_percent_tax_sta,(setter)PaymentIncentives_set_ibi_sta_percent_tax_sta,
	PyDoc_STR("*float*: State percentage-based IBI state taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_uti_amount", (getter)PaymentIncentives_get_ibi_uti_amount,(setter)PaymentIncentives_set_ibi_uti_amount,
	PyDoc_STR("*float*: Utility amount-based IBI amount [$]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_uti_amount_deprbas_fed", (getter)PaymentIncentives_get_ibi_uti_amount_deprbas_fed,(setter)PaymentIncentives_set_ibi_uti_amount_deprbas_fed,
	PyDoc_STR("*float*: Utility amount-based IBI reduces federal depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_uti_amount_deprbas_sta", (getter)PaymentIncentives_get_ibi_uti_amount_deprbas_sta,(setter)PaymentIncentives_set_ibi_uti_amount_deprbas_sta,
	PyDoc_STR("*float*: Utility amount-based IBI reduces state depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_uti_amount_tax_fed", (getter)PaymentIncentives_get_ibi_uti_amount_tax_fed,(setter)PaymentIncentives_set_ibi_uti_amount_tax_fed,
	PyDoc_STR("*float*: Utility amount-based IBI federal taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_uti_amount_tax_sta", (getter)PaymentIncentives_get_ibi_uti_amount_tax_sta,(setter)PaymentIncentives_set_ibi_uti_amount_tax_sta,
	PyDoc_STR("*float*: Utility amount-based IBI state taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_uti_percent", (getter)PaymentIncentives_get_ibi_uti_percent,(setter)PaymentIncentives_set_ibi_uti_percent,
	PyDoc_STR("*float*: Utility percentage-based IBI percent [%]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_uti_percent_deprbas_fed", (getter)PaymentIncentives_get_ibi_uti_percent_deprbas_fed,(setter)PaymentIncentives_set_ibi_uti_percent_deprbas_fed,
	PyDoc_STR("*float*: Utility percentage-based IBI reduces federal depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_uti_percent_deprbas_sta", (getter)PaymentIncentives_get_ibi_uti_percent_deprbas_sta,(setter)PaymentIncentives_set_ibi_uti_percent_deprbas_sta,
	PyDoc_STR("*float*: Utility percentage-based IBI reduces state depreciation basis [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_uti_percent_maxvalue", (getter)PaymentIncentives_get_ibi_uti_percent_maxvalue,(setter)PaymentIncentives_set_ibi_uti_percent_maxvalue,
	PyDoc_STR("*float*: Utility percentage-based IBI maximum value [$]\n\n**Required:**\nFalse. Automatically set to 1e99 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_uti_percent_tax_fed", (getter)PaymentIncentives_get_ibi_uti_percent_tax_fed,(setter)PaymentIncentives_set_ibi_uti_percent_tax_fed,
	PyDoc_STR("*float*: Utility percentage-based IBI federal taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ibi_uti_percent_tax_sta", (getter)PaymentIncentives_get_ibi_uti_percent_tax_sta,(setter)PaymentIncentives_set_ibi_uti_percent_tax_sta,
	PyDoc_STR("*float*: Utility percentage-based IBI state taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_fed_amount", (getter)PaymentIncentives_get_pbi_fed_amount,(setter)PaymentIncentives_set_pbi_fed_amount,
	PyDoc_STR("*sequence*: Federal PBI amount [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_fed_escal", (getter)PaymentIncentives_get_pbi_fed_escal,(setter)PaymentIncentives_set_pbi_fed_escal,
	PyDoc_STR("*float*: Federal PBI escalation [%]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_fed_for_ds", (getter)PaymentIncentives_get_pbi_fed_for_ds,(setter)PaymentIncentives_set_pbi_fed_for_ds,
	PyDoc_STR("*float*: Federal PBI available for debt service [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_fed_tax_fed", (getter)PaymentIncentives_get_pbi_fed_tax_fed,(setter)PaymentIncentives_set_pbi_fed_tax_fed,
	PyDoc_STR("*float*: Federal PBI federal taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_fed_tax_sta", (getter)PaymentIncentives_get_pbi_fed_tax_sta,(setter)PaymentIncentives_set_pbi_fed_tax_sta,
	PyDoc_STR("*float*: Federal PBI state taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_fed_term", (getter)PaymentIncentives_get_pbi_fed_term,(setter)PaymentIncentives_set_pbi_fed_term,
	PyDoc_STR("*float*: Federal PBI term [years]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_oth_amount", (getter)PaymentIncentives_get_pbi_oth_amount,(setter)PaymentIncentives_set_pbi_oth_amount,
	PyDoc_STR("*sequence*: Other PBI amount [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_oth_escal", (getter)PaymentIncentives_get_pbi_oth_escal,(setter)PaymentIncentives_set_pbi_oth_escal,
	PyDoc_STR("*float*: Other PBI escalation [%]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_oth_for_ds", (getter)PaymentIncentives_get_pbi_oth_for_ds,(setter)PaymentIncentives_set_pbi_oth_for_ds,
	PyDoc_STR("*float*: Other PBI available for debt service [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_oth_tax_fed", (getter)PaymentIncentives_get_pbi_oth_tax_fed,(setter)PaymentIncentives_set_pbi_oth_tax_fed,
	PyDoc_STR("*float*: Other PBI federal taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_oth_tax_sta", (getter)PaymentIncentives_get_pbi_oth_tax_sta,(setter)PaymentIncentives_set_pbi_oth_tax_sta,
	PyDoc_STR("*float*: Other PBI state taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_oth_term", (getter)PaymentIncentives_get_pbi_oth_term,(setter)PaymentIncentives_set_pbi_oth_term,
	PyDoc_STR("*float*: Other PBI term [years]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_sta_amount", (getter)PaymentIncentives_get_pbi_sta_amount,(setter)PaymentIncentives_set_pbi_sta_amount,
	PyDoc_STR("*sequence*: State PBI amount [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_sta_escal", (getter)PaymentIncentives_get_pbi_sta_escal,(setter)PaymentIncentives_set_pbi_sta_escal,
	PyDoc_STR("*float*: State PBI escalation [%]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_sta_for_ds", (getter)PaymentIncentives_get_pbi_sta_for_ds,(setter)PaymentIncentives_set_pbi_sta_for_ds,
	PyDoc_STR("*float*: State PBI available for debt service [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_sta_tax_fed", (getter)PaymentIncentives_get_pbi_sta_tax_fed,(setter)PaymentIncentives_set_pbi_sta_tax_fed,
	PyDoc_STR("*float*: State PBI federal taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_sta_tax_sta", (getter)PaymentIncentives_get_pbi_sta_tax_sta,(setter)PaymentIncentives_set_pbi_sta_tax_sta,
	PyDoc_STR("*float*: State PBI state taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_sta_term", (getter)PaymentIncentives_get_pbi_sta_term,(setter)PaymentIncentives_set_pbi_sta_term,
	PyDoc_STR("*float*: State PBI term [years]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_uti_amount", (getter)PaymentIncentives_get_pbi_uti_amount,(setter)PaymentIncentives_set_pbi_uti_amount,
	PyDoc_STR("*sequence*: Utility PBI amount [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_uti_escal", (getter)PaymentIncentives_get_pbi_uti_escal,(setter)PaymentIncentives_set_pbi_uti_escal,
	PyDoc_STR("*float*: Utility PBI escalation [%]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_uti_for_ds", (getter)PaymentIncentives_get_pbi_uti_for_ds,(setter)PaymentIncentives_set_pbi_uti_for_ds,
	PyDoc_STR("*float*: Utility PBI available for debt service [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_uti_tax_fed", (getter)PaymentIncentives_get_pbi_uti_tax_fed,(setter)PaymentIncentives_set_pbi_uti_tax_fed,
	PyDoc_STR("*float*: Utility PBI federal taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_uti_tax_sta", (getter)PaymentIncentives_get_pbi_uti_tax_sta,(setter)PaymentIncentives_set_pbi_uti_tax_sta,
	PyDoc_STR("*float*: Utility PBI state taxable [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pbi_uti_term", (getter)PaymentIncentives_get_pbi_uti_term,(setter)PaymentIncentives_set_pbi_uti_term,
	PyDoc_STR("*float*: Utility PBI term [years]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject PaymentIncentives_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.PaymentIncentives",             /*tp_name*/
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
		PaymentIncentives_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		PaymentIncentives_getset,          /*tp_getset*/
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
 * Host Group
 */ 

static PyTypeObject Host_Type;

static PyObject *
Host_new(SAM_HostDeveloper data_ptr)
{
	PyObject* new_obj = Host_Type.tp_alloc(&Host_Type,0);

	VarGroupObject* Host_obj = (VarGroupObject*)new_obj;

	Host_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Host methods */

static PyObject *
Host_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "Host")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Host_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Host_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "Host")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Host_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Host_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Host_methods[] = {
		{"assign",            (PyCFunction)Host_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Host_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Host_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Host_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Host_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Host_get_annual_energy_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Host_annual_energy_value_aget, self->data_ptr);
}

static int
Host_set_annual_energy_value(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_Host_annual_energy_value_aset, self->data_ptr);
}

static PyObject *
Host_get_elec_cost_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Host_elec_cost_with_system_aget, self->data_ptr);
}

static int
Host_set_elec_cost_with_system(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_Host_elec_cost_with_system_aset, self->data_ptr);
}

static PyObject *
Host_get_elec_cost_without_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Host_elec_cost_without_system_aget, self->data_ptr);
}

static int
Host_set_elec_cost_without_system(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_Host_elec_cost_without_system_aset, self->data_ptr);
}

static PyObject *
Host_get_host_real_discount_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Host_host_real_discount_rate_nget, self->data_ptr);
}

static int
Host_set_host_real_discount_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Host_host_real_discount_rate_nset, self->data_ptr);
}

static PyGetSetDef Host_getset[] = {
{"annual_energy_value", (getter)Host_get_annual_energy_value,(setter)Host_set_annual_energy_value,
	PyDoc_STR("*sequence*: Host energy value [$]\n\n**Required:**\nTrue"),
 	NULL},
{"elec_cost_with_system", (getter)Host_get_elec_cost_with_system,(setter)Host_set_elec_cost_with_system,
	PyDoc_STR("*sequence*: Host energy bill with system [$]\n\n**Required:**\nTrue"),
 	NULL},
{"elec_cost_without_system", (getter)Host_get_elec_cost_without_system,(setter)Host_set_elec_cost_without_system,
	PyDoc_STR("*sequence*: Host energy bill without system [$]\n\n**Required:**\nTrue"),
 	NULL},
{"host_real_discount_rate", (getter)Host_get_host_real_discount_rate,(setter)Host_set_host_real_discount_rate,
	PyDoc_STR("*float*: Host real discount rate [%]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Host_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.Host",             /*tp_name*/
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
		Host_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Host_getset,          /*tp_getset*/
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
TimeSeries_new(SAM_HostDeveloper data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "TimeSeries")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "TimeSeries")){
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
TimeSeries_get_year1_hourly_dc_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_TimeSeries_year1_hourly_dc_with_system_aget, self->data_ptr);
}

static int
TimeSeries_set_year1_hourly_dc_with_system(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_TimeSeries_year1_hourly_dc_with_system_aset, self->data_ptr);
}

static PyObject *
TimeSeries_get_year1_hourly_e_fromgrid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_TimeSeries_year1_hourly_e_fromgrid_aget, self->data_ptr);
}

static int
TimeSeries_set_year1_hourly_e_fromgrid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_TimeSeries_year1_hourly_e_fromgrid_aset, self->data_ptr);
}

static PyObject *
TimeSeries_get_year1_hourly_ec_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_TimeSeries_year1_hourly_ec_with_system_aget, self->data_ptr);
}

static int
TimeSeries_set_year1_hourly_ec_with_system(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_TimeSeries_year1_hourly_ec_with_system_aset, self->data_ptr);
}

static PyGetSetDef TimeSeries_getset[] = {
{"year1_hourly_dc_with_system", (getter)TimeSeries_get_year1_hourly_dc_with_system,(setter)TimeSeries_set_year1_hourly_dc_with_system,
	PyDoc_STR("*sequence*: Demand charge with system (year 1 hourly) [$]\n\n**Required:**\nTrue"),
 	NULL},
{"year1_hourly_e_fromgrid", (getter)TimeSeries_get_year1_hourly_e_fromgrid,(setter)TimeSeries_set_year1_hourly_e_fromgrid,
	PyDoc_STR("*sequence*: Electricity from grid (year 1 hourly) [kWh]\n\n**Required:**\nTrue"),
 	NULL},
{"year1_hourly_ec_with_system", (getter)TimeSeries_get_year1_hourly_ec_with_system,(setter)TimeSeries_set_year1_hourly_ec_with_system,
	PyDoc_STR("*sequence*: Energy charge with system (year 1 hourly) [$]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TimeSeries_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.TimeSeries",             /*tp_name*/
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
 * ChargesByMonth Group
 */ 

static PyTypeObject ChargesByMonth_Type;

static PyObject *
ChargesByMonth_new(SAM_HostDeveloper data_ptr)
{
	PyObject* new_obj = ChargesByMonth_Type.tp_alloc(&ChargesByMonth_Type,0);

	VarGroupObject* ChargesByMonth_obj = (VarGroupObject*)new_obj;

	ChargesByMonth_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* ChargesByMonth methods */

static PyObject *
ChargesByMonth_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "ChargesByMonth")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ChargesByMonth_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &ChargesByMonth_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "ChargesByMonth")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ChargesByMonth_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &ChargesByMonth_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ChargesByMonth_methods[] = {
		{"assign",            (PyCFunction)ChargesByMonth_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``ChargesByMonth_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)ChargesByMonth_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``ChargesByMonth_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)ChargesByMonth_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ChargesByMonth_get_charge_w_sys_dc_tou_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_HostDeveloper_ChargesByMonth_charge_w_sys_dc_tou_ym_mget, self->data_ptr);
}

static int
ChargesByMonth_set_charge_w_sys_dc_tou_ym(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_HostDeveloper_ChargesByMonth_charge_w_sys_dc_tou_ym_mset, self->data_ptr);
}

static PyObject *
ChargesByMonth_get_charge_w_sys_ec_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_HostDeveloper_ChargesByMonth_charge_w_sys_ec_ym_mget, self->data_ptr);
}

static int
ChargesByMonth_set_charge_w_sys_ec_ym(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_HostDeveloper_ChargesByMonth_charge_w_sys_ec_ym_mset, self->data_ptr);
}

static PyObject *
ChargesByMonth_get_charge_w_sys_fixed_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_HostDeveloper_ChargesByMonth_charge_w_sys_fixed_ym_mget, self->data_ptr);
}

static int
ChargesByMonth_set_charge_w_sys_fixed_ym(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_HostDeveloper_ChargesByMonth_charge_w_sys_fixed_ym_mset, self->data_ptr);
}

static PyObject *
ChargesByMonth_get_net_billing_credits_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_HostDeveloper_ChargesByMonth_net_billing_credits_ym_mget, self->data_ptr);
}

static int
ChargesByMonth_set_net_billing_credits_ym(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_HostDeveloper_ChargesByMonth_net_billing_credits_ym_mset, self->data_ptr);
}

static PyObject *
ChargesByMonth_get_nm_dollars_applied_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_HostDeveloper_ChargesByMonth_nm_dollars_applied_ym_mget, self->data_ptr);
}

static int
ChargesByMonth_set_nm_dollars_applied_ym(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_HostDeveloper_ChargesByMonth_nm_dollars_applied_ym_mset, self->data_ptr);
}

static PyObject *
ChargesByMonth_get_true_up_credits_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_HostDeveloper_ChargesByMonth_true_up_credits_ym_mget, self->data_ptr);
}

static int
ChargesByMonth_set_true_up_credits_ym(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_HostDeveloper_ChargesByMonth_true_up_credits_ym_mset, self->data_ptr);
}

static PyObject *
ChargesByMonth_get_utility_bill_w_sys(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_ChargesByMonth_utility_bill_w_sys_aget, self->data_ptr);
}

static int
ChargesByMonth_set_utility_bill_w_sys(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_ChargesByMonth_utility_bill_w_sys_aset, self->data_ptr);
}

static PyGetSetDef ChargesByMonth_getset[] = {
{"charge_w_sys_dc_tou_ym", (getter)ChargesByMonth_get_charge_w_sys_dc_tou_ym,(setter)ChargesByMonth_set_charge_w_sys_dc_tou_ym,
	PyDoc_STR("*sequence[sequence]*: Demand charge with system (TOU) [$]\n\n**Required:**\nTrue"),
 	NULL},
{"charge_w_sys_ec_ym", (getter)ChargesByMonth_get_charge_w_sys_ec_ym,(setter)ChargesByMonth_set_charge_w_sys_ec_ym,
	PyDoc_STR("*sequence[sequence]*: Energy charge with system [$]"),
 	NULL},
{"charge_w_sys_fixed_ym", (getter)ChargesByMonth_get_charge_w_sys_fixed_ym,(setter)ChargesByMonth_set_charge_w_sys_fixed_ym,
	PyDoc_STR("*sequence[sequence]*: Fixed monthly charge with system [$]\n\n**Required:**\nTrue"),
 	NULL},
{"net_billing_credits_ym", (getter)ChargesByMonth_get_net_billing_credits_ym,(setter)ChargesByMonth_set_net_billing_credits_ym,
	PyDoc_STR("*sequence[sequence]*: Net billing credit [$]\n\n**Required:**\nTrue"),
 	NULL},
{"nm_dollars_applied_ym", (getter)ChargesByMonth_get_nm_dollars_applied_ym,(setter)ChargesByMonth_set_nm_dollars_applied_ym,
	PyDoc_STR("*sequence[sequence]*: Net metering credit [$]\n\n**Required:**\nTrue"),
 	NULL},
{"true_up_credits_ym", (getter)ChargesByMonth_get_true_up_credits_ym,(setter)ChargesByMonth_set_true_up_credits_ym,
	PyDoc_STR("*sequence[sequence]*: Net annual true-up payments [$]"),
 	NULL},
{"utility_bill_w_sys", (getter)ChargesByMonth_get_utility_bill_w_sys,(setter)ChargesByMonth_set_utility_bill_w_sys,
	PyDoc_STR("*sequence*: Electricity bill for system [$]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ChargesByMonth_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.ChargesByMonth",             /*tp_name*/
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
		ChargesByMonth_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ChargesByMonth_getset,          /*tp_getset*/
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
SystemOutput_new(SAM_HostDeveloper data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "SystemOutput")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "SystemOutput")){
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
SystemOutput_get_annual_thermal_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemOutput_annual_thermal_value_aget, self->data_ptr);
}

static int
SystemOutput_set_annual_thermal_value(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemOutput_annual_thermal_value_aset, self->data_ptr);
}

static PyObject *
SystemOutput_get_degradation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemOutput_degradation_aget, self->data_ptr);
}

static int
SystemOutput_set_degradation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemOutput_degradation_aset, self->data_ptr);
}

static PyObject *
SystemOutput_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemOutput_gen_aget, self->data_ptr);
}

static int
SystemOutput_set_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemOutput_gen_aset, self->data_ptr);
}

static PyObject *
SystemOutput_get_gen_purchases(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_SystemOutput_gen_purchases_aget, self->data_ptr);
}

static int
SystemOutput_set_gen_purchases(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_SystemOutput_gen_purchases_aset, self->data_ptr);
}

static PyObject *
SystemOutput_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_SystemOutput_system_capacity_nget, self->data_ptr);
}

static int
SystemOutput_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_SystemOutput_system_capacity_nset, self->data_ptr);
}

static PyGetSetDef SystemOutput_getset[] = {
{"annual_thermal_value", (getter)SystemOutput_get_annual_thermal_value,(setter)SystemOutput_set_annual_thermal_value,
	PyDoc_STR("*sequence*: Host thermal value [$]"),
 	NULL},
{"degradation", (getter)SystemOutput_get_degradation,(setter)SystemOutput_set_degradation,
	PyDoc_STR("*sequence*: Annual energy degradation\n\n**Required:**\nRequired if system_use_lifetime_output=0"),
 	NULL},
{"gen", (getter)SystemOutput_get_gen,(setter)SystemOutput_set_gen,
	PyDoc_STR("*sequence*: Power generated by renewable resource [kW]\n\n**Required:**\nTrue"),
 	NULL},
{"gen_purchases", (getter)SystemOutput_get_gen_purchases,(setter)SystemOutput_set_gen_purchases,
	PyDoc_STR("*sequence*: Electricity from grid to system [kW]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"system_capacity", (getter)SystemOutput_get_system_capacity,(setter)SystemOutput_set_system_capacity,
	PyDoc_STR("*float*: System nameplate capacity [kW]\n\n**Constraints:**\nMIN=1e-3\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``system_capacity``:\n\n\t - battery_total_cost_lcos\n\t - construction_financing_cost\n\t - land_area\n\t - total_installed_cost\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemOutput_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.SystemOutput",             /*tp_name*/
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
 * Moratorium Group
 */ 

static PyTypeObject Moratorium_Type;

static PyObject *
Moratorium_new(SAM_HostDeveloper data_ptr)
{
	PyObject* new_obj = Moratorium_Type.tp_alloc(&Moratorium_Type,0);

	VarGroupObject* Moratorium_obj = (VarGroupObject*)new_obj;

	Moratorium_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Moratorium methods */

static PyObject *
Moratorium_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "Moratorium")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Moratorium_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Moratorium_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "Moratorium")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Moratorium_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Moratorium_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Moratorium_methods[] = {
		{"assign",            (PyCFunction)Moratorium_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Moratorium_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Moratorium_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Moratorium_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Moratorium_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Moratorium_get_loan_moratorium(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Moratorium_loan_moratorium_nget, self->data_ptr);
}

static int
Moratorium_set_loan_moratorium(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Moratorium_loan_moratorium_nset, self->data_ptr);
}

static PyGetSetDef Moratorium_getset[] = {
{"loan_moratorium", (getter)Moratorium_get_loan_moratorium,(setter)Moratorium_set_loan_moratorium,
	PyDoc_STR("*float*: Loan moratorium period [years]\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Moratorium_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.Moratorium",             /*tp_name*/
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
		Moratorium_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Moratorium_getset,          /*tp_getset*/
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
 * Recapitalization Group
 */ 

static PyTypeObject Recapitalization_Type;

static PyObject *
Recapitalization_new(SAM_HostDeveloper data_ptr)
{
	PyObject* new_obj = Recapitalization_Type.tp_alloc(&Recapitalization_Type,0);

	VarGroupObject* Recapitalization_obj = (VarGroupObject*)new_obj;

	Recapitalization_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Recapitalization methods */

static PyObject *
Recapitalization_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "Recapitalization")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Recapitalization_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Recapitalization_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "Recapitalization")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Recapitalization_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Recapitalization_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Recapitalization_methods[] = {
		{"assign",            (PyCFunction)Recapitalization_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Recapitalization_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Recapitalization_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Recapitalization_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Recapitalization_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Recapitalization_get_system_lifetime_recapitalize(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Recapitalization_system_lifetime_recapitalize_aget, self->data_ptr);
}

static int
Recapitalization_set_system_lifetime_recapitalize(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_Recapitalization_system_lifetime_recapitalize_aset, self->data_ptr);
}

static PyObject *
Recapitalization_get_system_recapitalization_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Recapitalization_system_recapitalization_cost_nget, self->data_ptr);
}

static int
Recapitalization_set_system_recapitalization_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Recapitalization_system_recapitalization_cost_nset, self->data_ptr);
}

static PyObject *
Recapitalization_get_system_recapitalization_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Recapitalization_system_recapitalization_escalation_nget, self->data_ptr);
}

static int
Recapitalization_set_system_recapitalization_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Recapitalization_system_recapitalization_escalation_nset, self->data_ptr);
}

static PyObject *
Recapitalization_get_system_use_recapitalization(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Recapitalization_system_use_recapitalization_nget, self->data_ptr);
}

static int
Recapitalization_set_system_use_recapitalization(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_Recapitalization_system_use_recapitalization_nset, self->data_ptr);
}

static PyGetSetDef Recapitalization_getset[] = {
{"system_lifetime_recapitalize", (getter)Recapitalization_get_system_lifetime_recapitalize,(setter)Recapitalization_set_system_lifetime_recapitalize,
	PyDoc_STR("*sequence*: Recapitalization boolean\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"system_recapitalization_cost", (getter)Recapitalization_get_system_recapitalization_cost,(setter)Recapitalization_set_system_recapitalization_cost,
	PyDoc_STR("*float*: Recapitalization cost [$]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"system_recapitalization_escalation", (getter)Recapitalization_get_system_recapitalization_escalation,(setter)Recapitalization_set_system_recapitalization_escalation,
	PyDoc_STR("*float*: Recapitalization escalation (above inflation) [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"system_use_recapitalization", (getter)Recapitalization_get_system_use_recapitalization,(setter)Recapitalization_set_system_use_recapitalization,
	PyDoc_STR("*float*: Recapitalization expenses [0/1]\n\n**Options:**\n0=None,1=Recapitalize\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Recapitalization_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.Recapitalization",             /*tp_name*/
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
		Recapitalization_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Recapitalization_getset,          /*tp_getset*/
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
 * TimeOfDelivery Group
 */ 

static PyTypeObject TimeOfDelivery_Type;

static PyObject *
TimeOfDelivery_new(SAM_HostDeveloper data_ptr)
{
	PyObject* new_obj = TimeOfDelivery_Type.tp_alloc(&TimeOfDelivery_Type,0);

	VarGroupObject* TimeOfDelivery_obj = (VarGroupObject*)new_obj;

	TimeOfDelivery_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* TimeOfDelivery methods */

static PyObject *
TimeOfDelivery_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "TimeOfDelivery")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TimeOfDelivery_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &TimeOfDelivery_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "TimeOfDelivery")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TimeOfDelivery_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &TimeOfDelivery_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TimeOfDelivery_methods[] = {
		{"assign",            (PyCFunction)TimeOfDelivery_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``TimeOfDelivery_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)TimeOfDelivery_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``TimeOfDelivery_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)TimeOfDelivery_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TimeOfDelivery_get_system_use_lifetime_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_TimeOfDelivery_system_use_lifetime_output_nget, self->data_ptr);
}

static int
TimeOfDelivery_set_system_use_lifetime_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_TimeOfDelivery_system_use_lifetime_output_nset, self->data_ptr);
}

static PyGetSetDef TimeOfDelivery_getset[] = {
{"system_use_lifetime_output", (getter)TimeOfDelivery_get_system_use_lifetime_output,(setter)TimeOfDelivery_set_system_use_lifetime_output,
	PyDoc_STR("*float*: Lifetime hourly system outputs [0/1]\n\n**Options:**\n0=hourly first year,1=hourly lifetime\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TimeOfDelivery_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.TimeOfDelivery",             /*tp_name*/
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
		TimeOfDelivery_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TimeOfDelivery_getset,          /*tp_getset*/
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
 * ConstructionFinancing Group
 */ 

static PyTypeObject ConstructionFinancing_Type;

static PyObject *
ConstructionFinancing_new(SAM_HostDeveloper data_ptr)
{
	PyObject* new_obj = ConstructionFinancing_Type.tp_alloc(&ConstructionFinancing_Type,0);

	VarGroupObject* ConstructionFinancing_obj = (VarGroupObject*)new_obj;

	ConstructionFinancing_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* ConstructionFinancing methods */

static PyObject *
ConstructionFinancing_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "ConstructionFinancing")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ConstructionFinancing_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &ConstructionFinancing_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "ConstructionFinancing")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ConstructionFinancing_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &ConstructionFinancing_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ConstructionFinancing_methods[] = {
		{"assign",            (PyCFunction)ConstructionFinancing_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``ConstructionFinancing_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)ConstructionFinancing_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``ConstructionFinancing_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)ConstructionFinancing_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ConstructionFinancing_get_construction_financing_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_ConstructionFinancing_construction_financing_cost_nget, self->data_ptr);
}

static int
ConstructionFinancing_set_construction_financing_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_ConstructionFinancing_construction_financing_cost_nset, self->data_ptr);
}

static PyGetSetDef ConstructionFinancing_getset[] = {
{"construction_financing_cost", (getter)ConstructionFinancing_get_construction_financing_cost,(setter)ConstructionFinancing_set_construction_financing_cost,
	PyDoc_STR("*float*: Construction financing total [$]\n\n**Required:**\nTrue\n\nThe value of ``construction_financing_cost`` depends on the following variables:\n\n\t - battery_per_kWh\n\t - total_installed_cost\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ConstructionFinancing_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.ConstructionFinancing",             /*tp_name*/
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
		ConstructionFinancing_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ConstructionFinancing_getset,          /*tp_getset*/
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
 * BatterySystem Group
 */ 

static PyTypeObject BatterySystem_Type;

static PyObject *
BatterySystem_new(SAM_HostDeveloper data_ptr)
{
	PyObject* new_obj = BatterySystem_Type.tp_alloc(&BatterySystem_Type,0);

	VarGroupObject* BatterySystem_obj = (VarGroupObject*)new_obj;

	BatterySystem_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* BatterySystem methods */

static PyObject *
BatterySystem_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "BatterySystem")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
BatterySystem_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &BatterySystem_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "BatterySystem")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
BatterySystem_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &BatterySystem_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef BatterySystem_methods[] = {
		{"assign",            (PyCFunction)BatterySystem_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``BatterySystem_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)BatterySystem_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``BatterySystem_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)BatterySystem_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
BatterySystem_get_batt_bank_replacement(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_BatterySystem_batt_bank_replacement_aget, self->data_ptr);
}

static int
BatterySystem_set_batt_bank_replacement(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_BatterySystem_batt_bank_replacement_aset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_computed_bank_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_BatterySystem_batt_computed_bank_capacity_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_computed_bank_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_BatterySystem_batt_computed_bank_capacity_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_replacement_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_BatterySystem_batt_replacement_option_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_replacement_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_BatterySystem_batt_replacement_option_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_replacement_schedule_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_BatterySystem_batt_replacement_schedule_percent_aget, self->data_ptr);
}

static int
BatterySystem_set_batt_replacement_schedule_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_BatterySystem_batt_replacement_schedule_percent_aset, self->data_ptr);
}

static PyObject *
BatterySystem_get_battery_per_kWh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_BatterySystem_battery_per_kWh_nget, self->data_ptr);
}

static int
BatterySystem_set_battery_per_kWh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_BatterySystem_battery_per_kWh_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_en_batt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_BatterySystem_en_batt_nget, self->data_ptr);
}

static int
BatterySystem_set_en_batt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_BatterySystem_en_batt_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_en_standalone_batt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_BatterySystem_en_standalone_batt_nget, self->data_ptr);
}

static int
BatterySystem_set_en_standalone_batt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_BatterySystem_en_standalone_batt_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_en_wave_batt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_BatterySystem_en_wave_batt_nget, self->data_ptr);
}

static int
BatterySystem_set_en_wave_batt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_BatterySystem_en_wave_batt_nset, self->data_ptr);
}

static PyGetSetDef BatterySystem_getset[] = {
{"batt_bank_replacement", (getter)BatterySystem_get_batt_bank_replacement,(setter)BatterySystem_set_batt_bank_replacement,
	PyDoc_STR("*sequence*: Battery bank replacements per year [number/year]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"batt_computed_bank_capacity", (getter)BatterySystem_get_batt_computed_bank_capacity,(setter)BatterySystem_set_batt_computed_bank_capacity,
	PyDoc_STR("*float*: Battery bank capacity [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults.\n\nThe value of the following variables depends on ``batt_computed_bank_capacity``:\n\n\t - battery_total_cost_lcos\n\t - construction_financing_cost\n\t - om_batt_nameplate\n\t - total_installed_cost\n"),
 	NULL},
{"batt_replacement_option", (getter)BatterySystem_get_batt_replacement_option,(setter)BatterySystem_set_batt_replacement_option,
	PyDoc_STR("*float*: Enable battery replacement? [0=none,1=capacity based,2=user schedule]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_replacement_schedule_percent", (getter)BatterySystem_get_batt_replacement_schedule_percent,(setter)BatterySystem_set_batt_replacement_schedule_percent,
	PyDoc_STR("*sequence*: Percentage of battery capacity to replace in each year [%]\n\n**Options:**\nlength <= analysis_period"),
 	NULL},
{"battery_per_kWh", (getter)BatterySystem_get_battery_per_kWh,(setter)BatterySystem_set_battery_per_kWh,
	PyDoc_STR("*float*: Battery cost [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults.\n\nThe value of the following variables depends on ``battery_per_kWh``:\n\n\t - battery_total_cost_lcos\n\t - construction_financing_cost\n\t - total_installed_cost\n"),
 	NULL},
{"en_batt", (getter)BatterySystem_get_en_batt,(setter)BatterySystem_set_en_batt,
	PyDoc_STR("*float*: Enable battery storage model [0/1]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"en_standalone_batt", (getter)BatterySystem_get_en_standalone_batt,(setter)BatterySystem_set_en_standalone_batt,
	PyDoc_STR("*float*: Enable standalone battery storage model [0/1]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"en_wave_batt", (getter)BatterySystem_get_en_wave_batt,(setter)BatterySystem_set_en_wave_batt,
	PyDoc_STR("*float*: Enable standalone battery storage model [0/1]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject BatterySystem_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.BatterySystem",             /*tp_name*/
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
		BatterySystem_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		BatterySystem_getset,          /*tp_getset*/
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
 * LCOS Group
 */ 

static PyTypeObject LCOS_Type;

static PyObject *
LCOS_new(SAM_HostDeveloper data_ptr)
{
	PyObject* new_obj = LCOS_Type.tp_alloc(&LCOS_Type,0);

	VarGroupObject* LCOS_obj = (VarGroupObject*)new_obj;

	LCOS_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* LCOS methods */

static PyObject *
LCOS_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "LCOS")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
LCOS_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &LCOS_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "LCOS")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
LCOS_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &LCOS_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef LCOS_methods[] = {
		{"assign",            (PyCFunction)LCOS_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``LCOS_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)LCOS_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``LCOS_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)LCOS_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
LCOS_get_batt_annual_charge_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_LCOS_batt_annual_charge_energy_aget, self->data_ptr);
}

static int
LCOS_set_batt_annual_charge_energy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_LCOS_batt_annual_charge_energy_aset, self->data_ptr);
}

static PyObject *
LCOS_get_batt_annual_charge_from_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_LCOS_batt_annual_charge_from_system_aget, self->data_ptr);
}

static int
LCOS_set_batt_annual_charge_from_system(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_LCOS_batt_annual_charge_from_system_aset, self->data_ptr);
}

static PyObject *
LCOS_get_batt_annual_discharge_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_LCOS_batt_annual_discharge_energy_aget, self->data_ptr);
}

static int
LCOS_set_batt_annual_discharge_energy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_LCOS_batt_annual_discharge_energy_aset, self->data_ptr);
}

static PyObject *
LCOS_get_batt_capacity_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_LCOS_batt_capacity_percent_aget, self->data_ptr);
}

static int
LCOS_set_batt_capacity_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_LCOS_batt_capacity_percent_aset, self->data_ptr);
}

static PyObject *
LCOS_get_batt_salvage_percentage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_LCOS_batt_salvage_percentage_nget, self->data_ptr);
}

static int
LCOS_set_batt_salvage_percentage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_LCOS_batt_salvage_percentage_nset, self->data_ptr);
}

static PyObject *
LCOS_get_battery_total_cost_lcos(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_LCOS_battery_total_cost_lcos_nget, self->data_ptr);
}

static int
LCOS_set_battery_total_cost_lcos(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_LCOS_battery_total_cost_lcos_nset, self->data_ptr);
}

static PyObject *
LCOS_get_charge_w_sys_ec_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_HostDeveloper_LCOS_charge_w_sys_ec_ym_mget, self->data_ptr);
}

static int
LCOS_set_charge_w_sys_ec_ym(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_HostDeveloper_LCOS_charge_w_sys_ec_ym_mset, self->data_ptr);
}

static PyObject *
LCOS_get_grid_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_LCOS_grid_to_batt_aget, self->data_ptr);
}

static int
LCOS_set_grid_to_batt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_LCOS_grid_to_batt_aset, self->data_ptr);
}

static PyObject *
LCOS_get_monthly_batt_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_LCOS_monthly_batt_to_grid_aget, self->data_ptr);
}

static int
LCOS_set_monthly_batt_to_grid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_LCOS_monthly_batt_to_grid_aset, self->data_ptr);
}

static PyObject *
LCOS_get_monthly_grid_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_LCOS_monthly_grid_to_batt_aget, self->data_ptr);
}

static int
LCOS_set_monthly_grid_to_batt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_LCOS_monthly_grid_to_batt_aset, self->data_ptr);
}

static PyObject *
LCOS_get_monthly_grid_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_LCOS_monthly_grid_to_load_aget, self->data_ptr);
}

static int
LCOS_set_monthly_grid_to_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_LCOS_monthly_grid_to_load_aset, self->data_ptr);
}

static PyObject *
LCOS_get_monthly_system_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_LCOS_monthly_system_to_grid_aget, self->data_ptr);
}

static int
LCOS_set_monthly_system_to_grid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_LCOS_monthly_system_to_grid_aset, self->data_ptr);
}

static PyObject *
LCOS_get_true_up_credits_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_HostDeveloper_LCOS_true_up_credits_ym_mget, self->data_ptr);
}

static int
LCOS_set_true_up_credits_ym(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_HostDeveloper_LCOS_true_up_credits_ym_mset, self->data_ptr);
}

static PyObject *
LCOS_get_year1_monthly_ec_charge_gross_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_LCOS_year1_monthly_ec_charge_gross_with_system_aget, self->data_ptr);
}

static int
LCOS_set_year1_monthly_ec_charge_gross_with_system(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_LCOS_year1_monthly_ec_charge_gross_with_system_aset, self->data_ptr);
}

static PyObject *
LCOS_get_year1_monthly_ec_charge_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_LCOS_year1_monthly_ec_charge_with_system_aget, self->data_ptr);
}

static int
LCOS_set_year1_monthly_ec_charge_with_system(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_LCOS_year1_monthly_ec_charge_with_system_aset, self->data_ptr);
}

static PyObject *
LCOS_get_year1_monthly_electricity_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_LCOS_year1_monthly_electricity_to_grid_aget, self->data_ptr);
}

static int
LCOS_set_year1_monthly_electricity_to_grid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_LCOS_year1_monthly_electricity_to_grid_aset, self->data_ptr);
}

static PyGetSetDef LCOS_getset[] = {
{"batt_annual_charge_energy", (getter)LCOS_get_batt_annual_charge_energy,(setter)LCOS_set_batt_annual_charge_energy,
	PyDoc_STR("*sequence*: Battery annual energy charged [kWh]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"batt_annual_charge_from_system", (getter)LCOS_get_batt_annual_charge_from_system,(setter)LCOS_set_batt_annual_charge_from_system,
	PyDoc_STR("*sequence*: Battery annual energy charged from system [kWh]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"batt_annual_discharge_energy", (getter)LCOS_get_batt_annual_discharge_energy,(setter)LCOS_set_batt_annual_discharge_energy,
	PyDoc_STR("*sequence*: Battery annual energy discharged [kWh]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"batt_capacity_percent", (getter)LCOS_get_batt_capacity_percent,(setter)LCOS_set_batt_capacity_percent,
	PyDoc_STR("*sequence*: Battery relative capacity to nameplate [%]"),
 	NULL},
{"batt_salvage_percentage", (getter)LCOS_get_batt_salvage_percentage,(setter)LCOS_set_batt_salvage_percentage,
	PyDoc_STR("*float*: Net pre-tax cash battery salvage value [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"battery_total_cost_lcos", (getter)LCOS_get_battery_total_cost_lcos,(setter)LCOS_set_battery_total_cost_lcos,
	PyDoc_STR("*float*: Battery total investment cost [$]\n\nThe value of ``battery_total_cost_lcos`` depends on the following variables:\n\n\t - battery_per_kWh\n\t - total_installed_cost\n"),
 	NULL},
{"charge_w_sys_ec_ym", (getter)LCOS_get_charge_w_sys_ec_ym,(setter)LCOS_set_charge_w_sys_ec_ym,
	PyDoc_STR("*sequence[sequence]*: Energy charge with system [$]"),
 	NULL},
{"grid_to_batt", (getter)LCOS_get_grid_to_batt,(setter)LCOS_set_grid_to_batt,
	PyDoc_STR("*sequence*: Electricity to grid from battery [kW]"),
 	NULL},
{"monthly_batt_to_grid", (getter)LCOS_get_monthly_batt_to_grid,(setter)LCOS_set_monthly_batt_to_grid,
	PyDoc_STR("*sequence*: Energy to grid from battery [kWh]\n\n**Constraints:**\nLENGTH=12"),
 	NULL},
{"monthly_grid_to_batt", (getter)LCOS_get_monthly_grid_to_batt,(setter)LCOS_set_monthly_grid_to_batt,
	PyDoc_STR("*sequence*: Energy to battery from grid [kWh]\n\n**Constraints:**\nLENGTH=12"),
 	NULL},
{"monthly_grid_to_load", (getter)LCOS_get_monthly_grid_to_load,(setter)LCOS_set_monthly_grid_to_load,
	PyDoc_STR("*sequence*: Energy to load from grid [kWh]\n\n**Constraints:**\nLENGTH=12"),
 	NULL},
{"monthly_system_to_grid", (getter)LCOS_get_monthly_system_to_grid,(setter)LCOS_set_monthly_system_to_grid,
	PyDoc_STR("*sequence*: Energy to grid from system [kWh]\n\n**Constraints:**\nLENGTH=12"),
 	NULL},
{"true_up_credits_ym", (getter)LCOS_get_true_up_credits_ym,(setter)LCOS_set_true_up_credits_ym,
	PyDoc_STR("*sequence[sequence]*: Net annual true-up payments [$]"),
 	NULL},
{"year1_monthly_ec_charge_gross_with_system", (getter)LCOS_get_year1_monthly_ec_charge_gross_with_system,(setter)LCOS_set_year1_monthly_ec_charge_gross_with_system,
	PyDoc_STR("*sequence*: Energy charge with system before credits [$/mo]\n\n**Constraints:**\nLENGTH=12"),
 	NULL},
{"year1_monthly_ec_charge_with_system", (getter)LCOS_get_year1_monthly_ec_charge_with_system,(setter)LCOS_set_year1_monthly_ec_charge_with_system,
	PyDoc_STR("*sequence*: Energy charge with system [$]"),
 	NULL},
{"year1_monthly_electricity_to_grid", (getter)LCOS_get_year1_monthly_electricity_to_grid,(setter)LCOS_set_year1_monthly_electricity_to_grid,
	PyDoc_STR("*sequence*: Electricity to/from grid [kWh/mo]\n\n**Constraints:**\nLENGTH=12"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject LCOS_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.LCOS",             /*tp_name*/
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
		LCOS_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		LCOS_getset,          /*tp_getset*/
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
ElectricityRates_new(SAM_HostDeveloper data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "ElectricityRates")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "ElectricityRates")){
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
ElectricityRates_get_rate_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_ElectricityRates_rate_escalation_aget, self->data_ptr);
}

static int
ElectricityRates_set_rate_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_ElectricityRates_rate_escalation_aset, self->data_ptr);
}

static PyGetSetDef ElectricityRates_getset[] = {
{"rate_escalation", (getter)ElectricityRates_get_rate_escalation,(setter)ElectricityRates_set_rate_escalation,
	PyDoc_STR("*sequence*: Annual electricity rate escalation [%/year]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ElectricityRates_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.ElectricityRates",             /*tp_name*/
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
 * HybridFin Group
 */ 

static PyTypeObject HybridFin_Type;

static PyObject *
HybridFin_new(SAM_HostDeveloper data_ptr)
{
	PyObject* new_obj = HybridFin_Type.tp_alloc(&HybridFin_Type,0);

	VarGroupObject* HybridFin_obj = (VarGroupObject*)new_obj;

	HybridFin_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* HybridFin methods */

static PyObject *
HybridFin_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "HybridFin")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
HybridFin_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &HybridFin_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "HybridFin")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
HybridFin_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &HybridFin_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef HybridFin_methods[] = {
		{"assign",            (PyCFunction)HybridFin_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``HybridFin_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)HybridFin_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``HybridFin_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)HybridFin_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
HybridFin_get_cf_hybrid_om_sum(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_HybridFin_cf_hybrid_om_sum_aget, self->data_ptr);
}

static int
HybridFin_set_cf_hybrid_om_sum(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_HybridFin_cf_hybrid_om_sum_aset, self->data_ptr);
}

static PyObject *
HybridFin_get_is_hybrid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_HybridFin_is_hybrid_nget, self->data_ptr);
}

static int
HybridFin_set_is_hybrid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_HybridFin_is_hybrid_nset, self->data_ptr);
}

static PyGetSetDef HybridFin_getset[] = {
{"cf_hybrid_om_sum", (getter)HybridFin_get_cf_hybrid_om_sum,(setter)HybridFin_set_cf_hybrid_om_sum,
	PyDoc_STR("*sequence*: Hybrid O&M costs [$]"),
 	NULL},
{"is_hybrid", (getter)HybridFin_get_is_hybrid,(setter)HybridFin_set_is_hybrid,
	PyDoc_STR("*float*: hybrid configuration [0/1]\n\n**Options:**\n0=singletech,1=hybrid\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject HybridFin_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.HybridFin",             /*tp_name*/
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
		HybridFin_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		HybridFin_getset,          /*tp_getset*/
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
 * Monthly Group
 */ 

static PyTypeObject Monthly_Type;

static PyObject *
Monthly_new(SAM_HostDeveloper data_ptr)
{
	PyObject* new_obj = Monthly_Type.tp_alloc(&Monthly_Type,0);

	VarGroupObject* Monthly_obj = (VarGroupObject*)new_obj;

	Monthly_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Monthly methods */

static PyObject *
Monthly_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "Monthly")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Monthly_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Monthly_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "Monthly")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Monthly_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Monthly_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Monthly_methods[] = {
		{"assign",            (PyCFunction)Monthly_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Monthly_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Monthly_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Monthly_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Monthly_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Monthly_get_monthly_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Monthly_monthly_energy_aget, self->data_ptr);
}

static int
Monthly_set_monthly_energy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_Monthly_monthly_energy_aset, self->data_ptr);
}

static PyGetSetDef Monthly_getset[] = {
{"monthly_energy", (getter)Monthly_get_monthly_energy,(setter)Monthly_set_monthly_energy,
	PyDoc_STR("*sequence*: Monthly AC energy in Year 1 [kWh]\n\n**Constraints:**\nLENGTH = 12"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Monthly_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.Monthly",             /*tp_name*/
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
		Monthly_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Monthly_getset,          /*tp_getset*/
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
 * FuelCell Group
 */ 

static PyTypeObject FuelCell_Type;

static PyObject *
FuelCell_new(SAM_HostDeveloper data_ptr)
{
	PyObject* new_obj = FuelCell_Type.tp_alloc(&FuelCell_Type,0);

	VarGroupObject* FuelCell_obj = (VarGroupObject*)new_obj;

	FuelCell_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* FuelCell methods */

static PyObject *
FuelCell_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "FuelCell")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FuelCell_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &FuelCell_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "FuelCell")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FuelCell_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &FuelCell_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef FuelCell_methods[] = {
		{"assign",            (PyCFunction)FuelCell_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``FuelCell_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)FuelCell_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``FuelCell_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)FuelCell_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
FuelCell_get_annual_fuel_usage_lifetime(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_FuelCell_annual_fuel_usage_lifetime_aget, self->data_ptr);
}

static int
FuelCell_set_annual_fuel_usage_lifetime(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_FuelCell_annual_fuel_usage_lifetime_aset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_annual_energy_discharged(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_FuelCell_fuelcell_annual_energy_discharged_aget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_annual_energy_discharged(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_FuelCell_fuelcell_annual_energy_discharged_aset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_replacement(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_FuelCell_fuelcell_replacement_aget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_replacement(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_FuelCell_fuelcell_replacement_aset, self->data_ptr);
}

static PyGetSetDef FuelCell_getset[] = {
{"annual_fuel_usage_lifetime", (getter)FuelCell_get_annual_fuel_usage_lifetime,(setter)FuelCell_set_annual_fuel_usage_lifetime,
	PyDoc_STR("*sequence*: Annual Fuel Usage (lifetime) [kWht]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"fuelcell_annual_energy_discharged", (getter)FuelCell_get_fuelcell_annual_energy_discharged,(setter)FuelCell_set_fuelcell_annual_energy_discharged,
	PyDoc_STR("*sequence*: Fuel cell annual energy discharged [kWh]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"fuelcell_replacement", (getter)FuelCell_get_fuelcell_replacement,(setter)FuelCell_set_fuelcell_replacement,
	PyDoc_STR("*sequence*: Fuel cell replacements per year [number/year]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FuelCell_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.FuelCell",             /*tp_name*/
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
		FuelCell_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		FuelCell_getset,          /*tp_getset*/
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
 * HybridCosts Group
 */ 

static PyTypeObject HybridCosts_Type;

static PyObject *
HybridCosts_new(SAM_HostDeveloper data_ptr)
{
	PyObject* new_obj = HybridCosts_Type.tp_alloc(&HybridCosts_Type,0);

	VarGroupObject* HybridCosts_obj = (VarGroupObject*)new_obj;

	HybridCosts_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* HybridCosts methods */

static PyObject *
HybridCosts_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "HybridCosts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
HybridCosts_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &HybridCosts_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "HybridCosts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
HybridCosts_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &HybridCosts_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef HybridCosts_methods[] = {
		{"assign",            (PyCFunction)HybridCosts_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``HybridCosts_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)HybridCosts_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``HybridCosts_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)HybridCosts_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
HybridCosts_get_degradation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_HybridCosts_degradation_aget, self->data_ptr);
}

static int
HybridCosts_set_degradation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_HostDeveloper_HybridCosts_degradation_aset, self->data_ptr);
}

static PyObject *
HybridCosts_get_total_installed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_HybridCosts_total_installed_cost_nget, self->data_ptr);
}

static int
HybridCosts_set_total_installed_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_HostDeveloper_HybridCosts_total_installed_cost_nset, self->data_ptr);
}

static PyGetSetDef HybridCosts_getset[] = {
{"degradation", (getter)HybridCosts_get_degradation,(setter)HybridCosts_set_degradation,
	PyDoc_STR("*sequence*: Annual AC degradation [%]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"total_installed_cost", (getter)HybridCosts_get_total_installed_cost,(setter)HybridCosts_set_total_installed_cost,
	PyDoc_STR("*float*: Total installed cost [$]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``total_installed_cost``:\n\n\t - battery_total_cost_lcos\n\t - construction_financing_cost\n\n\nThe value of ``total_installed_cost`` depends on the following variables:\n\n\t - battery_per_kWh\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject HybridCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper.HybridCosts",             /*tp_name*/
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
		HybridCosts_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		HybridCosts_getset,          /*tp_getset*/
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
Outputs_new(SAM_HostDeveloper data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "HostDeveloper", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "HostDeveloper", "Outputs")){
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
Outputs_get_adjusted_installed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_adjusted_installed_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_analysis_period_irr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_analysis_period_irr_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cash_for_debt_service(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_cash_for_debt_service_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_fedtax_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_cbi_fedtax_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_statax_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_cbi_statax_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_cbi_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_cbi_total_fed_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_oth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_cbi_total_oth_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_cbi_total_sta_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_uti(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_cbi_total_uti_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_after_tax_cash_flow(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_after_tax_cash_flow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_after_tax_net_equity_cost_flow(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_after_tax_net_equity_cost_flow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_agreement_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_agreement_cost_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_annual_cost_lcos(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_annual_cost_lcos_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_annual_costs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_annual_costs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_annual_discharge_lcos(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_annual_discharge_lcos_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_battery_replacement_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_battery_replacement_cost_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_battery_replacement_cost_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_battery_replacement_cost_schedule_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_cash_for_ds(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_cash_for_ds_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_charging_cost_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_charging_cost_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_charging_cost_grid_month(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_charging_cost_grid_month_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_charging_cost_pv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_charging_cost_pv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_cumulative_payback_with_expenses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_cumulative_payback_with_expenses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_debt_balance(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_debt_balance_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_debt_payment_interest(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_debt_payment_interest_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_debt_payment_principal(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_debt_payment_principal_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_debt_payment_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_debt_payment_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_debt_size(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_debt_size_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_disbursement_debtservice(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_disbursement_debtservice_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_disbursement_equip1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_disbursement_equip1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_disbursement_equip2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_disbursement_equip2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_disbursement_equip3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_disbursement_equip3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_disbursement_om(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_disbursement_om_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_disbursement_receivables(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_disbursement_receivables_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_ebitda(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_ebitda_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_effective_tax_frac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_effective_tax_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_purchases(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_purchases_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_dispatch1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_dispatch1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_dispatch2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_dispatch2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_dispatch3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_dispatch3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_dispatch4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_dispatch4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_dispatch5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_dispatch5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_dispatch6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_dispatch6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_dispatch7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_dispatch7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_dispatch8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_dispatch8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_dispatch9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_dispatch9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_monthly_firstyear_TOD1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_monthly_firstyear_TOD1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_monthly_firstyear_TOD2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_monthly_firstyear_TOD2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_monthly_firstyear_TOD3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_monthly_firstyear_TOD3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_monthly_firstyear_TOD4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_monthly_firstyear_TOD4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_monthly_firstyear_TOD5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_monthly_firstyear_TOD5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_monthly_firstyear_TOD6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_monthly_firstyear_TOD6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_monthly_firstyear_TOD7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_monthly_firstyear_TOD7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_monthly_firstyear_TOD8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_monthly_firstyear_TOD8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_monthly_firstyear_TOD9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_monthly_firstyear_TOD9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_sales_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_without_battery(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_energy_without_battery_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_custom(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_feddepr_custom_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_feddepr_macrs_15_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_feddepr_macrs_5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_me1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_feddepr_me1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_me2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_feddepr_me2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_me3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_feddepr_me3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_feddepr_sl_15_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_feddepr_sl_20_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_feddepr_sl_39_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_feddepr_sl_5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_feddepr_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_federal_tax_frac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_federal_tax_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fedtax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_fedtax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fedtax_income_prior_incentives(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_fedtax_income_prior_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fedtax_income_with_incentives(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_fedtax_income_with_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fedtax_taxable_incentives(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_fedtax_taxable_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_funding_debtservice(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_funding_debtservice_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_funding_equip1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_funding_equip1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_funding_equip2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_funding_equip2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_funding_equip3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_funding_equip3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_funding_om(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_funding_om_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_funding_receivables(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_funding_receivables_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_insurance_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_insurance_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_fed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_itc_fed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_fed_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_itc_fed_amount_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_fed_percent_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_itc_fed_percent_amount_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_sta(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_itc_sta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_sta_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_itc_sta_amount_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_sta_percent_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_itc_sta_percent_amount_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_itc_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_land_lease_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_land_lease_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_length(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_cf_length_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_net_salvage_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_net_salvage_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_nte(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_nte_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_batt_capacity_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_om_batt_capacity_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_batt_fixed_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_om_batt_fixed_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_capacity1_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_om_capacity1_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_capacity2_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_om_capacity2_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_capacity_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_om_capacity_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_fixed1_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_om_fixed1_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_fixed2_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_om_fixed2_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_fixed_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_om_fixed_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_fuel_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_om_fuel_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_opt_fuel_1_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_om_opt_fuel_1_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_opt_fuel_2_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_om_opt_fuel_2_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_production1_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_om_production1_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_production2_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_om_production2_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_production_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_om_production_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_operating_expenses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_operating_expenses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_parasitic_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_parasitic_cost_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_payback_with_expenses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_payback_with_expenses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_fedtax_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_pbi_fedtax_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_statax_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_pbi_statax_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_pbi_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_fed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_pbi_total_fed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_oth(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_pbi_total_oth_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_sta(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_pbi_total_sta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_uti(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_pbi_total_uti_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_ppa_price(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_ppa_price_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pretax_cashflow(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_pretax_cashflow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pretax_dscr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_pretax_dscr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_dsra(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_dsra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_financing_activities(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_financing_activities_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_investing_activities(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_investing_activities_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_me1cs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_me1cs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_me1ra(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_me1ra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_me2cs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_me2cs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_me2ra(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_me2ra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_me3cs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_me3cs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_me3ra(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_me3ra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_mecs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_mecs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_operating_activities(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_operating_activities_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_ra(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_ra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_receivablesra(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_receivablesra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_return_aftertax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_return_aftertax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_return_aftertax_cash(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_return_aftertax_cash_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_return_aftertax_irr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_return_aftertax_irr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_return_aftertax_max_irr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_return_aftertax_max_irr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_return_aftertax_npv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_return_aftertax_npv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_return_pretax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_return_pretax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_return_pretax_irr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_return_pretax_irr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_return_pretax_npv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_return_pretax_npv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_wcra(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_project_wcra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_property_tax_assessed_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_property_tax_assessed_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_property_tax_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_property_tax_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_ptc_fed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_ptc_fed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_ptc_sta(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_ptc_sta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pv_cash_for_ds(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_pv_cash_for_ds_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pv_interest_factor(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_pv_interest_factor_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_recapitalization(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_recapitalization_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_debtservice(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_reserve_debtservice_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_equip1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_reserve_equip1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_equip2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_reserve_equip2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_equip3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_reserve_equip3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_interest(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_reserve_interest_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_om(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_reserve_om_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_receivables(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_reserve_receivables_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_reserve_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_dispatch1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_dispatch2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_dispatch3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_dispatch4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_dispatch5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_dispatch6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_dispatch7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_dispatch8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_dispatch9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_monthly_firstyear_TOD1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_monthly_firstyear_TOD2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_monthly_firstyear_TOD3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_monthly_firstyear_TOD4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_monthly_firstyear_TOD5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_monthly_firstyear_TOD6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_monthly_firstyear_TOD7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_monthly_firstyear_TOD8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_monthly_firstyear_TOD9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_revenue_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_salvage_cost_lcos(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_salvage_cost_lcos_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_custom(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_stadepr_custom_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_stadepr_macrs_15_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_stadepr_macrs_5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_me1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_stadepr_me1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_me2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_stadepr_me2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_me3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_stadepr_me3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_stadepr_sl_15_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_stadepr_sl_20_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_stadepr_sl_39_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_stadepr_sl_5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_stadepr_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_statax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_statax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_statax_income_prior_incentives(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_statax_income_prior_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_statax_income_with_incentives(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_statax_income_with_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_statax_taxable_incentives(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_statax_taxable_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_state_tax_frac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_state_tax_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_total_revenue(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_total_revenue_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_util_escal_rate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_cf_util_escal_rate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cost_debt_upfront(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_cost_debt_upfront_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cost_financing(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_cost_financing_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cost_installed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_cost_installed_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cost_installedperwatt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_cost_installedperwatt_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cost_prefinancing(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_cost_prefinancing_nget, self->data_ptr);
}

static PyObject *
Outputs_get_debt_fraction(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_debt_fraction_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_alloc_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_alloc_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_alloc_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_none(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_alloc_none_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_none_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_alloc_none_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_alloc_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_alloc_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_alloc_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_alloc_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_alloc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_after_itc_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_after_itc_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_after_itc_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_after_itc_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_after_itc_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_after_itc_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_after_itc_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_after_itc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_cbi_reduc_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_cbi_reduc_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_cbi_reduc_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_cbi_reduc_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_cbi_reduc_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_cbi_reduc_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_cbi_reduc_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_cbi_reduc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_first_year_bonus_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_first_year_bonus_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_first_year_bonus_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_first_year_bonus_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_first_year_bonus_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_first_year_bonus_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_first_year_bonus_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_first_year_bonus_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_fixed_amount_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_fixed_amount_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_fixed_amount_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_fixed_amount_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_fixed_amount_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_fixed_amount_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_fixed_amount_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_fixed_amount_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_ibi_reduc_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_ibi_reduc_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_ibi_reduc_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_ibi_reduc_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_ibi_reduc_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_ibi_reduc_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_ibi_reduc_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_ibi_reduc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_itc_fed_reduction_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_itc_fed_reduction_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_itc_fed_reduction_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_itc_fed_reduction_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_itc_fed_reduction_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_itc_fed_reduction_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_itc_fed_reduction_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_itc_fed_reduction_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_itc_sta_reduction_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_itc_sta_reduction_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_itc_sta_reduction_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_itc_sta_reduction_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_itc_sta_reduction_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_itc_sta_reduction_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_itc_sta_reduction_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_itc_sta_reduction_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_amount_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_amount_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_amount_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_amount_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_amount_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_amount_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_amount_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_amount_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_qual_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_qual_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_qual_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_qual_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_qual_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_qual_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_qual_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_qual_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_percent_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_prior_itc_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_prior_itc_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_prior_itc_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_prior_itc_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_prior_itc_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_prior_itc_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_prior_itc_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_prior_itc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_fedbas_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_after_itc_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_after_itc_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_after_itc_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_after_itc_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_after_itc_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_after_itc_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_after_itc_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_after_itc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_cbi_reduc_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_cbi_reduc_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_cbi_reduc_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_cbi_reduc_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_cbi_reduc_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_cbi_reduc_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_cbi_reduc_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_cbi_reduc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_first_year_bonus_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_first_year_bonus_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_first_year_bonus_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_first_year_bonus_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_first_year_bonus_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_first_year_bonus_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_first_year_bonus_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_first_year_bonus_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_fixed_amount_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_fixed_amount_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_fixed_amount_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_fixed_amount_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_fixed_amount_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_fixed_amount_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_fixed_amount_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_fixed_amount_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_ibi_reduc_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_ibi_reduc_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_ibi_reduc_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_ibi_reduc_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_ibi_reduc_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_ibi_reduc_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_ibi_reduc_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_ibi_reduc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_itc_fed_reduction_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_itc_fed_reduction_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_itc_fed_reduction_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_itc_fed_reduction_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_itc_fed_reduction_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_itc_fed_reduction_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_itc_fed_reduction_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_itc_fed_reduction_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_itc_sta_reduction_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_itc_sta_reduction_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_itc_sta_reduction_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_itc_sta_reduction_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_itc_sta_reduction_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_itc_sta_reduction_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_itc_sta_reduction_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_itc_sta_reduction_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_amount_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_amount_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_amount_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_amount_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_amount_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_amount_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_amount_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_amount_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_qual_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_qual_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_qual_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_qual_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_qual_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_qual_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_qual_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_qual_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_percent_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_prior_itc_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_prior_itc_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_prior_itc_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_prior_itc_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_prior_itc_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_prior_itc_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_prior_itc_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_prior_itc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_depr_stabas_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_effective_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_effective_tax_rate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_energy_dispatch1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_energy_dispatch2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_energy_dispatch3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_energy_dispatch4_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_energy_dispatch5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_energy_dispatch6_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch7(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_energy_dispatch7_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch8(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_energy_dispatch8_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch9(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_energy_dispatch9_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_energy_price1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_energy_price2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_energy_price3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_energy_price4_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_energy_price5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_energy_price6_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price7(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_energy_price7_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price8(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_energy_price8_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price9(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_energy_price9_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_revenue_dispatch1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_revenue_dispatch2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_revenue_dispatch3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_revenue_dispatch4_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_revenue_dispatch5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_revenue_dispatch6_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch7(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_revenue_dispatch7_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch8(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_revenue_dispatch8_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch9(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_firstyear_revenue_dispatch9_nget, self->data_ptr);
}

static PyObject *
Outputs_get_flip_actual_irr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_flip_actual_irr_nget, self->data_ptr);
}

static PyObject *
Outputs_get_flip_actual_year(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_flip_actual_year_nget, self->data_ptr);
}

static PyObject *
Outputs_get_flip_target_irr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_flip_target_irr_nget, self->data_ptr);
}

static PyObject *
Outputs_get_flip_target_year(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_flip_target_year_nget, self->data_ptr);
}

static PyObject *
Outputs_get_host_nominal_discount_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_host_nominal_discount_rate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_fedtax_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_ibi_fedtax_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_statax_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_ibi_statax_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_ibi_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_ibi_total_fed_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_oth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_ibi_total_oth_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_ibi_total_sta_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_uti(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_ibi_total_uti_nget, self->data_ptr);
}

static PyObject *
Outputs_get_issuance_of_equity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_issuance_of_equity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_fed_fixed_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_fed_fixed_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_fed_fixed_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_fed_fixed_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_fed_fixed_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_fed_fixed_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_fed_fixed_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_fed_fixed_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_fed_percent_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_fed_percent_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_fed_percent_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_fed_percent_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_fed_percent_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_fed_percent_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_fed_percent_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_fed_percent_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_sta_fixed_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_sta_fixed_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_sta_fixed_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_sta_fixed_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_sta_fixed_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_sta_fixed_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_sta_fixed_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_sta_fixed_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_sta_percent_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_sta_percent_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_sta_percent_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_sta_percent_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_sta_percent_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_sta_percent_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_sta_percent_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_disallow_sta_percent_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_fixed_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_fed_fixed_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_percent_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_fed_percent_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_fed_qual_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_fed_qual_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_fed_qual_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_fed_qual_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_fed_qual_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_fed_qual_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_fed_qual_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_fed_qual_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_fixed_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_sta_fixed_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_percent_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_sta_percent_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_sta_qual_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_sta_qual_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_sta_qual_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_sta_qual_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_sta_qual_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_sta_qual_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_sta_qual_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_sta_qual_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_total_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_total_fed_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_total_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_itc_total_sta_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoe_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_lcoe_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoe_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_lcoe_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_fed_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_lcoptc_fed_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_fed_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_lcoptc_fed_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_sta_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_lcoptc_sta_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_sta_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_lcoptc_sta_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcos_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_lcos_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcos_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_lcos_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lnte_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_lnte_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lnte_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_lnte_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lppa_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_lppa_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lppa_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_lppa_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_min_dscr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_min_dscr_nget, self->data_ptr);
}

static PyObject *
Outputs_get_nominal_discount_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_nominal_discount_rate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_npv(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_npv_nget, self->data_ptr);
}

static PyObject *
Outputs_get_npv_annual_costs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_npv_annual_costs_nget, self->data_ptr);
}

static PyObject *
Outputs_get_npv_annual_costs_lcos(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_npv_annual_costs_lcos_nget, self->data_ptr);
}

static PyObject *
Outputs_get_npv_energy_lcos_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_npv_energy_lcos_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_npv_energy_lcos_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_npv_energy_lcos_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_npv_energy_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_npv_energy_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_npv_energy_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_npv_energy_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_npv_ppa_revenue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_npv_ppa_revenue_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ppa(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_ppa_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ppa_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_ppa_escalation_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ppa_multipliers(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_HostDeveloper_Outputs_ppa_multipliers_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ppa_price(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_ppa_price_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pre_depr_alloc_basis(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_pre_depr_alloc_basis_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pre_itc_qual_basis(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_pre_itc_qual_basis_nget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_fuel(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_present_value_fuel_nget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_insandproptax(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_present_value_insandproptax_nget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_oandm(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_present_value_oandm_nget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_oandm_nonfuel(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_present_value_oandm_nonfuel_nget, self->data_ptr);
}

static PyObject *
Outputs_get_project_return_aftertax_irr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_project_return_aftertax_irr_nget, self->data_ptr);
}

static PyObject *
Outputs_get_project_return_aftertax_npv(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_project_return_aftertax_npv_nget, self->data_ptr);
}

static PyObject *
Outputs_get_prop_tax_assessed_value(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_prop_tax_assessed_value_nget, self->data_ptr);
}

static PyObject *
Outputs_get_purchase_of_property(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_purchase_of_property_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pv_cafds(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_pv_cafds_nget, self->data_ptr);
}

static PyObject *
Outputs_get_salvage_value(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_salvage_value_nget, self->data_ptr);
}

static PyObject *
Outputs_get_size_of_debt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_size_of_debt_nget, self->data_ptr);
}

static PyObject *
Outputs_get_size_of_equity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_size_of_equity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_wacc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_wacc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_nte(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_HostDeveloper_Outputs_year1_nte_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"adjusted_installed_cost", (getter)Outputs_get_adjusted_installed_cost,(setter)0,
	PyDoc_STR("*float*: Initial cost less cash incentives [$]"),
 	NULL},
{"analysis_period_irr", (getter)Outputs_get_analysis_period_irr,(setter)0,
	PyDoc_STR("*float*: IRR at end of analysis period [%]"),
 	NULL},
{"cash_for_debt_service", (getter)Outputs_get_cash_for_debt_service,(setter)0,
	PyDoc_STR("*float*: Cash available for debt service (CAFDS) [$]"),
 	NULL},
{"cbi_fedtax_total", (getter)Outputs_get_cbi_fedtax_total,(setter)0,
	PyDoc_STR("*float*: Federal taxable CBI income [$]"),
 	NULL},
{"cbi_statax_total", (getter)Outputs_get_cbi_statax_total,(setter)0,
	PyDoc_STR("*float*: State taxable CBI income [$]"),
 	NULL},
{"cbi_total", (getter)Outputs_get_cbi_total,(setter)0,
	PyDoc_STR("*float*: Total CBI income [$]"),
 	NULL},
{"cbi_total_fed", (getter)Outputs_get_cbi_total_fed,(setter)0,
	PyDoc_STR("*float*: Federal CBI income [$]"),
 	NULL},
{"cbi_total_oth", (getter)Outputs_get_cbi_total_oth,(setter)0,
	PyDoc_STR("*float*: Other CBI income [$]"),
 	NULL},
{"cbi_total_sta", (getter)Outputs_get_cbi_total_sta,(setter)0,
	PyDoc_STR("*float*: State CBI income [$]"),
 	NULL},
{"cbi_total_uti", (getter)Outputs_get_cbi_total_uti,(setter)0,
	PyDoc_STR("*float*: Utility CBI income [$]"),
 	NULL},
{"cf_after_tax_cash_flow", (getter)Outputs_get_cf_after_tax_cash_flow,(setter)0,
	PyDoc_STR("*sequence*: Host after-tax cash flow [$]"),
 	NULL},
{"cf_after_tax_net_equity_cost_flow", (getter)Outputs_get_cf_after_tax_net_equity_cost_flow,(setter)0,
	PyDoc_STR("*sequence*: Host after-tax annual costs [$]"),
 	NULL},
{"cf_agreement_cost", (getter)Outputs_get_cf_agreement_cost,(setter)0,
	PyDoc_STR("*sequence*: Host agreement cost [$]"),
 	NULL},
{"cf_annual_cost_lcos", (getter)Outputs_get_cf_annual_cost_lcos,(setter)0,
	PyDoc_STR("*sequence*: Annual storage costs [$]"),
 	NULL},
{"cf_annual_costs", (getter)Outputs_get_cf_annual_costs,(setter)0,
	PyDoc_STR("*sequence*: Annual costs [$]"),
 	NULL},
{"cf_annual_discharge_lcos", (getter)Outputs_get_cf_annual_discharge_lcos,(setter)0,
	PyDoc_STR("*sequence*: Annual storage discharge [kWh]"),
 	NULL},
{"cf_battery_replacement_cost", (getter)Outputs_get_cf_battery_replacement_cost,(setter)0,
	PyDoc_STR("*sequence*: Battery replacement cost [$]"),
 	NULL},
{"cf_battery_replacement_cost_schedule", (getter)Outputs_get_cf_battery_replacement_cost_schedule,(setter)0,
	PyDoc_STR("*sequence*: Battery replacement cost schedule [$]"),
 	NULL},
{"cf_cash_for_ds", (getter)Outputs_get_cf_cash_for_ds,(setter)0,
	PyDoc_STR("*sequence*: Cash available for debt service (CAFDS) [$]"),
 	NULL},
{"cf_charging_cost_grid", (getter)Outputs_get_cf_charging_cost_grid,(setter)0,
	PyDoc_STR("*sequence*: Annual cost to charge from grid [$]"),
 	NULL},
{"cf_charging_cost_grid_month", (getter)Outputs_get_cf_charging_cost_grid_month,(setter)0,
	PyDoc_STR("*sequence*: Annual cost to charge from grid (monthly) [$]"),
 	NULL},
{"cf_charging_cost_pv", (getter)Outputs_get_cf_charging_cost_pv,(setter)0,
	PyDoc_STR("*sequence*: Annual cost to charge from system [$]"),
 	NULL},
{"cf_cumulative_payback_with_expenses", (getter)Outputs_get_cf_cumulative_payback_with_expenses,(setter)0,
	PyDoc_STR("*sequence*: Host cumulative simple payback with expenses [$]"),
 	NULL},
{"cf_debt_balance", (getter)Outputs_get_cf_debt_balance,(setter)0,
	PyDoc_STR("*sequence*: Debt balance [$]"),
 	NULL},
{"cf_debt_payment_interest", (getter)Outputs_get_cf_debt_payment_interest,(setter)0,
	PyDoc_STR("*sequence*: Debt interest payment [$]"),
 	NULL},
{"cf_debt_payment_principal", (getter)Outputs_get_cf_debt_payment_principal,(setter)0,
	PyDoc_STR("*sequence*: Debt principal payment [$]"),
 	NULL},
{"cf_debt_payment_total", (getter)Outputs_get_cf_debt_payment_total,(setter)0,
	PyDoc_STR("*sequence*: Debt total payment [$]"),
 	NULL},
{"cf_debt_size", (getter)Outputs_get_cf_debt_size,(setter)0,
	PyDoc_STR("*sequence*: Size of debt [$]"),
 	NULL},
{"cf_disbursement_debtservice", (getter)Outputs_get_cf_disbursement_debtservice,(setter)0,
	PyDoc_STR("*sequence*: Reserves debt service disbursement  [$]"),
 	NULL},
{"cf_disbursement_equip1", (getter)Outputs_get_cf_disbursement_equip1,(setter)0,
	PyDoc_STR("*sequence*: Reserves major equipment 1 disbursement [$]"),
 	NULL},
{"cf_disbursement_equip2", (getter)Outputs_get_cf_disbursement_equip2,(setter)0,
	PyDoc_STR("*sequence*: Reserves major equipment 2 disbursement [$]"),
 	NULL},
{"cf_disbursement_equip3", (getter)Outputs_get_cf_disbursement_equip3,(setter)0,
	PyDoc_STR("*sequence*: Reserves major equipment 3 disbursement [$]"),
 	NULL},
{"cf_disbursement_om", (getter)Outputs_get_cf_disbursement_om,(setter)0,
	PyDoc_STR("*sequence*: Reserves working capital disbursement [$]"),
 	NULL},
{"cf_disbursement_receivables", (getter)Outputs_get_cf_disbursement_receivables,(setter)0,
	PyDoc_STR("*sequence*: Reserves receivables disbursement [$]"),
 	NULL},
{"cf_ebitda", (getter)Outputs_get_cf_ebitda,(setter)0,
	PyDoc_STR("*sequence*: EBITDA [$]"),
 	NULL},
{"cf_effective_tax_frac", (getter)Outputs_get_cf_effective_tax_frac,(setter)0,
	PyDoc_STR("*sequence*: Effective income tax rate [frac]"),
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
{"cf_energy_sales_apr", (getter)Outputs_get_cf_energy_sales_apr,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in April [kWh]"),
 	NULL},
{"cf_energy_sales_aug", (getter)Outputs_get_cf_energy_sales_aug,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in August [kWh]"),
 	NULL},
{"cf_energy_sales_dec", (getter)Outputs_get_cf_energy_sales_dec,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in December [kWh]"),
 	NULL},
{"cf_energy_sales_dispatch1", (getter)Outputs_get_cf_energy_sales_dispatch1,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in TOD period 1 [kWh]"),
 	NULL},
{"cf_energy_sales_dispatch2", (getter)Outputs_get_cf_energy_sales_dispatch2,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in TOD period 2 [kWh]"),
 	NULL},
{"cf_energy_sales_dispatch3", (getter)Outputs_get_cf_energy_sales_dispatch3,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in TOD period 3 [kWh]"),
 	NULL},
{"cf_energy_sales_dispatch4", (getter)Outputs_get_cf_energy_sales_dispatch4,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in TOD period 4 [kWh]"),
 	NULL},
{"cf_energy_sales_dispatch5", (getter)Outputs_get_cf_energy_sales_dispatch5,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in TOD period 5 [kWh]"),
 	NULL},
{"cf_energy_sales_dispatch6", (getter)Outputs_get_cf_energy_sales_dispatch6,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in TOD period 6 [kWh]"),
 	NULL},
{"cf_energy_sales_dispatch7", (getter)Outputs_get_cf_energy_sales_dispatch7,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in TOD period 7 [kWh]"),
 	NULL},
{"cf_energy_sales_dispatch8", (getter)Outputs_get_cf_energy_sales_dispatch8,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in TOD period 8 [kWh]"),
 	NULL},
{"cf_energy_sales_dispatch9", (getter)Outputs_get_cf_energy_sales_dispatch9,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in TOD period 9 [kWh]"),
 	NULL},
{"cf_energy_sales_feb", (getter)Outputs_get_cf_energy_sales_feb,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in February [kWh]"),
 	NULL},
{"cf_energy_sales_jan", (getter)Outputs_get_cf_energy_sales_jan,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in January [kWh]"),
 	NULL},
{"cf_energy_sales_jul", (getter)Outputs_get_cf_energy_sales_jul,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in July [kWh]"),
 	NULL},
{"cf_energy_sales_jun", (getter)Outputs_get_cf_energy_sales_jun,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in June [kWh]"),
 	NULL},
{"cf_energy_sales_mar", (getter)Outputs_get_cf_energy_sales_mar,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in March [kWh]"),
 	NULL},
{"cf_energy_sales_may", (getter)Outputs_get_cf_energy_sales_may,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in May [kWh]"),
 	NULL},
{"cf_energy_sales_monthly_firstyear_TOD1", (getter)Outputs_get_cf_energy_sales_monthly_firstyear_TOD1,(setter)0,
	PyDoc_STR("*sequence*: First year energy from the system by month for TOD period 1 [kWh]"),
 	NULL},
{"cf_energy_sales_monthly_firstyear_TOD2", (getter)Outputs_get_cf_energy_sales_monthly_firstyear_TOD2,(setter)0,
	PyDoc_STR("*sequence*: First year energy from the system by month for TOD period 2 [kWh]"),
 	NULL},
{"cf_energy_sales_monthly_firstyear_TOD3", (getter)Outputs_get_cf_energy_sales_monthly_firstyear_TOD3,(setter)0,
	PyDoc_STR("*sequence*: First year energy from the system by month for TOD period 3 [kWh]"),
 	NULL},
{"cf_energy_sales_monthly_firstyear_TOD4", (getter)Outputs_get_cf_energy_sales_monthly_firstyear_TOD4,(setter)0,
	PyDoc_STR("*sequence*: First year energy from the system by month for TOD period 4 [kWh]"),
 	NULL},
{"cf_energy_sales_monthly_firstyear_TOD5", (getter)Outputs_get_cf_energy_sales_monthly_firstyear_TOD5,(setter)0,
	PyDoc_STR("*sequence*: First year energy from the system by month for TOD period 5 [kWh]"),
 	NULL},
{"cf_energy_sales_monthly_firstyear_TOD6", (getter)Outputs_get_cf_energy_sales_monthly_firstyear_TOD6,(setter)0,
	PyDoc_STR("*sequence*: First year energy from the system by month for TOD period 6 [kWh]"),
 	NULL},
{"cf_energy_sales_monthly_firstyear_TOD7", (getter)Outputs_get_cf_energy_sales_monthly_firstyear_TOD7,(setter)0,
	PyDoc_STR("*sequence*: First year energy from the system by month for TOD period 7 [kWh]"),
 	NULL},
{"cf_energy_sales_monthly_firstyear_TOD8", (getter)Outputs_get_cf_energy_sales_monthly_firstyear_TOD8,(setter)0,
	PyDoc_STR("*sequence*: First year energy from the system by month for TOD period 8 [kWh]"),
 	NULL},
{"cf_energy_sales_monthly_firstyear_TOD9", (getter)Outputs_get_cf_energy_sales_monthly_firstyear_TOD9,(setter)0,
	PyDoc_STR("*sequence*: First year energy from the system by month for TOD period 9 [kWh]"),
 	NULL},
{"cf_energy_sales_nov", (getter)Outputs_get_cf_energy_sales_nov,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in November [kWh]"),
 	NULL},
{"cf_energy_sales_oct", (getter)Outputs_get_cf_energy_sales_oct,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in October [kWh]"),
 	NULL},
{"cf_energy_sales_sep", (getter)Outputs_get_cf_energy_sales_sep,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in September [kWh]"),
 	NULL},
{"cf_energy_value", (getter)Outputs_get_cf_energy_value,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue [$]"),
 	NULL},
{"cf_energy_without_battery", (getter)Outputs_get_cf_energy_without_battery,(setter)0,
	PyDoc_STR("*sequence*: Electricity generated without storage [kWh]"),
 	NULL},
{"cf_feddepr_custom", (getter)Outputs_get_cf_feddepr_custom,(setter)0,
	PyDoc_STR("*sequence*: Federal depreciation from custom [$]"),
 	NULL},
{"cf_feddepr_macrs_15", (getter)Outputs_get_cf_feddepr_macrs_15,(setter)0,
	PyDoc_STR("*sequence*: Federal depreciation from 15-yr MACRS [$]"),
 	NULL},
{"cf_feddepr_macrs_5", (getter)Outputs_get_cf_feddepr_macrs_5,(setter)0,
	PyDoc_STR("*sequence*: Federal depreciation from 5-yr MACRS [$]"),
 	NULL},
{"cf_feddepr_me1", (getter)Outputs_get_cf_feddepr_me1,(setter)0,
	PyDoc_STR("*sequence*: Federal depreciation from major equipment 1 [$]"),
 	NULL},
{"cf_feddepr_me2", (getter)Outputs_get_cf_feddepr_me2,(setter)0,
	PyDoc_STR("*sequence*: Federal depreciation from major equipment 2 [$]"),
 	NULL},
{"cf_feddepr_me3", (getter)Outputs_get_cf_feddepr_me3,(setter)0,
	PyDoc_STR("*sequence*: Federal depreciation from major equipment 3 [$]"),
 	NULL},
{"cf_feddepr_sl_15", (getter)Outputs_get_cf_feddepr_sl_15,(setter)0,
	PyDoc_STR("*sequence*: Federal depreciation from 15-yr straight line [$]"),
 	NULL},
{"cf_feddepr_sl_20", (getter)Outputs_get_cf_feddepr_sl_20,(setter)0,
	PyDoc_STR("*sequence*: Federal depreciation from 20-yr straight line [$]"),
 	NULL},
{"cf_feddepr_sl_39", (getter)Outputs_get_cf_feddepr_sl_39,(setter)0,
	PyDoc_STR("*sequence*: Federal depreciation from 39-yr straight line [$]"),
 	NULL},
{"cf_feddepr_sl_5", (getter)Outputs_get_cf_feddepr_sl_5,(setter)0,
	PyDoc_STR("*sequence*: Federal depreciation from 5-yr straight line [$]"),
 	NULL},
{"cf_feddepr_total", (getter)Outputs_get_cf_feddepr_total,(setter)0,
	PyDoc_STR("*sequence*: Total federal tax depreciation [$]"),
 	NULL},
{"cf_federal_tax_frac", (getter)Outputs_get_cf_federal_tax_frac,(setter)0,
	PyDoc_STR("*sequence*: Federal income tax rate [frac]"),
 	NULL},
{"cf_fedtax", (getter)Outputs_get_cf_fedtax,(setter)0,
	PyDoc_STR("*sequence*: Federal tax benefit (liability) [$]"),
 	NULL},
{"cf_fedtax_income_prior_incentives", (getter)Outputs_get_cf_fedtax_income_prior_incentives,(setter)0,
	PyDoc_STR("*sequence*: Federal taxable income without incentives [$]"),
 	NULL},
{"cf_fedtax_income_with_incentives", (getter)Outputs_get_cf_fedtax_income_with_incentives,(setter)0,
	PyDoc_STR("*sequence*: Federal taxable income [$]"),
 	NULL},
{"cf_fedtax_taxable_incentives", (getter)Outputs_get_cf_fedtax_taxable_incentives,(setter)0,
	PyDoc_STR("*sequence*: Federal taxable incentives [$]"),
 	NULL},
{"cf_funding_debtservice", (getter)Outputs_get_cf_funding_debtservice,(setter)0,
	PyDoc_STR("*sequence*: Reserves debt service funding [$]"),
 	NULL},
{"cf_funding_equip1", (getter)Outputs_get_cf_funding_equip1,(setter)0,
	PyDoc_STR("*sequence*: Reserves major equipment 1 funding [$]"),
 	NULL},
{"cf_funding_equip2", (getter)Outputs_get_cf_funding_equip2,(setter)0,
	PyDoc_STR("*sequence*: Reserves major equipment 2 funding [$]"),
 	NULL},
{"cf_funding_equip3", (getter)Outputs_get_cf_funding_equip3,(setter)0,
	PyDoc_STR("*sequence*: Reserves major equipment 3 funding [$]"),
 	NULL},
{"cf_funding_om", (getter)Outputs_get_cf_funding_om,(setter)0,
	PyDoc_STR("*sequence*: Reserves working capital funding [$]"),
 	NULL},
{"cf_funding_receivables", (getter)Outputs_get_cf_funding_receivables,(setter)0,
	PyDoc_STR("*sequence*: Reserves receivables funding [$]"),
 	NULL},
{"cf_insurance_expense", (getter)Outputs_get_cf_insurance_expense,(setter)0,
	PyDoc_STR("*sequence*: Insurance expense [$]"),
 	NULL},
{"cf_itc_fed", (getter)Outputs_get_cf_itc_fed,(setter)0,
	PyDoc_STR("*sequence*: Federal ITC total income [$]"),
 	NULL},
{"cf_itc_fed_amount", (getter)Outputs_get_cf_itc_fed_amount,(setter)0,
	PyDoc_STR("*sequence*: Federal ITC amount income [$]"),
 	NULL},
{"cf_itc_fed_percent_amount", (getter)Outputs_get_cf_itc_fed_percent_amount,(setter)0,
	PyDoc_STR("*sequence*: Federal ITC percent income [$]"),
 	NULL},
{"cf_itc_sta", (getter)Outputs_get_cf_itc_sta,(setter)0,
	PyDoc_STR("*sequence*: State ITC total income [$]"),
 	NULL},
{"cf_itc_sta_amount", (getter)Outputs_get_cf_itc_sta_amount,(setter)0,
	PyDoc_STR("*sequence*: State ITC amount income [$]"),
 	NULL},
{"cf_itc_sta_percent_amount", (getter)Outputs_get_cf_itc_sta_percent_amount,(setter)0,
	PyDoc_STR("*sequence*: State ITC percent income [$]"),
 	NULL},
{"cf_itc_total", (getter)Outputs_get_cf_itc_total,(setter)0,
	PyDoc_STR("*sequence*: Total ITC income [$]"),
 	NULL},
{"cf_land_lease_expense", (getter)Outputs_get_cf_land_lease_expense,(setter)0,
	PyDoc_STR("*sequence*: Land lease expense [$]"),
 	NULL},
{"cf_length", (getter)Outputs_get_cf_length,(setter)0,
	PyDoc_STR("*float*: Number of periods in cashflow"),
 	NULL},
{"cf_net_salvage_value", (getter)Outputs_get_cf_net_salvage_value,(setter)0,
	PyDoc_STR("*sequence*: Salvage value [$]"),
 	NULL},
{"cf_nte", (getter)Outputs_get_cf_nte,(setter)0,
	PyDoc_STR("*sequence*: Host indifference point by year [cents/kWh]"),
 	NULL},
{"cf_om_batt_capacity_expense", (getter)Outputs_get_cf_om_batt_capacity_expense,(setter)0,
	PyDoc_STR("*sequence*: Annual cost for battery capacity based maintenance [$]"),
 	NULL},
{"cf_om_batt_fixed_expense", (getter)Outputs_get_cf_om_batt_fixed_expense,(setter)0,
	PyDoc_STR("*sequence*: Annual fixed cost for battery maintenance [$]"),
 	NULL},
{"cf_om_capacity1_expense", (getter)Outputs_get_cf_om_capacity1_expense,(setter)0,
	PyDoc_STR("*sequence*: O&M battery capacity-based expense [$]"),
 	NULL},
{"cf_om_capacity2_expense", (getter)Outputs_get_cf_om_capacity2_expense,(setter)0,
	PyDoc_STR("*sequence*: O&M fuel cell capacity-based expense [$]"),
 	NULL},
{"cf_om_capacity_expense", (getter)Outputs_get_cf_om_capacity_expense,(setter)0,
	PyDoc_STR("*sequence*: O&M capacity-based expense [$]"),
 	NULL},
{"cf_om_fixed1_expense", (getter)Outputs_get_cf_om_fixed1_expense,(setter)0,
	PyDoc_STR("*sequence*: O&M battery fixed expense [$]"),
 	NULL},
{"cf_om_fixed2_expense", (getter)Outputs_get_cf_om_fixed2_expense,(setter)0,
	PyDoc_STR("*sequence*: O&M fuel cell fixed expense [$]"),
 	NULL},
{"cf_om_fixed_expense", (getter)Outputs_get_cf_om_fixed_expense,(setter)0,
	PyDoc_STR("*sequence*: O&M fixed expense [$]"),
 	NULL},
{"cf_om_fuel_expense", (getter)Outputs_get_cf_om_fuel_expense,(setter)0,
	PyDoc_STR("*sequence*: Fuel expense [$]"),
 	NULL},
{"cf_om_opt_fuel_1_expense", (getter)Outputs_get_cf_om_opt_fuel_1_expense,(setter)0,
	PyDoc_STR("*sequence*: Feedstock biomass expense [$]"),
 	NULL},
{"cf_om_opt_fuel_2_expense", (getter)Outputs_get_cf_om_opt_fuel_2_expense,(setter)0,
	PyDoc_STR("*sequence*: Feedstock coal expense [$]"),
 	NULL},
{"cf_om_production1_expense", (getter)Outputs_get_cf_om_production1_expense,(setter)0,
	PyDoc_STR("*sequence*: O&M battery production-based expense [$]"),
 	NULL},
{"cf_om_production2_expense", (getter)Outputs_get_cf_om_production2_expense,(setter)0,
	PyDoc_STR("*sequence*: O&M fuel cell production-based expense [$]"),
 	NULL},
{"cf_om_production_expense", (getter)Outputs_get_cf_om_production_expense,(setter)0,
	PyDoc_STR("*sequence*: O&M production-based expense [$]"),
 	NULL},
{"cf_operating_expenses", (getter)Outputs_get_cf_operating_expenses,(setter)0,
	PyDoc_STR("*sequence*: Total operating expenses [$]"),
 	NULL},
{"cf_parasitic_cost", (getter)Outputs_get_cf_parasitic_cost,(setter)0,
	PyDoc_STR("*sequence*: Parasitic load costs [$]"),
 	NULL},
{"cf_payback_with_expenses", (getter)Outputs_get_cf_payback_with_expenses,(setter)0,
	PyDoc_STR("*sequence*: Host simple payback with expenses [$]"),
 	NULL},
{"cf_pbi_fedtax_total", (getter)Outputs_get_cf_pbi_fedtax_total,(setter)0,
	PyDoc_STR("*sequence*: Federal taxable PBI income [$]"),
 	NULL},
{"cf_pbi_statax_total", (getter)Outputs_get_cf_pbi_statax_total,(setter)0,
	PyDoc_STR("*sequence*: State taxable PBI income [$]"),
 	NULL},
{"cf_pbi_total", (getter)Outputs_get_cf_pbi_total,(setter)0,
	PyDoc_STR("*sequence*: Total PBI income [$]"),
 	NULL},
{"cf_pbi_total_fed", (getter)Outputs_get_cf_pbi_total_fed,(setter)0,
	PyDoc_STR("*sequence*: Federal PBI income [$]"),
 	NULL},
{"cf_pbi_total_oth", (getter)Outputs_get_cf_pbi_total_oth,(setter)0,
	PyDoc_STR("*sequence*: Other PBI income [$]"),
 	NULL},
{"cf_pbi_total_sta", (getter)Outputs_get_cf_pbi_total_sta,(setter)0,
	PyDoc_STR("*sequence*: State PBI income [$]"),
 	NULL},
{"cf_pbi_total_uti", (getter)Outputs_get_cf_pbi_total_uti,(setter)0,
	PyDoc_STR("*sequence*: Utility PBI income [$]"),
 	NULL},
{"cf_ppa_price", (getter)Outputs_get_cf_ppa_price,(setter)0,
	PyDoc_STR("*sequence*: PPA price [cents/kWh]"),
 	NULL},
{"cf_pretax_cashflow", (getter)Outputs_get_cf_pretax_cashflow,(setter)0,
	PyDoc_STR("*sequence*: Total pre-tax cash flow [$]"),
 	NULL},
{"cf_pretax_dscr", (getter)Outputs_get_cf_pretax_dscr,(setter)0,
	PyDoc_STR("*sequence*: DSCR (pre-tax)"),
 	NULL},
{"cf_project_dsra", (getter)Outputs_get_cf_project_dsra,(setter)0,
	PyDoc_STR("*sequence*: Reserve (increase)/decrease debt service  [$]"),
 	NULL},
{"cf_project_financing_activities", (getter)Outputs_get_cf_project_financing_activities,(setter)0,
	PyDoc_STR("*sequence*: Cash flow from financing activities [$]"),
 	NULL},
{"cf_project_investing_activities", (getter)Outputs_get_cf_project_investing_activities,(setter)0,
	PyDoc_STR("*sequence*: Cash flow from investing activities [$]"),
 	NULL},
{"cf_project_me1cs", (getter)Outputs_get_cf_project_me1cs,(setter)0,
	PyDoc_STR("*sequence*: Reserve capital spending major equipment 1 [$]"),
 	NULL},
{"cf_project_me1ra", (getter)Outputs_get_cf_project_me1ra,(setter)0,
	PyDoc_STR("*sequence*: Reserve (increase)/decrease major equipment 1 [$]"),
 	NULL},
{"cf_project_me2cs", (getter)Outputs_get_cf_project_me2cs,(setter)0,
	PyDoc_STR("*sequence*: Reserve capital spending major equipment 2 [$]"),
 	NULL},
{"cf_project_me2ra", (getter)Outputs_get_cf_project_me2ra,(setter)0,
	PyDoc_STR("*sequence*: Reserve (increase)/decrease major equipment 2 [$]"),
 	NULL},
{"cf_project_me3cs", (getter)Outputs_get_cf_project_me3cs,(setter)0,
	PyDoc_STR("*sequence*: Reserve capital spending major equipment 3 [$]"),
 	NULL},
{"cf_project_me3ra", (getter)Outputs_get_cf_project_me3ra,(setter)0,
	PyDoc_STR("*sequence*: Reserve (increase)/decrease major equipment 3 [$]"),
 	NULL},
{"cf_project_mecs", (getter)Outputs_get_cf_project_mecs,(setter)0,
	PyDoc_STR("*sequence*: Reserve capital spending major equipment total [$]"),
 	NULL},
{"cf_project_operating_activities", (getter)Outputs_get_cf_project_operating_activities,(setter)0,
	PyDoc_STR("*sequence*: Cash flow from operating activities [$]"),
 	NULL},
{"cf_project_ra", (getter)Outputs_get_cf_project_ra,(setter)0,
	PyDoc_STR("*sequence*: Reserve (increase)/decrease total reserve account [$]"),
 	NULL},
{"cf_project_receivablesra", (getter)Outputs_get_cf_project_receivablesra,(setter)0,
	PyDoc_STR("*sequence*: Reserve (increase)/decrease receivables [$]"),
 	NULL},
{"cf_project_return_aftertax", (getter)Outputs_get_cf_project_return_aftertax,(setter)0,
	PyDoc_STR("*sequence*: Total after-tax project returns [$]"),
 	NULL},
{"cf_project_return_aftertax_cash", (getter)Outputs_get_cf_project_return_aftertax_cash,(setter)0,
	PyDoc_STR("*sequence*: Total after-tax project cash returns [$]"),
 	NULL},
{"cf_project_return_aftertax_irr", (getter)Outputs_get_cf_project_return_aftertax_irr,(setter)0,
	PyDoc_STR("*sequence*: After-tax project cumulative IRR [%]"),
 	NULL},
{"cf_project_return_aftertax_max_irr", (getter)Outputs_get_cf_project_return_aftertax_max_irr,(setter)0,
	PyDoc_STR("*sequence*: After-tax project maximum IRR [%]"),
 	NULL},
{"cf_project_return_aftertax_npv", (getter)Outputs_get_cf_project_return_aftertax_npv,(setter)0,
	PyDoc_STR("*sequence*: After-tax project cumulative NPV [$]"),
 	NULL},
{"cf_project_return_pretax", (getter)Outputs_get_cf_project_return_pretax,(setter)0,
	PyDoc_STR("*sequence*: Total pre-tax project returns [$]"),
 	NULL},
{"cf_project_return_pretax_irr", (getter)Outputs_get_cf_project_return_pretax_irr,(setter)0,
	PyDoc_STR("*sequence*: Pre-tax project cumulative IRR [%]"),
 	NULL},
{"cf_project_return_pretax_npv", (getter)Outputs_get_cf_project_return_pretax_npv,(setter)0,
	PyDoc_STR("*sequence*: Pre-tax project cumulative NPV [$]"),
 	NULL},
{"cf_project_wcra", (getter)Outputs_get_cf_project_wcra,(setter)0,
	PyDoc_STR("*sequence*: Reserve (increase)/decrease working capital [$]"),
 	NULL},
{"cf_property_tax_assessed_value", (getter)Outputs_get_cf_property_tax_assessed_value,(setter)0,
	PyDoc_STR("*sequence*: Property tax net assessed value [$]"),
 	NULL},
{"cf_property_tax_expense", (getter)Outputs_get_cf_property_tax_expense,(setter)0,
	PyDoc_STR("*sequence*: Property tax expense [$]"),
 	NULL},
{"cf_ptc_fed", (getter)Outputs_get_cf_ptc_fed,(setter)0,
	PyDoc_STR("*sequence*: Federal PTC income [$]"),
 	NULL},
{"cf_ptc_sta", (getter)Outputs_get_cf_ptc_sta,(setter)0,
	PyDoc_STR("*sequence*: State PTC income [$]"),
 	NULL},
{"cf_pv_cash_for_ds", (getter)Outputs_get_cf_pv_cash_for_ds,(setter)0,
	PyDoc_STR("*sequence*: Present value of CAFDS [$]"),
 	NULL},
{"cf_pv_interest_factor", (getter)Outputs_get_cf_pv_interest_factor,(setter)0,
	PyDoc_STR("*sequence*: Present value interest factor for CAFDS"),
 	NULL},
{"cf_recapitalization", (getter)Outputs_get_cf_recapitalization,(setter)0,
	PyDoc_STR("*sequence*: Recapitalization operating expense [$]"),
 	NULL},
{"cf_reserve_debtservice", (getter)Outputs_get_cf_reserve_debtservice,(setter)0,
	PyDoc_STR("*sequence*: Reserves debt service balance [$]"),
 	NULL},
{"cf_reserve_equip1", (getter)Outputs_get_cf_reserve_equip1,(setter)0,
	PyDoc_STR("*sequence*: Reserves major equipment 1 balance [$]"),
 	NULL},
{"cf_reserve_equip2", (getter)Outputs_get_cf_reserve_equip2,(setter)0,
	PyDoc_STR("*sequence*: Reserves major equipment 2 balance [$]"),
 	NULL},
{"cf_reserve_equip3", (getter)Outputs_get_cf_reserve_equip3,(setter)0,
	PyDoc_STR("*sequence*: Reserves major equipment 3 balance [$]"),
 	NULL},
{"cf_reserve_interest", (getter)Outputs_get_cf_reserve_interest,(setter)0,
	PyDoc_STR("*sequence*: Interest earned on reserves [$]"),
 	NULL},
{"cf_reserve_om", (getter)Outputs_get_cf_reserve_om,(setter)0,
	PyDoc_STR("*sequence*: Reserves working capital balance  [$]"),
 	NULL},
{"cf_reserve_receivables", (getter)Outputs_get_cf_reserve_receivables,(setter)0,
	PyDoc_STR("*sequence*: Reserves receivables balance [$]"),
 	NULL},
{"cf_reserve_total", (getter)Outputs_get_cf_reserve_total,(setter)0,
	PyDoc_STR("*sequence*: Reserves total reserves balance [$]"),
 	NULL},
{"cf_revenue_apr", (getter)Outputs_get_cf_revenue_apr,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in April [$]"),
 	NULL},
{"cf_revenue_aug", (getter)Outputs_get_cf_revenue_aug,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in August [$]"),
 	NULL},
{"cf_revenue_dec", (getter)Outputs_get_cf_revenue_dec,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in December [$]"),
 	NULL},
{"cf_revenue_dispatch1", (getter)Outputs_get_cf_revenue_dispatch1,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in TOD period 1 [$]"),
 	NULL},
{"cf_revenue_dispatch2", (getter)Outputs_get_cf_revenue_dispatch2,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in TOD period 2 [$]"),
 	NULL},
{"cf_revenue_dispatch3", (getter)Outputs_get_cf_revenue_dispatch3,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in TOD period 3 [$]"),
 	NULL},
{"cf_revenue_dispatch4", (getter)Outputs_get_cf_revenue_dispatch4,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in TOD period 4 [$]"),
 	NULL},
{"cf_revenue_dispatch5", (getter)Outputs_get_cf_revenue_dispatch5,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in TOD period 5 [$]"),
 	NULL},
{"cf_revenue_dispatch6", (getter)Outputs_get_cf_revenue_dispatch6,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in TOD period 6 [$]"),
 	NULL},
{"cf_revenue_dispatch7", (getter)Outputs_get_cf_revenue_dispatch7,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in TOD period 7 [$]"),
 	NULL},
{"cf_revenue_dispatch8", (getter)Outputs_get_cf_revenue_dispatch8,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in TOD period 8 [$]"),
 	NULL},
{"cf_revenue_dispatch9", (getter)Outputs_get_cf_revenue_dispatch9,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in TOD period 9 [$]"),
 	NULL},
{"cf_revenue_feb", (getter)Outputs_get_cf_revenue_feb,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in February [$]"),
 	NULL},
{"cf_revenue_jan", (getter)Outputs_get_cf_revenue_jan,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in January [$]"),
 	NULL},
{"cf_revenue_jul", (getter)Outputs_get_cf_revenue_jul,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in July [$]"),
 	NULL},
{"cf_revenue_jun", (getter)Outputs_get_cf_revenue_jun,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in June [$]"),
 	NULL},
{"cf_revenue_mar", (getter)Outputs_get_cf_revenue_mar,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in March [$]"),
 	NULL},
{"cf_revenue_may", (getter)Outputs_get_cf_revenue_may,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in May [$]"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD1", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD1,(setter)0,
	PyDoc_STR("*sequence*: First year revenue from the system by month for TOD period 1 [$]"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD2", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD2,(setter)0,
	PyDoc_STR("*sequence*: First year revenue from the system by month for TOD period 2 [$]"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD3", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD3,(setter)0,
	PyDoc_STR("*sequence*: First year revenue from the system by month for TOD period 3 [$]"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD4", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD4,(setter)0,
	PyDoc_STR("*sequence*: First year revenue from the system by month for TOD period 4 [$]"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD5", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD5,(setter)0,
	PyDoc_STR("*sequence*: First year revenue from the system by month for TOD period 5 [$]"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD6", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD6,(setter)0,
	PyDoc_STR("*sequence*: First year revenue from the system by month for TOD period 6 [$]"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD7", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD7,(setter)0,
	PyDoc_STR("*sequence*: First year revenue from the system by month for TOD period 7 [$]"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD8", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD8,(setter)0,
	PyDoc_STR("*sequence*: First year revenue from the system by month for TOD period 8 [$]"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD9", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD9,(setter)0,
	PyDoc_STR("*sequence*: First year revenue from the system by month for TOD period 9 [$]"),
 	NULL},
{"cf_revenue_nov", (getter)Outputs_get_cf_revenue_nov,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in November [$]"),
 	NULL},
{"cf_revenue_oct", (getter)Outputs_get_cf_revenue_oct,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in October [$]"),
 	NULL},
{"cf_revenue_sep", (getter)Outputs_get_cf_revenue_sep,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in September [$]"),
 	NULL},
{"cf_salvage_cost_lcos", (getter)Outputs_get_cf_salvage_cost_lcos,(setter)0,
	PyDoc_STR("*sequence*: Annual battery salvage value costs [$]"),
 	NULL},
{"cf_stadepr_custom", (getter)Outputs_get_cf_stadepr_custom,(setter)0,
	PyDoc_STR("*sequence*: State depreciation from custom [$]"),
 	NULL},
{"cf_stadepr_macrs_15", (getter)Outputs_get_cf_stadepr_macrs_15,(setter)0,
	PyDoc_STR("*sequence*: State depreciation from 15-yr MACRS [$]"),
 	NULL},
{"cf_stadepr_macrs_5", (getter)Outputs_get_cf_stadepr_macrs_5,(setter)0,
	PyDoc_STR("*sequence*: State depreciation from 5-yr MACRS [$]"),
 	NULL},
{"cf_stadepr_me1", (getter)Outputs_get_cf_stadepr_me1,(setter)0,
	PyDoc_STR("*sequence*: State depreciation from major equipment 1 [$]"),
 	NULL},
{"cf_stadepr_me2", (getter)Outputs_get_cf_stadepr_me2,(setter)0,
	PyDoc_STR("*sequence*: State depreciation from major equipment 2 [$]"),
 	NULL},
{"cf_stadepr_me3", (getter)Outputs_get_cf_stadepr_me3,(setter)0,
	PyDoc_STR("*sequence*: State depreciation from major equipment 3 [$]"),
 	NULL},
{"cf_stadepr_sl_15", (getter)Outputs_get_cf_stadepr_sl_15,(setter)0,
	PyDoc_STR("*sequence*: State depreciation from 15-yr straight line [$]"),
 	NULL},
{"cf_stadepr_sl_20", (getter)Outputs_get_cf_stadepr_sl_20,(setter)0,
	PyDoc_STR("*sequence*: State depreciation from 20-yr straight line [$]"),
 	NULL},
{"cf_stadepr_sl_39", (getter)Outputs_get_cf_stadepr_sl_39,(setter)0,
	PyDoc_STR("*sequence*: State depreciation from 39-yr straight line [$]"),
 	NULL},
{"cf_stadepr_sl_5", (getter)Outputs_get_cf_stadepr_sl_5,(setter)0,
	PyDoc_STR("*sequence*: State depreciation from 5-yr straight line [$]"),
 	NULL},
{"cf_stadepr_total", (getter)Outputs_get_cf_stadepr_total,(setter)0,
	PyDoc_STR("*sequence*: Total state tax depreciation [$]"),
 	NULL},
{"cf_statax", (getter)Outputs_get_cf_statax,(setter)0,
	PyDoc_STR("*sequence*: State tax benefit (liability) [$]"),
 	NULL},
{"cf_statax_income_prior_incentives", (getter)Outputs_get_cf_statax_income_prior_incentives,(setter)0,
	PyDoc_STR("*sequence*: State taxable income without incentives [$]"),
 	NULL},
{"cf_statax_income_with_incentives", (getter)Outputs_get_cf_statax_income_with_incentives,(setter)0,
	PyDoc_STR("*sequence*: State taxable income [$]"),
 	NULL},
{"cf_statax_taxable_incentives", (getter)Outputs_get_cf_statax_taxable_incentives,(setter)0,
	PyDoc_STR("*sequence*: State taxable incentives [$]"),
 	NULL},
{"cf_state_tax_frac", (getter)Outputs_get_cf_state_tax_frac,(setter)0,
	PyDoc_STR("*sequence*: State income tax rate [frac]"),
 	NULL},
{"cf_total_revenue", (getter)Outputs_get_cf_total_revenue,(setter)0,
	PyDoc_STR("*sequence*: Total revenue [$]"),
 	NULL},
{"cf_util_escal_rate", (getter)Outputs_get_cf_util_escal_rate,(setter)0,
	PyDoc_STR("*sequence*: Utility escalation rate"),
 	NULL},
{"cost_debt_upfront", (getter)Outputs_get_cost_debt_upfront,(setter)0,
	PyDoc_STR("*float*: Debt up-front fee [$]"),
 	NULL},
{"cost_financing", (getter)Outputs_get_cost_financing,(setter)0,
	PyDoc_STR("*float*: Total financing cost [$]"),
 	NULL},
{"cost_installed", (getter)Outputs_get_cost_installed,(setter)0,
	PyDoc_STR("*float*: Net capital cost [$]"),
 	NULL},
{"cost_installedperwatt", (getter)Outputs_get_cost_installedperwatt,(setter)0,
	PyDoc_STR("*float*: Net capital cost per watt [$/W]"),
 	NULL},
{"cost_prefinancing", (getter)Outputs_get_cost_prefinancing,(setter)0,
	PyDoc_STR("*float*: Total installed cost [$]"),
 	NULL},
{"debt_fraction", (getter)Outputs_get_debt_fraction,(setter)0,
	PyDoc_STR("*float*: Debt percent [%]"),
 	NULL},
{"depr_alloc_custom", (getter)Outputs_get_depr_alloc_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line depreciation federal and state allocation [$]"),
 	NULL},
{"depr_alloc_macrs_15", (getter)Outputs_get_depr_alloc_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS depreciation federal and state allocation [$]"),
 	NULL},
{"depr_alloc_macrs_5", (getter)Outputs_get_depr_alloc_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS depreciation federal and state allocation [$]"),
 	NULL},
{"depr_alloc_none", (getter)Outputs_get_depr_alloc_none,(setter)0,
	PyDoc_STR("*float*: Non-depreciable federal and state allocation [$]"),
 	NULL},
{"depr_alloc_none_percent", (getter)Outputs_get_depr_alloc_none_percent,(setter)0,
	PyDoc_STR("*float*: Non-depreciable federal and state allocation [%]"),
 	NULL},
{"depr_alloc_sl_15", (getter)Outputs_get_depr_alloc_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line depreciation federal and state allocation [$]"),
 	NULL},
{"depr_alloc_sl_20", (getter)Outputs_get_depr_alloc_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line depreciation federal and state allocation [$]"),
 	NULL},
{"depr_alloc_sl_39", (getter)Outputs_get_depr_alloc_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line depreciation federal and state allocation [$]"),
 	NULL},
{"depr_alloc_sl_5", (getter)Outputs_get_depr_alloc_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line depreciation federal and state allocation [$]"),
 	NULL},
{"depr_alloc_total", (getter)Outputs_get_depr_alloc_total,(setter)0,
	PyDoc_STR("*float*: Total depreciation federal and state allocation [$]"),
 	NULL},
{"depr_fedbas_after_itc_custom", (getter)Outputs_get_depr_fedbas_after_itc_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line federal depreciation basis after ITC reduction [$]"),
 	NULL},
{"depr_fedbas_after_itc_macrs_15", (getter)Outputs_get_depr_fedbas_after_itc_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS federal depreciation basis after ITC reduction [$]"),
 	NULL},
{"depr_fedbas_after_itc_macrs_5", (getter)Outputs_get_depr_fedbas_after_itc_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS federal depreciation basis after ITC reduction [$]"),
 	NULL},
{"depr_fedbas_after_itc_sl_15", (getter)Outputs_get_depr_fedbas_after_itc_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line federal depreciation basis after ITC reduction [$]"),
 	NULL},
{"depr_fedbas_after_itc_sl_20", (getter)Outputs_get_depr_fedbas_after_itc_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line federal depreciation basis after ITC reduction [$]"),
 	NULL},
{"depr_fedbas_after_itc_sl_39", (getter)Outputs_get_depr_fedbas_after_itc_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line federal depreciation basis after ITC reduction [$]"),
 	NULL},
{"depr_fedbas_after_itc_sl_5", (getter)Outputs_get_depr_fedbas_after_itc_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line federal depreciation basis after ITC reduction [$]"),
 	NULL},
{"depr_fedbas_after_itc_total", (getter)Outputs_get_depr_fedbas_after_itc_total,(setter)0,
	PyDoc_STR("*float*: Total federal depreciation basis after ITC reduction [$]"),
 	NULL},
{"depr_fedbas_cbi_reduc_custom", (getter)Outputs_get_depr_fedbas_cbi_reduc_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line federal CBI reduction [$]"),
 	NULL},
{"depr_fedbas_cbi_reduc_macrs_15", (getter)Outputs_get_depr_fedbas_cbi_reduc_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS federal CBI reduction [$]"),
 	NULL},
{"depr_fedbas_cbi_reduc_macrs_5", (getter)Outputs_get_depr_fedbas_cbi_reduc_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS federal CBI reduction [$]"),
 	NULL},
{"depr_fedbas_cbi_reduc_sl_15", (getter)Outputs_get_depr_fedbas_cbi_reduc_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line federal CBI reduction [$]"),
 	NULL},
{"depr_fedbas_cbi_reduc_sl_20", (getter)Outputs_get_depr_fedbas_cbi_reduc_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line federal CBI reduction [$]"),
 	NULL},
{"depr_fedbas_cbi_reduc_sl_39", (getter)Outputs_get_depr_fedbas_cbi_reduc_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line federal CBI reduction [$]"),
 	NULL},
{"depr_fedbas_cbi_reduc_sl_5", (getter)Outputs_get_depr_fedbas_cbi_reduc_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line federal CBI reduction [$]"),
 	NULL},
{"depr_fedbas_cbi_reduc_total", (getter)Outputs_get_depr_fedbas_cbi_reduc_total,(setter)0,
	PyDoc_STR("*float*: Total federal CBI reduction [$]"),
 	NULL},
{"depr_fedbas_custom", (getter)Outputs_get_depr_fedbas_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line federal depreciation basis [$]"),
 	NULL},
{"depr_fedbas_first_year_bonus_custom", (getter)Outputs_get_depr_fedbas_first_year_bonus_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line federal first year bonus depreciation [$]"),
 	NULL},
{"depr_fedbas_first_year_bonus_macrs_15", (getter)Outputs_get_depr_fedbas_first_year_bonus_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS federal first year bonus depreciation [$]"),
 	NULL},
{"depr_fedbas_first_year_bonus_macrs_5", (getter)Outputs_get_depr_fedbas_first_year_bonus_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS federal first year bonus depreciation [$]"),
 	NULL},
{"depr_fedbas_first_year_bonus_sl_15", (getter)Outputs_get_depr_fedbas_first_year_bonus_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line federal first year bonus depreciation [$]"),
 	NULL},
{"depr_fedbas_first_year_bonus_sl_20", (getter)Outputs_get_depr_fedbas_first_year_bonus_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line federal first year bonus depreciation [$]"),
 	NULL},
{"depr_fedbas_first_year_bonus_sl_39", (getter)Outputs_get_depr_fedbas_first_year_bonus_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line federal first year bonus depreciation [$]"),
 	NULL},
{"depr_fedbas_first_year_bonus_sl_5", (getter)Outputs_get_depr_fedbas_first_year_bonus_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line federal first year bonus depreciation [$]"),
 	NULL},
{"depr_fedbas_first_year_bonus_total", (getter)Outputs_get_depr_fedbas_first_year_bonus_total,(setter)0,
	PyDoc_STR("*float*: Total federal first year bonus depreciation [$]"),
 	NULL},
{"depr_fedbas_fixed_amount_custom", (getter)Outputs_get_depr_fedbas_fixed_amount_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line depreciation ITC basis from federal fixed amount [$]"),
 	NULL},
{"depr_fedbas_fixed_amount_macrs_15", (getter)Outputs_get_depr_fedbas_fixed_amount_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS depreciation ITC basis from federal fixed amount [$]"),
 	NULL},
{"depr_fedbas_fixed_amount_macrs_5", (getter)Outputs_get_depr_fedbas_fixed_amount_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS depreciation ITC basis from federal fixed amount [$]"),
 	NULL},
{"depr_fedbas_fixed_amount_sl_15", (getter)Outputs_get_depr_fedbas_fixed_amount_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line depreciation ITC basis from federal fixed amount [$]"),
 	NULL},
{"depr_fedbas_fixed_amount_sl_20", (getter)Outputs_get_depr_fedbas_fixed_amount_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line depreciation ITC basis from federal fixed amount [$]"),
 	NULL},
{"depr_fedbas_fixed_amount_sl_39", (getter)Outputs_get_depr_fedbas_fixed_amount_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line depreciation ITC basis from federal fixed amount [$]"),
 	NULL},
{"depr_fedbas_fixed_amount_sl_5", (getter)Outputs_get_depr_fedbas_fixed_amount_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line depreciation ITC basis from federal fixed amount [$]"),
 	NULL},
{"depr_fedbas_fixed_amount_total", (getter)Outputs_get_depr_fedbas_fixed_amount_total,(setter)0,
	PyDoc_STR("*float*: Total depreciation ITC basis from federal fixed amount [$]"),
 	NULL},
{"depr_fedbas_ibi_reduc_custom", (getter)Outputs_get_depr_fedbas_ibi_reduc_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line federal IBI reduction [$]"),
 	NULL},
{"depr_fedbas_ibi_reduc_macrs_15", (getter)Outputs_get_depr_fedbas_ibi_reduc_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS federal IBI reduction [$]"),
 	NULL},
{"depr_fedbas_ibi_reduc_macrs_5", (getter)Outputs_get_depr_fedbas_ibi_reduc_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS federal IBI reduction [$]"),
 	NULL},
{"depr_fedbas_ibi_reduc_sl_15", (getter)Outputs_get_depr_fedbas_ibi_reduc_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line federal IBI reduction [$]"),
 	NULL},
{"depr_fedbas_ibi_reduc_sl_20", (getter)Outputs_get_depr_fedbas_ibi_reduc_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line federal IBI reduction [$]"),
 	NULL},
{"depr_fedbas_ibi_reduc_sl_39", (getter)Outputs_get_depr_fedbas_ibi_reduc_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line federal IBI reduction [$]"),
 	NULL},
{"depr_fedbas_ibi_reduc_sl_5", (getter)Outputs_get_depr_fedbas_ibi_reduc_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line federal IBI reduction [$]"),
 	NULL},
{"depr_fedbas_ibi_reduc_total", (getter)Outputs_get_depr_fedbas_ibi_reduc_total,(setter)0,
	PyDoc_STR("*float*: Total federal IBI reduction [$]"),
 	NULL},
{"depr_fedbas_itc_fed_reduction_custom", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line federal basis federal ITC reduction [$]"),
 	NULL},
{"depr_fedbas_itc_fed_reduction_macrs_15", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS federal basis federal ITC reduction [$]"),
 	NULL},
{"depr_fedbas_itc_fed_reduction_macrs_5", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS federal basis federal ITC reduction [$]"),
 	NULL},
{"depr_fedbas_itc_fed_reduction_sl_15", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line federal basis federal ITC reduction [$]"),
 	NULL},
{"depr_fedbas_itc_fed_reduction_sl_20", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line federal basis federal ITC reduction [$]"),
 	NULL},
{"depr_fedbas_itc_fed_reduction_sl_39", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line federal basis federal ITC reduction [$]"),
 	NULL},
{"depr_fedbas_itc_fed_reduction_sl_5", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line federal basis federal ITC reduction [$]"),
 	NULL},
{"depr_fedbas_itc_fed_reduction_total", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_total,(setter)0,
	PyDoc_STR("*float*: Total federal basis federal ITC reduction [$]"),
 	NULL},
{"depr_fedbas_itc_sta_reduction_custom", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line federal basis state ITC reduction [$]"),
 	NULL},
{"depr_fedbas_itc_sta_reduction_macrs_15", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS federal basis state ITC reduction [$]"),
 	NULL},
{"depr_fedbas_itc_sta_reduction_macrs_5", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS federal basis state ITC reduction [$]"),
 	NULL},
{"depr_fedbas_itc_sta_reduction_sl_15", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line federal basis state ITC reduction [$]"),
 	NULL},
{"depr_fedbas_itc_sta_reduction_sl_20", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line federal basis state ITC reduction [$]"),
 	NULL},
{"depr_fedbas_itc_sta_reduction_sl_39", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line federal basis state ITC reduction [$]"),
 	NULL},
{"depr_fedbas_itc_sta_reduction_sl_5", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line federal basis state ITC reduction [$]"),
 	NULL},
{"depr_fedbas_itc_sta_reduction_total", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_total,(setter)0,
	PyDoc_STR("*float*: Total federal basis state ITC reduction [$]"),
 	NULL},
{"depr_fedbas_macrs_15", (getter)Outputs_get_depr_fedbas_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS federal depreciation basis [$]"),
 	NULL},
{"depr_fedbas_macrs_5", (getter)Outputs_get_depr_fedbas_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS federal depreciation basis [$]"),
 	NULL},
{"depr_fedbas_percent_amount_custom", (getter)Outputs_get_depr_fedbas_percent_amount_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line depreciation ITC basis from federal percentage [$]"),
 	NULL},
{"depr_fedbas_percent_amount_macrs_15", (getter)Outputs_get_depr_fedbas_percent_amount_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS depreciation ITC basis from federal percentage [$]"),
 	NULL},
{"depr_fedbas_percent_amount_macrs_5", (getter)Outputs_get_depr_fedbas_percent_amount_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS depreciation ITC basis from federal percentage [$]"),
 	NULL},
{"depr_fedbas_percent_amount_sl_15", (getter)Outputs_get_depr_fedbas_percent_amount_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line depreciation ITC basis from federal percentage [$]"),
 	NULL},
{"depr_fedbas_percent_amount_sl_20", (getter)Outputs_get_depr_fedbas_percent_amount_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line depreciation ITC basis from federal percentage [$]"),
 	NULL},
{"depr_fedbas_percent_amount_sl_39", (getter)Outputs_get_depr_fedbas_percent_amount_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line depreciation ITC basis from federal percentage [$]"),
 	NULL},
{"depr_fedbas_percent_amount_sl_5", (getter)Outputs_get_depr_fedbas_percent_amount_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line depreciation ITC basis from federal percentage [$]"),
 	NULL},
{"depr_fedbas_percent_amount_total", (getter)Outputs_get_depr_fedbas_percent_amount_total,(setter)0,
	PyDoc_STR("*float*: Total depreciation ITC basis from federal percentage [$]"),
 	NULL},
{"depr_fedbas_percent_custom", (getter)Outputs_get_depr_fedbas_percent_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line federal percent of total depreciable basis [%]"),
 	NULL},
{"depr_fedbas_percent_macrs_15", (getter)Outputs_get_depr_fedbas_percent_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS federal percent of total depreciable basis [%]"),
 	NULL},
{"depr_fedbas_percent_macrs_5", (getter)Outputs_get_depr_fedbas_percent_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS federal percent of total depreciable basis [%]"),
 	NULL},
{"depr_fedbas_percent_qual_custom", (getter)Outputs_get_depr_fedbas_percent_qual_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line federal percent of qualifying costs [%]"),
 	NULL},
{"depr_fedbas_percent_qual_macrs_15", (getter)Outputs_get_depr_fedbas_percent_qual_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS federal percent of qualifying costs [%]"),
 	NULL},
{"depr_fedbas_percent_qual_macrs_5", (getter)Outputs_get_depr_fedbas_percent_qual_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS federal percent of qualifying costs [%]"),
 	NULL},
{"depr_fedbas_percent_qual_sl_15", (getter)Outputs_get_depr_fedbas_percent_qual_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line federal percent of qualifying costs [%]"),
 	NULL},
{"depr_fedbas_percent_qual_sl_20", (getter)Outputs_get_depr_fedbas_percent_qual_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line federal percent of qualifying costs [%]"),
 	NULL},
{"depr_fedbas_percent_qual_sl_39", (getter)Outputs_get_depr_fedbas_percent_qual_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line federal percent of qualifying costs [%]"),
 	NULL},
{"depr_fedbas_percent_qual_sl_5", (getter)Outputs_get_depr_fedbas_percent_qual_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line federal percent of qualifying costs [%]"),
 	NULL},
{"depr_fedbas_percent_qual_total", (getter)Outputs_get_depr_fedbas_percent_qual_total,(setter)0,
	PyDoc_STR("*float*: Total federal percent of qualifying costs [%]"),
 	NULL},
{"depr_fedbas_percent_sl_15", (getter)Outputs_get_depr_fedbas_percent_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line federal percent of total depreciable basis [%]"),
 	NULL},
{"depr_fedbas_percent_sl_20", (getter)Outputs_get_depr_fedbas_percent_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line federal percent of total depreciable basis [%]"),
 	NULL},
{"depr_fedbas_percent_sl_39", (getter)Outputs_get_depr_fedbas_percent_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line federal percent of total depreciable basis [%]"),
 	NULL},
{"depr_fedbas_percent_sl_5", (getter)Outputs_get_depr_fedbas_percent_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line federal percent of total depreciable basis [%]"),
 	NULL},
{"depr_fedbas_percent_total", (getter)Outputs_get_depr_fedbas_percent_total,(setter)0,
	PyDoc_STR("*float*: Total federal percent of total depreciable basis [%]"),
 	NULL},
{"depr_fedbas_prior_itc_custom", (getter)Outputs_get_depr_fedbas_prior_itc_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line federal depreciation basis prior ITC reduction [$]"),
 	NULL},
{"depr_fedbas_prior_itc_macrs_15", (getter)Outputs_get_depr_fedbas_prior_itc_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS federal depreciation basis prior ITC reduction [$]"),
 	NULL},
{"depr_fedbas_prior_itc_macrs_5", (getter)Outputs_get_depr_fedbas_prior_itc_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS federal depreciation basis prior ITC reduction [$]"),
 	NULL},
{"depr_fedbas_prior_itc_sl_15", (getter)Outputs_get_depr_fedbas_prior_itc_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line federal depreciation basis prior ITC reduction [$]"),
 	NULL},
{"depr_fedbas_prior_itc_sl_20", (getter)Outputs_get_depr_fedbas_prior_itc_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line federal depreciation basis prior ITC reduction [$]"),
 	NULL},
{"depr_fedbas_prior_itc_sl_39", (getter)Outputs_get_depr_fedbas_prior_itc_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line federal depreciation basis prior ITC reduction [$]"),
 	NULL},
{"depr_fedbas_prior_itc_sl_5", (getter)Outputs_get_depr_fedbas_prior_itc_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line federal depreciation basis prior ITC reduction [$]"),
 	NULL},
{"depr_fedbas_prior_itc_total", (getter)Outputs_get_depr_fedbas_prior_itc_total,(setter)0,
	PyDoc_STR("*float*: Total federal depreciation basis prior ITC reduction [$]"),
 	NULL},
{"depr_fedbas_sl_15", (getter)Outputs_get_depr_fedbas_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line federal depreciation basis [$]"),
 	NULL},
{"depr_fedbas_sl_20", (getter)Outputs_get_depr_fedbas_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line federal depreciation basis [$]"),
 	NULL},
{"depr_fedbas_sl_39", (getter)Outputs_get_depr_fedbas_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line federal depreciation basis [$]"),
 	NULL},
{"depr_fedbas_sl_5", (getter)Outputs_get_depr_fedbas_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line federal depreciation basis [$]"),
 	NULL},
{"depr_fedbas_total", (getter)Outputs_get_depr_fedbas_total,(setter)0,
	PyDoc_STR("*float*: Total federal depreciation basis [$]"),
 	NULL},
{"depr_stabas_after_itc_custom", (getter)Outputs_get_depr_stabas_after_itc_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line state depreciation basis after ITC reduction [$]"),
 	NULL},
{"depr_stabas_after_itc_macrs_15", (getter)Outputs_get_depr_stabas_after_itc_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS state depreciation basis after ITC reduction [$]"),
 	NULL},
{"depr_stabas_after_itc_macrs_5", (getter)Outputs_get_depr_stabas_after_itc_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS state depreciation basis after ITC reduction [$]"),
 	NULL},
{"depr_stabas_after_itc_sl_15", (getter)Outputs_get_depr_stabas_after_itc_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line state depreciation basis after ITC reduction [$]"),
 	NULL},
{"depr_stabas_after_itc_sl_20", (getter)Outputs_get_depr_stabas_after_itc_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line state depreciation basis after ITC reduction [$]"),
 	NULL},
{"depr_stabas_after_itc_sl_39", (getter)Outputs_get_depr_stabas_after_itc_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line state depreciation basis after ITC reduction [$]"),
 	NULL},
{"depr_stabas_after_itc_sl_5", (getter)Outputs_get_depr_stabas_after_itc_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line state depreciation basis after ITC reduction [$]"),
 	NULL},
{"depr_stabas_after_itc_total", (getter)Outputs_get_depr_stabas_after_itc_total,(setter)0,
	PyDoc_STR("*float*: Total state depreciation basis after ITC reduction [$]"),
 	NULL},
{"depr_stabas_cbi_reduc_custom", (getter)Outputs_get_depr_stabas_cbi_reduc_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line state CBI reduction [$]"),
 	NULL},
{"depr_stabas_cbi_reduc_macrs_15", (getter)Outputs_get_depr_stabas_cbi_reduc_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS state CBI reduction [$]"),
 	NULL},
{"depr_stabas_cbi_reduc_macrs_5", (getter)Outputs_get_depr_stabas_cbi_reduc_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS state CBI reduction [$]"),
 	NULL},
{"depr_stabas_cbi_reduc_sl_15", (getter)Outputs_get_depr_stabas_cbi_reduc_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line state CBI reduction [$]"),
 	NULL},
{"depr_stabas_cbi_reduc_sl_20", (getter)Outputs_get_depr_stabas_cbi_reduc_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line state CBI reduction [$]"),
 	NULL},
{"depr_stabas_cbi_reduc_sl_39", (getter)Outputs_get_depr_stabas_cbi_reduc_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line state CBI reduction [$]"),
 	NULL},
{"depr_stabas_cbi_reduc_sl_5", (getter)Outputs_get_depr_stabas_cbi_reduc_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line state CBI reduction [$]"),
 	NULL},
{"depr_stabas_cbi_reduc_total", (getter)Outputs_get_depr_stabas_cbi_reduc_total,(setter)0,
	PyDoc_STR("*float*: Total state CBI reduction [$]"),
 	NULL},
{"depr_stabas_custom", (getter)Outputs_get_depr_stabas_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line state depreciation basis [$]"),
 	NULL},
{"depr_stabas_first_year_bonus_custom", (getter)Outputs_get_depr_stabas_first_year_bonus_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line state first year bonus depreciation [$]"),
 	NULL},
{"depr_stabas_first_year_bonus_macrs_15", (getter)Outputs_get_depr_stabas_first_year_bonus_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS state first year bonus depreciation [$]"),
 	NULL},
{"depr_stabas_first_year_bonus_macrs_5", (getter)Outputs_get_depr_stabas_first_year_bonus_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS state first year bonus depreciation [$]"),
 	NULL},
{"depr_stabas_first_year_bonus_sl_15", (getter)Outputs_get_depr_stabas_first_year_bonus_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line state first year bonus depreciation [$]"),
 	NULL},
{"depr_stabas_first_year_bonus_sl_20", (getter)Outputs_get_depr_stabas_first_year_bonus_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line state first year bonus depreciation [$]"),
 	NULL},
{"depr_stabas_first_year_bonus_sl_39", (getter)Outputs_get_depr_stabas_first_year_bonus_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line state first year bonus depreciation [$]"),
 	NULL},
{"depr_stabas_first_year_bonus_sl_5", (getter)Outputs_get_depr_stabas_first_year_bonus_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line state first year bonus depreciation [$]"),
 	NULL},
{"depr_stabas_first_year_bonus_total", (getter)Outputs_get_depr_stabas_first_year_bonus_total,(setter)0,
	PyDoc_STR("*float*: Total state first year bonus depreciation [$]"),
 	NULL},
{"depr_stabas_fixed_amount_custom", (getter)Outputs_get_depr_stabas_fixed_amount_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line depreciation ITC basis from state fixed amount [$]"),
 	NULL},
{"depr_stabas_fixed_amount_macrs_15", (getter)Outputs_get_depr_stabas_fixed_amount_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS depreciation ITC basis from state fixed amount [$]"),
 	NULL},
{"depr_stabas_fixed_amount_macrs_5", (getter)Outputs_get_depr_stabas_fixed_amount_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS depreciation ITC basis from state fixed amount [$]"),
 	NULL},
{"depr_stabas_fixed_amount_sl_15", (getter)Outputs_get_depr_stabas_fixed_amount_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line depreciation ITC basis from state fixed amount [$]"),
 	NULL},
{"depr_stabas_fixed_amount_sl_20", (getter)Outputs_get_depr_stabas_fixed_amount_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line depreciation ITC basis from state fixed amount [$]"),
 	NULL},
{"depr_stabas_fixed_amount_sl_39", (getter)Outputs_get_depr_stabas_fixed_amount_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line depreciation ITC basis from state fixed amount [$]"),
 	NULL},
{"depr_stabas_fixed_amount_sl_5", (getter)Outputs_get_depr_stabas_fixed_amount_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line depreciation ITC basis from state fixed amount [$]"),
 	NULL},
{"depr_stabas_fixed_amount_total", (getter)Outputs_get_depr_stabas_fixed_amount_total,(setter)0,
	PyDoc_STR("*float*: Total depreciation ITC basis from state fixed amount [$]"),
 	NULL},
{"depr_stabas_ibi_reduc_custom", (getter)Outputs_get_depr_stabas_ibi_reduc_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line state IBI reduction [$]"),
 	NULL},
{"depr_stabas_ibi_reduc_macrs_15", (getter)Outputs_get_depr_stabas_ibi_reduc_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS state IBI reduction [$]"),
 	NULL},
{"depr_stabas_ibi_reduc_macrs_5", (getter)Outputs_get_depr_stabas_ibi_reduc_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS state IBI reduction [$]"),
 	NULL},
{"depr_stabas_ibi_reduc_sl_15", (getter)Outputs_get_depr_stabas_ibi_reduc_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line state IBI reduction [$]"),
 	NULL},
{"depr_stabas_ibi_reduc_sl_20", (getter)Outputs_get_depr_stabas_ibi_reduc_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line state IBI reduction [$]"),
 	NULL},
{"depr_stabas_ibi_reduc_sl_39", (getter)Outputs_get_depr_stabas_ibi_reduc_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line state IBI reduction [$]"),
 	NULL},
{"depr_stabas_ibi_reduc_sl_5", (getter)Outputs_get_depr_stabas_ibi_reduc_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line state IBI reduction [$]"),
 	NULL},
{"depr_stabas_ibi_reduc_total", (getter)Outputs_get_depr_stabas_ibi_reduc_total,(setter)0,
	PyDoc_STR("*float*: Total state IBI reduction [$]"),
 	NULL},
{"depr_stabas_itc_fed_reduction_custom", (getter)Outputs_get_depr_stabas_itc_fed_reduction_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line state basis federal ITC reduction [$]"),
 	NULL},
{"depr_stabas_itc_fed_reduction_macrs_15", (getter)Outputs_get_depr_stabas_itc_fed_reduction_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS state basis federal ITC reduction [$]"),
 	NULL},
{"depr_stabas_itc_fed_reduction_macrs_5", (getter)Outputs_get_depr_stabas_itc_fed_reduction_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS state basis federal ITC reduction [$]"),
 	NULL},
{"depr_stabas_itc_fed_reduction_sl_15", (getter)Outputs_get_depr_stabas_itc_fed_reduction_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line state basis federal ITC reduction [$]"),
 	NULL},
{"depr_stabas_itc_fed_reduction_sl_20", (getter)Outputs_get_depr_stabas_itc_fed_reduction_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line state basis federal ITC reduction [$]"),
 	NULL},
{"depr_stabas_itc_fed_reduction_sl_39", (getter)Outputs_get_depr_stabas_itc_fed_reduction_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line state basis federal ITC reduction [$]"),
 	NULL},
{"depr_stabas_itc_fed_reduction_sl_5", (getter)Outputs_get_depr_stabas_itc_fed_reduction_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line state basis federal ITC reduction [$]"),
 	NULL},
{"depr_stabas_itc_fed_reduction_total", (getter)Outputs_get_depr_stabas_itc_fed_reduction_total,(setter)0,
	PyDoc_STR("*float*: Total state basis federal ITC reduction [$]"),
 	NULL},
{"depr_stabas_itc_sta_reduction_custom", (getter)Outputs_get_depr_stabas_itc_sta_reduction_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line state basis state ITC reduction [$]"),
 	NULL},
{"depr_stabas_itc_sta_reduction_macrs_15", (getter)Outputs_get_depr_stabas_itc_sta_reduction_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS state basis state ITC reduction [$]"),
 	NULL},
{"depr_stabas_itc_sta_reduction_macrs_5", (getter)Outputs_get_depr_stabas_itc_sta_reduction_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS state basis state ITC reduction [$]"),
 	NULL},
{"depr_stabas_itc_sta_reduction_sl_15", (getter)Outputs_get_depr_stabas_itc_sta_reduction_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line state basis state ITC reduction [$]"),
 	NULL},
{"depr_stabas_itc_sta_reduction_sl_20", (getter)Outputs_get_depr_stabas_itc_sta_reduction_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line state basis state ITC reduction [$]"),
 	NULL},
{"depr_stabas_itc_sta_reduction_sl_39", (getter)Outputs_get_depr_stabas_itc_sta_reduction_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line state basis state ITC reduction [$]"),
 	NULL},
{"depr_stabas_itc_sta_reduction_sl_5", (getter)Outputs_get_depr_stabas_itc_sta_reduction_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line state basis state ITC reduction [$]"),
 	NULL},
{"depr_stabas_itc_sta_reduction_total", (getter)Outputs_get_depr_stabas_itc_sta_reduction_total,(setter)0,
	PyDoc_STR("*float*: Total state basis state ITC reduction [$]"),
 	NULL},
{"depr_stabas_macrs_15", (getter)Outputs_get_depr_stabas_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS state depreciation basis [$]"),
 	NULL},
{"depr_stabas_macrs_5", (getter)Outputs_get_depr_stabas_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS state depreciation basis [$]"),
 	NULL},
{"depr_stabas_percent_amount_custom", (getter)Outputs_get_depr_stabas_percent_amount_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line depreciation ITC basis from state percentage [$]"),
 	NULL},
{"depr_stabas_percent_amount_macrs_15", (getter)Outputs_get_depr_stabas_percent_amount_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS depreciation ITC basis from state percentage [$]"),
 	NULL},
{"depr_stabas_percent_amount_macrs_5", (getter)Outputs_get_depr_stabas_percent_amount_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS depreciation ITC basis from state percentage [$]"),
 	NULL},
{"depr_stabas_percent_amount_sl_15", (getter)Outputs_get_depr_stabas_percent_amount_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line depreciation ITC basis from state percentage [$]"),
 	NULL},
{"depr_stabas_percent_amount_sl_20", (getter)Outputs_get_depr_stabas_percent_amount_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line depreciation ITC basis from state percentage [$]"),
 	NULL},
{"depr_stabas_percent_amount_sl_39", (getter)Outputs_get_depr_stabas_percent_amount_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line depreciation ITC basis from state percentage [$]"),
 	NULL},
{"depr_stabas_percent_amount_sl_5", (getter)Outputs_get_depr_stabas_percent_amount_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line depreciation ITC basis from state percentage [$]"),
 	NULL},
{"depr_stabas_percent_amount_total", (getter)Outputs_get_depr_stabas_percent_amount_total,(setter)0,
	PyDoc_STR("*float*: Total depreciation ITC basis from state percentage [$]"),
 	NULL},
{"depr_stabas_percent_custom", (getter)Outputs_get_depr_stabas_percent_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line state percent of total depreciable basis [%]"),
 	NULL},
{"depr_stabas_percent_macrs_15", (getter)Outputs_get_depr_stabas_percent_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS state percent of total depreciable basis [%]"),
 	NULL},
{"depr_stabas_percent_macrs_5", (getter)Outputs_get_depr_stabas_percent_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS state percent of total depreciable basis [%]"),
 	NULL},
{"depr_stabas_percent_qual_custom", (getter)Outputs_get_depr_stabas_percent_qual_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line state percent of qualifying costs [%]"),
 	NULL},
{"depr_stabas_percent_qual_macrs_15", (getter)Outputs_get_depr_stabas_percent_qual_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS state percent of qualifying costs [%]"),
 	NULL},
{"depr_stabas_percent_qual_macrs_5", (getter)Outputs_get_depr_stabas_percent_qual_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS state percent of qualifying costs [%]"),
 	NULL},
{"depr_stabas_percent_qual_sl_15", (getter)Outputs_get_depr_stabas_percent_qual_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line state percent of qualifying costs [%]"),
 	NULL},
{"depr_stabas_percent_qual_sl_20", (getter)Outputs_get_depr_stabas_percent_qual_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line state percent of qualifying costs [%]"),
 	NULL},
{"depr_stabas_percent_qual_sl_39", (getter)Outputs_get_depr_stabas_percent_qual_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line state percent of qualifying costs [%]"),
 	NULL},
{"depr_stabas_percent_qual_sl_5", (getter)Outputs_get_depr_stabas_percent_qual_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line state percent of qualifying costs [%]"),
 	NULL},
{"depr_stabas_percent_qual_total", (getter)Outputs_get_depr_stabas_percent_qual_total,(setter)0,
	PyDoc_STR("*float*: Total state percent of qualifying costs [%]"),
 	NULL},
{"depr_stabas_percent_sl_15", (getter)Outputs_get_depr_stabas_percent_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line state percent of total depreciable basis [%]"),
 	NULL},
{"depr_stabas_percent_sl_20", (getter)Outputs_get_depr_stabas_percent_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line state percent of total depreciable basis [%]"),
 	NULL},
{"depr_stabas_percent_sl_39", (getter)Outputs_get_depr_stabas_percent_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line state percent of total depreciable basis [%]"),
 	NULL},
{"depr_stabas_percent_sl_5", (getter)Outputs_get_depr_stabas_percent_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line state percent of total depreciable basis [%]"),
 	NULL},
{"depr_stabas_percent_total", (getter)Outputs_get_depr_stabas_percent_total,(setter)0,
	PyDoc_STR("*float*: Total state percent of total depreciable basis [%]"),
 	NULL},
{"depr_stabas_prior_itc_custom", (getter)Outputs_get_depr_stabas_prior_itc_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line state depreciation basis prior ITC reduction [$]"),
 	NULL},
{"depr_stabas_prior_itc_macrs_15", (getter)Outputs_get_depr_stabas_prior_itc_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS state depreciation basis prior ITC reduction [$]"),
 	NULL},
{"depr_stabas_prior_itc_macrs_5", (getter)Outputs_get_depr_stabas_prior_itc_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS state depreciation basis prior ITC reduction [$]"),
 	NULL},
{"depr_stabas_prior_itc_sl_15", (getter)Outputs_get_depr_stabas_prior_itc_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line state depreciation basis prior ITC reduction [$]"),
 	NULL},
{"depr_stabas_prior_itc_sl_20", (getter)Outputs_get_depr_stabas_prior_itc_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line state depreciation basis prior ITC reduction [$]"),
 	NULL},
{"depr_stabas_prior_itc_sl_39", (getter)Outputs_get_depr_stabas_prior_itc_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line state depreciation basis prior ITC reduction [$]"),
 	NULL},
{"depr_stabas_prior_itc_sl_5", (getter)Outputs_get_depr_stabas_prior_itc_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line state depreciation basis prior ITC reduction [$]"),
 	NULL},
{"depr_stabas_prior_itc_total", (getter)Outputs_get_depr_stabas_prior_itc_total,(setter)0,
	PyDoc_STR("*float*: Total state depreciation basis prior ITC reduction [$]"),
 	NULL},
{"depr_stabas_sl_15", (getter)Outputs_get_depr_stabas_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line state depreciation basis [$]"),
 	NULL},
{"depr_stabas_sl_20", (getter)Outputs_get_depr_stabas_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line state depreciation basis [$]"),
 	NULL},
{"depr_stabas_sl_39", (getter)Outputs_get_depr_stabas_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line state depreciation basis [$]"),
 	NULL},
{"depr_stabas_sl_5", (getter)Outputs_get_depr_stabas_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line state depreciation basis [$]"),
 	NULL},
{"depr_stabas_total", (getter)Outputs_get_depr_stabas_total,(setter)0,
	PyDoc_STR("*float*: Total state depreciation basis [$]"),
 	NULL},
{"effective_tax_rate", (getter)Outputs_get_effective_tax_rate,(setter)0,
	PyDoc_STR("*float*: Effective tax rate [%]"),
 	NULL},
{"firstyear_energy_dispatch1", (getter)Outputs_get_firstyear_energy_dispatch1,(setter)0,
	PyDoc_STR("*float*: First year energy from the system in TOD period 1 [kWh]"),
 	NULL},
{"firstyear_energy_dispatch2", (getter)Outputs_get_firstyear_energy_dispatch2,(setter)0,
	PyDoc_STR("*float*: First year energy from the system in TOD period 2 [kWh]"),
 	NULL},
{"firstyear_energy_dispatch3", (getter)Outputs_get_firstyear_energy_dispatch3,(setter)0,
	PyDoc_STR("*float*: First year energy from the system in TOD period 3 [kWh]"),
 	NULL},
{"firstyear_energy_dispatch4", (getter)Outputs_get_firstyear_energy_dispatch4,(setter)0,
	PyDoc_STR("*float*: First year energy from the system in TOD period 4 [kWh]"),
 	NULL},
{"firstyear_energy_dispatch5", (getter)Outputs_get_firstyear_energy_dispatch5,(setter)0,
	PyDoc_STR("*float*: First year energy from the system in TOD period 5 [kWh]"),
 	NULL},
{"firstyear_energy_dispatch6", (getter)Outputs_get_firstyear_energy_dispatch6,(setter)0,
	PyDoc_STR("*float*: First year energy from the system in TOD period 6 [kWh]"),
 	NULL},
{"firstyear_energy_dispatch7", (getter)Outputs_get_firstyear_energy_dispatch7,(setter)0,
	PyDoc_STR("*float*: First year energy from the system in TOD period 7 [kWh]"),
 	NULL},
{"firstyear_energy_dispatch8", (getter)Outputs_get_firstyear_energy_dispatch8,(setter)0,
	PyDoc_STR("*float*: First year energy from the system in TOD period 8 [kWh]"),
 	NULL},
{"firstyear_energy_dispatch9", (getter)Outputs_get_firstyear_energy_dispatch9,(setter)0,
	PyDoc_STR("*float*: First year energy from the system in TOD period 9 [kWh]"),
 	NULL},
{"firstyear_energy_price1", (getter)Outputs_get_firstyear_energy_price1,(setter)0,
	PyDoc_STR("*float*: First year energy price for TOD period 1 [cents/kWh]"),
 	NULL},
{"firstyear_energy_price2", (getter)Outputs_get_firstyear_energy_price2,(setter)0,
	PyDoc_STR("*float*: First year energy price for TOD period 2 [cents/kWh]"),
 	NULL},
{"firstyear_energy_price3", (getter)Outputs_get_firstyear_energy_price3,(setter)0,
	PyDoc_STR("*float*: First year energy price for TOD period 3 [cents/kWh]"),
 	NULL},
{"firstyear_energy_price4", (getter)Outputs_get_firstyear_energy_price4,(setter)0,
	PyDoc_STR("*float*: First year energy price for TOD period 4 [cents/kWh]"),
 	NULL},
{"firstyear_energy_price5", (getter)Outputs_get_firstyear_energy_price5,(setter)0,
	PyDoc_STR("*float*: First year energy price for TOD period 5 [cents/kWh]"),
 	NULL},
{"firstyear_energy_price6", (getter)Outputs_get_firstyear_energy_price6,(setter)0,
	PyDoc_STR("*float*: First year energy price for TOD period 6 [cents/kWh]"),
 	NULL},
{"firstyear_energy_price7", (getter)Outputs_get_firstyear_energy_price7,(setter)0,
	PyDoc_STR("*float*: First year energy price for TOD period 7 [cents/kWh]"),
 	NULL},
{"firstyear_energy_price8", (getter)Outputs_get_firstyear_energy_price8,(setter)0,
	PyDoc_STR("*float*: First year energy price for TOD period 8 [cents/kWh]"),
 	NULL},
{"firstyear_energy_price9", (getter)Outputs_get_firstyear_energy_price9,(setter)0,
	PyDoc_STR("*float*: First year energy price for TOD period 9 [cents/kWh]"),
 	NULL},
{"firstyear_revenue_dispatch1", (getter)Outputs_get_firstyear_revenue_dispatch1,(setter)0,
	PyDoc_STR("*float*: First year revenue from the system in TOD period 1 [$]"),
 	NULL},
{"firstyear_revenue_dispatch2", (getter)Outputs_get_firstyear_revenue_dispatch2,(setter)0,
	PyDoc_STR("*float*: First year revenue from the system in TOD period 2 [$]"),
 	NULL},
{"firstyear_revenue_dispatch3", (getter)Outputs_get_firstyear_revenue_dispatch3,(setter)0,
	PyDoc_STR("*float*: First year revenue from the system in TOD period 3 [$]"),
 	NULL},
{"firstyear_revenue_dispatch4", (getter)Outputs_get_firstyear_revenue_dispatch4,(setter)0,
	PyDoc_STR("*float*: First year revenue from the system in TOD period 4 [$]"),
 	NULL},
{"firstyear_revenue_dispatch5", (getter)Outputs_get_firstyear_revenue_dispatch5,(setter)0,
	PyDoc_STR("*float*: First year revenue from the system in TOD period 5 [$]"),
 	NULL},
{"firstyear_revenue_dispatch6", (getter)Outputs_get_firstyear_revenue_dispatch6,(setter)0,
	PyDoc_STR("*float*: First year revenue from the system in TOD period 6 [$]"),
 	NULL},
{"firstyear_revenue_dispatch7", (getter)Outputs_get_firstyear_revenue_dispatch7,(setter)0,
	PyDoc_STR("*float*: First year revenue from the system in TOD period 7 [$]"),
 	NULL},
{"firstyear_revenue_dispatch8", (getter)Outputs_get_firstyear_revenue_dispatch8,(setter)0,
	PyDoc_STR("*float*: First year revenue from the system in TOD period 8 [$]"),
 	NULL},
{"firstyear_revenue_dispatch9", (getter)Outputs_get_firstyear_revenue_dispatch9,(setter)0,
	PyDoc_STR("*float*: First year revenue from the system in TOD period 9 [$]"),
 	NULL},
{"flip_actual_irr", (getter)Outputs_get_flip_actual_irr,(setter)0,
	PyDoc_STR("*float*: IRR in target year [%]"),
 	NULL},
{"flip_actual_year", (getter)Outputs_get_flip_actual_year,(setter)0,
	PyDoc_STR("*float*: Year target IRR was achieved [year]"),
 	NULL},
{"flip_target_irr", (getter)Outputs_get_flip_target_irr,(setter)0,
	PyDoc_STR("*float*: IRR target [%]"),
 	NULL},
{"flip_target_year", (getter)Outputs_get_flip_target_year,(setter)0,
	PyDoc_STR("*float*: Target year to meet IRR"),
 	NULL},
{"host_nominal_discount_rate", (getter)Outputs_get_host_nominal_discount_rate,(setter)0,
	PyDoc_STR("*float*: Host nominal discount rate [%]"),
 	NULL},
{"ibi_fedtax_total", (getter)Outputs_get_ibi_fedtax_total,(setter)0,
	PyDoc_STR("*float*: Federal taxable IBI income [$]"),
 	NULL},
{"ibi_statax_total", (getter)Outputs_get_ibi_statax_total,(setter)0,
	PyDoc_STR("*float*: State taxable IBI income [$]"),
 	NULL},
{"ibi_total", (getter)Outputs_get_ibi_total,(setter)0,
	PyDoc_STR("*float*: Total IBI income [$]"),
 	NULL},
{"ibi_total_fed", (getter)Outputs_get_ibi_total_fed,(setter)0,
	PyDoc_STR("*float*: Federal IBI income [$]"),
 	NULL},
{"ibi_total_oth", (getter)Outputs_get_ibi_total_oth,(setter)0,
	PyDoc_STR("*float*: Other IBI income [$]"),
 	NULL},
{"ibi_total_sta", (getter)Outputs_get_ibi_total_sta,(setter)0,
	PyDoc_STR("*float*: State IBI income [$]"),
 	NULL},
{"ibi_total_uti", (getter)Outputs_get_ibi_total_uti,(setter)0,
	PyDoc_STR("*float*: Utility IBI income [$]"),
 	NULL},
{"issuance_of_equity", (getter)Outputs_get_issuance_of_equity,(setter)0,
	PyDoc_STR("*float*: Issuance of equity [$]"),
 	NULL},
{"itc_disallow_fed_fixed_custom", (getter)Outputs_get_itc_disallow_fed_fixed_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line depreciation ITC basis disallowance from federal fixed amount [$]"),
 	NULL},
{"itc_disallow_fed_fixed_macrs_15", (getter)Outputs_get_itc_disallow_fed_fixed_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS depreciation ITC basis disallowance from federal fixed amount [$]"),
 	NULL},
{"itc_disallow_fed_fixed_macrs_5", (getter)Outputs_get_itc_disallow_fed_fixed_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS depreciation ITC basis disallowance from federal fixed amount [$]"),
 	NULL},
{"itc_disallow_fed_fixed_sl_15", (getter)Outputs_get_itc_disallow_fed_fixed_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line depreciation ITC basis disallowance from federal fixed amount [$]"),
 	NULL},
{"itc_disallow_fed_fixed_sl_20", (getter)Outputs_get_itc_disallow_fed_fixed_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line depreciation ITC basis disallowance from federal fixed amount [$]"),
 	NULL},
{"itc_disallow_fed_fixed_sl_39", (getter)Outputs_get_itc_disallow_fed_fixed_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line depreciation ITC basis disallowance from federal fixed amount [$]"),
 	NULL},
{"itc_disallow_fed_fixed_sl_5", (getter)Outputs_get_itc_disallow_fed_fixed_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line depreciation ITC basis disallowance from federal fixed amount [$]"),
 	NULL},
{"itc_disallow_fed_fixed_total", (getter)Outputs_get_itc_disallow_fed_fixed_total,(setter)0,
	PyDoc_STR("*float*: Total depreciation ITC basis disallowance from federal fixed amount [$]"),
 	NULL},
{"itc_disallow_fed_percent_custom", (getter)Outputs_get_itc_disallow_fed_percent_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line depreciation ITC basis disallowance from federal percentage [$]"),
 	NULL},
{"itc_disallow_fed_percent_macrs_15", (getter)Outputs_get_itc_disallow_fed_percent_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS depreciation ITC basis disallowance from federal percentage [$]"),
 	NULL},
{"itc_disallow_fed_percent_macrs_5", (getter)Outputs_get_itc_disallow_fed_percent_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS depreciation ITC basis disallowance from federal percentage [$]"),
 	NULL},
{"itc_disallow_fed_percent_sl_15", (getter)Outputs_get_itc_disallow_fed_percent_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line depreciation ITC basis disallowance from federal percentage [$]"),
 	NULL},
{"itc_disallow_fed_percent_sl_20", (getter)Outputs_get_itc_disallow_fed_percent_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line depreciation ITC basis disallowance from federal percentage [$]"),
 	NULL},
{"itc_disallow_fed_percent_sl_39", (getter)Outputs_get_itc_disallow_fed_percent_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line depreciation ITC basis disallowance from federal percentage [$]"),
 	NULL},
{"itc_disallow_fed_percent_sl_5", (getter)Outputs_get_itc_disallow_fed_percent_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line depreciation ITC basis disallowance from federal percentage [$]"),
 	NULL},
{"itc_disallow_fed_percent_total", (getter)Outputs_get_itc_disallow_fed_percent_total,(setter)0,
	PyDoc_STR("*float*: Total depreciation ITC basis disallowance from federal percentage [$]"),
 	NULL},
{"itc_disallow_sta_fixed_custom", (getter)Outputs_get_itc_disallow_sta_fixed_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line depreciation ITC basis disallowance from state fixed amount [$]"),
 	NULL},
{"itc_disallow_sta_fixed_macrs_15", (getter)Outputs_get_itc_disallow_sta_fixed_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS depreciation ITC basis disallowance from state fixed amount [$]"),
 	NULL},
{"itc_disallow_sta_fixed_macrs_5", (getter)Outputs_get_itc_disallow_sta_fixed_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS depreciation ITC basis disallowance from state fixed amount [$]"),
 	NULL},
{"itc_disallow_sta_fixed_sl_15", (getter)Outputs_get_itc_disallow_sta_fixed_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line depreciation ITC basis disallowance from state fixed amount [$]"),
 	NULL},
{"itc_disallow_sta_fixed_sl_20", (getter)Outputs_get_itc_disallow_sta_fixed_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line depreciation ITC basis disallowance from state fixed amount [$]"),
 	NULL},
{"itc_disallow_sta_fixed_sl_39", (getter)Outputs_get_itc_disallow_sta_fixed_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line depreciation ITC basis disallowance from state fixed amount [$]"),
 	NULL},
{"itc_disallow_sta_fixed_sl_5", (getter)Outputs_get_itc_disallow_sta_fixed_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line depreciation ITC basis disallowance from state fixed amount [$]"),
 	NULL},
{"itc_disallow_sta_fixed_total", (getter)Outputs_get_itc_disallow_sta_fixed_total,(setter)0,
	PyDoc_STR("*float*: Total depreciation ITC basis disallowance from state fixed amount [$]"),
 	NULL},
{"itc_disallow_sta_percent_custom", (getter)Outputs_get_itc_disallow_sta_percent_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line depreciation ITC basis disallowance from state percentage [$]"),
 	NULL},
{"itc_disallow_sta_percent_macrs_15", (getter)Outputs_get_itc_disallow_sta_percent_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS depreciation ITC basis disallowance from state percentage [$]"),
 	NULL},
{"itc_disallow_sta_percent_macrs_5", (getter)Outputs_get_itc_disallow_sta_percent_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS depreciation ITC basis disallowance from state percentage [$]"),
 	NULL},
{"itc_disallow_sta_percent_sl_15", (getter)Outputs_get_itc_disallow_sta_percent_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line depreciation ITC basis disallowance from state percentage [$]"),
 	NULL},
{"itc_disallow_sta_percent_sl_20", (getter)Outputs_get_itc_disallow_sta_percent_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line depreciation ITC basis disallowance from state percentage [$]"),
 	NULL},
{"itc_disallow_sta_percent_sl_39", (getter)Outputs_get_itc_disallow_sta_percent_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line depreciation ITC basis disallowance from state percentage [$]"),
 	NULL},
{"itc_disallow_sta_percent_sl_5", (getter)Outputs_get_itc_disallow_sta_percent_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line depreciation ITC basis disallowance from state percentage [$]"),
 	NULL},
{"itc_disallow_sta_percent_total", (getter)Outputs_get_itc_disallow_sta_percent_total,(setter)0,
	PyDoc_STR("*float*: Total depreciation ITC basis disallowance from state percentage [$]"),
 	NULL},
{"itc_fed_fixed_total", (getter)Outputs_get_itc_fed_fixed_total,(setter)0,
	PyDoc_STR("*float*: Federal ITC fixed total [$]"),
 	NULL},
{"itc_fed_percent_total", (getter)Outputs_get_itc_fed_percent_total,(setter)0,
	PyDoc_STR("*float*: Federal ITC percent total [$]"),
 	NULL},
{"itc_fed_qual_custom", (getter)Outputs_get_itc_fed_qual_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line depreciation federal ITC adj qualifying costs [$]"),
 	NULL},
{"itc_fed_qual_macrs_15", (getter)Outputs_get_itc_fed_qual_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS depreciation federal ITC adj qualifying costs [$]"),
 	NULL},
{"itc_fed_qual_macrs_5", (getter)Outputs_get_itc_fed_qual_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS depreciation federal ITC adj qualifying costs [$]"),
 	NULL},
{"itc_fed_qual_sl_15", (getter)Outputs_get_itc_fed_qual_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line depreciation federal ITC adj qualifying costs [$]"),
 	NULL},
{"itc_fed_qual_sl_20", (getter)Outputs_get_itc_fed_qual_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line depreciation federal ITC adj qualifying costs [$]"),
 	NULL},
{"itc_fed_qual_sl_39", (getter)Outputs_get_itc_fed_qual_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line depreciation federal ITC adj qualifying costs [$]"),
 	NULL},
{"itc_fed_qual_sl_5", (getter)Outputs_get_itc_fed_qual_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line depreciation federal ITC adj qualifying costs [$]"),
 	NULL},
{"itc_fed_qual_total", (getter)Outputs_get_itc_fed_qual_total,(setter)0,
	PyDoc_STR("*float*: Total federal ITC adj qualifying costs [$]"),
 	NULL},
{"itc_sta_fixed_total", (getter)Outputs_get_itc_sta_fixed_total,(setter)0,
	PyDoc_STR("*float*: State ITC fixed total [$]"),
 	NULL},
{"itc_sta_percent_total", (getter)Outputs_get_itc_sta_percent_total,(setter)0,
	PyDoc_STR("*float*: State ITC percent total [$]"),
 	NULL},
{"itc_sta_qual_custom", (getter)Outputs_get_itc_sta_qual_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line depreciation state ITC adj qualifying costs [$]"),
 	NULL},
{"itc_sta_qual_macrs_15", (getter)Outputs_get_itc_sta_qual_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS depreciation state ITC adj qualifying costs [$]"),
 	NULL},
{"itc_sta_qual_macrs_5", (getter)Outputs_get_itc_sta_qual_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS depreciation state ITC adj qualifying costs [$]"),
 	NULL},
{"itc_sta_qual_sl_15", (getter)Outputs_get_itc_sta_qual_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line depreciation state ITC adj qualifying costs [$]"),
 	NULL},
{"itc_sta_qual_sl_20", (getter)Outputs_get_itc_sta_qual_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line depreciation state ITC adj qualifying costs [$]"),
 	NULL},
{"itc_sta_qual_sl_39", (getter)Outputs_get_itc_sta_qual_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line depreciation state ITC adj qualifying costs [$]"),
 	NULL},
{"itc_sta_qual_sl_5", (getter)Outputs_get_itc_sta_qual_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line depreciation state ITC adj qualifying costs [$]"),
 	NULL},
{"itc_sta_qual_total", (getter)Outputs_get_itc_sta_qual_total,(setter)0,
	PyDoc_STR("*float*: Total state ITC adj qualifying costs [$]"),
 	NULL},
{"itc_total", (getter)Outputs_get_itc_total,(setter)0,
	PyDoc_STR("*float*: Total ITC income [$]"),
 	NULL},
{"itc_total_fed", (getter)Outputs_get_itc_total_fed,(setter)0,
	PyDoc_STR("*float*: Federal ITC income [$]"),
 	NULL},
{"itc_total_sta", (getter)Outputs_get_itc_total_sta,(setter)0,
	PyDoc_STR("*float*: State ITC income [$]"),
 	NULL},
{"lcoe_nom", (getter)Outputs_get_lcoe_nom,(setter)0,
	PyDoc_STR("*float*: LCOE Levelized cost of energy nominal [cents/kWh]"),
 	NULL},
{"lcoe_real", (getter)Outputs_get_lcoe_real,(setter)0,
	PyDoc_STR("*float*: LCOE Levelized cost of energy real [cents/kWh]"),
 	NULL},
{"lcoptc_fed_nom", (getter)Outputs_get_lcoptc_fed_nom,(setter)0,
	PyDoc_STR("*float*: Levelized federal PTC nominal [cents/kWh]"),
 	NULL},
{"lcoptc_fed_real", (getter)Outputs_get_lcoptc_fed_real,(setter)0,
	PyDoc_STR("*float*: Levelized federal PTC real [cents/kWh]"),
 	NULL},
{"lcoptc_sta_nom", (getter)Outputs_get_lcoptc_sta_nom,(setter)0,
	PyDoc_STR("*float*: Levelized state PTC nominal [cents/kWh]"),
 	NULL},
{"lcoptc_sta_real", (getter)Outputs_get_lcoptc_sta_real,(setter)0,
	PyDoc_STR("*float*: Levelized state PTC real [cents/kWh]"),
 	NULL},
{"lcos_nom", (getter)Outputs_get_lcos_nom,(setter)0,
	PyDoc_STR("*float*: LCOS Levelized cost of storage nominal [cents/kWh]"),
 	NULL},
{"lcos_real", (getter)Outputs_get_lcos_real,(setter)0,
	PyDoc_STR("*float*: LCOS Levelized cost of storage real [cents/kWh]"),
 	NULL},
{"lnte_nom", (getter)Outputs_get_lnte_nom,(setter)0,
	PyDoc_STR("*float*: Host indifference point levelized nominal [cents/kWh]"),
 	NULL},
{"lnte_real", (getter)Outputs_get_lnte_real,(setter)0,
	PyDoc_STR("*float*: Host indifference point levelized real [cents/kWh]"),
 	NULL},
{"lppa_nom", (getter)Outputs_get_lppa_nom,(setter)0,
	PyDoc_STR("*float*: LPPA Levelized PPA price nominal [cents/kWh]"),
 	NULL},
{"lppa_real", (getter)Outputs_get_lppa_real,(setter)0,
	PyDoc_STR("*float*: LPPA Levelized PPA price real [cents/kWh]"),
 	NULL},
{"min_dscr", (getter)Outputs_get_min_dscr,(setter)0,
	PyDoc_STR("*float*: Minimum DSCR"),
 	NULL},
{"nominal_discount_rate", (getter)Outputs_get_nominal_discount_rate,(setter)0,
	PyDoc_STR("*float*: Nominal discount rate [%]"),
 	NULL},
{"npv", (getter)Outputs_get_npv,(setter)0,
	PyDoc_STR("*float*: Host NPV Net present value [$]"),
 	NULL},
{"npv_annual_costs", (getter)Outputs_get_npv_annual_costs,(setter)0,
	PyDoc_STR("*float*: Present value of annual costs [$]"),
 	NULL},
{"npv_annual_costs_lcos", (getter)Outputs_get_npv_annual_costs_lcos,(setter)0,
	PyDoc_STR("*float*: Present value of annual storage costs [$]"),
 	NULL},
{"npv_energy_lcos_nom", (getter)Outputs_get_npv_energy_lcos_nom,(setter)0,
	PyDoc_STR("*float*: Present value of annual stored energy (nominal) [kWh]"),
 	NULL},
{"npv_energy_lcos_real", (getter)Outputs_get_npv_energy_lcos_real,(setter)0,
	PyDoc_STR("*float*: Present value of annual stored energy (real) [kWh]"),
 	NULL},
{"npv_energy_nom", (getter)Outputs_get_npv_energy_nom,(setter)0,
	PyDoc_STR("*float*: Present value of annual energy nominal [kWh]"),
 	NULL},
{"npv_energy_real", (getter)Outputs_get_npv_energy_real,(setter)0,
	PyDoc_STR("*float*: Present value of annual energy real [kWh]"),
 	NULL},
{"npv_ppa_revenue", (getter)Outputs_get_npv_ppa_revenue,(setter)0,
	PyDoc_STR("*float*: Present value of PPA revenue [$]"),
 	NULL},
{"ppa", (getter)Outputs_get_ppa,(setter)0,
	PyDoc_STR("*float*: PPA price in Year 1 [cents/kWh]"),
 	NULL},
{"ppa_escalation", (getter)Outputs_get_ppa_escalation,(setter)0,
	PyDoc_STR("*float*: PPA price escalation [%/year]"),
 	NULL},
{"ppa_multipliers", (getter)Outputs_get_ppa_multipliers,(setter)0,
	PyDoc_STR("*sequence*: TOD factors"),
 	NULL},
{"ppa_price", (getter)Outputs_get_ppa_price,(setter)0,
	PyDoc_STR("*float*: PPA price in first year [cents/kWh]"),
 	NULL},
{"pre_depr_alloc_basis", (getter)Outputs_get_pre_depr_alloc_basis,(setter)0,
	PyDoc_STR("*float*: Depreciable basis prior to allocation [$]"),
 	NULL},
{"pre_itc_qual_basis", (getter)Outputs_get_pre_itc_qual_basis,(setter)0,
	PyDoc_STR("*float*: ITC basis prior to qualification [$]"),
 	NULL},
{"present_value_fuel", (getter)Outputs_get_present_value_fuel,(setter)0,
	PyDoc_STR("*float*: Present value of fuel O&M [$]"),
 	NULL},
{"present_value_insandproptax", (getter)Outputs_get_present_value_insandproptax,(setter)0,
	PyDoc_STR("*float*: Present value of insurance and prop tax [$]"),
 	NULL},
{"present_value_oandm", (getter)Outputs_get_present_value_oandm,(setter)0,
	PyDoc_STR("*float*: Present value of O&M [$]"),
 	NULL},
{"present_value_oandm_nonfuel", (getter)Outputs_get_present_value_oandm_nonfuel,(setter)0,
	PyDoc_STR("*float*: Present value of non-fuel O&M [$]"),
 	NULL},
{"project_return_aftertax_irr", (getter)Outputs_get_project_return_aftertax_irr,(setter)0,
	PyDoc_STR("*float*: IRR Internal rate of return [%]"),
 	NULL},
{"project_return_aftertax_npv", (getter)Outputs_get_project_return_aftertax_npv,(setter)0,
	PyDoc_STR("*float*: NPV Net present value [$]"),
 	NULL},
{"prop_tax_assessed_value", (getter)Outputs_get_prop_tax_assessed_value,(setter)0,
	PyDoc_STR("*float*: Assessed value of property for tax purposes [$]"),
 	NULL},
{"purchase_of_property", (getter)Outputs_get_purchase_of_property,(setter)0,
	PyDoc_STR("*float*: Purchase of property [$]"),
 	NULL},
{"pv_cafds", (getter)Outputs_get_pv_cafds,(setter)0,
	PyDoc_STR("*float*: Present value of CAFDS [$]"),
 	NULL},
{"salvage_value", (getter)Outputs_get_salvage_value,(setter)0,
	PyDoc_STR("*float*: Net pre-tax cash salvage value [$]"),
 	NULL},
{"size_of_debt", (getter)Outputs_get_size_of_debt,(setter)0,
	PyDoc_STR("*float*: Size of debt [$]"),
 	NULL},
{"size_of_equity", (getter)Outputs_get_size_of_equity,(setter)0,
	PyDoc_STR("*float*: Equity [$]"),
 	NULL},
{"wacc", (getter)Outputs_get_wacc,(setter)0,
	PyDoc_STR("*float*: WACC Weighted average cost of capital [$]"),
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
		"HostDeveloper.Outputs",             /*tp_name*/
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
 * HostDeveloper
 */

static PyTypeObject HostDeveloper_Type;

static CmodObject *
newHostDeveloperObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &HostDeveloper_Type);

	PySAM_TECH_ATTR()

	PyObject* Revenue_obj = Revenue_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Revenue", Revenue_obj);
	Py_DECREF(Revenue_obj);

	PyObject* FinancialParameters_obj = FinancialParameters_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FinancialParameters", FinancialParameters_obj);
	Py_DECREF(FinancialParameters_obj);

	PyObject* SystemCosts_obj = SystemCosts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemCosts", SystemCosts_obj);
	Py_DECREF(SystemCosts_obj);

	PyObject* LandLease_obj = LandLease_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "LandLease", LandLease_obj);
	Py_DECREF(LandLease_obj);

	PyObject* TaxCreditIncentives_obj = TaxCreditIncentives_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TaxCreditIncentives", TaxCreditIncentives_obj);
	Py_DECREF(TaxCreditIncentives_obj);

	PyObject* Depreciation_obj = Depreciation_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Depreciation", Depreciation_obj);
	Py_DECREF(Depreciation_obj);

	PyObject* PaymentIncentives_obj = PaymentIncentives_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "PaymentIncentives", PaymentIncentives_obj);
	Py_DECREF(PaymentIncentives_obj);

	PyObject* Host_obj = Host_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Host", Host_obj);
	Py_DECREF(Host_obj);

	PyObject* TimeSeries_obj = TimeSeries_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TimeSeries", TimeSeries_obj);
	Py_DECREF(TimeSeries_obj);

	PyObject* ChargesByMonth_obj = ChargesByMonth_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ChargesByMonth", ChargesByMonth_obj);
	Py_DECREF(ChargesByMonth_obj);

	PyObject* SystemOutput_obj = SystemOutput_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemOutput", SystemOutput_obj);
	Py_DECREF(SystemOutput_obj);

	PyObject* Moratorium_obj = Moratorium_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Moratorium", Moratorium_obj);
	Py_DECREF(Moratorium_obj);

	PyObject* Recapitalization_obj = Recapitalization_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Recapitalization", Recapitalization_obj);
	Py_DECREF(Recapitalization_obj);

	PyObject* TimeOfDelivery_obj = TimeOfDelivery_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TimeOfDelivery", TimeOfDelivery_obj);
	Py_DECREF(TimeOfDelivery_obj);

	PyObject* ConstructionFinancing_obj = ConstructionFinancing_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ConstructionFinancing", ConstructionFinancing_obj);
	Py_DECREF(ConstructionFinancing_obj);

	PyObject* BatterySystem_obj = BatterySystem_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "BatterySystem", BatterySystem_obj);
	Py_DECREF(BatterySystem_obj);

	PyObject* LCOS_obj = LCOS_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "LCOS", LCOS_obj);
	Py_DECREF(LCOS_obj);

	PyObject* ElectricityRates_obj = ElectricityRates_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ElectricityRates", ElectricityRates_obj);
	Py_DECREF(ElectricityRates_obj);

	PyObject* HybridFin_obj = HybridFin_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "HybridFin", HybridFin_obj);
	Py_DECREF(HybridFin_obj);

	PyObject* Monthly_obj = Monthly_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Monthly", Monthly_obj);
	Py_DECREF(Monthly_obj);

	PyObject* FuelCell_obj = FuelCell_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FuelCell", FuelCell_obj);
	Py_DECREF(FuelCell_obj);

	PyObject* HybridCosts_obj = HybridCosts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "HybridCosts", HybridCosts_obj);
	Py_DECREF(HybridCosts_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* HostDeveloper methods */

static void
HostDeveloper_dealloc(CmodObject *self)
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
HostDeveloper_get_data_ptr(CmodObject *self, PyObject *args)
{
	PyObject* ptr = PyLong_FromVoidPtr((void*)self->data_ptr);
	return ptr;
}


static PyObject *
HostDeveloper_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_HostDeveloper_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
HostDeveloper_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "HostDeveloper"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
HostDeveloper_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "HostDeveloper"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
HostDeveloper_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
HostDeveloper_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
HostDeveloper_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef HostDeveloper_methods[] = {
		{"execute",           (PyCFunction)HostDeveloper_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)HostDeveloper_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Revenue': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)HostDeveloper_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Revenue': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)HostDeveloper_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)HostDeveloper_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)HostDeveloper_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{"get_data_ptr",           (PyCFunction)HostDeveloper_get_data_ptr,  METH_VARARGS,
				PyDoc_STR("get_data_ptr() -> Pointer\n Get ssc_data_t pointer")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
HostDeveloper_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
HostDeveloper_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject HostDeveloper_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"HostDeveloper",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)HostDeveloper_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)HostDeveloper_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)HostDeveloper_getattro, /*tp_getattro*/
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
		HostDeveloper_methods,      /*tp_methods*/
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


/* Function of no arguments returning new HostDeveloper object */

static PyObject *
HostDeveloper_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newHostDeveloperObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
HostDeveloper_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newHostDeveloperObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
HostDeveloper_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newHostDeveloperObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "HostDeveloper", def) < 0) {
		HostDeveloper_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
HostDeveloper_from_existing(PyObject *self, PyObject *args)
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

	rv = newHostDeveloperObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "HostDeveloper", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef HostDeveloperModule_methods[] = {
		{"new",             HostDeveloper_new,         METH_VARARGS,
				PyDoc_STR("new() -> HostDeveloper")},
		{"default",             HostDeveloper_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> HostDeveloper\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"CustomGenerationBatteryHostDeveloper\"*\n\n		- *\"CustomGenerationProfileHostDeveloper\"*\n\n		- *\"CustomGenerationPVWattsWindFuelCellBatteryHybridHostDeveloper\"*\n\n		- *\"FlatPlatePVHostDeveloper\"*\n\n		- *\"PVBatteryHostDeveloper\"*\n\n		- *\"PVWattsBatteryHostDeveloper\"*\n\n		- *\"PVWattsWindBatteryHybridHostDeveloper\"*\n\n		- *\"PVWattsWindFuelCellBatteryHybridHostDeveloper\"*\n\n		- *\"PVWattsHostDeveloper\"*\n\n		- *\"PhotovoltaicWindBatteryHybridHostDeveloper\"*\n\n		- *\"StandaloneBatteryHostDeveloper\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             HostDeveloper_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> HostDeveloper\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   HostDeveloper_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> HostDeveloper\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Third party ownership with PPA financial model from host and developer perspective");


static int
HostDeveloperModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	HostDeveloper_Type.tp_dict = PyDict_New();
	if (!HostDeveloper_Type.tp_dict) { goto fail; }

	/// Add the Revenue type object to HostDeveloper_Type
	if (PyType_Ready(&Revenue_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"Revenue",
				(PyObject*)&Revenue_Type);
	Py_DECREF(&Revenue_Type);

	/// Add the FinancialParameters type object to HostDeveloper_Type
	if (PyType_Ready(&FinancialParameters_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"FinancialParameters",
				(PyObject*)&FinancialParameters_Type);
	Py_DECREF(&FinancialParameters_Type);

	/// Add the SystemCosts type object to HostDeveloper_Type
	if (PyType_Ready(&SystemCosts_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"SystemCosts",
				(PyObject*)&SystemCosts_Type);
	Py_DECREF(&SystemCosts_Type);

	/// Add the LandLease type object to HostDeveloper_Type
	if (PyType_Ready(&LandLease_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"LandLease",
				(PyObject*)&LandLease_Type);
	Py_DECREF(&LandLease_Type);

	/// Add the TaxCreditIncentives type object to HostDeveloper_Type
	if (PyType_Ready(&TaxCreditIncentives_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"TaxCreditIncentives",
				(PyObject*)&TaxCreditIncentives_Type);
	Py_DECREF(&TaxCreditIncentives_Type);

	/// Add the Depreciation type object to HostDeveloper_Type
	if (PyType_Ready(&Depreciation_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"Depreciation",
				(PyObject*)&Depreciation_Type);
	Py_DECREF(&Depreciation_Type);

	/// Add the PaymentIncentives type object to HostDeveloper_Type
	if (PyType_Ready(&PaymentIncentives_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"PaymentIncentives",
				(PyObject*)&PaymentIncentives_Type);
	Py_DECREF(&PaymentIncentives_Type);

	/// Add the Host type object to HostDeveloper_Type
	if (PyType_Ready(&Host_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"Host",
				(PyObject*)&Host_Type);
	Py_DECREF(&Host_Type);

	/// Add the TimeSeries type object to HostDeveloper_Type
	if (PyType_Ready(&TimeSeries_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"TimeSeries",
				(PyObject*)&TimeSeries_Type);
	Py_DECREF(&TimeSeries_Type);

	/// Add the ChargesByMonth type object to HostDeveloper_Type
	if (PyType_Ready(&ChargesByMonth_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"ChargesByMonth",
				(PyObject*)&ChargesByMonth_Type);
	Py_DECREF(&ChargesByMonth_Type);

	/// Add the SystemOutput type object to HostDeveloper_Type
	if (PyType_Ready(&SystemOutput_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"SystemOutput",
				(PyObject*)&SystemOutput_Type);
	Py_DECREF(&SystemOutput_Type);

	/// Add the Moratorium type object to HostDeveloper_Type
	if (PyType_Ready(&Moratorium_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"Moratorium",
				(PyObject*)&Moratorium_Type);
	Py_DECREF(&Moratorium_Type);

	/// Add the Recapitalization type object to HostDeveloper_Type
	if (PyType_Ready(&Recapitalization_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"Recapitalization",
				(PyObject*)&Recapitalization_Type);
	Py_DECREF(&Recapitalization_Type);

	/// Add the TimeOfDelivery type object to HostDeveloper_Type
	if (PyType_Ready(&TimeOfDelivery_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"TimeOfDelivery",
				(PyObject*)&TimeOfDelivery_Type);
	Py_DECREF(&TimeOfDelivery_Type);

	/// Add the ConstructionFinancing type object to HostDeveloper_Type
	if (PyType_Ready(&ConstructionFinancing_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"ConstructionFinancing",
				(PyObject*)&ConstructionFinancing_Type);
	Py_DECREF(&ConstructionFinancing_Type);

	/// Add the BatterySystem type object to HostDeveloper_Type
	if (PyType_Ready(&BatterySystem_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"BatterySystem",
				(PyObject*)&BatterySystem_Type);
	Py_DECREF(&BatterySystem_Type);

	/// Add the LCOS type object to HostDeveloper_Type
	if (PyType_Ready(&LCOS_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"LCOS",
				(PyObject*)&LCOS_Type);
	Py_DECREF(&LCOS_Type);

	/// Add the ElectricityRates type object to HostDeveloper_Type
	if (PyType_Ready(&ElectricityRates_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"ElectricityRates",
				(PyObject*)&ElectricityRates_Type);
	Py_DECREF(&ElectricityRates_Type);

	/// Add the HybridFin type object to HostDeveloper_Type
	if (PyType_Ready(&HybridFin_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"HybridFin",
				(PyObject*)&HybridFin_Type);
	Py_DECREF(&HybridFin_Type);

	/// Add the Monthly type object to HostDeveloper_Type
	if (PyType_Ready(&Monthly_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"Monthly",
				(PyObject*)&Monthly_Type);
	Py_DECREF(&Monthly_Type);

	/// Add the FuelCell type object to HostDeveloper_Type
	if (PyType_Ready(&FuelCell_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"FuelCell",
				(PyObject*)&FuelCell_Type);
	Py_DECREF(&FuelCell_Type);

	/// Add the HybridCosts type object to HostDeveloper_Type
	if (PyType_Ready(&HybridCosts_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"HybridCosts",
				(PyObject*)&HybridCosts_Type);
	Py_DECREF(&HybridCosts_Type);

	/// Add the Outputs type object to HostDeveloper_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(HostDeveloper_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the HostDeveloper type object to the module
	if (PyType_Ready(&HostDeveloper_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"HostDeveloper",
				(PyObject*)&HostDeveloper_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot HostDeveloperModule_slots[] = {
		{Py_mod_exec, HostDeveloperModule_exec},
		{0, NULL},
};

static struct PyModuleDef HostDeveloperModule = {
		PyModuleDef_HEAD_INIT,
		"HostDeveloper",
		module_doc,
		0,
		HostDeveloperModule_methods,
		HostDeveloperModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_HostDeveloper(void)
{
	return PyModuleDef_Init(&HostDeveloperModule);
}