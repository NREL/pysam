#include <Python.h>

#include <SAM_Grid.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Lifetime Group
 */ 

static PyTypeObject Lifetime_Type;

static PyObject *
Lifetime_new(SAM_Grid data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Grid", "Lifetime")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Grid", "Lifetime")){
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
	return PySAM_double_getter(SAM_Grid_Lifetime_analysis_period_nget, self->data_ptr);
}

static int
Lifetime_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Grid_Lifetime_analysis_period_nset, self->data_ptr);
}

static PyObject *
Lifetime_get_system_use_lifetime_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Lifetime_system_use_lifetime_output_nget, self->data_ptr);
}

static int
Lifetime_set_system_use_lifetime_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Grid_Lifetime_system_use_lifetime_output_nset, self->data_ptr);
}

static PyGetSetDef Lifetime_getset[] = {
{"analysis_period", (getter)Lifetime_get_analysis_period,(setter)Lifetime_set_analysis_period,
	PyDoc_STR("*float*: Lifetime analysis period [years]\n\n**Info:**\nThe number of years in the simulation\n\n**Required:**\nRequired if system_use_lifetime_output=1"),
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
		"Grid.Lifetime",             /*tp_name*/
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
 * SystemOutput Group
 */ 

static PyTypeObject SystemOutput_Type;

static PyObject *
SystemOutput_new(SAM_Grid data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Grid", "SystemOutput")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Grid", "SystemOutput")){
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
	return PySAM_double_getter(SAM_Grid_SystemOutput_annual_energy_nget, self->data_ptr);
}

static int
SystemOutput_set_annual_energy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Grid_SystemOutput_annual_energy_nset, self->data_ptr);
}

static PyObject *
SystemOutput_get_energy_hourly_kW(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Grid_SystemOutput_energy_hourly_kW_aget, self->data_ptr);
}

static int
SystemOutput_set_energy_hourly_kW(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Grid_SystemOutput_energy_hourly_kW_aset, self->data_ptr);
}

static PyObject *
SystemOutput_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Grid_SystemOutput_gen_aget, self->data_ptr);
}

static int
SystemOutput_set_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Grid_SystemOutput_gen_aset, self->data_ptr);
}

static PyGetSetDef SystemOutput_getset[] = {
{"annual_energy", (getter)SystemOutput_get_annual_energy,(setter)SystemOutput_set_annual_energy,
	PyDoc_STR("*float*: Annual Energy AC (year 1) [kWh]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"energy_hourly_kW", (getter)SystemOutput_get_energy_hourly_kW,(setter)SystemOutput_set_energy_hourly_kW,
	PyDoc_STR("*sequence*: Power output of array [kW]\n\n**Info:**\nLifetime system generation\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"gen", (getter)SystemOutput_get_gen,(setter)SystemOutput_set_gen,
	PyDoc_STR("*sequence*: System power generated [kW]\n\n**Info:**\nLifetime system generation\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemOutput_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Grid.SystemOutput",             /*tp_name*/
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
Load_new(SAM_Grid data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Grid", "Load")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Grid", "Load")){
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
	return PySAM_array_getter(SAM_Grid_Load_crit_load_aget, self->data_ptr);
}

static int
Load_set_crit_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Grid_Load_crit_load_aset, self->data_ptr);
}

static PyObject *
Load_get_grid_outage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Grid_Load_grid_outage_aget, self->data_ptr);
}

static int
Load_set_grid_outage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Grid_Load_grid_outage_aset, self->data_ptr);
}

static PyObject *
Load_get_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Grid_Load_load_aget, self->data_ptr);
}

static int
Load_set_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Grid_Load_load_aset, self->data_ptr);
}

static PyObject *
Load_get_load_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Grid_Load_load_escalation_aget, self->data_ptr);
}

static int
Load_set_load_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Grid_Load_load_escalation_aset, self->data_ptr);
}

static PyGetSetDef Load_getset[] = {
{"crit_load", (getter)Load_get_crit_load,(setter)Load_set_crit_load,
	PyDoc_STR("*sequence*: Critical electricity load (year 1) [kW]"),
 	NULL},
{"grid_outage", (getter)Load_get_grid_outage,(setter)Load_set_grid_outage,
	PyDoc_STR("*sequence*: Grid outage in this time step [0/1]\n\n**Options:**\n0=GridAvailable,1=GridUnavailable,Length=load\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"load", (getter)Load_get_load,(setter)Load_set_load,
	PyDoc_STR("*sequence*: Electricity load (year 1) [kW]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"load_escalation", (getter)Load_get_load_escalation,(setter)Load_set_load_escalation,
	PyDoc_STR("*sequence*: Annual load escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Load_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Grid.Load",             /*tp_name*/
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
GridLimits_new(SAM_Grid data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Grid", "GridLimits")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Grid", "GridLimits")){
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
	return PySAM_double_getter(SAM_Grid_GridLimits_enable_interconnection_limit_nget, self->data_ptr);
}

static int
GridLimits_set_enable_interconnection_limit(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Grid_GridLimits_enable_interconnection_limit_nset, self->data_ptr);
}

static PyObject *
GridLimits_get_grid_curtailment(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Grid_GridLimits_grid_curtailment_aget, self->data_ptr);
}

static int
GridLimits_set_grid_curtailment(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Grid_GridLimits_grid_curtailment_aset, self->data_ptr);
}

static PyObject *
GridLimits_get_grid_interconnection_limit_kwac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_GridLimits_grid_interconnection_limit_kwac_nget, self->data_ptr);
}

static int
GridLimits_set_grid_interconnection_limit_kwac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Grid_GridLimits_grid_interconnection_limit_kwac_nset, self->data_ptr);
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
		"Grid.GridLimits",             /*tp_name*/
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
Outputs_new(SAM_Grid data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Grid", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Grid", "Outputs")){
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
Outputs_get_annual_ac_curtailment_loss_kwh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Outputs_annual_ac_curtailment_loss_kwh_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ac_curtailment_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Outputs_annual_ac_curtailment_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ac_interconnect_loss_kwh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Outputs_annual_ac_interconnect_loss_kwh_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ac_interconnect_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Outputs_annual_ac_interconnect_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution_time(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Grid_Outputs_annual_energy_distribution_time_mget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_pre_curtailment_ac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Outputs_annual_energy_pre_curtailment_ac_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_pre_interconnect_ac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Outputs_annual_energy_pre_interconnect_ac_nget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor_curtailment_ac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Outputs_capacity_factor_curtailment_ac_nget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor_interconnect_ac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Grid_Outputs_capacity_factor_interconnect_ac_nget, self->data_ptr);
}

static PyObject *
Outputs_get_full_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Grid_Outputs_full_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Grid_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_pre_curtailment_kwac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Grid_Outputs_system_pre_curtailment_kwac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_pre_interconnect_kwac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Grid_Outputs_system_pre_interconnect_kwac_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_ac_curtailment_loss_kwh", (getter)Outputs_get_annual_ac_curtailment_loss_kwh,(setter)0,
	PyDoc_STR("*float*: Annual Energy loss from curtailment (year 1) [kWh]"),
 	NULL},
{"annual_ac_curtailment_loss_percent", (getter)Outputs_get_annual_ac_curtailment_loss_percent,(setter)0,
	PyDoc_STR("*float*: Annual Energy loss from curtailment (year 1) [%]"),
 	NULL},
{"annual_ac_interconnect_loss_kwh", (getter)Outputs_get_annual_ac_interconnect_loss_kwh,(setter)0,
	PyDoc_STR("*float*: Annual Energy loss from interconnection limit (year 1) [kWh]"),
 	NULL},
{"annual_ac_interconnect_loss_percent", (getter)Outputs_get_annual_ac_interconnect_loss_percent,(setter)0,
	PyDoc_STR("*float*: Annual Energy loss from interconnection limit (year 1) [%]"),
 	NULL},
{"annual_energy_distribution_time", (getter)Outputs_get_annual_energy_distribution_time,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Annual energy production as function of time [kW]"),
 	NULL},
{"annual_energy_pre_curtailment_ac", (getter)Outputs_get_annual_energy_pre_curtailment_ac,(setter)0,
	PyDoc_STR("*float*: Annual Energy AC pre-curtailment (year 1) [kWh]"),
 	NULL},
{"annual_energy_pre_interconnect_ac", (getter)Outputs_get_annual_energy_pre_interconnect_ac,(setter)0,
	PyDoc_STR("*float*: Annual Energy AC pre-interconnection (year 1) [kWh]"),
 	NULL},
{"capacity_factor_curtailment_ac", (getter)Outputs_get_capacity_factor_curtailment_ac,(setter)0,
	PyDoc_STR("*float*: Capacity factor based on AC electricity after curtailment and AC interconnection limit [%]"),
 	NULL},
{"capacity_factor_interconnect_ac", (getter)Outputs_get_capacity_factor_interconnect_ac,(setter)0,
	PyDoc_STR("*float*: Capacity factor based on AC interconnection limit [%]"),
 	NULL},
{"full_load", (getter)Outputs_get_full_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity load prior to grid outage (year 1) [kW]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System power generated [kW]"),
 	NULL},
{"system_pre_curtailment_kwac", (getter)Outputs_get_system_pre_curtailment_kwac,(setter)0,
	PyDoc_STR("*sequence*: System power before grid curtailment [kW]"),
 	NULL},
{"system_pre_interconnect_kwac", (getter)Outputs_get_system_pre_interconnect_kwac,(setter)0,
	PyDoc_STR("*sequence*: System power before grid interconnect [kW]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Grid.Outputs",             /*tp_name*/
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
 * Grid
 */

static PyTypeObject Grid_Type;

static CmodObject *
newGridObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Grid_Type);

	PySAM_TECH_ATTR()

	PyObject* Lifetime_obj = Lifetime_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Lifetime", Lifetime_obj);
	Py_DECREF(Lifetime_obj);

	PyObject* SystemOutput_obj = SystemOutput_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemOutput", SystemOutput_obj);
	Py_DECREF(SystemOutput_obj);

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

/* Grid methods */

static void
Grid_dealloc(CmodObject *self)
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
Grid_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Grid_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Grid_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Grid"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Grid_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Grid"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Grid_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Grid_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Grid_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Grid_methods[] = {
		{"execute",           (PyCFunction)Grid_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Grid_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Lifetime': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Grid_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Lifetime': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Grid_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Grid_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Grid_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Grid_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Grid_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Grid_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Grid",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Grid_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Grid_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Grid_getattro, /*tp_getattro*/
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
		Grid_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Grid object */

static PyObject *
Grid_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newGridObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Grid_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newGridObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Grid_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newGridObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Grid", def) < 0) {
		Grid_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Grid_from_existing(PyObject *self, PyObject *args)
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

	rv = newGridObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Grid", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef GridModule_methods[] = {
		{"new",             Grid_new,         METH_VARARGS,
				PyDoc_STR("new() -> Grid")},
		{"default",             Grid_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Grid\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"BiopowerAllEquityPartnershipFlip\"*\n\n		- *\"BiopowerLCOECalculator\"*\n\n		- *\"BiopowerLeveragedPartnershipFlip\"*\n\n		- *\"BiopowerMerchantPlant\"*\n\n		- *\"BiopowerNone\"*\n\n		- *\"BiopowerSaleLeaseback\"*\n\n		- *\"BiopowerSingleOwner\"*\n\n		- *\"DSLFAllEquityPartnershipFlip\"*\n\n		- *\"DSLFCommercial\"*\n\n		- *\"DSLFLCOECalculator\"*\n\n		- *\"DSLFLeveragedPartnershipFlip\"*\n\n		- *\"DSLFMerchantPlant\"*\n\n		- *\"DSLFNone\"*\n\n		- *\"DSLFSaleLeaseback\"*\n\n		- *\"DSLFSingleOwner\"*\n\n		- *\"FlatPlatePVAllEquityPartnershipFlip\"*\n\n		- *\"FlatPlatePVCommercial\"*\n\n		- *\"FlatPlatePVHostDeveloper\"*\n\n		- *\"FlatPlatePVLCOECalculator\"*\n\n		- *\"FlatPlatePVLeveragedPartnershipFlip\"*\n\n		- *\"FlatPlatePVMerchantPlant\"*\n\n		- *\"FlatPlatePVNone\"*\n\n		- *\"FlatPlatePVResidential\"*\n\n		- *\"FlatPlatePVSaleLeaseback\"*\n\n		- *\"FlatPlatePVSingleOwner\"*\n\n		- *\"FlatPlatePVThirdParty\"*\n\n		- *\"FuelCellCommercial\"*\n\n		- *\"FuelCellSingleOwner\"*\n\n		- *\"GenericBatteryAllEquityPartnershipFlip\"*\n\n		- *\"GenericBatteryCommercial\"*\n\n		- *\"GenericBatteryHostDeveloper\"*\n\n		- *\"GenericBatteryLeveragedPartnershipFlip\"*\n\n		- *\"GenericBatteryMerchantPlant\"*\n\n		- *\"GenericBatteryResidential\"*\n\n		- *\"GenericBatterySaleLeaseback\"*\n\n		- *\"GenericBatterySingleOwner\"*\n\n		- *\"GenericBatteryThirdParty\"*\n\n		- *\"GenericCSPSystemAllEquityPartnershipFlip\"*\n\n		- *\"GenericCSPSystemCommercial\"*\n\n		- *\"GenericCSPSystemLCOECalculator\"*\n\n		- *\"GenericCSPSystemLeveragedPartnershipFlip\"*\n\n		- *\"GenericCSPSystemMerchantPlant\"*\n\n		- *\"GenericCSPSystemNone\"*\n\n		- *\"GenericCSPSystemSaleLeaseback\"*\n\n		- *\"GenericCSPSystemSingleOwner\"*\n\n		- *\"GenericSystemAllEquityPartnershipFlip\"*\n\n		- *\"GenericSystemCommercial\"*\n\n		- *\"GenericSystemHostDeveloper\"*\n\n		- *\"GenericSystemLCOECalculator\"*\n\n		- *\"GenericSystemLeveragedPartnershipFlip\"*\n\n		- *\"GenericSystemMerchantPlant\"*\n\n		- *\"GenericSystemNone\"*\n\n		- *\"GenericSystemResidential\"*\n\n		- *\"GenericSystemSaleLeaseback\"*\n\n		- *\"GenericSystemSingleOwner\"*\n\n		- *\"GenericSystemThirdParty\"*\n\n		- *\"GeothermalPowerAllEquityPartnershipFlip\"*\n\n		- *\"GeothermalPowerLCOECalculator\"*\n\n		- *\"GeothermalPowerLeveragedPartnershipFlip\"*\n\n		- *\"GeothermalPowerMerchantPlant\"*\n\n		- *\"GeothermalPowerNone\"*\n\n		- *\"GeothermalPowerSaleLeaseback\"*\n\n		- *\"GeothermalPowerSingleOwner\"*\n\n		- *\"HighXConcentratingPVAllEquityPartnershipFlip\"*\n\n		- *\"HighXConcentratingPVLCOECalculator\"*\n\n		- *\"HighXConcentratingPVLeveragedPartnershipFlip\"*\n\n		- *\"HighXConcentratingPVMerchantPlant\"*\n\n		- *\"HighXConcentratingPVNone\"*\n\n		- *\"HighXConcentratingPVSaleLeaseback\"*\n\n		- *\"HighXConcentratingPVSingleOwner\"*\n\n		- *\"MEwaveBatterySingleOwner\"*\n\n		- *\"MEwaveSingleOwner\"*\n\n		- *\"MSLFAllEquityPartnershipFlip\"*\n\n		- *\"MSLFCommercial\"*\n\n		- *\"MSLFLCOECalculator\"*\n\n		- *\"MSLFLeveragedPartnershipFlip\"*\n\n		- *\"MSLFMerchantPlant\"*\n\n		- *\"MSLFNone\"*\n\n		- *\"MSLFSaleLeaseback\"*\n\n		- *\"MSLFSingleOwner\"*\n\n		- *\"MSPTAllEquityPartnershipFlip\"*\n\n		- *\"MSPTLeveragedPartnershipFlip\"*\n\n		- *\"MSPTMerchantPlant\"*\n\n		- *\"MSPTSaleLeaseback\"*\n\n		- *\"MSPTSingleOwner\"*\n\n		- *\"PVBatteryAllEquityPartnershipFlip\"*\n\n		- *\"PVBatteryCommercial\"*\n\n		- *\"PVBatteryHostDeveloper\"*\n\n		- *\"PVBatteryLeveragedPartnershipFlip\"*\n\n		- *\"PVBatteryMerchantPlant\"*\n\n		- *\"PVBatteryResidential\"*\n\n		- *\"PVBatterySaleLeaseback\"*\n\n		- *\"PVBatterySingleOwner\"*\n\n		- *\"PVBatteryThirdParty\"*\n\n		- *\"PVWattsBatteryCommercial\"*\n\n		- *\"PVWattsBatteryHostDeveloper\"*\n\n		- *\"PVWattsBatteryResidential\"*\n\n		- *\"PVWattsBatteryThirdParty\"*\n\n		- *\"PVWattsAllEquityPartnershipFlip\"*\n\n		- *\"PVWattsCommercial\"*\n\n		- *\"PVWattsCommunitySolar\"*\n\n		- *\"PVWattsHostDeveloper\"*\n\n		- *\"PVWattsLCOECalculator\"*\n\n		- *\"PVWattsLeveragedPartnershipFlip\"*\n\n		- *\"PVWattsMerchantPlant\"*\n\n		- *\"PVWattsNone\"*\n\n		- *\"PVWattsResidential\"*\n\n		- *\"PVWattsSaleLeaseback\"*\n\n		- *\"PVWattsSingleOwner\"*\n\n		- *\"PVWattsThirdParty\"*\n\n		- *\"PhysicalTroughAllEquityPartnershipFlip\"*\n\n		- *\"PhysicalTroughLCOECalculator\"*\n\n		- *\"PhysicalTroughLeveragedPartnershipFlip\"*\n\n		- *\"PhysicalTroughMerchantPlant\"*\n\n		- *\"PhysicalTroughNone\"*\n\n		- *\"PhysicalTroughSaleLeaseback\"*\n\n		- *\"PhysicalTroughSingleOwner\"*\n\n		- *\"StandaloneBatteryAllEquityPartnershipFlip\"*\n\n		- *\"StandaloneBatteryCommercial\"*\n\n		- *\"StandaloneBatteryHostDeveloper\"*\n\n		- *\"StandaloneBatteryLeveragedPartnershipFlip\"*\n\n		- *\"StandaloneBatteryMerchantPlant\"*\n\n		- *\"StandaloneBatteryResidential\"*\n\n		- *\"StandaloneBatterySaleLeaseback\"*\n\n		- *\"StandaloneBatterySingleOwner\"*\n\n		- *\"StandaloneBatteryThirdParty\"*\n\n		- *\"WindPowerAllEquityPartnershipFlip\"*\n\n		- *\"WindPowerCommercial\"*\n\n		- *\"WindPowerLCOECalculator\"*\n\n		- *\"WindPowerLeveragedPartnershipFlip\"*\n\n		- *\"WindPowerMerchantPlant\"*\n\n		- *\"WindPowerNone\"*\n\n		- *\"WindPowerResidential\"*\n\n		- *\"WindPowerSaleLeaseback\"*\n\n		- *\"WindPowerSingleOwner\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Grid_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Grid\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Grid_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Grid\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Electric grid model");


static int
GridModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Grid_Type.tp_dict = PyDict_New();
	if (!Grid_Type.tp_dict) { goto fail; }

	/// Add the Lifetime type object to Grid_Type
	if (PyType_Ready(&Lifetime_Type) < 0) { goto fail; }
	PyDict_SetItemString(Grid_Type.tp_dict,
				"Lifetime",
				(PyObject*)&Lifetime_Type);
	Py_DECREF(&Lifetime_Type);

	/// Add the SystemOutput type object to Grid_Type
	if (PyType_Ready(&SystemOutput_Type) < 0) { goto fail; }
	PyDict_SetItemString(Grid_Type.tp_dict,
				"SystemOutput",
				(PyObject*)&SystemOutput_Type);
	Py_DECREF(&SystemOutput_Type);

	/// Add the Load type object to Grid_Type
	if (PyType_Ready(&Load_Type) < 0) { goto fail; }
	PyDict_SetItemString(Grid_Type.tp_dict,
				"Load",
				(PyObject*)&Load_Type);
	Py_DECREF(&Load_Type);

	/// Add the GridLimits type object to Grid_Type
	if (PyType_Ready(&GridLimits_Type) < 0) { goto fail; }
	PyDict_SetItemString(Grid_Type.tp_dict,
				"GridLimits",
				(PyObject*)&GridLimits_Type);
	Py_DECREF(&GridLimits_Type);

	/// Add the Outputs type object to Grid_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Grid_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Grid type object to the module
	if (PyType_Ready(&Grid_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Grid",
				(PyObject*)&Grid_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot GridModule_slots[] = {
		{Py_mod_exec, GridModule_exec},
		{0, NULL},
};

static struct PyModuleDef GridModule = {
		PyModuleDef_HEAD_INIT,
		"Grid",
		module_doc,
		0,
		GridModule_methods,
		GridModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Grid(void)
{
	return PyModuleDef_Init(&GridModule);
}