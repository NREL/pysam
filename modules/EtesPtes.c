#include <Python.h>

#include <SAM_EtesPtes.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * SolarResource Group
 */ 

static PyTypeObject SolarResource_Type;

static PyObject *
SolarResource_new(SAM_EtesPtes data_ptr)
{
	PyObject* new_obj = SolarResource_Type.tp_alloc(&SolarResource_Type,0);

	VarGroupObject* SolarResource_obj = (VarGroupObject*)new_obj;

	SolarResource_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SolarResource methods */

static PyObject *
SolarResource_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesPtes", "SolarResource")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SolarResource_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SolarResource_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "EtesPtes", "SolarResource")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SolarResource_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SolarResource_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SolarResource_methods[] = {
		{"assign",            (PyCFunction)SolarResource_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SolarResource_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SolarResource_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SolarResource_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SolarResource_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SolarResource_get_solar_resource_file(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_EtesPtes_SolarResource_solar_resource_file_sget, self->data_ptr);
}

static int
SolarResource_set_solar_resource_file(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_EtesPtes_SolarResource_solar_resource_file_sset, self->data_ptr);
}

static PyGetSetDef SolarResource_getset[] = {
{"solar_resource_file", (getter)SolarResource_get_solar_resource_file,(setter)SolarResource_set_solar_resource_file,
	PyDoc_STR("*str*: Local weather file path\n\n**Constraints:**\nLOCAL_FILE\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SolarResource_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesPtes.SolarResource",             /*tp_name*/
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
		SolarResource_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SolarResource_getset,          /*tp_getset*/
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
 * SystemControl Group
 */ 

static PyTypeObject SystemControl_Type;

static PyObject *
SystemControl_new(SAM_EtesPtes data_ptr)
{
	PyObject* new_obj = SystemControl_Type.tp_alloc(&SystemControl_Type,0);

	VarGroupObject* SystemControl_obj = (VarGroupObject*)new_obj;

	SystemControl_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SystemControl methods */

static PyObject *
SystemControl_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesPtes", "SystemControl")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemControl_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SystemControl_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "EtesPtes", "SystemControl")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemControl_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SystemControl_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SystemControl_methods[] = {
		{"assign",            (PyCFunction)SystemControl_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SystemControl_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SystemControl_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SystemControl_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SystemControl_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemControl_get_bop_par(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_bop_par_nget, self->data_ptr);
}

static int
SystemControl_set_bop_par(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_bop_par_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_bop_par_0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_bop_par_0_nget, self->data_ptr);
}

static int
SystemControl_set_bop_par_0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_bop_par_0_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_bop_par_1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_bop_par_1_nget, self->data_ptr);
}

static int
SystemControl_set_bop_par_1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_bop_par_1_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_bop_par_2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_bop_par_2_nget, self->data_ptr);
}

static int
SystemControl_set_bop_par_2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_bop_par_2_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_bop_par_f(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_bop_par_f_nget, self->data_ptr);
}

static int
SystemControl_set_bop_par_f(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_bop_par_f_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_csu_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_disp_csu_cost_nget, self->data_ptr);
}

static int
SystemControl_set_disp_csu_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_disp_csu_cost_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_down_time_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_disp_down_time_min_nget, self->data_ptr);
}

static int
SystemControl_set_disp_down_time_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_disp_down_time_min_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_frequency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_disp_frequency_nget, self->data_ptr);
}

static int
SystemControl_set_disp_frequency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_disp_frequency_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_horizon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_disp_horizon_nget, self->data_ptr);
}

static int
SystemControl_set_disp_horizon(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_disp_horizon_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_hsu_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_disp_hsu_cost_nget, self->data_ptr);
}

static int
SystemControl_set_disp_hsu_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_disp_hsu_cost_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_max_iter(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_disp_max_iter_nget, self->data_ptr);
}

static int
SystemControl_set_disp_max_iter(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_disp_max_iter_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_mip_gap(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_disp_mip_gap_nget, self->data_ptr);
}

static int
SystemControl_set_disp_mip_gap(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_disp_mip_gap_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_pen_delta_w(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_disp_pen_delta_w_nget, self->data_ptr);
}

static int
SystemControl_set_disp_pen_delta_w(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_disp_pen_delta_w_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_reporting(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_disp_reporting_nget, self->data_ptr);
}

static int
SystemControl_set_disp_reporting(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_disp_reporting_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_spec_bb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_disp_spec_bb_nget, self->data_ptr);
}

static int
SystemControl_set_disp_spec_bb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_disp_spec_bb_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_spec_presolve(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_disp_spec_presolve_nget, self->data_ptr);
}

static int
SystemControl_set_disp_spec_presolve(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_disp_spec_presolve_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_spec_scaling(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_disp_spec_scaling_nget, self->data_ptr);
}

static int
SystemControl_set_disp_spec_scaling(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_disp_spec_scaling_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_steps_per_hour(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_disp_steps_per_hour_nget, self->data_ptr);
}

static int
SystemControl_set_disp_steps_per_hour(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_disp_steps_per_hour_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_time_weighting(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_disp_time_weighting_nget, self->data_ptr);
}

static int
SystemControl_set_disp_time_weighting(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_disp_time_weighting_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_timeout(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_disp_timeout_nget, self->data_ptr);
}

static int
SystemControl_set_disp_timeout(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_disp_timeout_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_up_time_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_disp_up_time_min_nget, self->data_ptr);
}

static int
SystemControl_set_disp_up_time_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_disp_up_time_min_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_is_dispatch(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_is_dispatch_nget, self->data_ptr);
}

static int
SystemControl_set_is_dispatch(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_is_dispatch_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_pb_fixed_par(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_pb_fixed_par_nget, self->data_ptr);
}

static int
SystemControl_set_pb_fixed_par(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_pb_fixed_par_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_sim_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_sim_type_nget, self->data_ptr);
}

static int
SystemControl_set_sim_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_sim_type_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_time_start(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_time_start_nget, self->data_ptr);
}

static int
SystemControl_set_time_start(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_time_start_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_time_steps_per_hour(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_time_steps_per_hour_nget, self->data_ptr);
}

static int
SystemControl_set_time_steps_per_hour(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_time_steps_per_hour_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_time_stop(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_time_stop_nget, self->data_ptr);
}

static int
SystemControl_set_time_stop(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_time_stop_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_vacuum_arrays(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemControl_vacuum_arrays_nget, self->data_ptr);
}

static int
SystemControl_set_vacuum_arrays(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemControl_vacuum_arrays_nset, self->data_ptr);
}

static PyGetSetDef SystemControl_getset[] = {
{"bop_par", (getter)SystemControl_get_bop_par,(setter)SystemControl_set_bop_par,
	PyDoc_STR("*float*: Balance of plant parasitic power fraction [MWe/MWcap]\n\n**Required:**\nTrue"),
 	NULL},
{"bop_par_0", (getter)SystemControl_get_bop_par_0,(setter)SystemControl_set_bop_par_0,
	PyDoc_STR("*float*: Balance of plant parasitic power fraction - const coeff\n\n**Required:**\nTrue"),
 	NULL},
{"bop_par_1", (getter)SystemControl_get_bop_par_1,(setter)SystemControl_set_bop_par_1,
	PyDoc_STR("*float*: Balance of plant parasitic power fraction - linear coeff\n\n**Required:**\nTrue"),
 	NULL},
{"bop_par_2", (getter)SystemControl_get_bop_par_2,(setter)SystemControl_set_bop_par_2,
	PyDoc_STR("*float*: Balance of plant parasitic power fraction - quadratic coeff\n\n**Required:**\nTrue"),
 	NULL},
{"bop_par_f", (getter)SystemControl_get_bop_par_f,(setter)SystemControl_set_bop_par_f,
	PyDoc_STR("*float*: Balance of plant parasitic power fraction - mult frac\n\n**Required:**\nTrue"),
 	NULL},
{"disp_csu_cost", (getter)SystemControl_get_disp_csu_cost,(setter)SystemControl_set_disp_csu_cost,
	PyDoc_STR("*float*: Cycle startup cost [$/MWe-cycle/start]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_down_time_min", (getter)SystemControl_get_disp_down_time_min,(setter)SystemControl_set_disp_down_time_min,
	PyDoc_STR("*float*: Minimum time requirement for cycle to not generate power [hr]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_frequency", (getter)SystemControl_get_disp_frequency,(setter)SystemControl_set_disp_frequency,
	PyDoc_STR("*float*: Frequency for dispatch optimization calculations [hour]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_horizon", (getter)SystemControl_get_disp_horizon,(setter)SystemControl_set_disp_horizon,
	PyDoc_STR("*float*: Time horizon for dispatch optimization [hour]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_hsu_cost", (getter)SystemControl_get_disp_hsu_cost,(setter)SystemControl_set_disp_hsu_cost,
	PyDoc_STR("*float*: Heater startup cost [$/MWe-cycle/start]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_max_iter", (getter)SystemControl_get_disp_max_iter,(setter)SystemControl_set_disp_max_iter,
	PyDoc_STR("*float*: Max number of dispatch optimization iterations\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_mip_gap", (getter)SystemControl_get_disp_mip_gap,(setter)SystemControl_set_disp_mip_gap,
	PyDoc_STR("*float*: Dispatch optimization solution tolerance\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_pen_delta_w", (getter)SystemControl_get_disp_pen_delta_w,(setter)SystemControl_set_disp_pen_delta_w,
	PyDoc_STR("*float*: Dispatch cycle production change penalty [$/MWe-change]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_reporting", (getter)SystemControl_get_disp_reporting,(setter)SystemControl_set_disp_reporting,
	PyDoc_STR("*float*: Dispatch optimization reporting level\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_spec_bb", (getter)SystemControl_get_disp_spec_bb,(setter)SystemControl_set_disp_spec_bb,
	PyDoc_STR("*float*: Dispatch optimization B&B heuristic\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_spec_presolve", (getter)SystemControl_get_disp_spec_presolve,(setter)SystemControl_set_disp_spec_presolve,
	PyDoc_STR("*float*: Dispatch optimization presolve heuristic\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_spec_scaling", (getter)SystemControl_get_disp_spec_scaling,(setter)SystemControl_set_disp_spec_scaling,
	PyDoc_STR("*float*: Dispatch optimization scaling heuristic\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_steps_per_hour", (getter)SystemControl_get_disp_steps_per_hour,(setter)SystemControl_set_disp_steps_per_hour,
	PyDoc_STR("*float*: Time steps per hour for dispatch optimization calculations\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_time_weighting", (getter)SystemControl_get_disp_time_weighting,(setter)SystemControl_set_disp_time_weighting,
	PyDoc_STR("*float*: Dispatch optimization future time discounting factor\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_timeout", (getter)SystemControl_get_disp_timeout,(setter)SystemControl_set_disp_timeout,
	PyDoc_STR("*float*: Max dispatch optimization solve duration [s]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_up_time_min", (getter)SystemControl_get_disp_up_time_min,(setter)SystemControl_set_disp_up_time_min,
	PyDoc_STR("*float*: Minimum time requirement for cycle to generate power [hr]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"is_dispatch", (getter)SystemControl_get_is_dispatch,(setter)SystemControl_set_is_dispatch,
	PyDoc_STR("*float*: Allow dispatch optimization?\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pb_fixed_par", (getter)SystemControl_get_pb_fixed_par,(setter)SystemControl_set_pb_fixed_par,
	PyDoc_STR("*float*: Fixed parasitic load that don't generate heat - runs at all times [MWe/MWcap]\n\n**Required:**\nTrue"),
 	NULL},
{"sim_type", (getter)SystemControl_get_sim_type,(setter)SystemControl_set_sim_type,
	PyDoc_STR("*float*: 1 (default): timeseries, 2: design only\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"time_start", (getter)SystemControl_get_time_start,(setter)SystemControl_set_time_start,
	PyDoc_STR("*float*: Simulation start time [s]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"time_steps_per_hour", (getter)SystemControl_get_time_steps_per_hour,(setter)SystemControl_set_time_steps_per_hour,
	PyDoc_STR("*float*: Number of simulation time steps per hour\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"time_stop", (getter)SystemControl_get_time_stop,(setter)SystemControl_set_time_stop,
	PyDoc_STR("*float*: Simulation stop time [s]\n\n**Required:**\nFalse. Automatically set to 31536000 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"vacuum_arrays", (getter)SystemControl_get_vacuum_arrays,(setter)SystemControl_set_vacuum_arrays,
	PyDoc_STR("*float*: Allocate arrays for only the required number of steps\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemControl_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesPtes.SystemControl",             /*tp_name*/
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
		SystemControl_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SystemControl_getset,          /*tp_getset*/
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
 * FinancialModel Group
 */ 

static PyTypeObject FinancialModel_Type;

static PyObject *
FinancialModel_new(SAM_EtesPtes data_ptr)
{
	PyObject* new_obj = FinancialModel_Type.tp_alloc(&FinancialModel_Type,0);

	VarGroupObject* FinancialModel_obj = (VarGroupObject*)new_obj;

	FinancialModel_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* FinancialModel methods */

static PyObject *
FinancialModel_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesPtes", "FinancialModel")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialModel_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &FinancialModel_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "EtesPtes", "FinancialModel")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialModel_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &FinancialModel_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef FinancialModel_methods[] = {
		{"assign",            (PyCFunction)FinancialModel_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``FinancialModel_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)FinancialModel_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``FinancialModel_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)FinancialModel_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
FinancialModel_get_etes_financial_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialModel_etes_financial_model_nget, self->data_ptr);
}

static int
FinancialModel_set_etes_financial_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialModel_etes_financial_model_nset, self->data_ptr);
}

static PyGetSetDef FinancialModel_getset[] = {
{"etes_financial_model", (getter)FinancialModel_get_etes_financial_model,(setter)FinancialModel_set_etes_financial_model,
	PyDoc_STR("*float*:  [1-8]\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FinancialModel_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesPtes.FinancialModel",             /*tp_name*/
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
		FinancialModel_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		FinancialModel_getset,          /*tp_getset*/
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
 * SystemDesign Group
 */ 

static PyTypeObject SystemDesign_Type;

static PyObject *
SystemDesign_new(SAM_EtesPtes data_ptr)
{
	PyObject* new_obj = SystemDesign_Type.tp_alloc(&SystemDesign_Type,0);

	VarGroupObject* SystemDesign_obj = (VarGroupObject*)new_obj;

	SystemDesign_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SystemDesign methods */

static PyObject *
SystemDesign_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesPtes", "SystemDesign")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemDesign_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SystemDesign_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "EtesPtes", "SystemDesign")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemDesign_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SystemDesign_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SystemDesign_methods[] = {
		{"assign",            (PyCFunction)SystemDesign_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SystemDesign_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SystemDesign_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SystemDesign_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SystemDesign_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemDesign_get_T_CT_cold_htf_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemDesign_T_CT_cold_htf_des_nget, self->data_ptr);
}

static int
SystemDesign_set_T_CT_cold_htf_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemDesign_T_CT_cold_htf_des_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_T_CT_hot_htf_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemDesign_T_CT_hot_htf_des_nget, self->data_ptr);
}

static int
SystemDesign_set_T_CT_hot_htf_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemDesign_T_CT_hot_htf_des_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_T_HT_cold_htf_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemDesign_T_HT_cold_htf_des_nget, self->data_ptr);
}

static int
SystemDesign_set_T_HT_cold_htf_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemDesign_T_HT_cold_htf_des_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_T_HT_hot_htf_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemDesign_T_HT_hot_htf_des_nget, self->data_ptr);
}

static int
SystemDesign_set_T_HT_hot_htf_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemDesign_T_HT_hot_htf_des_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_W_dot_pc_thermo_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemDesign_W_dot_pc_thermo_des_nget, self->data_ptr);
}

static int
SystemDesign_set_W_dot_pc_thermo_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemDesign_W_dot_pc_thermo_des_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_cop_hp_thermo_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemDesign_cop_hp_thermo_des_nget, self->data_ptr);
}

static int
SystemDesign_set_cop_hp_thermo_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemDesign_cop_hp_thermo_des_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_eta_pc_thermo_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemDesign_eta_pc_thermo_des_nget, self->data_ptr);
}

static int
SystemDesign_set_eta_pc_thermo_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemDesign_eta_pc_thermo_des_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_f_hp_parasitic_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemDesign_f_hp_parasitic_des_nget, self->data_ptr);
}

static int
SystemDesign_set_f_hp_parasitic_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemDesign_f_hp_parasitic_des_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_f_pc_parasitic_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemDesign_f_pc_parasitic_des_nget, self->data_ptr);
}

static int
SystemDesign_set_f_pc_parasitic_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemDesign_f_pc_parasitic_des_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_heater_mult(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemDesign_heater_mult_nget, self->data_ptr);
}

static int
SystemDesign_set_heater_mult(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemDesign_heater_mult_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_tshours(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemDesign_tshours_nget, self->data_ptr);
}

static int
SystemDesign_set_tshours(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemDesign_tshours_nset, self->data_ptr);
}

static PyGetSetDef SystemDesign_getset[] = {
{"T_CT_cold_htf_des", (getter)SystemDesign_get_T_CT_cold_htf_des,(setter)SystemDesign_set_T_CT_cold_htf_des,
	PyDoc_STR("*float*: CT TES cold temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_CT_hot_htf_des", (getter)SystemDesign_get_T_CT_hot_htf_des,(setter)SystemDesign_set_T_CT_hot_htf_des,
	PyDoc_STR("*float*: CT TES hot temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_HT_cold_htf_des", (getter)SystemDesign_get_T_HT_cold_htf_des,(setter)SystemDesign_set_T_HT_cold_htf_des,
	PyDoc_STR("*float*: HT TES cold temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_HT_hot_htf_des", (getter)SystemDesign_get_T_HT_hot_htf_des,(setter)SystemDesign_set_T_HT_hot_htf_des,
	PyDoc_STR("*float*: HT TES hot temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"W_dot_pc_thermo_des", (getter)SystemDesign_get_W_dot_pc_thermo_des,(setter)SystemDesign_set_W_dot_pc_thermo_des,
	PyDoc_STR("*float*: PC design thermodynamic power [MWe]\n\n**Required:**\nTrue"),
 	NULL},
{"cop_hp_thermo_des", (getter)SystemDesign_get_cop_hp_thermo_des,(setter)SystemDesign_set_cop_hp_thermo_des,
	PyDoc_STR("*float*: Heat pump design thermodynamic heat COP [-]\n\n**Required:**\nTrue"),
 	NULL},
{"eta_pc_thermo_des", (getter)SystemDesign_get_eta_pc_thermo_des,(setter)SystemDesign_set_eta_pc_thermo_des,
	PyDoc_STR("*float*: PC design thermodynamic efficiency [-]\n\n**Required:**\nTrue"),
 	NULL},
{"f_hp_parasitic_des", (getter)SystemDesign_get_f_hp_parasitic_des,(setter)SystemDesign_set_f_hp_parasitic_des,
	PyDoc_STR("*float*: Heat pump parasitics as fraction of design thermo power in [-]\n\n**Required:**\nTrue"),
 	NULL},
{"f_pc_parasitic_des", (getter)SystemDesign_get_f_pc_parasitic_des,(setter)SystemDesign_set_f_pc_parasitic_des,
	PyDoc_STR("*float*: PC parasitics as fraction of design thermo power out [-]\n\n**Required:**\nTrue"),
 	NULL},
{"heater_mult", (getter)SystemDesign_get_heater_mult,(setter)SystemDesign_set_heater_mult,
	PyDoc_STR("*float*: Heater multiple relative to design cycle thermal power [-]\n\n**Required:**\nTrue"),
 	NULL},
{"tshours", (getter)SystemDesign_get_tshours,(setter)SystemDesign_set_tshours,
	PyDoc_STR("*float*: Equivalent full-load thermal storage hours [hr]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemDesign_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesPtes.SystemDesign",             /*tp_name*/
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
		SystemDesign_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SystemDesign_getset,          /*tp_getset*/
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
 * ThermalStorage Group
 */ 

static PyTypeObject ThermalStorage_Type;

static PyObject *
ThermalStorage_new(SAM_EtesPtes data_ptr)
{
	PyObject* new_obj = ThermalStorage_Type.tp_alloc(&ThermalStorage_Type,0);

	VarGroupObject* ThermalStorage_obj = (VarGroupObject*)new_obj;

	ThermalStorage_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* ThermalStorage methods */

static PyObject *
ThermalStorage_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesPtes", "ThermalStorage")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ThermalStorage_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &ThermalStorage_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "EtesPtes", "ThermalStorage")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ThermalStorage_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &ThermalStorage_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ThermalStorage_methods[] = {
		{"assign",            (PyCFunction)ThermalStorage_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``ThermalStorage_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)ThermalStorage_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``ThermalStorage_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)ThermalStorage_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ThermalStorage_get_cold_htf_code(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_ThermalStorage_cold_htf_code_nget, self->data_ptr);
}

static int
ThermalStorage_set_cold_htf_code(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_ThermalStorage_cold_htf_code_nset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_hot_htf_code(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_ThermalStorage_hot_htf_code_nget, self->data_ptr);
}

static int
ThermalStorage_set_hot_htf_code(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_ThermalStorage_hot_htf_code_nset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_ud_cold_htf_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_EtesPtes_ThermalStorage_ud_cold_htf_props_mget, self->data_ptr);
}

static int
ThermalStorage_set_ud_cold_htf_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_EtesPtes_ThermalStorage_ud_cold_htf_props_mset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_ud_hot_htf_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_EtesPtes_ThermalStorage_ud_hot_htf_props_mget, self->data_ptr);
}

static int
ThermalStorage_set_ud_hot_htf_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_EtesPtes_ThermalStorage_ud_hot_htf_props_mset, self->data_ptr);
}

static PyGetSetDef ThermalStorage_getset[] = {
{"cold_htf_code", (getter)ThermalStorage_get_cold_htf_code,(setter)ThermalStorage_set_cold_htf_code,
	PyDoc_STR("*float*: Cold HTF code - see htf_props.h for list\n\n**Required:**\nTrue"),
 	NULL},
{"hot_htf_code", (getter)ThermalStorage_get_hot_htf_code,(setter)ThermalStorage_set_hot_htf_code,
	PyDoc_STR("*float*: Hot HTF code - see htf_props.h for list\n\n**Required:**\nTrue"),
 	NULL},
{"ud_cold_htf_props", (getter)ThermalStorage_get_ud_cold_htf_props,(setter)ThermalStorage_set_ud_cold_htf_props,
	PyDoc_STR("*sequence[sequence]*: User-defined Cold HTF fluid property data [-]\n\n**Required:**\nRequired if cold_htf_code=50"),
 	NULL},
{"ud_hot_htf_props", (getter)ThermalStorage_get_ud_hot_htf_props,(setter)ThermalStorage_set_ud_hot_htf_props,
	PyDoc_STR("*sequence[sequence]*: User-defined Hot HTF fluid property data [-]\n\n**Required:**\nRequired if hot_htf_code=50"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ThermalStorage_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesPtes.ThermalStorage",             /*tp_name*/
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
		ThermalStorage_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ThermalStorage_getset,          /*tp_getset*/
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
 * Heater Group
 */ 

static PyTypeObject Heater_Type;

static PyObject *
Heater_new(SAM_EtesPtes data_ptr)
{
	PyObject* new_obj = Heater_Type.tp_alloc(&Heater_Type,0);

	VarGroupObject* Heater_obj = (VarGroupObject*)new_obj;

	Heater_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Heater methods */

static PyObject *
Heater_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesPtes", "Heater")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Heater_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Heater_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "EtesPtes", "Heater")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Heater_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Heater_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Heater_methods[] = {
		{"assign",            (PyCFunction)Heater_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Heater_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Heater_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Heater_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Heater_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Heater_get_f_q_dot_des_allowable_su(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Heater_f_q_dot_des_allowable_su_nget, self->data_ptr);
}

static int
Heater_set_f_q_dot_des_allowable_su(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_Heater_f_q_dot_des_allowable_su_nset, self->data_ptr);
}

static PyObject *
Heater_get_f_q_dot_heater_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Heater_f_q_dot_heater_min_nget, self->data_ptr);
}

static int
Heater_set_f_q_dot_heater_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_Heater_f_q_dot_heater_min_nset, self->data_ptr);
}

static PyObject *
Heater_get_hrs_startup_at_max_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Heater_hrs_startup_at_max_rate_nget, self->data_ptr);
}

static int
Heater_set_hrs_startup_at_max_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_Heater_hrs_startup_at_max_rate_nset, self->data_ptr);
}

static PyGetSetDef Heater_getset[] = {
{"f_q_dot_des_allowable_su", (getter)Heater_get_f_q_dot_des_allowable_su,(setter)Heater_set_f_q_dot_des_allowable_su,
	PyDoc_STR("*float*: Fraction of design power allowed during startup [-]\n\n**Required:**\nTrue"),
 	NULL},
{"f_q_dot_heater_min", (getter)Heater_get_f_q_dot_heater_min,(setter)Heater_set_f_q_dot_heater_min,
	PyDoc_STR("*float*: Minimum allowable heater output as fraction of design\n\n**Required:**\nTrue"),
 	NULL},
{"hrs_startup_at_max_rate", (getter)Heater_get_hrs_startup_at_max_rate,(setter)Heater_set_hrs_startup_at_max_rate,
	PyDoc_STR("*float*: Duration of startup at max startup power [hr]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Heater_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesPtes.Heater",             /*tp_name*/
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
		Heater_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Heater_getset,          /*tp_getset*/
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
 * PowerCycle Group
 */ 

static PyTypeObject PowerCycle_Type;

static PyObject *
PowerCycle_new(SAM_EtesPtes data_ptr)
{
	PyObject* new_obj = PowerCycle_Type.tp_alloc(&PowerCycle_Type,0);

	VarGroupObject* PowerCycle_obj = (VarGroupObject*)new_obj;

	PowerCycle_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* PowerCycle methods */

static PyObject *
PowerCycle_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesPtes", "PowerCycle")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PowerCycle_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &PowerCycle_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "EtesPtes", "PowerCycle")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PowerCycle_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &PowerCycle_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef PowerCycle_methods[] = {
		{"assign",            (PyCFunction)PowerCycle_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``PowerCycle_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)PowerCycle_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``PowerCycle_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)PowerCycle_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
PowerCycle_get_CT_pb_pump_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_PowerCycle_CT_pb_pump_coef_nget, self->data_ptr);
}

static int
PowerCycle_set_CT_pb_pump_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_PowerCycle_CT_pb_pump_coef_nset, self->data_ptr);
}

static PyObject *
PowerCycle_get_cycle_cutoff_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_PowerCycle_cycle_cutoff_frac_nget, self->data_ptr);
}

static int
PowerCycle_set_cycle_cutoff_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_PowerCycle_cycle_cutoff_frac_nset, self->data_ptr);
}

static PyObject *
PowerCycle_get_cycle_max_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_PowerCycle_cycle_max_frac_nget, self->data_ptr);
}

static int
PowerCycle_set_cycle_max_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_PowerCycle_cycle_max_frac_nset, self->data_ptr);
}

static PyObject *
PowerCycle_get_heat_pump_CT_HTF_pump_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_PowerCycle_heat_pump_CT_HTF_pump_coef_nget, self->data_ptr);
}

static int
PowerCycle_set_heat_pump_CT_HTF_pump_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_PowerCycle_heat_pump_CT_HTF_pump_coef_nset, self->data_ptr);
}

static PyObject *
PowerCycle_get_heat_pump_HT_HTF_pump_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_PowerCycle_heat_pump_HT_HTF_pump_coef_nget, self->data_ptr);
}

static int
PowerCycle_set_heat_pump_HT_HTF_pump_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_PowerCycle_heat_pump_HT_HTF_pump_coef_nset, self->data_ptr);
}

static PyObject *
PowerCycle_get_pb_pump_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_PowerCycle_pb_pump_coef_nget, self->data_ptr);
}

static int
PowerCycle_set_pb_pump_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_PowerCycle_pb_pump_coef_nset, self->data_ptr);
}

static PyObject *
PowerCycle_get_q_sby_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_PowerCycle_q_sby_frac_nget, self->data_ptr);
}

static int
PowerCycle_set_q_sby_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_PowerCycle_q_sby_frac_nset, self->data_ptr);
}

static PyObject *
PowerCycle_get_startup_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_PowerCycle_startup_frac_nget, self->data_ptr);
}

static int
PowerCycle_set_startup_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_PowerCycle_startup_frac_nset, self->data_ptr);
}

static PyObject *
PowerCycle_get_startup_time(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_PowerCycle_startup_time_nget, self->data_ptr);
}

static int
PowerCycle_set_startup_time(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_PowerCycle_startup_time_nset, self->data_ptr);
}

static PyGetSetDef PowerCycle_getset[] = {
{"CT_pb_pump_coef", (getter)PowerCycle_get_CT_pb_pump_coef,(setter)PowerCycle_set_CT_pb_pump_coef,
	PyDoc_STR("*float*: COLD TES pumping power to move 1kg of HTF through PB loop [kW/kg/s]\n\n**Required:**\nTrue"),
 	NULL},
{"cycle_cutoff_frac", (getter)PowerCycle_get_cycle_cutoff_frac,(setter)PowerCycle_set_cycle_cutoff_frac,
	PyDoc_STR("*float*: Minimum turbine operation fraction before shutdown\n\n**Required:**\nTrue"),
 	NULL},
{"cycle_max_frac", (getter)PowerCycle_get_cycle_max_frac,(setter)PowerCycle_set_cycle_max_frac,
	PyDoc_STR("*float*: Maximum turbine over design operation fraction\n\n**Required:**\nTrue"),
 	NULL},
{"heat_pump_CT_HTF_pump_coef", (getter)PowerCycle_get_heat_pump_CT_HTF_pump_coef,(setter)PowerCycle_set_heat_pump_CT_HTF_pump_coef,
	PyDoc_STR("*float*: Cold temp HX pumping power to move 1 kg/s [kW/kg/s]\n\n**Required:**\nTrue"),
 	NULL},
{"heat_pump_HT_HTF_pump_coef", (getter)PowerCycle_get_heat_pump_HT_HTF_pump_coef,(setter)PowerCycle_set_heat_pump_HT_HTF_pump_coef,
	PyDoc_STR("*float*: High temp HX pumping power to move 1 kg/s [kW/kg/s]\n\n**Required:**\nTrue"),
 	NULL},
{"pb_pump_coef", (getter)PowerCycle_get_pb_pump_coef,(setter)PowerCycle_set_pb_pump_coef,
	PyDoc_STR("*float*: COLD TES pumping power to move 1kg of HTF through PB loop [kW/kg/s]\n\n**Required:**\nTrue"),
 	NULL},
{"q_sby_frac", (getter)PowerCycle_get_q_sby_frac,(setter)PowerCycle_set_q_sby_frac,
	PyDoc_STR("*float*: Fraction of thermal power required for standby\n\n**Required:**\nTrue"),
 	NULL},
{"startup_frac", (getter)PowerCycle_get_startup_frac,(setter)PowerCycle_set_startup_frac,
	PyDoc_STR("*float*: Fraction of design thermal power needed for startup [none]\n\n**Required:**\nTrue"),
 	NULL},
{"startup_time", (getter)PowerCycle_get_startup_time,(setter)PowerCycle_set_startup_time,
	PyDoc_STR("*float*: Time needed for power block startup [hr]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject PowerCycle_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesPtes.PowerCycle",             /*tp_name*/
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
		PowerCycle_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		PowerCycle_getset,          /*tp_getset*/
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
 * HotThermalStorage Group
 */ 

static PyTypeObject HotThermalStorage_Type;

static PyObject *
HotThermalStorage_new(SAM_EtesPtes data_ptr)
{
	PyObject* new_obj = HotThermalStorage_Type.tp_alloc(&HotThermalStorage_Type,0);

	VarGroupObject* HotThermalStorage_obj = (VarGroupObject*)new_obj;

	HotThermalStorage_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* HotThermalStorage methods */

static PyObject *
HotThermalStorage_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesPtes", "HotThermalStorage")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
HotThermalStorage_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &HotThermalStorage_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "EtesPtes", "HotThermalStorage")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
HotThermalStorage_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &HotThermalStorage_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef HotThermalStorage_methods[] = {
		{"assign",            (PyCFunction)HotThermalStorage_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``HotThermalStorage_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)HotThermalStorage_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``HotThermalStorage_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)HotThermalStorage_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
HotThermalStorage_get_cold_tank_Thtr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_HotThermalStorage_cold_tank_Thtr_nget, self->data_ptr);
}

static int
HotThermalStorage_set_cold_tank_Thtr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_HotThermalStorage_cold_tank_Thtr_nset, self->data_ptr);
}

static PyObject *
HotThermalStorage_get_cold_tank_max_heat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_HotThermalStorage_cold_tank_max_heat_nget, self->data_ptr);
}

static int
HotThermalStorage_set_cold_tank_max_heat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_HotThermalStorage_cold_tank_max_heat_nset, self->data_ptr);
}

static PyObject *
HotThermalStorage_get_h_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_HotThermalStorage_h_tank_nget, self->data_ptr);
}

static int
HotThermalStorage_set_h_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_HotThermalStorage_h_tank_nset, self->data_ptr);
}

static PyObject *
HotThermalStorage_get_h_tank_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_HotThermalStorage_h_tank_min_nget, self->data_ptr);
}

static int
HotThermalStorage_set_h_tank_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_HotThermalStorage_h_tank_min_nset, self->data_ptr);
}

static PyObject *
HotThermalStorage_get_hot_tank_Thtr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_HotThermalStorage_hot_tank_Thtr_nget, self->data_ptr);
}

static int
HotThermalStorage_set_hot_tank_Thtr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_HotThermalStorage_hot_tank_Thtr_nset, self->data_ptr);
}

static PyObject *
HotThermalStorage_get_hot_tank_max_heat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_HotThermalStorage_hot_tank_max_heat_nget, self->data_ptr);
}

static int
HotThermalStorage_set_hot_tank_max_heat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_HotThermalStorage_hot_tank_max_heat_nset, self->data_ptr);
}

static PyObject *
HotThermalStorage_get_tank_pairs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_HotThermalStorage_tank_pairs_nget, self->data_ptr);
}

static int
HotThermalStorage_set_tank_pairs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_HotThermalStorage_tank_pairs_nset, self->data_ptr);
}

static PyObject *
HotThermalStorage_get_tes_init_hot_htf_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_HotThermalStorage_tes_init_hot_htf_percent_nget, self->data_ptr);
}

static int
HotThermalStorage_set_tes_init_hot_htf_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_HotThermalStorage_tes_init_hot_htf_percent_nset, self->data_ptr);
}

static PyObject *
HotThermalStorage_get_u_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_HotThermalStorage_u_tank_nget, self->data_ptr);
}

static int
HotThermalStorage_set_u_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_HotThermalStorage_u_tank_nset, self->data_ptr);
}

static PyGetSetDef HotThermalStorage_getset[] = {
{"cold_tank_Thtr", (getter)HotThermalStorage_get_cold_tank_Thtr,(setter)HotThermalStorage_set_cold_tank_Thtr,
	PyDoc_STR("*float*: HOT TES Minimum allowable cold tank HTF temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"cold_tank_max_heat", (getter)HotThermalStorage_get_cold_tank_max_heat,(setter)HotThermalStorage_set_cold_tank_max_heat,
	PyDoc_STR("*float*: HOT TES Rated heater capacity for cold tank heating [MW]\n\n**Required:**\nTrue"),
 	NULL},
{"h_tank", (getter)HotThermalStorage_get_h_tank,(setter)HotThermalStorage_set_h_tank,
	PyDoc_STR("*float*: HOT TES Total height of tank (height of HTF when tank is full) [m]\n\n**Required:**\nTrue"),
 	NULL},
{"h_tank_min", (getter)HotThermalStorage_get_h_tank_min,(setter)HotThermalStorage_set_h_tank_min,
	PyDoc_STR("*float*: HOT TES Minimum allowable HTF height in storage tank [m]\n\n**Required:**\nTrue"),
 	NULL},
{"hot_tank_Thtr", (getter)HotThermalStorage_get_hot_tank_Thtr,(setter)HotThermalStorage_set_hot_tank_Thtr,
	PyDoc_STR("*float*: HOT TES Minimum allowable hot tank HTF temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"hot_tank_max_heat", (getter)HotThermalStorage_get_hot_tank_max_heat,(setter)HotThermalStorage_set_hot_tank_max_heat,
	PyDoc_STR("*float*: HOT TES Rated heater capacity for hot tank heating [MW]\n\n**Required:**\nTrue"),
 	NULL},
{"tank_pairs", (getter)HotThermalStorage_get_tank_pairs,(setter)HotThermalStorage_set_tank_pairs,
	PyDoc_STR("*float*: HOT TES Number of equivalent tank pairs\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"tes_init_hot_htf_percent", (getter)HotThermalStorage_get_tes_init_hot_htf_percent,(setter)HotThermalStorage_set_tes_init_hot_htf_percent,
	PyDoc_STR("*float*: HOT TES Initial fraction of available volume that is hot [%]\n\n**Required:**\nTrue"),
 	NULL},
{"u_tank", (getter)HotThermalStorage_get_u_tank,(setter)HotThermalStorage_set_u_tank,
	PyDoc_STR("*float*: HOT TES Loss coefficient from the tank [W/m2-K]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject HotThermalStorage_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesPtes.HotThermalStorage",             /*tp_name*/
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
		HotThermalStorage_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		HotThermalStorage_getset,          /*tp_getset*/
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
 * ColdThermalStorage Group
 */ 

static PyTypeObject ColdThermalStorage_Type;

static PyObject *
ColdThermalStorage_new(SAM_EtesPtes data_ptr)
{
	PyObject* new_obj = ColdThermalStorage_Type.tp_alloc(&ColdThermalStorage_Type,0);

	VarGroupObject* ColdThermalStorage_obj = (VarGroupObject*)new_obj;

	ColdThermalStorage_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* ColdThermalStorage methods */

static PyObject *
ColdThermalStorage_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesPtes", "ColdThermalStorage")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ColdThermalStorage_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &ColdThermalStorage_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "EtesPtes", "ColdThermalStorage")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ColdThermalStorage_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &ColdThermalStorage_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ColdThermalStorage_methods[] = {
		{"assign",            (PyCFunction)ColdThermalStorage_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``ColdThermalStorage_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)ColdThermalStorage_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``ColdThermalStorage_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)ColdThermalStorage_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ColdThermalStorage_get_CT_h_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_ColdThermalStorage_CT_h_tank_nget, self->data_ptr);
}

static int
ColdThermalStorage_set_CT_h_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_ColdThermalStorage_CT_h_tank_nset, self->data_ptr);
}

static PyObject *
ColdThermalStorage_get_CT_h_tank_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_ColdThermalStorage_CT_h_tank_min_nget, self->data_ptr);
}

static int
ColdThermalStorage_set_CT_h_tank_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_ColdThermalStorage_CT_h_tank_min_nset, self->data_ptr);
}

static PyObject *
ColdThermalStorage_get_CT_tank_pairs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_ColdThermalStorage_CT_tank_pairs_nget, self->data_ptr);
}

static int
ColdThermalStorage_set_CT_tank_pairs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_ColdThermalStorage_CT_tank_pairs_nset, self->data_ptr);
}

static PyObject *
ColdThermalStorage_get_CT_u_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_ColdThermalStorage_CT_u_tank_nget, self->data_ptr);
}

static int
ColdThermalStorage_set_CT_u_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_ColdThermalStorage_CT_u_tank_nset, self->data_ptr);
}

static PyGetSetDef ColdThermalStorage_getset[] = {
{"CT_h_tank", (getter)ColdThermalStorage_get_CT_h_tank,(setter)ColdThermalStorage_set_CT_h_tank,
	PyDoc_STR("*float*: COLD TES Total height of tank (height of HTF when tank is full) [m]\n\n**Required:**\nTrue"),
 	NULL},
{"CT_h_tank_min", (getter)ColdThermalStorage_get_CT_h_tank_min,(setter)ColdThermalStorage_set_CT_h_tank_min,
	PyDoc_STR("*float*: COLD TES Minimum allowable HTF height in storage tank [m]\n\n**Required:**\nTrue"),
 	NULL},
{"CT_tank_pairs", (getter)ColdThermalStorage_get_CT_tank_pairs,(setter)ColdThermalStorage_set_CT_tank_pairs,
	PyDoc_STR("*float*: COLD TES Number of equivalent tank pairs\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"CT_u_tank", (getter)ColdThermalStorage_get_CT_u_tank,(setter)ColdThermalStorage_set_CT_u_tank,
	PyDoc_STR("*float*: COLD TES Loss coefficient from the tank [W/m2-K]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ColdThermalStorage_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesPtes.ColdThermalStorage",             /*tp_name*/
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
		ColdThermalStorage_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ColdThermalStorage_getset,          /*tp_getset*/
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
 * TimeOfDeliveryFactors Group
 */ 

static PyTypeObject TimeOfDeliveryFactors_Type;

static PyObject *
TimeOfDeliveryFactors_new(SAM_EtesPtes data_ptr)
{
	PyObject* new_obj = TimeOfDeliveryFactors_Type.tp_alloc(&TimeOfDeliveryFactors_Type,0);

	VarGroupObject* TimeOfDeliveryFactors_obj = (VarGroupObject*)new_obj;

	TimeOfDeliveryFactors_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* TimeOfDeliveryFactors methods */

static PyObject *
TimeOfDeliveryFactors_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesPtes", "TimeOfDeliveryFactors")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TimeOfDeliveryFactors_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &TimeOfDeliveryFactors_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "EtesPtes", "TimeOfDeliveryFactors")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TimeOfDeliveryFactors_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &TimeOfDeliveryFactors_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TimeOfDeliveryFactors_methods[] = {
		{"assign",            (PyCFunction)TimeOfDeliveryFactors_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``TimeOfDeliveryFactors_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)TimeOfDeliveryFactors_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``TimeOfDeliveryFactors_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)TimeOfDeliveryFactors_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factors_ts(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_TimeOfDeliveryFactors_dispatch_factors_ts_aget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factors_ts(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_EtesPtes_TimeOfDeliveryFactors_dispatch_factors_ts_aset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_EtesPtes_TimeOfDeliveryFactors_dispatch_sched_weekday_mget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_EtesPtes_TimeOfDeliveryFactors_dispatch_sched_weekday_mset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_EtesPtes_TimeOfDeliveryFactors_dispatch_sched_weekend_mget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_EtesPtes_TimeOfDeliveryFactors_dispatch_sched_weekend_mset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_tod_factors(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_TimeOfDeliveryFactors_dispatch_tod_factors_aget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_tod_factors(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_EtesPtes_TimeOfDeliveryFactors_dispatch_tod_factors_aset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_ppa_multiplier_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_TimeOfDeliveryFactors_ppa_multiplier_model_nget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_ppa_multiplier_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_TimeOfDeliveryFactors_ppa_multiplier_model_nset, self->data_ptr);
}

static PyGetSetDef TimeOfDeliveryFactors_getset[] = {
{"dispatch_factors_ts", (getter)TimeOfDeliveryFactors_get_dispatch_factors_ts,(setter)TimeOfDeliveryFactors_set_dispatch_factors_ts,
	PyDoc_STR("*sequence*: Dispatch payment factor timeseries array\n\n**Required:**\nRequired if ppa_multiplier_model=1&etes_financial_model<5&is_dispatch=1&sim_type=1"),
 	NULL},
{"dispatch_sched_weekday", (getter)TimeOfDeliveryFactors_get_dispatch_sched_weekday,(setter)TimeOfDeliveryFactors_set_dispatch_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: PPA pricing weekday schedule, 12x24\n\n**Required:**\nRequired if ppa_multiplier_model=0&etes_financial_model<5&is_dispatch=1&sim_type=1"),
 	NULL},
{"dispatch_sched_weekend", (getter)TimeOfDeliveryFactors_get_dispatch_sched_weekend,(setter)TimeOfDeliveryFactors_set_dispatch_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: PPA pricing weekend schedule, 12x24\n\n**Required:**\nRequired if ppa_multiplier_model=0&etes_financial_model<5&is_dispatch=1&sim_type=1"),
 	NULL},
{"dispatch_tod_factors", (getter)TimeOfDeliveryFactors_get_dispatch_tod_factors,(setter)TimeOfDeliveryFactors_set_dispatch_tod_factors,
	PyDoc_STR("*sequence*: TOD factors for periods 1 through 9\n\n**Info:**\nWe added this array input after SAM 2022.12.21 to replace the functionality of former single value inputs dispatch_factor1 through dispatch_factor9\n\n**Required:**\nRequired if ppa_multiplier_model=0&etes_financial_model<5&is_dispatch=1&sim_type=1"),
 	NULL},
{"ppa_multiplier_model", (getter)TimeOfDeliveryFactors_get_ppa_multiplier_model,(setter)TimeOfDeliveryFactors_set_ppa_multiplier_model,
	PyDoc_STR("*float*: PPA multiplier model [0/1]\n\n**Options:**\n0=diurnal,1=timestep\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TimeOfDeliveryFactors_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesPtes.TimeOfDeliveryFactors",             /*tp_name*/
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
		TimeOfDeliveryFactors_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TimeOfDeliveryFactors_getset,          /*tp_getset*/
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
Revenue_new(SAM_EtesPtes data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesPtes", "Revenue")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "EtesPtes", "Revenue")){
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
Revenue_get_ppa_price_input(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Revenue_ppa_price_input_aget, self->data_ptr);
}

static int
Revenue_set_ppa_price_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_EtesPtes_Revenue_ppa_price_input_aset, self->data_ptr);
}

static PyGetSetDef Revenue_getset[] = {
{"ppa_price_input", (getter)Revenue_get_ppa_price_input,(setter)Revenue_set_ppa_price_input,
	PyDoc_STR("*sequence*: PPA prices - yearly [$/kWh]\n\n**Required:**\nRequired if ppa_multiplier_model=0&etes_financial_model<5&is_dispatch=1&sim_type=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Revenue_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesPtes.Revenue",             /*tp_name*/
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
 * SystemCosts Group
 */ 

static PyTypeObject SystemCosts_Type;

static PyObject *
SystemCosts_new(SAM_EtesPtes data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesPtes", "SystemCosts")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "EtesPtes", "SystemCosts")){
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
SystemCosts_get_CT_tes_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemCosts_CT_tes_spec_cost_nget, self->data_ptr);
}

static int
SystemCosts_set_CT_tes_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemCosts_CT_tes_spec_cost_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_bop_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemCosts_bop_spec_cost_nget, self->data_ptr);
}

static int
SystemCosts_set_bop_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemCosts_bop_spec_cost_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_contingency_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemCosts_contingency_rate_nget, self->data_ptr);
}

static int
SystemCosts_set_contingency_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemCosts_contingency_rate_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_cycle_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemCosts_cycle_spec_cost_nget, self->data_ptr);
}

static int
SystemCosts_set_cycle_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemCosts_cycle_spec_cost_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_epc_cost_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemCosts_epc_cost_fixed_nget, self->data_ptr);
}

static int
SystemCosts_set_epc_cost_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemCosts_epc_cost_fixed_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_epc_cost_per_watt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemCosts_epc_cost_per_watt_nget, self->data_ptr);
}

static int
SystemCosts_set_epc_cost_per_watt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemCosts_epc_cost_per_watt_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_epc_cost_perc_of_direct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemCosts_epc_cost_perc_of_direct_nget, self->data_ptr);
}

static int
SystemCosts_set_epc_cost_perc_of_direct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemCosts_epc_cost_perc_of_direct_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_heat_pump_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemCosts_heat_pump_spec_cost_nget, self->data_ptr);
}

static int
SystemCosts_set_heat_pump_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemCosts_heat_pump_spec_cost_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_land_cost_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemCosts_land_cost_fixed_nget, self->data_ptr);
}

static int
SystemCosts_set_land_cost_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemCosts_land_cost_fixed_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_land_cost_per_watt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemCosts_land_cost_per_watt_nget, self->data_ptr);
}

static int
SystemCosts_set_land_cost_per_watt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemCosts_land_cost_per_watt_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_land_cost_perc_of_direct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemCosts_land_cost_perc_of_direct_nget, self->data_ptr);
}

static int
SystemCosts_set_land_cost_perc_of_direct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemCosts_land_cost_perc_of_direct_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_sales_tax_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemCosts_sales_tax_frac_nget, self->data_ptr);
}

static int
SystemCosts_set_sales_tax_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemCosts_sales_tax_frac_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_tes_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_SystemCosts_tes_spec_cost_nget, self->data_ptr);
}

static int
SystemCosts_set_tes_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_SystemCosts_tes_spec_cost_nset, self->data_ptr);
}

static PyGetSetDef SystemCosts_getset[] = {
{"CT_tes_spec_cost", (getter)SystemCosts_get_CT_tes_spec_cost,(setter)SystemCosts_set_CT_tes_spec_cost,
	PyDoc_STR("*float*: Cold Temp thermal energy storage specific cost [$/kWht]\n\n**Required:**\nTrue"),
 	NULL},
{"bop_spec_cost", (getter)SystemCosts_get_bop_spec_cost,(setter)SystemCosts_set_bop_spec_cost,
	PyDoc_STR("*float*: Balance of plant specific cost [$/kWe]\n\n**Required:**\nTrue"),
 	NULL},
{"contingency_rate", (getter)SystemCosts_get_contingency_rate,(setter)SystemCosts_set_contingency_rate,
	PyDoc_STR("*float*: Contingency for cost overrun [%]\n\n**Required:**\nTrue"),
 	NULL},
{"cycle_spec_cost", (getter)SystemCosts_get_cycle_spec_cost,(setter)SystemCosts_set_cycle_spec_cost,
	PyDoc_STR("*float*: Power cycle specific cost [$/kWe]\n\n**Required:**\nTrue"),
 	NULL},
{"epc_cost_fixed", (getter)SystemCosts_get_epc_cost_fixed,(setter)SystemCosts_set_epc_cost_fixed,
	PyDoc_STR("*float*: EPC fixed [$]\n\n**Required:**\nTrue"),
 	NULL},
{"epc_cost_per_watt", (getter)SystemCosts_get_epc_cost_per_watt,(setter)SystemCosts_set_epc_cost_per_watt,
	PyDoc_STR("*float*: EPC cost per watt [$/W]\n\n**Required:**\nTrue"),
 	NULL},
{"epc_cost_perc_of_direct", (getter)SystemCosts_get_epc_cost_perc_of_direct,(setter)SystemCosts_set_epc_cost_perc_of_direct,
	PyDoc_STR("*float*: EPC cost percent of direct [%]\n\n**Required:**\nTrue"),
 	NULL},
{"heat_pump_spec_cost", (getter)SystemCosts_get_heat_pump_spec_cost,(setter)SystemCosts_set_heat_pump_spec_cost,
	PyDoc_STR("*float*: Heater pump specific cost [$/kWht]\n\n**Required:**\nTrue"),
 	NULL},
{"land_cost_fixed", (getter)SystemCosts_get_land_cost_fixed,(setter)SystemCosts_set_land_cost_fixed,
	PyDoc_STR("*float*: Land fixed [$]\n\n**Required:**\nTrue"),
 	NULL},
{"land_cost_per_watt", (getter)SystemCosts_get_land_cost_per_watt,(setter)SystemCosts_set_land_cost_per_watt,
	PyDoc_STR("*float*: Land cost per watt [$/W]\n\n**Required:**\nTrue"),
 	NULL},
{"land_cost_perc_of_direct", (getter)SystemCosts_get_land_cost_perc_of_direct,(setter)SystemCosts_set_land_cost_perc_of_direct,
	PyDoc_STR("*float*: Land cost percent of direct [%]\n\n**Required:**\nTrue"),
 	NULL},
{"sales_tax_frac", (getter)SystemCosts_get_sales_tax_frac,(setter)SystemCosts_set_sales_tax_frac,
	PyDoc_STR("*float*: Percent of cost to which sales tax applies [%]\n\n**Required:**\nTrue"),
 	NULL},
{"tes_spec_cost", (getter)SystemCosts_get_tes_spec_cost,(setter)SystemCosts_set_tes_spec_cost,
	PyDoc_STR("*float*: Hot Temp thermal energy storage specific cost [$/kWht]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesPtes.SystemCosts",             /*tp_name*/
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
 * FinancialParameters Group
 */ 

static PyTypeObject FinancialParameters_Type;

static PyObject *
FinancialParameters_new(SAM_EtesPtes data_ptr)
{
	PyObject* new_obj = FinancialParameters_Type.tp_alloc(&FinancialParameters_Type,0);

	VarGroupObject* FinancialParameters_obj = (VarGroupObject*)new_obj;

	FinancialParameters_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* FinancialParameters methods */

static PyObject *
FinancialParameters_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesPtes", "FinancialParameters")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialParameters_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &FinancialParameters_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "EtesPtes", "FinancialParameters")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialParameters_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &FinancialParameters_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef FinancialParameters_methods[] = {
		{"assign",            (PyCFunction)FinancialParameters_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``FinancialParameters_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)FinancialParameters_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``FinancialParameters_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)FinancialParameters_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
FinancialParameters_get_const_per_interest_rate1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_interest_rate1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_interest_rate1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_interest_rate2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_interest_rate2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_interest_rate3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_interest_rate3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_interest_rate4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_interest_rate4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_interest_rate5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_interest_rate5_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_months1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_months1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_months2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_months2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_months3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_months3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_months4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_months4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_months5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_months5_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_percent1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_percent1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_percent2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_percent2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_percent3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_percent3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_percent4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_percent4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_percent5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_percent5_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_upfront_rate1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_upfront_rate1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_upfront_rate2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_upfront_rate2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_upfront_rate3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_upfront_rate3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_upfront_rate4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_upfront_rate4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_const_per_upfront_rate5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_const_per_upfront_rate5_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_sales_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_FinancialParameters_sales_tax_rate_nget, self->data_ptr);
}

static int
FinancialParameters_set_sales_tax_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesPtes_FinancialParameters_sales_tax_rate_nset, self->data_ptr);
}

static PyGetSetDef FinancialParameters_getset[] = {
{"const_per_interest_rate1", (getter)FinancialParameters_get_const_per_interest_rate1,(setter)FinancialParameters_set_const_per_interest_rate1,
	PyDoc_STR("*float*: Interest rate, loan 1 [%]\n\n**Required:**\nTrue"),
 	NULL},
{"const_per_interest_rate2", (getter)FinancialParameters_get_const_per_interest_rate2,(setter)FinancialParameters_set_const_per_interest_rate2,
	PyDoc_STR("*float*: Interest rate, loan 2 [%]\n\n**Required:**\nTrue"),
 	NULL},
{"const_per_interest_rate3", (getter)FinancialParameters_get_const_per_interest_rate3,(setter)FinancialParameters_set_const_per_interest_rate3,
	PyDoc_STR("*float*: Interest rate, loan 3 [%]\n\n**Required:**\nTrue"),
 	NULL},
{"const_per_interest_rate4", (getter)FinancialParameters_get_const_per_interest_rate4,(setter)FinancialParameters_set_const_per_interest_rate4,
	PyDoc_STR("*float*: Interest rate, loan 4 [%]\n\n**Required:**\nTrue"),
 	NULL},
{"const_per_interest_rate5", (getter)FinancialParameters_get_const_per_interest_rate5,(setter)FinancialParameters_set_const_per_interest_rate5,
	PyDoc_STR("*float*: Interest rate, loan 5 [%]\n\n**Required:**\nTrue"),
 	NULL},
{"const_per_months1", (getter)FinancialParameters_get_const_per_months1,(setter)FinancialParameters_set_const_per_months1,
	PyDoc_STR("*float*: Months prior to operation, loan 1\n\n**Required:**\nTrue"),
 	NULL},
{"const_per_months2", (getter)FinancialParameters_get_const_per_months2,(setter)FinancialParameters_set_const_per_months2,
	PyDoc_STR("*float*: Months prior to operation, loan 2\n\n**Required:**\nTrue"),
 	NULL},
{"const_per_months3", (getter)FinancialParameters_get_const_per_months3,(setter)FinancialParameters_set_const_per_months3,
	PyDoc_STR("*float*: Months prior to operation, loan 3\n\n**Required:**\nTrue"),
 	NULL},
{"const_per_months4", (getter)FinancialParameters_get_const_per_months4,(setter)FinancialParameters_set_const_per_months4,
	PyDoc_STR("*float*: Months prior to operation, loan 4\n\n**Required:**\nTrue"),
 	NULL},
{"const_per_months5", (getter)FinancialParameters_get_const_per_months5,(setter)FinancialParameters_set_const_per_months5,
	PyDoc_STR("*float*: Months prior to operation, loan 5\n\n**Required:**\nTrue"),
 	NULL},
{"const_per_percent1", (getter)FinancialParameters_get_const_per_percent1,(setter)FinancialParameters_set_const_per_percent1,
	PyDoc_STR("*float*: Percent of total installed cost, loan 1 [%]\n\n**Required:**\nTrue"),
 	NULL},
{"const_per_percent2", (getter)FinancialParameters_get_const_per_percent2,(setter)FinancialParameters_set_const_per_percent2,
	PyDoc_STR("*float*: Percent of total installed cost, loan 2 [%]\n\n**Required:**\nTrue"),
 	NULL},
{"const_per_percent3", (getter)FinancialParameters_get_const_per_percent3,(setter)FinancialParameters_set_const_per_percent3,
	PyDoc_STR("*float*: Percent of total installed cost, loan 3 [%]\n\n**Required:**\nTrue"),
 	NULL},
{"const_per_percent4", (getter)FinancialParameters_get_const_per_percent4,(setter)FinancialParameters_set_const_per_percent4,
	PyDoc_STR("*float*: Percent of total installed cost, loan 4 [%]\n\n**Required:**\nTrue"),
 	NULL},
{"const_per_percent5", (getter)FinancialParameters_get_const_per_percent5,(setter)FinancialParameters_set_const_per_percent5,
	PyDoc_STR("*float*: Percent of total installed cost, loan 5 [%]\n\n**Required:**\nTrue"),
 	NULL},
{"const_per_upfront_rate1", (getter)FinancialParameters_get_const_per_upfront_rate1,(setter)FinancialParameters_set_const_per_upfront_rate1,
	PyDoc_STR("*float*: Upfront fee on principal, loan 1 [%]\n\n**Required:**\nTrue"),
 	NULL},
{"const_per_upfront_rate2", (getter)FinancialParameters_get_const_per_upfront_rate2,(setter)FinancialParameters_set_const_per_upfront_rate2,
	PyDoc_STR("*float*: Upfront fee on principal, loan 2 [%]\n\n**Required:**\nTrue"),
 	NULL},
{"const_per_upfront_rate3", (getter)FinancialParameters_get_const_per_upfront_rate3,(setter)FinancialParameters_set_const_per_upfront_rate3,
	PyDoc_STR("*float*: Upfront fee on principal, loan 3 [%]\n\n**Required:**\nTrue"),
 	NULL},
{"const_per_upfront_rate4", (getter)FinancialParameters_get_const_per_upfront_rate4,(setter)FinancialParameters_set_const_per_upfront_rate4,
	PyDoc_STR("*float*: Upfront fee on principal, loan 4 [%]\n\n**Required:**\nTrue"),
 	NULL},
{"const_per_upfront_rate5", (getter)FinancialParameters_get_const_per_upfront_rate5,(setter)FinancialParameters_set_const_per_upfront_rate5,
	PyDoc_STR("*float*: Upfront fee on principal, loan 5 [%]\n\n**Required:**\nTrue"),
 	NULL},
{"sales_tax_rate", (getter)FinancialParameters_get_sales_tax_rate,(setter)FinancialParameters_set_sales_tax_rate,
	PyDoc_STR("*float*: Sales tax rate [%]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FinancialParameters_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesPtes.FinancialParameters",             /*tp_name*/
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
		FinancialParameters_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		FinancialParameters_getset,          /*tp_getset*/
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
Outputs_new(SAM_EtesPtes data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesPtes", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "EtesPtes", "Outputs")){
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
Outputs_get_COP_net_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_COP_net_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_CT_tes_cost_calc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_CT_tes_cost_calc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_E_hp_su_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_E_hp_su_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_CT_tes_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_Q_CT_tes_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_tes_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_Q_tes_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_T_CT_tes_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_T_CT_tes_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_CT_tes_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_T_CT_tes_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_hp_CT_htf_cold_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_T_hp_CT_htf_cold_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_hp_CT_htf_hot_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_T_hp_CT_htf_hot_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_hp_HT_htf_cold_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_T_hp_HT_htf_cold_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_hp_HT_htf_hot_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_T_hp_HT_htf_hot_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_pc_CT_htf_cold_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_T_pc_CT_htf_cold_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_pc_CT_htf_hot_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_T_pc_CT_htf_hot_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_pc_HT_htf_cold_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_T_pc_HT_htf_cold_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_pc_HT_htf_hot_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_T_pc_HT_htf_hot_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tes_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_T_tes_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tes_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_T_tes_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_V_CT_tes_htf_avail(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_V_CT_tes_htf_avail_nget, self->data_ptr);
}

static PyObject *
Outputs_get_V_CT_tes_htf_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_V_CT_tes_htf_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_V_tes_htf_avail(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_V_tes_htf_avail_nget, self->data_ptr);
}

static PyObject *
Outputs_get_V_tes_htf_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_V_tes_htf_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_bop_design(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_W_dot_bop_design_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_bop_parasitics(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_W_dot_bop_parasitics_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_W_dot_fixed_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_fixed_parasitics(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_W_dot_fixed_parasitics_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_hp_CT_htf_pump(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_W_dot_hp_CT_htf_pump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_hp_CT_htf_pump_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_W_dot_hp_CT_htf_pump_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_hp_HT_htf_pump(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_W_dot_hp_HT_htf_pump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_hp_HT_htf_pump_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_W_dot_hp_HT_htf_pump_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_hp_elec_parasitic_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_W_dot_hp_elec_parasitic_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_hp_in_net_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_W_dot_hp_in_net_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_hp_in_thermo_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_W_dot_hp_in_thermo_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_hp_net(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_W_dot_hp_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_hp_parasitics(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_W_dot_hp_parasitics_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_hp_thermo(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_W_dot_hp_thermo_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_out_net(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_W_dot_out_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_pc_CT_htf_pump(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_W_dot_pc_CT_htf_pump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_pc_CT_htf_pump_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_W_dot_pc_CT_htf_pump_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_pc_HT_htf_pump(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_W_dot_pc_HT_htf_pump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_pc_HT_htf_pump_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_W_dot_pc_HT_htf_pump_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_pc_elec_parasitic_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_W_dot_pc_elec_parasitic_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_pc_net_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_W_dot_pc_net_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_pc_parasitics(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_W_dot_pc_parasitics_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_pc_thermo_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_W_dot_pc_thermo_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution_time(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_EtesPtes_Outputs_annual_energy_distribution_time_mget, self->data_ptr);
}

static PyObject *
Outputs_get_avg_suboptimal_rel_mip_gap(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_avg_suboptimal_rel_mip_gap_nget, self->data_ptr);
}

static PyObject *
Outputs_get_bop_cost_calc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_bop_cost_calc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_charge_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_charge_capacity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_construction_financing_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_construction_financing_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_contingency_cost_calc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_contingency_cost_calc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cop_hot_hp_thermo(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_cop_hot_hp_thermo_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cp_battery_nameplate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_cp_battery_nameplate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cp_system_nameplate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_cp_system_nameplate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cycle_cost_calc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_cycle_cost_calc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_d_CT_tank_tes(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_d_CT_tank_tes_nget, self->data_ptr);
}

static PyObject *
Outputs_get_d_tank_tes(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_d_tank_tes_nget, self->data_ptr);
}

static PyObject *
Outputs_get_direct_subtotal_cost_calc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_direct_subtotal_cost_calc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_iter_ann(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_disp_iter_ann_nget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_obj_relax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_disp_obj_relax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_objective(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_disp_objective_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_objective_ann(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_disp_objective_ann_nget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_pceff_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_disp_pceff_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_presolve_nconstr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_disp_presolve_nconstr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_presolve_nconstr_ann(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_disp_presolve_nconstr_ann_nget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_presolve_nvar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_disp_presolve_nvar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_presolve_nvar_ann(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_disp_presolve_nvar_ann_nget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qpbsu_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_disp_qpbsu_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qsfprod_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_disp_qsfprod_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qsfsu_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_disp_qsfsu_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_rel_mip_gap(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_disp_rel_mip_gap_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_rev_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_disp_rev_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_iter(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_disp_solve_iter_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_state(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_disp_solve_state_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_state_ann(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_disp_solve_state_ann_nget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_time(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_disp_solve_time_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_time_ann(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_disp_solve_time_ann_nget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_subopt_flag(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_disp_subopt_flag_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_tes_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_disp_tes_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_wpb_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_disp_wpb_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_e_ch_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_e_ch_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_elec_purchase_price_mult(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_elec_purchase_price_mult_aget, self->data_ptr);
}

static PyObject *
Outputs_get_epc_cost_calc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_epc_cost_calc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_pc_net_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_eta_pc_net_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_pc_thermo(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_eta_pc_thermo_aget, self->data_ptr);
}

static PyObject *
Outputs_get_flip_target_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_flip_target_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_heater_cost_calc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_heater_cost_calc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_installed_per_cap_cost_calc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_installed_per_cap_cost_calc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_land_cost_calc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_land_cost_calc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_balance(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_m_dot_balance_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_hp_CT_htf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_m_dot_hp_CT_htf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_hp_CT_htf_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_m_dot_hp_CT_htf_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_hp_HT_htf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_m_dot_hp_HT_htf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_hp_HT_htf_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_m_dot_hp_HT_htf_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_pc_CT_htf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_m_dot_pc_CT_htf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_pc_CT_htf_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_m_dot_pc_CT_htf_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_pc_HT_htf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_m_dot_pc_HT_htf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_pc_HT_htf_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_m_dot_pc_HT_htf_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mass_CT_tes_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_mass_CT_tes_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mass_CT_tes_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_mass_CT_tes_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mass_tes_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_mass_tes_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mass_tes_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_mass_tes_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_n_op_modes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_n_op_modes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_nameplate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_nameplate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_op_mode_1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_op_mode_2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_op_mode_3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_operating_modes_a(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_operating_modes_a_aget, self->data_ptr);
}

static PyObject *
Outputs_get_operating_modes_b(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_operating_modes_b_aget, self->data_ptr);
}

static PyObject *
Outputs_get_operating_modes_c(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_operating_modes_c_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ppa_soln_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_ppa_soln_mode_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_balance(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_q_balance_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_CT_tes_heater(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_q_dot_CT_tes_heater_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_CT_tes_losses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_q_dot_CT_tes_losses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_ch_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_q_dot_ch_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_dc_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_q_dot_dc_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_hp_cold_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_q_dot_hp_cold_in_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_hp_from_CT_htf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_q_dot_hp_from_CT_htf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_hp_hot_out_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_q_dot_hp_hot_out_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_hp_startup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_q_dot_hp_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_hp_to_HT_htf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_q_dot_hp_to_HT_htf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_loss_CT_tes_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_q_dot_loss_CT_tes_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_loss_tes_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_q_dot_loss_tes_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_cold_out_thermo_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_q_dot_pc_cold_out_thermo_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_cold_to_CTES_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_q_dot_pc_cold_to_CTES_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_cold_to_surroundings_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_q_dot_pc_cold_to_surroundings_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_from_HT_htf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_q_dot_pc_from_HT_htf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_hot_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_q_dot_pc_hot_in_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_rejected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_q_dot_pc_rejected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_startup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_q_dot_pc_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_thermo_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_q_dot_pc_thermo_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_to_CT_htf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_q_dot_pc_to_CT_htf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_tes_heater(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_q_dot_tes_heater_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_tes_losses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_q_dot_tes_losses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_pc_target(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_q_pc_target_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rte_net(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_rte_net_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rte_thermo(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_rte_thermo_nget, self->data_ptr);
}

static PyObject *
Outputs_get_sales_tax_cost_calc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_sales_tax_cost_calc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_system_capacity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tdry(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_tdry_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_cost_calc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_tes_cost_calc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_time_hr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_time_hr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_total_direct_cost_calc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_total_direct_cost_calc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_indirect_cost_calc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_total_indirect_cost_calc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_installed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_total_installed_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tou_period(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_tou_period_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tshours_heater(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesPtes_Outputs_tshours_heater_nget, self->data_ptr);
}

static PyObject *
Outputs_get_twet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesPtes_Outputs_twet_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"COP_net_des", (getter)Outputs_get_COP_net_des,(setter)0,
	PyDoc_STR("*float*: Heat pump net COP [MWe]"),
 	NULL},
{"CT_tes_cost_calc", (getter)Outputs_get_CT_tes_cost_calc,(setter)0,
	PyDoc_STR("*float*: Cold TES cost [$]"),
 	NULL},
{"E_hp_su_des", (getter)Outputs_get_E_hp_su_des,(setter)0,
	PyDoc_STR("*float*: Heat pump startup energy [MWt-hr]"),
 	NULL},
{"Q_CT_tes_des", (getter)Outputs_get_Q_CT_tes_des,(setter)0,
	PyDoc_STR("*float*: Cold TES design capacity [MWt-hr]"),
 	NULL},
{"Q_tes_des", (getter)Outputs_get_Q_tes_des,(setter)0,
	PyDoc_STR("*float*: TES design capacity [MWt-hr]"),
 	NULL},
{"T_CT_tes_cold", (getter)Outputs_get_T_CT_tes_cold,(setter)0,
	PyDoc_STR("*sequence*: TES cold temperature [C]"),
 	NULL},
{"T_CT_tes_hot", (getter)Outputs_get_T_CT_tes_hot,(setter)0,
	PyDoc_STR("*sequence*: TES hot temperature [C]"),
 	NULL},
{"T_hp_CT_htf_cold_out", (getter)Outputs_get_T_hp_CT_htf_cold_out,(setter)0,
	PyDoc_STR("*sequence*: Heat pump cold tes HTF outlet temperature [C]"),
 	NULL},
{"T_hp_CT_htf_hot_in", (getter)Outputs_get_T_hp_CT_htf_hot_in,(setter)0,
	PyDoc_STR("*sequence*: Heat pump cold tes HTF inlet temperature [C]"),
 	NULL},
{"T_hp_HT_htf_cold_in", (getter)Outputs_get_T_hp_HT_htf_cold_in,(setter)0,
	PyDoc_STR("*sequence*: Heat pump hot tes HTF inlet temperature [C]"),
 	NULL},
{"T_hp_HT_htf_hot_out", (getter)Outputs_get_T_hp_HT_htf_hot_out,(setter)0,
	PyDoc_STR("*sequence*: Heat pump hot tes HTF outlet temperature [C]"),
 	NULL},
{"T_pc_CT_htf_cold_in", (getter)Outputs_get_T_pc_CT_htf_cold_in,(setter)0,
	PyDoc_STR("*sequence*: PC cold tes HTF inlet temperature [C]"),
 	NULL},
{"T_pc_CT_htf_hot_out", (getter)Outputs_get_T_pc_CT_htf_hot_out,(setter)0,
	PyDoc_STR("*sequence*: PC cold tes HTF outlet temperature [C]"),
 	NULL},
{"T_pc_HT_htf_cold_out", (getter)Outputs_get_T_pc_HT_htf_cold_out,(setter)0,
	PyDoc_STR("*sequence*: PC hot tes HTF outlet temperature [C]"),
 	NULL},
{"T_pc_HT_htf_hot_in", (getter)Outputs_get_T_pc_HT_htf_hot_in,(setter)0,
	PyDoc_STR("*sequence*: PC hot tes HTF inlet temperature [C]"),
 	NULL},
{"T_tes_cold", (getter)Outputs_get_T_tes_cold,(setter)0,
	PyDoc_STR("*sequence*: TES cold temperature [C]"),
 	NULL},
{"T_tes_hot", (getter)Outputs_get_T_tes_hot,(setter)0,
	PyDoc_STR("*sequence*: TES hot temperature [C]"),
 	NULL},
{"V_CT_tes_htf_avail", (getter)Outputs_get_V_CT_tes_htf_avail,(setter)0,
	PyDoc_STR("*float*: Volume of cold TES HTF available for heat transfer [m3]"),
 	NULL},
{"V_CT_tes_htf_total", (getter)Outputs_get_V_CT_tes_htf_total,(setter)0,
	PyDoc_STR("*float*: Total cold TES HTF volume [m3]"),
 	NULL},
{"V_tes_htf_avail", (getter)Outputs_get_V_tes_htf_avail,(setter)0,
	PyDoc_STR("*float*: Volume of TES HTF available for heat transfer [m3]"),
 	NULL},
{"V_tes_htf_total", (getter)Outputs_get_V_tes_htf_total,(setter)0,
	PyDoc_STR("*float*: Total TES HTF volume [m3]"),
 	NULL},
{"W_dot_bop_design", (getter)Outputs_get_W_dot_bop_design,(setter)0,
	PyDoc_STR("*float*: BOP parasitics at design [MWe]"),
 	NULL},
{"W_dot_bop_parasitics", (getter)Outputs_get_W_dot_bop_parasitics,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power plant generation-dependent laod [MWe]"),
 	NULL},
{"W_dot_fixed", (getter)Outputs_get_W_dot_fixed,(setter)0,
	PyDoc_STR("*float*: Fixed parasitic at design [MWe]"),
 	NULL},
{"W_dot_fixed_parasitics", (getter)Outputs_get_W_dot_fixed_parasitics,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power plant fixed load [MWe]"),
 	NULL},
{"W_dot_hp_CT_htf_pump", (getter)Outputs_get_W_dot_hp_CT_htf_pump,(setter)0,
	PyDoc_STR("*sequence*: Heat pump cold tes HTF pump power [MWe]"),
 	NULL},
{"W_dot_hp_CT_htf_pump_des", (getter)Outputs_get_W_dot_hp_CT_htf_pump_des,(setter)0,
	PyDoc_STR("*float*: Heat pump CT HTF pump power [MWe]"),
 	NULL},
{"W_dot_hp_HT_htf_pump", (getter)Outputs_get_W_dot_hp_HT_htf_pump,(setter)0,
	PyDoc_STR("*sequence*: Heat pump hot tes HTF pump power [MWe]"),
 	NULL},
{"W_dot_hp_HT_htf_pump_des", (getter)Outputs_get_W_dot_hp_HT_htf_pump_des,(setter)0,
	PyDoc_STR("*float*: Heat pump HT HTF pump power [MWe]"),
 	NULL},
{"W_dot_hp_elec_parasitic_des", (getter)Outputs_get_W_dot_hp_elec_parasitic_des,(setter)0,
	PyDoc_STR("*float*: Heat pump parasitic power [MWe]"),
 	NULL},
{"W_dot_hp_in_net_des", (getter)Outputs_get_W_dot_hp_in_net_des,(setter)0,
	PyDoc_STR("*float*: Heat pump total power consumption [MWe]"),
 	NULL},
{"W_dot_hp_in_thermo_des", (getter)Outputs_get_W_dot_hp_in_thermo_des,(setter)0,
	PyDoc_STR("*float*: Heat pump power into working fluid [MWe]"),
 	NULL},
{"W_dot_hp_net", (getter)Outputs_get_W_dot_hp_net,(setter)0,
	PyDoc_STR("*sequence*: Heat pump total power in [MWe]"),
 	NULL},
{"W_dot_hp_parasitics", (getter)Outputs_get_W_dot_hp_parasitics,(setter)0,
	PyDoc_STR("*sequence*: Heat pump thermodynamic parasitics [MWe]"),
 	NULL},
{"W_dot_hp_thermo", (getter)Outputs_get_W_dot_hp_thermo,(setter)0,
	PyDoc_STR("*sequence*: Heat pump thermodynamic power in [MWe]"),
 	NULL},
{"W_dot_out_net", (getter)Outputs_get_W_dot_out_net,(setter)0,
	PyDoc_STR("*sequence*: Total electric power to grid [MWe]"),
 	NULL},
{"W_dot_pc_CT_htf_pump", (getter)Outputs_get_W_dot_pc_CT_htf_pump,(setter)0,
	PyDoc_STR("*sequence*: PC cold tes HTF pump power [MWe]"),
 	NULL},
{"W_dot_pc_CT_htf_pump_des", (getter)Outputs_get_W_dot_pc_CT_htf_pump_des,(setter)0,
	PyDoc_STR("*float*: Cycle CT HTF pump power [MWe]"),
 	NULL},
{"W_dot_pc_HT_htf_pump", (getter)Outputs_get_W_dot_pc_HT_htf_pump,(setter)0,
	PyDoc_STR("*sequence*: PC hot tes HTF pump power [MWe]"),
 	NULL},
{"W_dot_pc_HT_htf_pump_des", (getter)Outputs_get_W_dot_pc_HT_htf_pump_des,(setter)0,
	PyDoc_STR("*float*: Cycle HT HTF pump power [MWe]"),
 	NULL},
{"W_dot_pc_elec_parasitic_des", (getter)Outputs_get_W_dot_pc_elec_parasitic_des,(setter)0,
	PyDoc_STR("*float*: Cycle parasitic power [MWe]"),
 	NULL},
{"W_dot_pc_net_des", (getter)Outputs_get_W_dot_pc_net_des,(setter)0,
	PyDoc_STR("*float*: Cycle net power generation [MWe]"),
 	NULL},
{"W_dot_pc_parasitics", (getter)Outputs_get_W_dot_pc_parasitics,(setter)0,
	PyDoc_STR("*sequence*: PC parasitics including cooling power [MWe]"),
 	NULL},
{"W_dot_pc_thermo_out", (getter)Outputs_get_W_dot_pc_thermo_out,(setter)0,
	PyDoc_STR("*sequence*: PC thermodynamic power out [MWe]"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual total electric power to grid [kWhe]"),
 	NULL},
{"annual_energy_distribution_time", (getter)Outputs_get_annual_energy_distribution_time,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Annual energy production as function of time [kW]"),
 	NULL},
{"avg_suboptimal_rel_mip_gap", (getter)Outputs_get_avg_suboptimal_rel_mip_gap,(setter)0,
	PyDoc_STR("*float*: Average suboptimal relative MIP gap [%]"),
 	NULL},
{"bop_cost_calc", (getter)Outputs_get_bop_cost_calc,(setter)0,
	PyDoc_STR("*float*: BOP cost [$]"),
 	NULL},
{"charge_capacity", (getter)Outputs_get_charge_capacity,(setter)0,
	PyDoc_STR("*float*: Total electricity consumption at design-point charge [MWe]"),
 	NULL},
{"construction_financing_cost", (getter)Outputs_get_construction_financing_cost,(setter)0,
	PyDoc_STR("*float*: Total construction financing cost [$]"),
 	NULL},
{"contingency_cost_calc", (getter)Outputs_get_contingency_cost_calc,(setter)0,
	PyDoc_STR("*float*: Contingency cost [$]"),
 	NULL},
{"cop_hot_hp_thermo", (getter)Outputs_get_cop_hot_hp_thermo,(setter)0,
	PyDoc_STR("*sequence*: Heat pump thermodynamic hot COP"),
 	NULL},
{"cp_battery_nameplate", (getter)Outputs_get_cp_battery_nameplate,(setter)0,
	PyDoc_STR("*float*: Battery nameplate [MWe]"),
 	NULL},
{"cp_system_nameplate", (getter)Outputs_get_cp_system_nameplate,(setter)0,
	PyDoc_STR("*float*: System capacity for capacity payments [MWe]"),
 	NULL},
{"cycle_cost_calc", (getter)Outputs_get_cycle_cost_calc,(setter)0,
	PyDoc_STR("*float*: Cycle cost [$]"),
 	NULL},
{"d_CT_tank_tes", (getter)Outputs_get_d_CT_tank_tes,(setter)0,
	PyDoc_STR("*float*: Diameter of cold TES tank [m]"),
 	NULL},
{"d_tank_tes", (getter)Outputs_get_d_tank_tes,(setter)0,
	PyDoc_STR("*float*: Diameter of TES tank [m]"),
 	NULL},
{"direct_subtotal_cost_calc", (getter)Outputs_get_direct_subtotal_cost_calc,(setter)0,
	PyDoc_STR("*float*: Direct subtotal cost [$]"),
 	NULL},
{"disp_iter_ann", (getter)Outputs_get_disp_iter_ann,(setter)0,
	PyDoc_STR("*float*: Annual sum of dispatch solver iterations"),
 	NULL},
{"disp_obj_relax", (getter)Outputs_get_disp_obj_relax,(setter)0,
	PyDoc_STR("*sequence*: Dispatch objective function - relaxed max"),
 	NULL},
{"disp_objective", (getter)Outputs_get_disp_objective,(setter)0,
	PyDoc_STR("*sequence*: Dispatch objective function value"),
 	NULL},
{"disp_objective_ann", (getter)Outputs_get_disp_objective_ann,(setter)0,
	PyDoc_STR("*float*: Annual sum of dispatch objective function value [$]"),
 	NULL},
{"disp_pceff_expected", (getter)Outputs_get_disp_pceff_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected power cycle efficiency adj."),
 	NULL},
{"disp_presolve_nconstr", (getter)Outputs_get_disp_presolve_nconstr,(setter)0,
	PyDoc_STR("*sequence*: Dispatch number of constraints in problem"),
 	NULL},
{"disp_presolve_nconstr_ann", (getter)Outputs_get_disp_presolve_nconstr_ann,(setter)0,
	PyDoc_STR("*float*: Annual sum of dispatch problem constraint count"),
 	NULL},
{"disp_presolve_nvar", (getter)Outputs_get_disp_presolve_nvar,(setter)0,
	PyDoc_STR("*sequence*: Dispatch number of variables in problem"),
 	NULL},
{"disp_presolve_nvar_ann", (getter)Outputs_get_disp_presolve_nvar_ann,(setter)0,
	PyDoc_STR("*float*: Annual sum of dispatch problem variable count"),
 	NULL},
{"disp_qpbsu_expected", (getter)Outputs_get_disp_qpbsu_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected power cycle startup energy [MWht]"),
 	NULL},
{"disp_qsfprod_expected", (getter)Outputs_get_disp_qsfprod_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected heat pump heat generation [MWt]"),
 	NULL},
{"disp_qsfsu_expected", (getter)Outputs_get_disp_qsfsu_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected heat pump startup enegy [MWt]"),
 	NULL},
{"disp_rel_mip_gap", (getter)Outputs_get_disp_rel_mip_gap,(setter)0,
	PyDoc_STR("*sequence*: Dispatch relative MIP gap"),
 	NULL},
{"disp_rev_expected", (getter)Outputs_get_disp_rev_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected revenue factor"),
 	NULL},
{"disp_solve_iter", (getter)Outputs_get_disp_solve_iter,(setter)0,
	PyDoc_STR("*sequence*: Dispatch iterations count"),
 	NULL},
{"disp_solve_state", (getter)Outputs_get_disp_solve_state,(setter)0,
	PyDoc_STR("*sequence*: Dispatch solver state"),
 	NULL},
{"disp_solve_state_ann", (getter)Outputs_get_disp_solve_state_ann,(setter)0,
	PyDoc_STR("*float*: Annual sum of dispatch solve state"),
 	NULL},
{"disp_solve_time", (getter)Outputs_get_disp_solve_time,(setter)0,
	PyDoc_STR("*sequence*: Dispatch solver time [sec]"),
 	NULL},
{"disp_solve_time_ann", (getter)Outputs_get_disp_solve_time_ann,(setter)0,
	PyDoc_STR("*float*: Annual sum of dispatch solver time [sec]"),
 	NULL},
{"disp_subopt_flag", (getter)Outputs_get_disp_subopt_flag,(setter)0,
	PyDoc_STR("*sequence*: Dispatch suboptimal solution flag"),
 	NULL},
{"disp_tes_expected", (getter)Outputs_get_disp_tes_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected TES charge level [MWht]"),
 	NULL},
{"disp_wpb_expected", (getter)Outputs_get_disp_wpb_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected power generation [MWe]"),
 	NULL},
{"e_ch_tes", (getter)Outputs_get_e_ch_tes,(setter)0,
	PyDoc_STR("*sequence*: TES charge state [MWht]"),
 	NULL},
{"elec_purchase_price_mult", (getter)Outputs_get_elec_purchase_price_mult,(setter)0,
	PyDoc_STR("*sequence*: Electricity purchase price multiplier"),
 	NULL},
{"epc_cost_calc", (getter)Outputs_get_epc_cost_calc,(setter)0,
	PyDoc_STR("*float*: EPC cost [$]"),
 	NULL},
{"eta_pc_net_des", (getter)Outputs_get_eta_pc_net_des,(setter)0,
	PyDoc_STR("*float*: Cycle net efficiency [-]"),
 	NULL},
{"eta_pc_thermo", (getter)Outputs_get_eta_pc_thermo,(setter)0,
	PyDoc_STR("*sequence*: PC thermodynamic efficiency"),
 	NULL},
{"flip_target_percent", (getter)Outputs_get_flip_target_percent,(setter)0,
	PyDoc_STR("*float*: After-tax IRR target [%]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: Total electric power to grid with available derate [kWe]"),
 	NULL},
{"heater_cost_calc", (getter)Outputs_get_heater_cost_calc,(setter)0,
	PyDoc_STR("*float*: Heater cost [$]"),
 	NULL},
{"installed_per_cap_cost_calc", (getter)Outputs_get_installed_per_cap_cost_calc,(setter)0,
	PyDoc_STR("*float*: Installed cost per capacity [$/kWe]"),
 	NULL},
{"land_cost_calc", (getter)Outputs_get_land_cost_calc,(setter)0,
	PyDoc_STR("*float*: Land cost [$]"),
 	NULL},
{"m_dot_balance", (getter)Outputs_get_m_dot_balance,(setter)0,
	PyDoc_STR("*sequence*: Relative mass flow balance error"),
 	NULL},
{"m_dot_hp_CT_htf", (getter)Outputs_get_m_dot_hp_CT_htf,(setter)0,
	PyDoc_STR("*sequence*: Heat pump cold tes HTF mass flow rate [kg/s]"),
 	NULL},
{"m_dot_hp_CT_htf_des", (getter)Outputs_get_m_dot_hp_CT_htf_des,(setter)0,
	PyDoc_STR("*float*: Heat pump CT HTF mass flow rate [kg/s]"),
 	NULL},
{"m_dot_hp_HT_htf", (getter)Outputs_get_m_dot_hp_HT_htf,(setter)0,
	PyDoc_STR("*sequence*: Heat pump hot tes HTF mass flow rate [kg/s]"),
 	NULL},
{"m_dot_hp_HT_htf_des", (getter)Outputs_get_m_dot_hp_HT_htf_des,(setter)0,
	PyDoc_STR("*float*: Heat pump HT HTF mass flow rate [kg/s]"),
 	NULL},
{"m_dot_pc_CT_htf", (getter)Outputs_get_m_dot_pc_CT_htf,(setter)0,
	PyDoc_STR("*sequence*: PC cold tes HTF mass flow rate [kg/s]"),
 	NULL},
{"m_dot_pc_CT_htf_des", (getter)Outputs_get_m_dot_pc_CT_htf_des,(setter)0,
	PyDoc_STR("*float*: Cycle CT HTF mass flow rate [kg/s]"),
 	NULL},
{"m_dot_pc_HT_htf", (getter)Outputs_get_m_dot_pc_HT_htf,(setter)0,
	PyDoc_STR("*sequence*: PC hot tes HTF mass flow rate [kg/s]"),
 	NULL},
{"m_dot_pc_HT_htf_des", (getter)Outputs_get_m_dot_pc_HT_htf_des,(setter)0,
	PyDoc_STR("*float*: Cycle HT HTF mass flow rate [kg/s]"),
 	NULL},
{"mass_CT_tes_cold", (getter)Outputs_get_mass_CT_tes_cold,(setter)0,
	PyDoc_STR("*sequence*: TES cold tank mass (end) [kg]"),
 	NULL},
{"mass_CT_tes_hot", (getter)Outputs_get_mass_CT_tes_hot,(setter)0,
	PyDoc_STR("*sequence*: TES hot tank mass (end) [kg]"),
 	NULL},
{"mass_tes_cold", (getter)Outputs_get_mass_tes_cold,(setter)0,
	PyDoc_STR("*sequence*: TES cold tank mass (end) [kg]"),
 	NULL},
{"mass_tes_hot", (getter)Outputs_get_mass_tes_hot,(setter)0,
	PyDoc_STR("*sequence*: TES hot tank mass (end) [kg]"),
 	NULL},
{"n_op_modes", (getter)Outputs_get_n_op_modes,(setter)0,
	PyDoc_STR("*sequence*: Operating modes in reporting timestep"),
 	NULL},
{"nameplate", (getter)Outputs_get_nameplate,(setter)0,
	PyDoc_STR("*float*: Nameplate capacity (discharge) [MWe]"),
 	NULL},
{"op_mode_1", (getter)Outputs_get_op_mode_1,(setter)0,
	PyDoc_STR("*sequence*: 1st operating mode"),
 	NULL},
{"op_mode_2", (getter)Outputs_get_op_mode_2,(setter)0,
	PyDoc_STR("*sequence*: 2nd operating mode, if applicable"),
 	NULL},
{"op_mode_3", (getter)Outputs_get_op_mode_3,(setter)0,
	PyDoc_STR("*sequence*: 3rd operating mode, if applicable"),
 	NULL},
{"operating_modes_a", (getter)Outputs_get_operating_modes_a,(setter)0,
	PyDoc_STR("*sequence*: First 3 operating modes tried"),
 	NULL},
{"operating_modes_b", (getter)Outputs_get_operating_modes_b,(setter)0,
	PyDoc_STR("*sequence*: Next 3 operating modes tried"),
 	NULL},
{"operating_modes_c", (getter)Outputs_get_operating_modes_c,(setter)0,
	PyDoc_STR("*sequence*: Final 3 operating modes tried"),
 	NULL},
{"ppa_soln_mode", (getter)Outputs_get_ppa_soln_mode,(setter)0,
	PyDoc_STR("*float*: PPA solution mode [0/1]"),
 	NULL},
{"q_balance", (getter)Outputs_get_q_balance,(setter)0,
	PyDoc_STR("*sequence*: Relative energy balance error"),
 	NULL},
{"q_dot_CT_tes_heater", (getter)Outputs_get_q_dot_CT_tes_heater,(setter)0,
	PyDoc_STR("*sequence*: TES freeze protection power [MWe]"),
 	NULL},
{"q_dot_CT_tes_losses", (getter)Outputs_get_q_dot_CT_tes_losses,(setter)0,
	PyDoc_STR("*sequence*: TES thermal losses [MWt]"),
 	NULL},
{"q_dot_ch_tes", (getter)Outputs_get_q_dot_ch_tes,(setter)0,
	PyDoc_STR("*sequence*: TES charge thermal power [MWt]"),
 	NULL},
{"q_dot_dc_tes", (getter)Outputs_get_q_dot_dc_tes,(setter)0,
	PyDoc_STR("*sequence*: TES discharge thermal power [MWt]"),
 	NULL},
{"q_dot_hp_cold_in_des", (getter)Outputs_get_q_dot_hp_cold_in_des,(setter)0,
	PyDoc_STR("*float*: Heat pump heat input [MWt]"),
 	NULL},
{"q_dot_hp_from_CT_htf", (getter)Outputs_get_q_dot_hp_from_CT_htf,(setter)0,
	PyDoc_STR("*sequence*: Heat pump thermal power from cold tes HTF [MWt]"),
 	NULL},
{"q_dot_hp_hot_out_des", (getter)Outputs_get_q_dot_hp_hot_out_des,(setter)0,
	PyDoc_STR("*float*: Heat pump heat output [MWt]"),
 	NULL},
{"q_dot_hp_startup", (getter)Outputs_get_q_dot_hp_startup,(setter)0,
	PyDoc_STR("*sequence*: Heat pump startup power [MWt]"),
 	NULL},
{"q_dot_hp_to_HT_htf", (getter)Outputs_get_q_dot_hp_to_HT_htf,(setter)0,
	PyDoc_STR("*sequence*: Heat pump thermal power to hot tes HTF [MWt]"),
 	NULL},
{"q_dot_loss_CT_tes_des", (getter)Outputs_get_q_dot_loss_CT_tes_des,(setter)0,
	PyDoc_STR("*float*: Cold TES thermal loss at design [MWt]"),
 	NULL},
{"q_dot_loss_tes_des", (getter)Outputs_get_q_dot_loss_tes_des,(setter)0,
	PyDoc_STR("*float*: TES thermal loss at design [MWt]"),
 	NULL},
{"q_dot_pc_cold_out_thermo_des", (getter)Outputs_get_q_dot_pc_cold_out_thermo_des,(setter)0,
	PyDoc_STR("*float*: Cycle total heat rejection [MWt]"),
 	NULL},
{"q_dot_pc_cold_to_CTES_des", (getter)Outputs_get_q_dot_pc_cold_to_CTES_des,(setter)0,
	PyDoc_STR("*float*: Cycle heat to cold TES [MWt]"),
 	NULL},
{"q_dot_pc_cold_to_surroundings_des", (getter)Outputs_get_q_dot_pc_cold_to_surroundings_des,(setter)0,
	PyDoc_STR("*float*: Cycle heat to surroundings [MWt]"),
 	NULL},
{"q_dot_pc_from_HT_htf", (getter)Outputs_get_q_dot_pc_from_HT_htf,(setter)0,
	PyDoc_STR("*sequence*: PC thermal power from hot tes HTF [MWt]"),
 	NULL},
{"q_dot_pc_hot_in_des", (getter)Outputs_get_q_dot_pc_hot_in_des,(setter)0,
	PyDoc_STR("*float*: Cycle heat input [MWt]"),
 	NULL},
{"q_dot_pc_rejected", (getter)Outputs_get_q_dot_pc_rejected,(setter)0,
	PyDoc_STR("*sequence*: PC thermal power rejected to surroundings [MWt]"),
 	NULL},
{"q_dot_pc_startup", (getter)Outputs_get_q_dot_pc_startup,(setter)0,
	PyDoc_STR("*sequence*: PC startup power [MWt]"),
 	NULL},
{"q_dot_pc_thermo_out", (getter)Outputs_get_q_dot_pc_thermo_out,(setter)0,
	PyDoc_STR("*sequence*: PC total heat leaving cycle [MWt]"),
 	NULL},
{"q_dot_pc_to_CT_htf", (getter)Outputs_get_q_dot_pc_to_CT_htf,(setter)0,
	PyDoc_STR("*sequence*: PC thermal power to cold tes HTF [MWt]"),
 	NULL},
{"q_dot_tes_heater", (getter)Outputs_get_q_dot_tes_heater,(setter)0,
	PyDoc_STR("*sequence*: TES freeze protection power [MWe]"),
 	NULL},
{"q_dot_tes_losses", (getter)Outputs_get_q_dot_tes_losses,(setter)0,
	PyDoc_STR("*sequence*: TES thermal losses [MWt]"),
 	NULL},
{"q_pc_target", (getter)Outputs_get_q_pc_target,(setter)0,
	PyDoc_STR("*sequence*: Controller target pc heat input [MWt]"),
 	NULL},
{"rte_net", (getter)Outputs_get_rte_net,(setter)0,
	PyDoc_STR("*float*: Net round-trip efficiency considering all parasitics [MWe]"),
 	NULL},
{"rte_thermo", (getter)Outputs_get_rte_thermo,(setter)0,
	PyDoc_STR("*float*: Round-trip efficiency of working fluid cycles [MWe]"),
 	NULL},
{"sales_tax_cost_calc", (getter)Outputs_get_sales_tax_cost_calc,(setter)0,
	PyDoc_STR("*float*: Sales tax cost [$]"),
 	NULL},
{"system_capacity", (getter)Outputs_get_system_capacity,(setter)0,
	PyDoc_STR("*float*: System capacity (discharge) [kWe]"),
 	NULL},
{"tdry", (getter)Outputs_get_tdry,(setter)0,
	PyDoc_STR("*sequence*: Resource dry Bulb temperature [C]"),
 	NULL},
{"tes_cost_calc", (getter)Outputs_get_tes_cost_calc,(setter)0,
	PyDoc_STR("*float*: TES cost [$]"),
 	NULL},
{"time_hr", (getter)Outputs_get_time_hr,(setter)0,
	PyDoc_STR("*sequence*: Time at end of timestep [hr]"),
 	NULL},
{"total_direct_cost_calc", (getter)Outputs_get_total_direct_cost_calc,(setter)0,
	PyDoc_STR("*float*: Total direct cost [$]"),
 	NULL},
{"total_indirect_cost_calc", (getter)Outputs_get_total_indirect_cost_calc,(setter)0,
	PyDoc_STR("*float*: Total indirect cost [$]"),
 	NULL},
{"total_installed_cost", (getter)Outputs_get_total_installed_cost,(setter)0,
	PyDoc_STR("*float*: Total installed cost [$]"),
 	NULL},
{"tou_period", (getter)Outputs_get_tou_period,(setter)0,
	PyDoc_STR("*sequence*: Time of use period"),
 	NULL},
{"tshours_heater", (getter)Outputs_get_tshours_heater,(setter)0,
	PyDoc_STR("*float*: Hours of TES relative to heater output [hr]"),
 	NULL},
{"twet", (getter)Outputs_get_twet,(setter)0,
	PyDoc_STR("*sequence*: Resource wet Bulb temperature [C]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesPtes.Outputs",             /*tp_name*/
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
 * EtesPtes
 */

static PyTypeObject EtesPtes_Type;

static CmodObject *
newEtesPtesObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &EtesPtes_Type);

	PySAM_TECH_ATTR()

	PyObject* SolarResource_obj = SolarResource_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SolarResource", SolarResource_obj);
	Py_DECREF(SolarResource_obj);

	PyObject* SystemControl_obj = SystemControl_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemControl", SystemControl_obj);
	Py_DECREF(SystemControl_obj);

	PyObject* FinancialModel_obj = FinancialModel_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FinancialModel", FinancialModel_obj);
	Py_DECREF(FinancialModel_obj);

	PyObject* SystemDesign_obj = SystemDesign_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemDesign", SystemDesign_obj);
	Py_DECREF(SystemDesign_obj);

	PyObject* ThermalStorage_obj = ThermalStorage_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ThermalStorage", ThermalStorage_obj);
	Py_DECREF(ThermalStorage_obj);

	PyObject* Heater_obj = Heater_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Heater", Heater_obj);
	Py_DECREF(Heater_obj);

	PyObject* PowerCycle_obj = PowerCycle_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "PowerCycle", PowerCycle_obj);
	Py_DECREF(PowerCycle_obj);

	PyObject* HotThermalStorage_obj = HotThermalStorage_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "HotThermalStorage", HotThermalStorage_obj);
	Py_DECREF(HotThermalStorage_obj);

	PyObject* ColdThermalStorage_obj = ColdThermalStorage_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ColdThermalStorage", ColdThermalStorage_obj);
	Py_DECREF(ColdThermalStorage_obj);

	PyObject* TimeOfDeliveryFactors_obj = TimeOfDeliveryFactors_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TimeOfDeliveryFactors", TimeOfDeliveryFactors_obj);
	Py_DECREF(TimeOfDeliveryFactors_obj);

	PyObject* Revenue_obj = Revenue_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Revenue", Revenue_obj);
	Py_DECREF(Revenue_obj);

	PyObject* SystemCosts_obj = SystemCosts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemCosts", SystemCosts_obj);
	Py_DECREF(SystemCosts_obj);

	PyObject* FinancialParameters_obj = FinancialParameters_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FinancialParameters", FinancialParameters_obj);
	Py_DECREF(FinancialParameters_obj);

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

/* EtesPtes methods */

static void
EtesPtes_dealloc(CmodObject *self)
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
EtesPtes_get_data_ptr(CmodObject *self, PyObject *args)
{
	PyObject* ptr = PyLong_FromVoidPtr((void*)self->data_ptr);
	return ptr;
}


static PyObject *
EtesPtes_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_EtesPtes_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
EtesPtes_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "EtesPtes"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
EtesPtes_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "EtesPtes"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
EtesPtes_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
EtesPtes_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
EtesPtes_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef EtesPtes_methods[] = {
		{"execute",           (PyCFunction)EtesPtes_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)EtesPtes_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Solar Resource': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)EtesPtes_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Solar Resource': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)EtesPtes_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)EtesPtes_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)EtesPtes_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{"get_data_ptr",           (PyCFunction)EtesPtes_get_data_ptr,  METH_VARARGS,
				PyDoc_STR("get_data_ptr() -> Pointer\n Get ssc_data_t pointer")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
EtesPtes_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
EtesPtes_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject EtesPtes_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesPtes",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)EtesPtes_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)EtesPtes_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)EtesPtes_getattro, /*tp_getattro*/
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
		EtesPtes_methods,      /*tp_methods*/
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


/* Function of no arguments returning new EtesPtes object */

static PyObject *
EtesPtes_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newEtesPtesObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
EtesPtes_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newEtesPtesObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
EtesPtes_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newEtesPtesObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "EtesPtes", def) < 0) {
		EtesPtes_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
EtesPtes_from_existing(PyObject *self, PyObject *args)
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

	rv = newEtesPtesObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "EtesPtes", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef EtesPtesModule_methods[] = {
		{"new",             EtesPtes_new,         METH_VARARGS,
				PyDoc_STR("new() -> EtesPtes")},
		{"default",             EtesPtes_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> EtesPtes\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"PTESSingleOwner\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             EtesPtes_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> EtesPtes\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   EtesPtes_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> EtesPtes\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Pumped thermal energy storage");


static int
EtesPtesModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	EtesPtes_Type.tp_dict = PyDict_New();
	if (!EtesPtes_Type.tp_dict) { goto fail; }

	/// Add the SolarResource type object to EtesPtes_Type
	if (PyType_Ready(&SolarResource_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesPtes_Type.tp_dict,
				"SolarResource",
				(PyObject*)&SolarResource_Type);
	Py_DECREF(&SolarResource_Type);

	/// Add the SystemControl type object to EtesPtes_Type
	if (PyType_Ready(&SystemControl_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesPtes_Type.tp_dict,
				"SystemControl",
				(PyObject*)&SystemControl_Type);
	Py_DECREF(&SystemControl_Type);

	/// Add the FinancialModel type object to EtesPtes_Type
	if (PyType_Ready(&FinancialModel_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesPtes_Type.tp_dict,
				"FinancialModel",
				(PyObject*)&FinancialModel_Type);
	Py_DECREF(&FinancialModel_Type);

	/// Add the SystemDesign type object to EtesPtes_Type
	if (PyType_Ready(&SystemDesign_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesPtes_Type.tp_dict,
				"SystemDesign",
				(PyObject*)&SystemDesign_Type);
	Py_DECREF(&SystemDesign_Type);

	/// Add the ThermalStorage type object to EtesPtes_Type
	if (PyType_Ready(&ThermalStorage_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesPtes_Type.tp_dict,
				"ThermalStorage",
				(PyObject*)&ThermalStorage_Type);
	Py_DECREF(&ThermalStorage_Type);

	/// Add the Heater type object to EtesPtes_Type
	if (PyType_Ready(&Heater_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesPtes_Type.tp_dict,
				"Heater",
				(PyObject*)&Heater_Type);
	Py_DECREF(&Heater_Type);

	/// Add the PowerCycle type object to EtesPtes_Type
	if (PyType_Ready(&PowerCycle_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesPtes_Type.tp_dict,
				"PowerCycle",
				(PyObject*)&PowerCycle_Type);
	Py_DECREF(&PowerCycle_Type);

	/// Add the HotThermalStorage type object to EtesPtes_Type
	if (PyType_Ready(&HotThermalStorage_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesPtes_Type.tp_dict,
				"HotThermalStorage",
				(PyObject*)&HotThermalStorage_Type);
	Py_DECREF(&HotThermalStorage_Type);

	/// Add the ColdThermalStorage type object to EtesPtes_Type
	if (PyType_Ready(&ColdThermalStorage_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesPtes_Type.tp_dict,
				"ColdThermalStorage",
				(PyObject*)&ColdThermalStorage_Type);
	Py_DECREF(&ColdThermalStorage_Type);

	/// Add the TimeOfDeliveryFactors type object to EtesPtes_Type
	if (PyType_Ready(&TimeOfDeliveryFactors_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesPtes_Type.tp_dict,
				"TimeOfDeliveryFactors",
				(PyObject*)&TimeOfDeliveryFactors_Type);
	Py_DECREF(&TimeOfDeliveryFactors_Type);

	/// Add the Revenue type object to EtesPtes_Type
	if (PyType_Ready(&Revenue_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesPtes_Type.tp_dict,
				"Revenue",
				(PyObject*)&Revenue_Type);
	Py_DECREF(&Revenue_Type);

	/// Add the SystemCosts type object to EtesPtes_Type
	if (PyType_Ready(&SystemCosts_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesPtes_Type.tp_dict,
				"SystemCosts",
				(PyObject*)&SystemCosts_Type);
	Py_DECREF(&SystemCosts_Type);

	/// Add the FinancialParameters type object to EtesPtes_Type
	if (PyType_Ready(&FinancialParameters_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesPtes_Type.tp_dict,
				"FinancialParameters",
				(PyObject*)&FinancialParameters_Type);
	Py_DECREF(&FinancialParameters_Type);

	/// Add the Outputs type object to EtesPtes_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesPtes_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the EtesPtes type object to the module
	if (PyType_Ready(&EtesPtes_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"EtesPtes",
				(PyObject*)&EtesPtes_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot EtesPtesModule_slots[] = {
		{Py_mod_exec, EtesPtesModule_exec},
		{0, NULL},
};

static struct PyModuleDef EtesPtesModule = {
		PyModuleDef_HEAD_INIT,
		"EtesPtes",
		module_doc,
		0,
		EtesPtesModule_methods,
		EtesPtesModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_EtesPtes(void)
{
	return PyModuleDef_Init(&EtesPtesModule);
}