#include <Python.h>

#include <SAM_MsptSfAndRecIsolated.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Simulation Group
 */ 

static PyTypeObject Simulation_Type;

static PyObject *
Simulation_new(SAM_MsptSfAndRecIsolated data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "MsptSfAndRecIsolated", "Simulation")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "MsptSfAndRecIsolated", "Simulation")){
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
Simulation_get_sim_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_Simulation_sim_type_nget, self->data_ptr);
}

static int
Simulation_set_sim_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_Simulation_sim_type_nset, self->data_ptr);
}

static PyGetSetDef Simulation_getset[] = {
{"sim_type", (getter)Simulation_get_sim_type,(setter)Simulation_set_sim_type,
	PyDoc_STR("*float*: 1 (default): timeseries, 2: design only\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Simulation_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MsptSfAndRecIsolated.Simulation",             /*tp_name*/
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
 * TowerAndReceiver Group
 */ 

static PyTypeObject TowerAndReceiver_Type;

static PyObject *
TowerAndReceiver_new(SAM_MsptSfAndRecIsolated data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "MsptSfAndRecIsolated", "TowerAndReceiver")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "MsptSfAndRecIsolated", "TowerAndReceiver")){
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
TowerAndReceiver_get_D_rec(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_D_rec_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_D_rec(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_D_rec_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_Flow_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_Flow_type_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_Flow_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_Flow_type_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_N_panels(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_N_panels_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_N_panels(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_N_panels_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_T_htf_cold_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_T_htf_cold_des_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_T_htf_cold_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_T_htf_cold_des_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_T_htf_hot_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_T_htf_hot_des_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_T_htf_hot_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_T_htf_hot_des_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_crossover_shift(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_crossover_shift_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_crossover_shift(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_crossover_shift_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_csp_pt_rec_max_oper_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_csp_pt_rec_max_oper_frac_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_csp_pt_rec_max_oper_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_csp_pt_rec_max_oper_frac_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_d_tube_out(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_d_tube_out_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_d_tube_out(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_d_tube_out_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_downc_tm_mult(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_downc_tm_mult_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_downc_tm_mult(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_downc_tm_mult_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_epsilon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_epsilon_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_epsilon(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_epsilon_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_eta_pump(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_eta_pump_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_eta_pump(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_eta_pump_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_f_rec_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_f_rec_min_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_f_rec_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_f_rec_min_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_field_fl_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_field_fl_props_mget, self->data_ptr);
}

static int
TowerAndReceiver_set_field_fl_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_field_fl_props_mset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_h_tower(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_h_tower_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_h_tower(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_h_tower_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_hl_ffact(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_hl_ffact_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_hl_ffact(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_hl_ffact_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_is_rec_clearsky_control(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_is_rec_clearsky_control_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_is_rec_clearsky_control(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_is_rec_clearsky_control_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_is_rec_model_trans(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_is_rec_model_trans_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_is_rec_model_trans(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_is_rec_model_trans_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_mat_tube(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_mat_tube_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_mat_tube(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_mat_tube_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_piping_length_const(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_piping_length_const_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_piping_length_const(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_piping_length_const_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_piping_length_mult(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_piping_length_mult_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_piping_length_mult(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_piping_length_mult_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_piping_loss_coefficient(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_piping_loss_coefficient_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_piping_loss_coefficient(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_piping_loss_coefficient_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_q_dot_rec_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_q_dot_rec_des_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_q_dot_rec_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_q_dot_rec_des_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_rec_height(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_rec_height_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_rec_height(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_rec_height_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_rec_htf(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_rec_htf_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_rec_htf(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_rec_htf_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_rec_qf_delay(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_rec_qf_delay_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_rec_qf_delay(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_rec_qf_delay_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_rec_su_delay(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_rec_su_delay_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_rec_su_delay(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_rec_su_delay_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_rec_tm_mult(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_rec_tm_mult_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_rec_tm_mult(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_rec_tm_mult_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_riser_tm_mult(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_riser_tm_mult_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_riser_tm_mult(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_riser_tm_mult_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_th_riser(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_th_riser_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_th_riser(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_th_riser_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_th_tube(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_th_tube_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_th_tube(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_th_tube_nset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_u_riser(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_TowerAndReceiver_u_riser_nget, self->data_ptr);
}

static int
TowerAndReceiver_set_u_riser(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_TowerAndReceiver_u_riser_nset, self->data_ptr);
}

static PyGetSetDef TowerAndReceiver_getset[] = {
{"D_rec", (getter)TowerAndReceiver_get_D_rec,(setter)TowerAndReceiver_set_D_rec,
	PyDoc_STR("*float*: The overall outer diameter of the receiver [m]\n\n**Required:**\nTrue"),
 	NULL},
{"Flow_type", (getter)TowerAndReceiver_get_Flow_type,(setter)TowerAndReceiver_set_Flow_type,
	PyDoc_STR("*float*: Receiver flow pattern: see figure on SAM Receiver page\n\n**Required:**\nTrue"),
 	NULL},
{"N_panels", (getter)TowerAndReceiver_get_N_panels,(setter)TowerAndReceiver_set_N_panels,
	PyDoc_STR("*float*: Number of individual panels on the receiver\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"T_htf_cold_des", (getter)TowerAndReceiver_get_T_htf_cold_des,(setter)TowerAndReceiver_set_T_htf_cold_des,
	PyDoc_STR("*float*: Cold HTF inlet temperature at design conditions [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_htf_hot_des", (getter)TowerAndReceiver_get_T_htf_hot_des,(setter)TowerAndReceiver_set_T_htf_hot_des,
	PyDoc_STR("*float*: Hot HTF outlet temperature at design conditions [C]\n\n**Required:**\nTrue"),
 	NULL},
{"crossover_shift", (getter)TowerAndReceiver_get_crossover_shift,(setter)TowerAndReceiver_set_crossover_shift,
	PyDoc_STR("*float*: Number of panels shift in receiver crossover position\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"csp_pt_rec_max_oper_frac", (getter)TowerAndReceiver_get_csp_pt_rec_max_oper_frac,(setter)TowerAndReceiver_set_csp_pt_rec_max_oper_frac,
	PyDoc_STR("*float*: Maximum receiver mass flow rate fraction\n\n**Required:**\nTrue"),
 	NULL},
{"d_tube_out", (getter)TowerAndReceiver_get_d_tube_out,(setter)TowerAndReceiver_set_d_tube_out,
	PyDoc_STR("*float*: The outer diameter of an individual receiver tube [mm]\n\n**Required:**\nTrue"),
 	NULL},
{"downc_tm_mult", (getter)TowerAndReceiver_get_downc_tm_mult,(setter)TowerAndReceiver_set_downc_tm_mult,
	PyDoc_STR("*float*: Downcomer thermal mass multiplier\n\n**Required:**\nRequired if is_rec_model_trans=1"),
 	NULL},
{"epsilon", (getter)TowerAndReceiver_get_epsilon,(setter)TowerAndReceiver_set_epsilon,
	PyDoc_STR("*float*: The emissivity of the receiver surface coating\n\n**Required:**\nTrue"),
 	NULL},
{"eta_pump", (getter)TowerAndReceiver_get_eta_pump,(setter)TowerAndReceiver_set_eta_pump,
	PyDoc_STR("*float*: Receiver HTF pump efficiency\n\n**Required:**\nTrue"),
 	NULL},
{"f_rec_min", (getter)TowerAndReceiver_get_f_rec_min,(setter)TowerAndReceiver_set_f_rec_min,
	PyDoc_STR("*float*: Minimum receiver mass flow rate turn down fraction\n\n**Required:**\nTrue"),
 	NULL},
{"field_fl_props", (getter)TowerAndReceiver_get_field_fl_props,(setter)TowerAndReceiver_set_field_fl_props,
	PyDoc_STR("*sequence[sequence]*: User defined field fluid property data [-]\n\n**Required:**\nTrue"),
 	NULL},
{"h_tower", (getter)TowerAndReceiver_get_h_tower,(setter)TowerAndReceiver_set_h_tower,
	PyDoc_STR("*float*: Tower height [m]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Required:**\nTrue"),
 	NULL},
{"hl_ffact", (getter)TowerAndReceiver_get_hl_ffact,(setter)TowerAndReceiver_set_hl_ffact,
	PyDoc_STR("*float*: The heat loss factor (thermal loss fudge factor)\n\n**Required:**\nTrue"),
 	NULL},
{"is_rec_clearsky_control", (getter)TowerAndReceiver_get_is_rec_clearsky_control,(setter)TowerAndReceiver_set_is_rec_clearsky_control,
	PyDoc_STR("*float*: 0: use measured dni, 1: use clear-sky control w/ rec_clearsky_frac input\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"is_rec_model_trans", (getter)TowerAndReceiver_get_is_rec_model_trans,(setter)TowerAndReceiver_set_is_rec_model_trans,
	PyDoc_STR("*float*: Formulate receiver model as transient?\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"mat_tube", (getter)TowerAndReceiver_get_mat_tube,(setter)TowerAndReceiver_set_mat_tube,
	PyDoc_STR("*float*: Receiver tube material, 2=Stainless AISI316\n\n**Required:**\nTrue"),
 	NULL},
{"piping_length_const", (getter)TowerAndReceiver_get_piping_length_const,(setter)TowerAndReceiver_set_piping_length_const,
	PyDoc_STR("*float*: Piping constant length [m]\n\n**Required:**\nTrue"),
 	NULL},
{"piping_length_mult", (getter)TowerAndReceiver_get_piping_length_mult,(setter)TowerAndReceiver_set_piping_length_mult,
	PyDoc_STR("*float*: Piping length multiplier\n\n**Required:**\nTrue"),
 	NULL},
{"piping_loss_coefficient", (getter)TowerAndReceiver_get_piping_loss_coefficient,(setter)TowerAndReceiver_set_piping_loss_coefficient,
	PyDoc_STR("*float*: Thermal loss per meter of piping [Wt/m2-K]"),
 	NULL},
{"q_dot_rec_des", (getter)TowerAndReceiver_get_q_dot_rec_des,(setter)TowerAndReceiver_set_q_dot_rec_des,
	PyDoc_STR("*float*: Receiver thermal power to HTF at design [MWt]\n\n**Required:**\nTrue"),
 	NULL},
{"rec_height", (getter)TowerAndReceiver_get_rec_height,(setter)TowerAndReceiver_set_rec_height,
	PyDoc_STR("*float*: Receiver height [m]\n\n**Required:**\nTrue"),
 	NULL},
{"rec_htf", (getter)TowerAndReceiver_get_rec_htf,(setter)TowerAndReceiver_set_rec_htf,
	PyDoc_STR("*float*: Receiver HTF, 17=Salt (60% NaNO3, 40% KNO3) 10=Salt (46.5% LiF 11.5% NaF 42% KF) 50=Lookup tables\n\n**Required:**\nTrue"),
 	NULL},
{"rec_qf_delay", (getter)TowerAndReceiver_get_rec_qf_delay,(setter)TowerAndReceiver_set_rec_qf_delay,
	PyDoc_STR("*float*: Energy-based receiver startup delay (fraction of rated thermal power)\n\n**Required:**\nTrue"),
 	NULL},
{"rec_su_delay", (getter)TowerAndReceiver_get_rec_su_delay,(setter)TowerAndReceiver_set_rec_su_delay,
	PyDoc_STR("*float*: Fixed startup delay time for the receiver [hr]\n\n**Required:**\nTrue"),
 	NULL},
{"rec_tm_mult", (getter)TowerAndReceiver_get_rec_tm_mult,(setter)TowerAndReceiver_set_rec_tm_mult,
	PyDoc_STR("*float*: Receiver thermal mass multiplier\n\n**Required:**\nRequired if is_rec_model_trans=1"),
 	NULL},
{"riser_tm_mult", (getter)TowerAndReceiver_get_riser_tm_mult,(setter)TowerAndReceiver_set_riser_tm_mult,
	PyDoc_STR("*float*: Riser thermal mass multiplier\n\n**Required:**\nRequired if is_rec_model_trans=1"),
 	NULL},
{"th_riser", (getter)TowerAndReceiver_get_th_riser,(setter)TowerAndReceiver_set_th_riser,
	PyDoc_STR("*float*: Riser or downcomer tube wall thickness [mm]\n\n**Required:**\nRequired if is_rec_model_trans=1"),
 	NULL},
{"th_tube", (getter)TowerAndReceiver_get_th_tube,(setter)TowerAndReceiver_set_th_tube,
	PyDoc_STR("*float*: The wall thickness of a single receiver tube [mm]\n\n**Required:**\nTrue"),
 	NULL},
{"u_riser", (getter)TowerAndReceiver_get_u_riser,(setter)TowerAndReceiver_set_u_riser,
	PyDoc_STR("*float*: Design point HTF velocity in riser [m/s]\n\n**Required:**\nRequired if is_rec_model_trans=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TowerAndReceiver_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MsptSfAndRecIsolated.TowerAndReceiver",             /*tp_name*/
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
 * ReceiverControl Group
 */ 

static PyTypeObject ReceiverControl_Type;

static PyObject *
ReceiverControl_new(SAM_MsptSfAndRecIsolated data_ptr)
{
	PyObject* new_obj = ReceiverControl_Type.tp_alloc(&ReceiverControl_Type,0);

	VarGroupObject* ReceiverControl_obj = (VarGroupObject*)new_obj;

	ReceiverControl_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* ReceiverControl methods */

static PyObject *
ReceiverControl_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "MsptSfAndRecIsolated", "ReceiverControl")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ReceiverControl_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &ReceiverControl_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "MsptSfAndRecIsolated", "ReceiverControl")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ReceiverControl_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &ReceiverControl_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ReceiverControl_methods[] = {
		{"assign",            (PyCFunction)ReceiverControl_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``ReceiverControl_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)ReceiverControl_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``ReceiverControl_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)ReceiverControl_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ReceiverControl_get_T_htf_cold_in_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MsptSfAndRecIsolated_ReceiverControl_T_htf_cold_in_od_aget, self->data_ptr);
}

static int
ReceiverControl_set_T_htf_cold_in_od(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_MsptSfAndRecIsolated_ReceiverControl_T_htf_cold_in_od_aset, self->data_ptr);
}

static PyObject *
ReceiverControl_get_plant_defocus_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MsptSfAndRecIsolated_ReceiverControl_plant_defocus_od_aget, self->data_ptr);
}

static int
ReceiverControl_set_plant_defocus_od(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_MsptSfAndRecIsolated_ReceiverControl_plant_defocus_od_aset, self->data_ptr);
}

static PyObject *
ReceiverControl_get_rec_clearsky_fraction(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_ReceiverControl_rec_clearsky_fraction_nget, self->data_ptr);
}

static int
ReceiverControl_set_rec_clearsky_fraction(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MsptSfAndRecIsolated_ReceiverControl_rec_clearsky_fraction_nset, self->data_ptr);
}

static PyGetSetDef ReceiverControl_getset[] = {
{"T_htf_cold_in_od", (getter)ReceiverControl_get_T_htf_cold_in_od,(setter)ReceiverControl_set_T_htf_cold_in_od,
	PyDoc_STR("*sequence*: HTF inlet temperature [C]\n\n**Required:**\nRequired if sim_type=1"),
 	NULL},
{"plant_defocus_od", (getter)ReceiverControl_get_plant_defocus_od,(setter)ReceiverControl_set_plant_defocus_od,
	PyDoc_STR("*sequence*: Plant defocus\n\n**Required:**\nRequired if sim_type=1"),
 	NULL},
{"rec_clearsky_fraction", (getter)ReceiverControl_get_rec_clearsky_fraction,(setter)ReceiverControl_set_rec_clearsky_fraction,
	PyDoc_STR("*float*: Weighting fraction on clear-sky DNI for receiver flow control\n\n**Required:**\nRequired if is_rec_clearsky_control=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ReceiverControl_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MsptSfAndRecIsolated.ReceiverControl",             /*tp_name*/
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
		ReceiverControl_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ReceiverControl_getset,          /*tp_getset*/
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
 * Timeseries Group
 */ 

static PyTypeObject Timeseries_Type;

static PyObject *
Timeseries_new(SAM_MsptSfAndRecIsolated data_ptr)
{
	PyObject* new_obj = Timeseries_Type.tp_alloc(&Timeseries_Type,0);

	VarGroupObject* Timeseries_obj = (VarGroupObject*)new_obj;

	Timeseries_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Timeseries methods */

static PyObject *
Timeseries_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "MsptSfAndRecIsolated", "Timeseries")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Timeseries_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Timeseries_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "MsptSfAndRecIsolated", "Timeseries")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Timeseries_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Timeseries_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Timeseries_methods[] = {
		{"assign",            (PyCFunction)Timeseries_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Timeseries_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Timeseries_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Timeseries_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Timeseries_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Timeseries_get_timestep_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MsptSfAndRecIsolated_Timeseries_timestep_od_aget, self->data_ptr);
}

static int
Timeseries_set_timestep_od(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_MsptSfAndRecIsolated_Timeseries_timestep_od_aset, self->data_ptr);
}

static PyGetSetDef Timeseries_getset[] = {
{"timestep_od", (getter)Timeseries_get_timestep_od,(setter)Timeseries_set_timestep_od,
	PyDoc_STR("*sequence*: Timestep [s]\n\n**Required:**\nRequired if sim_type=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Timeseries_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MsptSfAndRecIsolated.Timeseries",             /*tp_name*/
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
		Timeseries_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Timeseries_getset,          /*tp_getset*/
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
Weather_new(SAM_MsptSfAndRecIsolated data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "MsptSfAndRecIsolated", "Weather")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "MsptSfAndRecIsolated", "Weather")){
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
Weather_get_P_amb_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MsptSfAndRecIsolated_Weather_P_amb_od_aget, self->data_ptr);
}

static int
Weather_set_P_amb_od(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_MsptSfAndRecIsolated_Weather_P_amb_od_aset, self->data_ptr);
}

static PyObject *
Weather_get_T_amb_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MsptSfAndRecIsolated_Weather_T_amb_od_aget, self->data_ptr);
}

static int
Weather_set_T_amb_od(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_MsptSfAndRecIsolated_Weather_T_amb_od_aset, self->data_ptr);
}

static PyObject *
Weather_get_clearsky_to_measured_dni_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MsptSfAndRecIsolated_Weather_clearsky_to_measured_dni_od_aget, self->data_ptr);
}

static int
Weather_set_clearsky_to_measured_dni_od(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_MsptSfAndRecIsolated_Weather_clearsky_to_measured_dni_od_aset, self->data_ptr);
}

static PyObject *
Weather_get_deltaT_sky_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MsptSfAndRecIsolated_Weather_deltaT_sky_od_aget, self->data_ptr);
}

static int
Weather_set_deltaT_sky_od(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_MsptSfAndRecIsolated_Weather_deltaT_sky_od_aset, self->data_ptr);
}

static PyObject *
Weather_get_v_wind_10_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MsptSfAndRecIsolated_Weather_v_wind_10_od_aget, self->data_ptr);
}

static int
Weather_set_v_wind_10_od(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_MsptSfAndRecIsolated_Weather_v_wind_10_od_aset, self->data_ptr);
}

static PyGetSetDef Weather_getset[] = {
{"P_amb_od", (getter)Weather_get_P_amb_od,(setter)Weather_set_P_amb_od,
	PyDoc_STR("*sequence*: Ambient pressure [mbar]\n\n**Required:**\nRequired if sim_type=1"),
 	NULL},
{"T_amb_od", (getter)Weather_get_T_amb_od,(setter)Weather_set_T_amb_od,
	PyDoc_STR("*sequence*: Ambient temperature [C]\n\n**Required:**\nRequired if sim_type=1"),
 	NULL},
{"clearsky_to_measured_dni_od", (getter)Weather_get_clearsky_to_measured_dni_od,(setter)Weather_set_clearsky_to_measured_dni_od,
	PyDoc_STR("*sequence*: Ratio of clearsky to measured DNI\n\n**Required:**\nRequired if sim_type=1&is_rec_clearsky_control=1"),
 	NULL},
{"deltaT_sky_od", (getter)Weather_get_deltaT_sky_od,(setter)Weather_set_deltaT_sky_od,
	PyDoc_STR("*sequence*: Difference between ambient and sky temps [C]\n\n**Required:**\nRequired if sim_type=1"),
 	NULL},
{"v_wind_10_od", (getter)Weather_get_v_wind_10_od,(setter)Weather_set_v_wind_10_od,
	PyDoc_STR("*sequence*: Wind speed at 10 meters [m/s]\n\n**Required:**\nRequired if sim_type=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Weather_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MsptSfAndRecIsolated.Weather",             /*tp_name*/
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
 * Flux Group
 */ 

static PyTypeObject Flux_Type;

static PyObject *
Flux_new(SAM_MsptSfAndRecIsolated data_ptr)
{
	PyObject* new_obj = Flux_Type.tp_alloc(&Flux_Type,0);

	VarGroupObject* Flux_obj = (VarGroupObject*)new_obj;

	Flux_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Flux methods */

static PyObject *
Flux_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "MsptSfAndRecIsolated", "Flux")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Flux_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Flux_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "MsptSfAndRecIsolated", "Flux")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Flux_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Flux_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Flux_methods[] = {
		{"assign",            (PyCFunction)Flux_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Flux_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Flux_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Flux_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Flux_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Flux_get_flux_map_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_MsptSfAndRecIsolated_Flux_flux_map_od_mget, self->data_ptr);
}

static int
Flux_set_flux_map_od(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_MsptSfAndRecIsolated_Flux_flux_map_od_mset, self->data_ptr);
}

static PyGetSetDef Flux_getset[] = {
{"flux_map_od", (getter)Flux_get_flux_map_od,(setter)Flux_set_flux_map_od,
	PyDoc_STR("*sequence[sequence]*: rows: timestep, columns: panels. Flux *after* rec reflectance losses [W/m2]\n\n**Required:**\nRequired if sim_type=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Flux_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MsptSfAndRecIsolated.Flux",             /*tp_name*/
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
		Flux_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Flux_getset,          /*tp_getset*/
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
Outputs_new(SAM_MsptSfAndRecIsolated data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "MsptSfAndRecIsolated", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "MsptSfAndRecIsolated", "Outputs")){
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
Outputs_get_T_htf_rec_out_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MsptSfAndRecIsolated_Outputs_T_htf_rec_out_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_pump_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MsptSfAndRecIsolated_Outputs_W_dot_pump_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_rec_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MsptSfAndRecIsolated_Outputs_eta_rec_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_rec_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MsptSfAndRecIsolated_Outputs_m_dot_rec_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_rec_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MsptSfAndRecIsolated_Outputs_m_dot_rec_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_htf_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MsptSfAndRecIsolated_Outputs_q_dot_htf_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_conv_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MsptSfAndRecIsolated_Outputs_q_dot_rec_conv_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_inc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MsptSfAndRecIsolated_Outputs_q_dot_rec_inc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_inc_pre_defocus(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MsptSfAndRecIsolated_Outputs_q_dot_rec_inc_pre_defocus_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_piping_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MsptSfAndRecIsolated_Outputs_q_dot_rec_piping_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_rad_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MsptSfAndRecIsolated_Outputs_q_dot_rec_rad_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rec_component_defocus_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MsptSfAndRecIsolated_Outputs_rec_component_defocus_od_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"T_htf_rec_out_od", (getter)Outputs_get_T_htf_rec_out_od,(setter)0,
	PyDoc_STR("*sequence*: Receiver outlet temperature after piping losses [C]"),
 	NULL},
{"W_dot_pump_od", (getter)Outputs_get_W_dot_pump_od,(setter)0,
	PyDoc_STR("*sequence*: Receiver pumping power [MWe]"),
 	NULL},
{"eta_rec_od", (getter)Outputs_get_eta_rec_od,(setter)0,
	PyDoc_STR("*sequence*: Receiver thermal efficiency [kg/s]"),
 	NULL},
{"m_dot_rec_des", (getter)Outputs_get_m_dot_rec_des,(setter)0,
	PyDoc_STR("*float*: Receiver design mass flow rate [kg/s]"),
 	NULL},
{"m_dot_rec_od", (getter)Outputs_get_m_dot_rec_od,(setter)0,
	PyDoc_STR("*sequence*: Receiver mass flow rate [kg/s]"),
 	NULL},
{"q_dot_htf_od", (getter)Outputs_get_q_dot_htf_od,(setter)0,
	PyDoc_STR("*sequence*: Receiver thermal power to HTF after piping losses [MWt]"),
 	NULL},
{"q_dot_rec_conv_loss", (getter)Outputs_get_q_dot_rec_conv_loss,(setter)0,
	PyDoc_STR("*sequence*: Receiver convective losses [kg/s]"),
 	NULL},
{"q_dot_rec_inc", (getter)Outputs_get_q_dot_rec_inc,(setter)0,
	PyDoc_STR("*sequence*: Receiver incident flux, post defocus and reflection [kg/s]"),
 	NULL},
{"q_dot_rec_inc_pre_defocus", (getter)Outputs_get_q_dot_rec_inc_pre_defocus,(setter)0,
	PyDoc_STR("*sequence*: Receiver incident flux, pre-defocus, post-reflection [kg/s]"),
 	NULL},
{"q_dot_rec_piping_loss", (getter)Outputs_get_q_dot_rec_piping_loss,(setter)0,
	PyDoc_STR("*sequence*: Receiver piping thermal losses [kg/s]"),
 	NULL},
{"q_dot_rec_rad_loss", (getter)Outputs_get_q_dot_rec_rad_loss,(setter)0,
	PyDoc_STR("*sequence*: Receiver radiative losses [kg/s]"),
 	NULL},
{"rec_component_defocus_od", (getter)Outputs_get_rec_component_defocus_od,(setter)0,
	PyDoc_STR("*sequence*: Receiver component defocus"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MsptSfAndRecIsolated.Outputs",             /*tp_name*/
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
 * MsptSfAndRecIsolated
 */

static PyTypeObject MsptSfAndRecIsolated_Type;

static CmodObject *
newMsptSfAndRecIsolatedObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &MsptSfAndRecIsolated_Type);

	PySAM_TECH_ATTR()

	PyObject* Simulation_obj = Simulation_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Simulation", Simulation_obj);
	Py_DECREF(Simulation_obj);

	PyObject* TowerAndReceiver_obj = TowerAndReceiver_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TowerAndReceiver", TowerAndReceiver_obj);
	Py_DECREF(TowerAndReceiver_obj);

	PyObject* ReceiverControl_obj = ReceiverControl_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ReceiverControl", ReceiverControl_obj);
	Py_DECREF(ReceiverControl_obj);

	PyObject* Timeseries_obj = Timeseries_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Timeseries", Timeseries_obj);
	Py_DECREF(Timeseries_obj);

	PyObject* Weather_obj = Weather_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Weather", Weather_obj);
	Py_DECREF(Weather_obj);

	PyObject* Flux_obj = Flux_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Flux", Flux_obj);
	Py_DECREF(Flux_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* MsptSfAndRecIsolated methods */

static void
MsptSfAndRecIsolated_dealloc(CmodObject *self)
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
MsptSfAndRecIsolated_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_MsptSfAndRecIsolated_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
MsptSfAndRecIsolated_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "MsptSfAndRecIsolated"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
MsptSfAndRecIsolated_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "MsptSfAndRecIsolated"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
MsptSfAndRecIsolated_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
MsptSfAndRecIsolated_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
MsptSfAndRecIsolated_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef MsptSfAndRecIsolated_methods[] = {
		{"execute",           (PyCFunction)MsptSfAndRecIsolated_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)MsptSfAndRecIsolated_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Simulation': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)MsptSfAndRecIsolated_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Simulation': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)MsptSfAndRecIsolated_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)MsptSfAndRecIsolated_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)MsptSfAndRecIsolated_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
MsptSfAndRecIsolated_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
MsptSfAndRecIsolated_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject MsptSfAndRecIsolated_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MsptSfAndRecIsolated",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)MsptSfAndRecIsolated_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)MsptSfAndRecIsolated_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)MsptSfAndRecIsolated_getattro, /*tp_getattro*/
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
		MsptSfAndRecIsolated_methods,      /*tp_methods*/
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


/* Function of no arguments returning new MsptSfAndRecIsolated object */

static PyObject *
MsptSfAndRecIsolated_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newMsptSfAndRecIsolatedObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
MsptSfAndRecIsolated_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newMsptSfAndRecIsolatedObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
MsptSfAndRecIsolated_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newMsptSfAndRecIsolatedObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "MsptSfAndRecIsolated", def) < 0) {
		MsptSfAndRecIsolated_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
MsptSfAndRecIsolated_from_existing(PyObject *self, PyObject *args)
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

	rv = newMsptSfAndRecIsolatedObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "MsptSfAndRecIsolated", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef MsptSfAndRecIsolatedModule_methods[] = {
		{"new",             MsptSfAndRecIsolated_new,         METH_VARARGS,
				PyDoc_STR("new() -> MsptSfAndRecIsolated")},
		{"default",             MsptSfAndRecIsolated_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> MsptSfAndRecIsolated\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             MsptSfAndRecIsolated_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> MsptSfAndRecIsolated\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   MsptSfAndRecIsolated_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> MsptSfAndRecIsolated\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "MsptSfAndRecIsolated");


static int
MsptSfAndRecIsolatedModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	MsptSfAndRecIsolated_Type.tp_dict = PyDict_New();
	if (!MsptSfAndRecIsolated_Type.tp_dict) { goto fail; }

	/// Add the Simulation type object to MsptSfAndRecIsolated_Type
	if (PyType_Ready(&Simulation_Type) < 0) { goto fail; }
	PyDict_SetItemString(MsptSfAndRecIsolated_Type.tp_dict,
				"Simulation",
				(PyObject*)&Simulation_Type);
	Py_DECREF(&Simulation_Type);

	/// Add the TowerAndReceiver type object to MsptSfAndRecIsolated_Type
	if (PyType_Ready(&TowerAndReceiver_Type) < 0) { goto fail; }
	PyDict_SetItemString(MsptSfAndRecIsolated_Type.tp_dict,
				"TowerAndReceiver",
				(PyObject*)&TowerAndReceiver_Type);
	Py_DECREF(&TowerAndReceiver_Type);

	/// Add the ReceiverControl type object to MsptSfAndRecIsolated_Type
	if (PyType_Ready(&ReceiverControl_Type) < 0) { goto fail; }
	PyDict_SetItemString(MsptSfAndRecIsolated_Type.tp_dict,
				"ReceiverControl",
				(PyObject*)&ReceiverControl_Type);
	Py_DECREF(&ReceiverControl_Type);

	/// Add the Timeseries type object to MsptSfAndRecIsolated_Type
	if (PyType_Ready(&Timeseries_Type) < 0) { goto fail; }
	PyDict_SetItemString(MsptSfAndRecIsolated_Type.tp_dict,
				"Timeseries",
				(PyObject*)&Timeseries_Type);
	Py_DECREF(&Timeseries_Type);

	/// Add the Weather type object to MsptSfAndRecIsolated_Type
	if (PyType_Ready(&Weather_Type) < 0) { goto fail; }
	PyDict_SetItemString(MsptSfAndRecIsolated_Type.tp_dict,
				"Weather",
				(PyObject*)&Weather_Type);
	Py_DECREF(&Weather_Type);

	/// Add the Flux type object to MsptSfAndRecIsolated_Type
	if (PyType_Ready(&Flux_Type) < 0) { goto fail; }
	PyDict_SetItemString(MsptSfAndRecIsolated_Type.tp_dict,
				"Flux",
				(PyObject*)&Flux_Type);
	Py_DECREF(&Flux_Type);

	/// Add the Outputs type object to MsptSfAndRecIsolated_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(MsptSfAndRecIsolated_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the MsptSfAndRecIsolated type object to the module
	if (PyType_Ready(&MsptSfAndRecIsolated_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"MsptSfAndRecIsolated",
				(PyObject*)&MsptSfAndRecIsolated_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot MsptSfAndRecIsolatedModule_slots[] = {
		{Py_mod_exec, MsptSfAndRecIsolatedModule_exec},
		{0, NULL},
};

static struct PyModuleDef MsptSfAndRecIsolatedModule = {
		PyModuleDef_HEAD_INIT,
		"MsptSfAndRecIsolated",
		module_doc,
		0,
		MsptSfAndRecIsolatedModule_methods,
		MsptSfAndRecIsolatedModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_MsptSfAndRecIsolated(void)
{
	return PyModuleDef_Init(&MsptSfAndRecIsolatedModule);
}