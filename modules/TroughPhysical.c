#include <Python.h>

#include <SAM_TroughPhysical.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * SystemControl Group
 */ 

static PyTypeObject SystemControl_Type;

static PyObject *
SystemControl_new(SAM_TroughPhysical data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "SystemControl")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysical", "SystemControl")){
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
SystemControl_get_T_in_loop_initial(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_T_in_loop_initial_nget, self->data_ptr);
}

static int
SystemControl_set_T_in_loop_initial(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_T_in_loop_initial_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_T_out_loop_initial(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_T_out_loop_initial_nget, self->data_ptr);
}

static int
SystemControl_set_T_out_loop_initial(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_T_out_loop_initial_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_T_out_scas_initial(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SystemControl_T_out_scas_initial_aget, self->data_ptr);
}

static int
SystemControl_set_T_out_scas_initial(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SystemControl_T_out_scas_initial_aset, self->data_ptr);
}

static PyObject *
SystemControl_get_T_tank_cold_init(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_T_tank_cold_init_nget, self->data_ptr);
}

static int
SystemControl_set_T_tank_cold_init(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_T_tank_cold_init_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_T_tank_hot_init(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_T_tank_hot_init_nget, self->data_ptr);
}

static int
SystemControl_set_T_tank_hot_init(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_T_tank_hot_init_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_defocus_initial(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_defocus_initial_nget, self->data_ptr);
}

static int
SystemControl_set_defocus_initial(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_defocus_initial_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_csu_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_disp_csu_cost_nget, self->data_ptr);
}

static int
SystemControl_set_disp_csu_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_disp_csu_cost_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_inventory_incentive(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_disp_inventory_incentive_nget, self->data_ptr);
}

static int
SystemControl_set_disp_inventory_incentive(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_disp_inventory_incentive_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_rsu_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_disp_rsu_cost_nget, self->data_ptr);
}

static int
SystemControl_set_disp_rsu_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_disp_rsu_cost_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_is_dispatch_targets(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_is_dispatch_targets_nget, self->data_ptr);
}

static int
SystemControl_set_is_dispatch_targets(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_is_dispatch_targets_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_is_pc_sb_allowed_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SystemControl_is_pc_sb_allowed_in_aget, self->data_ptr);
}

static int
SystemControl_set_is_pc_sb_allowed_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SystemControl_is_pc_sb_allowed_in_aset, self->data_ptr);
}

static PyObject *
SystemControl_get_is_pc_su_allowed_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SystemControl_is_pc_su_allowed_in_aget, self->data_ptr);
}

static int
SystemControl_set_is_pc_su_allowed_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SystemControl_is_pc_su_allowed_in_aset, self->data_ptr);
}

static PyObject *
SystemControl_get_is_rec_su_allowed_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SystemControl_is_rec_su_allowed_in_aget, self->data_ptr);
}

static int
SystemControl_set_is_rec_su_allowed_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SystemControl_is_rec_su_allowed_in_aset, self->data_ptr);
}

static PyObject *
SystemControl_get_pc_op_mode_initial(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_pc_op_mode_initial_nget, self->data_ptr);
}

static int
SystemControl_set_pc_op_mode_initial(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_pc_op_mode_initial_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_pc_startup_energy_remain_initial(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_pc_startup_energy_remain_initial_nget, self->data_ptr);
}

static int
SystemControl_set_pc_startup_energy_remain_initial(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_pc_startup_energy_remain_initial_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_pc_startup_time_remain_init(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_pc_startup_time_remain_init_nget, self->data_ptr);
}

static int
SystemControl_set_pc_startup_time_remain_init(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_pc_startup_time_remain_init_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_q_pc_max_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SystemControl_q_pc_max_in_aget, self->data_ptr);
}

static int
SystemControl_set_q_pc_max_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SystemControl_q_pc_max_in_aset, self->data_ptr);
}

static PyObject *
SystemControl_get_q_pc_target_on_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SystemControl_q_pc_target_on_in_aget, self->data_ptr);
}

static int
SystemControl_set_q_pc_target_on_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SystemControl_q_pc_target_on_in_aset, self->data_ptr);
}

static PyObject *
SystemControl_get_q_pc_target_su_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SystemControl_q_pc_target_su_in_aget, self->data_ptr);
}

static int
SystemControl_set_q_pc_target_su_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SystemControl_q_pc_target_su_in_aset, self->data_ptr);
}

static PyObject *
SystemControl_get_rec_op_mode_initial(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_rec_op_mode_initial_nget, self->data_ptr);
}

static int
SystemControl_set_rec_op_mode_initial(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_rec_op_mode_initial_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_rec_qf_delay(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_rec_qf_delay_nget, self->data_ptr);
}

static int
SystemControl_set_rec_qf_delay(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_rec_qf_delay_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_rec_su_delay(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_rec_su_delay_nget, self->data_ptr);
}

static int
SystemControl_set_rec_su_delay(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_rec_su_delay_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_sim_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_sim_type_nget, self->data_ptr);
}

static int
SystemControl_set_sim_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_sim_type_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_time_start(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_time_start_nget, self->data_ptr);
}

static int
SystemControl_set_time_start(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_time_start_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_time_steps_per_hour(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_time_steps_per_hour_nget, self->data_ptr);
}

static int
SystemControl_set_time_steps_per_hour(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_time_steps_per_hour_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_time_stop(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_time_stop_nget, self->data_ptr);
}

static int
SystemControl_set_time_stop(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_time_stop_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_vacuum_arrays(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SystemControl_vacuum_arrays_nget, self->data_ptr);
}

static int
SystemControl_set_vacuum_arrays(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SystemControl_vacuum_arrays_nset, self->data_ptr);
}

static PyGetSetDef SystemControl_getset[] = {
{"T_in_loop_initial", (getter)SystemControl_get_T_in_loop_initial,(setter)SystemControl_set_T_in_loop_initial,
	PyDoc_STR("*float*: Initial loop inlet, cold header and cold runner fluid temperature [-]"),
 	NULL},
{"T_out_loop_initial", (getter)SystemControl_get_T_out_loop_initial,(setter)SystemControl_set_T_out_loop_initial,
	PyDoc_STR("*float*: Initial loop outlet, hot header and hot runner fluid temperature [-]"),
 	NULL},
{"T_out_scas_initial", (getter)SystemControl_get_T_out_scas_initial,(setter)SystemControl_set_T_out_scas_initial,
	PyDoc_STR("*sequence*: Initial SCA outlet temperatures [-]"),
 	NULL},
{"T_tank_cold_init", (getter)SystemControl_get_T_tank_cold_init,(setter)SystemControl_set_T_tank_cold_init,
	PyDoc_STR("*float*: Initial cold tank fluid temperature [C]"),
 	NULL},
{"T_tank_hot_init", (getter)SystemControl_get_T_tank_hot_init,(setter)SystemControl_set_T_tank_hot_init,
	PyDoc_STR("*float*: Initial hot tank fluid temperate [C]"),
 	NULL},
{"defocus_initial", (getter)SystemControl_get_defocus_initial,(setter)SystemControl_set_defocus_initial,
	PyDoc_STR("*float*: Initial receiver defocus [-]"),
 	NULL},
{"disp_csu_cost", (getter)SystemControl_get_disp_csu_cost,(setter)SystemControl_set_disp_csu_cost,
	PyDoc_STR("*float*: Cycle startup cost [$]"),
 	NULL},
{"disp_inventory_incentive", (getter)SystemControl_get_disp_inventory_incentive,(setter)SystemControl_set_disp_inventory_incentive,
	PyDoc_STR("*float*: Dispatch storage terminal inventory incentive multiplier\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_rsu_cost", (getter)SystemControl_get_disp_rsu_cost,(setter)SystemControl_set_disp_rsu_cost,
	PyDoc_STR("*float*: Receiver startup cost [$]"),
 	NULL},
{"is_dispatch_targets", (getter)SystemControl_get_is_dispatch_targets,(setter)SystemControl_set_is_dispatch_targets,
	PyDoc_STR("*float*: Run solution from user-specified dispatch targets? [-]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"is_pc_sb_allowed_in", (getter)SystemControl_get_is_pc_sb_allowed_in,(setter)SystemControl_set_is_pc_sb_allowed_in,
	PyDoc_STR("*sequence*: User-provided is power cycle standby allowed? [-]\n\n**Required:**\nRequired if is_dispatch_targets=1"),
 	NULL},
{"is_pc_su_allowed_in", (getter)SystemControl_get_is_pc_su_allowed_in,(setter)SystemControl_set_is_pc_su_allowed_in,
	PyDoc_STR("*sequence*: User-provided is power cycle startup allowed? [-]\n\n**Required:**\nRequired if is_dispatch_targets=1"),
 	NULL},
{"is_rec_su_allowed_in", (getter)SystemControl_get_is_rec_su_allowed_in,(setter)SystemControl_set_is_rec_su_allowed_in,
	PyDoc_STR("*sequence*: User-provided is receiver startup allowed? [-]\n\n**Required:**\nRequired if is_dispatch_targets=1"),
 	NULL},
{"pc_op_mode_initial", (getter)SystemControl_get_pc_op_mode_initial,(setter)SystemControl_set_pc_op_mode_initial,
	PyDoc_STR("*float*: Initial cycle operation mode 0:startup, 1:on, 2:standby, 3:off, 4:startup_controlled [-]"),
 	NULL},
{"pc_startup_energy_remain_initial", (getter)SystemControl_get_pc_startup_energy_remain_initial,(setter)SystemControl_set_pc_startup_energy_remain_initial,
	PyDoc_STR("*float*: Initial cycle startup energy remaining [kwh]"),
 	NULL},
{"pc_startup_time_remain_init", (getter)SystemControl_get_pc_startup_time_remain_init,(setter)SystemControl_set_pc_startup_time_remain_init,
	PyDoc_STR("*float*: Initial cycle startup time remaining [hr]"),
 	NULL},
{"q_pc_max_in", (getter)SystemControl_get_q_pc_max_in,(setter)SystemControl_set_q_pc_max_in,
	PyDoc_STR("*sequence*: User-provided max thermal power to PC [MWt]\n\n**Required:**\nRequired if is_dispatch_targets=1"),
 	NULL},
{"q_pc_target_on_in", (getter)SystemControl_get_q_pc_target_on_in,(setter)SystemControl_set_q_pc_target_on_in,
	PyDoc_STR("*sequence*: User-provided target thermal power to PC [MWt]\n\n**Required:**\nRequired if is_dispatch_targets=1"),
 	NULL},
{"q_pc_target_su_in", (getter)SystemControl_get_q_pc_target_su_in,(setter)SystemControl_set_q_pc_target_su_in,
	PyDoc_STR("*sequence*: User-provided target thermal power to PC [MWt]\n\n**Required:**\nRequired if is_dispatch_targets=1"),
 	NULL},
{"rec_op_mode_initial", (getter)SystemControl_get_rec_op_mode_initial,(setter)SystemControl_set_rec_op_mode_initial,
	PyDoc_STR("*float*: Initial receiver operating mode 0: off, 1: startup, 2: on [-]"),
 	NULL},
{"rec_qf_delay", (getter)SystemControl_get_rec_qf_delay,(setter)SystemControl_set_rec_qf_delay,
	PyDoc_STR("*float*: Energy-based receiver startup delay (fraction of rated thermal power) [-]\n\n**Required:**\nTrue"),
 	NULL},
{"rec_su_delay", (getter)SystemControl_get_rec_su_delay,(setter)SystemControl_set_rec_su_delay,
	PyDoc_STR("*float*: Fixed startup delay time for the receiver [hr]\n\n**Required:**\nTrue"),
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
		"TroughPhysical.SystemControl",             /*tp_name*/
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
 * Weather Group
 */ 

static PyTypeObject Weather_Type;

static PyObject *
Weather_new(SAM_TroughPhysical data_ptr)
{
	PyObject* new_obj = Weather_Type.tp_alloc(&Weather_Type,0);

	VarGroupObject* Weather_obj = (VarGroupObject*)new_obj;

	Weather_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Weather methods */

static PyObject *
Weather_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "Weather")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Weather_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Weather_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysical", "Weather")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Weather_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Weather_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Weather_methods[] = {
		{"assign",            (PyCFunction)Weather_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Weather_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Weather_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Weather_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Weather_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Weather_get_file_name(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TroughPhysical_Weather_file_name_sget, self->data_ptr);
}

static int
Weather_set_file_name(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TroughPhysical_Weather_file_name_sset, self->data_ptr);
}

static PyObject *
Weather_get_solar_resource_data(VarGroupObject *self, void *closure)
{
	return PySAM_table_getter(SAM_TroughPhysical_Weather_solar_resource_data_tget, self->data_ptr);
}

static int
Weather_set_solar_resource_data(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_table_setter(value, SAM_TroughPhysical_Weather_solar_resource_data_tset, self->data_ptr);
}

static PyGetSetDef Weather_getset[] = {
{"file_name", (getter)Weather_get_file_name,(setter)Weather_set_file_name,
	PyDoc_STR("*str*: Local weather file with path [none]\n\n**Constraints:**\nLOCAL_FILE\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"solar_resource_data", (getter)Weather_get_solar_resource_data,(setter)Weather_set_solar_resource_data,
	PyDoc_STR("*dict*: Weather resource data in memory\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Weather_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.Weather",             /*tp_name*/
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
		Weather_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Weather_getset,          /*tp_getset*/
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
 * SolarField Group
 */ 

static PyTypeObject SolarField_Type;

static PyObject *
SolarField_new(SAM_TroughPhysical data_ptr)
{
	PyObject* new_obj = SolarField_Type.tp_alloc(&SolarField_Type,0);

	VarGroupObject* SolarField_obj = (VarGroupObject*)new_obj;

	SolarField_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SolarField methods */

static PyObject *
SolarField_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "SolarField")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SolarField_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SolarField_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysical", "SolarField")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SolarField_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SolarField_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SolarField_methods[] = {
		{"assign",            (PyCFunction)SolarField_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SolarField_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SolarField_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SolarField_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SolarField_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SolarField_get_A_aperture(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_A_aperture_aget, self->data_ptr);
}

static int
SolarField_set_A_aperture(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_A_aperture_aset, self->data_ptr);
}

static PyObject *
SolarField_get_AbsorberMaterial(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_AbsorberMaterial_mget, self->data_ptr);
}

static int
SolarField_set_AbsorberMaterial(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_AbsorberMaterial_mset, self->data_ptr);
}

static PyObject *
SolarField_get_AnnulusGas(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_AnnulusGas_mget, self->data_ptr);
}

static int
SolarField_set_AnnulusGas(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_AnnulusGas_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Ave_Focal_Length(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_Ave_Focal_Length_aget, self->data_ptr);
}

static int
SolarField_set_Ave_Focal_Length(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_Ave_Focal_Length_aset, self->data_ptr);
}

static PyObject *
SolarField_get_ColperSCA(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_ColperSCA_aget, self->data_ptr);
}

static int
SolarField_set_ColperSCA(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_ColperSCA_aset, self->data_ptr);
}

static PyObject *
SolarField_get_D_2(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_D_2_mget, self->data_ptr);
}

static int
SolarField_set_D_2(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_D_2_mset, self->data_ptr);
}

static PyObject *
SolarField_get_D_3(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_D_3_mget, self->data_ptr);
}

static int
SolarField_set_D_3(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_D_3_mset, self->data_ptr);
}

static PyObject *
SolarField_get_D_4(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_D_4_mget, self->data_ptr);
}

static int
SolarField_set_D_4(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_D_4_mset, self->data_ptr);
}

static PyObject *
SolarField_get_D_5(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_D_5_mget, self->data_ptr);
}

static int
SolarField_set_D_5(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_D_5_mset, self->data_ptr);
}

static PyObject *
SolarField_get_D_p(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_D_p_mget, self->data_ptr);
}

static int
SolarField_set_D_p(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_D_p_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Design_loss(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_Design_loss_mget, self->data_ptr);
}

static int
SolarField_set_Design_loss(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_Design_loss_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Dirt_HCE(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_Dirt_HCE_mget, self->data_ptr);
}

static int
SolarField_set_Dirt_HCE(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_Dirt_HCE_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Dirt_mirror(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_Dirt_mirror_aget, self->data_ptr);
}

static int
SolarField_set_Dirt_mirror(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_Dirt_mirror_aset, self->data_ptr);
}

static PyObject *
SolarField_get_Distance_SCA(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_Distance_SCA_aget, self->data_ptr);
}

static int
SolarField_set_Distance_SCA(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_Distance_SCA_aset, self->data_ptr);
}

static PyObject *
SolarField_get_EPSILON_4(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_EPSILON_4_mget, self->data_ptr);
}

static int
SolarField_set_EPSILON_4(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_EPSILON_4_mset, self->data_ptr);
}

static PyObject *
SolarField_get_EPSILON_5(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_EPSILON_5_mget, self->data_ptr);
}

static int
SolarField_set_EPSILON_5(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_EPSILON_5_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Error(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_Error_aget, self->data_ptr);
}

static int
SolarField_set_Error(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_Error_aset, self->data_ptr);
}

static PyObject *
SolarField_get_FieldConfig(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_FieldConfig_nget, self->data_ptr);
}

static int
SolarField_set_FieldConfig(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_FieldConfig_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Flow_type(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_Flow_type_mget, self->data_ptr);
}

static int
SolarField_set_Flow_type(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_Flow_type_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Fluid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_Fluid_nget, self->data_ptr);
}

static int
SolarField_set_Fluid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_Fluid_nset, self->data_ptr);
}

static PyObject *
SolarField_get_GeomEffects(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_GeomEffects_aget, self->data_ptr);
}

static int
SolarField_set_GeomEffects(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_GeomEffects_aset, self->data_ptr);
}

static PyObject *
SolarField_get_GlazingIntactIn(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_GlazingIntactIn_mget, self->data_ptr);
}

static int
SolarField_set_GlazingIntactIn(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_GlazingIntactIn_mset, self->data_ptr);
}

static PyObject *
SolarField_get_HCE_FieldFrac(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_HCE_FieldFrac_mget, self->data_ptr);
}

static int
SolarField_set_HCE_FieldFrac(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_HCE_FieldFrac_mset, self->data_ptr);
}

static PyObject *
SolarField_get_HDR_rough(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_HDR_rough_nget, self->data_ptr);
}

static int
SolarField_set_HDR_rough(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_HDR_rough_nset, self->data_ptr);
}

static PyObject *
SolarField_get_IAM_matrix(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_IAM_matrix_mget, self->data_ptr);
}

static int
SolarField_set_IAM_matrix(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_IAM_matrix_mset, self->data_ptr);
}

static PyObject *
SolarField_get_I_bn_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_I_bn_des_nget, self->data_ptr);
}

static int
SolarField_set_I_bn_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_I_bn_des_nset, self->data_ptr);
}

static PyObject *
SolarField_get_L_SCA(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_L_SCA_aget, self->data_ptr);
}

static int
SolarField_set_L_SCA(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_L_SCA_aset, self->data_ptr);
}

static PyObject *
SolarField_get_L_aperture(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_L_aperture_aget, self->data_ptr);
}

static int
SolarField_set_L_aperture(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_L_aperture_aset, self->data_ptr);
}

static PyObject *
SolarField_get_L_power_block_piping(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_L_power_block_piping_nget, self->data_ptr);
}

static int
SolarField_set_L_power_block_piping(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_L_power_block_piping_nset, self->data_ptr);
}

static PyObject *
SolarField_get_L_rnr_per_xpan(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_L_rnr_per_xpan_nget, self->data_ptr);
}

static int
SolarField_set_L_rnr_per_xpan(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_L_rnr_per_xpan_nset, self->data_ptr);
}

static PyObject *
SolarField_get_L_xpan_hdr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_L_xpan_hdr_nget, self->data_ptr);
}

static int
SolarField_set_L_xpan_hdr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_L_xpan_hdr_nset, self->data_ptr);
}

static PyObject *
SolarField_get_L_xpan_rnr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_L_xpan_rnr_nget, self->data_ptr);
}

static int
SolarField_set_L_xpan_rnr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_L_xpan_rnr_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Min_rnr_xpans(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_Min_rnr_xpans_nget, self->data_ptr);
}

static int
SolarField_set_Min_rnr_xpans(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_Min_rnr_xpans_nset, self->data_ptr);
}

static PyObject *
SolarField_get_N_hdr_per_xpan(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_N_hdr_per_xpan_nget, self->data_ptr);
}

static int
SolarField_set_N_hdr_per_xpan(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_N_hdr_per_xpan_nset, self->data_ptr);
}

static PyObject *
SolarField_get_N_max_hdr_diams(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_N_max_hdr_diams_nget, self->data_ptr);
}

static int
SolarField_set_N_max_hdr_diams(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_N_max_hdr_diams_nset, self->data_ptr);
}

static PyObject *
SolarField_get_P_a(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_P_a_mget, self->data_ptr);
}

static int
SolarField_set_P_a(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_P_a_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Pipe_hl_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_Pipe_hl_coef_nget, self->data_ptr);
}

static int
SolarField_set_Pipe_hl_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_Pipe_hl_coef_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Rho_mirror_clean(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_Rho_mirror_clean_aget, self->data_ptr);
}

static int
SolarField_set_Rho_mirror_clean(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_Rho_mirror_clean_aset, self->data_ptr);
}

static PyObject *
SolarField_get_Rough(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_Rough_mget, self->data_ptr);
}

static int
SolarField_set_Rough(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_Rough_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Row_Distance(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_Row_Distance_nget, self->data_ptr);
}

static int
SolarField_set_Row_Distance(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_Row_Distance_nset, self->data_ptr);
}

static PyObject *
SolarField_get_SCA_drives_elec(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_SCA_drives_elec_nget, self->data_ptr);
}

static int
SolarField_set_SCA_drives_elec(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_SCA_drives_elec_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Shadowing(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_Shadowing_mget, self->data_ptr);
}

static int
SolarField_set_Shadowing(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_Shadowing_mset, self->data_ptr);
}

static PyObject *
SolarField_get_T_fp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_T_fp_nget, self->data_ptr);
}

static int
SolarField_set_T_fp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_T_fp_nset, self->data_ptr);
}

static PyObject *
SolarField_get_T_loop_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_T_loop_in_des_nget, self->data_ptr);
}

static int
SolarField_set_T_loop_in_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_T_loop_in_des_nset, self->data_ptr);
}

static PyObject *
SolarField_get_T_loop_out(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_T_loop_out_nget, self->data_ptr);
}

static int
SolarField_set_T_loop_out(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_T_loop_out_nset, self->data_ptr);
}

static PyObject *
SolarField_get_T_shutdown(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_T_shutdown_nget, self->data_ptr);
}

static int
SolarField_set_T_shutdown(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_T_shutdown_nset, self->data_ptr);
}

static PyObject *
SolarField_get_T_startup(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_T_startup_nget, self->data_ptr);
}

static int
SolarField_set_T_startup(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_T_startup_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Tau_envelope(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_Tau_envelope_mget, self->data_ptr);
}

static int
SolarField_set_Tau_envelope(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_Tau_envelope_mset, self->data_ptr);
}

static PyObject *
SolarField_get_TrackingError(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_TrackingError_aget, self->data_ptr);
}

static int
SolarField_set_TrackingError(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_TrackingError_aset, self->data_ptr);
}

static PyObject *
SolarField_get_V_hdr_cold_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_V_hdr_cold_max_nget, self->data_ptr);
}

static int
SolarField_set_V_hdr_cold_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_V_hdr_cold_max_nset, self->data_ptr);
}

static PyObject *
SolarField_get_V_hdr_cold_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_V_hdr_cold_min_nget, self->data_ptr);
}

static int
SolarField_set_V_hdr_cold_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_V_hdr_cold_min_nset, self->data_ptr);
}

static PyObject *
SolarField_get_V_hdr_hot_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_V_hdr_hot_max_nget, self->data_ptr);
}

static int
SolarField_set_V_hdr_hot_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_V_hdr_hot_max_nset, self->data_ptr);
}

static PyObject *
SolarField_get_V_hdr_hot_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_V_hdr_hot_min_nget, self->data_ptr);
}

static int
SolarField_set_V_hdr_hot_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_V_hdr_hot_min_nset, self->data_ptr);
}

static PyObject *
SolarField_get_W_aperture(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_W_aperture_aget, self->data_ptr);
}

static int
SolarField_set_W_aperture(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_W_aperture_aset, self->data_ptr);
}

static PyObject *
SolarField_get_accept_init(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_accept_init_nget, self->data_ptr);
}

static int
SolarField_set_accept_init(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_accept_init_nset, self->data_ptr);
}

static PyObject *
SolarField_get_accept_loc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_accept_loc_nget, self->data_ptr);
}

static int
SolarField_set_accept_loc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_accept_loc_nset, self->data_ptr);
}

static PyObject *
SolarField_get_accept_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_accept_mode_nget, self->data_ptr);
}

static int
SolarField_set_accept_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_accept_mode_nset, self->data_ptr);
}

static PyObject *
SolarField_get_alpha_abs(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_alpha_abs_mget, self->data_ptr);
}

static int
SolarField_set_alpha_abs(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_alpha_abs_mset, self->data_ptr);
}

static PyObject *
SolarField_get_alpha_env(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_alpha_env_mget, self->data_ptr);
}

static int
SolarField_set_alpha_env(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_alpha_env_mset, self->data_ptr);
}

static PyObject *
SolarField_get_azimuth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_azimuth_nget, self->data_ptr);
}

static int
SolarField_set_azimuth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_azimuth_nset, self->data_ptr);
}

static PyObject *
SolarField_get_calc_design_pipe_vals(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_calc_design_pipe_vals_nget, self->data_ptr);
}

static int
SolarField_set_calc_design_pipe_vals(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_calc_design_pipe_vals_nset, self->data_ptr);
}

static PyObject *
SolarField_get_custom_sf_pipe_sizes(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_custom_sf_pipe_sizes_nget, self->data_ptr);
}

static int
SolarField_set_custom_sf_pipe_sizes(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_custom_sf_pipe_sizes_nset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_11(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_11_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_11(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_11_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_12(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_12_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_12(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_12_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_13(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_13_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_13(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_13_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_14(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_14_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_14(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_14_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_21(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_21_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_21(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_21_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_22(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_22_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_22(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_22_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_23(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_23_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_23(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_23_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_24(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_24_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_24(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_24_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_31(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_31_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_31(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_31_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_32(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_32_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_32(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_32_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_33(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_33_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_33(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_33_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_34(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_34_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_34(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_34_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_41(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_41_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_41(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_41_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_42(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_42_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_42(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_42_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_43(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_43_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_43(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_43_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_44(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_44_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_44(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_44_mset, self->data_ptr);
}

static PyObject *
SolarField_get_eta_pump(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_eta_pump_nget, self->data_ptr);
}

static int
SolarField_set_eta_pump(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_eta_pump_nset, self->data_ptr);
}

static PyObject *
SolarField_get_f_htfmax(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_f_htfmax_nget, self->data_ptr);
}

static int
SolarField_set_f_htfmax(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_f_htfmax_nset, self->data_ptr);
}

static PyObject *
SolarField_get_f_htfmin(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_f_htfmin_nget, self->data_ptr);
}

static int
SolarField_set_f_htfmin(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_f_htfmin_nset, self->data_ptr);
}

static PyObject *
SolarField_get_field_fl_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_field_fl_props_mget, self->data_ptr);
}

static int
SolarField_set_field_fl_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_field_fl_props_mset, self->data_ptr);
}

static PyObject *
SolarField_get_include_fixed_power_block_runner(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_include_fixed_power_block_runner_nget, self->data_ptr);
}

static int
SolarField_set_include_fixed_power_block_runner(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_include_fixed_power_block_runner_nset, self->data_ptr);
}

static PyObject *
SolarField_get_m_dot_htfmax(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_m_dot_htfmax_nget, self->data_ptr);
}

static int
SolarField_set_m_dot_htfmax(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_m_dot_htfmax_nset, self->data_ptr);
}

static PyObject *
SolarField_get_m_dot_htfmin(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_m_dot_htfmin_nget, self->data_ptr);
}

static int
SolarField_set_m_dot_htfmin(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_m_dot_htfmin_nset, self->data_ptr);
}

static PyObject *
SolarField_get_mc_bal_cold(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_mc_bal_cold_nget, self->data_ptr);
}

static int
SolarField_set_mc_bal_cold(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_mc_bal_cold_nset, self->data_ptr);
}

static PyObject *
SolarField_get_mc_bal_hot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_mc_bal_hot_nget, self->data_ptr);
}

static int
SolarField_set_mc_bal_hot(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_mc_bal_hot_nset, self->data_ptr);
}

static PyObject *
SolarField_get_mc_bal_sca(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_mc_bal_sca_nget, self->data_ptr);
}

static int
SolarField_set_mc_bal_sca(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_mc_bal_sca_nset, self->data_ptr);
}

static PyObject *
SolarField_get_nColt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_nColt_nget, self->data_ptr);
}

static int
SolarField_set_nColt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_nColt_nset, self->data_ptr);
}

static PyObject *
SolarField_get_nHCEVar(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_nHCEVar_nget, self->data_ptr);
}

static int
SolarField_set_nHCEVar(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_nHCEVar_nset, self->data_ptr);
}

static PyObject *
SolarField_get_nHCEt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_nHCEt_nget, self->data_ptr);
}

static int
SolarField_set_nHCEt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_nHCEt_nset, self->data_ptr);
}

static PyObject *
SolarField_get_northsouth_field_sep(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_northsouth_field_sep_nget, self->data_ptr);
}

static int
SolarField_set_northsouth_field_sep(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_northsouth_field_sep_nset, self->data_ptr);
}

static PyObject *
SolarField_get_offset_xpan_hdr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_offset_xpan_hdr_nget, self->data_ptr);
}

static int
SolarField_set_offset_xpan_hdr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_offset_xpan_hdr_nset, self->data_ptr);
}

static PyObject *
SolarField_get_p_start(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_p_start_nget, self->data_ptr);
}

static int
SolarField_set_p_start(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_p_start_nset, self->data_ptr);
}

static PyObject *
SolarField_get_sf_hdr_diams(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_sf_hdr_diams_mget, self->data_ptr);
}

static int
SolarField_set_sf_hdr_diams(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_sf_hdr_diams_mset, self->data_ptr);
}

static PyObject *
SolarField_get_sf_hdr_lengths(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_sf_hdr_lengths_mget, self->data_ptr);
}

static int
SolarField_set_sf_hdr_lengths(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_sf_hdr_lengths_mset, self->data_ptr);
}

static PyObject *
SolarField_get_sf_hdr_wallthicks(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_sf_hdr_wallthicks_mget, self->data_ptr);
}

static int
SolarField_set_sf_hdr_wallthicks(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_sf_hdr_wallthicks_mset, self->data_ptr);
}

static PyObject *
SolarField_get_sf_rnr_diams(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_sf_rnr_diams_mget, self->data_ptr);
}

static int
SolarField_set_sf_rnr_diams(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_sf_rnr_diams_mset, self->data_ptr);
}

static PyObject *
SolarField_get_sf_rnr_lengths(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_sf_rnr_lengths_mget, self->data_ptr);
}

static int
SolarField_set_sf_rnr_lengths(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_sf_rnr_lengths_mset, self->data_ptr);
}

static PyObject *
SolarField_get_sf_rnr_wallthicks(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_sf_rnr_wallthicks_mget, self->data_ptr);
}

static int
SolarField_set_sf_rnr_wallthicks(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_sf_rnr_wallthicks_mset, self->data_ptr);
}

static PyObject *
SolarField_get_theta_dep(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_theta_dep_nget, self->data_ptr);
}

static int
SolarField_set_theta_dep(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_theta_dep_nset, self->data_ptr);
}

static PyObject *
SolarField_get_theta_stow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_theta_stow_nget, self->data_ptr);
}

static int
SolarField_set_theta_stow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_theta_stow_nset, self->data_ptr);
}

static PyObject *
SolarField_get_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_tilt_nget, self->data_ptr);
}

static int
SolarField_set_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_tilt_nset, self->data_ptr);
}

static PyObject *
SolarField_get_use_abs_or_rel_mdot_limit(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_use_abs_or_rel_mdot_limit_nget, self->data_ptr);
}

static int
SolarField_set_use_abs_or_rel_mdot_limit(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_use_abs_or_rel_mdot_limit_nset, self->data_ptr);
}

static PyObject *
SolarField_get_wind_stow_speed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_wind_stow_speed_nget, self->data_ptr);
}

static int
SolarField_set_wind_stow_speed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_wind_stow_speed_nset, self->data_ptr);
}

static PyGetSetDef SolarField_getset[] = {
{"A_aperture", (getter)SolarField_get_A_aperture,(setter)SolarField_set_A_aperture,
	PyDoc_STR("*sequence*: Reflective aperture area of the collector [m2]\n\n**Required:**\nTrue"),
 	NULL},
{"AbsorberMaterial", (getter)SolarField_get_AbsorberMaterial,(setter)SolarField_set_AbsorberMaterial,
	PyDoc_STR("*sequence[sequence]*: Absorber material type [none]\n\n**Required:**\nTrue"),
 	NULL},
{"AnnulusGas", (getter)SolarField_get_AnnulusGas,(setter)SolarField_set_AnnulusGas,
	PyDoc_STR("*sequence[sequence]*: Annulus gas type (1=air, 26=Ar, 27=H2) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"Ave_Focal_Length", (getter)SolarField_get_Ave_Focal_Length,(setter)SolarField_set_Ave_Focal_Length,
	PyDoc_STR("*sequence*: Average focal length of the collector  [m]\n\n**Required:**\nTrue"),
 	NULL},
{"ColperSCA", (getter)SolarField_get_ColperSCA,(setter)SolarField_set_ColperSCA,
	PyDoc_STR("*sequence*: Number of individual collector sections in an SCA  [none]\n\n**Required:**\nTrue"),
 	NULL},
{"D_2", (getter)SolarField_get_D_2,(setter)SolarField_set_D_2,
	PyDoc_STR("*sequence[sequence]*: Inner absorber tube diameter [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_3", (getter)SolarField_get_D_3,(setter)SolarField_set_D_3,
	PyDoc_STR("*sequence[sequence]*: Outer absorber tube diameter [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_4", (getter)SolarField_get_D_4,(setter)SolarField_set_D_4,
	PyDoc_STR("*sequence[sequence]*: Inner glass envelope diameter  [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_5", (getter)SolarField_get_D_5,(setter)SolarField_set_D_5,
	PyDoc_STR("*sequence[sequence]*: Outer glass envelope diameter  [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_p", (getter)SolarField_get_D_p,(setter)SolarField_set_D_p,
	PyDoc_STR("*sequence[sequence]*: Diameter of the absorber flow plug (optional)  [m]\n\n**Required:**\nTrue"),
 	NULL},
{"Design_loss", (getter)SolarField_get_Design_loss,(setter)SolarField_set_Design_loss,
	PyDoc_STR("*sequence[sequence]*: Receiver heat loss at design [W/m]\n\n**Required:**\nTrue"),
 	NULL},
{"Dirt_HCE", (getter)SolarField_get_Dirt_HCE,(setter)SolarField_set_Dirt_HCE,
	PyDoc_STR("*sequence[sequence]*: Loss due to dirt on the receiver envelope [none]\n\n**Required:**\nTrue"),
 	NULL},
{"Dirt_mirror", (getter)SolarField_get_Dirt_mirror,(setter)SolarField_set_Dirt_mirror,
	PyDoc_STR("*sequence*: User-defined dirt on mirror derate [none]\n\n**Required:**\nTrue"),
 	NULL},
{"Distance_SCA", (getter)SolarField_get_Distance_SCA,(setter)SolarField_set_Distance_SCA,
	PyDoc_STR("*sequence*: Piping distance between SCA's in the field [m]\n\n**Required:**\nTrue"),
 	NULL},
{"EPSILON_4", (getter)SolarField_get_EPSILON_4,(setter)SolarField_set_EPSILON_4,
	PyDoc_STR("*sequence[sequence]*: Inner glass envelope emissivities (Pyrex)  [none]\n\n**Required:**\nTrue"),
 	NULL},
{"EPSILON_5", (getter)SolarField_get_EPSILON_5,(setter)SolarField_set_EPSILON_5,
	PyDoc_STR("*sequence[sequence]*: Outer glass envelope emissivities (Pyrex)  [none]\n\n**Required:**\nTrue"),
 	NULL},
{"Error", (getter)SolarField_get_Error,(setter)SolarField_set_Error,
	PyDoc_STR("*sequence*: User-defined general optical error derate  [none]\n\n**Required:**\nTrue"),
 	NULL},
{"FieldConfig", (getter)SolarField_get_FieldConfig,(setter)SolarField_set_FieldConfig,
	PyDoc_STR("*float*: Number of subfield headers [none]\n\n**Required:**\nTrue"),
 	NULL},
{"Flow_type", (getter)SolarField_get_Flow_type,(setter)SolarField_set_Flow_type,
	PyDoc_STR("*sequence[sequence]*: Flow type through the absorber [none]\n\n**Required:**\nTrue"),
 	NULL},
{"Fluid", (getter)SolarField_get_Fluid,(setter)SolarField_set_Fluid,
	PyDoc_STR("*float*: Field HTF fluid ID number [none]\n\n**Required:**\nTrue"),
 	NULL},
{"GeomEffects", (getter)SolarField_get_GeomEffects,(setter)SolarField_set_GeomEffects,
	PyDoc_STR("*sequence*: User-defined geometry effects derate [none]\n\n**Required:**\nTrue"),
 	NULL},
{"GlazingIntactIn", (getter)SolarField_get_GlazingIntactIn,(setter)SolarField_set_GlazingIntactIn,
	PyDoc_STR("*sequence[sequence]*: Glazing intact (broken glass) flag {1=true, else=false} [none]\n\n**Required:**\nTrue"),
 	NULL},
{"HCE_FieldFrac", (getter)SolarField_get_HCE_FieldFrac,(setter)SolarField_set_HCE_FieldFrac,
	PyDoc_STR("*sequence[sequence]*: Fraction of the field occupied by this HCE type  [none]\n\n**Required:**\nTrue"),
 	NULL},
{"HDR_rough", (getter)SolarField_get_HDR_rough,(setter)SolarField_set_HDR_rough,
	PyDoc_STR("*float*: Header pipe roughness [m]\n\n**Required:**\nTrue"),
 	NULL},
{"IAM_matrix", (getter)SolarField_get_IAM_matrix,(setter)SolarField_set_IAM_matrix,
	PyDoc_STR("*sequence[sequence]*: IAM coefficients, matrix for 4 collectors [none]\n\n**Required:**\nTrue"),
 	NULL},
{"I_bn_des", (getter)SolarField_get_I_bn_des,(setter)SolarField_set_I_bn_des,
	PyDoc_STR("*float*: Solar irradiation at design [C]\n\n**Required:**\nTrue"),
 	NULL},
{"L_SCA", (getter)SolarField_get_L_SCA,(setter)SolarField_set_L_SCA,
	PyDoc_STR("*sequence*: Length of the SCA  [m]\n\n**Required:**\nTrue"),
 	NULL},
{"L_aperture", (getter)SolarField_get_L_aperture,(setter)SolarField_set_L_aperture,
	PyDoc_STR("*sequence*: Length of a single mirror/HCE unit [m]\n\n**Required:**\nTrue"),
 	NULL},
{"L_power_block_piping", (getter)SolarField_get_L_power_block_piping,(setter)SolarField_set_L_power_block_piping,
	PyDoc_STR("*float*: Length of piping (full mass flow) through heat sink (if applicable) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"L_rnr_per_xpan", (getter)SolarField_get_L_rnr_per_xpan,(setter)SolarField_set_L_rnr_per_xpan,
	PyDoc_STR("*float*: Threshold length of straight runner pipe without an expansion loop [m]\n\n**Required:**\nTrue"),
 	NULL},
{"L_xpan_hdr", (getter)SolarField_get_L_xpan_hdr,(setter)SolarField_set_L_xpan_hdr,
	PyDoc_STR("*float*: Compined perpendicular lengths of each header expansion loop [m]\n\n**Required:**\nTrue"),
 	NULL},
{"L_xpan_rnr", (getter)SolarField_get_L_xpan_rnr,(setter)SolarField_set_L_xpan_rnr,
	PyDoc_STR("*float*: Compined perpendicular lengths of each runner expansion loop [m]\n\n**Required:**\nTrue"),
 	NULL},
{"Min_rnr_xpans", (getter)SolarField_get_Min_rnr_xpans,(setter)SolarField_set_Min_rnr_xpans,
	PyDoc_STR("*float*: Minimum number of expansion loops per single-diameter runner section [none]\n\n**Required:**\nTrue"),
 	NULL},
{"N_hdr_per_xpan", (getter)SolarField_get_N_hdr_per_xpan,(setter)SolarField_set_N_hdr_per_xpan,
	PyDoc_STR("*float*: Number of collector loops per expansion loop [none]\n\n**Required:**\nTrue"),
 	NULL},
{"N_max_hdr_diams", (getter)SolarField_get_N_max_hdr_diams,(setter)SolarField_set_N_max_hdr_diams,
	PyDoc_STR("*float*: Maximum number of diameters in each of the hot and cold headers [none]\n\n**Required:**\nTrue"),
 	NULL},
{"P_a", (getter)SolarField_get_P_a,(setter)SolarField_set_P_a,
	PyDoc_STR("*sequence[sequence]*: Annulus gas pressure [torr]\n\n**Required:**\nTrue"),
 	NULL},
{"Pipe_hl_coef", (getter)SolarField_get_Pipe_hl_coef,(setter)SolarField_set_Pipe_hl_coef,
	PyDoc_STR("*float*: Loss coefficient from the header, runner pipe, and non-HCE piping [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"Rho_mirror_clean", (getter)SolarField_get_Rho_mirror_clean,(setter)SolarField_set_Rho_mirror_clean,
	PyDoc_STR("*sequence*: User-defined clean mirror reflectivity [none]\n\n**Required:**\nTrue"),
 	NULL},
{"Rough", (getter)SolarField_get_Rough,(setter)SolarField_set_Rough,
	PyDoc_STR("*sequence[sequence]*: Relative roughness of the internal HCE surface  [-]\n\n**Required:**\nTrue"),
 	NULL},
{"Row_Distance", (getter)SolarField_get_Row_Distance,(setter)SolarField_set_Row_Distance,
	PyDoc_STR("*float*: Spacing between rows (centerline to centerline) [m]\n\n**Required:**\nTrue"),
 	NULL},
{"SCA_drives_elec", (getter)SolarField_get_SCA_drives_elec,(setter)SolarField_set_SCA_drives_elec,
	PyDoc_STR("*float*: Tracking power, in Watts per SCA drive [W/m2-K]\n\n**Required:**\nTrue"),
 	NULL},
{"Shadowing", (getter)SolarField_get_Shadowing,(setter)SolarField_set_Shadowing,
	PyDoc_STR("*sequence[sequence]*: Receiver bellows shadowing loss factor [none]\n\n**Required:**\nTrue"),
 	NULL},
{"T_fp", (getter)SolarField_get_T_fp,(setter)SolarField_set_T_fp,
	PyDoc_STR("*float*: Freeze protection temperature (heat trace activation temperature) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"T_loop_in_des", (getter)SolarField_get_T_loop_in_des,(setter)SolarField_set_T_loop_in_des,
	PyDoc_STR("*float*: Design loop inlet temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_loop_out", (getter)SolarField_get_T_loop_out,(setter)SolarField_set_T_loop_out,
	PyDoc_STR("*float*: Target loop outlet temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_shutdown", (getter)SolarField_get_T_shutdown,(setter)SolarField_set_T_shutdown,
	PyDoc_STR("*float*: Temperature when solar field begins recirculating [C]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"T_startup", (getter)SolarField_get_T_startup,(setter)SolarField_set_T_startup,
	PyDoc_STR("*float*: Required temperature of the system before the power block can be switched on [C]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"Tau_envelope", (getter)SolarField_get_Tau_envelope,(setter)SolarField_set_Tau_envelope,
	PyDoc_STR("*sequence[sequence]*: Envelope transmittance [none]\n\n**Required:**\nTrue"),
 	NULL},
{"TrackingError", (getter)SolarField_get_TrackingError,(setter)SolarField_set_TrackingError,
	PyDoc_STR("*sequence*: User-defined tracking error derate [none]\n\n**Required:**\nTrue"),
 	NULL},
{"V_hdr_cold_max", (getter)SolarField_get_V_hdr_cold_max,(setter)SolarField_set_V_hdr_cold_max,
	PyDoc_STR("*float*: Maximum HTF velocity in the cold headers at design [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"V_hdr_cold_min", (getter)SolarField_get_V_hdr_cold_min,(setter)SolarField_set_V_hdr_cold_min,
	PyDoc_STR("*float*: Minimum HTF velocity in the cold headers at design [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"V_hdr_hot_max", (getter)SolarField_get_V_hdr_hot_max,(setter)SolarField_set_V_hdr_hot_max,
	PyDoc_STR("*float*: Maximum HTF velocity in the hot headers at design [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"V_hdr_hot_min", (getter)SolarField_get_V_hdr_hot_min,(setter)SolarField_set_V_hdr_hot_min,
	PyDoc_STR("*float*: Minimum HTF velocity in the hot headers at design [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"W_aperture", (getter)SolarField_get_W_aperture,(setter)SolarField_set_W_aperture,
	PyDoc_STR("*sequence*: The collector aperture width (Total structural area used for shadowing) [m]\n\n**Required:**\nTrue"),
 	NULL},
{"accept_init", (getter)SolarField_get_accept_init,(setter)SolarField_set_accept_init,
	PyDoc_STR("*float*: In acceptance testing mode - require steady-state startup [none]\n\n**Required:**\nTrue"),
 	NULL},
{"accept_loc", (getter)SolarField_get_accept_loc,(setter)SolarField_set_accept_loc,
	PyDoc_STR("*float*: In acceptance testing mode - temperature sensor location [1/2]\n\n**Info:**\nhx/loop\n\n**Required:**\nTrue"),
 	NULL},
{"accept_mode", (getter)SolarField_get_accept_mode,(setter)SolarField_set_accept_mode,
	PyDoc_STR("*float*: Acceptance testing mode? [0/1]\n\n**Info:**\nno/yes\n\n**Required:**\nTrue"),
 	NULL},
{"alpha_abs", (getter)SolarField_get_alpha_abs,(setter)SolarField_set_alpha_abs,
	PyDoc_STR("*sequence[sequence]*: Absorber absorptance  [none]\n\n**Required:**\nTrue"),
 	NULL},
{"alpha_env", (getter)SolarField_get_alpha_env,(setter)SolarField_set_alpha_env,
	PyDoc_STR("*sequence[sequence]*: Envelope absorptance  [none]\n\n**Required:**\nTrue"),
 	NULL},
{"azimuth", (getter)SolarField_get_azimuth,(setter)SolarField_set_azimuth,
	PyDoc_STR("*float*: Azimuth angle of surface/axis [none]\n\n**Required:**\nTrue"),
 	NULL},
{"calc_design_pipe_vals", (getter)SolarField_get_calc_design_pipe_vals,(setter)SolarField_set_calc_design_pipe_vals,
	PyDoc_STR("*float*: Calculate temps and pressures at design conditions for runners and headers [none]\n\n**Required:**\nTrue"),
 	NULL},
{"custom_sf_pipe_sizes", (getter)SolarField_get_custom_sf_pipe_sizes,(setter)SolarField_set_custom_sf_pipe_sizes,
	PyDoc_STR("*float*: Use custom solar field pipe diams, wallthks, and lengths [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_11", (getter)SolarField_get_epsilon_3_11,(setter)SolarField_set_epsilon_3_11,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 1 variation 1 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_12", (getter)SolarField_get_epsilon_3_12,(setter)SolarField_set_epsilon_3_12,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 1 variation 2 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_13", (getter)SolarField_get_epsilon_3_13,(setter)SolarField_set_epsilon_3_13,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 1 variation 3 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_14", (getter)SolarField_get_epsilon_3_14,(setter)SolarField_set_epsilon_3_14,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 1 variation 4 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_21", (getter)SolarField_get_epsilon_3_21,(setter)SolarField_set_epsilon_3_21,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 2 variation 1 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_22", (getter)SolarField_get_epsilon_3_22,(setter)SolarField_set_epsilon_3_22,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 2 variation 2 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_23", (getter)SolarField_get_epsilon_3_23,(setter)SolarField_set_epsilon_3_23,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 2 variation 3 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_24", (getter)SolarField_get_epsilon_3_24,(setter)SolarField_set_epsilon_3_24,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 2 variation 4 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_31", (getter)SolarField_get_epsilon_3_31,(setter)SolarField_set_epsilon_3_31,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 3 variation 1 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_32", (getter)SolarField_get_epsilon_3_32,(setter)SolarField_set_epsilon_3_32,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 3 variation 2 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_33", (getter)SolarField_get_epsilon_3_33,(setter)SolarField_set_epsilon_3_33,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 3 variation 3 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_34", (getter)SolarField_get_epsilon_3_34,(setter)SolarField_set_epsilon_3_34,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 3 variation 4 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_41", (getter)SolarField_get_epsilon_3_41,(setter)SolarField_set_epsilon_3_41,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 4 variation 1 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_42", (getter)SolarField_get_epsilon_3_42,(setter)SolarField_set_epsilon_3_42,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 4 variation 2 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_43", (getter)SolarField_get_epsilon_3_43,(setter)SolarField_set_epsilon_3_43,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 4 variation 3 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_44", (getter)SolarField_get_epsilon_3_44,(setter)SolarField_set_epsilon_3_44,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 4 variation 4 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"eta_pump", (getter)SolarField_get_eta_pump,(setter)SolarField_set_eta_pump,
	PyDoc_STR("*float*: HTF pump efficiency [none]\n\n**Required:**\nTrue"),
 	NULL},
{"f_htfmax", (getter)SolarField_get_f_htfmax,(setter)SolarField_set_f_htfmax,
	PyDoc_STR("*float*: Maximum loop mass flow rate fraction of design\n\n**Required:**\nRequired if use_abs_or_rel_mdot_limit=1"),
 	NULL},
{"f_htfmin", (getter)SolarField_get_f_htfmin,(setter)SolarField_set_f_htfmin,
	PyDoc_STR("*float*: Minimum loop mass flow rate fraction of design\n\n**Required:**\nRequired if use_abs_or_rel_mdot_limit=1"),
 	NULL},
{"field_fl_props", (getter)SolarField_get_field_fl_props,(setter)SolarField_set_field_fl_props,
	PyDoc_STR("*sequence[sequence]*: User defined field fluid property data [-]\n\n**Required:**\nTrue"),
 	NULL},
{"include_fixed_power_block_runner", (getter)SolarField_get_include_fixed_power_block_runner,(setter)SolarField_set_include_fixed_power_block_runner,
	PyDoc_STR("*float*: Should model consider piping through power block? [none]\n\n**Required:**\nTrue"),
 	NULL},
{"m_dot_htfmax", (getter)SolarField_get_m_dot_htfmax,(setter)SolarField_set_m_dot_htfmax,
	PyDoc_STR("*float*: Maximum loop HTF flow rate [kg/s]\n\n**Required:**\nRequired if use_abs_or_rel_mdot_limit=0"),
 	NULL},
{"m_dot_htfmin", (getter)SolarField_get_m_dot_htfmin,(setter)SolarField_set_m_dot_htfmin,
	PyDoc_STR("*float*: Minimum loop HTF flow rate [kg/s]\n\n**Required:**\nRequired if use_abs_or_rel_mdot_limit=0"),
 	NULL},
{"mc_bal_cold", (getter)SolarField_get_mc_bal_cold,(setter)SolarField_set_mc_bal_cold,
	PyDoc_STR("*float*: Heat capacity of the balance of plant on the cold side [kWht/K-MWt]\n\n**Required:**\nTrue"),
 	NULL},
{"mc_bal_hot", (getter)SolarField_get_mc_bal_hot,(setter)SolarField_set_mc_bal_hot,
	PyDoc_STR("*float*: Heat capacity of the balance of plant on the hot side [kWht/K-MWt]\n\n**Info:**\nnone\n\n**Required:**\nTrue"),
 	NULL},
{"mc_bal_sca", (getter)SolarField_get_mc_bal_sca,(setter)SolarField_set_mc_bal_sca,
	PyDoc_STR("*float*: Non-HTF heat capacity associated with each SCA - per meter basis [Wht/K-m]\n\n**Required:**\nTrue"),
 	NULL},
{"nColt", (getter)SolarField_get_nColt,(setter)SolarField_set_nColt,
	PyDoc_STR("*float*: Number of collector types [none]\n\n**Options:**\nconstant=4\n\n**Required:**\nTrue"),
 	NULL},
{"nHCEVar", (getter)SolarField_get_nHCEVar,(setter)SolarField_set_nHCEVar,
	PyDoc_STR("*float*: Number of HCE variants per type [none]\n\n**Required:**\nTrue"),
 	NULL},
{"nHCEt", (getter)SolarField_get_nHCEt,(setter)SolarField_set_nHCEt,
	PyDoc_STR("*float*: Number of HCE types [none]\n\n**Required:**\nTrue"),
 	NULL},
{"northsouth_field_sep", (getter)SolarField_get_northsouth_field_sep,(setter)SolarField_set_northsouth_field_sep,
	PyDoc_STR("*float*: North/south separation between subfields. 0 = SCAs are touching [m]\n\n**Required:**\nTrue"),
 	NULL},
{"offset_xpan_hdr", (getter)SolarField_get_offset_xpan_hdr,(setter)SolarField_set_offset_xpan_hdr,
	PyDoc_STR("*float*: Location of first header expansion loop. 1 = after first collector loop [none]\n\n**Required:**\nTrue"),
 	NULL},
{"p_start", (getter)SolarField_get_p_start,(setter)SolarField_set_p_start,
	PyDoc_STR("*float*: Collector startup energy, per SCA [kWhe]\n\n**Required:**\nTrue"),
 	NULL},
{"sf_hdr_diams", (getter)SolarField_get_sf_hdr_diams,(setter)SolarField_set_sf_hdr_diams,
	PyDoc_STR("*sequence[sequence]*: Custom header diameters [m]\n\n**Required:**\nTrue"),
 	NULL},
{"sf_hdr_lengths", (getter)SolarField_get_sf_hdr_lengths,(setter)SolarField_set_sf_hdr_lengths,
	PyDoc_STR("*sequence[sequence]*: Custom header lengths [m]\n\n**Required:**\nTrue"),
 	NULL},
{"sf_hdr_wallthicks", (getter)SolarField_get_sf_hdr_wallthicks,(setter)SolarField_set_sf_hdr_wallthicks,
	PyDoc_STR("*sequence[sequence]*: Custom header wall thicknesses [m]\n\n**Required:**\nTrue"),
 	NULL},
{"sf_rnr_diams", (getter)SolarField_get_sf_rnr_diams,(setter)SolarField_set_sf_rnr_diams,
	PyDoc_STR("*sequence[sequence]*: Custom runner diameters [m]\n\n**Required:**\nTrue"),
 	NULL},
{"sf_rnr_lengths", (getter)SolarField_get_sf_rnr_lengths,(setter)SolarField_set_sf_rnr_lengths,
	PyDoc_STR("*sequence[sequence]*: Custom runner lengths [m]\n\n**Required:**\nTrue"),
 	NULL},
{"sf_rnr_wallthicks", (getter)SolarField_get_sf_rnr_wallthicks,(setter)SolarField_set_sf_rnr_wallthicks,
	PyDoc_STR("*sequence[sequence]*: Custom runner wall thicknesses [m]\n\n**Required:**\nTrue"),
 	NULL},
{"theta_dep", (getter)SolarField_get_theta_dep,(setter)SolarField_set_theta_dep,
	PyDoc_STR("*float*: Deploy angle [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"theta_stow", (getter)SolarField_get_theta_stow,(setter)SolarField_set_theta_stow,
	PyDoc_STR("*float*: Stow angle [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"tilt", (getter)SolarField_get_tilt,(setter)SolarField_set_tilt,
	PyDoc_STR("*float*: Tilt angle of surface/axis [none]\n\n**Required:**\nTrue"),
 	NULL},
{"use_abs_or_rel_mdot_limit", (getter)SolarField_get_use_abs_or_rel_mdot_limit,(setter)SolarField_set_use_abs_or_rel_mdot_limit,
	PyDoc_STR("*float*: Use mass flow abs (0) or relative (1) limits\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"wind_stow_speed", (getter)SolarField_get_wind_stow_speed,(setter)SolarField_set_wind_stow_speed,
	PyDoc_STR("*float*: Trough wind stow speed [m/s]\n\n**Required:**\nFalse. Automatically set to 50 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SolarField_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.SolarField",             /*tp_name*/
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
		SolarField_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SolarField_getset,          /*tp_getset*/
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
 * Powerblock Group
 */ 

static PyTypeObject Powerblock_Type;

static PyObject *
Powerblock_new(SAM_TroughPhysical data_ptr)
{
	PyObject* new_obj = Powerblock_Type.tp_alloc(&Powerblock_Type,0);

	VarGroupObject* Powerblock_obj = (VarGroupObject*)new_obj;

	Powerblock_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Powerblock methods */

static PyObject *
Powerblock_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "Powerblock")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Powerblock_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Powerblock_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysical", "Powerblock")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Powerblock_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Powerblock_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Powerblock_methods[] = {
		{"assign",            (PyCFunction)Powerblock_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Powerblock_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Powerblock_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Powerblock_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Powerblock_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Powerblock_get_CT(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_CT_nget, self->data_ptr);
}

static int
Powerblock_set_CT(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_CT_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_F_wc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Powerblock_F_wc_aget, self->data_ptr);
}

static int
Powerblock_set_F_wc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_Powerblock_F_wc_aset, self->data_ptr);
}

static PyObject *
Powerblock_get_L_rnr_pb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_L_rnr_pb_nget, self->data_ptr);
}

static int
Powerblock_set_L_rnr_pb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_L_rnr_pb_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_boil(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_P_boil_nget, self->data_ptr);
}

static int
Powerblock_set_P_boil(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_P_boil_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_cond_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_P_cond_min_nget, self->data_ptr);
}

static int
Powerblock_set_P_cond_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_P_cond_min_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_cond_ratio(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_P_cond_ratio_nget, self->data_ptr);
}

static int
Powerblock_set_P_cond_ratio(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_P_cond_ratio_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_P_ref_nget, self->data_ptr);
}

static int
Powerblock_set_P_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_P_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_ITD_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_T_ITD_des_nget, self->data_ptr);
}

static int
Powerblock_set_T_ITD_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_T_ITD_des_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_amb_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_T_amb_des_nget, self->data_ptr);
}

static int
Powerblock_set_T_amb_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_T_amb_des_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_approach(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_T_approach_nget, self->data_ptr);
}

static int
Powerblock_set_T_approach(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_T_approach_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_cycle_cutoff_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_cycle_cutoff_frac_nget, self->data_ptr);
}

static int
Powerblock_set_cycle_cutoff_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_cycle_cutoff_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_cycle_max_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_cycle_max_frac_nget, self->data_ptr);
}

static int
Powerblock_set_cycle_max_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_cycle_max_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_dT_cw_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_dT_cw_ref_nget, self->data_ptr);
}

static int
Powerblock_set_dT_cw_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_dT_cw_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_eta_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_eta_ref_nget, self->data_ptr);
}

static int
Powerblock_set_eta_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_eta_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_n_pl_inc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_n_pl_inc_nget, self->data_ptr);
}

static int
Powerblock_set_n_pl_inc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_n_pl_inc_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_pb_bd_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_pb_bd_frac_nget, self->data_ptr);
}

static int
Powerblock_set_pb_bd_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_pb_bd_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_pb_pump_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_pb_pump_coef_nget, self->data_ptr);
}

static int
Powerblock_set_pb_pump_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_pb_pump_coef_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_pc_config(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_pc_config_nget, self->data_ptr);
}

static int
Powerblock_set_pc_config(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_pc_config_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_q_sby_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_q_sby_frac_nget, self->data_ptr);
}

static int
Powerblock_set_q_sby_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_q_sby_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_startup_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_startup_frac_nget, self->data_ptr);
}

static int
Powerblock_set_startup_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_startup_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_startup_time(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_startup_time_nget, self->data_ptr);
}

static int
Powerblock_set_startup_time(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_startup_time_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_tech_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_tech_type_nget, self->data_ptr);
}

static int
Powerblock_set_tech_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_tech_type_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_ud_f_W_dot_cool_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_ud_f_W_dot_cool_des_nget, self->data_ptr);
}

static int
Powerblock_set_ud_f_W_dot_cool_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_ud_f_W_dot_cool_des_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_ud_ind_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Powerblock_ud_ind_od_mget, self->data_ptr);
}

static int
Powerblock_set_ud_ind_od(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Powerblock_ud_ind_od_mset, self->data_ptr);
}

static PyObject *
Powerblock_get_ud_is_sco2_regr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_ud_is_sco2_regr_nget, self->data_ptr);
}

static int
Powerblock_set_ud_is_sco2_regr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_ud_is_sco2_regr_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_ud_m_dot_water_cool_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_ud_m_dot_water_cool_des_nget, self->data_ptr);
}

static int
Powerblock_set_ud_m_dot_water_cool_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_ud_m_dot_water_cool_des_nset, self->data_ptr);
}

static PyGetSetDef Powerblock_getset[] = {
{"CT", (getter)Powerblock_get_CT,(setter)Powerblock_set_CT,
	PyDoc_STR("*float*: Flag for using dry cooling or wet cooling system [none]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"F_wc", (getter)Powerblock_get_F_wc,(setter)Powerblock_set_F_wc,
	PyDoc_STR("*sequence*: Fraction indicating wet cooling use for hybrid system [none]\n\n**Options:**\nconstant=[0,0,0,0,0,0,0,0,0]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"L_rnr_pb", (getter)Powerblock_get_L_rnr_pb,(setter)Powerblock_set_L_rnr_pb,
	PyDoc_STR("*float*: Length of runner pipe in power block [m]\n\n**Required:**\nTrue"),
 	NULL},
{"P_boil", (getter)Powerblock_get_P_boil,(setter)Powerblock_set_P_boil,
	PyDoc_STR("*float*: Boiler operating pressure [bar]"),
 	NULL},
{"P_cond_min", (getter)Powerblock_get_P_cond_min,(setter)Powerblock_set_P_cond_min,
	PyDoc_STR("*float*: Minimum condenser pressure [inHg]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"P_cond_ratio", (getter)Powerblock_get_P_cond_ratio,(setter)Powerblock_set_P_cond_ratio,
	PyDoc_STR("*float*: Condenser pressure ratio [none]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"P_ref", (getter)Powerblock_get_P_ref,(setter)Powerblock_set_P_ref,
	PyDoc_STR("*float*: Rated plant capacity [MWe]\n\n**Required:**\nTrue"),
 	NULL},
{"T_ITD_des", (getter)Powerblock_get_T_ITD_des,(setter)Powerblock_set_T_ITD_des,
	PyDoc_STR("*float*: ITD at design for dry system [C]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"T_amb_des", (getter)Powerblock_get_T_amb_des,(setter)Powerblock_set_T_amb_des,
	PyDoc_STR("*float*: Reference ambient temperature at design point [C]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"T_approach", (getter)Powerblock_get_T_approach,(setter)Powerblock_set_T_approach,
	PyDoc_STR("*float*: Cooling tower approach temperature [C]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"cycle_cutoff_frac", (getter)Powerblock_get_cycle_cutoff_frac,(setter)Powerblock_set_cycle_cutoff_frac,
	PyDoc_STR("*float*: Minimum turbine operation fraction before shutdown [-]\n\n**Required:**\nTrue"),
 	NULL},
{"cycle_max_frac", (getter)Powerblock_get_cycle_max_frac,(setter)Powerblock_set_cycle_max_frac,
	PyDoc_STR("*float*: Maximum turbine over design operation fraction [-]\n\n**Required:**\nTrue"),
 	NULL},
{"dT_cw_ref", (getter)Powerblock_get_dT_cw_ref,(setter)Powerblock_set_dT_cw_ref,
	PyDoc_STR("*float*: Reference condenser cooling water inlet/outlet T diff [C]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"eta_ref", (getter)Powerblock_get_eta_ref,(setter)Powerblock_set_eta_ref,
	PyDoc_STR("*float*: Power cycle efficiency at design [none]\n\n**Required:**\nTrue"),
 	NULL},
{"n_pl_inc", (getter)Powerblock_get_n_pl_inc,(setter)Powerblock_set_n_pl_inc,
	PyDoc_STR("*float*: Number of part-load increments for the heat rejection system [none]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"pb_bd_frac", (getter)Powerblock_get_pb_bd_frac,(setter)Powerblock_set_pb_bd_frac,
	PyDoc_STR("*float*: Power block blowdown steam fraction  [none]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"pb_pump_coef", (getter)Powerblock_get_pb_pump_coef,(setter)Powerblock_set_pb_pump_coef,
	PyDoc_STR("*float*: Pumping power to move 1kg of HTF through PB loop [kW/kg]\n\n**Required:**\nTrue"),
 	NULL},
{"pc_config", (getter)Powerblock_get_pc_config,(setter)Powerblock_set_pc_config,
	PyDoc_STR("*float*: 0: Steam Rankine (224), 1: user defined [-]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"q_sby_frac", (getter)Powerblock_get_q_sby_frac,(setter)Powerblock_set_q_sby_frac,
	PyDoc_STR("*float*: Fraction of thermal power required for standby mode [none]\n\n**Required:**\nTrue"),
 	NULL},
{"startup_frac", (getter)Powerblock_get_startup_frac,(setter)Powerblock_set_startup_frac,
	PyDoc_STR("*float*: Fraction of design thermal power needed for startup [none]\n\n**Required:**\nTrue"),
 	NULL},
{"startup_time", (getter)Powerblock_get_startup_time,(setter)Powerblock_set_startup_time,
	PyDoc_STR("*float*: Time needed for power block startup [hr]\n\n**Required:**\nTrue"),
 	NULL},
{"tech_type", (getter)Powerblock_get_tech_type,(setter)Powerblock_set_tech_type,
	PyDoc_STR("*float*: Turbine inlet pressure control flag (sliding=user, fixed=trough) [1/2/3]\n\n**Info:**\ntower/trough/user\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"ud_f_W_dot_cool_des", (getter)Powerblock_get_ud_f_W_dot_cool_des,(setter)Powerblock_set_ud_f_W_dot_cool_des,
	PyDoc_STR("*float*: Percent of user-defined power cycle design gross output consumed by cooling [%]\n\n**Required:**\nRequired if pc_config=1"),
 	NULL},
{"ud_ind_od", (getter)Powerblock_get_ud_ind_od,(setter)Powerblock_set_ud_ind_od,
	PyDoc_STR("*sequence[sequence]*: Off design user-defined power cycle performance as function of T_htf, m_dot_htf [ND], and T_amb\n\n**Required:**\nRequired if pc_config=1"),
 	NULL},
{"ud_is_sco2_regr", (getter)Powerblock_get_ud_is_sco2_regr,(setter)Powerblock_set_ud_is_sco2_regr,
	PyDoc_STR("*float*: 0: (default) simple max htf mass flow correction; 1: sco2 heuristic regression; 2: no correction\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ud_m_dot_water_cool_des", (getter)Powerblock_get_ud_m_dot_water_cool_des,(setter)Powerblock_set_ud_m_dot_water_cool_des,
	PyDoc_STR("*float*: Mass flow rate of water required at user-defined power cycle design point [kg/s]\n\n**Required:**\nRequired if pc_config=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Powerblock_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.Powerblock",             /*tp_name*/
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
		Powerblock_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Powerblock_getset,          /*tp_getset*/
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
 * TES Group
 */ 

static PyTypeObject TES_Type;

static PyObject *
TES_new(SAM_TroughPhysical data_ptr)
{
	PyObject* new_obj = TES_Type.tp_alloc(&TES_Type,0);

	VarGroupObject* TES_obj = (VarGroupObject*)new_obj;

	TES_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* TES methods */

static PyObject *
TES_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "TES")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TES_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &TES_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysical", "TES")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TES_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &TES_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TES_methods[] = {
		{"assign",            (PyCFunction)TES_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``TES_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)TES_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``TES_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)TES_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TES_get_cold_tank_Thtr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_cold_tank_Thtr_nget, self->data_ptr);
}

static int
TES_set_cold_tank_Thtr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_cold_tank_Thtr_nset, self->data_ptr);
}

static PyObject *
TES_get_cold_tank_max_heat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_cold_tank_max_heat_nget, self->data_ptr);
}

static int
TES_set_cold_tank_max_heat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_cold_tank_max_heat_nset, self->data_ptr);
}

static PyObject *
TES_get_d_tank_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_d_tank_in_nget, self->data_ptr);
}

static int
TES_set_d_tank_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_d_tank_in_nset, self->data_ptr);
}

static PyObject *
TES_get_dt_hot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_dt_hot_nget, self->data_ptr);
}

static int
TES_set_dt_hot(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_dt_hot_nset, self->data_ptr);
}

static PyObject *
TES_get_h_tank_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_h_tank_in_nget, self->data_ptr);
}

static int
TES_set_h_tank_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_h_tank_in_nset, self->data_ptr);
}

static PyObject *
TES_get_h_tank_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_h_tank_min_nget, self->data_ptr);
}

static int
TES_set_h_tank_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_h_tank_min_nset, self->data_ptr);
}

static PyObject *
TES_get_hot_tank_Thtr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_hot_tank_Thtr_nget, self->data_ptr);
}

static int
TES_set_hot_tank_Thtr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_hot_tank_Thtr_nset, self->data_ptr);
}

static PyObject *
TES_get_hot_tank_max_heat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_hot_tank_max_heat_nget, self->data_ptr);
}

static int
TES_set_hot_tank_max_heat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_hot_tank_max_heat_nset, self->data_ptr);
}

static PyObject *
TES_get_init_hot_htf_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_init_hot_htf_percent_nget, self->data_ptr);
}

static int
TES_set_init_hot_htf_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_init_hot_htf_percent_nset, self->data_ptr);
}

static PyObject *
TES_get_is_h_tank_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_is_h_tank_fixed_nget, self->data_ptr);
}

static int
TES_set_is_h_tank_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_is_h_tank_fixed_nset, self->data_ptr);
}

static PyObject *
TES_get_store_fl_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_TES_store_fl_props_mget, self->data_ptr);
}

static int
TES_set_store_fl_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_TES_store_fl_props_mset, self->data_ptr);
}

static PyObject *
TES_get_store_fluid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_store_fluid_nget, self->data_ptr);
}

static int
TES_set_store_fluid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_store_fluid_nset, self->data_ptr);
}

static PyObject *
TES_get_tank_pairs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_tank_pairs_nget, self->data_ptr);
}

static int
TES_set_tank_pairs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_tank_pairs_nset, self->data_ptr);
}

static PyObject *
TES_get_tes_cyl_piston_loss_poly(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_TES_tes_cyl_piston_loss_poly_aget, self->data_ptr);
}

static int
TES_set_tes_cyl_piston_loss_poly(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_TES_tes_cyl_piston_loss_poly_aset, self->data_ptr);
}

static PyObject *
TES_get_tes_cyl_tank_cp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_tes_cyl_tank_cp_nget, self->data_ptr);
}

static int
TES_set_tes_cyl_tank_cp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_tes_cyl_tank_cp_nset, self->data_ptr);
}

static PyObject *
TES_get_tes_cyl_tank_dens(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_tes_cyl_tank_dens_nget, self->data_ptr);
}

static int
TES_set_tes_cyl_tank_dens(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_tes_cyl_tank_dens_nset, self->data_ptr);
}

static PyObject *
TES_get_tes_cyl_tank_insul_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_tes_cyl_tank_insul_percent_nget, self->data_ptr);
}

static int
TES_set_tes_cyl_tank_insul_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_tes_cyl_tank_insul_percent_nset, self->data_ptr);
}

static PyObject *
TES_get_tes_cyl_tank_thick(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_tes_cyl_tank_thick_nget, self->data_ptr);
}

static int
TES_set_tes_cyl_tank_thick(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_tes_cyl_tank_thick_nset, self->data_ptr);
}

static PyObject *
TES_get_tes_n_tsteps(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_tes_n_tsteps_nget, self->data_ptr);
}

static int
TES_set_tes_n_tsteps(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_tes_n_tsteps_nset, self->data_ptr);
}

static PyObject *
TES_get_tes_pb_T_charge_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_tes_pb_T_charge_min_nget, self->data_ptr);
}

static int
TES_set_tes_pb_T_charge_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_tes_pb_T_charge_min_nset, self->data_ptr);
}

static PyObject *
TES_get_tes_pb_T_cold_delta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_tes_pb_T_cold_delta_nget, self->data_ptr);
}

static int
TES_set_tes_pb_T_cold_delta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_tes_pb_T_cold_delta_nset, self->data_ptr);
}

static PyObject *
TES_get_tes_pb_T_hot_delta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_tes_pb_T_hot_delta_nget, self->data_ptr);
}

static int
TES_set_tes_pb_T_hot_delta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_tes_pb_T_hot_delta_nset, self->data_ptr);
}

static PyObject *
TES_get_tes_pb_cp_solid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_tes_pb_cp_solid_nget, self->data_ptr);
}

static int
TES_set_tes_pb_cp_solid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_tes_pb_cp_solid_nset, self->data_ptr);
}

static PyObject *
TES_get_tes_pb_dens_solid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_tes_pb_dens_solid_nget, self->data_ptr);
}

static int
TES_set_tes_pb_dens_solid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_tes_pb_dens_solid_nset, self->data_ptr);
}

static PyObject *
TES_get_tes_pb_f_oversize(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_tes_pb_f_oversize_nget, self->data_ptr);
}

static int
TES_set_tes_pb_f_oversize(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_tes_pb_f_oversize_nset, self->data_ptr);
}

static PyObject *
TES_get_tes_pb_k_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_tes_pb_k_eff_nget, self->data_ptr);
}

static int
TES_set_tes_pb_k_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_tes_pb_k_eff_nset, self->data_ptr);
}

static PyObject *
TES_get_tes_pb_n_xsteps(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_tes_pb_n_xsteps_nget, self->data_ptr);
}

static int
TES_set_tes_pb_n_xsteps(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_tes_pb_n_xsteps_nset, self->data_ptr);
}

static PyObject *
TES_get_tes_pb_void_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_tes_pb_void_frac_nget, self->data_ptr);
}

static int
TES_set_tes_pb_void_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_tes_pb_void_frac_nset, self->data_ptr);
}

static PyObject *
TES_get_tes_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_tes_type_nget, self->data_ptr);
}

static int
TES_set_tes_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_tes_type_nset, self->data_ptr);
}

static PyObject *
TES_get_tshours(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_tshours_nget, self->data_ptr);
}

static int
TES_set_tshours(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_tshours_nset, self->data_ptr);
}

static PyObject *
TES_get_u_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_u_tank_nget, self->data_ptr);
}

static int
TES_set_u_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_u_tank_nset, self->data_ptr);
}

static PyGetSetDef TES_getset[] = {
{"cold_tank_Thtr", (getter)TES_get_cold_tank_Thtr,(setter)TES_set_cold_tank_Thtr,
	PyDoc_STR("*float*: Minimum allowable cold tank HTF temp [C]\n\n**Required:**\nRequired if tes_type=1|tes_type=3"),
 	NULL},
{"cold_tank_max_heat", (getter)TES_get_cold_tank_max_heat,(setter)TES_set_cold_tank_max_heat,
	PyDoc_STR("*float*: Rated heater capacity for cold tank heating [MWe]\n\n**Required:**\nRequired if tes_type=1|tes_type=3"),
 	NULL},
{"d_tank_in", (getter)TES_get_d_tank_in,(setter)TES_set_d_tank_in,
	PyDoc_STR("*float*: Tank diameter input [m]\n\n**Required:**\nRequired if is_h_tank_fixed=0|is_h_tank_fixed=2"),
 	NULL},
{"dt_hot", (getter)TES_get_dt_hot,(setter)TES_set_dt_hot,
	PyDoc_STR("*float*: Hot side HX approach temp [C]\n\n**Required:**\nRequired if tes_type=1"),
 	NULL},
{"h_tank_in", (getter)TES_get_h_tank_in,(setter)TES_set_h_tank_in,
	PyDoc_STR("*float*: Total height of tank input (height of HTF when tank is full [m]\n\n**Required:**\nRequired if is_h_tank_fixed=1"),
 	NULL},
{"h_tank_min", (getter)TES_get_h_tank_min,(setter)TES_set_h_tank_min,
	PyDoc_STR("*float*: Minimum allowable HTF height in storage tank [m]\n\n**Required:**\nRequired if tes_type=1|tes_type=3"),
 	NULL},
{"hot_tank_Thtr", (getter)TES_get_hot_tank_Thtr,(setter)TES_set_hot_tank_Thtr,
	PyDoc_STR("*float*: Minimum allowable hot tank HTF temp [C]\n\n**Required:**\nRequired if tes_type=1|tes_type=3"),
 	NULL},
{"hot_tank_max_heat", (getter)TES_get_hot_tank_max_heat,(setter)TES_set_hot_tank_max_heat,
	PyDoc_STR("*float*: Rated heater capacity for hot tank heating [MWe]\n\n**Required:**\nRequired if tes_type=1|tes_type=3"),
 	NULL},
{"init_hot_htf_percent", (getter)TES_get_init_hot_htf_percent,(setter)TES_set_init_hot_htf_percent,
	PyDoc_STR("*float*: Initial fraction of avail. vol that is hot [%]\n\n**Required:**\nTrue"),
 	NULL},
{"is_h_tank_fixed", (getter)TES_get_is_h_tank_fixed,(setter)TES_set_is_h_tank_fixed,
	PyDoc_STR("*float*: [1] Use fixed height (calculate diameter) [0] Use fixed diameter [2] Use fixed d and h (for packed bed) [-]\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"store_fl_props", (getter)TES_get_store_fl_props,(setter)TES_set_store_fl_props,
	PyDoc_STR("*sequence[sequence]*: User defined storage fluid property data [-]\n\n**Required:**\nRequired if tes_type=1"),
 	NULL},
{"store_fluid", (getter)TES_get_store_fluid,(setter)TES_set_store_fluid,
	PyDoc_STR("*float*: Material number for storage fluid [-]\n\n**Required:**\nRequired if tes_type=1"),
 	NULL},
{"tank_pairs", (getter)TES_get_tank_pairs,(setter)TES_set_tank_pairs,
	PyDoc_STR("*float*: Number of equivalent tank pairs [-]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"tes_cyl_piston_loss_poly", (getter)TES_get_tes_cyl_piston_loss_poly,(setter)TES_set_tes_cyl_piston_loss_poly,
	PyDoc_STR("*sequence*: Polynomial coefficients describing piston heat loss function (f(kg/s)=%)\n\n**Required:**\nRequired if tes_type=3"),
 	NULL},
{"tes_cyl_tank_cp", (getter)TES_get_tes_cyl_tank_cp,(setter)TES_set_tes_cyl_tank_cp,
	PyDoc_STR("*float*: Tank wall cp (used for Piston Cylinder) [kJ/kg-K]\n\n**Required:**\nRequired if tes_type=3"),
 	NULL},
{"tes_cyl_tank_dens", (getter)TES_get_tes_cyl_tank_dens,(setter)TES_set_tes_cyl_tank_dens,
	PyDoc_STR("*float*: Tank wall thickness (used for Piston Cylinder) [kg/m3]\n\n**Required:**\nRequired if tes_type=3"),
 	NULL},
{"tes_cyl_tank_insul_percent", (getter)TES_get_tes_cyl_tank_insul_percent,(setter)TES_set_tes_cyl_tank_insul_percent,
	PyDoc_STR("*float*: Percent additional wall mass due to insulation (used for Piston Cylinder) [%]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"tes_cyl_tank_thick", (getter)TES_get_tes_cyl_tank_thick,(setter)TES_set_tes_cyl_tank_thick,
	PyDoc_STR("*float*: Tank wall thickness (used for Piston Cylinder) [m]\n\n**Required:**\nRequired if tes_type=3"),
 	NULL},
{"tes_n_tsteps", (getter)TES_get_tes_n_tsteps,(setter)TES_set_tes_n_tsteps,
	PyDoc_STR("*float*: Number of subtimesteps (for NT and packed bed)\n\n**Required:**\ntes_type>1"),
 	NULL},
{"tes_pb_T_charge_min", (getter)TES_get_tes_pb_T_charge_min,(setter)TES_set_tes_pb_T_charge_min,
	PyDoc_STR("*float*: Min charge temp [C]\n\n**Required:**\nRequired if tes_type=2"),
 	NULL},
{"tes_pb_T_cold_delta", (getter)TES_get_tes_pb_T_cold_delta,(setter)TES_set_tes_pb_T_cold_delta,
	PyDoc_STR("*float*: Max allowable increase in cold discharge temp [C]\n\n**Required:**\nRequired if tes_type=2"),
 	NULL},
{"tes_pb_T_hot_delta", (getter)TES_get_tes_pb_T_hot_delta,(setter)TES_set_tes_pb_T_hot_delta,
	PyDoc_STR("*float*: Max allowable decrease in hot discharge temp [C]\n\n**Required:**\nRequired if tes_type=2"),
 	NULL},
{"tes_pb_cp_solid", (getter)TES_get_tes_pb_cp_solid,(setter)TES_set_tes_pb_cp_solid,
	PyDoc_STR("*float*: TES particle specific heat [kJ/kg K]\n\n**Required:**\nRequired if tes_type=2"),
 	NULL},
{"tes_pb_dens_solid", (getter)TES_get_tes_pb_dens_solid,(setter)TES_set_tes_pb_dens_solid,
	PyDoc_STR("*float*: TES packed bed media density [kg/m3]\n\n**Required:**\nRequired if tes_type=2"),
 	NULL},
{"tes_pb_f_oversize", (getter)TES_get_tes_pb_f_oversize,(setter)TES_set_tes_pb_f_oversize,
	PyDoc_STR("*float*: Packed bed oversize factor\n\n**Required:**\nRequired if tes_type=2"),
 	NULL},
{"tes_pb_k_eff", (getter)TES_get_tes_pb_k_eff,(setter)TES_set_tes_pb_k_eff,
	PyDoc_STR("*float*: TES packed bed effective conductivity [W/m K]\n\n**Required:**\nRequired if tes_type=2"),
 	NULL},
{"tes_pb_n_xsteps", (getter)TES_get_tes_pb_n_xsteps,(setter)TES_set_tes_pb_n_xsteps,
	PyDoc_STR("*float*: Number of spatial segments\n\n**Required:**\nRequired if tes_type=2"),
 	NULL},
{"tes_pb_void_frac", (getter)TES_get_tes_pb_void_frac,(setter)TES_set_tes_pb_void_frac,
	PyDoc_STR("*float*: TES packed bed void fraction\n\n**Required:**\nRequired if tes_type=2"),
 	NULL},
{"tes_type", (getter)TES_get_tes_type,(setter)TES_set_tes_type,
	PyDoc_STR("*float*: Standard two tank (1), Packed Bed (2), Piston Cylinder (3) [-]\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"tshours", (getter)TES_get_tshours,(setter)TES_set_tshours,
	PyDoc_STR("*float*: Equivalent full-load thermal storage hours [hr]\n\n**Required:**\nTrue"),
 	NULL},
{"u_tank", (getter)TES_get_u_tank,(setter)TES_set_u_tank,
	PyDoc_STR("*float*: Loss coefficient from the tank [W/m2-K]\n\n**Required:**\nRequired if tes_type=1|tes_type=3"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TES_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.TES",             /*tp_name*/
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
		TES_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TES_getset,          /*tp_getset*/
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
 * Controller Group
 */ 

static PyTypeObject Controller_Type;

static PyObject *
Controller_new(SAM_TroughPhysical data_ptr)
{
	PyObject* new_obj = Controller_Type.tp_alloc(&Controller_Type,0);

	VarGroupObject* Controller_obj = (VarGroupObject*)new_obj;

	Controller_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Controller methods */

static PyObject *
Controller_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "Controller")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Controller_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Controller_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysical", "Controller")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Controller_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Controller_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Controller_methods[] = {
		{"assign",            (PyCFunction)Controller_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Controller_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Controller_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Controller_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Controller_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Controller_get_DP_SGS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_DP_SGS_nget, self->data_ptr);
}

static int
Controller_set_DP_SGS(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_DP_SGS_nset, self->data_ptr);
}

static PyObject *
Controller_get_T_tank_hot_inlet_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_T_tank_hot_inlet_min_nget, self->data_ptr);
}

static int
Controller_set_T_tank_hot_inlet_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_T_tank_hot_inlet_min_nset, self->data_ptr);
}

static PyObject *
Controller_get_V_tes_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_V_tes_des_nget, self->data_ptr);
}

static int
Controller_set_V_tes_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_V_tes_des_nset, self->data_ptr);
}

static PyObject *
Controller_get_custom_tes_p_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_custom_tes_p_loss_nget, self->data_ptr);
}

static int
Controller_set_custom_tes_p_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_custom_tes_p_loss_nset, self->data_ptr);
}

static PyObject *
Controller_get_custom_tes_pipe_sizes(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_custom_tes_pipe_sizes_nget, self->data_ptr);
}

static int
Controller_set_custom_tes_pipe_sizes(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_custom_tes_pipe_sizes_nset, self->data_ptr);
}

static PyObject *
Controller_get_has_hot_tank_bypass(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_has_hot_tank_bypass_nget, self->data_ptr);
}

static int
Controller_set_has_hot_tank_bypass(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_has_hot_tank_bypass_nset, self->data_ptr);
}

static PyObject *
Controller_get_k_tes_loss_coeffs(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Controller_k_tes_loss_coeffs_mget, self->data_ptr);
}

static int
Controller_set_k_tes_loss_coeffs(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Controller_k_tes_loss_coeffs_mset, self->data_ptr);
}

static PyObject *
Controller_get_non_solar_field_land_area_multiplier(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_non_solar_field_land_area_multiplier_nget, self->data_ptr);
}

static int
Controller_set_non_solar_field_land_area_multiplier(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_non_solar_field_land_area_multiplier_nset, self->data_ptr);
}

static PyObject *
Controller_get_specified_solar_multiple(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_specified_solar_multiple_nget, self->data_ptr);
}

static int
Controller_set_specified_solar_multiple(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_specified_solar_multiple_nset, self->data_ptr);
}

static PyObject *
Controller_get_specified_total_aperture(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_specified_total_aperture_nget, self->data_ptr);
}

static int
Controller_set_specified_total_aperture(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_specified_total_aperture_nset, self->data_ptr);
}

static PyObject *
Controller_get_tanks_in_parallel(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_tanks_in_parallel_nget, self->data_ptr);
}

static int
Controller_set_tanks_in_parallel(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_tanks_in_parallel_nset, self->data_ptr);
}

static PyObject *
Controller_get_tes_diams(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Controller_tes_diams_mget, self->data_ptr);
}

static int
Controller_set_tes_diams(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Controller_tes_diams_mset, self->data_ptr);
}

static PyObject *
Controller_get_tes_lengths(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Controller_tes_lengths_mget, self->data_ptr);
}

static int
Controller_set_tes_lengths(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Controller_tes_lengths_mset, self->data_ptr);
}

static PyObject *
Controller_get_tes_pump_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_tes_pump_coef_nget, self->data_ptr);
}

static int
Controller_set_tes_pump_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_tes_pump_coef_nset, self->data_ptr);
}

static PyObject *
Controller_get_tes_wallthicks(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Controller_tes_wallthicks_mget, self->data_ptr);
}

static int
Controller_set_tes_wallthicks(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Controller_tes_wallthicks_mset, self->data_ptr);
}

static PyObject *
Controller_get_trough_loop_control(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Controller_trough_loop_control_aget, self->data_ptr);
}

static int
Controller_set_trough_loop_control(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_Controller_trough_loop_control_aset, self->data_ptr);
}

static PyObject *
Controller_get_use_solar_mult_or_aperture_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_use_solar_mult_or_aperture_area_nget, self->data_ptr);
}

static int
Controller_set_use_solar_mult_or_aperture_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_use_solar_mult_or_aperture_area_nset, self->data_ptr);
}

static PyGetSetDef Controller_getset[] = {
{"DP_SGS", (getter)Controller_get_DP_SGS,(setter)Controller_set_DP_SGS,
	PyDoc_STR("*float*: Pressure drop within the steam generator [bar]\n\n**Required:**\nTrue"),
 	NULL},
{"T_tank_hot_inlet_min", (getter)Controller_get_T_tank_hot_inlet_min,(setter)Controller_set_T_tank_hot_inlet_min,
	PyDoc_STR("*float*: Minimum hot tank htf inlet temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"V_tes_des", (getter)Controller_get_V_tes_des,(setter)Controller_set_V_tes_des,
	PyDoc_STR("*float*: Design-point velocity to size the TES pipe diameters [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"custom_tes_p_loss", (getter)Controller_get_custom_tes_p_loss,(setter)Controller_set_custom_tes_p_loss,
	PyDoc_STR("*float*: TES pipe losses are based on custom lengths and coeffs [-]\n\n**Required:**\nTrue"),
 	NULL},
{"custom_tes_pipe_sizes", (getter)Controller_get_custom_tes_pipe_sizes,(setter)Controller_set_custom_tes_pipe_sizes,
	PyDoc_STR("*float*: Use custom TES pipe diams, wallthks, and lengths [-]\n\n**Required:**\nTrue"),
 	NULL},
{"has_hot_tank_bypass", (getter)Controller_get_has_hot_tank_bypass,(setter)Controller_set_has_hot_tank_bypass,
	PyDoc_STR("*float*: Bypass valve connects field outlet to cold tank [-]\n\n**Required:**\nTrue"),
 	NULL},
{"k_tes_loss_coeffs", (getter)Controller_get_k_tes_loss_coeffs,(setter)Controller_set_k_tes_loss_coeffs,
	PyDoc_STR("*sequence[sequence]*: Minor loss coeffs for the coll, gen, and bypass loops [-]\n\n**Required:**\nTrue"),
 	NULL},
{"non_solar_field_land_area_multiplier", (getter)Controller_get_non_solar_field_land_area_multiplier,(setter)Controller_set_non_solar_field_land_area_multiplier,
	PyDoc_STR("*float*: non_solar_field_land_area_multiplier [-]\n\n**Required:**\nTrue"),
 	NULL},
{"specified_solar_multiple", (getter)Controller_get_specified_solar_multiple,(setter)Controller_set_specified_solar_multiple,
	PyDoc_STR("*float*: specified_solar_multiple [-]\n\n**Required:**\nTrue"),
 	NULL},
{"specified_total_aperture", (getter)Controller_get_specified_total_aperture,(setter)Controller_set_specified_total_aperture,
	PyDoc_STR("*float*: specified_total_aperture [-]\n\n**Required:**\nTrue"),
 	NULL},
{"tanks_in_parallel", (getter)Controller_get_tanks_in_parallel,(setter)Controller_set_tanks_in_parallel,
	PyDoc_STR("*float*: Tanks are in parallel, not in series, with solar field [-]\n\n**Required:**\nRequired if tes_type=1"),
 	NULL},
{"tes_diams", (getter)Controller_get_tes_diams,(setter)Controller_set_tes_diams,
	PyDoc_STR("*sequence[sequence]*: Custom TES diameters [m]\n\n**Required:**\nRequired if custom_tes_pipe_sizes=1"),
 	NULL},
{"tes_lengths", (getter)Controller_get_tes_lengths,(setter)Controller_set_tes_lengths,
	PyDoc_STR("*sequence[sequence]*: Custom TES lengths [m]\n\n**Required:**\nRequired if custom_tes_pipe_sizes=1"),
 	NULL},
{"tes_pump_coef", (getter)Controller_get_tes_pump_coef,(setter)Controller_set_tes_pump_coef,
	PyDoc_STR("*float*: Pumping power to move 1kg of HTF through tes loop [kW/(kg/s)]\n\n**Required:**\nTrue"),
 	NULL},
{"tes_wallthicks", (getter)Controller_get_tes_wallthicks,(setter)Controller_set_tes_wallthicks,
	PyDoc_STR("*sequence[sequence]*: Custom TES wall thicknesses [m]\n\n**Required:**\nRequired if custom_tes_pipe_sizes=1"),
 	NULL},
{"trough_loop_control", (getter)Controller_get_trough_loop_control,(setter)Controller_set_trough_loop_control,
	PyDoc_STR("*sequence*: trough_loop_control [-]\n\n**Required:**\nTrue"),
 	NULL},
{"use_solar_mult_or_aperture_area", (getter)Controller_get_use_solar_mult_or_aperture_area,(setter)Controller_set_use_solar_mult_or_aperture_area,
	PyDoc_STR("*float*: Use solar multiple or total field aperture area [-]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Controller_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.Controller",             /*tp_name*/
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
		Controller_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Controller_getset,          /*tp_getset*/
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
 * Tou Group
 */ 

static PyTypeObject Tou_Type;

static PyObject *
Tou_new(SAM_TroughPhysical data_ptr)
{
	PyObject* new_obj = Tou_Type.tp_alloc(&Tou_Type,0);

	VarGroupObject* Tou_obj = (VarGroupObject*)new_obj;

	Tou_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Tou methods */

static PyObject *
Tou_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "Tou")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Tou_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Tou_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysical", "Tou")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Tou_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Tou_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Tou_methods[] = {
		{"assign",            (PyCFunction)Tou_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Tou_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Tou_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Tou_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Tou_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Tou_get_ampl_data_dir(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TroughPhysical_Tou_ampl_data_dir_sget, self->data_ptr);
}

static int
Tou_set_ampl_data_dir(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TroughPhysical_Tou_ampl_data_dir_sset, self->data_ptr);
}

static PyObject *
Tou_get_ampl_exec_call(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TroughPhysical_Tou_ampl_exec_call_sget, self->data_ptr);
}

static int
Tou_set_ampl_exec_call(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TroughPhysical_Tou_ampl_exec_call_sset, self->data_ptr);
}

static PyObject *
Tou_get_can_cycle_use_standby(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_can_cycle_use_standby_nget, self->data_ptr);
}

static int
Tou_set_can_cycle_use_standby(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_can_cycle_use_standby_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_csu_cost_rel(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_csu_cost_rel_nget, self->data_ptr);
}

static int
Tou_set_disp_csu_cost_rel(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_csu_cost_rel_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_frequency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_frequency_nget, self->data_ptr);
}

static int
Tou_set_disp_frequency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_frequency_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_horizon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_horizon_nget, self->data_ptr);
}

static int
Tou_set_disp_horizon(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_horizon_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_max_iter(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_max_iter_nget, self->data_ptr);
}

static int
Tou_set_disp_max_iter(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_max_iter_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_mip_gap(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_mip_gap_nget, self->data_ptr);
}

static int
Tou_set_disp_mip_gap(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_mip_gap_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_pen_delta_w(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_pen_delta_w_nget, self->data_ptr);
}

static int
Tou_set_disp_pen_delta_w(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_pen_delta_w_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_pen_ramping(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_pen_ramping_nget, self->data_ptr);
}

static int
Tou_set_disp_pen_ramping(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_pen_ramping_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_reporting(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_reporting_nget, self->data_ptr);
}

static int
Tou_set_disp_reporting(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_reporting_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_rsu_cost_rel(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_rsu_cost_rel_nget, self->data_ptr);
}

static int
Tou_set_disp_rsu_cost_rel(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_rsu_cost_rel_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_spec_bb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_spec_bb_nget, self->data_ptr);
}

static int
Tou_set_disp_spec_bb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_spec_bb_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_spec_presolve(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_spec_presolve_nget, self->data_ptr);
}

static int
Tou_set_disp_spec_presolve(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_spec_presolve_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_spec_scaling(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_spec_scaling_nget, self->data_ptr);
}

static int
Tou_set_disp_spec_scaling(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_spec_scaling_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_steps_per_hour(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_steps_per_hour_nget, self->data_ptr);
}

static int
Tou_set_disp_steps_per_hour(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_steps_per_hour_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_time_weighting(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_time_weighting_nget, self->data_ptr);
}

static int
Tou_set_disp_time_weighting(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_time_weighting_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_timeout(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_timeout_nget, self->data_ptr);
}

static int
Tou_set_disp_timeout(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_timeout_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factors_ts(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Tou_dispatch_factors_ts_aget, self->data_ptr);
}

static int
Tou_set_dispatch_factors_ts(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_Tou_dispatch_factors_ts_aset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Tou_dispatch_sched_weekday_mget, self->data_ptr);
}

static int
Tou_set_dispatch_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Tou_dispatch_sched_weekday_mset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Tou_dispatch_sched_weekend_mget, self->data_ptr);
}

static int
Tou_set_dispatch_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Tou_dispatch_sched_weekend_mset, self->data_ptr);
}

static PyObject *
Tou_get_f_turb_tou_periods(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Tou_f_turb_tou_periods_aget, self->data_ptr);
}

static int
Tou_set_f_turb_tou_periods(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_Tou_f_turb_tou_periods_aset, self->data_ptr);
}

static PyObject *
Tou_get_is_ampl_engine(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_is_ampl_engine_nget, self->data_ptr);
}

static int
Tou_set_is_ampl_engine(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_is_ampl_engine_nset, self->data_ptr);
}

static PyObject *
Tou_get_is_dispatch(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_is_dispatch_nget, self->data_ptr);
}

static int
Tou_set_is_dispatch(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_is_dispatch_nset, self->data_ptr);
}

static PyObject *
Tou_get_is_timestep_load_fractions(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_is_timestep_load_fractions_nget, self->data_ptr);
}

static int
Tou_set_is_timestep_load_fractions(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_is_timestep_load_fractions_nset, self->data_ptr);
}

static PyObject *
Tou_get_is_tod_pc_target_also_pc_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_is_tod_pc_target_also_pc_max_nget, self->data_ptr);
}

static int
Tou_set_is_tod_pc_target_also_pc_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_is_tod_pc_target_also_pc_max_nset, self->data_ptr);
}

static PyObject *
Tou_get_is_write_ampl_dat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_is_write_ampl_dat_nget, self->data_ptr);
}

static int
Tou_set_is_write_ampl_dat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_is_write_ampl_dat_nset, self->data_ptr);
}

static PyObject *
Tou_get_ppa_multiplier_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_ppa_multiplier_model_nget, self->data_ptr);
}

static int
Tou_set_ppa_multiplier_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_ppa_multiplier_model_nset, self->data_ptr);
}

static PyObject *
Tou_get_q_rec_heattrace(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_q_rec_heattrace_nget, self->data_ptr);
}

static int
Tou_set_q_rec_heattrace(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_q_rec_heattrace_nset, self->data_ptr);
}

static PyObject *
Tou_get_q_rec_standby(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_q_rec_standby_nget, self->data_ptr);
}

static int
Tou_set_q_rec_standby(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_q_rec_standby_nset, self->data_ptr);
}

static PyObject *
Tou_get_timestep_load_fractions(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Tou_timestep_load_fractions_aget, self->data_ptr);
}

static int
Tou_set_timestep_load_fractions(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_Tou_timestep_load_fractions_aset, self->data_ptr);
}

static PyObject *
Tou_get_weekday_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Tou_weekday_schedule_mget, self->data_ptr);
}

static int
Tou_set_weekday_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Tou_weekday_schedule_mset, self->data_ptr);
}

static PyObject *
Tou_get_weekend_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Tou_weekend_schedule_mget, self->data_ptr);
}

static int
Tou_set_weekend_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Tou_weekend_schedule_mset, self->data_ptr);
}

static PyGetSetDef Tou_getset[] = {
{"ampl_data_dir", (getter)Tou_get_ampl_data_dir,(setter)Tou_set_ampl_data_dir,
	PyDoc_STR("*str*: AMPL data file directory [-]\n\n**Required:**\nFalse. Automatically set to '' if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ampl_exec_call", (getter)Tou_get_ampl_exec_call,(setter)Tou_set_ampl_exec_call,
	PyDoc_STR("*str*: System command to run AMPL code [-]\n\n**Required:**\nFalse. Automatically set to 'ampl sdk_solution.run' if not assigned explicitly or loaded from defaults."),
 	NULL},
{"can_cycle_use_standby", (getter)Tou_get_can_cycle_use_standby,(setter)Tou_set_can_cycle_use_standby,
	PyDoc_STR("*float*: Can the cycle use standby operation?\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_csu_cost_rel", (getter)Tou_get_disp_csu_cost_rel,(setter)Tou_set_disp_csu_cost_rel,
	PyDoc_STR("*float*: Cycle startup cost [$/MWe-cycle/start]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_frequency", (getter)Tou_get_disp_frequency,(setter)Tou_set_disp_frequency,
	PyDoc_STR("*float*: Frequency for dispatch optimization calculations [hour]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_horizon", (getter)Tou_get_disp_horizon,(setter)Tou_set_disp_horizon,
	PyDoc_STR("*float*: Time horizon for dispatch optimization [hour]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_max_iter", (getter)Tou_get_disp_max_iter,(setter)Tou_set_disp_max_iter,
	PyDoc_STR("*float*: Max. no. dispatch optimization iterations [-]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_mip_gap", (getter)Tou_get_disp_mip_gap,(setter)Tou_set_disp_mip_gap,
	PyDoc_STR("*float*: Dispatch optimization solution tolerance [-]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_pen_delta_w", (getter)Tou_get_disp_pen_delta_w,(setter)Tou_set_disp_pen_delta_w,
	PyDoc_STR("*float*: Dispatch cycle production change penalty [$/kWe-change]"),
 	NULL},
{"disp_pen_ramping", (getter)Tou_get_disp_pen_ramping,(setter)Tou_set_disp_pen_ramping,
	PyDoc_STR("*float*: Dispatch cycle production change penalty [$/MWe-change]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_reporting", (getter)Tou_get_disp_reporting,(setter)Tou_set_disp_reporting,
	PyDoc_STR("*float*: Dispatch optimization reporting level [-]\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_rsu_cost_rel", (getter)Tou_get_disp_rsu_cost_rel,(setter)Tou_set_disp_rsu_cost_rel,
	PyDoc_STR("*float*: Receiver startup cost [$/MWt/start]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_spec_bb", (getter)Tou_get_disp_spec_bb,(setter)Tou_set_disp_spec_bb,
	PyDoc_STR("*float*: Dispatch optimization B&B heuristic [-]\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_spec_presolve", (getter)Tou_get_disp_spec_presolve,(setter)Tou_set_disp_spec_presolve,
	PyDoc_STR("*float*: Dispatch optimization presolve heuristic [-]\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_spec_scaling", (getter)Tou_get_disp_spec_scaling,(setter)Tou_set_disp_spec_scaling,
	PyDoc_STR("*float*: Dispatch optimization scaling heuristic [-]\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_steps_per_hour", (getter)Tou_get_disp_steps_per_hour,(setter)Tou_set_disp_steps_per_hour,
	PyDoc_STR("*float*: Time steps per hour for dispatch optimization calculations [-]\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_time_weighting", (getter)Tou_get_disp_time_weighting,(setter)Tou_set_disp_time_weighting,
	PyDoc_STR("*float*: Dispatch optimization future time discounting factor [-]\n\n**Required:**\nFalse. Automatically set to 0.99 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_timeout", (getter)Tou_get_disp_timeout,(setter)Tou_set_disp_timeout,
	PyDoc_STR("*float*: Max. dispatch optimization solve duration [s]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"dispatch_factors_ts", (getter)Tou_get_dispatch_factors_ts,(setter)Tou_set_dispatch_factors_ts,
	PyDoc_STR("*sequence*: Dispatch payment factor array\n\n**Required:**\nRequired if sim_type=1&ppa_multiplier_model=1&csp_financial_model<5&is_dispatch=1"),
 	NULL},
{"dispatch_sched_weekday", (getter)Tou_get_dispatch_sched_weekday,(setter)Tou_set_dispatch_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: 12x24 PPA pricing Weekday schedule\n\n**Required:**\nRequired if sim_type=1&ppa_multiplier_model=0&csp_financial_model<5&is_dispatch=1"),
 	NULL},
{"dispatch_sched_weekend", (getter)Tou_get_dispatch_sched_weekend,(setter)Tou_set_dispatch_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: 12x24 PPA pricing Weekend schedule\n\n**Required:**\nRequired if sim_type=1&ppa_multiplier_model=0&csp_financial_model<5&is_dispatch=1"),
 	NULL},
{"f_turb_tou_periods", (getter)Tou_get_f_turb_tou_periods,(setter)Tou_set_f_turb_tou_periods,
	PyDoc_STR("*sequence*: Dispatch logic for turbine load fraction [-]\n\n**Required:**\nTrue"),
 	NULL},
{"is_ampl_engine", (getter)Tou_get_is_ampl_engine,(setter)Tou_set_is_ampl_engine,
	PyDoc_STR("*float*: Run dispatch optimization with external AMPL engine [-]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"is_dispatch", (getter)Tou_get_is_dispatch,(setter)Tou_set_is_dispatch,
	PyDoc_STR("*float*: Allow dispatch optimization? [-]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"is_timestep_load_fractions", (getter)Tou_get_is_timestep_load_fractions,(setter)Tou_set_is_timestep_load_fractions,
	PyDoc_STR("*float*: Use turbine load fraction for each timestep instead of block dispatch?\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"is_tod_pc_target_also_pc_max", (getter)Tou_get_is_tod_pc_target_also_pc_max,(setter)Tou_set_is_tod_pc_target_also_pc_max,
	PyDoc_STR("*float*: Is the TOD target cycle heat input also the max cycle heat input?\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"is_write_ampl_dat", (getter)Tou_get_is_write_ampl_dat,(setter)Tou_set_is_write_ampl_dat,
	PyDoc_STR("*float*: Write AMPL data files for dispatch run [-]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ppa_multiplier_model", (getter)Tou_get_ppa_multiplier_model,(setter)Tou_set_ppa_multiplier_model,
	PyDoc_STR("*float*: PPA multiplier model 0: dispatch factors dispatch_factorX, 1: hourly multipliers dispatch_factors_ts [0/1]\n\n**Options:**\n0=diurnal,1=timestep\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"q_rec_heattrace", (getter)Tou_get_q_rec_heattrace,(setter)Tou_set_q_rec_heattrace,
	PyDoc_STR("*float*: Receiver heat trace energy consumption during startup [kWhe]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"q_rec_standby", (getter)Tou_get_q_rec_standby,(setter)Tou_set_q_rec_standby,
	PyDoc_STR("*float*: Receiver standby energy consumption [kWt]\n\n**Required:**\nFalse. Automatically set to 9e99 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"timestep_load_fractions", (getter)Tou_get_timestep_load_fractions,(setter)Tou_set_timestep_load_fractions,
	PyDoc_STR("*sequence*: Turbine load fraction for each timestep, alternative to block dispatch\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"weekday_schedule", (getter)Tou_get_weekday_schedule,(setter)Tou_set_weekday_schedule,
	PyDoc_STR("*sequence[sequence]*: 12x24 CSP operation Time-of-Use Weekday schedule [-]\n\n**Required:**\nTrue"),
 	NULL},
{"weekend_schedule", (getter)Tou_get_weekend_schedule,(setter)Tou_set_weekend_schedule,
	PyDoc_STR("*sequence[sequence]*: 12x24 CSP operation Time-of-Use Weekend schedule [-]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Tou_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.Tou",             /*tp_name*/
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
		Tou_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Tou_getset,          /*tp_getset*/
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
FinancialModel_new(SAM_TroughPhysical data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "FinancialModel")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysical", "FinancialModel")){
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
FinancialModel_get_csp_financial_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialModel_csp_financial_model_nget, self->data_ptr);
}

static int
FinancialModel_set_csp_financial_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialModel_csp_financial_model_nset, self->data_ptr);
}

static PyGetSetDef FinancialModel_getset[] = {
{"csp_financial_model", (getter)FinancialModel_get_csp_financial_model,(setter)FinancialModel_set_csp_financial_model,
	PyDoc_STR("*float*:  [1-8]\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FinancialModel_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.FinancialModel",             /*tp_name*/
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
 * FinancialSolutionMode Group
 */ 

static PyTypeObject FinancialSolutionMode_Type;

static PyObject *
FinancialSolutionMode_new(SAM_TroughPhysical data_ptr)
{
	PyObject* new_obj = FinancialSolutionMode_Type.tp_alloc(&FinancialSolutionMode_Type,0);

	VarGroupObject* FinancialSolutionMode_obj = (VarGroupObject*)new_obj;

	FinancialSolutionMode_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* FinancialSolutionMode methods */

static PyObject *
FinancialSolutionMode_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "FinancialSolutionMode")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialSolutionMode_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &FinancialSolutionMode_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysical", "FinancialSolutionMode")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialSolutionMode_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &FinancialSolutionMode_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef FinancialSolutionMode_methods[] = {
		{"assign",            (PyCFunction)FinancialSolutionMode_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``FinancialSolutionMode_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)FinancialSolutionMode_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``FinancialSolutionMode_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)FinancialSolutionMode_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
FinancialSolutionMode_get_ppa_soln_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialSolutionMode_ppa_soln_mode_nget, self->data_ptr);
}

static int
FinancialSolutionMode_set_ppa_soln_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialSolutionMode_ppa_soln_mode_nset, self->data_ptr);
}

static PyGetSetDef FinancialSolutionMode_getset[] = {
{"ppa_soln_mode", (getter)FinancialSolutionMode_get_ppa_soln_mode,(setter)FinancialSolutionMode_set_ppa_soln_mode,
	PyDoc_STR("*float*: PPA solution mode (0=Specify IRR target, 1=Specify PPA price)\n\n**Required:**\nRequired if sim_type=1&ppa_multiplier_model=0&csp_financial_model<5&is_dispatch=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FinancialSolutionMode_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.FinancialSolutionMode",             /*tp_name*/
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
		FinancialSolutionMode_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		FinancialSolutionMode_getset,          /*tp_getset*/
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
ElectricityRates_new(SAM_TroughPhysical data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "ElectricityRates")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysical", "ElectricityRates")){
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
	return PySAM_double_getter(SAM_TroughPhysical_ElectricityRates_en_electricity_rates_nget, self->data_ptr);
}

static int
ElectricityRates_set_en_electricity_rates(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_ElectricityRates_en_electricity_rates_nset, self->data_ptr);
}

static PyGetSetDef ElectricityRates_getset[] = {
{"en_electricity_rates", (getter)ElectricityRates_get_en_electricity_rates,(setter)ElectricityRates_set_en_electricity_rates,
	PyDoc_STR("*float*: Enable electricity rates for grid purchase [0/1]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ElectricityRates_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.ElectricityRates",             /*tp_name*/
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
 * TimeOfDeliveryFactors Group
 */ 

static PyTypeObject TimeOfDeliveryFactors_Type;

static PyObject *
TimeOfDeliveryFactors_new(SAM_TroughPhysical data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "TimeOfDeliveryFactors")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysical", "TimeOfDeliveryFactors")){
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
TimeOfDeliveryFactors_get_dispatch_tod_factors(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_TimeOfDeliveryFactors_dispatch_tod_factors_aget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_tod_factors(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_TimeOfDeliveryFactors_dispatch_tod_factors_aset, self->data_ptr);
}

static PyGetSetDef TimeOfDeliveryFactors_getset[] = {
{"dispatch_tod_factors", (getter)TimeOfDeliveryFactors_get_dispatch_tod_factors,(setter)TimeOfDeliveryFactors_set_dispatch_tod_factors,
	PyDoc_STR("*sequence*: TOD factors for periods 1 through 9\n\n**Info:**\nWe added this array input after SAM 2022.12.21 to replace the functionality of former single value inputs dispatch_factor1 through dispatch_factor9\n\n**Required:**\nRequired if sim_type=1&ppa_multiplier_model=0&csp_financial_model<5&is_dispatch=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TimeOfDeliveryFactors_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.TimeOfDeliveryFactors",             /*tp_name*/
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
Revenue_new(SAM_TroughPhysical data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "Revenue")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysical", "Revenue")){
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
Revenue_get_mp_energy_market_revenue(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Revenue_mp_energy_market_revenue_mget, self->data_ptr);
}

static int
Revenue_set_mp_energy_market_revenue(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Revenue_mp_energy_market_revenue_mset, self->data_ptr);
}

static PyObject *
Revenue_get_ppa_price_input(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Revenue_ppa_price_input_aget, self->data_ptr);
}

static int
Revenue_set_ppa_price_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_Revenue_ppa_price_input_aset, self->data_ptr);
}

static PyGetSetDef Revenue_getset[] = {
{"mp_energy_market_revenue", (getter)Revenue_get_mp_energy_market_revenue,(setter)Revenue_set_mp_energy_market_revenue,
	PyDoc_STR("*sequence[sequence]*: Energy market revenue input\n\n**Info:**\nLifetime x 2[Cleared Capacity(MW),Price($/MWh)]\n\n**Required:**\nRequired if sim_type=1&csp_financial_model=6&is_dispatch=1"),
 	NULL},
{"ppa_price_input", (getter)Revenue_get_ppa_price_input,(setter)Revenue_set_ppa_price_input,
	PyDoc_STR("*sequence*: PPA prices - yearly [$/kWh]\n\n**Required:**\nRequired if sim_type=1&ppa_multiplier_model=0&csp_financial_model<5&is_dispatch=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Revenue_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.Revenue",             /*tp_name*/
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
 * System Group
 */ 

static PyTypeObject System_Type;

static PyObject *
System_new(SAM_TroughPhysical data_ptr)
{
	PyObject* new_obj = System_Type.tp_alloc(&System_Type,0);

	VarGroupObject* System_obj = (VarGroupObject*)new_obj;

	System_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* System methods */

static PyObject *
System_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "System")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
System_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &System_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysical", "System")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
System_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &System_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef System_methods[] = {
		{"assign",            (PyCFunction)System_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``System_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)System_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``System_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)System_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
System_get_aux_array(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_System_aux_array_aget, self->data_ptr);
}

static int
System_set_aux_array(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_System_aux_array_aset, self->data_ptr);
}

static PyObject *
System_get_bop_array(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_System_bop_array_aget, self->data_ptr);
}

static int
System_set_bop_array(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_System_bop_array_aset, self->data_ptr);
}

static PyObject *
System_get_gross_net_conversion_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_System_gross_net_conversion_factor_nget, self->data_ptr);
}

static int
System_set_gross_net_conversion_factor(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_System_gross_net_conversion_factor_nset, self->data_ptr);
}

static PyObject *
System_get_pb_fixed_par(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_System_pb_fixed_par_nget, self->data_ptr);
}

static int
System_set_pb_fixed_par(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_System_pb_fixed_par_nset, self->data_ptr);
}

static PyObject *
System_get_washing_frequency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_System_washing_frequency_nget, self->data_ptr);
}

static int
System_set_washing_frequency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_System_washing_frequency_nset, self->data_ptr);
}

static PyObject *
System_get_water_usage_per_wash(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_System_water_usage_per_wash_nget, self->data_ptr);
}

static int
System_set_water_usage_per_wash(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_System_water_usage_per_wash_nset, self->data_ptr);
}

static PyGetSetDef System_getset[] = {
{"aux_array", (getter)System_get_aux_array,(setter)System_set_aux_array,
	PyDoc_STR("*sequence*: Auxiliary heater, mult frac and const, linear and quad coeff\n\n**Required:**\nTrue"),
 	NULL},
{"bop_array", (getter)System_get_bop_array,(setter)System_set_bop_array,
	PyDoc_STR("*sequence*: Balance of plant parasitic power fraction, mult frac and const, linear and quad coeff\n\n**Required:**\nTrue"),
 	NULL},
{"gross_net_conversion_factor", (getter)System_get_gross_net_conversion_factor,(setter)System_set_gross_net_conversion_factor,
	PyDoc_STR("*float*: Estimated gross to net conversion factor\n\n**Required:**\nTrue"),
 	NULL},
{"pb_fixed_par", (getter)System_get_pb_fixed_par,(setter)System_set_pb_fixed_par,
	PyDoc_STR("*float*: Fraction of rated gross power constantly consumed [MWe/MWcap]\n\n**Required:**\nTrue"),
 	NULL},
{"washing_frequency", (getter)System_get_washing_frequency,(setter)System_set_washing_frequency,
	PyDoc_STR("*float*: Mirror washing frequency [-/year]\n\n**Required:**\nTrue"),
 	NULL},
{"water_usage_per_wash", (getter)System_get_water_usage_per_wash,(setter)System_set_water_usage_per_wash,
	PyDoc_STR("*float*: Water usage per wash [L/m2_aper]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject System_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.System",             /*tp_name*/
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
		System_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		System_getset,          /*tp_getset*/
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
 * TowerAndReceiver Group
 */ 

static PyTypeObject TowerAndReceiver_Type;

static PyObject *
TowerAndReceiver_new(SAM_TroughPhysical data_ptr)
{
	PyObject* new_obj = TowerAndReceiver_Type.tp_alloc(&TowerAndReceiver_Type,0);

	VarGroupObject* TowerAndReceiver_obj = (VarGroupObject*)new_obj;

	TowerAndReceiver_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* TowerAndReceiver methods */

static PyObject *
TowerAndReceiver_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "TowerAndReceiver")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TowerAndReceiver_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &TowerAndReceiver_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysical", "TowerAndReceiver")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TowerAndReceiver_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &TowerAndReceiver_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TowerAndReceiver_methods[] = {
		{"assign",            (PyCFunction)TowerAndReceiver_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``TowerAndReceiver_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)TowerAndReceiver_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``TowerAndReceiver_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)TowerAndReceiver_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TowerAndReceiver_get_piping_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TowerAndReceiver_piping_loss_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_piping_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TowerAndReceiver_piping_loss_nset, self->data_ptr);
}

static PyGetSetDef TowerAndReceiver_getset[] = {
{"piping_loss", (getter)TowerAndReceiver_get_piping_loss,(setter)TowerAndReceiver_set_piping_loss,
	PyDoc_STR("*float*: Thermal loss per meter of piping [Wt/m]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TowerAndReceiver_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.TowerAndReceiver",             /*tp_name*/
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
		TowerAndReceiver_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TowerAndReceiver_getset,          /*tp_getset*/
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
 * CapitalCosts Group
 */ 

static PyTypeObject CapitalCosts_Type;

static PyObject *
CapitalCosts_new(SAM_TroughPhysical data_ptr)
{
	PyObject* new_obj = CapitalCosts_Type.tp_alloc(&CapitalCosts_Type,0);

	VarGroupObject* CapitalCosts_obj = (VarGroupObject*)new_obj;

	CapitalCosts_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* CapitalCosts methods */

static PyObject *
CapitalCosts_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "CapitalCosts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
CapitalCosts_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &CapitalCosts_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysical", "CapitalCosts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
CapitalCosts_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &CapitalCosts_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef CapitalCosts_methods[] = {
		{"assign",            (PyCFunction)CapitalCosts_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``CapitalCosts_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)CapitalCosts_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``CapitalCosts_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)CapitalCosts_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
CapitalCosts_get_csp_dtr_cost_bop_per_kwe(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_bop_per_kwe_nget, self->data_ptr);
}

static int
CapitalCosts_set_csp_dtr_cost_bop_per_kwe(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_bop_per_kwe_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_csp_dtr_cost_contingency_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_contingency_percent_nget, self->data_ptr);
}

static int
CapitalCosts_set_csp_dtr_cost_contingency_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_contingency_percent_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_csp_dtr_cost_epc_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_epc_fixed_nget, self->data_ptr);
}

static int
CapitalCosts_set_csp_dtr_cost_epc_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_epc_fixed_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_csp_dtr_cost_epc_per_acre(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_epc_per_acre_nget, self->data_ptr);
}

static int
CapitalCosts_set_csp_dtr_cost_epc_per_acre(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_epc_per_acre_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_csp_dtr_cost_epc_per_watt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_epc_per_watt_nget, self->data_ptr);
}

static int
CapitalCosts_set_csp_dtr_cost_epc_per_watt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_epc_per_watt_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_csp_dtr_cost_epc_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_epc_percent_nget, self->data_ptr);
}

static int
CapitalCosts_set_csp_dtr_cost_epc_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_epc_percent_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_csp_dtr_cost_fossil_backup_cost_per_kwe(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_fossil_backup_cost_per_kwe_nget, self->data_ptr);
}

static int
CapitalCosts_set_csp_dtr_cost_fossil_backup_cost_per_kwe(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_fossil_backup_cost_per_kwe_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_csp_dtr_cost_htf_system_cost_per_m2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_htf_system_cost_per_m2_nget, self->data_ptr);
}

static int
CapitalCosts_set_csp_dtr_cost_htf_system_cost_per_m2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_htf_system_cost_per_m2_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_csp_dtr_cost_plm_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_plm_fixed_nget, self->data_ptr);
}

static int
CapitalCosts_set_csp_dtr_cost_plm_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_plm_fixed_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_csp_dtr_cost_plm_per_acre(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_plm_per_acre_nget, self->data_ptr);
}

static int
CapitalCosts_set_csp_dtr_cost_plm_per_acre(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_plm_per_acre_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_csp_dtr_cost_plm_per_watt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_plm_per_watt_nget, self->data_ptr);
}

static int
CapitalCosts_set_csp_dtr_cost_plm_per_watt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_plm_per_watt_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_csp_dtr_cost_plm_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_plm_percent_nget, self->data_ptr);
}

static int
CapitalCosts_set_csp_dtr_cost_plm_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_plm_percent_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_csp_dtr_cost_power_plant_cost_per_kwe(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_power_plant_cost_per_kwe_nget, self->data_ptr);
}

static int
CapitalCosts_set_csp_dtr_cost_power_plant_cost_per_kwe(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_power_plant_cost_per_kwe_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_csp_dtr_cost_sales_tax_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_sales_tax_percent_nget, self->data_ptr);
}

static int
CapitalCosts_set_csp_dtr_cost_sales_tax_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_sales_tax_percent_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_csp_dtr_cost_site_improvements_cost_per_m2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_site_improvements_cost_per_m2_nget, self->data_ptr);
}

static int
CapitalCosts_set_csp_dtr_cost_site_improvements_cost_per_m2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_site_improvements_cost_per_m2_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_csp_dtr_cost_solar_field_cost_per_m2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_solar_field_cost_per_m2_nget, self->data_ptr);
}

static int
CapitalCosts_set_csp_dtr_cost_solar_field_cost_per_m2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_solar_field_cost_per_m2_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_csp_dtr_cost_storage_cost_per_kwht(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_storage_cost_per_kwht_nget, self->data_ptr);
}

static int
CapitalCosts_set_csp_dtr_cost_storage_cost_per_kwht(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_CapitalCosts_csp_dtr_cost_storage_cost_per_kwht_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_sales_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_CapitalCosts_sales_tax_rate_nget, self->data_ptr);
}

static int
CapitalCosts_set_sales_tax_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_CapitalCosts_sales_tax_rate_nset, self->data_ptr);
}

static PyGetSetDef CapitalCosts_getset[] = {
{"csp_dtr_cost_bop_per_kwe", (getter)CapitalCosts_get_csp_dtr_cost_bop_per_kwe,(setter)CapitalCosts_set_csp_dtr_cost_bop_per_kwe,
	PyDoc_STR("*float*: Balance of Plant Cost per kWe [$/kWe]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"csp_dtr_cost_contingency_percent", (getter)CapitalCosts_get_csp_dtr_cost_contingency_percent,(setter)CapitalCosts_set_csp_dtr_cost_contingency_percent,
	PyDoc_STR("*float*: Contingency Percent [%]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"csp_dtr_cost_epc_fixed", (getter)CapitalCosts_get_csp_dtr_cost_epc_fixed,(setter)CapitalCosts_set_csp_dtr_cost_epc_fixed,
	PyDoc_STR("*float*: Fixed EPC Cost [$]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"csp_dtr_cost_epc_per_acre", (getter)CapitalCosts_get_csp_dtr_cost_epc_per_acre,(setter)CapitalCosts_set_csp_dtr_cost_epc_per_acre,
	PyDoc_STR("*float*: EPC Costs per acre [$/acre]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"csp_dtr_cost_epc_per_watt", (getter)CapitalCosts_get_csp_dtr_cost_epc_per_watt,(setter)CapitalCosts_set_csp_dtr_cost_epc_per_watt,
	PyDoc_STR("*float*: EPC Cost Wac [$/Wac]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"csp_dtr_cost_epc_percent", (getter)CapitalCosts_get_csp_dtr_cost_epc_percent,(setter)CapitalCosts_set_csp_dtr_cost_epc_percent,
	PyDoc_STR("*float*: EPC Costs % direct [%]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"csp_dtr_cost_fossil_backup_cost_per_kwe", (getter)CapitalCosts_get_csp_dtr_cost_fossil_backup_cost_per_kwe,(setter)CapitalCosts_set_csp_dtr_cost_fossil_backup_cost_per_kwe,
	PyDoc_STR("*float*: Fossil Backup Cost per kWe [$/kWe]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"csp_dtr_cost_htf_system_cost_per_m2", (getter)CapitalCosts_get_csp_dtr_cost_htf_system_cost_per_m2,(setter)CapitalCosts_set_csp_dtr_cost_htf_system_cost_per_m2,
	PyDoc_STR("*float*: HTF System Cost Per m2 [$/m2]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"csp_dtr_cost_plm_fixed", (getter)CapitalCosts_get_csp_dtr_cost_plm_fixed,(setter)CapitalCosts_set_csp_dtr_cost_plm_fixed,
	PyDoc_STR("*float*: Fixed Land Cost [$]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"csp_dtr_cost_plm_per_acre", (getter)CapitalCosts_get_csp_dtr_cost_plm_per_acre,(setter)CapitalCosts_set_csp_dtr_cost_plm_per_acre,
	PyDoc_STR("*float*: Land Cost per acre [$/acre]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"csp_dtr_cost_plm_per_watt", (getter)CapitalCosts_get_csp_dtr_cost_plm_per_watt,(setter)CapitalCosts_set_csp_dtr_cost_plm_per_watt,
	PyDoc_STR("*float*: Land Cost Wac [$/Wac]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"csp_dtr_cost_plm_percent", (getter)CapitalCosts_get_csp_dtr_cost_plm_percent,(setter)CapitalCosts_set_csp_dtr_cost_plm_percent,
	PyDoc_STR("*float*: Land Cost % direct [%]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"csp_dtr_cost_power_plant_cost_per_kwe", (getter)CapitalCosts_get_csp_dtr_cost_power_plant_cost_per_kwe,(setter)CapitalCosts_set_csp_dtr_cost_power_plant_cost_per_kwe,
	PyDoc_STR("*float*: Power Plant Cost per kWe [$/kWe]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"csp_dtr_cost_sales_tax_percent", (getter)CapitalCosts_get_csp_dtr_cost_sales_tax_percent,(setter)CapitalCosts_set_csp_dtr_cost_sales_tax_percent,
	PyDoc_STR("*float*: Sales Tax Percentage of Direct Cost [%]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"csp_dtr_cost_site_improvements_cost_per_m2", (getter)CapitalCosts_get_csp_dtr_cost_site_improvements_cost_per_m2,(setter)CapitalCosts_set_csp_dtr_cost_site_improvements_cost_per_m2,
	PyDoc_STR("*float*: Site Improvement Cost per m2 [$/m2]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"csp_dtr_cost_solar_field_cost_per_m2", (getter)CapitalCosts_get_csp_dtr_cost_solar_field_cost_per_m2,(setter)CapitalCosts_set_csp_dtr_cost_solar_field_cost_per_m2,
	PyDoc_STR("*float*: Solar Field Cost per m2 [$/m2]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"csp_dtr_cost_storage_cost_per_kwht", (getter)CapitalCosts_get_csp_dtr_cost_storage_cost_per_kwht,(setter)CapitalCosts_set_csp_dtr_cost_storage_cost_per_kwht,
	PyDoc_STR("*float*: Storage cost per kWht [$/kWht]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"sales_tax_rate", (getter)CapitalCosts_get_sales_tax_rate,(setter)CapitalCosts_set_sales_tax_rate,
	PyDoc_STR("*float*: Sales Tax Rate [%]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject CapitalCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.CapitalCosts",             /*tp_name*/
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
		CapitalCosts_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		CapitalCosts_getset,          /*tp_getset*/
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
FinancialParameters_new(SAM_TroughPhysical data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "FinancialParameters")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysical", "FinancialParameters")){
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
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_interest_rate1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_interest_rate1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_interest_rate2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_interest_rate2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_interest_rate3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_interest_rate3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_interest_rate4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_interest_rate4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_interest_rate5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_interest_rate5_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_months1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_months1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_months2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_months2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_months3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_months3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_months4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_months4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_months5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_months5_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_percent1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_percent1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_percent2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_percent2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_percent3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_percent3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_percent4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_percent4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_percent5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_percent5_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_upfront_rate1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_upfront_rate1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_upfront_rate2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_upfront_rate2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_upfront_rate3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_upfront_rate3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_upfront_rate4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_upfront_rate4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_FinancialParameters_const_per_upfront_rate5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_FinancialParameters_const_per_upfront_rate5_nset, self->data_ptr);
}

static PyGetSetDef FinancialParameters_getset[] = {
{"const_per_interest_rate1", (getter)FinancialParameters_get_const_per_interest_rate1,(setter)FinancialParameters_set_const_per_interest_rate1,
	PyDoc_STR("*float*: Interest rate, loan 1 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_interest_rate2", (getter)FinancialParameters_get_const_per_interest_rate2,(setter)FinancialParameters_set_const_per_interest_rate2,
	PyDoc_STR("*float*: Interest rate, loan 2 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_interest_rate3", (getter)FinancialParameters_get_const_per_interest_rate3,(setter)FinancialParameters_set_const_per_interest_rate3,
	PyDoc_STR("*float*: Interest rate, loan 3 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_interest_rate4", (getter)FinancialParameters_get_const_per_interest_rate4,(setter)FinancialParameters_set_const_per_interest_rate4,
	PyDoc_STR("*float*: Interest rate, loan 4 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_interest_rate5", (getter)FinancialParameters_get_const_per_interest_rate5,(setter)FinancialParameters_set_const_per_interest_rate5,
	PyDoc_STR("*float*: Interest rate, loan 5 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_months1", (getter)FinancialParameters_get_const_per_months1,(setter)FinancialParameters_set_const_per_months1,
	PyDoc_STR("*float*: Months prior to operation, loan 1\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_months2", (getter)FinancialParameters_get_const_per_months2,(setter)FinancialParameters_set_const_per_months2,
	PyDoc_STR("*float*: Months prior to operation, loan 2\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_months3", (getter)FinancialParameters_get_const_per_months3,(setter)FinancialParameters_set_const_per_months3,
	PyDoc_STR("*float*: Months prior to operation, loan 3\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_months4", (getter)FinancialParameters_get_const_per_months4,(setter)FinancialParameters_set_const_per_months4,
	PyDoc_STR("*float*: Months prior to operation, loan 4\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_months5", (getter)FinancialParameters_get_const_per_months5,(setter)FinancialParameters_set_const_per_months5,
	PyDoc_STR("*float*: Months prior to operation, loan 5\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_percent1", (getter)FinancialParameters_get_const_per_percent1,(setter)FinancialParameters_set_const_per_percent1,
	PyDoc_STR("*float*: Percent of total installed cost, loan 1 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_percent2", (getter)FinancialParameters_get_const_per_percent2,(setter)FinancialParameters_set_const_per_percent2,
	PyDoc_STR("*float*: Percent of total installed cost, loan 2 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_percent3", (getter)FinancialParameters_get_const_per_percent3,(setter)FinancialParameters_set_const_per_percent3,
	PyDoc_STR("*float*: Percent of total installed cost, loan 3 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_percent4", (getter)FinancialParameters_get_const_per_percent4,(setter)FinancialParameters_set_const_per_percent4,
	PyDoc_STR("*float*: Percent of total installed cost, loan 4 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_percent5", (getter)FinancialParameters_get_const_per_percent5,(setter)FinancialParameters_set_const_per_percent5,
	PyDoc_STR("*float*: Percent of total installed cost, loan 5 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_upfront_rate1", (getter)FinancialParameters_get_const_per_upfront_rate1,(setter)FinancialParameters_set_const_per_upfront_rate1,
	PyDoc_STR("*float*: Upfront fee on principal, loan 1 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_upfront_rate2", (getter)FinancialParameters_get_const_per_upfront_rate2,(setter)FinancialParameters_set_const_per_upfront_rate2,
	PyDoc_STR("*float*: Upfront fee on principal, loan 2 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_upfront_rate3", (getter)FinancialParameters_get_const_per_upfront_rate3,(setter)FinancialParameters_set_const_per_upfront_rate3,
	PyDoc_STR("*float*: Upfront fee on principal, loan 3 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_upfront_rate4", (getter)FinancialParameters_get_const_per_upfront_rate4,(setter)FinancialParameters_set_const_per_upfront_rate4,
	PyDoc_STR("*float*: Upfront fee on principal, loan 4 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_upfront_rate5", (getter)FinancialParameters_get_const_per_upfront_rate5,(setter)FinancialParameters_set_const_per_upfront_rate5,
	PyDoc_STR("*float*: Upfront fee on principal, loan 5 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FinancialParameters_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.FinancialParameters",             /*tp_name*/
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
 * AdjustmentFactors Group
 */ 

static PyTypeObject AdjustmentFactors_Type;

static PyObject *
AdjustmentFactors_new(SAM_TroughPhysical data_ptr)
{
	PyObject* new_obj = AdjustmentFactors_Type.tp_alloc(&AdjustmentFactors_Type,0);

	VarGroupObject* AdjustmentFactors_obj = (VarGroupObject*)new_obj;

	AdjustmentFactors_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* AdjustmentFactors methods */

static PyObject *
AdjustmentFactors_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "AdjustmentFactors")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
AdjustmentFactors_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &AdjustmentFactors_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysical", "AdjustmentFactors")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
AdjustmentFactors_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &AdjustmentFactors_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef AdjustmentFactors_methods[] = {
		{"assign",            (PyCFunction)AdjustmentFactors_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``AdjustmentFactors_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)AdjustmentFactors_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``AdjustmentFactors_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)AdjustmentFactors_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
AdjustmentFactors_get_adjust_constant(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_AdjustmentFactors_adjust_constant_nget, self->data_ptr);
}

static int
AdjustmentFactors_set_adjust_constant(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_AdjustmentFactors_adjust_constant_nset, self->data_ptr);
}

static PyObject *
AdjustmentFactors_get_adjust_en_periods(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_AdjustmentFactors_adjust_en_periods_nget, self->data_ptr);
}

static int
AdjustmentFactors_set_adjust_en_periods(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_AdjustmentFactors_adjust_en_periods_nset, self->data_ptr);
}

static PyObject *
AdjustmentFactors_get_adjust_en_timeindex(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_AdjustmentFactors_adjust_en_timeindex_nget, self->data_ptr);
}

static int
AdjustmentFactors_set_adjust_en_timeindex(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_AdjustmentFactors_adjust_en_timeindex_nset, self->data_ptr);
}

static PyObject *
AdjustmentFactors_get_adjust_periods(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_AdjustmentFactors_adjust_periods_mget, self->data_ptr);
}

static int
AdjustmentFactors_set_adjust_periods(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_AdjustmentFactors_adjust_periods_mset, self->data_ptr);
}

static PyObject *
AdjustmentFactors_get_adjust_timeindex(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_AdjustmentFactors_adjust_timeindex_aget, self->data_ptr);
}

static int
AdjustmentFactors_set_adjust_timeindex(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_AdjustmentFactors_adjust_timeindex_aset, self->data_ptr);
}

static PyGetSetDef AdjustmentFactors_getset[] = {
{"adjust_constant", (getter)AdjustmentFactors_get_adjust_constant,(setter)AdjustmentFactors_set_adjust_constant,
	PyDoc_STR("*float*: Constant loss adjustment [%]\n\n**Info:**\n'adjust' and 'constant' separated by _ instead of : after SAM 2022.12.21\n\n**Constraints:**\nMAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"adjust_en_periods", (getter)AdjustmentFactors_get_adjust_en_periods,(setter)AdjustmentFactors_set_adjust_en_periods,
	PyDoc_STR("*float*: Enable period-based adjustment factors [0/1]\n\n**Info:**\n'adjust' and 'en_periods' separated by _ instead of : after SAM 2022.12.21\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"adjust_en_timeindex", (getter)AdjustmentFactors_get_adjust_en_timeindex,(setter)AdjustmentFactors_set_adjust_en_timeindex,
	PyDoc_STR("*float*: Enable lifetime adjustment factors [0/1]\n\n**Info:**\n'adjust' and 'en_timeindex' separated by _ instead of : after SAM 2022.12.21\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"adjust_periods", (getter)AdjustmentFactors_get_adjust_periods,(setter)AdjustmentFactors_set_adjust_periods,
	PyDoc_STR("*sequence[sequence]*: Period-based adjustment factors [%]\n\n**Info:**\nSyntax: n x 3 matrix [ start, end, loss ]; Version upgrade: 'adjust' and 'periods' separated by _ instead of : after SAM 2022.12.21\n\n**Constraints:**\nCOLS=3\n\n**Required:**\nRequired if adjust_en_periods=1"),
 	NULL},
{"adjust_timeindex", (getter)AdjustmentFactors_get_adjust_timeindex,(setter)AdjustmentFactors_set_adjust_timeindex,
	PyDoc_STR("*sequence*: Lifetime adjustment factors [%]\n\n**Info:**\n'adjust' and 'timeindex' separated by _ instead of : after SAM 2022.12.21\n\n**Required:**\nRequired if adjust_en_timeindex=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject AdjustmentFactors_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.AdjustmentFactors",             /*tp_name*/
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
		AdjustmentFactors_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		AdjustmentFactors_getset,          /*tp_getset*/
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
Outputs_new(SAM_TroughPhysical data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysical", "Outputs")){
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
Outputs_get_CosTh_ave(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_CosTh_ave_aget, self->data_ptr);
}

static PyObject *
Outputs_get_D_cpnt(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Outputs_D_cpnt_mget, self->data_ptr);
}

static PyObject *
Outputs_get_EndLoss_ave(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_EndLoss_ave_aget, self->data_ptr);
}

static PyObject *
Outputs_get_EqOpteff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_EqOpteff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_IAM_ave(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_IAM_ave_aget, self->data_ptr);
}

static PyObject *
Outputs_get_K_cpnt(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Outputs_K_cpnt_mget, self->data_ptr);
}

static PyObject *
Outputs_get_L_cpnt(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Outputs_L_cpnt_mget, self->data_ptr);
}

static PyObject *
Outputs_get_P_cooling_tower_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_P_cooling_tower_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_cycle(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_P_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_P_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_out_net(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_P_out_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_plant_balance_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_P_plant_balance_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_RowShadow_ave(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_RowShadow_ave_aget, self->data_ptr);
}

static PyObject *
Outputs_get_SCADefocusArray(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_SCADefocusArray_aget, self->data_ptr);
}

static PyObject *
Outputs_get_SCAInfoArray(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Outputs_SCAInfoArray_mget, self->data_ptr);
}

static PyObject *
Outputs_get_SCAs_def(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_SCAs_def_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_field_cold_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_field_cold_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_field_hot_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_field_hot_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_grad_0(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_grad_0_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_grad_1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_grad_1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_grad_2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_grad_2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_grad_3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_grad_3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_grad_4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_grad_4_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_grad_5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_grad_5_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_grad_6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_grad_6_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_grad_7(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_grad_7_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_grad_8(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_grad_8_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_grad_9(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_grad_9_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_in_loop_final(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_in_loop_final_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_out_loop_final(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_out_loop_final_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_out_scas_last_final(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_out_scas_last_final_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_pc_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_pc_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_pc_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_pc_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_rec_cold_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_rec_cold_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_rec_hot_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_rec_hot_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tes_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_tes_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tes_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_tes_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Theta_ave(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_Theta_ave_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Type_cpnt(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Outputs_Type_cpnt_mget, self->data_ptr);
}

static PyObject *
Outputs_get_V_tank_hot_ini(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_V_tank_hot_ini_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_field_pump(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_W_dot_field_pump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_pump_SS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_W_dot_pump_SS_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_sca_track(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_W_dot_sca_track_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_W_cycle_gross(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_annual_W_cycle_gross_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_field_freeze_protection(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_annual_field_freeze_protection_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_tes_freeze_protection(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_annual_tes_freeze_protection_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_thermal_consumption(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_annual_thermal_consumption_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_total_water_use(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_annual_total_water_use_nget, self->data_ptr);
}

static PyObject *
Outputs_get_aux_design(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_aux_design_nget, self->data_ptr);
}

static PyObject *
Outputs_get_avg_suboptimal_rel_mip_gap(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_avg_suboptimal_rel_mip_gap_nget, self->data_ptr);
}

static PyObject *
Outputs_get_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_bop_design(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_bop_design_nget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_const_per_interest1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_const_per_interest2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_const_per_interest3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_const_per_interest4_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_const_per_interest5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_const_per_interest_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_percent_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_const_per_percent_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_const_per_principal1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_const_per_principal2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_const_per_principal3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_const_per_principal4_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_const_per_principal5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_const_per_principal_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_const_per_total1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_const_per_total2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_const_per_total3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_const_per_total4_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_const_per_total5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_construction_financing_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_construction_financing_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_conversion_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_conversion_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cp_battery_nameplate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_cp_battery_nameplate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cp_system_nameplate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_cp_system_nameplate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_cost_bop(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_dtr_cost_bop_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_cost_contingency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_dtr_cost_contingency_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_cost_epc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_dtr_cost_epc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_cost_fossil_backup(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_dtr_cost_fossil_backup_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_cost_htf_system(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_dtr_cost_htf_system_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_cost_installed_per_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_dtr_cost_installed_per_capacity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_cost_plm_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_dtr_cost_plm_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_cost_power_plant(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_dtr_cost_power_plant_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_cost_sales_tax_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_dtr_cost_sales_tax_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_cost_site_improvements(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_dtr_cost_site_improvements_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_cost_solar_field(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_dtr_cost_solar_field_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_cost_storage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_dtr_cost_storage_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_hce_design_heat_losses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_csp_dtr_hce_design_heat_losses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_hce_optical_effs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_csp_dtr_hce_optical_effs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_loop_hce_heat_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_dtr_loop_hce_heat_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_sca_ap_lengths(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Outputs_csp_dtr_sca_ap_lengths_mget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_sca_calc_costh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_dtr_sca_calc_costh_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_sca_calc_end_gains(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Outputs_csp_dtr_sca_calc_end_gains_mget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_sca_calc_end_losses(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Outputs_csp_dtr_sca_calc_end_losses_mget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_sca_calc_iams(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Outputs_csp_dtr_sca_calc_iams_mget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_sca_calc_latitude(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_dtr_sca_calc_latitude_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_sca_calc_sca_effs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_csp_dtr_sca_calc_sca_effs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_sca_calc_theta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_dtr_sca_calc_theta_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_dtr_sca_calc_zenith(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_dtr_sca_calc_zenith_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_tes_htf_density(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_pt_tes_htf_density_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_tes_tank_diameter(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_pt_tes_tank_diameter_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_tes_tank_height(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_csp_pt_tes_tank_height_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cycle_Tdb_table(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Outputs_cycle_Tdb_table_mget, self->data_ptr);
}

static PyObject *
Outputs_get_cycle_eff_load_table(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Outputs_cycle_eff_load_table_mget, self->data_ptr);
}

static PyObject *
Outputs_get_cycle_htf_pump_power(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_cycle_htf_pump_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dP_sf_SS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_dP_sf_SS_nget, self->data_ptr);
}

static PyObject *
Outputs_get_defocus(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_defocus_aget, self->data_ptr);
}

static PyObject *
Outputs_get_defocus_final(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_defocus_final_aget, self->data_ptr);
}

static PyObject *
Outputs_get_deltaP_field(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_deltaP_field_aget, self->data_ptr);
}

static PyObject *
Outputs_get_direct_subtotal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_direct_subtotal_nget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_obj_relax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_obj_relax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_objective(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_objective_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_pceff_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_pceff_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_presolve_nconstr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_presolve_nconstr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_presolve_nvar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_presolve_nvar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qpbsu_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_qpbsu_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qsf_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_qsf_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qsfprod_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_qsfprod_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qsfsu_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_qsfsu_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_rel_mip_gap(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_rel_mip_gap_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_rev_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_rev_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_iter(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_solve_iter_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_state(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_solve_state_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_time(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_solve_time_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_subopt_flag(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_subopt_flag_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_tes_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_tes_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_thermeff_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_thermeff_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_wpb_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_wpb_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dni_costh(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_dni_costh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_e_ch_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_e_ch_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_e_dot_field_int_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_e_dot_field_int_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_eta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_f_htfmax_actual(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_f_htfmax_actual_nget, self->data_ptr);
}

static PyObject *
Outputs_get_f_htfmin_actual(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_f_htfmin_actual_nget, self->data_ptr);
}

static PyObject *
Outputs_get_field_htf_cp_avg_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_field_htf_cp_avg_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_field_htf_max_temp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_field_htf_max_temp_nget, self->data_ptr);
}

static PyObject *
Outputs_get_field_htf_min_temp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_field_htf_min_temp_nget, self->data_ptr);
}

static PyObject *
Outputs_get_field_thermal_output_actual(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_field_thermal_output_actual_nget, self->data_ptr);
}

static PyObject *
Outputs_get_field_thermal_output_ideal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_field_thermal_output_ideal_nget, self->data_ptr);
}

static PyObject *
Outputs_get_fixed_land_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_fixed_land_area_nget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_hot_tank_htf_percent_final(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_hot_tank_htf_percent_final_aget, self->data_ptr);
}

static PyObject *
Outputs_get_hour_day(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_hour_day_aget, self->data_ptr);
}

static PyObject *
Outputs_get_is_hx(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_is_hx_nget, self->data_ptr);
}

static PyObject *
Outputs_get_is_pc_sb_allowed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_is_pc_sb_allowed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_is_pc_su_allowed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_is_pc_su_allowed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_is_rec_su_allowed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_is_rec_su_allowed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_kwh_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_loop_optical_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_loop_optical_efficiency_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_balance(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_balance_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_cold_tank_to_hot_tank(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_cold_tank_to_hot_tank_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_cr_to_tes_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_cr_to_tes_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_cycle_to_field(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_cycle_to_field_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_field_delivered(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_field_delivered_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_field_recirc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_field_recirc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_field_to_cycle(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_field_to_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_htf_cycle_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_m_dot_htf_cycle_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_htfmax_actual(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_m_dot_htfmax_actual_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_htfmin_actual(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_m_dot_htfmin_actual_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_loop(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_loop_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_pc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_pc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_pc_to_tes_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_pc_to_tes_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_tes_cold_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_tes_cold_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_tes_hot_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_tes_hot_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_water_pc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_water_pc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mass_tes_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_mass_tes_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mass_tes_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_mass_tes_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_max_field_flow_velocity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_max_field_flow_velocity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_max_loop_flow_vel_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_max_loop_flow_vel_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_min_field_flow_velocity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_min_field_flow_velocity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_min_inner_diameter(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_min_inner_diameter_nget, self->data_ptr);
}

static PyObject *
Outputs_get_min_loop_flow_vel_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_min_loop_flow_vel_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_month(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_month_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_nLoops(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_nLoops_nget, self->data_ptr);
}

static PyObject *
Outputs_get_nSCA(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_nSCA_nget, self->data_ptr);
}

static PyObject *
Outputs_get_n_op_modes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_n_op_modes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_nameplate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_nameplate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_op_mode_1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_op_mode_2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_op_mode_3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_operating_modes_a(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_operating_modes_a_aget, self->data_ptr);
}

static PyObject *
Outputs_get_operating_modes_b(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_operating_modes_b_aget, self->data_ptr);
}

static PyObject *
Outputs_get_operating_modes_c(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_operating_modes_c_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_op_mode_final(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pc_op_mode_final_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_startup_energy_remain_final(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pc_startup_energy_remain_final_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_startup_time_remain_final(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pc_startup_time_remain_final_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_header_P_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_header_P_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_header_T_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_header_T_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_header_diams(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_header_diams_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_header_expansions(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_header_expansions_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_header_lengths(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_header_lengths_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_header_mdot_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_header_mdot_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_header_vel_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_header_vel_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_header_wallthk(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_header_wallthk_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_loop_P_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_loop_P_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_loop_T_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_loop_T_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_runner_P_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_runner_P_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_runner_T_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_runner_T_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_runner_diams(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_runner_diams_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_runner_expansions(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_runner_expansions_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_runner_lengths(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_runner_lengths_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_runner_mdot_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_runner_mdot_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_runner_vel_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_runner_vel_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_runner_wallthk(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_runner_wallthk_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_P_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_tes_P_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_T_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_tes_T_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_diams(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_tes_diams_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_lengths(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_tes_lengths_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_mdot_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_tes_mdot_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_vel_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_tes_vel_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_wallthk(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_tes_wallthk_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pres(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pres_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pricing_mult(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pricing_mult_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_balance(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_balance_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_ch_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_ch_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dc_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dc_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_cycle_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_q_dot_cycle_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_cr_on(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_est_cr_on_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_cr_su(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_est_cr_su_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_tes_ch(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_est_tes_ch_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_tes_dc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_est_tes_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_freeze_prot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_freeze_prot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_htf_sf_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_htf_sf_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_max(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_pc_max_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_min(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_pc_min_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_sb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_pc_sb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_startup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_pc_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_target(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_pc_target_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_piping_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_piping_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_abs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_rec_abs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_inc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_rec_inc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_thermal_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_rec_thermal_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_tes_est(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_q_dot_tes_est_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_inc_sf_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_inc_sf_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_pb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_pb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_pc_startup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_pc_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_tes(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_q_tes_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_tes_heater(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_tes_heater_aget, self->data_ptr);
}

static PyObject *
Outputs_get_qinc_costh(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_qinc_costh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rec_op_mode_final(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_rec_op_mode_final_aget, self->data_ptr);
}

static PyObject *
Outputs_get_recirculating(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_recirculating_aget, self->data_ptr);
}

static PyObject *
Outputs_get_required_number_of_loops_for_SM1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_required_number_of_loops_for_SM1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rh(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_rh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_sim_duration(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_sim_duration_nget, self->data_ptr);
}

static PyObject *
Outputs_get_single_loop_aperture(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_single_loop_aperture_nget, self->data_ptr);
}

static PyObject *
Outputs_get_solar_mult(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_solar_mult_nget, self->data_ptr);
}

static PyObject *
Outputs_get_solazi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_solazi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solzen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_solzen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_system_capacity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tank_losses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_tank_losses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tdry(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_tdry_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_SA_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_tes_SA_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_SA_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_tes_SA_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_SA_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_tes_SA_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_avail_vol(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_tes_avail_vol_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_cold_vol_frac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_tes_cold_vol_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_error(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_tes_error_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_error_corrected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_tes_error_corrected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_error_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_tes_error_percent_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_htf_avg_temp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_tes_htf_avg_temp_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_htf_max_temp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_tes_htf_max_temp_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_htf_min_temp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_tes_htf_min_temp_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_htf_pump_power(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_tes_htf_pump_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_leak_error(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_tes_leak_error_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_mass_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_tes_mass_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_piston_frac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_tes_piston_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_piston_loc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_tes_piston_loc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_wall_error(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_tes_wall_error_aget, self->data_ptr);
}

static PyObject *
Outputs_get_time_hr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_time_hr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_total_aperture(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_total_aperture_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_direct_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_total_direct_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_indirect_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_total_indirect_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_installed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_total_installed_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_land_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_total_land_area_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_loop_conversion_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_total_loop_conversion_efficiency_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_required_aperture_for_SM1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_total_required_aperture_for_SM1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_tracking_power(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_total_tracking_power_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tou_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_tou_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_twet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_twet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_vel_loop_max(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_vel_loop_max_aget, self->data_ptr);
}

static PyObject *
Outputs_get_vel_loop_min(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_vel_loop_min_aget, self->data_ptr);
}

static PyObject *
Outputs_get_vol_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_vol_min_nget, self->data_ptr);
}

static PyObject *
Outputs_get_vol_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_vol_tank_nget, self->data_ptr);
}

static PyObject *
Outputs_get_vol_tes_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_vol_tes_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_vol_tes_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_vol_tes_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_vol_tes_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_vol_tes_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_wspd_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"CosTh_ave", (getter)Outputs_get_CosTh_ave,(setter)0,
	PyDoc_STR("*sequence*: Field collector cosine efficiency"),
 	NULL},
{"D_cpnt", (getter)Outputs_get_D_cpnt,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Inner diameters of the components in each loop interconnect [m]"),
 	NULL},
{"EndLoss_ave", (getter)Outputs_get_EndLoss_ave,(setter)0,
	PyDoc_STR("*sequence*: Field collector optical end loss"),
 	NULL},
{"EqOpteff", (getter)Outputs_get_EqOpteff,(setter)0,
	PyDoc_STR("*sequence*: Field optical efficiency before defocus"),
 	NULL},
{"IAM_ave", (getter)Outputs_get_IAM_ave,(setter)0,
	PyDoc_STR("*sequence*: Field collector incidence angle modifier"),
 	NULL},
{"K_cpnt", (getter)Outputs_get_K_cpnt,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Minor loss coefficients of the components in each loop interconnect"),
 	NULL},
{"L_cpnt", (getter)Outputs_get_L_cpnt,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Lengths of the components in each loop interconnect [m]"),
 	NULL},
{"P_cooling_tower_tot", (getter)Outputs_get_P_cooling_tower_tot,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power condenser operation [MWe]"),
 	NULL},
{"P_cycle", (getter)Outputs_get_P_cycle,(setter)0,
	PyDoc_STR("*sequence*: PC electrical power output: gross [MWe]"),
 	NULL},
{"P_fixed", (getter)Outputs_get_P_fixed,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power fixed load [MWe]"),
 	NULL},
{"P_out_net", (getter)Outputs_get_P_out_net,(setter)0,
	PyDoc_STR("*sequence*: System net electrical power [MWe]"),
 	NULL},
{"P_plant_balance_tot", (getter)Outputs_get_P_plant_balance_tot,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power generation-dependent load [MWe]"),
 	NULL},
{"RowShadow_ave", (getter)Outputs_get_RowShadow_ave,(setter)0,
	PyDoc_STR("*sequence*: Field collector row shadowing loss"),
 	NULL},
{"SCADefocusArray", (getter)Outputs_get_SCADefocusArray,(setter)0,
	PyDoc_STR("*sequence*: Order in which the SCA's should be defocused"),
 	NULL},
{"SCAInfoArray", (getter)Outputs_get_SCAInfoArray,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Receiver (,1) and collector (,2) type for each assembly in loop"),
 	NULL},
{"SCAs_def", (getter)Outputs_get_SCAs_def,(setter)0,
	PyDoc_STR("*sequence*: Field fraction of focused SCAs"),
 	NULL},
{"T_field_cold_in", (getter)Outputs_get_T_field_cold_in,(setter)0,
	PyDoc_STR("*sequence*: Field timestep-averaged inlet temperature [C]"),
 	NULL},
{"T_field_hot_out", (getter)Outputs_get_T_field_hot_out,(setter)0,
	PyDoc_STR("*sequence*: Field timestep-averaged outlet temperature [C]"),
 	NULL},
{"T_grad_0", (getter)Outputs_get_T_grad_0,(setter)0,
	PyDoc_STR("*sequence*: TES Temperature gradient 0 indice [C]"),
 	NULL},
{"T_grad_1", (getter)Outputs_get_T_grad_1,(setter)0,
	PyDoc_STR("*sequence*: TES Temperature gradient 1 indice [C]"),
 	NULL},
{"T_grad_2", (getter)Outputs_get_T_grad_2,(setter)0,
	PyDoc_STR("*sequence*: TES Temperature gradient 2 indice [C]"),
 	NULL},
{"T_grad_3", (getter)Outputs_get_T_grad_3,(setter)0,
	PyDoc_STR("*sequence*: TES Temperature gradient 3 indice [C]"),
 	NULL},
{"T_grad_4", (getter)Outputs_get_T_grad_4,(setter)0,
	PyDoc_STR("*sequence*: TES Temperature gradient 4 indice [C]"),
 	NULL},
{"T_grad_5", (getter)Outputs_get_T_grad_5,(setter)0,
	PyDoc_STR("*sequence*: TES Temperature gradient 5 indice [C]"),
 	NULL},
{"T_grad_6", (getter)Outputs_get_T_grad_6,(setter)0,
	PyDoc_STR("*sequence*: TES Temperature gradient 6 indice [C]"),
 	NULL},
{"T_grad_7", (getter)Outputs_get_T_grad_7,(setter)0,
	PyDoc_STR("*sequence*: TES Temperature gradient 7 indice [C]"),
 	NULL},
{"T_grad_8", (getter)Outputs_get_T_grad_8,(setter)0,
	PyDoc_STR("*sequence*: TES Temperature gradient 8 indice [C]"),
 	NULL},
{"T_grad_9", (getter)Outputs_get_T_grad_9,(setter)0,
	PyDoc_STR("*sequence*: TES Temperature gradient 9 indice [C]"),
 	NULL},
{"T_in_loop_final", (getter)Outputs_get_T_in_loop_final,(setter)0,
	PyDoc_STR("*sequence*: Final loop inlet, cold header and cold runner fluid temperature [-]"),
 	NULL},
{"T_out_loop_final", (getter)Outputs_get_T_out_loop_final,(setter)0,
	PyDoc_STR("*sequence*: Final loop outlet, hot header and hot runner fluid temperature [-]"),
 	NULL},
{"T_out_scas_last_final", (getter)Outputs_get_T_out_scas_last_final,(setter)0,
	PyDoc_STR("*sequence*: Final SCA outlet temperatures [-]"),
 	NULL},
{"T_pc_in", (getter)Outputs_get_T_pc_in,(setter)0,
	PyDoc_STR("*sequence*: PC HTF inlet temperature [C]"),
 	NULL},
{"T_pc_out", (getter)Outputs_get_T_pc_out,(setter)0,
	PyDoc_STR("*sequence*: PC HTF outlet temperature [C]"),
 	NULL},
{"T_rec_cold_in", (getter)Outputs_get_T_rec_cold_in,(setter)0,
	PyDoc_STR("*sequence*: Loop timestep-averaged inlet temperature [C]"),
 	NULL},
{"T_rec_hot_out", (getter)Outputs_get_T_rec_hot_out,(setter)0,
	PyDoc_STR("*sequence*: Loop timestep-averaged outlet temperature [C]"),
 	NULL},
{"T_tes_cold", (getter)Outputs_get_T_tes_cold,(setter)0,
	PyDoc_STR("*sequence*: TES cold temperature [C]"),
 	NULL},
{"T_tes_hot", (getter)Outputs_get_T_tes_hot,(setter)0,
	PyDoc_STR("*sequence*: TES hot temperature [C]"),
 	NULL},
{"Theta_ave", (getter)Outputs_get_Theta_ave,(setter)0,
	PyDoc_STR("*sequence*: Field collector solar incidence angle [deg]"),
 	NULL},
{"Type_cpnt", (getter)Outputs_get_Type_cpnt,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Type of component in each loop interconnect [0=fitting | 1=pipe | 2=flex_hose] [Wm]"),
 	NULL},
{"V_tank_hot_ini", (getter)Outputs_get_V_tank_hot_ini,(setter)0,
	PyDoc_STR("*float*: Initial hot tank volume [m3]"),
 	NULL},
{"W_dot_field_pump", (getter)Outputs_get_W_dot_field_pump,(setter)0,
	PyDoc_STR("*sequence*: Field htf pumping power [MWe]"),
 	NULL},
{"W_dot_pump_SS", (getter)Outputs_get_W_dot_pump_SS,(setter)0,
	PyDoc_STR("*float*: Steady State pumping power [MWe]"),
 	NULL},
{"W_dot_sca_track", (getter)Outputs_get_W_dot_sca_track,(setter)0,
	PyDoc_STR("*sequence*: Field collector tracking power [MWe]"),
 	NULL},
{"annual_W_cycle_gross", (getter)Outputs_get_annual_W_cycle_gross,(setter)0,
	PyDoc_STR("*float*: Electrical source - Power cycle gross output [kWhe]"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual net electrical energy w/ avail. derate [kWhe]"),
 	NULL},
{"annual_field_freeze_protection", (getter)Outputs_get_annual_field_freeze_protection,(setter)0,
	PyDoc_STR("*float*: Annual thermal power for field freeze protection [kWht]"),
 	NULL},
{"annual_tes_freeze_protection", (getter)Outputs_get_annual_tes_freeze_protection,(setter)0,
	PyDoc_STR("*float*: Annual thermal power for TES freeze protection [kWht]"),
 	NULL},
{"annual_thermal_consumption", (getter)Outputs_get_annual_thermal_consumption,(setter)0,
	PyDoc_STR("*float*: Annual thermal freeze protection required [kWht]"),
 	NULL},
{"annual_total_water_use", (getter)Outputs_get_annual_total_water_use,(setter)0,
	PyDoc_STR("*float*: Total Annual Water Usage [m^3]"),
 	NULL},
{"aux_design", (getter)Outputs_get_aux_design,(setter)0,
	PyDoc_STR("*float*: Aux parasitic at design [MWe]"),
 	NULL},
{"avg_suboptimal_rel_mip_gap", (getter)Outputs_get_avg_suboptimal_rel_mip_gap,(setter)0,
	PyDoc_STR("*float*: Average suboptimal relative MIP gap [%]"),
 	NULL},
{"beam", (getter)Outputs_get_beam,(setter)0,
	PyDoc_STR("*sequence*: Resource Beam normal irradiance [W/m2]"),
 	NULL},
{"bop_design", (getter)Outputs_get_bop_design,(setter)0,
	PyDoc_STR("*float*: BOP parasitic at design [MWe]"),
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	PyDoc_STR("*float*: Capacity factor [%]"),
 	NULL},
{"const_per_interest1", (getter)Outputs_get_const_per_interest1,(setter)0,
	PyDoc_STR("*float*: Interest cost, loan 1 [$]"),
 	NULL},
{"const_per_interest2", (getter)Outputs_get_const_per_interest2,(setter)0,
	PyDoc_STR("*float*: Interest cost, loan 2 [$]"),
 	NULL},
{"const_per_interest3", (getter)Outputs_get_const_per_interest3,(setter)0,
	PyDoc_STR("*float*: Interest cost, loan 3 [$]"),
 	NULL},
{"const_per_interest4", (getter)Outputs_get_const_per_interest4,(setter)0,
	PyDoc_STR("*float*: Interest cost, loan 4 [$]"),
 	NULL},
{"const_per_interest5", (getter)Outputs_get_const_per_interest5,(setter)0,
	PyDoc_STR("*float*: Interest cost, loan 5 [$]"),
 	NULL},
{"const_per_interest_total", (getter)Outputs_get_const_per_interest_total,(setter)0,
	PyDoc_STR("*float*: Total interest costs, all loans [$]"),
 	NULL},
{"const_per_percent_total", (getter)Outputs_get_const_per_percent_total,(setter)0,
	PyDoc_STR("*float*: Total percent of installed costs, all loans [%]"),
 	NULL},
{"const_per_principal1", (getter)Outputs_get_const_per_principal1,(setter)0,
	PyDoc_STR("*float*: Principal, loan 1 [$]"),
 	NULL},
{"const_per_principal2", (getter)Outputs_get_const_per_principal2,(setter)0,
	PyDoc_STR("*float*: Principal, loan 2 [$]"),
 	NULL},
{"const_per_principal3", (getter)Outputs_get_const_per_principal3,(setter)0,
	PyDoc_STR("*float*: Principal, loan 3 [$]"),
 	NULL},
{"const_per_principal4", (getter)Outputs_get_const_per_principal4,(setter)0,
	PyDoc_STR("*float*: Principal, loan 4 [$]"),
 	NULL},
{"const_per_principal5", (getter)Outputs_get_const_per_principal5,(setter)0,
	PyDoc_STR("*float*: Principal, loan 5 [$]"),
 	NULL},
{"const_per_principal_total", (getter)Outputs_get_const_per_principal_total,(setter)0,
	PyDoc_STR("*float*: Total principal, all loans [$]"),
 	NULL},
{"const_per_total1", (getter)Outputs_get_const_per_total1,(setter)0,
	PyDoc_STR("*float*: Total financing cost, loan 1 [$]"),
 	NULL},
{"const_per_total2", (getter)Outputs_get_const_per_total2,(setter)0,
	PyDoc_STR("*float*: Total financing cost, loan 2 [$]"),
 	NULL},
{"const_per_total3", (getter)Outputs_get_const_per_total3,(setter)0,
	PyDoc_STR("*float*: Total financing cost, loan 3 [$]"),
 	NULL},
{"const_per_total4", (getter)Outputs_get_const_per_total4,(setter)0,
	PyDoc_STR("*float*: Total financing cost, loan 4 [$]"),
 	NULL},
{"const_per_total5", (getter)Outputs_get_const_per_total5,(setter)0,
	PyDoc_STR("*float*: Total financing cost, loan 5 [$]"),
 	NULL},
{"construction_financing_cost", (getter)Outputs_get_construction_financing_cost,(setter)0,
	PyDoc_STR("*float*: Total construction financing cost [$]"),
 	NULL},
{"conversion_factor", (getter)Outputs_get_conversion_factor,(setter)0,
	PyDoc_STR("*float*: Gross to Net Conversion Factor [%]"),
 	NULL},
{"cp_battery_nameplate", (getter)Outputs_get_cp_battery_nameplate,(setter)0,
	PyDoc_STR("*float*: Battery nameplate [MWe]"),
 	NULL},
{"cp_system_nameplate", (getter)Outputs_get_cp_system_nameplate,(setter)0,
	PyDoc_STR("*float*: System capacity for capacity payments [MWe]"),
 	NULL},
{"csp_dtr_cost_bop", (getter)Outputs_get_csp_dtr_cost_bop,(setter)0,
	PyDoc_STR("*float*: Balance of plant cost [$]"),
 	NULL},
{"csp_dtr_cost_contingency", (getter)Outputs_get_csp_dtr_cost_contingency,(setter)0,
	PyDoc_STR("*float*: Contingency cost [$]"),
 	NULL},
{"csp_dtr_cost_epc_total", (getter)Outputs_get_csp_dtr_cost_epc_total,(setter)0,
	PyDoc_STR("*float*: EPC total cost [$]"),
 	NULL},
{"csp_dtr_cost_fossil_backup", (getter)Outputs_get_csp_dtr_cost_fossil_backup,(setter)0,
	PyDoc_STR("*float*: Fossil backup cost [$]"),
 	NULL},
{"csp_dtr_cost_htf_system", (getter)Outputs_get_csp_dtr_cost_htf_system,(setter)0,
	PyDoc_STR("*float*: HTF system cost [$]"),
 	NULL},
{"csp_dtr_cost_installed_per_capacity", (getter)Outputs_get_csp_dtr_cost_installed_per_capacity,(setter)0,
	PyDoc_STR("*float*: Estimated total installed cost per net capacity ($/kW) [$/kW]"),
 	NULL},
{"csp_dtr_cost_plm_total", (getter)Outputs_get_csp_dtr_cost_plm_total,(setter)0,
	PyDoc_STR("*float*: Total land cost [$]"),
 	NULL},
{"csp_dtr_cost_power_plant", (getter)Outputs_get_csp_dtr_cost_power_plant,(setter)0,
	PyDoc_STR("*float*: Power plant cost [$]"),
 	NULL},
{"csp_dtr_cost_sales_tax_total", (getter)Outputs_get_csp_dtr_cost_sales_tax_total,(setter)0,
	PyDoc_STR("*float*: Sales tax total [$]"),
 	NULL},
{"csp_dtr_cost_site_improvements", (getter)Outputs_get_csp_dtr_cost_site_improvements,(setter)0,
	PyDoc_STR("*float*: Site improvements cost [$]"),
 	NULL},
{"csp_dtr_cost_solar_field", (getter)Outputs_get_csp_dtr_cost_solar_field,(setter)0,
	PyDoc_STR("*float*: Solar field cost [$]"),
 	NULL},
{"csp_dtr_cost_storage", (getter)Outputs_get_csp_dtr_cost_storage,(setter)0,
	PyDoc_STR("*float*: Thermal storage cost [$]"),
 	NULL},
{"csp_dtr_hce_design_heat_losses", (getter)Outputs_get_csp_dtr_hce_design_heat_losses,(setter)0,
	PyDoc_STR("*sequence*: Heat loss at design [W/m]"),
 	NULL},
{"csp_dtr_hce_optical_effs", (getter)Outputs_get_csp_dtr_hce_optical_effs,(setter)0,
	PyDoc_STR("*sequence*: HCE optical efficiencies at design"),
 	NULL},
{"csp_dtr_loop_hce_heat_loss", (getter)Outputs_get_csp_dtr_loop_hce_heat_loss,(setter)0,
	PyDoc_STR("*float*: Loop Heat Loss from HCE at Design [W/m]"),
 	NULL},
{"csp_dtr_sca_ap_lengths", (getter)Outputs_get_csp_dtr_sca_ap_lengths,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Length of single module [m]"),
 	NULL},
{"csp_dtr_sca_calc_costh", (getter)Outputs_get_csp_dtr_sca_calc_costh,(setter)0,
	PyDoc_STR("*float*: Calculated costheta"),
 	NULL},
{"csp_dtr_sca_calc_end_gains", (getter)Outputs_get_csp_dtr_sca_calc_end_gains,(setter)0,
	PyDoc_STR("*sequence[sequence]*: End gain factor"),
 	NULL},
{"csp_dtr_sca_calc_end_losses", (getter)Outputs_get_csp_dtr_sca_calc_end_losses,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Use time-series net electricity generation limits"),
 	NULL},
{"csp_dtr_sca_calc_iams", (getter)Outputs_get_csp_dtr_sca_calc_iams,(setter)0,
	PyDoc_STR("*sequence[sequence]*: IAM at summer solstice"),
 	NULL},
{"csp_dtr_sca_calc_latitude", (getter)Outputs_get_csp_dtr_sca_calc_latitude,(setter)0,
	PyDoc_STR("*float*: Latitude [degree]"),
 	NULL},
{"csp_dtr_sca_calc_sca_effs", (getter)Outputs_get_csp_dtr_sca_calc_sca_effs,(setter)0,
	PyDoc_STR("*sequence*: SCA optical efficiencies at design"),
 	NULL},
{"csp_dtr_sca_calc_theta", (getter)Outputs_get_csp_dtr_sca_calc_theta,(setter)0,
	PyDoc_STR("*float*: Calculated theta [degree]"),
 	NULL},
{"csp_dtr_sca_calc_zenith", (getter)Outputs_get_csp_dtr_sca_calc_zenith,(setter)0,
	PyDoc_STR("*float*: Calculated zenith [degree]"),
 	NULL},
{"csp_pt_tes_htf_density", (getter)Outputs_get_csp_pt_tes_htf_density,(setter)0,
	PyDoc_STR("*float*: Storage htf density [kg/m3]"),
 	NULL},
{"csp_pt_tes_tank_diameter", (getter)Outputs_get_csp_pt_tes_tank_diameter,(setter)0,
	PyDoc_STR("*float*: Tank diameter [m]"),
 	NULL},
{"csp_pt_tes_tank_height", (getter)Outputs_get_csp_pt_tes_tank_height,(setter)0,
	PyDoc_STR("*float*: Tank height [m]"),
 	NULL},
{"cycle_Tdb_table", (getter)Outputs_get_cycle_Tdb_table,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Normalized cycle efficiency and condenser power vs. ambient temperature"),
 	NULL},
{"cycle_eff_load_table", (getter)Outputs_get_cycle_eff_load_table,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Cycle efficiency vs. load"),
 	NULL},
{"cycle_htf_pump_power", (getter)Outputs_get_cycle_htf_pump_power,(setter)0,
	PyDoc_STR("*sequence*: PC HTF pump power [MWe]"),
 	NULL},
{"dP_sf_SS", (getter)Outputs_get_dP_sf_SS,(setter)0,
	PyDoc_STR("*float*: Steady State field pressure drop [bar]"),
 	NULL},
{"defocus", (getter)Outputs_get_defocus,(setter)0,
	PyDoc_STR("*sequence*: Field optical focus fraction"),
 	NULL},
{"defocus_final", (getter)Outputs_get_defocus_final,(setter)0,
	PyDoc_STR("*sequence*: Defocus final [-]"),
 	NULL},
{"deltaP_field", (getter)Outputs_get_deltaP_field,(setter)0,
	PyDoc_STR("*sequence*: Field pressure drop [bar]"),
 	NULL},
{"direct_subtotal", (getter)Outputs_get_direct_subtotal,(setter)0,
	PyDoc_STR("*float*: Direct subtotal [$]"),
 	NULL},
{"disp_obj_relax", (getter)Outputs_get_disp_obj_relax,(setter)0,
	PyDoc_STR("*sequence*: Dispatch objective function - relaxed max"),
 	NULL},
{"disp_objective", (getter)Outputs_get_disp_objective,(setter)0,
	PyDoc_STR("*sequence*: Dispatch objective function value"),
 	NULL},
{"disp_pceff_expected", (getter)Outputs_get_disp_pceff_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected power cycle efficiency adj."),
 	NULL},
{"disp_presolve_nconstr", (getter)Outputs_get_disp_presolve_nconstr,(setter)0,
	PyDoc_STR("*sequence*: Dispatch number of constraints in problem"),
 	NULL},
{"disp_presolve_nvar", (getter)Outputs_get_disp_presolve_nvar,(setter)0,
	PyDoc_STR("*sequence*: Dispatch number of variables in problem"),
 	NULL},
{"disp_qpbsu_expected", (getter)Outputs_get_disp_qpbsu_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected power cycle startup energy [MWht]"),
 	NULL},
{"disp_qsf_expected", (getter)Outputs_get_disp_qsf_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected solar field available energy [MWt]"),
 	NULL},
{"disp_qsfprod_expected", (getter)Outputs_get_disp_qsfprod_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected solar field generation [MWt]"),
 	NULL},
{"disp_qsfsu_expected", (getter)Outputs_get_disp_qsfsu_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected solar field startup energy [MWt]"),
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
{"disp_solve_time", (getter)Outputs_get_disp_solve_time,(setter)0,
	PyDoc_STR("*sequence*: Dispatch solver time [sec]"),
 	NULL},
{"disp_subopt_flag", (getter)Outputs_get_disp_subopt_flag,(setter)0,
	PyDoc_STR("*sequence*: Dispatch suboptimal solution flag"),
 	NULL},
{"disp_tes_expected", (getter)Outputs_get_disp_tes_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected TES charge level [MWht]"),
 	NULL},
{"disp_thermeff_expected", (getter)Outputs_get_disp_thermeff_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected SF thermal efficiency adj."),
 	NULL},
{"disp_wpb_expected", (getter)Outputs_get_disp_wpb_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected power generation [MWe]"),
 	NULL},
{"dni_costh", (getter)Outputs_get_dni_costh,(setter)0,
	PyDoc_STR("*sequence*: Field collector DNI-cosine product [W/m2]"),
 	NULL},
{"e_ch_tes", (getter)Outputs_get_e_ch_tes,(setter)0,
	PyDoc_STR("*sequence*: TES charge state [MWht]"),
 	NULL},
{"e_dot_field_int_energy", (getter)Outputs_get_e_dot_field_int_energy,(setter)0,
	PyDoc_STR("*sequence*: Field change in material/htf internal energy [MWt]"),
 	NULL},
{"eta", (getter)Outputs_get_eta,(setter)0,
	PyDoc_STR("*sequence*: PC efficiency: gross"),
 	NULL},
{"f_htfmax_actual", (getter)Outputs_get_f_htfmax_actual,(setter)0,
	PyDoc_STR("*float*: Actual maximum loop mass flow rate fraction of design"),
 	NULL},
{"f_htfmin_actual", (getter)Outputs_get_f_htfmin_actual,(setter)0,
	PyDoc_STR("*float*: Actual minimum loop mass flow rate fraction of design"),
 	NULL},
{"field_htf_cp_avg_des", (getter)Outputs_get_field_htf_cp_avg_des,(setter)0,
	PyDoc_STR("*float*: Field average htf cp at design [kJ/kgK]"),
 	NULL},
{"field_htf_max_temp", (getter)Outputs_get_field_htf_max_temp,(setter)0,
	PyDoc_STR("*float*: Maximum field htf temp [C]"),
 	NULL},
{"field_htf_min_temp", (getter)Outputs_get_field_htf_min_temp,(setter)0,
	PyDoc_STR("*float*: Minimum field htf temp [C]"),
 	NULL},
{"field_thermal_output_actual", (getter)Outputs_get_field_thermal_output_actual,(setter)0,
	PyDoc_STR("*float*: Design-point thermal power from the solar field limited by mass flow [MW]"),
 	NULL},
{"field_thermal_output_ideal", (getter)Outputs_get_field_thermal_output_ideal,(setter)0,
	PyDoc_STR("*float*: Design-point thermal power from the solar field with no limit [MW]"),
 	NULL},
{"fixed_land_area", (getter)Outputs_get_fixed_land_area,(setter)0,
	PyDoc_STR("*float*: Fixed Land Area [acre]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System net electrical power w/ avail. derate [kWe]"),
 	NULL},
{"hot_tank_htf_percent_final", (getter)Outputs_get_hot_tank_htf_percent_final,(setter)0,
	PyDoc_STR("*sequence*: Final percent fill of available hot tank mass [%]"),
 	NULL},
{"hour_day", (getter)Outputs_get_hour_day,(setter)0,
	PyDoc_STR("*sequence*: Resource Hour of Day"),
 	NULL},
{"is_hx", (getter)Outputs_get_is_hx,(setter)0,
	PyDoc_STR("*float*: System has heat exchanger no/yes (0/1)"),
 	NULL},
{"is_pc_sb_allowed", (getter)Outputs_get_is_pc_sb_allowed,(setter)0,
	PyDoc_STR("*sequence*: is power cycle standby allowed"),
 	NULL},
{"is_pc_su_allowed", (getter)Outputs_get_is_pc_su_allowed,(setter)0,
	PyDoc_STR("*sequence*: is power cycle startup allowed"),
 	NULL},
{"is_rec_su_allowed", (getter)Outputs_get_is_rec_su_allowed,(setter)0,
	PyDoc_STR("*sequence*: is receiver startup allowed"),
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	PyDoc_STR("*float*: First year kWh/kW [kWh/kW]"),
 	NULL},
{"loop_optical_efficiency", (getter)Outputs_get_loop_optical_efficiency,(setter)0,
	PyDoc_STR("*float*: Loop total optical effiency at design"),
 	NULL},
{"m_dot_balance", (getter)Outputs_get_m_dot_balance,(setter)0,
	PyDoc_STR("*sequence*: Relative mass flow balance error"),
 	NULL},
{"m_dot_cold_tank_to_hot_tank", (getter)Outputs_get_m_dot_cold_tank_to_hot_tank,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: cold tank to hot tank [kg/s]"),
 	NULL},
{"m_dot_cr_to_tes_hot", (getter)Outputs_get_m_dot_cr_to_tes_hot,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: field to hot TES [kg/s]"),
 	NULL},
{"m_dot_cycle_to_field", (getter)Outputs_get_m_dot_cycle_to_field,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: cycle to field [kg/s]"),
 	NULL},
{"m_dot_field_delivered", (getter)Outputs_get_m_dot_field_delivered,(setter)0,
	PyDoc_STR("*sequence*: Field total mass flow delivered [kg/s]"),
 	NULL},
{"m_dot_field_recirc", (getter)Outputs_get_m_dot_field_recirc,(setter)0,
	PyDoc_STR("*sequence*: Field total mass flow recirculated [kg/s]"),
 	NULL},
{"m_dot_field_to_cycle", (getter)Outputs_get_m_dot_field_to_cycle,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: field to cycle [kg/s]"),
 	NULL},
{"m_dot_htf_cycle_des", (getter)Outputs_get_m_dot_htf_cycle_des,(setter)0,
	PyDoc_STR("*float*: PC mass flow rate at design [kg/s]"),
 	NULL},
{"m_dot_htfmax_actual", (getter)Outputs_get_m_dot_htfmax_actual,(setter)0,
	PyDoc_STR("*float*: Actual maximum loop HTF flow rate [kg/s]"),
 	NULL},
{"m_dot_htfmin_actual", (getter)Outputs_get_m_dot_htfmin_actual,(setter)0,
	PyDoc_STR("*float*: Actual minimum loop HTF flow rate [kg/s]"),
 	NULL},
{"m_dot_loop", (getter)Outputs_get_m_dot_loop,(setter)0,
	PyDoc_STR("*sequence*: Receiver mass flow rate [kg/s]"),
 	NULL},
{"m_dot_pc", (getter)Outputs_get_m_dot_pc,(setter)0,
	PyDoc_STR("*sequence*: PC HTF mass flow rate [kg/s]"),
 	NULL},
{"m_dot_pc_to_tes_cold", (getter)Outputs_get_m_dot_pc_to_tes_cold,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: cycle to cold TES [kg/s]"),
 	NULL},
{"m_dot_tes_cold_out", (getter)Outputs_get_m_dot_tes_cold_out,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: TES cold out [kg/s]"),
 	NULL},
{"m_dot_tes_hot_out", (getter)Outputs_get_m_dot_tes_hot_out,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: TES hot out [kg/s]"),
 	NULL},
{"m_dot_water_pc", (getter)Outputs_get_m_dot_water_pc,(setter)0,
	PyDoc_STR("*sequence*: PC water consumption: makeup + cooling [kg/s]"),
 	NULL},
{"mass_tes_cold", (getter)Outputs_get_mass_tes_cold,(setter)0,
	PyDoc_STR("*sequence*: TES cold tank mass (end) [kg]"),
 	NULL},
{"mass_tes_hot", (getter)Outputs_get_mass_tes_hot,(setter)0,
	PyDoc_STR("*sequence*: TES hot tank mass (end) [kg]"),
 	NULL},
{"max_field_flow_velocity", (getter)Outputs_get_max_field_flow_velocity,(setter)0,
	PyDoc_STR("*float*: Maximum field flow velocity [m/s]"),
 	NULL},
{"max_loop_flow_vel_des", (getter)Outputs_get_max_loop_flow_vel_des,(setter)0,
	PyDoc_STR("*float*: Maximum loop flow velocity at design [m/s]"),
 	NULL},
{"min_field_flow_velocity", (getter)Outputs_get_min_field_flow_velocity,(setter)0,
	PyDoc_STR("*float*: Minimum field flow velocity [m/s]"),
 	NULL},
{"min_inner_diameter", (getter)Outputs_get_min_inner_diameter,(setter)0,
	PyDoc_STR("*float*: Minimum absorber inner diameter in loop [m]"),
 	NULL},
{"min_loop_flow_vel_des", (getter)Outputs_get_min_loop_flow_vel_des,(setter)0,
	PyDoc_STR("*float*: Minimum loop flow velocity at design [m/s]"),
 	NULL},
{"month", (getter)Outputs_get_month,(setter)0,
	PyDoc_STR("*sequence*: Resource Month"),
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	PyDoc_STR("*sequence*: Monthly AC energy in Year 1 [kWh]"),
 	NULL},
{"nLoops", (getter)Outputs_get_nLoops,(setter)0,
	PyDoc_STR("*float*: Number of loops in the field"),
 	NULL},
{"nSCA", (getter)Outputs_get_nSCA,(setter)0,
	PyDoc_STR("*float*: Number of SCAs in a loop [none]"),
 	NULL},
{"n_op_modes", (getter)Outputs_get_n_op_modes,(setter)0,
	PyDoc_STR("*sequence*: Operating modes in reporting timestep"),
 	NULL},
{"nameplate", (getter)Outputs_get_nameplate,(setter)0,
	PyDoc_STR("*float*: Nameplate capacity [MWe]"),
 	NULL},
{"op_mode_1", (getter)Outputs_get_op_mode_1,(setter)0,
	PyDoc_STR("*sequence*: 1st operating mode"),
 	NULL},
{"op_mode_2", (getter)Outputs_get_op_mode_2,(setter)0,
	PyDoc_STR("*sequence*: 2nd op. mode, if applicable"),
 	NULL},
{"op_mode_3", (getter)Outputs_get_op_mode_3,(setter)0,
	PyDoc_STR("*sequence*: 3rd op. mode, if applicable"),
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
{"pc_op_mode_final", (getter)Outputs_get_pc_op_mode_final,(setter)0,
	PyDoc_STR("*sequence*: Final cycle operation mode 0:startup, 1:on, 2:standby, 3:off, 4:startup_controlled [-]"),
 	NULL},
{"pc_startup_energy_remain_final", (getter)Outputs_get_pc_startup_energy_remain_final,(setter)0,
	PyDoc_STR("*sequence*: Final cycle startup energy remaining [kwh]"),
 	NULL},
{"pc_startup_time_remain_final", (getter)Outputs_get_pc_startup_time_remain_final,(setter)0,
	PyDoc_STR("*sequence*: Final cycle startup time remaining [hr]"),
 	NULL},
{"pipe_header_P_dsn", (getter)Outputs_get_pipe_header_P_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping header pressure at design [bar]"),
 	NULL},
{"pipe_header_T_dsn", (getter)Outputs_get_pipe_header_T_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping header temperature at design [C]"),
 	NULL},
{"pipe_header_diams", (getter)Outputs_get_pipe_header_diams,(setter)0,
	PyDoc_STR("*sequence*: Field piping header diameters [m]"),
 	NULL},
{"pipe_header_expansions", (getter)Outputs_get_pipe_header_expansions,(setter)0,
	PyDoc_STR("*sequence*: Number of field piping header expansions [-]"),
 	NULL},
{"pipe_header_lengths", (getter)Outputs_get_pipe_header_lengths,(setter)0,
	PyDoc_STR("*sequence*: Field piping header lengths [m]"),
 	NULL},
{"pipe_header_mdot_dsn", (getter)Outputs_get_pipe_header_mdot_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping header mass flow at design [kg/s]"),
 	NULL},
{"pipe_header_vel_dsn", (getter)Outputs_get_pipe_header_vel_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping header velocity at design [m/s]"),
 	NULL},
{"pipe_header_wallthk", (getter)Outputs_get_pipe_header_wallthk,(setter)0,
	PyDoc_STR("*sequence*: Field piping header wall thicknesses [m]"),
 	NULL},
{"pipe_loop_P_dsn", (getter)Outputs_get_pipe_loop_P_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping loop pressure at design [bar]"),
 	NULL},
{"pipe_loop_T_dsn", (getter)Outputs_get_pipe_loop_T_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping loop temperature at design [C]"),
 	NULL},
{"pipe_runner_P_dsn", (getter)Outputs_get_pipe_runner_P_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping runner pressure at design [bar]"),
 	NULL},
{"pipe_runner_T_dsn", (getter)Outputs_get_pipe_runner_T_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping runner temperature at design [C]"),
 	NULL},
{"pipe_runner_diams", (getter)Outputs_get_pipe_runner_diams,(setter)0,
	PyDoc_STR("*sequence*: Field piping runner diameters [m]"),
 	NULL},
{"pipe_runner_expansions", (getter)Outputs_get_pipe_runner_expansions,(setter)0,
	PyDoc_STR("*sequence*: Number of field piping runner expansions [-]"),
 	NULL},
{"pipe_runner_lengths", (getter)Outputs_get_pipe_runner_lengths,(setter)0,
	PyDoc_STR("*sequence*: Field piping runner lengths [m]"),
 	NULL},
{"pipe_runner_mdot_dsn", (getter)Outputs_get_pipe_runner_mdot_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping runner mass flow at design [kg/s]"),
 	NULL},
{"pipe_runner_vel_dsn", (getter)Outputs_get_pipe_runner_vel_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping runner velocity at design [m/s]"),
 	NULL},
{"pipe_runner_wallthk", (getter)Outputs_get_pipe_runner_wallthk,(setter)0,
	PyDoc_STR("*sequence*: Field piping runner wall thicknesses [m]"),
 	NULL},
{"pipe_tes_P_dsn", (getter)Outputs_get_pipe_tes_P_dsn,(setter)0,
	PyDoc_STR("*sequence*: Pressure in TES pipes at design conditions [bar]"),
 	NULL},
{"pipe_tes_T_dsn", (getter)Outputs_get_pipe_tes_T_dsn,(setter)0,
	PyDoc_STR("*sequence*: Temperature in TES pipes at design conditions [C]"),
 	NULL},
{"pipe_tes_diams", (getter)Outputs_get_pipe_tes_diams,(setter)0,
	PyDoc_STR("*sequence*: Pipe diameters in TES [m]"),
 	NULL},
{"pipe_tes_lengths", (getter)Outputs_get_pipe_tes_lengths,(setter)0,
	PyDoc_STR("*sequence*: Pipe lengths in TES [m]"),
 	NULL},
{"pipe_tes_mdot_dsn", (getter)Outputs_get_pipe_tes_mdot_dsn,(setter)0,
	PyDoc_STR("*sequence*: Mass flow TES pipes at design conditions [kg/s]"),
 	NULL},
{"pipe_tes_vel_dsn", (getter)Outputs_get_pipe_tes_vel_dsn,(setter)0,
	PyDoc_STR("*sequence*: Velocity in TES pipes at design conditions [m/s]"),
 	NULL},
{"pipe_tes_wallthk", (getter)Outputs_get_pipe_tes_wallthk,(setter)0,
	PyDoc_STR("*sequence*: Pipe wall thickness in TES [m]"),
 	NULL},
{"pres", (getter)Outputs_get_pres,(setter)0,
	PyDoc_STR("*sequence*: Resource Pressure [mbar]"),
 	NULL},
{"pricing_mult", (getter)Outputs_get_pricing_mult,(setter)0,
	PyDoc_STR("*sequence*: PPA price multiplier"),
 	NULL},
{"q_balance", (getter)Outputs_get_q_balance,(setter)0,
	PyDoc_STR("*sequence*: Relative energy balance error"),
 	NULL},
{"q_ch_tes", (getter)Outputs_get_q_ch_tes,(setter)0,
	PyDoc_STR("*sequence*: TES charge thermal power [MWt]"),
 	NULL},
{"q_dc_tes", (getter)Outputs_get_q_dc_tes,(setter)0,
	PyDoc_STR("*sequence*: TES discharge thermal power [MWt]"),
 	NULL},
{"q_dot_cycle_des", (getter)Outputs_get_q_dot_cycle_des,(setter)0,
	PyDoc_STR("*float*: Cycle thermal power at design [MWt]"),
 	NULL},
{"q_dot_est_cr_on", (getter)Outputs_get_q_dot_est_cr_on,(setter)0,
	PyDoc_STR("*sequence*: Estimate rec. thermal power TO HTF [MWt]"),
 	NULL},
{"q_dot_est_cr_su", (getter)Outputs_get_q_dot_est_cr_su,(setter)0,
	PyDoc_STR("*sequence*: Estimate rec. startup thermal power [MWt]"),
 	NULL},
{"q_dot_est_tes_ch", (getter)Outputs_get_q_dot_est_tes_ch,(setter)0,
	PyDoc_STR("*sequence*: Estimate max TES charge thermal power [MWt]"),
 	NULL},
{"q_dot_est_tes_dc", (getter)Outputs_get_q_dot_est_tes_dc,(setter)0,
	PyDoc_STR("*sequence*: Estimate max TES discharge thermal power [MWt]"),
 	NULL},
{"q_dot_freeze_prot", (getter)Outputs_get_q_dot_freeze_prot,(setter)0,
	PyDoc_STR("*sequence*: Field freeze protection required [MWt]"),
 	NULL},
{"q_dot_htf_sf_out", (getter)Outputs_get_q_dot_htf_sf_out,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power leaving in HTF [MWt]"),
 	NULL},
{"q_dot_pc_max", (getter)Outputs_get_q_dot_pc_max,(setter)0,
	PyDoc_STR("*sequence*: Max thermal power to PC [MWt]"),
 	NULL},
{"q_dot_pc_min", (getter)Outputs_get_q_dot_pc_min,(setter)0,
	PyDoc_STR("*sequence*: Thermal power for PC min operation [MWt]"),
 	NULL},
{"q_dot_pc_sb", (getter)Outputs_get_q_dot_pc_sb,(setter)0,
	PyDoc_STR("*sequence*: Thermal power for PC standby [MWt]"),
 	NULL},
{"q_dot_pc_startup", (getter)Outputs_get_q_dot_pc_startup,(setter)0,
	PyDoc_STR("*sequence*: PC startup thermal power [MWt]"),
 	NULL},
{"q_dot_pc_target", (getter)Outputs_get_q_dot_pc_target,(setter)0,
	PyDoc_STR("*sequence*: Target thermal power to PC [MWt]"),
 	NULL},
{"q_dot_piping_loss", (getter)Outputs_get_q_dot_piping_loss,(setter)0,
	PyDoc_STR("*sequence*: Field piping thermal losses [MWt]"),
 	NULL},
{"q_dot_rec_abs", (getter)Outputs_get_q_dot_rec_abs,(setter)0,
	PyDoc_STR("*sequence*: Receiver thermal power absorbed [MWt]"),
 	NULL},
{"q_dot_rec_inc", (getter)Outputs_get_q_dot_rec_inc,(setter)0,
	PyDoc_STR("*sequence*: Receiver thermal power incident [MWt]"),
 	NULL},
{"q_dot_rec_thermal_loss", (getter)Outputs_get_q_dot_rec_thermal_loss,(setter)0,
	PyDoc_STR("*sequence*: Receiver thermal losses [MWt]"),
 	NULL},
{"q_dot_tes_est", (getter)Outputs_get_q_dot_tes_est,(setter)0,
	PyDoc_STR("*float*: Estimated TES Heat Loss [MW]"),
 	NULL},
{"q_inc_sf_tot", (getter)Outputs_get_q_inc_sf_tot,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power incident [MWt]"),
 	NULL},
{"q_pb", (getter)Outputs_get_q_pb,(setter)0,
	PyDoc_STR("*sequence*: PC input energy [MWt]"),
 	NULL},
{"q_pc_startup", (getter)Outputs_get_q_pc_startup,(setter)0,
	PyDoc_STR("*sequence*: PC startup thermal energy [MWht]"),
 	NULL},
{"q_tes", (getter)Outputs_get_q_tes,(setter)0,
	PyDoc_STR("*float*: TES design capacity [MWt-hr]"),
 	NULL},
{"q_tes_heater", (getter)Outputs_get_q_tes_heater,(setter)0,
	PyDoc_STR("*sequence*: TES freeze protection power [MWe]"),
 	NULL},
{"qinc_costh", (getter)Outputs_get_qinc_costh,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power incident after cosine [MWt]"),
 	NULL},
{"rec_op_mode_final", (getter)Outputs_get_rec_op_mode_final,(setter)0,
	PyDoc_STR("*sequence*: Final receiver operating mode 0: off, 1: startup, 2: on [-]"),
 	NULL},
{"recirculating", (getter)Outputs_get_recirculating,(setter)0,
	PyDoc_STR("*sequence*: Field recirculating (bypass valve open) [-]"),
 	NULL},
{"required_number_of_loops_for_SM1", (getter)Outputs_get_required_number_of_loops_for_SM1,(setter)0,
	PyDoc_STR("*float*: Heat loss at design"),
 	NULL},
{"rh", (getter)Outputs_get_rh,(setter)0,
	PyDoc_STR("*sequence*: Resource Relative Humidity [%]"),
 	NULL},
{"sim_duration", (getter)Outputs_get_sim_duration,(setter)0,
	PyDoc_STR("*float*: Computational time of timeseries simulation [s]"),
 	NULL},
{"single_loop_aperture", (getter)Outputs_get_single_loop_aperture,(setter)0,
	PyDoc_STR("*float*: Single loop aperture [m2]"),
 	NULL},
{"solar_mult", (getter)Outputs_get_solar_mult,(setter)0,
	PyDoc_STR("*float*: Actual solar multiple"),
 	NULL},
{"solazi", (getter)Outputs_get_solazi,(setter)0,
	PyDoc_STR("*sequence*: Resource Solar Azimuth [deg]"),
 	NULL},
{"solzen", (getter)Outputs_get_solzen,(setter)0,
	PyDoc_STR("*sequence*: Resource Solar Zenith [deg]"),
 	NULL},
{"system_capacity", (getter)Outputs_get_system_capacity,(setter)0,
	PyDoc_STR("*float*: System capacity [kWe]"),
 	NULL},
{"tank_losses", (getter)Outputs_get_tank_losses,(setter)0,
	PyDoc_STR("*sequence*: TES thermal losses [MWt]"),
 	NULL},
{"tdry", (getter)Outputs_get_tdry,(setter)0,
	PyDoc_STR("*sequence*: Resource Dry bulb temperature [C]"),
 	NULL},
{"tes_SA_cold", (getter)Outputs_get_tes_SA_cold,(setter)0,
	PyDoc_STR("*sequence*: TES cold side surface area [m2]"),
 	NULL},
{"tes_SA_hot", (getter)Outputs_get_tes_SA_hot,(setter)0,
	PyDoc_STR("*sequence*: TES hot side surface area [m2]"),
 	NULL},
{"tes_SA_tot", (getter)Outputs_get_tes_SA_tot,(setter)0,
	PyDoc_STR("*sequence*: TES total surface area [m2]"),
 	NULL},
{"tes_avail_vol", (getter)Outputs_get_tes_avail_vol,(setter)0,
	PyDoc_STR("*float*: Available HTF volume [m3]"),
 	NULL},
{"tes_cold_vol_frac", (getter)Outputs_get_tes_cold_vol_frac,(setter)0,
	PyDoc_STR("*sequence*: TES volume fraction of cold over total"),
 	NULL},
{"tes_error", (getter)Outputs_get_tes_error,(setter)0,
	PyDoc_STR("*sequence*: TES energy balance error [MWt]"),
 	NULL},
{"tes_error_corrected", (getter)Outputs_get_tes_error_corrected,(setter)0,
	PyDoc_STR("*sequence*: TES energy balance error, accounting for wall and temperature assumption error [MWt]"),
 	NULL},
{"tes_error_percent", (getter)Outputs_get_tes_error_percent,(setter)0,
	PyDoc_STR("*sequence*: TES energy balance error percent [%]"),
 	NULL},
{"tes_htf_avg_temp", (getter)Outputs_get_tes_htf_avg_temp,(setter)0,
	PyDoc_STR("*float*: HTF Average Temperature at Design [C]"),
 	NULL},
{"tes_htf_max_temp", (getter)Outputs_get_tes_htf_max_temp,(setter)0,
	PyDoc_STR("*float*: Maximum storage htf temp [C]"),
 	NULL},
{"tes_htf_min_temp", (getter)Outputs_get_tes_htf_min_temp,(setter)0,
	PyDoc_STR("*float*: Minimum storage htf temp [C]"),
 	NULL},
{"tes_htf_pump_power", (getter)Outputs_get_tes_htf_pump_power,(setter)0,
	PyDoc_STR("*sequence*: TES HTF pump power [MWe]"),
 	NULL},
{"tes_leak_error", (getter)Outputs_get_tes_leak_error,(setter)0,
	PyDoc_STR("*sequence*: TES energy balance error due to leakage assumption [MWt]"),
 	NULL},
{"tes_mass_tot", (getter)Outputs_get_tes_mass_tot,(setter)0,
	PyDoc_STR("*sequence*: TES total fluid mass [kg]"),
 	NULL},
{"tes_piston_frac", (getter)Outputs_get_tes_piston_frac,(setter)0,
	PyDoc_STR("*sequence*: TES piston fraction of cold distance over total"),
 	NULL},
{"tes_piston_loc", (getter)Outputs_get_tes_piston_loc,(setter)0,
	PyDoc_STR("*sequence*: TES piston distance from left (cold) side [m]"),
 	NULL},
{"tes_wall_error", (getter)Outputs_get_tes_wall_error,(setter)0,
	PyDoc_STR("*sequence*: TES energy balance error due to wall temperature assumption [MWt]"),
 	NULL},
{"time_hr", (getter)Outputs_get_time_hr,(setter)0,
	PyDoc_STR("*sequence*: Time at end of timestep [hr]"),
 	NULL},
{"total_aperture", (getter)Outputs_get_total_aperture,(setter)0,
	PyDoc_STR("*float*: Total field aperture area [m2]"),
 	NULL},
{"total_direct_cost", (getter)Outputs_get_total_direct_cost,(setter)0,
	PyDoc_STR("*float*: Total direct cost [$]"),
 	NULL},
{"total_indirect_cost", (getter)Outputs_get_total_indirect_cost,(setter)0,
	PyDoc_STR("*float*: Total direct cost [$]"),
 	NULL},
{"total_installed_cost", (getter)Outputs_get_total_installed_cost,(setter)0,
	PyDoc_STR("*float*: Total installed cost [$]"),
 	NULL},
{"total_land_area", (getter)Outputs_get_total_land_area,(setter)0,
	PyDoc_STR("*float*: Total Land Area [acre]"),
 	NULL},
{"total_loop_conversion_efficiency", (getter)Outputs_get_total_loop_conversion_efficiency,(setter)0,
	PyDoc_STR("*float*: Total Loop Conversion Efficiency at Design"),
 	NULL},
{"total_required_aperture_for_SM1", (getter)Outputs_get_total_required_aperture_for_SM1,(setter)0,
	PyDoc_STR("*float*: Aperture required for solar mult = 1 [m2]"),
 	NULL},
{"total_tracking_power", (getter)Outputs_get_total_tracking_power,(setter)0,
	PyDoc_STR("*float*: Total Tracking Power [MWe]"),
 	NULL},
{"tou_value", (getter)Outputs_get_tou_value,(setter)0,
	PyDoc_STR("*sequence*: CSP operating Time-of-use value"),
 	NULL},
{"twet", (getter)Outputs_get_twet,(setter)0,
	PyDoc_STR("*sequence*: Resource Wet bulb temperature [C]"),
 	NULL},
{"vel_loop_max", (getter)Outputs_get_vel_loop_max,(setter)0,
	PyDoc_STR("*sequence*: Receiver max HTF velocity in loop [m/s]"),
 	NULL},
{"vel_loop_min", (getter)Outputs_get_vel_loop_min,(setter)0,
	PyDoc_STR("*sequence*: Receiver min HTF velocity in loop [m/s]"),
 	NULL},
{"vol_min", (getter)Outputs_get_vol_min,(setter)0,
	PyDoc_STR("*float*: Minimum Fluid Volume [m3]"),
 	NULL},
{"vol_tank", (getter)Outputs_get_vol_tank,(setter)0,
	PyDoc_STR("*float*: Total tank volume [m3]"),
 	NULL},
{"vol_tes_cold", (getter)Outputs_get_vol_tes_cold,(setter)0,
	PyDoc_STR("*sequence*: TES cold fluid volume [m3]"),
 	NULL},
{"vol_tes_hot", (getter)Outputs_get_vol_tes_hot,(setter)0,
	PyDoc_STR("*sequence*: TES hot fluid volume [m3]"),
 	NULL},
{"vol_tes_tot", (getter)Outputs_get_vol_tes_tot,(setter)0,
	PyDoc_STR("*sequence*: TES total fluid volume [m3]"),
 	NULL},
{"wspd", (getter)Outputs_get_wspd,(setter)0,
	PyDoc_STR("*sequence*: Resource Wind Speed [m/s]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.Outputs",             /*tp_name*/
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
 * TroughPhysical
 */

static PyTypeObject TroughPhysical_Type;

static CmodObject *
newTroughPhysicalObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &TroughPhysical_Type);

	PySAM_TECH_ATTR()

	PyObject* SystemControl_obj = SystemControl_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemControl", SystemControl_obj);
	Py_DECREF(SystemControl_obj);

	PyObject* Weather_obj = Weather_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Weather", Weather_obj);
	Py_DECREF(Weather_obj);

	PyObject* SolarField_obj = SolarField_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SolarField", SolarField_obj);
	Py_DECREF(SolarField_obj);

	PyObject* Powerblock_obj = Powerblock_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Powerblock", Powerblock_obj);
	Py_DECREF(Powerblock_obj);

	PyObject* TES_obj = TES_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TES", TES_obj);
	Py_DECREF(TES_obj);

	PyObject* Controller_obj = Controller_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Controller", Controller_obj);
	Py_DECREF(Controller_obj);

	PyObject* Tou_obj = Tou_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Tou", Tou_obj);
	Py_DECREF(Tou_obj);

	PyObject* FinancialModel_obj = FinancialModel_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FinancialModel", FinancialModel_obj);
	Py_DECREF(FinancialModel_obj);

	PyObject* FinancialSolutionMode_obj = FinancialSolutionMode_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FinancialSolutionMode", FinancialSolutionMode_obj);
	Py_DECREF(FinancialSolutionMode_obj);

	PyObject* ElectricityRates_obj = ElectricityRates_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ElectricityRates", ElectricityRates_obj);
	Py_DECREF(ElectricityRates_obj);

	PyObject* TimeOfDeliveryFactors_obj = TimeOfDeliveryFactors_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TimeOfDeliveryFactors", TimeOfDeliveryFactors_obj);
	Py_DECREF(TimeOfDeliveryFactors_obj);

	PyObject* Revenue_obj = Revenue_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Revenue", Revenue_obj);
	Py_DECREF(Revenue_obj);

	PyObject* System_obj = System_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "System", System_obj);
	Py_DECREF(System_obj);

	PyObject* TowerAndReceiver_obj = TowerAndReceiver_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TowerAndReceiver", TowerAndReceiver_obj);
	Py_DECREF(TowerAndReceiver_obj);

	PyObject* CapitalCosts_obj = CapitalCosts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "CapitalCosts", CapitalCosts_obj);
	Py_DECREF(CapitalCosts_obj);

	PyObject* FinancialParameters_obj = FinancialParameters_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FinancialParameters", FinancialParameters_obj);
	Py_DECREF(FinancialParameters_obj);

	PyObject* AdjustmentFactors_obj = AdjustmentFactors_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "AdjustmentFactors", AdjustmentFactors_obj);
	Py_DECREF(AdjustmentFactors_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* TroughPhysical methods */

static void
TroughPhysical_dealloc(CmodObject *self)
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
TroughPhysical_get_data_ptr(CmodObject *self, PyObject *args)
{
	PyObject* ptr = PyLong_FromVoidPtr((void*)self->data_ptr);
	return ptr;
}


static PyObject *
TroughPhysical_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_TroughPhysical_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
TroughPhysical_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "TroughPhysical"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TroughPhysical_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "TroughPhysical"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TroughPhysical_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
TroughPhysical_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
TroughPhysical_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef TroughPhysical_methods[] = {
		{"execute",           (PyCFunction)TroughPhysical_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)TroughPhysical_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'System Control': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)TroughPhysical_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'System Control': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)TroughPhysical_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)TroughPhysical_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)TroughPhysical_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{"get_data_ptr",           (PyCFunction)TroughPhysical_get_data_ptr,  METH_VARARGS,
				PyDoc_STR("get_data_ptr() -> Pointer\n Get ssc_data_t pointer")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TroughPhysical_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
TroughPhysical_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject TroughPhysical_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)TroughPhysical_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)TroughPhysical_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)TroughPhysical_getattro, /*tp_getattro*/
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
		TroughPhysical_methods,      /*tp_methods*/
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


/* Function of no arguments returning new TroughPhysical object */

static PyObject *
TroughPhysical_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newTroughPhysicalObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
TroughPhysical_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTroughPhysicalObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
TroughPhysical_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTroughPhysicalObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "TroughPhysical", def) < 0) {
		TroughPhysical_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
TroughPhysical_from_existing(PyObject *self, PyObject *args)
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

	rv = newTroughPhysicalObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "TroughPhysical", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef TroughPhysicalModule_methods[] = {
		{"new",             TroughPhysical_new,         METH_VARARGS,
				PyDoc_STR("new() -> TroughPhysical")},
		{"default",             TroughPhysical_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> TroughPhysical\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"PhysicalTroughAllEquityPartnershipFlip\"*\n\n		- *\"PhysicalTroughCommercial\"*\n\n		- *\"PhysicalTroughLCOECalculator\"*\n\n		- *\"PhysicalTroughLeveragedPartnershipFlip\"*\n\n		- *\"PhysicalTroughMerchantPlant\"*\n\n		- *\"PhysicalTroughNone\"*\n\n		- *\"PhysicalTroughSaleLeaseback\"*\n\n		- *\"PhysicalTroughSingleOwner\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             TroughPhysical_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> TroughPhysical\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   TroughPhysical_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> TroughPhysical\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "CSP parabolic trough model based on heat transfer and thermodynamic principles for power generation");


static int
TroughPhysicalModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	TroughPhysical_Type.tp_dict = PyDict_New();
	if (!TroughPhysical_Type.tp_dict) { goto fail; }

	/// Add the SystemControl type object to TroughPhysical_Type
	if (PyType_Ready(&SystemControl_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"SystemControl",
				(PyObject*)&SystemControl_Type);
	Py_DECREF(&SystemControl_Type);

	/// Add the Weather type object to TroughPhysical_Type
	if (PyType_Ready(&Weather_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"Weather",
				(PyObject*)&Weather_Type);
	Py_DECREF(&Weather_Type);

	/// Add the SolarField type object to TroughPhysical_Type
	if (PyType_Ready(&SolarField_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"SolarField",
				(PyObject*)&SolarField_Type);
	Py_DECREF(&SolarField_Type);

	/// Add the Powerblock type object to TroughPhysical_Type
	if (PyType_Ready(&Powerblock_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"Powerblock",
				(PyObject*)&Powerblock_Type);
	Py_DECREF(&Powerblock_Type);

	/// Add the TES type object to TroughPhysical_Type
	if (PyType_Ready(&TES_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"TES",
				(PyObject*)&TES_Type);
	Py_DECREF(&TES_Type);

	/// Add the Controller type object to TroughPhysical_Type
	if (PyType_Ready(&Controller_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"Controller",
				(PyObject*)&Controller_Type);
	Py_DECREF(&Controller_Type);

	/// Add the Tou type object to TroughPhysical_Type
	if (PyType_Ready(&Tou_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"Tou",
				(PyObject*)&Tou_Type);
	Py_DECREF(&Tou_Type);

	/// Add the FinancialModel type object to TroughPhysical_Type
	if (PyType_Ready(&FinancialModel_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"FinancialModel",
				(PyObject*)&FinancialModel_Type);
	Py_DECREF(&FinancialModel_Type);

	/// Add the FinancialSolutionMode type object to TroughPhysical_Type
	if (PyType_Ready(&FinancialSolutionMode_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"FinancialSolutionMode",
				(PyObject*)&FinancialSolutionMode_Type);
	Py_DECREF(&FinancialSolutionMode_Type);

	/// Add the ElectricityRates type object to TroughPhysical_Type
	if (PyType_Ready(&ElectricityRates_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"ElectricityRates",
				(PyObject*)&ElectricityRates_Type);
	Py_DECREF(&ElectricityRates_Type);

	/// Add the TimeOfDeliveryFactors type object to TroughPhysical_Type
	if (PyType_Ready(&TimeOfDeliveryFactors_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"TimeOfDeliveryFactors",
				(PyObject*)&TimeOfDeliveryFactors_Type);
	Py_DECREF(&TimeOfDeliveryFactors_Type);

	/// Add the Revenue type object to TroughPhysical_Type
	if (PyType_Ready(&Revenue_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"Revenue",
				(PyObject*)&Revenue_Type);
	Py_DECREF(&Revenue_Type);

	/// Add the System type object to TroughPhysical_Type
	if (PyType_Ready(&System_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"System",
				(PyObject*)&System_Type);
	Py_DECREF(&System_Type);

	/// Add the TowerAndReceiver type object to TroughPhysical_Type
	if (PyType_Ready(&TowerAndReceiver_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"TowerAndReceiver",
				(PyObject*)&TowerAndReceiver_Type);
	Py_DECREF(&TowerAndReceiver_Type);

	/// Add the CapitalCosts type object to TroughPhysical_Type
	if (PyType_Ready(&CapitalCosts_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"CapitalCosts",
				(PyObject*)&CapitalCosts_Type);
	Py_DECREF(&CapitalCosts_Type);

	/// Add the FinancialParameters type object to TroughPhysical_Type
	if (PyType_Ready(&FinancialParameters_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"FinancialParameters",
				(PyObject*)&FinancialParameters_Type);
	Py_DECREF(&FinancialParameters_Type);

	/// Add the AdjustmentFactors type object to TroughPhysical_Type
	if (PyType_Ready(&AdjustmentFactors_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"AdjustmentFactors",
				(PyObject*)&AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);

	/// Add the Outputs type object to TroughPhysical_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the TroughPhysical type object to the module
	if (PyType_Ready(&TroughPhysical_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"TroughPhysical",
				(PyObject*)&TroughPhysical_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot TroughPhysicalModule_slots[] = {
		{Py_mod_exec, TroughPhysicalModule_exec},
		{0, NULL},
};

static struct PyModuleDef TroughPhysicalModule = {
		PyModuleDef_HEAD_INIT,
		"TroughPhysical",
		module_doc,
		0,
		TroughPhysicalModule_methods,
		TroughPhysicalModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_TroughPhysical(void)
{
	return PyModuleDef_Init(&TroughPhysicalModule);
}