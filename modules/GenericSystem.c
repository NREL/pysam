#include <Python.h>

#include <SAM_GenericSystem.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Plant Group
 */ 

static PyTypeObject Plant_Type;

static PyObject *
Plant_new(SAM_GenericSystem data_ptr)
{
	PyObject* new_obj = Plant_Type.tp_alloc(&Plant_Type,0);

	VarGroupObject* Plant_obj = (VarGroupObject*)new_obj;

	Plant_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Plant methods */

static PyObject *
Plant_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "GenericSystem", "Plant")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Plant_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Plant_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "GenericSystem", "Plant")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Plant_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Plant_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Plant_methods[] = {
		{"assign",            (PyCFunction)Plant_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Plant_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Plant_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Plant_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Plant_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Plant_get_conv_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GenericSystem_Plant_conv_eff_nget, self->data_ptr);
}

static int
Plant_set_conv_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GenericSystem_Plant_conv_eff_nset, self->data_ptr);
}

static PyObject *
Plant_get_derate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GenericSystem_Plant_derate_nget, self->data_ptr);
}

static int
Plant_set_derate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GenericSystem_Plant_derate_nset, self->data_ptr);
}

static PyObject *
Plant_get_energy_output_array(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_GenericSystem_Plant_energy_output_array_aget, self->data_ptr);
}

static int
Plant_set_energy_output_array(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_GenericSystem_Plant_energy_output_array_aset, self->data_ptr);
}

static PyObject *
Plant_get_heat_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GenericSystem_Plant_heat_rate_nget, self->data_ptr);
}

static int
Plant_set_heat_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GenericSystem_Plant_heat_rate_nset, self->data_ptr);
}

static PyObject *
Plant_get_spec_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GenericSystem_Plant_spec_mode_nget, self->data_ptr);
}

static int
Plant_set_spec_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GenericSystem_Plant_spec_mode_nset, self->data_ptr);
}

static PyObject *
Plant_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GenericSystem_Plant_system_capacity_nget, self->data_ptr);
}

static int
Plant_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GenericSystem_Plant_system_capacity_nset, self->data_ptr);
}

static PyObject *
Plant_get_user_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GenericSystem_Plant_user_capacity_factor_nget, self->data_ptr);
}

static int
Plant_set_user_capacity_factor(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GenericSystem_Plant_user_capacity_factor_nset, self->data_ptr);
}

static PyGetSetDef Plant_getset[] = {
{"conv_eff", (getter)Plant_get_conv_eff,(setter)Plant_set_conv_eff,
	PyDoc_STR("*float*: Conversion Efficiency [%]\n\n**Required:**\nTrue\n\nThe value of ``conv_eff`` depends on the following variables:\n\n\t - heat_rate\n"),
 	NULL},
{"derate", (getter)Plant_get_derate,(setter)Plant_set_derate,
	PyDoc_STR("*float*: Derate [%]\n\n**Required:**\nTrue"),
 	NULL},
{"energy_output_array", (getter)Plant_get_energy_output_array,(setter)Plant_set_energy_output_array,
	PyDoc_STR("*sequence*: Array of Energy Output Profile [kW]\n\n**Required:**\nRequired if spec_mode=1"),
 	NULL},
{"heat_rate", (getter)Plant_get_heat_rate,(setter)Plant_set_heat_rate,
	PyDoc_STR("*float*: Heat Rate [MMBTUs/MWhe]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``heat_rate``:\n\n\t - conv_eff\n"),
 	NULL},
{"spec_mode", (getter)Plant_get_spec_mode,(setter)Plant_set_spec_mode,
	PyDoc_STR("*float*: Spec mode: 0=constant CF,1=profile\n\n**Required:**\nTrue"),
 	NULL},
{"system_capacity", (getter)Plant_get_system_capacity,(setter)Plant_set_system_capacity,
	PyDoc_STR("*float*: Nameplace Capcity [kW]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Required:**\nTrue"),
 	NULL},
{"user_capacity_factor", (getter)Plant_get_user_capacity_factor,(setter)Plant_set_user_capacity_factor,
	PyDoc_STR("*float*: Capacity Factor [%]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Plant_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"GenericSystem.Plant",             /*tp_name*/
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
		Plant_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Plant_getset,          /*tp_getset*/
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
Lifetime_new(SAM_GenericSystem data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "GenericSystem", "Lifetime")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "GenericSystem", "Lifetime")){
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
	return PySAM_double_getter(SAM_GenericSystem_Lifetime_analysis_period_nget, self->data_ptr);
}

static int
Lifetime_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GenericSystem_Lifetime_analysis_period_nset, self->data_ptr);
}

static PyObject *
Lifetime_get_generic_degradation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_GenericSystem_Lifetime_generic_degradation_aget, self->data_ptr);
}

static int
Lifetime_set_generic_degradation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_GenericSystem_Lifetime_generic_degradation_aset, self->data_ptr);
}

static PyObject *
Lifetime_get_system_use_lifetime_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GenericSystem_Lifetime_system_use_lifetime_output_nget, self->data_ptr);
}

static int
Lifetime_set_system_use_lifetime_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GenericSystem_Lifetime_system_use_lifetime_output_nset, self->data_ptr);
}

static PyGetSetDef Lifetime_getset[] = {
{"analysis_period", (getter)Lifetime_get_analysis_period,(setter)Lifetime_set_analysis_period,
	PyDoc_STR("*float*: Lifetime analysis period [years]\n\n**Required:**\nRequired if system_use_lifetime_output=1"),
 	NULL},
{"generic_degradation", (getter)Lifetime_get_generic_degradation,(setter)Lifetime_set_generic_degradation,
	PyDoc_STR("*sequence*: Annual AC degradation [%/year]\n\n**Required:**\nRequired if system_use_lifetime_output=1"),
 	NULL},
{"system_use_lifetime_output", (getter)Lifetime_get_system_use_lifetime_output,(setter)Lifetime_set_system_use_lifetime_output,
	PyDoc_STR("*float*: Generic lifetime simulation [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Lifetime_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"GenericSystem.Lifetime",             /*tp_name*/
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
Outputs_new(SAM_GenericSystem data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "GenericSystem", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "GenericSystem", "Outputs")){
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
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GenericSystem_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution_time(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_GenericSystem_Outputs_annual_energy_distribution_time_mget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_fuel_usage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GenericSystem_Outputs_annual_fuel_usage_nget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GenericSystem_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_GenericSystem_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GenericSystem_Outputs_kwh_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_GenericSystem_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_heat_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GenericSystem_Outputs_system_heat_rate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_water_usage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GenericSystem_Outputs_water_usage_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual Energy [kWh]"),
 	NULL},
{"annual_energy_distribution_time", (getter)Outputs_get_annual_energy_distribution_time,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Annual energy production as function of time [kW]"),
 	NULL},
{"annual_fuel_usage", (getter)Outputs_get_annual_fuel_usage,(setter)0,
	PyDoc_STR("*float*: Annual Fuel Usage [kWht]"),
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	PyDoc_STR("*float*: Capacity factor [%]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System power generated [kW]"),
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	PyDoc_STR("*float*: First year kWh/kW [kWh/kW]"),
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	PyDoc_STR("*sequence*: Monthly Energy Gross [kWh]"),
 	NULL},
{"system_heat_rate", (getter)Outputs_get_system_heat_rate,(setter)0,
	PyDoc_STR("*float*: Heat Rate Conversion Factor [MMBTUs/MWhe]"),
 	NULL},
{"water_usage", (getter)Outputs_get_water_usage,(setter)0,
	PyDoc_STR("*float*: Annual Water Usage"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"GenericSystem.Outputs",             /*tp_name*/
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
 * GenericSystem
 */

static PyTypeObject GenericSystem_Type;

static CmodObject *
newGenericSystemObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &GenericSystem_Type);

	PySAM_TECH_ATTR()

	PyObject* Plant_obj = Plant_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Plant", Plant_obj);
	Py_DECREF(Plant_obj);

	PyObject* Lifetime_obj = Lifetime_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Lifetime", Lifetime_obj);
	Py_DECREF(Lifetime_obj);

	PyObject* AdjustmentFactorsModule = PyImport_ImportModule("AdjustmentFactors");

	PyObject* data_cap = PyCapsule_New(self->data_ptr, NULL, NULL);
	PyObject* Adjust_obj = PyObject_CallMethod(AdjustmentFactorsModule, "new", "(O)", data_cap);
	Py_XDECREF(data_cap);
	Py_XDECREF(AdjustmentFactorsModule);

	if (!Adjust_obj){
		PyErr_SetString(PyExc_Exception, "Couldn't create AdjustmentFactorsObject\n");
		return NULL;
	}

	PyDict_SetItemString(attr_dict, "AdjustmentFactors", Adjust_obj);
	Py_DECREF(Adjust_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* GenericSystem methods */

static void
GenericSystem_dealloc(CmodObject *self)
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
GenericSystem_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_GenericSystem_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
GenericSystem_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "GenericSystem"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
GenericSystem_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "GenericSystem"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
GenericSystem_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
GenericSystem_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
GenericSystem_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef GenericSystem_methods[] = {
		{"execute",           (PyCFunction)GenericSystem_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)GenericSystem_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Plant': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)GenericSystem_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Plant': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)GenericSystem_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)GenericSystem_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)GenericSystem_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
GenericSystem_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
GenericSystem_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject GenericSystem_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"GenericSystem",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)GenericSystem_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)GenericSystem_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)GenericSystem_getattro, /*tp_getattro*/
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
		GenericSystem_methods,      /*tp_methods*/
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


/* Function of no arguments returning new GenericSystem object */

static PyObject *
GenericSystem_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newGenericSystemObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
GenericSystem_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newGenericSystemObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
GenericSystem_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newGenericSystemObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "GenericSystem", def) < 0) {
		GenericSystem_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
GenericSystem_from_existing(PyObject *self, PyObject *args)
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

	rv = newGenericSystemObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "GenericSystem", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef GenericSystemModule_methods[] = {
		{"new",             GenericSystem_new,         METH_VARARGS,
				PyDoc_STR("new() -> GenericSystem")},
		{"default",             GenericSystem_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> GenericSystem\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"GenericBatteryAllEquityPartnershipFlip\"*\n\n		- *\"GenericBatteryCommercial\"*\n\n		- *\"GenericBatteryHostDeveloper\"*\n\n		- *\"GenericBatteryLeveragedPartnershipFlip\"*\n\n		- *\"GenericBatteryMerchantPlant\"*\n\n		- *\"GenericBatteryResidential\"*\n\n		- *\"GenericBatterySaleLeaseback\"*\n\n		- *\"GenericBatterySingleOwner\"*\n\n		- *\"GenericBatteryThirdParty\"*\n\n		- *\"GenericSystemAllEquityPartnershipFlip\"*\n\n		- *\"GenericSystemCommercial\"*\n\n		- *\"GenericSystemHostDeveloper\"*\n\n		- *\"GenericSystemLCOECalculator\"*\n\n		- *\"GenericSystemLeveragedPartnershipFlip\"*\n\n		- *\"GenericSystemMerchantPlant\"*\n\n		- *\"GenericSystemNone\"*\n\n		- *\"GenericSystemResidential\"*\n\n		- *\"GenericSystemSaleLeaseback\"*\n\n		- *\"GenericSystemSingleOwner\"*\n\n		- *\"GenericSystemThirdParty\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             GenericSystem_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> GenericSystem\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   GenericSystem_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> GenericSystem\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Basic power system model using either capacity, capacity factor, and heat rate, or an hourly power generation profile as input");


static int
GenericSystemModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	GenericSystem_Type.tp_dict = PyDict_New();
	if (!GenericSystem_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to GenericSystem_Type
	PyObject* AdjustmentFactorsModule = PyImport_ImportModule("AdjustmentFactors");
	if (!AdjustmentFactorsModule){
		PyErr_SetImportError(PyUnicode_FromString("Could not import AdjustmentFactors module."), NULL, NULL);
	}

	PyTypeObject* AdjustmentFactors_Type = (PyTypeObject*)PyObject_GetAttrString(AdjustmentFactorsModule, "AdjustmentFactors");
	if (!AdjustmentFactors_Type){
		PyErr_SetImportError(PyUnicode_FromString("Could not import AdjustmentFactors type."), NULL, NULL);
	}
	Py_XDECREF(AdjustmentFactorsModule);

	if (PyType_Ready(AdjustmentFactors_Type) < 0) { goto fail; }
	PyDict_SetItemString(GenericSystem_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the Plant type object to GenericSystem_Type
	if (PyType_Ready(&Plant_Type) < 0) { goto fail; }
	PyDict_SetItemString(GenericSystem_Type.tp_dict,
				"Plant",
				(PyObject*)&Plant_Type);
	Py_DECREF(&Plant_Type);

	/// Add the Lifetime type object to GenericSystem_Type
	if (PyType_Ready(&Lifetime_Type) < 0) { goto fail; }
	PyDict_SetItemString(GenericSystem_Type.tp_dict,
				"Lifetime",
				(PyObject*)&Lifetime_Type);
	Py_DECREF(&Lifetime_Type);

	/// Add the Outputs type object to GenericSystem_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(GenericSystem_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the GenericSystem type object to the module
	if (PyType_Ready(&GenericSystem_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"GenericSystem",
				(PyObject*)&GenericSystem_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot GenericSystemModule_slots[] = {
		{Py_mod_exec, GenericSystemModule_exec},
		{0, NULL},
};

static struct PyModuleDef GenericSystemModule = {
		PyModuleDef_HEAD_INIT,
		"GenericSystem",
		module_doc,
		0,
		GenericSystemModule_methods,
		GenericSystemModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_GenericSystem(void)
{
	return PyModuleDef_Init(&GenericSystemModule);
}