#include <Python.h>

#include <SAM_Equpartflip.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Revenue Group
 */ 

static PyTypeObject Revenue_Type;

static PyObject *
Revenue_new(SAM_Equpartflip data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "Revenue")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "Revenue")){
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
Revenue_get_ppa_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Revenue_ppa_escalation_nget, self->data_ptr);
}

static int
Revenue_set_ppa_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Revenue_ppa_escalation_nset, self->data_ptr);
}

static PyObject *
Revenue_get_ppa_price_input(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Revenue_ppa_price_input_aget, self->data_ptr);
}

static int
Revenue_set_ppa_price_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_Revenue_ppa_price_input_aset, self->data_ptr);
}

static PyObject *
Revenue_get_ppa_soln_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Revenue_ppa_soln_max_nget, self->data_ptr);
}

static int
Revenue_set_ppa_soln_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Revenue_ppa_soln_max_nset, self->data_ptr);
}

static PyObject *
Revenue_get_ppa_soln_max_iterations(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Revenue_ppa_soln_max_iterations_nget, self->data_ptr);
}

static int
Revenue_set_ppa_soln_max_iterations(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Revenue_ppa_soln_max_iterations_nset, self->data_ptr);
}

static PyObject *
Revenue_get_ppa_soln_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Revenue_ppa_soln_min_nget, self->data_ptr);
}

static int
Revenue_set_ppa_soln_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Revenue_ppa_soln_min_nset, self->data_ptr);
}

static PyObject *
Revenue_get_ppa_soln_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Revenue_ppa_soln_mode_nget, self->data_ptr);
}

static int
Revenue_set_ppa_soln_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Revenue_ppa_soln_mode_nset, self->data_ptr);
}

static PyObject *
Revenue_get_ppa_soln_tolerance(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Revenue_ppa_soln_tolerance_nget, self->data_ptr);
}

static int
Revenue_set_ppa_soln_tolerance(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Revenue_ppa_soln_tolerance_nset, self->data_ptr);
}

static PyGetSetDef Revenue_getset[] = {
{"ppa_escalation", (getter)Revenue_get_ppa_escalation,(setter)Revenue_set_ppa_escalation,
	PyDoc_STR("*float*: PPA escalation rate [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
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
		"Equpartflip.Revenue",             /*tp_name*/
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
FinancialParameters_new(SAM_Equpartflip data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "FinancialParameters")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "FinancialParameters")){
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
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_analysis_period_nget, self->data_ptr);
}

static int
FinancialParameters_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_analysis_period_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_batt_salvage_percentage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_batt_salvage_percentage_nget, self->data_ptr);
}

static int
FinancialParameters_set_batt_salvage_percentage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_batt_salvage_percentage_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_equip1_reserve_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_equip1_reserve_cost_nget, self->data_ptr);
}

static int
FinancialParameters_set_equip1_reserve_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_equip1_reserve_cost_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_equip1_reserve_freq(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_equip1_reserve_freq_nget, self->data_ptr);
}

static int
FinancialParameters_set_equip1_reserve_freq(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_equip1_reserve_freq_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_equip2_reserve_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_equip2_reserve_cost_nget, self->data_ptr);
}

static int
FinancialParameters_set_equip2_reserve_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_equip2_reserve_cost_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_equip2_reserve_freq(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_equip2_reserve_freq_nget, self->data_ptr);
}

static int
FinancialParameters_set_equip2_reserve_freq(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_equip2_reserve_freq_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_equip3_reserve_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_equip3_reserve_cost_nget, self->data_ptr);
}

static int
FinancialParameters_set_equip3_reserve_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_equip3_reserve_cost_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_equip3_reserve_freq(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_equip3_reserve_freq_nget, self->data_ptr);
}

static int
FinancialParameters_set_equip3_reserve_freq(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_equip3_reserve_freq_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_equip_reserve_depr_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_equip_reserve_depr_fed_nget, self->data_ptr);
}

static int
FinancialParameters_set_equip_reserve_depr_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_equip_reserve_depr_fed_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_equip_reserve_depr_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_equip_reserve_depr_sta_nget, self->data_ptr);
}

static int
FinancialParameters_set_equip_reserve_depr_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_equip_reserve_depr_sta_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_federal_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_FinancialParameters_federal_tax_rate_aget, self->data_ptr);
}

static int
FinancialParameters_set_federal_tax_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_FinancialParameters_federal_tax_rate_aset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_inflation_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_inflation_rate_nget, self->data_ptr);
}

static int
FinancialParameters_set_inflation_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_inflation_rate_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_insurance_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_insurance_rate_nget, self->data_ptr);
}

static int
FinancialParameters_set_insurance_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_insurance_rate_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_prop_tax_assessed_decline(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_prop_tax_assessed_decline_nget, self->data_ptr);
}

static int
FinancialParameters_set_prop_tax_assessed_decline(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_prop_tax_assessed_decline_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_prop_tax_cost_assessed_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_prop_tax_cost_assessed_percent_nget, self->data_ptr);
}

static int
FinancialParameters_set_prop_tax_cost_assessed_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_prop_tax_cost_assessed_percent_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_property_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_property_tax_rate_nget, self->data_ptr);
}

static int
FinancialParameters_set_property_tax_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_property_tax_rate_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_real_discount_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_real_discount_rate_nget, self->data_ptr);
}

static int
FinancialParameters_set_real_discount_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_real_discount_rate_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_reserves_interest(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_reserves_interest_nget, self->data_ptr);
}

static int
FinancialParameters_set_reserves_interest(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_reserves_interest_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_salvage_percentage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_salvage_percentage_nget, self->data_ptr);
}

static int
FinancialParameters_set_salvage_percentage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_salvage_percentage_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_state_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_FinancialParameters_state_tax_rate_aget, self->data_ptr);
}

static int
FinancialParameters_set_state_tax_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_FinancialParameters_state_tax_rate_aset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_system_capacity_nget, self->data_ptr);
}

static int
FinancialParameters_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_system_capacity_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_system_heat_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_FinancialParameters_system_heat_rate_nget, self->data_ptr);
}

static int
FinancialParameters_set_system_heat_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_FinancialParameters_system_heat_rate_nset, self->data_ptr);
}

static PyGetSetDef FinancialParameters_getset[] = {
{"analysis_period", (getter)FinancialParameters_get_analysis_period,(setter)FinancialParameters_set_analysis_period,
	PyDoc_STR("*float*: Analyis period [years]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=50\n\n**Required:**\nFalse. Automatically set to 30 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_salvage_percentage", (getter)FinancialParameters_get_batt_salvage_percentage,(setter)FinancialParameters_set_batt_salvage_percentage,
	PyDoc_STR("*float*: Net pre-tax cash battery salvage value [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
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
	PyDoc_STR("*float*: System nameplate capacity [kW]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"system_heat_rate", (getter)FinancialParameters_get_system_heat_rate,(setter)FinancialParameters_set_system_heat_rate,
	PyDoc_STR("*float*: System heat rate [MMBTus/MWh]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FinancialParameters_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Equpartflip.FinancialParameters",             /*tp_name*/
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
SystemCosts_new(SAM_Equpartflip data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "SystemCosts")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "SystemCosts")){
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
	return PySAM_double_getter(SAM_Equpartflip_SystemCosts_add_om_num_types_nget, self->data_ptr);
}

static int
SystemCosts_set_add_om_num_types(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_SystemCosts_add_om_num_types_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_annual_fuel_usage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_SystemCosts_annual_fuel_usage_nget, self->data_ptr);
}

static int
SystemCosts_set_annual_fuel_usage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_SystemCosts_annual_fuel_usage_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_annual_fuel_usage_lifetime(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemCosts_annual_fuel_usage_lifetime_aget, self->data_ptr);
}

static int
SystemCosts_set_annual_fuel_usage_lifetime(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemCosts_annual_fuel_usage_lifetime_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_fuelcell_annual_energy_discharged(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemCosts_fuelcell_annual_energy_discharged_aget, self->data_ptr);
}

static int
SystemCosts_set_fuelcell_annual_energy_discharged(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemCosts_fuelcell_annual_energy_discharged_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_batt_capacity_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemCosts_om_batt_capacity_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_batt_capacity_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemCosts_om_batt_capacity_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_batt_fixed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemCosts_om_batt_fixed_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_batt_fixed_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemCosts_om_batt_fixed_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_batt_nameplate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_SystemCosts_om_batt_nameplate_nget, self->data_ptr);
}

static int
SystemCosts_set_om_batt_nameplate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_SystemCosts_om_batt_nameplate_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_batt_replacement_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemCosts_om_batt_replacement_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_batt_replacement_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemCosts_om_batt_replacement_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_batt_variable_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemCosts_om_batt_variable_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_batt_variable_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemCosts_om_batt_variable_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemCosts_om_capacity_aget, self->data_ptr);
}

static int
SystemCosts_set_om_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemCosts_om_capacity_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_capacity_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_SystemCosts_om_capacity_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_capacity_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_SystemCosts_om_capacity_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemCosts_om_fixed_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemCosts_om_fixed_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fixed_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_SystemCosts_om_fixed_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_fixed_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_SystemCosts_om_fixed_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuel_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemCosts_om_fuel_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fuel_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemCosts_om_fuel_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuel_cost_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_SystemCosts_om_fuel_cost_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_fuel_cost_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_SystemCosts_om_fuel_cost_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuelcell_capacity_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemCosts_om_fuelcell_capacity_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fuelcell_capacity_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemCosts_om_fuelcell_capacity_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuelcell_fixed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemCosts_om_fuelcell_fixed_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fuelcell_fixed_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemCosts_om_fuelcell_fixed_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuelcell_nameplate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_SystemCosts_om_fuelcell_nameplate_nget, self->data_ptr);
}

static int
SystemCosts_set_om_fuelcell_nameplate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_SystemCosts_om_fuelcell_nameplate_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuelcell_replacement_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemCosts_om_fuelcell_replacement_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fuelcell_replacement_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemCosts_om_fuelcell_replacement_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuelcell_variable_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemCosts_om_fuelcell_variable_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fuelcell_variable_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemCosts_om_fuelcell_variable_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_1_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemCosts_om_opt_fuel_1_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_1_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemCosts_om_opt_fuel_1_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_1_cost_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_SystemCosts_om_opt_fuel_1_cost_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_1_cost_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_SystemCosts_om_opt_fuel_1_cost_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_1_usage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_SystemCosts_om_opt_fuel_1_usage_nget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_1_usage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_SystemCosts_om_opt_fuel_1_usage_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_2_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemCosts_om_opt_fuel_2_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_2_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemCosts_om_opt_fuel_2_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_2_cost_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_SystemCosts_om_opt_fuel_2_cost_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_2_cost_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_SystemCosts_om_opt_fuel_2_cost_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_2_usage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_SystemCosts_om_opt_fuel_2_usage_nget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_2_usage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_SystemCosts_om_opt_fuel_2_usage_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemCosts_om_production_aget, self->data_ptr);
}

static int
SystemCosts_set_om_production(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemCosts_om_production_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production1_values(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemCosts_om_production1_values_aget, self->data_ptr);
}

static int
SystemCosts_set_om_production1_values(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemCosts_om_production1_values_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production2_values(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemCosts_om_production2_values_aget, self->data_ptr);
}

static int
SystemCosts_set_om_production2_values(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemCosts_om_production2_values_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_SystemCosts_om_production_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_production_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_SystemCosts_om_production_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_replacement_cost_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_SystemCosts_om_replacement_cost_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_replacement_cost_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_SystemCosts_om_replacement_cost_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_total_installed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_SystemCosts_total_installed_cost_nget, self->data_ptr);
}

static int
SystemCosts_set_total_installed_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_SystemCosts_total_installed_cost_nset, self->data_ptr);
}

static PyGetSetDef SystemCosts_getset[] = {
{"add_om_num_types", (getter)SystemCosts_get_add_om_num_types,(setter)SystemCosts_set_add_om_num_types,
	PyDoc_STR("*float*: Number of O and M types\n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"annual_fuel_usage", (getter)SystemCosts_get_annual_fuel_usage,(setter)SystemCosts_set_annual_fuel_usage,
	PyDoc_STR("*float*: Fuel usage (yr 1) [kWht]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"annual_fuel_usage_lifetime", (getter)SystemCosts_get_annual_fuel_usage_lifetime,(setter)SystemCosts_set_annual_fuel_usage_lifetime,
	PyDoc_STR("*sequence*: Fuel usage (lifetime) [kWht]"),
 	NULL},
{"fuelcell_annual_energy_discharged", (getter)SystemCosts_get_fuelcell_annual_energy_discharged,(setter)SystemCosts_set_fuelcell_annual_energy_discharged,
	PyDoc_STR("*sequence*: Fuel cell annual energy discharged [kWh]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_batt_capacity_cost", (getter)SystemCosts_get_om_batt_capacity_cost,(setter)SystemCosts_set_om_batt_capacity_cost,
	PyDoc_STR("*sequence*: Battery capacity-based System Costs amount [$/kWcap]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_batt_fixed_cost", (getter)SystemCosts_get_om_batt_fixed_cost,(setter)SystemCosts_set_om_batt_fixed_cost,
	PyDoc_STR("*sequence*: Battery fixed System Costs annual amount [$/year]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_batt_nameplate", (getter)SystemCosts_get_om_batt_nameplate,(setter)SystemCosts_set_om_batt_nameplate,
	PyDoc_STR("*float*: Battery capacity for System Costs values [kW]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_batt_replacement_cost", (getter)SystemCosts_get_om_batt_replacement_cost,(setter)SystemCosts_set_om_batt_replacement_cost,
	PyDoc_STR("*sequence*: Replacement cost 1 [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_batt_variable_cost", (getter)SystemCosts_get_om_batt_variable_cost,(setter)SystemCosts_set_om_batt_variable_cost,
	PyDoc_STR("*sequence*: Battery production-based System Costs amount [$/MWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_capacity", (getter)SystemCosts_get_om_capacity,(setter)SystemCosts_set_om_capacity,
	PyDoc_STR("*sequence*: Capacity-based O&M amount [$/kWcap]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_capacity_escal", (getter)SystemCosts_get_om_capacity_escal,(setter)SystemCosts_set_om_capacity_escal,
	PyDoc_STR("*float*: Capacity-based O&M escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_fixed", (getter)SystemCosts_get_om_fixed,(setter)SystemCosts_set_om_fixed,
	PyDoc_STR("*sequence*: Fixed O&M annual amount [$/year]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_fixed_escal", (getter)SystemCosts_get_om_fixed_escal,(setter)SystemCosts_set_om_fixed_escal,
	PyDoc_STR("*float*: Fixed O&M escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_fuel_cost", (getter)SystemCosts_get_om_fuel_cost,(setter)SystemCosts_set_om_fuel_cost,
	PyDoc_STR("*sequence*: Fuel cost [$/MMBtu]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_fuel_cost_escal", (getter)SystemCosts_get_om_fuel_cost_escal,(setter)SystemCosts_set_om_fuel_cost_escal,
	PyDoc_STR("*float*: Fuel cost escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_fuelcell_capacity_cost", (getter)SystemCosts_get_om_fuelcell_capacity_cost,(setter)SystemCosts_set_om_fuelcell_capacity_cost,
	PyDoc_STR("*sequence*: Fuel cell capacity-based System Costs amount [$/kWcap]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_fuelcell_fixed_cost", (getter)SystemCosts_get_om_fuelcell_fixed_cost,(setter)SystemCosts_set_om_fuelcell_fixed_cost,
	PyDoc_STR("*sequence*: Fuel cell fixed System Costs annual amount [$/year]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_fuelcell_nameplate", (getter)SystemCosts_get_om_fuelcell_nameplate,(setter)SystemCosts_set_om_fuelcell_nameplate,
	PyDoc_STR("*float*: Fuel cell capacity for System Costs values [kW]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_fuelcell_replacement_cost", (getter)SystemCosts_get_om_fuelcell_replacement_cost,(setter)SystemCosts_set_om_fuelcell_replacement_cost,
	PyDoc_STR("*sequence*: Replacement cost 2 [$/kW]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_fuelcell_variable_cost", (getter)SystemCosts_get_om_fuelcell_variable_cost,(setter)SystemCosts_set_om_fuelcell_variable_cost,
	PyDoc_STR("*sequence*: Fuel cell production-based System Costs amount [$/MWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_opt_fuel_1_cost", (getter)SystemCosts_get_om_opt_fuel_1_cost,(setter)SystemCosts_set_om_opt_fuel_1_cost,
	PyDoc_STR("*sequence*: Biomass feedstock cost [$/unit]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_opt_fuel_1_cost_escal", (getter)SystemCosts_get_om_opt_fuel_1_cost_escal,(setter)SystemCosts_set_om_opt_fuel_1_cost_escal,
	PyDoc_STR("*float*: Biomass feedstock cost escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_opt_fuel_1_usage", (getter)SystemCosts_get_om_opt_fuel_1_usage,(setter)SystemCosts_set_om_opt_fuel_1_usage,
	PyDoc_STR("*float*: Biomass feedstock usage [unit]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_opt_fuel_2_cost", (getter)SystemCosts_get_om_opt_fuel_2_cost,(setter)SystemCosts_set_om_opt_fuel_2_cost,
	PyDoc_STR("*sequence*: Coal feedstock cost [$/unit]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_opt_fuel_2_cost_escal", (getter)SystemCosts_get_om_opt_fuel_2_cost_escal,(setter)SystemCosts_set_om_opt_fuel_2_cost_escal,
	PyDoc_STR("*float*: Coal feedstock cost escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_opt_fuel_2_usage", (getter)SystemCosts_get_om_opt_fuel_2_usage,(setter)SystemCosts_set_om_opt_fuel_2_usage,
	PyDoc_STR("*float*: Coal feedstock usage [unit]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_production", (getter)SystemCosts_get_om_production,(setter)SystemCosts_set_om_production,
	PyDoc_STR("*sequence*: Production-based O&M amount [$/MWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_production1_values", (getter)SystemCosts_get_om_production1_values,(setter)SystemCosts_set_om_production1_values,
	PyDoc_STR("*sequence*: Battery production for System Costs values [kWh]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_production2_values", (getter)SystemCosts_get_om_production2_values,(setter)SystemCosts_set_om_production2_values,
	PyDoc_STR("*sequence*: Fuel cell production for System Costs values [kWh]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_production_escal", (getter)SystemCosts_get_om_production_escal,(setter)SystemCosts_set_om_production_escal,
	PyDoc_STR("*float*: Production-based O&M escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_replacement_cost_escal", (getter)SystemCosts_get_om_replacement_cost_escal,(setter)SystemCosts_set_om_replacement_cost_escal,
	PyDoc_STR("*float*: Replacement cost escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"total_installed_cost", (getter)SystemCosts_get_total_installed_cost,(setter)SystemCosts_set_total_installed_cost,
	PyDoc_STR("*float*: Installed cost [$]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``total_installed_cost``:\n\n\t - construction_financing_cost\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Equpartflip.SystemCosts",             /*tp_name*/
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
LandLease_new(SAM_Equpartflip data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "LandLease")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "LandLease")){
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
	return PySAM_double_getter(SAM_Equpartflip_LandLease_land_area_nget, self->data_ptr);
}

static int
LandLease_set_land_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_LandLease_land_area_nset, self->data_ptr);
}

static PyObject *
LandLease_get_om_land_lease(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_LandLease_om_land_lease_aget, self->data_ptr);
}

static int
LandLease_set_om_land_lease(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_LandLease_om_land_lease_aset, self->data_ptr);
}

static PyObject *
LandLease_get_om_land_lease_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_LandLease_om_land_lease_escal_nget, self->data_ptr);
}

static int
LandLease_set_om_land_lease_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_LandLease_om_land_lease_escal_nset, self->data_ptr);
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
		"Equpartflip.LandLease",             /*tp_name*/
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
TaxCreditIncentives_new(SAM_Equpartflip data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "TaxCreditIncentives")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "TaxCreditIncentives")){
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
	return PySAM_array_getter(SAM_Equpartflip_TaxCreditIncentives_itc_fed_amount_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_TaxCreditIncentives_itc_fed_amount_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_amount_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TaxCreditIncentives_itc_fed_amount_deprbas_fed_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_amount_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TaxCreditIncentives_itc_fed_amount_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_amount_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TaxCreditIncentives_itc_fed_amount_deprbas_sta_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_amount_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TaxCreditIncentives_itc_fed_amount_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_TaxCreditIncentives_itc_fed_percent_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_TaxCreditIncentives_itc_fed_percent_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TaxCreditIncentives_itc_fed_percent_deprbas_fed_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TaxCreditIncentives_itc_fed_percent_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TaxCreditIncentives_itc_fed_percent_deprbas_sta_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TaxCreditIncentives_itc_fed_percent_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_TaxCreditIncentives_itc_fed_percent_maxvalue_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_TaxCreditIncentives_itc_fed_percent_maxvalue_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_TaxCreditIncentives_itc_sta_amount_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_TaxCreditIncentives_itc_sta_amount_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_amount_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TaxCreditIncentives_itc_sta_amount_deprbas_fed_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_amount_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TaxCreditIncentives_itc_sta_amount_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_amount_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TaxCreditIncentives_itc_sta_amount_deprbas_sta_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_amount_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TaxCreditIncentives_itc_sta_amount_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_TaxCreditIncentives_itc_sta_percent_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_TaxCreditIncentives_itc_sta_percent_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TaxCreditIncentives_itc_sta_percent_deprbas_fed_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TaxCreditIncentives_itc_sta_percent_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TaxCreditIncentives_itc_sta_percent_deprbas_sta_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TaxCreditIncentives_itc_sta_percent_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_TaxCreditIncentives_itc_sta_percent_maxvalue_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_TaxCreditIncentives_itc_sta_percent_maxvalue_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_fed_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_TaxCreditIncentives_ptc_fed_amount_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_fed_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_TaxCreditIncentives_ptc_fed_amount_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_fed_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TaxCreditIncentives_ptc_fed_escal_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_fed_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TaxCreditIncentives_ptc_fed_escal_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_fed_term(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TaxCreditIncentives_ptc_fed_term_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_fed_term(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TaxCreditIncentives_ptc_fed_term_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_sta_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_TaxCreditIncentives_ptc_sta_amount_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_sta_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_TaxCreditIncentives_ptc_sta_amount_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_sta_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TaxCreditIncentives_ptc_sta_escal_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_sta_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TaxCreditIncentives_ptc_sta_escal_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_sta_term(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TaxCreditIncentives_ptc_sta_term_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_sta_term(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TaxCreditIncentives_ptc_sta_term_nset, self->data_ptr);
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
		"Equpartflip.TaxCreditIncentives",             /*tp_name*/
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
Depreciation_new(SAM_Equpartflip data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "Depreciation")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "Depreciation")){
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
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_alloc_custom_percent_nget, self->data_ptr);
}

static int
Depreciation_set_depr_alloc_custom_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_alloc_custom_percent_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_alloc_macrs_15_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_alloc_macrs_15_percent_nget, self->data_ptr);
}

static int
Depreciation_set_depr_alloc_macrs_15_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_alloc_macrs_15_percent_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_alloc_macrs_5_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_alloc_macrs_5_percent_nget, self->data_ptr);
}

static int
Depreciation_set_depr_alloc_macrs_5_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_alloc_macrs_5_percent_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_alloc_sl_15_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_alloc_sl_15_percent_nget, self->data_ptr);
}

static int
Depreciation_set_depr_alloc_sl_15_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_alloc_sl_15_percent_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_alloc_sl_20_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_alloc_sl_20_percent_nget, self->data_ptr);
}

static int
Depreciation_set_depr_alloc_sl_20_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_alloc_sl_20_percent_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_alloc_sl_39_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_alloc_sl_39_percent_nget, self->data_ptr);
}

static int
Depreciation_set_depr_alloc_sl_39_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_alloc_sl_39_percent_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_alloc_sl_5_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_alloc_sl_5_percent_nget, self->data_ptr);
}

static int
Depreciation_set_depr_alloc_sl_5_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_alloc_sl_5_percent_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_bonus_fed_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_bonus_fed_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_fed_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_bonus_fed_custom_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_fed_custom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_bonus_fed_custom_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_fed_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_bonus_fed_macrs_15_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_fed_macrs_15(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_bonus_fed_macrs_15_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_fed_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_bonus_fed_macrs_5_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_fed_macrs_5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_bonus_fed_macrs_5_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_fed_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_bonus_fed_sl_15_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_fed_sl_15(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_bonus_fed_sl_15_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_fed_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_bonus_fed_sl_20_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_fed_sl_20(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_bonus_fed_sl_20_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_fed_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_bonus_fed_sl_39_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_fed_sl_39(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_bonus_fed_sl_39_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_fed_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_bonus_fed_sl_5_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_fed_sl_5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_bonus_fed_sl_5_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_bonus_sta_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_bonus_sta_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_sta_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_bonus_sta_custom_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_sta_custom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_bonus_sta_custom_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_sta_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_bonus_sta_macrs_15_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_sta_macrs_15(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_bonus_sta_macrs_15_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_sta_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_bonus_sta_macrs_5_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_sta_macrs_5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_bonus_sta_macrs_5_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_sta_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_bonus_sta_sl_15_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_sta_sl_15(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_bonus_sta_sl_15_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_sta_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_bonus_sta_sl_20_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_sta_sl_20(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_bonus_sta_sl_20_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_sta_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_bonus_sta_sl_39_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_sta_sl_39(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_bonus_sta_sl_39_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_bonus_sta_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_bonus_sta_sl_5_nget, self->data_ptr);
}

static int
Depreciation_set_depr_bonus_sta_sl_5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_bonus_sta_sl_5_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_custom_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Depreciation_depr_custom_schedule_aget, self->data_ptr);
}

static int
Depreciation_set_depr_custom_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_Depreciation_depr_custom_schedule_aset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_fedbas_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_fedbas_method_nget, self->data_ptr);
}

static int
Depreciation_set_depr_fedbas_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_fedbas_method_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_fed_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_itc_fed_custom_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_fed_custom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_itc_fed_custom_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_fed_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_itc_fed_macrs_15_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_fed_macrs_15(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_itc_fed_macrs_15_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_fed_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_itc_fed_macrs_5_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_fed_macrs_5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_itc_fed_macrs_5_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_fed_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_itc_fed_sl_15_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_fed_sl_15(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_itc_fed_sl_15_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_fed_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_itc_fed_sl_20_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_fed_sl_20(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_itc_fed_sl_20_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_fed_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_itc_fed_sl_39_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_fed_sl_39(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_itc_fed_sl_39_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_fed_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_itc_fed_sl_5_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_fed_sl_5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_itc_fed_sl_5_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_sta_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_itc_sta_custom_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_sta_custom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_itc_sta_custom_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_sta_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_itc_sta_macrs_15_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_sta_macrs_15(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_itc_sta_macrs_15_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_sta_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_itc_sta_macrs_5_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_sta_macrs_5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_itc_sta_macrs_5_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_sta_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_itc_sta_sl_15_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_sta_sl_15(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_itc_sta_sl_15_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_sta_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_itc_sta_sl_20_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_sta_sl_20(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_itc_sta_sl_20_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_sta_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_itc_sta_sl_39_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_sta_sl_39(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_itc_sta_sl_39_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_itc_sta_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_itc_sta_sl_5_nget, self->data_ptr);
}

static int
Depreciation_set_depr_itc_sta_sl_5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_itc_sta_sl_5_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_stabas_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Depreciation_depr_stabas_method_nget, self->data_ptr);
}

static int
Depreciation_set_depr_stabas_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Depreciation_depr_stabas_method_nset, self->data_ptr);
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
		"Equpartflip.Depreciation",             /*tp_name*/
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
PaymentIncentives_new(SAM_Equpartflip data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "PaymentIncentives")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "PaymentIncentives")){
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
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_fed_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_fed_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_fed_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_fed_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_fed_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_fed_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_fed_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_fed_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_fed_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_fed_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_fed_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_fed_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_oth_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_oth_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_oth_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_oth_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_oth_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_oth_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_oth_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_oth_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_oth_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_oth_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_oth_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_oth_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_sta_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_sta_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_sta_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_sta_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_sta_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_sta_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_sta_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_sta_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_sta_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_sta_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_sta_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_sta_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_uti_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_uti_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_uti_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_uti_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_uti_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_uti_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_uti_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_uti_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_uti_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_uti_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_cbi_uti_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_cbi_uti_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_fed_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_fed_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_fed_amount_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_fed_amount_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_fed_amount_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_fed_amount_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_fed_amount_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_fed_amount_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_fed_amount_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_fed_amount_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_fed_percent_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_fed_percent_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_fed_percent_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_fed_percent_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_fed_percent_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_fed_percent_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_fed_percent_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_fed_percent_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_fed_percent_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_fed_percent_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_fed_percent_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_fed_percent_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_oth_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_oth_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_oth_amount_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_oth_amount_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_oth_amount_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_oth_amount_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_oth_amount_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_oth_amount_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_oth_amount_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_oth_amount_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_oth_percent_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_oth_percent_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_oth_percent_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_oth_percent_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_oth_percent_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_oth_percent_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_oth_percent_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_oth_percent_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_oth_percent_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_oth_percent_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_oth_percent_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_oth_percent_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_sta_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_sta_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_sta_amount_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_sta_amount_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_sta_amount_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_sta_amount_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_sta_amount_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_sta_amount_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_sta_amount_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_sta_amount_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_sta_percent_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_sta_percent_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_sta_percent_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_sta_percent_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_sta_percent_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_sta_percent_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_sta_percent_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_sta_percent_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_sta_percent_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_sta_percent_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_sta_percent_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_sta_percent_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_uti_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_uti_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_uti_amount_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_uti_amount_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_uti_amount_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_uti_amount_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_uti_amount_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_uti_amount_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_uti_amount_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_uti_amount_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_uti_percent_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_uti_percent_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_uti_percent_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_uti_percent_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_uti_percent_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_uti_percent_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_uti_percent_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_uti_percent_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_uti_percent_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_uti_percent_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_ibi_uti_percent_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_ibi_uti_percent_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_PaymentIncentives_pbi_fed_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_fed_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_pbi_fed_escal_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_fed_escal_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_pbi_fed_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_fed_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_pbi_fed_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_fed_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_term(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_pbi_fed_term_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_term(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_fed_term_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_PaymentIncentives_pbi_oth_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_oth_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_pbi_oth_escal_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_oth_escal_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_pbi_oth_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_oth_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_pbi_oth_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_oth_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_term(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_pbi_oth_term_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_term(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_oth_term_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_PaymentIncentives_pbi_sta_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_sta_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_pbi_sta_escal_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_sta_escal_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_pbi_sta_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_sta_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_pbi_sta_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_sta_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_term(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_pbi_sta_term_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_term(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_sta_term_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_PaymentIncentives_pbi_uti_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_uti_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_pbi_uti_escal_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_uti_escal_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_pbi_uti_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_uti_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_pbi_uti_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_uti_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_term(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_PaymentIncentives_pbi_uti_term_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_term(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_PaymentIncentives_pbi_uti_term_nset, self->data_ptr);
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
		"Equpartflip.PaymentIncentives",             /*tp_name*/
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
 * SystemOutput Group
 */ 

static PyTypeObject SystemOutput_Type;

static PyObject *
SystemOutput_new(SAM_Equpartflip data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "SystemOutput")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "SystemOutput")){
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
	return PySAM_array_getter(SAM_Equpartflip_SystemOutput_degradation_aget, self->data_ptr);
}

static int
SystemOutput_set_degradation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemOutput_degradation_aset, self->data_ptr);
}

static PyObject *
SystemOutput_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemOutput_gen_aget, self->data_ptr);
}

static int
SystemOutput_set_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemOutput_gen_aset, self->data_ptr);
}

static PyObject *
SystemOutput_get_gen_purchases(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_SystemOutput_gen_purchases_aget, self->data_ptr);
}

static int
SystemOutput_set_gen_purchases(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_SystemOutput_gen_purchases_aset, self->data_ptr);
}

static PyObject *
SystemOutput_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_SystemOutput_system_capacity_nget, self->data_ptr);
}

static int
SystemOutput_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_SystemOutput_system_capacity_nset, self->data_ptr);
}

static PyGetSetDef SystemOutput_getset[] = {
{"degradation", (getter)SystemOutput_get_degradation,(setter)SystemOutput_set_degradation,
	PyDoc_STR("*sequence*: Annual energy degradation\n\n**Required:**\nTrue"),
 	NULL},
{"gen", (getter)SystemOutput_get_gen,(setter)SystemOutput_set_gen,
	PyDoc_STR("*sequence*: Power generated by renewable resource [kW]\n\n**Required:**\nTrue"),
 	NULL},
{"gen_purchases", (getter)SystemOutput_get_gen_purchases,(setter)SystemOutput_set_gen_purchases,
	PyDoc_STR("*sequence*: Electricity from grid [kW]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"system_capacity", (getter)SystemOutput_get_system_capacity,(setter)SystemOutput_set_system_capacity,
	PyDoc_STR("*float*: System nameplate capacity [kW]\n\n**Constraints:**\nMIN=1e-3\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemOutput_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Equpartflip.SystemOutput",             /*tp_name*/
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
 * ElectricityRates Group
 */ 

static PyTypeObject ElectricityRates_Type;

static PyObject *
ElectricityRates_new(SAM_Equpartflip data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "ElectricityRates")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "ElectricityRates")){
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
	return PySAM_double_getter(SAM_Equpartflip_ElectricityRates_en_electricity_rates_nget, self->data_ptr);
}

static int
ElectricityRates_set_en_electricity_rates(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_ElectricityRates_en_electricity_rates_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_rate_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_ElectricityRates_rate_escalation_aget, self->data_ptr);
}

static int
ElectricityRates_set_rate_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_ElectricityRates_rate_escalation_aset, self->data_ptr);
}

static PyGetSetDef ElectricityRates_getset[] = {
{"en_electricity_rates", (getter)ElectricityRates_get_en_electricity_rates,(setter)ElectricityRates_set_en_electricity_rates,
	PyDoc_STR("*float*: Enable electricity rates for grid purchase [0/1]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"rate_escalation", (getter)ElectricityRates_get_rate_escalation,(setter)ElectricityRates_set_rate_escalation,
	PyDoc_STR("*sequence*: Annual electricity rate escalation [%/year]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ElectricityRates_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Equpartflip.ElectricityRates",             /*tp_name*/
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
 * Recapitalization Group
 */ 

static PyTypeObject Recapitalization_Type;

static PyObject *
Recapitalization_new(SAM_Equpartflip data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "Recapitalization")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "Recapitalization")){
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
	return PySAM_array_getter(SAM_Equpartflip_Recapitalization_system_lifetime_recapitalize_aget, self->data_ptr);
}

static int
Recapitalization_set_system_lifetime_recapitalize(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_Recapitalization_system_lifetime_recapitalize_aset, self->data_ptr);
}

static PyObject *
Recapitalization_get_system_recapitalization_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Recapitalization_system_recapitalization_cost_nget, self->data_ptr);
}

static int
Recapitalization_set_system_recapitalization_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Recapitalization_system_recapitalization_cost_nset, self->data_ptr);
}

static PyObject *
Recapitalization_get_system_recapitalization_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Recapitalization_system_recapitalization_escalation_nget, self->data_ptr);
}

static int
Recapitalization_set_system_recapitalization_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Recapitalization_system_recapitalization_escalation_nset, self->data_ptr);
}

static PyObject *
Recapitalization_get_system_use_recapitalization(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Recapitalization_system_use_recapitalization_nget, self->data_ptr);
}

static int
Recapitalization_set_system_use_recapitalization(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_Recapitalization_system_use_recapitalization_nset, self->data_ptr);
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
		"Equpartflip.Recapitalization",             /*tp_name*/
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
TimeOfDelivery_new(SAM_Equpartflip data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "TimeOfDelivery")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "TimeOfDelivery")){
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
TimeOfDelivery_get_dispatch_factor1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TimeOfDelivery_dispatch_factor1_nget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factor1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TimeOfDelivery_dispatch_factor1_nset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_factor2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TimeOfDelivery_dispatch_factor2_nget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factor2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TimeOfDelivery_dispatch_factor2_nset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_factor3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TimeOfDelivery_dispatch_factor3_nget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factor3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TimeOfDelivery_dispatch_factor3_nset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_factor4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TimeOfDelivery_dispatch_factor4_nget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factor4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TimeOfDelivery_dispatch_factor4_nset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_factor5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TimeOfDelivery_dispatch_factor5_nget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factor5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TimeOfDelivery_dispatch_factor5_nset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_factor6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TimeOfDelivery_dispatch_factor6_nget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factor6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TimeOfDelivery_dispatch_factor6_nset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_factor7(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TimeOfDelivery_dispatch_factor7_nget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factor7(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TimeOfDelivery_dispatch_factor7_nset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_factor8(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TimeOfDelivery_dispatch_factor8_nget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factor8(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TimeOfDelivery_dispatch_factor8_nset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_factor9(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TimeOfDelivery_dispatch_factor9_nget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factor9(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TimeOfDelivery_dispatch_factor9_nset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_factors_ts(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_TimeOfDelivery_dispatch_factors_ts_aget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factors_ts(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_TimeOfDelivery_dispatch_factors_ts_aset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Equpartflip_TimeOfDelivery_dispatch_sched_weekday_mget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Equpartflip_TimeOfDelivery_dispatch_sched_weekday_mset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Equpartflip_TimeOfDelivery_dispatch_sched_weekend_mget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Equpartflip_TimeOfDelivery_dispatch_sched_weekend_mset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_ppa_multiplier_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TimeOfDelivery_ppa_multiplier_model_nget, self->data_ptr);
}

static int
TimeOfDelivery_set_ppa_multiplier_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TimeOfDelivery_ppa_multiplier_model_nset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_system_use_lifetime_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_TimeOfDelivery_system_use_lifetime_output_nget, self->data_ptr);
}

static int
TimeOfDelivery_set_system_use_lifetime_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_TimeOfDelivery_system_use_lifetime_output_nset, self->data_ptr);
}

static PyGetSetDef TimeOfDelivery_getset[] = {
{"dispatch_factor1", (getter)TimeOfDelivery_get_dispatch_factor1,(setter)TimeOfDelivery_set_dispatch_factor1,
	PyDoc_STR("*float*: TOD factor for period 1\n\n**Required:**\nRequired if ppa_multiplier_model=0"),
 	NULL},
{"dispatch_factor2", (getter)TimeOfDelivery_get_dispatch_factor2,(setter)TimeOfDelivery_set_dispatch_factor2,
	PyDoc_STR("*float*: TOD factor for period 2\n\n**Required:**\nRequired if ppa_multiplier_model=0"),
 	NULL},
{"dispatch_factor3", (getter)TimeOfDelivery_get_dispatch_factor3,(setter)TimeOfDelivery_set_dispatch_factor3,
	PyDoc_STR("*float*: TOD factor for period 3\n\n**Required:**\nRequired if ppa_multiplier_model=0"),
 	NULL},
{"dispatch_factor4", (getter)TimeOfDelivery_get_dispatch_factor4,(setter)TimeOfDelivery_set_dispatch_factor4,
	PyDoc_STR("*float*: TOD factor for period 4\n\n**Required:**\nRequired if ppa_multiplier_model=0"),
 	NULL},
{"dispatch_factor5", (getter)TimeOfDelivery_get_dispatch_factor5,(setter)TimeOfDelivery_set_dispatch_factor5,
	PyDoc_STR("*float*: TOD factor for period 5\n\n**Required:**\nRequired if ppa_multiplier_model=0"),
 	NULL},
{"dispatch_factor6", (getter)TimeOfDelivery_get_dispatch_factor6,(setter)TimeOfDelivery_set_dispatch_factor6,
	PyDoc_STR("*float*: TOD factor for period 6\n\n**Required:**\nRequired if ppa_multiplier_model=0"),
 	NULL},
{"dispatch_factor7", (getter)TimeOfDelivery_get_dispatch_factor7,(setter)TimeOfDelivery_set_dispatch_factor7,
	PyDoc_STR("*float*: TOD factor for period 7\n\n**Required:**\nRequired if ppa_multiplier_model=0"),
 	NULL},
{"dispatch_factor8", (getter)TimeOfDelivery_get_dispatch_factor8,(setter)TimeOfDelivery_set_dispatch_factor8,
	PyDoc_STR("*float*: TOD factor for period 8\n\n**Required:**\nRequired if ppa_multiplier_model=0"),
 	NULL},
{"dispatch_factor9", (getter)TimeOfDelivery_get_dispatch_factor9,(setter)TimeOfDelivery_set_dispatch_factor9,
	PyDoc_STR("*float*: TOD factor for period 9\n\n**Required:**\nRequired if ppa_multiplier_model=0"),
 	NULL},
{"dispatch_factors_ts", (getter)TimeOfDelivery_get_dispatch_factors_ts,(setter)TimeOfDelivery_set_dispatch_factors_ts,
	PyDoc_STR("*sequence*: Dispatch payment factor array\n\n**Required:**\nRequired if ppa_multiplier_model=1"),
 	NULL},
{"dispatch_sched_weekday", (getter)TimeOfDelivery_get_dispatch_sched_weekday,(setter)TimeOfDelivery_set_dispatch_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: Diurnal weekday TOD periods [1..9]\n\n**Info:**\n12 x 24 matrix\n\n**Required:**\nRequired if ppa_multiplier_model=0"),
 	NULL},
{"dispatch_sched_weekend", (getter)TimeOfDelivery_get_dispatch_sched_weekend,(setter)TimeOfDelivery_set_dispatch_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Diurnal weekend TOD periods [1..9]\n\n**Info:**\n12 x 24 matrix\n\n**Required:**\nRequired if ppa_multiplier_model=0"),
 	NULL},
{"ppa_multiplier_model", (getter)TimeOfDelivery_get_ppa_multiplier_model,(setter)TimeOfDelivery_set_ppa_multiplier_model,
	PyDoc_STR("*float*: PPA multiplier model [0/1]\n\n**Options:**\n0=diurnal,1=timestep\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"system_use_lifetime_output", (getter)TimeOfDelivery_get_system_use_lifetime_output,(setter)TimeOfDelivery_set_system_use_lifetime_output,
	PyDoc_STR("*float*: Lifetime hourly system outputs [0/1]\n\n**Options:**\n0=hourly first year,1=hourly lifetime\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TimeOfDelivery_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Equpartflip.TimeOfDelivery",             /*tp_name*/
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
 * UtilityBill Group
 */ 

static PyTypeObject UtilityBill_Type;

static PyObject *
UtilityBill_new(SAM_Equpartflip data_ptr)
{
	PyObject* new_obj = UtilityBill_Type.tp_alloc(&UtilityBill_Type,0);

	VarGroupObject* UtilityBill_obj = (VarGroupObject*)new_obj;

	UtilityBill_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* UtilityBill methods */

static PyObject *
UtilityBill_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "UtilityBill")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
UtilityBill_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &UtilityBill_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "UtilityBill")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
UtilityBill_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &UtilityBill_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef UtilityBill_methods[] = {
		{"assign",            (PyCFunction)UtilityBill_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``UtilityBill_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)UtilityBill_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``UtilityBill_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)UtilityBill_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
UtilityBill_get_utility_bill_w_sys(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_UtilityBill_utility_bill_w_sys_aget, self->data_ptr);
}

static int
UtilityBill_set_utility_bill_w_sys(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_UtilityBill_utility_bill_w_sys_aset, self->data_ptr);
}

static PyGetSetDef UtilityBill_getset[] = {
{"utility_bill_w_sys", (getter)UtilityBill_get_utility_bill_w_sys,(setter)UtilityBill_set_utility_bill_w_sys,
	PyDoc_STR("*sequence*: Electricity bill with system [$]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject UtilityBill_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Equpartflip.UtilityBill",             /*tp_name*/
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
		UtilityBill_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		UtilityBill_getset,          /*tp_getset*/
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
ConstructionFinancing_new(SAM_Equpartflip data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "ConstructionFinancing")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "ConstructionFinancing")){
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
	return PySAM_double_getter(SAM_Equpartflip_ConstructionFinancing_construction_financing_cost_nget, self->data_ptr);
}

static int
ConstructionFinancing_set_construction_financing_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_ConstructionFinancing_construction_financing_cost_nset, self->data_ptr);
}

static PyGetSetDef ConstructionFinancing_getset[] = {
{"construction_financing_cost", (getter)ConstructionFinancing_get_construction_financing_cost,(setter)ConstructionFinancing_set_construction_financing_cost,
	PyDoc_STR("*float*: Construction financing total [$]\n\n**Required:**\nTrue\n\nThe value of ``construction_financing_cost`` depends on the following variables:\n\n\t - total_installed_cost\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ConstructionFinancing_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Equpartflip.ConstructionFinancing",             /*tp_name*/
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
 * OtherCapitalCosts Group
 */ 

static PyTypeObject OtherCapitalCosts_Type;

static PyObject *
OtherCapitalCosts_new(SAM_Equpartflip data_ptr)
{
	PyObject* new_obj = OtherCapitalCosts_Type.tp_alloc(&OtherCapitalCosts_Type,0);

	VarGroupObject* OtherCapitalCosts_obj = (VarGroupObject*)new_obj;

	OtherCapitalCosts_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* OtherCapitalCosts methods */

static PyObject *
OtherCapitalCosts_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "OtherCapitalCosts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
OtherCapitalCosts_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &OtherCapitalCosts_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "OtherCapitalCosts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
OtherCapitalCosts_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &OtherCapitalCosts_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef OtherCapitalCosts_methods[] = {
		{"assign",            (PyCFunction)OtherCapitalCosts_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``OtherCapitalCosts_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)OtherCapitalCosts_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``OtherCapitalCosts_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)OtherCapitalCosts_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
OtherCapitalCosts_get_cost_dev_fee_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_OtherCapitalCosts_cost_dev_fee_percent_nget, self->data_ptr);
}

static int
OtherCapitalCosts_set_cost_dev_fee_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_OtherCapitalCosts_cost_dev_fee_percent_nset, self->data_ptr);
}

static PyObject *
OtherCapitalCosts_get_cost_equity_closing(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_OtherCapitalCosts_cost_equity_closing_nget, self->data_ptr);
}

static int
OtherCapitalCosts_set_cost_equity_closing(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_OtherCapitalCosts_cost_equity_closing_nset, self->data_ptr);
}

static PyObject *
OtherCapitalCosts_get_cost_other_financing(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_OtherCapitalCosts_cost_other_financing_nget, self->data_ptr);
}

static int
OtherCapitalCosts_set_cost_other_financing(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_OtherCapitalCosts_cost_other_financing_nset, self->data_ptr);
}

static PyObject *
OtherCapitalCosts_get_months_receivables_reserve(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_OtherCapitalCosts_months_receivables_reserve_nget, self->data_ptr);
}

static int
OtherCapitalCosts_set_months_receivables_reserve(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_OtherCapitalCosts_months_receivables_reserve_nset, self->data_ptr);
}

static PyObject *
OtherCapitalCosts_get_months_working_reserve(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_OtherCapitalCosts_months_working_reserve_nget, self->data_ptr);
}

static int
OtherCapitalCosts_set_months_working_reserve(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_OtherCapitalCosts_months_working_reserve_nset, self->data_ptr);
}

static PyGetSetDef OtherCapitalCosts_getset[] = {
{"cost_dev_fee_percent", (getter)OtherCapitalCosts_get_cost_dev_fee_percent,(setter)OtherCapitalCosts_set_cost_dev_fee_percent,
	PyDoc_STR("*float*: Development fee (% pre-financing cost) [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 3 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cost_equity_closing", (getter)OtherCapitalCosts_get_cost_equity_closing,(setter)OtherCapitalCosts_set_cost_equity_closing,
	PyDoc_STR("*float*: Equity closing cost [$]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 100000 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cost_other_financing", (getter)OtherCapitalCosts_get_cost_other_financing,(setter)OtherCapitalCosts_set_cost_other_financing,
	PyDoc_STR("*float*:  [$]\n\n**Info:**\nOther financing cost\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 150000 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"months_receivables_reserve", (getter)OtherCapitalCosts_get_months_receivables_reserve,(setter)OtherCapitalCosts_set_months_receivables_reserve,
	PyDoc_STR("*float*: Receivables reserve months of PPA revenue [months]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"months_working_reserve", (getter)OtherCapitalCosts_get_months_working_reserve,(setter)OtherCapitalCosts_set_months_working_reserve,
	PyDoc_STR("*float*: Working capital reserve months of operating costs [months]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 6 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject OtherCapitalCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Equpartflip.OtherCapitalCosts",             /*tp_name*/
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
		OtherCapitalCosts_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		OtherCapitalCosts_getset,          /*tp_getset*/
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
 * IRRTargets Group
 */ 

static PyTypeObject IRRTargets_Type;

static PyObject *
IRRTargets_new(SAM_Equpartflip data_ptr)
{
	PyObject* new_obj = IRRTargets_Type.tp_alloc(&IRRTargets_Type,0);

	VarGroupObject* IRRTargets_obj = (VarGroupObject*)new_obj;

	IRRTargets_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* IRRTargets methods */

static PyObject *
IRRTargets_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "IRRTargets")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
IRRTargets_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &IRRTargets_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "IRRTargets")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
IRRTargets_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &IRRTargets_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef IRRTargets_methods[] = {
		{"assign",            (PyCFunction)IRRTargets_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``IRRTargets_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)IRRTargets_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``IRRTargets_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)IRRTargets_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
IRRTargets_get_flip_target_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_IRRTargets_flip_target_percent_nget, self->data_ptr);
}

static int
IRRTargets_set_flip_target_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_IRRTargets_flip_target_percent_nset, self->data_ptr);
}

static PyObject *
IRRTargets_get_flip_target_year(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_IRRTargets_flip_target_year_nget, self->data_ptr);
}

static int
IRRTargets_set_flip_target_year(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_IRRTargets_flip_target_year_nset, self->data_ptr);
}

static PyObject *
IRRTargets_get_tax_investor_equity_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_IRRTargets_tax_investor_equity_percent_nget, self->data_ptr);
}

static int
IRRTargets_set_tax_investor_equity_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_IRRTargets_tax_investor_equity_percent_nset, self->data_ptr);
}

static PyObject *
IRRTargets_get_tax_investor_postflip_cash_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_IRRTargets_tax_investor_postflip_cash_percent_nget, self->data_ptr);
}

static int
IRRTargets_set_tax_investor_postflip_cash_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_IRRTargets_tax_investor_postflip_cash_percent_nset, self->data_ptr);
}

static PyObject *
IRRTargets_get_tax_investor_postflip_tax_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_IRRTargets_tax_investor_postflip_tax_percent_nget, self->data_ptr);
}

static int
IRRTargets_set_tax_investor_postflip_tax_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_IRRTargets_tax_investor_postflip_tax_percent_nset, self->data_ptr);
}

static PyObject *
IRRTargets_get_tax_investor_preflip_cash_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_IRRTargets_tax_investor_preflip_cash_percent_nget, self->data_ptr);
}

static int
IRRTargets_set_tax_investor_preflip_cash_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_IRRTargets_tax_investor_preflip_cash_percent_nset, self->data_ptr);
}

static PyObject *
IRRTargets_get_tax_investor_preflip_tax_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_IRRTargets_tax_investor_preflip_tax_percent_nget, self->data_ptr);
}

static int
IRRTargets_set_tax_investor_preflip_tax_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_IRRTargets_tax_investor_preflip_tax_percent_nset, self->data_ptr);
}

static PyGetSetDef IRRTargets_getset[] = {
{"flip_target_percent", (getter)IRRTargets_get_flip_target_percent,(setter)IRRTargets_set_flip_target_percent,
	PyDoc_STR("*float*: Investor percent of project benefit [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 11 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"flip_target_year", (getter)IRRTargets_get_flip_target_year,(setter)IRRTargets_set_flip_target_year,
	PyDoc_STR("*float*: Target flip year\n\n**Constraints:**\nMIN=1\n\n**Required:**\nFalse. Automatically set to 11 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"tax_investor_equity_percent", (getter)IRRTargets_get_tax_investor_equity_percent,(setter)IRRTargets_set_tax_investor_equity_percent,
	PyDoc_STR("*float*: Investor equity [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 98 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"tax_investor_postflip_cash_percent", (getter)IRRTargets_get_tax_investor_postflip_cash_percent,(setter)IRRTargets_set_tax_investor_postflip_cash_percent,
	PyDoc_STR("*float*: Investor post-flip cash  [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 15 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"tax_investor_postflip_tax_percent", (getter)IRRTargets_get_tax_investor_postflip_tax_percent,(setter)IRRTargets_set_tax_investor_postflip_tax_percent,
	PyDoc_STR("*float*: Investor post-flip tax benefit  [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 15 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"tax_investor_preflip_cash_percent", (getter)IRRTargets_get_tax_investor_preflip_cash_percent,(setter)IRRTargets_set_tax_investor_preflip_cash_percent,
	PyDoc_STR("*float*: Investor pre-flip cash  [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 98 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"tax_investor_preflip_tax_percent", (getter)IRRTargets_get_tax_investor_preflip_tax_percent,(setter)IRRTargets_set_tax_investor_preflip_tax_percent,
	PyDoc_STR("*float*: Investor pre-flip tax benefit  [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 98 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject IRRTargets_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Equpartflip.IRRTargets",             /*tp_name*/
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
		IRRTargets_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		IRRTargets_getset,          /*tp_getset*/
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
 * DeveloperCapitalRecovery Group
 */ 

static PyTypeObject DeveloperCapitalRecovery_Type;

static PyObject *
DeveloperCapitalRecovery_new(SAM_Equpartflip data_ptr)
{
	PyObject* new_obj = DeveloperCapitalRecovery_Type.tp_alloc(&DeveloperCapitalRecovery_Type,0);

	VarGroupObject* DeveloperCapitalRecovery_obj = (VarGroupObject*)new_obj;

	DeveloperCapitalRecovery_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* DeveloperCapitalRecovery methods */

static PyObject *
DeveloperCapitalRecovery_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "DeveloperCapitalRecovery")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
DeveloperCapitalRecovery_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &DeveloperCapitalRecovery_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "DeveloperCapitalRecovery")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
DeveloperCapitalRecovery_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &DeveloperCapitalRecovery_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef DeveloperCapitalRecovery_methods[] = {
		{"assign",            (PyCFunction)DeveloperCapitalRecovery_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``DeveloperCapitalRecovery_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)DeveloperCapitalRecovery_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``DeveloperCapitalRecovery_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)DeveloperCapitalRecovery_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
DeveloperCapitalRecovery_get_sponsor_cap_recovery_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_DeveloperCapitalRecovery_sponsor_cap_recovery_mode_nget, self->data_ptr);
}

static int
DeveloperCapitalRecovery_set_sponsor_cap_recovery_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_DeveloperCapitalRecovery_sponsor_cap_recovery_mode_nset, self->data_ptr);
}

static PyObject *
DeveloperCapitalRecovery_get_sponsor_cap_recovery_year(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_DeveloperCapitalRecovery_sponsor_cap_recovery_year_nget, self->data_ptr);
}

static int
DeveloperCapitalRecovery_set_sponsor_cap_recovery_year(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_DeveloperCapitalRecovery_sponsor_cap_recovery_year_nset, self->data_ptr);
}

static PyGetSetDef DeveloperCapitalRecovery_getset[] = {
{"sponsor_cap_recovery_mode", (getter)DeveloperCapitalRecovery_get_sponsor_cap_recovery_mode,(setter)DeveloperCapitalRecovery_set_sponsor_cap_recovery_mode,
	PyDoc_STR("*float*: Developer Capital Recovery\n\n**Options:**\n0=Time, 1=Full Capital Recovery\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"sponsor_cap_recovery_year", (getter)DeveloperCapitalRecovery_get_sponsor_cap_recovery_year,(setter)DeveloperCapitalRecovery_set_sponsor_cap_recovery_year,
	PyDoc_STR("*float*: Duration (in years) [years]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nFalse. Automatically set to 3 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject DeveloperCapitalRecovery_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Equpartflip.DeveloperCapitalRecovery",             /*tp_name*/
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
		DeveloperCapitalRecovery_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		DeveloperCapitalRecovery_getset,          /*tp_getset*/
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
LCOS_new(SAM_Equpartflip data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "LCOS")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "LCOS")){
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
	return PySAM_array_getter(SAM_Equpartflip_LCOS_batt_annual_charge_energy_aget, self->data_ptr);
}

static int
LCOS_set_batt_annual_charge_energy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_LCOS_batt_annual_charge_energy_aset, self->data_ptr);
}

static PyObject *
LCOS_get_batt_annual_charge_from_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_LCOS_batt_annual_charge_from_system_aget, self->data_ptr);
}

static int
LCOS_set_batt_annual_charge_from_system(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_LCOS_batt_annual_charge_from_system_aset, self->data_ptr);
}

static PyObject *
LCOS_get_batt_annual_discharge_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_LCOS_batt_annual_discharge_energy_aget, self->data_ptr);
}

static int
LCOS_set_batt_annual_discharge_energy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_LCOS_batt_annual_discharge_energy_aset, self->data_ptr);
}

static PyObject *
LCOS_get_batt_capacity_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_LCOS_batt_capacity_percent_aget, self->data_ptr);
}

static int
LCOS_set_batt_capacity_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_LCOS_batt_capacity_percent_aset, self->data_ptr);
}

static PyObject *
LCOS_get_batt_salvage_percentage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_LCOS_batt_salvage_percentage_nget, self->data_ptr);
}

static int
LCOS_set_batt_salvage_percentage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_LCOS_batt_salvage_percentage_nset, self->data_ptr);
}

static PyObject *
LCOS_get_battery_total_cost_lcos(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_LCOS_battery_total_cost_lcos_nget, self->data_ptr);
}

static int
LCOS_set_battery_total_cost_lcos(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_LCOS_battery_total_cost_lcos_nset, self->data_ptr);
}

static PyObject *
LCOS_get_charge_w_sys_ec_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Equpartflip_LCOS_charge_w_sys_ec_ym_mget, self->data_ptr);
}

static int
LCOS_set_charge_w_sys_ec_ym(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Equpartflip_LCOS_charge_w_sys_ec_ym_mset, self->data_ptr);
}

static PyObject *
LCOS_get_grid_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_LCOS_grid_to_batt_aget, self->data_ptr);
}

static int
LCOS_set_grid_to_batt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_LCOS_grid_to_batt_aset, self->data_ptr);
}

static PyObject *
LCOS_get_monthly_batt_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_LCOS_monthly_batt_to_grid_aget, self->data_ptr);
}

static int
LCOS_set_monthly_batt_to_grid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_LCOS_monthly_batt_to_grid_aset, self->data_ptr);
}

static PyObject *
LCOS_get_monthly_grid_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_LCOS_monthly_grid_to_batt_aget, self->data_ptr);
}

static int
LCOS_set_monthly_grid_to_batt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_LCOS_monthly_grid_to_batt_aset, self->data_ptr);
}

static PyObject *
LCOS_get_monthly_grid_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_LCOS_monthly_grid_to_load_aget, self->data_ptr);
}

static int
LCOS_set_monthly_grid_to_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_LCOS_monthly_grid_to_load_aset, self->data_ptr);
}

static PyObject *
LCOS_get_monthly_system_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_LCOS_monthly_system_to_grid_aget, self->data_ptr);
}

static int
LCOS_set_monthly_system_to_grid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_LCOS_monthly_system_to_grid_aset, self->data_ptr);
}

static PyObject *
LCOS_get_true_up_credits_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Equpartflip_LCOS_true_up_credits_ym_mget, self->data_ptr);
}

static int
LCOS_set_true_up_credits_ym(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Equpartflip_LCOS_true_up_credits_ym_mset, self->data_ptr);
}

static PyObject *
LCOS_get_year1_monthly_ec_charge_gross_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_LCOS_year1_monthly_ec_charge_gross_with_system_aget, self->data_ptr);
}

static int
LCOS_set_year1_monthly_ec_charge_gross_with_system(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_LCOS_year1_monthly_ec_charge_gross_with_system_aset, self->data_ptr);
}

static PyObject *
LCOS_get_year1_monthly_ec_charge_with_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_LCOS_year1_monthly_ec_charge_with_system_aget, self->data_ptr);
}

static int
LCOS_set_year1_monthly_ec_charge_with_system(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_LCOS_year1_monthly_ec_charge_with_system_aset, self->data_ptr);
}

static PyObject *
LCOS_get_year1_monthly_electricity_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_LCOS_year1_monthly_electricity_to_grid_aget, self->data_ptr);
}

static int
LCOS_set_year1_monthly_electricity_to_grid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_LCOS_year1_monthly_electricity_to_grid_aset, self->data_ptr);
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
	PyDoc_STR("*float*: Battery total investment cost [$]"),
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
		"Equpartflip.LCOS",             /*tp_name*/
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
 * ChargesByMonth Group
 */ 

static PyTypeObject ChargesByMonth_Type;

static PyObject *
ChargesByMonth_new(SAM_Equpartflip data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "ChargesByMonth")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "ChargesByMonth")){
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
ChargesByMonth_get_net_billing_credits_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Equpartflip_ChargesByMonth_net_billing_credits_ym_mget, self->data_ptr);
}

static int
ChargesByMonth_set_net_billing_credits_ym(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Equpartflip_ChargesByMonth_net_billing_credits_ym_mset, self->data_ptr);
}

static PyObject *
ChargesByMonth_get_nm_dollars_applied_ym(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Equpartflip_ChargesByMonth_nm_dollars_applied_ym_mget, self->data_ptr);
}

static int
ChargesByMonth_set_nm_dollars_applied_ym(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Equpartflip_ChargesByMonth_nm_dollars_applied_ym_mset, self->data_ptr);
}

static PyGetSetDef ChargesByMonth_getset[] = {
{"net_billing_credits_ym", (getter)ChargesByMonth_get_net_billing_credits_ym,(setter)ChargesByMonth_set_net_billing_credits_ym,
	PyDoc_STR("*sequence[sequence]*: Net billing credit [$]"),
 	NULL},
{"nm_dollars_applied_ym", (getter)ChargesByMonth_get_nm_dollars_applied_ym,(setter)ChargesByMonth_set_nm_dollars_applied_ym,
	PyDoc_STR("*sequence[sequence]*: Net metering credit [$]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ChargesByMonth_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Equpartflip.ChargesByMonth",             /*tp_name*/
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
 * BatterySystem Group
 */ 

static PyTypeObject BatterySystem_Type;

static PyObject *
BatterySystem_new(SAM_Equpartflip data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "BatterySystem")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "BatterySystem")){
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
	return PySAM_array_getter(SAM_Equpartflip_BatterySystem_batt_bank_replacement_aget, self->data_ptr);
}

static int
BatterySystem_set_batt_bank_replacement(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_BatterySystem_batt_bank_replacement_aset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_computed_bank_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_BatterySystem_batt_computed_bank_capacity_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_computed_bank_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_BatterySystem_batt_computed_bank_capacity_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_replacement_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_BatterySystem_batt_replacement_option_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_replacement_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_BatterySystem_batt_replacement_option_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_replacement_schedule_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_BatterySystem_batt_replacement_schedule_percent_aget, self->data_ptr);
}

static int
BatterySystem_set_batt_replacement_schedule_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Equpartflip_BatterySystem_batt_replacement_schedule_percent_aset, self->data_ptr);
}

static PyObject *
BatterySystem_get_battery_per_kWh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_BatterySystem_battery_per_kWh_nget, self->data_ptr);
}

static int
BatterySystem_set_battery_per_kWh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_BatterySystem_battery_per_kWh_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_en_batt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_BatterySystem_en_batt_nget, self->data_ptr);
}

static int
BatterySystem_set_en_batt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_BatterySystem_en_batt_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_en_standalone_batt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_BatterySystem_en_standalone_batt_nget, self->data_ptr);
}

static int
BatterySystem_set_en_standalone_batt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_BatterySystem_en_standalone_batt_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_en_wave_batt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_BatterySystem_en_wave_batt_nget, self->data_ptr);
}

static int
BatterySystem_set_en_wave_batt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Equpartflip_BatterySystem_en_wave_batt_nset, self->data_ptr);
}

static PyGetSetDef BatterySystem_getset[] = {
{"batt_bank_replacement", (getter)BatterySystem_get_batt_bank_replacement,(setter)BatterySystem_set_batt_bank_replacement,
	PyDoc_STR("*sequence*: Battery bank replacements per year [number/year]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"batt_computed_bank_capacity", (getter)BatterySystem_get_batt_computed_bank_capacity,(setter)BatterySystem_set_batt_computed_bank_capacity,
	PyDoc_STR("*float*: Battery bank capacity [kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_replacement_option", (getter)BatterySystem_get_batt_replacement_option,(setter)BatterySystem_set_batt_replacement_option,
	PyDoc_STR("*float*: Enable battery replacement? [0=none,1=capacity based,2=user schedule]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_replacement_schedule_percent", (getter)BatterySystem_get_batt_replacement_schedule_percent,(setter)BatterySystem_set_batt_replacement_schedule_percent,
	PyDoc_STR("*sequence*: Percentage of battery capacity to replace in each year [%]\n\n**Options:**\nlength <= analysis_period"),
 	NULL},
{"battery_per_kWh", (getter)BatterySystem_get_battery_per_kWh,(setter)BatterySystem_set_battery_per_kWh,
	PyDoc_STR("*float*: Battery cost [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
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
		"Equpartflip.BatterySystem",             /*tp_name*/
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
 * Outputs Group
 */ 

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Equpartflip data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Equpartflip", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Equpartflip", "Outputs")){
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
	return PySAM_double_getter(SAM_Equpartflip_Outputs_adjusted_installed_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_analysis_period_irr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_analysis_period_irr_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_fedtax_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_cbi_fedtax_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_statax_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_cbi_statax_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_cbi_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_cbi_total_fed_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_oth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_cbi_total_oth_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_cbi_total_sta_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_uti(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_cbi_total_uti_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_annual_cost_lcos(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_annual_cost_lcos_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_annual_costs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_annual_costs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_annual_discharge_lcos(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_annual_discharge_lcos_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_battery_replacement_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_battery_replacement_cost_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_battery_replacement_cost_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_battery_replacement_cost_schedule_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_charging_cost_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_charging_cost_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_charging_cost_grid_month(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_charging_cost_grid_month_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_charging_cost_pv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_charging_cost_pv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_disbursement_equip1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_disbursement_equip1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_disbursement_equip2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_disbursement_equip2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_disbursement_equip3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_disbursement_equip3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_disbursement_om(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_disbursement_om_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_disbursement_receivables(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_disbursement_receivables_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_ebitda(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_ebitda_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_effective_tax_frac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_effective_tax_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_dispatch1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_dispatch2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_dispatch3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_dispatch4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_dispatch5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_dispatch6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_dispatch7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_dispatch8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_dispatch9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_monthly_firstyear_TOD1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_monthly_firstyear_TOD2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_monthly_firstyear_TOD3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_monthly_firstyear_TOD4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_monthly_firstyear_TOD5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_monthly_firstyear_TOD6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_monthly_firstyear_TOD7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_monthly_firstyear_TOD8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_monthly_firstyear_TOD9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_net_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_purchases(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_purchases_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_sales(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_sales_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_without_battery(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_energy_without_battery_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_custom(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_feddepr_custom_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_feddepr_macrs_15_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_feddepr_macrs_5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_me1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_feddepr_me1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_me2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_feddepr_me2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_me3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_feddepr_me3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_feddepr_sl_15_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_feddepr_sl_20_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_feddepr_sl_39_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_feddepr_sl_5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_feddepr_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_federal_tax_frac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_federal_tax_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fedtax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_fedtax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fedtax_income_prior_incentives(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_fedtax_income_prior_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fedtax_income_with_incentives(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_fedtax_income_with_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fedtax_taxable_incentives(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_fedtax_taxable_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_funding_equip1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_funding_equip1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_funding_equip2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_funding_equip2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_funding_equip3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_funding_equip3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_funding_om(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_funding_om_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_funding_receivables(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_funding_receivables_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_insurance_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_insurance_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_fed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_itc_fed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_fed_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_itc_fed_amount_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_fed_percent_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_itc_fed_percent_amount_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_sta(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_itc_sta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_sta_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_itc_sta_amount_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_sta_percent_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_itc_sta_percent_amount_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_itc_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_land_lease_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_land_lease_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_length(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_cf_length_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_net_salvage_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_net_salvage_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_batt_capacity_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_om_batt_capacity_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_batt_fixed_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_om_batt_fixed_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_capacity1_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_om_capacity1_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_capacity2_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_om_capacity2_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_capacity_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_om_capacity_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_fixed1_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_om_fixed1_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_fixed2_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_om_fixed2_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_fixed_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_om_fixed_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_fuel_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_om_fuel_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_opt_fuel_1_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_om_opt_fuel_1_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_opt_fuel_2_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_om_opt_fuel_2_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_production1_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_om_production1_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_production2_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_om_production2_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_production_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_om_production_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_operating_expenses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_operating_expenses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_fedtax_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_pbi_fedtax_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_statax_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_pbi_statax_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_pbi_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_fed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_pbi_total_fed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_oth(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_pbi_total_oth_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_sta(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_pbi_total_sta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_uti(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_pbi_total_uti_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_ppa_price(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_ppa_price_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pretax_cashflow(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_pretax_cashflow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_financing_activities(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_financing_activities_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_investing_activities(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_investing_activities_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_me1cs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_me1cs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_me1ra(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_me1ra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_me2cs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_me2cs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_me2ra(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_me2ra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_me3cs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_me3cs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_me3ra(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_me3ra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_mecs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_mecs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_operating_activities(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_operating_activities_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_ra(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_ra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_receivablesra(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_receivablesra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_return_aftertax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_return_aftertax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_return_aftertax_cash(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_return_aftertax_cash_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_return_aftertax_irr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_return_aftertax_irr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_return_aftertax_npv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_return_aftertax_npv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_return_pretax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_return_pretax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_return_pretax_irr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_return_pretax_irr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_return_pretax_npv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_return_pretax_npv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_project_wcra(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_project_wcra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_property_tax_assessed_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_property_tax_assessed_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_property_tax_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_property_tax_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_ptc_fed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_ptc_fed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_ptc_sta(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_ptc_sta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_ptc_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_ptc_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_recapitalization(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_recapitalization_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_equip1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_reserve_equip1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_equip2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_reserve_equip2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_equip3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_reserve_equip3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_interest(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_reserve_interest_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_om(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_reserve_om_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_receivables(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_reserve_receivables_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_reserve_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_dispatch1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_dispatch2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_dispatch3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_dispatch4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_dispatch5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_dispatch6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_dispatch7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_dispatch8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_dispatch9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_monthly_firstyear_TOD1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_monthly_firstyear_TOD2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_monthly_firstyear_TOD3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_monthly_firstyear_TOD4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_monthly_firstyear_TOD5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_monthly_firstyear_TOD6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_monthly_firstyear_TOD7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_monthly_firstyear_TOD8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_monthly_firstyear_TOD9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_revenue_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_salvage_cost_lcos(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_salvage_cost_lcos_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_aftertax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_sponsor_aftertax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_aftertax_cash(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_sponsor_aftertax_cash_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_aftertax_irr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_sponsor_aftertax_irr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_aftertax_itc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_sponsor_aftertax_itc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_aftertax_npv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_sponsor_aftertax_npv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_aftertax_ptc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_sponsor_aftertax_ptc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_aftertax_tax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_sponsor_aftertax_tax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_capital_recovery_balance(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_sponsor_capital_recovery_balance_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_capital_recovery_cash(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_sponsor_capital_recovery_cash_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_pretax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_sponsor_pretax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_pretax_cash_during_recovery(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_sponsor_pretax_cash_during_recovery_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_pretax_cash_post_recovery(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_sponsor_pretax_cash_post_recovery_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_pretax_irr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_sponsor_pretax_irr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_pretax_npv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_sponsor_pretax_npv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_custom(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_stadepr_custom_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_stadepr_macrs_15_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_stadepr_macrs_5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_me1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_stadepr_me1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_me2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_stadepr_me2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_me3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_stadepr_me3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_stadepr_sl_15_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_stadepr_sl_20_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_stadepr_sl_39_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_stadepr_sl_5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_stadepr_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_statax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_statax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_statax_income_prior_incentives(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_statax_income_prior_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_statax_income_with_incentives(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_statax_income_with_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_statax_taxable_incentives(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_statax_taxable_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_state_tax_frac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_state_tax_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_aftertax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_tax_investor_aftertax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_aftertax_cash(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_tax_investor_aftertax_cash_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_aftertax_irr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_tax_investor_aftertax_irr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_aftertax_itc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_tax_investor_aftertax_itc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_aftertax_max_irr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_tax_investor_aftertax_max_irr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_aftertax_npv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_tax_investor_aftertax_npv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_aftertax_ptc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_tax_investor_aftertax_ptc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_aftertax_tax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_tax_investor_aftertax_tax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_pretax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_tax_investor_pretax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_pretax_irr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_tax_investor_pretax_irr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_pretax_npv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_tax_investor_pretax_npv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_total_revenue(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_total_revenue_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_util_escal_rate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_util_escal_rate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_utility_bill(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_cf_utility_bill_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cost_financing(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_cost_financing_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cost_installed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_cost_installed_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cost_installedperwatt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_cost_installedperwatt_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cost_prefinancing(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_cost_prefinancing_nget, self->data_ptr);
}

static PyObject *
Outputs_get_debt_fraction(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_debt_fraction_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_alloc_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_alloc_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_alloc_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_none(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_alloc_none_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_none_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_alloc_none_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_alloc_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_alloc_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_alloc_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_alloc_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_alloc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_after_itc_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_after_itc_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_after_itc_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_after_itc_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_after_itc_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_after_itc_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_after_itc_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_after_itc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_cbi_reduc_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_cbi_reduc_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_cbi_reduc_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_cbi_reduc_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_cbi_reduc_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_cbi_reduc_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_cbi_reduc_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_cbi_reduc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_first_year_bonus_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_first_year_bonus_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_first_year_bonus_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_first_year_bonus_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_first_year_bonus_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_first_year_bonus_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_first_year_bonus_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_first_year_bonus_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_fixed_amount_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_fixed_amount_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_fixed_amount_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_fixed_amount_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_fixed_amount_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_fixed_amount_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_fixed_amount_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_fixed_amount_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_ibi_reduc_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_ibi_reduc_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_ibi_reduc_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_ibi_reduc_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_ibi_reduc_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_ibi_reduc_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_ibi_reduc_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_ibi_reduc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_itc_fed_reduction_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_itc_fed_reduction_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_itc_fed_reduction_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_itc_fed_reduction_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_itc_fed_reduction_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_itc_fed_reduction_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_itc_fed_reduction_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_itc_fed_reduction_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_itc_sta_reduction_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_itc_sta_reduction_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_itc_sta_reduction_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_itc_sta_reduction_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_itc_sta_reduction_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_itc_sta_reduction_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_itc_sta_reduction_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_itc_sta_reduction_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_amount_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_amount_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_amount_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_amount_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_amount_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_amount_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_amount_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_amount_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_qual_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_qual_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_qual_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_qual_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_qual_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_qual_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_qual_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_qual_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_percent_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_prior_itc_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_prior_itc_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_prior_itc_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_prior_itc_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_prior_itc_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_prior_itc_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_prior_itc_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_prior_itc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_fedbas_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_after_itc_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_after_itc_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_after_itc_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_after_itc_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_after_itc_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_after_itc_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_after_itc_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_after_itc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_cbi_reduc_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_cbi_reduc_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_cbi_reduc_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_cbi_reduc_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_cbi_reduc_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_cbi_reduc_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_cbi_reduc_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_cbi_reduc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_first_year_bonus_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_first_year_bonus_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_first_year_bonus_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_first_year_bonus_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_first_year_bonus_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_first_year_bonus_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_first_year_bonus_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_first_year_bonus_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_fixed_amount_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_fixed_amount_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_fixed_amount_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_fixed_amount_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_fixed_amount_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_fixed_amount_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_fixed_amount_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_fixed_amount_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_ibi_reduc_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_ibi_reduc_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_ibi_reduc_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_ibi_reduc_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_ibi_reduc_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_ibi_reduc_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_ibi_reduc_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_ibi_reduc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_itc_fed_reduction_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_itc_fed_reduction_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_itc_fed_reduction_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_itc_fed_reduction_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_itc_fed_reduction_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_itc_fed_reduction_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_itc_fed_reduction_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_itc_fed_reduction_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_itc_sta_reduction_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_itc_sta_reduction_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_itc_sta_reduction_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_itc_sta_reduction_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_itc_sta_reduction_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_itc_sta_reduction_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_itc_sta_reduction_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_itc_sta_reduction_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_amount_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_amount_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_amount_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_amount_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_amount_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_amount_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_amount_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_amount_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_qual_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_qual_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_qual_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_qual_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_qual_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_qual_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_qual_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_qual_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_percent_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_prior_itc_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_prior_itc_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_prior_itc_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_prior_itc_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_prior_itc_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_prior_itc_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_prior_itc_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_prior_itc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_depr_stabas_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_effective_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_effective_tax_rate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_energy_dispatch1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_energy_dispatch2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_energy_dispatch3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_energy_dispatch4_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_energy_dispatch5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_energy_dispatch6_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch7(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_energy_dispatch7_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch8(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_energy_dispatch8_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch9(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_energy_dispatch9_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_energy_price1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_energy_price2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_energy_price3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_energy_price4_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_energy_price5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_energy_price6_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price7(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_energy_price7_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price8(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_energy_price8_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price9(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_energy_price9_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_revenue_dispatch1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_revenue_dispatch2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_revenue_dispatch3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_revenue_dispatch4_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_revenue_dispatch5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_revenue_dispatch6_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch7(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_revenue_dispatch7_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch8(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_revenue_dispatch8_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch9(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_firstyear_revenue_dispatch9_nget, self->data_ptr);
}

static PyObject *
Outputs_get_flip_actual_irr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_flip_actual_irr_nget, self->data_ptr);
}

static PyObject *
Outputs_get_flip_actual_year(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_flip_actual_year_nget, self->data_ptr);
}

static PyObject *
Outputs_get_flip_target_irr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_flip_target_irr_nget, self->data_ptr);
}

static PyObject *
Outputs_get_flip_target_year(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_flip_target_year_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_fedtax_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_ibi_fedtax_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_statax_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_ibi_statax_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_ibi_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_ibi_total_fed_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_oth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_ibi_total_oth_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_ibi_total_sta_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_uti(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_ibi_total_uti_nget, self->data_ptr);
}

static PyObject *
Outputs_get_issuance_of_equity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_issuance_of_equity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_fed_fixed_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_fed_fixed_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_fed_fixed_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_fed_fixed_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_fed_fixed_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_fed_fixed_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_fed_fixed_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_fed_fixed_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_fed_percent_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_fed_percent_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_fed_percent_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_fed_percent_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_fed_percent_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_fed_percent_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_fed_percent_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_fed_percent_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_sta_fixed_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_sta_fixed_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_sta_fixed_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_sta_fixed_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_sta_fixed_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_sta_fixed_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_sta_fixed_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_sta_fixed_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_sta_percent_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_sta_percent_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_sta_percent_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_sta_percent_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_sta_percent_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_sta_percent_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_sta_percent_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_disallow_sta_percent_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_fixed_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_fed_fixed_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_percent_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_fed_percent_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_fed_qual_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_fed_qual_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_fed_qual_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_fed_qual_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_fed_qual_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_fed_qual_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_fed_qual_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_fed_qual_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_fixed_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_sta_fixed_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_percent_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_sta_percent_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_custom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_sta_qual_custom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_macrs_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_sta_qual_macrs_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_macrs_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_sta_qual_macrs_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_sl_15(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_sta_qual_sl_15_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_sl_20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_sta_qual_sl_20_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_sl_39(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_sta_qual_sl_39_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_sl_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_sta_qual_sl_5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_sta_qual_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_total_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_total_fed_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_total_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_itc_total_sta_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoe_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_lcoe_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoe_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_lcoe_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_fed_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_lcoptc_fed_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_fed_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_lcoptc_fed_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_sta_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_lcoptc_sta_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_sta_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_lcoptc_sta_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcos_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_lcos_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcos_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_lcos_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lppa_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_lppa_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lppa_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_lppa_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_nominal_discount_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_nominal_discount_rate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_npv_annual_costs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_npv_annual_costs_nget, self->data_ptr);
}

static PyObject *
Outputs_get_npv_annual_costs_lcos(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_npv_annual_costs_lcos_nget, self->data_ptr);
}

static PyObject *
Outputs_get_npv_energy_lcos_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_npv_energy_lcos_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_npv_energy_lcos_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_npv_energy_lcos_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_npv_energy_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_npv_energy_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_npv_energy_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_npv_energy_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_npv_ppa_revenue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_npv_ppa_revenue_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ppa(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_ppa_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ppa_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_ppa_escalation_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ppa_multipliers(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Equpartflip_Outputs_ppa_multipliers_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ppa_price(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_ppa_price_nget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_fuel(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_present_value_fuel_nget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_insandproptax(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_present_value_insandproptax_nget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_oandm(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_present_value_oandm_nget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_oandm_nonfuel(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_present_value_oandm_nonfuel_nget, self->data_ptr);
}

static PyObject *
Outputs_get_prop_tax_assessed_value(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_prop_tax_assessed_value_nget, self->data_ptr);
}

static PyObject *
Outputs_get_purchase_of_property(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_purchase_of_property_nget, self->data_ptr);
}

static PyObject *
Outputs_get_salvage_value(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_salvage_value_nget, self->data_ptr);
}

static PyObject *
Outputs_get_size_of_equity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_size_of_equity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_sponsor_aftertax_equity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_sponsor_aftertax_equity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_sponsor_aftertax_irr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_sponsor_aftertax_irr_nget, self->data_ptr);
}

static PyObject *
Outputs_get_sponsor_aftertax_npv(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_sponsor_aftertax_npv_nget, self->data_ptr);
}

static PyObject *
Outputs_get_sponsor_pretax_development(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_sponsor_pretax_development_nget, self->data_ptr);
}

static PyObject *
Outputs_get_sponsor_pretax_equity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_sponsor_pretax_equity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_sponsor_pretax_irr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_sponsor_pretax_irr_nget, self->data_ptr);
}

static PyObject *
Outputs_get_sponsor_pretax_npv(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_sponsor_pretax_npv_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tax_investor_aftertax_irr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_tax_investor_aftertax_irr_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tax_investor_aftertax_npv(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_tax_investor_aftertax_npv_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tax_investor_pretax_irr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_tax_investor_pretax_irr_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tax_investor_pretax_npv(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_tax_investor_pretax_npv_nget, self->data_ptr);
}

static PyObject *
Outputs_get_wacc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Equpartflip_Outputs_wacc_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"adjusted_installed_cost", (getter)Outputs_get_adjusted_installed_cost,(setter)0,
	PyDoc_STR("*float*: Initial cost less cash incentives [$]"),
 	NULL},
{"analysis_period_irr", (getter)Outputs_get_analysis_period_irr,(setter)0,
	PyDoc_STR("*float*: IRR at end of analysis period [%]"),
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
{"cf_charging_cost_grid", (getter)Outputs_get_cf_charging_cost_grid,(setter)0,
	PyDoc_STR("*sequence*: Annual cost to charge from grid [$]"),
 	NULL},
{"cf_charging_cost_grid_month", (getter)Outputs_get_cf_charging_cost_grid_month,(setter)0,
	PyDoc_STR("*sequence*: Annual cost to charge from grid (monthly) [$]"),
 	NULL},
{"cf_charging_cost_pv", (getter)Outputs_get_cf_charging_cost_pv,(setter)0,
	PyDoc_STR("*sequence*: Annual cost to charge from system [$]"),
 	NULL},
{"cf_disbursement_equip1", (getter)Outputs_get_cf_disbursement_equip1,(setter)0,
	PyDoc_STR("*sequence*: Reserve disbursement major equipment 1 [$]"),
 	NULL},
{"cf_disbursement_equip2", (getter)Outputs_get_cf_disbursement_equip2,(setter)0,
	PyDoc_STR("*sequence*: Reserve disbursement major equipment 2 [$]"),
 	NULL},
{"cf_disbursement_equip3", (getter)Outputs_get_cf_disbursement_equip3,(setter)0,
	PyDoc_STR("*sequence*: Reserve disbursement major equipment 3 [$]"),
 	NULL},
{"cf_disbursement_om", (getter)Outputs_get_cf_disbursement_om,(setter)0,
	PyDoc_STR("*sequence*: Reserve disbursement working capital [$]"),
 	NULL},
{"cf_disbursement_receivables", (getter)Outputs_get_cf_disbursement_receivables,(setter)0,
	PyDoc_STR("*sequence*: Reserve disbursement receivables [$]"),
 	NULL},
{"cf_ebitda", (getter)Outputs_get_cf_ebitda,(setter)0,
	PyDoc_STR("*sequence*: EBITDA [$]"),
 	NULL},
{"cf_effective_tax_frac", (getter)Outputs_get_cf_effective_tax_frac,(setter)0,
	PyDoc_STR("*sequence*: Effective income tax rate [frac]"),
 	NULL},
{"cf_energy_net", (getter)Outputs_get_cf_energy_net,(setter)0,
	PyDoc_STR("*sequence*: Electricity to grid net [kWh]"),
 	NULL},
{"cf_energy_net_apr", (getter)Outputs_get_cf_energy_net_apr,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in April [kWh]"),
 	NULL},
{"cf_energy_net_aug", (getter)Outputs_get_cf_energy_net_aug,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in August [kWh]"),
 	NULL},
{"cf_energy_net_dec", (getter)Outputs_get_cf_energy_net_dec,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in December [kWh]"),
 	NULL},
{"cf_energy_net_dispatch1", (getter)Outputs_get_cf_energy_net_dispatch1,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in TOD period 1 [kWh]"),
 	NULL},
{"cf_energy_net_dispatch2", (getter)Outputs_get_cf_energy_net_dispatch2,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in TOD period 2 [kWh]"),
 	NULL},
{"cf_energy_net_dispatch3", (getter)Outputs_get_cf_energy_net_dispatch3,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in TOD period 3 [kWh]"),
 	NULL},
{"cf_energy_net_dispatch4", (getter)Outputs_get_cf_energy_net_dispatch4,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in TOD period 4 [kWh]"),
 	NULL},
{"cf_energy_net_dispatch5", (getter)Outputs_get_cf_energy_net_dispatch5,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in TOD period 5 [kWh]"),
 	NULL},
{"cf_energy_net_dispatch6", (getter)Outputs_get_cf_energy_net_dispatch6,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in TOD period 6 [kWh]"),
 	NULL},
{"cf_energy_net_dispatch7", (getter)Outputs_get_cf_energy_net_dispatch7,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in TOD period 7 [kWh]"),
 	NULL},
{"cf_energy_net_dispatch8", (getter)Outputs_get_cf_energy_net_dispatch8,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in TOD period 8 [kWh]"),
 	NULL},
{"cf_energy_net_dispatch9", (getter)Outputs_get_cf_energy_net_dispatch9,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in TOD period 9 [kWh]"),
 	NULL},
{"cf_energy_net_feb", (getter)Outputs_get_cf_energy_net_feb,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in February [kWh]"),
 	NULL},
{"cf_energy_net_jan", (getter)Outputs_get_cf_energy_net_jan,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in January [kWh]"),
 	NULL},
{"cf_energy_net_jul", (getter)Outputs_get_cf_energy_net_jul,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in July [kWh]"),
 	NULL},
{"cf_energy_net_jun", (getter)Outputs_get_cf_energy_net_jun,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in June [kWh]"),
 	NULL},
{"cf_energy_net_mar", (getter)Outputs_get_cf_energy_net_mar,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in March [kWh]"),
 	NULL},
{"cf_energy_net_may", (getter)Outputs_get_cf_energy_net_may,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in May [kWh]"),
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD1", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD1,(setter)0,
	PyDoc_STR("*sequence*: Energy produced in Year 1 by month for TOD period 1 [kWh]"),
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD2", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD2,(setter)0,
	PyDoc_STR("*sequence*: Energy produced in Year 1 by month for TOD period 2 [kWh]"),
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD3", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD3,(setter)0,
	PyDoc_STR("*sequence*: Energy produced in Year 1 by month for TOD period 3 [kWh]"),
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD4", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD4,(setter)0,
	PyDoc_STR("*sequence*: Energy produced in Year 1 by month for TOD period 4 [kWh]"),
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD5", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD5,(setter)0,
	PyDoc_STR("*sequence*: Energy produced in Year 1 by month for TOD period 5 [kWh]"),
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD6", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD6,(setter)0,
	PyDoc_STR("*sequence*: Energy produced in Year 1 by month for TOD period 6 [kWh]"),
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD7", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD7,(setter)0,
	PyDoc_STR("*sequence*: Energy produced in Year 1 by month for TOD period 7 [kWh]"),
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD8", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD8,(setter)0,
	PyDoc_STR("*sequence*: Energy produced in Year 1 by month for TOD period 8 [kWh]"),
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD9", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD9,(setter)0,
	PyDoc_STR("*sequence*: Energy produced in Year 1 by month for TOD period 9 [kWh]"),
 	NULL},
{"cf_energy_net_nov", (getter)Outputs_get_cf_energy_net_nov,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in November [kWh]"),
 	NULL},
{"cf_energy_net_oct", (getter)Outputs_get_cf_energy_net_oct,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in October [kWh]"),
 	NULL},
{"cf_energy_net_sep", (getter)Outputs_get_cf_energy_net_sep,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by year in September [kWh]"),
 	NULL},
{"cf_energy_purchases", (getter)Outputs_get_cf_energy_purchases,(setter)0,
	PyDoc_STR("*sequence*: Electricity from grid [kWh]"),
 	NULL},
{"cf_energy_sales", (getter)Outputs_get_cf_energy_sales,(setter)0,
	PyDoc_STR("*sequence*: Electricity to grid [kWh]"),
 	NULL},
{"cf_energy_value", (getter)Outputs_get_cf_energy_value,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue to project [$]"),
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
{"cf_funding_equip1", (getter)Outputs_get_cf_funding_equip1,(setter)0,
	PyDoc_STR("*sequence*: Reserve funding major equipment 1 [$]"),
 	NULL},
{"cf_funding_equip2", (getter)Outputs_get_cf_funding_equip2,(setter)0,
	PyDoc_STR("*sequence*: Reserve funding major equipment 2 [$]"),
 	NULL},
{"cf_funding_equip3", (getter)Outputs_get_cf_funding_equip3,(setter)0,
	PyDoc_STR("*sequence*: Reserve funding major equipment 3 [$]"),
 	NULL},
{"cf_funding_om", (getter)Outputs_get_cf_funding_om,(setter)0,
	PyDoc_STR("*sequence*: Reserve funding working capital [$]"),
 	NULL},
{"cf_funding_receivables", (getter)Outputs_get_cf_funding_receivables,(setter)0,
	PyDoc_STR("*sequence*: Reserve funding receivables [$]"),
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
	PyDoc_STR("*sequence*: Total operating expense [$]"),
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
	PyDoc_STR("*sequence*: Project pre-tax cash flow [$]"),
 	NULL},
{"cf_project_financing_activities", (getter)Outputs_get_cf_project_financing_activities,(setter)0,
	PyDoc_STR("*sequence*: Cash flow from financing activities [$]"),
 	NULL},
{"cf_project_investing_activities", (getter)Outputs_get_cf_project_investing_activities,(setter)0,
	PyDoc_STR("*sequence*: Project cash flow from investing activities [$]"),
 	NULL},
{"cf_project_me1cs", (getter)Outputs_get_cf_project_me1cs,(setter)0,
	PyDoc_STR("*sequence*: Reserve capital spending major equipment 1 [$]"),
 	NULL},
{"cf_project_me1ra", (getter)Outputs_get_cf_project_me1ra,(setter)0,
	PyDoc_STR("*sequence*: Reserve (increase)/decrease) major equipment reserve 1 [$]"),
 	NULL},
{"cf_project_me2cs", (getter)Outputs_get_cf_project_me2cs,(setter)0,
	PyDoc_STR("*sequence*: Reserve capital spending major equipment 2 [$]"),
 	NULL},
{"cf_project_me2ra", (getter)Outputs_get_cf_project_me2ra,(setter)0,
	PyDoc_STR("*sequence*: Reserve (increase)/decrease) major equipment reserve 2 [$]"),
 	NULL},
{"cf_project_me3cs", (getter)Outputs_get_cf_project_me3cs,(setter)0,
	PyDoc_STR("*sequence*: Reserve capital spending major equipment 3 [$]"),
 	NULL},
{"cf_project_me3ra", (getter)Outputs_get_cf_project_me3ra,(setter)0,
	PyDoc_STR("*sequence*: Reserve (increase)/decrease) major equipment reserve 3 [$]"),
 	NULL},
{"cf_project_mecs", (getter)Outputs_get_cf_project_mecs,(setter)0,
	PyDoc_STR("*sequence*: Reserve capital spending major equipment total [$]"),
 	NULL},
{"cf_project_operating_activities", (getter)Outputs_get_cf_project_operating_activities,(setter)0,
	PyDoc_STR("*sequence*: Cash flow from operating activities [$]"),
 	NULL},
{"cf_project_ra", (getter)Outputs_get_cf_project_ra,(setter)0,
	PyDoc_STR("*sequence*: Reserve (increase)/decrease total [$]"),
 	NULL},
{"cf_project_receivablesra", (getter)Outputs_get_cf_project_receivablesra,(setter)0,
	PyDoc_STR("*sequence*: Reserve (increase)/decrease receivables [$]"),
 	NULL},
{"cf_project_return_aftertax", (getter)Outputs_get_cf_project_return_aftertax,(setter)0,
	PyDoc_STR("*sequence*: Project after-tax returns [$]"),
 	NULL},
{"cf_project_return_aftertax_cash", (getter)Outputs_get_cf_project_return_aftertax_cash,(setter)0,
	PyDoc_STR("*sequence*: Project operating cash [$]"),
 	NULL},
{"cf_project_return_aftertax_irr", (getter)Outputs_get_cf_project_return_aftertax_irr,(setter)0,
	PyDoc_STR("*sequence*: Project after-tax cumulative IRR [%]"),
 	NULL},
{"cf_project_return_aftertax_npv", (getter)Outputs_get_cf_project_return_aftertax_npv,(setter)0,
	PyDoc_STR("*sequence*: Project after-tax cumulative NPV [$]"),
 	NULL},
{"cf_project_return_pretax", (getter)Outputs_get_cf_project_return_pretax,(setter)0,
	PyDoc_STR("*sequence*: Project pre-tax returns [$]"),
 	NULL},
{"cf_project_return_pretax_irr", (getter)Outputs_get_cf_project_return_pretax_irr,(setter)0,
	PyDoc_STR("*sequence*: Project pre-tax cumulative IRR [%]"),
 	NULL},
{"cf_project_return_pretax_npv", (getter)Outputs_get_cf_project_return_pretax_npv,(setter)0,
	PyDoc_STR("*sequence*: Project pre-tax cumulative NPV [$]"),
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
{"cf_ptc_total", (getter)Outputs_get_cf_ptc_total,(setter)0,
	PyDoc_STR("*sequence*: Total PTC income [$]"),
 	NULL},
{"cf_recapitalization", (getter)Outputs_get_cf_recapitalization,(setter)0,
	PyDoc_STR("*sequence*: Recapitalization operating expense [$]"),
 	NULL},
{"cf_reserve_equip1", (getter)Outputs_get_cf_reserve_equip1,(setter)0,
	PyDoc_STR("*sequence*: Reserve account major equipment 1 [$]"),
 	NULL},
{"cf_reserve_equip2", (getter)Outputs_get_cf_reserve_equip2,(setter)0,
	PyDoc_STR("*sequence*: Reserve account major equipment 2 [$]"),
 	NULL},
{"cf_reserve_equip3", (getter)Outputs_get_cf_reserve_equip3,(setter)0,
	PyDoc_STR("*sequence*: Reserve account major equipment 3 [$]"),
 	NULL},
{"cf_reserve_interest", (getter)Outputs_get_cf_reserve_interest,(setter)0,
	PyDoc_STR("*sequence*: Reserve account interest on reserves [$]"),
 	NULL},
{"cf_reserve_om", (getter)Outputs_get_cf_reserve_om,(setter)0,
	PyDoc_STR("*sequence*: Reserve account working capital [$]"),
 	NULL},
{"cf_reserve_receivables", (getter)Outputs_get_cf_reserve_receivables,(setter)0,
	PyDoc_STR("*sequence*: Reserve account receivables [$]"),
 	NULL},
{"cf_reserve_total", (getter)Outputs_get_cf_reserve_total,(setter)0,
	PyDoc_STR("*sequence*: Reserve account total [$]"),
 	NULL},
{"cf_revenue_apr", (getter)Outputs_get_cf_revenue_apr,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for April [$]"),
 	NULL},
{"cf_revenue_aug", (getter)Outputs_get_cf_revenue_aug,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for August [$]"),
 	NULL},
{"cf_revenue_dec", (getter)Outputs_get_cf_revenue_dec,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for December [$]"),
 	NULL},
{"cf_revenue_dispatch1", (getter)Outputs_get_cf_revenue_dispatch1,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for TOD period 1 [$]"),
 	NULL},
{"cf_revenue_dispatch2", (getter)Outputs_get_cf_revenue_dispatch2,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for TOD period 2 [$]"),
 	NULL},
{"cf_revenue_dispatch3", (getter)Outputs_get_cf_revenue_dispatch3,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for TOD period 3 [$]"),
 	NULL},
{"cf_revenue_dispatch4", (getter)Outputs_get_cf_revenue_dispatch4,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for TOD period 4 [$]"),
 	NULL},
{"cf_revenue_dispatch5", (getter)Outputs_get_cf_revenue_dispatch5,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for TOD period 5 [$]"),
 	NULL},
{"cf_revenue_dispatch6", (getter)Outputs_get_cf_revenue_dispatch6,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for TOD period 6 [$]"),
 	NULL},
{"cf_revenue_dispatch7", (getter)Outputs_get_cf_revenue_dispatch7,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for TOD period 7 [$]"),
 	NULL},
{"cf_revenue_dispatch8", (getter)Outputs_get_cf_revenue_dispatch8,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for TOD period 8 [$]"),
 	NULL},
{"cf_revenue_dispatch9", (getter)Outputs_get_cf_revenue_dispatch9,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for TOD period 9 [$]"),
 	NULL},
{"cf_revenue_feb", (getter)Outputs_get_cf_revenue_feb,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for February [$]"),
 	NULL},
{"cf_revenue_jan", (getter)Outputs_get_cf_revenue_jan,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for January [$]"),
 	NULL},
{"cf_revenue_jul", (getter)Outputs_get_cf_revenue_jul,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for July [$]"),
 	NULL},
{"cf_revenue_jun", (getter)Outputs_get_cf_revenue_jun,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for June [$]"),
 	NULL},
{"cf_revenue_mar", (getter)Outputs_get_cf_revenue_mar,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for March [$]"),
 	NULL},
{"cf_revenue_may", (getter)Outputs_get_cf_revenue_may,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for May [$]"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD1", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD1,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by month for TOD period 1 [$]"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD2", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD2,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by month for TOD period 2 [$]"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD3", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD3,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by month for TOD period 3 [$]"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD4", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD4,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by month for TOD period 4 [$]"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD5", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD5,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by month for TOD period 5 [$]"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD6", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD6,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by month for TOD period 6 [$]"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD7", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD7,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by month for TOD period 7 [$]"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD8", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD8,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by month for TOD period 8 [$]"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD9", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD9,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by month for TOD period 9 [$]"),
 	NULL},
{"cf_revenue_nov", (getter)Outputs_get_cf_revenue_nov,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for November [$]"),
 	NULL},
{"cf_revenue_oct", (getter)Outputs_get_cf_revenue_oct,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for October [$]"),
 	NULL},
{"cf_revenue_sep", (getter)Outputs_get_cf_revenue_sep,(setter)0,
	PyDoc_STR("*sequence*: PPA revenue by year for September [$]"),
 	NULL},
{"cf_salvage_cost_lcos", (getter)Outputs_get_cf_salvage_cost_lcos,(setter)0,
	PyDoc_STR("*sequence*: Annual battery salvage value costs [$]"),
 	NULL},
{"cf_sponsor_aftertax", (getter)Outputs_get_cf_sponsor_aftertax,(setter)0,
	PyDoc_STR("*sequence*: Developer after-tax total [$]"),
 	NULL},
{"cf_sponsor_aftertax_cash", (getter)Outputs_get_cf_sponsor_aftertax_cash,(setter)0,
	PyDoc_STR("*sequence*: Developer after-tax cash returns [$]"),
 	NULL},
{"cf_sponsor_aftertax_irr", (getter)Outputs_get_cf_sponsor_aftertax_irr,(setter)0,
	PyDoc_STR("*sequence*: Developer after-tax cumulative IRR [%]"),
 	NULL},
{"cf_sponsor_aftertax_itc", (getter)Outputs_get_cf_sponsor_aftertax_itc,(setter)0,
	PyDoc_STR("*sequence*: Developer after-tax share of ITC [$]"),
 	NULL},
{"cf_sponsor_aftertax_npv", (getter)Outputs_get_cf_sponsor_aftertax_npv,(setter)0,
	PyDoc_STR("*sequence*: Developer after-tax cumulative NPV [$]"),
 	NULL},
{"cf_sponsor_aftertax_ptc", (getter)Outputs_get_cf_sponsor_aftertax_ptc,(setter)0,
	PyDoc_STR("*sequence*: Developer after-tax share of PTC [$]"),
 	NULL},
{"cf_sponsor_aftertax_tax", (getter)Outputs_get_cf_sponsor_aftertax_tax,(setter)0,
	PyDoc_STR("*sequence*: Developer after-tax share of tax benefit (liability) [$]"),
 	NULL},
{"cf_sponsor_capital_recovery_balance", (getter)Outputs_get_cf_sponsor_capital_recovery_balance,(setter)0,
	PyDoc_STR("*sequence*: Developer capital recovery balance [$]"),
 	NULL},
{"cf_sponsor_capital_recovery_cash", (getter)Outputs_get_cf_sponsor_capital_recovery_cash,(setter)0,
	PyDoc_STR("*sequence*: Developer capital recovery cash [$]"),
 	NULL},
{"cf_sponsor_pretax", (getter)Outputs_get_cf_sponsor_pretax,(setter)0,
	PyDoc_STR("*sequence*: Developer pre-tax total [$]"),
 	NULL},
{"cf_sponsor_pretax_cash_during_recovery", (getter)Outputs_get_cf_sponsor_pretax_cash_during_recovery,(setter)0,
	PyDoc_STR("*sequence*: Developer operating cash during recovery [$]"),
 	NULL},
{"cf_sponsor_pretax_cash_post_recovery", (getter)Outputs_get_cf_sponsor_pretax_cash_post_recovery,(setter)0,
	PyDoc_STR("*sequence*: Developer operating cash post recovery [$]"),
 	NULL},
{"cf_sponsor_pretax_irr", (getter)Outputs_get_cf_sponsor_pretax_irr,(setter)0,
	PyDoc_STR("*sequence*: Developer pre-tax cumulative IRR [%]"),
 	NULL},
{"cf_sponsor_pretax_npv", (getter)Outputs_get_cf_sponsor_pretax_npv,(setter)0,
	PyDoc_STR("*sequence*: Developer pre-tax cumulative NPV [$]"),
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
{"cf_tax_investor_aftertax", (getter)Outputs_get_cf_tax_investor_aftertax,(setter)0,
	PyDoc_STR("*sequence*: Investor after-tax returns [$]"),
 	NULL},
{"cf_tax_investor_aftertax_cash", (getter)Outputs_get_cf_tax_investor_aftertax_cash,(setter)0,
	PyDoc_STR("*sequence*: Investor after-tax cash returns [$]"),
 	NULL},
{"cf_tax_investor_aftertax_irr", (getter)Outputs_get_cf_tax_investor_aftertax_irr,(setter)0,
	PyDoc_STR("*sequence*: Investor after-tax cumulative IRR [%]"),
 	NULL},
{"cf_tax_investor_aftertax_itc", (getter)Outputs_get_cf_tax_investor_aftertax_itc,(setter)0,
	PyDoc_STR("*sequence*: Investor share of ITC [$]"),
 	NULL},
{"cf_tax_investor_aftertax_max_irr", (getter)Outputs_get_cf_tax_investor_aftertax_max_irr,(setter)0,
	PyDoc_STR("*sequence*: Investor after-tax maximum IRR [%]"),
 	NULL},
{"cf_tax_investor_aftertax_npv", (getter)Outputs_get_cf_tax_investor_aftertax_npv,(setter)0,
	PyDoc_STR("*sequence*: Investor after-tax cumulative NPV [$]"),
 	NULL},
{"cf_tax_investor_aftertax_ptc", (getter)Outputs_get_cf_tax_investor_aftertax_ptc,(setter)0,
	PyDoc_STR("*sequence*: Investor share of PTC [$]"),
 	NULL},
{"cf_tax_investor_aftertax_tax", (getter)Outputs_get_cf_tax_investor_aftertax_tax,(setter)0,
	PyDoc_STR("*sequence*: Investor share of tax benefit (liability) [$]"),
 	NULL},
{"cf_tax_investor_pretax", (getter)Outputs_get_cf_tax_investor_pretax,(setter)0,
	PyDoc_STR("*sequence*: Investor pre-tax returns [$]"),
 	NULL},
{"cf_tax_investor_pretax_irr", (getter)Outputs_get_cf_tax_investor_pretax_irr,(setter)0,
	PyDoc_STR("*sequence*: Investor pre-tax cumulative IRR [%]"),
 	NULL},
{"cf_tax_investor_pretax_npv", (getter)Outputs_get_cf_tax_investor_pretax_npv,(setter)0,
	PyDoc_STR("*sequence*: Investor pre-tax cumulative NPV [$]"),
 	NULL},
{"cf_total_revenue", (getter)Outputs_get_cf_total_revenue,(setter)0,
	PyDoc_STR("*sequence*: Total revenue [$]"),
 	NULL},
{"cf_util_escal_rate", (getter)Outputs_get_cf_util_escal_rate,(setter)0,
	PyDoc_STR("*sequence*: Utility escalation rate"),
 	NULL},
{"cf_utility_bill", (getter)Outputs_get_cf_utility_bill,(setter)0,
	PyDoc_STR("*sequence*: Electricity purchase [$]"),
 	NULL},
{"cost_financing", (getter)Outputs_get_cost_financing,(setter)0,
	PyDoc_STR("*float*: Financing Cost [$]"),
 	NULL},
{"cost_installed", (getter)Outputs_get_cost_installed,(setter)0,
	PyDoc_STR("*float*: Initial cost [$]"),
 	NULL},
{"cost_installedperwatt", (getter)Outputs_get_cost_installedperwatt,(setter)0,
	PyDoc_STR("*float*: Installed cost per watt [$/W]"),
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
	PyDoc_STR("*float*: Federal depreciation basis after ITC reduction [$]"),
 	NULL},
{"depr_fedbas_cbi_reduc_custom", (getter)Outputs_get_depr_fedbas_cbi_reduc_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line federal cbi reduction [$]"),
 	NULL},
{"depr_fedbas_cbi_reduc_macrs_15", (getter)Outputs_get_depr_fedbas_cbi_reduc_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS federal cbi reduction [$]"),
 	NULL},
{"depr_fedbas_cbi_reduc_macrs_5", (getter)Outputs_get_depr_fedbas_cbi_reduc_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS federal cbi reduction [$]"),
 	NULL},
{"depr_fedbas_cbi_reduc_sl_15", (getter)Outputs_get_depr_fedbas_cbi_reduc_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line federal cbi reduction [$]"),
 	NULL},
{"depr_fedbas_cbi_reduc_sl_20", (getter)Outputs_get_depr_fedbas_cbi_reduc_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line federal cbi reduction [$]"),
 	NULL},
{"depr_fedbas_cbi_reduc_sl_39", (getter)Outputs_get_depr_fedbas_cbi_reduc_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line federal cbi reduction [$]"),
 	NULL},
{"depr_fedbas_cbi_reduc_sl_5", (getter)Outputs_get_depr_fedbas_cbi_reduc_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line federal cbi reduction [$]"),
 	NULL},
{"depr_fedbas_cbi_reduc_total", (getter)Outputs_get_depr_fedbas_cbi_reduc_total,(setter)0,
	PyDoc_STR("*float*: Federal cbi reduction [$]"),
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
	PyDoc_STR("*float*: Federal first year bonus depreciation [$]"),
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
	PyDoc_STR("*float*: Custom straight line federal ibi reduction [$]"),
 	NULL},
{"depr_fedbas_ibi_reduc_macrs_15", (getter)Outputs_get_depr_fedbas_ibi_reduc_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS federal ibi reduction [$]"),
 	NULL},
{"depr_fedbas_ibi_reduc_macrs_5", (getter)Outputs_get_depr_fedbas_ibi_reduc_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS federal ibi reduction [$]"),
 	NULL},
{"depr_fedbas_ibi_reduc_sl_15", (getter)Outputs_get_depr_fedbas_ibi_reduc_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line federal ibi reduction [$]"),
 	NULL},
{"depr_fedbas_ibi_reduc_sl_20", (getter)Outputs_get_depr_fedbas_ibi_reduc_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line federal ibi reduction [$]"),
 	NULL},
{"depr_fedbas_ibi_reduc_sl_39", (getter)Outputs_get_depr_fedbas_ibi_reduc_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line federal ibi reduction [$]"),
 	NULL},
{"depr_fedbas_ibi_reduc_sl_5", (getter)Outputs_get_depr_fedbas_ibi_reduc_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line federal ibi reduction [$]"),
 	NULL},
{"depr_fedbas_ibi_reduc_total", (getter)Outputs_get_depr_fedbas_ibi_reduc_total,(setter)0,
	PyDoc_STR("*float*: Federal ibi reduction [$]"),
 	NULL},
{"depr_fedbas_itc_fed_reduction_custom", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line federal basis federal ITC reduciton [$]"),
 	NULL},
{"depr_fedbas_itc_fed_reduction_macrs_15", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS federal basis federal ITC reduciton [$]"),
 	NULL},
{"depr_fedbas_itc_fed_reduction_macrs_5", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS federal basis federal ITC reduciton [$]"),
 	NULL},
{"depr_fedbas_itc_fed_reduction_sl_15", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line federal basis federal ITC reduciton [$]"),
 	NULL},
{"depr_fedbas_itc_fed_reduction_sl_20", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line federal basis federal ITC reduciton [$]"),
 	NULL},
{"depr_fedbas_itc_fed_reduction_sl_39", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line federal basis federal ITC reduciton [$]"),
 	NULL},
{"depr_fedbas_itc_fed_reduction_sl_5", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line federal basis federal ITC reduciton [$]"),
 	NULL},
{"depr_fedbas_itc_fed_reduction_total", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_total,(setter)0,
	PyDoc_STR("*float*: Federal basis federal ITC reduciton [$]"),
 	NULL},
{"depr_fedbas_itc_sta_reduction_custom", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line federal basis state ITC reduciton [$]"),
 	NULL},
{"depr_fedbas_itc_sta_reduction_macrs_15", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS federal basis state ITC reduciton [$]"),
 	NULL},
{"depr_fedbas_itc_sta_reduction_macrs_5", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS federal basis state ITC reduciton [$]"),
 	NULL},
{"depr_fedbas_itc_sta_reduction_sl_15", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line federal basis state ITC reduciton [$]"),
 	NULL},
{"depr_fedbas_itc_sta_reduction_sl_20", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line federal basis state ITC reduciton [$]"),
 	NULL},
{"depr_fedbas_itc_sta_reduction_sl_39", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line federal basis state ITC reduciton [$]"),
 	NULL},
{"depr_fedbas_itc_sta_reduction_sl_5", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line federal basis state ITC reduciton [$]"),
 	NULL},
{"depr_fedbas_itc_sta_reduction_total", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_total,(setter)0,
	PyDoc_STR("*float*: Federal basis state ITC reduciton [$]"),
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
	PyDoc_STR("*float*: Federal percent of qualifying costs [%]"),
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
	PyDoc_STR("*float*: Federal percent of total depreciable basis [%]"),
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
	PyDoc_STR("*float*: Federal depreciation basis prior ITC reduction [$]"),
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
	PyDoc_STR("*float*: Federal depreciation basis [$]"),
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
	PyDoc_STR("*float*: State depreciation basis after ITC reduction [$]"),
 	NULL},
{"depr_stabas_cbi_reduc_custom", (getter)Outputs_get_depr_stabas_cbi_reduc_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line state cbi reduction [$]"),
 	NULL},
{"depr_stabas_cbi_reduc_macrs_15", (getter)Outputs_get_depr_stabas_cbi_reduc_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS state cbi reduction [$]"),
 	NULL},
{"depr_stabas_cbi_reduc_macrs_5", (getter)Outputs_get_depr_stabas_cbi_reduc_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS state cbi reduction [$]"),
 	NULL},
{"depr_stabas_cbi_reduc_sl_15", (getter)Outputs_get_depr_stabas_cbi_reduc_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line state cbi reduction [$]"),
 	NULL},
{"depr_stabas_cbi_reduc_sl_20", (getter)Outputs_get_depr_stabas_cbi_reduc_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line state cbi reduction [$]"),
 	NULL},
{"depr_stabas_cbi_reduc_sl_39", (getter)Outputs_get_depr_stabas_cbi_reduc_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line state cbi reduction [$]"),
 	NULL},
{"depr_stabas_cbi_reduc_sl_5", (getter)Outputs_get_depr_stabas_cbi_reduc_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line state cbi reduction [$]"),
 	NULL},
{"depr_stabas_cbi_reduc_total", (getter)Outputs_get_depr_stabas_cbi_reduc_total,(setter)0,
	PyDoc_STR("*float*: State cbi reduction [$]"),
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
	PyDoc_STR("*float*: State first year bonus depreciation [$]"),
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
	PyDoc_STR("*float*: Custom straight line state ibi reduction [$]"),
 	NULL},
{"depr_stabas_ibi_reduc_macrs_15", (getter)Outputs_get_depr_stabas_ibi_reduc_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS state ibi reduction [$]"),
 	NULL},
{"depr_stabas_ibi_reduc_macrs_5", (getter)Outputs_get_depr_stabas_ibi_reduc_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS state ibi reduction [$]"),
 	NULL},
{"depr_stabas_ibi_reduc_sl_15", (getter)Outputs_get_depr_stabas_ibi_reduc_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line state ibi reduction [$]"),
 	NULL},
{"depr_stabas_ibi_reduc_sl_20", (getter)Outputs_get_depr_stabas_ibi_reduc_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line state ibi reduction [$]"),
 	NULL},
{"depr_stabas_ibi_reduc_sl_39", (getter)Outputs_get_depr_stabas_ibi_reduc_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line state ibi reduction [$]"),
 	NULL},
{"depr_stabas_ibi_reduc_sl_5", (getter)Outputs_get_depr_stabas_ibi_reduc_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line state ibi reduction [$]"),
 	NULL},
{"depr_stabas_ibi_reduc_total", (getter)Outputs_get_depr_stabas_ibi_reduc_total,(setter)0,
	PyDoc_STR("*float*: State ibi reduction [$]"),
 	NULL},
{"depr_stabas_itc_fed_reduction_custom", (getter)Outputs_get_depr_stabas_itc_fed_reduction_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line state basis federal ITC reduciton [$]"),
 	NULL},
{"depr_stabas_itc_fed_reduction_macrs_15", (getter)Outputs_get_depr_stabas_itc_fed_reduction_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS state basis federal ITC reduciton [$]"),
 	NULL},
{"depr_stabas_itc_fed_reduction_macrs_5", (getter)Outputs_get_depr_stabas_itc_fed_reduction_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS state basis federal ITC reduciton [$]"),
 	NULL},
{"depr_stabas_itc_fed_reduction_sl_15", (getter)Outputs_get_depr_stabas_itc_fed_reduction_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line state basis federal ITC reduciton [$]"),
 	NULL},
{"depr_stabas_itc_fed_reduction_sl_20", (getter)Outputs_get_depr_stabas_itc_fed_reduction_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line state basis federal ITC reduciton [$]"),
 	NULL},
{"depr_stabas_itc_fed_reduction_sl_39", (getter)Outputs_get_depr_stabas_itc_fed_reduction_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line state basis federal ITC reduciton [$]"),
 	NULL},
{"depr_stabas_itc_fed_reduction_sl_5", (getter)Outputs_get_depr_stabas_itc_fed_reduction_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line state basis federal ITC reduciton [$]"),
 	NULL},
{"depr_stabas_itc_fed_reduction_total", (getter)Outputs_get_depr_stabas_itc_fed_reduction_total,(setter)0,
	PyDoc_STR("*float*: State basis federal ITC reduciton [$]"),
 	NULL},
{"depr_stabas_itc_sta_reduction_custom", (getter)Outputs_get_depr_stabas_itc_sta_reduction_custom,(setter)0,
	PyDoc_STR("*float*: Custom straight line state basis state ITC reduciton [$]"),
 	NULL},
{"depr_stabas_itc_sta_reduction_macrs_15", (getter)Outputs_get_depr_stabas_itc_sta_reduction_macrs_15,(setter)0,
	PyDoc_STR("*float*: 15-yr MACRS state basis state ITC reduciton [$]"),
 	NULL},
{"depr_stabas_itc_sta_reduction_macrs_5", (getter)Outputs_get_depr_stabas_itc_sta_reduction_macrs_5,(setter)0,
	PyDoc_STR("*float*: 5-yr MACRS state basis state ITC reduciton [$]"),
 	NULL},
{"depr_stabas_itc_sta_reduction_sl_15", (getter)Outputs_get_depr_stabas_itc_sta_reduction_sl_15,(setter)0,
	PyDoc_STR("*float*: 15-yr straight line state basis state ITC reduciton [$]"),
 	NULL},
{"depr_stabas_itc_sta_reduction_sl_20", (getter)Outputs_get_depr_stabas_itc_sta_reduction_sl_20,(setter)0,
	PyDoc_STR("*float*: 20-yr straight line state basis state ITC reduciton [$]"),
 	NULL},
{"depr_stabas_itc_sta_reduction_sl_39", (getter)Outputs_get_depr_stabas_itc_sta_reduction_sl_39,(setter)0,
	PyDoc_STR("*float*: 39-yr straight line state basis state ITC reduciton [$]"),
 	NULL},
{"depr_stabas_itc_sta_reduction_sl_5", (getter)Outputs_get_depr_stabas_itc_sta_reduction_sl_5,(setter)0,
	PyDoc_STR("*float*: 5-yr straight line state basis state ITC reduciton [$]"),
 	NULL},
{"depr_stabas_itc_sta_reduction_total", (getter)Outputs_get_depr_stabas_itc_sta_reduction_total,(setter)0,
	PyDoc_STR("*float*: State basis state ITC reduciton [$]"),
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
	PyDoc_STR("*float*: State percent of qualifying costs [%]"),
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
	PyDoc_STR("*float*: State percent of total depreciable basis [%]"),
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
	PyDoc_STR("*float*: State depreciation basis prior ITC reduction [$]"),
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
	PyDoc_STR("*float*: State depreciation basis [$]"),
 	NULL},
{"effective_tax_rate", (getter)Outputs_get_effective_tax_rate,(setter)0,
	PyDoc_STR("*float*: Effective tax rate [%]"),
 	NULL},
{"firstyear_energy_dispatch1", (getter)Outputs_get_firstyear_energy_dispatch1,(setter)0,
	PyDoc_STR("*float*: Energy produced in Year 1 TOD period 1 [kWh]"),
 	NULL},
{"firstyear_energy_dispatch2", (getter)Outputs_get_firstyear_energy_dispatch2,(setter)0,
	PyDoc_STR("*float*: Energy produced in Year 1 TOD period 2 [kWh]"),
 	NULL},
{"firstyear_energy_dispatch3", (getter)Outputs_get_firstyear_energy_dispatch3,(setter)0,
	PyDoc_STR("*float*: Energy produced in Year 1 TOD period 3 [kWh]"),
 	NULL},
{"firstyear_energy_dispatch4", (getter)Outputs_get_firstyear_energy_dispatch4,(setter)0,
	PyDoc_STR("*float*: Energy produced in Year 1 TOD period 4 [kWh]"),
 	NULL},
{"firstyear_energy_dispatch5", (getter)Outputs_get_firstyear_energy_dispatch5,(setter)0,
	PyDoc_STR("*float*: Energy produced in Year 1 TOD period 5 [kWh]"),
 	NULL},
{"firstyear_energy_dispatch6", (getter)Outputs_get_firstyear_energy_dispatch6,(setter)0,
	PyDoc_STR("*float*: Energy produced in Year 1 TOD period 6 [kWh]"),
 	NULL},
{"firstyear_energy_dispatch7", (getter)Outputs_get_firstyear_energy_dispatch7,(setter)0,
	PyDoc_STR("*float*: Energy produced in Year 1 TOD period 7 [kWh]"),
 	NULL},
{"firstyear_energy_dispatch8", (getter)Outputs_get_firstyear_energy_dispatch8,(setter)0,
	PyDoc_STR("*float*: Energy produced in Year 1 TOD period 8 [kWh]"),
 	NULL},
{"firstyear_energy_dispatch9", (getter)Outputs_get_firstyear_energy_dispatch9,(setter)0,
	PyDoc_STR("*float*: Energy produced in Year 1 TOD period 9 [kWh]"),
 	NULL},
{"firstyear_energy_price1", (getter)Outputs_get_firstyear_energy_price1,(setter)0,
	PyDoc_STR("*float*: Power price in Year 1 TOD period 1 [cents/kWh]"),
 	NULL},
{"firstyear_energy_price2", (getter)Outputs_get_firstyear_energy_price2,(setter)0,
	PyDoc_STR("*float*: Power price in Year 1 TOD period 2 [cents/kWh]"),
 	NULL},
{"firstyear_energy_price3", (getter)Outputs_get_firstyear_energy_price3,(setter)0,
	PyDoc_STR("*float*: Power price in Year 1 TOD period 3 [cents/kWh]"),
 	NULL},
{"firstyear_energy_price4", (getter)Outputs_get_firstyear_energy_price4,(setter)0,
	PyDoc_STR("*float*: Power price in Year 1 TOD period 4 [cents/kWh]"),
 	NULL},
{"firstyear_energy_price5", (getter)Outputs_get_firstyear_energy_price5,(setter)0,
	PyDoc_STR("*float*: Power price in Year 1 TOD period 5 [cents/kWh]"),
 	NULL},
{"firstyear_energy_price6", (getter)Outputs_get_firstyear_energy_price6,(setter)0,
	PyDoc_STR("*float*: Power price in Year 1 TOD period 6 [cents/kWh]"),
 	NULL},
{"firstyear_energy_price7", (getter)Outputs_get_firstyear_energy_price7,(setter)0,
	PyDoc_STR("*float*: Power price in Year 1 TOD period 7 [cents/kWh]"),
 	NULL},
{"firstyear_energy_price8", (getter)Outputs_get_firstyear_energy_price8,(setter)0,
	PyDoc_STR("*float*: Power price in Year 1 TOD period 8 [cents/kWh]"),
 	NULL},
{"firstyear_energy_price9", (getter)Outputs_get_firstyear_energy_price9,(setter)0,
	PyDoc_STR("*float*: Power price in Year 1 TOD period 9 [cents/kWh]"),
 	NULL},
{"firstyear_revenue_dispatch1", (getter)Outputs_get_firstyear_revenue_dispatch1,(setter)0,
	PyDoc_STR("*float*: PPA revenue in Year 1 TOD period 1 [$]"),
 	NULL},
{"firstyear_revenue_dispatch2", (getter)Outputs_get_firstyear_revenue_dispatch2,(setter)0,
	PyDoc_STR("*float*: PPA revenue in Year 1 TOD period 2 [$]"),
 	NULL},
{"firstyear_revenue_dispatch3", (getter)Outputs_get_firstyear_revenue_dispatch3,(setter)0,
	PyDoc_STR("*float*: PPA revenue in Year 1 TOD period 3 [$]"),
 	NULL},
{"firstyear_revenue_dispatch4", (getter)Outputs_get_firstyear_revenue_dispatch4,(setter)0,
	PyDoc_STR("*float*: PPA revenue in Year 1 TOD period 4 [$]"),
 	NULL},
{"firstyear_revenue_dispatch5", (getter)Outputs_get_firstyear_revenue_dispatch5,(setter)0,
	PyDoc_STR("*float*: PPA revenue in Year 1 TOD period 5 [$]"),
 	NULL},
{"firstyear_revenue_dispatch6", (getter)Outputs_get_firstyear_revenue_dispatch6,(setter)0,
	PyDoc_STR("*float*: PPA revenue in Year 1 TOD period 6 [$]"),
 	NULL},
{"firstyear_revenue_dispatch7", (getter)Outputs_get_firstyear_revenue_dispatch7,(setter)0,
	PyDoc_STR("*float*: PPA revenue in Year 1 TOD period 7 [$]"),
 	NULL},
{"firstyear_revenue_dispatch8", (getter)Outputs_get_firstyear_revenue_dispatch8,(setter)0,
	PyDoc_STR("*float*: PPA revenue in Year 1 TOD period 8 [$]"),
 	NULL},
{"firstyear_revenue_dispatch9", (getter)Outputs_get_firstyear_revenue_dispatch9,(setter)0,
	PyDoc_STR("*float*: PPA revenue in Year 1 TOD period 9 [$]"),
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
	PyDoc_STR("*float*: federal ITC fixed total [$]"),
 	NULL},
{"itc_fed_percent_total", (getter)Outputs_get_itc_fed_percent_total,(setter)0,
	PyDoc_STR("*float*: federal ITC percent total [$]"),
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
	PyDoc_STR("*float*: Federal ITC adj qualifying costs [$]"),
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
	PyDoc_STR("*float*: State ITC adj qualifying costs [$]"),
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
{"lppa_nom", (getter)Outputs_get_lppa_nom,(setter)0,
	PyDoc_STR("*float*: LPPA Levelized PPA price nominal [cents/kWh]"),
 	NULL},
{"lppa_real", (getter)Outputs_get_lppa_real,(setter)0,
	PyDoc_STR("*float*: LPPA Levelized PPA price real [cents/kWh]"),
 	NULL},
{"nominal_discount_rate", (getter)Outputs_get_nominal_discount_rate,(setter)0,
	PyDoc_STR("*float*: Nominal discount rate [%]"),
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
	PyDoc_STR("*float*: Initial year PPA price [cents/kWh]"),
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
{"prop_tax_assessed_value", (getter)Outputs_get_prop_tax_assessed_value,(setter)0,
	PyDoc_STR("*float*: Assessed value of property for tax purposes [$]"),
 	NULL},
{"purchase_of_property", (getter)Outputs_get_purchase_of_property,(setter)0,
	PyDoc_STR("*float*: Purchase of property cost [$]"),
 	NULL},
{"salvage_value", (getter)Outputs_get_salvage_value,(setter)0,
	PyDoc_STR("*float*: Net pre-tax cash salvage value [$]"),
 	NULL},
{"size_of_equity", (getter)Outputs_get_size_of_equity,(setter)0,
	PyDoc_STR("*float*: Total equity [$]"),
 	NULL},
{"sponsor_aftertax_equity", (getter)Outputs_get_sponsor_aftertax_equity,(setter)0,
	PyDoc_STR("*float*: Developer after-tax equity investment [$]"),
 	NULL},
{"sponsor_aftertax_irr", (getter)Outputs_get_sponsor_aftertax_irr,(setter)0,
	PyDoc_STR("*float*: Developer after-tax IRR at end of project [%]"),
 	NULL},
{"sponsor_aftertax_npv", (getter)Outputs_get_sponsor_aftertax_npv,(setter)0,
	PyDoc_STR("*float*: Developer after-tax NPV [$]"),
 	NULL},
{"sponsor_pretax_development", (getter)Outputs_get_sponsor_pretax_development,(setter)0,
	PyDoc_STR("*float*: Development fee [$]"),
 	NULL},
{"sponsor_pretax_equity", (getter)Outputs_get_sponsor_pretax_equity,(setter)0,
	PyDoc_STR("*float*: Developer pre-tax equity investment [$]"),
 	NULL},
{"sponsor_pretax_irr", (getter)Outputs_get_sponsor_pretax_irr,(setter)0,
	PyDoc_STR("*float*: Developer pre-tax IRR at end of project [%]"),
 	NULL},
{"sponsor_pretax_npv", (getter)Outputs_get_sponsor_pretax_npv,(setter)0,
	PyDoc_STR("*float*: Developer pre-tax NPV [$]"),
 	NULL},
{"tax_investor_aftertax_irr", (getter)Outputs_get_tax_investor_aftertax_irr,(setter)0,
	PyDoc_STR("*float*: Investor after-tax IRR at end of project"),
 	NULL},
{"tax_investor_aftertax_npv", (getter)Outputs_get_tax_investor_aftertax_npv,(setter)0,
	PyDoc_STR("*float*: Investor after-tax NPV"),
 	NULL},
{"tax_investor_pretax_irr", (getter)Outputs_get_tax_investor_pretax_irr,(setter)0,
	PyDoc_STR("*float*: Investor pre-tax IRR at end of project [%]"),
 	NULL},
{"tax_investor_pretax_npv", (getter)Outputs_get_tax_investor_pretax_npv,(setter)0,
	PyDoc_STR("*float*: Investor pre-tax NPV [$]"),
 	NULL},
{"wacc", (getter)Outputs_get_wacc,(setter)0,
	PyDoc_STR("*float*: WACC Weighted average cost of capital [$]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Equpartflip.Outputs",             /*tp_name*/
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
 * Equpartflip
 */

static PyTypeObject Equpartflip_Type;

static CmodObject *
newEqupartflipObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Equpartflip_Type);

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

	PyObject* SystemOutput_obj = SystemOutput_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemOutput", SystemOutput_obj);
	Py_DECREF(SystemOutput_obj);

	PyObject* ElectricityRates_obj = ElectricityRates_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ElectricityRates", ElectricityRates_obj);
	Py_DECREF(ElectricityRates_obj);

	PyObject* Recapitalization_obj = Recapitalization_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Recapitalization", Recapitalization_obj);
	Py_DECREF(Recapitalization_obj);

	PyObject* TimeOfDelivery_obj = TimeOfDelivery_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TimeOfDelivery", TimeOfDelivery_obj);
	Py_DECREF(TimeOfDelivery_obj);

	PyObject* UtilityBill_obj = UtilityBill_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "UtilityBill", UtilityBill_obj);
	Py_DECREF(UtilityBill_obj);

	PyObject* ConstructionFinancing_obj = ConstructionFinancing_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ConstructionFinancing", ConstructionFinancing_obj);
	Py_DECREF(ConstructionFinancing_obj);

	PyObject* OtherCapitalCosts_obj = OtherCapitalCosts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "OtherCapitalCosts", OtherCapitalCosts_obj);
	Py_DECREF(OtherCapitalCosts_obj);

	PyObject* IRRTargets_obj = IRRTargets_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "IRRTargets", IRRTargets_obj);
	Py_DECREF(IRRTargets_obj);

	PyObject* DeveloperCapitalRecovery_obj = DeveloperCapitalRecovery_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "DeveloperCapitalRecovery", DeveloperCapitalRecovery_obj);
	Py_DECREF(DeveloperCapitalRecovery_obj);

	PyObject* LCOS_obj = LCOS_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "LCOS", LCOS_obj);
	Py_DECREF(LCOS_obj);

	PyObject* ChargesByMonth_obj = ChargesByMonth_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ChargesByMonth", ChargesByMonth_obj);
	Py_DECREF(ChargesByMonth_obj);

	PyObject* BatterySystem_obj = BatterySystem_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "BatterySystem", BatterySystem_obj);
	Py_DECREF(BatterySystem_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Equpartflip methods */

static void
Equpartflip_dealloc(CmodObject *self)
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
Equpartflip_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Equpartflip_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Equpartflip_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Equpartflip"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Equpartflip_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Equpartflip"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Equpartflip_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Equpartflip_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Equpartflip_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Equpartflip_methods[] = {
		{"execute",           (PyCFunction)Equpartflip_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Equpartflip_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Revenue': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Equpartflip_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Revenue': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Equpartflip_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Equpartflip_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Equpartflip_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Equpartflip_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Equpartflip_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Equpartflip_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Equpartflip",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Equpartflip_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Equpartflip_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Equpartflip_getattro, /*tp_getattro*/
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
		Equpartflip_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Equpartflip object */

static PyObject *
Equpartflip_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newEqupartflipObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Equpartflip_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newEqupartflipObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Equpartflip_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newEqupartflipObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Equpartflip", def) < 0) {
		Equpartflip_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Equpartflip_from_existing(PyObject *self, PyObject *args)
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

	rv = newEqupartflipObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Equpartflip", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef EqupartflipModule_methods[] = {
		{"new",             Equpartflip_new,         METH_VARARGS,
				PyDoc_STR("new() -> Equpartflip")},
		{"default",             Equpartflip_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Equpartflip\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"BiopowerAllEquityPartnershipFlip\"*\n\n		- *\"DSLFAllEquityPartnershipFlip\"*\n\n		- *\"EmpiricalTroughAllEquityPartnershipFlip\"*\n\n		- *\"FlatPlatePVAllEquityPartnershipFlip\"*\n\n		- *\"GenericBatteryAllEquityPartnershipFlip\"*\n\n		- *\"GenericCSPSystemAllEquityPartnershipFlip\"*\n\n		- *\"GenericSystemAllEquityPartnershipFlip\"*\n\n		- *\"GeothermalPowerAllEquityPartnershipFlip\"*\n\n		- *\"HighXConcentratingPVAllEquityPartnershipFlip\"*\n\n		- *\"MSLFAllEquityPartnershipFlip\"*\n\n		- *\"MSPTAllEquityPartnershipFlip\"*\n\n		- *\"PVBatteryAllEquityPartnershipFlip\"*\n\n		- *\"PVWattsAllEquityPartnershipFlip\"*\n\n		- *\"PhysicalTroughAllEquityPartnershipFlip\"*\n\n		- *\"StandaloneBatteryAllEquityPartnershipFlip\"*\n\n		- *\"WindPowerAllEquityPartnershipFlip\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Equpartflip_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Equpartflip\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Equpartflip_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Equpartflip\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "PPA all equity partnership flip (no debt) financial model");


static int
EqupartflipModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Equpartflip_Type.tp_dict = PyDict_New();
	if (!Equpartflip_Type.tp_dict) { goto fail; }

	/// Add the Revenue type object to Equpartflip_Type
	if (PyType_Ready(&Revenue_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"Revenue",
				(PyObject*)&Revenue_Type);
	Py_DECREF(&Revenue_Type);

	/// Add the FinancialParameters type object to Equpartflip_Type
	if (PyType_Ready(&FinancialParameters_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"FinancialParameters",
				(PyObject*)&FinancialParameters_Type);
	Py_DECREF(&FinancialParameters_Type);

	/// Add the SystemCosts type object to Equpartflip_Type
	if (PyType_Ready(&SystemCosts_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"SystemCosts",
				(PyObject*)&SystemCosts_Type);
	Py_DECREF(&SystemCosts_Type);

	/// Add the LandLease type object to Equpartflip_Type
	if (PyType_Ready(&LandLease_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"LandLease",
				(PyObject*)&LandLease_Type);
	Py_DECREF(&LandLease_Type);

	/// Add the TaxCreditIncentives type object to Equpartflip_Type
	if (PyType_Ready(&TaxCreditIncentives_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"TaxCreditIncentives",
				(PyObject*)&TaxCreditIncentives_Type);
	Py_DECREF(&TaxCreditIncentives_Type);

	/// Add the Depreciation type object to Equpartflip_Type
	if (PyType_Ready(&Depreciation_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"Depreciation",
				(PyObject*)&Depreciation_Type);
	Py_DECREF(&Depreciation_Type);

	/// Add the PaymentIncentives type object to Equpartflip_Type
	if (PyType_Ready(&PaymentIncentives_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"PaymentIncentives",
				(PyObject*)&PaymentIncentives_Type);
	Py_DECREF(&PaymentIncentives_Type);

	/// Add the SystemOutput type object to Equpartflip_Type
	if (PyType_Ready(&SystemOutput_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"SystemOutput",
				(PyObject*)&SystemOutput_Type);
	Py_DECREF(&SystemOutput_Type);

	/// Add the ElectricityRates type object to Equpartflip_Type
	if (PyType_Ready(&ElectricityRates_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"ElectricityRates",
				(PyObject*)&ElectricityRates_Type);
	Py_DECREF(&ElectricityRates_Type);

	/// Add the Recapitalization type object to Equpartflip_Type
	if (PyType_Ready(&Recapitalization_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"Recapitalization",
				(PyObject*)&Recapitalization_Type);
	Py_DECREF(&Recapitalization_Type);

	/// Add the TimeOfDelivery type object to Equpartflip_Type
	if (PyType_Ready(&TimeOfDelivery_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"TimeOfDelivery",
				(PyObject*)&TimeOfDelivery_Type);
	Py_DECREF(&TimeOfDelivery_Type);

	/// Add the UtilityBill type object to Equpartflip_Type
	if (PyType_Ready(&UtilityBill_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"UtilityBill",
				(PyObject*)&UtilityBill_Type);
	Py_DECREF(&UtilityBill_Type);

	/// Add the ConstructionFinancing type object to Equpartflip_Type
	if (PyType_Ready(&ConstructionFinancing_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"ConstructionFinancing",
				(PyObject*)&ConstructionFinancing_Type);
	Py_DECREF(&ConstructionFinancing_Type);

	/// Add the OtherCapitalCosts type object to Equpartflip_Type
	if (PyType_Ready(&OtherCapitalCosts_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"OtherCapitalCosts",
				(PyObject*)&OtherCapitalCosts_Type);
	Py_DECREF(&OtherCapitalCosts_Type);

	/// Add the IRRTargets type object to Equpartflip_Type
	if (PyType_Ready(&IRRTargets_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"IRRTargets",
				(PyObject*)&IRRTargets_Type);
	Py_DECREF(&IRRTargets_Type);

	/// Add the DeveloperCapitalRecovery type object to Equpartflip_Type
	if (PyType_Ready(&DeveloperCapitalRecovery_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"DeveloperCapitalRecovery",
				(PyObject*)&DeveloperCapitalRecovery_Type);
	Py_DECREF(&DeveloperCapitalRecovery_Type);

	/// Add the LCOS type object to Equpartflip_Type
	if (PyType_Ready(&LCOS_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"LCOS",
				(PyObject*)&LCOS_Type);
	Py_DECREF(&LCOS_Type);

	/// Add the ChargesByMonth type object to Equpartflip_Type
	if (PyType_Ready(&ChargesByMonth_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"ChargesByMonth",
				(PyObject*)&ChargesByMonth_Type);
	Py_DECREF(&ChargesByMonth_Type);

	/// Add the BatterySystem type object to Equpartflip_Type
	if (PyType_Ready(&BatterySystem_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"BatterySystem",
				(PyObject*)&BatterySystem_Type);
	Py_DECREF(&BatterySystem_Type);

	/// Add the Outputs type object to Equpartflip_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Equpartflip_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Equpartflip type object to the module
	if (PyType_Ready(&Equpartflip_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Equpartflip",
				(PyObject*)&Equpartflip_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot EqupartflipModule_slots[] = {
		{Py_mod_exec, EqupartflipModule_exec},
		{0, NULL},
};

static struct PyModuleDef EqupartflipModule = {
		PyModuleDef_HEAD_INIT,
		"Equpartflip",
		module_doc,
		0,
		EqupartflipModule_methods,
		EqupartflipModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Equpartflip(void)
{
	return PyModuleDef_Init(&EqupartflipModule);
}