#include <Python.h>

#include <SAM_Saleleaseback.h>
#include <SAM_api.h>

#include "PySAM_utils.h"



	/*
	 * FinancialParameters Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Saleleaseback   data_ptr;
} FinancialParametersObject;

static PyTypeObject FinancialParameters_Type;

static PyObject *
FinancialParameters_new(SAM_Saleleaseback data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Saleleaseback", "FinancialParameters")){
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
	return PySAM_float_getter(SAM_Saleleaseback_FinancialParameters_analysis_period_fget, self->data_ptr);
}

static int
FinancialParameters_set_analysis_period(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_FinancialParameters_analysis_period_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_federal_tax_rate(FinancialParametersObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_FinancialParameters_federal_tax_rate_aget, self->data_ptr);
}

static int
FinancialParameters_set_federal_tax_rate(FinancialParametersObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_FinancialParameters_federal_tax_rate_aset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_inflation_rate(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_FinancialParameters_inflation_rate_fget, self->data_ptr);
}

static int
FinancialParameters_set_inflation_rate(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_FinancialParameters_inflation_rate_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_insurance_rate(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_FinancialParameters_insurance_rate_fget, self->data_ptr);
}

static int
FinancialParameters_set_insurance_rate(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_FinancialParameters_insurance_rate_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_prop_tax_assessed_decline(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_FinancialParameters_prop_tax_assessed_decline_fget, self->data_ptr);
}

static int
FinancialParameters_set_prop_tax_assessed_decline(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_FinancialParameters_prop_tax_assessed_decline_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_prop_tax_cost_assessed_percent(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_FinancialParameters_prop_tax_cost_assessed_percent_fget, self->data_ptr);
}

static int
FinancialParameters_set_prop_tax_cost_assessed_percent(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_FinancialParameters_prop_tax_cost_assessed_percent_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_property_tax_rate(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_FinancialParameters_property_tax_rate_fget, self->data_ptr);
}

static int
FinancialParameters_set_property_tax_rate(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_FinancialParameters_property_tax_rate_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_real_discount_rate(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_FinancialParameters_real_discount_rate_fget, self->data_ptr);
}

static int
FinancialParameters_set_real_discount_rate(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_FinancialParameters_real_discount_rate_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_state_tax_rate(FinancialParametersObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_FinancialParameters_state_tax_rate_aget, self->data_ptr);
}

static int
FinancialParameters_set_state_tax_rate(FinancialParametersObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_FinancialParameters_state_tax_rate_aset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_system_capacity(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_FinancialParameters_system_capacity_fget, self->data_ptr);
}

static int
FinancialParameters_set_system_capacity(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_FinancialParameters_system_capacity_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_system_heat_rate(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_FinancialParameters_system_heat_rate_fget, self->data_ptr);
}

static int
FinancialParameters_set_system_heat_rate(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_FinancialParameters_system_heat_rate_fset, self->data_ptr);
}

static PyGetSetDef FinancialParameters_getset[] = {
{"analysis_period", (getter)FinancialParameters_get_analysis_period,(setter)FinancialParameters_set_analysis_period,
	"Analyis period [years], number.\n Constraints: INTEGER,MIN=0,MAX=50; Required if ?=30.",
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
		"Saleleaseback.FinancialParameters",             /*tp_name*/
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
	SAM_Saleleaseback   data_ptr;
} SystemCostsObject;

static PyTypeObject SystemCosts_Type;

static PyObject *
SystemCosts_new(SAM_Saleleaseback data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Saleleaseback", "SystemCosts")){
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
	return PySAM_float_getter(SAM_Saleleaseback_SystemCosts_add_om_num_types_fget, self->data_ptr);
}

static int
SystemCosts_set_add_om_num_types(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_SystemCosts_add_om_num_types_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_annual_fuel_usage(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_SystemCosts_annual_fuel_usage_fget, self->data_ptr);
}

static int
SystemCosts_set_annual_fuel_usage(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_SystemCosts_annual_fuel_usage_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_capacity(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_SystemCosts_om_capacity_aget, self->data_ptr);
}

static int
SystemCosts_set_om_capacity(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_SystemCosts_om_capacity_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_capacity1(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_SystemCosts_om_capacity1_aget, self->data_ptr);
}

static int
SystemCosts_set_om_capacity1(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_SystemCosts_om_capacity1_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_capacity1_nameplate(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_SystemCosts_om_capacity1_nameplate_fget, self->data_ptr);
}

static int
SystemCosts_set_om_capacity1_nameplate(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_SystemCosts_om_capacity1_nameplate_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_capacity2(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_SystemCosts_om_capacity2_aget, self->data_ptr);
}

static int
SystemCosts_set_om_capacity2(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_SystemCosts_om_capacity2_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_capacity2_nameplate(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_SystemCosts_om_capacity2_nameplate_fget, self->data_ptr);
}

static int
SystemCosts_set_om_capacity2_nameplate(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_SystemCosts_om_capacity2_nameplate_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_capacity_escal(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_SystemCosts_om_capacity_escal_fget, self->data_ptr);
}

static int
SystemCosts_set_om_capacity_escal(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_SystemCosts_om_capacity_escal_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fixed(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_SystemCosts_om_fixed_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fixed(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_SystemCosts_om_fixed_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fixed1(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_SystemCosts_om_fixed1_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fixed1(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_SystemCosts_om_fixed1_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fixed2(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_SystemCosts_om_fixed2_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fixed2(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_SystemCosts_om_fixed2_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fixed_escal(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_SystemCosts_om_fixed_escal_fget, self->data_ptr);
}

static int
SystemCosts_set_om_fixed_escal(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_SystemCosts_om_fixed_escal_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuel_cost(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_SystemCosts_om_fuel_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_fuel_cost(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_SystemCosts_om_fuel_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_fuel_cost_escal(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_SystemCosts_om_fuel_cost_escal_fget, self->data_ptr);
}

static int
SystemCosts_set_om_fuel_cost_escal(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_SystemCosts_om_fuel_cost_escal_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_1_cost(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_SystemCosts_om_opt_fuel_1_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_1_cost(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_SystemCosts_om_opt_fuel_1_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_1_cost_escal(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_SystemCosts_om_opt_fuel_1_cost_escal_fget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_1_cost_escal(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_SystemCosts_om_opt_fuel_1_cost_escal_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_1_usage(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_SystemCosts_om_opt_fuel_1_usage_fget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_1_usage(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_SystemCosts_om_opt_fuel_1_usage_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_2_cost(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_SystemCosts_om_opt_fuel_2_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_2_cost(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_SystemCosts_om_opt_fuel_2_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_2_cost_escal(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_SystemCosts_om_opt_fuel_2_cost_escal_fget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_2_cost_escal(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_SystemCosts_om_opt_fuel_2_cost_escal_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_opt_fuel_2_usage(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_SystemCosts_om_opt_fuel_2_usage_fget, self->data_ptr);
}

static int
SystemCosts_set_om_opt_fuel_2_usage(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_SystemCosts_om_opt_fuel_2_usage_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_SystemCosts_om_production_aget, self->data_ptr);
}

static int
SystemCosts_set_om_production(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_SystemCosts_om_production_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production1(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_SystemCosts_om_production1_aget, self->data_ptr);
}

static int
SystemCosts_set_om_production1(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_SystemCosts_om_production1_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production1_values(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_SystemCosts_om_production1_values_aget, self->data_ptr);
}

static int
SystemCosts_set_om_production1_values(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_SystemCosts_om_production1_values_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production2(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_SystemCosts_om_production2_aget, self->data_ptr);
}

static int
SystemCosts_set_om_production2(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_SystemCosts_om_production2_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production2_values(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_SystemCosts_om_production2_values_aget, self->data_ptr);
}

static int
SystemCosts_set_om_production2_values(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_SystemCosts_om_production2_values_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production_escal(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_SystemCosts_om_production_escal_fget, self->data_ptr);
}

static int
SystemCosts_set_om_production_escal(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_SystemCosts_om_production_escal_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_replacement_cost1(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_SystemCosts_om_replacement_cost1_aget, self->data_ptr);
}

static int
SystemCosts_set_om_replacement_cost1(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_SystemCosts_om_replacement_cost1_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_replacement_cost2(SystemCostsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_SystemCosts_om_replacement_cost2_aget, self->data_ptr);
}

static int
SystemCosts_set_om_replacement_cost2(SystemCostsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_SystemCosts_om_replacement_cost2_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_replacement_cost_escal(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_SystemCosts_om_replacement_cost_escal_fget, self->data_ptr);
}

static int
SystemCosts_set_om_replacement_cost_escal(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_SystemCosts_om_replacement_cost_escal_fset, self->data_ptr);
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
		"Saleleaseback.SystemCosts",             /*tp_name*/
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
	 * TaxCreditIncentives Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Saleleaseback   data_ptr;
} TaxCreditIncentivesObject;

static PyTypeObject TaxCreditIncentives_Type;

static PyObject *
TaxCreditIncentives_new(SAM_Saleleaseback data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Saleleaseback", "TaxCreditIncentives")){
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
	return PySAM_float_getter(SAM_Saleleaseback_TaxCreditIncentives_itc_fed_amount_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_amount(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TaxCreditIncentives_itc_fed_amount_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_amount_deprbas_fed(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TaxCreditIncentives_itc_fed_amount_deprbas_fed_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_amount_deprbas_fed(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TaxCreditIncentives_itc_fed_amount_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_amount_deprbas_sta(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TaxCreditIncentives_itc_fed_amount_deprbas_sta_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_amount_deprbas_sta(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TaxCreditIncentives_itc_fed_amount_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TaxCreditIncentives_itc_fed_percent_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TaxCreditIncentives_itc_fed_percent_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent_deprbas_fed(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TaxCreditIncentives_itc_fed_percent_deprbas_fed_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent_deprbas_fed(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TaxCreditIncentives_itc_fed_percent_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent_deprbas_sta(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TaxCreditIncentives_itc_fed_percent_deprbas_sta_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent_deprbas_sta(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TaxCreditIncentives_itc_fed_percent_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_fed_percent_maxvalue(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TaxCreditIncentives_itc_fed_percent_maxvalue_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_fed_percent_maxvalue(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TaxCreditIncentives_itc_fed_percent_maxvalue_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_amount(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TaxCreditIncentives_itc_sta_amount_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_amount(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TaxCreditIncentives_itc_sta_amount_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_amount_deprbas_fed(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TaxCreditIncentives_itc_sta_amount_deprbas_fed_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_amount_deprbas_fed(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TaxCreditIncentives_itc_sta_amount_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_amount_deprbas_sta(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TaxCreditIncentives_itc_sta_amount_deprbas_sta_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_amount_deprbas_sta(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TaxCreditIncentives_itc_sta_amount_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TaxCreditIncentives_itc_sta_percent_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TaxCreditIncentives_itc_sta_percent_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent_deprbas_fed(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TaxCreditIncentives_itc_sta_percent_deprbas_fed_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent_deprbas_fed(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TaxCreditIncentives_itc_sta_percent_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent_deprbas_sta(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TaxCreditIncentives_itc_sta_percent_deprbas_sta_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent_deprbas_sta(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TaxCreditIncentives_itc_sta_percent_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_itc_sta_percent_maxvalue(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TaxCreditIncentives_itc_sta_percent_maxvalue_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_itc_sta_percent_maxvalue(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TaxCreditIncentives_itc_sta_percent_maxvalue_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_fed_amount(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_TaxCreditIncentives_ptc_fed_amount_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_fed_amount(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_TaxCreditIncentives_ptc_fed_amount_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_fed_escal(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TaxCreditIncentives_ptc_fed_escal_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_fed_escal(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TaxCreditIncentives_ptc_fed_escal_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_fed_term(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TaxCreditIncentives_ptc_fed_term_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_fed_term(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TaxCreditIncentives_ptc_fed_term_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_sta_amount(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_TaxCreditIncentives_ptc_sta_amount_aget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_sta_amount(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_TaxCreditIncentives_ptc_sta_amount_aset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_sta_escal(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TaxCreditIncentives_ptc_sta_escal_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_sta_escal(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TaxCreditIncentives_ptc_sta_escal_fset, self->data_ptr);
}

static PyObject *
TaxCreditIncentives_get_ptc_sta_term(TaxCreditIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TaxCreditIncentives_ptc_sta_term_fget, self->data_ptr);
}

static int
TaxCreditIncentives_set_ptc_sta_term(TaxCreditIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TaxCreditIncentives_ptc_sta_term_fset, self->data_ptr);
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
		"Saleleaseback.TaxCreditIncentives",             /*tp_name*/
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
	SAM_Saleleaseback   data_ptr;
} PaymentIncentivesObject;

static PyTypeObject PaymentIncentives_Type;

static PyObject *
PaymentIncentives_new(SAM_Saleleaseback data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Saleleaseback", "PaymentIncentives")){
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
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_fed_amount_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_fed_amount_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_fed_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_fed_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_fed_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_fed_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_maxvalue(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_fed_maxvalue_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_maxvalue(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_fed_maxvalue_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_fed_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_fed_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_fed_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_fed_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_fed_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_fed_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_oth_amount_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_oth_amount_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_oth_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_oth_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_oth_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_oth_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_maxvalue(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_oth_maxvalue_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_maxvalue(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_oth_maxvalue_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_oth_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_oth_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_oth_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_oth_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_oth_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_oth_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_sta_amount_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_sta_amount_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_sta_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_sta_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_sta_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_sta_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_maxvalue(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_sta_maxvalue_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_maxvalue(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_sta_maxvalue_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_sta_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_sta_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_sta_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_sta_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_sta_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_sta_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_uti_amount_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_uti_amount_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_uti_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_uti_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_uti_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_uti_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_maxvalue(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_uti_maxvalue_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_maxvalue(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_uti_maxvalue_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_uti_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_uti_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_cbi_uti_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_cbi_uti_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_cbi_uti_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_cbi_uti_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_fed_amount_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_fed_amount_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_fed_amount_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_fed_amount_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_fed_amount_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_fed_amount_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_fed_amount_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_fed_amount_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_amount_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_fed_amount_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_amount_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_fed_amount_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_fed_percent_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_fed_percent_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_fed_percent_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_fed_percent_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_fed_percent_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_fed_percent_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_maxvalue(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_fed_percent_maxvalue_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_maxvalue(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_fed_percent_maxvalue_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_fed_percent_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_fed_percent_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_fed_percent_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_fed_percent_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_fed_percent_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_fed_percent_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_oth_amount_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_oth_amount_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_oth_amount_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_oth_amount_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_oth_amount_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_oth_amount_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_oth_amount_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_oth_amount_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_amount_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_oth_amount_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_amount_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_oth_amount_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_oth_percent_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_oth_percent_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_oth_percent_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_oth_percent_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_oth_percent_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_oth_percent_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_maxvalue(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_oth_percent_maxvalue_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_maxvalue(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_oth_percent_maxvalue_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_oth_percent_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_oth_percent_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_oth_percent_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_oth_percent_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_oth_percent_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_oth_percent_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_sta_amount_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_sta_amount_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_sta_amount_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_sta_amount_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_sta_amount_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_sta_amount_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_sta_amount_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_sta_amount_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_amount_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_sta_amount_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_amount_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_sta_amount_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_sta_percent_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_sta_percent_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_sta_percent_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_sta_percent_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_sta_percent_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_sta_percent_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_maxvalue(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_sta_percent_maxvalue_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_maxvalue(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_sta_percent_maxvalue_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_sta_percent_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_sta_percent_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_sta_percent_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_sta_percent_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_sta_percent_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_sta_percent_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_uti_amount_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_uti_amount_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_uti_amount_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_uti_amount_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_uti_amount_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_uti_amount_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_uti_amount_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_uti_amount_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_amount_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_uti_amount_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_amount_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_uti_amount_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_uti_percent_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_uti_percent_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_deprbas_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_uti_percent_deprbas_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_deprbas_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_uti_percent_deprbas_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_deprbas_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_uti_percent_deprbas_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_deprbas_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_uti_percent_deprbas_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_maxvalue(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_uti_percent_maxvalue_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_maxvalue(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_uti_percent_maxvalue_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_uti_percent_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_uti_percent_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_ibi_uti_percent_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_ibi_uti_percent_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_ibi_uti_percent_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_ibi_uti_percent_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_PaymentIncentives_pbi_fed_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_fed_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_escal(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_pbi_fed_escal_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_escal(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_fed_escal_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_pbi_fed_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_fed_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_pbi_fed_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_fed_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_fed_term(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_pbi_fed_term_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_fed_term(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_fed_term_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_PaymentIncentives_pbi_oth_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_oth_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_escal(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_pbi_oth_escal_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_escal(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_oth_escal_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_pbi_oth_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_oth_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_pbi_oth_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_oth_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_oth_term(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_pbi_oth_term_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_oth_term(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_oth_term_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_PaymentIncentives_pbi_sta_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_sta_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_escal(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_pbi_sta_escal_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_escal(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_sta_escal_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_pbi_sta_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_sta_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_pbi_sta_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_sta_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_sta_term(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_pbi_sta_term_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_sta_term(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_sta_term_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_amount(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_PaymentIncentives_pbi_uti_amount_aget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_amount(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_uti_amount_aset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_escal(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_pbi_uti_escal_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_escal(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_uti_escal_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_tax_fed(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_pbi_uti_tax_fed_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_tax_fed(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_uti_tax_fed_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_tax_sta(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_pbi_uti_tax_sta_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_tax_sta(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_uti_tax_sta_fset, self->data_ptr);
}

static PyObject *
PaymentIncentives_get_pbi_uti_term(PaymentIncentivesObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_PaymentIncentives_pbi_uti_term_fget, self->data_ptr);
}

static int
PaymentIncentives_set_pbi_uti_term(PaymentIncentivesObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_PaymentIncentives_pbi_uti_term_fset, self->data_ptr);
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
		"Saleleaseback.PaymentIncentives",             /*tp_name*/
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
	 * Common Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Saleleaseback   data_ptr;
} CommonObject;

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_Saleleaseback data_ptr)
{
	PyObject* new_obj = Common_Type.tp_alloc(&Common_Type,0);

	CommonObject* Common_obj = (CommonObject*)new_obj;

	Common_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Common methods */

static PyObject *
Common_assign(CommonObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Saleleaseback", "Common")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Common_export(CommonObject *self, PyObject *args)
{
	PyTypeObject* tp = &Common_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Common_methods[] = {
		{"assign",            (PyCFunction)Common_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Common_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Common_get_gen(CommonObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Common_gen_aget, self->data_ptr);
}

static int
Common_set_gen(CommonObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_Common_gen_aset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"gen", (getter)Common_get_gen,(setter)Common_set_gen,
	"Power generated by renewable resource [kW], array.\n Required.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Saleleaseback.Common",             /*tp_name*/
		sizeof(CommonObject),          /*tp_basicsize*/
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
		Common_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Common_getset,          /*tp_getset*/
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
	 * DHF Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Saleleaseback   data_ptr;
} DHFObject;

static PyTypeObject DHF_Type;

static PyObject *
DHF_new(SAM_Saleleaseback data_ptr)
{
	PyObject* new_obj = DHF_Type.tp_alloc(&DHF_Type,0);

	DHFObject* DHF_obj = (DHFObject*)new_obj;

	DHF_obj->data_ptr = data_ptr;

	return new_obj;
}

/* DHF methods */

static PyObject *
DHF_assign(DHFObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Saleleaseback", "DHF")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
DHF_export(DHFObject *self, PyObject *args)
{
	PyTypeObject* tp = &DHF_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef DHF_methods[] = {
		{"assign",            (PyCFunction)DHF_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)DHF_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
DHF_get_construction_financing_cost(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_construction_financing_cost_fget, self->data_ptr);
}

static int
DHF_set_construction_financing_cost(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_construction_financing_cost_fset, self->data_ptr);
}

static PyObject *
DHF_get_cost_dev_fee_percent(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_cost_dev_fee_percent_fget, self->data_ptr);
}

static int
DHF_set_cost_dev_fee_percent(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_cost_dev_fee_percent_fset, self->data_ptr);
}

static PyObject *
DHF_get_cost_equity_closing(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_cost_equity_closing_fget, self->data_ptr);
}

static int
DHF_set_cost_equity_closing(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_cost_equity_closing_fset, self->data_ptr);
}

static PyObject *
DHF_get_cost_other_financing(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_cost_other_financing_fget, self->data_ptr);
}

static int
DHF_set_cost_other_financing(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_cost_other_financing_fset, self->data_ptr);
}

static PyObject *
DHF_get_degradation(DHFObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_DHF_degradation_aget, self->data_ptr);
}

static int
DHF_set_degradation(DHFObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_DHF_degradation_aset, self->data_ptr);
}

static PyObject *
DHF_get_depr_alloc_custom_percent(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_alloc_custom_percent_fget, self->data_ptr);
}

static int
DHF_set_depr_alloc_custom_percent(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_alloc_custom_percent_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_alloc_macrs_15_percent(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_alloc_macrs_15_percent_fget, self->data_ptr);
}

static int
DHF_set_depr_alloc_macrs_15_percent(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_alloc_macrs_15_percent_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_alloc_macrs_5_percent(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_alloc_macrs_5_percent_fget, self->data_ptr);
}

static int
DHF_set_depr_alloc_macrs_5_percent(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_alloc_macrs_5_percent_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_alloc_sl_15_percent(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_alloc_sl_15_percent_fget, self->data_ptr);
}

static int
DHF_set_depr_alloc_sl_15_percent(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_alloc_sl_15_percent_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_alloc_sl_20_percent(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_alloc_sl_20_percent_fget, self->data_ptr);
}

static int
DHF_set_depr_alloc_sl_20_percent(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_alloc_sl_20_percent_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_alloc_sl_39_percent(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_alloc_sl_39_percent_fget, self->data_ptr);
}

static int
DHF_set_depr_alloc_sl_39_percent(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_alloc_sl_39_percent_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_alloc_sl_5_percent(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_alloc_sl_5_percent_fget, self->data_ptr);
}

static int
DHF_set_depr_alloc_sl_5_percent(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_alloc_sl_5_percent_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_bonus_fed(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_bonus_fed_fget, self->data_ptr);
}

static int
DHF_set_depr_bonus_fed(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_bonus_fed_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_bonus_fed_custom(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_bonus_fed_custom_fget, self->data_ptr);
}

static int
DHF_set_depr_bonus_fed_custom(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_bonus_fed_custom_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_bonus_fed_macrs_15(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_bonus_fed_macrs_15_fget, self->data_ptr);
}

static int
DHF_set_depr_bonus_fed_macrs_15(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_bonus_fed_macrs_15_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_bonus_fed_macrs_5(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_bonus_fed_macrs_5_fget, self->data_ptr);
}

static int
DHF_set_depr_bonus_fed_macrs_5(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_bonus_fed_macrs_5_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_bonus_fed_sl_15(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_bonus_fed_sl_15_fget, self->data_ptr);
}

static int
DHF_set_depr_bonus_fed_sl_15(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_bonus_fed_sl_15_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_bonus_fed_sl_20(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_bonus_fed_sl_20_fget, self->data_ptr);
}

static int
DHF_set_depr_bonus_fed_sl_20(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_bonus_fed_sl_20_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_bonus_fed_sl_39(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_bonus_fed_sl_39_fget, self->data_ptr);
}

static int
DHF_set_depr_bonus_fed_sl_39(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_bonus_fed_sl_39_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_bonus_fed_sl_5(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_bonus_fed_sl_5_fget, self->data_ptr);
}

static int
DHF_set_depr_bonus_fed_sl_5(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_bonus_fed_sl_5_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_bonus_sta(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_bonus_sta_fget, self->data_ptr);
}

static int
DHF_set_depr_bonus_sta(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_bonus_sta_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_bonus_sta_custom(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_bonus_sta_custom_fget, self->data_ptr);
}

static int
DHF_set_depr_bonus_sta_custom(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_bonus_sta_custom_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_bonus_sta_macrs_15(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_bonus_sta_macrs_15_fget, self->data_ptr);
}

static int
DHF_set_depr_bonus_sta_macrs_15(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_bonus_sta_macrs_15_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_bonus_sta_macrs_5(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_bonus_sta_macrs_5_fget, self->data_ptr);
}

static int
DHF_set_depr_bonus_sta_macrs_5(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_bonus_sta_macrs_5_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_bonus_sta_sl_15(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_bonus_sta_sl_15_fget, self->data_ptr);
}

static int
DHF_set_depr_bonus_sta_sl_15(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_bonus_sta_sl_15_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_bonus_sta_sl_20(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_bonus_sta_sl_20_fget, self->data_ptr);
}

static int
DHF_set_depr_bonus_sta_sl_20(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_bonus_sta_sl_20_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_bonus_sta_sl_39(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_bonus_sta_sl_39_fget, self->data_ptr);
}

static int
DHF_set_depr_bonus_sta_sl_39(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_bonus_sta_sl_39_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_bonus_sta_sl_5(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_bonus_sta_sl_5_fget, self->data_ptr);
}

static int
DHF_set_depr_bonus_sta_sl_5(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_bonus_sta_sl_5_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_custom_schedule(DHFObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_DHF_depr_custom_schedule_aget, self->data_ptr);
}

static int
DHF_set_depr_custom_schedule(DHFObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_DHF_depr_custom_schedule_aset, self->data_ptr);
}

static PyObject *
DHF_get_depr_fedbas_method(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_fedbas_method_fget, self->data_ptr);
}

static int
DHF_set_depr_fedbas_method(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_fedbas_method_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_itc_fed_custom(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_itc_fed_custom_fget, self->data_ptr);
}

static int
DHF_set_depr_itc_fed_custom(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_itc_fed_custom_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_itc_fed_macrs_15(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_itc_fed_macrs_15_fget, self->data_ptr);
}

static int
DHF_set_depr_itc_fed_macrs_15(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_itc_fed_macrs_15_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_itc_fed_macrs_5(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_itc_fed_macrs_5_fget, self->data_ptr);
}

static int
DHF_set_depr_itc_fed_macrs_5(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_itc_fed_macrs_5_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_itc_fed_sl_15(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_itc_fed_sl_15_fget, self->data_ptr);
}

static int
DHF_set_depr_itc_fed_sl_15(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_itc_fed_sl_15_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_itc_fed_sl_20(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_itc_fed_sl_20_fget, self->data_ptr);
}

static int
DHF_set_depr_itc_fed_sl_20(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_itc_fed_sl_20_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_itc_fed_sl_39(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_itc_fed_sl_39_fget, self->data_ptr);
}

static int
DHF_set_depr_itc_fed_sl_39(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_itc_fed_sl_39_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_itc_fed_sl_5(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_itc_fed_sl_5_fget, self->data_ptr);
}

static int
DHF_set_depr_itc_fed_sl_5(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_itc_fed_sl_5_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_itc_sta_custom(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_itc_sta_custom_fget, self->data_ptr);
}

static int
DHF_set_depr_itc_sta_custom(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_itc_sta_custom_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_itc_sta_macrs_15(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_itc_sta_macrs_15_fget, self->data_ptr);
}

static int
DHF_set_depr_itc_sta_macrs_15(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_itc_sta_macrs_15_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_itc_sta_macrs_5(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_itc_sta_macrs_5_fget, self->data_ptr);
}

static int
DHF_set_depr_itc_sta_macrs_5(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_itc_sta_macrs_5_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_itc_sta_sl_15(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_itc_sta_sl_15_fget, self->data_ptr);
}

static int
DHF_set_depr_itc_sta_sl_15(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_itc_sta_sl_15_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_itc_sta_sl_20(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_itc_sta_sl_20_fget, self->data_ptr);
}

static int
DHF_set_depr_itc_sta_sl_20(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_itc_sta_sl_20_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_itc_sta_sl_39(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_itc_sta_sl_39_fget, self->data_ptr);
}

static int
DHF_set_depr_itc_sta_sl_39(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_itc_sta_sl_39_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_itc_sta_sl_5(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_itc_sta_sl_5_fget, self->data_ptr);
}

static int
DHF_set_depr_itc_sta_sl_5(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_itc_sta_sl_5_fset, self->data_ptr);
}

static PyObject *
DHF_get_depr_stabas_method(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_depr_stabas_method_fget, self->data_ptr);
}

static int
DHF_set_depr_stabas_method(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_depr_stabas_method_fset, self->data_ptr);
}

static PyObject *
DHF_get_equip_reserve_depr_fed(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_equip_reserve_depr_fed_fget, self->data_ptr);
}

static int
DHF_set_equip_reserve_depr_fed(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_equip_reserve_depr_fed_fset, self->data_ptr);
}

static PyObject *
DHF_get_equip_reserve_depr_sta(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_equip_reserve_depr_sta_fget, self->data_ptr);
}

static int
DHF_set_equip_reserve_depr_sta(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_equip_reserve_depr_sta_fset, self->data_ptr);
}

static PyObject *
DHF_get_flip_target_percent(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_flip_target_percent_fget, self->data_ptr);
}

static int
DHF_set_flip_target_percent(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_flip_target_percent_fset, self->data_ptr);
}

static PyObject *
DHF_get_flip_target_year(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_flip_target_year_fget, self->data_ptr);
}

static int
DHF_set_flip_target_year(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_flip_target_year_fset, self->data_ptr);
}

static PyObject *
DHF_get_ppa_escalation(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_ppa_escalation_fget, self->data_ptr);
}

static int
DHF_set_ppa_escalation(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_ppa_escalation_fset, self->data_ptr);
}

static PyObject *
DHF_get_ppa_price_input(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_ppa_price_input_fget, self->data_ptr);
}

static int
DHF_set_ppa_price_input(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_ppa_price_input_fset, self->data_ptr);
}

static PyObject *
DHF_get_ppa_soln_max(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_ppa_soln_max_fget, self->data_ptr);
}

static int
DHF_set_ppa_soln_max(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_ppa_soln_max_fset, self->data_ptr);
}

static PyObject *
DHF_get_ppa_soln_max_iterations(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_ppa_soln_max_iterations_fget, self->data_ptr);
}

static int
DHF_set_ppa_soln_max_iterations(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_ppa_soln_max_iterations_fset, self->data_ptr);
}

static PyObject *
DHF_get_ppa_soln_min(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_ppa_soln_min_fget, self->data_ptr);
}

static int
DHF_set_ppa_soln_min(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_ppa_soln_min_fset, self->data_ptr);
}

static PyObject *
DHF_get_ppa_soln_mode(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_ppa_soln_mode_fget, self->data_ptr);
}

static int
DHF_set_ppa_soln_mode(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_ppa_soln_mode_fset, self->data_ptr);
}

static PyObject *
DHF_get_ppa_soln_tolerance(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_ppa_soln_tolerance_fget, self->data_ptr);
}

static int
DHF_set_ppa_soln_tolerance(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_ppa_soln_tolerance_fset, self->data_ptr);
}

static PyObject *
DHF_get_reserves_interest(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_reserves_interest_fget, self->data_ptr);
}

static int
DHF_set_reserves_interest(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_reserves_interest_fset, self->data_ptr);
}

static PyObject *
DHF_get_salvage_percentage(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_salvage_percentage_fget, self->data_ptr);
}

static int
DHF_set_salvage_percentage(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_salvage_percentage_fset, self->data_ptr);
}

static PyObject *
DHF_get_sponsor_operating_margin(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_sponsor_operating_margin_fget, self->data_ptr);
}

static int
DHF_set_sponsor_operating_margin(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_sponsor_operating_margin_fset, self->data_ptr);
}

static PyObject *
DHF_get_sponsor_operating_margin_escalation(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_sponsor_operating_margin_escalation_fget, self->data_ptr);
}

static int
DHF_set_sponsor_operating_margin_escalation(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_sponsor_operating_margin_escalation_fset, self->data_ptr);
}

static PyObject *
DHF_get_system_capacity(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_system_capacity_fget, self->data_ptr);
}

static int
DHF_set_system_capacity(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_system_capacity_fset, self->data_ptr);
}

static PyObject *
DHF_get_system_lifetime_recapitalize(DHFObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_DHF_system_lifetime_recapitalize_aget, self->data_ptr);
}

static int
DHF_set_system_lifetime_recapitalize(DHFObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_DHF_system_lifetime_recapitalize_aset, self->data_ptr);
}

static PyObject *
DHF_get_system_recapitalization_cost(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_system_recapitalization_cost_fget, self->data_ptr);
}

static int
DHF_set_system_recapitalization_cost(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_system_recapitalization_cost_fset, self->data_ptr);
}

static PyObject *
DHF_get_system_recapitalization_escalation(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_system_recapitalization_escalation_fget, self->data_ptr);
}

static int
DHF_set_system_recapitalization_escalation(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_system_recapitalization_escalation_fset, self->data_ptr);
}

static PyObject *
DHF_get_system_use_lifetime_output(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_system_use_lifetime_output_fget, self->data_ptr);
}

static int
DHF_set_system_use_lifetime_output(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_system_use_lifetime_output_fset, self->data_ptr);
}

static PyObject *
DHF_get_system_use_recapitalization(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_system_use_recapitalization_fget, self->data_ptr);
}

static int
DHF_set_system_use_recapitalization(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_system_use_recapitalization_fset, self->data_ptr);
}

static PyObject *
DHF_get_tax_investor_required_lease_reserve(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_tax_investor_required_lease_reserve_fget, self->data_ptr);
}

static int
DHF_set_tax_investor_required_lease_reserve(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_tax_investor_required_lease_reserve_fset, self->data_ptr);
}

static PyObject *
DHF_get_total_installed_cost(DHFObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_DHF_total_installed_cost_fget, self->data_ptr);
}

static int
DHF_set_total_installed_cost(DHFObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_DHF_total_installed_cost_fset, self->data_ptr);
}

static PyGetSetDef DHF_getset[] = {
{"construction_financing_cost", (getter)DHF_get_construction_financing_cost,(setter)DHF_set_construction_financing_cost,
	"Construction financing total [$], number.\n Required.",
 	NULL},
{"cost_dev_fee_percent", (getter)DHF_get_cost_dev_fee_percent,(setter)DHF_set_cost_dev_fee_percent,
	"Development fee (% pre-financing cost) [%], number.\n Constraints: MIN=0,MAX=100; Required if ?=3.",
 	NULL},
{"cost_equity_closing", (getter)DHF_get_cost_equity_closing,(setter)DHF_set_cost_equity_closing,
	"Equity closing cost [$], number.\n Constraints: MIN=0; Required if ?=100000.",
 	NULL},
{"cost_other_financing", (getter)DHF_get_cost_other_financing,(setter)DHF_set_cost_other_financing,
	" [$], number.\n Other Financing Cost; Constraints: MIN=0; Required if ?=150000.",
 	NULL},
{"degradation", (getter)DHF_get_degradation,(setter)DHF_set_degradation,
	"Annual energy degradation, array.\n Required.",
 	NULL},
{"depr_alloc_custom_percent", (getter)DHF_get_depr_alloc_custom_percent,(setter)DHF_set_depr_alloc_custom_percent,
	"Custom depreciation federal and state allocation [%], number.\n Constraints: MIN=0,MAX=100; 0 if not set.",
 	NULL},
{"depr_alloc_macrs_15_percent", (getter)DHF_get_depr_alloc_macrs_15_percent,(setter)DHF_set_depr_alloc_macrs_15_percent,
	"15-yr MACRS depreciation federal and state allocation [%], number.\n Constraints: MIN=0,MAX=100; Required if ?=1.5.",
 	NULL},
{"depr_alloc_macrs_5_percent", (getter)DHF_get_depr_alloc_macrs_5_percent,(setter)DHF_set_depr_alloc_macrs_5_percent,
	"5-yr MACRS depreciation federal and state allocation [%], number.\n Constraints: MIN=0,MAX=100; Required if ?=89.",
 	NULL},
{"depr_alloc_sl_15_percent", (getter)DHF_get_depr_alloc_sl_15_percent,(setter)DHF_set_depr_alloc_sl_15_percent,
	"15-yr straight line depreciation federal and state allocation [%], number.\n Constraints: MIN=0,MAX=100; Required if ?=3.",
 	NULL},
{"depr_alloc_sl_20_percent", (getter)DHF_get_depr_alloc_sl_20_percent,(setter)DHF_set_depr_alloc_sl_20_percent,
	"20-yr straight line depreciation federal and state allocation [%], number.\n Constraints: MIN=0,MAX=100; Required if ?=3.",
 	NULL},
{"depr_alloc_sl_39_percent", (getter)DHF_get_depr_alloc_sl_39_percent,(setter)DHF_set_depr_alloc_sl_39_percent,
	"39-yr straight line depreciation federal and state allocation [%], number.\n Constraints: MIN=0,MAX=100; Required if ?=0.5.",
 	NULL},
{"depr_alloc_sl_5_percent", (getter)DHF_get_depr_alloc_sl_5_percent,(setter)DHF_set_depr_alloc_sl_5_percent,
	"5-yr straight line depreciation federal and state allocation [%], number.\n Constraints: MIN=0,MAX=100; 0 if not set.",
 	NULL},
{"depr_bonus_fed", (getter)DHF_get_depr_bonus_fed,(setter)DHF_set_depr_bonus_fed,
	"Federal bonus depreciation [%], number.\n Constraints: MIN=0,MAX=100; 0 if not set.",
 	NULL},
{"depr_bonus_fed_custom", (getter)DHF_get_depr_bonus_fed_custom,(setter)DHF_set_depr_bonus_fed_custom,
	"Federal bonus depreciation custom [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_bonus_fed_macrs_15", (getter)DHF_get_depr_bonus_fed_macrs_15,(setter)DHF_set_depr_bonus_fed_macrs_15,
	"Federal bonus depreciation 15-yr MACRS [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_bonus_fed_macrs_5", (getter)DHF_get_depr_bonus_fed_macrs_5,(setter)DHF_set_depr_bonus_fed_macrs_5,
	"Federal bonus depreciation 5-yr MACRS [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"depr_bonus_fed_sl_15", (getter)DHF_get_depr_bonus_fed_sl_15,(setter)DHF_set_depr_bonus_fed_sl_15,
	"Federal bonus depreciation 15-yr straight line [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_bonus_fed_sl_20", (getter)DHF_get_depr_bonus_fed_sl_20,(setter)DHF_set_depr_bonus_fed_sl_20,
	"Federal bonus depreciation 20-yr straight line [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_bonus_fed_sl_39", (getter)DHF_get_depr_bonus_fed_sl_39,(setter)DHF_set_depr_bonus_fed_sl_39,
	"Federal bonus depreciation 39-yr straight line [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_bonus_fed_sl_5", (getter)DHF_get_depr_bonus_fed_sl_5,(setter)DHF_set_depr_bonus_fed_sl_5,
	"Federal bonus depreciation 5-yr straight line [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_bonus_sta", (getter)DHF_get_depr_bonus_sta,(setter)DHF_set_depr_bonus_sta,
	"State bonus depreciation [%], number.\n Constraints: MIN=0,MAX=100; 0 if not set.",
 	NULL},
{"depr_bonus_sta_custom", (getter)DHF_get_depr_bonus_sta_custom,(setter)DHF_set_depr_bonus_sta_custom,
	"State bonus depreciation custom [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_bonus_sta_macrs_15", (getter)DHF_get_depr_bonus_sta_macrs_15,(setter)DHF_set_depr_bonus_sta_macrs_15,
	"State bonus depreciation 15-yr MACRS [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_bonus_sta_macrs_5", (getter)DHF_get_depr_bonus_sta_macrs_5,(setter)DHF_set_depr_bonus_sta_macrs_5,
	"State bonus depreciation 5-yr MACRS [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"depr_bonus_sta_sl_15", (getter)DHF_get_depr_bonus_sta_sl_15,(setter)DHF_set_depr_bonus_sta_sl_15,
	"State bonus depreciation 15-yr straight line [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_bonus_sta_sl_20", (getter)DHF_get_depr_bonus_sta_sl_20,(setter)DHF_set_depr_bonus_sta_sl_20,
	"State bonus depreciation 20-yr straight line [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_bonus_sta_sl_39", (getter)DHF_get_depr_bonus_sta_sl_39,(setter)DHF_set_depr_bonus_sta_sl_39,
	"State bonus depreciation 39-yr straight line [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_bonus_sta_sl_5", (getter)DHF_get_depr_bonus_sta_sl_5,(setter)DHF_set_depr_bonus_sta_sl_5,
	"State bonus depreciation 5-yr straight line [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_custom_schedule", (getter)DHF_get_depr_custom_schedule,(setter)DHF_set_depr_custom_schedule,
	"Custom depreciation schedule [%], array.\n Required.",
 	NULL},
{"depr_fedbas_method", (getter)DHF_get_depr_fedbas_method,(setter)DHF_set_depr_fedbas_method,
	"Method of federal depreciation reduction, number.\n 0=5yr MACRS,1=Proportional; Constraints: INTEGER,MIN=0,MAX=1; 0 if not set.",
 	NULL},
{"depr_itc_fed_custom", (getter)DHF_get_depr_itc_fed_custom,(setter)DHF_set_depr_itc_fed_custom,
	"Federal itc depreciation custom [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_itc_fed_macrs_15", (getter)DHF_get_depr_itc_fed_macrs_15,(setter)DHF_set_depr_itc_fed_macrs_15,
	"Federal itc depreciation 15-yr MACRS [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_itc_fed_macrs_5", (getter)DHF_get_depr_itc_fed_macrs_5,(setter)DHF_set_depr_itc_fed_macrs_5,
	"Federal itc depreciation 5-yr MACRS [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"depr_itc_fed_sl_15", (getter)DHF_get_depr_itc_fed_sl_15,(setter)DHF_set_depr_itc_fed_sl_15,
	"Federal itc depreciation 15-yr straight line [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_itc_fed_sl_20", (getter)DHF_get_depr_itc_fed_sl_20,(setter)DHF_set_depr_itc_fed_sl_20,
	"Federal itc depreciation 20-yr straight line [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_itc_fed_sl_39", (getter)DHF_get_depr_itc_fed_sl_39,(setter)DHF_set_depr_itc_fed_sl_39,
	"Federal itc depreciation 39-yr straight line [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_itc_fed_sl_5", (getter)DHF_get_depr_itc_fed_sl_5,(setter)DHF_set_depr_itc_fed_sl_5,
	"Federal itc depreciation 5-yr straight line [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_itc_sta_custom", (getter)DHF_get_depr_itc_sta_custom,(setter)DHF_set_depr_itc_sta_custom,
	"State itc depreciation custom [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_itc_sta_macrs_15", (getter)DHF_get_depr_itc_sta_macrs_15,(setter)DHF_set_depr_itc_sta_macrs_15,
	"State itc depreciation 15-yr MACRS [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_itc_sta_macrs_5", (getter)DHF_get_depr_itc_sta_macrs_5,(setter)DHF_set_depr_itc_sta_macrs_5,
	"State itc depreciation 5-yr MACRS [0/1], number.\n Constraints: BOOLEAN; Required if ?=1.",
 	NULL},
{"depr_itc_sta_sl_15", (getter)DHF_get_depr_itc_sta_sl_15,(setter)DHF_set_depr_itc_sta_sl_15,
	"State itc depreciation 15-yr straight line [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_itc_sta_sl_20", (getter)DHF_get_depr_itc_sta_sl_20,(setter)DHF_set_depr_itc_sta_sl_20,
	"State itc depreciation 20-yr straight line [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_itc_sta_sl_39", (getter)DHF_get_depr_itc_sta_sl_39,(setter)DHF_set_depr_itc_sta_sl_39,
	"State itc depreciation 39-yr straight line [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_itc_sta_sl_5", (getter)DHF_get_depr_itc_sta_sl_5,(setter)DHF_set_depr_itc_sta_sl_5,
	"State itc depreciation 5-yr straight line [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"depr_stabas_method", (getter)DHF_get_depr_stabas_method,(setter)DHF_set_depr_stabas_method,
	"Method of state depreciation reduction, number.\n 0=5yr MACRS,1=Proportional; Constraints: INTEGER,MIN=0,MAX=1; 0 if not set.",
 	NULL},
{"equip_reserve_depr_fed", (getter)DHF_get_equip_reserve_depr_fed,(setter)DHF_set_equip_reserve_depr_fed,
	"Major equipment reserve federal depreciation, number.\n 0=5yr MACRS,1=15yr MACRS,2=5yr SL,3=15yr SL, 4=20yr SL,5=39yr SL,6=Custom; Constraints: INTEGER,MIN=0,MAX=6; 0 if not set.",
 	NULL},
{"equip_reserve_depr_sta", (getter)DHF_get_equip_reserve_depr_sta,(setter)DHF_set_equip_reserve_depr_sta,
	"Major equipment reserve state depreciation, number.\n 0=5yr MACRS,1=15yr MACRS,2=5yr SL,3=15yr SL, 4=20yr SL,5=39yr SL,6=Custom; Constraints: INTEGER,MIN=0,MAX=6; 0 if not set.",
 	NULL},
{"flip_target_percent", (getter)DHF_get_flip_target_percent,(setter)DHF_set_flip_target_percent,
	"After-tax flip/return target [%], number.\n Constraints: MIN=0,MAX=100; Required if ?=11.",
 	NULL},
{"flip_target_year", (getter)DHF_get_flip_target_year,(setter)DHF_set_flip_target_year,
	"Return target year, number.\n Constraints: MIN=1; Required if ?=11.",
 	NULL},
{"ppa_escalation", (getter)DHF_get_ppa_escalation,(setter)DHF_set_ppa_escalation,
	"PPA escalation [%], number.\n 0 if not set.",
 	NULL},
{"ppa_price_input", (getter)DHF_get_ppa_price_input,(setter)DHF_set_ppa_price_input,
	"Initial year PPA price [$/kWh], number.\n Required if ?=10.",
 	NULL},
{"ppa_soln_max", (getter)DHF_get_ppa_soln_max,(setter)DHF_set_ppa_soln_max,
	"PPA solution maximum ppa [cents/kWh], number.\n Required if ?=100.",
 	NULL},
{"ppa_soln_max_iterations", (getter)DHF_get_ppa_soln_max_iterations,(setter)DHF_set_ppa_soln_max_iterations,
	"PPA solution maximum number of iterations, number.\n Constraints: INTEGER,MIN=1; Required if ?=100.",
 	NULL},
{"ppa_soln_min", (getter)DHF_get_ppa_soln_min,(setter)DHF_set_ppa_soln_min,
	"PPA solution minimum ppa [cents/kWh], number.\n 0 if not set.",
 	NULL},
{"ppa_soln_mode", (getter)DHF_get_ppa_soln_mode,(setter)DHF_set_ppa_soln_mode,
	"PPA solution mode [0/1], number.\n 0=solve ppa,1=specify ppa; Constraints: INTEGER,MIN=0,MAX=1; 0 if not set.",
 	NULL},
{"ppa_soln_tolerance", (getter)DHF_get_ppa_soln_tolerance,(setter)DHF_set_ppa_soln_tolerance,
	"PPA solution tolerance, number.\n Required if ?=1e-3.",
 	NULL},
{"reserves_interest", (getter)DHF_get_reserves_interest,(setter)DHF_set_reserves_interest,
	"Interest on reserves [%], number.\n Constraints: MIN=0,MAX=100; Required if ?=1.75.",
 	NULL},
{"salvage_percentage", (getter)DHF_get_salvage_percentage,(setter)DHF_set_salvage_percentage,
	"Net pre-tax cash salvage value [%], number.\n Constraints: MIN=0,MAX=100; Required if ?=10.",
 	NULL},
{"sponsor_operating_margin", (getter)DHF_get_sponsor_operating_margin,(setter)DHF_set_sponsor_operating_margin,
	"Annual Developer (Lessee) Operating Margin [$/kW], number.\n Required if ?=40.",
 	NULL},
{"sponsor_operating_margin_escalation", (getter)DHF_get_sponsor_operating_margin_escalation,(setter)DHF_set_sponsor_operating_margin_escalation,
	"Annual Developer (Lessee) Operating Margin Escalation [%], number.\n Constraints: MIN=0,MAX=100; Required if ?=2.",
 	NULL},
{"system_capacity", (getter)DHF_get_system_capacity,(setter)DHF_set_system_capacity,
	"System nameplate capacity [kW], number.\n Constraints: MIN=1e-3; Required.",
 	NULL},
{"system_lifetime_recapitalize", (getter)DHF_get_system_lifetime_recapitalize,(setter)DHF_set_system_lifetime_recapitalize,
	"Recapitalization boolean, array.\n 0 if not set.",
 	NULL},
{"system_recapitalization_cost", (getter)DHF_get_system_recapitalization_cost,(setter)DHF_set_system_recapitalization_cost,
	"Recapitalization cost [$], number.\n 0 if not set.",
 	NULL},
{"system_recapitalization_escalation", (getter)DHF_get_system_recapitalization_escalation,(setter)DHF_set_system_recapitalization_escalation,
	"Recapitalization escalation (above inflation) [%], number.\n Constraints: MIN=0,MAX=100; 0 if not set.",
 	NULL},
{"system_use_lifetime_output", (getter)DHF_get_system_use_lifetime_output,(setter)DHF_set_system_use_lifetime_output,
	"Lifetime hourly system outputs [0/1], number.\n 0=hourly first year,1=hourly lifetime; Constraints: INTEGER,MIN=0; Required.",
 	NULL},
{"system_use_recapitalization", (getter)DHF_get_system_use_recapitalization,(setter)DHF_set_system_use_recapitalization,
	"Recapitalization expenses [0/1], number.\n 0=None,1=Recapitalize; Constraints: INTEGER,MIN=0; 0 if not set.",
 	NULL},
{"tax_investor_required_lease_reserve", (getter)DHF_get_tax_investor_required_lease_reserve,(setter)DHF_set_tax_investor_required_lease_reserve,
	"Lessor Required Lease Payment Reserve [months], number.\n Constraints: INTEGER; Required if ?=6.",
 	NULL},
{"total_installed_cost", (getter)DHF_get_total_installed_cost,(setter)DHF_set_total_installed_cost,
	"Installed cost [$], number.\n Required.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject DHF_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Saleleaseback.DHF",             /*tp_name*/
		sizeof(DHFObject),          /*tp_basicsize*/
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
		DHF_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		DHF_getset,          /*tp_getset*/
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
	 * TimeOfDelivery Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Saleleaseback   data_ptr;
} TimeOfDeliveryObject;

static PyTypeObject TimeOfDelivery_Type;

static PyObject *
TimeOfDelivery_new(SAM_Saleleaseback data_ptr)
{
	PyObject* new_obj = TimeOfDelivery_Type.tp_alloc(&TimeOfDelivery_Type,0);

	TimeOfDeliveryObject* TimeOfDelivery_obj = (TimeOfDeliveryObject*)new_obj;

	TimeOfDelivery_obj->data_ptr = data_ptr;

	return new_obj;
}

/* TimeOfDelivery methods */

static PyObject *
TimeOfDelivery_assign(TimeOfDeliveryObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Saleleaseback", "TimeOfDelivery")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TimeOfDelivery_export(TimeOfDeliveryObject *self, PyObject *args)
{
	PyTypeObject* tp = &TimeOfDelivery_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TimeOfDelivery_methods[] = {
		{"assign",            (PyCFunction)TimeOfDelivery_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)TimeOfDelivery_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TimeOfDelivery_get_dispatch_factor1(TimeOfDeliveryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TimeOfDelivery_dispatch_factor1_fget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factor1(TimeOfDeliveryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TimeOfDelivery_dispatch_factor1_fset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_factor2(TimeOfDeliveryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TimeOfDelivery_dispatch_factor2_fget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factor2(TimeOfDeliveryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TimeOfDelivery_dispatch_factor2_fset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_factor3(TimeOfDeliveryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TimeOfDelivery_dispatch_factor3_fget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factor3(TimeOfDeliveryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TimeOfDelivery_dispatch_factor3_fset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_factor4(TimeOfDeliveryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TimeOfDelivery_dispatch_factor4_fget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factor4(TimeOfDeliveryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TimeOfDelivery_dispatch_factor4_fset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_factor5(TimeOfDeliveryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TimeOfDelivery_dispatch_factor5_fget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factor5(TimeOfDeliveryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TimeOfDelivery_dispatch_factor5_fset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_factor6(TimeOfDeliveryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TimeOfDelivery_dispatch_factor6_fget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factor6(TimeOfDeliveryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TimeOfDelivery_dispatch_factor6_fset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_factor7(TimeOfDeliveryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TimeOfDelivery_dispatch_factor7_fget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factor7(TimeOfDeliveryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TimeOfDelivery_dispatch_factor7_fset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_factor8(TimeOfDeliveryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TimeOfDelivery_dispatch_factor8_fget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factor8(TimeOfDeliveryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TimeOfDelivery_dispatch_factor8_fset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_factor9(TimeOfDeliveryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TimeOfDelivery_dispatch_factor9_fget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factor9(TimeOfDeliveryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TimeOfDelivery_dispatch_factor9_fset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_factors_ts(TimeOfDeliveryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_TimeOfDelivery_dispatch_factors_ts_aget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factors_ts(TimeOfDeliveryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_TimeOfDelivery_dispatch_factors_ts_aset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_sched_weekday(TimeOfDeliveryObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Saleleaseback_TimeOfDelivery_dispatch_sched_weekday_mget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_sched_weekday(TimeOfDeliveryObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Saleleaseback_TimeOfDelivery_dispatch_sched_weekday_mset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_dispatch_sched_weekend(TimeOfDeliveryObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Saleleaseback_TimeOfDelivery_dispatch_sched_weekend_mget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_sched_weekend(TimeOfDeliveryObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Saleleaseback_TimeOfDelivery_dispatch_sched_weekend_mset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_ppa_multiplier_model(TimeOfDeliveryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_TimeOfDelivery_ppa_multiplier_model_fget, self->data_ptr);
}

static int
TimeOfDelivery_set_ppa_multiplier_model(TimeOfDeliveryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_TimeOfDelivery_ppa_multiplier_model_fset, self->data_ptr);
}

static PyGetSetDef TimeOfDelivery_getset[] = {
{"dispatch_factor1", (getter)TimeOfDelivery_get_dispatch_factor1,(setter)TimeOfDelivery_set_dispatch_factor1,
	"TOD factor for period 1, number.\n Required if ppa_multiplier_model=0.",
 	NULL},
{"dispatch_factor2", (getter)TimeOfDelivery_get_dispatch_factor2,(setter)TimeOfDelivery_set_dispatch_factor2,
	"TOD factor for period 2, number.\n Required if ppa_multiplier_model=0.",
 	NULL},
{"dispatch_factor3", (getter)TimeOfDelivery_get_dispatch_factor3,(setter)TimeOfDelivery_set_dispatch_factor3,
	"TOD factor for period 3, number.\n Required if ppa_multiplier_model=0.",
 	NULL},
{"dispatch_factor4", (getter)TimeOfDelivery_get_dispatch_factor4,(setter)TimeOfDelivery_set_dispatch_factor4,
	"TOD factor for period 4, number.\n Required if ppa_multiplier_model=0.",
 	NULL},
{"dispatch_factor5", (getter)TimeOfDelivery_get_dispatch_factor5,(setter)TimeOfDelivery_set_dispatch_factor5,
	"TOD factor for period 5, number.\n Required if ppa_multiplier_model=0.",
 	NULL},
{"dispatch_factor6", (getter)TimeOfDelivery_get_dispatch_factor6,(setter)TimeOfDelivery_set_dispatch_factor6,
	"TOD factor for period 6, number.\n Required if ppa_multiplier_model=0.",
 	NULL},
{"dispatch_factor7", (getter)TimeOfDelivery_get_dispatch_factor7,(setter)TimeOfDelivery_set_dispatch_factor7,
	"TOD factor for period 7, number.\n Required if ppa_multiplier_model=0.",
 	NULL},
{"dispatch_factor8", (getter)TimeOfDelivery_get_dispatch_factor8,(setter)TimeOfDelivery_set_dispatch_factor8,
	"TOD factor for period 8, number.\n Required if ppa_multiplier_model=0.",
 	NULL},
{"dispatch_factor9", (getter)TimeOfDelivery_get_dispatch_factor9,(setter)TimeOfDelivery_set_dispatch_factor9,
	"TOD factor for period 9, number.\n Required if ppa_multiplier_model=0.",
 	NULL},
{"dispatch_factors_ts", (getter)TimeOfDelivery_get_dispatch_factors_ts,(setter)TimeOfDelivery_set_dispatch_factors_ts,
	"Dispatch payment factor array, array.\n Required if ppa_multiplier_model=1.",
 	NULL},
{"dispatch_sched_weekday", (getter)TimeOfDelivery_get_dispatch_sched_weekday,(setter)TimeOfDelivery_set_dispatch_sched_weekday,
	"Diurnal weekday TOD periods [1..9], matrix.\n 12 x 24 matrix; Required if ppa_multiplier_model=0.",
 	NULL},
{"dispatch_sched_weekend", (getter)TimeOfDelivery_get_dispatch_sched_weekend,(setter)TimeOfDelivery_set_dispatch_sched_weekend,
	"Diurnal weekend TOD periods [1..9], matrix.\n 12 x 24 matrix; Required if ppa_multiplier_model=0.",
 	NULL},
{"ppa_multiplier_model", (getter)TimeOfDelivery_get_ppa_multiplier_model,(setter)TimeOfDelivery_set_ppa_multiplier_model,
	"PPA multiplier model [0/1], number.\n 0=diurnal,1=timestep; Constraints: INTEGER,MIN=0; 0 if not set.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TimeOfDelivery_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Saleleaseback.TimeOfDelivery",             /*tp_name*/
		sizeof(TimeOfDeliveryObject),          /*tp_basicsize*/
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
		TimeOfDelivery_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TimeOfDelivery_getset,          /*tp_getset*/
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
	 * ReserveAccounts Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Saleleaseback   data_ptr;
} ReserveAccountsObject;

static PyTypeObject ReserveAccounts_Type;

static PyObject *
ReserveAccounts_new(SAM_Saleleaseback data_ptr)
{
	PyObject* new_obj = ReserveAccounts_Type.tp_alloc(&ReserveAccounts_Type,0);

	ReserveAccountsObject* ReserveAccounts_obj = (ReserveAccountsObject*)new_obj;

	ReserveAccounts_obj->data_ptr = data_ptr;

	return new_obj;
}

/* ReserveAccounts methods */

static PyObject *
ReserveAccounts_assign(ReserveAccountsObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Saleleaseback", "ReserveAccounts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ReserveAccounts_export(ReserveAccountsObject *self, PyObject *args)
{
	PyTypeObject* tp = &ReserveAccounts_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ReserveAccounts_methods[] = {
		{"assign",            (PyCFunction)ReserveAccounts_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)ReserveAccounts_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ReserveAccounts_get_equip1_reserve_cost(ReserveAccountsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_ReserveAccounts_equip1_reserve_cost_fget, self->data_ptr);
}

static int
ReserveAccounts_set_equip1_reserve_cost(ReserveAccountsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_ReserveAccounts_equip1_reserve_cost_fset, self->data_ptr);
}

static PyObject *
ReserveAccounts_get_equip1_reserve_freq(ReserveAccountsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_ReserveAccounts_equip1_reserve_freq_fget, self->data_ptr);
}

static int
ReserveAccounts_set_equip1_reserve_freq(ReserveAccountsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_ReserveAccounts_equip1_reserve_freq_fset, self->data_ptr);
}

static PyObject *
ReserveAccounts_get_equip2_reserve_cost(ReserveAccountsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_ReserveAccounts_equip2_reserve_cost_fget, self->data_ptr);
}

static int
ReserveAccounts_set_equip2_reserve_cost(ReserveAccountsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_ReserveAccounts_equip2_reserve_cost_fset, self->data_ptr);
}

static PyObject *
ReserveAccounts_get_equip2_reserve_freq(ReserveAccountsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_ReserveAccounts_equip2_reserve_freq_fget, self->data_ptr);
}

static int
ReserveAccounts_set_equip2_reserve_freq(ReserveAccountsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_ReserveAccounts_equip2_reserve_freq_fset, self->data_ptr);
}

static PyObject *
ReserveAccounts_get_equip3_reserve_cost(ReserveAccountsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_ReserveAccounts_equip3_reserve_cost_fget, self->data_ptr);
}

static int
ReserveAccounts_set_equip3_reserve_cost(ReserveAccountsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_ReserveAccounts_equip3_reserve_cost_fset, self->data_ptr);
}

static PyObject *
ReserveAccounts_get_equip3_reserve_freq(ReserveAccountsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_ReserveAccounts_equip3_reserve_freq_fget, self->data_ptr);
}

static int
ReserveAccounts_set_equip3_reserve_freq(ReserveAccountsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_ReserveAccounts_equip3_reserve_freq_fset, self->data_ptr);
}

static PyGetSetDef ReserveAccounts_getset[] = {
{"equip1_reserve_cost", (getter)ReserveAccounts_get_equip1_reserve_cost,(setter)ReserveAccounts_set_equip1_reserve_cost,
	"Major equipment reserve 1 cost [$/W], number.\n Constraints: MIN=0; Required if ?=0.25.",
 	NULL},
{"equip1_reserve_freq", (getter)ReserveAccounts_get_equip1_reserve_freq,(setter)ReserveAccounts_set_equip1_reserve_freq,
	"Major equipment reserve 1 frequency [years], number.\n Constraints: INTEGER,MIN=0; Required if ?=12.",
 	NULL},
{"equip2_reserve_cost", (getter)ReserveAccounts_get_equip2_reserve_cost,(setter)ReserveAccounts_set_equip2_reserve_cost,
	"Major equipment reserve 2 cost [$/W], number.\n Constraints: MIN=0; 0 if not set.",
 	NULL},
{"equip2_reserve_freq", (getter)ReserveAccounts_get_equip2_reserve_freq,(setter)ReserveAccounts_set_equip2_reserve_freq,
	"Major equipment reserve 2 frequency [years], number.\n Constraints: INTEGER,MIN=0; Required if ?=15.",
 	NULL},
{"equip3_reserve_cost", (getter)ReserveAccounts_get_equip3_reserve_cost,(setter)ReserveAccounts_set_equip3_reserve_cost,
	"Major equipment reserve 3 cost [$/W], number.\n Constraints: MIN=0; 0 if not set.",
 	NULL},
{"equip3_reserve_freq", (getter)ReserveAccounts_get_equip3_reserve_freq,(setter)ReserveAccounts_set_equip3_reserve_freq,
	"Major equipment reserve 3 frequency [years], number.\n Constraints: INTEGER,MIN=0; Required if ?=20.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ReserveAccounts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Saleleaseback.ReserveAccounts",             /*tp_name*/
		sizeof(ReserveAccountsObject),          /*tp_basicsize*/
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
		ReserveAccounts_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ReserveAccounts_getset,          /*tp_getset*/
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
	 * OtherCapitalCosts Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Saleleaseback   data_ptr;
} OtherCapitalCostsObject;

static PyTypeObject OtherCapitalCosts_Type;

static PyObject *
OtherCapitalCosts_new(SAM_Saleleaseback data_ptr)
{
	PyObject* new_obj = OtherCapitalCosts_Type.tp_alloc(&OtherCapitalCosts_Type,0);

	OtherCapitalCostsObject* OtherCapitalCosts_obj = (OtherCapitalCostsObject*)new_obj;

	OtherCapitalCosts_obj->data_ptr = data_ptr;

	return new_obj;
}

/* OtherCapitalCosts methods */

static PyObject *
OtherCapitalCosts_assign(OtherCapitalCostsObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Saleleaseback", "OtherCapitalCosts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
OtherCapitalCosts_export(OtherCapitalCostsObject *self, PyObject *args)
{
	PyTypeObject* tp = &OtherCapitalCosts_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef OtherCapitalCosts_methods[] = {
		{"assign",            (PyCFunction)OtherCapitalCosts_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)OtherCapitalCosts_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
OtherCapitalCosts_get_months_receivables_reserve(OtherCapitalCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_OtherCapitalCosts_months_receivables_reserve_fget, self->data_ptr);
}

static int
OtherCapitalCosts_set_months_receivables_reserve(OtherCapitalCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_OtherCapitalCosts_months_receivables_reserve_fset, self->data_ptr);
}

static PyObject *
OtherCapitalCosts_get_months_working_reserve(OtherCapitalCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_OtherCapitalCosts_months_working_reserve_fget, self->data_ptr);
}

static int
OtherCapitalCosts_set_months_working_reserve(OtherCapitalCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_OtherCapitalCosts_months_working_reserve_fset, self->data_ptr);
}

static PyGetSetDef OtherCapitalCosts_getset[] = {
{"months_receivables_reserve", (getter)OtherCapitalCosts_get_months_receivables_reserve,(setter)OtherCapitalCosts_set_months_receivables_reserve,
	"Receivables reserve months of PPA revenue [months], number.\n Constraints: MIN=0; 0 if not set.",
 	NULL},
{"months_working_reserve", (getter)OtherCapitalCosts_get_months_working_reserve,(setter)OtherCapitalCosts_set_months_working_reserve,
	"Working capital reserve months of operating costs [months], number.\n Constraints: MIN=0; Required if ?=6.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject OtherCapitalCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Saleleaseback.OtherCapitalCosts",             /*tp_name*/
		sizeof(OtherCapitalCostsObject),          /*tp_basicsize*/
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
		OtherCapitalCosts_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		OtherCapitalCosts_getset,          /*tp_getset*/
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
	SAM_Saleleaseback   data_ptr;
} BatteryObject;

static PyTypeObject Battery_Type;

static PyObject *
Battery_new(SAM_Saleleaseback data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Saleleaseback", "Battery")){
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
	return PySAM_array_getter(SAM_Saleleaseback_Battery_batt_bank_replacement_aget, self->data_ptr);
}

static int
Battery_set_batt_bank_replacement(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_Battery_batt_bank_replacement_aset, self->data_ptr);
}

static PyObject *
Battery_get_batt_computed_bank_capacity(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Battery_batt_computed_bank_capacity_fget, self->data_ptr);
}

static int
Battery_set_batt_computed_bank_capacity(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_Battery_batt_computed_bank_capacity_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_replacement_option(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Battery_batt_replacement_option_fget, self->data_ptr);
}

static int
Battery_set_batt_replacement_option(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_Battery_batt_replacement_option_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_replacement_schedule(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Battery_batt_replacement_schedule_aget, self->data_ptr);
}

static int
Battery_set_batt_replacement_schedule(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Saleleaseback_Battery_batt_replacement_schedule_aset, self->data_ptr);
}

static PyObject *
Battery_get_battery_per_kWh(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Battery_battery_per_kWh_fget, self->data_ptr);
}

static int
Battery_set_battery_per_kWh(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_Battery_battery_per_kWh_fset, self->data_ptr);
}

static PyObject *
Battery_get_en_batt(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Battery_en_batt_fget, self->data_ptr);
}

static int
Battery_set_en_batt(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Saleleaseback_Battery_en_batt_fset, self->data_ptr);
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
		"Saleleaseback.Battery",             /*tp_name*/
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
	 * Outputs Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Saleleaseback   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Saleleaseback data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Saleleaseback", "Outputs")){
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
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_adjusted_installed_cost_fget, self->data_ptr);
}

static PyObject *
Outputs_get_analysis_period_irr(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_analysis_period_irr_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_fedtax_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_cbi_fedtax_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_statax_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_cbi_statax_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_cbi_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_fed(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_cbi_total_fed_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_oth(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_cbi_total_oth_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_sta(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_cbi_total_sta_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cbi_total_uti(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_cbi_total_uti_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_annual_costs(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_annual_costs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_battery_replacement_cost(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_battery_replacement_cost_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_battery_replacement_cost_schedule(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_battery_replacement_cost_schedule_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_disbursement_equip1(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_disbursement_equip1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_disbursement_equip2(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_disbursement_equip2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_disbursement_equip3(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_disbursement_equip3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_disbursement_leasepayment(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_disbursement_leasepayment_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_disbursement_merr(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_disbursement_merr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_disbursement_om(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_disbursement_om_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_disbursement_receivables(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_disbursement_receivables_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_effective_tax_frac(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_effective_tax_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_apr(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_aug(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dec(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch1(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_dispatch1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch2(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_dispatch2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch3(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_dispatch3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch4(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_dispatch4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch5(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_dispatch5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch6(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_dispatch6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch7(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_dispatch7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch8(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_dispatch8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_dispatch9(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_dispatch9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_feb(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_jan(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_jul(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_jun(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_mar(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_may(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD1(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_monthly_firstyear_TOD1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD2(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_monthly_firstyear_TOD2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD3(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_monthly_firstyear_TOD3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD4(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_monthly_firstyear_TOD4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD5(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_monthly_firstyear_TOD5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD6(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_monthly_firstyear_TOD6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD7(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_monthly_firstyear_TOD7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD8(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_monthly_firstyear_TOD8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_monthly_firstyear_TOD9(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_monthly_firstyear_TOD9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_nov(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_oct(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net_sep(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_net_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_value(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_energy_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_custom(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_feddepr_custom_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_feddepr_macrs_15_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_feddepr_macrs_5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_me1(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_feddepr_me1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_me2(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_feddepr_me2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_me3(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_feddepr_me3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_feddepr_sl_15_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_feddepr_sl_20_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_feddepr_sl_39_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_feddepr_sl_5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_feddepr_total(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_feddepr_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_federal_tax_frac(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_federal_tax_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_funding_equip1(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_funding_equip1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_funding_equip2(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_funding_equip2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_funding_equip3(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_funding_equip3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_funding_leasepayment(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_funding_leasepayment_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_funding_om(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_funding_om_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_funding_receivables(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_funding_receivables_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_insurance_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_insurance_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_length(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_cf_length_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_net_salvage_value(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_net_salvage_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_capacity_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_om_capacity_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_fixed_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_om_fixed_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_fuel_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_om_fuel_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_opt_fuel_1_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_om_opt_fuel_1_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_opt_fuel_2_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_om_opt_fuel_2_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_om_production_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_om_production_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_operating_expenses(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_operating_expenses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_fedtax_total(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_pbi_fedtax_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_statax_total(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_pbi_statax_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_pbi_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_fed(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_pbi_total_fed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_oth(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_pbi_total_oth_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_sta(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_pbi_total_sta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pbi_total_uti(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_pbi_total_uti_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_ppa_price(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_ppa_price_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pretax_cashflow(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_pretax_cashflow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_pretax_operating_cashflow(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_pretax_operating_cashflow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_property_tax_assessed_value(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_property_tax_assessed_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_property_tax_expense(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_property_tax_expense_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_ptc_fed(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_ptc_fed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_ptc_sta(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_ptc_sta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_recapitalization(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_recapitalization_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_equip1(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_reserve_equip1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_equip2(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_reserve_equip2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_equip3(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_reserve_equip3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_interest(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_reserve_interest_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_leasepayment(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_reserve_leasepayment_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_leasepayment_interest(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_reserve_leasepayment_interest_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_om(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_reserve_om_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_receivables(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_reserve_receivables_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_reserve_total(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_reserve_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_apr(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_apr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_aug(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_aug_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dec(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch1(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_dispatch1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch2(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_dispatch2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch3(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_dispatch3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch4(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_dispatch4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch5(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_dispatch5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch6(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_dispatch6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch7(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_dispatch7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch8(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_dispatch8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_dispatch9(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_dispatch9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_feb(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_feb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_jan(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_jan_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_jul(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_jul_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_jun(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_jun_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_mar(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_mar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_may(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_may_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD1(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_monthly_firstyear_TOD1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD2(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_monthly_firstyear_TOD2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD3(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_monthly_firstyear_TOD3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD4(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_monthly_firstyear_TOD4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD5(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_monthly_firstyear_TOD5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD6(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_monthly_firstyear_TOD6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD7(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_monthly_firstyear_TOD7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD8(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_monthly_firstyear_TOD8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_monthly_firstyear_TOD9(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_monthly_firstyear_TOD9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_nov(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_nov_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_oct(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_oct_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_revenue_sep(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_revenue_sep_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_adj_reserve_release(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_adj_reserve_release_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_aftertax(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_aftertax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_aftertax_cash(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_aftertax_cash_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_aftertax_devfee(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_aftertax_devfee_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_aftertax_irr(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_aftertax_irr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_aftertax_npv(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_aftertax_npv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_aftertax_tax(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_aftertax_tax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_fedtax(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_fedtax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_fedtax_income_prior_incentives(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_fedtax_income_prior_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_fedtax_income_with_incentives(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_fedtax_income_with_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_fedtax_taxable_incentives(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_fedtax_taxable_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_financing_activities(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_financing_activities_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_investing_activities(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_investing_activities_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_lpra(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_lpra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_margin(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_margin_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_me1cs(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_me1cs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_me1ra(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_me1ra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_me2cs(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_me2cs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_me2ra(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_me2ra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_me3cs(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_me3cs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_me3ra(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_me3ra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_mecs(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_mecs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_operating_activities(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_operating_activities_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_operating_margin(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_operating_margin_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_pretax(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_pretax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_pretax_irr(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_pretax_irr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_pretax_npv(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_pretax_npv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_ra(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_ra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_receivablesra(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_receivablesra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_statax(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_statax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_statax_income_prior_incentives(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_statax_income_prior_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_statax_income_with_incentives(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_statax_income_with_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_statax_taxable_incentives(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_statax_taxable_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_sponsor_wcra(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_sponsor_wcra_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_custom(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_stadepr_custom_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_stadepr_macrs_15_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_stadepr_macrs_5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_me1(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_stadepr_me1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_me2(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_stadepr_me2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_me3(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_stadepr_me3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_stadepr_sl_15_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_stadepr_sl_20_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_stadepr_sl_39_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_stadepr_sl_5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_stadepr_total(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_stadepr_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_state_tax_frac(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_state_tax_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_aftertax(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_aftertax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_aftertax_cash(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_aftertax_cash_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_aftertax_irr(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_aftertax_irr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_aftertax_itc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_aftertax_itc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_aftertax_max_irr(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_aftertax_max_irr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_aftertax_npv(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_aftertax_npv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_aftertax_ptc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_aftertax_ptc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_aftertax_tax(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_aftertax_tax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_fedtax(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_fedtax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_fedtax_income_prior_incentives(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_fedtax_income_prior_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_fedtax_income_with_incentives(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_fedtax_income_with_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_fedtax_taxable_incentives(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_fedtax_taxable_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_financing_activities(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_financing_activities_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_investing_activities(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_investing_activities_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_operating_activities(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_operating_activities_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_pretax(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_pretax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_pretax_cashflow(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_pretax_cashflow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_pretax_irr(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_pretax_irr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_pretax_npv(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_pretax_npv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_statax(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_statax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_statax_income_prior_incentives(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_statax_income_prior_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_statax_income_with_incentives(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_statax_income_with_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_tax_investor_statax_taxable_incentives(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_tax_investor_statax_taxable_incentives_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_total_revenue(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_cf_total_revenue_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cost_financing(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_cost_financing_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cost_installed(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_cost_installed_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cost_installedperwatt(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_cost_installedperwatt_fget, self->data_ptr);
}

static PyObject *
Outputs_get_debt_fraction(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_debt_fraction_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_alloc_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_alloc_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_alloc_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_none(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_alloc_none_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_none_percent(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_alloc_none_percent_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_alloc_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_alloc_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_alloc_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_alloc_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_alloc_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_alloc_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_after_itc_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_after_itc_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_after_itc_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_after_itc_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_after_itc_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_after_itc_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_after_itc_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_after_itc_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_after_itc_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_cbi_reduc_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_cbi_reduc_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_cbi_reduc_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_cbi_reduc_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_cbi_reduc_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_cbi_reduc_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_cbi_reduc_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_cbi_reduc_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_cbi_reduc_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_first_year_bonus_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_first_year_bonus_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_first_year_bonus_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_first_year_bonus_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_first_year_bonus_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_first_year_bonus_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_first_year_bonus_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_first_year_bonus_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_first_year_bonus_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_fixed_amount_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_fixed_amount_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_fixed_amount_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_fixed_amount_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_fixed_amount_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_fixed_amount_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_fixed_amount_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_fixed_amount_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_fixed_amount_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_ibi_reduc_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_ibi_reduc_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_ibi_reduc_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_ibi_reduc_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_ibi_reduc_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_ibi_reduc_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_ibi_reduc_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_ibi_reduc_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_ibi_reduc_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_itc_fed_reduction_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_itc_fed_reduction_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_itc_fed_reduction_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_itc_fed_reduction_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_itc_fed_reduction_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_itc_fed_reduction_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_itc_fed_reduction_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_fed_reduction_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_itc_fed_reduction_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_itc_sta_reduction_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_itc_sta_reduction_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_itc_sta_reduction_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_itc_sta_reduction_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_itc_sta_reduction_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_itc_sta_reduction_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_itc_sta_reduction_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_itc_sta_reduction_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_itc_sta_reduction_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_amount_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_amount_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_amount_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_amount_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_amount_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_amount_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_amount_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_amount_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_amount_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_qual_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_qual_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_qual_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_qual_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_qual_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_qual_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_qual_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_qual_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_qual_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_percent_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_percent_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_prior_itc_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_prior_itc_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_prior_itc_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_prior_itc_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_prior_itc_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_prior_itc_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_prior_itc_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_prior_itc_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_prior_itc_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_fedbas_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_fedbas_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_after_itc_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_after_itc_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_after_itc_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_after_itc_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_after_itc_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_after_itc_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_after_itc_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_after_itc_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_after_itc_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_cbi_reduc_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_cbi_reduc_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_cbi_reduc_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_cbi_reduc_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_cbi_reduc_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_cbi_reduc_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_cbi_reduc_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_cbi_reduc_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_cbi_reduc_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_first_year_bonus_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_first_year_bonus_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_first_year_bonus_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_first_year_bonus_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_first_year_bonus_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_first_year_bonus_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_first_year_bonus_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_first_year_bonus_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_first_year_bonus_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_fixed_amount_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_fixed_amount_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_fixed_amount_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_fixed_amount_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_fixed_amount_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_fixed_amount_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_fixed_amount_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_fixed_amount_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_fixed_amount_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_ibi_reduc_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_ibi_reduc_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_ibi_reduc_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_ibi_reduc_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_ibi_reduc_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_ibi_reduc_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_ibi_reduc_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_ibi_reduc_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_ibi_reduc_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_itc_fed_reduction_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_itc_fed_reduction_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_itc_fed_reduction_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_itc_fed_reduction_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_itc_fed_reduction_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_itc_fed_reduction_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_itc_fed_reduction_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_fed_reduction_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_itc_fed_reduction_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_itc_sta_reduction_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_itc_sta_reduction_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_itc_sta_reduction_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_itc_sta_reduction_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_itc_sta_reduction_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_itc_sta_reduction_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_itc_sta_reduction_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_itc_sta_reduction_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_itc_sta_reduction_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_amount_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_amount_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_amount_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_amount_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_amount_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_amount_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_amount_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_amount_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_amount_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_qual_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_qual_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_qual_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_qual_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_qual_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_qual_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_qual_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_qual_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_qual_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_percent_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_percent_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_prior_itc_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_prior_itc_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_prior_itc_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_prior_itc_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_prior_itc_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_prior_itc_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_prior_itc_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_prior_itc_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_prior_itc_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_depr_stabas_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_depr_stabas_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_distribution_of_development_fee(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_distribution_of_development_fee_fget, self->data_ptr);
}

static PyObject *
Outputs_get_effective_tax_rate(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_effective_tax_rate_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch1(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_energy_dispatch1_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch2(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_energy_dispatch2_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch3(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_energy_dispatch3_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch4(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_energy_dispatch4_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_energy_dispatch5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch6(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_energy_dispatch6_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch7(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_energy_dispatch7_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch8(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_energy_dispatch8_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_dispatch9(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_energy_dispatch9_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price1(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_energy_price1_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price2(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_energy_price2_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price3(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_energy_price3_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price4(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_energy_price4_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_energy_price5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price6(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_energy_price6_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price7(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_energy_price7_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price8(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_energy_price8_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_energy_price9(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_energy_price9_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch1(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_revenue_dispatch1_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch2(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_revenue_dispatch2_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch3(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_revenue_dispatch3_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch4(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_revenue_dispatch4_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_revenue_dispatch5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch6(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_revenue_dispatch6_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch7(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_revenue_dispatch7_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch8(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_revenue_dispatch8_fget, self->data_ptr);
}

static PyObject *
Outputs_get_firstyear_revenue_dispatch9(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_firstyear_revenue_dispatch9_fget, self->data_ptr);
}

static PyObject *
Outputs_get_flip_actual_irr(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_flip_actual_irr_fget, self->data_ptr);
}

static PyObject *
Outputs_get_flip_actual_year(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_flip_actual_year_fget, self->data_ptr);
}

static PyObject *
Outputs_get_flip_target_irr(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_flip_target_irr_fget, self->data_ptr);
}

static PyObject *
Outputs_get_flip_target_year(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_flip_target_year_fget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_fedtax_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_ibi_fedtax_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_statax_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_ibi_statax_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_ibi_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_fed(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_ibi_total_fed_fget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_oth(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_ibi_total_oth_fget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_sta(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_ibi_total_sta_fget, self->data_ptr);
}

static PyObject *
Outputs_get_ibi_total_uti(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_ibi_total_uti_fget, self->data_ptr);
}

static PyObject *
Outputs_get_issuance_of_equity(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_issuance_of_equity_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_fed_fixed_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_fed_fixed_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_fed_fixed_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_fed_fixed_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_fed_fixed_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_fed_fixed_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_fed_fixed_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_fixed_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_fed_fixed_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_fed_percent_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_fed_percent_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_fed_percent_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_fed_percent_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_fed_percent_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_fed_percent_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_fed_percent_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_fed_percent_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_fed_percent_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_sta_fixed_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_sta_fixed_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_sta_fixed_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_sta_fixed_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_sta_fixed_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_sta_fixed_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_sta_fixed_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_fixed_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_sta_fixed_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_sta_percent_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_sta_percent_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_sta_percent_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_sta_percent_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_sta_percent_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_sta_percent_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_sta_percent_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_disallow_sta_percent_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_disallow_sta_percent_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_fixed_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_fed_fixed_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_percent_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_fed_percent_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_fed_qual_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_fed_qual_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_fed_qual_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_fed_qual_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_fed_qual_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_fed_qual_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_fed_qual_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_fed_qual_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_fed_qual_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_fixed_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_sta_fixed_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_percent_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_sta_percent_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_custom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_sta_qual_custom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_macrs_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_sta_qual_macrs_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_macrs_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_sta_qual_macrs_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_sl_15(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_sta_qual_sl_15_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_sl_20(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_sta_qual_sl_20_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_sl_39(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_sta_qual_sl_39_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_sl_5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_sta_qual_sl_5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_sta_qual_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_sta_qual_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_total_fed(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_total_fed_fget, self->data_ptr);
}

static PyObject *
Outputs_get_itc_total_sta(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_itc_total_sta_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoe_nom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_lcoe_nom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoe_real(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_lcoe_real_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_fed_nom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_lcoptc_fed_nom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_fed_real(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_lcoptc_fed_real_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_sta_nom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_lcoptc_sta_nom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lcoptc_sta_real(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_lcoptc_sta_real_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lppa_nom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_lppa_nom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lppa_real(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_lppa_real_fget, self->data_ptr);
}

static PyObject *
Outputs_get_nominal_discount_rate(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_nominal_discount_rate_fget, self->data_ptr);
}

static PyObject *
Outputs_get_npv_annual_costs(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_npv_annual_costs_fget, self->data_ptr);
}

static PyObject *
Outputs_get_npv_energy_nom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_npv_energy_nom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_npv_energy_real(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_npv_energy_real_fget, self->data_ptr);
}

static PyObject *
Outputs_get_npv_ppa_revenue(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_npv_ppa_revenue_fget, self->data_ptr);
}

static PyObject *
Outputs_get_ppa(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_ppa_fget, self->data_ptr);
}

static PyObject *
Outputs_get_ppa_escalation(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_ppa_escalation_fget, self->data_ptr);
}

static PyObject *
Outputs_get_ppa_multipliers(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Saleleaseback_Outputs_ppa_multipliers_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ppa_price(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_ppa_price_fget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_fuel(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_present_value_fuel_fget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_insandproptax(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_present_value_insandproptax_fget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_oandm(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_present_value_oandm_fget, self->data_ptr);
}

static PyObject *
Outputs_get_present_value_oandm_nonfuel(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_present_value_oandm_nonfuel_fget, self->data_ptr);
}

static PyObject *
Outputs_get_prop_tax_assessed_value(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_prop_tax_assessed_value_fget, self->data_ptr);
}

static PyObject *
Outputs_get_purchase_of_plant(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_purchase_of_plant_fget, self->data_ptr);
}

static PyObject *
Outputs_get_sale_of_property(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_sale_of_property_fget, self->data_ptr);
}

static PyObject *
Outputs_get_salvage_value(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_salvage_value_fget, self->data_ptr);
}

static PyObject *
Outputs_get_size_of_equity(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_size_of_equity_fget, self->data_ptr);
}

static PyObject *
Outputs_get_sponsor_aftertax_irr(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_sponsor_aftertax_irr_fget, self->data_ptr);
}

static PyObject *
Outputs_get_sponsor_aftertax_npv(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_sponsor_aftertax_npv_fget, self->data_ptr);
}

static PyObject *
Outputs_get_sponsor_equity_in_lessee_llc(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_sponsor_equity_in_lessee_llc_fget, self->data_ptr);
}

static PyObject *
Outputs_get_sponsor_pretax_irr(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_sponsor_pretax_irr_fget, self->data_ptr);
}

static PyObject *
Outputs_get_sponsor_pretax_npv(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_sponsor_pretax_npv_fget, self->data_ptr);
}

static PyObject *
Outputs_get_tax_investor_aftertax_irr(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_tax_investor_aftertax_irr_fget, self->data_ptr);
}

static PyObject *
Outputs_get_tax_investor_aftertax_npv(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_tax_investor_aftertax_npv_fget, self->data_ptr);
}

static PyObject *
Outputs_get_tax_investor_pretax_irr(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_tax_investor_pretax_irr_fget, self->data_ptr);
}

static PyObject *
Outputs_get_tax_investor_pretax_npv(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_tax_investor_pretax_npv_fget, self->data_ptr);
}

static PyObject *
Outputs_get_wacc(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Saleleaseback_Outputs_wacc_fget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"adjusted_installed_cost", (getter)Outputs_get_adjusted_installed_cost,(setter)0,
	"Initial cost less cash incentives [$], number.",
 	NULL},
{"analysis_period_irr", (getter)Outputs_get_analysis_period_irr,(setter)0,
	"Analysis Period IRR [%], number.",
 	NULL},
{"cbi_fedtax_total", (getter)Outputs_get_cbi_fedtax_total,(setter)0,
	"Total federal taxable CBI incentive income [$], number.",
 	NULL},
{"cbi_statax_total", (getter)Outputs_get_cbi_statax_total,(setter)0,
	"Total state taxable CBI incentive income [$], number.",
 	NULL},
{"cbi_total", (getter)Outputs_get_cbi_total,(setter)0,
	"Total CBI incentive income [$], number.",
 	NULL},
{"cbi_total_fed", (getter)Outputs_get_cbi_total_fed,(setter)0,
	"Total federal CBI incentive income [$], number.",
 	NULL},
{"cbi_total_oth", (getter)Outputs_get_cbi_total_oth,(setter)0,
	"Total other CBI incentive income [$], number.",
 	NULL},
{"cbi_total_sta", (getter)Outputs_get_cbi_total_sta,(setter)0,
	"Total state CBI incentive income [$], number.",
 	NULL},
{"cbi_total_uti", (getter)Outputs_get_cbi_total_uti,(setter)0,
	"Total utility CBI incentive income [$], number.",
 	NULL},
{"cf_annual_costs", (getter)Outputs_get_cf_annual_costs,(setter)0,
	"Annual costs [$], array.",
 	NULL},
{"cf_battery_replacement_cost", (getter)Outputs_get_cf_battery_replacement_cost,(setter)0,
	"Battery replacement cost [$], array.",
 	NULL},
{"cf_battery_replacement_cost_schedule", (getter)Outputs_get_cf_battery_replacement_cost_schedule,(setter)0,
	"Battery replacement cost schedule [$/kWh], array.",
 	NULL},
{"cf_disbursement_equip1", (getter)Outputs_get_cf_disbursement_equip1,(setter)0,
	"Reserve disbursement major equipment 1 [$], array.",
 	NULL},
{"cf_disbursement_equip2", (getter)Outputs_get_cf_disbursement_equip2,(setter)0,
	"Reserve disbursement major equipment 2 [$], array.",
 	NULL},
{"cf_disbursement_equip3", (getter)Outputs_get_cf_disbursement_equip3,(setter)0,
	"Reserve disbursement major equipment 3 [$], array.",
 	NULL},
{"cf_disbursement_leasepayment", (getter)Outputs_get_cf_disbursement_leasepayment,(setter)0,
	"Reserve disbursement lease payment [$], array.",
 	NULL},
{"cf_disbursement_merr", (getter)Outputs_get_cf_disbursement_merr,(setter)0,
	"Reserve disbursement major equipment total [$], array.",
 	NULL},
{"cf_disbursement_om", (getter)Outputs_get_cf_disbursement_om,(setter)0,
	"Reserve disbursement working capital [$], array.",
 	NULL},
{"cf_disbursement_receivables", (getter)Outputs_get_cf_disbursement_receivables,(setter)0,
	"Reserve disbursement receivables [$], array.",
 	NULL},
{"cf_effective_tax_frac", (getter)Outputs_get_cf_effective_tax_frac,(setter)0,
	"Effective income tax rate [frac], array.",
 	NULL},
{"cf_energy_net", (getter)Outputs_get_cf_energy_net,(setter)0,
	"Energy [kWh], array.",
 	NULL},
{"cf_energy_net_apr", (getter)Outputs_get_cf_energy_net_apr,(setter)0,
	"Energy produced by the system in April [kWh], array.",
 	NULL},
{"cf_energy_net_aug", (getter)Outputs_get_cf_energy_net_aug,(setter)0,
	"Energy produced by the system in August [kWh], array.",
 	NULL},
{"cf_energy_net_dec", (getter)Outputs_get_cf_energy_net_dec,(setter)0,
	"Energy produced by the system in December [kWh], array.",
 	NULL},
{"cf_energy_net_dispatch1", (getter)Outputs_get_cf_energy_net_dispatch1,(setter)0,
	"Energy produced by the system in TOD period 1 [kWh], array.",
 	NULL},
{"cf_energy_net_dispatch2", (getter)Outputs_get_cf_energy_net_dispatch2,(setter)0,
	"Energy produced by the system in TOD period 2 [kWh], array.",
 	NULL},
{"cf_energy_net_dispatch3", (getter)Outputs_get_cf_energy_net_dispatch3,(setter)0,
	"Energy produced by the system in TOD period 3 [kWh], array.",
 	NULL},
{"cf_energy_net_dispatch4", (getter)Outputs_get_cf_energy_net_dispatch4,(setter)0,
	"Energy produced by the system in TOD period 4 [kWh], array.",
 	NULL},
{"cf_energy_net_dispatch5", (getter)Outputs_get_cf_energy_net_dispatch5,(setter)0,
	"Energy produced by the system in TOD period 5 [kWh], array.",
 	NULL},
{"cf_energy_net_dispatch6", (getter)Outputs_get_cf_energy_net_dispatch6,(setter)0,
	"Energy produced by the system in TOD period 6 [kWh], array.",
 	NULL},
{"cf_energy_net_dispatch7", (getter)Outputs_get_cf_energy_net_dispatch7,(setter)0,
	"Energy produced by the system in TOD period 7 [kWh], array.",
 	NULL},
{"cf_energy_net_dispatch8", (getter)Outputs_get_cf_energy_net_dispatch8,(setter)0,
	"Energy produced by the system in TOD period 8 [kWh], array.",
 	NULL},
{"cf_energy_net_dispatch9", (getter)Outputs_get_cf_energy_net_dispatch9,(setter)0,
	"Energy produced by the system in TOD period 9 [kWh], array.",
 	NULL},
{"cf_energy_net_feb", (getter)Outputs_get_cf_energy_net_feb,(setter)0,
	"Energy produced by the system in February [kWh], array.",
 	NULL},
{"cf_energy_net_jan", (getter)Outputs_get_cf_energy_net_jan,(setter)0,
	"Energy produced by the system in January [kWh], array.",
 	NULL},
{"cf_energy_net_jul", (getter)Outputs_get_cf_energy_net_jul,(setter)0,
	"Energy produced by the system in July [kWh], array.",
 	NULL},
{"cf_energy_net_jun", (getter)Outputs_get_cf_energy_net_jun,(setter)0,
	"Energy produced by the system in June [kWh], array.",
 	NULL},
{"cf_energy_net_mar", (getter)Outputs_get_cf_energy_net_mar,(setter)0,
	"Energy produced by the system in March [kWh], array.",
 	NULL},
{"cf_energy_net_may", (getter)Outputs_get_cf_energy_net_may,(setter)0,
	"Energy produced by the system in May [kWh], array.",
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD1", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD1,(setter)0,
	"First year energy from the system by month for TOD period 1 [kWh], array.",
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD2", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD2,(setter)0,
	"First year energy from the system by month for TOD period 2 [kWh], array.",
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD3", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD3,(setter)0,
	"First year energy from the system by month for TOD period 3 [kWh], array.",
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD4", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD4,(setter)0,
	"First year energy from the system by month for TOD period 4 [kWh], array.",
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD5", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD5,(setter)0,
	"First year energy from the system by month for TOD period 5 [kWh], array.",
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD6", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD6,(setter)0,
	"First year energy from the system by month for TOD period 6 [kWh], array.",
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD7", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD7,(setter)0,
	"First year energy from the system by month for TOD period 7 [kWh], array.",
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD8", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD8,(setter)0,
	"First year energy from the system by month for TOD period 8 [kWh], array.",
 	NULL},
{"cf_energy_net_monthly_firstyear_TOD9", (getter)Outputs_get_cf_energy_net_monthly_firstyear_TOD9,(setter)0,
	"First year energy from the system by month for TOD period 9 [kWh], array.",
 	NULL},
{"cf_energy_net_nov", (getter)Outputs_get_cf_energy_net_nov,(setter)0,
	"Energy produced by the system in November [kWh], array.",
 	NULL},
{"cf_energy_net_oct", (getter)Outputs_get_cf_energy_net_oct,(setter)0,
	"Energy produced by the system in October [kWh], array.",
 	NULL},
{"cf_energy_net_sep", (getter)Outputs_get_cf_energy_net_sep,(setter)0,
	"Energy produced by the system in September [kWh], array.",
 	NULL},
{"cf_energy_value", (getter)Outputs_get_cf_energy_value,(setter)0,
	"PPA revenue [$], array.",
 	NULL},
{"cf_feddepr_custom", (getter)Outputs_get_cf_feddepr_custom,(setter)0,
	"Federal depreciation from custom [$], array.",
 	NULL},
{"cf_feddepr_macrs_15", (getter)Outputs_get_cf_feddepr_macrs_15,(setter)0,
	"Federal depreciation from 15-yr MACRS [$], array.",
 	NULL},
{"cf_feddepr_macrs_5", (getter)Outputs_get_cf_feddepr_macrs_5,(setter)0,
	"Federal depreciation from 5-yr MACRS [$], array.",
 	NULL},
{"cf_feddepr_me1", (getter)Outputs_get_cf_feddepr_me1,(setter)0,
	"Federal depreciation from major equipment 1 [$], array.",
 	NULL},
{"cf_feddepr_me2", (getter)Outputs_get_cf_feddepr_me2,(setter)0,
	"Federal depreciation from major equipment 2 [$], array.",
 	NULL},
{"cf_feddepr_me3", (getter)Outputs_get_cf_feddepr_me3,(setter)0,
	"Federal depreciation from major equipment 3 [$], array.",
 	NULL},
{"cf_feddepr_sl_15", (getter)Outputs_get_cf_feddepr_sl_15,(setter)0,
	"Federal depreciation from 15-yr straight line [$], array.",
 	NULL},
{"cf_feddepr_sl_20", (getter)Outputs_get_cf_feddepr_sl_20,(setter)0,
	"Federal depreciation from 20-yr straight line [$], array.",
 	NULL},
{"cf_feddepr_sl_39", (getter)Outputs_get_cf_feddepr_sl_39,(setter)0,
	"Federal depreciation from 39-yr straight line [$], array.",
 	NULL},
{"cf_feddepr_sl_5", (getter)Outputs_get_cf_feddepr_sl_5,(setter)0,
	"Federal depreciation from 5-yr straight line [$], array.",
 	NULL},
{"cf_feddepr_total", (getter)Outputs_get_cf_feddepr_total,(setter)0,
	"Total federal tax depreciation [$], array.",
 	NULL},
{"cf_federal_tax_frac", (getter)Outputs_get_cf_federal_tax_frac,(setter)0,
	"Federal income tax rate [frac], array.",
 	NULL},
{"cf_funding_equip1", (getter)Outputs_get_cf_funding_equip1,(setter)0,
	"Reserve funding major equipment 1 [$], array.",
 	NULL},
{"cf_funding_equip2", (getter)Outputs_get_cf_funding_equip2,(setter)0,
	"Reserve funding major equipment 2 [$], array.",
 	NULL},
{"cf_funding_equip3", (getter)Outputs_get_cf_funding_equip3,(setter)0,
	"Reserve funding major equipment 3 [$], array.",
 	NULL},
{"cf_funding_leasepayment", (getter)Outputs_get_cf_funding_leasepayment,(setter)0,
	"Reserve funding lease payment [$], array.",
 	NULL},
{"cf_funding_om", (getter)Outputs_get_cf_funding_om,(setter)0,
	"Reserve funding working capital [$], array.",
 	NULL},
{"cf_funding_receivables", (getter)Outputs_get_cf_funding_receivables,(setter)0,
	"Reserve funding receivables [$], array.",
 	NULL},
{"cf_insurance_expense", (getter)Outputs_get_cf_insurance_expense,(setter)0,
	"Insurance expense [$], array.",
 	NULL},
{"cf_length", (getter)Outputs_get_cf_length,(setter)0,
	"Number of periods in cashflow, number.",
 	NULL},
{"cf_net_salvage_value", (getter)Outputs_get_cf_net_salvage_value,(setter)0,
	"Salvage value [$], array.",
 	NULL},
{"cf_om_capacity_expense", (getter)Outputs_get_cf_om_capacity_expense,(setter)0,
	"O&M capacity-based expense [$], array.",
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
{"cf_om_production_expense", (getter)Outputs_get_cf_om_production_expense,(setter)0,
	"O&M production-based expense [$], array.",
 	NULL},
{"cf_operating_expenses", (getter)Outputs_get_cf_operating_expenses,(setter)0,
	"Total operating expense [$], array.",
 	NULL},
{"cf_pbi_fedtax_total", (getter)Outputs_get_cf_pbi_fedtax_total,(setter)0,
	"Total federal taxable PBI incentive income [$], array.",
 	NULL},
{"cf_pbi_statax_total", (getter)Outputs_get_cf_pbi_statax_total,(setter)0,
	"Total state taxable PBI incentive income [$], array.",
 	NULL},
{"cf_pbi_total", (getter)Outputs_get_cf_pbi_total,(setter)0,
	"Total PBI incentive income [$], array.",
 	NULL},
{"cf_pbi_total_fed", (getter)Outputs_get_cf_pbi_total_fed,(setter)0,
	"Total federal PBI incentive income [$], array.",
 	NULL},
{"cf_pbi_total_oth", (getter)Outputs_get_cf_pbi_total_oth,(setter)0,
	"Total other PBI incentive income [$], array.",
 	NULL},
{"cf_pbi_total_sta", (getter)Outputs_get_cf_pbi_total_sta,(setter)0,
	"Total state PBI incentive income [$], array.",
 	NULL},
{"cf_pbi_total_uti", (getter)Outputs_get_cf_pbi_total_uti,(setter)0,
	"Total utility PBI incentive income [$], array.",
 	NULL},
{"cf_ppa_price", (getter)Outputs_get_cf_ppa_price,(setter)0,
	"PPA price [cents/kWh], array.",
 	NULL},
{"cf_pretax_cashflow", (getter)Outputs_get_cf_pretax_cashflow,(setter)0,
	"Pre-tax cash flow [$], array.",
 	NULL},
{"cf_pretax_operating_cashflow", (getter)Outputs_get_cf_pretax_operating_cashflow,(setter)0,
	"Pre-tax operating cash flow [$], array.",
 	NULL},
{"cf_property_tax_assessed_value", (getter)Outputs_get_cf_property_tax_assessed_value,(setter)0,
	"Property tax net assessed value [$], array.",
 	NULL},
{"cf_property_tax_expense", (getter)Outputs_get_cf_property_tax_expense,(setter)0,
	"Property tax expense [$], array.",
 	NULL},
{"cf_ptc_fed", (getter)Outputs_get_cf_ptc_fed,(setter)0,
	"Federal PTC income [$], array.",
 	NULL},
{"cf_ptc_sta", (getter)Outputs_get_cf_ptc_sta,(setter)0,
	"State PTC income [$], array.",
 	NULL},
{"cf_recapitalization", (getter)Outputs_get_cf_recapitalization,(setter)0,
	"Recapitalization operating expense [$], array.",
 	NULL},
{"cf_reserve_equip1", (getter)Outputs_get_cf_reserve_equip1,(setter)0,
	"Reserve account major equipment 1 [$], array.",
 	NULL},
{"cf_reserve_equip2", (getter)Outputs_get_cf_reserve_equip2,(setter)0,
	"Reserve account major equipment 2 [$], array.",
 	NULL},
{"cf_reserve_equip3", (getter)Outputs_get_cf_reserve_equip3,(setter)0,
	"Reserve account major equipment 3 [$], array.",
 	NULL},
{"cf_reserve_interest", (getter)Outputs_get_cf_reserve_interest,(setter)0,
	"Reserve account interest on reserves [$], array.",
 	NULL},
{"cf_reserve_leasepayment", (getter)Outputs_get_cf_reserve_leasepayment,(setter)0,
	"Reserve account lease payment reserve [$], array.",
 	NULL},
{"cf_reserve_leasepayment_interest", (getter)Outputs_get_cf_reserve_leasepayment_interest,(setter)0,
	"Reserve account lease payment reserve interest [$], array.",
 	NULL},
{"cf_reserve_om", (getter)Outputs_get_cf_reserve_om,(setter)0,
	"Reserve account working capital [$], array.",
 	NULL},
{"cf_reserve_receivables", (getter)Outputs_get_cf_reserve_receivables,(setter)0,
	"Reserve account receivables [$], array.",
 	NULL},
{"cf_reserve_total", (getter)Outputs_get_cf_reserve_total,(setter)0,
	"Reserve account total [$], array.",
 	NULL},
{"cf_revenue_apr", (getter)Outputs_get_cf_revenue_apr,(setter)0,
	"Revenue from the system in April [$], array.",
 	NULL},
{"cf_revenue_aug", (getter)Outputs_get_cf_revenue_aug,(setter)0,
	"Revenue from the system in August [$], array.",
 	NULL},
{"cf_revenue_dec", (getter)Outputs_get_cf_revenue_dec,(setter)0,
	"Revenue from the system in December [$], array.",
 	NULL},
{"cf_revenue_dispatch1", (getter)Outputs_get_cf_revenue_dispatch1,(setter)0,
	"Revenue from the system in TOD period 1 [$], array.",
 	NULL},
{"cf_revenue_dispatch2", (getter)Outputs_get_cf_revenue_dispatch2,(setter)0,
	"Revenue from the system in TOD period 2 [$], array.",
 	NULL},
{"cf_revenue_dispatch3", (getter)Outputs_get_cf_revenue_dispatch3,(setter)0,
	"Revenue from the system in TOD period 3 [$], array.",
 	NULL},
{"cf_revenue_dispatch4", (getter)Outputs_get_cf_revenue_dispatch4,(setter)0,
	"Revenue from the system in TOD period 4 [$], array.",
 	NULL},
{"cf_revenue_dispatch5", (getter)Outputs_get_cf_revenue_dispatch5,(setter)0,
	"Revenue from the system in TOD period 5 [$], array.",
 	NULL},
{"cf_revenue_dispatch6", (getter)Outputs_get_cf_revenue_dispatch6,(setter)0,
	"Revenue from the system in TOD period 6 [$], array.",
 	NULL},
{"cf_revenue_dispatch7", (getter)Outputs_get_cf_revenue_dispatch7,(setter)0,
	"Revenue from the system in TOD period 7 [$], array.",
 	NULL},
{"cf_revenue_dispatch8", (getter)Outputs_get_cf_revenue_dispatch8,(setter)0,
	"Revenue from the system in TOD period 8 [$], array.",
 	NULL},
{"cf_revenue_dispatch9", (getter)Outputs_get_cf_revenue_dispatch9,(setter)0,
	"Revenue from the system in TOD period 9 [$], array.",
 	NULL},
{"cf_revenue_feb", (getter)Outputs_get_cf_revenue_feb,(setter)0,
	"Revenue from the system in February [$], array.",
 	NULL},
{"cf_revenue_jan", (getter)Outputs_get_cf_revenue_jan,(setter)0,
	"Revenue from the system in January [$], array.",
 	NULL},
{"cf_revenue_jul", (getter)Outputs_get_cf_revenue_jul,(setter)0,
	"Revenue from the system in July [$], array.",
 	NULL},
{"cf_revenue_jun", (getter)Outputs_get_cf_revenue_jun,(setter)0,
	"Revenue from the system in June [$], array.",
 	NULL},
{"cf_revenue_mar", (getter)Outputs_get_cf_revenue_mar,(setter)0,
	"Revenue from the system in March [$], array.",
 	NULL},
{"cf_revenue_may", (getter)Outputs_get_cf_revenue_may,(setter)0,
	"Revenue from the system in May [$], array.",
 	NULL},
{"cf_revenue_monthly_firstyear_TOD1", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD1,(setter)0,
	"First year revenue from the system by month for TOD period 1 [$], array.",
 	NULL},
{"cf_revenue_monthly_firstyear_TOD2", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD2,(setter)0,
	"First year revenue from the system by month for TOD period 2 [$], array.",
 	NULL},
{"cf_revenue_monthly_firstyear_TOD3", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD3,(setter)0,
	"First year revenue from the system by month for TOD period 3 [$], array.",
 	NULL},
{"cf_revenue_monthly_firstyear_TOD4", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD4,(setter)0,
	"First year revenue from the system by month for TOD period 4 [$], array.",
 	NULL},
{"cf_revenue_monthly_firstyear_TOD5", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD5,(setter)0,
	"First year revenue from the system by month for TOD period 5 [$], array.",
 	NULL},
{"cf_revenue_monthly_firstyear_TOD6", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD6,(setter)0,
	"First year revenue from the system by month for TOD period 6 [$], array.",
 	NULL},
{"cf_revenue_monthly_firstyear_TOD7", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD7,(setter)0,
	"First year revenue from the system by month for TOD period 7 [$], array.",
 	NULL},
{"cf_revenue_monthly_firstyear_TOD8", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD8,(setter)0,
	"First year revenue from the system by month for TOD period 8 [$], array.",
 	NULL},
{"cf_revenue_monthly_firstyear_TOD9", (getter)Outputs_get_cf_revenue_monthly_firstyear_TOD9,(setter)0,
	"First year revenue from the system by month for TOD period 9 [$], array.",
 	NULL},
{"cf_revenue_nov", (getter)Outputs_get_cf_revenue_nov,(setter)0,
	"Revenue from the system in November [$], array.",
 	NULL},
{"cf_revenue_oct", (getter)Outputs_get_cf_revenue_oct,(setter)0,
	"Revenue from the system in October [$], array.",
 	NULL},
{"cf_revenue_sep", (getter)Outputs_get_cf_revenue_sep,(setter)0,
	"Revenue from the system in September [$], array.",
 	NULL},
{"cf_sponsor_adj_reserve_release", (getter)Outputs_get_cf_sponsor_adj_reserve_release,(setter)0,
	"Adjustment for release of reserves [$], array.",
 	NULL},
{"cf_sponsor_aftertax", (getter)Outputs_get_cf_sponsor_aftertax,(setter)0,
	"After-tax developer returns [$], array.",
 	NULL},
{"cf_sponsor_aftertax_cash", (getter)Outputs_get_cf_sponsor_aftertax_cash,(setter)0,
	"After-tax developer returns cash total [$], array.",
 	NULL},
{"cf_sponsor_aftertax_devfee", (getter)Outputs_get_cf_sponsor_aftertax_devfee,(setter)0,
	"After-tax sponsor developer fee tax liability [$], array.",
 	NULL},
{"cf_sponsor_aftertax_irr", (getter)Outputs_get_cf_sponsor_aftertax_irr,(setter)0,
	"After-tax developer cumulative IRR [%], array.",
 	NULL},
{"cf_sponsor_aftertax_npv", (getter)Outputs_get_cf_sponsor_aftertax_npv,(setter)0,
	"After-tax developer cumulative NPV [$], array.",
 	NULL},
{"cf_sponsor_aftertax_tax", (getter)Outputs_get_cf_sponsor_aftertax_tax,(setter)0,
	"After-tax sponsor tax returns [$], array.",
 	NULL},
{"cf_sponsor_fedtax", (getter)Outputs_get_cf_sponsor_fedtax,(setter)0,
	"Developer federal tax benefit/(liability) [$], array.",
 	NULL},
{"cf_sponsor_fedtax_income_prior_incentives", (getter)Outputs_get_cf_sponsor_fedtax_income_prior_incentives,(setter)0,
	"Developer federal taxable income prior incentives [$], array.",
 	NULL},
{"cf_sponsor_fedtax_income_with_incentives", (getter)Outputs_get_cf_sponsor_fedtax_income_with_incentives,(setter)0,
	"Developer federal tax income with incentives [$], array.",
 	NULL},
{"cf_sponsor_fedtax_taxable_incentives", (getter)Outputs_get_cf_sponsor_fedtax_taxable_incentives,(setter)0,
	"Developer federal taxable incentives [$], array.",
 	NULL},
{"cf_sponsor_financing_activities", (getter)Outputs_get_cf_sponsor_financing_activities,(setter)0,
	"Cash flow from financing activities [$], array.",
 	NULL},
{"cf_sponsor_investing_activities", (getter)Outputs_get_cf_sponsor_investing_activities,(setter)0,
	"After-tax annual costs [$], array.",
 	NULL},
{"cf_sponsor_lpra", (getter)Outputs_get_cf_sponsor_lpra,(setter)0,
	"Reserve (increase)/decrease lease payment [$], array.",
 	NULL},
{"cf_sponsor_margin", (getter)Outputs_get_cf_sponsor_margin,(setter)0,
	"Annual developer (lessee) margin [$], array.",
 	NULL},
{"cf_sponsor_me1cs", (getter)Outputs_get_cf_sponsor_me1cs,(setter)0,
	"Reserve capital spending major equipment 1 [$], array.",
 	NULL},
{"cf_sponsor_me1ra", (getter)Outputs_get_cf_sponsor_me1ra,(setter)0,
	"Reserve (increase)/decrease major equipment 1 [$], array.",
 	NULL},
{"cf_sponsor_me2cs", (getter)Outputs_get_cf_sponsor_me2cs,(setter)0,
	"Reserve capital spending major equipment 2 [$], array.",
 	NULL},
{"cf_sponsor_me2ra", (getter)Outputs_get_cf_sponsor_me2ra,(setter)0,
	"Reserve (increase)/decrease major equipment 2 [$], array.",
 	NULL},
{"cf_sponsor_me3cs", (getter)Outputs_get_cf_sponsor_me3cs,(setter)0,
	"Reserve capital spending major equipment 3 [$], array.",
 	NULL},
{"cf_sponsor_me3ra", (getter)Outputs_get_cf_sponsor_me3ra,(setter)0,
	"Reserve (increase)/decrease major equipment 3 [$], array.",
 	NULL},
{"cf_sponsor_mecs", (getter)Outputs_get_cf_sponsor_mecs,(setter)0,
	"Reserve capital spending major equipment total [$], array.",
 	NULL},
{"cf_sponsor_operating_activities", (getter)Outputs_get_cf_sponsor_operating_activities,(setter)0,
	"Cash flow from operating activities [$], array.",
 	NULL},
{"cf_sponsor_operating_margin", (getter)Outputs_get_cf_sponsor_operating_margin,(setter)0,
	"Operating margin not including lease payment [$], array.",
 	NULL},
{"cf_sponsor_pretax", (getter)Outputs_get_cf_sponsor_pretax,(setter)0,
	"Pre-tax developer returns [$], array.",
 	NULL},
{"cf_sponsor_pretax_irr", (getter)Outputs_get_cf_sponsor_pretax_irr,(setter)0,
	"Pre-tax developer cumulative IRR [%], array.",
 	NULL},
{"cf_sponsor_pretax_npv", (getter)Outputs_get_cf_sponsor_pretax_npv,(setter)0,
	"Pre-tax developer cumulative NPV [$], array.",
 	NULL},
{"cf_sponsor_ra", (getter)Outputs_get_cf_sponsor_ra,(setter)0,
	"Reserve (increase)/decrease total [$], array.",
 	NULL},
{"cf_sponsor_receivablesra", (getter)Outputs_get_cf_sponsor_receivablesra,(setter)0,
	"Reserve (increase)/decrease receivables [$], array.",
 	NULL},
{"cf_sponsor_statax", (getter)Outputs_get_cf_sponsor_statax,(setter)0,
	"Developer state tax benefit/(liability) [$], array.",
 	NULL},
{"cf_sponsor_statax_income_prior_incentives", (getter)Outputs_get_cf_sponsor_statax_income_prior_incentives,(setter)0,
	"Developer state taxable income prior incentives [$], array.",
 	NULL},
{"cf_sponsor_statax_income_with_incentives", (getter)Outputs_get_cf_sponsor_statax_income_with_incentives,(setter)0,
	"Developer state taxable income with incentives [$], array.",
 	NULL},
{"cf_sponsor_statax_taxable_incentives", (getter)Outputs_get_cf_sponsor_statax_taxable_incentives,(setter)0,
	"Developer state taxable incentives [$], array.",
 	NULL},
{"cf_sponsor_wcra", (getter)Outputs_get_cf_sponsor_wcra,(setter)0,
	"Reserve (increase)/decrease working capital [$], array.",
 	NULL},
{"cf_stadepr_custom", (getter)Outputs_get_cf_stadepr_custom,(setter)0,
	"State depreciation from custom [$], array.",
 	NULL},
{"cf_stadepr_macrs_15", (getter)Outputs_get_cf_stadepr_macrs_15,(setter)0,
	"State depreciation from 15-yr MACRS [$], array.",
 	NULL},
{"cf_stadepr_macrs_5", (getter)Outputs_get_cf_stadepr_macrs_5,(setter)0,
	"State depreciation from 5-yr MACRS [$], array.",
 	NULL},
{"cf_stadepr_me1", (getter)Outputs_get_cf_stadepr_me1,(setter)0,
	"State depreciation from major equipment 1 [$], array.",
 	NULL},
{"cf_stadepr_me2", (getter)Outputs_get_cf_stadepr_me2,(setter)0,
	"State depreciation from major equipment 2 [$], array.",
 	NULL},
{"cf_stadepr_me3", (getter)Outputs_get_cf_stadepr_me3,(setter)0,
	"State depreciation from major equipment 3 [$], array.",
 	NULL},
{"cf_stadepr_sl_15", (getter)Outputs_get_cf_stadepr_sl_15,(setter)0,
	"State depreciation from 15-yr straight line [$], array.",
 	NULL},
{"cf_stadepr_sl_20", (getter)Outputs_get_cf_stadepr_sl_20,(setter)0,
	"State depreciation from 20-yr straight line [$], array.",
 	NULL},
{"cf_stadepr_sl_39", (getter)Outputs_get_cf_stadepr_sl_39,(setter)0,
	"State depreciation from 39-yr straight line [$], array.",
 	NULL},
{"cf_stadepr_sl_5", (getter)Outputs_get_cf_stadepr_sl_5,(setter)0,
	"State depreciation from 5-yr straight line [$], array.",
 	NULL},
{"cf_stadepr_total", (getter)Outputs_get_cf_stadepr_total,(setter)0,
	"Total state tax depreciation [$], array.",
 	NULL},
{"cf_state_tax_frac", (getter)Outputs_get_cf_state_tax_frac,(setter)0,
	"State income tax rate [frac], array.",
 	NULL},
{"cf_tax_investor_aftertax", (getter)Outputs_get_cf_tax_investor_aftertax,(setter)0,
	"After-tax tax investor returns [$], array.",
 	NULL},
{"cf_tax_investor_aftertax_cash", (getter)Outputs_get_cf_tax_investor_aftertax_cash,(setter)0,
	"After-tax tax investor cash returns [$], array.",
 	NULL},
{"cf_tax_investor_aftertax_irr", (getter)Outputs_get_cf_tax_investor_aftertax_irr,(setter)0,
	"After-tax tax investor cumulative IRR [%], array.",
 	NULL},
{"cf_tax_investor_aftertax_itc", (getter)Outputs_get_cf_tax_investor_aftertax_itc,(setter)0,
	"After-tax tax investor itc returns [$], array.",
 	NULL},
{"cf_tax_investor_aftertax_max_irr", (getter)Outputs_get_cf_tax_investor_aftertax_max_irr,(setter)0,
	"After-tax tax investor maximum IRR [%], array.",
 	NULL},
{"cf_tax_investor_aftertax_npv", (getter)Outputs_get_cf_tax_investor_aftertax_npv,(setter)0,
	"After-tax tax investor cumulative NPV [$], array.",
 	NULL},
{"cf_tax_investor_aftertax_ptc", (getter)Outputs_get_cf_tax_investor_aftertax_ptc,(setter)0,
	"After-tax tax investor ptc returns [$], array.",
 	NULL},
{"cf_tax_investor_aftertax_tax", (getter)Outputs_get_cf_tax_investor_aftertax_tax,(setter)0,
	"After-tax tax investor tax returns [$], array.",
 	NULL},
{"cf_tax_investor_fedtax", (getter)Outputs_get_cf_tax_investor_fedtax,(setter)0,
	"Tax investor federal tax [$], array.",
 	NULL},
{"cf_tax_investor_fedtax_income_prior_incentives", (getter)Outputs_get_cf_tax_investor_fedtax_income_prior_incentives,(setter)0,
	"Tax investor federal taxable income prior to incentives [$], array.",
 	NULL},
{"cf_tax_investor_fedtax_income_with_incentives", (getter)Outputs_get_cf_tax_investor_fedtax_income_with_incentives,(setter)0,
	"Tax investor federal taxable income with incentives [$], array.",
 	NULL},
{"cf_tax_investor_fedtax_taxable_incentives", (getter)Outputs_get_cf_tax_investor_fedtax_taxable_incentives,(setter)0,
	"Tax investor federal taxable incentives [$], array.",
 	NULL},
{"cf_tax_investor_financing_activities", (getter)Outputs_get_cf_tax_investor_financing_activities,(setter)0,
	"Cash flow from financing activities [$], array.",
 	NULL},
{"cf_tax_investor_investing_activities", (getter)Outputs_get_cf_tax_investor_investing_activities,(setter)0,
	"Cash flow from investing activities [$], array.",
 	NULL},
{"cf_tax_investor_operating_activities", (getter)Outputs_get_cf_tax_investor_operating_activities,(setter)0,
	"Cash flow from operating activities [$], array.",
 	NULL},
{"cf_tax_investor_pretax", (getter)Outputs_get_cf_tax_investor_pretax,(setter)0,
	"Pre-tax tax investor returns [$], array.",
 	NULL},
{"cf_tax_investor_pretax_cashflow", (getter)Outputs_get_cf_tax_investor_pretax_cashflow,(setter)0,
	"Pre-tax cash flow [$], array.",
 	NULL},
{"cf_tax_investor_pretax_irr", (getter)Outputs_get_cf_tax_investor_pretax_irr,(setter)0,
	"Pre-tax tax investor cumulative IRR [%], array.",
 	NULL},
{"cf_tax_investor_pretax_npv", (getter)Outputs_get_cf_tax_investor_pretax_npv,(setter)0,
	"Pre-tax tax investor cumulative NPV [$], array.",
 	NULL},
{"cf_tax_investor_statax", (getter)Outputs_get_cf_tax_investor_statax,(setter)0,
	"Tax investor state tax [$], array.",
 	NULL},
{"cf_tax_investor_statax_income_prior_incentives", (getter)Outputs_get_cf_tax_investor_statax_income_prior_incentives,(setter)0,
	"Tax investor state taxable income prior to incentives [$], array.",
 	NULL},
{"cf_tax_investor_statax_income_with_incentives", (getter)Outputs_get_cf_tax_investor_statax_income_with_incentives,(setter)0,
	"Tax investor state taxable income with incentives [$], array.",
 	NULL},
{"cf_tax_investor_statax_taxable_incentives", (getter)Outputs_get_cf_tax_investor_statax_taxable_incentives,(setter)0,
	"Tax investor state taxable incentives [$], array.",
 	NULL},
{"cf_total_revenue", (getter)Outputs_get_cf_total_revenue,(setter)0,
	"Total revenue [$], array.",
 	NULL},
{"cost_financing", (getter)Outputs_get_cost_financing,(setter)0,
	"Financing Cost [$], number.",
 	NULL},
{"cost_installed", (getter)Outputs_get_cost_installed,(setter)0,
	"Initial cost, number.",
 	NULL},
{"cost_installedperwatt", (getter)Outputs_get_cost_installedperwatt,(setter)0,
	"Installed cost per watt [$/W], number.",
 	NULL},
{"debt_fraction", (getter)Outputs_get_debt_fraction,(setter)0,
	"Debt percent [%], number.",
 	NULL},
{"depr_alloc_custom", (getter)Outputs_get_depr_alloc_custom,(setter)0,
	"Custom straight line depreciation federal and state allocation [$], number.",
 	NULL},
{"depr_alloc_macrs_15", (getter)Outputs_get_depr_alloc_macrs_15,(setter)0,
	"15-yr MACRS depreciation federal and state allocation [$], number.",
 	NULL},
{"depr_alloc_macrs_5", (getter)Outputs_get_depr_alloc_macrs_5,(setter)0,
	"5-yr MACRS depreciation federal and state allocation [$], number.",
 	NULL},
{"depr_alloc_none", (getter)Outputs_get_depr_alloc_none,(setter)0,
	"Non-depreciable federal and state allocation [$], number.",
 	NULL},
{"depr_alloc_none_percent", (getter)Outputs_get_depr_alloc_none_percent,(setter)0,
	"Non-depreciable federal and state allocation [%], number.",
 	NULL},
{"depr_alloc_sl_15", (getter)Outputs_get_depr_alloc_sl_15,(setter)0,
	"15-yr straight line depreciation federal and state allocation [$], number.",
 	NULL},
{"depr_alloc_sl_20", (getter)Outputs_get_depr_alloc_sl_20,(setter)0,
	"20-yr straight line depreciation federal and state allocation [$], number.",
 	NULL},
{"depr_alloc_sl_39", (getter)Outputs_get_depr_alloc_sl_39,(setter)0,
	"39-yr straight line depreciation federal and state allocation [$], number.",
 	NULL},
{"depr_alloc_sl_5", (getter)Outputs_get_depr_alloc_sl_5,(setter)0,
	"5-yr straight line depreciation federal and state allocation [$], number.",
 	NULL},
{"depr_alloc_total", (getter)Outputs_get_depr_alloc_total,(setter)0,
	"Total depreciation federal and state allocation [$], number.",
 	NULL},
{"depr_fedbas_after_itc_custom", (getter)Outputs_get_depr_fedbas_after_itc_custom,(setter)0,
	"Custom straight line federal depreciation basis after ITC reduction [$], number.",
 	NULL},
{"depr_fedbas_after_itc_macrs_15", (getter)Outputs_get_depr_fedbas_after_itc_macrs_15,(setter)0,
	"15-yr MACRS federal depreciation basis after ITC reduction [$], number.",
 	NULL},
{"depr_fedbas_after_itc_macrs_5", (getter)Outputs_get_depr_fedbas_after_itc_macrs_5,(setter)0,
	"5-yr MACRS federal depreciation basis after ITC reduction [$], number.",
 	NULL},
{"depr_fedbas_after_itc_sl_15", (getter)Outputs_get_depr_fedbas_after_itc_sl_15,(setter)0,
	"15-yr straight line federal depreciation basis after ITC reduction [$], number.",
 	NULL},
{"depr_fedbas_after_itc_sl_20", (getter)Outputs_get_depr_fedbas_after_itc_sl_20,(setter)0,
	"20-yr straight line federal depreciation basis after ITC reduction [$], number.",
 	NULL},
{"depr_fedbas_after_itc_sl_39", (getter)Outputs_get_depr_fedbas_after_itc_sl_39,(setter)0,
	"39-yr straight line federal depreciation basis after ITC reduction [$], number.",
 	NULL},
{"depr_fedbas_after_itc_sl_5", (getter)Outputs_get_depr_fedbas_after_itc_sl_5,(setter)0,
	"5-yr straight line federal depreciation basis after ITC reduction [$], number.",
 	NULL},
{"depr_fedbas_after_itc_total", (getter)Outputs_get_depr_fedbas_after_itc_total,(setter)0,
	"Total federal depreciation basis after ITC reduction [$], number.",
 	NULL},
{"depr_fedbas_cbi_reduc_custom", (getter)Outputs_get_depr_fedbas_cbi_reduc_custom,(setter)0,
	"Custom straight line federal cbi reduction [$], number.",
 	NULL},
{"depr_fedbas_cbi_reduc_macrs_15", (getter)Outputs_get_depr_fedbas_cbi_reduc_macrs_15,(setter)0,
	"15-yr MACRS federal cbi reduction [$], number.",
 	NULL},
{"depr_fedbas_cbi_reduc_macrs_5", (getter)Outputs_get_depr_fedbas_cbi_reduc_macrs_5,(setter)0,
	"5-yr MACRS federal cbi reduction [$], number.",
 	NULL},
{"depr_fedbas_cbi_reduc_sl_15", (getter)Outputs_get_depr_fedbas_cbi_reduc_sl_15,(setter)0,
	"15-yr straight line federal cbi reduction [$], number.",
 	NULL},
{"depr_fedbas_cbi_reduc_sl_20", (getter)Outputs_get_depr_fedbas_cbi_reduc_sl_20,(setter)0,
	"20-yr straight line federal cbi reduction [$], number.",
 	NULL},
{"depr_fedbas_cbi_reduc_sl_39", (getter)Outputs_get_depr_fedbas_cbi_reduc_sl_39,(setter)0,
	"39-yr straight line federal cbi reduction [$], number.",
 	NULL},
{"depr_fedbas_cbi_reduc_sl_5", (getter)Outputs_get_depr_fedbas_cbi_reduc_sl_5,(setter)0,
	"5-yr straight line federal cbi reduction [$], number.",
 	NULL},
{"depr_fedbas_cbi_reduc_total", (getter)Outputs_get_depr_fedbas_cbi_reduc_total,(setter)0,
	"Total federal cbi reduction [$], number.",
 	NULL},
{"depr_fedbas_custom", (getter)Outputs_get_depr_fedbas_custom,(setter)0,
	"Custom straight line federal depreciation basis [$], number.",
 	NULL},
{"depr_fedbas_first_year_bonus_custom", (getter)Outputs_get_depr_fedbas_first_year_bonus_custom,(setter)0,
	"Custom straight line federal first year bonus depreciation [$], number.",
 	NULL},
{"depr_fedbas_first_year_bonus_macrs_15", (getter)Outputs_get_depr_fedbas_first_year_bonus_macrs_15,(setter)0,
	"15-yr MACRS federal first year bonus depreciation [$], number.",
 	NULL},
{"depr_fedbas_first_year_bonus_macrs_5", (getter)Outputs_get_depr_fedbas_first_year_bonus_macrs_5,(setter)0,
	"5-yr MACRS federal first year bonus depreciation [$], number.",
 	NULL},
{"depr_fedbas_first_year_bonus_sl_15", (getter)Outputs_get_depr_fedbas_first_year_bonus_sl_15,(setter)0,
	"15-yr straight line federal first year bonus depreciation [$], number.",
 	NULL},
{"depr_fedbas_first_year_bonus_sl_20", (getter)Outputs_get_depr_fedbas_first_year_bonus_sl_20,(setter)0,
	"20-yr straight line federal first year bonus depreciation [$], number.",
 	NULL},
{"depr_fedbas_first_year_bonus_sl_39", (getter)Outputs_get_depr_fedbas_first_year_bonus_sl_39,(setter)0,
	"39-yr straight line federal first year bonus depreciation [$], number.",
 	NULL},
{"depr_fedbas_first_year_bonus_sl_5", (getter)Outputs_get_depr_fedbas_first_year_bonus_sl_5,(setter)0,
	"5-yr straight line federal first year bonus depreciation [$], number.",
 	NULL},
{"depr_fedbas_first_year_bonus_total", (getter)Outputs_get_depr_fedbas_first_year_bonus_total,(setter)0,
	"Total federal first year bonus depreciation [$], number.",
 	NULL},
{"depr_fedbas_fixed_amount_custom", (getter)Outputs_get_depr_fedbas_fixed_amount_custom,(setter)0,
	"Custom straight line depreciation ITC basis from federal fixed amount [$], number.",
 	NULL},
{"depr_fedbas_fixed_amount_macrs_15", (getter)Outputs_get_depr_fedbas_fixed_amount_macrs_15,(setter)0,
	"15-yr MACRS depreciation ITC basis from federal fixed amount [$], number.",
 	NULL},
{"depr_fedbas_fixed_amount_macrs_5", (getter)Outputs_get_depr_fedbas_fixed_amount_macrs_5,(setter)0,
	"5-yr MACRS depreciation ITC basis from federal fixed amount [$], number.",
 	NULL},
{"depr_fedbas_fixed_amount_sl_15", (getter)Outputs_get_depr_fedbas_fixed_amount_sl_15,(setter)0,
	"15-yr straight line depreciation ITC basis from federal fixed amount [$], number.",
 	NULL},
{"depr_fedbas_fixed_amount_sl_20", (getter)Outputs_get_depr_fedbas_fixed_amount_sl_20,(setter)0,
	"20-yr straight line depreciation ITC basis from federal fixed amount [$], number.",
 	NULL},
{"depr_fedbas_fixed_amount_sl_39", (getter)Outputs_get_depr_fedbas_fixed_amount_sl_39,(setter)0,
	"39-yr straight line depreciation ITC basis from federal fixed amount [$], number.",
 	NULL},
{"depr_fedbas_fixed_amount_sl_5", (getter)Outputs_get_depr_fedbas_fixed_amount_sl_5,(setter)0,
	"5-yr straight line depreciation ITC basis from federal fixed amount [$], number.",
 	NULL},
{"depr_fedbas_fixed_amount_total", (getter)Outputs_get_depr_fedbas_fixed_amount_total,(setter)0,
	"Total depreciation ITC basis from federal fixed amount [$], number.",
 	NULL},
{"depr_fedbas_ibi_reduc_custom", (getter)Outputs_get_depr_fedbas_ibi_reduc_custom,(setter)0,
	"Custom straight line federal ibi reduction [$], number.",
 	NULL},
{"depr_fedbas_ibi_reduc_macrs_15", (getter)Outputs_get_depr_fedbas_ibi_reduc_macrs_15,(setter)0,
	"15-yr MACRS federal ibi reduction [$], number.",
 	NULL},
{"depr_fedbas_ibi_reduc_macrs_5", (getter)Outputs_get_depr_fedbas_ibi_reduc_macrs_5,(setter)0,
	"5-yr MACRS federal ibi reduction [$], number.",
 	NULL},
{"depr_fedbas_ibi_reduc_sl_15", (getter)Outputs_get_depr_fedbas_ibi_reduc_sl_15,(setter)0,
	"15-yr straight line federal ibi reduction [$], number.",
 	NULL},
{"depr_fedbas_ibi_reduc_sl_20", (getter)Outputs_get_depr_fedbas_ibi_reduc_sl_20,(setter)0,
	"20-yr straight line federal ibi reduction [$], number.",
 	NULL},
{"depr_fedbas_ibi_reduc_sl_39", (getter)Outputs_get_depr_fedbas_ibi_reduc_sl_39,(setter)0,
	"39-yr straight line federal ibi reduction [$], number.",
 	NULL},
{"depr_fedbas_ibi_reduc_sl_5", (getter)Outputs_get_depr_fedbas_ibi_reduc_sl_5,(setter)0,
	"5-yr straight line federal ibi reduction [$], number.",
 	NULL},
{"depr_fedbas_ibi_reduc_total", (getter)Outputs_get_depr_fedbas_ibi_reduc_total,(setter)0,
	"Total federal ibi reduction [$], number.",
 	NULL},
{"depr_fedbas_itc_fed_reduction_custom", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_custom,(setter)0,
	"Custom straight line federal basis federal ITC reduciton [$], number.",
 	NULL},
{"depr_fedbas_itc_fed_reduction_macrs_15", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_macrs_15,(setter)0,
	"15-yr MACRS federal basis federal ITC reduciton [$], number.",
 	NULL},
{"depr_fedbas_itc_fed_reduction_macrs_5", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_macrs_5,(setter)0,
	"5-yr MACRS federal basis federal ITC reduciton [$], number.",
 	NULL},
{"depr_fedbas_itc_fed_reduction_sl_15", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_sl_15,(setter)0,
	"15-yr straight line federal basis federal ITC reduciton [$], number.",
 	NULL},
{"depr_fedbas_itc_fed_reduction_sl_20", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_sl_20,(setter)0,
	"20-yr straight line federal basis federal ITC reduciton [$], number.",
 	NULL},
{"depr_fedbas_itc_fed_reduction_sl_39", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_sl_39,(setter)0,
	"39-yr straight line federal basis federal ITC reduciton [$], number.",
 	NULL},
{"depr_fedbas_itc_fed_reduction_sl_5", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_sl_5,(setter)0,
	"5-yr straight line federal basis federal ITC reduciton [$], number.",
 	NULL},
{"depr_fedbas_itc_fed_reduction_total", (getter)Outputs_get_depr_fedbas_itc_fed_reduction_total,(setter)0,
	"Total federal basis federal ITC reduciton [$], number.",
 	NULL},
{"depr_fedbas_itc_sta_reduction_custom", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_custom,(setter)0,
	"Custom straight line federal basis state ITC reduciton [$], number.",
 	NULL},
{"depr_fedbas_itc_sta_reduction_macrs_15", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_macrs_15,(setter)0,
	"15-yr MACRS federal basis state ITC reduciton [$], number.",
 	NULL},
{"depr_fedbas_itc_sta_reduction_macrs_5", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_macrs_5,(setter)0,
	"5-yr MACRS federal basis state ITC reduciton [$], number.",
 	NULL},
{"depr_fedbas_itc_sta_reduction_sl_15", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_sl_15,(setter)0,
	"15-yr straight line federal basis state ITC reduciton [$], number.",
 	NULL},
{"depr_fedbas_itc_sta_reduction_sl_20", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_sl_20,(setter)0,
	"20-yr straight line federal basis state ITC reduciton [$], number.",
 	NULL},
{"depr_fedbas_itc_sta_reduction_sl_39", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_sl_39,(setter)0,
	"39-yr straight line federal basis state ITC reduciton [$], number.",
 	NULL},
{"depr_fedbas_itc_sta_reduction_sl_5", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_sl_5,(setter)0,
	"5-yr straight line federal basis state ITC reduciton [$], number.",
 	NULL},
{"depr_fedbas_itc_sta_reduction_total", (getter)Outputs_get_depr_fedbas_itc_sta_reduction_total,(setter)0,
	"Total federal basis state ITC reduciton [$], number.",
 	NULL},
{"depr_fedbas_macrs_15", (getter)Outputs_get_depr_fedbas_macrs_15,(setter)0,
	"15-yr MACRS federal depreciation basis [$], number.",
 	NULL},
{"depr_fedbas_macrs_5", (getter)Outputs_get_depr_fedbas_macrs_5,(setter)0,
	"5-yr MACRS federal depreciation basis [$], number.",
 	NULL},
{"depr_fedbas_percent_amount_custom", (getter)Outputs_get_depr_fedbas_percent_amount_custom,(setter)0,
	"Custom straight line depreciation ITC basis from federal percentage [$], number.",
 	NULL},
{"depr_fedbas_percent_amount_macrs_15", (getter)Outputs_get_depr_fedbas_percent_amount_macrs_15,(setter)0,
	"15-yr MACRS depreciation ITC basis from federal percentage [$], number.",
 	NULL},
{"depr_fedbas_percent_amount_macrs_5", (getter)Outputs_get_depr_fedbas_percent_amount_macrs_5,(setter)0,
	"5-yr MACRS depreciation ITC basis from federal percentage [$], number.",
 	NULL},
{"depr_fedbas_percent_amount_sl_15", (getter)Outputs_get_depr_fedbas_percent_amount_sl_15,(setter)0,
	"15-yr straight line depreciation ITC basis from federal percentage [$], number.",
 	NULL},
{"depr_fedbas_percent_amount_sl_20", (getter)Outputs_get_depr_fedbas_percent_amount_sl_20,(setter)0,
	"20-yr straight line depreciation ITC basis from federal percentage [$], number.",
 	NULL},
{"depr_fedbas_percent_amount_sl_39", (getter)Outputs_get_depr_fedbas_percent_amount_sl_39,(setter)0,
	"39-yr straight line depreciation ITC basis from federal percentage [$], number.",
 	NULL},
{"depr_fedbas_percent_amount_sl_5", (getter)Outputs_get_depr_fedbas_percent_amount_sl_5,(setter)0,
	"5-yr straight line depreciation ITC basis from federal percentage [$], number.",
 	NULL},
{"depr_fedbas_percent_amount_total", (getter)Outputs_get_depr_fedbas_percent_amount_total,(setter)0,
	"Total depreciation ITC basis from federal percentage [$], number.",
 	NULL},
{"depr_fedbas_percent_custom", (getter)Outputs_get_depr_fedbas_percent_custom,(setter)0,
	"Custom straight line federal percent of total depreciable basis [%], number.",
 	NULL},
{"depr_fedbas_percent_macrs_15", (getter)Outputs_get_depr_fedbas_percent_macrs_15,(setter)0,
	"15-yr MACRS federal percent of total depreciable basis [%], number.",
 	NULL},
{"depr_fedbas_percent_macrs_5", (getter)Outputs_get_depr_fedbas_percent_macrs_5,(setter)0,
	"5-yr MACRS federal percent of total depreciable basis [%], number.",
 	NULL},
{"depr_fedbas_percent_qual_custom", (getter)Outputs_get_depr_fedbas_percent_qual_custom,(setter)0,
	"Custom straight line federal percent of qualifying costs [%], number.",
 	NULL},
{"depr_fedbas_percent_qual_macrs_15", (getter)Outputs_get_depr_fedbas_percent_qual_macrs_15,(setter)0,
	"15-yr MACRS federal percent of qualifying costs [%], number.",
 	NULL},
{"depr_fedbas_percent_qual_macrs_5", (getter)Outputs_get_depr_fedbas_percent_qual_macrs_5,(setter)0,
	"5-yr MACRS federal percent of qualifying costs [%], number.",
 	NULL},
{"depr_fedbas_percent_qual_sl_15", (getter)Outputs_get_depr_fedbas_percent_qual_sl_15,(setter)0,
	"15-yr straight line federal percent of qualifying costs [%], number.",
 	NULL},
{"depr_fedbas_percent_qual_sl_20", (getter)Outputs_get_depr_fedbas_percent_qual_sl_20,(setter)0,
	"20-yr straight line federal percent of qualifying costs [%], number.",
 	NULL},
{"depr_fedbas_percent_qual_sl_39", (getter)Outputs_get_depr_fedbas_percent_qual_sl_39,(setter)0,
	"39-yr straight line federal percent of qualifying costs [%], number.",
 	NULL},
{"depr_fedbas_percent_qual_sl_5", (getter)Outputs_get_depr_fedbas_percent_qual_sl_5,(setter)0,
	"5-yr straight line federal percent of qualifying costs [%], number.",
 	NULL},
{"depr_fedbas_percent_qual_total", (getter)Outputs_get_depr_fedbas_percent_qual_total,(setter)0,
	"Total federal percent of qualifying costs [%], number.",
 	NULL},
{"depr_fedbas_percent_sl_15", (getter)Outputs_get_depr_fedbas_percent_sl_15,(setter)0,
	"15-yr straight line federal percent of total depreciable basis [%], number.",
 	NULL},
{"depr_fedbas_percent_sl_20", (getter)Outputs_get_depr_fedbas_percent_sl_20,(setter)0,
	"20-yr straight line federal percent of total depreciable basis [%], number.",
 	NULL},
{"depr_fedbas_percent_sl_39", (getter)Outputs_get_depr_fedbas_percent_sl_39,(setter)0,
	"39-yr straight line federal percent of total depreciable basis [%], number.",
 	NULL},
{"depr_fedbas_percent_sl_5", (getter)Outputs_get_depr_fedbas_percent_sl_5,(setter)0,
	"5-yr straight line federal percent of total depreciable basis [%], number.",
 	NULL},
{"depr_fedbas_percent_total", (getter)Outputs_get_depr_fedbas_percent_total,(setter)0,
	"Total federal percent of total depreciable basis [%], number.",
 	NULL},
{"depr_fedbas_prior_itc_custom", (getter)Outputs_get_depr_fedbas_prior_itc_custom,(setter)0,
	"Custom straight line federal depreciation basis prior ITC reduction [$], number.",
 	NULL},
{"depr_fedbas_prior_itc_macrs_15", (getter)Outputs_get_depr_fedbas_prior_itc_macrs_15,(setter)0,
	"15-yr MACRS federal depreciation basis prior ITC reduction [$], number.",
 	NULL},
{"depr_fedbas_prior_itc_macrs_5", (getter)Outputs_get_depr_fedbas_prior_itc_macrs_5,(setter)0,
	"5-yr MACRS federal depreciation basis prior ITC reduction [$], number.",
 	NULL},
{"depr_fedbas_prior_itc_sl_15", (getter)Outputs_get_depr_fedbas_prior_itc_sl_15,(setter)0,
	"15-yr straight line federal depreciation basis prior ITC reduction [$], number.",
 	NULL},
{"depr_fedbas_prior_itc_sl_20", (getter)Outputs_get_depr_fedbas_prior_itc_sl_20,(setter)0,
	"20-yr straight line federal depreciation basis prior ITC reduction [$], number.",
 	NULL},
{"depr_fedbas_prior_itc_sl_39", (getter)Outputs_get_depr_fedbas_prior_itc_sl_39,(setter)0,
	"39-yr straight line federal depreciation basis prior ITC reduction [$], number.",
 	NULL},
{"depr_fedbas_prior_itc_sl_5", (getter)Outputs_get_depr_fedbas_prior_itc_sl_5,(setter)0,
	"5-yr straight line federal depreciation basis prior ITC reduction [$], number.",
 	NULL},
{"depr_fedbas_prior_itc_total", (getter)Outputs_get_depr_fedbas_prior_itc_total,(setter)0,
	"Total federal depreciation basis prior ITC reduction [$], number.",
 	NULL},
{"depr_fedbas_sl_15", (getter)Outputs_get_depr_fedbas_sl_15,(setter)0,
	"15-yr straight line federal depreciation basis [$], number.",
 	NULL},
{"depr_fedbas_sl_20", (getter)Outputs_get_depr_fedbas_sl_20,(setter)0,
	"20-yr straight line federal depreciation basis [$], number.",
 	NULL},
{"depr_fedbas_sl_39", (getter)Outputs_get_depr_fedbas_sl_39,(setter)0,
	"39-yr straight line federal depreciation basis [$], number.",
 	NULL},
{"depr_fedbas_sl_5", (getter)Outputs_get_depr_fedbas_sl_5,(setter)0,
	"5-yr straight line federal depreciation basis [$], number.",
 	NULL},
{"depr_fedbas_total", (getter)Outputs_get_depr_fedbas_total,(setter)0,
	"Total federal depreciation basis [$], number.",
 	NULL},
{"depr_stabas_after_itc_custom", (getter)Outputs_get_depr_stabas_after_itc_custom,(setter)0,
	"Custom straight line state depreciation basis after ITC reduction [$], number.",
 	NULL},
{"depr_stabas_after_itc_macrs_15", (getter)Outputs_get_depr_stabas_after_itc_macrs_15,(setter)0,
	"15-yr MACRS state depreciation basis after ITC reduction [$], number.",
 	NULL},
{"depr_stabas_after_itc_macrs_5", (getter)Outputs_get_depr_stabas_after_itc_macrs_5,(setter)0,
	"5-yr MACRS state depreciation basis after ITC reduction [$], number.",
 	NULL},
{"depr_stabas_after_itc_sl_15", (getter)Outputs_get_depr_stabas_after_itc_sl_15,(setter)0,
	"15-yr straight line state depreciation basis after ITC reduction [$], number.",
 	NULL},
{"depr_stabas_after_itc_sl_20", (getter)Outputs_get_depr_stabas_after_itc_sl_20,(setter)0,
	"20-yr straight line state depreciation basis after ITC reduction [$], number.",
 	NULL},
{"depr_stabas_after_itc_sl_39", (getter)Outputs_get_depr_stabas_after_itc_sl_39,(setter)0,
	"39-yr straight line state depreciation basis after ITC reduction [$], number.",
 	NULL},
{"depr_stabas_after_itc_sl_5", (getter)Outputs_get_depr_stabas_after_itc_sl_5,(setter)0,
	"5-yr straight line state depreciation basis after ITC reduction [$], number.",
 	NULL},
{"depr_stabas_after_itc_total", (getter)Outputs_get_depr_stabas_after_itc_total,(setter)0,
	"Total state depreciation basis after ITC reduction [$], number.",
 	NULL},
{"depr_stabas_cbi_reduc_custom", (getter)Outputs_get_depr_stabas_cbi_reduc_custom,(setter)0,
	"Custom straight line state cbi reduction [$], number.",
 	NULL},
{"depr_stabas_cbi_reduc_macrs_15", (getter)Outputs_get_depr_stabas_cbi_reduc_macrs_15,(setter)0,
	"15-yr MACRS state cbi reduction [$], number.",
 	NULL},
{"depr_stabas_cbi_reduc_macrs_5", (getter)Outputs_get_depr_stabas_cbi_reduc_macrs_5,(setter)0,
	"5-yr MACRS state cbi reduction [$], number.",
 	NULL},
{"depr_stabas_cbi_reduc_sl_15", (getter)Outputs_get_depr_stabas_cbi_reduc_sl_15,(setter)0,
	"15-yr straight line state cbi reduction [$], number.",
 	NULL},
{"depr_stabas_cbi_reduc_sl_20", (getter)Outputs_get_depr_stabas_cbi_reduc_sl_20,(setter)0,
	"20-yr straight line state cbi reduction [$], number.",
 	NULL},
{"depr_stabas_cbi_reduc_sl_39", (getter)Outputs_get_depr_stabas_cbi_reduc_sl_39,(setter)0,
	"39-yr straight line state cbi reduction [$], number.",
 	NULL},
{"depr_stabas_cbi_reduc_sl_5", (getter)Outputs_get_depr_stabas_cbi_reduc_sl_5,(setter)0,
	"5-yr straight line state cbi reduction [$], number.",
 	NULL},
{"depr_stabas_cbi_reduc_total", (getter)Outputs_get_depr_stabas_cbi_reduc_total,(setter)0,
	"Total state cbi reduction [$], number.",
 	NULL},
{"depr_stabas_custom", (getter)Outputs_get_depr_stabas_custom,(setter)0,
	"Custom straight line state depreciation basis [$], number.",
 	NULL},
{"depr_stabas_first_year_bonus_custom", (getter)Outputs_get_depr_stabas_first_year_bonus_custom,(setter)0,
	"Custom straight line state first year bonus depreciation [$], number.",
 	NULL},
{"depr_stabas_first_year_bonus_macrs_15", (getter)Outputs_get_depr_stabas_first_year_bonus_macrs_15,(setter)0,
	"15-yr MACRS state first year bonus depreciation [$], number.",
 	NULL},
{"depr_stabas_first_year_bonus_macrs_5", (getter)Outputs_get_depr_stabas_first_year_bonus_macrs_5,(setter)0,
	"5-yr MACRS state first year bonus depreciation [$], number.",
 	NULL},
{"depr_stabas_first_year_bonus_sl_15", (getter)Outputs_get_depr_stabas_first_year_bonus_sl_15,(setter)0,
	"15-yr straight line state first year bonus depreciation [$], number.",
 	NULL},
{"depr_stabas_first_year_bonus_sl_20", (getter)Outputs_get_depr_stabas_first_year_bonus_sl_20,(setter)0,
	"20-yr straight line state first year bonus depreciation [$], number.",
 	NULL},
{"depr_stabas_first_year_bonus_sl_39", (getter)Outputs_get_depr_stabas_first_year_bonus_sl_39,(setter)0,
	"39-yr straight line state first year bonus depreciation [$], number.",
 	NULL},
{"depr_stabas_first_year_bonus_sl_5", (getter)Outputs_get_depr_stabas_first_year_bonus_sl_5,(setter)0,
	"5-yr straight line state first year bonus depreciation [$], number.",
 	NULL},
{"depr_stabas_first_year_bonus_total", (getter)Outputs_get_depr_stabas_first_year_bonus_total,(setter)0,
	"Total state first year bonus depreciation [$], number.",
 	NULL},
{"depr_stabas_fixed_amount_custom", (getter)Outputs_get_depr_stabas_fixed_amount_custom,(setter)0,
	"Custom straight line depreciation ITC basis from state fixed amount [$], number.",
 	NULL},
{"depr_stabas_fixed_amount_macrs_15", (getter)Outputs_get_depr_stabas_fixed_amount_macrs_15,(setter)0,
	"15-yr MACRS depreciation ITC basis from state fixed amount [$], number.",
 	NULL},
{"depr_stabas_fixed_amount_macrs_5", (getter)Outputs_get_depr_stabas_fixed_amount_macrs_5,(setter)0,
	"5-yr MACRS depreciation ITC basis from state fixed amount [$], number.",
 	NULL},
{"depr_stabas_fixed_amount_sl_15", (getter)Outputs_get_depr_stabas_fixed_amount_sl_15,(setter)0,
	"15-yr straight line depreciation ITC basis from state fixed amount [$], number.",
 	NULL},
{"depr_stabas_fixed_amount_sl_20", (getter)Outputs_get_depr_stabas_fixed_amount_sl_20,(setter)0,
	"20-yr straight line depreciation ITC basis from state fixed amount [$], number.",
 	NULL},
{"depr_stabas_fixed_amount_sl_39", (getter)Outputs_get_depr_stabas_fixed_amount_sl_39,(setter)0,
	"39-yr straight line depreciation ITC basis from state fixed amount [$], number.",
 	NULL},
{"depr_stabas_fixed_amount_sl_5", (getter)Outputs_get_depr_stabas_fixed_amount_sl_5,(setter)0,
	"5-yr straight line depreciation ITC basis from state fixed amount [$], number.",
 	NULL},
{"depr_stabas_fixed_amount_total", (getter)Outputs_get_depr_stabas_fixed_amount_total,(setter)0,
	"Total depreciation ITC basis from state fixed amount [$], number.",
 	NULL},
{"depr_stabas_ibi_reduc_custom", (getter)Outputs_get_depr_stabas_ibi_reduc_custom,(setter)0,
	"Custom straight line state ibi reduction [$], number.",
 	NULL},
{"depr_stabas_ibi_reduc_macrs_15", (getter)Outputs_get_depr_stabas_ibi_reduc_macrs_15,(setter)0,
	"15-yr MACRS state ibi reduction [$], number.",
 	NULL},
{"depr_stabas_ibi_reduc_macrs_5", (getter)Outputs_get_depr_stabas_ibi_reduc_macrs_5,(setter)0,
	"5-yr MACRS state ibi reduction [$], number.",
 	NULL},
{"depr_stabas_ibi_reduc_sl_15", (getter)Outputs_get_depr_stabas_ibi_reduc_sl_15,(setter)0,
	"15-yr straight line state ibi reduction [$], number.",
 	NULL},
{"depr_stabas_ibi_reduc_sl_20", (getter)Outputs_get_depr_stabas_ibi_reduc_sl_20,(setter)0,
	"20-yr straight line state ibi reduction [$], number.",
 	NULL},
{"depr_stabas_ibi_reduc_sl_39", (getter)Outputs_get_depr_stabas_ibi_reduc_sl_39,(setter)0,
	"39-yr straight line state ibi reduction [$], number.",
 	NULL},
{"depr_stabas_ibi_reduc_sl_5", (getter)Outputs_get_depr_stabas_ibi_reduc_sl_5,(setter)0,
	"5-yr straight line state ibi reduction [$], number.",
 	NULL},
{"depr_stabas_ibi_reduc_total", (getter)Outputs_get_depr_stabas_ibi_reduc_total,(setter)0,
	"Total state ibi reduction [$], number.",
 	NULL},
{"depr_stabas_itc_fed_reduction_custom", (getter)Outputs_get_depr_stabas_itc_fed_reduction_custom,(setter)0,
	"Custom straight line state basis federal ITC reduciton [$], number.",
 	NULL},
{"depr_stabas_itc_fed_reduction_macrs_15", (getter)Outputs_get_depr_stabas_itc_fed_reduction_macrs_15,(setter)0,
	"15-yr MACRS state basis federal ITC reduciton [$], number.",
 	NULL},
{"depr_stabas_itc_fed_reduction_macrs_5", (getter)Outputs_get_depr_stabas_itc_fed_reduction_macrs_5,(setter)0,
	"5-yr MACRS state basis federal ITC reduciton [$], number.",
 	NULL},
{"depr_stabas_itc_fed_reduction_sl_15", (getter)Outputs_get_depr_stabas_itc_fed_reduction_sl_15,(setter)0,
	"15-yr straight line state basis federal ITC reduciton [$], number.",
 	NULL},
{"depr_stabas_itc_fed_reduction_sl_20", (getter)Outputs_get_depr_stabas_itc_fed_reduction_sl_20,(setter)0,
	"20-yr straight line state basis federal ITC reduciton [$], number.",
 	NULL},
{"depr_stabas_itc_fed_reduction_sl_39", (getter)Outputs_get_depr_stabas_itc_fed_reduction_sl_39,(setter)0,
	"39-yr straight line state basis federal ITC reduciton [$], number.",
 	NULL},
{"depr_stabas_itc_fed_reduction_sl_5", (getter)Outputs_get_depr_stabas_itc_fed_reduction_sl_5,(setter)0,
	"5-yr straight line state basis federal ITC reduciton [$], number.",
 	NULL},
{"depr_stabas_itc_fed_reduction_total", (getter)Outputs_get_depr_stabas_itc_fed_reduction_total,(setter)0,
	"Total state basis federal ITC reduciton [$], number.",
 	NULL},
{"depr_stabas_itc_sta_reduction_custom", (getter)Outputs_get_depr_stabas_itc_sta_reduction_custom,(setter)0,
	"Custom straight line state basis state ITC reduciton [$], number.",
 	NULL},
{"depr_stabas_itc_sta_reduction_macrs_15", (getter)Outputs_get_depr_stabas_itc_sta_reduction_macrs_15,(setter)0,
	"15-yr MACRS state basis state ITC reduciton [$], number.",
 	NULL},
{"depr_stabas_itc_sta_reduction_macrs_5", (getter)Outputs_get_depr_stabas_itc_sta_reduction_macrs_5,(setter)0,
	"5-yr MACRS state basis state ITC reduciton [$], number.",
 	NULL},
{"depr_stabas_itc_sta_reduction_sl_15", (getter)Outputs_get_depr_stabas_itc_sta_reduction_sl_15,(setter)0,
	"15-yr straight line state basis state ITC reduciton [$], number.",
 	NULL},
{"depr_stabas_itc_sta_reduction_sl_20", (getter)Outputs_get_depr_stabas_itc_sta_reduction_sl_20,(setter)0,
	"20-yr straight line state basis state ITC reduciton [$], number.",
 	NULL},
{"depr_stabas_itc_sta_reduction_sl_39", (getter)Outputs_get_depr_stabas_itc_sta_reduction_sl_39,(setter)0,
	"39-yr straight line state basis state ITC reduciton [$], number.",
 	NULL},
{"depr_stabas_itc_sta_reduction_sl_5", (getter)Outputs_get_depr_stabas_itc_sta_reduction_sl_5,(setter)0,
	"5-yr straight line state basis state ITC reduciton [$], number.",
 	NULL},
{"depr_stabas_itc_sta_reduction_total", (getter)Outputs_get_depr_stabas_itc_sta_reduction_total,(setter)0,
	"Total state basis state ITC reduciton [$], number.",
 	NULL},
{"depr_stabas_macrs_15", (getter)Outputs_get_depr_stabas_macrs_15,(setter)0,
	"15-yr MACRS state depreciation basis [$], number.",
 	NULL},
{"depr_stabas_macrs_5", (getter)Outputs_get_depr_stabas_macrs_5,(setter)0,
	"5-yr MACRS state depreciation basis [$], number.",
 	NULL},
{"depr_stabas_percent_amount_custom", (getter)Outputs_get_depr_stabas_percent_amount_custom,(setter)0,
	"Custom straight line depreciation ITC basis from state percentage [$], number.",
 	NULL},
{"depr_stabas_percent_amount_macrs_15", (getter)Outputs_get_depr_stabas_percent_amount_macrs_15,(setter)0,
	"15-yr MACRS depreciation ITC basis from state percentage [$], number.",
 	NULL},
{"depr_stabas_percent_amount_macrs_5", (getter)Outputs_get_depr_stabas_percent_amount_macrs_5,(setter)0,
	"5-yr MACRS depreciation ITC basis from state percentage [$], number.",
 	NULL},
{"depr_stabas_percent_amount_sl_15", (getter)Outputs_get_depr_stabas_percent_amount_sl_15,(setter)0,
	"15-yr straight line depreciation ITC basis from state percentage [$], number.",
 	NULL},
{"depr_stabas_percent_amount_sl_20", (getter)Outputs_get_depr_stabas_percent_amount_sl_20,(setter)0,
	"20-yr straight line depreciation ITC basis from state percentage [$], number.",
 	NULL},
{"depr_stabas_percent_amount_sl_39", (getter)Outputs_get_depr_stabas_percent_amount_sl_39,(setter)0,
	"39-yr straight line depreciation ITC basis from state percentage [$], number.",
 	NULL},
{"depr_stabas_percent_amount_sl_5", (getter)Outputs_get_depr_stabas_percent_amount_sl_5,(setter)0,
	"5-yr straight line depreciation ITC basis from state percentage [$], number.",
 	NULL},
{"depr_stabas_percent_amount_total", (getter)Outputs_get_depr_stabas_percent_amount_total,(setter)0,
	"Total depreciation ITC basis from state percentage [$], number.",
 	NULL},
{"depr_stabas_percent_custom", (getter)Outputs_get_depr_stabas_percent_custom,(setter)0,
	"Custom straight line state percent of total depreciable basis [%], number.",
 	NULL},
{"depr_stabas_percent_macrs_15", (getter)Outputs_get_depr_stabas_percent_macrs_15,(setter)0,
	"15-yr MACRS state percent of total depreciable basis [%], number.",
 	NULL},
{"depr_stabas_percent_macrs_5", (getter)Outputs_get_depr_stabas_percent_macrs_5,(setter)0,
	"5-yr MACRS state percent of total depreciable basis [%], number.",
 	NULL},
{"depr_stabas_percent_qual_custom", (getter)Outputs_get_depr_stabas_percent_qual_custom,(setter)0,
	"Custom straight line state percent of qualifying costs [%], number.",
 	NULL},
{"depr_stabas_percent_qual_macrs_15", (getter)Outputs_get_depr_stabas_percent_qual_macrs_15,(setter)0,
	"15-yr MACRS state percent of qualifying costs [%], number.",
 	NULL},
{"depr_stabas_percent_qual_macrs_5", (getter)Outputs_get_depr_stabas_percent_qual_macrs_5,(setter)0,
	"5-yr MACRS state percent of qualifying costs [%], number.",
 	NULL},
{"depr_stabas_percent_qual_sl_15", (getter)Outputs_get_depr_stabas_percent_qual_sl_15,(setter)0,
	"15-yr straight line state percent of qualifying costs [%], number.",
 	NULL},
{"depr_stabas_percent_qual_sl_20", (getter)Outputs_get_depr_stabas_percent_qual_sl_20,(setter)0,
	"20-yr straight line state percent of qualifying costs [%], number.",
 	NULL},
{"depr_stabas_percent_qual_sl_39", (getter)Outputs_get_depr_stabas_percent_qual_sl_39,(setter)0,
	"39-yr straight line state percent of qualifying costs [%], number.",
 	NULL},
{"depr_stabas_percent_qual_sl_5", (getter)Outputs_get_depr_stabas_percent_qual_sl_5,(setter)0,
	"5-yr straight line state percent of qualifying costs [%], number.",
 	NULL},
{"depr_stabas_percent_qual_total", (getter)Outputs_get_depr_stabas_percent_qual_total,(setter)0,
	"Total state percent of qualifying costs [%], number.",
 	NULL},
{"depr_stabas_percent_sl_15", (getter)Outputs_get_depr_stabas_percent_sl_15,(setter)0,
	"15-yr straight line state percent of total depreciable basis [%], number.",
 	NULL},
{"depr_stabas_percent_sl_20", (getter)Outputs_get_depr_stabas_percent_sl_20,(setter)0,
	"20-yr straight line state percent of total depreciable basis [%], number.",
 	NULL},
{"depr_stabas_percent_sl_39", (getter)Outputs_get_depr_stabas_percent_sl_39,(setter)0,
	"39-yr straight line state percent of total depreciable basis [%], number.",
 	NULL},
{"depr_stabas_percent_sl_5", (getter)Outputs_get_depr_stabas_percent_sl_5,(setter)0,
	"5-yr straight line state percent of total depreciable basis [%], number.",
 	NULL},
{"depr_stabas_percent_total", (getter)Outputs_get_depr_stabas_percent_total,(setter)0,
	"Total state percent of total depreciable basis [%], number.",
 	NULL},
{"depr_stabas_prior_itc_custom", (getter)Outputs_get_depr_stabas_prior_itc_custom,(setter)0,
	"Custom straight line state depreciation basis prior ITC reduction [$], number.",
 	NULL},
{"depr_stabas_prior_itc_macrs_15", (getter)Outputs_get_depr_stabas_prior_itc_macrs_15,(setter)0,
	"15-yr MACRS state depreciation basis prior ITC reduction [$], number.",
 	NULL},
{"depr_stabas_prior_itc_macrs_5", (getter)Outputs_get_depr_stabas_prior_itc_macrs_5,(setter)0,
	"5-yr MACRS state depreciation basis prior ITC reduction [$], number.",
 	NULL},
{"depr_stabas_prior_itc_sl_15", (getter)Outputs_get_depr_stabas_prior_itc_sl_15,(setter)0,
	"15-yr straight line state depreciation basis prior ITC reduction [$], number.",
 	NULL},
{"depr_stabas_prior_itc_sl_20", (getter)Outputs_get_depr_stabas_prior_itc_sl_20,(setter)0,
	"20-yr straight line state depreciation basis prior ITC reduction [$], number.",
 	NULL},
{"depr_stabas_prior_itc_sl_39", (getter)Outputs_get_depr_stabas_prior_itc_sl_39,(setter)0,
	"39-yr straight line state depreciation basis prior ITC reduction [$], number.",
 	NULL},
{"depr_stabas_prior_itc_sl_5", (getter)Outputs_get_depr_stabas_prior_itc_sl_5,(setter)0,
	"5-yr straight line state depreciation basis prior ITC reduction [$], number.",
 	NULL},
{"depr_stabas_prior_itc_total", (getter)Outputs_get_depr_stabas_prior_itc_total,(setter)0,
	"Total state depreciation basis prior ITC reduction [$], number.",
 	NULL},
{"depr_stabas_sl_15", (getter)Outputs_get_depr_stabas_sl_15,(setter)0,
	"15-yr straight line state depreciation basis [$], number.",
 	NULL},
{"depr_stabas_sl_20", (getter)Outputs_get_depr_stabas_sl_20,(setter)0,
	"20-yr straight line state depreciation basis [$], number.",
 	NULL},
{"depr_stabas_sl_39", (getter)Outputs_get_depr_stabas_sl_39,(setter)0,
	"39-yr straight line state depreciation basis [$], number.",
 	NULL},
{"depr_stabas_sl_5", (getter)Outputs_get_depr_stabas_sl_5,(setter)0,
	"5-yr straight line state depreciation basis [$], number.",
 	NULL},
{"depr_stabas_total", (getter)Outputs_get_depr_stabas_total,(setter)0,
	"Total state depreciation basis [$], number.",
 	NULL},
{"distribution_of_development_fee", (getter)Outputs_get_distribution_of_development_fee,(setter)0,
	"Distribution of development fee [$], number.",
 	NULL},
{"effective_tax_rate", (getter)Outputs_get_effective_tax_rate,(setter)0,
	"Effective Tax Rate [%], number.",
 	NULL},
{"firstyear_energy_dispatch1", (getter)Outputs_get_firstyear_energy_dispatch1,(setter)0,
	"First year energy from the system in TOD period 1 [kWh], number.",
 	NULL},
{"firstyear_energy_dispatch2", (getter)Outputs_get_firstyear_energy_dispatch2,(setter)0,
	"First year energy from the system in TOD period 2 [kWh], number.",
 	NULL},
{"firstyear_energy_dispatch3", (getter)Outputs_get_firstyear_energy_dispatch3,(setter)0,
	"First year energy from the system in TOD period 3 [kWh], number.",
 	NULL},
{"firstyear_energy_dispatch4", (getter)Outputs_get_firstyear_energy_dispatch4,(setter)0,
	"First year energy from the system in TOD period 4 [kWh], number.",
 	NULL},
{"firstyear_energy_dispatch5", (getter)Outputs_get_firstyear_energy_dispatch5,(setter)0,
	"First year energy from the system in TOD period 5 [kWh], number.",
 	NULL},
{"firstyear_energy_dispatch6", (getter)Outputs_get_firstyear_energy_dispatch6,(setter)0,
	"First year energy from the system in TOD period 6 [kWh], number.",
 	NULL},
{"firstyear_energy_dispatch7", (getter)Outputs_get_firstyear_energy_dispatch7,(setter)0,
	"First year energy from the system in TOD period 7 [kWh], number.",
 	NULL},
{"firstyear_energy_dispatch8", (getter)Outputs_get_firstyear_energy_dispatch8,(setter)0,
	"First year energy from the system in TOD period 8 [kWh], number.",
 	NULL},
{"firstyear_energy_dispatch9", (getter)Outputs_get_firstyear_energy_dispatch9,(setter)0,
	"First year energy from the system in TOD period 9 [kWh], number.",
 	NULL},
{"firstyear_energy_price1", (getter)Outputs_get_firstyear_energy_price1,(setter)0,
	"First year energy price for TOD period 1 [cents/kWh], number.",
 	NULL},
{"firstyear_energy_price2", (getter)Outputs_get_firstyear_energy_price2,(setter)0,
	"First year energy price for TOD period 2 [cents/kWh], number.",
 	NULL},
{"firstyear_energy_price3", (getter)Outputs_get_firstyear_energy_price3,(setter)0,
	"First year energy price for TOD period 3 [cents/kWh], number.",
 	NULL},
{"firstyear_energy_price4", (getter)Outputs_get_firstyear_energy_price4,(setter)0,
	"First year energy price for TOD period 4 [cents/kWh], number.",
 	NULL},
{"firstyear_energy_price5", (getter)Outputs_get_firstyear_energy_price5,(setter)0,
	"First year energy price for TOD period 5 [cents/kWh], number.",
 	NULL},
{"firstyear_energy_price6", (getter)Outputs_get_firstyear_energy_price6,(setter)0,
	"First year energy price for TOD period 6 [cents/kWh], number.",
 	NULL},
{"firstyear_energy_price7", (getter)Outputs_get_firstyear_energy_price7,(setter)0,
	"First year energy price for TOD period 7 [cents/kWh], number.",
 	NULL},
{"firstyear_energy_price8", (getter)Outputs_get_firstyear_energy_price8,(setter)0,
	"First year energy price for TOD period 8 [cents/kWh], number.",
 	NULL},
{"firstyear_energy_price9", (getter)Outputs_get_firstyear_energy_price9,(setter)0,
	"First year energy price for TOD period 9 [cents/kWh], number.",
 	NULL},
{"firstyear_revenue_dispatch1", (getter)Outputs_get_firstyear_revenue_dispatch1,(setter)0,
	"First year revenue from the system in TOD period 1 [$], number.",
 	NULL},
{"firstyear_revenue_dispatch2", (getter)Outputs_get_firstyear_revenue_dispatch2,(setter)0,
	"First year revenue from the system in TOD period 2 [$], number.",
 	NULL},
{"firstyear_revenue_dispatch3", (getter)Outputs_get_firstyear_revenue_dispatch3,(setter)0,
	"First year revenue from the system in TOD period 3 [$], number.",
 	NULL},
{"firstyear_revenue_dispatch4", (getter)Outputs_get_firstyear_revenue_dispatch4,(setter)0,
	"First year revenue from the system in TOD period 4 [$], number.",
 	NULL},
{"firstyear_revenue_dispatch5", (getter)Outputs_get_firstyear_revenue_dispatch5,(setter)0,
	"First year revenue from the system in TOD period 5 [$], number.",
 	NULL},
{"firstyear_revenue_dispatch6", (getter)Outputs_get_firstyear_revenue_dispatch6,(setter)0,
	"First year revenue from the system in TOD period 6 [$], number.",
 	NULL},
{"firstyear_revenue_dispatch7", (getter)Outputs_get_firstyear_revenue_dispatch7,(setter)0,
	"First year revenue from the system in TOD period 7 [$], number.",
 	NULL},
{"firstyear_revenue_dispatch8", (getter)Outputs_get_firstyear_revenue_dispatch8,(setter)0,
	"First year revenue from the system in TOD period 8 [$], number.",
 	NULL},
{"firstyear_revenue_dispatch9", (getter)Outputs_get_firstyear_revenue_dispatch9,(setter)0,
	"First year revenue from the system in TOD period 9 [$], number.",
 	NULL},
{"flip_actual_irr", (getter)Outputs_get_flip_actual_irr,(setter)0,
	"IRR in target year [%], number.",
 	NULL},
{"flip_actual_year", (getter)Outputs_get_flip_actual_year,(setter)0,
	"IRR actual year, number.",
 	NULL},
{"flip_target_irr", (getter)Outputs_get_flip_target_irr,(setter)0,
	"IRR target [%], number.",
 	NULL},
{"flip_target_year", (getter)Outputs_get_flip_target_year,(setter)0,
	"IRR target year, number.",
 	NULL},
{"ibi_fedtax_total", (getter)Outputs_get_ibi_fedtax_total,(setter)0,
	"Total federal taxable IBI incentive income [$], number.",
 	NULL},
{"ibi_statax_total", (getter)Outputs_get_ibi_statax_total,(setter)0,
	"Total state taxable IBI incentive income [$], number.",
 	NULL},
{"ibi_total", (getter)Outputs_get_ibi_total,(setter)0,
	"Total IBI incentive income [$], number.",
 	NULL},
{"ibi_total_fed", (getter)Outputs_get_ibi_total_fed,(setter)0,
	"Total federal IBI incentive income [$], number.",
 	NULL},
{"ibi_total_oth", (getter)Outputs_get_ibi_total_oth,(setter)0,
	"Total other IBI incentive income [$], number.",
 	NULL},
{"ibi_total_sta", (getter)Outputs_get_ibi_total_sta,(setter)0,
	"Total state IBI incentive income [$], number.",
 	NULL},
{"ibi_total_uti", (getter)Outputs_get_ibi_total_uti,(setter)0,
	"Total utility IBI incentive income [$], number.",
 	NULL},
{"issuance_of_equity", (getter)Outputs_get_issuance_of_equity,(setter)0,
	"Issuance of equity [$], number.",
 	NULL},
{"itc_disallow_fed_fixed_custom", (getter)Outputs_get_itc_disallow_fed_fixed_custom,(setter)0,
	"Custom straight line depreciation ITC basis disallowance from federal fixed amount [$], number.",
 	NULL},
{"itc_disallow_fed_fixed_macrs_15", (getter)Outputs_get_itc_disallow_fed_fixed_macrs_15,(setter)0,
	"15-yr MACRS depreciation ITC basis disallowance from federal fixed amount [$], number.",
 	NULL},
{"itc_disallow_fed_fixed_macrs_5", (getter)Outputs_get_itc_disallow_fed_fixed_macrs_5,(setter)0,
	"5-yr MACRS depreciation ITC basis disallowance from federal fixed amount [$], number.",
 	NULL},
{"itc_disallow_fed_fixed_sl_15", (getter)Outputs_get_itc_disallow_fed_fixed_sl_15,(setter)0,
	"15-yr straight line depreciation ITC basis disallowance from federal fixed amount [$], number.",
 	NULL},
{"itc_disallow_fed_fixed_sl_20", (getter)Outputs_get_itc_disallow_fed_fixed_sl_20,(setter)0,
	"20-yr straight line depreciation ITC basis disallowance from federal fixed amount [$], number.",
 	NULL},
{"itc_disallow_fed_fixed_sl_39", (getter)Outputs_get_itc_disallow_fed_fixed_sl_39,(setter)0,
	"39-yr straight line depreciation ITC basis disallowance from federal fixed amount [$], number.",
 	NULL},
{"itc_disallow_fed_fixed_sl_5", (getter)Outputs_get_itc_disallow_fed_fixed_sl_5,(setter)0,
	"5-yr straight line depreciation ITC basis disallowance from federal fixed amount [$], number.",
 	NULL},
{"itc_disallow_fed_fixed_total", (getter)Outputs_get_itc_disallow_fed_fixed_total,(setter)0,
	"Total depreciation ITC basis disallowance from federal fixed amount [$], number.",
 	NULL},
{"itc_disallow_fed_percent_custom", (getter)Outputs_get_itc_disallow_fed_percent_custom,(setter)0,
	"Custom straight line depreciation ITC basis disallowance from federal percentage [$], number.",
 	NULL},
{"itc_disallow_fed_percent_macrs_15", (getter)Outputs_get_itc_disallow_fed_percent_macrs_15,(setter)0,
	"15-yr MACRS depreciation ITC basis disallowance from federal percentage [$], number.",
 	NULL},
{"itc_disallow_fed_percent_macrs_5", (getter)Outputs_get_itc_disallow_fed_percent_macrs_5,(setter)0,
	"5-yr MACRS depreciation ITC basis disallowance from federal percentage [$], number.",
 	NULL},
{"itc_disallow_fed_percent_sl_15", (getter)Outputs_get_itc_disallow_fed_percent_sl_15,(setter)0,
	"15-yr straight line depreciation ITC basis disallowance from federal percentage [$], number.",
 	NULL},
{"itc_disallow_fed_percent_sl_20", (getter)Outputs_get_itc_disallow_fed_percent_sl_20,(setter)0,
	"20-yr straight line depreciation ITC basis disallowance from federal percentage [$], number.",
 	NULL},
{"itc_disallow_fed_percent_sl_39", (getter)Outputs_get_itc_disallow_fed_percent_sl_39,(setter)0,
	"39-yr straight line depreciation ITC basis disallowance from federal percentage [$], number.",
 	NULL},
{"itc_disallow_fed_percent_sl_5", (getter)Outputs_get_itc_disallow_fed_percent_sl_5,(setter)0,
	"5-yr straight line depreciation ITC basis disallowance from federal percentage [$], number.",
 	NULL},
{"itc_disallow_fed_percent_total", (getter)Outputs_get_itc_disallow_fed_percent_total,(setter)0,
	"Total depreciation ITC basis disallowance from federal percentage [$], number.",
 	NULL},
{"itc_disallow_sta_fixed_custom", (getter)Outputs_get_itc_disallow_sta_fixed_custom,(setter)0,
	"Custom straight line depreciation ITC basis disallowance from state fixed amount [$], number.",
 	NULL},
{"itc_disallow_sta_fixed_macrs_15", (getter)Outputs_get_itc_disallow_sta_fixed_macrs_15,(setter)0,
	"15-yr MACRS depreciation ITC basis disallowance from state fixed amount [$], number.",
 	NULL},
{"itc_disallow_sta_fixed_macrs_5", (getter)Outputs_get_itc_disallow_sta_fixed_macrs_5,(setter)0,
	"5-yr MACRS depreciation ITC basis disallowance from state fixed amount [$], number.",
 	NULL},
{"itc_disallow_sta_fixed_sl_15", (getter)Outputs_get_itc_disallow_sta_fixed_sl_15,(setter)0,
	"15-yr straight line depreciation ITC basis disallowance from state fixed amount [$], number.",
 	NULL},
{"itc_disallow_sta_fixed_sl_20", (getter)Outputs_get_itc_disallow_sta_fixed_sl_20,(setter)0,
	"20-yr straight line depreciation ITC basis disallowance from state fixed amount [$], number.",
 	NULL},
{"itc_disallow_sta_fixed_sl_39", (getter)Outputs_get_itc_disallow_sta_fixed_sl_39,(setter)0,
	"39-yr straight line depreciation ITC basis disallowance from state fixed amount [$], number.",
 	NULL},
{"itc_disallow_sta_fixed_sl_5", (getter)Outputs_get_itc_disallow_sta_fixed_sl_5,(setter)0,
	"5-yr straight line depreciation ITC basis disallowance from state fixed amount [$], number.",
 	NULL},
{"itc_disallow_sta_fixed_total", (getter)Outputs_get_itc_disallow_sta_fixed_total,(setter)0,
	"Total depreciation ITC basis disallowance from state fixed amount [$], number.",
 	NULL},
{"itc_disallow_sta_percent_custom", (getter)Outputs_get_itc_disallow_sta_percent_custom,(setter)0,
	"Custom straight line depreciation ITC basis disallowance from state percentage [$], number.",
 	NULL},
{"itc_disallow_sta_percent_macrs_15", (getter)Outputs_get_itc_disallow_sta_percent_macrs_15,(setter)0,
	"15-yr MACRS depreciation ITC basis disallowance from state percentage [$], number.",
 	NULL},
{"itc_disallow_sta_percent_macrs_5", (getter)Outputs_get_itc_disallow_sta_percent_macrs_5,(setter)0,
	"5-yr MACRS depreciation ITC basis disallowance from state percentage [$], number.",
 	NULL},
{"itc_disallow_sta_percent_sl_15", (getter)Outputs_get_itc_disallow_sta_percent_sl_15,(setter)0,
	"15-yr straight line depreciation ITC basis disallowance from state percentage [$], number.",
 	NULL},
{"itc_disallow_sta_percent_sl_20", (getter)Outputs_get_itc_disallow_sta_percent_sl_20,(setter)0,
	"20-yr straight line depreciation ITC basis disallowance from state percentage [$], number.",
 	NULL},
{"itc_disallow_sta_percent_sl_39", (getter)Outputs_get_itc_disallow_sta_percent_sl_39,(setter)0,
	"39-yr straight line depreciation ITC basis disallowance from state percentage [$], number.",
 	NULL},
{"itc_disallow_sta_percent_sl_5", (getter)Outputs_get_itc_disallow_sta_percent_sl_5,(setter)0,
	"5-yr straight line depreciation ITC basis disallowance from state percentage [$], number.",
 	NULL},
{"itc_disallow_sta_percent_total", (getter)Outputs_get_itc_disallow_sta_percent_total,(setter)0,
	"Total depreciation ITC basis disallowance from state percentage [$], number.",
 	NULL},
{"itc_fed_fixed_total", (getter)Outputs_get_itc_fed_fixed_total,(setter)0,
	"federal ITC fixed total [$], number.",
 	NULL},
{"itc_fed_percent_total", (getter)Outputs_get_itc_fed_percent_total,(setter)0,
	"federal ITC percent total [$], number.",
 	NULL},
{"itc_fed_qual_custom", (getter)Outputs_get_itc_fed_qual_custom,(setter)0,
	"Custom straight line depreciation federal ITC adj qualifying costs [$], number.",
 	NULL},
{"itc_fed_qual_macrs_15", (getter)Outputs_get_itc_fed_qual_macrs_15,(setter)0,
	"15-yr MACRS depreciation federal ITC adj qualifying costs [$], number.",
 	NULL},
{"itc_fed_qual_macrs_5", (getter)Outputs_get_itc_fed_qual_macrs_5,(setter)0,
	"5-yr MACRS depreciation federal ITC adj qualifying costs [$], number.",
 	NULL},
{"itc_fed_qual_sl_15", (getter)Outputs_get_itc_fed_qual_sl_15,(setter)0,
	"15-yr straight line depreciation federal ITC adj qualifying costs [$], number.",
 	NULL},
{"itc_fed_qual_sl_20", (getter)Outputs_get_itc_fed_qual_sl_20,(setter)0,
	"20-yr straight line depreciation federal ITC adj qualifying costs [$], number.",
 	NULL},
{"itc_fed_qual_sl_39", (getter)Outputs_get_itc_fed_qual_sl_39,(setter)0,
	"39-yr straight line depreciation federal ITC adj qualifying costs [$], number.",
 	NULL},
{"itc_fed_qual_sl_5", (getter)Outputs_get_itc_fed_qual_sl_5,(setter)0,
	"5-yr straight line depreciation federal ITC adj qualifying costs [$], number.",
 	NULL},
{"itc_fed_qual_total", (getter)Outputs_get_itc_fed_qual_total,(setter)0,
	"Total federal ITC adj qualifying costs [$], number.",
 	NULL},
{"itc_sta_fixed_total", (getter)Outputs_get_itc_sta_fixed_total,(setter)0,
	"State ITC fixed total [$], number.",
 	NULL},
{"itc_sta_percent_total", (getter)Outputs_get_itc_sta_percent_total,(setter)0,
	"State ITC percent total [$], number.",
 	NULL},
{"itc_sta_qual_custom", (getter)Outputs_get_itc_sta_qual_custom,(setter)0,
	"Custom straight line depreciation state ITC adj qualifying costs [$], number.",
 	NULL},
{"itc_sta_qual_macrs_15", (getter)Outputs_get_itc_sta_qual_macrs_15,(setter)0,
	"15-yr MACRS depreciation state ITC adj qualifying costs [$], number.",
 	NULL},
{"itc_sta_qual_macrs_5", (getter)Outputs_get_itc_sta_qual_macrs_5,(setter)0,
	"5-yr MACRS depreciation state ITC adj qualifying costs [$], number.",
 	NULL},
{"itc_sta_qual_sl_15", (getter)Outputs_get_itc_sta_qual_sl_15,(setter)0,
	"15-yr straight line depreciation state ITC adj qualifying costs [$], number.",
 	NULL},
{"itc_sta_qual_sl_20", (getter)Outputs_get_itc_sta_qual_sl_20,(setter)0,
	"20-yr straight line depreciation state ITC adj qualifying costs [$], number.",
 	NULL},
{"itc_sta_qual_sl_39", (getter)Outputs_get_itc_sta_qual_sl_39,(setter)0,
	"39-yr straight line depreciation state ITC adj qualifying costs [$], number.",
 	NULL},
{"itc_sta_qual_sl_5", (getter)Outputs_get_itc_sta_qual_sl_5,(setter)0,
	"5-yr straight line depreciation state ITC adj qualifying costs [$], number.",
 	NULL},
{"itc_sta_qual_total", (getter)Outputs_get_itc_sta_qual_total,(setter)0,
	"Total state ITC adj qualifying costs [$], number.",
 	NULL},
{"itc_total", (getter)Outputs_get_itc_total,(setter)0,
	"Total ITC  [$], number.",
 	NULL},
{"itc_total_fed", (getter)Outputs_get_itc_total_fed,(setter)0,
	"Total federal ITC  [$], number.",
 	NULL},
{"itc_total_sta", (getter)Outputs_get_itc_total_sta,(setter)0,
	"Total state ITC  [$], number.",
 	NULL},
{"lcoe_nom", (getter)Outputs_get_lcoe_nom,(setter)0,
	"Levelized cost (nominal) [cents/kWh], number.",
 	NULL},
{"lcoe_real", (getter)Outputs_get_lcoe_real,(setter)0,
	"Levelized cost (real) [cents/kWh], number.",
 	NULL},
{"lcoptc_fed_nom", (getter)Outputs_get_lcoptc_fed_nom,(setter)0,
	"Levelized Federal PTC (nominal) [cents/kWh], number.",
 	NULL},
{"lcoptc_fed_real", (getter)Outputs_get_lcoptc_fed_real,(setter)0,
	"Levelized Federal PTC (real) [cents/kWh], number.",
 	NULL},
{"lcoptc_sta_nom", (getter)Outputs_get_lcoptc_sta_nom,(setter)0,
	"Levelized State PTC (nominal) [cents/kWh], number.",
 	NULL},
{"lcoptc_sta_real", (getter)Outputs_get_lcoptc_sta_real,(setter)0,
	"Levelized State PTC (real) [cents/kWh], number.",
 	NULL},
{"lppa_nom", (getter)Outputs_get_lppa_nom,(setter)0,
	"Levelized PPA price (nominal) [cents/kWh], number.",
 	NULL},
{"lppa_real", (getter)Outputs_get_lppa_real,(setter)0,
	"Levelized PPA price (real) [cents/kWh], number.",
 	NULL},
{"nominal_discount_rate", (getter)Outputs_get_nominal_discount_rate,(setter)0,
	"Nominal discount rate [%], number.",
 	NULL},
{"npv_annual_costs", (getter)Outputs_get_npv_annual_costs,(setter)0,
	"Present value of annual costs [$], number.",
 	NULL},
{"npv_energy_nom", (getter)Outputs_get_npv_energy_nom,(setter)0,
	"NPV of net annual energy (nominal) [kWh], number.",
 	NULL},
{"npv_energy_real", (getter)Outputs_get_npv_energy_real,(setter)0,
	"NPV of net annual energy (real) [kWh], number.",
 	NULL},
{"npv_ppa_revenue", (getter)Outputs_get_npv_ppa_revenue,(setter)0,
	"NPV of PPA revenue [$], number.",
 	NULL},
{"ppa", (getter)Outputs_get_ppa,(setter)0,
	"PPA price, number.",
 	NULL},
{"ppa_escalation", (getter)Outputs_get_ppa_escalation,(setter)0,
	"PPA price escalation [%], number.",
 	NULL},
{"ppa_multipliers", (getter)Outputs_get_ppa_multipliers,(setter)0,
	"TOD factors, array.",
 	NULL},
{"ppa_price", (getter)Outputs_get_ppa_price,(setter)0,
	"Initial year PPA price [cents/kWh], number.",
 	NULL},
{"present_value_fuel", (getter)Outputs_get_present_value_fuel,(setter)0,
	"Present value of fuel O and M [$], number.",
 	NULL},
{"present_value_insandproptax", (getter)Outputs_get_present_value_insandproptax,(setter)0,
	"Present value of Insurance and Prop Tax [$], number.",
 	NULL},
{"present_value_oandm", (getter)Outputs_get_present_value_oandm,(setter)0,
	"Present value of O and M [$], number.",
 	NULL},
{"present_value_oandm_nonfuel", (getter)Outputs_get_present_value_oandm_nonfuel,(setter)0,
	"Present value of non-fuel O and M [$], number.",
 	NULL},
{"prop_tax_assessed_value", (getter)Outputs_get_prop_tax_assessed_value,(setter)0,
	"Assessed value of property for tax purposes [$], number.",
 	NULL},
{"purchase_of_plant", (getter)Outputs_get_purchase_of_plant,(setter)0,
	"Purchase of plant [$], number.",
 	NULL},
{"sale_of_property", (getter)Outputs_get_sale_of_property,(setter)0,
	"Sale of property [$], number.",
 	NULL},
{"salvage_value", (getter)Outputs_get_salvage_value,(setter)0,
	"Net pre-tax cash salvage value [$], number.",
 	NULL},
{"size_of_equity", (getter)Outputs_get_size_of_equity,(setter)0,
	"Total equity, number.",
 	NULL},
{"sponsor_aftertax_irr", (getter)Outputs_get_sponsor_aftertax_irr,(setter)0,
	"After-tax developer IRR [%], number.",
 	NULL},
{"sponsor_aftertax_npv", (getter)Outputs_get_sponsor_aftertax_npv,(setter)0,
	"After-tax developer NPV [$], number.",
 	NULL},
{"sponsor_equity_in_lessee_llc", (getter)Outputs_get_sponsor_equity_in_lessee_llc,(setter)0,
	"Developer equity in lessee LLC (funding of reserve accounts) [$], number.",
 	NULL},
{"sponsor_pretax_irr", (getter)Outputs_get_sponsor_pretax_irr,(setter)0,
	"Pre-tax developer IRR [%], number.",
 	NULL},
{"sponsor_pretax_npv", (getter)Outputs_get_sponsor_pretax_npv,(setter)0,
	"Pre-tax developer NPV [$], number.",
 	NULL},
{"tax_investor_aftertax_irr", (getter)Outputs_get_tax_investor_aftertax_irr,(setter)0,
	"After-tax tax investor IRR, number.",
 	NULL},
{"tax_investor_aftertax_npv", (getter)Outputs_get_tax_investor_aftertax_npv,(setter)0,
	"After-tax tax investor NPV, number.",
 	NULL},
{"tax_investor_pretax_irr", (getter)Outputs_get_tax_investor_pretax_irr,(setter)0,
	"Pre-tax tax investor IRR [%], number.",
 	NULL},
{"tax_investor_pretax_npv", (getter)Outputs_get_tax_investor_pretax_npv,(setter)0,
	"Pre-tax tax investor NPV [$], number.",
 	NULL},
{"wacc", (getter)Outputs_get_wacc,(setter)0,
	"Weighted Average Cost of Capital (WACC), number.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Saleleaseback.Outputs",             /*tp_name*/
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
 * Saleleaseback
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_Saleleaseback   data_ptr;
} SaleleasebackObject;

static PyTypeObject Saleleaseback_Type;

#define SaleleasebackObject_Check(v)      (Py_TYPE(v) == &Saleleaseback_Type)

static SaleleasebackObject *
newSaleleasebackObject(void* data_ptr)
{
	SaleleasebackObject *self;
	self = PyObject_New(SaleleasebackObject, &Saleleaseback_Type);

	PySAM_TECH_ATTR("Saleleaseback", SAM_Saleleaseback_construct)

	PyObject* FinancialParameters_obj = FinancialParameters_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FinancialParameters", FinancialParameters_obj);
	Py_DECREF(FinancialParameters_obj);

	PyObject* SystemCosts_obj = SystemCosts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemCosts", SystemCosts_obj);
	Py_DECREF(SystemCosts_obj);

	PyObject* TaxCreditIncentives_obj = TaxCreditIncentives_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TaxCreditIncentives", TaxCreditIncentives_obj);
	Py_DECREF(TaxCreditIncentives_obj);

	PyObject* PaymentIncentives_obj = PaymentIncentives_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "PaymentIncentives", PaymentIncentives_obj);
	Py_DECREF(PaymentIncentives_obj);

	PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

	PyObject* DHF_obj = DHF_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "DHF", DHF_obj);
	Py_DECREF(DHF_obj);

	PyObject* TimeOfDelivery_obj = TimeOfDelivery_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TimeOfDelivery", TimeOfDelivery_obj);
	Py_DECREF(TimeOfDelivery_obj);

	PyObject* ReserveAccounts_obj = ReserveAccounts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ReserveAccounts", ReserveAccounts_obj);
	Py_DECREF(ReserveAccounts_obj);

	PyObject* OtherCapitalCosts_obj = OtherCapitalCosts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "OtherCapitalCosts", OtherCapitalCosts_obj);
	Py_DECREF(OtherCapitalCosts_obj);

	PyObject* Battery_obj = Battery_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Battery", Battery_obj);
	Py_DECREF(Battery_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);


	return self;
}

/* Saleleaseback methods */

static void
Saleleaseback_dealloc(SaleleasebackObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_Saleleaseback_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
Saleleaseback_execute(SaleleasebackObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Saleleaseback_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Saleleaseback_assign(SaleleasebackObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Saleleaseback"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Saleleaseback_export(SaleleasebackObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyMethodDef Saleleaseback_methods[] = {
		{"execute",            (PyCFunction)Saleleaseback_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Saleleaseback_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs")},
		{"export",            (PyCFunction)Saleleaseback_export,  METH_VARARGS,
				PyDoc_STR("assign() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Saleleaseback_getattro(SaleleasebackObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Saleleaseback_setattr(SaleleasebackObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Saleleaseback_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Saleleaseback",            /*tp_name*/
		sizeof(SaleleasebackObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Saleleaseback_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Saleleaseback_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Saleleaseback_getattro, /*tp_getattro*/
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
		Saleleaseback_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Saleleaseback object */

static PyObject *
Saleleaseback_new(PyObject *self, PyObject *args)
{
	SaleleasebackObject *rv;
	rv = newSaleleasebackObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Saleleaseback_wrap(PyObject *self, PyObject *args)
{
	SaleleasebackObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSaleleasebackObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Saleleaseback_default(PyObject *self, PyObject *args)
{
	SaleleasebackObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSaleleasebackObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Saleleaseback", def);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef SaleleasebackModule_methods[] = {
		{"new",             Saleleaseback_new,         METH_VARARGS,
				PyDoc_STR("new() -> new Saleleaseback object")},
		{"default",             Saleleaseback_default,         METH_VARARGS,
				PyDoc_STR("default(financial) -> new Saleleaseback object with financial model-specific default attributes\n"
				"Options: TcsMSLF, TcsdirectSteam, TcslinearFresnel, Biomass, Tcsdish, Hcpv, TcsgenericSolar, Geothermal, Windpower, Pvwattsv5, TcstroughPhysical, GenericSystem, Pvsamv1, TcsmoltenSalt, TcstroughEmpirical")},
		{"wrap",             Saleleaseback_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> new Saleleaseback object around existing PySSC data, taking over memory ownership")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "PPA sale leaseback partnership financial model");


static int
SaleleasebackModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error(m) < 0) goto fail;

	Saleleaseback_Type.tp_dict = PyDict_New();
	if (!Saleleaseback_Type.tp_dict) { goto fail; }

	/// Add the FinancialParameters type object to Saleleaseback_Type
	if (PyType_Ready(&FinancialParameters_Type) < 0) { goto fail; }
	PyDict_SetItemString(Saleleaseback_Type.tp_dict,
				"FinancialParameters",
				(PyObject*)&FinancialParameters_Type);
	Py_DECREF(&FinancialParameters_Type);

	/// Add the SystemCosts type object to Saleleaseback_Type
	if (PyType_Ready(&SystemCosts_Type) < 0) { goto fail; }
	PyDict_SetItemString(Saleleaseback_Type.tp_dict,
				"SystemCosts",
				(PyObject*)&SystemCosts_Type);
	Py_DECREF(&SystemCosts_Type);

	/// Add the TaxCreditIncentives type object to Saleleaseback_Type
	if (PyType_Ready(&TaxCreditIncentives_Type) < 0) { goto fail; }
	PyDict_SetItemString(Saleleaseback_Type.tp_dict,
				"TaxCreditIncentives",
				(PyObject*)&TaxCreditIncentives_Type);
	Py_DECREF(&TaxCreditIncentives_Type);

	/// Add the PaymentIncentives type object to Saleleaseback_Type
	if (PyType_Ready(&PaymentIncentives_Type) < 0) { goto fail; }
	PyDict_SetItemString(Saleleaseback_Type.tp_dict,
				"PaymentIncentives",
				(PyObject*)&PaymentIncentives_Type);
	Py_DECREF(&PaymentIncentives_Type);

	/// Add the Common type object to Saleleaseback_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(Saleleaseback_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the DHF type object to Saleleaseback_Type
	if (PyType_Ready(&DHF_Type) < 0) { goto fail; }
	PyDict_SetItemString(Saleleaseback_Type.tp_dict,
				"DHF",
				(PyObject*)&DHF_Type);
	Py_DECREF(&DHF_Type);

	/// Add the TimeOfDelivery type object to Saleleaseback_Type
	if (PyType_Ready(&TimeOfDelivery_Type) < 0) { goto fail; }
	PyDict_SetItemString(Saleleaseback_Type.tp_dict,
				"TimeOfDelivery",
				(PyObject*)&TimeOfDelivery_Type);
	Py_DECREF(&TimeOfDelivery_Type);

	/// Add the ReserveAccounts type object to Saleleaseback_Type
	if (PyType_Ready(&ReserveAccounts_Type) < 0) { goto fail; }
	PyDict_SetItemString(Saleleaseback_Type.tp_dict,
				"ReserveAccounts",
				(PyObject*)&ReserveAccounts_Type);
	Py_DECREF(&ReserveAccounts_Type);

	/// Add the OtherCapitalCosts type object to Saleleaseback_Type
	if (PyType_Ready(&OtherCapitalCosts_Type) < 0) { goto fail; }
	PyDict_SetItemString(Saleleaseback_Type.tp_dict,
				"OtherCapitalCosts",
				(PyObject*)&OtherCapitalCosts_Type);
	Py_DECREF(&OtherCapitalCosts_Type);

	/// Add the Battery type object to Saleleaseback_Type
	if (PyType_Ready(&Battery_Type) < 0) { goto fail; }
	PyDict_SetItemString(Saleleaseback_Type.tp_dict,
				"Battery",
				(PyObject*)&Battery_Type);
	Py_DECREF(&Battery_Type);

	/// Add the Outputs type object to Saleleaseback_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Saleleaseback_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Saleleaseback type object to the module
	if (PyType_Ready(&Saleleaseback_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Saleleaseback",
				(PyObject*)&Saleleaseback_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot SaleleasebackModule_slots[] = {
		{Py_mod_exec, SaleleasebackModule_exec},
		{0, NULL},
};

static struct PyModuleDef SaleleasebackModule = {
		PyModuleDef_HEAD_INIT,
		"Saleleaseback",
		module_doc,
		0,
		SaleleasebackModule_methods,
		SaleleasebackModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Saleleaseback(void)
{
	return PyModuleDef_Init(&SaleleasebackModule);
}