#include <Python.h>

#include <SAM_Battery.h>
#include <SAM_api.h>

#include "PySAM_utils.h"



	/*
	 * Simulation Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Battery   data_ptr;
} SimulationObject;

static PyTypeObject Simulation_Type;

static PyObject *
Simulation_new(SAM_Battery data_ptr)
{
	PyObject* new_obj = Simulation_Type.tp_alloc(&Simulation_Type,0);

	SimulationObject* Simulation_obj = (SimulationObject*)new_obj;

	Simulation_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Simulation methods */

static PyObject *
Simulation_assign(SimulationObject *self, PyObject *args)
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
Simulation_export(SimulationObject *self, PyObject *args)
{
	PyTypeObject* tp = &Simulation_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Simulation_methods[] = {
		{"assign",            (PyCFunction)Simulation_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Simulation_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Simulation_get_analysis_period(SimulationObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Simulation_analysis_period_fget, self->data_ptr);
}

static int
Simulation_set_analysis_period(SimulationObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Simulation_analysis_period_fset, self->data_ptr);
}

static PyObject *
Simulation_get_percent_complete(SimulationObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Simulation_percent_complete_fget, self->data_ptr);
}

static int
Simulation_set_percent_complete(SimulationObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Simulation_percent_complete_fset, self->data_ptr);
}

static PyObject *
Simulation_get_system_use_lifetime_output(SimulationObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Simulation_system_use_lifetime_output_fget, self->data_ptr);
}

static int
Simulation_set_system_use_lifetime_output(SimulationObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Simulation_system_use_lifetime_output_fset, self->data_ptr);
}

static PyGetSetDef Simulation_getset[] = {
{"analysis_period", (getter)Simulation_get_analysis_period,(setter)Simulation_set_analysis_period,
	"Lifetime analysis period [years], number.\n The number of years in the simulation; Required if: system_use_lifetime_output=1.",
 	NULL},
{"percent_complete", (getter)Simulation_get_percent_complete,(setter)Simulation_set_percent_complete,
	"Estimated simulation status [%], number.\n ",
 	NULL},
{"system_use_lifetime_output", (getter)Simulation_get_system_use_lifetime_output,(setter)Simulation_set_system_use_lifetime_output,
	"Lifetime simulation [0/1], number.\n 0=SingleYearRepeated,1=RunEveryYear; Constraints: BOOLEAN; Required if: ?=0.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Simulation_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.Simulation",             /*tp_name*/
		sizeof(SimulationObject),          /*tp_basicsize*/
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
		Simulation_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Simulation_getset,          /*tp_getset*/
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
	SAM_Battery   data_ptr;
} BatteryObject;

static PyTypeObject Battery_Type;

static PyObject *
Battery_new(SAM_Battery data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "Battery")){
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
Battery_get_LeadAcid_q10_computed(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_LeadAcid_q10_computed_fget, self->data_ptr);
}

static int
Battery_set_LeadAcid_q10_computed(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_LeadAcid_q10_computed_fset, self->data_ptr);
}

static PyObject *
Battery_get_LeadAcid_q20_computed(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_LeadAcid_q20_computed_fget, self->data_ptr);
}

static int
Battery_set_LeadAcid_q20_computed(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_LeadAcid_q20_computed_fset, self->data_ptr);
}

static PyObject *
Battery_get_LeadAcid_qn_computed(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_LeadAcid_qn_computed_fget, self->data_ptr);
}

static int
Battery_set_LeadAcid_qn_computed(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_LeadAcid_qn_computed_fset, self->data_ptr);
}

static PyObject *
Battery_get_LeadAcid_tn(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_LeadAcid_tn_fget, self->data_ptr);
}

static int
Battery_set_LeadAcid_tn(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_LeadAcid_tn_fset, self->data_ptr);
}

static PyObject *
Battery_get_annual_energy(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_annual_energy_fget, self->data_ptr);
}

static int
Battery_set_annual_energy(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_annual_energy_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_C_rate(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_C_rate_fget, self->data_ptr);
}

static int
Battery_set_batt_C_rate(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_C_rate_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_Cp(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_Cp_fget, self->data_ptr);
}

static int
Battery_set_batt_Cp(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_Cp_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_Qexp(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_Qexp_fget, self->data_ptr);
}

static int
Battery_set_batt_Qexp(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_Qexp_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_Qfull(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_Qfull_fget, self->data_ptr);
}

static int
Battery_set_batt_Qfull(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_Qfull_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_Qfull_flow(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_Qfull_flow_fget, self->data_ptr);
}

static int
Battery_set_batt_Qfull_flow(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_Qfull_flow_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_Qnom(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_Qnom_fget, self->data_ptr);
}

static int
Battery_set_batt_Qnom(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_Qnom_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_Vexp(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_Vexp_fget, self->data_ptr);
}

static int
Battery_set_batt_Vexp(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_Vexp_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_Vfull(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_Vfull_fget, self->data_ptr);
}

static int
Battery_set_batt_Vfull(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_Vfull_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_Vnom(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_Vnom_fget, self->data_ptr);
}

static int
Battery_set_batt_Vnom(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_Vnom_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_Vnom_default(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_Vnom_default_fget, self->data_ptr);
}

static int
Battery_set_batt_Vnom_default(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_Vnom_default_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_ac_dc_efficiency(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_ac_dc_efficiency_fget, self->data_ptr);
}

static int
Battery_set_batt_ac_dc_efficiency(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_ac_dc_efficiency_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_ac_or_dc(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_ac_or_dc_fget, self->data_ptr);
}

static int
Battery_set_batt_ac_or_dc(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_ac_or_dc_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_auto_gridcharge_max_daily(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_auto_gridcharge_max_daily_fget, self->data_ptr);
}

static int
Battery_set_batt_auto_gridcharge_max_daily(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_auto_gridcharge_max_daily_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_calendar_a(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_calendar_a_fget, self->data_ptr);
}

static int
Battery_set_batt_calendar_a(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_calendar_a_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_calendar_b(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_calendar_b_fget, self->data_ptr);
}

static int
Battery_set_batt_calendar_b(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_calendar_b_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_calendar_c(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_calendar_c_fget, self->data_ptr);
}

static int
Battery_set_batt_calendar_c(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_calendar_c_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_calendar_choice(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_calendar_choice_fget, self->data_ptr);
}

static int
Battery_set_batt_calendar_choice(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_calendar_choice_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_calendar_lifetime_matrix(BatteryObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_Battery_batt_calendar_lifetime_matrix_mget, self->data_ptr);
}

static int
Battery_set_batt_calendar_lifetime_matrix(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_Battery_batt_calendar_lifetime_matrix_mset, self->data_ptr);
}

static PyObject *
Battery_get_batt_calendar_q0(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_calendar_q0_fget, self->data_ptr);
}

static int
Battery_set_batt_calendar_q0(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_calendar_q0_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_chem(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_chem_fget, self->data_ptr);
}

static int
Battery_set_batt_chem(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_chem_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_computed_bank_capacity(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_computed_bank_capacity_fget, self->data_ptr);
}

static int
Battery_set_batt_computed_bank_capacity(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_computed_bank_capacity_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_computed_series(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_computed_series_fget, self->data_ptr);
}

static int
Battery_set_batt_computed_series(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_computed_series_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_computed_strings(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_computed_strings_fget, self->data_ptr);
}

static int
Battery_set_batt_computed_strings(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_computed_strings_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_current_charge_max(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_current_charge_max_fget, self->data_ptr);
}

static int
Battery_set_batt_current_charge_max(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_current_charge_max_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_current_choice(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_current_choice_fget, self->data_ptr);
}

static int
Battery_set_batt_current_choice(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_current_choice_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_current_discharge_max(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_current_discharge_max_fget, self->data_ptr);
}

static int
Battery_set_batt_current_discharge_max(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_current_discharge_max_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_custom_dispatch(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Battery_batt_custom_dispatch_aget, self->data_ptr);
}

static int
Battery_set_batt_custom_dispatch(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_Battery_batt_custom_dispatch_aset, self->data_ptr);
}

static PyObject *
Battery_get_batt_cycle_cost(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_cycle_cost_fget, self->data_ptr);
}

static int
Battery_set_batt_cycle_cost(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_cycle_cost_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_cycle_cost_choice(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_cycle_cost_choice_fget, self->data_ptr);
}

static int
Battery_set_batt_cycle_cost_choice(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_cycle_cost_choice_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_dc_ac_efficiency(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_dc_ac_efficiency_fget, self->data_ptr);
}

static int
Battery_set_batt_dc_ac_efficiency(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_dc_ac_efficiency_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_dc_dc_efficiency(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_dc_dc_efficiency_fget, self->data_ptr);
}

static int
Battery_set_batt_dc_dc_efficiency(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_dc_dc_efficiency_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_dispatch_auto_can_charge(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_dispatch_auto_can_charge_fget, self->data_ptr);
}

static int
Battery_set_batt_dispatch_auto_can_charge(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_dispatch_auto_can_charge_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_dispatch_auto_can_clipcharge(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_dispatch_auto_can_clipcharge_fget, self->data_ptr);
}

static int
Battery_set_batt_dispatch_auto_can_clipcharge(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_dispatch_auto_can_clipcharge_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_dispatch_auto_can_fuelcellcharge(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_dispatch_auto_can_fuelcellcharge_fget, self->data_ptr);
}

static int
Battery_set_batt_dispatch_auto_can_fuelcellcharge(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_dispatch_auto_can_fuelcellcharge_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_dispatch_auto_can_gridcharge(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_dispatch_auto_can_gridcharge_fget, self->data_ptr);
}

static int
Battery_set_batt_dispatch_auto_can_gridcharge(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_dispatch_auto_can_gridcharge_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_dispatch_choice(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_dispatch_choice_fget, self->data_ptr);
}

static int
Battery_set_batt_dispatch_choice(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_dispatch_choice_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_dispatch_update_frequency_hours(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_dispatch_update_frequency_hours_fget, self->data_ptr);
}

static int
Battery_set_batt_dispatch_update_frequency_hours(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_dispatch_update_frequency_hours_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_h_to_ambient(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_h_to_ambient_fget, self->data_ptr);
}

static int
Battery_set_batt_h_to_ambient(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_h_to_ambient_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_height(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_height_fget, self->data_ptr);
}

static int
Battery_set_batt_height(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_height_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_initial_SOC(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_initial_SOC_fget, self->data_ptr);
}

static int
Battery_set_batt_initial_SOC(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_initial_SOC_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_length(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_length_fget, self->data_ptr);
}

static int
Battery_set_batt_length(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_length_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_lifetime_matrix(BatteryObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_Battery_batt_lifetime_matrix_mget, self->data_ptr);
}

static int
Battery_set_batt_lifetime_matrix(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_Battery_batt_lifetime_matrix_mset, self->data_ptr);
}

static PyObject *
Battery_get_batt_look_ahead_hours(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_look_ahead_hours_fget, self->data_ptr);
}

static int
Battery_set_batt_look_ahead_hours(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_look_ahead_hours_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_loss_choice(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_loss_choice_fget, self->data_ptr);
}

static int
Battery_set_batt_loss_choice(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_loss_choice_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_losses(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Battery_batt_losses_aget, self->data_ptr);
}

static int
Battery_set_batt_losses(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_Battery_batt_losses_aset, self->data_ptr);
}

static PyObject *
Battery_get_batt_losses_charging(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Battery_batt_losses_charging_aget, self->data_ptr);
}

static int
Battery_set_batt_losses_charging(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_Battery_batt_losses_charging_aset, self->data_ptr);
}

static PyObject *
Battery_get_batt_losses_discharging(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Battery_batt_losses_discharging_aget, self->data_ptr);
}

static int
Battery_set_batt_losses_discharging(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_Battery_batt_losses_discharging_aset, self->data_ptr);
}

static PyObject *
Battery_get_batt_losses_idle(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Battery_batt_losses_idle_aget, self->data_ptr);
}

static int
Battery_set_batt_losses_idle(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_Battery_batt_losses_idle_aset, self->data_ptr);
}

static PyObject *
Battery_get_batt_mass(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_mass_fget, self->data_ptr);
}

static int
Battery_set_batt_mass(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_mass_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_maximum_SOC(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_maximum_SOC_fget, self->data_ptr);
}

static int
Battery_set_batt_maximum_SOC(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_maximum_SOC_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_meter_position(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_meter_position_fget, self->data_ptr);
}

static int
Battery_set_batt_meter_position(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_meter_position_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_minimum_SOC(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_minimum_SOC_fget, self->data_ptr);
}

static int
Battery_set_batt_minimum_SOC(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_minimum_SOC_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_minimum_modetime(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_minimum_modetime_fget, self->data_ptr);
}

static int
Battery_set_batt_minimum_modetime(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_minimum_modetime_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_power_charge_max(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_power_charge_max_fget, self->data_ptr);
}

static int
Battery_set_batt_power_charge_max(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_power_charge_max_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_power_discharge_max(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_power_discharge_max_fget, self->data_ptr);
}

static int
Battery_set_batt_power_discharge_max(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_power_discharge_max_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_pv_clipping_forecast(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Battery_batt_pv_clipping_forecast_aget, self->data_ptr);
}

static int
Battery_set_batt_pv_clipping_forecast(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_Battery_batt_pv_clipping_forecast_aset, self->data_ptr);
}

static PyObject *
Battery_get_batt_pv_dc_forecast(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Battery_batt_pv_dc_forecast_aget, self->data_ptr);
}

static int
Battery_set_batt_pv_dc_forecast(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_Battery_batt_pv_dc_forecast_aset, self->data_ptr);
}

static PyObject *
Battery_get_batt_replacement_capacity(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_replacement_capacity_fget, self->data_ptr);
}

static int
Battery_set_batt_replacement_capacity(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_replacement_capacity_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_replacement_option(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_replacement_option_fget, self->data_ptr);
}

static int
Battery_set_batt_replacement_option(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_replacement_option_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_replacement_schedule(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Battery_batt_replacement_schedule_aget, self->data_ptr);
}

static int
Battery_set_batt_replacement_schedule(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_Battery_batt_replacement_schedule_aset, self->data_ptr);
}

static PyObject *
Battery_get_batt_resistance(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_resistance_fget, self->data_ptr);
}

static int
Battery_set_batt_resistance(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_resistance_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_room_temperature_celsius(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Battery_batt_room_temperature_celsius_aget, self->data_ptr);
}

static int
Battery_set_batt_room_temperature_celsius(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_Battery_batt_room_temperature_celsius_aset, self->data_ptr);
}

static PyObject *
Battery_get_batt_target_choice(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_target_choice_fget, self->data_ptr);
}

static int
Battery_set_batt_target_choice(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_target_choice_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_target_power(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Battery_batt_target_power_aget, self->data_ptr);
}

static int
Battery_set_batt_target_power(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_Battery_batt_target_power_aset, self->data_ptr);
}

static PyObject *
Battery_get_batt_target_power_monthly(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Battery_batt_target_power_monthly_aget, self->data_ptr);
}

static int
Battery_set_batt_target_power_monthly(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_Battery_batt_target_power_monthly_aset, self->data_ptr);
}

static PyObject *
Battery_get_batt_voltage_choice(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_voltage_choice_fget, self->data_ptr);
}

static int
Battery_set_batt_voltage_choice(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_voltage_choice_fset, self->data_ptr);
}

static PyObject *
Battery_get_batt_voltage_matrix(BatteryObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_Battery_batt_voltage_matrix_mget, self->data_ptr);
}

static int
Battery_set_batt_voltage_matrix(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_Battery_batt_voltage_matrix_mset, self->data_ptr);
}

static PyObject *
Battery_get_batt_width(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_batt_width_fget, self->data_ptr);
}

static int
Battery_set_batt_width(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_batt_width_fset, self->data_ptr);
}

static PyObject *
Battery_get_cap_vs_temp(BatteryObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_Battery_cap_vs_temp_mget, self->data_ptr);
}

static int
Battery_set_cap_vs_temp(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_Battery_cap_vs_temp_mset, self->data_ptr);
}

static PyObject *
Battery_get_dispatch_manual_charge(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Battery_dispatch_manual_charge_aget, self->data_ptr);
}

static int
Battery_set_dispatch_manual_charge(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_Battery_dispatch_manual_charge_aset, self->data_ptr);
}

static PyObject *
Battery_get_dispatch_manual_discharge(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Battery_dispatch_manual_discharge_aget, self->data_ptr);
}

static int
Battery_set_dispatch_manual_discharge(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_Battery_dispatch_manual_discharge_aset, self->data_ptr);
}

static PyObject *
Battery_get_dispatch_manual_gridcharge(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Battery_dispatch_manual_gridcharge_aget, self->data_ptr);
}

static int
Battery_set_dispatch_manual_gridcharge(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_Battery_dispatch_manual_gridcharge_aset, self->data_ptr);
}

static PyObject *
Battery_get_dispatch_manual_percent_discharge(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Battery_dispatch_manual_percent_discharge_aget, self->data_ptr);
}

static int
Battery_set_dispatch_manual_percent_discharge(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_Battery_dispatch_manual_percent_discharge_aset, self->data_ptr);
}

static PyObject *
Battery_get_dispatch_manual_percent_gridcharge(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Battery_dispatch_manual_percent_gridcharge_aget, self->data_ptr);
}

static int
Battery_set_dispatch_manual_percent_gridcharge(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_Battery_dispatch_manual_percent_gridcharge_aset, self->data_ptr);
}

static PyObject *
Battery_get_dispatch_manual_sched(BatteryObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_Battery_dispatch_manual_sched_mget, self->data_ptr);
}

static int
Battery_set_dispatch_manual_sched(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_Battery_dispatch_manual_sched_mset, self->data_ptr);
}

static PyObject *
Battery_get_dispatch_manual_sched_weekend(BatteryObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_Battery_dispatch_manual_sched_weekend_mget, self->data_ptr);
}

static int
Battery_set_dispatch_manual_sched_weekend(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_Battery_dispatch_manual_sched_weekend_mset, self->data_ptr);
}

static PyObject *
Battery_get_en_batt(BatteryObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Battery_en_batt_fget, self->data_ptr);
}

static int
Battery_set_en_batt(BatteryObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Battery_en_batt_fset, self->data_ptr);
}

static PyObject *
Battery_get_om_replacement_cost1(BatteryObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Battery_om_replacement_cost1_aget, self->data_ptr);
}

static int
Battery_set_om_replacement_cost1(BatteryObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_Battery_om_replacement_cost1_aset, self->data_ptr);
}

static PyGetSetDef Battery_getset[] = {
{"LeadAcid_q10_computed", (getter)Battery_get_LeadAcid_q10_computed,(setter)Battery_set_LeadAcid_q10_computed,
	"Capacity at 10-hour discharge rate [Ah], number.\n ",
 	NULL},
{"LeadAcid_q20_computed", (getter)Battery_get_LeadAcid_q20_computed,(setter)Battery_set_LeadAcid_q20_computed,
	"Capacity at 20-hour discharge rate [Ah], number.\n ",
 	NULL},
{"LeadAcid_qn_computed", (getter)Battery_get_LeadAcid_qn_computed,(setter)Battery_set_LeadAcid_qn_computed,
	"Capacity at discharge rate for n-hour rate [Ah], number.\n ",
 	NULL},
{"LeadAcid_tn", (getter)Battery_get_LeadAcid_tn,(setter)Battery_set_LeadAcid_tn,
	"Time to discharge [h], number.\n ",
 	NULL},
{"annual_energy", (getter)Battery_get_annual_energy,(setter)Battery_set_annual_energy,
	"Annual Energy [kWh], number.\n Required if: ?=0.",
 	NULL},
{"batt_C_rate", (getter)Battery_get_batt_C_rate,(setter)Battery_set_batt_C_rate,
	"Rate at which voltage vs. capacity curve input [], number.\n ",
 	NULL},
{"batt_Cp", (getter)Battery_get_batt_Cp,(setter)Battery_set_batt_Cp,
	"Battery specific heat capacity [J/KgK], number.\n ",
 	NULL},
{"batt_Qexp", (getter)Battery_get_batt_Qexp,(setter)Battery_set_batt_Qexp,
	"Cell capacity at end of exponential zone [Ah], number.\n ",
 	NULL},
{"batt_Qfull", (getter)Battery_get_batt_Qfull,(setter)Battery_set_batt_Qfull,
	"Fully charged cell capacity [Ah], number.\n ",
 	NULL},
{"batt_Qfull_flow", (getter)Battery_get_batt_Qfull_flow,(setter)Battery_set_batt_Qfull_flow,
	"Fully charged flow battery capacity [Ah], number.\n ",
 	NULL},
{"batt_Qnom", (getter)Battery_get_batt_Qnom,(setter)Battery_set_batt_Qnom,
	"Cell capacity at end of nominal zone [Ah], number.\n ",
 	NULL},
{"batt_Vexp", (getter)Battery_get_batt_Vexp,(setter)Battery_set_batt_Vexp,
	"Cell voltage at end of exponential zone [V], number.\n ",
 	NULL},
{"batt_Vfull", (getter)Battery_get_batt_Vfull,(setter)Battery_set_batt_Vfull,
	"Fully charged cell voltage [V], number.\n ",
 	NULL},
{"batt_Vnom", (getter)Battery_get_batt_Vnom,(setter)Battery_set_batt_Vnom,
	"Cell voltage at end of nominal zone [V], number.\n ",
 	NULL},
{"batt_Vnom_default", (getter)Battery_get_batt_Vnom_default,(setter)Battery_set_batt_Vnom_default,
	"Default nominal cell voltage [V], number.\n ",
 	NULL},
{"batt_ac_dc_efficiency", (getter)Battery_get_batt_ac_dc_efficiency,(setter)Battery_set_batt_ac_dc_efficiency,
	"Inverter AC to battery DC efficiency [], number.\n ",
 	NULL},
{"batt_ac_or_dc", (getter)Battery_get_batt_ac_or_dc,(setter)Battery_set_batt_ac_or_dc,
	"Battery interconnection (AC or DC) [], number.\n 0=DC_Connected,1=AC_Connected; ",
 	NULL},
{"batt_auto_gridcharge_max_daily", (getter)Battery_get_batt_auto_gridcharge_max_daily,(setter)Battery_set_batt_auto_gridcharge_max_daily,
	"Allowed grid charging percent per day for automated dispatch [kW], number.\n ",
 	NULL},
{"batt_calendar_a", (getter)Battery_get_batt_calendar_a,(setter)Battery_set_batt_calendar_a,
	"Calendar life model coefficient [1/sqrt(day)], number.\n ",
 	NULL},
{"batt_calendar_b", (getter)Battery_get_batt_calendar_b,(setter)Battery_set_batt_calendar_b,
	"Calendar life model coefficient [K], number.\n ",
 	NULL},
{"batt_calendar_c", (getter)Battery_get_batt_calendar_c,(setter)Battery_set_batt_calendar_c,
	"Calendar life model coefficient [K], number.\n ",
 	NULL},
{"batt_calendar_choice", (getter)Battery_get_batt_calendar_choice,(setter)Battery_set_batt_calendar_choice,
	"Calendar life degradation input option [0/1/2], number.\n 0=NoCalendarDegradation,1=LithiomIonModel,2=InputLossTable; ",
 	NULL},
{"batt_calendar_lifetime_matrix", (getter)Battery_get_batt_calendar_lifetime_matrix,(setter)Battery_set_batt_calendar_lifetime_matrix,
	"Days vs capacity [], matrix.\n ",
 	NULL},
{"batt_calendar_q0", (getter)Battery_get_batt_calendar_q0,(setter)Battery_set_batt_calendar_q0,
	"Calendar life model initial capacity cofficient [], number.\n ",
 	NULL},
{"batt_chem", (getter)Battery_get_batt_chem,(setter)Battery_set_batt_chem,
	"Battery chemistry [], number.\n 0=LeadAcid,1=LiIon; ",
 	NULL},
{"batt_computed_bank_capacity", (getter)Battery_get_batt_computed_bank_capacity,(setter)Battery_set_batt_computed_bank_capacity,
	"Computed bank capacity [kWh], number.\n ",
 	NULL},
{"batt_computed_series", (getter)Battery_get_batt_computed_series,(setter)Battery_set_batt_computed_series,
	"Number of cells in series [], number.\n ",
 	NULL},
{"batt_computed_strings", (getter)Battery_get_batt_computed_strings,(setter)Battery_set_batt_computed_strings,
	"Number of strings of cells [], number.\n ",
 	NULL},
{"batt_current_charge_max", (getter)Battery_get_batt_current_charge_max,(setter)Battery_set_batt_current_charge_max,
	"Maximum charge current [A], number.\n ",
 	NULL},
{"batt_current_choice", (getter)Battery_get_batt_current_choice,(setter)Battery_set_batt_current_choice,
	"Limit cells by current or power [], number.\n ",
 	NULL},
{"batt_current_discharge_max", (getter)Battery_get_batt_current_discharge_max,(setter)Battery_set_batt_current_discharge_max,
	"Maximum discharge current [A], number.\n ",
 	NULL},
{"batt_custom_dispatch", (getter)Battery_get_batt_custom_dispatch,(setter)Battery_set_batt_custom_dispatch,
	"Custom battery power for every time step [kW], array.\n Required if: en_batt=1&batt_dispatch_choice=3.",
 	NULL},
{"batt_cycle_cost", (getter)Battery_get_batt_cycle_cost,(setter)Battery_set_batt_cycle_cost,
	"Input battery cycle costs [$/cycle-kWh], number.\n ",
 	NULL},
{"batt_cycle_cost_choice", (getter)Battery_get_batt_cycle_cost_choice,(setter)Battery_set_batt_cycle_cost_choice,
	"Use SAM model for cycle costs or input custom [0/1], number.\n 0=UseCostModel,1=InputCost; ",
 	NULL},
{"batt_dc_ac_efficiency", (getter)Battery_get_batt_dc_ac_efficiency,(setter)Battery_set_batt_dc_ac_efficiency,
	"Battery DC to AC efficiency [], number.\n ",
 	NULL},
{"batt_dc_dc_efficiency", (getter)Battery_get_batt_dc_dc_efficiency,(setter)Battery_set_batt_dc_dc_efficiency,
	"PV DC to battery DC efficiency [], number.\n ",
 	NULL},
{"batt_dispatch_auto_can_charge", (getter)Battery_get_batt_dispatch_auto_can_charge,(setter)Battery_set_batt_dispatch_auto_can_charge,
	"PV charging allowed for automated dispatch? [kW], number.\n ",
 	NULL},
{"batt_dispatch_auto_can_clipcharge", (getter)Battery_get_batt_dispatch_auto_can_clipcharge,(setter)Battery_set_batt_dispatch_auto_can_clipcharge,
	"Battery can charge from clipped PV for automated dispatch? [kW], number.\n ",
 	NULL},
{"batt_dispatch_auto_can_fuelcellcharge", (getter)Battery_get_batt_dispatch_auto_can_fuelcellcharge,(setter)Battery_set_batt_dispatch_auto_can_fuelcellcharge,
	"Charging from fuel cell allowed for automated dispatch? [kW], number.\n ",
 	NULL},
{"batt_dispatch_auto_can_gridcharge", (getter)Battery_get_batt_dispatch_auto_can_gridcharge,(setter)Battery_set_batt_dispatch_auto_can_gridcharge,
	"Grid charging allowed for automated dispatch? [kW], number.\n ",
 	NULL},
{"batt_dispatch_choice", (getter)Battery_get_batt_dispatch_choice,(setter)Battery_set_batt_dispatch_choice,
	"Battery dispatch algorithm [0/1/2/3/4], number.\n If behind the meter: 0=PeakShavingLookAhead,1=PeakShavingLookBehind,2=InputGridTarget,3=InputBatteryPower,4=ManualDispatch, if front of meter: 0=AutomatedLookAhead,1=AutomatedLookBehind,2=AutomatedInputForecast,3=InputBatteryPower,4=ManualDispatch; Required if: en_batt=1.",
 	NULL},
{"batt_dispatch_update_frequency_hours", (getter)Battery_get_batt_dispatch_update_frequency_hours,(setter)Battery_set_batt_dispatch_update_frequency_hours,
	"Frequency to update the look-ahead dispatch [hours], number.\n ",
 	NULL},
{"batt_h_to_ambient", (getter)Battery_get_batt_h_to_ambient,(setter)Battery_set_batt_h_to_ambient,
	"Heat transfer between battery and environment [W/m2K], number.\n ",
 	NULL},
{"batt_height", (getter)Battery_get_batt_height,(setter)Battery_set_batt_height,
	"Battery height [m], number.\n ",
 	NULL},
{"batt_initial_SOC", (getter)Battery_get_batt_initial_SOC,(setter)Battery_set_batt_initial_SOC,
	"Initial state-of-charge [%], number.\n ",
 	NULL},
{"batt_length", (getter)Battery_get_batt_length,(setter)Battery_set_batt_length,
	"Battery length [m], number.\n ",
 	NULL},
{"batt_lifetime_matrix", (getter)Battery_get_batt_lifetime_matrix,(setter)Battery_set_batt_lifetime_matrix,
	"Cycles vs capacity at different depths-of-discharge [], matrix.\n ",
 	NULL},
{"batt_look_ahead_hours", (getter)Battery_get_batt_look_ahead_hours,(setter)Battery_set_batt_look_ahead_hours,
	"Hours to look ahead in automated dispatch [hours], number.\n ",
 	NULL},
{"batt_loss_choice", (getter)Battery_get_batt_loss_choice,(setter)Battery_set_batt_loss_choice,
	"Loss power input option [0/1], number.\n 0=Monthly,1=TimeSeries; Required if: ?=0.",
 	NULL},
{"batt_losses", (getter)Battery_get_batt_losses,(setter)Battery_set_batt_losses,
	"Battery system losses at each timestep [kW], array.\n Required if: ?=0.",
 	NULL},
{"batt_losses_charging", (getter)Battery_get_batt_losses_charging,(setter)Battery_set_batt_losses_charging,
	"Battery system losses when charging [kW], array.\n Required if: ?=0.",
 	NULL},
{"batt_losses_discharging", (getter)Battery_get_batt_losses_discharging,(setter)Battery_set_batt_losses_discharging,
	"Battery system losses when discharging [kW], array.\n Required if: ?=0.",
 	NULL},
{"batt_losses_idle", (getter)Battery_get_batt_losses_idle,(setter)Battery_set_batt_losses_idle,
	"Battery system losses when idle [kW], array.\n Required if: ?=0.",
 	NULL},
{"batt_mass", (getter)Battery_get_batt_mass,(setter)Battery_set_batt_mass,
	"Battery mass [kg], number.\n ",
 	NULL},
{"batt_maximum_SOC", (getter)Battery_get_batt_maximum_SOC,(setter)Battery_set_batt_maximum_SOC,
	"Maximum allowed state-of-charge [%], number.\n ",
 	NULL},
{"batt_meter_position", (getter)Battery_get_batt_meter_position,(setter)Battery_set_batt_meter_position,
	"Position of battery relative to electric meter [], number.\n 0=BehindTheMeter,1=FrontOfMeter; ",
 	NULL},
{"batt_minimum_SOC", (getter)Battery_get_batt_minimum_SOC,(setter)Battery_set_batt_minimum_SOC,
	"Minimum allowed state-of-charge [%], number.\n ",
 	NULL},
{"batt_minimum_modetime", (getter)Battery_get_batt_minimum_modetime,(setter)Battery_set_batt_minimum_modetime,
	"Minimum time at charge state [min], number.\n ",
 	NULL},
{"batt_power_charge_max", (getter)Battery_get_batt_power_charge_max,(setter)Battery_set_batt_power_charge_max,
	"Maximum charge power [kW], number.\n ",
 	NULL},
{"batt_power_discharge_max", (getter)Battery_get_batt_power_discharge_max,(setter)Battery_set_batt_power_discharge_max,
	"Maximum discharge power [kW], number.\n ",
 	NULL},
{"batt_pv_clipping_forecast", (getter)Battery_get_batt_pv_clipping_forecast,(setter)Battery_set_batt_pv_clipping_forecast,
	"PV clipping forecast [kW], array.\n Required if: en_batt=1&batt_meter_position=1&batt_dispatch_choice=2.",
 	NULL},
{"batt_pv_dc_forecast", (getter)Battery_get_batt_pv_dc_forecast,(setter)Battery_set_batt_pv_dc_forecast,
	"PV dc power forecast [kW], array.\n Required if: en_batt=1&batt_meter_position=1&batt_dispatch_choice=2.",
 	NULL},
{"batt_replacement_capacity", (getter)Battery_get_batt_replacement_capacity,(setter)Battery_set_batt_replacement_capacity,
	"Capacity degradation at which to replace battery [%], number.\n ",
 	NULL},
{"batt_replacement_option", (getter)Battery_get_batt_replacement_option,(setter)Battery_set_batt_replacement_option,
	"Enable battery replacement? [0=none,1=capacity based,2=user schedule], number.\n Constraints: INTEGER,MIN=0,MAX=2; Required if: ?=0.",
 	NULL},
{"batt_replacement_schedule", (getter)Battery_get_batt_replacement_schedule,(setter)Battery_set_batt_replacement_schedule,
	"Battery bank replacements per year (user specified) [number/year], array.\n Required if: batt_replacement_option=2.",
 	NULL},
{"batt_resistance", (getter)Battery_get_batt_resistance,(setter)Battery_set_batt_resistance,
	"Internal resistance [Ohm], number.\n ",
 	NULL},
{"batt_room_temperature_celsius", (getter)Battery_get_batt_room_temperature_celsius,(setter)Battery_set_batt_room_temperature_celsius,
	"Temperature of storage room [C], array.\n ",
 	NULL},
{"batt_target_choice", (getter)Battery_get_batt_target_choice,(setter)Battery_set_batt_target_choice,
	"Target power input option [0/1], number.\n 0=InputMonthlyTarget,1=InputFullTimeSeries; Required if: en_batt=1&batt_meter_position=0&batt_dispatch_choice=2.",
 	NULL},
{"batt_target_power", (getter)Battery_get_batt_target_power,(setter)Battery_set_batt_target_power,
	"Grid target power for every time step [kW], array.\n Required if: en_batt=1&batt_meter_position=0&batt_dispatch_choice=2.",
 	NULL},
{"batt_target_power_monthly", (getter)Battery_get_batt_target_power_monthly,(setter)Battery_set_batt_target_power_monthly,
	"Grid target power on monthly basis [kW], array.\n Required if: en_batt=1&batt_meter_position=0&batt_dispatch_choice=2.",
 	NULL},
{"batt_voltage_choice", (getter)Battery_get_batt_voltage_choice,(setter)Battery_set_batt_voltage_choice,
	"Battery voltage input option [0/1], number.\n 0=UseVoltageModel,1=InputVoltageTable; Required if: ?=0.",
 	NULL},
{"batt_voltage_matrix", (getter)Battery_get_batt_voltage_matrix,(setter)Battery_set_batt_voltage_matrix,
	"Battery voltage vs. depth-of-discharge [], matrix.\n ",
 	NULL},
{"batt_width", (getter)Battery_get_batt_width,(setter)Battery_set_batt_width,
	"Battery width [m], number.\n ",
 	NULL},
{"cap_vs_temp", (getter)Battery_get_cap_vs_temp,(setter)Battery_set_cap_vs_temp,
	"Effective capacity as function of temperature [C,%], matrix.\n ",
 	NULL},
{"dispatch_manual_charge", (getter)Battery_get_dispatch_manual_charge,(setter)Battery_set_dispatch_manual_charge,
	"Periods 1-6 charging from system allowed? [], array.\n Required if: en_batt=1&batt_dispatch_choice=4.",
 	NULL},
{"dispatch_manual_discharge", (getter)Battery_get_dispatch_manual_discharge,(setter)Battery_set_dispatch_manual_discharge,
	"Periods 1-6 discharging allowed? [], array.\n Required if: en_batt=1&batt_dispatch_choice=4.",
 	NULL},
{"dispatch_manual_gridcharge", (getter)Battery_get_dispatch_manual_gridcharge,(setter)Battery_set_dispatch_manual_gridcharge,
	"Periods 1-6 grid charging allowed? [], array.\n Required if: en_batt=1&batt_dispatch_choice=4.",
 	NULL},
{"dispatch_manual_percent_discharge", (getter)Battery_get_dispatch_manual_percent_discharge,(setter)Battery_set_dispatch_manual_percent_discharge,
	"Periods 1-6 discharge percent [%], array.\n Required if: en_batt=1&batt_dispatch_choice=4.",
 	NULL},
{"dispatch_manual_percent_gridcharge", (getter)Battery_get_dispatch_manual_percent_gridcharge,(setter)Battery_set_dispatch_manual_percent_gridcharge,
	"Periods 1-6 gridcharge percent [%], array.\n Required if: en_batt=1&batt_dispatch_choice=4.",
 	NULL},
{"dispatch_manual_sched", (getter)Battery_get_dispatch_manual_sched,(setter)Battery_set_dispatch_manual_sched,
	"Battery dispatch schedule for weekday [], matrix.\n Required if: en_batt=1&batt_dispatch_choice=4.",
 	NULL},
{"dispatch_manual_sched_weekend", (getter)Battery_get_dispatch_manual_sched_weekend,(setter)Battery_set_dispatch_manual_sched_weekend,
	"Battery dispatch schedule for weekend [], matrix.\n Required if: en_batt=1&batt_dispatch_choice=4.",
 	NULL},
{"en_batt", (getter)Battery_get_en_batt,(setter)Battery_set_en_batt,
	"Enable battery storage model [0/1], number.\n Required if: ?=0.",
 	NULL},
{"om_replacement_cost1", (getter)Battery_get_om_replacement_cost1,(setter)Battery_set_om_replacement_cost1,
	"Cost to replace battery per kWh [$/kWh], array.\n ",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Battery_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.Battery",             /*tp_name*/
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
	 * System Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Battery   data_ptr;
} SystemObject;

static PyTypeObject System_Type;

static PyObject *
System_new(SAM_Battery data_ptr)
{
	PyObject* new_obj = System_Type.tp_alloc(&System_Type,0);

	SystemObject* System_obj = (SystemObject*)new_obj;

	System_obj->data_ptr = data_ptr;

	return new_obj;
}

/* System methods */

static PyObject *
System_assign(SystemObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "System")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
System_export(SystemObject *self, PyObject *args)
{
	PyTypeObject* tp = &System_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef System_methods[] = {
		{"assign",            (PyCFunction)System_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)System_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
System_get_capacity_factor(SystemObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_System_capacity_factor_fget, self->data_ptr);
}

static int
System_set_capacity_factor(SystemObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_System_capacity_factor_fset, self->data_ptr);
}

static PyObject *
System_get_gen(SystemObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_System_gen_aget, self->data_ptr);
}

static int
System_set_gen(SystemObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_System_gen_aset, self->data_ptr);
}

static PyGetSetDef System_getset[] = {
{"capacity_factor", (getter)System_get_capacity_factor,(setter)System_set_capacity_factor,
	"Capacity factor [%], number.\n Required if: ?=0.",
 	NULL},
{"gen", (getter)System_get_gen,(setter)System_set_gen,
	"System power generated [kW], array.\n ",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject System_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.System",             /*tp_name*/
		sizeof(SystemObject),          /*tp_basicsize*/
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
		System_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		System_getset,          /*tp_getset*/
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
	 * ElectricLoad Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Battery   data_ptr;
} ElectricLoadObject;

static PyTypeObject ElectricLoad_Type;

static PyObject *
ElectricLoad_new(SAM_Battery data_ptr)
{
	PyObject* new_obj = ElectricLoad_Type.tp_alloc(&ElectricLoad_Type,0);

	ElectricLoadObject* ElectricLoad_obj = (ElectricLoadObject*)new_obj;

	ElectricLoad_obj->data_ptr = data_ptr;

	return new_obj;
}

/* ElectricLoad methods */

static PyObject *
ElectricLoad_assign(ElectricLoadObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "ElectricLoad")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ElectricLoad_export(ElectricLoadObject *self, PyObject *args)
{
	PyTypeObject* tp = &ElectricLoad_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ElectricLoad_methods[] = {
		{"assign",            (PyCFunction)ElectricLoad_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)ElectricLoad_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ElectricLoad_get_load(ElectricLoadObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_ElectricLoad_load_aget, self->data_ptr);
}

static int
ElectricLoad_set_load(ElectricLoadObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_ElectricLoad_load_aset, self->data_ptr);
}

static PyGetSetDef ElectricLoad_getset[] = {
{"load", (getter)ElectricLoad_get_load,(setter)ElectricLoad_set_load,
	"Electricity load (year 1) [kW], array.\n ",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ElectricLoad_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.ElectricLoad",             /*tp_name*/
		sizeof(ElectricLoadObject),          /*tp_basicsize*/
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
		ElectricLoad_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ElectricLoad_getset,          /*tp_getset*/
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
	SAM_Battery   data_ptr;
} CommonObject;

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_Battery data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "Common")){
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
Common_get_inverter_model(CommonObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Common_inverter_model_fget, self->data_ptr);
}

static int
Common_set_inverter_model(CommonObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Common_inverter_model_fset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"inverter_model", (getter)Common_get_inverter_model,(setter)Common_set_inverter_model,
	"Inverter model specifier [], number.\n 0=cec,1=datasheet,2=partload,3=coefficientgenerator,4=generic; Constraints: INTEGER,MIN=0,MAX=4; ",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.Common",             /*tp_name*/
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
	 * Inverter Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Battery   data_ptr;
} InverterObject;

static PyTypeObject Inverter_Type;

static PyObject *
Inverter_new(SAM_Battery data_ptr)
{
	PyObject* new_obj = Inverter_Type.tp_alloc(&Inverter_Type,0);

	InverterObject* Inverter_obj = (InverterObject*)new_obj;

	Inverter_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Inverter methods */

static PyObject *
Inverter_assign(InverterObject *self, PyObject *args)
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
Inverter_export(InverterObject *self, PyObject *args)
{
	PyTypeObject* tp = &Inverter_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Inverter_methods[] = {
		{"assign",            (PyCFunction)Inverter_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Inverter_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Inverter_get_inv_cec_cg_eff_cec(InverterObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Inverter_inv_cec_cg_eff_cec_fget, self->data_ptr);
}

static int
Inverter_set_inv_cec_cg_eff_cec(InverterObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Inverter_inv_cec_cg_eff_cec_fset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_cec_cg_paco(InverterObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Inverter_inv_cec_cg_paco_fget, self->data_ptr);
}

static int
Inverter_set_inv_cec_cg_paco(InverterObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Inverter_inv_cec_cg_paco_fset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_ds_eff(InverterObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Inverter_inv_ds_eff_fget, self->data_ptr);
}

static int
Inverter_set_inv_ds_eff(InverterObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Inverter_inv_ds_eff_fset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_ds_paco(InverterObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Inverter_inv_ds_paco_fget, self->data_ptr);
}

static int
Inverter_set_inv_ds_paco(InverterObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Inverter_inv_ds_paco_fset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_pd_eff(InverterObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Inverter_inv_pd_eff_fget, self->data_ptr);
}

static int
Inverter_set_inv_pd_eff(InverterObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Inverter_inv_pd_eff_fset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_pd_paco(InverterObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Inverter_inv_pd_paco_fget, self->data_ptr);
}

static int
Inverter_set_inv_pd_paco(InverterObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Inverter_inv_pd_paco_fset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_snl_eff_cec(InverterObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Inverter_inv_snl_eff_cec_fget, self->data_ptr);
}

static int
Inverter_set_inv_snl_eff_cec(InverterObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Inverter_inv_snl_eff_cec_fset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_snl_paco(InverterObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Inverter_inv_snl_paco_fget, self->data_ptr);
}

static int
Inverter_set_inv_snl_paco(InverterObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Inverter_inv_snl_paco_fset, self->data_ptr);
}

static PyObject *
Inverter_get_inverter_count(InverterObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Inverter_inverter_count_fget, self->data_ptr);
}

static int
Inverter_set_inverter_count(InverterObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_Inverter_inverter_count_fset, self->data_ptr);
}

static PyGetSetDef Inverter_getset[] = {
{"inv_cec_cg_eff_cec", (getter)Inverter_get_inv_cec_cg_eff_cec,(setter)Inverter_set_inv_cec_cg_eff_cec,
	"Inverter Coefficient Generator CEC Efficiency [%], number.\n ",
 	NULL},
{"inv_cec_cg_paco", (getter)Inverter_get_inv_cec_cg_paco,(setter)Inverter_set_inv_cec_cg_paco,
	"Inverter Coefficient Generator Max AC Power [Wac], number.\n ",
 	NULL},
{"inv_ds_eff", (getter)Inverter_get_inv_ds_eff,(setter)Inverter_set_inv_ds_eff,
	"Inverter Datasheet Efficiency [%], number.\n ",
 	NULL},
{"inv_ds_paco", (getter)Inverter_get_inv_ds_paco,(setter)Inverter_set_inv_ds_paco,
	"Inverter Datasheet Maximum AC Power [Wac], number.\n ",
 	NULL},
{"inv_pd_eff", (getter)Inverter_get_inv_pd_eff,(setter)Inverter_set_inv_pd_eff,
	"Inverter Partload Efficiency [%], number.\n ",
 	NULL},
{"inv_pd_paco", (getter)Inverter_get_inv_pd_paco,(setter)Inverter_set_inv_pd_paco,
	"Inverter Partload Maximum AC Power [Wac], number.\n ",
 	NULL},
{"inv_snl_eff_cec", (getter)Inverter_get_inv_snl_eff_cec,(setter)Inverter_set_inv_snl_eff_cec,
	"Inverter Sandia CEC Efficiency [%], number.\n ",
 	NULL},
{"inv_snl_paco", (getter)Inverter_get_inv_snl_paco,(setter)Inverter_set_inv_snl_paco,
	"Inverter Sandia Maximum AC Power [Wac], number.\n ",
 	NULL},
{"inverter_count", (getter)Inverter_get_inverter_count,(setter)Inverter_set_inverter_count,
	"Number of inverters [], number.\n ",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Inverter_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.Inverter",             /*tp_name*/
		sizeof(InverterObject),          /*tp_basicsize*/
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
		Inverter_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Inverter_getset,          /*tp_getset*/
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
	 * PV Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Battery   data_ptr;
} PVObject;

static PyTypeObject PV_Type;

static PyObject *
PV_new(SAM_Battery data_ptr)
{
	PyObject* new_obj = PV_Type.tp_alloc(&PV_Type,0);

	PVObject* PV_obj = (PVObject*)new_obj;

	PV_obj->data_ptr = data_ptr;

	return new_obj;
}

/* PV methods */

static PyObject *
PV_assign(PVObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "PV")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PV_export(PVObject *self, PyObject *args)
{
	PyTypeObject* tp = &PV_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef PV_methods[] = {
		{"assign",            (PyCFunction)PV_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)PV_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
PV_get_dcoptimizer_loss(PVObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_PV_dcoptimizer_loss_fget, self->data_ptr);
}

static int
PV_set_dcoptimizer_loss(PVObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_PV_dcoptimizer_loss_fset, self->data_ptr);
}

static PyGetSetDef PV_getset[] = {
{"dcoptimizer_loss", (getter)PV_get_dcoptimizer_loss,(setter)PV_set_dcoptimizer_loss,
	"PV loss in DC/DC w/MPPT conversion [], number.\n ",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject PV_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.PV",             /*tp_name*/
		sizeof(PVObject),          /*tp_basicsize*/
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
		PV_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		PV_getset,          /*tp_getset*/
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
	SAM_Battery   data_ptr;
} FuelCellObject;

static PyTypeObject FuelCell_Type;

static PyObject *
FuelCell_new(SAM_Battery data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "FuelCell")){
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
FuelCell_get_dispatch_manual_fuelcellcharge(FuelCellObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_FuelCell_dispatch_manual_fuelcellcharge_aget, self->data_ptr);
}

static int
FuelCell_set_dispatch_manual_fuelcellcharge(FuelCellObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_FuelCell_dispatch_manual_fuelcellcharge_aset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_power(FuelCellObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_FuelCell_fuelcell_power_aget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_power(FuelCellObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_FuelCell_fuelcell_power_aset, self->data_ptr);
}

static PyGetSetDef FuelCell_getset[] = {
{"dispatch_manual_fuelcellcharge", (getter)FuelCell_get_dispatch_manual_fuelcellcharge,(setter)FuelCell_set_dispatch_manual_fuelcellcharge,
	"Periods 1-6 charging from fuel cell allowed? [], array.\n ",
 	NULL},
{"fuelcell_power", (getter)FuelCell_get_fuelcell_power,(setter)FuelCell_set_fuelcell_power,
	"Electricity from fuel cell [kW], array.\n ",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FuelCell_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.FuelCell",             /*tp_name*/
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
	 * ElectricityRate Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Battery   data_ptr;
} ElectricityRateObject;

static PyTypeObject ElectricityRate_Type;

static PyObject *
ElectricityRate_new(SAM_Battery data_ptr)
{
	PyObject* new_obj = ElectricityRate_Type.tp_alloc(&ElectricityRate_Type,0);

	ElectricityRateObject* ElectricityRate_obj = (ElectricityRateObject*)new_obj;

	ElectricityRate_obj->data_ptr = data_ptr;

	return new_obj;
}

/* ElectricityRate methods */

static PyObject *
ElectricityRate_assign(ElectricityRateObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "ElectricityRate")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ElectricityRate_export(ElectricityRateObject *self, PyObject *args)
{
	PyTypeObject* tp = &ElectricityRate_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ElectricityRate_methods[] = {
		{"assign",            (PyCFunction)ElectricityRate_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)ElectricityRate_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ElectricityRate_get_en_electricity_rates(ElectricityRateObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_ElectricityRate_en_electricity_rates_fget, self->data_ptr);
}

static int
ElectricityRate_set_en_electricity_rates(ElectricityRateObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_ElectricityRate_en_electricity_rates_fset, self->data_ptr);
}

static PyObject *
ElectricityRate_get_ur_ec_sched_weekday(ElectricityRateObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_ElectricityRate_ur_ec_sched_weekday_mget, self->data_ptr);
}

static int
ElectricityRate_set_ur_ec_sched_weekday(ElectricityRateObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_ElectricityRate_ur_ec_sched_weekday_mset, self->data_ptr);
}

static PyObject *
ElectricityRate_get_ur_ec_sched_weekend(ElectricityRateObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_ElectricityRate_ur_ec_sched_weekend_mget, self->data_ptr);
}

static int
ElectricityRate_set_ur_ec_sched_weekend(ElectricityRateObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_ElectricityRate_ur_ec_sched_weekend_mset, self->data_ptr);
}

static PyObject *
ElectricityRate_get_ur_ec_tou_mat(ElectricityRateObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_ElectricityRate_ur_ec_tou_mat_mget, self->data_ptr);
}

static int
ElectricityRate_set_ur_ec_tou_mat(ElectricityRateObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_ElectricityRate_ur_ec_tou_mat_mset, self->data_ptr);
}

static PyGetSetDef ElectricityRate_getset[] = {
{"en_electricity_rates", (getter)ElectricityRate_get_en_electricity_rates,(setter)ElectricityRate_set_en_electricity_rates,
	"Enable Electricity Rates [0/1], number.\n 0=EnableElectricityRates,1=NoRates; ",
 	NULL},
{"ur_ec_sched_weekday", (getter)ElectricityRate_get_ur_ec_sched_weekday,(setter)ElectricityRate_set_ur_ec_sched_weekday,
	"Energy charge weekday schedule [], matrix.\n 12 x 24 matrix; Required if: en_batt=1&batt_meter_position=1&batt_dispatch_choice=2.",
 	NULL},
{"ur_ec_sched_weekend", (getter)ElectricityRate_get_ur_ec_sched_weekend,(setter)ElectricityRate_set_ur_ec_sched_weekend,
	"Energy charge weekend schedule [], matrix.\n 12 x 24 matrix; Required if: en_batt=1&batt_meter_position=1&batt_dispatch_choice=2.",
 	NULL},
{"ur_ec_tou_mat", (getter)ElectricityRate_get_ur_ec_tou_mat,(setter)ElectricityRate_set_ur_ec_tou_mat,
	"Energy rates table [], matrix.\n Required if: en_batt=1&batt_meter_position=1&batt_dispatch_choice=2.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ElectricityRate_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.ElectricityRate",             /*tp_name*/
		sizeof(ElectricityRateObject),          /*tp_basicsize*/
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
		ElectricityRate_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ElectricityRate_getset,          /*tp_getset*/
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
	 * EnergyMarket Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Battery   data_ptr;
} EnergyMarketObject;

static PyTypeObject EnergyMarket_Type;

static PyObject *
EnergyMarket_new(SAM_Battery data_ptr)
{
	PyObject* new_obj = EnergyMarket_Type.tp_alloc(&EnergyMarket_Type,0);

	EnergyMarketObject* EnergyMarket_obj = (EnergyMarketObject*)new_obj;

	EnergyMarket_obj->data_ptr = data_ptr;

	return new_obj;
}

/* EnergyMarket methods */

static PyObject *
EnergyMarket_assign(EnergyMarketObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "EnergyMarket")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
EnergyMarket_export(EnergyMarketObject *self, PyObject *args)
{
	PyTypeObject* tp = &EnergyMarket_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef EnergyMarket_methods[] = {
		{"assign",            (PyCFunction)EnergyMarket_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)EnergyMarket_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
EnergyMarket_get_dispatch_sched_weekday(EnergyMarketObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_EnergyMarket_dispatch_sched_weekday_mget, self->data_ptr);
}

static int
EnergyMarket_set_dispatch_sched_weekday(EnergyMarketObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_EnergyMarket_dispatch_sched_weekday_mset, self->data_ptr);
}

static PyObject *
EnergyMarket_get_dispatch_sched_weekend(EnergyMarketObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_EnergyMarket_dispatch_sched_weekend_mget, self->data_ptr);
}

static int
EnergyMarket_set_dispatch_sched_weekend(EnergyMarketObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Battery_EnergyMarket_dispatch_sched_weekend_mset, self->data_ptr);
}

static PyObject *
EnergyMarket_get_dispatch_tod_factors(EnergyMarketObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_EnergyMarket_dispatch_tod_factors_aget, self->data_ptr);
}

static int
EnergyMarket_set_dispatch_tod_factors(EnergyMarketObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battery_EnergyMarket_dispatch_tod_factors_aset, self->data_ptr);
}

static PyObject *
EnergyMarket_get_ppa_price_input(EnergyMarketObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_EnergyMarket_ppa_price_input_fget, self->data_ptr);
}

static int
EnergyMarket_set_ppa_price_input(EnergyMarketObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battery_EnergyMarket_ppa_price_input_fset, self->data_ptr);
}

static PyGetSetDef EnergyMarket_getset[] = {
{"dispatch_sched_weekday", (getter)EnergyMarket_get_dispatch_sched_weekday,(setter)EnergyMarket_set_dispatch_sched_weekday,
	"Diurnal weekday TOD periods [1..9], matrix.\n 12 x 24 matrix; Required if: en_batt=1&batt_meter_position=1&batt_dispatch_choice=2.",
 	NULL},
{"dispatch_sched_weekend", (getter)EnergyMarket_get_dispatch_sched_weekend,(setter)EnergyMarket_set_dispatch_sched_weekend,
	"Diurnal weekend TOD periods [1..9], matrix.\n 12 x 24 matrix; Required if: en_batt=1&batt_meter_position=1&batt_dispatch_choice=2.",
 	NULL},
{"dispatch_tod_factors", (getter)EnergyMarket_get_dispatch_tod_factors,(setter)EnergyMarket_set_dispatch_tod_factors,
	"TOD factors for periods 1-9 [], array.\n Required if: en_batt=1&batt_meter_position=1&batt_dispatch_choice=2.",
 	NULL},
{"ppa_price_input", (getter)EnergyMarket_get_ppa_price_input,(setter)EnergyMarket_set_ppa_price_input,
	"PPA Price Input [], number.\n Required if: en_batt=1&batt_meter_position=1&batt_dispatch_choice=2.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject EnergyMarket_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.EnergyMarket",             /*tp_name*/
		sizeof(EnergyMarketObject),          /*tp_basicsize*/
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
		EnergyMarket_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		EnergyMarket_getset,          /*tp_getset*/
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
	SAM_Battery   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Battery data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battery", "Outputs")){
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
Outputs_get_annual_export_to_grid_energy(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_annual_export_to_grid_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_import_to_grid_energy(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_annual_import_to_grid_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_average_battery_conversion_efficiency(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Outputs_average_battery_conversion_efficiency_fget, self->data_ptr);
}

static PyObject *
Outputs_get_average_battery_roundtrip_efficiency(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Outputs_average_battery_roundtrip_efficiency_fget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_DOD(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_DOD_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_I(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_I_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_SOC(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_SOC_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_charge_energy(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_annual_charge_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_charge_from_grid(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_annual_charge_from_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_charge_from_pv(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_annual_charge_from_pv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_discharge_energy(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_annual_discharge_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_energy_loss(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_annual_energy_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_energy_system_loss(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_annual_energy_system_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_bank_installed_capacity(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Outputs_batt_bank_installed_capacity_fget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_bank_replacement(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_bank_replacement_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_capacity_percent(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_capacity_percent_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_capacity_thermal_percent(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_capacity_thermal_percent_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_conversion_loss(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_conversion_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_cost_to_cycle(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_cost_to_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_cycles(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_cycles_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_dispatch_sched(OutputsObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battery_Outputs_batt_dispatch_sched_mget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_power(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_power_target(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_power_target_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pv_charge_percent(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battery_Outputs_batt_pv_charge_percent_fget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_q0(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_q0_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_q1(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_q1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_q2(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_q2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_qmax(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_qmax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_qmaxI(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_qmaxI_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_qmax_thermal(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_qmax_thermal_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_system_loss(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_system_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_temperature(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_temperature_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_to_grid(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_to_load(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_voltage(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_voltage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_voltage_cell(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_batt_voltage_cell_aget, self->data_ptr);
}

static PyObject *
Outputs_get_fuelcell_to_batt(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_fuelcell_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_power(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_grid_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_power_target(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_grid_power_target_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_to_batt(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_grid_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_to_load(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_grid_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_batt_to_grid(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_batt_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_batt_to_load(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_batt_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_grid_to_batt(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_grid_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_grid_to_load(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_grid_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_pv_to_batt(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_pv_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_pv_to_grid(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_pv_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_pv_to_load(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_monthly_pv_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pv_to_batt(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_pv_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pv_to_grid(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_pv_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pv_to_load(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battery_Outputs_pv_to_load_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_export_to_grid_energy", (getter)Outputs_get_annual_export_to_grid_energy,(setter)0,
	"Annual energy exported to grid [kWh], array.",
 	NULL},
{"annual_import_to_grid_energy", (getter)Outputs_get_annual_import_to_grid_energy,(setter)0,
	"Annual energy imported from grid [kWh], array.",
 	NULL},
{"average_battery_conversion_efficiency", (getter)Outputs_get_average_battery_conversion_efficiency,(setter)0,
	"Battery average cycle conversion efficiency [%], number.",
 	NULL},
{"average_battery_roundtrip_efficiency", (getter)Outputs_get_average_battery_roundtrip_efficiency,(setter)0,
	"Battery average roundtrip efficiency [%], number.",
 	NULL},
{"batt_DOD", (getter)Outputs_get_batt_DOD,(setter)0,
	"Battery cycle depth of discharge [%], array.",
 	NULL},
{"batt_I", (getter)Outputs_get_batt_I,(setter)0,
	"Battery current [A], array.",
 	NULL},
{"batt_SOC", (getter)Outputs_get_batt_SOC,(setter)0,
	"Battery state of charge [%], array.",
 	NULL},
{"batt_annual_charge_energy", (getter)Outputs_get_batt_annual_charge_energy,(setter)0,
	"Battery annual energy charged [kWh], array.",
 	NULL},
{"batt_annual_charge_from_grid", (getter)Outputs_get_batt_annual_charge_from_grid,(setter)0,
	"Battery annual energy charged from grid [kWh], array.",
 	NULL},
{"batt_annual_charge_from_pv", (getter)Outputs_get_batt_annual_charge_from_pv,(setter)0,
	"Battery annual energy charged from PV [kWh], array.",
 	NULL},
{"batt_annual_discharge_energy", (getter)Outputs_get_batt_annual_discharge_energy,(setter)0,
	"Battery annual energy discharged [kWh], array.",
 	NULL},
{"batt_annual_energy_loss", (getter)Outputs_get_batt_annual_energy_loss,(setter)0,
	"Battery annual energy loss [kWh], array.",
 	NULL},
{"batt_annual_energy_system_loss", (getter)Outputs_get_batt_annual_energy_system_loss,(setter)0,
	"Battery annual system energy loss [kWh], array.",
 	NULL},
{"batt_bank_installed_capacity", (getter)Outputs_get_batt_bank_installed_capacity,(setter)0,
	"Battery bank installed capacity [kWh], number.",
 	NULL},
{"batt_bank_replacement", (getter)Outputs_get_batt_bank_replacement,(setter)0,
	"Battery bank replacements per year [number/year], array.",
 	NULL},
{"batt_capacity_percent", (getter)Outputs_get_batt_capacity_percent,(setter)0,
	"Battery capacity percent for lifetime [%], array.",
 	NULL},
{"batt_capacity_thermal_percent", (getter)Outputs_get_batt_capacity_thermal_percent,(setter)0,
	"Battery capacity percent for temperature [%], array.",
 	NULL},
{"batt_conversion_loss", (getter)Outputs_get_batt_conversion_loss,(setter)0,
	"Electricity loss in battery power electronics [kW], array.",
 	NULL},
{"batt_cost_to_cycle", (getter)Outputs_get_batt_cost_to_cycle,(setter)0,
	"Computed cost to cycle [$/cycle], array.",
 	NULL},
{"batt_cycles", (getter)Outputs_get_batt_cycles,(setter)0,
	"Battery number of cycles [], array.",
 	NULL},
{"batt_dispatch_sched", (getter)Outputs_get_batt_dispatch_sched,(setter)0,
	"Battery dispatch schedule [], matrix.",
 	NULL},
{"batt_power", (getter)Outputs_get_batt_power,(setter)0,
	"Electricity to/from battery [kW], array.",
 	NULL},
{"batt_power_target", (getter)Outputs_get_batt_power_target,(setter)0,
	"Electricity battery power target for automated dispatch [kW], array.",
 	NULL},
{"batt_pv_charge_percent", (getter)Outputs_get_batt_pv_charge_percent,(setter)0,
	"Battery percent energy charged from PV [%], number.",
 	NULL},
{"batt_q0", (getter)Outputs_get_batt_q0,(setter)0,
	"Battery total charge [Ah], array.",
 	NULL},
{"batt_q1", (getter)Outputs_get_batt_q1,(setter)0,
	"Battery available charge [Ah], array.",
 	NULL},
{"batt_q2", (getter)Outputs_get_batt_q2,(setter)0,
	"Battery bound charge [Ah], array.",
 	NULL},
{"batt_qmax", (getter)Outputs_get_batt_qmax,(setter)0,
	"Battery maximum charge with degradation [Ah], array.",
 	NULL},
{"batt_qmaxI", (getter)Outputs_get_batt_qmaxI,(setter)0,
	"Battery maximum capacity at current [Ah], array.",
 	NULL},
{"batt_qmax_thermal", (getter)Outputs_get_batt_qmax_thermal,(setter)0,
	"Battery maximum charge at temperature [Ah], array.",
 	NULL},
{"batt_system_loss", (getter)Outputs_get_batt_system_loss,(setter)0,
	"Electricity loss from battery ancillary equipment [kW], array.",
 	NULL},
{"batt_temperature", (getter)Outputs_get_batt_temperature,(setter)0,
	"Battery temperature [C], array.",
 	NULL},
{"batt_to_grid", (getter)Outputs_get_batt_to_grid,(setter)0,
	"Electricity to grid from battery [kW], array.",
 	NULL},
{"batt_to_load", (getter)Outputs_get_batt_to_load,(setter)0,
	"Electricity to load from battery [kW], array.",
 	NULL},
{"batt_voltage", (getter)Outputs_get_batt_voltage,(setter)0,
	"Battery voltage [V], array.",
 	NULL},
{"batt_voltage_cell", (getter)Outputs_get_batt_voltage_cell,(setter)0,
	"Battery cell voltage [V], array.",
 	NULL},
{"fuelcell_to_batt", (getter)Outputs_get_fuelcell_to_batt,(setter)0,
	"Electricity to battery from fuel cell [kW], array.",
 	NULL},
{"grid_power", (getter)Outputs_get_grid_power,(setter)0,
	"Electricity to/from grid [kW], array.",
 	NULL},
{"grid_power_target", (getter)Outputs_get_grid_power_target,(setter)0,
	"Electricity grid power target for automated dispatch [kW], array.",
 	NULL},
{"grid_to_batt", (getter)Outputs_get_grid_to_batt,(setter)0,
	"Electricity to battery from grid [kW], array.",
 	NULL},
{"grid_to_load", (getter)Outputs_get_grid_to_load,(setter)0,
	"Electricity to load from grid [kW], array.",
 	NULL},
{"monthly_batt_to_grid", (getter)Outputs_get_monthly_batt_to_grid,(setter)0,
	"Energy to grid from battery [kWh], array.",
 	NULL},
{"monthly_batt_to_load", (getter)Outputs_get_monthly_batt_to_load,(setter)0,
	"Energy to load from battery [kWh], array.",
 	NULL},
{"monthly_grid_to_batt", (getter)Outputs_get_monthly_grid_to_batt,(setter)0,
	"Energy to battery from grid [kWh], array.",
 	NULL},
{"monthly_grid_to_load", (getter)Outputs_get_monthly_grid_to_load,(setter)0,
	"Energy to load from grid [kWh], array.",
 	NULL},
{"monthly_pv_to_batt", (getter)Outputs_get_monthly_pv_to_batt,(setter)0,
	"Energy to battery from PV [kWh], array.",
 	NULL},
{"monthly_pv_to_grid", (getter)Outputs_get_monthly_pv_to_grid,(setter)0,
	"Energy to grid from PV [kWh], array.",
 	NULL},
{"monthly_pv_to_load", (getter)Outputs_get_monthly_pv_to_load,(setter)0,
	"Energy to load from PV [kWh], array.",
 	NULL},
{"pv_to_batt", (getter)Outputs_get_pv_to_batt,(setter)0,
	"Electricity to battery from PV [kW], array.",
 	NULL},
{"pv_to_grid", (getter)Outputs_get_pv_to_grid,(setter)0,
	"Electricity to grid from PV [kW], array.",
 	NULL},
{"pv_to_load", (getter)Outputs_get_pv_to_load,(setter)0,
	"Electricity to load from PV [kW], array.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery.Outputs",             /*tp_name*/
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
 * Battery
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_Battery   data_ptr;
} BatteryObject;

static PyTypeObject Battery_Type;

#define BatteryObject_Check(v)      (Py_TYPE(v) == &Battery_Type)

static BatteryObject *
newBatteryObject(void* data_ptr)
{
	BatteryObject *self;
	self = PyObject_New(BatteryObject, &Battery_Type);

	PySAM_TECH_ATTR("Battery", SAM_Battery_construct)

PyObject* Simulation_obj = Simulation_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Simulation", Simulation_obj);
	Py_DECREF(Simulation_obj);

PyObject* Battery_obj = Battery_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Battery", Battery_obj);
	Py_DECREF(Battery_obj);

PyObject* System_obj = System_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "System", System_obj);
	Py_DECREF(System_obj);

PyObject* ElectricLoad_obj = ElectricLoad_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ElectricLoad", ElectricLoad_obj);
	Py_DECREF(ElectricLoad_obj);

PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

PyObject* Inverter_obj = Inverter_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Inverter", Inverter_obj);
	Py_DECREF(Inverter_obj);

PyObject* PV_obj = PV_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "PV", PV_obj);
	Py_DECREF(PV_obj);

PyObject* FuelCell_obj = FuelCell_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FuelCell", FuelCell_obj);
	Py_DECREF(FuelCell_obj);

PyObject* ElectricityRate_obj = ElectricityRate_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ElectricityRate", ElectricityRate_obj);
	Py_DECREF(ElectricityRate_obj);

PyObject* EnergyMarket_obj = EnergyMarket_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "EnergyMarket", EnergyMarket_obj);
	Py_DECREF(EnergyMarket_obj);

PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

PyObject* AdjustmentFactorsModule = PyImport_ImportModule("AdjustmentFactors");

	PyObject* data_cap = PyCapsule_New(self->data_ptr, NULL, NULL);
	PyObject* Adjust_obj = PyObject_CallMethod(AdjustmentFactorsModule, "new", "(O)", data_cap);
	Py_XDECREF(data_cap);
	Py_XDECREF(AdjustmentFactorsModule);

	if (!Adjust_obj){
		PyErr_SetString(PySAM_ErrorObject, "Couldn't create AdjustmentFactorsObject\n");
		return NULL;
	}

	PyDict_SetItemString(attr_dict, "AdjustmentFactors", Adjust_obj);
	Py_DECREF(Adjust_obj);

	return self;
}

/* Battery methods */

static void
Battery_dealloc(BatteryObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_Battery_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
Battery_execute(BatteryObject *self, PyObject *args)
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
Battery_assign(BatteryObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict(self, self->x_attr, self->data_ptr, dict, "Battery"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Battery_export(BatteryObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}


static PyMethodDef Battery_methods[] = {
		{"execute",            (PyCFunction)Battery_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Battery_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs")},
		{"export",            (PyCFunction)Battery_export,  METH_VARARGS,
				PyDoc_STR("assign() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Battery_getattro(BatteryObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Battery_setattr(BatteryObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Battery_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battery",            /*tp_name*/
		sizeof(BatteryObject),/*tp_basicsize*/
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
		"see html for help",        /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Battery_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Battery object */

static PyObject *
Battery_new(PyObject *self, PyObject *args)
{
	BatteryObject *rv;
	rv = newBatteryObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Battery_wrap(PyObject *self, PyObject *args)
{
	BatteryObject *rv;
	long int ptr = 0;
	if (!PyArg_ParseTuple(args, "l:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newBatteryObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Battery_default(PyObject *self, PyObject *args)
{
	BatteryObject *rv;
	char* fin = 0;
	if (!PyArg_ParseTuple(args, "s:default", &fin)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newBatteryObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults(rv, rv->x_attr, rv->data_ptr, "Battery", fin);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef BatteryModule_methods[] = {
		{"new",             Battery_new,         METH_VARARGS,
				PyDoc_STR("new() -> new Battery object")},
		{"wrap",             Battery_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> new Battery object around existing data")},
		{"default",             Battery_default,         METH_VARARGS,
				PyDoc_STR("default(financial) -> new Battery object with financial model-specific default attributes")},		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "This is a template module just for instruction.");


static int
BatteryModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	Battery_Type.tp_dict = PyDict_New();
	if (!Battery_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to Battery_Type
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
	PyDict_SetItemString(Battery_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the Simulation type object to Battery_Type
	if (PyType_Ready(&Simulation_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"Simulation",
				(PyObject*)&Simulation_Type);
	Py_DECREF(&Simulation_Type);

	/// Add the Battery type object to Battery_Type
	if (PyType_Ready(&Battery_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"Battery",
				(PyObject*)&Battery_Type);
	Py_DECREF(&Battery_Type);

	/// Add the System type object to Battery_Type
	if (PyType_Ready(&System_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"System",
				(PyObject*)&System_Type);
	Py_DECREF(&System_Type);

	/// Add the ElectricLoad type object to Battery_Type
	if (PyType_Ready(&ElectricLoad_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"ElectricLoad",
				(PyObject*)&ElectricLoad_Type);
	Py_DECREF(&ElectricLoad_Type);

	/// Add the Common type object to Battery_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the Inverter type object to Battery_Type
	if (PyType_Ready(&Inverter_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"Inverter",
				(PyObject*)&Inverter_Type);
	Py_DECREF(&Inverter_Type);

	/// Add the PV type object to Battery_Type
	if (PyType_Ready(&PV_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"PV",
				(PyObject*)&PV_Type);
	Py_DECREF(&PV_Type);

	/// Add the FuelCell type object to Battery_Type
	if (PyType_Ready(&FuelCell_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"FuelCell",
				(PyObject*)&FuelCell_Type);
	Py_DECREF(&FuelCell_Type);

	/// Add the ElectricityRate type object to Battery_Type
	if (PyType_Ready(&ElectricityRate_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"ElectricityRate",
				(PyObject*)&ElectricityRate_Type);
	Py_DECREF(&ElectricityRate_Type);

	/// Add the EnergyMarket type object to Battery_Type
	if (PyType_Ready(&EnergyMarket_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battery_Type.tp_dict,
				"EnergyMarket",
				(PyObject*)&EnergyMarket_Type);
	Py_DECREF(&EnergyMarket_Type);

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

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error() < 0) goto fail;

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