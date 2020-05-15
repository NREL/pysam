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
GridLimits_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &GridLimits_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef GridLimits_methods[] = {
		{"assign",            (PyCFunction)GridLimits_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``GridLimits_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)GridLimits_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
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
	PyDoc_STR("*float*: Enable grid interconnection limit [0/1]\n\n*Info*: Enable a grid interconnection limit"),
 	NULL},
{"grid_curtailment", (getter)GridLimits_get_grid_curtailment,(setter)GridLimits_set_grid_curtailment,
	PyDoc_STR("*sequence*: Grid curtailment as energy delivery limit (first year) [MW]\n\n*Required*: False"),
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
	return PySAM_double_getter(SAM_Grid_SystemOutput_annual_energy_nget, self->data_ptr);
}

static int
SystemOutput_set_annual_energy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Grid_SystemOutput_annual_energy_nset, self->data_ptr);
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
	PyDoc_STR("*float*: Annual Energy AC (year 1) [kWh]"),
 	NULL},
{"gen", (getter)SystemOutput_get_gen,(setter)SystemOutput_set_gen,
	PyDoc_STR("*sequence*: System power generated [kW]\n\n*Info*: Lifetime system generation"),
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
Load_get_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Grid_Load_load_aget, self->data_ptr);
}

static int
Load_set_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Grid_Load_load_aset, self->data_ptr);
}

static PyGetSetDef Load_getset[] = {
{"load", (getter)Load_get_load,(setter)Load_set_load,
	PyDoc_STR("*sequence*: Electricity load (year 1) [kW]"),
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
{"annual_energy_pre_curtailment_ac", (getter)Outputs_get_annual_energy_pre_curtailment_ac,(setter)0,
	PyDoc_STR("*float*: Annual Energy AC pre-curtailment (year 1) [kWh]"),
 	NULL},
{"annual_energy_pre_interconnect_ac", (getter)Outputs_get_annual_energy_pre_interconnect_ac,(setter)0,
	PyDoc_STR("*float*: Annual Energy AC pre-interconnection (year 1) [kWh]"),
 	NULL},
{"capacity_factor_curtailment_ac", (getter)Outputs_get_capacity_factor_curtailment_ac,(setter)0,
	PyDoc_STR("*float*: Capacity factor of the curtailment (year 1) [%]"),
 	NULL},
{"capacity_factor_interconnect_ac", (getter)Outputs_get_capacity_factor_interconnect_ac,(setter)0,
	PyDoc_STR("*float*: Capacity factor of the interconnection (year 1) [%]"),
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

	PyObject* GridLimits_obj = GridLimits_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "GridLimits", GridLimits_obj);
	Py_DECREF(GridLimits_obj);

	PyObject* SystemOutput_obj = SystemOutput_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemOutput", SystemOutput_obj);
	Py_DECREF(SystemOutput_obj);

	PyObject* Load_obj = Load_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Load", Load_obj);
	Py_DECREF(Load_obj);

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
Grid_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Grid_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef Grid_methods[] = {
		{"execute",            (PyCFunction)Grid_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Grid_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Lifetime': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Grid_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Grid_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
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
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Grid", def);

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
				PyDoc_STR("default(config) -> Grid\n\nUse financial config-specific default attributes\n"
				"config options:\n\n- \"BiopowerAllEquityPartnershipFlip\"\n- \"BiopowerCommercial\"\n- \"BiopowerLCOECalculator\"\n- \"BiopowerLeveragedPartnershipFlip\"\n- \"BiopowerMerchantPlant\"\n- \"BiopowerNone\"\n- \"BiopowerSaleLeaseback\"\n- \"BiopowerSingleOwner\"\n- \"DSLFAllEquityPartnershipFlip\"\n- \"DSLFCommercial\"\n- \"DSLFLCOECalculator\"\n- \"DSLFLeveragedPartnershipFlip\"\n- \"DSLFMerchantPlant\"\n- \"DSLFNone\"\n- \"DSLFSaleLeaseback\"\n- \"DSLFSingleOwner\"\n- \"DSPTAllEquityPartnershipFlip\"\n- \"DSPTLeveragedPartnershipFlip\"\n- \"DSPTMerchantPlant\"\n- \"DSPTSaleLeaseback\"\n- \"DSPTSingleOwner\"\n- \"DishStirlingAllEquityPartnershipFlip\"\n- \"DishStirlingCommercial\"\n- \"DishStirlingLCOECalculator\"\n- \"DishStirlingLeveragedPartnershipFlip\"\n- \"DishStirlingMerchantPlant\"\n- \"DishStirlingNone\"\n- \"DishStirlingSaleLeaseback\"\n- \"DishStirlingSingleOwner\"\n- \"FlatPlatePVAllEquityPartnershipFlip\"\n- \"FlatPlatePVCommercial\"\n- \"FlatPlatePVHostDeveloper\"\n- \"FlatPlatePVLCOECalculator\"\n- \"FlatPlatePVLeveragedPartnershipFlip\"\n- \"FlatPlatePVMerchantPlant\"\n- \"FlatPlatePVNone\"\n- \"FlatPlatePVResidential\"\n- \"FlatPlatePVSaleLeaseback\"\n- \"FlatPlatePVSingleOwner\"\n- \"FlatPlatePVThirdParty\"\n- \"FuelCellCommercial\"\n- \"FuelCellSingleOwner\"\n- \"GenericBatteryAllEquityPartnershipFlip\"\n- \"GenericBatteryCommercial\"\n- \"GenericBatteryHostDeveloper\"\n- \"GenericBatteryLeveragedPartnershipFlip\"\n- \"GenericBatteryMerchantPlant\"\n- \"GenericBatteryResidential\"\n- \"GenericBatterySaleLeaseback\"\n- \"GenericBatterySingleOwner\"\n- \"GenericBatteryThirdParty\"\n- \"GenericCSPSystemAllEquityPartnershipFlip\"\n- \"GenericCSPSystemCommercial\"\n- \"GenericCSPSystemLCOECalculator\"\n- \"GenericCSPSystemLeveragedPartnershipFlip\"\n- \"GenericCSPSystemMerchantPlant\"\n- \"GenericCSPSystemNone\"\n- \"GenericCSPSystemSaleLeaseback\"\n- \"GenericCSPSystemSingleOwner\"\n- \"GenericSystemAllEquityPartnershipFlip\"\n- \"GenericSystemCommercial\"\n- \"GenericSystemHostDeveloper\"\n- \"GenericSystemLCOECalculator\"\n- \"GenericSystemLeveragedPartnershipFlip\"\n- \"GenericSystemMerchantPlant\"\n- \"GenericSystemNone\"\n- \"GenericSystemResidential\"\n- \"GenericSystemSaleLeaseback\"\n- \"GenericSystemSingleOwner\"\n- \"GenericSystemThirdParty\"\n- \"GeothermalPowerAllEquityPartnershipFlip\"\n- \"GeothermalPowerLCOECalculator\"\n- \"GeothermalPowerLeveragedPartnershipFlip\"\n- \"GeothermalPowerMerchantPlant\"\n- \"GeothermalPowerNone\"\n- \"GeothermalPowerSaleLeaseback\"\n- \"GeothermalPowerSingleOwner\"\n- \"HighXConcentratingPVAllEquityPartnershipFlip\"\n- \"HighXConcentratingPVLCOECalculator\"\n- \"HighXConcentratingPVLeveragedPartnershipFlip\"\n- \"HighXConcentratingPVMerchantPlant\"\n- \"HighXConcentratingPVNone\"\n- \"HighXConcentratingPVSaleLeaseback\"\n- \"HighXConcentratingPVSingleOwner\"\n- \"MSLFAllEquityPartnershipFlip\"\n- \"MSLFCommercial\"\n- \"MSLFLCOECalculator\"\n- \"MSLFLeveragedPartnershipFlip\"\n- \"MSLFMerchantPlant\"\n- \"MSLFNone\"\n- \"MSLFSaleLeaseback\"\n- \"MSLFSingleOwner\"\n- \"MSPTAllEquityPartnershipFlip\"\n- \"MSPTLeveragedPartnershipFlip\"\n- \"MSPTMerchantPlant\"\n- \"MSPTSaleLeaseback\"\n- \"MSPTSingleOwner\"\n- \"PVBatteryAllEquityPartnershipFlip\"\n- \"PVBatteryCommercial\"\n- \"PVBatteryHostDeveloper\"\n- \"PVBatteryLeveragedPartnershipFlip\"\n- \"PVBatteryMerchantPlant\"\n- \"PVBatteryResidential\"\n- \"PVBatterySaleLeaseback\"\n- \"PVBatterySingleOwner\"\n- \"PVBatteryThirdParty\"\n- \"PVWattsBatteryCommercial\"\n- \"PVWattsBatteryHostDeveloper\"\n- \"PVWattsBatteryResidential\"\n- \"PVWattsBatteryThirdParty\"\n- \"PVWattsAllEquityPartnershipFlip\"\n- \"PVWattsCommercial\"\n- \"PVWattsHostDeveloper\"\n- \"PVWattsLCOECalculator\"\n- \"PVWattsLeveragedPartnershipFlip\"\n- \"PVWattsMerchantPlant\"\n- \"PVWattsNone\"\n- \"PVWattsResidential\"\n- \"PVWattsSaleLeaseback\"\n- \"PVWattsSingleOwner\"\n- \"PVWattsThirdParty\"\n- \"PhysicalTroughAllEquityPartnershipFlip\"\n- \"PhysicalTroughCommercial\"\n- \"PhysicalTroughLCOECalculator\"\n- \"PhysicalTroughLeveragedPartnershipFlip\"\n- \"PhysicalTroughMerchantPlant\"\n- \"PhysicalTroughNone\"\n- \"PhysicalTroughSaleLeaseback\"\n- \"PhysicalTroughSingleOwner\"\n- \"WindPowerAllEquityPartnershipFlip\"\n- \"WindPowerCommercial\"\n- \"WindPowerLCOECalculator\"\n- \"WindPowerLeveragedPartnershipFlip\"\n- \"WindPowerMerchantPlant\"\n- \"WindPowerNone\"\n- \"WindPowerResidential\"\n- \"WindPowerSaleLeaseback\"\n- \"WindPowerSingleOwner\"")},
		{"wrap",             Grid_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Grid\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   Grid_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Grid\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
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

	/// Add the GridLimits type object to Grid_Type
	if (PyType_Ready(&GridLimits_Type) < 0) { goto fail; }
	PyDict_SetItemString(Grid_Type.tp_dict,
				"GridLimits",
				(PyObject*)&GridLimits_Type);
	Py_DECREF(&GridLimits_Type);

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