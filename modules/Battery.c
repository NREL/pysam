#include <Python.h>

#include <SAM_Battery.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Simulation Group
 */ 

static PyTypeObject Simulation_Type;

static PyObject *
Simulation_new(SAM_Battery data_ptr)
{
	PyObject* new_obj = Simulation_Type.tp_alloc(&Simulation_Type,0);

	VarGroupObject* Simulation_obj = (VarGroupObject*)new_obj;

	Simulation_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Simulation methods */

static PyObject *
Simulation_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "Simulation")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Simulation_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Simulation_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battery", "Simulation")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Simulation_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Simulation_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Simulation_methods[] = {
		{"assign",            (PyCFunction)Simulation_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Simulation_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Simulation_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Simulation_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Simulation_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Simulation_get_percent_complete(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Simulation_percent_complete_nget, self->data_ptr);
}

static int
Simulation_set_percent_complete(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Simulation_percent_complete_nset, self->data_ptr);
}

static PyGetSetDef Simulation_getset[] = {
{"percent_complete", (getter)Simulation_get_percent_complete,(setter)Simulation_set_percent_complete,
	PyDoc_STR("*float*: Estimated simulation status [%]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Simulation_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.Simulation",             /*tp_name*/
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
		Simulation_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Simulation_getset,          /*tp_getset*/
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
Lifetime_new(SAM_Battery data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "Lifetime")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battery", "Lifetime")){
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
	return PySAM_double_getter(SAM_Battery_Lifetime_analysis_period_nget, self->data_ptr);
}

static int
Lifetime_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Lifetime_analysis_period_nset, self->data_ptr);
}

static PyObject *
Lifetime_get_inflation_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Lifetime_inflation_rate_nget, self->data_ptr);
}

static int
Lifetime_set_inflation_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Lifetime_inflation_rate_nset, self->data_ptr);
}

static PyObject *
Lifetime_get_system_use_lifetime_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Lifetime_system_use_lifetime_output_nget, self->data_ptr);
}

static int
Lifetime_set_system_use_lifetime_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Lifetime_system_use_lifetime_output_nset, self->data_ptr);
}

static PyGetSetDef Lifetime_getset[] = {
{"analysis_period", (getter)Lifetime_get_analysis_period,(setter)Lifetime_set_analysis_period,
	PyDoc_STR("*float*: Lifetime analysis period [years]\n\n**Info:**\nThe number of years in the simulation\n\n**Required:**\nRequired if system_use_lifetime_output=1"),
 	NULL},
{"inflation_rate", (getter)Lifetime_get_inflation_rate,(setter)Lifetime_set_inflation_rate,
	PyDoc_STR("*float*: Inflation rate [%]\n\n**Constraints:**\nMIN=-99\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"system_use_lifetime_output", (getter)Lifetime_get_system_use_lifetime_output,(setter)Lifetime_set_system_use_lifetime_output,
	PyDoc_STR("*float*: Lifetime simulation [0/1]\n\n**Options:**\n0=SingleYearRepeated,1=RunEveryYear\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Lifetime_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.Lifetime",             /*tp_name*/
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
 * BatterySystem Group
 */ 

static PyTypeObject BatterySystem_Type;

static PyObject *
BatterySystem_new(SAM_Battery data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "BatterySystem")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battery", "BatterySystem")){
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
BatterySystem_get_batt_ac_dc_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_ac_dc_efficiency_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_ac_dc_efficiency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_ac_dc_efficiency_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_ac_or_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_ac_or_dc_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_ac_or_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_ac_or_dc_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_computed_bank_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_computed_bank_capacity_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_computed_bank_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_computed_bank_capacity_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_computed_series(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_computed_series_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_computed_series(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_computed_series_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_computed_strings(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_computed_strings_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_computed_strings(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_computed_strings_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_current_charge_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_current_charge_max_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_current_charge_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_current_charge_max_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_current_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_current_choice_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_current_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_current_choice_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_current_discharge_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_current_discharge_max_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_current_discharge_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_current_discharge_max_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_dc_ac_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_dc_ac_efficiency_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_dc_ac_efficiency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_dc_ac_efficiency_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_dc_dc_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_dc_dc_efficiency_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_dc_dc_efficiency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_dc_dc_efficiency_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_inverter_efficiency_cutoff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_inverter_efficiency_cutoff_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_inverter_efficiency_cutoff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_inverter_efficiency_cutoff_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_loss_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_loss_choice_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_loss_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_loss_choice_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_losses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatterySystem_batt_losses_aget, self->data_ptr);
}

static int
BatterySystem_set_batt_losses(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatterySystem_batt_losses_aset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_losses_charging(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatterySystem_batt_losses_charging_aget, self->data_ptr);
}

static int
BatterySystem_set_batt_losses_charging(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatterySystem_batt_losses_charging_aset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_losses_discharging(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatterySystem_batt_losses_discharging_aget, self->data_ptr);
}

static int
BatterySystem_set_batt_losses_discharging(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatterySystem_batt_losses_discharging_aset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_losses_idle(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatterySystem_batt_losses_idle_aget, self->data_ptr);
}

static int
BatterySystem_set_batt_losses_idle(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatterySystem_batt_losses_idle_aset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_mass(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_mass_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_mass(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_mass_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_meter_position(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_meter_position_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_meter_position(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_meter_position_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_power_charge_max_kwac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_power_charge_max_kwac_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_power_charge_max_kwac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_power_charge_max_kwac_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_power_charge_max_kwdc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_power_charge_max_kwdc_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_power_charge_max_kwdc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_power_charge_max_kwdc_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_power_discharge_max_kwac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_power_discharge_max_kwac_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_power_discharge_max_kwac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_power_discharge_max_kwac_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_power_discharge_max_kwdc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_power_discharge_max_kwdc_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_power_discharge_max_kwdc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_power_discharge_max_kwdc_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_replacement_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_replacement_capacity_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_replacement_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_replacement_capacity_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_replacement_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_replacement_option_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_replacement_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_replacement_option_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_replacement_schedule_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatterySystem_batt_replacement_schedule_percent_aget, self->data_ptr);
}

static int
BatterySystem_set_batt_replacement_schedule_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatterySystem_batt_replacement_schedule_percent_aset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_surface_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_surface_area_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_surface_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_surface_area_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_en_batt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_en_batt_nget, self->data_ptr);
}

static int
BatterySystem_set_en_batt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_en_batt_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_en_standalone_batt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_en_standalone_batt_nget, self->data_ptr);
}

static int
BatterySystem_set_en_standalone_batt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_en_standalone_batt_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_en_wave_batt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_en_wave_batt_nget, self->data_ptr);
}

static int
BatterySystem_set_en_wave_batt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_en_wave_batt_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_om_replacement_cost1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatterySystem_om_replacement_cost1_aget, self->data_ptr);
}

static int
BatterySystem_set_om_replacement_cost1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatterySystem_om_replacement_cost1_aset, self->data_ptr);
}

static PyGetSetDef BatterySystem_getset[] = {
{"batt_ac_dc_efficiency", (getter)BatterySystem_get_batt_ac_dc_efficiency,(setter)BatterySystem_set_batt_ac_dc_efficiency,
	PyDoc_STR("*float*: Inverter AC to battery DC efficiency\n\nThe value of the following variables depends on ``batt_ac_dc_efficiency``:\n\n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"batt_ac_or_dc", (getter)BatterySystem_get_batt_ac_or_dc,(setter)BatterySystem_set_batt_ac_or_dc,
	PyDoc_STR("*float*: Battery interconnection (AC or DC)\n\n**Options:**\n0=DC_Connected,1=AC_Connected\n\nThe value of the following variables depends on ``batt_ac_or_dc``:\n\n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"batt_computed_bank_capacity", (getter)BatterySystem_get_batt_computed_bank_capacity,(setter)BatterySystem_set_batt_computed_bank_capacity,
	PyDoc_STR("*float*: Battery computed bank capacity [kWh]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\nThe value of the following variables depends on ``batt_computed_bank_capacity``:\n\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_mass\n\t - batt_surface_area\n\n\nThe value of ``batt_computed_bank_capacity`` depends on the following variables:\n\n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_dc_efficiency\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_computed_series", (getter)BatterySystem_get_batt_computed_series,(setter)BatterySystem_set_batt_computed_series,
	PyDoc_STR("*float*: Battery number of cells in series\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\nThe value of ``batt_computed_series`` depends on the following variables:\n\n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_dc_efficiency\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_computed_strings", (getter)BatterySystem_get_batt_computed_strings,(setter)BatterySystem_set_batt_computed_strings,
	PyDoc_STR("*float*: Battery number of strings of cells\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\nThe value of the following variables depends on ``batt_computed_strings``:\n\n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\n\nThe value of ``batt_computed_strings`` depends on the following variables:\n\n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_dc_efficiency\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_current_charge_max", (getter)BatterySystem_get_batt_current_charge_max,(setter)BatterySystem_set_batt_current_charge_max,
	PyDoc_STR("*float*: Battery maximum charge current [A]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\nThe value of ``batt_current_charge_max`` depends on the following variables:\n\n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_dc_efficiency\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_current_choice", (getter)BatterySystem_get_batt_current_choice,(setter)BatterySystem_set_batt_current_choice,
	PyDoc_STR("*float*: Limit cells by current or power\n\nThe value of the following variables depends on ``batt_current_choice``:\n\n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"batt_current_discharge_max", (getter)BatterySystem_get_batt_current_discharge_max,(setter)BatterySystem_set_batt_current_discharge_max,
	PyDoc_STR("*float*: Battery maximum discharge current [A]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\nThe value of ``batt_current_discharge_max`` depends on the following variables:\n\n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_dc_efficiency\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_dc_ac_efficiency", (getter)BatterySystem_get_batt_dc_ac_efficiency,(setter)BatterySystem_set_batt_dc_ac_efficiency,
	PyDoc_STR("*float*: Battery DC to AC efficiency\n\nThe value of the following variables depends on ``batt_dc_ac_efficiency``:\n\n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"batt_dc_dc_efficiency", (getter)BatterySystem_get_batt_dc_dc_efficiency,(setter)BatterySystem_set_batt_dc_dc_efficiency,
	PyDoc_STR("*float*: System DC to battery DC efficiency\n\nThe value of the following variables depends on ``batt_dc_dc_efficiency``:\n\n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"batt_inverter_efficiency_cutoff", (getter)BatterySystem_get_batt_inverter_efficiency_cutoff,(setter)BatterySystem_set_batt_inverter_efficiency_cutoff,
	PyDoc_STR("*float*: Inverter efficiency at which to cut battery charge or discharge off [%]"),
 	NULL},
{"batt_loss_choice", (getter)BatterySystem_get_batt_loss_choice,(setter)BatterySystem_set_batt_loss_choice,
	PyDoc_STR("*float*: Loss power input option [0/1]\n\n**Options:**\n0=Monthly,1=TimeSeries\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_losses", (getter)BatterySystem_get_batt_losses,(setter)BatterySystem_set_batt_losses,
	PyDoc_STR("*sequence*: Battery system losses at each timestep (kW DC for DC connected, AC for AC connected) [kW]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_losses_charging", (getter)BatterySystem_get_batt_losses_charging,(setter)BatterySystem_set_batt_losses_charging,
	PyDoc_STR("*sequence*: Battery system losses when charging (kW DC for DC connected, AC for AC connected) [kW]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_losses_discharging", (getter)BatterySystem_get_batt_losses_discharging,(setter)BatterySystem_set_batt_losses_discharging,
	PyDoc_STR("*sequence*: Battery system losses when discharging (kW DC for DC connected, AC for AC connected) [kW]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_losses_idle", (getter)BatterySystem_get_batt_losses_idle,(setter)BatterySystem_set_batt_losses_idle,
	PyDoc_STR("*sequence*: Battery system losses when idle (kW DC for DC connected, AC for AC connected) [kW]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_mass", (getter)BatterySystem_get_batt_mass,(setter)BatterySystem_set_batt_mass,
	PyDoc_STR("*float*: Battery mass [kg]\n\nThe value of ``batt_mass`` depends on the following variables:\n\n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_dc_efficiency\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_computed_bank_capacity\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_meter_position", (getter)BatterySystem_get_batt_meter_position,(setter)BatterySystem_set_batt_meter_position,
	PyDoc_STR("*float*: Position of battery relative to electric meter\n\n**Options:**\n0=BehindTheMeter,1=FrontOfMeter"),
 	NULL},
{"batt_power_charge_max_kwac", (getter)BatterySystem_get_batt_power_charge_max_kwac,(setter)BatterySystem_set_batt_power_charge_max_kwac,
	PyDoc_STR("*float*: Battery maximum charge power (AC) [kWac]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\nThe value of ``batt_power_charge_max_kwac`` depends on the following variables:\n\n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_dc_efficiency\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_power_charge_max_kwdc", (getter)BatterySystem_get_batt_power_charge_max_kwdc,(setter)BatterySystem_set_batt_power_charge_max_kwdc,
	PyDoc_STR("*float*: Battery maximum charge power (DC) [kWdc]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\nThe value of ``batt_power_charge_max_kwdc`` depends on the following variables:\n\n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_dc_efficiency\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_power_discharge_max_kwac", (getter)BatterySystem_get_batt_power_discharge_max_kwac,(setter)BatterySystem_set_batt_power_discharge_max_kwac,
	PyDoc_STR("*float*: Battery maximum discharge power (AC) [kWac]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\nThe value of ``batt_power_discharge_max_kwac`` depends on the following variables:\n\n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_dc_efficiency\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_power_discharge_max_kwdc", (getter)BatterySystem_get_batt_power_discharge_max_kwdc,(setter)BatterySystem_set_batt_power_discharge_max_kwdc,
	PyDoc_STR("*float*: Battery maximum discharge power (DC) [kWdc]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\nThe value of ``batt_power_discharge_max_kwdc`` depends on the following variables:\n\n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_dc_efficiency\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_replacement_capacity", (getter)BatterySystem_get_batt_replacement_capacity,(setter)BatterySystem_set_batt_replacement_capacity,
	PyDoc_STR("*float*: Capacity degradation at which to replace battery [%]"),
 	NULL},
{"batt_replacement_option", (getter)BatterySystem_get_batt_replacement_option,(setter)BatterySystem_set_batt_replacement_option,
	PyDoc_STR("*float*: Enable battery replacement? [0=none,1=capacity based,2=user schedule]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_replacement_schedule_percent", (getter)BatterySystem_get_batt_replacement_schedule_percent,(setter)BatterySystem_set_batt_replacement_schedule_percent,
	PyDoc_STR("*sequence*: Percentage of battery capacity to replace in each year [%]\n\n**Options:**\nlength <= analysis_period\n\n**Required:**\nRequired if batt_replacement_option=2"),
 	NULL},
{"batt_surface_area", (getter)BatterySystem_get_batt_surface_area,(setter)BatterySystem_set_batt_surface_area,
	PyDoc_STR("*float*: Battery surface area [m^2]\n\nThe value of ``batt_surface_area`` depends on the following variables:\n\n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_dc_efficiency\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_computed_bank_capacity\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"en_batt", (getter)BatterySystem_get_en_batt,(setter)BatterySystem_set_en_batt,
	PyDoc_STR("*float*: Enable battery storage model [0/1]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"en_standalone_batt", (getter)BatterySystem_get_en_standalone_batt,(setter)BatterySystem_set_en_standalone_batt,
	PyDoc_STR("*float*: Enable standalone battery storage model [0/1]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"en_wave_batt", (getter)BatterySystem_get_en_wave_batt,(setter)BatterySystem_set_en_wave_batt,
	PyDoc_STR("*float*: Enable wave battery storage model [0/1]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_replacement_cost1", (getter)BatterySystem_get_om_replacement_cost1,(setter)BatterySystem_set_om_replacement_cost1,
	PyDoc_STR("*sequence*: Cost to replace battery per kWh [$/kWh]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject BatterySystem_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.BatterySystem",             /*tp_name*/
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
 * SystemOutput Group
 */ 

static PyTypeObject SystemOutput_Type;

static PyObject *
SystemOutput_new(SAM_Battery data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "SystemOutput")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battery", "SystemOutput")){
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
SystemOutput_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_SystemOutput_annual_energy_nget, self->data_ptr);
}

static int
SystemOutput_set_annual_energy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_SystemOutput_annual_energy_nset, self->data_ptr);
}

static PyObject *
SystemOutput_get_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_SystemOutput_capacity_factor_nget, self->data_ptr);
}

static int
SystemOutput_set_capacity_factor(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_SystemOutput_capacity_factor_nset, self->data_ptr);
}

static PyObject *
SystemOutput_get_energy_hourly_kW(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_SystemOutput_energy_hourly_kW_aget, self->data_ptr);
}

static int
SystemOutput_set_energy_hourly_kW(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_SystemOutput_energy_hourly_kW_aset, self->data_ptr);
}

static PyObject *
SystemOutput_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_SystemOutput_gen_aget, self->data_ptr);
}

static int
SystemOutput_set_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_SystemOutput_gen_aset, self->data_ptr);
}

static PyGetSetDef SystemOutput_getset[] = {
{"annual_energy", (getter)SystemOutput_get_annual_energy,(setter)SystemOutput_set_annual_energy,
	PyDoc_STR("*float*: Annual Energy [kWh]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"capacity_factor", (getter)SystemOutput_get_capacity_factor,(setter)SystemOutput_set_capacity_factor,
	PyDoc_STR("*float*: Capacity factor [%]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"energy_hourly_kW", (getter)SystemOutput_get_energy_hourly_kW,(setter)SystemOutput_set_energy_hourly_kW,
	PyDoc_STR("*sequence*: Power output of array [kW]\n\n**Info:**\nLifetime system generation\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Required:**\nRequired if en_wave_batt=1"),
 	NULL},
{"gen", (getter)SystemOutput_get_gen,(setter)SystemOutput_set_gen,
	PyDoc_STR("*sequence*: System power generated [kW]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemOutput_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.SystemOutput",             /*tp_name*/
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
Load_new(SAM_Battery data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "Load")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battery", "Load")){
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
Load_get_crit_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Load_crit_load_aget, self->data_ptr);
}

static int
Load_set_crit_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_Load_crit_load_aset, self->data_ptr);
}

static PyObject *
Load_get_crit_load_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Load_crit_load_escalation_aget, self->data_ptr);
}

static int
Load_set_crit_load_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_Load_crit_load_escalation_aset, self->data_ptr);
}

static PyObject *
Load_get_grid_outage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Load_grid_outage_aget, self->data_ptr);
}

static int
Load_set_grid_outage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_Load_grid_outage_aset, self->data_ptr);
}

static PyObject *
Load_get_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Load_load_aget, self->data_ptr);
}

static int
Load_set_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_Load_load_aset, self->data_ptr);
}

static PyObject *
Load_get_load_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Load_load_escalation_aget, self->data_ptr);
}

static int
Load_set_load_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_Load_load_escalation_aset, self->data_ptr);
}

static PyObject *
Load_get_run_resiliency_calcs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Load_run_resiliency_calcs_nget, self->data_ptr);
}

static int
Load_set_run_resiliency_calcs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Load_run_resiliency_calcs_nset, self->data_ptr);
}

static PyGetSetDef Load_getset[] = {
{"crit_load", (getter)Load_get_crit_load,(setter)Load_set_crit_load,
	PyDoc_STR("*sequence*: Critical electricity load (year 1) [kW]"),
 	NULL},
{"crit_load_escalation", (getter)Load_get_crit_load_escalation,(setter)Load_set_crit_load_escalation,
	PyDoc_STR("*sequence*: Annual critical load escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"grid_outage", (getter)Load_get_grid_outage,(setter)Load_set_grid_outage,
	PyDoc_STR("*sequence*: Grid outage in this time step [0/1]\n\n**Options:**\n0=GridAvailable,1=GridUnavailable,Length=load"),
 	NULL},
{"load", (getter)Load_get_load,(setter)Load_set_load,
	PyDoc_STR("*sequence*: Electricity load (year 1) [kW]\n\nThe value of the following variables depends on ``load``:\n\n\t - batt_room_temperature_celsius\n"),
 	NULL},
{"load_escalation", (getter)Load_get_load_escalation,(setter)Load_set_load_escalation,
	PyDoc_STR("*sequence*: Annual load escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults.\n\nThe value of the following variables depends on ``load_escalation``:\n\n\t - batt_load_ac_forecast_escalation\n"),
 	NULL},
{"run_resiliency_calcs", (getter)Load_get_run_resiliency_calcs,(setter)Load_set_run_resiliency_calcs,
	PyDoc_STR("*float*: Enable resilence calculations for every timestep [0/1]\n\n**Options:**\n0=DisableCalcs,1=EnableCalcs\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Load_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.Load",             /*tp_name*/
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
 * BatteryCell Group
 */ 

static PyTypeObject BatteryCell_Type;

static PyObject *
BatteryCell_new(SAM_Battery data_ptr)
{
	PyObject* new_obj = BatteryCell_Type.tp_alloc(&BatteryCell_Type,0);

	VarGroupObject* BatteryCell_obj = (VarGroupObject*)new_obj;

	BatteryCell_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* BatteryCell methods */

static PyObject *
BatteryCell_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "BatteryCell")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
BatteryCell_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &BatteryCell_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battery", "BatteryCell")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
BatteryCell_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &BatteryCell_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef BatteryCell_methods[] = {
		{"assign",            (PyCFunction)BatteryCell_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``BatteryCell_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)BatteryCell_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``BatteryCell_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)BatteryCell_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
BatteryCell_get_LeadAcid_q10_computed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_LeadAcid_q10_computed_nget, self->data_ptr);
}

static int
BatteryCell_set_LeadAcid_q10_computed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_LeadAcid_q10_computed_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_LeadAcid_q20_computed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_LeadAcid_q20_computed_nget, self->data_ptr);
}

static int
BatteryCell_set_LeadAcid_q20_computed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_LeadAcid_q20_computed_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_LeadAcid_qn_computed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_LeadAcid_qn_computed_nget, self->data_ptr);
}

static int
BatteryCell_set_LeadAcid_qn_computed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_LeadAcid_qn_computed_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_LeadAcid_tn(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_LeadAcid_tn_nget, self->data_ptr);
}

static int
BatteryCell_set_LeadAcid_tn(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_LeadAcid_tn_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_C_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_C_rate_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_C_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_C_rate_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Cp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_Cp_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Cp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_Cp_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Qexp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_Qexp_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Qexp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_Qexp_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Qfull(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_Qfull_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Qfull(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_Qfull_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Qfull_flow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_Qfull_flow_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Qfull_flow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_Qfull_flow_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Qnom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_Qnom_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Qnom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_Qnom_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Vcut(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_Vcut_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Vcut(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_Vcut_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Vexp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_Vexp_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Vexp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_Vexp_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Vfull(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_Vfull_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Vfull(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_Vfull_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Vnom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_Vnom_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Vnom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_Vnom_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Vnom_default(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_Vnom_default_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Vnom_default(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_Vnom_default_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_calendar_a(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_calendar_a_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_calendar_a(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_calendar_a_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_calendar_b(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_calendar_b_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_calendar_b(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_calendar_b_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_calendar_c(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_calendar_c_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_calendar_c(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_calendar_c_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_calendar_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_calendar_choice_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_calendar_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_calendar_choice_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_calendar_lifetime_matrix(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_BatteryCell_batt_calendar_lifetime_matrix_mget, self->data_ptr);
}

static int
BatteryCell_set_batt_calendar_lifetime_matrix(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_BatteryCell_batt_calendar_lifetime_matrix_mset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_calendar_q0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_calendar_q0_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_calendar_q0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_calendar_q0_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_chem(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_chem_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_chem(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_chem_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_h_to_ambient(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_h_to_ambient_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_h_to_ambient(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_h_to_ambient_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_initial_SOC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_initial_SOC_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_initial_SOC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_initial_SOC_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_life_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_life_model_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_life_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_life_model_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_lifetime_matrix(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_BatteryCell_batt_lifetime_matrix_mget, self->data_ptr);
}

static int
BatteryCell_set_batt_lifetime_matrix(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_BatteryCell_batt_lifetime_matrix_mset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_maximum_SOC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_maximum_SOC_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_maximum_SOC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_maximum_SOC_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_minimum_SOC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_minimum_SOC_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_minimum_SOC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_minimum_SOC_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_minimum_modetime(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_minimum_modetime_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_minimum_modetime(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_minimum_modetime_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_minimum_outage_SOC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_minimum_outage_SOC_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_minimum_outage_SOC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_minimum_outage_SOC_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_resistance(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_resistance_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_resistance(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_resistance_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_room_temperature_celsius(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatteryCell_batt_room_temperature_celsius_aget, self->data_ptr);
}

static int
BatteryCell_set_batt_room_temperature_celsius(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatteryCell_batt_room_temperature_celsius_aset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_voltage_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryCell_batt_voltage_choice_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_voltage_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryCell_batt_voltage_choice_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_voltage_matrix(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_BatteryCell_batt_voltage_matrix_mget, self->data_ptr);
}

static int
BatteryCell_set_batt_voltage_matrix(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_BatteryCell_batt_voltage_matrix_mset, self->data_ptr);
}

static PyObject *
BatteryCell_get_cap_vs_temp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_BatteryCell_cap_vs_temp_mget, self->data_ptr);
}

static int
BatteryCell_set_cap_vs_temp(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_BatteryCell_cap_vs_temp_mset, self->data_ptr);
}

static PyGetSetDef BatteryCell_getset[] = {
{"LeadAcid_q10_computed", (getter)BatteryCell_get_LeadAcid_q10_computed,(setter)BatteryCell_set_LeadAcid_q10_computed,
	PyDoc_STR("*float*: Capacity at 10-hour discharge rate [Ah]\n\nThe value of ``LeadAcid_q10_computed`` depends on the following variables:\n\n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_dc_efficiency\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_computed_strings\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"LeadAcid_q20_computed", (getter)BatteryCell_get_LeadAcid_q20_computed,(setter)BatteryCell_set_LeadAcid_q20_computed,
	PyDoc_STR("*float*: Capacity at 20-hour discharge rate [Ah]\n\nThe value of ``LeadAcid_q20_computed`` depends on the following variables:\n\n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_dc_efficiency\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_computed_strings\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"LeadAcid_qn_computed", (getter)BatteryCell_get_LeadAcid_qn_computed,(setter)BatteryCell_set_LeadAcid_qn_computed,
	PyDoc_STR("*float*: Capacity at discharge rate for n-hour rate [Ah]\n\nThe value of ``LeadAcid_qn_computed`` depends on the following variables:\n\n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_dc_efficiency\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_computed_strings\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"LeadAcid_tn", (getter)BatteryCell_get_LeadAcid_tn,(setter)BatteryCell_set_LeadAcid_tn,
	PyDoc_STR("*float*: Time to discharge [h]"),
 	NULL},
{"batt_C_rate", (getter)BatteryCell_get_batt_C_rate,(setter)BatteryCell_set_batt_C_rate,
	PyDoc_STR("*float*: Rate at which voltage vs. capacity curve input"),
 	NULL},
{"batt_Cp", (getter)BatteryCell_get_batt_Cp,(setter)BatteryCell_set_batt_Cp,
	PyDoc_STR("*float*: Battery specific heat capacity [J/KgK]"),
 	NULL},
{"batt_Qexp", (getter)BatteryCell_get_batt_Qexp,(setter)BatteryCell_set_batt_Qexp,
	PyDoc_STR("*float*: Cell capacity at end of exponential zone [Ah]\n\nThe value of ``batt_Qexp`` depends on the following variables:\n\n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_dc_efficiency\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_computed_bank_capacity\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_Qfull", (getter)BatteryCell_get_batt_Qfull,(setter)BatteryCell_set_batt_Qfull,
	PyDoc_STR("*float*: Fully charged cell capacity [Ah]\n\nThe value of the following variables depends on ``batt_Qfull``:\n\n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"batt_Qfull_flow", (getter)BatteryCell_get_batt_Qfull_flow,(setter)BatteryCell_set_batt_Qfull_flow,
	PyDoc_STR("*float*: Fully charged flow battery capacity [Ah]\n\nThe value of ``batt_Qfull_flow`` depends on the following variables:\n\n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_dc_efficiency\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_computed_bank_capacity\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_Qnom", (getter)BatteryCell_get_batt_Qnom,(setter)BatteryCell_set_batt_Qnom,
	PyDoc_STR("*float*: Cell capacity at end of nominal zone [Ah]\n\nThe value of ``batt_Qnom`` depends on the following variables:\n\n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_dc_efficiency\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_computed_bank_capacity\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_Vcut", (getter)BatteryCell_get_batt_Vcut,(setter)BatteryCell_set_batt_Vcut,
	PyDoc_STR("*float*: Cutoff voltage for battery rated capacity [V]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_Vexp", (getter)BatteryCell_get_batt_Vexp,(setter)BatteryCell_set_batt_Vexp,
	PyDoc_STR("*float*: Cell voltage at end of exponential zone [V]"),
 	NULL},
{"batt_Vfull", (getter)BatteryCell_get_batt_Vfull,(setter)BatteryCell_set_batt_Vfull,
	PyDoc_STR("*float*: Fully charged cell voltage [V]"),
 	NULL},
{"batt_Vnom", (getter)BatteryCell_get_batt_Vnom,(setter)BatteryCell_set_batt_Vnom,
	PyDoc_STR("*float*: Cell voltage at end of nominal zone [V]"),
 	NULL},
{"batt_Vnom_default", (getter)BatteryCell_get_batt_Vnom_default,(setter)BatteryCell_set_batt_Vnom_default,
	PyDoc_STR("*float*: Default nominal cell voltage [V]\n\nThe value of the following variables depends on ``batt_Vnom_default``:\n\n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"batt_calendar_a", (getter)BatteryCell_get_batt_calendar_a,(setter)BatteryCell_set_batt_calendar_a,
	PyDoc_STR("*float*: Calendar life model coefficient [1/sqrt(day)]\n\n**Required:**\nRequired if en_batt=1&batt_life_model=0&batt_calendar_choice=1"),
 	NULL},
{"batt_calendar_b", (getter)BatteryCell_get_batt_calendar_b,(setter)BatteryCell_set_batt_calendar_b,
	PyDoc_STR("*float*: Calendar life model coefficient [K]\n\n**Required:**\nRequired if en_batt=1&batt_life_model=0&batt_calendar_choice=1"),
 	NULL},
{"batt_calendar_c", (getter)BatteryCell_get_batt_calendar_c,(setter)BatteryCell_set_batt_calendar_c,
	PyDoc_STR("*float*: Calendar life model coefficient [K]\n\n**Required:**\nRequired if en_batt=1&batt_life_model=0&batt_calendar_choice=1"),
 	NULL},
{"batt_calendar_choice", (getter)BatteryCell_get_batt_calendar_choice,(setter)BatteryCell_set_batt_calendar_choice,
	PyDoc_STR("*float*: Calendar life degradation input option [0/1/2]\n\n**Options:**\n0=NoCalendarDegradation,1=LithiomIonModel,2=InputLossTable\n\n**Required:**\nRequired if en_batt=1&batt_life_model=0"),
 	NULL},
{"batt_calendar_lifetime_matrix", (getter)BatteryCell_get_batt_calendar_lifetime_matrix,(setter)BatteryCell_set_batt_calendar_lifetime_matrix,
	PyDoc_STR("*sequence[sequence]*: Days vs capacity\n\n**Required:**\nRequired if en_batt=1&batt_life_model=0&batt_calendar_choice=2"),
 	NULL},
{"batt_calendar_q0", (getter)BatteryCell_get_batt_calendar_q0,(setter)BatteryCell_set_batt_calendar_q0,
	PyDoc_STR("*float*: Calendar life model initial capacity cofficient\n\n**Required:**\nRequired if en_batt=1&batt_life_model=0&batt_calendar_choice=1"),
 	NULL},
{"batt_chem", (getter)BatteryCell_get_batt_chem,(setter)BatteryCell_set_batt_chem,
	PyDoc_STR("*float*: Battery chemistry\n\n**Options:**\n0=LeadAcid,1=LiIon\n\nThe value of the following variables depends on ``batt_chem``:\n\n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"batt_h_to_ambient", (getter)BatteryCell_get_batt_h_to_ambient,(setter)BatteryCell_set_batt_h_to_ambient,
	PyDoc_STR("*float*: Heat transfer between battery and environment [W/m2K]"),
 	NULL},
{"batt_initial_SOC", (getter)BatteryCell_get_batt_initial_SOC,(setter)BatteryCell_set_batt_initial_SOC,
	PyDoc_STR("*float*: Initial state-of-charge [%]"),
 	NULL},
{"batt_life_model", (getter)BatteryCell_get_batt_life_model,(setter)BatteryCell_set_batt_life_model,
	PyDoc_STR("*float*: Battery life model specifier [0/1/2]\n\n**Options:**\n0=calendar/cycle,1=NMC,2=LMO/LTO\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_lifetime_matrix", (getter)BatteryCell_get_batt_lifetime_matrix,(setter)BatteryCell_set_batt_lifetime_matrix,
	PyDoc_STR("*sequence[sequence]*: Cycles vs capacity at different depths-of-discharge\n\n**Required:**\nRequired if en_batt=1&batt_life_model=0"),
 	NULL},
{"batt_maximum_SOC", (getter)BatteryCell_get_batt_maximum_SOC,(setter)BatteryCell_set_batt_maximum_SOC,
	PyDoc_STR("*float*: Maximum allowed state-of-charge [%]"),
 	NULL},
{"batt_minimum_SOC", (getter)BatteryCell_get_batt_minimum_SOC,(setter)BatteryCell_set_batt_minimum_SOC,
	PyDoc_STR("*float*: Minimum allowed state-of-charge during nominal operation [%]"),
 	NULL},
{"batt_minimum_modetime", (getter)BatteryCell_get_batt_minimum_modetime,(setter)BatteryCell_set_batt_minimum_modetime,
	PyDoc_STR("*float*: Minimum time at charge state [min]"),
 	NULL},
{"batt_minimum_outage_SOC", (getter)BatteryCell_get_batt_minimum_outage_SOC,(setter)BatteryCell_set_batt_minimum_outage_SOC,
	PyDoc_STR("*float*: Minimum allowed state-of-charge during an outage [%]"),
 	NULL},
{"batt_resistance", (getter)BatteryCell_get_batt_resistance,(setter)BatteryCell_set_batt_resistance,
	PyDoc_STR("*float*: Internal resistance [Ohm]"),
 	NULL},
{"batt_room_temperature_celsius", (getter)BatteryCell_get_batt_room_temperature_celsius,(setter)BatteryCell_set_batt_room_temperature_celsius,
	PyDoc_STR("*sequence*: Temperature of storage room [C]\n\n**Options:**\nlength=1 for fixed, # of weatherfile records otherwise\n\nThe value of ``batt_room_temperature_celsius`` depends on the following variables:\n\n\t - grid_curtailment\n"),
 	NULL},
{"batt_voltage_choice", (getter)BatteryCell_get_batt_voltage_choice,(setter)BatteryCell_set_batt_voltage_choice,
	PyDoc_STR("*float*: Battery voltage input option [0/1]\n\n**Options:**\n0=UseVoltageModel,1=InputVoltageTable\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_voltage_matrix", (getter)BatteryCell_get_batt_voltage_matrix,(setter)BatteryCell_set_batt_voltage_matrix,
	PyDoc_STR("*sequence[sequence]*: Battery voltage vs. depth-of-discharge"),
 	NULL},
{"cap_vs_temp", (getter)BatteryCell_get_cap_vs_temp,(setter)BatteryCell_set_cap_vs_temp,
	PyDoc_STR("*sequence[sequence]*: Effective capacity as function of temperature [C,%]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject BatteryCell_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.BatteryCell",             /*tp_name*/
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
		BatteryCell_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		BatteryCell_getset,          /*tp_getset*/
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
 * Inverter Group
 */ 

static PyTypeObject Inverter_Type;

static PyObject *
Inverter_new(SAM_Battery data_ptr)
{
	PyObject* new_obj = Inverter_Type.tp_alloc(&Inverter_Type,0);

	VarGroupObject* Inverter_obj = (VarGroupObject*)new_obj;

	Inverter_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Inverter methods */

static PyObject *
Inverter_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "Inverter")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Inverter_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Inverter_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battery", "Inverter")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Inverter_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Inverter_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Inverter_methods[] = {
		{"assign",            (PyCFunction)Inverter_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Inverter_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Inverter_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Inverter_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Inverter_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Inverter_get_inv_cec_cg_eff_cec(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Inverter_inv_cec_cg_eff_cec_nget, self->data_ptr);
}

static int
Inverter_set_inv_cec_cg_eff_cec(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Inverter_inv_cec_cg_eff_cec_nset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_cec_cg_paco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Inverter_inv_cec_cg_paco_nget, self->data_ptr);
}

static int
Inverter_set_inv_cec_cg_paco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Inverter_inv_cec_cg_paco_nset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_ds_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Inverter_inv_ds_eff_nget, self->data_ptr);
}

static int
Inverter_set_inv_ds_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Inverter_inv_ds_eff_nset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_ds_paco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Inverter_inv_ds_paco_nget, self->data_ptr);
}

static int
Inverter_set_inv_ds_paco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Inverter_inv_ds_paco_nset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_pd_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Inverter_inv_pd_eff_nget, self->data_ptr);
}

static int
Inverter_set_inv_pd_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Inverter_inv_pd_eff_nset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_pd_paco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Inverter_inv_pd_paco_nget, self->data_ptr);
}

static int
Inverter_set_inv_pd_paco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Inverter_inv_pd_paco_nset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_snl_eff_cec(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Inverter_inv_snl_eff_cec_nget, self->data_ptr);
}

static int
Inverter_set_inv_snl_eff_cec(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Inverter_inv_snl_eff_cec_nset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_snl_paco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Inverter_inv_snl_paco_nget, self->data_ptr);
}

static int
Inverter_set_inv_snl_paco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Inverter_inv_snl_paco_nset, self->data_ptr);
}

static PyObject *
Inverter_get_inverter_count(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Inverter_inverter_count_nget, self->data_ptr);
}

static int
Inverter_set_inverter_count(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Inverter_inverter_count_nset, self->data_ptr);
}

static PyObject *
Inverter_get_inverter_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Inverter_inverter_model_nget, self->data_ptr);
}

static int
Inverter_set_inverter_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Inverter_inverter_model_nset, self->data_ptr);
}

static PyGetSetDef Inverter_getset[] = {
{"inv_cec_cg_eff_cec", (getter)Inverter_get_inv_cec_cg_eff_cec,(setter)Inverter_set_inv_cec_cg_eff_cec,
	PyDoc_STR("*float*: Inverter Coefficient Generator CEC Efficiency [%]\n\nThe value of the following variables depends on ``inv_cec_cg_eff_cec``:\n\n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"inv_cec_cg_paco", (getter)Inverter_get_inv_cec_cg_paco,(setter)Inverter_set_inv_cec_cg_paco,
	PyDoc_STR("*float*: Inverter Coefficient Generator Max AC Power [Wac]"),
 	NULL},
{"inv_ds_eff", (getter)Inverter_get_inv_ds_eff,(setter)Inverter_set_inv_ds_eff,
	PyDoc_STR("*float*: Inverter Datasheet Efficiency [%]\n\nThe value of the following variables depends on ``inv_ds_eff``:\n\n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"inv_ds_paco", (getter)Inverter_get_inv_ds_paco,(setter)Inverter_set_inv_ds_paco,
	PyDoc_STR("*float*: Inverter Datasheet Maximum AC Power [Wac]"),
 	NULL},
{"inv_pd_eff", (getter)Inverter_get_inv_pd_eff,(setter)Inverter_set_inv_pd_eff,
	PyDoc_STR("*float*: Inverter Partload Efficiency [%]\n\nThe value of the following variables depends on ``inv_pd_eff``:\n\n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"inv_pd_paco", (getter)Inverter_get_inv_pd_paco,(setter)Inverter_set_inv_pd_paco,
	PyDoc_STR("*float*: Inverter Partload Maximum AC Power [Wac]"),
 	NULL},
{"inv_snl_eff_cec", (getter)Inverter_get_inv_snl_eff_cec,(setter)Inverter_set_inv_snl_eff_cec,
	PyDoc_STR("*float*: Inverter Sandia CEC Efficiency [%]\n\nThe value of the following variables depends on ``inv_snl_eff_cec``:\n\n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"inv_snl_paco", (getter)Inverter_get_inv_snl_paco,(setter)Inverter_set_inv_snl_paco,
	PyDoc_STR("*float*: Inverter Sandia Maximum AC Power [Wac]"),
 	NULL},
{"inverter_count", (getter)Inverter_get_inverter_count,(setter)Inverter_set_inverter_count,
	PyDoc_STR("*float*: Number of inverters"),
 	NULL},
{"inverter_model", (getter)Inverter_get_inverter_model,(setter)Inverter_set_inverter_model,
	PyDoc_STR("*float*: Inverter model specifier\n\n**Options:**\n0=cec,1=datasheet,2=partload,3=coefficientgenerator,4=generic\n\n**Constraints:**\nINTEGER,MIN=0,MAX=4\n\n**Required:**\nFalse. Automatically set to 4 if not assigned explicitly or loaded from defaults.\n\nThe value of the following variables depends on ``inverter_model``:\n\n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Inverter_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.Inverter",             /*tp_name*/
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
		Inverter_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Inverter_getset,          /*tp_getset*/
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
 * Losses Group
 */ 

static PyTypeObject Losses_Type;

static PyObject *
Losses_new(SAM_Battery data_ptr)
{
	PyObject* new_obj = Losses_Type.tp_alloc(&Losses_Type,0);

	VarGroupObject* Losses_obj = (VarGroupObject*)new_obj;

	Losses_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Losses methods */

static PyObject *
Losses_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "Losses")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Losses_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Losses_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battery", "Losses")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Losses_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Losses_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Losses_methods[] = {
		{"assign",            (PyCFunction)Losses_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Losses_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Losses_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Losses_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Losses_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Losses_get_dcoptimizer_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Losses_dcoptimizer_loss_nget, self->data_ptr);
}

static int
Losses_set_dcoptimizer_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Losses_dcoptimizer_loss_nset, self->data_ptr);
}

static PyGetSetDef Losses_getset[] = {
{"dcoptimizer_loss", (getter)Losses_get_dcoptimizer_loss,(setter)Losses_set_dcoptimizer_loss,
	PyDoc_STR("*float*: DC optimizer loss"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Losses_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.Losses",             /*tp_name*/
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
		Losses_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Losses_getset,          /*tp_getset*/
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
 * BatteryDispatch Group
 */ 

static PyTypeObject BatteryDispatch_Type;

static PyObject *
BatteryDispatch_new(SAM_Battery data_ptr)
{
	PyObject* new_obj = BatteryDispatch_Type.tp_alloc(&BatteryDispatch_Type,0);

	VarGroupObject* BatteryDispatch_obj = (VarGroupObject*)new_obj;

	BatteryDispatch_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* BatteryDispatch methods */

static PyObject *
BatteryDispatch_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "BatteryDispatch")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
BatteryDispatch_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &BatteryDispatch_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battery", "BatteryDispatch")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
BatteryDispatch_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &BatteryDispatch_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef BatteryDispatch_methods[] = {
		{"assign",            (PyCFunction)BatteryDispatch_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``BatteryDispatch_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)BatteryDispatch_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``BatteryDispatch_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)BatteryDispatch_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
BatteryDispatch_get_batt_custom_dispatch(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatteryDispatch_batt_custom_dispatch_aget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_custom_dispatch(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatteryDispatch_batt_custom_dispatch_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_cycle_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatteryDispatch_batt_cycle_cost_aget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_cycle_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatteryDispatch_batt_cycle_cost_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_cycle_cost_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_cycle_cost_choice_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_cycle_cost_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_cycle_cost_choice_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_auto_btm_can_discharge_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_auto_btm_can_discharge_to_grid_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_auto_btm_can_discharge_to_grid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_auto_btm_can_discharge_to_grid_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_auto_can_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_auto_can_charge_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_auto_can_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_auto_can_charge_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_auto_can_clipcharge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_auto_can_clipcharge_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_auto_can_clipcharge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_auto_can_clipcharge_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_auto_can_fuelcellcharge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_auto_can_fuelcellcharge_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_auto_can_fuelcellcharge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_auto_can_fuelcellcharge_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_auto_can_gridcharge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_auto_can_gridcharge_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_auto_can_gridcharge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_auto_can_gridcharge_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_charge_only_system_exceeds_load(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_charge_only_system_exceeds_load_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_charge_only_system_exceeds_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_charge_only_system_exceeds_load_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_choice_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_choice_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_discharge_only_load_exceeds_system(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_discharge_only_load_exceeds_system_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_discharge_only_load_exceeds_system(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_discharge_only_load_exceeds_system_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_load_forecast_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_load_forecast_choice_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_load_forecast_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_load_forecast_choice_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_ac_lb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_pvs_ac_lb_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_ac_lb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_pvs_ac_lb_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_ac_lb_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_pvs_ac_lb_enable_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_ac_lb_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_pvs_ac_lb_enable_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_ac_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_pvs_ac_ub_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_ac_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_pvs_ac_ub_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_ac_ub_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_pvs_ac_ub_enable_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_ac_ub_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_pvs_ac_ub_enable_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_curtail_as_control(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_pvs_curtail_as_control_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_curtail_as_control(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_pvs_curtail_as_control_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_curtail_if_violation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_pvs_curtail_if_violation_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_curtail_if_violation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_pvs_curtail_if_violation_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_forecast_shift_periods(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_pvs_forecast_shift_periods_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_forecast_shift_periods(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_pvs_forecast_shift_periods_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_kf(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_pvs_kf_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_kf(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_pvs_kf_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_ki(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_pvs_ki_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_ki(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_pvs_ki_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_kp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_pvs_kp_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_kp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_pvs_kp_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_max_ramp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_pvs_max_ramp_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_max_ramp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_pvs_max_ramp_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_nameplate_ac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_pvs_nameplate_ac_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_nameplate_ac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_pvs_nameplate_ac_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_short_forecast_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_pvs_short_forecast_enable_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_short_forecast_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_pvs_short_forecast_enable_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_soc_rest(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_pvs_soc_rest_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_soc_rest(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_pvs_soc_rest_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_timestep_multiplier(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_pvs_timestep_multiplier_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_timestep_multiplier(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_pvs_timestep_multiplier_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_update_frequency_hours(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_update_frequency_hours_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_update_frequency_hours(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_update_frequency_hours_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_wf_forecast_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_dispatch_wf_forecast_choice_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_wf_forecast_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_dispatch_wf_forecast_choice_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_load_ac_forecast(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatteryDispatch_batt_load_ac_forecast_aget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_load_ac_forecast(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatteryDispatch_batt_load_ac_forecast_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_load_ac_forecast_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatteryDispatch_batt_load_ac_forecast_escalation_aget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_load_ac_forecast_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatteryDispatch_batt_load_ac_forecast_escalation_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_look_ahead_hours(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_look_ahead_hours_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_look_ahead_hours(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_look_ahead_hours_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_pv_ac_forecast(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatteryDispatch_batt_pv_ac_forecast_aget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_pv_ac_forecast(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatteryDispatch_batt_pv_ac_forecast_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_pv_clipping_forecast(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatteryDispatch_batt_pv_clipping_forecast_aget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_pv_clipping_forecast(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatteryDispatch_batt_pv_clipping_forecast_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_target_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_target_choice_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_target_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_target_choice_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_target_power(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatteryDispatch_batt_target_power_aget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_target_power(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatteryDispatch_batt_target_power_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_target_power_monthly(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatteryDispatch_batt_target_power_monthly_aget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_target_power_monthly(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatteryDispatch_batt_target_power_monthly_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_btm_discharge_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatteryDispatch_dispatch_manual_btm_discharge_to_grid_aget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_btm_discharge_to_grid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatteryDispatch_dispatch_manual_btm_discharge_to_grid_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_charge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatteryDispatch_dispatch_manual_charge_aget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatteryDispatch_dispatch_manual_charge_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_discharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatteryDispatch_dispatch_manual_discharge_aget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_discharge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatteryDispatch_dispatch_manual_discharge_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_fuelcellcharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatteryDispatch_dispatch_manual_fuelcellcharge_aget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_fuelcellcharge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatteryDispatch_dispatch_manual_fuelcellcharge_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_gridcharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatteryDispatch_dispatch_manual_gridcharge_aget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_gridcharge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatteryDispatch_dispatch_manual_gridcharge_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_percent_discharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatteryDispatch_dispatch_manual_percent_discharge_aget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_percent_discharge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatteryDispatch_dispatch_manual_percent_discharge_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_percent_gridcharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatteryDispatch_dispatch_manual_percent_gridcharge_aget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_percent_gridcharge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatteryDispatch_dispatch_manual_percent_gridcharge_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_sched(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_BatteryDispatch_dispatch_manual_sched_mget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_sched(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_BatteryDispatch_dispatch_manual_sched_mset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_BatteryDispatch_dispatch_manual_sched_weekend_mget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_BatteryDispatch_dispatch_manual_sched_weekend_mset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_system_charge_first(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_dispatch_manual_system_charge_first_nget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_system_charge_first(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_dispatch_manual_system_charge_first_nset, self->data_ptr);
}

static PyGetSetDef BatteryDispatch_getset[] = {
{"batt_custom_dispatch", (getter)BatteryDispatch_get_batt_custom_dispatch,(setter)BatteryDispatch_set_batt_custom_dispatch,
	PyDoc_STR("*sequence*: Custom battery power for every time step [kW]\n\n**Info:**\nkWAC if AC-connected, else kWDC\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_dispatch_choice=2"),
 	NULL},
{"batt_cycle_cost", (getter)BatteryDispatch_get_batt_cycle_cost,(setter)BatteryDispatch_set_batt_cycle_cost,
	PyDoc_STR("*sequence*: Input battery cycle degradaton penalty per year [$/cycle-kWh]\n\n**Info:**\nlength 1 or analysis_period, length 1 will be extended using inflation\n\n**Required:**\nRequired if batt_cycle_cost_choice=1"),
 	NULL},
{"batt_cycle_cost_choice", (getter)BatteryDispatch_get_batt_cycle_cost_choice,(setter)BatteryDispatch_set_batt_cycle_cost_choice,
	PyDoc_STR("*float*: Use SAM cost model for degradaton penalty or input custom via batt_cycle_cost [0/1]\n\n**Options:**\n0=UseCostModel,1=InputCost\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_dispatch_auto_btm_can_discharge_to_grid", (getter)BatteryDispatch_get_batt_dispatch_auto_btm_can_discharge_to_grid,(setter)BatteryDispatch_set_batt_dispatch_auto_btm_can_discharge_to_grid,
	PyDoc_STR("*float*: Behind the meter battery can discharge to grid? [0/1]"),
 	NULL},
{"batt_dispatch_auto_can_charge", (getter)BatteryDispatch_get_batt_dispatch_auto_can_charge,(setter)BatteryDispatch_set_batt_dispatch_auto_can_charge,
	PyDoc_STR("*float*: System charging allowed for automated dispatch? [0/1]"),
 	NULL},
{"batt_dispatch_auto_can_clipcharge", (getter)BatteryDispatch_get_batt_dispatch_auto_can_clipcharge,(setter)BatteryDispatch_set_batt_dispatch_auto_can_clipcharge,
	PyDoc_STR("*float*: Battery can charge from clipped power? [0/1]"),
 	NULL},
{"batt_dispatch_auto_can_fuelcellcharge", (getter)BatteryDispatch_get_batt_dispatch_auto_can_fuelcellcharge,(setter)BatteryDispatch_set_batt_dispatch_auto_can_fuelcellcharge,
	PyDoc_STR("*float*: Charging from fuel cell allowed for automated dispatch? [0/1]"),
 	NULL},
{"batt_dispatch_auto_can_gridcharge", (getter)BatteryDispatch_get_batt_dispatch_auto_can_gridcharge,(setter)BatteryDispatch_set_batt_dispatch_auto_can_gridcharge,
	PyDoc_STR("*float*: Grid charging allowed for automated dispatch? [0/1]"),
 	NULL},
{"batt_dispatch_charge_only_system_exceeds_load", (getter)BatteryDispatch_get_batt_dispatch_charge_only_system_exceeds_load,(setter)BatteryDispatch_set_batt_dispatch_charge_only_system_exceeds_load,
	PyDoc_STR("*float*: Battery can charge from system only when system output exceeds load [0/1]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=0"),
 	NULL},
{"batt_dispatch_choice", (getter)BatteryDispatch_get_batt_dispatch_choice,(setter)BatteryDispatch_set_batt_dispatch_choice,
	PyDoc_STR("*float*: Battery dispatch algorithm [0/1/2/3/4]\n\n**Options:**\nIf behind the meter: 0=PeakShaving,1=InputGridTarget,2=InputBatteryPower,3=ManualDispatch,4=PriceSignalForecast if front of meter: 0=AutomatedEconomic,1=PV_Smoothing,2=InputBatteryPower,3=ManualDispatch\n\n**Required:**\nRequired if en_batt=1"),
 	NULL},
{"batt_dispatch_discharge_only_load_exceeds_system", (getter)BatteryDispatch_get_batt_dispatch_discharge_only_load_exceeds_system,(setter)BatteryDispatch_set_batt_dispatch_discharge_only_load_exceeds_system,
	PyDoc_STR("*float*: Battery can discharge battery only when load exceeds system output [0/1]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=0"),
 	NULL},
{"batt_dispatch_load_forecast_choice", (getter)BatteryDispatch_get_batt_dispatch_load_forecast_choice,(setter)BatteryDispatch_set_batt_dispatch_load_forecast_choice,
	PyDoc_STR("*float*: Load forecast choice for automatic dispatch [0/1/2]\n\n**Options:**\n0=LookAhead,1=LookBehind,2=InputForecast\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults.\n\nThe value of the following variables depends on ``batt_dispatch_load_forecast_choice``:\n\n\t - batt_load_ac_forecast\n\t - batt_load_ac_forecast_escalation\n"),
 	NULL},
{"batt_dispatch_pvs_ac_lb", (getter)BatteryDispatch_get_batt_dispatch_pvs_ac_lb,(setter)BatteryDispatch_set_batt_dispatch_pvs_ac_lb,
	PyDoc_STR("*float*: AC lower bound [fraction of nameplate]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_ac_lb_enable", (getter)BatteryDispatch_get_batt_dispatch_pvs_ac_lb_enable,(setter)BatteryDispatch_set_batt_dispatch_pvs_ac_lb_enable,
	PyDoc_STR("*float*: Enable AC lower bound [0/1]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_ac_ub", (getter)BatteryDispatch_get_batt_dispatch_pvs_ac_ub,(setter)BatteryDispatch_set_batt_dispatch_pvs_ac_ub,
	PyDoc_STR("*float*: AC upper bound [fraction of nameplate]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_ac_ub_enable", (getter)BatteryDispatch_get_batt_dispatch_pvs_ac_ub_enable,(setter)BatteryDispatch_set_batt_dispatch_pvs_ac_ub_enable,
	PyDoc_STR("*float*: Enable AC upper bound [0/1]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_curtail_as_control", (getter)BatteryDispatch_get_batt_dispatch_pvs_curtail_as_control,(setter)BatteryDispatch_set_batt_dispatch_pvs_curtail_as_control,
	PyDoc_STR("*float*: Correct up-ramp violations [0/1]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_curtail_if_violation", (getter)BatteryDispatch_get_batt_dispatch_pvs_curtail_if_violation,(setter)BatteryDispatch_set_batt_dispatch_pvs_curtail_if_violation,
	PyDoc_STR("*float*: Curtail violations [0/1]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_forecast_shift_periods", (getter)BatteryDispatch_get_batt_dispatch_pvs_forecast_shift_periods,(setter)BatteryDispatch_set_batt_dispatch_pvs_forecast_shift_periods,
	PyDoc_STR("*float*: Forecasting window [periods of ramp intervals]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_kf", (getter)BatteryDispatch_get_batt_dispatch_pvs_kf,(setter)BatteryDispatch_set_batt_dispatch_pvs_kf,
	PyDoc_STR("*float*: Forecast accumulation error multiplier (kf)\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_ki", (getter)BatteryDispatch_get_batt_dispatch_pvs_ki,(setter)BatteryDispatch_set_batt_dispatch_pvs_ki,
	PyDoc_STR("*float*: Return to rest SOC multiplier (ki)\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_kp", (getter)BatteryDispatch_get_batt_dispatch_pvs_kp,(setter)BatteryDispatch_set_batt_dispatch_pvs_kp,
	PyDoc_STR("*float*: Track PV power multiplier (kp)\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_max_ramp", (getter)BatteryDispatch_get_batt_dispatch_pvs_max_ramp,(setter)BatteryDispatch_set_batt_dispatch_pvs_max_ramp,
	PyDoc_STR("*float*: Maximum ramp rate [% of nameplate per ramp interval]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_nameplate_ac", (getter)BatteryDispatch_get_batt_dispatch_pvs_nameplate_ac,(setter)BatteryDispatch_set_batt_dispatch_pvs_nameplate_ac,
	PyDoc_STR("*float*: Nameplate for pv smoothing [kWac]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_short_forecast_enable", (getter)BatteryDispatch_get_batt_dispatch_pvs_short_forecast_enable,(setter)BatteryDispatch_set_batt_dispatch_pvs_short_forecast_enable,
	PyDoc_STR("*float*: Enable short term power forecast [0/1]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_soc_rest", (getter)BatteryDispatch_get_batt_dispatch_pvs_soc_rest,(setter)BatteryDispatch_set_batt_dispatch_pvs_soc_rest,
	PyDoc_STR("*float*: Battery resting SOC [%]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_timestep_multiplier", (getter)BatteryDispatch_get_batt_dispatch_pvs_timestep_multiplier,(setter)BatteryDispatch_set_batt_dispatch_pvs_timestep_multiplier,
	PyDoc_STR("*float*: Ramp timestep multiplier\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_update_frequency_hours", (getter)BatteryDispatch_get_batt_dispatch_update_frequency_hours,(setter)BatteryDispatch_set_batt_dispatch_update_frequency_hours,
	PyDoc_STR("*float*: Frequency to update the look-ahead dispatch [hours]"),
 	NULL},
{"batt_dispatch_wf_forecast_choice", (getter)BatteryDispatch_get_batt_dispatch_wf_forecast_choice,(setter)BatteryDispatch_set_batt_dispatch_wf_forecast_choice,
	PyDoc_STR("*float*: Weather forecast choice for automatic dispatch [0/1/2]\n\n**Options:**\n0=LookAhead,1=LookBehind,2=InputForecast\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_load_ac_forecast", (getter)BatteryDispatch_get_batt_load_ac_forecast,(setter)BatteryDispatch_set_batt_load_ac_forecast,
	PyDoc_STR("*sequence*: Load ac power forecast [kW]\n\n**Info:**\nLength either 8760 or 8760 * steps per hour\n\nThe value of ``batt_load_ac_forecast`` depends on the following variables:\n\n\t - batt_dispatch_load_forecast_choice\n"),
 	NULL},
{"batt_load_ac_forecast_escalation", (getter)BatteryDispatch_get_batt_load_ac_forecast_escalation,(setter)BatteryDispatch_set_batt_load_ac_forecast_escalation,
	PyDoc_STR("*sequence*: Annual load escalation for ac power forecast [kW]\n\n**Options:**\nlength <= analysis_period\n\nThe value of ``batt_load_ac_forecast_escalation`` depends on the following variables:\n\n\t - batt_dispatch_load_forecast_choice\n\t - load_escalation\n"),
 	NULL},
{"batt_look_ahead_hours", (getter)BatteryDispatch_get_batt_look_ahead_hours,(setter)BatteryDispatch_set_batt_look_ahead_hours,
	PyDoc_STR("*float*: Hours to look ahead in automated dispatch [hours]"),
 	NULL},
{"batt_pv_ac_forecast", (getter)BatteryDispatch_get_batt_pv_ac_forecast,(setter)BatteryDispatch_set_batt_pv_ac_forecast,
	PyDoc_STR("*sequence*: PV ac power forecast [kW]\n\n**Info:**\nLength either 8760 * steps per hour (values repeat each year) or 8760 * steps per hour * analysis period"),
 	NULL},
{"batt_pv_clipping_forecast", (getter)BatteryDispatch_get_batt_pv_clipping_forecast,(setter)BatteryDispatch_set_batt_pv_clipping_forecast,
	PyDoc_STR("*sequence*: PV clipping forecast [kW]\n\n**Info:**\nLength either 8760 * steps per hour (values repeat each year) or 8760 * steps per hour * analysis period"),
 	NULL},
{"batt_target_choice", (getter)BatteryDispatch_get_batt_target_choice,(setter)BatteryDispatch_set_batt_target_choice,
	PyDoc_STR("*float*: Target power input option [0/1]\n\n**Options:**\n0=InputMonthlyTarget,1=InputFullTimeSeries\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=0&batt_dispatch_choice=1"),
 	NULL},
{"batt_target_power", (getter)BatteryDispatch_get_batt_target_power,(setter)BatteryDispatch_set_batt_target_power,
	PyDoc_STR("*sequence*: Grid target power for every time step [kW]\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=0&batt_dispatch_choice=1"),
 	NULL},
{"batt_target_power_monthly", (getter)BatteryDispatch_get_batt_target_power_monthly,(setter)BatteryDispatch_set_batt_target_power_monthly,
	PyDoc_STR("*sequence*: Grid target power on monthly basis [kW]\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=0&batt_dispatch_choice=1"),
 	NULL},
{"dispatch_manual_btm_discharge_to_grid", (getter)BatteryDispatch_get_dispatch_manual_btm_discharge_to_grid,(setter)BatteryDispatch_set_dispatch_manual_btm_discharge_to_grid,
	PyDoc_STR("*sequence*: Periods 1-6 behind the meter discharging to grid allowed?\n\n**Required:**\nRequired if en_batt=1&batt_dispatch_choice=3&batt_meter_position=0"),
 	NULL},
{"dispatch_manual_charge", (getter)BatteryDispatch_get_dispatch_manual_charge,(setter)BatteryDispatch_set_dispatch_manual_charge,
	PyDoc_STR("*sequence*: Periods 1-6 charging from system allowed?\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_dispatch_choice=3"),
 	NULL},
{"dispatch_manual_discharge", (getter)BatteryDispatch_get_dispatch_manual_discharge,(setter)BatteryDispatch_set_dispatch_manual_discharge,
	PyDoc_STR("*sequence*: Periods 1-6 discharging allowed?\n\n**Required:**\nRequired if en_batt=1&batt_dispatch_choice=3\n\nThe value of the following variables depends on ``dispatch_manual_discharge``:\n\n\t - dispatch_manual_percent_discharge\n"),
 	NULL},
{"dispatch_manual_fuelcellcharge", (getter)BatteryDispatch_get_dispatch_manual_fuelcellcharge,(setter)BatteryDispatch_set_dispatch_manual_fuelcellcharge,
	PyDoc_STR("*sequence*: Periods 1-6 charging from fuel cell allowed?"),
 	NULL},
{"dispatch_manual_gridcharge", (getter)BatteryDispatch_get_dispatch_manual_gridcharge,(setter)BatteryDispatch_set_dispatch_manual_gridcharge,
	PyDoc_STR("*sequence*: Periods 1-6 grid charging allowed?\n\n**Required:**\nRequired if en_batt=1&batt_dispatch_choice=3\n\nThe value of the following variables depends on ``dispatch_manual_gridcharge``:\n\n\t - dispatch_manual_percent_gridcharge\n"),
 	NULL},
{"dispatch_manual_percent_discharge", (getter)BatteryDispatch_get_dispatch_manual_percent_discharge,(setter)BatteryDispatch_set_dispatch_manual_percent_discharge,
	PyDoc_STR("*sequence*: Periods 1-6 discharge percent [%]\n\n**Required:**\nRequired if en_batt=1&batt_dispatch_choice=3\n\nThe value of ``dispatch_manual_percent_discharge`` depends on the following variables:\n\n\t - dispatch_manual_discharge\n"),
 	NULL},
{"dispatch_manual_percent_gridcharge", (getter)BatteryDispatch_get_dispatch_manual_percent_gridcharge,(setter)BatteryDispatch_set_dispatch_manual_percent_gridcharge,
	PyDoc_STR("*sequence*: Periods 1-6 gridcharge percent [%]\n\n**Required:**\nRequired if en_batt=1&batt_dispatch_choice=3\n\nThe value of ``dispatch_manual_percent_gridcharge`` depends on the following variables:\n\n\t - dispatch_manual_gridcharge\n"),
 	NULL},
{"dispatch_manual_sched", (getter)BatteryDispatch_get_dispatch_manual_sched,(setter)BatteryDispatch_set_dispatch_manual_sched,
	PyDoc_STR("*sequence[sequence]*: Battery dispatch schedule for weekday\n\n**Required:**\nRequired if en_batt=1&batt_dispatch_choice=3"),
 	NULL},
{"dispatch_manual_sched_weekend", (getter)BatteryDispatch_get_dispatch_manual_sched_weekend,(setter)BatteryDispatch_set_dispatch_manual_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Battery dispatch schedule for weekend\n\n**Required:**\nRequired if en_batt=1&batt_dispatch_choice=3"),
 	NULL},
{"dispatch_manual_system_charge_first", (getter)BatteryDispatch_get_dispatch_manual_system_charge_first,(setter)BatteryDispatch_set_dispatch_manual_system_charge_first,
	PyDoc_STR("*float*: System charges battery before meeting load [0/1]\n\n**Options:**\n0=LoadFirst,1=ChargeFirst\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=0&batt_dispatch_choice=3&batt_dispatch_charge_only_system_exceeds_load=0"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject BatteryDispatch_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.BatteryDispatch",             /*tp_name*/
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
		BatteryDispatch_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		BatteryDispatch_getset,          /*tp_getset*/
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
SystemCosts_new(SAM_Battery data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "SystemCosts")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battery", "SystemCosts")){
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
SystemCosts_get_om_batt_replacement_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_SystemCosts_om_batt_replacement_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_batt_replacement_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_SystemCosts_om_batt_replacement_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_batt_variable_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_SystemCosts_om_batt_variable_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_batt_variable_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_SystemCosts_om_batt_variable_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_SystemCosts_om_production_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_production_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_SystemCosts_om_production_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_replacement_cost_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_SystemCosts_om_replacement_cost_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_replacement_cost_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_SystemCosts_om_replacement_cost_escal_nset, self->data_ptr);
}

static PyGetSetDef SystemCosts_getset[] = {
{"om_batt_replacement_cost", (getter)SystemCosts_get_om_batt_replacement_cost,(setter)SystemCosts_set_om_batt_replacement_cost,
	PyDoc_STR("*sequence*: Replacement cost 1 [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_batt_variable_cost", (getter)SystemCosts_get_om_batt_variable_cost,(setter)SystemCosts_set_om_batt_variable_cost,
	PyDoc_STR("*sequence*: Battery production-based System Costs amount [$/MWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
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
		"Battery.SystemCosts",             /*tp_name*/
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
 * FuelCell Group
 */ 

static PyTypeObject FuelCell_Type;

static PyObject *
FuelCell_new(SAM_Battery data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "FuelCell")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battery", "FuelCell")){
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
FuelCell_get_fuelcell_power(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_FuelCell_fuelcell_power_aget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_power(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_FuelCell_fuelcell_power_aset, self->data_ptr);
}

static PyGetSetDef FuelCell_getset[] = {
{"fuelcell_power", (getter)FuelCell_get_fuelcell_power,(setter)FuelCell_set_fuelcell_power,
	PyDoc_STR("*sequence*: Electricity from fuel cell AC [kW]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FuelCell_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.FuelCell",             /*tp_name*/
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
 * PriceSignal Group
 */ 

static PyTypeObject PriceSignal_Type;

static PyObject *
PriceSignal_new(SAM_Battery data_ptr)
{
	PyObject* new_obj = PriceSignal_Type.tp_alloc(&PriceSignal_Type,0);

	VarGroupObject* PriceSignal_obj = (VarGroupObject*)new_obj;

	PriceSignal_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* PriceSignal methods */

static PyObject *
PriceSignal_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "PriceSignal")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PriceSignal_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &PriceSignal_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battery", "PriceSignal")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PriceSignal_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &PriceSignal_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef PriceSignal_methods[] = {
		{"assign",            (PyCFunction)PriceSignal_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``PriceSignal_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)PriceSignal_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``PriceSignal_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)PriceSignal_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
PriceSignal_get_dispatch_factors_ts(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_PriceSignal_dispatch_factors_ts_aget, self->data_ptr);
}

static int
PriceSignal_set_dispatch_factors_ts(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_PriceSignal_dispatch_factors_ts_aset, self->data_ptr);
}

static PyObject *
PriceSignal_get_dispatch_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_PriceSignal_dispatch_sched_weekday_mget, self->data_ptr);
}

static int
PriceSignal_set_dispatch_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_PriceSignal_dispatch_sched_weekday_mset, self->data_ptr);
}

static PyObject *
PriceSignal_get_dispatch_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_PriceSignal_dispatch_sched_weekend_mget, self->data_ptr);
}

static int
PriceSignal_set_dispatch_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_PriceSignal_dispatch_sched_weekend_mset, self->data_ptr);
}

static PyObject *
PriceSignal_get_dispatch_tod_factors(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_PriceSignal_dispatch_tod_factors_aget, self->data_ptr);
}

static int
PriceSignal_set_dispatch_tod_factors(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_PriceSignal_dispatch_tod_factors_aset, self->data_ptr);
}

static PyObject *
PriceSignal_get_forecast_price_signal_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_PriceSignal_forecast_price_signal_model_nget, self->data_ptr);
}

static int
PriceSignal_set_forecast_price_signal_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_PriceSignal_forecast_price_signal_model_nset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_ancserv1_revenue(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_PriceSignal_mp_ancserv1_revenue_mget, self->data_ptr);
}

static int
PriceSignal_set_mp_ancserv1_revenue(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_PriceSignal_mp_ancserv1_revenue_mset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_ancserv2_revenue(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_PriceSignal_mp_ancserv2_revenue_mget, self->data_ptr);
}

static int
PriceSignal_set_mp_ancserv2_revenue(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_PriceSignal_mp_ancserv2_revenue_mset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_ancserv3_revenue(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_PriceSignal_mp_ancserv3_revenue_mget, self->data_ptr);
}

static int
PriceSignal_set_mp_ancserv3_revenue(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_PriceSignal_mp_ancserv3_revenue_mset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_ancserv4_revenue(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_PriceSignal_mp_ancserv4_revenue_mget, self->data_ptr);
}

static int
PriceSignal_set_mp_ancserv4_revenue(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_PriceSignal_mp_ancserv4_revenue_mset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_enable_ancserv1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_PriceSignal_mp_enable_ancserv1_nget, self->data_ptr);
}

static int
PriceSignal_set_mp_enable_ancserv1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_PriceSignal_mp_enable_ancserv1_nset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_enable_ancserv2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_PriceSignal_mp_enable_ancserv2_nget, self->data_ptr);
}

static int
PriceSignal_set_mp_enable_ancserv2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_PriceSignal_mp_enable_ancserv2_nset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_enable_ancserv3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_PriceSignal_mp_enable_ancserv3_nget, self->data_ptr);
}

static int
PriceSignal_set_mp_enable_ancserv3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_PriceSignal_mp_enable_ancserv3_nset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_enable_ancserv4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_PriceSignal_mp_enable_ancserv4_nget, self->data_ptr);
}

static int
PriceSignal_set_mp_enable_ancserv4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_PriceSignal_mp_enable_ancserv4_nset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_enable_energy_market_revenue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_PriceSignal_mp_enable_energy_market_revenue_nget, self->data_ptr);
}

static int
PriceSignal_set_mp_enable_energy_market_revenue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_PriceSignal_mp_enable_energy_market_revenue_nset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_energy_market_revenue(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_PriceSignal_mp_energy_market_revenue_mget, self->data_ptr);
}

static int
PriceSignal_set_mp_energy_market_revenue(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_PriceSignal_mp_energy_market_revenue_mset, self->data_ptr);
}

static PyObject *
PriceSignal_get_ppa_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_PriceSignal_ppa_escalation_nget, self->data_ptr);
}

static int
PriceSignal_set_ppa_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_PriceSignal_ppa_escalation_nset, self->data_ptr);
}

static PyObject *
PriceSignal_get_ppa_multiplier_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_PriceSignal_ppa_multiplier_model_nget, self->data_ptr);
}

static int
PriceSignal_set_ppa_multiplier_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_PriceSignal_ppa_multiplier_model_nset, self->data_ptr);
}

static PyObject *
PriceSignal_get_ppa_price_input(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_PriceSignal_ppa_price_input_aget, self->data_ptr);
}

static int
PriceSignal_set_ppa_price_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_PriceSignal_ppa_price_input_aset, self->data_ptr);
}

static PyGetSetDef PriceSignal_getset[] = {
{"dispatch_factors_ts", (getter)PriceSignal_get_dispatch_factors_ts,(setter)PriceSignal_set_dispatch_factors_ts,
	PyDoc_STR("*sequence*: Dispatch payment factor time step\n\n**Required:**\nRequired if forecast_price_signal_model=0&en_batt=1&batt_meter_position=1&ppa_multiplier_model=1"),
 	NULL},
{"dispatch_sched_weekday", (getter)PriceSignal_get_dispatch_sched_weekday,(setter)PriceSignal_set_dispatch_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: Diurnal weekday TOD periods [1..9]\n\n**Info:**\n12 x 24 matrix\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=1&forecast_price_signal_model=0&ppa_multiplier_model=0"),
 	NULL},
{"dispatch_sched_weekend", (getter)PriceSignal_get_dispatch_sched_weekend,(setter)PriceSignal_set_dispatch_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Diurnal weekend TOD periods [1..9]\n\n**Info:**\n12 x 24 matrix\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=1&forecast_price_signal_model=0&ppa_multiplier_model=0"),
 	NULL},
{"dispatch_tod_factors", (getter)PriceSignal_get_dispatch_tod_factors,(setter)PriceSignal_set_dispatch_tod_factors,
	PyDoc_STR("*sequence*: TOD factors for periods 1-9\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=1&forecast_price_signal_model=0&ppa_multiplier_model=0"),
 	NULL},
{"forecast_price_signal_model", (getter)PriceSignal_get_forecast_price_signal_model,(setter)PriceSignal_set_forecast_price_signal_model,
	PyDoc_STR("*float*: Forecast price signal model selected [0/1]\n\n**Options:**\n0=PPA based,1=Merchant Plant\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"mp_ancserv1_revenue", (getter)PriceSignal_get_mp_ancserv1_revenue,(setter)PriceSignal_set_mp_ancserv1_revenue,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 1 revenue input [ [MW, $/MW]]\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=1&forecast_price_signal_model=1"),
 	NULL},
{"mp_ancserv2_revenue", (getter)PriceSignal_get_mp_ancserv2_revenue,(setter)PriceSignal_set_mp_ancserv2_revenue,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 2 revenue input [ [MW, $/MW]]\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=1&forecast_price_signal_model=1"),
 	NULL},
{"mp_ancserv3_revenue", (getter)PriceSignal_get_mp_ancserv3_revenue,(setter)PriceSignal_set_mp_ancserv3_revenue,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 3 revenue input [ [MW, $/MW]]\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=1&forecast_price_signal_model=1"),
 	NULL},
{"mp_ancserv4_revenue", (getter)PriceSignal_get_mp_ancserv4_revenue,(setter)PriceSignal_set_mp_ancserv4_revenue,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 4 revenue input [ [MW, $/MW]]\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=1&forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_ancserv1", (getter)PriceSignal_get_mp_enable_ancserv1,(setter)PriceSignal_set_mp_enable_ancserv1,
	PyDoc_STR("*float*: Enable ancillary services 1 revenue [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_ancserv2", (getter)PriceSignal_get_mp_enable_ancserv2,(setter)PriceSignal_set_mp_enable_ancserv2,
	PyDoc_STR("*float*: Enable ancillary services 2 revenue [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_ancserv3", (getter)PriceSignal_get_mp_enable_ancserv3,(setter)PriceSignal_set_mp_enable_ancserv3,
	PyDoc_STR("*float*: Enable ancillary services 3 revenue [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_ancserv4", (getter)PriceSignal_get_mp_enable_ancserv4,(setter)PriceSignal_set_mp_enable_ancserv4,
	PyDoc_STR("*float*: Enable ancillary services 4 revenue [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_energy_market_revenue", (getter)PriceSignal_get_mp_enable_energy_market_revenue,(setter)PriceSignal_set_mp_enable_energy_market_revenue,
	PyDoc_STR("*float*: Enable energy market revenue [0/1]\n\n**Options:**\n0=false,1=true\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=1&forecast_price_signal_model=1"),
 	NULL},
{"mp_energy_market_revenue", (getter)PriceSignal_get_mp_energy_market_revenue,(setter)PriceSignal_set_mp_energy_market_revenue,
	PyDoc_STR("*sequence[sequence]*: Energy market revenue input [ [MW, $/MW]]\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=1&forecast_price_signal_model=1"),
 	NULL},
{"ppa_escalation", (getter)PriceSignal_get_ppa_escalation,(setter)PriceSignal_set_ppa_escalation,
	PyDoc_STR("*float*: PPA escalation rate [%/year]\n\n**Required:**\nRequired if forecast_price_signal_model=0&en_batt=1&batt_meter_position=1"),
 	NULL},
{"ppa_multiplier_model", (getter)PriceSignal_get_ppa_multiplier_model,(setter)PriceSignal_set_ppa_multiplier_model,
	PyDoc_STR("*float*: PPA multiplier model [0/1]\n\n**Options:**\n0=diurnal,1=timestep\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nRequired if forecast_price_signal_model=0&en_batt=1&batt_meter_position=1"),
 	NULL},
{"ppa_price_input", (getter)PriceSignal_get_ppa_price_input,(setter)PriceSignal_set_ppa_price_input,
	PyDoc_STR("*sequence*: PPA Price Input [$/kWh]\n\n**Required:**\nRequired if forecast_price_signal_model=0&en_batt=1&batt_meter_position=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject PriceSignal_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.PriceSignal",             /*tp_name*/
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
		PriceSignal_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		PriceSignal_getset,          /*tp_getset*/
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
 * Revenue Group
 */ 

static PyTypeObject Revenue_Type;

static PyObject *
Revenue_new(SAM_Battery data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "Revenue")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battery", "Revenue")){
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
Revenue_get_mp_ancserv1_revenue_single(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_Revenue_mp_ancserv1_revenue_single_mget, self->data_ptr);
}

static int
Revenue_set_mp_ancserv1_revenue_single(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_Revenue_mp_ancserv1_revenue_single_mset, self->data_ptr);
}

static PyObject *
Revenue_get_mp_ancserv2_revenue_single(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_Revenue_mp_ancserv2_revenue_single_mget, self->data_ptr);
}

static int
Revenue_set_mp_ancserv2_revenue_single(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_Revenue_mp_ancserv2_revenue_single_mset, self->data_ptr);
}

static PyObject *
Revenue_get_mp_ancserv3_revenue_single(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_Revenue_mp_ancserv3_revenue_single_mget, self->data_ptr);
}

static int
Revenue_set_mp_ancserv3_revenue_single(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_Revenue_mp_ancserv3_revenue_single_mset, self->data_ptr);
}

static PyObject *
Revenue_get_mp_ancserv4_revenue_single(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_Revenue_mp_ancserv4_revenue_single_mget, self->data_ptr);
}

static int
Revenue_set_mp_ancserv4_revenue_single(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_Revenue_mp_ancserv4_revenue_single_mset, self->data_ptr);
}

static PyObject *
Revenue_get_mp_enable_ancserv1_percent_gen(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Revenue_mp_enable_ancserv1_percent_gen_nget, self->data_ptr);
}

static int
Revenue_set_mp_enable_ancserv1_percent_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Revenue_mp_enable_ancserv1_percent_gen_nset, self->data_ptr);
}

static PyObject *
Revenue_get_mp_enable_ancserv2_percent_gen(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Revenue_mp_enable_ancserv2_percent_gen_nget, self->data_ptr);
}

static int
Revenue_set_mp_enable_ancserv2_percent_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Revenue_mp_enable_ancserv2_percent_gen_nset, self->data_ptr);
}

static PyObject *
Revenue_get_mp_enable_ancserv3_percent_gen(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Revenue_mp_enable_ancserv3_percent_gen_nget, self->data_ptr);
}

static int
Revenue_set_mp_enable_ancserv3_percent_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Revenue_mp_enable_ancserv3_percent_gen_nset, self->data_ptr);
}

static PyObject *
Revenue_get_mp_enable_ancserv4_percent_gen(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Revenue_mp_enable_ancserv4_percent_gen_nget, self->data_ptr);
}

static int
Revenue_set_mp_enable_ancserv4_percent_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Revenue_mp_enable_ancserv4_percent_gen_nset, self->data_ptr);
}

static PyObject *
Revenue_get_mp_enable_market_percent_gen(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Revenue_mp_enable_market_percent_gen_nget, self->data_ptr);
}

static int
Revenue_set_mp_enable_market_percent_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_Revenue_mp_enable_market_percent_gen_nset, self->data_ptr);
}

static PyObject *
Revenue_get_mp_energy_market_revenue_single(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_Revenue_mp_energy_market_revenue_single_mget, self->data_ptr);
}

static int
Revenue_set_mp_energy_market_revenue_single(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_Revenue_mp_energy_market_revenue_single_mset, self->data_ptr);
}

static PyGetSetDef Revenue_getset[] = {
{"mp_ancserv1_revenue_single", (getter)Revenue_get_mp_ancserv1_revenue_single,(setter)Revenue_set_mp_ancserv1_revenue_single,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 1 revenue input\n\n**Info:**\nLifetime x 1[Price($/MWh)]\n\n**Required:**\nRequired if forecast_price_signal_model=1&mp_enable_ancserv1_percent_gen=1"),
 	NULL},
{"mp_ancserv2_revenue_single", (getter)Revenue_get_mp_ancserv2_revenue_single,(setter)Revenue_set_mp_ancserv2_revenue_single,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 2 revenue input\n\n**Info:**\nLifetime x 1[Price($/MWh)]\n\n**Required:**\nRequired if forecast_price_signal_model=1&mp_enable_ancserv2_percent_gen=1"),
 	NULL},
{"mp_ancserv3_revenue_single", (getter)Revenue_get_mp_ancserv3_revenue_single,(setter)Revenue_set_mp_ancserv3_revenue_single,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 3 revenue input\n\n**Info:**\nLifetime x 1[Price($/MWh)]\n\n**Required:**\nRequired if forecast_price_signal_model=1&mp_enable_ancserv3_percent_gen=1"),
 	NULL},
{"mp_ancserv4_revenue_single", (getter)Revenue_get_mp_ancserv4_revenue_single,(setter)Revenue_set_mp_ancserv4_revenue_single,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 4 revenue input\n\n**Info:**\nLifetime x 1[Price($/MWh)]\n\n**Required:**\nRequired if forecast_price_signal_model=1&mp_enable_ancserv4_percent_gen=1"),
 	NULL},
{"mp_enable_ancserv1_percent_gen", (getter)Revenue_get_mp_enable_ancserv1_percent_gen,(setter)Revenue_set_mp_enable_ancserv1_percent_gen,
	PyDoc_STR("*float*: Enable percent demand cleared capacity option for ancillary service 1 [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_ancserv2_percent_gen", (getter)Revenue_get_mp_enable_ancserv2_percent_gen,(setter)Revenue_set_mp_enable_ancserv2_percent_gen,
	PyDoc_STR("*float*: Enable percent demand cleared capacity option for ancillary service 2 [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_ancserv3_percent_gen", (getter)Revenue_get_mp_enable_ancserv3_percent_gen,(setter)Revenue_set_mp_enable_ancserv3_percent_gen,
	PyDoc_STR("*float*: Enable percent demand cleared capacity option for ancillary service 3 [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_ancserv4_percent_gen", (getter)Revenue_get_mp_enable_ancserv4_percent_gen,(setter)Revenue_set_mp_enable_ancserv4_percent_gen,
	PyDoc_STR("*float*: Enable percent demand cleared capacity option for ancillary service 4 [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_market_percent_gen", (getter)Revenue_get_mp_enable_market_percent_gen,(setter)Revenue_set_mp_enable_market_percent_gen,
	PyDoc_STR("*float*: Enable percent demand cleared capacity option for market revenue [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if forecast_price_signal_model=1"),
 	NULL},
{"mp_energy_market_revenue_single", (getter)Revenue_get_mp_energy_market_revenue_single,(setter)Revenue_set_mp_energy_market_revenue_single,
	PyDoc_STR("*sequence[sequence]*: Energy market revenue input\n\n**Info:**\nLifetime x 1 [Price($/MWh)]\n\n**Required:**\nRequired if forecast_price_signal_model=1&mp_enable_market_percent_gen=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Revenue_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.Revenue",             /*tp_name*/
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
 * ElectricityRates Group
 */ 

static PyTypeObject ElectricityRates_Type;

static PyObject *
ElectricityRates_new(SAM_Battery data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "ElectricityRates")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battery", "ElectricityRates")){
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
	return PySAM_double_getter(SAM_Battery_ElectricityRates_en_electricity_rates_nget, self->data_ptr);
}

static int
ElectricityRates_set_en_electricity_rates(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_ElectricityRates_en_electricity_rates_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_rate_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_ElectricityRates_rate_escalation_aget, self->data_ptr);
}

static int
ElectricityRates_set_rate_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_ElectricityRates_rate_escalation_aset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_annual_min_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_ElectricityRates_ur_annual_min_charge_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_annual_min_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_ElectricityRates_ur_annual_min_charge_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_billing_demand_lookback_percentages(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_ElectricityRates_ur_billing_demand_lookback_percentages_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_billing_demand_lookback_percentages(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_ElectricityRates_ur_billing_demand_lookback_percentages_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_billing_demand_lookback_period(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_ElectricityRates_ur_billing_demand_lookback_period_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_billing_demand_lookback_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_ElectricityRates_ur_billing_demand_lookback_period_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_billing_demand_minimum(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_ElectricityRates_ur_billing_demand_minimum_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_billing_demand_minimum(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_ElectricityRates_ur_billing_demand_minimum_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_billing_demand_periods(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_ElectricityRates_ur_dc_billing_demand_periods_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_billing_demand_periods(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_ElectricityRates_ur_dc_billing_demand_periods_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_ElectricityRates_ur_dc_enable_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_ElectricityRates_ur_dc_enable_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_flat_mat(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_ElectricityRates_ur_dc_flat_mat_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_flat_mat(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_ElectricityRates_ur_dc_flat_mat_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_ElectricityRates_ur_dc_sched_weekday_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_ElectricityRates_ur_dc_sched_weekday_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_ElectricityRates_ur_dc_sched_weekend_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_ElectricityRates_ur_dc_sched_weekend_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_tou_mat(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_ElectricityRates_ur_dc_tou_mat_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_tou_mat(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_ElectricityRates_ur_dc_tou_mat_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ec_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_ElectricityRates_ur_ec_sched_weekday_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ec_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_ElectricityRates_ur_ec_sched_weekday_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ec_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_ElectricityRates_ur_ec_sched_weekend_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ec_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_ElectricityRates_ur_ec_sched_weekend_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ec_tou_mat(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_ElectricityRates_ur_ec_tou_mat_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ec_tou_mat(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_ElectricityRates_ur_ec_tou_mat_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_en_ts_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_ElectricityRates_ur_en_ts_buy_rate_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_en_ts_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_ElectricityRates_ur_en_ts_buy_rate_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_en_ts_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_ElectricityRates_ur_en_ts_sell_rate_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_en_ts_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_ElectricityRates_ur_en_ts_sell_rate_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_enable_billing_demand(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_ElectricityRates_ur_enable_billing_demand_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_enable_billing_demand(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_ElectricityRates_ur_enable_billing_demand_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_metering_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_ElectricityRates_ur_metering_option_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_metering_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_ElectricityRates_ur_metering_option_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_monthly_fixed_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_ElectricityRates_ur_monthly_fixed_charge_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_monthly_fixed_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_ElectricityRates_ur_monthly_fixed_charge_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_monthly_min_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_ElectricityRates_ur_monthly_min_charge_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_monthly_min_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_ElectricityRates_ur_monthly_min_charge_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_nm_credit_month(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_ElectricityRates_ur_nm_credit_month_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_nm_credit_month(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_ElectricityRates_ur_nm_credit_month_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_nm_credit_rollover(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_ElectricityRates_ur_nm_credit_rollover_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_nm_credit_rollover(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_ElectricityRates_ur_nm_credit_rollover_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_nm_yearend_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_ElectricityRates_ur_nm_yearend_sell_rate_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_nm_yearend_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_ElectricityRates_ur_nm_yearend_sell_rate_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_sell_eq_buy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_ElectricityRates_ur_sell_eq_buy_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_sell_eq_buy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_ElectricityRates_ur_sell_eq_buy_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ts_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_ElectricityRates_ur_ts_buy_rate_aget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ts_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_ElectricityRates_ur_ts_buy_rate_aset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ts_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_ElectricityRates_ur_ts_sell_rate_aget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ts_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_ElectricityRates_ur_ts_sell_rate_aset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_yearzero_usage_peaks(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_ElectricityRates_ur_yearzero_usage_peaks_aget, self->data_ptr);
}

static int
ElectricityRates_set_ur_yearzero_usage_peaks(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_ElectricityRates_ur_yearzero_usage_peaks_aset, self->data_ptr);
}

static PyGetSetDef ElectricityRates_getset[] = {
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
		"Battery.ElectricityRates",             /*tp_name*/
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
 * GridLimits Group
 */ 

static PyTypeObject GridLimits_Type;

static PyObject *
GridLimits_new(SAM_Battery data_ptr)
{
	PyObject* new_obj = GridLimits_Type.tp_alloc(&GridLimits_Type,0);

	VarGroupObject* GridLimits_obj = (VarGroupObject*)new_obj;

	GridLimits_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* GridLimits methods */

static PyObject *
GridLimits_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "GridLimits")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
GridLimits_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &GridLimits_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battery", "GridLimits")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
GridLimits_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &GridLimits_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef GridLimits_methods[] = {
		{"assign",            (PyCFunction)GridLimits_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``GridLimits_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)GridLimits_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``GridLimits_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)GridLimits_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
GridLimits_get_enable_interconnection_limit(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_GridLimits_enable_interconnection_limit_nget, self->data_ptr);
}

static int
GridLimits_set_enable_interconnection_limit(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_GridLimits_enable_interconnection_limit_nset, self->data_ptr);
}

static PyObject *
GridLimits_get_grid_curtailment(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_GridLimits_grid_curtailment_aget, self->data_ptr);
}

static int
GridLimits_set_grid_curtailment(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_GridLimits_grid_curtailment_aset, self->data_ptr);
}

static PyObject *
GridLimits_get_grid_interconnection_limit_kwac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_GridLimits_grid_interconnection_limit_kwac_nget, self->data_ptr);
}

static int
GridLimits_set_grid_interconnection_limit_kwac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_GridLimits_grid_interconnection_limit_kwac_nset, self->data_ptr);
}

static PyGetSetDef GridLimits_getset[] = {
{"enable_interconnection_limit", (getter)GridLimits_get_enable_interconnection_limit,(setter)GridLimits_set_enable_interconnection_limit,
	PyDoc_STR("*float*: Enable grid interconnection limit [0/1]\n\n**Info:**\nEnable a grid interconnection limit"),
 	NULL},
{"grid_curtailment", (getter)GridLimits_get_grid_curtailment,(setter)GridLimits_set_grid_curtailment,
	PyDoc_STR("*sequence*: Grid curtailment as energy delivery limit (first year) [MW]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required.\n\nThe value of the following variables depends on ``grid_curtailment``:\n\n\t - batt_room_temperature_celsius\n"),
 	NULL},
{"grid_interconnection_limit_kwac", (getter)GridLimits_get_grid_interconnection_limit_kwac,(setter)GridLimits_set_grid_interconnection_limit_kwac,
	PyDoc_STR("*float*: Grid interconnection limit [kWac]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject GridLimits_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.GridLimits",             /*tp_name*/
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
		GridLimits_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		GridLimits_getset,          /*tp_getset*/
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
Outputs_new(SAM_Battery data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battery", "Outputs")){
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
Outputs_get_annual_crit_load(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Outputs_annual_crit_load_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_crit_load_unmet(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Outputs_annual_crit_load_unmet_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_crit_load_unmet_percentage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Outputs_annual_crit_load_unmet_percentage_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_export_to_grid_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_annual_export_to_grid_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_import_to_grid_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_annual_import_to_grid_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_outage_losses_unmet(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Outputs_annual_outage_losses_unmet_nget, self->data_ptr);
}

static PyObject *
Outputs_get_average_battery_conversion_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Outputs_average_battery_conversion_efficiency_nget, self->data_ptr);
}

static PyObject *
Outputs_get_average_battery_roundtrip_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Outputs_average_battery_roundtrip_efficiency_nget, self->data_ptr);
}

static PyObject *
Outputs_get_avg_critical_load(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Outputs_avg_critical_load_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_DOD(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_DOD_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_DOD_cycle_average(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_DOD_cycle_average_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_I(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_I_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_SOC(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_SOC_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_charge_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_annual_charge_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_charge_from_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_annual_charge_from_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_charge_from_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_annual_charge_from_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_discharge_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_annual_discharge_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_energy_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_annual_energy_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_energy_system_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_annual_energy_system_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_bank_installed_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Outputs_batt_bank_installed_capacity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_bank_replacement(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_bank_replacement_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_capacity_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_capacity_percent_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_capacity_percent_calendar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_capacity_percent_calendar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_capacity_percent_cycle(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_capacity_percent_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_capacity_thermal_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_capacity_thermal_percent_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_conversion_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_conversion_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_cost_to_cycle(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_cost_to_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_cycles(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_cycles_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_dispatch_sched(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_Outputs_batt_dispatch_sched_mget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_power(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_power_dc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_power_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_power_target(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_power_target_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_PV_ramp_interval(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_pvs_PV_ramp_interval_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_P_pv_ac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_pvs_P_pv_ac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_battpower(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_pvs_battpower_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_battsoc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_pvs_battsoc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_curtail(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_pvs_curtail_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_energy_to_grid_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Outputs_batt_pvs_energy_to_grid_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_energy_to_grid_percent_sam(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Outputs_batt_pvs_energy_to_grid_percent_sam_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_forecast_pv_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_pvs_forecast_pv_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_outpower(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_pvs_outpower_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_violation_count(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Outputs_batt_pvs_violation_count_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_violation_list(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_pvs_violation_list_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_violation_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Outputs_batt_pvs_violation_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_q0(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_q0_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_q1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_q1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_q2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_q2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_qmax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_qmax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_qmaxI(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_qmaxI_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_qmax_thermal(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_qmax_thermal_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_revenue_charge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_revenue_charge_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_revenue_clipcharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_revenue_clipcharge_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_revenue_discharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_revenue_discharge_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_revenue_gridcharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_revenue_gridcharge_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_system_charge_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Outputs_batt_system_charge_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_system_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_system_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_temperature(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_temperature_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_to_inverter_dc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_to_inverter_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_to_system_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_to_system_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_voltage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_voltage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_voltage_cell(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_voltage_cell_aget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor_sales(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Outputs_capacity_factor_sales_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cdf_of_surviving(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_cdf_of_surviving_aget, self->data_ptr);
}

static PyObject *
Outputs_get_crit_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_crit_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_crit_load_unmet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_crit_load_unmet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_fuelcell_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_fuelcell_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen_without_battery(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_gen_without_battery_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_power(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_grid_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_power_target(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_grid_power_target_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_grid_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_grid_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_interconnection_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_interconnection_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_market_sell_rate_series_yr1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_market_sell_rate_series_yr1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_batt_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_batt_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_batt_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_batt_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_batt_to_system_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_batt_to_system_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_crit_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_crit_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_crit_load_unmet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_crit_load_unmet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_crit_load_unmet_percentage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_crit_load_unmet_percentage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_grid_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_grid_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_grid_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_grid_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_interconnection_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_interconnection_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_outage_losses_unmet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_outage_losses_unmet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_system_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_system_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_system_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_system_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_system_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_system_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_outage_durations(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_outage_durations_aget, self->data_ptr);
}

static PyObject *
Outputs_get_outage_losses_unmet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_outage_losses_unmet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pdf_of_surviving(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_pdf_of_surviving_aget, self->data_ptr);
}

static PyObject *
Outputs_get_resilience_hrs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_resilience_hrs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_resilience_hrs_avg(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Outputs_resilience_hrs_avg_nget, self->data_ptr);
}

static PyObject *
Outputs_get_resilience_hrs_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Outputs_resilience_hrs_max_nget, self->data_ptr);
}

static PyObject *
Outputs_get_resilience_hrs_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Outputs_resilience_hrs_min_nget, self->data_ptr);
}

static PyObject *
Outputs_get_survival_function(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_survival_function_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_system_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_to_batt_dc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_system_to_batt_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_system_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_system_to_load_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_crit_load", (getter)Outputs_get_annual_crit_load,(setter)0,
	PyDoc_STR("*float*: Critical load energy (year 1) [kWh]"),
 	NULL},
{"annual_crit_load_unmet", (getter)Outputs_get_annual_crit_load_unmet,(setter)0,
	PyDoc_STR("*float*: Critical load energy unmet (year 1) [kWh]"),
 	NULL},
{"annual_crit_load_unmet_percentage", (getter)Outputs_get_annual_crit_load_unmet_percentage,(setter)0,
	PyDoc_STR("*float*: Critical load unmet percentage (year 1) [%]"),
 	NULL},
{"annual_export_to_grid_energy", (getter)Outputs_get_annual_export_to_grid_energy,(setter)0,
	PyDoc_STR("*sequence*: Annual energy exported to grid [kWh]"),
 	NULL},
{"annual_import_to_grid_energy", (getter)Outputs_get_annual_import_to_grid_energy,(setter)0,
	PyDoc_STR("*sequence*: Annual energy imported from grid [kWh]"),
 	NULL},
{"annual_outage_losses_unmet", (getter)Outputs_get_annual_outage_losses_unmet,(setter)0,
	PyDoc_STR("*float*: Battery and system losses unmet energy (year 1) [kWh]"),
 	NULL},
{"average_battery_conversion_efficiency", (getter)Outputs_get_average_battery_conversion_efficiency,(setter)0,
	PyDoc_STR("*float*: Battery average cycle conversion efficiency [%]"),
 	NULL},
{"average_battery_roundtrip_efficiency", (getter)Outputs_get_average_battery_roundtrip_efficiency,(setter)0,
	PyDoc_STR("*float*: Battery average roundtrip efficiency [%]"),
 	NULL},
{"avg_critical_load", (getter)Outputs_get_avg_critical_load,(setter)0,
	PyDoc_STR("*float*: Hours of autonomy during grid outage critical load met [kWh]"),
 	NULL},
{"batt_DOD", (getter)Outputs_get_batt_DOD,(setter)0,
	PyDoc_STR("*sequence*: Battery cycle depth of discharge [%]"),
 	NULL},
{"batt_DOD_cycle_average", (getter)Outputs_get_batt_DOD_cycle_average,(setter)0,
	PyDoc_STR("*sequence*: Battery average cycle DOD"),
 	NULL},
{"batt_I", (getter)Outputs_get_batt_I,(setter)0,
	PyDoc_STR("*sequence*: Battery current [A]"),
 	NULL},
{"batt_SOC", (getter)Outputs_get_batt_SOC,(setter)0,
	PyDoc_STR("*sequence*: Battery state of charge [%]"),
 	NULL},
{"batt_annual_charge_energy", (getter)Outputs_get_batt_annual_charge_energy,(setter)0,
	PyDoc_STR("*sequence*: Battery annual energy charged [kWh]"),
 	NULL},
{"batt_annual_charge_from_grid", (getter)Outputs_get_batt_annual_charge_from_grid,(setter)0,
	PyDoc_STR("*sequence*: Battery annual energy charged from grid [kWh]"),
 	NULL},
{"batt_annual_charge_from_system", (getter)Outputs_get_batt_annual_charge_from_system,(setter)0,
	PyDoc_STR("*sequence*: Battery annual energy charged from system [kWh]"),
 	NULL},
{"batt_annual_discharge_energy", (getter)Outputs_get_batt_annual_discharge_energy,(setter)0,
	PyDoc_STR("*sequence*: Battery annual energy discharged [kWh]"),
 	NULL},
{"batt_annual_energy_loss", (getter)Outputs_get_batt_annual_energy_loss,(setter)0,
	PyDoc_STR("*sequence*: Battery annual energy loss [kWh]"),
 	NULL},
{"batt_annual_energy_system_loss", (getter)Outputs_get_batt_annual_energy_system_loss,(setter)0,
	PyDoc_STR("*sequence*: Battery annual system energy loss [kWh]"),
 	NULL},
{"batt_bank_installed_capacity", (getter)Outputs_get_batt_bank_installed_capacity,(setter)0,
	PyDoc_STR("*float*: Battery bank installed capacity [kWh]"),
 	NULL},
{"batt_bank_replacement", (getter)Outputs_get_batt_bank_replacement,(setter)0,
	PyDoc_STR("*sequence*: Battery bank replacements per year [number/year]"),
 	NULL},
{"batt_capacity_percent", (getter)Outputs_get_batt_capacity_percent,(setter)0,
	PyDoc_STR("*sequence*: Battery relative capacity to nameplate [%]"),
 	NULL},
{"batt_capacity_percent_calendar", (getter)Outputs_get_batt_capacity_percent_calendar,(setter)0,
	PyDoc_STR("*sequence*: Battery relative capacity to nameplate (calendar) [%]"),
 	NULL},
{"batt_capacity_percent_cycle", (getter)Outputs_get_batt_capacity_percent_cycle,(setter)0,
	PyDoc_STR("*sequence*: Battery relative capacity to nameplate (cycling) [%]"),
 	NULL},
{"batt_capacity_thermal_percent", (getter)Outputs_get_batt_capacity_thermal_percent,(setter)0,
	PyDoc_STR("*sequence*: Battery capacity percent for temperature [%]"),
 	NULL},
{"batt_conversion_loss", (getter)Outputs_get_batt_conversion_loss,(setter)0,
	PyDoc_STR("*sequence*: Battery loss from power electronics [kW]"),
 	NULL},
{"batt_cost_to_cycle", (getter)Outputs_get_batt_cost_to_cycle,(setter)0,
	PyDoc_STR("*sequence*: Battery computed cycle degradation penalty [$/cycle-kWh]"),
 	NULL},
{"batt_cycles", (getter)Outputs_get_batt_cycles,(setter)0,
	PyDoc_STR("*sequence*: Battery number of cycles"),
 	NULL},
{"batt_dispatch_sched", (getter)Outputs_get_batt_dispatch_sched,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Battery dispatch schedule"),
 	NULL},
{"batt_power", (getter)Outputs_get_batt_power,(setter)0,
	PyDoc_STR("*sequence*: Electricity to/from battery AC [kW]"),
 	NULL},
{"batt_power_dc", (getter)Outputs_get_batt_power_dc,(setter)0,
	PyDoc_STR("*sequence*: Electricity to/from battery DC [kW]"),
 	NULL},
{"batt_power_target", (getter)Outputs_get_batt_power_target,(setter)0,
	PyDoc_STR("*sequence*: Electricity battery power target for automated dispatch [kW]"),
 	NULL},
{"batt_pvs_PV_ramp_interval", (getter)Outputs_get_batt_pvs_PV_ramp_interval,(setter)0,
	PyDoc_STR("*sequence*: PV smoothing PV power sampled [kW]"),
 	NULL},
{"batt_pvs_P_pv_ac", (getter)Outputs_get_batt_pvs_P_pv_ac,(setter)0,
	PyDoc_STR("*sequence*: PV smoothing PV power before smoothing [kW]"),
 	NULL},
{"batt_pvs_battpower", (getter)Outputs_get_batt_pvs_battpower,(setter)0,
	PyDoc_STR("*sequence*: PV smoothing battpower [kW]"),
 	NULL},
{"batt_pvs_battsoc", (getter)Outputs_get_batt_pvs_battsoc,(setter)0,
	PyDoc_STR("*sequence*: PV smoothing battery SOC [%]"),
 	NULL},
{"batt_pvs_curtail", (getter)Outputs_get_batt_pvs_curtail,(setter)0,
	PyDoc_STR("*sequence*: PV smoothing curtailed power [kW]"),
 	NULL},
{"batt_pvs_energy_to_grid_percent", (getter)Outputs_get_batt_pvs_energy_to_grid_percent,(setter)0,
	PyDoc_STR("*float*: PV smoothing energy to grid percent (loss due to curtail and battery loss) [%]"),
 	NULL},
{"batt_pvs_energy_to_grid_percent_sam", (getter)Outputs_get_batt_pvs_energy_to_grid_percent_sam,(setter)0,
	PyDoc_STR("*float*: PV smoothing energy to grid percent actual (loss due to curtail and battery loss) [%]"),
 	NULL},
{"batt_pvs_forecast_pv_energy", (getter)Outputs_get_batt_pvs_forecast_pv_energy,(setter)0,
	PyDoc_STR("*sequence*: PV smoothing PV power forecast [kW]"),
 	NULL},
{"batt_pvs_outpower", (getter)Outputs_get_batt_pvs_outpower,(setter)0,
	PyDoc_STR("*sequence*: PV smoothing outpower [kW]"),
 	NULL},
{"batt_pvs_violation_count", (getter)Outputs_get_batt_pvs_violation_count,(setter)0,
	PyDoc_STR("*float*: PV smoothing violation count"),
 	NULL},
{"batt_pvs_violation_list", (getter)Outputs_get_batt_pvs_violation_list,(setter)0,
	PyDoc_STR("*sequence*: PV smoothing violation"),
 	NULL},
{"batt_pvs_violation_percent", (getter)Outputs_get_batt_pvs_violation_percent,(setter)0,
	PyDoc_STR("*float*: PV smoothing violation percent (of all intervals-including nighttime) [%]"),
 	NULL},
{"batt_q0", (getter)Outputs_get_batt_q0,(setter)0,
	PyDoc_STR("*sequence*: Battery total charge [Ah]"),
 	NULL},
{"batt_q1", (getter)Outputs_get_batt_q1,(setter)0,
	PyDoc_STR("*sequence*: Battery available charge [Ah]"),
 	NULL},
{"batt_q2", (getter)Outputs_get_batt_q2,(setter)0,
	PyDoc_STR("*sequence*: Battery bound charge [Ah]"),
 	NULL},
{"batt_qmax", (getter)Outputs_get_batt_qmax,(setter)0,
	PyDoc_STR("*sequence*: Battery maximum charge with degradation [Ah]"),
 	NULL},
{"batt_qmaxI", (getter)Outputs_get_batt_qmaxI,(setter)0,
	PyDoc_STR("*sequence*: Battery maximum capacity at current [Ah]"),
 	NULL},
{"batt_qmax_thermal", (getter)Outputs_get_batt_qmax_thermal,(setter)0,
	PyDoc_STR("*sequence*: Battery maximum charge at temperature [Ah]"),
 	NULL},
{"batt_revenue_charge", (getter)Outputs_get_batt_revenue_charge,(setter)0,
	PyDoc_STR("*sequence*: Revenue to charge from system [$/kWh]"),
 	NULL},
{"batt_revenue_clipcharge", (getter)Outputs_get_batt_revenue_clipcharge,(setter)0,
	PyDoc_STR("*sequence*: Revenue to charge from clipped [$/kWh]"),
 	NULL},
{"batt_revenue_discharge", (getter)Outputs_get_batt_revenue_discharge,(setter)0,
	PyDoc_STR("*sequence*: Revenue to discharge [$/kWh]"),
 	NULL},
{"batt_revenue_gridcharge", (getter)Outputs_get_batt_revenue_gridcharge,(setter)0,
	PyDoc_STR("*sequence*: Revenue to charge from grid [$/kWh]"),
 	NULL},
{"batt_system_charge_percent", (getter)Outputs_get_batt_system_charge_percent,(setter)0,
	PyDoc_STR("*float*: Battery charge energy charged from system [%]"),
 	NULL},
{"batt_system_loss", (getter)Outputs_get_batt_system_loss,(setter)0,
	PyDoc_STR("*sequence*: Battery loss from ancillary equipment [kW]"),
 	NULL},
{"batt_temperature", (getter)Outputs_get_batt_temperature,(setter)0,
	PyDoc_STR("*sequence*: Battery temperature [C]"),
 	NULL},
{"batt_to_grid", (getter)Outputs_get_batt_to_grid,(setter)0,
	PyDoc_STR("*sequence*: Electricity to grid from battery AC [kW]"),
 	NULL},
{"batt_to_inverter_dc", (getter)Outputs_get_batt_to_inverter_dc,(setter)0,
	PyDoc_STR("*sequence*: Electricity to inverter from battery DC [kW]"),
 	NULL},
{"batt_to_load", (getter)Outputs_get_batt_to_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity to load from battery AC [kW]"),
 	NULL},
{"batt_to_system_load", (getter)Outputs_get_batt_to_system_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity to system loads from battery AC [kW]"),
 	NULL},
{"batt_voltage", (getter)Outputs_get_batt_voltage,(setter)0,
	PyDoc_STR("*sequence*: Battery voltage [V]"),
 	NULL},
{"batt_voltage_cell", (getter)Outputs_get_batt_voltage_cell,(setter)0,
	PyDoc_STR("*sequence*: Battery cell voltage [V]"),
 	NULL},
{"capacity_factor_sales", (getter)Outputs_get_capacity_factor_sales,(setter)0,
	PyDoc_STR("*float*: Capacity factor based on AC electricity to grid [%]"),
 	NULL},
{"cdf_of_surviving", (getter)Outputs_get_cdf_of_surviving,(setter)0,
	PyDoc_STR("*sequence*: Hours of autonomy during grid outage cumulative probabilities"),
 	NULL},
{"crit_load", (getter)Outputs_get_crit_load,(setter)0,
	PyDoc_STR("*sequence*: Critical load in this timestep [kW]"),
 	NULL},
{"crit_load_unmet", (getter)Outputs_get_crit_load_unmet,(setter)0,
	PyDoc_STR("*sequence*: Critical load unmet in this timestep [kW]"),
 	NULL},
{"fuelcell_to_batt", (getter)Outputs_get_fuelcell_to_batt,(setter)0,
	PyDoc_STR("*sequence*: Electricity to battery from fuel cell AC [kW]"),
 	NULL},
{"gen_without_battery", (getter)Outputs_get_gen_without_battery,(setter)0,
	PyDoc_STR("*sequence*: Power produced without the battery or curtailment [kW]"),
 	NULL},
{"grid_power", (getter)Outputs_get_grid_power,(setter)0,
	PyDoc_STR("*sequence*: Electricity to/from grid AC [kW]"),
 	NULL},
{"grid_power_target", (getter)Outputs_get_grid_power_target,(setter)0,
	PyDoc_STR("*sequence*: Electricity grid power target for automated dispatch [kW]"),
 	NULL},
{"grid_to_batt", (getter)Outputs_get_grid_to_batt,(setter)0,
	PyDoc_STR("*sequence*: Electricity to battery from grid AC [kW]"),
 	NULL},
{"grid_to_load", (getter)Outputs_get_grid_to_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity to load from grid AC [kW]"),
 	NULL},
{"interconnection_loss", (getter)Outputs_get_interconnection_loss,(setter)0,
	PyDoc_STR("*sequence*: Electricity loss due to curtailment interconnection outage [kW]"),
 	NULL},
{"market_sell_rate_series_yr1", (getter)Outputs_get_market_sell_rate_series_yr1,(setter)0,
	PyDoc_STR("*sequence*: Power price for battery dispatch [$/MWh]"),
 	NULL},
{"monthly_batt_to_grid", (getter)Outputs_get_monthly_batt_to_grid,(setter)0,
	PyDoc_STR("*sequence*: Energy to grid from battery [kWh]"),
 	NULL},
{"monthly_batt_to_load", (getter)Outputs_get_monthly_batt_to_load,(setter)0,
	PyDoc_STR("*sequence*: Energy to load from battery [kWh]"),
 	NULL},
{"monthly_batt_to_system_load", (getter)Outputs_get_monthly_batt_to_system_load,(setter)0,
	PyDoc_STR("*sequence*: Energy to system loads from battery [kWh]"),
 	NULL},
{"monthly_crit_load", (getter)Outputs_get_monthly_crit_load,(setter)0,
	PyDoc_STR("*sequence*: Critical load energy [kWh]"),
 	NULL},
{"monthly_crit_load_unmet", (getter)Outputs_get_monthly_crit_load_unmet,(setter)0,
	PyDoc_STR("*sequence*: Critical load energy unmet [kWh]"),
 	NULL},
{"monthly_crit_load_unmet_percentage", (getter)Outputs_get_monthly_crit_load_unmet_percentage,(setter)0,
	PyDoc_STR("*sequence*: Critical load unmet percentage [%]"),
 	NULL},
{"monthly_grid_to_batt", (getter)Outputs_get_monthly_grid_to_batt,(setter)0,
	PyDoc_STR("*sequence*: Energy to battery from grid [kWh]"),
 	NULL},
{"monthly_grid_to_load", (getter)Outputs_get_monthly_grid_to_load,(setter)0,
	PyDoc_STR("*sequence*: Energy to load from grid [kWh]"),
 	NULL},
{"monthly_interconnection_loss", (getter)Outputs_get_monthly_interconnection_loss,(setter)0,
	PyDoc_STR("*sequence*: Energy loss due to curtailment, interconnection, or outage [kWh]"),
 	NULL},
{"monthly_outage_losses_unmet", (getter)Outputs_get_monthly_outage_losses_unmet,(setter)0,
	PyDoc_STR("*sequence*: Battery and system losses unmet energy [kWh]"),
 	NULL},
{"monthly_system_to_batt", (getter)Outputs_get_monthly_system_to_batt,(setter)0,
	PyDoc_STR("*sequence*: Energy to battery from system [kWh]"),
 	NULL},
{"monthly_system_to_grid", (getter)Outputs_get_monthly_system_to_grid,(setter)0,
	PyDoc_STR("*sequence*: Energy to grid from system [kWh]"),
 	NULL},
{"monthly_system_to_load", (getter)Outputs_get_monthly_system_to_load,(setter)0,
	PyDoc_STR("*sequence*: Energy to load from system [kWh]"),
 	NULL},
{"outage_durations", (getter)Outputs_get_outage_durations,(setter)0,
	PyDoc_STR("*sequence*: Hours of autonomy during grid outage hour list from min to max [hr]"),
 	NULL},
{"outage_losses_unmet", (getter)Outputs_get_outage_losses_unmet,(setter)0,
	PyDoc_STR("*sequence*: Battery and system losses unmet in this timestep [kW]"),
 	NULL},
{"pdf_of_surviving", (getter)Outputs_get_pdf_of_surviving,(setter)0,
	PyDoc_STR("*sequence*: Hours of autonomy during grid outage probabilities"),
 	NULL},
{"resilience_hrs", (getter)Outputs_get_resilience_hrs,(setter)0,
	PyDoc_STR("*sequence*: Hours of autonomy during grid outage at each timestep [hr]"),
 	NULL},
{"resilience_hrs_avg", (getter)Outputs_get_resilience_hrs_avg,(setter)0,
	PyDoc_STR("*float*: Hours of autonomy during grid outage average [hr]"),
 	NULL},
{"resilience_hrs_max", (getter)Outputs_get_resilience_hrs_max,(setter)0,
	PyDoc_STR("*float*: Hours of autonomy during grid outage maximum [hr]"),
 	NULL},
{"resilience_hrs_min", (getter)Outputs_get_resilience_hrs_min,(setter)0,
	PyDoc_STR("*float*: Hours of autonomy during grid outage minimum [hr]"),
 	NULL},
{"survival_function", (getter)Outputs_get_survival_function,(setter)0,
	PyDoc_STR("*sequence*: Hours of autonomy during grid outage survival function"),
 	NULL},
{"system_to_batt", (getter)Outputs_get_system_to_batt,(setter)0,
	PyDoc_STR("*sequence*: Electricity to battery from system AC [kW]"),
 	NULL},
{"system_to_batt_dc", (getter)Outputs_get_system_to_batt_dc,(setter)0,
	PyDoc_STR("*sequence*: Electricity to battery from system DC [kW]"),
 	NULL},
{"system_to_grid", (getter)Outputs_get_system_to_grid,(setter)0,
	PyDoc_STR("*sequence*: Electricity to grid from system AC [kW]"),
 	NULL},
{"system_to_load", (getter)Outputs_get_system_to_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity to load from system AC [kW]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.Outputs",             /*tp_name*/
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
 * Battery
 */

static PyTypeObject Battery_Type;

static CmodObject *
newBatteryObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Battery_Type);

	PySAM_TECH_ATTR()

	PyObject* Simulation_obj = Simulation_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Simulation", Simulation_obj);
	Py_DECREF(Simulation_obj);

	PyObject* Lifetime_obj = Lifetime_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Lifetime", Lifetime_obj);
	Py_DECREF(Lifetime_obj);

	PyObject* BatterySystem_obj = BatterySystem_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "BatterySystem", BatterySystem_obj);
	Py_DECREF(BatterySystem_obj);

	PyObject* SystemOutput_obj = SystemOutput_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemOutput", SystemOutput_obj);
	Py_DECREF(SystemOutput_obj);

	PyObject* Load_obj = Load_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Load", Load_obj);
	Py_DECREF(Load_obj);

	PyObject* BatteryCell_obj = BatteryCell_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "BatteryCell", BatteryCell_obj);
	Py_DECREF(BatteryCell_obj);

	PyObject* Inverter_obj = Inverter_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Inverter", Inverter_obj);
	Py_DECREF(Inverter_obj);

	PyObject* Losses_obj = Losses_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Losses", Losses_obj);
	Py_DECREF(Losses_obj);

	PyObject* BatteryDispatch_obj = BatteryDispatch_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "BatteryDispatch", BatteryDispatch_obj);
	Py_DECREF(BatteryDispatch_obj);

	PyObject* SystemCosts_obj = SystemCosts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemCosts", SystemCosts_obj);
	Py_DECREF(SystemCosts_obj);

	PyObject* FuelCell_obj = FuelCell_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FuelCell", FuelCell_obj);
	Py_DECREF(FuelCell_obj);

	PyObject* PriceSignal_obj = PriceSignal_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "PriceSignal", PriceSignal_obj);
	Py_DECREF(PriceSignal_obj);

	PyObject* Revenue_obj = Revenue_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Revenue", Revenue_obj);
	Py_DECREF(Revenue_obj);

	PyObject* ElectricityRates_obj = ElectricityRates_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ElectricityRates", ElectricityRates_obj);
	Py_DECREF(ElectricityRates_obj);

	PyObject* GridLimits_obj = GridLimits_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "GridLimits", GridLimits_obj);
	Py_DECREF(GridLimits_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Battery methods */

static void
Battery_dealloc(CmodObject *self)
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
Battery_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Battery_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Battery_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Battery"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Battery_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Battery"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Battery_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Battery_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Battery_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Battery_methods[] = {
		{"execute",           (PyCFunction)Battery_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Battery_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Simulation': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Battery_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Simulation': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Battery_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Battery_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Battery_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Battery_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Battery_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Battery_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Battery_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Battery_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Battery_getattro, /*tp_getattro*/
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
		Battery_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Battery object */

static PyObject *
Battery_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newBatteryObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Battery_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newBatteryObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Battery_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newBatteryObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Battery", def) < 0) {
		Battery_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Battery_from_existing(PyObject *self, PyObject *args)
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

	rv = newBatteryObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Battery", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef BatteryModule_methods[] = {
		{"new",             Battery_new,         METH_VARARGS,
				PyDoc_STR("new() -> Battery")},
		{"default",             Battery_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Battery\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"FuelCellCommercial\"*\n\n		- *\"FuelCellSingleOwner\"*\n\n		- *\"GenericBatteryAllEquityPartnershipFlip\"*\n\n		- *\"GenericBatteryCommercial\"*\n\n		- *\"GenericBatteryHostDeveloper\"*\n\n		- *\"GenericBatteryLeveragedPartnershipFlip\"*\n\n		- *\"GenericBatteryMerchantPlant\"*\n\n		- *\"GenericBatteryResidential\"*\n\n		- *\"GenericBatterySaleLeaseback\"*\n\n		- *\"GenericBatterySingleOwner\"*\n\n		- *\"GenericBatteryThirdParty\"*\n\n		- *\"MEwaveBatterySingleOwner\"*\n\n		- *\"StandaloneBatteryAllEquityPartnershipFlip\"*\n\n		- *\"StandaloneBatteryCommercial\"*\n\n		- *\"StandaloneBatteryHostDeveloper\"*\n\n		- *\"StandaloneBatteryLeveragedPartnershipFlip\"*\n\n		- *\"StandaloneBatteryMerchantPlant\"*\n\n		- *\"StandaloneBatteryResidential\"*\n\n		- *\"StandaloneBatterySaleLeaseback\"*\n\n		- *\"StandaloneBatterySingleOwner\"*\n\n		- *\"StandaloneBatteryThirdParty\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Battery_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Battery\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Battery_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Battery\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Detailed battery storage model");


static int
BatteryModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Battery_Type.tp_dict = PyDict_New();
	if (!Battery_Type.tp_dict) { goto fail; }

	/// Add the Simulation type object to Battery_Type
	if (PyType_Ready(&Simulation_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"Simulation",
				(PyObject*)&Simulation_Type);
	Py_DECREF(&Simulation_Type);

	/// Add the Lifetime type object to Battery_Type
	if (PyType_Ready(&Lifetime_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"Lifetime",
				(PyObject*)&Lifetime_Type);
	Py_DECREF(&Lifetime_Type);

	/// Add the BatterySystem type object to Battery_Type
	if (PyType_Ready(&BatterySystem_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"BatterySystem",
				(PyObject*)&BatterySystem_Type);
	Py_DECREF(&BatterySystem_Type);

	/// Add the SystemOutput type object to Battery_Type
	if (PyType_Ready(&SystemOutput_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"SystemOutput",
				(PyObject*)&SystemOutput_Type);
	Py_DECREF(&SystemOutput_Type);

	/// Add the Load type object to Battery_Type
	if (PyType_Ready(&Load_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"Load",
				(PyObject*)&Load_Type);
	Py_DECREF(&Load_Type);

	/// Add the BatteryCell type object to Battery_Type
	if (PyType_Ready(&BatteryCell_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"BatteryCell",
				(PyObject*)&BatteryCell_Type);
	Py_DECREF(&BatteryCell_Type);

	/// Add the Inverter type object to Battery_Type
	if (PyType_Ready(&Inverter_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"Inverter",
				(PyObject*)&Inverter_Type);
	Py_DECREF(&Inverter_Type);

	/// Add the Losses type object to Battery_Type
	if (PyType_Ready(&Losses_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"Losses",
				(PyObject*)&Losses_Type);
	Py_DECREF(&Losses_Type);

	/// Add the BatteryDispatch type object to Battery_Type
	if (PyType_Ready(&BatteryDispatch_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"BatteryDispatch",
				(PyObject*)&BatteryDispatch_Type);
	Py_DECREF(&BatteryDispatch_Type);

	/// Add the SystemCosts type object to Battery_Type
	if (PyType_Ready(&SystemCosts_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"SystemCosts",
				(PyObject*)&SystemCosts_Type);
	Py_DECREF(&SystemCosts_Type);

	/// Add the FuelCell type object to Battery_Type
	if (PyType_Ready(&FuelCell_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"FuelCell",
				(PyObject*)&FuelCell_Type);
	Py_DECREF(&FuelCell_Type);

	/// Add the PriceSignal type object to Battery_Type
	if (PyType_Ready(&PriceSignal_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"PriceSignal",
				(PyObject*)&PriceSignal_Type);
	Py_DECREF(&PriceSignal_Type);

	/// Add the Revenue type object to Battery_Type
	if (PyType_Ready(&Revenue_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"Revenue",
				(PyObject*)&Revenue_Type);
	Py_DECREF(&Revenue_Type);

	/// Add the ElectricityRates type object to Battery_Type
	if (PyType_Ready(&ElectricityRates_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"ElectricityRates",
				(PyObject*)&ElectricityRates_Type);
	Py_DECREF(&ElectricityRates_Type);

	/// Add the GridLimits type object to Battery_Type
	if (PyType_Ready(&GridLimits_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"GridLimits",
				(PyObject*)&GridLimits_Type);
	Py_DECREF(&GridLimits_Type);

	/// Add the Outputs type object to Battery_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Battery type object to the module
	if (PyType_Ready(&Battery_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Battery",
				(PyObject*)&Battery_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot BatteryModule_slots[] = {
		{Py_mod_exec, BatteryModule_exec},
		{0, NULL},
};

static struct PyModuleDef BatteryModule = {
		PyModuleDef_HEAD_INIT,
		"Battery",
		module_doc,
		0,
		BatteryModule_methods,
		BatteryModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Battery(void)
{
	return PyModuleDef_Init(&BatteryModule);
}