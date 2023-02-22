#include <Python.h>

#include <SAM_Ippppa.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * FinancialParameters Group
 */ 

static PyTypeObject FinancialParameters_Type;

static PyObject *
FinancialParameters_new(SAM_Ippppa data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Ippppa", "FinancialParameters")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Ippppa", "FinancialParameters")){
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
	return PySAM_double_getter(SAM_Ippppa_FinancialParameters_analysis_period_nget, self->data_ptr);
}

static int
FinancialParameters_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_FinancialParameters_analysis_period_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_debt_fraction(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_FinancialParameters_debt_fraction_nget, self->data_ptr);
}

static int
FinancialParameters_set_debt_fraction(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_FinancialParameters_debt_fraction_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_federal_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_FinancialParameters_federal_tax_rate_aget, self->data_ptr);
}

static int
FinancialParameters_set_federal_tax_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_FinancialParameters_federal_tax_rate_aset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_inflation_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_FinancialParameters_inflation_rate_nget, self->data_ptr);
}

static int
FinancialParameters_set_inflation_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_FinancialParameters_inflation_rate_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_insurance_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_FinancialParameters_insurance_rate_nget, self->data_ptr);
}

static int
FinancialParameters_set_insurance_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_FinancialParameters_insurance_rate_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_loan_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_FinancialParameters_loan_rate_nget, self->data_ptr);
}

static int
FinancialParameters_set_loan_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_FinancialParameters_loan_rate_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_loan_term(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_FinancialParameters_loan_term_nget, self->data_ptr);
}

static int
FinancialParameters_set_loan_term(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_FinancialParameters_loan_term_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_prop_tax_assessed_decline(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_FinancialParameters_prop_tax_assessed_decline_nget, self->data_ptr);
}

static int
FinancialParameters_set_prop_tax_assessed_decline(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_FinancialParameters_prop_tax_assessed_decline_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_prop_tax_cost_assessed_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_FinancialParameters_prop_tax_cost_assessed_percent_nget, self->data_ptr);
}

static int
FinancialParameters_set_prop_tax_cost_assessed_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_FinancialParameters_prop_tax_cost_assessed_percent_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_property_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_FinancialParameters_property_tax_rate_nget, self->data_ptr);
}

static int
FinancialParameters_set_property_tax_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_FinancialParameters_property_tax_rate_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_real_discount_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_FinancialParameters_real_discount_rate_nget, self->data_ptr);
}

static int
FinancialParameters_set_real_discount_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_FinancialParameters_real_discount_rate_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_state_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_FinancialParameters_state_tax_rate_aget, self->data_ptr);
}

static int
FinancialParameters_set_state_tax_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_FinancialParameters_state_tax_rate_aset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_FinancialParameters_system_capacity_nget, self->data_ptr);
}

static int
FinancialParameters_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_FinancialParameters_system_capacity_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_system_heat_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_FinancialParameters_system_heat_rate_nget, self->data_ptr);
}

static int
FinancialParameters_set_system_heat_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_FinancialParameters_system_heat_rate_nset, self->data_ptr);
}

static PyGetSetDef FinancialParameters_getset[] = {
{"analysis_period", (getter)FinancialParameters_get_analysis_period,(setter)FinancialParameters_set_analysis_period,
	PyDoc_STR("*float*: Analyis period [years]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=50\n\n**Required:**\nFalse. Automatically set to 30 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"debt_fraction", (getter)FinancialParameters_get_debt_fraction,(setter)FinancialParameters_set_debt_fraction,
	PyDoc_STR("*float*: Debt percentage [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
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
{"loan_rate", (getter)FinancialParameters_get_loan_rate,(setter)FinancialParameters_set_loan_rate,
	PyDoc_STR("*float*: Loan rate [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"loan_term", (getter)FinancialParameters_get_loan_term,(setter)FinancialParameters_set_loan_term,
	PyDoc_STR("*float*: Loan term [years]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=50\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
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
		"Ippppa.FinancialParameters",             /*tp_name*/
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
SystemCosts_new(SAM_Ippppa data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Ippppa", "SystemCosts")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Ippppa", "SystemCosts")){
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
	return PySAM_double_getter(SAM_Ippppa_SystemCosts_add_om_num_types_nget, self->data_ptr);
}

static int
SystemCosts_set_add_om_num_types(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_SystemCosts_add_om_num_types_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_annual_fuel_usage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_SystemCosts_annual_fuel_usage_nget, self->data_ptr);
}

static int
SystemCosts_set_annual_fuel_usage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_SystemCosts_annual_fuel_usage_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_annual_fuel_usage_lifetime(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_SystemCosts_annual_fuel_usage_lifetime_aget, self->data_ptr);
}

static int
SystemCosts_set_annual_fuel_usage_lifetime(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_SystemCosts_annual_fuel_usage_lifetime_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_fuelcell_annual_energy_discharged(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_SystemCosts_fuelcell_annual_energy_discharged_aget, self->data_ptr);
}

static int
SystemCosts_set_fuelcell_annual_energy_discharged(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_SystemCosts_fuelcell_annual_energy_discharged_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_batt_capacity_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_SystemCosts_om_batt_capacity_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_batt_capacity_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_SystemCosts_om_batt_capacity_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_batt_fixed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_SystemCosts_om_batt_fixed_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_batt_fixed_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_SystemCosts_om_batt_fixed_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_batt_nameplate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_SystemCosts_om_batt_nameplate_nget, self->data_ptr);
}

static int
SystemCosts_set_om_batt_nameplate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_SystemCosts_om_batt_nameplate_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_batt_replacement_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_SystemCosts_om_batt_replacement_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_batt_replacement_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_SystemCosts_om_batt_replacement_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_batt_variable_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_SystemCosts_om_batt_variable_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_batt_variable_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_SystemCosts_om_batt_variable_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_SystemCosts_om_capacity_aget, self->data_ptr);
}

static int
SystemCosts_set_om_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_SystemCosts_om_capacity_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_capacity_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_SystemCosts_om_capacity_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_capacity_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_SystemCosts_om_capacity_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_SystemCosts_om_fixed_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_SystemCosts_om_fixed_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fixed_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_SystemCosts_om_fixed_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_fixed_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_SystemCosts_om_fixed_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuel_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_SystemCosts_om_fuel_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fuel_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_SystemCosts_om_fuel_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuel_cost_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_SystemCosts_om_fuel_cost_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_fuel_cost_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_SystemCosts_om_fuel_cost_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuelcell_capacity_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_SystemCosts_om_fuelcell_capacity_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fuelcell_capacity_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_SystemCosts_om_fuelcell_capacity_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuelcell_fixed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_SystemCosts_om_fuelcell_fixed_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fuelcell_fixed_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_SystemCosts_om_fuelcell_fixed_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuelcell_nameplate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_SystemCosts_om_fuelcell_nameplate_nget, self->data_ptr);
}

static int
SystemCosts_set_om_fuelcell_nameplate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_SystemCosts_om_fuelcell_nameplate_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuelcell_replacement_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_SystemCosts_om_fuelcell_replacement_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fuelcell_replacement_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_SystemCosts_om_fuelcell_replacement_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuelcell_variable_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_SystemCosts_om_fuelcell_variable_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fuelcell_variable_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_SystemCosts_om_fuelcell_variable_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_1_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_SystemCosts_om_opt_fuel_1_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_1_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_SystemCosts_om_opt_fuel_1_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_1_cost_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_SystemCosts_om_opt_fuel_1_cost_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_1_cost_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_SystemCosts_om_opt_fuel_1_cost_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_1_usage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_SystemCosts_om_opt_fuel_1_usage_nget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_1_usage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_SystemCosts_om_opt_fuel_1_usage_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_2_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_SystemCosts_om_opt_fuel_2_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_2_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_SystemCosts_om_opt_fuel_2_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_2_cost_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_SystemCosts_om_opt_fuel_2_cost_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_2_cost_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_SystemCosts_om_opt_fuel_2_cost_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_2_usage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_SystemCosts_om_opt_fuel_2_usage_nget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_2_usage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_SystemCosts_om_opt_fuel_2_usage_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_SystemCosts_om_production_aget, self->data_ptr);
}

static int
SystemCosts_set_om_production(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_SystemCosts_om_production_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production1_values(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_SystemCosts_om_production1_values_aget, self->data_ptr);
}

static int
SystemCosts_set_om_production1_values(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_SystemCosts_om_production1_values_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production2_values(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_SystemCosts_om_production2_values_aget, self->data_ptr);
}

static int
SystemCosts_set_om_production2_values(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_SystemCosts_om_production2_values_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_SystemCosts_om_production_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_production_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_SystemCosts_om_production_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_replacement_cost_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_SystemCosts_om_replacement_cost_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_replacement_cost_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_SystemCosts_om_replacement_cost_escal_nset, self->data_ptr);
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
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Ippppa.SystemCosts",             /*tp_name*/
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
LandLease_new(SAM_Ippppa data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Ippppa", "LandLease")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Ippppa", "LandLease")){
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
	return PySAM_double_getter(SAM_Ippppa_LandLease_land_area_nget, self->data_ptr);
}

static int
LandLease_set_land_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_LandLease_land_area_nset, self->data_ptr);
}

static PyObject *
LandLease_get_om_land_lease(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_LandLease_om_land_lease_aget, self->data_ptr);
}

static int
LandLease_set_om_land_lease(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_LandLease_om_land_lease_aset, self->data_ptr);
}

static PyObject *
LandLease_get_om_land_lease_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_LandLease_om_land_lease_escal_nget, self->data_ptr);
}

static int
LandLease_set_om_land_lease_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_LandLease_om_land_lease_escal_nset, self->data_ptr);
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
		"Ippppa.LandLease",             /*tp_name*/
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
 * Depreciation Group
 */ 

static PyTypeObject Depreciation_Type;

static PyObject *
Depreciation_new(SAM_Ippppa data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Ippppa", "Depreciation")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Ippppa", "Depreciation")){
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
	return PySAM_array_getter(SAM_Ippppa_Depreciation_depr_fed_custom_aget, self->data_ptr);
}

static int
Depreciation_set_depr_fed_custom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_Depreciation_depr_fed_custom_aset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_fed_sl_years(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Depreciation_depr_fed_sl_years_nget, self->data_ptr);
}

static int
Depreciation_set_depr_fed_sl_years(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Depreciation_depr_fed_sl_years_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_fed_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Depreciation_depr_fed_type_nget, self->data_ptr);
}

static int
Depreciation_set_depr_fed_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Depreciation_depr_fed_type_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_sta_custom(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Depreciation_depr_sta_custom_aget, self->data_ptr);
}

static int
Depreciation_set_depr_sta_custom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_Depreciation_depr_sta_custom_aset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_sta_sl_years(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Depreciation_depr_sta_sl_years_nget, self->data_ptr);
}

static int
Depreciation_set_depr_sta_sl_years(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Depreciation_depr_sta_sl_years_nset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_sta_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Depreciation_depr_sta_type_nget, self->data_ptr);
}

static int
Depreciation_set_depr_sta_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Depreciation_depr_sta_type_nset, self->data_ptr);
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
		"Ippppa.Depreciation",             /*tp_name*/
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
 * TaxCreditIncentives Group
 */ 

static PyTypeObject TaxCreditIncentives_Type;

static PyObject *
TaxCreditIncentives_new(SAM_Ippppa data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Ippppa", "TaxCreditIncentives")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Ippppa", "TaxCreditIncentives")){
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
	return PySAM_array_getter(SAM_Ippppa_TaxCreditIncentives_itc_fed_amount_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_TaxCreditIncentives_itc_fed_amount_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_amount_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_TaxCreditIncentives_itc_fed_amount_deprbas_fed_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_amount_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_TaxCreditIncentives_itc_fed_amount_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_amount_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_TaxCreditIncentives_itc_fed_amount_deprbas_sta_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_amount_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_TaxCreditIncentives_itc_fed_amount_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_TaxCreditIncentives_itc_fed_percent_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_TaxCreditIncentives_itc_fed_percent_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_TaxCreditIncentives_itc_fed_percent_deprbas_fed_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_TaxCreditIncentives_itc_fed_percent_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_TaxCreditIncentives_itc_fed_percent_deprbas_sta_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_TaxCreditIncentives_itc_fed_percent_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_TaxCreditIncentives_itc_fed_percent_maxvalue_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_TaxCreditIncentives_itc_fed_percent_maxvalue_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_TaxCreditIncentives_itc_sta_amount_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_TaxCreditIncentives_itc_sta_amount_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_amount_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_TaxCreditIncentives_itc_sta_amount_deprbas_fed_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_amount_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_TaxCreditIncentives_itc_sta_amount_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_amount_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_TaxCreditIncentives_itc_sta_amount_deprbas_sta_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_amount_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_TaxCreditIncentives_itc_sta_amount_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_TaxCreditIncentives_itc_sta_percent_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_TaxCreditIncentives_itc_sta_percent_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_TaxCreditIncentives_itc_sta_percent_deprbas_fed_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_TaxCreditIncentives_itc_sta_percent_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_TaxCreditIncentives_itc_sta_percent_deprbas_sta_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_TaxCreditIncentives_itc_sta_percent_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_TaxCreditIncentives_itc_sta_percent_maxvalue_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_TaxCreditIncentives_itc_sta_percent_maxvalue_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_fed_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_TaxCreditIncentives_ptc_fed_amount_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_fed_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_TaxCreditIncentives_ptc_fed_amount_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_fed_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_TaxCreditIncentives_ptc_fed_escal_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_fed_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_TaxCreditIncentives_ptc_fed_escal_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_fed_term(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_TaxCreditIncentives_ptc_fed_term_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_fed_term(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_TaxCreditIncentives_ptc_fed_term_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_sta_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_TaxCreditIncentives_ptc_sta_amount_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_sta_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_TaxCreditIncentives_ptc_sta_amount_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_sta_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_TaxCreditIncentives_ptc_sta_escal_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_sta_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_TaxCreditIncentives_ptc_sta_escal_nset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_sta_term(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_TaxCreditIncentives_ptc_sta_term_nget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_sta_term(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_TaxCreditIncentives_ptc_sta_term_nset, self->data_ptr);
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
		"Ippppa.TaxCreditIncentives",             /*tp_name*/
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
 * PaymentIncentives Group
 */ 

static PyTypeObject PaymentIncentives_Type;

static PyObject *
PaymentIncentives_new(SAM_Ippppa data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Ippppa", "PaymentIncentives")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Ippppa", "PaymentIncentives")){
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
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_fed_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_fed_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_fed_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_fed_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_fed_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_fed_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_fed_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_fed_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_fed_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_fed_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_fed_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_fed_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_oth_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_oth_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_oth_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_oth_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_oth_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_oth_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_oth_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_oth_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_oth_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_oth_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_oth_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_oth_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_sta_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_sta_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_sta_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_sta_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_sta_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_sta_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_sta_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_sta_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_sta_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_sta_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_sta_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_sta_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_uti_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_uti_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_uti_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_uti_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_uti_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_uti_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_uti_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_uti_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_uti_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_uti_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_cbi_uti_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_cbi_uti_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_fed_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_fed_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_fed_amount_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_fed_amount_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_fed_amount_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_fed_amount_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_fed_amount_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_fed_amount_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_fed_amount_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_fed_amount_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_fed_percent_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_fed_percent_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_fed_percent_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_fed_percent_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_fed_percent_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_fed_percent_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_fed_percent_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_fed_percent_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_fed_percent_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_fed_percent_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_fed_percent_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_fed_percent_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_oth_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_oth_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_oth_amount_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_oth_amount_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_oth_amount_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_oth_amount_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_oth_amount_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_oth_amount_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_oth_amount_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_oth_amount_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_oth_percent_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_oth_percent_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_oth_percent_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_oth_percent_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_oth_percent_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_oth_percent_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_oth_percent_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_oth_percent_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_oth_percent_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_oth_percent_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_oth_percent_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_oth_percent_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_sta_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_sta_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_sta_amount_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_sta_amount_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_sta_amount_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_sta_amount_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_sta_amount_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_sta_amount_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_sta_amount_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_sta_amount_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_sta_percent_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_sta_percent_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_sta_percent_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_sta_percent_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_sta_percent_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_sta_percent_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_sta_percent_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_sta_percent_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_sta_percent_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_sta_percent_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_sta_percent_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_sta_percent_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_uti_amount_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_uti_amount_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_uti_amount_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_uti_amount_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_uti_amount_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_uti_amount_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_uti_amount_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_uti_amount_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_uti_amount_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_uti_amount_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_uti_percent_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_uti_percent_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_deprbas_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_uti_percent_deprbas_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_deprbas_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_uti_percent_deprbas_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_deprbas_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_uti_percent_deprbas_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_deprbas_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_uti_percent_deprbas_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_maxvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_uti_percent_maxvalue_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_maxvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_uti_percent_maxvalue_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_uti_percent_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_uti_percent_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_ibi_uti_percent_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_ibi_uti_percent_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_PaymentIncentives_pbi_fed_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_PaymentIncentives_pbi_fed_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_pbi_fed_escal_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_pbi_fed_escal_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_pbi_fed_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_pbi_fed_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_pbi_fed_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_pbi_fed_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_term(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_pbi_fed_term_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_term(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_pbi_fed_term_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_PaymentIncentives_pbi_oth_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_PaymentIncentives_pbi_oth_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_pbi_oth_escal_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_pbi_oth_escal_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_pbi_oth_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_pbi_oth_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_pbi_oth_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_pbi_oth_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_term(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_pbi_oth_term_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_term(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_pbi_oth_term_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_PaymentIncentives_pbi_sta_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_PaymentIncentives_pbi_sta_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_pbi_sta_escal_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_pbi_sta_escal_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_pbi_sta_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_pbi_sta_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_pbi_sta_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_pbi_sta_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_term(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_pbi_sta_term_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_term(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_pbi_sta_term_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_PaymentIncentives_pbi_uti_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_amount(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_PaymentIncentives_pbi_uti_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_pbi_uti_escal_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_pbi_uti_escal_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_tax_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_pbi_uti_tax_fed_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_tax_fed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_pbi_uti_tax_fed_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_tax_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_pbi_uti_tax_sta_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_tax_sta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_pbi_uti_tax_sta_nset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_term(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_PaymentIncentives_pbi_uti_term_nget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_term(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_PaymentIncentives_pbi_uti_term_nset, self->data_ptr);
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
		"Ippppa.PaymentIncentives",             /*tp_name*/
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
 * Common Group
 */ 

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_Ippppa data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Ippppa", "Common")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Ippppa", "Common")){
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
Common_get_bid_price(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Common_bid_price_aget, self->data_ptr);
}

static int
Common_set_bid_price(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_Common_bid_price_aset, self->data_ptr);
}

static PyObject *
Common_get_bid_price_esc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_bid_price_esc_nget, self->data_ptr);
}

static int
Common_set_bid_price_esc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_bid_price_esc_nset, self->data_ptr);
}

static PyObject *
Common_get_construction_financing_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_construction_financing_cost_nget, self->data_ptr);
}

static int
Common_set_construction_financing_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_construction_financing_cost_nset, self->data_ptr);
}

static PyObject *
Common_get_degradation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Common_degradation_aget, self->data_ptr);
}

static int
Common_set_degradation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_Common_degradation_aset, self->data_ptr);
}

static PyObject *
Common_get_dispatch_factor1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_dispatch_factor1_nget, self->data_ptr);
}

static int
Common_set_dispatch_factor1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_dispatch_factor1_nset, self->data_ptr);
}

static PyObject *
Common_get_dispatch_factor2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_dispatch_factor2_nget, self->data_ptr);
}

static int
Common_set_dispatch_factor2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_dispatch_factor2_nset, self->data_ptr);
}

static PyObject *
Common_get_dispatch_factor3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_dispatch_factor3_nget, self->data_ptr);
}

static int
Common_set_dispatch_factor3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_dispatch_factor3_nset, self->data_ptr);
}

static PyObject *
Common_get_dispatch_factor4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_dispatch_factor4_nget, self->data_ptr);
}

static int
Common_set_dispatch_factor4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_dispatch_factor4_nset, self->data_ptr);
}

static PyObject *
Common_get_dispatch_factor5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_dispatch_factor5_nget, self->data_ptr);
}

static int
Common_set_dispatch_factor5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_dispatch_factor5_nset, self->data_ptr);
}

static PyObject *
Common_get_dispatch_factor6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_dispatch_factor6_nget, self->data_ptr);
}

static int
Common_set_dispatch_factor6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_dispatch_factor6_nset, self->data_ptr);
}

static PyObject *
Common_get_dispatch_factor7(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_dispatch_factor7_nget, self->data_ptr);
}

static int
Common_set_dispatch_factor7(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_dispatch_factor7_nset, self->data_ptr);
}

static PyObject *
Common_get_dispatch_factor8(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_dispatch_factor8_nget, self->data_ptr);
}

static int
Common_set_dispatch_factor8(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_dispatch_factor8_nset, self->data_ptr);
}

static PyObject *
Common_get_dispatch_factor9(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_dispatch_factor9_nget, self->data_ptr);
}

static int
Common_set_dispatch_factor9(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_dispatch_factor9_nset, self->data_ptr);
}

static PyObject *
Common_get_dispatch_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Ippppa_Common_dispatch_sched_weekday_mget, self->data_ptr);
}

static int
Common_set_dispatch_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Ippppa_Common_dispatch_sched_weekday_mset, self->data_ptr);
}

static PyObject *
Common_get_dispatch_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Ippppa_Common_dispatch_sched_weekend_mget, self->data_ptr);
}

static int
Common_set_dispatch_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Ippppa_Common_dispatch_sched_weekend_mset, self->data_ptr);
}

static PyObject *
Common_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Common_gen_aget, self->data_ptr);
}

static int
Common_set_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_Common_gen_aset, self->data_ptr);
}

static PyObject *
Common_get_market(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_market_nget, self->data_ptr);
}

static int
Common_set_market(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_market_nset, self->data_ptr);
}

static PyObject *
Common_get_min_dscr_required(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_min_dscr_required_nget, self->data_ptr);
}

static int
Common_set_min_dscr_required(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_min_dscr_required_nset, self->data_ptr);
}

static PyObject *
Common_get_min_dscr_target(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_min_dscr_target_nget, self->data_ptr);
}

static int
Common_set_min_dscr_target(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_min_dscr_target_nset, self->data_ptr);
}

static PyObject *
Common_get_min_irr_target(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_min_irr_target_nget, self->data_ptr);
}

static int
Common_set_min_irr_target(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_min_irr_target_nset, self->data_ptr);
}

static PyObject *
Common_get_optimize_lcoe_wrt_debt_fraction(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_optimize_lcoe_wrt_debt_fraction_nget, self->data_ptr);
}

static int
Common_set_optimize_lcoe_wrt_debt_fraction(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_optimize_lcoe_wrt_debt_fraction_nset, self->data_ptr);
}

static PyObject *
Common_get_optimize_lcoe_wrt_ppa_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_optimize_lcoe_wrt_ppa_escalation_nget, self->data_ptr);
}

static int
Common_set_optimize_lcoe_wrt_ppa_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_optimize_lcoe_wrt_ppa_escalation_nset, self->data_ptr);
}

static PyObject *
Common_get_positive_cashflow_required(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_positive_cashflow_required_nget, self->data_ptr);
}

static int
Common_set_positive_cashflow_required(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_positive_cashflow_required_nset, self->data_ptr);
}

static PyObject *
Common_get_ppa_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_ppa_escalation_nget, self->data_ptr);
}

static int
Common_set_ppa_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_ppa_escalation_nset, self->data_ptr);
}

static PyObject *
Common_get_ppa_soln_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_ppa_soln_max_nget, self->data_ptr);
}

static int
Common_set_ppa_soln_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_ppa_soln_max_nset, self->data_ptr);
}

static PyObject *
Common_get_ppa_soln_max_iterations(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_ppa_soln_max_iterations_nget, self->data_ptr);
}

static int
Common_set_ppa_soln_max_iterations(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_ppa_soln_max_iterations_nset, self->data_ptr);
}

static PyObject *
Common_get_ppa_soln_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_ppa_soln_min_nget, self->data_ptr);
}

static int
Common_set_ppa_soln_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_ppa_soln_min_nset, self->data_ptr);
}

static PyObject *
Common_get_ppa_soln_tolerance(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_ppa_soln_tolerance_nget, self->data_ptr);
}

static int
Common_set_ppa_soln_tolerance(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_ppa_soln_tolerance_nset, self->data_ptr);
}

static PyObject *
Common_get_salvage_percentage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_salvage_percentage_nget, self->data_ptr);
}

static int
Common_set_salvage_percentage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_salvage_percentage_nset, self->data_ptr);
}

static PyObject *
Common_get_soln_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_soln_mode_nget, self->data_ptr);
}

static int
Common_set_soln_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_soln_mode_nset, self->data_ptr);
}

static PyObject *
Common_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_system_capacity_nget, self->data_ptr);
}

static int
Common_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_system_capacity_nset, self->data_ptr);
}

static PyObject *
Common_get_system_recapitalization_boolean(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Common_system_recapitalization_boolean_aget, self->data_ptr);
}

static int
Common_set_system_recapitalization_boolean(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Ippppa_Common_system_recapitalization_boolean_aset, self->data_ptr);
}

static PyObject *
Common_get_system_recapitalization_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_system_recapitalization_cost_nget, self->data_ptr);
}

static int
Common_set_system_recapitalization_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_system_recapitalization_cost_nset, self->data_ptr);
}

static PyObject *
Common_get_system_recapitalization_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_system_recapitalization_escalation_nget, self->data_ptr);
}

static int
Common_set_system_recapitalization_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_system_recapitalization_escalation_nset, self->data_ptr);
}

static PyObject *
Common_get_system_use_lifetime_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_system_use_lifetime_output_nget, self->data_ptr);
}

static int
Common_set_system_use_lifetime_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_system_use_lifetime_output_nset, self->data_ptr);
}

static PyObject *
Common_get_system_use_recapitalization(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_system_use_recapitalization_nget, self->data_ptr);
}

static int
Common_set_system_use_recapitalization(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_system_use_recapitalization_nset, self->data_ptr);
}

static PyObject *
Common_get_total_installed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Common_total_installed_cost_nget, self->data_ptr);
}

static int
Common_set_total_installed_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Ippppa_Common_total_installed_cost_nset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"bid_price", (getter)Common_get_bid_price,(setter)Common_set_bid_price,
	PyDoc_STR("*sequence*: Initial year PPA price [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.10 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"bid_price_esc", (getter)Common_get_bid_price_esc,(setter)Common_set_bid_price_esc,
	PyDoc_STR("*float*: PPA escalation [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"construction_financing_cost", (getter)Common_get_construction_financing_cost,(setter)Common_set_construction_financing_cost,
	PyDoc_STR("*float*: Construction financing total [$]\n\n**Required:**\nTrue"),
 	NULL},
{"degradation", (getter)Common_get_degradation,(setter)Common_set_degradation,
	PyDoc_STR("*sequence*: Annual energy degradation\n\n**Required:**\nTrue"),
 	NULL},
{"dispatch_factor1", (getter)Common_get_dispatch_factor1,(setter)Common_set_dispatch_factor1,
	PyDoc_STR("*float*: Dispatch payment factor 1\n\n**Required:**\nRequired if market=0"),
 	NULL},
{"dispatch_factor2", (getter)Common_get_dispatch_factor2,(setter)Common_set_dispatch_factor2,
	PyDoc_STR("*float*: Dispatch payment factor 2\n\n**Required:**\nRequired if market=0"),
 	NULL},
{"dispatch_factor3", (getter)Common_get_dispatch_factor3,(setter)Common_set_dispatch_factor3,
	PyDoc_STR("*float*: Dispatch payment factor 3\n\n**Required:**\nRequired if market=0"),
 	NULL},
{"dispatch_factor4", (getter)Common_get_dispatch_factor4,(setter)Common_set_dispatch_factor4,
	PyDoc_STR("*float*: Dispatch payment factor 4\n\n**Required:**\nRequired if market=0"),
 	NULL},
{"dispatch_factor5", (getter)Common_get_dispatch_factor5,(setter)Common_set_dispatch_factor5,
	PyDoc_STR("*float*: Dispatch payment factor 5\n\n**Required:**\nRequired if market=0"),
 	NULL},
{"dispatch_factor6", (getter)Common_get_dispatch_factor6,(setter)Common_set_dispatch_factor6,
	PyDoc_STR("*float*: Dispatch payment factor 6\n\n**Required:**\nRequired if market=0"),
 	NULL},
{"dispatch_factor7", (getter)Common_get_dispatch_factor7,(setter)Common_set_dispatch_factor7,
	PyDoc_STR("*float*: Dispatch payment factor 7\n\n**Required:**\nRequired if market=0"),
 	NULL},
{"dispatch_factor8", (getter)Common_get_dispatch_factor8,(setter)Common_set_dispatch_factor8,
	PyDoc_STR("*float*: Dispatch payment factor 8\n\n**Required:**\nRequired if market=0"),
 	NULL},
{"dispatch_factor9", (getter)Common_get_dispatch_factor9,(setter)Common_set_dispatch_factor9,
	PyDoc_STR("*float*: Dispatch payment factor 9\n\n**Required:**\nRequired if market=0"),
 	NULL},
{"dispatch_sched_weekday", (getter)Common_get_dispatch_sched_weekday,(setter)Common_set_dispatch_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: Diurnal weekday dispatch periods [1..9]\n\n**Info:**\n12 x 24 matrix\n\n**Required:**\nRequired if market=0"),
 	NULL},
{"dispatch_sched_weekend", (getter)Common_get_dispatch_sched_weekend,(setter)Common_set_dispatch_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Diurnal weekend dispatch periods [1..9]\n\n**Info:**\n12 x 24 matrix\n\n**Required:**\nRequired if market=0"),
 	NULL},
{"gen", (getter)Common_get_gen,(setter)Common_set_gen,
	PyDoc_STR("*sequence*: Power generated by renewable resource [kW]\n\n**Required:**\nTrue"),
 	NULL},
{"market", (getter)Common_get_market,(setter)Common_set_market,
	PyDoc_STR("*float*: Utility IPP or Commercial PPA [0/1]\n\n**Options:**\n0=ipp,1=ppa\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"min_dscr_required", (getter)Common_get_min_dscr_required,(setter)Common_set_min_dscr_required,
	PyDoc_STR("*float*: Minimum DSCR required [0/1]\n\n**Options:**\n0=no,1=yes\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"min_dscr_target", (getter)Common_get_min_dscr_target,(setter)Common_set_min_dscr_target,
	PyDoc_STR("*float*: Minimum required DSCR\n\n**Required:**\nFalse. Automatically set to 1.4 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"min_irr_target", (getter)Common_get_min_irr_target,(setter)Common_set_min_irr_target,
	PyDoc_STR("*float*: Minimum required IRR [%]\n\n**Required:**\nFalse. Automatically set to 15 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"optimize_lcoe_wrt_debt_fraction", (getter)Common_get_optimize_lcoe_wrt_debt_fraction,(setter)Common_set_optimize_lcoe_wrt_debt_fraction,
	PyDoc_STR("*float*: Optimize LCOE with respect to debt percent [0/1]\n\n**Options:**\n0=no,1=yes\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"optimize_lcoe_wrt_ppa_escalation", (getter)Common_get_optimize_lcoe_wrt_ppa_escalation,(setter)Common_set_optimize_lcoe_wrt_ppa_escalation,
	PyDoc_STR("*float*: Optimize LCOE with respect to PPA escalation [0/1]\n\n**Options:**\n0=no,1=yes\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"positive_cashflow_required", (getter)Common_get_positive_cashflow_required,(setter)Common_set_positive_cashflow_required,
	PyDoc_STR("*float*: Positive cash flow required [0/1]\n\n**Options:**\n0=no,1=yes\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ppa_escalation", (getter)Common_get_ppa_escalation,(setter)Common_set_ppa_escalation,
	PyDoc_STR("*float*: PPA escalation [%]\n\n**Required:**\nFalse. Automatically set to 0.6 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ppa_soln_max", (getter)Common_get_ppa_soln_max,(setter)Common_set_ppa_soln_max,
	PyDoc_STR("*float*: PPA solution maximum ppa [cents/kWh]\n\n**Required:**\nFalse. Automatically set to 100 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ppa_soln_max_iterations", (getter)Common_get_ppa_soln_max_iterations,(setter)Common_set_ppa_soln_max_iterations,
	PyDoc_STR("*float*: PPA solution maximum number of iterations\n\n**Constraints:**\nINTEGER,MIN=1\n\n**Required:**\nFalse. Automatically set to 100 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ppa_soln_min", (getter)Common_get_ppa_soln_min,(setter)Common_set_ppa_soln_min,
	PyDoc_STR("*float*: PPA solution minimum ppa [cents/kWh]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ppa_soln_tolerance", (getter)Common_get_ppa_soln_tolerance,(setter)Common_set_ppa_soln_tolerance,
	PyDoc_STR("*float*: PPA solution tolerance\n\n**Required:**\nFalse. Automatically set to 1e-3 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"salvage_percentage", (getter)Common_get_salvage_percentage,(setter)Common_set_salvage_percentage,
	PyDoc_STR("*float*: Salvage value percentage [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"soln_mode", (getter)Common_get_soln_mode,(setter)Common_set_soln_mode,
	PyDoc_STR("*float*: PPA solution mode [0/1]\n\n**Options:**\n0=solve ppa,1=specify ppa\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"system_capacity", (getter)Common_get_system_capacity,(setter)Common_set_system_capacity,
	PyDoc_STR("*float*: System nameplate capacity [kW]\n\n**Constraints:**\nMIN=1e-3\n\n**Required:**\nTrue"),
 	NULL},
{"system_recapitalization_boolean", (getter)Common_get_system_recapitalization_boolean,(setter)Common_set_system_recapitalization_boolean,
	PyDoc_STR("*sequence*: Recapitalization boolean\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"system_recapitalization_cost", (getter)Common_get_system_recapitalization_cost,(setter)Common_set_system_recapitalization_cost,
	PyDoc_STR("*float*: Recapitalization cost [$]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"system_recapitalization_escalation", (getter)Common_get_system_recapitalization_escalation,(setter)Common_set_system_recapitalization_escalation,
	PyDoc_STR("*float*: Recapitalization escalation (above inflation) [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"system_use_lifetime_output", (getter)Common_get_system_use_lifetime_output,(setter)Common_set_system_use_lifetime_output,
	PyDoc_STR("*float*: Lifetime hourly system outputs [0/1]\n\n**Options:**\n0=hourly first year,1=hourly lifetime\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nTrue"),
 	NULL},
{"system_use_recapitalization", (getter)Common_get_system_use_recapitalization,(setter)Common_set_system_use_recapitalization,
	PyDoc_STR("*float*: Recapitalization expenses [0/1]\n\n**Options:**\n0=None,1=Recapitalize\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"total_installed_cost", (getter)Common_get_total_installed_cost,(setter)Common_set_total_installed_cost,
	PyDoc_STR("*float*: Total installed cost [$]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Ippppa.Common",             /*tp_name*/
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
 * Outputs Group
 */ 

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Ippppa data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Ippppa", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Ippppa", "Outputs")){
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
Outputs_get_actual_debt_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_actual_debt_frac_nget, self->data_ptr);
}

static PyObject *
Outputs_get_actual_ppa_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_actual_ppa_escalation_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_fedtax_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_cbi_fedtax_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_statax_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_cbi_statax_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_cbi_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_cbi_total_fed_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_oth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_cbi_total_oth_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_cbi_total_sta_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_uti(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_cbi_total_uti_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_after_tax_cash_flow(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_after_tax_cash_flow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_after_tax_net_equity_cash_flow(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_after_tax_net_equity_cash_flow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_after_tax_net_equity_cost_flow(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_after_tax_net_equity_cost_flow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_debt_balance(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_debt_balance_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_debt_payment_interest(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_debt_payment_interest_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_debt_payment_principal(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_debt_payment_principal_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_debt_payment_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_debt_payment_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_deductible_expenses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_deductible_expenses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_degradation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_degradation_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_effective_tax_frac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_effective_tax_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_dispatch1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_dispatch2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_dispatch3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_dispatch4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_dispatch5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_dispatch6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_dispatch7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_dispatch8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_dispatch9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_monthly_firstyear_TOD1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_monthly_firstyear_TOD2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_monthly_firstyear_TOD3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_monthly_firstyear_TOD4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_monthly_firstyear_TOD5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_monthly_firstyear_TOD6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_monthly_firstyear_TOD7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_monthly_firstyear_TOD8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_monthly_firstyear_TOD9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_net_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_price(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_price_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_energy_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fed_depr_sched(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_fed_depr_sched_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fed_depreciation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_fed_depreciation_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fed_incentive_income_less_deductions(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_fed_incentive_income_less_deductions_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fed_income_taxes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_fed_income_taxes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fed_tax_savings(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_fed_tax_savings_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fed_taxable_income_less_deductions(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_fed_taxable_income_less_deductions_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_federal_tax_frac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_federal_tax_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_insurance_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_insurance_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_fed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_itc_fed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_fed_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_itc_fed_amount_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_fed_percent_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_itc_fed_percent_amount_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_sta(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_itc_sta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_sta_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_itc_sta_amount_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_sta_percent_amount(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_itc_sta_percent_amount_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_itc_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_itc_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_land_lease_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_land_lease_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_length(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_cf_length_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_net_salvage_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_net_salvage_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_capacity_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_om_capacity_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_fixed_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_om_fixed_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_fuel_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_om_fuel_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_opt_fuel_1_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_om_opt_fuel_1_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_opt_fuel_2_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_om_opt_fuel_2_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_production_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_om_production_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_operating_expenses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_operating_expenses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_operating_income(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_operating_income_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_fedtax_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_pbi_fedtax_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_statax_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_pbi_statax_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_pbi_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_fed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_pbi_total_fed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_oth(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_pbi_total_oth_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_sta(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_pbi_total_sta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_uti(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_pbi_total_uti_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_ppa_price(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_ppa_price_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pretax_dscr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_pretax_dscr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_property_tax_assessed_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_property_tax_assessed_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_property_tax_expense(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_property_tax_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_ptc_fed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_ptc_fed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_ptc_sta(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_ptc_sta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_ptc_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_ptc_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_recapitalization(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_recapitalization_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_apr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_aug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_dispatch1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_dispatch2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_dispatch3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_dispatch4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_dispatch5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_dispatch6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_dispatch7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_dispatch8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_dispatch9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_feb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_jan(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_jul(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_jun(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_mar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_may(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_monthly_firstyear_TOD1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_monthly_firstyear_TOD2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_monthly_firstyear_TOD3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_monthly_firstyear_TOD4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_monthly_firstyear_TOD5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_monthly_firstyear_TOD6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_monthly_firstyear_TOD7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_monthly_firstyear_TOD8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_monthly_firstyear_TOD9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_nov(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_oct(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_sep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_revenue_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sta_and_fed_tax_savings(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_sta_and_fed_tax_savings_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sta_depr_sched(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_sta_depr_sched_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sta_depreciation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_sta_depreciation_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sta_incentive_income_less_deductions(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_sta_incentive_income_less_deductions_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sta_income_taxes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_sta_income_taxes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sta_tax_savings(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_sta_tax_savings_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sta_taxable_income_less_deductions(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_sta_taxable_income_less_deductions_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_state_tax_frac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Ippppa_Outputs_cf_state_tax_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_debt_fraction(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_debt_fraction_nget, self->data_ptr);
}

static PyObject *
Outputs_get_effective_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_effective_tax_rate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_energy_dispatch1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_energy_dispatch2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_energy_dispatch3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_energy_dispatch4_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_energy_dispatch5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_energy_dispatch6_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch7(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_energy_dispatch7_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch8(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_energy_dispatch8_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch9(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_energy_dispatch9_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_energy_price1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_energy_price2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_energy_price3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_energy_price4_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_energy_price5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_energy_price6_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price7(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_energy_price7_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price8(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_energy_price8_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price9(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_energy_price9_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_revenue_dispatch1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_revenue_dispatch2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_revenue_dispatch3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_revenue_dispatch4_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_revenue_dispatch5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_revenue_dispatch6_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch7(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_revenue_dispatch7_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch8(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_revenue_dispatch8_nget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch9(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_firstyear_revenue_dispatch9_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_fedtax_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_ibi_fedtax_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_statax_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_ibi_statax_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_ibi_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_ibi_total_fed_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_oth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_ibi_total_oth_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_ibi_total_sta_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_uti(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_ibi_total_uti_nget, self->data_ptr);
}

static PyObject *
Outputs_get_irr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_irr_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_itc_fed_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_itc_sta_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_itc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_total_fed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_itc_total_fed_nget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_total_sta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_itc_total_sta_nget, self->data_ptr);
}

static PyObject *
Outputs_get_latcf_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_latcf_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_latcf_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_latcf_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoe_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_lcoe_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoe_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_lcoe_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_fed_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_lcoptc_fed_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_fed_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_lcoptc_fed_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_sta_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_lcoptc_sta_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_sta_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_lcoptc_sta_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lppa_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_lppa_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lppa_real(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_lppa_real_nget, self->data_ptr);
}

static PyObject *
Outputs_get_min_cashflow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_min_cashflow_nget, self->data_ptr);
}

static PyObject *
Outputs_get_min_dscr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_min_dscr_nget, self->data_ptr);
}

static PyObject *
Outputs_get_npv(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_npv_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ppa(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_ppa_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ppa_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_ppa_escalation_nget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_fuel(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_present_value_fuel_nget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_insandproptax(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_present_value_insandproptax_nget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_oandm(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_present_value_oandm_nget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_oandm_nonfuel(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_present_value_oandm_nonfuel_nget, self->data_ptr);
}

static PyObject *
Outputs_get_wacc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Ippppa_Outputs_wacc_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"actual_debt_frac", (getter)Outputs_get_actual_debt_frac,(setter)0,
	PyDoc_STR("*float*: Calculated debt fraction [%]"),
 	NULL},
{"actual_ppa_escalation", (getter)Outputs_get_actual_ppa_escalation,(setter)0,
	PyDoc_STR("*float*: Calculated ppa escalation [%]"),
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
	PyDoc_STR("*sequence*: After-tax cash flow [$]"),
 	NULL},
{"cf_after_tax_net_equity_cash_flow", (getter)Outputs_get_cf_after_tax_net_equity_cash_flow,(setter)0,
	PyDoc_STR("*sequence*: After-tax net equity cash flow [$]"),
 	NULL},
{"cf_after_tax_net_equity_cost_flow", (getter)Outputs_get_cf_after_tax_net_equity_cost_flow,(setter)0,
	PyDoc_STR("*sequence*: After-tax net equity cost flow [$]"),
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
{"cf_deductible_expenses", (getter)Outputs_get_cf_deductible_expenses,(setter)0,
	PyDoc_STR("*sequence*: Deductible expenses [$]"),
 	NULL},
{"cf_degradation", (getter)Outputs_get_cf_degradation,(setter)0,
	PyDoc_STR("*sequence*: Energy degradation [kWh]"),
 	NULL},
{"cf_effective_tax_frac", (getter)Outputs_get_cf_effective_tax_frac,(setter)0,
	PyDoc_STR("*sequence*: Effective income tax rate [frac]"),
 	NULL},
{"cf_energy_net", (getter)Outputs_get_cf_energy_net,(setter)0,
	PyDoc_STR("*sequence*: Energy [kWh]"),
 	NULL},
{"cf_energy_net_apr", (getter)Outputs_get_cf_energy_net_apr,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in April"),
 	NULL},
{"cf_energy_net_aug", (getter)Outputs_get_cf_energy_net_aug,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in August"),
 	NULL},
{"cf_energy_net_dec", (getter)Outputs_get_cf_energy_net_dec,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in December"),
 	NULL},
{"cf_energy_net_dispatch1", (getter)Outputs_get_cf_energy_net_dispatch1,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in dispatch period 1"),
 	NULL},
{"cf_energy_net_dispatch2", (getter)Outputs_get_cf_energy_net_dispatch2,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in dispatch period 2"),
 	NULL},
{"cf_energy_net_dispatch3", (getter)Outputs_get_cf_energy_net_dispatch3,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in dispatch period 3"),
 	NULL},
{"cf_energy_net_dispatch4", (getter)Outputs_get_cf_energy_net_dispatch4,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in dispatch period 4"),
 	NULL},
{"cf_energy_net_dispatch5", (getter)Outputs_get_cf_energy_net_dispatch5,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in dispatch period 5"),
 	NULL},
{"cf_energy_net_dispatch6", (getter)Outputs_get_cf_energy_net_dispatch6,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in dispatch period 6"),
 	NULL},
{"cf_energy_net_dispatch7", (getter)Outputs_get_cf_energy_net_dispatch7,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in dispatch period 7"),
 	NULL},
{"cf_energy_net_dispatch8", (getter)Outputs_get_cf_energy_net_dispatch8,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in dispatch period 8"),
 	NULL},
{"cf_energy_net_dispatch9", (getter)Outputs_get_cf_energy_net_dispatch9,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in dispatch period 9"),
 	NULL},
{"cf_energy_net_feb", (getter)Outputs_get_cf_energy_net_feb,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in February"),
 	NULL},
{"cf_energy_net_jan", (getter)Outputs_get_cf_energy_net_jan,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in January"),
 	NULL},
{"cf_energy_net_jul", (getter)Outputs_get_cf_energy_net_jul,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in July"),
 	NULL},
{"cf_energy_net_jun", (getter)Outputs_get_cf_energy_net_jun,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in June"),
 	NULL},
{"cf_energy_net_mar", (getter)Outputs_get_cf_energy_net_mar,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in March"),
 	NULL},
{"cf_energy_net_may", (getter)Outputs_get_cf_energy_net_may,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in May"),
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD1", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD1,(setter)0,
	PyDoc_STR("*sequence*: First year energy from the system by month for TOD1"),
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD2", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD2,(setter)0,
	PyDoc_STR("*sequence*: First year energy from the system by month for TOD2"),
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD3", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD3,(setter)0,
	PyDoc_STR("*sequence*: First year energy from the system by month for TOD3"),
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD4", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD4,(setter)0,
	PyDoc_STR("*sequence*: First year energy from the system by month for TOD4"),
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD5", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD5,(setter)0,
	PyDoc_STR("*sequence*: First year energy from the system by month for TOD5"),
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD6", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD6,(setter)0,
	PyDoc_STR("*sequence*: First year energy from the system by month for TOD6"),
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD7", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD7,(setter)0,
	PyDoc_STR("*sequence*: First year energy from the system by month for TOD7"),
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD8", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD8,(setter)0,
	PyDoc_STR("*sequence*: First year energy from the system by month for TOD8"),
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD9", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD9,(setter)0,
	PyDoc_STR("*sequence*: First year energy from the system by month for TOD9"),
 	NULL},
{"cf_energy_net_nov", (getter)Outputs_get_cf_energy_net_nov,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in November"),
 	NULL},
{"cf_energy_net_oct", (getter)Outputs_get_cf_energy_net_oct,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in October"),
 	NULL},
{"cf_energy_net_sep", (getter)Outputs_get_cf_energy_net_sep,(setter)0,
	PyDoc_STR("*sequence*: Energy produced by the system in September"),
 	NULL},
{"cf_energy_price", (getter)Outputs_get_cf_energy_price,(setter)0,
	PyDoc_STR("*sequence*: Energy Price [$/kWh]"),
 	NULL},
{"cf_energy_value", (getter)Outputs_get_cf_energy_value,(setter)0,
	PyDoc_STR("*sequence*: Energy Value [$]"),
 	NULL},
{"cf_fed_depr_sched", (getter)Outputs_get_cf_fed_depr_sched,(setter)0,
	PyDoc_STR("*sequence*: Federal depreciation schedule [%]"),
 	NULL},
{"cf_fed_depreciation", (getter)Outputs_get_cf_fed_depreciation,(setter)0,
	PyDoc_STR("*sequence*: Federal depreciation [$]"),
 	NULL},
{"cf_fed_incentive_income_less_deductions", (getter)Outputs_get_cf_fed_incentive_income_less_deductions,(setter)0,
	PyDoc_STR("*sequence*: Federal incentive income less deductions [$]"),
 	NULL},
{"cf_fed_income_taxes", (getter)Outputs_get_cf_fed_income_taxes,(setter)0,
	PyDoc_STR("*sequence*: Federal Income Taxes [$]"),
 	NULL},
{"cf_fed_tax_savings", (getter)Outputs_get_cf_fed_tax_savings,(setter)0,
	PyDoc_STR("*sequence*: Federal tax savings [$]"),
 	NULL},
{"cf_fed_taxable_income_less_deductions", (getter)Outputs_get_cf_fed_taxable_income_less_deductions,(setter)0,
	PyDoc_STR("*sequence*: Federal taxable income less deductions [$]"),
 	NULL},
{"cf_federal_tax_frac", (getter)Outputs_get_cf_federal_tax_frac,(setter)0,
	PyDoc_STR("*sequence*: Federal income tax rate [frac]"),
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
	PyDoc_STR("*sequence*: Net Salvage Value [$]"),
 	NULL},
{"cf_om_capacity_expense", (getter)Outputs_get_cf_om_capacity_expense,(setter)0,
	PyDoc_STR("*sequence*: O&M capacity-based expense [$]"),
 	NULL},
{"cf_om_fixed_expense", (getter)Outputs_get_cf_om_fixed_expense,(setter)0,
	PyDoc_STR("*sequence*: O&M fixed expense [$]"),
 	NULL},
{"cf_om_fuel_expense", (getter)Outputs_get_cf_om_fuel_expense,(setter)0,
	PyDoc_STR("*sequence*: O&M fuel expense [$]"),
 	NULL},
{"cf_om_opt_fuel_1_expense", (getter)Outputs_get_cf_om_opt_fuel_1_expense,(setter)0,
	PyDoc_STR("*sequence*: O&M biomass feedstock expense [$]"),
 	NULL},
{"cf_om_opt_fuel_2_expense", (getter)Outputs_get_cf_om_opt_fuel_2_expense,(setter)0,
	PyDoc_STR("*sequence*: O&M coal feedstock expense [$]"),
 	NULL},
{"cf_om_production_expense", (getter)Outputs_get_cf_om_production_expense,(setter)0,
	PyDoc_STR("*sequence*: O&M production-based expense [$]"),
 	NULL},
{"cf_operating_expenses", (getter)Outputs_get_cf_operating_expenses,(setter)0,
	PyDoc_STR("*sequence*: Total operating expense [$]"),
 	NULL},
{"cf_operating_income", (getter)Outputs_get_cf_operating_income,(setter)0,
	PyDoc_STR("*sequence*: Total operating income [$]"),
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
{"cf_pretax_dscr", (getter)Outputs_get_cf_pretax_dscr,(setter)0,
	PyDoc_STR("*sequence*: Pre-tax DSCR"),
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
{"cf_revenue_apr", (getter)Outputs_get_cf_revenue_apr,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in April"),
 	NULL},
{"cf_revenue_aug", (getter)Outputs_get_cf_revenue_aug,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in August"),
 	NULL},
{"cf_revenue_dec", (getter)Outputs_get_cf_revenue_dec,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in December"),
 	NULL},
{"cf_revenue_dispatch1", (getter)Outputs_get_cf_revenue_dispatch1,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in dispatch period 1"),
 	NULL},
{"cf_revenue_dispatch2", (getter)Outputs_get_cf_revenue_dispatch2,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in dispatch period 2"),
 	NULL},
{"cf_revenue_dispatch3", (getter)Outputs_get_cf_revenue_dispatch3,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in dispatch period 3"),
 	NULL},
{"cf_revenue_dispatch4", (getter)Outputs_get_cf_revenue_dispatch4,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in dispatch period 4"),
 	NULL},
{"cf_revenue_dispatch5", (getter)Outputs_get_cf_revenue_dispatch5,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in dispatch period 5"),
 	NULL},
{"cf_revenue_dispatch6", (getter)Outputs_get_cf_revenue_dispatch6,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in dispatch period 6"),
 	NULL},
{"cf_revenue_dispatch7", (getter)Outputs_get_cf_revenue_dispatch7,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in dispatch period 7"),
 	NULL},
{"cf_revenue_dispatch8", (getter)Outputs_get_cf_revenue_dispatch8,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in dispatch period 8"),
 	NULL},
{"cf_revenue_dispatch9", (getter)Outputs_get_cf_revenue_dispatch9,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in dispatch period 9"),
 	NULL},
{"cf_revenue_feb", (getter)Outputs_get_cf_revenue_feb,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in February"),
 	NULL},
{"cf_revenue_jan", (getter)Outputs_get_cf_revenue_jan,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in January"),
 	NULL},
{"cf_revenue_jul", (getter)Outputs_get_cf_revenue_jul,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in July"),
 	NULL},
{"cf_revenue_jun", (getter)Outputs_get_cf_revenue_jun,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in June"),
 	NULL},
{"cf_revenue_mar", (getter)Outputs_get_cf_revenue_mar,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in March"),
 	NULL},
{"cf_revenue_may", (getter)Outputs_get_cf_revenue_may,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in May"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD1", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD1,(setter)0,
	PyDoc_STR("*sequence*: First year revenue from the system by month for TOD1"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD2", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD2,(setter)0,
	PyDoc_STR("*sequence*: First year revenue from the system by month for TOD2"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD3", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD3,(setter)0,
	PyDoc_STR("*sequence*: First year revenue from the system by month for TOD3"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD4", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD4,(setter)0,
	PyDoc_STR("*sequence*: First year revenue from the system by month for TOD4"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD5", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD5,(setter)0,
	PyDoc_STR("*sequence*: First year revenue from the system by month for TOD5"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD6", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD6,(setter)0,
	PyDoc_STR("*sequence*: First year revenue from the system by month for TOD6"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD7", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD7,(setter)0,
	PyDoc_STR("*sequence*: First year revenue from the system by month for TOD7"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD8", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD8,(setter)0,
	PyDoc_STR("*sequence*: First year revenue from the system by month for TOD8"),
 	NULL},
{"cf_revenue_monthly_firstyear_TOD9", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD9,(setter)0,
	PyDoc_STR("*sequence*: First year revenue from the system by month for TOD9"),
 	NULL},
{"cf_revenue_nov", (getter)Outputs_get_cf_revenue_nov,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in November"),
 	NULL},
{"cf_revenue_oct", (getter)Outputs_get_cf_revenue_oct,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in October"),
 	NULL},
{"cf_revenue_sep", (getter)Outputs_get_cf_revenue_sep,(setter)0,
	PyDoc_STR("*sequence*: Revenue from the system in September"),
 	NULL},
{"cf_sta_and_fed_tax_savings", (getter)Outputs_get_cf_sta_and_fed_tax_savings,(setter)0,
	PyDoc_STR("*sequence*: Total tax savings (Federal & State) [$]"),
 	NULL},
{"cf_sta_depr_sched", (getter)Outputs_get_cf_sta_depr_sched,(setter)0,
	PyDoc_STR("*sequence*: State depreciation schedule [%]"),
 	NULL},
{"cf_sta_depreciation", (getter)Outputs_get_cf_sta_depreciation,(setter)0,
	PyDoc_STR("*sequence*: State depreciation [$]"),
 	NULL},
{"cf_sta_incentive_income_less_deductions", (getter)Outputs_get_cf_sta_incentive_income_less_deductions,(setter)0,
	PyDoc_STR("*sequence*: State incentive income less deductions [$]"),
 	NULL},
{"cf_sta_income_taxes", (getter)Outputs_get_cf_sta_income_taxes,(setter)0,
	PyDoc_STR("*sequence*: State Income Taxes [$]"),
 	NULL},
{"cf_sta_tax_savings", (getter)Outputs_get_cf_sta_tax_savings,(setter)0,
	PyDoc_STR("*sequence*: State tax savings [$]"),
 	NULL},
{"cf_sta_taxable_income_less_deductions", (getter)Outputs_get_cf_sta_taxable_income_less_deductions,(setter)0,
	PyDoc_STR("*sequence*: State taxable income less deductions [$]"),
 	NULL},
{"cf_state_tax_frac", (getter)Outputs_get_cf_state_tax_frac,(setter)0,
	PyDoc_STR("*sequence*: State income tax rate [frac]"),
 	NULL},
{"debt_fraction", (getter)Outputs_get_debt_fraction,(setter)0,
	PyDoc_STR("*float*: Debt fraction"),
 	NULL},
{"effective_tax_rate", (getter)Outputs_get_effective_tax_rate,(setter)0,
	PyDoc_STR("*float*: Effective Tax Rate"),
 	NULL},
{"firstyear_energy_dispatch1", (getter)Outputs_get_firstyear_energy_dispatch1,(setter)0,
	PyDoc_STR("*float*: First year energy from the system in dispatch period 1"),
 	NULL},
{"firstyear_energy_dispatch2", (getter)Outputs_get_firstyear_energy_dispatch2,(setter)0,
	PyDoc_STR("*float*: First year energy from the system in dispatch period 2"),
 	NULL},
{"firstyear_energy_dispatch3", (getter)Outputs_get_firstyear_energy_dispatch3,(setter)0,
	PyDoc_STR("*float*: First year energy from the system in dispatch period 3"),
 	NULL},
{"firstyear_energy_dispatch4", (getter)Outputs_get_firstyear_energy_dispatch4,(setter)0,
	PyDoc_STR("*float*: First year energy from the system in dispatch period 4"),
 	NULL},
{"firstyear_energy_dispatch5", (getter)Outputs_get_firstyear_energy_dispatch5,(setter)0,
	PyDoc_STR("*float*: First year energy from the system in dispatch period 5"),
 	NULL},
{"firstyear_energy_dispatch6", (getter)Outputs_get_firstyear_energy_dispatch6,(setter)0,
	PyDoc_STR("*float*: First year energy from the system in dispatch period 6"),
 	NULL},
{"firstyear_energy_dispatch7", (getter)Outputs_get_firstyear_energy_dispatch7,(setter)0,
	PyDoc_STR("*float*: First year energy from the system in dispatch period 7"),
 	NULL},
{"firstyear_energy_dispatch8", (getter)Outputs_get_firstyear_energy_dispatch8,(setter)0,
	PyDoc_STR("*float*: First year energy from the system in dispatch period 8"),
 	NULL},
{"firstyear_energy_dispatch9", (getter)Outputs_get_firstyear_energy_dispatch9,(setter)0,
	PyDoc_STR("*float*: First year energy from the system in dispatch period 9"),
 	NULL},
{"firstyear_energy_price1", (getter)Outputs_get_firstyear_energy_price1,(setter)0,
	PyDoc_STR("*float*: First year energy price dispatch period 1"),
 	NULL},
{"firstyear_energy_price2", (getter)Outputs_get_firstyear_energy_price2,(setter)0,
	PyDoc_STR("*float*: First year energy price dispatch period 2"),
 	NULL},
{"firstyear_energy_price3", (getter)Outputs_get_firstyear_energy_price3,(setter)0,
	PyDoc_STR("*float*: First year energy price dispatch period 3"),
 	NULL},
{"firstyear_energy_price4", (getter)Outputs_get_firstyear_energy_price4,(setter)0,
	PyDoc_STR("*float*: First year energy price dispatch period 4"),
 	NULL},
{"firstyear_energy_price5", (getter)Outputs_get_firstyear_energy_price5,(setter)0,
	PyDoc_STR("*float*: First year energy price dispatch period 5"),
 	NULL},
{"firstyear_energy_price6", (getter)Outputs_get_firstyear_energy_price6,(setter)0,
	PyDoc_STR("*float*: First year energy price dispatch period 6"),
 	NULL},
{"firstyear_energy_price7", (getter)Outputs_get_firstyear_energy_price7,(setter)0,
	PyDoc_STR("*float*: First year energy price dispatch period 7"),
 	NULL},
{"firstyear_energy_price8", (getter)Outputs_get_firstyear_energy_price8,(setter)0,
	PyDoc_STR("*float*: First year energy price dispatch period 8"),
 	NULL},
{"firstyear_energy_price9", (getter)Outputs_get_firstyear_energy_price9,(setter)0,
	PyDoc_STR("*float*: First year energy price dispatch period 9"),
 	NULL},
{"firstyear_revenue_dispatch1", (getter)Outputs_get_firstyear_revenue_dispatch1,(setter)0,
	PyDoc_STR("*float*: First year revenue from the system in dispatch period 1"),
 	NULL},
{"firstyear_revenue_dispatch2", (getter)Outputs_get_firstyear_revenue_dispatch2,(setter)0,
	PyDoc_STR("*float*: First year revenue from the system in dispatch period 2"),
 	NULL},
{"firstyear_revenue_dispatch3", (getter)Outputs_get_firstyear_revenue_dispatch3,(setter)0,
	PyDoc_STR("*float*: First year revenue from the system in dispatch period 3"),
 	NULL},
{"firstyear_revenue_dispatch4", (getter)Outputs_get_firstyear_revenue_dispatch4,(setter)0,
	PyDoc_STR("*float*: First year revenue from the system in dispatch period 4"),
 	NULL},
{"firstyear_revenue_dispatch5", (getter)Outputs_get_firstyear_revenue_dispatch5,(setter)0,
	PyDoc_STR("*float*: First year revenue from the system in dispatch period 5"),
 	NULL},
{"firstyear_revenue_dispatch6", (getter)Outputs_get_firstyear_revenue_dispatch6,(setter)0,
	PyDoc_STR("*float*: First year revenue from the system in dispatch period 6"),
 	NULL},
{"firstyear_revenue_dispatch7", (getter)Outputs_get_firstyear_revenue_dispatch7,(setter)0,
	PyDoc_STR("*float*: First year revenue from the system in dispatch period 7"),
 	NULL},
{"firstyear_revenue_dispatch8", (getter)Outputs_get_firstyear_revenue_dispatch8,(setter)0,
	PyDoc_STR("*float*: First year revenue from the system in dispatch period 8"),
 	NULL},
{"firstyear_revenue_dispatch9", (getter)Outputs_get_firstyear_revenue_dispatch9,(setter)0,
	PyDoc_STR("*float*: First year revenue from the system in dispatch period 9"),
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
{"irr", (getter)Outputs_get_irr,(setter)0,
	PyDoc_STR("*float*: Internal rate of return [%]"),
 	NULL},
{"itc_fed_total", (getter)Outputs_get_itc_fed_total,(setter)0,
	PyDoc_STR("*float*: Federal ITC income [$]"),
 	NULL},
{"itc_sta_total", (getter)Outputs_get_itc_sta_total,(setter)0,
	PyDoc_STR("*float*: State ITC income [$]"),
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
{"latcf_nom", (getter)Outputs_get_latcf_nom,(setter)0,
	PyDoc_STR("*float*: Nominal LATCF [cents/kWh]"),
 	NULL},
{"latcf_real", (getter)Outputs_get_latcf_real,(setter)0,
	PyDoc_STR("*float*: Real LATCF [cents/kWh]"),
 	NULL},
{"lcoe_nom", (getter)Outputs_get_lcoe_nom,(setter)0,
	PyDoc_STR("*float*: Nominal LCOE [cents/kWh]"),
 	NULL},
{"lcoe_real", (getter)Outputs_get_lcoe_real,(setter)0,
	PyDoc_STR("*float*: Real LCOE [cents/kWh]"),
 	NULL},
{"lcoptc_fed_nom", (getter)Outputs_get_lcoptc_fed_nom,(setter)0,
	PyDoc_STR("*float*: Levelized Federal PTC (nominal) [cents/kWh]"),
 	NULL},
{"lcoptc_fed_real", (getter)Outputs_get_lcoptc_fed_real,(setter)0,
	PyDoc_STR("*float*: Levelized Federal PTC (real) [cents/kWh]"),
 	NULL},
{"lcoptc_sta_nom", (getter)Outputs_get_lcoptc_sta_nom,(setter)0,
	PyDoc_STR("*float*: Levelized State PTC (nominal) [cents/kWh]"),
 	NULL},
{"lcoptc_sta_real", (getter)Outputs_get_lcoptc_sta_real,(setter)0,
	PyDoc_STR("*float*: Levelized State PTC (real) [cents/kWh]"),
 	NULL},
{"lppa_nom", (getter)Outputs_get_lppa_nom,(setter)0,
	PyDoc_STR("*float*: Nominal LPPA [cents/kWh]"),
 	NULL},
{"lppa_real", (getter)Outputs_get_lppa_real,(setter)0,
	PyDoc_STR("*float*: Real LPPA [cents/kWh]"),
 	NULL},
{"min_cashflow", (getter)Outputs_get_min_cashflow,(setter)0,
	PyDoc_STR("*float*: Minimum cash flow value [$]"),
 	NULL},
{"min_dscr", (getter)Outputs_get_min_dscr,(setter)0,
	PyDoc_STR("*float*: Minimum DSCR"),
 	NULL},
{"npv", (getter)Outputs_get_npv,(setter)0,
	PyDoc_STR("*float*: Net present value [$]"),
 	NULL},
{"ppa", (getter)Outputs_get_ppa,(setter)0,
	PyDoc_STR("*float*: First year PPA [cents/kWh]"),
 	NULL},
{"ppa_escalation", (getter)Outputs_get_ppa_escalation,(setter)0,
	PyDoc_STR("*float*: PPA price escalation"),
 	NULL},
{"present_value_fuel", (getter)Outputs_get_present_value_fuel,(setter)0,
	PyDoc_STR("*float*: Present value of fuel O and M [$]"),
 	NULL},
{"present_value_insandproptax", (getter)Outputs_get_present_value_insandproptax,(setter)0,
	PyDoc_STR("*float*: Present value of Insurance and Prop Tax [$]"),
 	NULL},
{"present_value_oandm", (getter)Outputs_get_present_value_oandm,(setter)0,
	PyDoc_STR("*float*: Present value of O and M [$]"),
 	NULL},
{"present_value_oandm_nonfuel", (getter)Outputs_get_present_value_oandm_nonfuel,(setter)0,
	PyDoc_STR("*float*: Present value of non-fuel O and M [$]"),
 	NULL},
{"wacc", (getter)Outputs_get_wacc,(setter)0,
	PyDoc_STR("*float*: Weighted Average Cost of Capital (WACC)"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Ippppa.Outputs",             /*tp_name*/
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
 * Ippppa
 */

static PyTypeObject Ippppa_Type;

static CmodObject *
newIppppaObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Ippppa_Type);

	PySAM_TECH_ATTR()

	PyObject* FinancialParameters_obj = FinancialParameters_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FinancialParameters", FinancialParameters_obj);
	Py_DECREF(FinancialParameters_obj);

	PyObject* SystemCosts_obj = SystemCosts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemCosts", SystemCosts_obj);
	Py_DECREF(SystemCosts_obj);

	PyObject* LandLease_obj = LandLease_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "LandLease", LandLease_obj);
	Py_DECREF(LandLease_obj);

	PyObject* Depreciation_obj = Depreciation_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Depreciation", Depreciation_obj);
	Py_DECREF(Depreciation_obj);

	PyObject* TaxCreditIncentives_obj = TaxCreditIncentives_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TaxCreditIncentives", TaxCreditIncentives_obj);
	Py_DECREF(TaxCreditIncentives_obj);

	PyObject* PaymentIncentives_obj = PaymentIncentives_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "PaymentIncentives", PaymentIncentives_obj);
	Py_DECREF(PaymentIncentives_obj);

	PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Ippppa methods */

static void
Ippppa_dealloc(CmodObject *self)
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
Ippppa_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Ippppa_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Ippppa_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Ippppa"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Ippppa_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Ippppa"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Ippppa_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Ippppa_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Ippppa_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Ippppa_methods[] = {
		{"execute",           (PyCFunction)Ippppa_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Ippppa_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Financial Parameters': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Ippppa_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Financial Parameters': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Ippppa_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Ippppa_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Ippppa_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Ippppa_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Ippppa_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Ippppa_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Ippppa",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Ippppa_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Ippppa_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Ippppa_getattro, /*tp_getattro*/
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
		Ippppa_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Ippppa object */

static PyObject *
Ippppa_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newIppppaObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Ippppa_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newIppppaObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Ippppa_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newIppppaObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Ippppa", def) < 0) {
		Ippppa_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Ippppa_from_existing(PyObject *self, PyObject *args)
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

	rv = newIppppaObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Ippppa", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef IppppaModule_methods[] = {
		{"new",             Ippppa_new,         METH_VARARGS,
				PyDoc_STR("new() -> Ippppa")},
		{"default",             Ippppa_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Ippppa\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Ippppa_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Ippppa\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Ippppa_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Ippppa\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Ippppa");


static int
IppppaModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Ippppa_Type.tp_dict = PyDict_New();
	if (!Ippppa_Type.tp_dict) { goto fail; }

	/// Add the FinancialParameters type object to Ippppa_Type
	if (PyType_Ready(&FinancialParameters_Type) < 0) { goto fail; }
	PyDict_SetItemString(Ippppa_Type.tp_dict,
				"FinancialParameters",
				(PyObject*)&FinancialParameters_Type);
	Py_DECREF(&FinancialParameters_Type);

	/// Add the SystemCosts type object to Ippppa_Type
	if (PyType_Ready(&SystemCosts_Type) < 0) { goto fail; }
	PyDict_SetItemString(Ippppa_Type.tp_dict,
				"SystemCosts",
				(PyObject*)&SystemCosts_Type);
	Py_DECREF(&SystemCosts_Type);

	/// Add the LandLease type object to Ippppa_Type
	if (PyType_Ready(&LandLease_Type) < 0) { goto fail; }
	PyDict_SetItemString(Ippppa_Type.tp_dict,
				"LandLease",
				(PyObject*)&LandLease_Type);
	Py_DECREF(&LandLease_Type);

	/// Add the Depreciation type object to Ippppa_Type
	if (PyType_Ready(&Depreciation_Type) < 0) { goto fail; }
	PyDict_SetItemString(Ippppa_Type.tp_dict,
				"Depreciation",
				(PyObject*)&Depreciation_Type);
	Py_DECREF(&Depreciation_Type);

	/// Add the TaxCreditIncentives type object to Ippppa_Type
	if (PyType_Ready(&TaxCreditIncentives_Type) < 0) { goto fail; }
	PyDict_SetItemString(Ippppa_Type.tp_dict,
				"TaxCreditIncentives",
				(PyObject*)&TaxCreditIncentives_Type);
	Py_DECREF(&TaxCreditIncentives_Type);

	/// Add the PaymentIncentives type object to Ippppa_Type
	if (PyType_Ready(&PaymentIncentives_Type) < 0) { goto fail; }
	PyDict_SetItemString(Ippppa_Type.tp_dict,
				"PaymentIncentives",
				(PyObject*)&PaymentIncentives_Type);
	Py_DECREF(&PaymentIncentives_Type);

	/// Add the Common type object to Ippppa_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(Ippppa_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the Outputs type object to Ippppa_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Ippppa_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Ippppa type object to the module
	if (PyType_Ready(&Ippppa_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Ippppa",
				(PyObject*)&Ippppa_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot IppppaModule_slots[] = {
		{Py_mod_exec, IppppaModule_exec},
		{0, NULL},
};

static struct PyModuleDef IppppaModule = {
		PyModuleDef_HEAD_INIT,
		"Ippppa",
		module_doc,
		0,
		IppppaModule_methods,
		IppppaModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Ippppa(void)
{
	return PyModuleDef_Init(&IppppaModule);
}