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
Simulation_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Simulation_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Simulation_methods[] = {
		{"assign",            (PyCFunction)Simulation_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Simulation_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Simulation_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
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
	PyDoc_STR("*float*: Estimated simulation status [%]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Simulation_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"StandAloneBattery.Simulation",             /*tp_name*/
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
Lifetime_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Lifetime_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Lifetime_methods[] = {
		{"assign",            (PyCFunction)Lifetime_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Lifetime_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Lifetime_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
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
	PyDoc_STR("*float*: Lifetime analysis period [years]\n\n*Info*: The number of years in the simulation\n\n*Required*: True if system_use_lifetime_output=1"),
 	NULL},
{"system_use_lifetime_output", (getter)Lifetime_get_system_use_lifetime_output,(setter)Lifetime_set_system_use_lifetime_output,
	PyDoc_STR("*float*: Lifetime simulation [0/1]\n\n*Options*: 0=SingleYearRepeated,1=RunEveryYear\n\n*Constraints*: BOOLEAN\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Lifetime_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"StandAloneBattery.Lifetime",             /*tp_name*/
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
BatterySystem_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &BatterySystem_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef BatterySystem_methods[] = {
		{"assign",            (PyCFunction)BatterySystem_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``BatterySystem_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)BatterySystem_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
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
BatterySystem_get_batt_cycle_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_cycle_cost_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_cycle_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_cycle_cost_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_cycle_cost_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatterySystem_batt_cycle_cost_choice_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_cycle_cost_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatterySystem_batt_cycle_cost_choice_nset, self->data_ptr);
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
BatterySystem_get_batt_replacement_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatterySystem_batt_replacement_schedule_aget, self->data_ptr);
}

static int
BatterySystem_set_batt_replacement_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatterySystem_batt_replacement_schedule_aset, self->data_ptr);
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
	PyDoc_STR("*float*: Inverter AC to battery DC efficiency"),
 	NULL},
{"batt_ac_or_dc", (getter)BatterySystem_get_batt_ac_or_dc,(setter)BatterySystem_set_batt_ac_or_dc,
	PyDoc_STR("*float*: Battery interconnection (AC or DC)\n\n*Options*: 0=DC_Connected,1=AC_Connected\n\n*Changes to this variable may require updating the values of the following*: \n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"batt_computed_bank_capacity", (getter)BatterySystem_get_batt_computed_bank_capacity,(setter)BatterySystem_set_batt_computed_bank_capacity,
	PyDoc_STR("*float*: Computed bank capacity [kWh]\n\n*Changes to this variable may require updating the values of the following*: \n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_mass\n\t - batt_surface_area\n\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_computed_series", (getter)BatterySystem_get_batt_computed_series,(setter)BatterySystem_set_batt_computed_series,
	PyDoc_STR("*float*: Number of cells in series\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_computed_strings", (getter)BatterySystem_get_batt_computed_strings,(setter)BatterySystem_set_batt_computed_strings,
	PyDoc_STR("*float*: Number of strings of cells\n\n*Changes to this variable may require updating the values of the following*: \n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_current_charge_max", (getter)BatterySystem_get_batt_current_charge_max,(setter)BatterySystem_set_batt_current_charge_max,
	PyDoc_STR("*float*: Maximum charge current [A]\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_current_choice", (getter)BatterySystem_get_batt_current_choice,(setter)BatterySystem_set_batt_current_choice,
	PyDoc_STR("*float*: Limit cells by current or power\n\n*Changes to this variable may require updating the values of the following*: \n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"batt_current_discharge_max", (getter)BatterySystem_get_batt_current_discharge_max,(setter)BatterySystem_set_batt_current_discharge_max,
	PyDoc_STR("*float*: Maximum discharge current [A]\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_cycle_cost", (getter)BatterySystem_get_batt_cycle_cost,(setter)BatterySystem_set_batt_cycle_cost,
	PyDoc_STR("*float*: Input battery cycle costs [$/cycle-kWh]"),
 	NULL},
{"batt_cycle_cost_choice", (getter)BatterySystem_get_batt_cycle_cost_choice,(setter)BatterySystem_set_batt_cycle_cost_choice,
	PyDoc_STR("*float*: Use SAM model for cycle costs or input custom [0/1]\n\n*Options*: 0=UseCostModel,1=InputCost"),
 	NULL},
{"batt_dc_ac_efficiency", (getter)BatterySystem_get_batt_dc_ac_efficiency,(setter)BatterySystem_set_batt_dc_ac_efficiency,
	PyDoc_STR("*float*: Battery DC to AC efficiency\n\n*Changes to this variable may require updating the values of the following*: \n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"batt_dc_dc_efficiency", (getter)BatterySystem_get_batt_dc_dc_efficiency,(setter)BatterySystem_set_batt_dc_dc_efficiency,
	PyDoc_STR("*float*: PV DC to battery DC efficiency\n\n*Changes to this variable may require updating the values of the following*: \n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"batt_inverter_efficiency_cutoff", (getter)BatterySystem_get_batt_inverter_efficiency_cutoff,(setter)BatterySystem_set_batt_inverter_efficiency_cutoff,
	PyDoc_STR("*float*: Inverter efficiency at which to cut battery charge or discharge off [%]"),
 	NULL},
{"batt_loss_choice", (getter)BatterySystem_get_batt_loss_choice,(setter)BatterySystem_set_batt_loss_choice,
	PyDoc_STR("*float*: Loss power input option [0/1]\n\n*Options*: 0=Monthly,1=TimeSeries\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"batt_losses", (getter)BatterySystem_get_batt_losses,(setter)BatterySystem_set_batt_losses,
	PyDoc_STR("*sequence*: Battery system losses at each timestep [kW]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"batt_losses_charging", (getter)BatterySystem_get_batt_losses_charging,(setter)BatterySystem_set_batt_losses_charging,
	PyDoc_STR("*sequence*: Battery system losses when charging [kW]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"batt_losses_discharging", (getter)BatterySystem_get_batt_losses_discharging,(setter)BatterySystem_set_batt_losses_discharging,
	PyDoc_STR("*sequence*: Battery system losses when discharging [kW]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"batt_losses_idle", (getter)BatterySystem_get_batt_losses_idle,(setter)BatterySystem_set_batt_losses_idle,
	PyDoc_STR("*sequence*: Battery system losses when idle [kW]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"batt_mass", (getter)BatterySystem_get_batt_mass,(setter)BatterySystem_set_batt_mass,
	PyDoc_STR("*float*: Battery mass [kg]\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_computed_bank_capacity\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_meter_position", (getter)BatterySystem_get_batt_meter_position,(setter)BatterySystem_set_batt_meter_position,
	PyDoc_STR("*float*: Position of battery relative to electric meter\n\n*Options*: 0=BehindTheMeter,1=FrontOfMeter"),
 	NULL},
{"batt_power_charge_max_kwac", (getter)BatterySystem_get_batt_power_charge_max_kwac,(setter)BatterySystem_set_batt_power_charge_max_kwac,
	PyDoc_STR("*float*: Maximum charge power (AC) [kWac]\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_power_charge_max_kwdc", (getter)BatterySystem_get_batt_power_charge_max_kwdc,(setter)BatterySystem_set_batt_power_charge_max_kwdc,
	PyDoc_STR("*float*: Maximum charge power (DC) [kWdc]\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_power_discharge_max_kwac", (getter)BatterySystem_get_batt_power_discharge_max_kwac,(setter)BatterySystem_set_batt_power_discharge_max_kwac,
	PyDoc_STR("*float*: Maximum discharge power (AC) [kWac]\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_power_discharge_max_kwdc", (getter)BatterySystem_get_batt_power_discharge_max_kwdc,(setter)BatterySystem_set_batt_power_discharge_max_kwdc,
	PyDoc_STR("*float*: Maximum discharge power (DC) [kWdc]\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_replacement_capacity", (getter)BatterySystem_get_batt_replacement_capacity,(setter)BatterySystem_set_batt_replacement_capacity,
	PyDoc_STR("*float*: Capacity degradation at which to replace battery [%]"),
 	NULL},
{"batt_replacement_option", (getter)BatterySystem_get_batt_replacement_option,(setter)BatterySystem_set_batt_replacement_option,
	PyDoc_STR("*float*: Enable battery replacement? [0=none,1=capacity based,2=user schedule]\n\n*Constraints*: INTEGER,MIN=0,MAX=2\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"batt_replacement_schedule", (getter)BatterySystem_get_batt_replacement_schedule,(setter)BatterySystem_set_batt_replacement_schedule,
	PyDoc_STR("*sequence*: Battery bank number of replacements in each year [number/year]\n\n*Options*: length <= analysis_period\n\n*Required*: True if batt_replacement_option=2"),
 	NULL},
{"batt_replacement_schedule_percent", (getter)BatterySystem_get_batt_replacement_schedule_percent,(setter)BatterySystem_set_batt_replacement_schedule_percent,
	PyDoc_STR("*sequence*: Percentage of battery capacity to replace in each year [%]\n\n*Options*: length <= analysis_period\n\n*Required*: True if batt_replacement_option=2"),
 	NULL},
{"batt_surface_area", (getter)BatterySystem_get_batt_surface_area,(setter)BatterySystem_set_batt_surface_area,
	PyDoc_STR("*float*: Battery surface area [m^2]\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_computed_bank_capacity\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"en_batt", (getter)BatterySystem_get_en_batt,(setter)BatterySystem_set_en_batt,
	PyDoc_STR("*float*: Enable battery storage model [0/1]\n\n*Required*: If not provided, assumed to be 0"),
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
		"StandAloneBattery.BatterySystem",             /*tp_name*/
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
SystemOutput_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SystemOutput_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SystemOutput_methods[] = {
		{"assign",            (PyCFunction)SystemOutput_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``SystemOutput_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SystemOutput_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
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
	PyDoc_STR("*float*: Annual Energy [kWh]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"capacity_factor", (getter)SystemOutput_get_capacity_factor,(setter)SystemOutput_set_capacity_factor,
	PyDoc_STR("*float*: Capacity factor [%]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"gen", (getter)SystemOutput_get_gen,(setter)SystemOutput_set_gen,
	PyDoc_STR("*sequence*: System power generated [kW]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemOutput_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"StandAloneBattery.SystemOutput",             /*tp_name*/
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
Load_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Load_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Load_methods[] = {
		{"assign",            (PyCFunction)Load_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Load_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Load_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
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
Load_get_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Load_load_aget, self->data_ptr);
}

static int
Load_set_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_Load_load_aset, self->data_ptr);
}

static PyGetSetDef Load_getset[] = {
{"crit_load", (getter)Load_get_crit_load,(setter)Load_set_crit_load,
	PyDoc_STR("*sequence*: Critical electricity load (year 1) [kW]"),
 	NULL},
{"load", (getter)Load_get_load,(setter)Load_set_load,
	PyDoc_STR("*sequence*: Electricity load (year 1) [kW]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Load_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"StandAloneBattery.Load",             /*tp_name*/
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
BatteryCell_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &BatteryCell_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef BatteryCell_methods[] = {
		{"assign",            (PyCFunction)BatteryCell_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``BatteryCell_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)BatteryCell_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
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
	PyDoc_STR("*float*: Capacity at 10-hour discharge rate [Ah]\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_computed_strings\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"LeadAcid_q20_computed", (getter)BatteryCell_get_LeadAcid_q20_computed,(setter)BatteryCell_set_LeadAcid_q20_computed,
	PyDoc_STR("*float*: Capacity at 20-hour discharge rate [Ah]\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_computed_strings\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"LeadAcid_qn_computed", (getter)BatteryCell_get_LeadAcid_qn_computed,(setter)BatteryCell_set_LeadAcid_qn_computed,
	PyDoc_STR("*float*: Capacity at discharge rate for n-hour rate [Ah]\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_computed_strings\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
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
	PyDoc_STR("*float*: Cell capacity at end of exponential zone [Ah]\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_computed_bank_capacity\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_Qfull", (getter)BatteryCell_get_batt_Qfull,(setter)BatteryCell_set_batt_Qfull,
	PyDoc_STR("*float*: Fully charged cell capacity [Ah]\n\n*Changes to this variable may require updating the values of the following*: \n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"batt_Qfull_flow", (getter)BatteryCell_get_batt_Qfull_flow,(setter)BatteryCell_set_batt_Qfull_flow,
	PyDoc_STR("*float*: Fully charged flow battery capacity [Ah]\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_computed_bank_capacity\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
 	NULL},
{"batt_Qnom", (getter)BatteryCell_get_batt_Qnom,(setter)BatteryCell_set_batt_Qnom,
	PyDoc_STR("*float*: Cell capacity at end of nominal zone [Ah]\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - batt_Qfull\n\t - batt_Vnom_default\n\t - batt_ac_or_dc\n\t - batt_chem\n\t - batt_computed_bank_capacity\n\t - batt_current_choice\n\t - batt_dc_ac_efficiency\n\t - batt_dc_dc_efficiency\n"),
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
	PyDoc_STR("*float*: Default nominal cell voltage [V]\n\n*Changes to this variable may require updating the values of the following*: \n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"batt_calendar_a", (getter)BatteryCell_get_batt_calendar_a,(setter)BatteryCell_set_batt_calendar_a,
	PyDoc_STR("*float*: Calendar life model coefficient [1/sqrt(day)]"),
 	NULL},
{"batt_calendar_b", (getter)BatteryCell_get_batt_calendar_b,(setter)BatteryCell_set_batt_calendar_b,
	PyDoc_STR("*float*: Calendar life model coefficient [K]"),
 	NULL},
{"batt_calendar_c", (getter)BatteryCell_get_batt_calendar_c,(setter)BatteryCell_set_batt_calendar_c,
	PyDoc_STR("*float*: Calendar life model coefficient [K]"),
 	NULL},
{"batt_calendar_choice", (getter)BatteryCell_get_batt_calendar_choice,(setter)BatteryCell_set_batt_calendar_choice,
	PyDoc_STR("*float*: Calendar life degradation input option [0/1/2]\n\n*Options*: 0=NoCalendarDegradation,1=LithiomIonModel,2=InputLossTable"),
 	NULL},
{"batt_calendar_lifetime_matrix", (getter)BatteryCell_get_batt_calendar_lifetime_matrix,(setter)BatteryCell_set_batt_calendar_lifetime_matrix,
	PyDoc_STR("*sequence[sequence]*: Days vs capacity"),
 	NULL},
{"batt_calendar_q0", (getter)BatteryCell_get_batt_calendar_q0,(setter)BatteryCell_set_batt_calendar_q0,
	PyDoc_STR("*float*: Calendar life model initial capacity cofficient"),
 	NULL},
{"batt_chem", (getter)BatteryCell_get_batt_chem,(setter)BatteryCell_set_batt_chem,
	PyDoc_STR("*float*: Battery chemistry\n\n*Options*: 0=LeadAcid,1=LiIon\n\n*Changes to this variable may require updating the values of the following*: \n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"batt_h_to_ambient", (getter)BatteryCell_get_batt_h_to_ambient,(setter)BatteryCell_set_batt_h_to_ambient,
	PyDoc_STR("*float*: Heat transfer between battery and environment [W/m2K]"),
 	NULL},
{"batt_initial_SOC", (getter)BatteryCell_get_batt_initial_SOC,(setter)BatteryCell_set_batt_initial_SOC,
	PyDoc_STR("*float*: Initial state-of-charge [%]"),
 	NULL},
{"batt_lifetime_matrix", (getter)BatteryCell_get_batt_lifetime_matrix,(setter)BatteryCell_set_batt_lifetime_matrix,
	PyDoc_STR("*sequence[sequence]*: Cycles vs capacity at different depths-of-discharge"),
 	NULL},
{"batt_maximum_SOC", (getter)BatteryCell_get_batt_maximum_SOC,(setter)BatteryCell_set_batt_maximum_SOC,
	PyDoc_STR("*float*: Maximum allowed state-of-charge [%]"),
 	NULL},
{"batt_minimum_SOC", (getter)BatteryCell_get_batt_minimum_SOC,(setter)BatteryCell_set_batt_minimum_SOC,
	PyDoc_STR("*float*: Minimum allowed state-of-charge [%]"),
 	NULL},
{"batt_minimum_modetime", (getter)BatteryCell_get_batt_minimum_modetime,(setter)BatteryCell_set_batt_minimum_modetime,
	PyDoc_STR("*float*: Minimum time at charge state [min]"),
 	NULL},
{"batt_resistance", (getter)BatteryCell_get_batt_resistance,(setter)BatteryCell_set_batt_resistance,
	PyDoc_STR("*float*: Internal resistance [Ohm]"),
 	NULL},
{"batt_room_temperature_celsius", (getter)BatteryCell_get_batt_room_temperature_celsius,(setter)BatteryCell_set_batt_room_temperature_celsius,
	PyDoc_STR("*sequence*: Temperature of storage room [C]"),
 	NULL},
{"batt_voltage_choice", (getter)BatteryCell_get_batt_voltage_choice,(setter)BatteryCell_set_batt_voltage_choice,
	PyDoc_STR("*float*: Battery voltage input option [0/1]\n\n*Options*: 0=UseVoltageModel,1=InputVoltageTable\n\n*Required*: If not provided, assumed to be 0"),
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
		"StandAloneBattery.BatteryCell",             /*tp_name*/
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
Inverter_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Inverter_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Inverter_methods[] = {
		{"assign",            (PyCFunction)Inverter_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Inverter_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Inverter_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
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
	PyDoc_STR("*float*: Inverter Coefficient Generator CEC Efficiency [%]\n\n*Changes to this variable may require updating the values of the following*: \n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"inv_cec_cg_paco", (getter)Inverter_get_inv_cec_cg_paco,(setter)Inverter_set_inv_cec_cg_paco,
	PyDoc_STR("*float*: Inverter Coefficient Generator Max AC Power [Wac]"),
 	NULL},
{"inv_ds_eff", (getter)Inverter_get_inv_ds_eff,(setter)Inverter_set_inv_ds_eff,
	PyDoc_STR("*float*: Inverter Datasheet Efficiency [%]\n\n*Changes to this variable may require updating the values of the following*: \n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"inv_ds_paco", (getter)Inverter_get_inv_ds_paco,(setter)Inverter_set_inv_ds_paco,
	PyDoc_STR("*float*: Inverter Datasheet Maximum AC Power [Wac]"),
 	NULL},
{"inv_pd_eff", (getter)Inverter_get_inv_pd_eff,(setter)Inverter_set_inv_pd_eff,
	PyDoc_STR("*float*: Inverter Partload Efficiency [%]\n\n*Changes to this variable may require updating the values of the following*: \n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"inv_pd_paco", (getter)Inverter_get_inv_pd_paco,(setter)Inverter_set_inv_pd_paco,
	PyDoc_STR("*float*: Inverter Partload Maximum AC Power [Wac]"),
 	NULL},
{"inv_snl_eff_cec", (getter)Inverter_get_inv_snl_eff_cec,(setter)Inverter_set_inv_snl_eff_cec,
	PyDoc_STR("*float*: Inverter Sandia CEC Efficiency [%]\n\n*Changes to this variable may require updating the values of the following*: \n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
{"inv_snl_paco", (getter)Inverter_get_inv_snl_paco,(setter)Inverter_set_inv_snl_paco,
	PyDoc_STR("*float*: Inverter Sandia Maximum AC Power [Wac]"),
 	NULL},
{"inverter_count", (getter)Inverter_get_inverter_count,(setter)Inverter_set_inverter_count,
	PyDoc_STR("*float*: Number of inverters"),
 	NULL},
{"inverter_model", (getter)Inverter_get_inverter_model,(setter)Inverter_set_inverter_model,
	PyDoc_STR("*float*: Inverter model specifier\n\n*Options*: 0=cec,1=datasheet,2=partload,3=coefficientgenerator,4=generic\n\n*Constraints*: INTEGER,MIN=0,MAX=4\n\n*Required*: If not provided, assumed to be 4\n\n*Changes to this variable may require updating the values of the following*: \n\t - LeadAcid_q10_computed\n\t - LeadAcid_q20_computed\n\t - LeadAcid_qn_computed\n\t - batt_Qexp\n\t - batt_Qfull_flow\n\t - batt_Qnom\n\t - batt_computed_bank_capacity\n\t - batt_computed_series\n\t - batt_computed_strings\n\t - batt_current_charge_max\n\t - batt_current_discharge_max\n\t - batt_mass\n\t - batt_power_charge_max_kwac\n\t - batt_power_charge_max_kwdc\n\t - batt_power_discharge_max_kwac\n\t - batt_power_discharge_max_kwdc\n\t - batt_surface_area\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Inverter_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"StandAloneBattery.Inverter",             /*tp_name*/
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
Losses_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Losses_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Losses_methods[] = {
		{"assign",            (PyCFunction)Losses_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Losses_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Losses_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
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
	PyDoc_STR("*float*: PV loss in DC/DC w/MPPT conversion"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Losses_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"StandAloneBattery.Losses",             /*tp_name*/
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
BatteryDispatch_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &BatteryDispatch_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef BatteryDispatch_methods[] = {
		{"assign",            (PyCFunction)BatteryDispatch_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``BatteryDispatch_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)BatteryDispatch_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
BatteryDispatch_get_batt_auto_gridcharge_max_daily(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_BatteryDispatch_batt_auto_gridcharge_max_daily_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_auto_gridcharge_max_daily(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battery_BatteryDispatch_batt_auto_gridcharge_max_daily_nset, self->data_ptr);
}

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
BatteryDispatch_get_batt_pv_dc_forecast(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_BatteryDispatch_batt_pv_dc_forecast_aget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_pv_dc_forecast(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_BatteryDispatch_batt_pv_dc_forecast_aset, self->data_ptr);
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

static PyGetSetDef BatteryDispatch_getset[] = {
{"batt_auto_gridcharge_max_daily", (getter)BatteryDispatch_get_batt_auto_gridcharge_max_daily,(setter)BatteryDispatch_set_batt_auto_gridcharge_max_daily,
	PyDoc_STR("*float*: Allowed grid charging percent per day for automated dispatch [kW]"),
 	NULL},
{"batt_custom_dispatch", (getter)BatteryDispatch_get_batt_custom_dispatch,(setter)BatteryDispatch_set_batt_custom_dispatch,
	PyDoc_STR("*sequence*: Custom battery power for every time step [kW]\n\n*Info*: kWAC if AC-connected, else kWDC\n\n*Required*: True if en_batt=1&batt_dispatch_choice=3"),
 	NULL},
{"batt_dispatch_auto_can_charge", (getter)BatteryDispatch_get_batt_dispatch_auto_can_charge,(setter)BatteryDispatch_set_batt_dispatch_auto_can_charge,
	PyDoc_STR("*float*: PV charging allowed for automated dispatch? [kW]"),
 	NULL},
{"batt_dispatch_auto_can_clipcharge", (getter)BatteryDispatch_get_batt_dispatch_auto_can_clipcharge,(setter)BatteryDispatch_set_batt_dispatch_auto_can_clipcharge,
	PyDoc_STR("*float*: Battery can charge from clipped PV for automated dispatch? [kW]"),
 	NULL},
{"batt_dispatch_auto_can_fuelcellcharge", (getter)BatteryDispatch_get_batt_dispatch_auto_can_fuelcellcharge,(setter)BatteryDispatch_set_batt_dispatch_auto_can_fuelcellcharge,
	PyDoc_STR("*float*: Charging from fuel cell allowed for automated dispatch? [kW]"),
 	NULL},
{"batt_dispatch_auto_can_gridcharge", (getter)BatteryDispatch_get_batt_dispatch_auto_can_gridcharge,(setter)BatteryDispatch_set_batt_dispatch_auto_can_gridcharge,
	PyDoc_STR("*float*: Grid charging allowed for automated dispatch? [kW]"),
 	NULL},
{"batt_dispatch_choice", (getter)BatteryDispatch_get_batt_dispatch_choice,(setter)BatteryDispatch_set_batt_dispatch_choice,
	PyDoc_STR("*float*: Battery dispatch algorithm [0/1/2/3/4]\n\n*Options*: If behind the meter: 0=PeakShavingLookAhead,1=PeakShavingLookBehind,2=InputGridTarget,3=InputBatteryPower,4=ManualDispatch, if front of meter: 0=AutomatedLookAhead,1=AutomatedLookBehind,2=AutomatedInputForecast,3=InputBatteryPower,4=ManualDispatch\n\n*Required*: True if en_batt=1"),
 	NULL},
{"batt_dispatch_update_frequency_hours", (getter)BatteryDispatch_get_batt_dispatch_update_frequency_hours,(setter)BatteryDispatch_set_batt_dispatch_update_frequency_hours,
	PyDoc_STR("*float*: Frequency to update the look-ahead dispatch [hours]"),
 	NULL},
{"batt_look_ahead_hours", (getter)BatteryDispatch_get_batt_look_ahead_hours,(setter)BatteryDispatch_set_batt_look_ahead_hours,
	PyDoc_STR("*float*: Hours to look ahead in automated dispatch [hours]"),
 	NULL},
{"batt_pv_clipping_forecast", (getter)BatteryDispatch_get_batt_pv_clipping_forecast,(setter)BatteryDispatch_set_batt_pv_clipping_forecast,
	PyDoc_STR("*sequence*: PV clipping forecast [kW]\n\n*Required*: True if en_batt=1&batt_meter_position=1&batt_dispatch_choice=2"),
 	NULL},
{"batt_pv_dc_forecast", (getter)BatteryDispatch_get_batt_pv_dc_forecast,(setter)BatteryDispatch_set_batt_pv_dc_forecast,
	PyDoc_STR("*sequence*: PV dc power forecast [kW]\n\n*Required*: True if en_batt=1&batt_meter_position=1&batt_dispatch_choice=2"),
 	NULL},
{"batt_target_choice", (getter)BatteryDispatch_get_batt_target_choice,(setter)BatteryDispatch_set_batt_target_choice,
	PyDoc_STR("*float*: Target power input option [0/1]\n\n*Options*: 0=InputMonthlyTarget,1=InputFullTimeSeries\n\n*Required*: True if en_batt=1&batt_meter_position=0&batt_dispatch_choice=2"),
 	NULL},
{"batt_target_power", (getter)BatteryDispatch_get_batt_target_power,(setter)BatteryDispatch_set_batt_target_power,
	PyDoc_STR("*sequence*: Grid target power for every time step [kW]\n\n*Required*: True if en_batt=1&batt_meter_position=0&batt_dispatch_choice=2"),
 	NULL},
{"batt_target_power_monthly", (getter)BatteryDispatch_get_batt_target_power_monthly,(setter)BatteryDispatch_set_batt_target_power_monthly,
	PyDoc_STR("*sequence*: Grid target power on monthly basis [kW]\n\n*Required*: True if en_batt=1&batt_meter_position=0&batt_dispatch_choice=2"),
 	NULL},
{"dispatch_manual_charge", (getter)BatteryDispatch_get_dispatch_manual_charge,(setter)BatteryDispatch_set_dispatch_manual_charge,
	PyDoc_STR("*sequence*: Periods 1-6 charging from system allowed?\n\n*Required*: True if en_batt=1&batt_dispatch_choice=4"),
 	NULL},
{"dispatch_manual_discharge", (getter)BatteryDispatch_get_dispatch_manual_discharge,(setter)BatteryDispatch_set_dispatch_manual_discharge,
	PyDoc_STR("*sequence*: Periods 1-6 discharging allowed?\n\n*Required*: True if en_batt=1&batt_dispatch_choice=4\n\n*Changes to this variable may require updating the values of the following*: \n\t - dispatch_manual_percent_discharge\n"),
 	NULL},
{"dispatch_manual_fuelcellcharge", (getter)BatteryDispatch_get_dispatch_manual_fuelcellcharge,(setter)BatteryDispatch_set_dispatch_manual_fuelcellcharge,
	PyDoc_STR("*sequence*: Periods 1-6 charging from fuel cell allowed?"),
 	NULL},
{"dispatch_manual_gridcharge", (getter)BatteryDispatch_get_dispatch_manual_gridcharge,(setter)BatteryDispatch_set_dispatch_manual_gridcharge,
	PyDoc_STR("*sequence*: Periods 1-6 grid charging allowed?\n\n*Required*: True if en_batt=1&batt_dispatch_choice=4\n\n*Changes to this variable may require updating the values of the following*: \n\t - dispatch_manual_percent_gridcharge\n"),
 	NULL},
{"dispatch_manual_percent_discharge", (getter)BatteryDispatch_get_dispatch_manual_percent_discharge,(setter)BatteryDispatch_set_dispatch_manual_percent_discharge,
	PyDoc_STR("*sequence*: Periods 1-6 discharge percent [%]\n\n*Required*: True if en_batt=1&batt_dispatch_choice=4\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - dispatch_manual_discharge\n"),
 	NULL},
{"dispatch_manual_percent_gridcharge", (getter)BatteryDispatch_get_dispatch_manual_percent_gridcharge,(setter)BatteryDispatch_set_dispatch_manual_percent_gridcharge,
	PyDoc_STR("*sequence*: Periods 1-6 gridcharge percent [%]\n\n*Required*: True if en_batt=1&batt_dispatch_choice=4\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - dispatch_manual_gridcharge\n"),
 	NULL},
{"dispatch_manual_sched", (getter)BatteryDispatch_get_dispatch_manual_sched,(setter)BatteryDispatch_set_dispatch_manual_sched,
	PyDoc_STR("*sequence[sequence]*: Battery dispatch schedule for weekday\n\n*Required*: True if en_batt=1&batt_dispatch_choice=4"),
 	NULL},
{"dispatch_manual_sched_weekend", (getter)BatteryDispatch_get_dispatch_manual_sched_weekend,(setter)BatteryDispatch_set_dispatch_manual_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Battery dispatch schedule for weekend\n\n*Required*: True if en_batt=1&batt_dispatch_choice=4"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject BatteryDispatch_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"StandAloneBattery.BatteryDispatch",             /*tp_name*/
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
ElectricityRates_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &ElectricityRates_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ElectricityRates_methods[] = {
		{"assign",            (PyCFunction)ElectricityRates_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``ElectricityRates_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)ElectricityRates_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
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
ElectricityRates_get_ur_ts_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_ElectricityRates_ur_ts_buy_rate_aget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ts_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battery_ElectricityRates_ur_ts_buy_rate_aset, self->data_ptr);
}

static PyGetSetDef ElectricityRates_getset[] = {
{"en_electricity_rates", (getter)ElectricityRates_get_en_electricity_rates,(setter)ElectricityRates_set_en_electricity_rates,
	PyDoc_STR("*float*: Enable Electricity Rates [0/1]\n\n*Options*: 0=EnableElectricityRates,1=NoRates"),
 	NULL},
{"ur_ec_sched_weekday", (getter)ElectricityRates_get_ur_ec_sched_weekday,(setter)ElectricityRates_set_ur_ec_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: Energy charge weekday schedule\n\n*Info*: 12 x 24 matrix\n\n*Required*: True if en_batt=1&batt_meter_position=1&batt_dispatch_choice=2"),
 	NULL},
{"ur_ec_sched_weekend", (getter)ElectricityRates_get_ur_ec_sched_weekend,(setter)ElectricityRates_set_ur_ec_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Energy charge weekend schedule\n\n*Info*: 12 x 24 matrix\n\n*Required*: True if en_batt=1&batt_meter_position=1&batt_dispatch_choice=2"),
 	NULL},
{"ur_ec_tou_mat", (getter)ElectricityRates_get_ur_ec_tou_mat,(setter)ElectricityRates_set_ur_ec_tou_mat,
	PyDoc_STR("*sequence[sequence]*: Energy rates table\n\n*Required*: True if en_batt=1&batt_meter_position=1&batt_dispatch_choice=2"),
 	NULL},
{"ur_en_ts_sell_rate", (getter)ElectricityRates_get_ur_en_ts_sell_rate,(setter)ElectricityRates_set_ur_en_ts_sell_rate,
	PyDoc_STR("*float*: Enable time step sell rates [0/1]\n\n*Constraints*: BOOLEAN\n\n*Required*: True if en_batt=1&batt_meter_position=1&batt_dispatch_choice=2"),
 	NULL},
{"ur_ts_buy_rate", (getter)ElectricityRates_get_ur_ts_buy_rate,(setter)ElectricityRates_set_ur_ts_buy_rate,
	PyDoc_STR("*sequence*: Time step buy rates [0/1]\n\n*Required*: True if en_batt=1&batt_meter_position=1&batt_dispatch_choice=2"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ElectricityRates_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"StandAloneBattery.ElectricityRates",             /*tp_name*/
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
FuelCell_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &FuelCell_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef FuelCell_methods[] = {
		{"assign",            (PyCFunction)FuelCell_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``FuelCell_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)FuelCell_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
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
	PyDoc_STR("*sequence*: Electricity from fuel cell [kW]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FuelCell_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"StandAloneBattery.FuelCell",             /*tp_name*/
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
PriceSignal_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &PriceSignal_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef PriceSignal_methods[] = {
		{"assign",            (PyCFunction)PriceSignal_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``PriceSignal_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)PriceSignal_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
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
	PyDoc_STR("*sequence*: Dispatch payment factor time step\n\n*Required*: True if forecast_price_signal_model=0&en_batt=1&batt_meter_position=1&ppa_multiplier_model=1"),
 	NULL},
{"dispatch_sched_weekday", (getter)PriceSignal_get_dispatch_sched_weekday,(setter)PriceSignal_set_dispatch_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: Diurnal weekday TOD periods [1..9]\n\n*Info*: 12 x 24 matrix\n\n*Required*: True if en_batt=1&batt_meter_position=1&forecast_price_signal_model=0&ppa_multiplier_model=0"),
 	NULL},
{"dispatch_sched_weekend", (getter)PriceSignal_get_dispatch_sched_weekend,(setter)PriceSignal_set_dispatch_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Diurnal weekend TOD periods [1..9]\n\n*Info*: 12 x 24 matrix\n\n*Required*: True if en_batt=1&batt_meter_position=1&forecast_price_signal_model=0&ppa_multiplier_model=0"),
 	NULL},
{"dispatch_tod_factors", (getter)PriceSignal_get_dispatch_tod_factors,(setter)PriceSignal_set_dispatch_tod_factors,
	PyDoc_STR("*sequence*: TOD factors for periods 1-9\n\n*Required*: True if en_batt=1&batt_meter_position=1&forecast_price_signal_model=0&ppa_multiplier_model=0"),
 	NULL},
{"forecast_price_signal_model", (getter)PriceSignal_get_forecast_price_signal_model,(setter)PriceSignal_set_forecast_price_signal_model,
	PyDoc_STR("*float*: Forecast price signal model selected [0/1]\n\n*Options*: 0=PPA based,1=Merchant Plant\n\n*Constraints*: INTEGER,MIN=0,MAX=1\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"mp_ancserv1_revenue", (getter)PriceSignal_get_mp_ancserv1_revenue,(setter)PriceSignal_set_mp_ancserv1_revenue,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 1 revenue input [ [MW, $/MW]]\n\n*Required*: True if en_batt=1&batt_meter_position=1&forecast_price_signal_model=1"),
 	NULL},
{"mp_ancserv2_revenue", (getter)PriceSignal_get_mp_ancserv2_revenue,(setter)PriceSignal_set_mp_ancserv2_revenue,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 2 revenue input [ [MW, $/MW]]\n\n*Required*: True if en_batt=1&batt_meter_position=1&forecast_price_signal_model=1"),
 	NULL},
{"mp_ancserv3_revenue", (getter)PriceSignal_get_mp_ancserv3_revenue,(setter)PriceSignal_set_mp_ancserv3_revenue,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 3 revenue input [ [MW, $/MW]]\n\n*Required*: True if en_batt=1&batt_meter_position=1&forecast_price_signal_model=1"),
 	NULL},
{"mp_ancserv4_revenue", (getter)PriceSignal_get_mp_ancserv4_revenue,(setter)PriceSignal_set_mp_ancserv4_revenue,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 4 revenue input [ [MW, $/MW]]\n\n*Required*: True if en_batt=1&batt_meter_position=1&forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_ancserv1", (getter)PriceSignal_get_mp_enable_ancserv1,(setter)PriceSignal_set_mp_enable_ancserv1,
	PyDoc_STR("*float*: Enable ancillary services 1 revenue [0/1]\n\n*Constraints*: INTEGER,MIN=0,MAX=1\n\n*Required*: True if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_ancserv2", (getter)PriceSignal_get_mp_enable_ancserv2,(setter)PriceSignal_set_mp_enable_ancserv2,
	PyDoc_STR("*float*: Enable ancillary services 2 revenue [0/1]\n\n*Constraints*: INTEGER,MIN=0,MAX=1\n\n*Required*: True if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_ancserv3", (getter)PriceSignal_get_mp_enable_ancserv3,(setter)PriceSignal_set_mp_enable_ancserv3,
	PyDoc_STR("*float*: Enable ancillary services 3 revenue [0/1]\n\n*Constraints*: INTEGER,MIN=0,MAX=1\n\n*Required*: True if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_ancserv4", (getter)PriceSignal_get_mp_enable_ancserv4,(setter)PriceSignal_set_mp_enable_ancserv4,
	PyDoc_STR("*float*: Enable ancillary services 4 revenue [0/1]\n\n*Constraints*: INTEGER,MIN=0,MAX=1\n\n*Required*: True if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_energy_market_revenue", (getter)PriceSignal_get_mp_enable_energy_market_revenue,(setter)PriceSignal_set_mp_enable_energy_market_revenue,
	PyDoc_STR("*float*: Enable energy market revenue [0/1]\n\n*Options*: 0=false,1=true\n\n*Constraints*: INTEGER,MIN=0,MAX=1\n\n*Required*: True if en_batt=1&batt_meter_position=1&forecast_price_signal_model=1"),
 	NULL},
{"mp_energy_market_revenue", (getter)PriceSignal_get_mp_energy_market_revenue,(setter)PriceSignal_set_mp_energy_market_revenue,
	PyDoc_STR("*sequence[sequence]*: Energy market revenue input [ [MW, $/MW]]\n\n*Required*: True if en_batt=1&batt_meter_position=1&forecast_price_signal_model=1"),
 	NULL},
{"ppa_multiplier_model", (getter)PriceSignal_get_ppa_multiplier_model,(setter)PriceSignal_set_ppa_multiplier_model,
	PyDoc_STR("*float*: PPA multiplier model [0/1]\n\n*Options*: 0=diurnal,1=timestep\n\n*Constraints*: INTEGER,MIN=0\n\n*Required*: True if forecast_price_signal_model=0&en_batt=1&batt_meter_position=1"),
 	NULL},
{"ppa_price_input", (getter)PriceSignal_get_ppa_price_input,(setter)PriceSignal_set_ppa_price_input,
	PyDoc_STR("*sequence*: PPA Price Input\n\n*Required*: True if forecast_price_signal_model=0&en_batt=1&batt_meter_position=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject PriceSignal_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"StandAloneBattery.PriceSignal",             /*tp_name*/
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
Outputs_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Outputs_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Outputs_methods[] = {
		{"assign",            (PyCFunction)Outputs_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Outputs_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Outputs_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

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
Outputs_get_batt_annual_charge_from_pv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_annual_charge_from_pv_aget, self->data_ptr);
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
Outputs_get_batt_power_target(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_power_target_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pv_charge_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battery_Outputs_batt_pv_charge_percent_nget, self->data_ptr);
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
Outputs_get_batt_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_to_load_aget, self->data_ptr);
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
Outputs_get_cdf_of_surviving(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_cdf_of_surviving_aget, self->data_ptr);
}

static PyObject *
Outputs_get_fuelcell_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_fuelcell_to_batt_aget, self->data_ptr);
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
Outputs_get_monthly_pv_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_pv_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_pv_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_pv_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_pv_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_pv_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_outage_durations(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_outage_durations_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pdf_of_surviving(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_pdf_of_surviving_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pv_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_pv_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pv_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_pv_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pv_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_pv_to_load_aget, self->data_ptr);
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

static PyGetSetDef Outputs_getset[] = {
{"annual_export_to_grid_energy", (getter)Outputs_get_annual_export_to_grid_energy,(setter)0,
	PyDoc_STR("*sequence*: Annual energy exported to grid [kWh]"),
 	NULL},
{"annual_import_to_grid_energy", (getter)Outputs_get_annual_import_to_grid_energy,(setter)0,
	PyDoc_STR("*sequence*: Annual energy imported from grid [kWh]"),
 	NULL},
{"average_battery_conversion_efficiency", (getter)Outputs_get_average_battery_conversion_efficiency,(setter)0,
	PyDoc_STR("*float*: Battery average cycle conversion efficiency [%]"),
 	NULL},
{"average_battery_roundtrip_efficiency", (getter)Outputs_get_average_battery_roundtrip_efficiency,(setter)0,
	PyDoc_STR("*float*: Battery average roundtrip efficiency [%]"),
 	NULL},
{"avg_critical_load", (getter)Outputs_get_avg_critical_load,(setter)0,
	PyDoc_STR("*float*: Average critical load met for resilience [kWh]"),
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
{"batt_annual_charge_from_pv", (getter)Outputs_get_batt_annual_charge_from_pv,(setter)0,
	PyDoc_STR("*sequence*: Battery annual energy charged from PV [kWh]"),
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
	PyDoc_STR("*sequence*: Electricity loss in battery power electronics [kW]"),
 	NULL},
{"batt_cost_to_cycle", (getter)Outputs_get_batt_cost_to_cycle,(setter)0,
	PyDoc_STR("*sequence*: Battery computed cost to cycle [$/cycle]"),
 	NULL},
{"batt_cycles", (getter)Outputs_get_batt_cycles,(setter)0,
	PyDoc_STR("*sequence*: Battery number of cycles"),
 	NULL},
{"batt_dispatch_sched", (getter)Outputs_get_batt_dispatch_sched,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Battery dispatch schedule"),
 	NULL},
{"batt_power", (getter)Outputs_get_batt_power,(setter)0,
	PyDoc_STR("*sequence*: Electricity to/from battery [kW]"),
 	NULL},
{"batt_power_target", (getter)Outputs_get_batt_power_target,(setter)0,
	PyDoc_STR("*sequence*: Electricity battery power target for automated dispatch [kW]"),
 	NULL},
{"batt_pv_charge_percent", (getter)Outputs_get_batt_pv_charge_percent,(setter)0,
	PyDoc_STR("*float*: Battery percent energy charged from PV [%]"),
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
{"batt_system_loss", (getter)Outputs_get_batt_system_loss,(setter)0,
	PyDoc_STR("*sequence*: Electricity loss from battery ancillary equipment [kW]"),
 	NULL},
{"batt_temperature", (getter)Outputs_get_batt_temperature,(setter)0,
	PyDoc_STR("*sequence*: Battery temperature [C]"),
 	NULL},
{"batt_to_grid", (getter)Outputs_get_batt_to_grid,(setter)0,
	PyDoc_STR("*sequence*: Electricity to grid from battery [kW]"),
 	NULL},
{"batt_to_load", (getter)Outputs_get_batt_to_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity to load from battery [kW]"),
 	NULL},
{"batt_voltage", (getter)Outputs_get_batt_voltage,(setter)0,
	PyDoc_STR("*sequence*: Battery voltage [V]"),
 	NULL},
{"batt_voltage_cell", (getter)Outputs_get_batt_voltage_cell,(setter)0,
	PyDoc_STR("*sequence*: Battery cell voltage [V]"),
 	NULL},
{"cdf_of_surviving", (getter)Outputs_get_cdf_of_surviving,(setter)0,
	PyDoc_STR("*sequence*: Cumulative probabilities of autonomous hours for resilience"),
 	NULL},
{"fuelcell_to_batt", (getter)Outputs_get_fuelcell_to_batt,(setter)0,
	PyDoc_STR("*sequence*: Electricity to battery from fuel cell [kW]"),
 	NULL},
{"grid_power", (getter)Outputs_get_grid_power,(setter)0,
	PyDoc_STR("*sequence*: Electricity to/from grid [kW]"),
 	NULL},
{"grid_power_target", (getter)Outputs_get_grid_power_target,(setter)0,
	PyDoc_STR("*sequence*: Electricity grid power target for automated dispatch [kW]"),
 	NULL},
{"grid_to_batt", (getter)Outputs_get_grid_to_batt,(setter)0,
	PyDoc_STR("*sequence*: Electricity to battery from grid [kW]"),
 	NULL},
{"grid_to_load", (getter)Outputs_get_grid_to_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity to load from grid [kW]"),
 	NULL},
{"market_sell_rate_series_yr1", (getter)Outputs_get_market_sell_rate_series_yr1,(setter)0,
	PyDoc_STR("*sequence*: Market sell rate (Year 1) [$/MWh]"),
 	NULL},
{"monthly_batt_to_grid", (getter)Outputs_get_monthly_batt_to_grid,(setter)0,
	PyDoc_STR("*sequence*: Energy to grid from battery [kWh]"),
 	NULL},
{"monthly_batt_to_load", (getter)Outputs_get_monthly_batt_to_load,(setter)0,
	PyDoc_STR("*sequence*: Energy to load from battery [kWh]"),
 	NULL},
{"monthly_grid_to_batt", (getter)Outputs_get_monthly_grid_to_batt,(setter)0,
	PyDoc_STR("*sequence*: Energy to battery from grid [kWh]"),
 	NULL},
{"monthly_grid_to_load", (getter)Outputs_get_monthly_grid_to_load,(setter)0,
	PyDoc_STR("*sequence*: Energy to load from grid [kWh]"),
 	NULL},
{"monthly_pv_to_batt", (getter)Outputs_get_monthly_pv_to_batt,(setter)0,
	PyDoc_STR("*sequence*: Energy to battery from PV [kWh]"),
 	NULL},
{"monthly_pv_to_grid", (getter)Outputs_get_monthly_pv_to_grid,(setter)0,
	PyDoc_STR("*sequence*: Energy to grid from PV [kWh]"),
 	NULL},
{"monthly_pv_to_load", (getter)Outputs_get_monthly_pv_to_load,(setter)0,
	PyDoc_STR("*sequence*: Energy to load from PV [kWh]"),
 	NULL},
{"outage_durations", (getter)Outputs_get_outage_durations,(setter)0,
	PyDoc_STR("*sequence*: List of autonomous hours for resilience from min to max [hr]"),
 	NULL},
{"pdf_of_surviving", (getter)Outputs_get_pdf_of_surviving,(setter)0,
	PyDoc_STR("*sequence*: Probabilities of autonomous hours for resilience "),
 	NULL},
{"pv_to_batt", (getter)Outputs_get_pv_to_batt,(setter)0,
	PyDoc_STR("*sequence*: Electricity to battery from PV [kW]"),
 	NULL},
{"pv_to_grid", (getter)Outputs_get_pv_to_grid,(setter)0,
	PyDoc_STR("*sequence*: Electricity to grid from PV [kW]"),
 	NULL},
{"pv_to_load", (getter)Outputs_get_pv_to_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity to load from PV [kW]"),
 	NULL},
{"resilience_hrs", (getter)Outputs_get_resilience_hrs,(setter)0,
	PyDoc_STR("*sequence*: Hours of autonomy during outage at each timestep for resilience [hr]"),
 	NULL},
{"resilience_hrs_avg", (getter)Outputs_get_resilience_hrs_avg,(setter)0,
	PyDoc_STR("*float*: Avg hours of autonomy for resilience [hr]"),
 	NULL},
{"resilience_hrs_max", (getter)Outputs_get_resilience_hrs_max,(setter)0,
	PyDoc_STR("*float*: Max hours of autonomy for resilience [hr]"),
 	NULL},
{"resilience_hrs_min", (getter)Outputs_get_resilience_hrs_min,(setter)0,
	PyDoc_STR("*float*: Min hours of autonomy for resilience  [hr]"),
 	NULL},
{"survival_function", (getter)Outputs_get_survival_function,(setter)0,
	PyDoc_STR("*sequence*: Survival function of autonomous hours for resilience"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"StandAloneBattery.Outputs",             /*tp_name*/
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
 * StandAloneBattery
 */

static PyTypeObject StandAloneBattery_Type;

static CmodObject *
newStandAloneBatteryObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &StandAloneBattery_Type);

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

	PyObject* ElectricityRates_obj = ElectricityRates_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ElectricityRates", ElectricityRates_obj);
	Py_DECREF(ElectricityRates_obj);

	PyObject* FuelCell_obj = FuelCell_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FuelCell", FuelCell_obj);
	Py_DECREF(FuelCell_obj);

	PyObject* PriceSignal_obj = PriceSignal_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "PriceSignal", PriceSignal_obj);
	Py_DECREF(PriceSignal_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* StandAloneBattery methods */

static void
StandAloneBattery_dealloc(CmodObject *self)
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
StandAloneBattery_execute(CmodObject *self, PyObject *args)
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
StandAloneBattery_assign(CmodObject *self, PyObject *args)
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
StandAloneBattery_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
StandAloneBattery_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef StandAloneBattery_methods[] = {
		{"execute",            (PyCFunction)StandAloneBattery_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)StandAloneBattery_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Simulation': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)StandAloneBattery_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)StandAloneBattery_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
StandAloneBattery_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
StandAloneBattery_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject StandAloneBattery_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"StandAloneBattery",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)StandAloneBattery_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)StandAloneBattery_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)StandAloneBattery_getattro, /*tp_getattro*/
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
		StandAloneBattery_methods,      /*tp_methods*/
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


/* Function of no arguments returning new StandAloneBattery object */

static PyObject *
StandAloneBattery_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newStandAloneBatteryObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
StandAloneBattery_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newStandAloneBatteryObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
StandAloneBattery_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newStandAloneBatteryObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Battery", def);

	return (PyObject *)rv;
}

static PyObject *
StandAloneBattery_from_existing(PyObject *self, PyObject *args)
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

	rv = newStandAloneBatteryObject((void*)ptr);
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

static PyMethodDef StandAloneBatteryModule_methods[] = {
		{"new",             StandAloneBattery_new,         METH_VARARGS,
				PyDoc_STR("new() -> StandAloneBattery")},
		{"default",             StandAloneBattery_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> StandAloneBattery\n\nUse financial config-specific default attributes\n"
				"config options:\n\n- \"FuelCellCommercial\"\n- \"FuelCellSingleOwner\"\n- \"GenericBatteryAllEquityPartnershipFlip\"\n- \"GenericBatteryCommercial\"\n- \"GenericBatteryHostDeveloper\"\n- \"GenericBatteryLeveragedPartnershipFlip\"\n- \"GenericBatteryMerchantPlant\"\n- \"GenericBatteryResidential\"\n- \"GenericBatterySaleLeaseback\"\n- \"GenericBatterySingleOwner\"\n- \"GenericBatteryThirdParty\"")},
		{"wrap",             StandAloneBattery_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> StandAloneBattery\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   StandAloneBattery_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> StandAloneBattery\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Detailed battery storage model");


static int
StandAloneBatteryModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	StandAloneBattery_Type.tp_dict = PyDict_New();
	if (!StandAloneBattery_Type.tp_dict) { goto fail; }

	/// Add the Simulation type object to StandAloneBattery_Type
	if (PyType_Ready(&Simulation_Type) < 0) { goto fail; }
	PyDict_SetItemString(StandAloneBattery_Type.tp_dict,
				"Simulation",
				(PyObject*)&Simulation_Type);
	Py_DECREF(&Simulation_Type);

	/// Add the Lifetime type object to StandAloneBattery_Type
	if (PyType_Ready(&Lifetime_Type) < 0) { goto fail; }
	PyDict_SetItemString(StandAloneBattery_Type.tp_dict,
				"Lifetime",
				(PyObject*)&Lifetime_Type);
	Py_DECREF(&Lifetime_Type);

	/// Add the BatterySystem type object to StandAloneBattery_Type
	if (PyType_Ready(&BatterySystem_Type) < 0) { goto fail; }
	PyDict_SetItemString(StandAloneBattery_Type.tp_dict,
				"BatterySystem",
				(PyObject*)&BatterySystem_Type);
	Py_DECREF(&BatterySystem_Type);

	/// Add the SystemOutput type object to StandAloneBattery_Type
	if (PyType_Ready(&SystemOutput_Type) < 0) { goto fail; }
	PyDict_SetItemString(StandAloneBattery_Type.tp_dict,
				"SystemOutput",
				(PyObject*)&SystemOutput_Type);
	Py_DECREF(&SystemOutput_Type);

	/// Add the Load type object to StandAloneBattery_Type
	if (PyType_Ready(&Load_Type) < 0) { goto fail; }
	PyDict_SetItemString(StandAloneBattery_Type.tp_dict,
				"Load",
				(PyObject*)&Load_Type);
	Py_DECREF(&Load_Type);

	/// Add the BatteryCell type object to StandAloneBattery_Type
	if (PyType_Ready(&BatteryCell_Type) < 0) { goto fail; }
	PyDict_SetItemString(StandAloneBattery_Type.tp_dict,
				"BatteryCell",
				(PyObject*)&BatteryCell_Type);
	Py_DECREF(&BatteryCell_Type);

	/// Add the Inverter type object to StandAloneBattery_Type
	if (PyType_Ready(&Inverter_Type) < 0) { goto fail; }
	PyDict_SetItemString(StandAloneBattery_Type.tp_dict,
				"Inverter",
				(PyObject*)&Inverter_Type);
	Py_DECREF(&Inverter_Type);

	/// Add the Losses type object to StandAloneBattery_Type
	if (PyType_Ready(&Losses_Type) < 0) { goto fail; }
	PyDict_SetItemString(StandAloneBattery_Type.tp_dict,
				"Losses",
				(PyObject*)&Losses_Type);
	Py_DECREF(&Losses_Type);

	/// Add the BatteryDispatch type object to StandAloneBattery_Type
	if (PyType_Ready(&BatteryDispatch_Type) < 0) { goto fail; }
	PyDict_SetItemString(StandAloneBattery_Type.tp_dict,
				"BatteryDispatch",
				(PyObject*)&BatteryDispatch_Type);
	Py_DECREF(&BatteryDispatch_Type);

	/// Add the ElectricityRates type object to StandAloneBattery_Type
	if (PyType_Ready(&ElectricityRates_Type) < 0) { goto fail; }
	PyDict_SetItemString(StandAloneBattery_Type.tp_dict,
				"ElectricityRates",
				(PyObject*)&ElectricityRates_Type);
	Py_DECREF(&ElectricityRates_Type);

	/// Add the FuelCell type object to StandAloneBattery_Type
	if (PyType_Ready(&FuelCell_Type) < 0) { goto fail; }
	PyDict_SetItemString(StandAloneBattery_Type.tp_dict,
				"FuelCell",
				(PyObject*)&FuelCell_Type);
	Py_DECREF(&FuelCell_Type);

	/// Add the PriceSignal type object to StandAloneBattery_Type
	if (PyType_Ready(&PriceSignal_Type) < 0) { goto fail; }
	PyDict_SetItemString(StandAloneBattery_Type.tp_dict,
				"PriceSignal",
				(PyObject*)&PriceSignal_Type);
	Py_DECREF(&PriceSignal_Type);

	/// Add the Outputs type object to StandAloneBattery_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(StandAloneBattery_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the StandAloneBattery type object to the module
	if (PyType_Ready(&StandAloneBattery_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"StandAloneBattery",
				(PyObject*)&StandAloneBattery_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot StandAloneBatteryModule_slots[] = {
		{Py_mod_exec, StandAloneBatteryModule_exec},
		{0, NULL},
};

static struct PyModuleDef StandAloneBatteryModule = {
		PyModuleDef_HEAD_INIT,
		"StandAloneBattery",
		module_doc,
		0,
		StandAloneBatteryModule_methods,
		StandAloneBatteryModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_StandAloneBattery(void)
{
	return PyModuleDef_Init(&StandAloneBatteryModule);
}