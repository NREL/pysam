#include <Python.h>

#include <SAM_Battwatts.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Lifetime Group
 */ 

static PyTypeObject Lifetime_Type;

static PyObject *
Lifetime_new(SAM_Battwatts data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battwatts", "Lifetime")){
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
	return PySAM_double_getter(SAM_Battwatts_Lifetime_analysis_period_nget, self->data_ptr);
}

static int
Lifetime_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battwatts_Lifetime_analysis_period_nset, self->data_ptr);
}

static PyObject *
Lifetime_get_system_use_lifetime_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Lifetime_system_use_lifetime_output_nget, self->data_ptr);
}

static int
Lifetime_set_system_use_lifetime_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battwatts_Lifetime_system_use_lifetime_output_nset, self->data_ptr);
}

static PyGetSetDef Lifetime_getset[] = {
{"analysis_period", (getter)Lifetime_get_analysis_period,(setter)Lifetime_set_analysis_period,
	PyDoc_STR("*float*: Lifetime analysis period [years]\n\n*Info*: The number of years in the simulation\n\n*Required*: True if system_use_lifetime_output=1"),
 	NULL},
{"system_use_lifetime_output", (getter)Lifetime_get_system_use_lifetime_output,(setter)Lifetime_set_system_use_lifetime_output,
	PyDoc_STR("*float*: PV lifetime simulation [0/1]\n\n*Options*: 0=SingleYearRepeated,1=RunEveryYear\n\n*Constraints*: BOOLEAN\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Lifetime_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battwatts.Lifetime",             /*tp_name*/
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
 * Battery Group
 */ 

static PyTypeObject Battery_Type;

static PyObject *
Battery_new(SAM_Battwatts data_ptr)
{
	PyObject* new_obj = Battery_Type.tp_alloc(&Battery_Type,0);

	VarGroupObject* Battery_obj = (VarGroupObject*)new_obj;

	Battery_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Battery methods */

static PyObject *
Battery_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battwatts", "Battery")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Battery_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Battery_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Battery_methods[] = {
		{"assign",            (PyCFunction)Battery_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Battery_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Battery_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Battery_get_ac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Battery_ac_aget, self->data_ptr);
}

static int
Battery_set_ac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battwatts_Battery_ac_aset, self->data_ptr);
}

static PyObject *
Battery_get_batt_custom_dispatch(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Battery_batt_custom_dispatch_aget, self->data_ptr);
}

static int
Battery_set_batt_custom_dispatch(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battwatts_Battery_batt_custom_dispatch_aset, self->data_ptr);
}

static PyObject *
Battery_get_batt_simple_chemistry(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Battery_batt_simple_chemistry_nget, self->data_ptr);
}

static int
Battery_set_batt_simple_chemistry(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battwatts_Battery_batt_simple_chemistry_nset, self->data_ptr);
}

static PyObject *
Battery_get_batt_simple_dispatch(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Battery_batt_simple_dispatch_nget, self->data_ptr);
}

static int
Battery_set_batt_simple_dispatch(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battwatts_Battery_batt_simple_dispatch_nset, self->data_ptr);
}

static PyObject *
Battery_get_batt_simple_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Battery_batt_simple_enable_nget, self->data_ptr);
}

static int
Battery_set_batt_simple_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battwatts_Battery_batt_simple_enable_nset, self->data_ptr);
}

static PyObject *
Battery_get_batt_simple_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Battery_batt_simple_kw_nget, self->data_ptr);
}

static int
Battery_set_batt_simple_kw(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battwatts_Battery_batt_simple_kw_nset, self->data_ptr);
}

static PyObject *
Battery_get_batt_simple_kwh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Battery_batt_simple_kwh_nget, self->data_ptr);
}

static int
Battery_set_batt_simple_kwh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battwatts_Battery_batt_simple_kwh_nset, self->data_ptr);
}

static PyObject *
Battery_get_batt_simple_meter_position(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Battery_batt_simple_meter_position_nget, self->data_ptr);
}

static int
Battery_set_batt_simple_meter_position(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battwatts_Battery_batt_simple_meter_position_nset, self->data_ptr);
}

static PyObject *
Battery_get_crit_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Battery_crit_load_aget, self->data_ptr);
}

static int
Battery_set_crit_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battwatts_Battery_crit_load_aset, self->data_ptr);
}

static PyObject *
Battery_get_dc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Battery_dc_aget, self->data_ptr);
}

static int
Battery_set_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battwatts_Battery_dc_aset, self->data_ptr);
}

static PyObject *
Battery_get_inverter_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Battery_inverter_efficiency_nget, self->data_ptr);
}

static int
Battery_set_inverter_efficiency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battwatts_Battery_inverter_efficiency_nset, self->data_ptr);
}

static PyObject *
Battery_get_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Battery_load_aget, self->data_ptr);
}

static int
Battery_set_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battwatts_Battery_load_aset, self->data_ptr);
}

static PyGetSetDef Battery_getset[] = {
{"ac", (getter)Battery_get_ac,(setter)Battery_set_ac,
	PyDoc_STR("*sequence*: AC inverter power [W]"),
 	NULL},
{"batt_custom_dispatch", (getter)Battery_get_batt_custom_dispatch,(setter)Battery_set_batt_custom_dispatch,
	PyDoc_STR("*sequence*: Battery Dispatch [kW]\n\n*Required*: True if batt_simple_dispatch=2"),
 	NULL},
{"batt_simple_chemistry", (getter)Battery_get_batt_simple_chemistry,(setter)Battery_set_batt_simple_chemistry,
	PyDoc_STR("*float*: Battery Chemistry [0=LeadAcid,1=Li-ion/2]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"batt_simple_dispatch", (getter)Battery_get_batt_simple_dispatch,(setter)Battery_set_batt_simple_dispatch,
	PyDoc_STR("*float*: Battery Dispatch [0=PeakShavingLookAhead,1=PeakShavingLookBehind,2=Custom]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"batt_simple_enable", (getter)Battery_get_batt_simple_enable,(setter)Battery_set_batt_simple_enable,
	PyDoc_STR("*float*: Enable Battery [0/1]\n\n*Constraints*: BOOLEAN\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"batt_simple_kw", (getter)Battery_get_batt_simple_kw,(setter)Battery_set_batt_simple_kw,
	PyDoc_STR("*float*: Battery Power [kW]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"batt_simple_kwh", (getter)Battery_get_batt_simple_kwh,(setter)Battery_set_batt_simple_kwh,
	PyDoc_STR("*float*: Battery Capacity [kWh]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"batt_simple_meter_position", (getter)Battery_get_batt_simple_meter_position,(setter)Battery_set_batt_simple_meter_position,
	PyDoc_STR("*float*: Battery Meter Position [0=BehindTheMeter,1=FrontOfMeter]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"crit_load", (getter)Battery_get_crit_load,(setter)Battery_set_crit_load,
	PyDoc_STR("*sequence*: Critical electricity load (year 1) [kW]"),
 	NULL},
{"dc", (getter)Battery_get_dc,(setter)Battery_set_dc,
	PyDoc_STR("*sequence*: DC array power [W]"),
 	NULL},
{"inverter_efficiency", (getter)Battery_get_inverter_efficiency,(setter)Battery_set_inverter_efficiency,
	PyDoc_STR("*float*: Inverter Efficiency [%]\n\n*Constraints*: MIN=0,MAX=100"),
 	NULL},
{"load", (getter)Battery_get_load,(setter)Battery_set_load,
	PyDoc_STR("*sequence*: Electricity load (year 1) [kW]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Battery_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battwatts.Battery",             /*tp_name*/
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
		Battery_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Battery_getset,          /*tp_getset*/
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
Outputs_new(SAM_Battwatts data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battwatts", "Outputs")){
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
	return PySAM_array_getter(SAM_Battwatts_Outputs_annual_export_to_grid_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_import_to_grid_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_annual_import_to_grid_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_average_battery_conversion_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Outputs_average_battery_conversion_efficiency_nget, self->data_ptr);
}

static PyObject *
Outputs_get_average_battery_roundtrip_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Outputs_average_battery_roundtrip_efficiency_nget, self->data_ptr);
}

static PyObject *
Outputs_get_avg_critical_load(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Outputs_avg_critical_load_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_DOD(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_DOD_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_DOD_cycle_average(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_DOD_cycle_average_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_I(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_I_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_SOC(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_SOC_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_charge_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_annual_charge_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_charge_from_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_annual_charge_from_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_charge_from_pv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_annual_charge_from_pv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_discharge_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_annual_discharge_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_energy_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_annual_energy_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_energy_system_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_annual_energy_system_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_bank_installed_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Outputs_batt_bank_installed_capacity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_bank_replacement(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_bank_replacement_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_capacity_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_capacity_percent_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_capacity_percent_calendar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_capacity_percent_calendar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_capacity_percent_cycle(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_capacity_percent_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_capacity_thermal_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_capacity_thermal_percent_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_conversion_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_conversion_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_cost_to_cycle(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_cost_to_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_cycles(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_cycles_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_dispatch_sched(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battwatts_Outputs_batt_dispatch_sched_mget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_power(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_power_target(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_power_target_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pv_charge_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Outputs_batt_pv_charge_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_q0(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_q0_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_q1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_q1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_q2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_q2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_qmax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_qmax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_qmaxI(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_qmaxI_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_qmax_thermal(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_qmax_thermal_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_revenue_charge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_revenue_charge_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_revenue_clipcharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_revenue_clipcharge_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_revenue_discharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_revenue_discharge_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_revenue_gridcharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_revenue_gridcharge_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_system_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_system_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_temperature(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_temperature_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_voltage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_voltage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_voltage_cell(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_voltage_cell_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cdf_of_surviving(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_cdf_of_surviving_aget, self->data_ptr);
}

static PyObject *
Outputs_get_fuelcell_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_fuelcell_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_power(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_grid_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_power_target(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_grid_power_target_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_grid_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_grid_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_market_sell_rate_series_yr1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_market_sell_rate_series_yr1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_batt_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_batt_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_batt_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_batt_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_grid_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_grid_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_grid_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_grid_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_pv_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_pv_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_pv_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_pv_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_pv_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_pv_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_outage_durations(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_outage_durations_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pdf_of_surviving(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_pdf_of_surviving_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pv_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_pv_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pv_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_pv_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pv_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_pv_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_resilience_hrs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_resilience_hrs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_resilience_hrs_avg(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Outputs_resilience_hrs_avg_nget, self->data_ptr);
}

static PyObject *
Outputs_get_resilience_hrs_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Outputs_resilience_hrs_max_nget, self->data_ptr);
}

static PyObject *
Outputs_get_resilience_hrs_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Outputs_resilience_hrs_min_nget, self->data_ptr);
}

static PyObject *
Outputs_get_survival_function(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_survival_function_aget, self->data_ptr);
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
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System power generated [kW]"),
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
		"Battwatts.Outputs",             /*tp_name*/
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
 * Battwatts
 */

static PyTypeObject Battwatts_Type;

static CmodObject *
newBattwattsObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Battwatts_Type);

	PySAM_TECH_ATTR()

	PyObject* Lifetime_obj = Lifetime_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Lifetime", Lifetime_obj);
	Py_DECREF(Lifetime_obj);

	PyObject* Battery_obj = Battery_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Battery", Battery_obj);
	Py_DECREF(Battery_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Battwatts methods */

static void
Battwatts_dealloc(CmodObject *self)
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
Battwatts_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Battwatts_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Battwatts_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Battwatts"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Battwatts_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Battwatts_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef Battwatts_methods[] = {
		{"execute",            (PyCFunction)Battwatts_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Battwatts_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Lifetime': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Battwatts_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Battwatts_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Battwatts_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Battwatts_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Battwatts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battwatts",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Battwatts_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Battwatts_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Battwatts_getattro, /*tp_getattro*/
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
		Battwatts_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Battwatts object */

static PyObject *
Battwatts_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newBattwattsObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Battwatts_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newBattwattsObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Battwatts_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newBattwattsObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Battwatts", def);

	return (PyObject *)rv;
}

static PyObject *
Battwatts_from_existing(PyObject *self, PyObject *args)
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

	rv = newBattwattsObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Battwatts", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef BattwattsModule_methods[] = {
		{"new",             Battwatts_new,         METH_VARARGS,
				PyDoc_STR("new() -> Battwatts")},
		{"default",             Battwatts_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Battwatts\n\nUse financial config-specific default attributes\n"
				"config options:\n\n- \"PVWattsBatteryCommercial\"\n- \"PVWattsBatteryHostDeveloper\"\n- \"PVWattsBatteryResidential\"\n- \"PVWattsBatteryThirdParty\"")},
		{"wrap",             Battwatts_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Battwatts\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   Battwatts_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Battwatts\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Simplified battery storage model");


static int
BattwattsModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Battwatts_Type.tp_dict = PyDict_New();
	if (!Battwatts_Type.tp_dict) { goto fail; }

	/// Add the Lifetime type object to Battwatts_Type
	if (PyType_Ready(&Lifetime_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battwatts_Type.tp_dict,
				"Lifetime",
				(PyObject*)&Lifetime_Type);
	Py_DECREF(&Lifetime_Type);

	/// Add the Battery type object to Battwatts_Type
	if (PyType_Ready(&Battery_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battwatts_Type.tp_dict,
				"Battery",
				(PyObject*)&Battery_Type);
	Py_DECREF(&Battery_Type);

	/// Add the Outputs type object to Battwatts_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battwatts_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Battwatts type object to the module
	if (PyType_Ready(&Battwatts_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Battwatts",
				(PyObject*)&Battwatts_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot BattwattsModule_slots[] = {
		{Py_mod_exec, BattwattsModule_exec},
		{0, NULL},
};

static struct PyModuleDef BattwattsModule = {
		PyModuleDef_HEAD_INIT,
		"Battwatts",
		module_doc,
		0,
		BattwattsModule_methods,
		BattwattsModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Battwatts(void)
{
	return PyModuleDef_Init(&BattwattsModule);
}