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
Lifetime_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Lifetime_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battwatts", "Lifetime")){
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
	PyDoc_STR("*float*: Lifetime analysis period [years]\n\n**Info:**\nThe number of years in the simulation\n\n**Required:**\nRequired if system_use_lifetime_output=1"),
 	NULL},
{"system_use_lifetime_output", (getter)Lifetime_get_system_use_lifetime_output,(setter)Lifetime_set_system_use_lifetime_output,
	PyDoc_STR("*float*: Enable lifetime simulation [0/1]\n\n**Options:**\n0=SingleYearRepeated,1=RunEveryYear\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
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
Battery_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Battery_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battwatts", "Battery")){
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
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Battery_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Battery_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Battery_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Battery_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
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
	PyDoc_STR("*sequence*: Battery Dispatch [kW]\n\n**Required:**\nRequired if batt_simple_dispatch=2"),
 	NULL},
{"batt_simple_chemistry", (getter)Battery_get_batt_simple_chemistry,(setter)Battery_set_batt_simple_chemistry,
	PyDoc_STR("*float*: Battery Chemistry [0=LeadAcid,1=Li-ion/2]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_simple_dispatch", (getter)Battery_get_batt_simple_dispatch,(setter)Battery_set_batt_simple_dispatch,
	PyDoc_STR("*float*: Battery Dispatch [0=PeakShavingLookAhead,1=PeakShavingLookBehind,2=Custom]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_simple_enable", (getter)Battery_get_batt_simple_enable,(setter)Battery_set_batt_simple_enable,
	PyDoc_STR("*float*: Enable Battery [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_simple_kw", (getter)Battery_get_batt_simple_kw,(setter)Battery_set_batt_simple_kw,
	PyDoc_STR("*float*: Battery Power [kW]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_simple_kwh", (getter)Battery_get_batt_simple_kwh,(setter)Battery_set_batt_simple_kwh,
	PyDoc_STR("*float*: Battery Capacity [kWh]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_simple_meter_position", (getter)Battery_get_batt_simple_meter_position,(setter)Battery_set_batt_simple_meter_position,
	PyDoc_STR("*float*: Battery Meter Position [0=BehindTheMeter,1=FrontOfMeter]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"crit_load", (getter)Battery_get_crit_load,(setter)Battery_set_crit_load,
	PyDoc_STR("*sequence*: Critical electricity load (year 1) [kW]"),
 	NULL},
{"dc", (getter)Battery_get_dc,(setter)Battery_set_dc,
	PyDoc_STR("*sequence*: DC array power [W]"),
 	NULL},
{"inverter_efficiency", (getter)Battery_get_inverter_efficiency,(setter)Battery_set_inverter_efficiency,
	PyDoc_STR("*float*: Inverter Efficiency [%]\n\n**Constraints:**\nMIN=0,MAX=100"),
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
 * Load Group
 */ 

static PyTypeObject Load_Type;

static PyObject *
Load_new(SAM_Battwatts data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battwatts", "Load")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battwatts", "Load")){
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
Load_get_grid_outage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Load_grid_outage_aget, self->data_ptr);
}

static int
Load_set_grid_outage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battwatts_Load_grid_outage_aset, self->data_ptr);
}

static PyObject *
Load_get_load_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Load_load_escalation_aget, self->data_ptr);
}

static int
Load_set_load_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battwatts_Load_load_escalation_aset, self->data_ptr);
}

static PyObject *
Load_get_run_resiliency_calcs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Load_run_resiliency_calcs_nget, self->data_ptr);
}

static int
Load_set_run_resiliency_calcs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battwatts_Load_run_resiliency_calcs_nset, self->data_ptr);
}

static PyGetSetDef Load_getset[] = {
{"grid_outage", (getter)Load_get_grid_outage,(setter)Load_set_grid_outage,
	PyDoc_STR("*sequence*: Grid outage in this time step [0/1]\n\n**Options:**\n0=GridAvailable,1=GridUnavailable,Length=load"),
 	NULL},
{"load_escalation", (getter)Load_get_load_escalation,(setter)Load_set_load_escalation,
	PyDoc_STR("*sequence*: Annual load escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
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
		"Battwatts.Load",             /*tp_name*/
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
 * GridLimits Group
 */ 

static PyTypeObject GridLimits_Type;

static PyObject *
GridLimits_new(SAM_Battwatts data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battwatts", "GridLimits")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battwatts", "GridLimits")){
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
	return PySAM_double_getter(SAM_Battwatts_GridLimits_enable_interconnection_limit_nget, self->data_ptr);
}

static int
GridLimits_set_enable_interconnection_limit(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battwatts_GridLimits_enable_interconnection_limit_nset, self->data_ptr);
}

static PyObject *
GridLimits_get_grid_curtailment(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_GridLimits_grid_curtailment_aget, self->data_ptr);
}

static int
GridLimits_set_grid_curtailment(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Battwatts_GridLimits_grid_curtailment_aset, self->data_ptr);
}

static PyObject *
GridLimits_get_grid_interconnection_limit_kwac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_GridLimits_grid_interconnection_limit_kwac_nget, self->data_ptr);
}

static int
GridLimits_set_grid_interconnection_limit_kwac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Battwatts_GridLimits_grid_interconnection_limit_kwac_nset, self->data_ptr);
}

static PyGetSetDef GridLimits_getset[] = {
{"enable_interconnection_limit", (getter)GridLimits_get_enable_interconnection_limit,(setter)GridLimits_set_enable_interconnection_limit,
	PyDoc_STR("*float*: Enable grid interconnection limit [0/1]\n\n**Info:**\nEnable a grid interconnection limit"),
 	NULL},
{"grid_curtailment", (getter)GridLimits_get_grid_curtailment,(setter)GridLimits_set_grid_curtailment,
	PyDoc_STR("*sequence*: Grid curtailment as energy delivery limit (first year) [MW]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
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
		"Battwatts.GridLimits",             /*tp_name*/
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
Outputs_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Outputs_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Battwatts", "Outputs")){
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
	return PySAM_double_getter(SAM_Battwatts_Outputs_annual_crit_load_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_crit_load_unmet(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Outputs_annual_crit_load_unmet_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_crit_load_unmet_percentage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Outputs_annual_crit_load_unmet_percentage_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution_time(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battwatts_Outputs_annual_energy_distribution_time_mget, self->data_ptr);
}

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
Outputs_get_annual_outage_losses_unmet(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Outputs_annual_outage_losses_unmet_nget, self->data_ptr);
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
Outputs_get_batt_annual_charge_from_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_annual_charge_from_system_aget, self->data_ptr);
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
Outputs_get_batt_pvs_PV_ramp_interval(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_pvs_PV_ramp_interval_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_P_pv_ac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_pvs_P_pv_ac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_battpower(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_pvs_battpower_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_battsoc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_pvs_battsoc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_curtail(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_pvs_curtail_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_energy_to_grid_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Outputs_batt_pvs_energy_to_grid_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_energy_to_grid_percent_sam(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Outputs_batt_pvs_energy_to_grid_percent_sam_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_forecast_pv_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_pvs_forecast_pv_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_outpower(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_pvs_outpower_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_violation_count(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Outputs_batt_pvs_violation_count_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_violation_list(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_pvs_violation_list_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_violation_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Outputs_batt_pvs_violation_percent_nget, self->data_ptr);
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
Outputs_get_batt_system_charge_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Battwatts_Outputs_batt_system_charge_percent_nget, self->data_ptr);
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
Outputs_get_batt_to_system_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_to_system_load_aget, self->data_ptr);
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
Outputs_get_crit_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_crit_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_crit_load_unmet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_crit_load_unmet_aget, self->data_ptr);
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
Outputs_get_gen_without_battery(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_gen_without_battery_aget, self->data_ptr);
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
Outputs_get_interconnection_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_interconnection_loss_aget, self->data_ptr);
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
Outputs_get_monthly_batt_to_system_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_batt_to_system_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_crit_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_crit_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_crit_load_unmet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_crit_load_unmet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_crit_load_unmet_percentage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_crit_load_unmet_percentage_aget, self->data_ptr);
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
Outputs_get_monthly_interconnection_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_interconnection_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_outage_losses_unmet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_outage_losses_unmet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_system_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_system_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_system_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_system_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_system_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_system_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_outage_durations(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_outage_durations_aget, self->data_ptr);
}

static PyObject *
Outputs_get_outage_losses_unmet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_outage_losses_unmet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pdf_of_surviving(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_pdf_of_surviving_aget, self->data_ptr);
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

static PyObject *
Outputs_get_system_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_system_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_system_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_system_to_load_aget, self->data_ptr);
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
{"annual_energy_distribution_time", (getter)Outputs_get_annual_energy_distribution_time,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Annual energy production as function of time [kW]"),
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
	PyDoc_STR("*sequence*: Electricity to/from battery [kW]"),
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
	PyDoc_STR("*sequence*: Electricity to grid from battery [kW]"),
 	NULL},
{"batt_to_load", (getter)Outputs_get_batt_to_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity to load from battery [kW]"),
 	NULL},
{"batt_to_system_load", (getter)Outputs_get_batt_to_system_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity to system loads from battery [kW]"),
 	NULL},
{"batt_voltage", (getter)Outputs_get_batt_voltage,(setter)0,
	PyDoc_STR("*sequence*: Battery voltage [V]"),
 	NULL},
{"batt_voltage_cell", (getter)Outputs_get_batt_voltage_cell,(setter)0,
	PyDoc_STR("*sequence*: Battery cell voltage [V]"),
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
	PyDoc_STR("*sequence*: Electricity to battery from fuel cell [kW]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System power generated [kW]"),
 	NULL},
{"gen_without_battery", (getter)Outputs_get_gen_without_battery,(setter)0,
	PyDoc_STR("*sequence*: Power produced without the battery or curtailment [kW]"),
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
{"interconnection_loss", (getter)Outputs_get_interconnection_loss,(setter)0,
	PyDoc_STR("*sequence*: Electricity loss due to curtailment, interconnection, or outage [kW]"),
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
	PyDoc_STR("*sequence*: Electricity to battery from system [kW]"),
 	NULL},
{"system_to_grid", (getter)Outputs_get_system_to_grid,(setter)0,
	PyDoc_STR("*sequence*: Electricity to grid from system [kW]"),
 	NULL},
{"system_to_load", (getter)Outputs_get_system_to_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity to load from system [kW]"),
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

	PyObject* Load_obj = Load_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Load", Load_obj);
	Py_DECREF(Load_obj);

	PyObject* GridLimits_obj = GridLimits_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "GridLimits", GridLimits_obj);
	Py_DECREF(GridLimits_obj);

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
Battwatts_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Battwatts"))
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

static PyObject *
Battwatts_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Battwatts_methods[] = {
		{"execute",           (PyCFunction)Battwatts_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Battwatts_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Lifetime': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Battwatts_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Lifetime': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Battwatts_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Battwatts_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Battwatts_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
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
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Battwatts", def) < 0) {
		Battwatts_dealloc(rv);
		return NULL;
	}
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
				PyDoc_STR("default(config) -> Battwatts\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"PVWattsBatteryCommercial\"*\n\n		- *\"PVWattsBatteryHostDeveloper\"*\n\n		- *\"PVWattsBatteryResidential\"*\n\n		- *\"PVWattsBatteryThirdParty\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Battwatts_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Battwatts\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Battwatts_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Battwatts\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
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

	/// Add the Load type object to Battwatts_Type
	if (PyType_Ready(&Load_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battwatts_Type.tp_dict,
				"Load",
				(PyObject*)&Load_Type);
	Py_DECREF(&Load_Type);

	/// Add the GridLimits type object to Battwatts_Type
	if (PyType_Ready(&GridLimits_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battwatts_Type.tp_dict,
				"GridLimits",
				(PyObject*)&GridLimits_Type);
	Py_DECREF(&GridLimits_Type);

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