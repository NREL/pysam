#include <Python.h>

#include <SAM_Fuelcell.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Lifetime Group
 */ 

static PyTypeObject Lifetime_Type;

static PyObject *
Lifetime_new(SAM_Fuelcell data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Fuelcell", "Lifetime")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Fuelcell", "Lifetime")){
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
	return PySAM_double_getter(SAM_Fuelcell_Lifetime_analysis_period_nget, self->data_ptr);
}

static int
Lifetime_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_Lifetime_analysis_period_nset, self->data_ptr);
}

static PyObject *
Lifetime_get_system_use_lifetime_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_Lifetime_system_use_lifetime_output_nget, self->data_ptr);
}

static int
Lifetime_set_system_use_lifetime_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_Lifetime_system_use_lifetime_output_nset, self->data_ptr);
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
		"Fuelcell.Lifetime",             /*tp_name*/
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
 * Common Group
 */ 

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_Fuelcell data_ptr)
{
	PyObject* new_obj = Common_Type.tp_alloc(&Common_Type,0);

	VarGroupObject* Common_obj = (VarGroupObject*)new_obj;

	Common_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Common methods */

static PyObject *
Common_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Fuelcell", "Common")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Common_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Common_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Fuelcell", "Common")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Common_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Common_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Common_methods[] = {
		{"assign",            (PyCFunction)Common_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Common_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Common_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Common_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Common_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Common_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_Common_annual_energy_nget, self->data_ptr);
}

static int
Common_set_annual_energy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_Common_annual_energy_nset, self->data_ptr);
}

static PyObject *
Common_get_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_Common_capacity_factor_nget, self->data_ptr);
}

static int
Common_set_capacity_factor(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_Common_capacity_factor_nset, self->data_ptr);
}

static PyObject *
Common_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_Common_gen_aget, self->data_ptr);
}

static int
Common_set_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Fuelcell_Common_gen_aset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"annual_energy", (getter)Common_get_annual_energy,(setter)Common_set_annual_energy,
	PyDoc_STR("*float*: Annual Energy [kWh]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"capacity_factor", (getter)Common_get_capacity_factor,(setter)Common_set_capacity_factor,
	PyDoc_STR("*float*: Capacity factor [%]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"gen", (getter)Common_get_gen,(setter)Common_set_gen,
	PyDoc_STR("*sequence*: System power generated [kW]\n\n**Info:**\nLifetime system generation\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Fuelcell.Common",             /*tp_name*/
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
		Common_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Common_getset,          /*tp_getset*/
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
Load_new(SAM_Fuelcell data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Fuelcell", "Load")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Fuelcell", "Load")){
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
Load_get_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_Load_load_aget, self->data_ptr);
}

static int
Load_set_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Fuelcell_Load_load_aset, self->data_ptr);
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
		"Fuelcell.Load",             /*tp_name*/
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
 * FuelCell Group
 */ 

static PyTypeObject FuelCell_Type;

static PyObject *
FuelCell_new(SAM_Fuelcell data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Fuelcell", "FuelCell")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Fuelcell", "FuelCell")){
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
FuelCell_get_dispatch_manual_fuelcellcharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_FuelCell_dispatch_manual_fuelcellcharge_aget, self->data_ptr);
}

static int
FuelCell_set_dispatch_manual_fuelcellcharge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Fuelcell_FuelCell_dispatch_manual_fuelcellcharge_aset, self->data_ptr);
}

static PyObject *
FuelCell_get_dispatch_manual_fuelcelldischarge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_FuelCell_dispatch_manual_fuelcelldischarge_aget, self->data_ptr);
}

static int
FuelCell_set_dispatch_manual_fuelcelldischarge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Fuelcell_FuelCell_dispatch_manual_fuelcelldischarge_aset, self->data_ptr);
}

static PyObject *
FuelCell_get_dispatch_manual_percent_fc_discharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_FuelCell_dispatch_manual_percent_fc_discharge_aget, self->data_ptr);
}

static int
FuelCell_set_dispatch_manual_percent_fc_discharge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Fuelcell_FuelCell_dispatch_manual_percent_fc_discharge_aset, self->data_ptr);
}

static PyObject *
FuelCell_get_dispatch_manual_sched(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Fuelcell_FuelCell_dispatch_manual_sched_mget, self->data_ptr);
}

static int
FuelCell_set_dispatch_manual_sched(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Fuelcell_FuelCell_dispatch_manual_sched_mset, self->data_ptr);
}

static PyObject *
FuelCell_get_dispatch_manual_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Fuelcell_FuelCell_dispatch_manual_sched_weekend_mget, self->data_ptr);
}

static int
FuelCell_set_dispatch_manual_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Fuelcell_FuelCell_dispatch_manual_sched_weekend_mset, self->data_ptr);
}

static PyObject *
FuelCell_get_dispatch_manual_units_fc_discharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_FuelCell_dispatch_manual_units_fc_discharge_aget, self->data_ptr);
}

static int
FuelCell_set_dispatch_manual_units_fc_discharge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Fuelcell_FuelCell_dispatch_manual_units_fc_discharge_aset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_availability_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Fuelcell_FuelCell_fuelcell_availability_schedule_mget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_availability_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Fuelcell_FuelCell_fuelcell_availability_schedule_mset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_degradation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_degradation_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_degradation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_degradation_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_degradation_restart(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_degradation_restart_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_degradation_restart(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_degradation_restart_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_degradation_restart_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_degradation_restart_schedule_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_degradation_restart_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_degradation_restart_schedule_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_degradation_restarts_per_year(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_degradation_restarts_per_year_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_degradation_restarts_per_year(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_degradation_restarts_per_year_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_dispatch(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_FuelCell_fuelcell_dispatch_aget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_dispatch(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Fuelcell_FuelCell_fuelcell_dispatch_aset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_dispatch_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_dispatch_choice_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_dispatch_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_dispatch_choice_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_dynamic_response_down(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_dynamic_response_down_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_dynamic_response_down(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_dynamic_response_down_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_dynamic_response_up(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_dynamic_response_up_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_dynamic_response_up(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_dynamic_response_up_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Fuelcell_FuelCell_fuelcell_efficiency_mget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_efficiency(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Fuelcell_FuelCell_fuelcell_efficiency_mset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_efficiency_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_efficiency_choice_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_efficiency_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_efficiency_choice_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_fixed_pct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_fixed_pct_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_fixed_pct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_fixed_pct_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_fuel_available(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_fuel_available_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_fuel_available(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_fuel_available_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_fuel_price(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_fuel_price_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_fuel_price(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_fuel_price_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_fuel_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_fuel_type_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_fuel_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_fuel_type_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_is_started(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_is_started_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_is_started(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_is_started_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_lhv(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_lhv_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_lhv(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_lhv_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_number_of_units(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_number_of_units_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_number_of_units(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_number_of_units_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_operation_options(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_operation_options_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_operation_options(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_operation_options_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_replacement_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_replacement_option_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_replacement_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_replacement_option_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_replacement_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_replacement_percent_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_replacement_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_replacement_percent_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_replacement_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_FuelCell_fuelcell_replacement_schedule_aget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_replacement_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Fuelcell_FuelCell_fuelcell_replacement_schedule_aset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_shutdown_time(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_shutdown_time_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_shutdown_time(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_shutdown_time_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_startup_time(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_startup_time_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_startup_time(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_startup_time_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_type_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_type_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_unit_max_power(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_unit_max_power_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_unit_max_power(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_unit_max_power_nset, self->data_ptr);
}

static PyObject *
FuelCell_get_fuelcell_unit_min_power(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_FuelCell_fuelcell_unit_min_power_nget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_unit_min_power(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Fuelcell_FuelCell_fuelcell_unit_min_power_nset, self->data_ptr);
}

static PyGetSetDef FuelCell_getset[] = {
{"dispatch_manual_fuelcellcharge", (getter)FuelCell_get_dispatch_manual_fuelcellcharge,(setter)FuelCell_set_dispatch_manual_fuelcellcharge,
	PyDoc_STR("*sequence*: Periods 1-6 charging allowed?"),
 	NULL},
{"dispatch_manual_fuelcelldischarge", (getter)FuelCell_get_dispatch_manual_fuelcelldischarge,(setter)FuelCell_set_dispatch_manual_fuelcelldischarge,
	PyDoc_STR("*sequence*: Periods 1-6 discharging allowed?\n\nThe value of the following variables depends on ``dispatch_manual_fuelcelldischarge``:\n\n\t - dispatch_manual_percent_fc_discharge\n\t - dispatch_manual_units_fc_discharge\n"),
 	NULL},
{"dispatch_manual_percent_fc_discharge", (getter)FuelCell_get_dispatch_manual_percent_fc_discharge,(setter)FuelCell_set_dispatch_manual_percent_fc_discharge,
	PyDoc_STR("*sequence*: Periods 1-6 percent of max fuelcell output\n\nThe value of ``dispatch_manual_percent_fc_discharge`` depends on the following variables:\n\n\t - dispatch_manual_fuelcelldischarge\n"),
 	NULL},
{"dispatch_manual_sched", (getter)FuelCell_get_dispatch_manual_sched,(setter)FuelCell_set_dispatch_manual_sched,
	PyDoc_STR("*sequence[sequence]*: Dispatch schedule for weekday"),
 	NULL},
{"dispatch_manual_sched_weekend", (getter)FuelCell_get_dispatch_manual_sched_weekend,(setter)FuelCell_set_dispatch_manual_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Dispatch schedule for weekend"),
 	NULL},
{"dispatch_manual_units_fc_discharge", (getter)FuelCell_get_dispatch_manual_units_fc_discharge,(setter)FuelCell_set_dispatch_manual_units_fc_discharge,
	PyDoc_STR("*sequence*: Periods 1-6 number of fuel cell units?\n\nThe value of ``dispatch_manual_units_fc_discharge`` depends on the following variables:\n\n\t - dispatch_manual_fuelcelldischarge\n"),
 	NULL},
{"fuelcell_availability_schedule", (getter)FuelCell_get_fuelcell_availability_schedule,(setter)FuelCell_set_fuelcell_availability_schedule,
	PyDoc_STR("*sequence[sequence]*: Fuel cell availability schedule  [Column 1: Hour of year start shutdown/Column 2: Hours duration of shutdown ]"),
 	NULL},
{"fuelcell_degradation", (getter)FuelCell_get_fuelcell_degradation,(setter)FuelCell_set_fuelcell_degradation,
	PyDoc_STR("*float*: Fuel cell degradation per hour [kW/h]\n\nThe value of ``fuelcell_degradation`` depends on the following variables:\n\n\t - fuelcell_unit_max_power\n"),
 	NULL},
{"fuelcell_degradation_restart", (getter)FuelCell_get_fuelcell_degradation_restart,(setter)FuelCell_set_fuelcell_degradation_restart,
	PyDoc_STR("*float*: Fuel cell degradation at restart [kW]"),
 	NULL},
{"fuelcell_degradation_restart_schedule", (getter)FuelCell_get_fuelcell_degradation_restart_schedule,(setter)FuelCell_set_fuelcell_degradation_restart_schedule,
	PyDoc_STR("*float*: Fuel cell enable scheduled restarts [0/1]"),
 	NULL},
{"fuelcell_degradation_restarts_per_year", (getter)FuelCell_get_fuelcell_degradation_restarts_per_year,(setter)FuelCell_set_fuelcell_degradation_restarts_per_year,
	PyDoc_STR("*float*: Fuel cell scheduled restarts per year"),
 	NULL},
{"fuelcell_dispatch", (getter)FuelCell_get_fuelcell_dispatch,(setter)FuelCell_set_fuelcell_dispatch,
	PyDoc_STR("*sequence*: Fuel cell dispatch input per unit [kW]\n\nThe value of ``fuelcell_dispatch`` depends on the following variables:\n\n\t - fuelcell_unit_max_power\n"),
 	NULL},
{"fuelcell_dispatch_choice", (getter)FuelCell_get_fuelcell_dispatch_choice,(setter)FuelCell_set_fuelcell_dispatch_choice,
	PyDoc_STR("*float*: Fuel cell dispatch choice [0/1/2]"),
 	NULL},
{"fuelcell_dynamic_response_down", (getter)FuelCell_get_fuelcell_dynamic_response_down,(setter)FuelCell_set_fuelcell_dynamic_response_down,
	PyDoc_STR("*float*: Fuel cell ramp rate limit down [kW/h]\n\nThe value of ``fuelcell_dynamic_response_down`` depends on the following variables:\n\n\t - fuelcell_number_of_units\n\t - fuelcell_unit_max_power\n"),
 	NULL},
{"fuelcell_dynamic_response_up", (getter)FuelCell_get_fuelcell_dynamic_response_up,(setter)FuelCell_set_fuelcell_dynamic_response_up,
	PyDoc_STR("*float*: Fuel cell ramp rate limit up [kW/h]\n\nThe value of ``fuelcell_dynamic_response_up`` depends on the following variables:\n\n\t - fuelcell_number_of_units\n\t - fuelcell_unit_max_power\n"),
 	NULL},
{"fuelcell_efficiency", (getter)FuelCell_get_fuelcell_efficiency,(setter)FuelCell_set_fuelcell_efficiency,
	PyDoc_STR("*sequence[sequence]*: Fuel cell efficiency table "),
 	NULL},
{"fuelcell_efficiency_choice", (getter)FuelCell_get_fuelcell_efficiency_choice,(setter)FuelCell_set_fuelcell_efficiency_choice,
	PyDoc_STR("*float*: Fuel cell efficiency definition choice  [0/1]\n\n**Options:**\n0=OriginalNameplate,1=DegradedNameplate"),
 	NULL},
{"fuelcell_fixed_pct", (getter)FuelCell_get_fuelcell_fixed_pct,(setter)FuelCell_set_fuelcell_fixed_pct,
	PyDoc_STR("*float*: Fuel cell fixed operation percent [%]"),
 	NULL},
{"fuelcell_fuel_available", (getter)FuelCell_get_fuelcell_fuel_available,(setter)FuelCell_set_fuelcell_fuel_available,
	PyDoc_STR("*float*: Fuel cell available fuel quantity [MCf]\n\nThe value of ``fuelcell_fuel_available`` depends on the following variables:\n\n\t - fuelcell_fuel_type\n"),
 	NULL},
{"fuelcell_fuel_price", (getter)FuelCell_get_fuelcell_fuel_price,(setter)FuelCell_set_fuelcell_fuel_price,
	PyDoc_STR("*float*: Fuel cell price [$/MCf]"),
 	NULL},
{"fuelcell_fuel_type", (getter)FuelCell_get_fuelcell_fuel_type,(setter)FuelCell_set_fuelcell_fuel_type,
	PyDoc_STR("*float*: Fuel cell type [0/1]\n\nThe value of the following variables depends on ``fuelcell_fuel_type``:\n\n\t - fuelcell_fuel_available\n\t - fuelcell_lhv\n"),
 	NULL},
{"fuelcell_is_started", (getter)FuelCell_get_fuelcell_is_started,(setter)FuelCell_set_fuelcell_is_started,
	PyDoc_STR("*float*: Fuel cell is started [0/1]"),
 	NULL},
{"fuelcell_lhv", (getter)FuelCell_get_fuelcell_lhv,(setter)FuelCell_set_fuelcell_lhv,
	PyDoc_STR("*float*: Fuel cell lower heating value [Btu/ft3]\n\nThe value of ``fuelcell_lhv`` depends on the following variables:\n\n\t - fuelcell_fuel_type\n"),
 	NULL},
{"fuelcell_number_of_units", (getter)FuelCell_get_fuelcell_number_of_units,(setter)FuelCell_set_fuelcell_number_of_units,
	PyDoc_STR("*float*: Fuel cell number of units\n\nThe value of the following variables depends on ``fuelcell_number_of_units``:\n\n\t - fuelcell_dynamic_response_down\n\t - fuelcell_dynamic_response_up\n"),
 	NULL},
{"fuelcell_operation_options", (getter)FuelCell_get_fuelcell_operation_options,(setter)FuelCell_set_fuelcell_operation_options,
	PyDoc_STR("*float*: Fuel cell turn off options [0/1]"),
 	NULL},
{"fuelcell_replacement_option", (getter)FuelCell_get_fuelcell_replacement_option,(setter)FuelCell_set_fuelcell_replacement_option,
	PyDoc_STR("*float*: Fuel cell replacement option [0/1/2]"),
 	NULL},
{"fuelcell_replacement_percent", (getter)FuelCell_get_fuelcell_replacement_percent,(setter)FuelCell_set_fuelcell_replacement_percent,
	PyDoc_STR("*float*: Fuel cell replace at percentage"),
 	NULL},
{"fuelcell_replacement_schedule", (getter)FuelCell_get_fuelcell_replacement_schedule,(setter)FuelCell_set_fuelcell_replacement_schedule,
	PyDoc_STR("*sequence*: Fuel cell replace on schedule"),
 	NULL},
{"fuelcell_shutdown_time", (getter)FuelCell_get_fuelcell_shutdown_time,(setter)FuelCell_set_fuelcell_shutdown_time,
	PyDoc_STR("*float*: Fuel cell shutdown hours [hours]"),
 	NULL},
{"fuelcell_startup_time", (getter)FuelCell_get_fuelcell_startup_time,(setter)FuelCell_set_fuelcell_startup_time,
	PyDoc_STR("*float*: Fuel cell startup hours [hours]"),
 	NULL},
{"fuelcell_type", (getter)FuelCell_get_fuelcell_type,(setter)FuelCell_set_fuelcell_type,
	PyDoc_STR("*float*: Fuel cell type [0/1/2]"),
 	NULL},
{"fuelcell_unit_max_power", (getter)FuelCell_get_fuelcell_unit_max_power,(setter)FuelCell_set_fuelcell_unit_max_power,
	PyDoc_STR("*float*: Fuel cell max power per unit [kW]\n\nThe value of the following variables depends on ``fuelcell_unit_max_power``:\n\n\t - fuelcell_degradation\n\t - fuelcell_dispatch\n\t - fuelcell_dynamic_response_down\n\t - fuelcell_dynamic_response_up\n\t - fuelcell_unit_min_power\n"),
 	NULL},
{"fuelcell_unit_min_power", (getter)FuelCell_get_fuelcell_unit_min_power,(setter)FuelCell_set_fuelcell_unit_min_power,
	PyDoc_STR("*float*: Fuel cell min power per unit [kW]\n\nThe value of ``fuelcell_unit_min_power`` depends on the following variables:\n\n\t - fuelcell_unit_max_power\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FuelCell_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Fuelcell.FuelCell",             /*tp_name*/
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
 * Outputs Group
 */ 

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Fuelcell data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Fuelcell", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Fuelcell", "Outputs")){
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
Outputs_get_annual_energy_distribution_time(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Fuelcell_Outputs_annual_energy_distribution_time_mget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution_time_fc(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Fuelcell_Outputs_annual_energy_distribution_time_fc_mget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_fuel_usage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_Outputs_annual_fuel_usage_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_fuel_usage_lifetime(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_Outputs_annual_fuel_usage_lifetime_aget, self->data_ptr);
}

static PyObject *
Outputs_get_fuelcell_annual_energy_discharged(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_Outputs_fuelcell_annual_energy_discharged_aget, self->data_ptr);
}

static PyObject *
Outputs_get_fuelcell_electrical_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_Outputs_fuelcell_electrical_efficiency_aget, self->data_ptr);
}

static PyObject *
Outputs_get_fuelcell_fuel_consumption_mcf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_Outputs_fuelcell_fuel_consumption_mcf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_fuelcell_percent_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_Outputs_fuelcell_percent_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_fuelcell_power(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_Outputs_fuelcell_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_fuelcell_power_max_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_Outputs_fuelcell_power_max_percent_aget, self->data_ptr);
}

static PyObject *
Outputs_get_fuelcell_power_thermal(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_Outputs_fuelcell_power_thermal_aget, self->data_ptr);
}

static PyObject *
Outputs_get_fuelcell_replacement(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_Outputs_fuelcell_replacement_aget, self->data_ptr);
}

static PyObject *
Outputs_get_fuelcell_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_Outputs_fuelcell_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_fuelcell_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_Outputs_fuelcell_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Fuelcell_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_heat_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Fuelcell_Outputs_system_heat_rate_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_energy_distribution_time", (getter)Outputs_get_annual_energy_distribution_time,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Annual energy production as function of time [kW]"),
 	NULL},
{"annual_energy_distribution_time_fc", (getter)Outputs_get_annual_energy_distribution_time_fc,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Annual energy production (PV + battery + fuel cell) as function of Time"),
 	NULL},
{"annual_fuel_usage", (getter)Outputs_get_annual_fuel_usage,(setter)0,
	PyDoc_STR("*float*: Annual Fuel Usage [kWht]"),
 	NULL},
{"annual_fuel_usage_lifetime", (getter)Outputs_get_annual_fuel_usage_lifetime,(setter)0,
	PyDoc_STR("*sequence*: Annual Fuel Usage (lifetime) [kWht]"),
 	NULL},
{"fuelcell_annual_energy_discharged", (getter)Outputs_get_fuelcell_annual_energy_discharged,(setter)0,
	PyDoc_STR("*sequence*: Fuel cell annual energy discharged [kWh]"),
 	NULL},
{"fuelcell_electrical_efficiency", (getter)Outputs_get_fuelcell_electrical_efficiency,(setter)0,
	PyDoc_STR("*sequence*: Fuel cell electrical efficiency [%]"),
 	NULL},
{"fuelcell_fuel_consumption_mcf", (getter)Outputs_get_fuelcell_fuel_consumption_mcf,(setter)0,
	PyDoc_STR("*sequence*: Fuel cell fuel consumption [MCf]"),
 	NULL},
{"fuelcell_percent_load", (getter)Outputs_get_fuelcell_percent_load,(setter)0,
	PyDoc_STR("*sequence*: Fuel cell percent load [%]"),
 	NULL},
{"fuelcell_power", (getter)Outputs_get_fuelcell_power,(setter)0,
	PyDoc_STR("*sequence*: Electricity from fuel cell [kW]"),
 	NULL},
{"fuelcell_power_max_percent", (getter)Outputs_get_fuelcell_power_max_percent,(setter)0,
	PyDoc_STR("*sequence*: Fuel cell max power percent available [%]"),
 	NULL},
{"fuelcell_power_thermal", (getter)Outputs_get_fuelcell_power_thermal,(setter)0,
	PyDoc_STR("*sequence*: Heat from fuel cell [kWt]"),
 	NULL},
{"fuelcell_replacement", (getter)Outputs_get_fuelcell_replacement,(setter)0,
	PyDoc_STR("*sequence*: Fuel cell replacements per year [number/year]"),
 	NULL},
{"fuelcell_to_grid", (getter)Outputs_get_fuelcell_to_grid,(setter)0,
	PyDoc_STR("*sequence*: Electricity to grid from fuel cell [kW]"),
 	NULL},
{"fuelcell_to_load", (getter)Outputs_get_fuelcell_to_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity to load from fuel cell [kW]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System power generated [kW]"),
 	NULL},
{"system_heat_rate", (getter)Outputs_get_system_heat_rate,(setter)0,
	PyDoc_STR("*float*: Heat rate conversion factor (MMBTUs/MWhe) [MMBTUs/MWhe]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Fuelcell.Outputs",             /*tp_name*/
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
 * Fuelcell
 */

static PyTypeObject Fuelcell_Type;

static CmodObject *
newFuelcellObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Fuelcell_Type);

	PySAM_TECH_ATTR()

	PyObject* Lifetime_obj = Lifetime_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Lifetime", Lifetime_obj);
	Py_DECREF(Lifetime_obj);

	PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

	PyObject* Load_obj = Load_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Load", Load_obj);
	Py_DECREF(Load_obj);

	PyObject* FuelCell_obj = FuelCell_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FuelCell", FuelCell_obj);
	Py_DECREF(FuelCell_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Fuelcell methods */

static void
Fuelcell_dealloc(CmodObject *self)
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
Fuelcell_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Fuelcell_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Fuelcell_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Fuelcell"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Fuelcell_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Fuelcell"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Fuelcell_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Fuelcell_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Fuelcell_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Fuelcell_methods[] = {
		{"execute",           (PyCFunction)Fuelcell_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Fuelcell_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Lifetime': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Fuelcell_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Lifetime': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Fuelcell_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Fuelcell_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Fuelcell_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Fuelcell_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Fuelcell_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Fuelcell_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Fuelcell",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Fuelcell_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Fuelcell_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Fuelcell_getattro, /*tp_getattro*/
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
		Fuelcell_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Fuelcell object */

static PyObject *
Fuelcell_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newFuelcellObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Fuelcell_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newFuelcellObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Fuelcell_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newFuelcellObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Fuelcell", def) < 0) {
		Fuelcell_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Fuelcell_from_existing(PyObject *self, PyObject *args)
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

	rv = newFuelcellObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Fuelcell", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef FuelcellModule_methods[] = {
		{"new",             Fuelcell_new,         METH_VARARGS,
				PyDoc_STR("new() -> Fuelcell")},
		{"default",             Fuelcell_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Fuelcell\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"FuelCellCommercial\"*\n\n		- *\"FuelCellSingleOwner\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Fuelcell_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Fuelcell\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Fuelcell_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Fuelcell\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Fuel cell model");


static int
FuelcellModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Fuelcell_Type.tp_dict = PyDict_New();
	if (!Fuelcell_Type.tp_dict) { goto fail; }

	/// Add the Lifetime type object to Fuelcell_Type
	if (PyType_Ready(&Lifetime_Type) < 0) { goto fail; }
	PyDict_SetItemString(Fuelcell_Type.tp_dict,
				"Lifetime",
				(PyObject*)&Lifetime_Type);
	Py_DECREF(&Lifetime_Type);

	/// Add the Common type object to Fuelcell_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(Fuelcell_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the Load type object to Fuelcell_Type
	if (PyType_Ready(&Load_Type) < 0) { goto fail; }
	PyDict_SetItemString(Fuelcell_Type.tp_dict,
				"Load",
				(PyObject*)&Load_Type);
	Py_DECREF(&Load_Type);

	/// Add the FuelCell type object to Fuelcell_Type
	if (PyType_Ready(&FuelCell_Type) < 0) { goto fail; }
	PyDict_SetItemString(Fuelcell_Type.tp_dict,
				"FuelCell",
				(PyObject*)&FuelCell_Type);
	Py_DECREF(&FuelCell_Type);

	/// Add the Outputs type object to Fuelcell_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Fuelcell_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Fuelcell type object to the module
	if (PyType_Ready(&Fuelcell_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Fuelcell",
				(PyObject*)&Fuelcell_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot FuelcellModule_slots[] = {
		{Py_mod_exec, FuelcellModule_exec},
		{0, NULL},
};

static struct PyModuleDef FuelcellModule = {
		PyModuleDef_HEAD_INIT,
		"Fuelcell",
		module_doc,
		0,
		FuelcellModule_methods,
		FuelcellModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Fuelcell(void)
{
	return PyModuleDef_Init(&FuelcellModule);
}