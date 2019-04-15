#include <Python.h>

#include <SAM_Cashloan.h>
#include <SAM_api.h>

#include "PySAM_utils.h"



	/*
	 * FinancialParameters Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Cashloan   data_ptr;
} FinancialParametersObject;

static PyTypeObject FinancialParameters_Type;

static PyObject *
FinancialParameters_new(SAM_Cashloan data_ptr)
{
	PyObject* new_obj = FinancialParameters_Type.tp_alloc(&FinancialParameters_Type,0);

	FinancialParametersObject* FinancialParameters_obj = (FinancialParametersObject*)new_obj;

	FinancialParameters_obj->data_ptr = data_ptr;

	return new_obj;
}

/* FinancialParameters methods */

static PyObject *
FinancialParameters_assign(FinancialParametersObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Cashloan", "FinancialParameters")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialParameters_export(FinancialParametersObject *self, PyObject *args)
{
	PyTypeObject* tp = &FinancialParameters_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef FinancialParameters_methods[] = {
		{"assign",            (PyCFunction)FinancialParameters_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)FinancialParameters_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
FinancialParameters_get_analysis_period(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_FinancialParameters_analysis_period_fget, self->data_ptr);
}

static int
FinancialParameters_set_analysis_period(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_FinancialParameters_analysis_period_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_debt_fraction(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_FinancialParameters_debt_fraction_fget, self->data_ptr);
}

static int
FinancialParameters_set_debt_fraction(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_FinancialParameters_debt_fraction_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_federal_tax_rate(FinancialParametersObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_FinancialParameters_federal_tax_rate_aget, self->data_ptr);
}

static int
FinancialParameters_set_federal_tax_rate(FinancialParametersObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_FinancialParameters_federal_tax_rate_aset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_inflation_rate(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_FinancialParameters_inflation_rate_fget, self->data_ptr);
}

static int
FinancialParameters_set_inflation_rate(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_FinancialParameters_inflation_rate_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_insurance_rate(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_FinancialParameters_insurance_rate_fget, self->data_ptr);
}

static int
FinancialParameters_set_insurance_rate(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_FinancialParameters_insurance_rate_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_loan_rate(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_FinancialParameters_loan_rate_fget, self->data_ptr);
}

static int
FinancialParameters_set_loan_rate(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_FinancialParameters_loan_rate_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_loan_term(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_FinancialParameters_loan_term_fget, self->data_ptr);
}

static int
FinancialParameters_set_loan_term(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_FinancialParameters_loan_term_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_prop_tax_assessed_decline(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_FinancialParameters_prop_tax_assessed_decline_fget, self->data_ptr);
}

static int
FinancialParameters_set_prop_tax_assessed_decline(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_FinancialParameters_prop_tax_assessed_decline_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_prop_tax_cost_assessed_percent(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_FinancialParameters_prop_tax_cost_assessed_percent_fget, self->data_ptr);
}

static int
FinancialParameters_set_prop_tax_cost_assessed_percent(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_FinancialParameters_prop_tax_cost_assessed_percent_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_property_tax_rate(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_FinancialParameters_property_tax_rate_fget, self->data_ptr);
}

static int
FinancialParameters_set_property_tax_rate(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_FinancialParameters_property_tax_rate_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_real_discount_rate(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_FinancialParameters_real_discount_rate_fget, self->data_ptr);
}

static int
FinancialParameters_set_real_discount_rate(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_FinancialParameters_real_discount_rate_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_state_tax_rate(FinancialParametersObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_FinancialParameters_state_tax_rate_aget, self->data_ptr);
}

static int
FinancialParameters_set_state_tax_rate(FinancialParametersObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_FinancialParameters_state_tax_rate_aset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_system_capacity(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_FinancialParameters_system_capacity_fget, self->data_ptr);
}

static int
FinancialParameters_set_system_capacity(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_FinancialParameters_system_capacity_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_system_heat_rate(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_FinancialParameters_system_heat_rate_fget, self->data_ptr);
}

static int
FinancialParameters_set_system_heat_rate(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_FinancialParameters_system_heat_rate_fset, self->data_ptr);
}

static PyGetSetDef FinancialParameters_getset[] = {
{"analysis_period", (getter)FinancialParameters_get_analysis_period,(setter)FinancialParameters_set_analysis_period,
	"Analyis period [years], number.\n Constraints: INTEGER,MIN=0,MAX=50; Required if ?=30.",
 	NULL},
{"debt_fraction", (getter)FinancialParameters_get_debt_fraction,(setter)FinancialParameters_set_debt_fraction,
	"Debt percentage [%], number.\n Constraints: MIN=0,MAX=100; 0 if not set.",
 	NULL},
{"federal_tax_rate", (getter)FinancialParameters_get_federal_tax_rate,(setter)FinancialParameters_set_federal_tax_rate,
	"Federal income tax rate [%], array.\n Required.",
 	NULL},
{"inflation_rate", (getter)FinancialParameters_get_inflation_rate,(setter)FinancialParameters_set_inflation_rate,
	"Inflation rate [%], number.\n Constraints: MIN=-99; Required.",
 	NULL},
{"insurance_rate", (getter)FinancialParameters_get_insurance_rate,(setter)FinancialParameters_set_insurance_rate,
	"Insurance rate [%], number.\n Constraints: MIN=0,MAX=100; Required if ?=0.0.",
 	NULL},
{"loan_rate", (getter)FinancialParameters_get_loan_rate,(setter)FinancialParameters_set_loan_rate,
	"Loan rate [%], number.\n Constraints: MIN=0,MAX=100; 0 if not set.",
 	NULL},
{"loan_term", (getter)FinancialParameters_get_loan_term,(setter)FinancialParameters_set_loan_term,
	"Loan term [years], number.\n Constraints: INTEGER,MIN=0,MAX=50; 0 if not set.",
 	NULL},
{"prop_tax_assessed_decline", (getter)FinancialParameters_get_prop_tax_assessed_decline,(setter)FinancialParameters_set_prop_tax_assessed_decline,
	"Assessed value annual decline [%], number.\n Constraints: MIN=0,MAX=100; Required if ?=5.",
 	NULL},
{"prop_tax_cost_assessed_percent", (getter)FinancialParameters_get_prop_tax_cost_assessed_percent,(setter)FinancialParameters_set_prop_tax_cost_assessed_percent,
	"Percent of pre-financing costs assessed [%], number.\n Constraints: MIN=0,MAX=100; Required if ?=95.",
 	NULL},
{"property_tax_rate", (getter)FinancialParameters_get_property_tax_rate,(setter)FinancialParameters_set_property_tax_rate,
	"Property tax rate [%], number.\n Constraints: MIN=0,MAX=100; Required if ?=0.0.",
 	NULL},
{"real_discount_rate", (getter)FinancialParameters_get_real_discount_rate,(setter)FinancialParameters_set_real_discount_rate,
	"Real discount rate [%], number.\n Constraints: MIN=-99; Required.",
 	NULL},
{"state_tax_rate", (getter)FinancialParameters_get_state_tax_rate,(setter)FinancialParameters_set_state_tax_rate,
	"State income tax rate [%], array.\n Required.",
 	NULL},
{"system_capacity", (getter)FinancialParameters_get_system_capacity,(setter)FinancialParameters_set_system_capacity,
	"System nameplate capacity [kW], number.\n Constraints: POSITIVE; Required.",
 	NULL},
{"system_heat_rate", (getter)FinancialParameters_get_system_heat_rate,(setter)FinancialParameters_set_system_heat_rate,
	"System heat rate [MMBTus/MWh], number.\n Constraints: MIN=0; Required if ?=0.0.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FinancialParameters_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CashloanModel.FinancialParameters",             /*tp_name*/
		sizeof(FinancialParametersObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		FinancialParameters_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		FinancialParameters_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * SystemCosts Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Cashloan   data_ptr;
} SystemCostsObject;

static PyTypeObject SystemCosts_Type;

static PyObject *
SystemCosts_new(SAM_Cashloan data_ptr)
{
	PyObject* new_obj = SystemCosts_Type.tp_alloc(&SystemCosts_Type,0);

	SystemCostsObject* SystemCosts_obj = (SystemCostsObject*)new_obj;

	SystemCosts_obj->data_ptr = data_ptr;

	return new_obj;
}

/* SystemCosts methods */

static PyObject *
SystemCosts_assign(SystemCostsObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Cashloan", "SystemCosts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemCosts_export(SystemCostsObject *self, PyObject *args)
{
	PyTypeObject* tp = &SystemCosts_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SystemCosts_methods[] = {
		{"assign",            (PyCFunction)SystemCosts_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)SystemCosts_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemCosts_get_add_om_num_types(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_SystemCosts_add_om_num_types_fget, self->data_ptr);
}

static int
SystemCosts_set_add_om_num_types(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_SystemCosts_add_om_num_types_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_annual_fuel_usage(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_SystemCosts_annual_fuel_usage_fget, self->data_ptr);
}

static int
SystemCosts_set_annual_fuel_usage(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_SystemCosts_annual_fuel_usage_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_capacity(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_SystemCosts_om_capacity_aget, self->data_ptr);
}

static int
SystemCosts_set_om_capacity(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_SystemCosts_om_capacity_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_capacity1(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_SystemCosts_om_capacity1_aget, self->data_ptr);
}

static int
SystemCosts_set_om_capacity1(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_SystemCosts_om_capacity1_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_capacity1_nameplate(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_SystemCosts_om_capacity1_nameplate_fget, self->data_ptr);
}

static int
SystemCosts_set_om_capacity1_nameplate(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_SystemCosts_om_capacity1_nameplate_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_capacity2(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_SystemCosts_om_capacity2_aget, self->data_ptr);
}

static int
SystemCosts_set_om_capacity2(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_SystemCosts_om_capacity2_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_capacity2_nameplate(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_SystemCosts_om_capacity2_nameplate_fget, self->data_ptr);
}

static int
SystemCosts_set_om_capacity2_nameplate(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_SystemCosts_om_capacity2_nameplate_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_capacity_escal(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_SystemCosts_om_capacity_escal_fget, self->data_ptr);
}

static int
SystemCosts_set_om_capacity_escal(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_SystemCosts_om_capacity_escal_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fixed(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_SystemCosts_om_fixed_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fixed(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_SystemCosts_om_fixed_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fixed1(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_SystemCosts_om_fixed1_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fixed1(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_SystemCosts_om_fixed1_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fixed2(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_SystemCosts_om_fixed2_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fixed2(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_SystemCosts_om_fixed2_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fixed_escal(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_SystemCosts_om_fixed_escal_fget, self->data_ptr);
}

static int
SystemCosts_set_om_fixed_escal(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_SystemCosts_om_fixed_escal_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuel_cost(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_SystemCosts_om_fuel_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fuel_cost(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_SystemCosts_om_fuel_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuel_cost_escal(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_SystemCosts_om_fuel_cost_escal_fget, self->data_ptr);
}

static int
SystemCosts_set_om_fuel_cost_escal(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_SystemCosts_om_fuel_cost_escal_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_1_cost(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_SystemCosts_om_opt_fuel_1_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_1_cost(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_SystemCosts_om_opt_fuel_1_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_1_cost_escal(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_SystemCosts_om_opt_fuel_1_cost_escal_fget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_1_cost_escal(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_SystemCosts_om_opt_fuel_1_cost_escal_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_1_usage(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_SystemCosts_om_opt_fuel_1_usage_fget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_1_usage(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_SystemCosts_om_opt_fuel_1_usage_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_2_cost(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_SystemCosts_om_opt_fuel_2_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_2_cost(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_SystemCosts_om_opt_fuel_2_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_2_cost_escal(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_SystemCosts_om_opt_fuel_2_cost_escal_fget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_2_cost_escal(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_SystemCosts_om_opt_fuel_2_cost_escal_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_2_usage(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_SystemCosts_om_opt_fuel_2_usage_fget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_2_usage(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_SystemCosts_om_opt_fuel_2_usage_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_SystemCosts_om_production_aget, self->data_ptr);
}

static int
SystemCosts_set_om_production(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_SystemCosts_om_production_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production1(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_SystemCosts_om_production1_aget, self->data_ptr);
}

static int
SystemCosts_set_om_production1(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_SystemCosts_om_production1_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production1_values(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_SystemCosts_om_production1_values_aget, self->data_ptr);
}

static int
SystemCosts_set_om_production1_values(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_SystemCosts_om_production1_values_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production2(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_SystemCosts_om_production2_aget, self->data_ptr);
}

static int
SystemCosts_set_om_production2(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_SystemCosts_om_production2_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production2_values(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_SystemCosts_om_production2_values_aget, self->data_ptr);
}

static int
SystemCosts_set_om_production2_values(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_SystemCosts_om_production2_values_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production_escal(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_SystemCosts_om_production_escal_fget, self->data_ptr);
}

static int
SystemCosts_set_om_production_escal(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_SystemCosts_om_production_escal_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_replacement_cost1(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_SystemCosts_om_replacement_cost1_aget, self->data_ptr);
}

static int
SystemCosts_set_om_replacement_cost1(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_SystemCosts_om_replacement_cost1_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_replacement_cost2(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_SystemCosts_om_replacement_cost2_aget, self->data_ptr);
}

static int
SystemCosts_set_om_replacement_cost2(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_SystemCosts_om_replacement_cost2_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_replacement_cost_escal(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_SystemCosts_om_replacement_cost_escal_fget, self->data_ptr);
}

static int
SystemCosts_set_om_replacement_cost_escal(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_SystemCosts_om_replacement_cost_escal_fset, self->data_ptr);
}

static PyGetSetDef SystemCosts_getset[] = {
{"add_om_num_types", (getter)SystemCosts_get_add_om_num_types,(setter)SystemCosts_set_add_om_num_types,
	"Number of O and M types, number.\n Constraints: INTEGER,MIN=0,MAX=2; 0 if not set.",
 	NULL},
{"annual_fuel_usage", (getter)SystemCosts_get_annual_fuel_usage,(setter)SystemCosts_set_annual_fuel_usage,
	"Fuel usage [kWht], number.\n Constraints: MIN=0; 0 if not set.",
 	NULL},
{"om_capacity", (getter)SystemCosts_get_om_capacity,(setter)SystemCosts_set_om_capacity,
	"Capacity-based System Costs amount [$/kWcap], array.\n Required if ?=0.0.",
 	NULL},
{"om_capacity1", (getter)SystemCosts_get_om_capacity1,(setter)SystemCosts_set_om_capacity1,
	"Battery capacity-based System Costs amount [$/kWcap], array.\n Required if ?=0.0.",
 	NULL},
{"om_capacity1_nameplate", (getter)SystemCosts_get_om_capacity1_nameplate,(setter)SystemCosts_set_om_capacity1_nameplate,
	"Battery capacity for System Costs values [kW], number.\n 0 if not set.",
 	NULL},
{"om_capacity2", (getter)SystemCosts_get_om_capacity2,(setter)SystemCosts_set_om_capacity2,
	"Fuel cell capacity-based System Costs amount [$/kWcap], array.\n Required if ?=0.0.",
 	NULL},
{"om_capacity2_nameplate", (getter)SystemCosts_get_om_capacity2_nameplate,(setter)SystemCosts_set_om_capacity2_nameplate,
	"Fuel cell capacity for System Costs values [kW], number.\n 0 if not set.",
 	NULL},
{"om_capacity_escal", (getter)SystemCosts_get_om_capacity_escal,(setter)SystemCosts_set_om_capacity_escal,
	"Capacity-based System Costs escalation [%/year], number.\n Required if ?=0.0.",
 	NULL},
{"om_fixed", (getter)SystemCosts_get_om_fixed,(setter)SystemCosts_set_om_fixed,
	"Fixed System Costs annual amount [$/year], array.\n Required if ?=0.0.",
 	NULL},
{"om_fixed1", (getter)SystemCosts_get_om_fixed1,(setter)SystemCosts_set_om_fixed1,
	"Battery fixed System Costs annual amount [$/year], array.\n Required if ?=0.0.",
 	NULL},
{"om_fixed2", (getter)SystemCosts_get_om_fixed2,(setter)SystemCosts_set_om_fixed2,
	"Fuel cell fixed System Costs annual amount [$/year], array.\n Required if ?=0.0.",
 	NULL},
{"om_fixed_escal", (getter)SystemCosts_get_om_fixed_escal,(setter)SystemCosts_set_om_fixed_escal,
	"Fixed System Costs escalation [%/year], number.\n Required if ?=0.0.",
 	NULL},
{"om_fuel_cost", (getter)SystemCosts_get_om_fuel_cost,(setter)SystemCosts_set_om_fuel_cost,
	"Fuel cost [$/MMBtu], array.\n Required if ?=0.0.",
 	NULL},
{"om_fuel_cost_escal", (getter)SystemCosts_get_om_fuel_cost_escal,(setter)SystemCosts_set_om_fuel_cost_escal,
	"Fuel cost escalation [%/year], number.\n Required if ?=0.0.",
 	NULL},
{"om_opt_fuel_1_cost", (getter)SystemCosts_get_om_opt_fuel_1_cost,(setter)SystemCosts_set_om_opt_fuel_1_cost,
	"Biomass feedstock cost [$/unit], array.\n Required if ?=0.0.",
 	NULL},
{"om_opt_fuel_1_cost_escal", (getter)SystemCosts_get_om_opt_fuel_1_cost_escal,(setter)SystemCosts_set_om_opt_fuel_1_cost_escal,
	"Biomass feedstock cost escalation [%/year], number.\n Required if ?=0.0.",
 	NULL},
{"om_opt_fuel_1_usage", (getter)SystemCosts_get_om_opt_fuel_1_usage,(setter)SystemCosts_set_om_opt_fuel_1_usage,
	"Biomass feedstock usage [unit], number.\n Required if ?=0.0.",
 	NULL},
{"om_opt_fuel_2_cost", (getter)SystemCosts_get_om_opt_fuel_2_cost,(setter)SystemCosts_set_om_opt_fuel_2_cost,
	"Coal feedstock cost [$/unit], array.\n Required if ?=0.0.",
 	NULL},
{"om_opt_fuel_2_cost_escal", (getter)SystemCosts_get_om_opt_fuel_2_cost_escal,(setter)SystemCosts_set_om_opt_fuel_2_cost_escal,
	"Coal feedstock cost escalation [%/year], number.\n Required if ?=0.0.",
 	NULL},
{"om_opt_fuel_2_usage", (getter)SystemCosts_get_om_opt_fuel_2_usage,(setter)SystemCosts_set_om_opt_fuel_2_usage,
	"Coal feedstock usage [unit], number.\n Required if ?=0.0.",
 	NULL},
{"om_production", (getter)SystemCosts_get_om_production,(setter)SystemCosts_set_om_production,
	"Production-based System Costs amount [$/MWh], array.\n Required if ?=0.0.",
 	NULL},
{"om_production1", (getter)SystemCosts_get_om_production1,(setter)SystemCosts_set_om_production1,
	"Battery production-based System Costs amount [$/MWh], array.\n Required if ?=0.0.",
 	NULL},
{"om_production1_values", (getter)SystemCosts_get_om_production1_values,(setter)SystemCosts_set_om_production1_values,
	"Battery production for System Costs values [kWh], array.\n 0 if not set.",
 	NULL},
{"om_production2", (getter)SystemCosts_get_om_production2,(setter)SystemCosts_set_om_production2,
	"Fuel cell production-based System Costs amount [$/MWh], array.\n Required if ?=0.0.",
 	NULL},
{"om_production2_values", (getter)SystemCosts_get_om_production2_values,(setter)SystemCosts_set_om_production2_values,
	"Fuel cell production for System Costs values [kWh], array.\n 0 if not set.",
 	NULL},
{"om_production_escal", (getter)SystemCosts_get_om_production_escal,(setter)SystemCosts_set_om_production_escal,
	"Production-based System Costs escalation [%/year], number.\n Required if ?=0.0.",
 	NULL},
{"om_replacement_cost1", (getter)SystemCosts_get_om_replacement_cost1,(setter)SystemCosts_set_om_replacement_cost1,
	"Repacement cost 1 [$/kWh], array.\n Required if ?=0.0.",
 	NULL},
{"om_replacement_cost2", (getter)SystemCosts_get_om_replacement_cost2,(setter)SystemCosts_set_om_replacement_cost2,
	"Repacement cost 2 [$/kW], array.\n Required if ?=0.0.",
 	NULL},
{"om_replacement_cost_escal", (getter)SystemCosts_get_om_replacement_cost_escal,(setter)SystemCosts_set_om_replacement_cost_escal,
	"Replacement cost escalation [%/year], number.\n Required if ?=0.0.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CashloanModel.SystemCosts",             /*tp_name*/
		sizeof(SystemCostsObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		SystemCosts_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SystemCosts_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * Depreciation Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Cashloan   data_ptr;
} DepreciationObject;

static PyTypeObject Depreciation_Type;

static PyObject *
Depreciation_new(SAM_Cashloan data_ptr)
{
	PyObject* new_obj = Depreciation_Type.tp_alloc(&Depreciation_Type,0);

	DepreciationObject* Depreciation_obj = (DepreciationObject*)new_obj;

	Depreciation_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Depreciation methods */

static PyObject *
Depreciation_assign(DepreciationObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Cashloan", "Depreciation")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Depreciation_export(DepreciationObject *self, PyObject *args)
{
	PyTypeObject* tp = &Depreciation_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Depreciation_methods[] = {
		{"assign",            (PyCFunction)Depreciation_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Depreciation_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Depreciation_get_depr_fed_custom(DepreciationObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Depreciation_depr_fed_custom_aget, self->data_ptr);
}

static int
Depreciation_set_depr_fed_custom(DepreciationObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_Depreciation_depr_fed_custom_aset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_fed_sl_years(DepreciationObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Depreciation_depr_fed_sl_years_fget, self->data_ptr);
}

static int
Depreciation_set_depr_fed_sl_years(DepreciationObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_Depreciation_depr_fed_sl_years_fset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_fed_type(DepreciationObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Depreciation_depr_fed_type_fget, self->data_ptr);
}

static int
Depreciation_set_depr_fed_type(DepreciationObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_Depreciation_depr_fed_type_fset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_sta_custom(DepreciationObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Depreciation_depr_sta_custom_aget, self->data_ptr);
}

static int
Depreciation_set_depr_sta_custom(DepreciationObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_Depreciation_depr_sta_custom_aset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_sta_sl_years(DepreciationObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Depreciation_depr_sta_sl_years_fget, self->data_ptr);
}

static int
Depreciation_set_depr_sta_sl_years(DepreciationObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_Depreciation_depr_sta_sl_years_fset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_sta_type(DepreciationObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Depreciation_depr_sta_type_fget, self->data_ptr);
}

static int
Depreciation_set_depr_sta_type(DepreciationObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_Depreciation_depr_sta_type_fset, self->data_ptr);
}

static PyGetSetDef Depreciation_getset[] = {
{"depr_fed_custom", (getter)Depreciation_get_depr_fed_custom,(setter)Depreciation_set_depr_fed_custom,
	"Federal custom depreciation [%/year], array.\n Required if depr_fed_type=3.",
 	NULL},
{"depr_fed_sl_years", (getter)Depreciation_get_depr_fed_sl_years,(setter)Depreciation_set_depr_fed_sl_years,
	"Federal depreciation straight-line Years [years], number.\n Constraints: INTEGER,POSITIVE; Required if depr_fed_type=2.",
 	NULL},
{"depr_fed_type", (getter)Depreciation_get_depr_fed_type,(setter)Depreciation_set_depr_fed_type,
	"Federal depreciation type, number.\n 0=none,1=macrs_half_year,2=sl,3=custom; Constraints: INTEGER,MIN=0,MAX=3; 0 if not set.",
 	NULL},
{"depr_sta_custom", (getter)Depreciation_get_depr_sta_custom,(setter)Depreciation_set_depr_sta_custom,
	"State custom depreciation [%/year], array.\n Required if depr_sta_type=3.",
 	NULL},
{"depr_sta_sl_years", (getter)Depreciation_get_depr_sta_sl_years,(setter)Depreciation_set_depr_sta_sl_years,
	"State depreciation straight-line years [years], number.\n Constraints: INTEGER,POSITIVE; Required if depr_sta_type=2.",
 	NULL},
{"depr_sta_type", (getter)Depreciation_get_depr_sta_type,(setter)Depreciation_set_depr_sta_type,
	"State depreciation type, number.\n 0=none,1=macrs_half_year,2=sl,3=custom; Constraints: INTEGER,MIN=0,MAX=3; 0 if not set.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Depreciation_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CashloanModel.Depreciation",             /*tp_name*/
		sizeof(DepreciationObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Depreciation_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Depreciation_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * TaxCreditIncentives Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Cashloan   data_ptr;
} TaxCreditIncentivesObject;

static PyTypeObject TaxCreditIncentives_Type;

static PyObject *
TaxCreditIncentives_new(SAM_Cashloan data_ptr)
{
	PyObject* new_obj = TaxCreditIncentives_Type.tp_alloc(&TaxCreditIncentives_Type,0);

	TaxCreditIncentivesObject* TaxCreditIncentives_obj = (TaxCreditIncentivesObject*)new_obj;

	TaxCreditIncentives_obj->data_ptr = data_ptr;

	return new_obj;
}

/* TaxCreditIncentives methods */

static PyObject *
TaxCreditIncentives_assign(TaxCreditIncentivesObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Cashloan", "TaxCreditIncentives")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TaxCreditIncentives_export(TaxCreditIncentivesObject *self, PyObject *args)
{
	PyTypeObject* tp = &TaxCreditIncentives_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TaxCreditIncentives_methods[] = {
		{"assign",            (PyCFunction)TaxCreditIncentives_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)TaxCreditIncentives_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TaxCreditIncentives_get_itc_fed_amount(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_TaxCreditIncentives_itc_fed_amount_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_amount(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_TaxCreditIncentives_itc_fed_amount_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_amount_deprbas_fed(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_TaxCreditIncentives_itc_fed_amount_deprbas_fed_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_amount_deprbas_fed(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_TaxCreditIncentives_itc_fed_amount_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_amount_deprbas_sta(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_TaxCreditIncentives_itc_fed_amount_deprbas_sta_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_amount_deprbas_sta(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_TaxCreditIncentives_itc_fed_amount_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_TaxCreditIncentives_itc_fed_percent_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_TaxCreditIncentives_itc_fed_percent_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent_deprbas_fed(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_TaxCreditIncentives_itc_fed_percent_deprbas_fed_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent_deprbas_fed(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_TaxCreditIncentives_itc_fed_percent_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent_deprbas_sta(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_TaxCreditIncentives_itc_fed_percent_deprbas_sta_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent_deprbas_sta(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_TaxCreditIncentives_itc_fed_percent_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent_maxvalue(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_TaxCreditIncentives_itc_fed_percent_maxvalue_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent_maxvalue(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_TaxCreditIncentives_itc_fed_percent_maxvalue_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_amount(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_TaxCreditIncentives_itc_sta_amount_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_amount(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_TaxCreditIncentives_itc_sta_amount_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_amount_deprbas_fed(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_TaxCreditIncentives_itc_sta_amount_deprbas_fed_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_amount_deprbas_fed(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_TaxCreditIncentives_itc_sta_amount_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_amount_deprbas_sta(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_TaxCreditIncentives_itc_sta_amount_deprbas_sta_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_amount_deprbas_sta(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_TaxCreditIncentives_itc_sta_amount_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_TaxCreditIncentives_itc_sta_percent_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_TaxCreditIncentives_itc_sta_percent_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent_deprbas_fed(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_TaxCreditIncentives_itc_sta_percent_deprbas_fed_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent_deprbas_fed(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_TaxCreditIncentives_itc_sta_percent_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent_deprbas_sta(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_TaxCreditIncentives_itc_sta_percent_deprbas_sta_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent_deprbas_sta(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_TaxCreditIncentives_itc_sta_percent_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent_maxvalue(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_TaxCreditIncentives_itc_sta_percent_maxvalue_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent_maxvalue(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_TaxCreditIncentives_itc_sta_percent_maxvalue_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_fed_amount(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_TaxCreditIncentives_ptc_fed_amount_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_fed_amount(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_TaxCreditIncentives_ptc_fed_amount_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_fed_escal(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_TaxCreditIncentives_ptc_fed_escal_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_fed_escal(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_TaxCreditIncentives_ptc_fed_escal_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_fed_term(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_TaxCreditIncentives_ptc_fed_term_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_fed_term(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_TaxCreditIncentives_ptc_fed_term_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_sta_amount(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_TaxCreditIncentives_ptc_sta_amount_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_sta_amount(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_TaxCreditIncentives_ptc_sta_amount_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_sta_escal(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_TaxCreditIncentives_ptc_sta_escal_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_sta_escal(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_TaxCreditIncentives_ptc_sta_escal_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_sta_term(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_TaxCreditIncentives_ptc_sta_term_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_sta_term(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_TaxCreditIncentives_ptc_sta_term_fset, self->data_ptr);
}

static PyGetSetDef TaxCreditIncentives_getset[] = {
{"itc_fed_amount", (getter)TaxCreditIncentives_get_itc_fed_amount,(setter)TaxCreditIncentives_set_itc_fed_amount,
	"Federal amount-based ITC amount [$], number.\n 0 if not set.",
 	NULL},
{"itc_fed_amount_deprbas_fed", (getter)TaxCreditIncentives_get_itc_fed_amount_deprbas_fed,(setter)TaxCreditIncentives_set_itc_fed_amount_deprbas_fed,
	"Federal amount-based ITC reduces federal depreciation basis [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"itc_fed_amount_deprbas_sta", (getter)TaxCreditIncentives_get_itc_fed_amount_deprbas_sta,(setter)TaxCreditIncentives_set_itc_fed_amount_deprbas_sta,
	"Federal amount-based ITC reduces state depreciation basis [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"itc_fed_percent", (getter)TaxCreditIncentives_get_itc_fed_percent,(setter)TaxCreditIncentives_set_itc_fed_percent,
	"Federal percentage-based ITC percent [%], number.\n 0 if not set.",
 	NULL},
{"itc_fed_percent_deprbas_fed", (getter)TaxCreditIncentives_get_itc_fed_percent_deprbas_fed,(setter)TaxCreditIncentives_set_itc_fed_percent_deprbas_fed,
	"Federal percentage-based ITC reduces federal depreciation basis [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"itc_fed_percent_deprbas_sta", (getter)TaxCreditIncentives_get_itc_fed_percent_deprbas_sta,(setter)TaxCreditIncentives_set_itc_fed_percent_deprbas_sta,
	"Federal percentage-based ITC reduces state depreciation basis [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"itc_fed_percent_maxvalue", (getter)TaxCreditIncentives_get_itc_fed_percent_maxvalue,(setter)TaxCreditIncentives_set_itc_fed_percent_maxvalue,
	"Federal percentage-based ITC maximum value [$], number.\n Required if ?=1e99.",
 	NULL},
{"itc_sta_amount", (getter)TaxCreditIncentives_get_itc_sta_amount,(setter)TaxCreditIncentives_set_itc_sta_amount,
	"State amount-based ITC amount [$], number.\n 0 if not set.",
 	NULL},
{"itc_sta_amount_deprbas_fed", (getter)TaxCreditIncentives_get_itc_sta_amount_deprbas_fed,(setter)TaxCreditIncentives_set_itc_sta_amount_deprbas_fed,
	"State amount-based ITC reduces federal depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"itc_sta_amount_deprbas_sta", (getter)TaxCreditIncentives_get_itc_sta_amount_deprbas_sta,(setter)TaxCreditIncentives_set_itc_sta_amount_deprbas_sta,
	"State amount-based ITC reduces state depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"itc_sta_percent", (getter)TaxCreditIncentives_get_itc_sta_percent,(setter)TaxCreditIncentives_set_itc_sta_percent,
	"State percentage-based ITC percent [%], number.\n 0 if not set.",
 	NULL},
{"itc_sta_percent_deprbas_fed", (getter)TaxCreditIncentives_get_itc_sta_percent_deprbas_fed,(setter)TaxCreditIncentives_set_itc_sta_percent_deprbas_fed,
	"State percentage-based ITC reduces federal depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"itc_sta_percent_deprbas_sta", (getter)TaxCreditIncentives_get_itc_sta_percent_deprbas_sta,(setter)TaxCreditIncentives_set_itc_sta_percent_deprbas_sta,
	"State percentage-based ITC reduces state depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"itc_sta_percent_maxvalue", (getter)TaxCreditIncentives_get_itc_sta_percent_maxvalue,(setter)TaxCreditIncentives_set_itc_sta_percent_maxvalue,
	"State percentage-based ITC maximum Value [$], number.\n Required if ?=1e99.",
 	NULL},
{"ptc_fed_amount", (getter)TaxCreditIncentives_get_ptc_fed_amount,(setter)TaxCreditIncentives_set_ptc_fed_amount,
	"Federal PTC amount [$/kWh], array.\n 0 if not set.",
 	NULL},
{"ptc_fed_escal", (getter)TaxCreditIncentives_get_ptc_fed_escal,(setter)TaxCreditIncentives_set_ptc_fed_escal,
	"Federal PTC escalation [%/year], number.\n 0 if not set.",
 	NULL},
{"ptc_fed_term", (getter)TaxCreditIncentives_get_ptc_fed_term,(setter)TaxCreditIncentives_set_ptc_fed_term,
	"Federal PTC term [years], number.\n Required if ?=10.",
 	NULL},
{"ptc_sta_amount", (getter)TaxCreditIncentives_get_ptc_sta_amount,(setter)TaxCreditIncentives_set_ptc_sta_amount,
	"State PTC amount [$/kWh], array.\n 0 if not set.",
 	NULL},
{"ptc_sta_escal", (getter)TaxCreditIncentives_get_ptc_sta_escal,(setter)TaxCreditIncentives_set_ptc_sta_escal,
	"State PTC escalation [%/year], number.\n 0 if not set.",
 	NULL},
{"ptc_sta_term", (getter)TaxCreditIncentives_get_ptc_sta_term,(setter)TaxCreditIncentives_set_ptc_sta_term,
	"State PTC term [years], number.\n Required if ?=10.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TaxCreditIncentives_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CashloanModel.TaxCreditIncentives",             /*tp_name*/
		sizeof(TaxCreditIncentivesObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		TaxCreditIncentives_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TaxCreditIncentives_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * PaymentIncentives Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Cashloan   data_ptr;
} PaymentIncentivesObject;

static PyTypeObject PaymentIncentives_Type;

static PyObject *
PaymentIncentives_new(SAM_Cashloan data_ptr)
{
	PyObject* new_obj = PaymentIncentives_Type.tp_alloc(&PaymentIncentives_Type,0);

	PaymentIncentivesObject* PaymentIncentives_obj = (PaymentIncentivesObject*)new_obj;

	PaymentIncentives_obj->data_ptr = data_ptr;

	return new_obj;
}

/* PaymentIncentives methods */

static PyObject *
PaymentIncentives_assign(PaymentIncentivesObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Cashloan", "PaymentIncentives")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PaymentIncentives_export(PaymentIncentivesObject *self, PyObject *args)
{
	PyTypeObject* tp = &PaymentIncentives_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef PaymentIncentives_methods[] = {
		{"assign",            (PyCFunction)PaymentIncentives_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)PaymentIncentives_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
PaymentIncentives_get_cbi_fed_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_fed_amount_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_fed_amount_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_fed_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_fed_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_fed_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_fed_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_maxvalue(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_fed_maxvalue_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_maxvalue(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_fed_maxvalue_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_fed_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_fed_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_fed_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_fed_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_oth_amount_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_oth_amount_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_oth_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_oth_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_oth_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_oth_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_maxvalue(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_oth_maxvalue_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_maxvalue(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_oth_maxvalue_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_oth_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_oth_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_oth_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_oth_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_sta_amount_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_sta_amount_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_sta_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_sta_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_sta_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_sta_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_maxvalue(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_sta_maxvalue_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_maxvalue(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_sta_maxvalue_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_sta_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_sta_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_sta_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_sta_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_uti_amount_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_uti_amount_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_uti_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_uti_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_uti_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_uti_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_maxvalue(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_uti_maxvalue_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_maxvalue(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_uti_maxvalue_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_uti_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_uti_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_cbi_uti_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_cbi_uti_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_fed_amount_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_fed_amount_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_fed_amount_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_fed_amount_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_fed_amount_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_fed_amount_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_fed_amount_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_fed_amount_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_fed_amount_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_fed_amount_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_fed_percent_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_fed_percent_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_fed_percent_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_fed_percent_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_fed_percent_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_fed_percent_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_maxvalue(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_fed_percent_maxvalue_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_maxvalue(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_fed_percent_maxvalue_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_fed_percent_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_fed_percent_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_fed_percent_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_fed_percent_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_oth_amount_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_oth_amount_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_oth_amount_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_oth_amount_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_oth_amount_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_oth_amount_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_oth_amount_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_oth_amount_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_oth_amount_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_oth_amount_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_oth_percent_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_oth_percent_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_oth_percent_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_oth_percent_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_oth_percent_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_oth_percent_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_maxvalue(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_oth_percent_maxvalue_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_maxvalue(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_oth_percent_maxvalue_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_oth_percent_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_oth_percent_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_oth_percent_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_oth_percent_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_sta_amount_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_sta_amount_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_sta_amount_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_sta_amount_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_sta_amount_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_sta_amount_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_sta_amount_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_sta_amount_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_sta_amount_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_sta_amount_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_sta_percent_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_sta_percent_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_sta_percent_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_sta_percent_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_sta_percent_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_sta_percent_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_maxvalue(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_sta_percent_maxvalue_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_maxvalue(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_sta_percent_maxvalue_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_sta_percent_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_sta_percent_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_sta_percent_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_sta_percent_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_uti_amount_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_uti_amount_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_uti_amount_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_uti_amount_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_uti_amount_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_uti_amount_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_uti_amount_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_uti_amount_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_uti_amount_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_uti_amount_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_uti_percent_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_uti_percent_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_uti_percent_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_uti_percent_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_uti_percent_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_uti_percent_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_maxvalue(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_uti_percent_maxvalue_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_maxvalue(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_uti_percent_maxvalue_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_uti_percent_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_uti_percent_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_ibi_uti_percent_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_ibi_uti_percent_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_PaymentIncentives_pbi_fed_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_PaymentIncentives_pbi_fed_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_escal(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_pbi_fed_escal_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_escal(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_pbi_fed_escal_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_pbi_fed_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_pbi_fed_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_pbi_fed_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_pbi_fed_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_term(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_pbi_fed_term_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_term(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_pbi_fed_term_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_PaymentIncentives_pbi_oth_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_PaymentIncentives_pbi_oth_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_escal(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_pbi_oth_escal_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_escal(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_pbi_oth_escal_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_pbi_oth_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_pbi_oth_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_pbi_oth_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_pbi_oth_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_term(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_pbi_oth_term_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_term(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_pbi_oth_term_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_PaymentIncentives_pbi_sta_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_PaymentIncentives_pbi_sta_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_escal(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_pbi_sta_escal_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_escal(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_pbi_sta_escal_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_pbi_sta_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_pbi_sta_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_pbi_sta_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_pbi_sta_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_term(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_pbi_sta_term_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_term(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_pbi_sta_term_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_PaymentIncentives_pbi_uti_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_PaymentIncentives_pbi_uti_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_escal(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_pbi_uti_escal_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_escal(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_pbi_uti_escal_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_pbi_uti_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_pbi_uti_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_pbi_uti_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_pbi_uti_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_term(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_PaymentIncentives_pbi_uti_term_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_term(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_PaymentIncentives_pbi_uti_term_fset, self->data_ptr);
}

static PyGetSetDef PaymentIncentives_getset[] = {
{"cbi_fed_amount", (getter)PaymentIncentives_get_cbi_fed_amount,(setter)PaymentIncentives_set_cbi_fed_amount,
	"Federal CBI amount [$/Watt], number.\n Required if ?=0.0.",
 	NULL},
{"cbi_fed_deprbas_fed", (getter)PaymentIncentives_get_cbi_fed_deprbas_fed,(setter)PaymentIncentives_set_cbi_fed_deprbas_fed,
	"Federal CBI reduces federal depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"cbi_fed_deprbas_sta", (getter)PaymentIncentives_get_cbi_fed_deprbas_sta,(setter)PaymentIncentives_set_cbi_fed_deprbas_sta,
	"Federal CBI reduces state depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"cbi_fed_maxvalue", (getter)PaymentIncentives_get_cbi_fed_maxvalue,(setter)PaymentIncentives_set_cbi_fed_maxvalue,
	"Federal CBI maximum [$], number.\n Required if ?=1e99.",
 	NULL},
{"cbi_fed_tax_fed", (getter)PaymentIncentives_get_cbi_fed_tax_fed,(setter)PaymentIncentives_set_cbi_fed_tax_fed,
	"Federal CBI federal taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"cbi_fed_tax_sta", (getter)PaymentIncentives_get_cbi_fed_tax_sta,(setter)PaymentIncentives_set_cbi_fed_tax_sta,
	"Federal CBI state taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"cbi_oth_amount", (getter)PaymentIncentives_get_cbi_oth_amount,(setter)PaymentIncentives_set_cbi_oth_amount,
	"Other CBI amount [$/Watt], number.\n Required if ?=0.0.",
 	NULL},
{"cbi_oth_deprbas_fed", (getter)PaymentIncentives_get_cbi_oth_deprbas_fed,(setter)PaymentIncentives_set_cbi_oth_deprbas_fed,
	"Other CBI reduces federal depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"cbi_oth_deprbas_sta", (getter)PaymentIncentives_get_cbi_oth_deprbas_sta,(setter)PaymentIncentives_set_cbi_oth_deprbas_sta,
	"Other CBI reduces state depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"cbi_oth_maxvalue", (getter)PaymentIncentives_get_cbi_oth_maxvalue,(setter)PaymentIncentives_set_cbi_oth_maxvalue,
	"Other CBI maximum [$], number.\n Required if ?=1e99.",
 	NULL},
{"cbi_oth_tax_fed", (getter)PaymentIncentives_get_cbi_oth_tax_fed,(setter)PaymentIncentives_set_cbi_oth_tax_fed,
	"Other CBI federal taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"cbi_oth_tax_sta", (getter)PaymentIncentives_get_cbi_oth_tax_sta,(setter)PaymentIncentives_set_cbi_oth_tax_sta,
	"Other CBI state taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"cbi_sta_amount", (getter)PaymentIncentives_get_cbi_sta_amount,(setter)PaymentIncentives_set_cbi_sta_amount,
	"State CBI amount [$/Watt], number.\n Required if ?=0.0.",
 	NULL},
{"cbi_sta_deprbas_fed", (getter)PaymentIncentives_get_cbi_sta_deprbas_fed,(setter)PaymentIncentives_set_cbi_sta_deprbas_fed,
	"State CBI reduces federal depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"cbi_sta_deprbas_sta", (getter)PaymentIncentives_get_cbi_sta_deprbas_sta,(setter)PaymentIncentives_set_cbi_sta_deprbas_sta,
	"State CBI reduces state depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"cbi_sta_maxvalue", (getter)PaymentIncentives_get_cbi_sta_maxvalue,(setter)PaymentIncentives_set_cbi_sta_maxvalue,
	"State CBI maximum [$], number.\n Required if ?=1e99.",
 	NULL},
{"cbi_sta_tax_fed", (getter)PaymentIncentives_get_cbi_sta_tax_fed,(setter)PaymentIncentives_set_cbi_sta_tax_fed,
	"State CBI federal taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"cbi_sta_tax_sta", (getter)PaymentIncentives_get_cbi_sta_tax_sta,(setter)PaymentIncentives_set_cbi_sta_tax_sta,
	"State CBI state taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"cbi_uti_amount", (getter)PaymentIncentives_get_cbi_uti_amount,(setter)PaymentIncentives_set_cbi_uti_amount,
	"Utility CBI amount [$/Watt], number.\n Required if ?=0.0.",
 	NULL},
{"cbi_uti_deprbas_fed", (getter)PaymentIncentives_get_cbi_uti_deprbas_fed,(setter)PaymentIncentives_set_cbi_uti_deprbas_fed,
	"Utility CBI reduces federal depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"cbi_uti_deprbas_sta", (getter)PaymentIncentives_get_cbi_uti_deprbas_sta,(setter)PaymentIncentives_set_cbi_uti_deprbas_sta,
	"Utility CBI reduces state depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"cbi_uti_maxvalue", (getter)PaymentIncentives_get_cbi_uti_maxvalue,(setter)PaymentIncentives_set_cbi_uti_maxvalue,
	"Utility CBI maximum [$], number.\n Required if ?=1e99.",
 	NULL},
{"cbi_uti_tax_fed", (getter)PaymentIncentives_get_cbi_uti_tax_fed,(setter)PaymentIncentives_set_cbi_uti_tax_fed,
	"Utility CBI federal taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"cbi_uti_tax_sta", (getter)PaymentIncentives_get_cbi_uti_tax_sta,(setter)PaymentIncentives_set_cbi_uti_tax_sta,
	"Utility CBI state taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"ibi_fed_amount", (getter)PaymentIncentives_get_ibi_fed_amount,(setter)PaymentIncentives_set_ibi_fed_amount,
	"Federal amount-based IBI amount [$], number.\n 0 if not set.",
 	NULL},
{"ibi_fed_amount_deprbas_fed", (getter)PaymentIncentives_get_ibi_fed_amount_deprbas_fed,(setter)PaymentIncentives_set_ibi_fed_amount_deprbas_fed,
	"Federal amount-based IBI reduces federal depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"ibi_fed_amount_deprbas_sta", (getter)PaymentIncentives_get_ibi_fed_amount_deprbas_sta,(setter)PaymentIncentives_set_ibi_fed_amount_deprbas_sta,
	"Federal amount-based IBI reduces state depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"ibi_fed_amount_tax_fed", (getter)PaymentIncentives_get_ibi_fed_amount_tax_fed,(setter)PaymentIncentives_set_ibi_fed_amount_tax_fed,
	"Federal amount-based IBI federal taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"ibi_fed_amount_tax_sta", (getter)PaymentIncentives_get_ibi_fed_amount_tax_sta,(setter)PaymentIncentives_set_ibi_fed_amount_tax_sta,
	"Federal amount-based IBI state taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"ibi_fed_percent", (getter)PaymentIncentives_get_ibi_fed_percent,(setter)PaymentIncentives_set_ibi_fed_percent,
	"Federal percentage-based IBI percent [%], number.\n Required if ?=0.0.",
 	NULL},
{"ibi_fed_percent_deprbas_fed", (getter)PaymentIncentives_get_ibi_fed_percent_deprbas_fed,(setter)PaymentIncentives_set_ibi_fed_percent_deprbas_fed,
	"Federal percentage-based IBI reduces federal depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"ibi_fed_percent_deprbas_sta", (getter)PaymentIncentives_get_ibi_fed_percent_deprbas_sta,(setter)PaymentIncentives_set_ibi_fed_percent_deprbas_sta,
	"Federal percentage-based IBI reduces state depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"ibi_fed_percent_maxvalue", (getter)PaymentIncentives_get_ibi_fed_percent_maxvalue,(setter)PaymentIncentives_set_ibi_fed_percent_maxvalue,
	"Federal percentage-based IBI maximum value [$], number.\n Required if ?=1e99.",
 	NULL},
{"ibi_fed_percent_tax_fed", (getter)PaymentIncentives_get_ibi_fed_percent_tax_fed,(setter)PaymentIncentives_set_ibi_fed_percent_tax_fed,
	"Federal percentage-based IBI federal taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"ibi_fed_percent_tax_sta", (getter)PaymentIncentives_get_ibi_fed_percent_tax_sta,(setter)PaymentIncentives_set_ibi_fed_percent_tax_sta,
	"Federal percentage-based IBI state taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"ibi_oth_amount", (getter)PaymentIncentives_get_ibi_oth_amount,(setter)PaymentIncentives_set_ibi_oth_amount,
	"Other amount-based IBI amount [$], number.\n 0 if not set.",
 	NULL},
{"ibi_oth_amount_deprbas_fed", (getter)PaymentIncentives_get_ibi_oth_amount_deprbas_fed,(setter)PaymentIncentives_set_ibi_oth_amount_deprbas_fed,
	"Other amount-based IBI reduces federal depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"ibi_oth_amount_deprbas_sta", (getter)PaymentIncentives_get_ibi_oth_amount_deprbas_sta,(setter)PaymentIncentives_set_ibi_oth_amount_deprbas_sta,
	"Other amount-based IBI reduces state depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"ibi_oth_amount_tax_fed", (getter)PaymentIncentives_get_ibi_oth_amount_tax_fed,(setter)PaymentIncentives_set_ibi_oth_amount_tax_fed,
	"Other amount-based IBI federal taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"ibi_oth_amount_tax_sta", (getter)PaymentIncentives_get_ibi_oth_amount_tax_sta,(setter)PaymentIncentives_set_ibi_oth_amount_tax_sta,
	"Other amount-based IBI state taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"ibi_oth_percent", (getter)PaymentIncentives_get_ibi_oth_percent,(setter)PaymentIncentives_set_ibi_oth_percent,
	"Other percentage-based IBI percent [%], number.\n Required if ?=0.0.",
 	NULL},
{"ibi_oth_percent_deprbas_fed", (getter)PaymentIncentives_get_ibi_oth_percent_deprbas_fed,(setter)PaymentIncentives_set_ibi_oth_percent_deprbas_fed,
	"Other percentage-based IBI reduces federal depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"ibi_oth_percent_deprbas_sta", (getter)PaymentIncentives_get_ibi_oth_percent_deprbas_sta,(setter)PaymentIncentives_set_ibi_oth_percent_deprbas_sta,
	"Other percentage-based IBI reduces state depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"ibi_oth_percent_maxvalue", (getter)PaymentIncentives_get_ibi_oth_percent_maxvalue,(setter)PaymentIncentives_set_ibi_oth_percent_maxvalue,
	"Other percentage-based IBI maximum value [$], number.\n Required if ?=1e99.",
 	NULL},
{"ibi_oth_percent_tax_fed", (getter)PaymentIncentives_get_ibi_oth_percent_tax_fed,(setter)PaymentIncentives_set_ibi_oth_percent_tax_fed,
	"Other percentage-based IBI federal taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"ibi_oth_percent_tax_sta", (getter)PaymentIncentives_get_ibi_oth_percent_tax_sta,(setter)PaymentIncentives_set_ibi_oth_percent_tax_sta,
	"Other percentage-based IBI state taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"ibi_sta_amount", (getter)PaymentIncentives_get_ibi_sta_amount,(setter)PaymentIncentives_set_ibi_sta_amount,
	"State amount-based IBI amount [$], number.\n 0 if not set.",
 	NULL},
{"ibi_sta_amount_deprbas_fed", (getter)PaymentIncentives_get_ibi_sta_amount_deprbas_fed,(setter)PaymentIncentives_set_ibi_sta_amount_deprbas_fed,
	"State amount-based IBI reduces federal depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"ibi_sta_amount_deprbas_sta", (getter)PaymentIncentives_get_ibi_sta_amount_deprbas_sta,(setter)PaymentIncentives_set_ibi_sta_amount_deprbas_sta,
	"State amount-based IBI reduces state depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"ibi_sta_amount_tax_fed", (getter)PaymentIncentives_get_ibi_sta_amount_tax_fed,(setter)PaymentIncentives_set_ibi_sta_amount_tax_fed,
	"State amount-based IBI federal taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"ibi_sta_amount_tax_sta", (getter)PaymentIncentives_get_ibi_sta_amount_tax_sta,(setter)PaymentIncentives_set_ibi_sta_amount_tax_sta,
	"State amount-based IBI state taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"ibi_sta_percent", (getter)PaymentIncentives_get_ibi_sta_percent,(setter)PaymentIncentives_set_ibi_sta_percent,
	"State percentage-based IBI percent [%], number.\n Required if ?=0.0.",
 	NULL},
{"ibi_sta_percent_deprbas_fed", (getter)PaymentIncentives_get_ibi_sta_percent_deprbas_fed,(setter)PaymentIncentives_set_ibi_sta_percent_deprbas_fed,
	"State percentage-based IBI reduces federal depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"ibi_sta_percent_deprbas_sta", (getter)PaymentIncentives_get_ibi_sta_percent_deprbas_sta,(setter)PaymentIncentives_set_ibi_sta_percent_deprbas_sta,
	"State percentage-based IBI reduces state depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"ibi_sta_percent_maxvalue", (getter)PaymentIncentives_get_ibi_sta_percent_maxvalue,(setter)PaymentIncentives_set_ibi_sta_percent_maxvalue,
	"State percentage-based IBI maximum value [$], number.\n Required if ?=1e99.",
 	NULL},
{"ibi_sta_percent_tax_fed", (getter)PaymentIncentives_get_ibi_sta_percent_tax_fed,(setter)PaymentIncentives_set_ibi_sta_percent_tax_fed,
	"State percentage-based IBI federal taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"ibi_sta_percent_tax_sta", (getter)PaymentIncentives_get_ibi_sta_percent_tax_sta,(setter)PaymentIncentives_set_ibi_sta_percent_tax_sta,
	"State percentage-based IBI state taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"ibi_uti_amount", (getter)PaymentIncentives_get_ibi_uti_amount,(setter)PaymentIncentives_set_ibi_uti_amount,
	"Utility amount-based IBI amount [$], number.\n 0 if not set.",
 	NULL},
{"ibi_uti_amount_deprbas_fed", (getter)PaymentIncentives_get_ibi_uti_amount_deprbas_fed,(setter)PaymentIncentives_set_ibi_uti_amount_deprbas_fed,
	"Utility amount-based IBI reduces federal depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"ibi_uti_amount_deprbas_sta", (getter)PaymentIncentives_get_ibi_uti_amount_deprbas_sta,(setter)PaymentIncentives_set_ibi_uti_amount_deprbas_sta,
	"Utility amount-based IBI reduces state depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"ibi_uti_amount_tax_fed", (getter)PaymentIncentives_get_ibi_uti_amount_tax_fed,(setter)PaymentIncentives_set_ibi_uti_amount_tax_fed,
	"Utility amount-based IBI federal taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"ibi_uti_amount_tax_sta", (getter)PaymentIncentives_get_ibi_uti_amount_tax_sta,(setter)PaymentIncentives_set_ibi_uti_amount_tax_sta,
	"Utility amount-based IBI state taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"ibi_uti_percent", (getter)PaymentIncentives_get_ibi_uti_percent,(setter)PaymentIncentives_set_ibi_uti_percent,
	"Utility percentage-based IBI percent [%], number.\n Required if ?=0.0.",
 	NULL},
{"ibi_uti_percent_deprbas_fed", (getter)PaymentIncentives_get_ibi_uti_percent_deprbas_fed,(setter)PaymentIncentives_set_ibi_uti_percent_deprbas_fed,
	"Utility percentage-based IBI reduces federal depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"ibi_uti_percent_deprbas_sta", (getter)PaymentIncentives_get_ibi_uti_percent_deprbas_sta,(setter)PaymentIncentives_set_ibi_uti_percent_deprbas_sta,
	"Utility percentage-based IBI reduces state depreciation basis [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"ibi_uti_percent_maxvalue", (getter)PaymentIncentives_get_ibi_uti_percent_maxvalue,(setter)PaymentIncentives_set_ibi_uti_percent_maxvalue,
	"Utility percentage-based IBI maximum value [$], number.\n Required if ?=1e99.",
 	NULL},
{"ibi_uti_percent_tax_fed", (getter)PaymentIncentives_get_ibi_uti_percent_tax_fed,(setter)PaymentIncentives_set_ibi_uti_percent_tax_fed,
	"Utility percentage-based IBI federal taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"ibi_uti_percent_tax_sta", (getter)PaymentIncentives_get_ibi_uti_percent_tax_sta,(setter)PaymentIncentives_set_ibi_uti_percent_tax_sta,
	"Utility percentage-based IBI state taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"pbi_fed_amount", (getter)PaymentIncentives_get_pbi_fed_amount,(setter)PaymentIncentives_set_pbi_fed_amount,
	"Federal PBI amount [$/kWh], array.\n 0 if not set.",
 	NULL},
{"pbi_fed_escal", (getter)PaymentIncentives_get_pbi_fed_escal,(setter)PaymentIncentives_set_pbi_fed_escal,
	"Federal PBI escalation [%], number.\n 0 if not set.",
 	NULL},
{"pbi_fed_tax_fed", (getter)PaymentIncentives_get_pbi_fed_tax_fed,(setter)PaymentIncentives_set_pbi_fed_tax_fed,
	"Federal PBI federal taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"pbi_fed_tax_sta", (getter)PaymentIncentives_get_pbi_fed_tax_sta,(setter)PaymentIncentives_set_pbi_fed_tax_sta,
	"Federal PBI state taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"pbi_fed_term", (getter)PaymentIncentives_get_pbi_fed_term,(setter)PaymentIncentives_set_pbi_fed_term,
	"Federal PBI term [years], number.\n 0 if not set.",
 	NULL},
{"pbi_oth_amount", (getter)PaymentIncentives_get_pbi_oth_amount,(setter)PaymentIncentives_set_pbi_oth_amount,
	"Other PBI amount [$/kWh], array.\n 0 if not set.",
 	NULL},
{"pbi_oth_escal", (getter)PaymentIncentives_get_pbi_oth_escal,(setter)PaymentIncentives_set_pbi_oth_escal,
	"Other PBI escalation [%], number.\n 0 if not set.",
 	NULL},
{"pbi_oth_tax_fed", (getter)PaymentIncentives_get_pbi_oth_tax_fed,(setter)PaymentIncentives_set_pbi_oth_tax_fed,
	"Other PBI federal taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"pbi_oth_tax_sta", (getter)PaymentIncentives_get_pbi_oth_tax_sta,(setter)PaymentIncentives_set_pbi_oth_tax_sta,
	"Other PBI state taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"pbi_oth_term", (getter)PaymentIncentives_get_pbi_oth_term,(setter)PaymentIncentives_set_pbi_oth_term,
	"Other PBI term [years], number.\n 0 if not set.",
 	NULL},
{"pbi_sta_amount", (getter)PaymentIncentives_get_pbi_sta_amount,(setter)PaymentIncentives_set_pbi_sta_amount,
	"State PBI amount [$/kWh], array.\n 0 if not set.",
 	NULL},
{"pbi_sta_escal", (getter)PaymentIncentives_get_pbi_sta_escal,(setter)PaymentIncentives_set_pbi_sta_escal,
	"State PBI escalation [%], number.\n 0 if not set.",
 	NULL},
{"pbi_sta_tax_fed", (getter)PaymentIncentives_get_pbi_sta_tax_fed,(setter)PaymentIncentives_set_pbi_sta_tax_fed,
	"State PBI federal taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"pbi_sta_tax_sta", (getter)PaymentIncentives_get_pbi_sta_tax_sta,(setter)PaymentIncentives_set_pbi_sta_tax_sta,
	"State PBI state taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"pbi_sta_term", (getter)PaymentIncentives_get_pbi_sta_term,(setter)PaymentIncentives_set_pbi_sta_term,
	"State PBI term [years], number.\n 0 if not set.",
 	NULL},
{"pbi_uti_amount", (getter)PaymentIncentives_get_pbi_uti_amount,(setter)PaymentIncentives_set_pbi_uti_amount,
	"Utility PBI amount [$/kWh], array.\n 0 if not set.",
 	NULL},
{"pbi_uti_escal", (getter)PaymentIncentives_get_pbi_uti_escal,(setter)PaymentIncentives_set_pbi_uti_escal,
	"Utility PBI escalation [%], number.\n 0 if not set.",
 	NULL},
{"pbi_uti_tax_fed", (getter)PaymentIncentives_get_pbi_uti_tax_fed,(setter)PaymentIncentives_set_pbi_uti_tax_fed,
	"Utility PBI federal taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"pbi_uti_tax_sta", (getter)PaymentIncentives_get_pbi_uti_tax_sta,(setter)PaymentIncentives_set_pbi_uti_tax_sta,
	"Utility PBI state taxable [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"pbi_uti_term", (getter)PaymentIncentives_get_pbi_uti_term,(setter)PaymentIncentives_set_pbi_uti_term,
	"Utility PBI term [years], number.\n 0 if not set.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject PaymentIncentives_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CashloanModel.PaymentIncentives",             /*tp_name*/
		sizeof(PaymentIncentivesObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		PaymentIncentives_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		PaymentIncentives_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * Battery Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Cashloan   data_ptr;
} BatteryObject;

static PyTypeObject Battery_Type;

static PyObject *
Battery_new(SAM_Cashloan data_ptr)
{
	PyObject* new_obj = Battery_Type.tp_alloc(&Battery_Type,0);

	BatteryObject* Battery_obj = (BatteryObject*)new_obj;

	Battery_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Battery methods */

static PyObject *
Battery_assign(BatteryObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Cashloan", "Battery")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Battery_export(BatteryObject *self, PyObject *args)
{
	PyTypeObject* tp = &Battery_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Battery_methods[] = {
		{"assign",            (PyCFunction)Battery_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Battery_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Battery_get_batt_bank_replacement(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Battery_batt_bank_replacement_aget, self->data_ptr);
}

static int
Battery_set_batt_bank_replacement(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_Battery_batt_bank_replacement_aset, self->data_ptr);
}

static PyObject *
Battery_get_batt_computed_bank_capacity(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Battery_batt_computed_bank_capacity_fget, self->data_ptr);
}

static int
Battery_set_batt_computed_bank_capacity(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_Battery_batt_computed_bank_capacity_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_replacement_option(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Battery_batt_replacement_option_fget, self->data_ptr);
}

static int
Battery_set_batt_replacement_option(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_Battery_batt_replacement_option_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_replacement_schedule(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Battery_batt_replacement_schedule_aget, self->data_ptr);
}

static int
Battery_set_batt_replacement_schedule(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_Battery_batt_replacement_schedule_aset, self->data_ptr);
}

static PyObject *
Battery_get_battery_per_kWh(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Battery_battery_per_kWh_fget, self->data_ptr);
}

static int
Battery_set_battery_per_kWh(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_Battery_battery_per_kWh_fset, self->data_ptr);
}

static PyObject *
Battery_get_en_batt(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Battery_en_batt_fget, self->data_ptr);
}

static int
Battery_set_en_batt(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_Battery_en_batt_fset, self->data_ptr);
}

static PyGetSetDef Battery_getset[] = {
{"batt_bank_replacement", (getter)Battery_get_batt_bank_replacement,(setter)Battery_set_batt_bank_replacement,
	"Battery bank replacements per year [number/year], array.\n ",
 	NULL},
{"batt_computed_bank_capacity", (getter)Battery_get_batt_computed_bank_capacity,(setter)Battery_set_batt_computed_bank_capacity,
	"Battery bank capacity [kWh], number.\n Required if ?=0.0.",
 	NULL},
{"batt_replacement_option", (getter)Battery_get_batt_replacement_option,(setter)Battery_set_batt_replacement_option,
	"Enable battery replacement? [0=none,1=capacity based,2=user schedule], number.\n Constraints: INTEGER,MIN=0,MAX=2; 0 if not set.",
 	NULL},
{"batt_replacement_schedule", (getter)Battery_get_batt_replacement_schedule,(setter)Battery_set_batt_replacement_schedule,
	"Battery bank replacements per year (user specified) [number/year], array.\n ",
 	NULL},
{"battery_per_kWh", (getter)Battery_get_battery_per_kWh,(setter)Battery_set_battery_per_kWh,
	"Battery cost [$/kWh], number.\n Required if ?=0.0.",
 	NULL},
{"en_batt", (getter)Battery_get_en_batt,(setter)Battery_set_en_batt,
	"Enable battery storage model [0/1], number.\n 0 if not set.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Battery_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CashloanModel.Battery",             /*tp_name*/
		sizeof(BatteryObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Battery_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Battery_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * FuelCell Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Cashloan   data_ptr;
} FuelCellObject;

static PyTypeObject FuelCell_Type;

static PyObject *
FuelCell_new(SAM_Cashloan data_ptr)
{
	PyObject* new_obj = FuelCell_Type.tp_alloc(&FuelCell_Type,0);

	FuelCellObject* FuelCell_obj = (FuelCellObject*)new_obj;

	FuelCell_obj->data_ptr = data_ptr;

	return new_obj;
}

/* FuelCell methods */

static PyObject *
FuelCell_assign(FuelCellObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Cashloan", "FuelCell")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FuelCell_export(FuelCellObject *self, PyObject *args)
{
	PyTypeObject* tp = &FuelCell_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef FuelCell_methods[] = {
		{"assign",            (PyCFunction)FuelCell_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)FuelCell_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
FuelCell_get_en_fuelcell(FuelCellObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_FuelCell_en_fuelcell_fget, self->data_ptr);
}

static int
FuelCell_set_en_fuelcell(FuelCellObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_FuelCell_en_fuelcell_fset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_computed_bank_capacity(FuelCellObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_FuelCell_fuelcell_computed_bank_capacity_fget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_computed_bank_capacity(FuelCellObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_FuelCell_fuelcell_computed_bank_capacity_fset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_per_kWh(FuelCellObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_FuelCell_fuelcell_per_kWh_fget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_per_kWh(FuelCellObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_FuelCell_fuelcell_per_kWh_fset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_replacement(FuelCellObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_FuelCell_fuelcell_replacement_aget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_replacement(FuelCellObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_FuelCell_fuelcell_replacement_aset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_replacement_option(FuelCellObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_FuelCell_fuelcell_replacement_option_fget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_replacement_option(FuelCellObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_FuelCell_fuelcell_replacement_option_fset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_replacement_schedule(FuelCellObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_FuelCell_fuelcell_replacement_schedule_aget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_replacement_schedule(FuelCellObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_FuelCell_fuelcell_replacement_schedule_aset, self->data_ptr);
}

static PyGetSetDef FuelCell_getset[] = {
{"en_fuelcell", (getter)FuelCell_get_en_fuelcell,(setter)FuelCell_set_en_fuelcell,
	"Enable fuel cell storage model [0/1], number.\n 0 if not set.",
 	NULL},
{"fuelcell_computed_bank_capacity", (getter)FuelCell_get_fuelcell_computed_bank_capacity,(setter)FuelCell_set_fuelcell_computed_bank_capacity,
	"Fuel cell capacity [kWh], number.\n Required if ?=0.0.",
 	NULL},
{"fuelcell_per_kWh", (getter)FuelCell_get_fuelcell_per_kWh,(setter)FuelCell_set_fuelcell_per_kWh,
	"Fuel cell cost [$/kWh], number.\n Required if ?=0.0.",
 	NULL},
{"fuelcell_replacement", (getter)FuelCell_get_fuelcell_replacement,(setter)FuelCell_set_fuelcell_replacement,
	"Fuel cell replacements per year [number/year], array.\n ",
 	NULL},
{"fuelcell_replacement_option", (getter)FuelCell_get_fuelcell_replacement_option,(setter)FuelCell_set_fuelcell_replacement_option,
	"Enable fuel cell replacement? [0=none,1=capacity based,2=user schedule], number.\n Constraints: INTEGER,MIN=0,MAX=2; 0 if not set.",
 	NULL},
{"fuelcell_replacement_schedule", (getter)FuelCell_get_fuelcell_replacement_schedule,(setter)FuelCell_set_fuelcell_replacement_schedule,
	"Fuel cell replacements per year (user specified) [number/year], array.\n ",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FuelCell_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CashloanModel.FuelCell",             /*tp_name*/
		sizeof(FuelCellObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		FuelCell_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		FuelCell_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * Cashloan Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Cashloan   data_ptr;
} CashloanObject;

static PyTypeObject Cashloan_Type;

static PyObject *
Cashloan_new(SAM_Cashloan data_ptr)
{
	PyObject* new_obj = Cashloan_Type.tp_alloc(&Cashloan_Type,0);

	CashloanObject* Cashloan_obj = (CashloanObject*)new_obj;

	Cashloan_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Cashloan methods */

static PyObject *
Cashloan_assign(CashloanObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Cashloan", "Cashloan")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Cashloan_export(CashloanObject *self, PyObject *args)
{
	PyTypeObject* tp = &Cashloan_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Cashloan_methods[] = {
		{"assign",            (PyCFunction)Cashloan_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Cashloan_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Cashloan_get_annual_energy_value(CashloanObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Cashloan_annual_energy_value_aget, self->data_ptr);
}

static int
Cashloan_set_annual_energy_value(CashloanObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_Cashloan_annual_energy_value_aset, self->data_ptr);
}

static PyObject *
Cashloan_get_annual_themal_value(CashloanObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Cashloan_annual_themal_value_aget, self->data_ptr);
}

static int
Cashloan_set_annual_themal_value(CashloanObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_Cashloan_annual_themal_value_aset, self->data_ptr);
}

static PyObject *
Cashloan_get_market(CashloanObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Cashloan_market_fget, self->data_ptr);
}

static int
Cashloan_set_market(CashloanObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_Cashloan_market_fset, self->data_ptr);
}

static PyObject *
Cashloan_get_mortgage(CashloanObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Cashloan_mortgage_fget, self->data_ptr);
}

static int
Cashloan_set_mortgage(CashloanObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_Cashloan_mortgage_fset, self->data_ptr);
}

static PyObject *
Cashloan_get_salvage_percentage(CashloanObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Cashloan_salvage_percentage_fget, self->data_ptr);
}

static int
Cashloan_set_salvage_percentage(CashloanObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_Cashloan_salvage_percentage_fset, self->data_ptr);
}

static PyObject *
Cashloan_get_total_installed_cost(CashloanObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Cashloan_total_installed_cost_fget, self->data_ptr);
}

static int
Cashloan_set_total_installed_cost(CashloanObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_Cashloan_total_installed_cost_fset, self->data_ptr);
}

static PyGetSetDef Cashloan_getset[] = {
{"annual_energy_value", (getter)Cashloan_get_annual_energy_value,(setter)Cashloan_set_annual_energy_value,
	"Energy value [$], array.\n Required.",
 	NULL},
{"annual_themal_value", (getter)Cashloan_get_annual_themal_value,(setter)Cashloan_set_annual_themal_value,
	"Energy value [$], array.\n ",
 	NULL},
{"market", (getter)Cashloan_get_market,(setter)Cashloan_set_market,
	"Residential or Commercial Market [0/1], number.\n 0=residential,1=comm.; Constraints: INTEGER,MIN=0,MAX=1; Required if ?=1.",
 	NULL},
{"mortgage", (getter)Cashloan_get_mortgage,(setter)Cashloan_set_mortgage,
	"Use mortgage style loan (res. only) [0/1], number.\n 0=standard loan,1=mortgage; Constraints: INTEGER,MIN=0,MAX=1; 0 if not set.",
 	NULL},
{"salvage_percentage", (getter)Cashloan_get_salvage_percentage,(setter)Cashloan_set_salvage_percentage,
	"Salvage value percentage [%], number.\n Constraints: MIN=0,MAX=100; Required if ?=0.0.",
 	NULL},
{"total_installed_cost", (getter)Cashloan_get_total_installed_cost,(setter)Cashloan_set_total_installed_cost,
	"Total installed cost [$], number.\n Constraints: MIN=0; Required.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Cashloan_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CashloanModel.Cashloan",             /*tp_name*/
		sizeof(CashloanObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Cashloan_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Cashloan_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * SystemOutput Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Cashloan   data_ptr;
} SystemOutputObject;

static PyTypeObject SystemOutput_Type;

static PyObject *
SystemOutput_new(SAM_Cashloan data_ptr)
{
	PyObject* new_obj = SystemOutput_Type.tp_alloc(&SystemOutput_Type,0);

	SystemOutputObject* SystemOutput_obj = (SystemOutputObject*)new_obj;

	SystemOutput_obj->data_ptr = data_ptr;

	return new_obj;
}

/* SystemOutput methods */

static PyObject *
SystemOutput_assign(SystemOutputObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Cashloan", "SystemOutput")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemOutput_export(SystemOutputObject *self, PyObject *args)
{
	PyTypeObject* tp = &SystemOutput_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SystemOutput_methods[] = {
		{"assign",            (PyCFunction)SystemOutput_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)SystemOutput_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemOutput_get_degradation(SystemOutputObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_SystemOutput_degradation_aget, self->data_ptr);
}

static int
SystemOutput_set_degradation(SystemOutputObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_SystemOutput_degradation_aset, self->data_ptr);
}

static PyObject *
SystemOutput_get_gen(SystemOutputObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_SystemOutput_gen_aget, self->data_ptr);
}

static int
SystemOutput_set_gen(SystemOutputObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_SystemOutput_gen_aset, self->data_ptr);
}

static PyGetSetDef SystemOutput_getset[] = {
{"degradation", (getter)SystemOutput_get_degradation,(setter)SystemOutput_set_degradation,
	"Annual degradation [%], array.\n Required.",
 	NULL},
{"gen", (getter)SystemOutput_get_gen,(setter)SystemOutput_set_gen,
	"Power generated by renewable resource [kW], array.\n Required.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemOutput_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CashloanModel.SystemOutput",             /*tp_name*/
		sizeof(SystemOutputObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		SystemOutput_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SystemOutput_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * Lifetime Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Cashloan   data_ptr;
} LifetimeObject;

static PyTypeObject Lifetime_Type;

static PyObject *
Lifetime_new(SAM_Cashloan data_ptr)
{
	PyObject* new_obj = Lifetime_Type.tp_alloc(&Lifetime_Type,0);

	LifetimeObject* Lifetime_obj = (LifetimeObject*)new_obj;

	Lifetime_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Lifetime methods */

static PyObject *
Lifetime_assign(LifetimeObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Cashloan", "Lifetime")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Lifetime_export(LifetimeObject *self, PyObject *args)
{
	PyTypeObject* tp = &Lifetime_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Lifetime_methods[] = {
		{"assign",            (PyCFunction)Lifetime_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Lifetime_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Lifetime_get_system_use_lifetime_output(LifetimeObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Lifetime_system_use_lifetime_output_fget, self->data_ptr);
}

static int
Lifetime_set_system_use_lifetime_output(LifetimeObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Cashloan_Lifetime_system_use_lifetime_output_fset, self->data_ptr);
}

static PyGetSetDef Lifetime_getset[] = {
{"system_use_lifetime_output", (getter)Lifetime_get_system_use_lifetime_output,(setter)Lifetime_set_system_use_lifetime_output,
	"Lifetime hourly system outputs [0/1], number.\n 0=hourly first year,1=hourly lifetime; Constraints: INTEGER,MIN=0; Required.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Lifetime_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CashloanModel.Lifetime",             /*tp_name*/
		sizeof(LifetimeObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Lifetime_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Lifetime_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * ThirdPartyOwnership Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Cashloan   data_ptr;
} ThirdPartyOwnershipObject;

static PyTypeObject ThirdPartyOwnership_Type;

static PyObject *
ThirdPartyOwnership_new(SAM_Cashloan data_ptr)
{
	PyObject* new_obj = ThirdPartyOwnership_Type.tp_alloc(&ThirdPartyOwnership_Type,0);

	ThirdPartyOwnershipObject* ThirdPartyOwnership_obj = (ThirdPartyOwnershipObject*)new_obj;

	ThirdPartyOwnership_obj->data_ptr = data_ptr;

	return new_obj;
}

/* ThirdPartyOwnership methods */

static PyObject *
ThirdPartyOwnership_assign(ThirdPartyOwnershipObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Cashloan", "ThirdPartyOwnership")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ThirdPartyOwnership_export(ThirdPartyOwnershipObject *self, PyObject *args)
{
	PyTypeObject* tp = &ThirdPartyOwnership_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ThirdPartyOwnership_methods[] = {
		{"assign",            (PyCFunction)ThirdPartyOwnership_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)ThirdPartyOwnership_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ThirdPartyOwnership_get_elec_cost_with_system(ThirdPartyOwnershipObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_ThirdPartyOwnership_elec_cost_with_system_aget, self->data_ptr);
}

static int
ThirdPartyOwnership_set_elec_cost_with_system(ThirdPartyOwnershipObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_ThirdPartyOwnership_elec_cost_with_system_aset, self->data_ptr);
}

static PyObject *
ThirdPartyOwnership_get_elec_cost_without_system(ThirdPartyOwnershipObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_ThirdPartyOwnership_elec_cost_without_system_aget, self->data_ptr);
}

static int
ThirdPartyOwnership_set_elec_cost_without_system(ThirdPartyOwnershipObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Cashloan_ThirdPartyOwnership_elec_cost_without_system_aset, self->data_ptr);
}

static PyGetSetDef ThirdPartyOwnership_getset[] = {
{"elec_cost_with_system", (getter)ThirdPartyOwnership_get_elec_cost_with_system,(setter)ThirdPartyOwnership_set_elec_cost_with_system,
	"Energy value [$], array.\n Required.",
 	NULL},
{"elec_cost_without_system", (getter)ThirdPartyOwnership_get_elec_cost_without_system,(setter)ThirdPartyOwnership_set_elec_cost_without_system,
	"Energy value [$], array.\n Required.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ThirdPartyOwnership_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CashloanModel.ThirdPartyOwnership",             /*tp_name*/
		sizeof(ThirdPartyOwnershipObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		ThirdPartyOwnership_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ThirdPartyOwnership_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * Outputs Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Cashloan   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Cashloan data_ptr)
{
	PyObject* new_obj = Outputs_Type.tp_alloc(&Outputs_Type,0);

	OutputsObject* Outputs_obj = (OutputsObject*)new_obj;

	Outputs_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Outputs methods */

static PyObject *
Outputs_assign(OutputsObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Cashloan", "Outputs")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Outputs_export(OutputsObject *self, PyObject *args)
{
	PyTypeObject* tp = &Outputs_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Outputs_methods[] = {
		{"assign",            (PyCFunction)Outputs_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Outputs_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Outputs_get_adjusted_installed_cost(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_adjusted_installed_cost_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_cbi_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_fed(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_cbi_total_fed_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_oth(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_cbi_total_oth_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_sta(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_cbi_total_sta_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_uti(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_cbi_total_uti_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_after_tax_cash_flow(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_after_tax_cash_flow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_after_tax_net_equity_cost_flow(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_after_tax_net_equity_cost_flow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_battery_replacement_cost(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_battery_replacement_cost_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_battery_replacement_cost_schedule(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_battery_replacement_cost_schedule_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_cumulative_payback_with_expenses(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_cumulative_payback_with_expenses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_cumulative_payback_without_expenses(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_cumulative_payback_without_expenses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_debt_balance(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_debt_balance_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_debt_payment_interest(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_debt_payment_interest_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_debt_payment_principal(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_debt_payment_principal_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_debt_payment_total(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_debt_payment_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_deductible_expenses(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_deductible_expenses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_discounted_costs(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_discounted_costs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_discounted_cumulative_payback(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_discounted_cumulative_payback_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_discounted_payback(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_discounted_payback_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_discounted_savings(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_discounted_savings_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_effective_tax_frac(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_effective_tax_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_energy_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_value(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_energy_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fed_depr_sched(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_fed_depr_sched_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fed_depreciation(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_fed_depreciation_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fed_incentive_income_less_deductions(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_fed_incentive_income_less_deductions_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fed_tax_savings(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_fed_tax_savings_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fed_taxable_income_less_deductions(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_fed_taxable_income_less_deductions_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_federal_tax_frac(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_federal_tax_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fuelcell_replacement_cost(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_fuelcell_replacement_cost_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_fuelcell_replacement_cost_schedule(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_fuelcell_replacement_cost_schedule_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_insurance_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_insurance_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_length(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_cf_length_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_net_salvage_value(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_net_salvage_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_nte(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_nte_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_capacity1_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_om_capacity1_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_capacity2_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_om_capacity2_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_capacity_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_om_capacity_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_fixed1_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_om_fixed1_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_fixed2_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_om_fixed2_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_fixed_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_om_fixed_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_fuel_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_om_fuel_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_opt_fuel_1_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_om_opt_fuel_1_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_opt_fuel_2_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_om_opt_fuel_2_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_production1_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_om_production1_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_production2_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_om_production2_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_production_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_om_production_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_operating_expenses(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_operating_expenses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_payback_with_expenses(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_payback_with_expenses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_payback_without_expenses(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_payback_without_expenses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_pbi_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_fed(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_pbi_total_fed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_oth(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_pbi_total_oth_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_sta(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_pbi_total_sta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_uti(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_pbi_total_uti_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_property_tax_assessed_value(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_property_tax_assessed_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_property_tax_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_property_tax_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_ptc_fed(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_ptc_fed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_ptc_sta(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_ptc_sta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_ptc_total(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_ptc_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sta_and_fed_tax_savings(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_sta_and_fed_tax_savings_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sta_depr_sched(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_sta_depr_sched_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sta_depreciation(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_sta_depreciation_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sta_incentive_income_less_deductions(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_sta_incentive_income_less_deductions_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sta_tax_savings(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_sta_tax_savings_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sta_taxable_income_less_deductions(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_sta_taxable_income_less_deductions_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_state_tax_frac(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_state_tax_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_thermal_value(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_thermal_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_value_added(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Cashloan_Outputs_cf_value_added_aget, self->data_ptr);
}

static PyObject *
Outputs_get_discounted_payback(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_discounted_payback_fget, self->data_ptr);
}

static PyObject *
Outputs_get_effective_tax_rate(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_effective_tax_rate_fget, self->data_ptr);
}

static PyObject *
Outputs_get_first_cost(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_first_cost_fget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_ibi_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_fed(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_ibi_total_fed_fget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_oth(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_ibi_total_oth_fget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_sta(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_ibi_total_sta_fget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_uti(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_ibi_total_uti_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_itc_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_total_fed(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_itc_total_fed_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_total_sta(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_itc_total_sta_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoe_nom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_lcoe_nom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoe_real(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_lcoe_real_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_fed_nom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_lcoptc_fed_nom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_fed_real(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_lcoptc_fed_real_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_sta_nom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_lcoptc_sta_nom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_sta_real(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_lcoptc_sta_real_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lnte_nom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_lnte_nom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lnte_real(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_lnte_real_fget, self->data_ptr);
}

static PyObject *
Outputs_get_loan_amount(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_loan_amount_fget, self->data_ptr);
}

static PyObject *
Outputs_get_npv(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_npv_fget, self->data_ptr);
}

static PyObject *
Outputs_get_payback(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_payback_fget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_fuel(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_present_value_fuel_fget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_insandproptax(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_present_value_insandproptax_fget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_oandm(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_present_value_oandm_fget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_oandm_nonfuel(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_present_value_oandm_nonfuel_fget, self->data_ptr);
}

static PyObject *
Outputs_get_total_cost(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_total_cost_fget, self->data_ptr);
}

static PyObject *
Outputs_get_wacc(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_wacc_fget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_nte(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Cashloan_Outputs_year1_nte_fget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"adjusted_installed_cost", (getter)Outputs_get_adjusted_installed_cost,(setter)0,
	"Net capital cost [$], number.",
 	NULL},
{"cbi_total", (getter)Outputs_get_cbi_total,(setter)0,
	"Total CBI income [$], number.",
 	NULL},
{"cbi_total_fed", (getter)Outputs_get_cbi_total_fed,(setter)0,
	"Federal CBI income [$], number.",
 	NULL},
{"cbi_total_oth", (getter)Outputs_get_cbi_total_oth,(setter)0,
	"Other CBI income [$], number.",
 	NULL},
{"cbi_total_sta", (getter)Outputs_get_cbi_total_sta,(setter)0,
	"State CBI income [$], number.",
 	NULL},
{"cbi_total_uti", (getter)Outputs_get_cbi_total_uti,(setter)0,
	"Utility CBI income [$], number.",
 	NULL},
{"cf_after_tax_cash_flow", (getter)Outputs_get_cf_after_tax_cash_flow,(setter)0,
	"After-tax cash flow [$], array.",
 	NULL},
{"cf_after_tax_net_equity_cost_flow", (getter)Outputs_get_cf_after_tax_net_equity_cost_flow,(setter)0,
	"After-tax annual costs [$], array.",
 	NULL},
{"cf_battery_replacement_cost", (getter)Outputs_get_cf_battery_replacement_cost,(setter)0,
	"Battery replacement cost [$], array.",
 	NULL},
{"cf_battery_replacement_cost_schedule", (getter)Outputs_get_cf_battery_replacement_cost_schedule,(setter)0,
	"Battery replacement cost schedule [$/kWh], array.",
 	NULL},
{"cf_cumulative_payback_with_expenses", (getter)Outputs_get_cf_cumulative_payback_with_expenses,(setter)0,
	"Cumulative simple payback with expenses [$], array.",
 	NULL},
{"cf_cumulative_payback_without_expenses", (getter)Outputs_get_cf_cumulative_payback_without_expenses,(setter)0,
	"Cumulative simple payback without expenses [$], array.",
 	NULL},
{"cf_debt_balance", (getter)Outputs_get_cf_debt_balance,(setter)0,
	"Debt balance [$], array.",
 	NULL},
{"cf_debt_payment_interest", (getter)Outputs_get_cf_debt_payment_interest,(setter)0,
	"Interest payment [$], array.",
 	NULL},
{"cf_debt_payment_principal", (getter)Outputs_get_cf_debt_payment_principal,(setter)0,
	"Principal payment [$], array.",
 	NULL},
{"cf_debt_payment_total", (getter)Outputs_get_cf_debt_payment_total,(setter)0,
	"Total P&I debt payment [$], array.",
 	NULL},
{"cf_deductible_expenses", (getter)Outputs_get_cf_deductible_expenses,(setter)0,
	"Deductible expenses [$], array.",
 	NULL},
{"cf_discounted_costs", (getter)Outputs_get_cf_discounted_costs,(setter)0,
	"Discounted costs [$], array.",
 	NULL},
{"cf_discounted_cumulative_payback", (getter)Outputs_get_cf_discounted_cumulative_payback,(setter)0,
	"Cumulative discounted payback [$], array.",
 	NULL},
{"cf_discounted_payback", (getter)Outputs_get_cf_discounted_payback,(setter)0,
	"Discounted payback [$], array.",
 	NULL},
{"cf_discounted_savings", (getter)Outputs_get_cf_discounted_savings,(setter)0,
	"Discounted savings [$], array.",
 	NULL},
{"cf_effective_tax_frac", (getter)Outputs_get_cf_effective_tax_frac,(setter)0,
	"Effective income tax rate [frac], array.",
 	NULL},
{"cf_energy_net", (getter)Outputs_get_cf_energy_net,(setter)0,
	"Energy [kWh], array.",
 	NULL},
{"cf_energy_value", (getter)Outputs_get_cf_energy_value,(setter)0,
	"Value of electricity savings [$], array.",
 	NULL},
{"cf_fed_depr_sched", (getter)Outputs_get_cf_fed_depr_sched,(setter)0,
	"Federal depreciation schedule [%], array.",
 	NULL},
{"cf_fed_depreciation", (getter)Outputs_get_cf_fed_depreciation,(setter)0,
	"Federal depreciation [$], array.",
 	NULL},
{"cf_fed_incentive_income_less_deductions", (getter)Outputs_get_cf_fed_incentive_income_less_deductions,(setter)0,
	"Federal incentive income less deductions [$], array.",
 	NULL},
{"cf_fed_tax_savings", (getter)Outputs_get_cf_fed_tax_savings,(setter)0,
	"Federal tax savings [$], array.",
 	NULL},
{"cf_fed_taxable_income_less_deductions", (getter)Outputs_get_cf_fed_taxable_income_less_deductions,(setter)0,
	"Federal taxable income less deductions [$], array.",
 	NULL},
{"cf_federal_tax_frac", (getter)Outputs_get_cf_federal_tax_frac,(setter)0,
	"Federal income tax rate [frac], array.",
 	NULL},
{"cf_fuelcell_replacement_cost", (getter)Outputs_get_cf_fuelcell_replacement_cost,(setter)0,
	"Fuel cell replacement cost [$], array.",
 	NULL},
{"cf_fuelcell_replacement_cost_schedule", (getter)Outputs_get_cf_fuelcell_replacement_cost_schedule,(setter)0,
	"Fuel cell replacement cost schedule [$/kW], array.",
 	NULL},
{"cf_insurance_expense", (getter)Outputs_get_cf_insurance_expense,(setter)0,
	"Insurance expense [$], array.",
 	NULL},
{"cf_length", (getter)Outputs_get_cf_length,(setter)0,
	"Number of periods in cash flow, number.",
 	NULL},
{"cf_net_salvage_value", (getter)Outputs_get_cf_net_salvage_value,(setter)0,
	"Net salvage value [$], array.",
 	NULL},
{"cf_nte", (getter)Outputs_get_cf_nte,(setter)0,
	"Not to exceed (NTE) [cents/kWh], array.",
 	NULL},
{"cf_om_capacity1_expense", (getter)Outputs_get_cf_om_capacity1_expense,(setter)0,
	"Battery capacity-based expense [$], array.",
 	NULL},
{"cf_om_capacity2_expense", (getter)Outputs_get_cf_om_capacity2_expense,(setter)0,
	"Fuel cell capacity-based expense [$], array.",
 	NULL},
{"cf_om_capacity_expense", (getter)Outputs_get_cf_om_capacity_expense,(setter)0,
	"O&M capacity-based expense [$], array.",
 	NULL},
{"cf_om_fixed1_expense", (getter)Outputs_get_cf_om_fixed1_expense,(setter)0,
	"Battery fixed expense [$], array.",
 	NULL},
{"cf_om_fixed2_expense", (getter)Outputs_get_cf_om_fixed2_expense,(setter)0,
	"Fuel cell fixed expense [$], array.",
 	NULL},
{"cf_om_fixed_expense", (getter)Outputs_get_cf_om_fixed_expense,(setter)0,
	"O&M fixed expense [$], array.",
 	NULL},
{"cf_om_fuel_expense", (getter)Outputs_get_cf_om_fuel_expense,(setter)0,
	"O&M fuel expense [$], array.",
 	NULL},
{"cf_om_opt_fuel_1_expense", (getter)Outputs_get_cf_om_opt_fuel_1_expense,(setter)0,
	"O&M biomass feedstock expense [$], array.",
 	NULL},
{"cf_om_opt_fuel_2_expense", (getter)Outputs_get_cf_om_opt_fuel_2_expense,(setter)0,
	"O&M coal feedstock expense [$], array.",
 	NULL},
{"cf_om_production1_expense", (getter)Outputs_get_cf_om_production1_expense,(setter)0,
	"Battery production-based expense [$], array.",
 	NULL},
{"cf_om_production2_expense", (getter)Outputs_get_cf_om_production2_expense,(setter)0,
	"Fuel cell production-based expense [$], array.",
 	NULL},
{"cf_om_production_expense", (getter)Outputs_get_cf_om_production_expense,(setter)0,
	"O&M production-based expense [$], array.",
 	NULL},
{"cf_operating_expenses", (getter)Outputs_get_cf_operating_expenses,(setter)0,
	"Total operating expense [$], array.",
 	NULL},
{"cf_payback_with_expenses", (getter)Outputs_get_cf_payback_with_expenses,(setter)0,
	"Simple payback with expenses [$], array.",
 	NULL},
{"cf_payback_without_expenses", (getter)Outputs_get_cf_payback_without_expenses,(setter)0,
	"Simple payback without expenses [$], array.",
 	NULL},
{"cf_pbi_total", (getter)Outputs_get_cf_pbi_total,(setter)0,
	"Total PBI income [$], array.",
 	NULL},
{"cf_pbi_total_fed", (getter)Outputs_get_cf_pbi_total_fed,(setter)0,
	"Federal PBI income [$], array.",
 	NULL},
{"cf_pbi_total_oth", (getter)Outputs_get_cf_pbi_total_oth,(setter)0,
	"Other PBI income [$], array.",
 	NULL},
{"cf_pbi_total_sta", (getter)Outputs_get_cf_pbi_total_sta,(setter)0,
	"State PBI income [$], array.",
 	NULL},
{"cf_pbi_total_uti", (getter)Outputs_get_cf_pbi_total_uti,(setter)0,
	"Utility PBI income [$], array.",
 	NULL},
{"cf_property_tax_assessed_value", (getter)Outputs_get_cf_property_tax_assessed_value,(setter)0,
	"Property tax net assessed value [$], array.",
 	NULL},
{"cf_property_tax_expense", (getter)Outputs_get_cf_property_tax_expense,(setter)0,
	"Property tax expense [$], array.",
 	NULL},
{"cf_ptc_fed", (getter)Outputs_get_cf_ptc_fed,(setter)0,
	"Federal PTC [$], array.",
 	NULL},
{"cf_ptc_sta", (getter)Outputs_get_cf_ptc_sta,(setter)0,
	"State PTC [$], array.",
 	NULL},
{"cf_ptc_total", (getter)Outputs_get_cf_ptc_total,(setter)0,
	"Total PTC [$], array.",
 	NULL},
{"cf_sta_and_fed_tax_savings", (getter)Outputs_get_cf_sta_and_fed_tax_savings,(setter)0,
	"Total tax savings (federal and state) [$], array.",
 	NULL},
{"cf_sta_depr_sched", (getter)Outputs_get_cf_sta_depr_sched,(setter)0,
	"State depreciation schedule [%], array.",
 	NULL},
{"cf_sta_depreciation", (getter)Outputs_get_cf_sta_depreciation,(setter)0,
	"State depreciation [$], array.",
 	NULL},
{"cf_sta_incentive_income_less_deductions", (getter)Outputs_get_cf_sta_incentive_income_less_deductions,(setter)0,
	"State incentive income less deductions [$], array.",
 	NULL},
{"cf_sta_tax_savings", (getter)Outputs_get_cf_sta_tax_savings,(setter)0,
	"State tax savings [$], array.",
 	NULL},
{"cf_sta_taxable_income_less_deductions", (getter)Outputs_get_cf_sta_taxable_income_less_deductions,(setter)0,
	"State taxable income less deductions [$], array.",
 	NULL},
{"cf_state_tax_frac", (getter)Outputs_get_cf_state_tax_frac,(setter)0,
	"State income tax rate [frac], array.",
 	NULL},
{"cf_thermal_value", (getter)Outputs_get_cf_thermal_value,(setter)0,
	"Value of thermal savings [$], array.",
 	NULL},
{"cf_value_added", (getter)Outputs_get_cf_value_added,(setter)0,
	"Real estate value added [$], array.",
 	NULL},
{"discounted_payback", (getter)Outputs_get_discounted_payback,(setter)0,
	"Discounted payback period [years], number.",
 	NULL},
{"effective_tax_rate", (getter)Outputs_get_effective_tax_rate,(setter)0,
	"Effective tax rate [%], number.",
 	NULL},
{"first_cost", (getter)Outputs_get_first_cost,(setter)0,
	"Equity [$], number.",
 	NULL},
{"ibi_total", (getter)Outputs_get_ibi_total,(setter)0,
	"Total IBI income [$], number.",
 	NULL},
{"ibi_total_fed", (getter)Outputs_get_ibi_total_fed,(setter)0,
	"Federal IBI income [$], number.",
 	NULL},
{"ibi_total_oth", (getter)Outputs_get_ibi_total_oth,(setter)0,
	"Other IBI income [$], number.",
 	NULL},
{"ibi_total_sta", (getter)Outputs_get_ibi_total_sta,(setter)0,
	"State IBI income [$], number.",
 	NULL},
{"ibi_total_uti", (getter)Outputs_get_ibi_total_uti,(setter)0,
	"Utility IBI income [$], number.",
 	NULL},
{"itc_total", (getter)Outputs_get_itc_total,(setter)0,
	"Total ITC [$], number.",
 	NULL},
{"itc_total_fed", (getter)Outputs_get_itc_total_fed,(setter)0,
	"Federal ITC [$], number.",
 	NULL},
{"itc_total_sta", (getter)Outputs_get_itc_total_sta,(setter)0,
	"State ITC [$], number.",
 	NULL},
{"lcoe_nom", (getter)Outputs_get_lcoe_nom,(setter)0,
	"Nominal LCOE [cents/kWh], number.",
 	NULL},
{"lcoe_real", (getter)Outputs_get_lcoe_real,(setter)0,
	"Real LCOE [cents/kWh], number.",
 	NULL},
{"lcoptc_fed_nom", (getter)Outputs_get_lcoptc_fed_nom,(setter)0,
	"Levelized federal PTC (nominal) [cents/kWh], number.",
 	NULL},
{"lcoptc_fed_real", (getter)Outputs_get_lcoptc_fed_real,(setter)0,
	"Levelized federal PTC (real) [cents/kWh], number.",
 	NULL},
{"lcoptc_sta_nom", (getter)Outputs_get_lcoptc_sta_nom,(setter)0,
	"Levelized state PTC (nominal) [cents/kWh], number.",
 	NULL},
{"lcoptc_sta_real", (getter)Outputs_get_lcoptc_sta_real,(setter)0,
	"Levelized state PTC (real) [cents/kWh], number.",
 	NULL},
{"lnte_nom", (getter)Outputs_get_lnte_nom,(setter)0,
	"Nominal LNTE [cents/kWh], number.",
 	NULL},
{"lnte_real", (getter)Outputs_get_lnte_real,(setter)0,
	"Real LNTE [cents/kWh], number.",
 	NULL},
{"loan_amount", (getter)Outputs_get_loan_amount,(setter)0,
	"Debt [$], number.",
 	NULL},
{"npv", (getter)Outputs_get_npv,(setter)0,
	"Net present value [$], number.",
 	NULL},
{"payback", (getter)Outputs_get_payback,(setter)0,
	"Payback period [years], number.",
 	NULL},
{"present_value_fuel", (getter)Outputs_get_present_value_fuel,(setter)0,
	"Present value of fuel expenses [$], number.",
 	NULL},
{"present_value_insandproptax", (getter)Outputs_get_present_value_insandproptax,(setter)0,
	"Present value of insurance and property tax [$], number.",
 	NULL},
{"present_value_oandm", (getter)Outputs_get_present_value_oandm,(setter)0,
	"Present value of O&M expenses [$], number.",
 	NULL},
{"present_value_oandm_nonfuel", (getter)Outputs_get_present_value_oandm_nonfuel,(setter)0,
	"Present value of non-fuel O&M expenses [$], number.",
 	NULL},
{"total_cost", (getter)Outputs_get_total_cost,(setter)0,
	"Total installed cost [$], number.",
 	NULL},
{"wacc", (getter)Outputs_get_wacc,(setter)0,
	"Weighted average cost of capital (WACC), number.",
 	NULL},
{"year1_nte", (getter)Outputs_get_year1_nte,(setter)0,
	"Year 1 NTE [cents/kWh], number.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CashloanModel.Outputs",             /*tp_name*/
		sizeof(OutputsObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Outputs_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Outputs_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};

/*
 * CashloanModel
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_Cashloan   data_ptr;
} CashloanModelObject;

static PyTypeObject CashloanModel_Type;

#define CashloanModelObject_Check(v)      (Py_TYPE(v) == &CashloanModel_Type)

static CashloanModelObject *
newCashloanModelObject(void* data_ptr)
{
	CashloanModelObject *self;
	self = PyObject_New(CashloanModelObject, &CashloanModel_Type);

	PySAM_TECH_ATTR("CashloanModel", SAM_Cashloan_construct)

	PyObject* FinancialParameters_obj = FinancialParameters_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FinancialParameters", FinancialParameters_obj);
	Py_DECREF(FinancialParameters_obj);

	PyObject* SystemCosts_obj = SystemCosts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemCosts", SystemCosts_obj);
	Py_DECREF(SystemCosts_obj);

	PyObject* Depreciation_obj = Depreciation_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Depreciation", Depreciation_obj);
	Py_DECREF(Depreciation_obj);

	PyObject* TaxCreditIncentives_obj = TaxCreditIncentives_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TaxCreditIncentives", TaxCreditIncentives_obj);
	Py_DECREF(TaxCreditIncentives_obj);

	PyObject* PaymentIncentives_obj = PaymentIncentives_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "PaymentIncentives", PaymentIncentives_obj);
	Py_DECREF(PaymentIncentives_obj);

	PyObject* Battery_obj = Battery_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Battery", Battery_obj);
	Py_DECREF(Battery_obj);

	PyObject* FuelCell_obj = FuelCell_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FuelCell", FuelCell_obj);
	Py_DECREF(FuelCell_obj);

	PyObject* Cashloan_obj = Cashloan_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Cashloan", Cashloan_obj);
	Py_DECREF(Cashloan_obj);

	PyObject* SystemOutput_obj = SystemOutput_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemOutput", SystemOutput_obj);
	Py_DECREF(SystemOutput_obj);

	PyObject* Lifetime_obj = Lifetime_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Lifetime", Lifetime_obj);
	Py_DECREF(Lifetime_obj);

	PyObject* ThirdPartyOwnership_obj = ThirdPartyOwnership_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ThirdPartyOwnership", ThirdPartyOwnership_obj);
	Py_DECREF(ThirdPartyOwnership_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);


	return self;
}

/* CashloanModel methods */

static void
CashloanModel_dealloc(CashloanModelObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_Cashloan_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
CashloanModel_execute(CashloanModelObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Cashloan_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
CashloanModel_assign(CashloanModelObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "CashloanModel"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
CashloanModel_export(CashloanModelObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyMethodDef CashloanModel_methods[] = {
		{"execute",            (PyCFunction)CashloanModel_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)CashloanModel_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs")},
		{"export",            (PyCFunction)CashloanModel_export,  METH_VARARGS,
				PyDoc_STR("assign() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
CashloanModel_getattro(CashloanModelObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
CashloanModel_setattr(CashloanModelObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject CashloanModel_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CashloanModel",            /*tp_name*/
		sizeof(CashloanModelObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)CashloanModel_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)CashloanModel_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)CashloanModel_getattro, /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		"see html for help",        /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		CashloanModel_methods,      /*tp_methods*/
		0,                          /*tp_members*/
		0,       /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,                          /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};

/* --------------------------------------------------------------------- */


/* Function of no arguments returning new CashloanModel object */

static PyObject *
CashloanModel_new(PyObject *self, PyObject *args)
{
	CashloanModelObject *rv;
	rv = newCashloanModelObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
CashloanModel_wrap(PyObject *self, PyObject *args)
{
	CashloanModelObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newCashloanModelObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
CashloanModel_default(PyObject *self, PyObject *args)
{
	CashloanModelObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newCashloanModelObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Cashloan", def);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef CashloanModelModule_methods[] = {
		{"new",             CashloanModel_new,         METH_VARARGS,
				PyDoc_STR("new() -> new CashloanModel object")},
		{"default",             CashloanModel_default,         METH_VARARGS,
				PyDoc_STR("default(financial) -> new CashloanModel object with financial model-specific default attributes\n"
				"Options: TcsMSLF, TcslinearFresnel, Swh, Tcsdish, GenericSystem, Pvsamv1, Fuelcell, TcsgenericSolar, TcstroughPhysical, Pvwattsv5, TcstroughEmpirical, Biomass, Windpower")},
		{"wrap",             CashloanModel_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> new CashloanModel object around existing PySSC data, taking over memory ownership")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Financial model for residential and commercial behind-the-meter projects");


static int
CashloanModelModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error(m) < 0) goto fail;

	CashloanModel_Type.tp_dict = PyDict_New();
	if (!CashloanModel_Type.tp_dict) { goto fail; }

	/// Add the FinancialParameters type object to CashloanModel_Type
	if (PyType_Ready(&FinancialParameters_Type) < 0) { goto fail; }
	PyDict_SetItemString(CashloanModel_Type.tp_dict,
				"FinancialParameters",
				(PyObject*)&FinancialParameters_Type);
	Py_DECREF(&FinancialParameters_Type);

	/// Add the SystemCosts type object to CashloanModel_Type
	if (PyType_Ready(&SystemCosts_Type) < 0) { goto fail; }
	PyDict_SetItemString(CashloanModel_Type.tp_dict,
				"SystemCosts",
				(PyObject*)&SystemCosts_Type);
	Py_DECREF(&SystemCosts_Type);

	/// Add the Depreciation type object to CashloanModel_Type
	if (PyType_Ready(&Depreciation_Type) < 0) { goto fail; }
	PyDict_SetItemString(CashloanModel_Type.tp_dict,
				"Depreciation",
				(PyObject*)&Depreciation_Type);
	Py_DECREF(&Depreciation_Type);

	/// Add the TaxCreditIncentives type object to CashloanModel_Type
	if (PyType_Ready(&TaxCreditIncentives_Type) < 0) { goto fail; }
	PyDict_SetItemString(CashloanModel_Type.tp_dict,
				"TaxCreditIncentives",
				(PyObject*)&TaxCreditIncentives_Type);
	Py_DECREF(&TaxCreditIncentives_Type);

	/// Add the PaymentIncentives type object to CashloanModel_Type
	if (PyType_Ready(&PaymentIncentives_Type) < 0) { goto fail; }
	PyDict_SetItemString(CashloanModel_Type.tp_dict,
				"PaymentIncentives",
				(PyObject*)&PaymentIncentives_Type);
	Py_DECREF(&PaymentIncentives_Type);

	/// Add the Battery type object to CashloanModel_Type
	if (PyType_Ready(&Battery_Type) < 0) { goto fail; }
	PyDict_SetItemString(CashloanModel_Type.tp_dict,
				"Battery",
				(PyObject*)&Battery_Type);
	Py_DECREF(&Battery_Type);

	/// Add the FuelCell type object to CashloanModel_Type
	if (PyType_Ready(&FuelCell_Type) < 0) { goto fail; }
	PyDict_SetItemString(CashloanModel_Type.tp_dict,
				"FuelCell",
				(PyObject*)&FuelCell_Type);
	Py_DECREF(&FuelCell_Type);

	/// Add the Cashloan type object to CashloanModel_Type
	if (PyType_Ready(&Cashloan_Type) < 0) { goto fail; }
	PyDict_SetItemString(CashloanModel_Type.tp_dict,
				"Cashloan",
				(PyObject*)&Cashloan_Type);
	Py_DECREF(&Cashloan_Type);

	/// Add the SystemOutput type object to CashloanModel_Type
	if (PyType_Ready(&SystemOutput_Type) < 0) { goto fail; }
	PyDict_SetItemString(CashloanModel_Type.tp_dict,
				"SystemOutput",
				(PyObject*)&SystemOutput_Type);
	Py_DECREF(&SystemOutput_Type);

	/// Add the Lifetime type object to CashloanModel_Type
	if (PyType_Ready(&Lifetime_Type) < 0) { goto fail; }
	PyDict_SetItemString(CashloanModel_Type.tp_dict,
				"Lifetime",
				(PyObject*)&Lifetime_Type);
	Py_DECREF(&Lifetime_Type);

	/// Add the ThirdPartyOwnership type object to CashloanModel_Type
	if (PyType_Ready(&ThirdPartyOwnership_Type) < 0) { goto fail; }
	PyDict_SetItemString(CashloanModel_Type.tp_dict,
				"ThirdPartyOwnership",
				(PyObject*)&ThirdPartyOwnership_Type);
	Py_DECREF(&ThirdPartyOwnership_Type);

	/// Add the Outputs type object to CashloanModel_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(CashloanModel_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the CashloanModel type object to the module
	if (PyType_Ready(&CashloanModel_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"CashloanModel",
				(PyObject*)&CashloanModel_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot CashloanModelModule_slots[] = {
		{Py_mod_exec, CashloanModelModule_exec},
		{0, NULL},
};

static struct PyModuleDef CashloanModelModule = {
		PyModuleDef_HEAD_INIT,
		"CashloanModel",
		module_doc,
		0,
		CashloanModelModule_methods,
		CashloanModelModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_CashloanModel(void)
{
	return PyModuleDef_Init(&CashloanModelModule);
}