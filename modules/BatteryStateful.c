#include <Python.h>

#include <SAM_BatteryStateful.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Controls Group
 */ 

static PyTypeObject Controls_Type;

static PyObject *
Controls_new(SAM_BatteryStateful data_ptr)
{
	PyObject* new_obj = Controls_Type.tp_alloc(&Controls_Type,0);

	VarGroupObject* Controls_obj = (VarGroupObject*)new_obj;

	Controls_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Controls methods */

static PyObject *
Controls_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "BatteryStateful", "Controls")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Controls_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Controls_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "BatteryStateful", "Controls")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Controls_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Controls_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Controls_methods[] = {
		{"assign",            (PyCFunction)Controls_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Controls_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Controls_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Controls_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Controls_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Controls_get_control_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_Controls_control_mode_nget, self->data_ptr);
}

static int
Controls_set_control_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_Controls_control_mode_nset, self->data_ptr);
}

static PyObject *
Controls_get_dt_hr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_Controls_dt_hr_nget, self->data_ptr);
}

static int
Controls_set_dt_hr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_Controls_dt_hr_nset, self->data_ptr);
}

static PyObject *
Controls_get_input_current(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_Controls_input_current_nget, self->data_ptr);
}

static int
Controls_set_input_current(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_Controls_input_current_nset, self->data_ptr);
}

static PyObject *
Controls_get_input_power(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_Controls_input_power_nget, self->data_ptr);
}

static int
Controls_set_input_power(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_Controls_input_power_nset, self->data_ptr);
}

static PyGetSetDef Controls_getset[] = {
{"control_mode", (getter)Controls_get_control_mode,(setter)Controls_set_control_mode,
	PyDoc_STR("*float*: Control using current (0) or power (1) [0/1]\n\n**Required:**\nTrue"),
 	NULL},
{"dt_hr", (getter)Controls_get_dt_hr,(setter)Controls_set_dt_hr,
	PyDoc_STR("*float*: Time step in hours [hr]\n\n**Required:**\nTrue"),
 	NULL},
{"input_current", (getter)Controls_get_input_current,(setter)Controls_set_input_current,
	PyDoc_STR("*float*: Current at which to run battery [A]\n\n**Required:**\nRequired if control_mode=0"),
 	NULL},
{"input_power", (getter)Controls_get_input_power,(setter)Controls_set_input_power,
	PyDoc_STR("*float*: Power at which to run battery [kW]\n\n**Required:**\nRequired if control_mode=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Controls_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"BatteryStateful.Controls",             /*tp_name*/
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
		Controls_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Controls_getset,          /*tp_getset*/
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
 * ParamsCell Group
 */ 

static PyTypeObject ParamsCell_Type;

static PyObject *
ParamsCell_new(SAM_BatteryStateful data_ptr)
{
	PyObject* new_obj = ParamsCell_Type.tp_alloc(&ParamsCell_Type,0);

	VarGroupObject* ParamsCell_obj = (VarGroupObject*)new_obj;

	ParamsCell_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* ParamsCell methods */

static PyObject *
ParamsCell_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "BatteryStateful", "ParamsCell")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ParamsCell_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &ParamsCell_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "BatteryStateful", "ParamsCell")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ParamsCell_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &ParamsCell_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ParamsCell_methods[] = {
		{"assign",            (PyCFunction)ParamsCell_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``ParamsCell_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)ParamsCell_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``ParamsCell_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)ParamsCell_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ParamsCell_get_C_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_C_rate_nget, self->data_ptr);
}

static int
ParamsCell_set_C_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_C_rate_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_Qexp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_Qexp_nget, self->data_ptr);
}

static int
ParamsCell_set_Qexp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_Qexp_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_Qfull(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_Qfull_nget, self->data_ptr);
}

static int
ParamsCell_set_Qfull(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_Qfull_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_Qfull_flow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_Qfull_flow_nget, self->data_ptr);
}

static int
ParamsCell_set_Qfull_flow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_Qfull_flow_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_Qnom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_Qnom_nget, self->data_ptr);
}

static int
ParamsCell_set_Qnom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_Qnom_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_Vcut(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_Vcut_nget, self->data_ptr);
}

static int
ParamsCell_set_Vcut(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_Vcut_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_Vexp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_Vexp_nget, self->data_ptr);
}

static int
ParamsCell_set_Vexp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_Vexp_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_Vfull(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_Vfull_nget, self->data_ptr);
}

static int
ParamsCell_set_Vfull(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_Vfull_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_Vnom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_Vnom_nget, self->data_ptr);
}

static int
ParamsCell_set_Vnom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_Vnom_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_Vnom_default(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_Vnom_default_nget, self->data_ptr);
}

static int
ParamsCell_set_Vnom_default(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_Vnom_default_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_calendar_a(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_calendar_a_nget, self->data_ptr);
}

static int
ParamsCell_set_calendar_a(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_calendar_a_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_calendar_b(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_calendar_b_nget, self->data_ptr);
}

static int
ParamsCell_set_calendar_b(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_calendar_b_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_calendar_c(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_calendar_c_nget, self->data_ptr);
}

static int
ParamsCell_set_calendar_c(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_calendar_c_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_calendar_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_calendar_choice_nget, self->data_ptr);
}

static int
ParamsCell_set_calendar_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_calendar_choice_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_calendar_matrix(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_BatteryStateful_ParamsCell_calendar_matrix_mget, self->data_ptr);
}

static int
ParamsCell_set_calendar_matrix(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_BatteryStateful_ParamsCell_calendar_matrix_mset, self->data_ptr);
}

static PyObject *
ParamsCell_get_calendar_q0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_calendar_q0_nget, self->data_ptr);
}

static int
ParamsCell_set_calendar_q0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_calendar_q0_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_chem(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_chem_nget, self->data_ptr);
}

static int
ParamsCell_set_chem(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_chem_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_cycling_matrix(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_BatteryStateful_ParamsCell_cycling_matrix_mget, self->data_ptr);
}

static int
ParamsCell_set_cycling_matrix(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_BatteryStateful_ParamsCell_cycling_matrix_mset, self->data_ptr);
}

static PyObject *
ParamsCell_get_initial_SOC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_initial_SOC_nget, self->data_ptr);
}

static int
ParamsCell_set_initial_SOC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_initial_SOC_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_leadacid_q10(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_leadacid_q10_nget, self->data_ptr);
}

static int
ParamsCell_set_leadacid_q10(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_leadacid_q10_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_leadacid_q20(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_leadacid_q20_nget, self->data_ptr);
}

static int
ParamsCell_set_leadacid_q20(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_leadacid_q20_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_leadacid_qn(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_leadacid_qn_nget, self->data_ptr);
}

static int
ParamsCell_set_leadacid_qn(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_leadacid_qn_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_leadacid_tn(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_leadacid_tn_nget, self->data_ptr);
}

static int
ParamsCell_set_leadacid_tn(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_leadacid_tn_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_life_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_life_model_nget, self->data_ptr);
}

static int
ParamsCell_set_life_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_life_model_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_maximum_SOC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_maximum_SOC_nget, self->data_ptr);
}

static int
ParamsCell_set_maximum_SOC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_maximum_SOC_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_minimum_SOC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_minimum_SOC_nget, self->data_ptr);
}

static int
ParamsCell_set_minimum_SOC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_minimum_SOC_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_resistance(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_resistance_nget, self->data_ptr);
}

static int
ParamsCell_set_resistance(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_resistance_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_voltage_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsCell_voltage_choice_nget, self->data_ptr);
}

static int
ParamsCell_set_voltage_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsCell_voltage_choice_nset, self->data_ptr);
}

static PyObject *
ParamsCell_get_voltage_matrix(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_BatteryStateful_ParamsCell_voltage_matrix_mget, self->data_ptr);
}

static int
ParamsCell_set_voltage_matrix(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_BatteryStateful_ParamsCell_voltage_matrix_mset, self->data_ptr);
}

static PyGetSetDef ParamsCell_getset[] = {
{"C_rate", (getter)ParamsCell_get_C_rate,(setter)ParamsCell_set_C_rate,
	PyDoc_STR("*float*: Rate at which voltage vs. capacity curve input\n\n**Required:**\nRequired if voltage_choice=0&chem~2"),
 	NULL},
{"Qexp", (getter)ParamsCell_get_Qexp,(setter)ParamsCell_set_Qexp,
	PyDoc_STR("*float*: Cell capacity at end of exponential zone [Ah]\n\n**Required:**\nRequired if voltage_choice=0&chem~2"),
 	NULL},
{"Qfull", (getter)ParamsCell_get_Qfull,(setter)ParamsCell_set_Qfull,
	PyDoc_STR("*float*: Fully charged cell capacity [Ah]\n\n**Required:**\nTrue"),
 	NULL},
{"Qfull_flow", (getter)ParamsCell_get_Qfull_flow,(setter)ParamsCell_set_Qfull_flow,
	PyDoc_STR("*float*: Fully charged flow battery capacity [Ah]\n\n**Required:**\nRequired if voltage_choice=0&chem=3"),
 	NULL},
{"Qnom", (getter)ParamsCell_get_Qnom,(setter)ParamsCell_set_Qnom,
	PyDoc_STR("*float*: Cell capacity at end of nominal zone [Ah]\n\n**Required:**\nRequired if voltage_choice=0&chem~2"),
 	NULL},
{"Vcut", (getter)ParamsCell_get_Vcut,(setter)ParamsCell_set_Vcut,
	PyDoc_STR("*float*: Cell cutoff voltage [V]\n\n**Required:**\nRequired if voltage_choice=0&chem~2"),
 	NULL},
{"Vexp", (getter)ParamsCell_get_Vexp,(setter)ParamsCell_set_Vexp,
	PyDoc_STR("*float*: Cell voltage at end of exponential zone [V]\n\n**Required:**\nRequired if voltage_choice=0&chem~2"),
 	NULL},
{"Vfull", (getter)ParamsCell_get_Vfull,(setter)ParamsCell_set_Vfull,
	PyDoc_STR("*float*: Fully charged cell voltage [V]\n\n**Required:**\nRequired if voltage_choice=0&chem~2"),
 	NULL},
{"Vnom", (getter)ParamsCell_get_Vnom,(setter)ParamsCell_set_Vnom,
	PyDoc_STR("*float*: Cell voltage at end of nominal zone [V]\n\n**Required:**\nRequired if voltage_choice=0&chem~2"),
 	NULL},
{"Vnom_default", (getter)ParamsCell_get_Vnom_default,(setter)ParamsCell_set_Vnom_default,
	PyDoc_STR("*float*: Default nominal cell voltage [V]\n\n**Required:**\nTrue"),
 	NULL},
{"calendar_a", (getter)ParamsCell_get_calendar_a,(setter)ParamsCell_set_calendar_a,
	PyDoc_STR("*float*: Calendar life model coefficient [1/sqrt(day)]\n\n**Required:**\nRequired if life_model=0&calendar_choice=1"),
 	NULL},
{"calendar_b", (getter)ParamsCell_get_calendar_b,(setter)ParamsCell_set_calendar_b,
	PyDoc_STR("*float*: Calendar life model coefficient [K]\n\n**Required:**\nRequired if life_model=0&calendar_choice=1"),
 	NULL},
{"calendar_c", (getter)ParamsCell_get_calendar_c,(setter)ParamsCell_set_calendar_c,
	PyDoc_STR("*float*: Calendar life model coefficient [K]\n\n**Required:**\nRequired if life_model=0&calendar_choice=1"),
 	NULL},
{"calendar_choice", (getter)ParamsCell_get_calendar_choice,(setter)ParamsCell_set_calendar_choice,
	PyDoc_STR("*float*: Calendar life degradation input option [0/1/2]\n\n**Options:**\n0=None,1=LithiumIonModel,2=InputLossTable\n\n**Required:**\nRequired if life_model=0"),
 	NULL},
{"calendar_matrix", (getter)ParamsCell_get_calendar_matrix,(setter)ParamsCell_set_calendar_matrix,
	PyDoc_STR("*sequence[sequence]*: Table with Day # and Capacity % columns [[[#, %]]]\n\n**Required:**\nRequired if life_model=0&calendar_choice=2"),
 	NULL},
{"calendar_q0", (getter)ParamsCell_get_calendar_q0,(setter)ParamsCell_set_calendar_q0,
	PyDoc_STR("*float*: Calendar life model initial capacity cofficient\n\n**Required:**\nRequired if life_model=0&calendar_choice=1"),
 	NULL},
{"chem", (getter)ParamsCell_get_chem,(setter)ParamsCell_set_chem,
	PyDoc_STR("*float*: Lead Acid (0), Li Ion (1), Vanadium Redox (2), Iron Flow (3) [0/1/2/3]\n\n**Required:**\nTrue"),
 	NULL},
{"cycling_matrix", (getter)ParamsCell_get_cycling_matrix,(setter)ParamsCell_set_cycling_matrix,
	PyDoc_STR("*sequence[sequence]*: Table with DOD %, Cycle #, and Capacity % columns [[[%, #, %]]]\n\n**Required:**\nRequired if life_model=0"),
 	NULL},
{"initial_SOC", (getter)ParamsCell_get_initial_SOC,(setter)ParamsCell_set_initial_SOC,
	PyDoc_STR("*float*: Initial state-of-charge [%]\n\n**Required:**\nTrue"),
 	NULL},
{"leadacid_q10", (getter)ParamsCell_get_leadacid_q10,(setter)ParamsCell_set_leadacid_q10,
	PyDoc_STR("*float*: Capacity at 10-hour discharge rate [Ah]\n\n**Required:**\nRequired if chem=0"),
 	NULL},
{"leadacid_q20", (getter)ParamsCell_get_leadacid_q20,(setter)ParamsCell_set_leadacid_q20,
	PyDoc_STR("*float*: Capacity at 20-hour discharge rate [Ah]\n\n**Required:**\nRequired if chem=0"),
 	NULL},
{"leadacid_qn", (getter)ParamsCell_get_leadacid_qn,(setter)ParamsCell_set_leadacid_qn,
	PyDoc_STR("*float*: Capacity at discharge rate for n-hour rate [Ah]\n\n**Required:**\nRequired if chem=0"),
 	NULL},
{"leadacid_tn", (getter)ParamsCell_get_leadacid_tn,(setter)ParamsCell_set_leadacid_tn,
	PyDoc_STR("*float*: Hours to discharge for qn rate [h]\n\n**Required:**\nRequired if chem=0"),
 	NULL},
{"life_model", (getter)ParamsCell_get_life_model,(setter)ParamsCell_set_life_model,
	PyDoc_STR("*float*: Battery life model specifier [0/1/2]\n\n**Options:**\n0=calendar/cycle,1=NMC,2=LMO/LTO\n\n**Required:**\nTrue"),
 	NULL},
{"maximum_SOC", (getter)ParamsCell_get_maximum_SOC,(setter)ParamsCell_set_maximum_SOC,
	PyDoc_STR("*float*: Maximum allowed state-of-charge [%]\n\n**Required:**\nTrue"),
 	NULL},
{"minimum_SOC", (getter)ParamsCell_get_minimum_SOC,(setter)ParamsCell_set_minimum_SOC,
	PyDoc_STR("*float*: Minimum allowed state-of-charge [%]\n\n**Required:**\nTrue"),
 	NULL},
{"resistance", (getter)ParamsCell_get_resistance,(setter)ParamsCell_set_resistance,
	PyDoc_STR("*float*: Internal resistance [Ohm]\n\n**Required:**\nTrue"),
 	NULL},
{"voltage_choice", (getter)ParamsCell_get_voltage_choice,(setter)ParamsCell_set_voltage_choice,
	PyDoc_STR("*float*: Battery voltage input option [0/1]\n\n**Options:**\n0=Model,1=Table\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"voltage_matrix", (getter)ParamsCell_get_voltage_matrix,(setter)ParamsCell_set_voltage_matrix,
	PyDoc_STR("*sequence[sequence]*: Table with depth-of-discharge % and Voltage as columns [[[%, V]]]\n\n**Required:**\nRequired if voltage_choice=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ParamsCell_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"BatteryStateful.ParamsCell",             /*tp_name*/
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
		ParamsCell_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ParamsCell_getset,          /*tp_getset*/
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
 * ParamsPack Group
 */ 

static PyTypeObject ParamsPack_Type;

static PyObject *
ParamsPack_new(SAM_BatteryStateful data_ptr)
{
	PyObject* new_obj = ParamsPack_Type.tp_alloc(&ParamsPack_Type,0);

	VarGroupObject* ParamsPack_obj = (VarGroupObject*)new_obj;

	ParamsPack_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* ParamsPack methods */

static PyObject *
ParamsPack_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "BatteryStateful", "ParamsPack")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ParamsPack_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &ParamsPack_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "BatteryStateful", "ParamsPack")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ParamsPack_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &ParamsPack_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ParamsPack_methods[] = {
		{"assign",            (PyCFunction)ParamsPack_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``ParamsPack_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)ParamsPack_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``ParamsPack_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)ParamsPack_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ParamsPack_get_Cp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsPack_Cp_nget, self->data_ptr);
}

static int
ParamsPack_set_Cp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsPack_Cp_nset, self->data_ptr);
}

static PyObject *
ParamsPack_get_T_room_init(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsPack_T_room_init_nget, self->data_ptr);
}

static int
ParamsPack_set_T_room_init(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsPack_T_room_init_nset, self->data_ptr);
}

static PyObject *
ParamsPack_get_cap_vs_temp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_BatteryStateful_ParamsPack_cap_vs_temp_mget, self->data_ptr);
}

static int
ParamsPack_set_cap_vs_temp(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_BatteryStateful_ParamsPack_cap_vs_temp_mset, self->data_ptr);
}

static PyObject *
ParamsPack_get_h(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsPack_h_nget, self->data_ptr);
}

static int
ParamsPack_set_h(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsPack_h_nset, self->data_ptr);
}

static PyObject *
ParamsPack_get_loss_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsPack_loss_choice_nget, self->data_ptr);
}

static int
ParamsPack_set_loss_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsPack_loss_choice_nset, self->data_ptr);
}

static PyObject *
ParamsPack_get_mass(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsPack_mass_nget, self->data_ptr);
}

static int
ParamsPack_set_mass(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsPack_mass_nset, self->data_ptr);
}

static PyObject *
ParamsPack_get_monthly_charge_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_BatteryStateful_ParamsPack_monthly_charge_loss_aget, self->data_ptr);
}

static int
ParamsPack_set_monthly_charge_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_BatteryStateful_ParamsPack_monthly_charge_loss_aset, self->data_ptr);
}

static PyObject *
ParamsPack_get_monthly_discharge_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_BatteryStateful_ParamsPack_monthly_discharge_loss_aget, self->data_ptr);
}

static int
ParamsPack_set_monthly_discharge_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_BatteryStateful_ParamsPack_monthly_discharge_loss_aset, self->data_ptr);
}

static PyObject *
ParamsPack_get_monthly_idle_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_BatteryStateful_ParamsPack_monthly_idle_loss_aget, self->data_ptr);
}

static int
ParamsPack_set_monthly_idle_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_BatteryStateful_ParamsPack_monthly_idle_loss_aset, self->data_ptr);
}

static PyObject *
ParamsPack_get_nominal_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsPack_nominal_energy_nget, self->data_ptr);
}

static int
ParamsPack_set_nominal_energy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsPack_nominal_energy_nset, self->data_ptr);
}

static PyObject *
ParamsPack_get_nominal_voltage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsPack_nominal_voltage_nget, self->data_ptr);
}

static int
ParamsPack_set_nominal_voltage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsPack_nominal_voltage_nset, self->data_ptr);
}

static PyObject *
ParamsPack_get_replacement_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsPack_replacement_capacity_nget, self->data_ptr);
}

static int
ParamsPack_set_replacement_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsPack_replacement_capacity_nset, self->data_ptr);
}

static PyObject *
ParamsPack_get_replacement_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsPack_replacement_option_nget, self->data_ptr);
}

static int
ParamsPack_set_replacement_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsPack_replacement_option_nset, self->data_ptr);
}

static PyObject *
ParamsPack_get_replacement_schedule_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_BatteryStateful_ParamsPack_replacement_schedule_percent_aget, self->data_ptr);
}

static int
ParamsPack_set_replacement_schedule_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_BatteryStateful_ParamsPack_replacement_schedule_percent_aset, self->data_ptr);
}

static PyObject *
ParamsPack_get_schedule_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_BatteryStateful_ParamsPack_schedule_loss_aget, self->data_ptr);
}

static int
ParamsPack_set_schedule_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_BatteryStateful_ParamsPack_schedule_loss_aset, self->data_ptr);
}

static PyObject *
ParamsPack_get_surface_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_ParamsPack_surface_area_nget, self->data_ptr);
}

static int
ParamsPack_set_surface_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_ParamsPack_surface_area_nset, self->data_ptr);
}

static PyGetSetDef ParamsPack_getset[] = {
{"Cp", (getter)ParamsPack_get_Cp,(setter)ParamsPack_set_Cp,
	PyDoc_STR("*float*: Battery specific heat capacity [J/KgK]\n\n**Required:**\nTrue"),
 	NULL},
{"T_room_init", (getter)ParamsPack_get_T_room_init,(setter)ParamsPack_set_T_room_init,
	PyDoc_STR("*float*: Temperature of storage room [C]\n\n**Required:**\nTrue"),
 	NULL},
{"cap_vs_temp", (getter)ParamsPack_get_cap_vs_temp,(setter)ParamsPack_set_cap_vs_temp,
	PyDoc_STR("*sequence[sequence]*: Table with Temperature and Capacity % as columns [[[C,%]]]\n\n**Required:**\nRequired if life_model=0"),
 	NULL},
{"h", (getter)ParamsPack_get_h,(setter)ParamsPack_set_h,
	PyDoc_STR("*float*: Heat transfer between battery and environment [W/m2K]\n\n**Required:**\nTrue"),
 	NULL},
{"loss_choice", (getter)ParamsPack_get_loss_choice,(setter)ParamsPack_set_loss_choice,
	PyDoc_STR("*float*: Loss power input option [0/1]\n\n**Options:**\n0=Monthly,1=TimeSeries\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"mass", (getter)ParamsPack_get_mass,(setter)ParamsPack_set_mass,
	PyDoc_STR("*float*: Battery mass [kg]\n\n**Required:**\nTrue"),
 	NULL},
{"monthly_charge_loss", (getter)ParamsPack_get_monthly_charge_loss,(setter)ParamsPack_set_monthly_charge_loss,
	PyDoc_STR("*sequence*: Battery system losses when charging [[kW]]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"monthly_discharge_loss", (getter)ParamsPack_get_monthly_discharge_loss,(setter)ParamsPack_set_monthly_discharge_loss,
	PyDoc_STR("*sequence*: Battery system losses when discharging [[kW]]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"monthly_idle_loss", (getter)ParamsPack_get_monthly_idle_loss,(setter)ParamsPack_set_monthly_idle_loss,
	PyDoc_STR("*sequence*: Battery system losses when idle [[kW]]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"nominal_energy", (getter)ParamsPack_get_nominal_energy,(setter)ParamsPack_set_nominal_energy,
	PyDoc_STR("*float*: Nominal installed energy [kWh]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Required:**\nTrue"),
 	NULL},
{"nominal_voltage", (getter)ParamsPack_get_nominal_voltage,(setter)ParamsPack_set_nominal_voltage,
	PyDoc_STR("*float*: Nominal DC voltage [V]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Required:**\nTrue"),
 	NULL},
{"replacement_capacity", (getter)ParamsPack_get_replacement_capacity,(setter)ParamsPack_set_replacement_capacity,
	PyDoc_STR("*float*: Capacity degradation at which to replace battery [%]\n\n**Required:**\nRequired if replacement_option=1"),
 	NULL},
{"replacement_option", (getter)ParamsPack_get_replacement_option,(setter)ParamsPack_set_replacement_option,
	PyDoc_STR("*float*: Replacements: none (0), by capacity (1), or schedule (2) [0=none,1=capacity limit,2=yearly schedule]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"replacement_schedule_percent", (getter)ParamsPack_get_replacement_schedule_percent,(setter)ParamsPack_set_replacement_schedule_percent,
	PyDoc_STR("*sequence*: Percentage of battery capacity to replace in each year [[%/year]]\n\n**Options:**\nlength <= analysis_period\n\n**Required:**\nRequired if replacement_option=2"),
 	NULL},
{"schedule_loss", (getter)ParamsPack_get_schedule_loss,(setter)ParamsPack_set_schedule_loss,
	PyDoc_STR("*sequence*: Battery system losses at each timestep [[kW]]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"surface_area", (getter)ParamsPack_get_surface_area,(setter)ParamsPack_set_surface_area,
	PyDoc_STR("*float*: Battery surface area [m^2]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ParamsPack_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"BatteryStateful.ParamsPack",             /*tp_name*/
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
		ParamsPack_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ParamsPack_getset,          /*tp_getset*/
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
 * StatePack Group
 */ 

static PyTypeObject StatePack_Type;

static PyObject *
StatePack_new(SAM_BatteryStateful data_ptr)
{
	PyObject* new_obj = StatePack_Type.tp_alloc(&StatePack_Type,0);

	VarGroupObject* StatePack_obj = (VarGroupObject*)new_obj;

	StatePack_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* StatePack methods */

static PyObject *
StatePack_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "BatteryStateful", "StatePack")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
StatePack_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &StatePack_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "BatteryStateful", "StatePack")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
StatePack_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &StatePack_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef StatePack_methods[] = {
		{"assign",            (PyCFunction)StatePack_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``StatePack_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)StatePack_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``StatePack_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)StatePack_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
StatePack_get_I(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StatePack_I_nget, self->data_ptr);
}

static int
StatePack_set_I(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StatePack_I_nset, self->data_ptr);
}

static PyObject *
StatePack_get_I_chargeable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StatePack_I_chargeable_nget, self->data_ptr);
}

static int
StatePack_set_I_chargeable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StatePack_I_chargeable_nset, self->data_ptr);
}

static PyObject *
StatePack_get_I_dischargeable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StatePack_I_dischargeable_nget, self->data_ptr);
}

static int
StatePack_set_I_dischargeable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StatePack_I_dischargeable_nset, self->data_ptr);
}

static PyObject *
StatePack_get_P(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StatePack_P_nget, self->data_ptr);
}

static int
StatePack_set_P(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StatePack_P_nset, self->data_ptr);
}

static PyObject *
StatePack_get_P_chargeable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StatePack_P_chargeable_nget, self->data_ptr);
}

static int
StatePack_set_P_chargeable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StatePack_P_chargeable_nset, self->data_ptr);
}

static PyObject *
StatePack_get_P_dischargeable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StatePack_P_dischargeable_nget, self->data_ptr);
}

static int
StatePack_set_P_dischargeable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StatePack_P_dischargeable_nset, self->data_ptr);
}

static PyObject *
StatePack_get_Q(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StatePack_Q_nget, self->data_ptr);
}

static int
StatePack_set_Q(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StatePack_Q_nset, self->data_ptr);
}

static PyObject *
StatePack_get_Q_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StatePack_Q_max_nget, self->data_ptr);
}

static int
StatePack_set_Q_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StatePack_Q_max_nset, self->data_ptr);
}

static PyObject *
StatePack_get_SOC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StatePack_SOC_nget, self->data_ptr);
}

static int
StatePack_set_SOC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StatePack_SOC_nset, self->data_ptr);
}

static PyObject *
StatePack_get_T_batt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StatePack_T_batt_nget, self->data_ptr);
}

static int
StatePack_set_T_batt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StatePack_T_batt_nset, self->data_ptr);
}

static PyObject *
StatePack_get_T_room(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StatePack_T_room_nget, self->data_ptr);
}

static int
StatePack_set_T_room(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StatePack_T_room_nset, self->data_ptr);
}

static PyObject *
StatePack_get_V(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StatePack_V_nget, self->data_ptr);
}

static int
StatePack_set_V(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StatePack_V_nset, self->data_ptr);
}

static PyObject *
StatePack_get_heat_dissipated(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StatePack_heat_dissipated_nget, self->data_ptr);
}

static int
StatePack_set_heat_dissipated(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StatePack_heat_dissipated_nset, self->data_ptr);
}

static PyObject *
StatePack_get_indices_replaced(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_BatteryStateful_StatePack_indices_replaced_aget, self->data_ptr);
}

static int
StatePack_set_indices_replaced(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_BatteryStateful_StatePack_indices_replaced_aset, self->data_ptr);
}

static PyObject *
StatePack_get_last_idx(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StatePack_last_idx_nget, self->data_ptr);
}

static int
StatePack_set_last_idx(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StatePack_last_idx_nset, self->data_ptr);
}

static PyObject *
StatePack_get_loss_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StatePack_loss_kw_nget, self->data_ptr);
}

static int
StatePack_set_loss_kw(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StatePack_loss_kw_nset, self->data_ptr);
}

static PyObject *
StatePack_get_n_replacements(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StatePack_n_replacements_nget, self->data_ptr);
}

static int
StatePack_set_n_replacements(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StatePack_n_replacements_nset, self->data_ptr);
}

static PyGetSetDef StatePack_getset[] = {
{"I", (getter)StatePack_get_I,(setter)StatePack_set_I,
	PyDoc_STR("*float*: Current [A]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"I_chargeable", (getter)StatePack_get_I_chargeable,(setter)StatePack_set_I_chargeable,
	PyDoc_STR("*float*: Estimated max chargeable current [A]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"I_dischargeable", (getter)StatePack_get_I_dischargeable,(setter)StatePack_set_I_dischargeable,
	PyDoc_STR("*float*: Estimated max dischargeable current [A]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"P", (getter)StatePack_get_P,(setter)StatePack_set_P,
	PyDoc_STR("*float*: Power [kW]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"P_chargeable", (getter)StatePack_get_P_chargeable,(setter)StatePack_set_P_chargeable,
	PyDoc_STR("*float*: Estimated max chargeable power  [kW]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"P_dischargeable", (getter)StatePack_get_P_dischargeable,(setter)StatePack_set_P_dischargeable,
	PyDoc_STR("*float*: Estimated max dischargeable power [kW]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"Q", (getter)StatePack_get_Q,(setter)StatePack_set_Q,
	PyDoc_STR("*float*: Capacity [Ah]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"Q_max", (getter)StatePack_get_Q_max,(setter)StatePack_set_Q_max,
	PyDoc_STR("*float*: Max Capacity [Ah]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"SOC", (getter)StatePack_get_SOC,(setter)StatePack_set_SOC,
	PyDoc_STR("*float*: State of Charge [%]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"T_batt", (getter)StatePack_get_T_batt,(setter)StatePack_set_T_batt,
	PyDoc_STR("*float*: Battery temperature averaged over time step [C]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"T_room", (getter)StatePack_get_T_room,(setter)StatePack_set_T_room,
	PyDoc_STR("*float*: Room temperature [C]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"V", (getter)StatePack_get_V,(setter)StatePack_set_V,
	PyDoc_STR("*float*: Voltage [V]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"heat_dissipated", (getter)StatePack_get_heat_dissipated,(setter)StatePack_set_heat_dissipated,
	PyDoc_STR("*float*: Heat dissipated due to flux [kW]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"indices_replaced", (getter)StatePack_get_indices_replaced,(setter)StatePack_set_indices_replaced,
	PyDoc_STR("*sequence*: Lifetime indices of replacement occurrences\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"last_idx", (getter)StatePack_get_last_idx,(setter)StatePack_set_last_idx,
	PyDoc_STR("*float*: Last index (lifetime)\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"loss_kw", (getter)StatePack_get_loss_kw,(setter)StatePack_set_loss_kw,
	PyDoc_STR("*float*: Ancillary power loss (kW DC for DC connected, AC for AC connected) [kW]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"n_replacements", (getter)StatePack_get_n_replacements,(setter)StatePack_set_n_replacements,
	PyDoc_STR("*float*: Number of replacements at current year\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject StatePack_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"BatteryStateful.StatePack",             /*tp_name*/
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
		StatePack_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		StatePack_getset,          /*tp_getset*/
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
 * StateCell Group
 */ 

static PyTypeObject StateCell_Type;

static PyObject *
StateCell_new(SAM_BatteryStateful data_ptr)
{
	PyObject* new_obj = StateCell_Type.tp_alloc(&StateCell_Type,0);

	VarGroupObject* StateCell_obj = (VarGroupObject*)new_obj;

	StateCell_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* StateCell methods */

static PyObject *
StateCell_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "BatteryStateful", "StateCell")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
StateCell_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &StateCell_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "BatteryStateful", "StateCell")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
StateCell_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &StateCell_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef StateCell_methods[] = {
		{"assign",            (PyCFunction)StateCell_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``StateCell_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)StateCell_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``StateCell_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)StateCell_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
StateCell_get_DOD_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_DOD_max_nget, self->data_ptr);
}

static int
StateCell_set_DOD_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_DOD_max_nset, self->data_ptr);
}

static PyObject *
StateCell_get_DOD_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_DOD_min_nget, self->data_ptr);
}

static int
StateCell_set_DOD_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_DOD_min_nset, self->data_ptr);
}

static PyObject *
StateCell_get_EFC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_EFC_nget, self->data_ptr);
}

static int
StateCell_set_EFC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_EFC_nset, self->data_ptr);
}

static PyObject *
StateCell_get_EFC_dt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_EFC_dt_nget, self->data_ptr);
}

static int
StateCell_set_EFC_dt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_EFC_dt_nset, self->data_ptr);
}

static PyObject *
StateCell_get_I_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_I_loss_nget, self->data_ptr);
}

static int
StateCell_set_I_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_I_loss_nset, self->data_ptr);
}

static PyObject *
StateCell_get_SOC_prev(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_SOC_prev_nget, self->data_ptr);
}

static int
StateCell_set_SOC_prev(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_SOC_prev_nset, self->data_ptr);
}

static PyObject *
StateCell_get_T_batt_prev(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_T_batt_prev_nget, self->data_ptr);
}

static int
StateCell_set_T_batt_prev(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_T_batt_prev_nset, self->data_ptr);
}

static PyObject *
StateCell_get_average_range(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_average_range_nget, self->data_ptr);
}

static int
StateCell_set_average_range(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_average_range_nset, self->data_ptr);
}

static PyObject *
StateCell_get_b1_dt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_b1_dt_nget, self->data_ptr);
}

static int
StateCell_set_b1_dt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_b1_dt_nset, self->data_ptr);
}

static PyObject *
StateCell_get_b2_dt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_b2_dt_nget, self->data_ptr);
}

static int
StateCell_set_b2_dt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_b2_dt_nset, self->data_ptr);
}

static PyObject *
StateCell_get_b3_dt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_b3_dt_nget, self->data_ptr);
}

static int
StateCell_set_b3_dt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_b3_dt_nset, self->data_ptr);
}

static PyObject *
StateCell_get_c0_dt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_c0_dt_nget, self->data_ptr);
}

static int
StateCell_set_c0_dt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_c0_dt_nset, self->data_ptr);
}

static PyObject *
StateCell_get_c2_dt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_c2_dt_nget, self->data_ptr);
}

static int
StateCell_set_c2_dt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_c2_dt_nset, self->data_ptr);
}

static PyObject *
StateCell_get_cell_current(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_cell_current_nget, self->data_ptr);
}

static int
StateCell_set_cell_current(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_cell_current_nset, self->data_ptr);
}

static PyObject *
StateCell_get_cell_voltage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_cell_voltage_nget, self->data_ptr);
}

static int
StateCell_set_cell_voltage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_cell_voltage_nset, self->data_ptr);
}

static PyObject *
StateCell_get_chargeChange(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_chargeChange_nget, self->data_ptr);
}

static int
StateCell_set_chargeChange(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_chargeChange_nset, self->data_ptr);
}

static PyObject *
StateCell_get_charge_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_charge_mode_nget, self->data_ptr);
}

static int
StateCell_set_charge_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_charge_mode_nset, self->data_ptr);
}

static PyObject *
StateCell_get_cum_dt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_cum_dt_nget, self->data_ptr);
}

static int
StateCell_set_cum_dt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_cum_dt_nset, self->data_ptr);
}

static PyObject *
StateCell_get_cycle_DOD(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_cycle_DOD_nget, self->data_ptr);
}

static int
StateCell_set_cycle_DOD(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_cycle_DOD_nset, self->data_ptr);
}

static PyObject *
StateCell_get_cycle_DOD_max(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_BatteryStateful_StateCell_cycle_DOD_max_aget, self->data_ptr);
}

static int
StateCell_set_cycle_DOD_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_BatteryStateful_StateCell_cycle_DOD_max_aset, self->data_ptr);
}

static PyObject *
StateCell_get_cycle_counts(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_BatteryStateful_StateCell_cycle_counts_mget, self->data_ptr);
}

static int
StateCell_set_cycle_counts(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_BatteryStateful_StateCell_cycle_counts_mset, self->data_ptr);
}

static PyObject *
StateCell_get_cycle_range(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_cycle_range_nget, self->data_ptr);
}

static int
StateCell_set_cycle_range(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_cycle_range_nset, self->data_ptr);
}

static PyObject *
StateCell_get_day_age_of_battery(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_day_age_of_battery_nget, self->data_ptr);
}

static int
StateCell_set_day_age_of_battery(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_day_age_of_battery_nset, self->data_ptr);
}

static PyObject *
StateCell_get_dq_relative_cal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_dq_relative_cal_nget, self->data_ptr);
}

static int
StateCell_set_dq_relative_cal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_dq_relative_cal_nset, self->data_ptr);
}

static PyObject *
StateCell_get_dq_relative_calendar_old(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_dq_relative_calendar_old_nget, self->data_ptr);
}

static int
StateCell_set_dq_relative_calendar_old(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_dq_relative_calendar_old_nset, self->data_ptr);
}

static PyObject *
StateCell_get_dq_relative_cyc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_dq_relative_cyc_nget, self->data_ptr);
}

static int
StateCell_set_dq_relative_cyc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_dq_relative_cyc_nset, self->data_ptr);
}

static PyObject *
StateCell_get_dq_relative_li1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_dq_relative_li1_nget, self->data_ptr);
}

static int
StateCell_set_dq_relative_li1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_dq_relative_li1_nset, self->data_ptr);
}

static PyObject *
StateCell_get_dq_relative_li2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_dq_relative_li2_nget, self->data_ptr);
}

static int
StateCell_set_dq_relative_li2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_dq_relative_li2_nset, self->data_ptr);
}

static PyObject *
StateCell_get_dq_relative_li3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_dq_relative_li3_nget, self->data_ptr);
}

static int
StateCell_set_dq_relative_li3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_dq_relative_li3_nset, self->data_ptr);
}

static PyObject *
StateCell_get_dq_relative_neg(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_dq_relative_neg_nget, self->data_ptr);
}

static int
StateCell_set_dq_relative_neg(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_dq_relative_neg_nset, self->data_ptr);
}

static PyObject *
StateCell_get_n_cycles(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_n_cycles_nget, self->data_ptr);
}

static int
StateCell_set_n_cycles(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_n_cycles_nset, self->data_ptr);
}

static PyObject *
StateCell_get_prev_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_prev_charge_nget, self->data_ptr);
}

static int
StateCell_set_prev_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_prev_charge_nset, self->data_ptr);
}

static PyObject *
StateCell_get_q0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_q0_nget, self->data_ptr);
}

static int
StateCell_set_q0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_q0_nset, self->data_ptr);
}

static PyObject *
StateCell_get_q1_0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_q1_0_nget, self->data_ptr);
}

static int
StateCell_set_q1_0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_q1_0_nset, self->data_ptr);
}

static PyObject *
StateCell_get_q2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_q2_nget, self->data_ptr);
}

static int
StateCell_set_q2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_q2_nset, self->data_ptr);
}

static PyObject *
StateCell_get_q2_0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_q2_0_nget, self->data_ptr);
}

static int
StateCell_set_q2_0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_q2_0_nset, self->data_ptr);
}

static PyObject *
StateCell_get_q_relative(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_q_relative_nget, self->data_ptr);
}

static int
StateCell_set_q_relative(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_q_relative_nset, self->data_ptr);
}

static PyObject *
StateCell_get_q_relative_calendar(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_q_relative_calendar_nget, self->data_ptr);
}

static int
StateCell_set_q_relative_calendar(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_q_relative_calendar_nset, self->data_ptr);
}

static PyObject *
StateCell_get_q_relative_cycle(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_q_relative_cycle_nget, self->data_ptr);
}

static int
StateCell_set_q_relative_cycle(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_q_relative_cycle_nset, self->data_ptr);
}

static PyObject *
StateCell_get_q_relative_li(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_q_relative_li_nget, self->data_ptr);
}

static int
StateCell_set_q_relative_li(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_q_relative_li_nset, self->data_ptr);
}

static PyObject *
StateCell_get_q_relative_neg(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_q_relative_neg_nget, self->data_ptr);
}

static int
StateCell_set_q_relative_neg(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_q_relative_neg_nset, self->data_ptr);
}

static PyObject *
StateCell_get_q_relative_thermal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_q_relative_thermal_nget, self->data_ptr);
}

static int
StateCell_set_q_relative_thermal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_q_relative_thermal_nset, self->data_ptr);
}

static PyObject *
StateCell_get_qmax_lifetime(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_qmax_lifetime_nget, self->data_ptr);
}

static int
StateCell_set_qmax_lifetime(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_qmax_lifetime_nset, self->data_ptr);
}

static PyObject *
StateCell_get_qmax_thermal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_qmax_thermal_nget, self->data_ptr);
}

static int
StateCell_set_qmax_thermal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_qmax_thermal_nset, self->data_ptr);
}

static PyObject *
StateCell_get_qn(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_qn_nget, self->data_ptr);
}

static int
StateCell_set_qn(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_qn_nset, self->data_ptr);
}

static PyObject *
StateCell_get_rainflow_Xlt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_rainflow_Xlt_nget, self->data_ptr);
}

static int
StateCell_set_rainflow_Xlt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_rainflow_Xlt_nset, self->data_ptr);
}

static PyObject *
StateCell_get_rainflow_Ylt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_rainflow_Ylt_nget, self->data_ptr);
}

static int
StateCell_set_rainflow_Ylt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_rainflow_Ylt_nset, self->data_ptr);
}

static PyObject *
StateCell_get_rainflow_jlt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_rainflow_jlt_nget, self->data_ptr);
}

static int
StateCell_set_rainflow_jlt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_rainflow_jlt_nset, self->data_ptr);
}

static PyObject *
StateCell_get_rainflow_peaks(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_BatteryStateful_StateCell_rainflow_peaks_aget, self->data_ptr);
}

static int
StateCell_set_rainflow_peaks(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_BatteryStateful_StateCell_rainflow_peaks_aset, self->data_ptr);
}

static PyObject *
StateCell_get_temp_avg(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_temp_avg_nget, self->data_ptr);
}

static int
StateCell_set_temp_avg(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_temp_avg_nset, self->data_ptr);
}

static PyObject *
StateCell_get_temp_dt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_BatteryStateful_StateCell_temp_dt_nget, self->data_ptr);
}

static int
StateCell_set_temp_dt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_BatteryStateful_StateCell_temp_dt_nset, self->data_ptr);
}

static PyGetSetDef StateCell_getset[] = {
{"DOD_max", (getter)StateCell_get_DOD_max,(setter)StateCell_set_DOD_max,
	PyDoc_STR("*float*: Max DOD of battery for current day [%]\n\n**Info:**\nCycles for Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"DOD_min", (getter)StateCell_get_DOD_min,(setter)StateCell_set_DOD_min,
	PyDoc_STR("*float*: Min DOD of battery for current day [%]\n\n**Info:**\nCycles for Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"EFC", (getter)StateCell_get_EFC,(setter)StateCell_set_EFC,
	PyDoc_STR("*float*: Total Equivalent Full Cycles [1]\n\n**Info:**\nLMO/LTO Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"EFC_dt", (getter)StateCell_get_EFC_dt,(setter)StateCell_set_EFC_dt,
	PyDoc_STR("*float*: Equivalent Full Cycles cumulated for current day [1]\n\n**Info:**\nLMO/LTO Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"I_loss", (getter)StateCell_get_I_loss,(setter)StateCell_set_I_loss,
	PyDoc_STR("*float*: Lifetime and thermal losses [A]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"SOC_prev", (getter)StateCell_get_SOC_prev,(setter)StateCell_set_SOC_prev,
	PyDoc_STR("*float*: State of Charge of last time step [%]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"T_batt_prev", (getter)StateCell_get_T_batt_prev,(setter)StateCell_set_T_batt_prev,
	PyDoc_STR("*float*: Battery temperature at end of last time step [C]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"average_range", (getter)StateCell_get_average_range,(setter)StateCell_set_average_range,
	PyDoc_STR("*float*: Average cycle cycle_range [%]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"b1_dt", (getter)StateCell_get_b1_dt,(setter)StateCell_set_b1_dt,
	PyDoc_STR("*float*: b1 coefficient cumulated for current day [day^-0.5]\n\n**Info:**\nNMC Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"b2_dt", (getter)StateCell_get_b2_dt,(setter)StateCell_set_b2_dt,
	PyDoc_STR("*float*: b2 coefficient cumulated for current day [1/cycle]\n\n**Info:**\nNMC Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"b3_dt", (getter)StateCell_get_b3_dt,(setter)StateCell_set_b3_dt,
	PyDoc_STR("*float*: b3 coefficient cumulated for current day [1]\n\n**Info:**\nNMC Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"c0_dt", (getter)StateCell_get_c0_dt,(setter)StateCell_set_c0_dt,
	PyDoc_STR("*float*: c0 coefficient cumulated for current day [Ah]\n\n**Info:**\nNMC Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"c2_dt", (getter)StateCell_get_c2_dt,(setter)StateCell_set_c2_dt,
	PyDoc_STR("*float*: c2 coefficient cumulated for current day [1/cycle]\n\n**Info:**\nNMC Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"cell_current", (getter)StateCell_get_cell_current,(setter)StateCell_set_cell_current,
	PyDoc_STR("*float*: Cell current [A]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"cell_voltage", (getter)StateCell_get_cell_voltage,(setter)StateCell_set_cell_voltage,
	PyDoc_STR("*float*: Cell voltage [V]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"chargeChange", (getter)StateCell_get_chargeChange,(setter)StateCell_set_chargeChange,
	PyDoc_STR("*float*: Whether Charge mode changed since last step [0/1]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"charge_mode", (getter)StateCell_get_charge_mode,(setter)StateCell_set_charge_mode,
	PyDoc_STR("*float*: Charge (0), Idle (1), Discharge (2) [0/1/2]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"cum_dt", (getter)StateCell_get_cum_dt,(setter)StateCell_set_cum_dt,
	PyDoc_STR("*float*: Elapsed time for current day [day]\n\n**Info:**\nCycles for Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"cycle_DOD", (getter)StateCell_get_cycle_DOD,(setter)StateCell_set_cycle_DOD,
	PyDoc_STR("*float*: cycle_DOD of last cycle [%]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"cycle_DOD_max", (getter)StateCell_get_cycle_DOD_max,(setter)StateCell_set_cycle_DOD_max,
	PyDoc_STR("*sequence*: Max DODs of cycles concluded in current day [%]\n\n**Info:**\nCycles for Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"cycle_counts", (getter)StateCell_get_cycle_counts,(setter)StateCell_set_cycle_counts,
	PyDoc_STR("*sequence[sequence]*: Counts of cycles by DOD [[%, cycles]]\n\n**Options:**\nIf life_model=0, counts all cycles in simulation; else, cycles per day\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"cycle_range", (getter)StateCell_get_cycle_range,(setter)StateCell_set_cycle_range,
	PyDoc_STR("*float*: Range of last cycle [%]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"day_age_of_battery", (getter)StateCell_get_day_age_of_battery,(setter)StateCell_set_day_age_of_battery,
	PyDoc_STR("*float*: Day age of battery [day]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"dq_relative_cal", (getter)StateCell_get_dq_relative_cal,(setter)StateCell_set_dq_relative_cal,
	PyDoc_STR("*float*: Cumulative capacity change from calendar degradation [%]\n\n**Info:**\nLMO/LTO Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"dq_relative_calendar_old", (getter)StateCell_get_dq_relative_calendar_old,(setter)StateCell_set_dq_relative_calendar_old,
	PyDoc_STR("*float*: Change in capacity of last time step [%]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"dq_relative_cyc", (getter)StateCell_get_dq_relative_cyc,(setter)StateCell_set_dq_relative_cyc,
	PyDoc_STR("*float*: Cumulative capacity change from cycling degradation [%]\n\n**Info:**\nLMO/LTO Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"dq_relative_li1", (getter)StateCell_get_dq_relative_li1,(setter)StateCell_set_dq_relative_li1,
	PyDoc_STR("*float*: Cumulative capacity change from time-dependent Li loss [1]\n\n**Info:**\nNMC Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"dq_relative_li2", (getter)StateCell_get_dq_relative_li2,(setter)StateCell_set_dq_relative_li2,
	PyDoc_STR("*float*: Cumulative capacity change from cycle-dependent Li loss [1]\n\n**Info:**\nNMC Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"dq_relative_li3", (getter)StateCell_get_dq_relative_li3,(setter)StateCell_set_dq_relative_li3,
	PyDoc_STR("*float*: Cumulative capacity change from BOL Li loss [1]\n\n**Info:**\nNMC Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"dq_relative_neg", (getter)StateCell_get_dq_relative_neg,(setter)StateCell_set_dq_relative_neg,
	PyDoc_STR("*float*: Cumulative capacity change from negative electrode [1]\n\n**Info:**\nNMC Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"n_cycles", (getter)StateCell_get_n_cycles,(setter)StateCell_set_n_cycles,
	PyDoc_STR("*float*: Number of cycles\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"prev_charge", (getter)StateCell_get_prev_charge,(setter)StateCell_set_prev_charge,
	PyDoc_STR("*float*: Charge mode of last time step [0/1/2]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"q0", (getter)StateCell_get_q0,(setter)StateCell_set_q0,
	PyDoc_STR("*float*: Cell capacity at timestep [Ah]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"q1_0", (getter)StateCell_get_q1_0,(setter)StateCell_set_q1_0,
	PyDoc_STR("*float*: Lead acid - Cell charge available [Ah]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"q2", (getter)StateCell_get_q2,(setter)StateCell_set_q2,
	PyDoc_STR("*float*: Lead acid - Cell capacity at 10-hr discharge rate [Ah]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"q2_0", (getter)StateCell_get_q2_0,(setter)StateCell_set_q2_0,
	PyDoc_STR("*float*: Lead acid - Cell charge bound [Ah]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"q_relative", (getter)StateCell_get_q_relative,(setter)StateCell_set_q_relative,
	PyDoc_STR("*float*: Overall relative capacity due to lifetime effects [%]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"q_relative_calendar", (getter)StateCell_get_q_relative_calendar,(setter)StateCell_set_q_relative_calendar,
	PyDoc_STR("*float*: Relative capacity due to calendar effects [%]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"q_relative_cycle", (getter)StateCell_get_q_relative_cycle,(setter)StateCell_set_q_relative_cycle,
	PyDoc_STR("*float*: Relative capacity due to cycling effects [%]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"q_relative_li", (getter)StateCell_get_q_relative_li,(setter)StateCell_set_q_relative_li,
	PyDoc_STR("*float*: Relative capacity due to loss of lithium inventory [%]\n\n**Info:**\nNMC Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"q_relative_neg", (getter)StateCell_get_q_relative_neg,(setter)StateCell_set_q_relative_neg,
	PyDoc_STR("*float*: Relative capacity due to loss of anode material [%]\n\n**Info:**\nNMC Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"q_relative_thermal", (getter)StateCell_get_q_relative_thermal,(setter)StateCell_set_q_relative_thermal,
	PyDoc_STR("*float*: Relative capacity due to thermal effects [%]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"qmax_lifetime", (getter)StateCell_get_qmax_lifetime,(setter)StateCell_set_qmax_lifetime,
	PyDoc_STR("*float*: Maximum possible cell capacity [Ah]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"qmax_thermal", (getter)StateCell_get_qmax_thermal,(setter)StateCell_set_qmax_thermal,
	PyDoc_STR("*float*: Maximum cell capacity adjusted for temperature effects [Ah]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"qn", (getter)StateCell_get_qn,(setter)StateCell_set_qn,
	PyDoc_STR("*float*: Lead acid - Cell capacity at n-hr discharge rate [Ah]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"rainflow_Xlt", (getter)StateCell_get_rainflow_Xlt,(setter)StateCell_set_rainflow_Xlt,
	PyDoc_STR("*float*: Rainflow cycle_range of second to last half cycle [%]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"rainflow_Ylt", (getter)StateCell_get_rainflow_Ylt,(setter)StateCell_set_rainflow_Ylt,
	PyDoc_STR("*float*: Rainflow cycle_range of last half cycle [%]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"rainflow_jlt", (getter)StateCell_get_rainflow_jlt,(setter)StateCell_set_rainflow_jlt,
	PyDoc_STR("*float*: Rainflow number of turning points\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"rainflow_peaks", (getter)StateCell_get_rainflow_peaks,(setter)StateCell_set_rainflow_peaks,
	PyDoc_STR("*sequence*: Rainflow peaks of cycle_DOD [[%]]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"temp_avg", (getter)StateCell_get_temp_avg,(setter)StateCell_set_temp_avg,
	PyDoc_STR("*float*: Average temperature for current day [K]\n\n**Info:**\nLMO/LTO Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"temp_dt", (getter)StateCell_get_temp_dt,(setter)StateCell_set_temp_dt,
	PyDoc_STR("*float*: Temperature cumulated for current day [K]\n\n**Info:**\nNMC Life Model\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject StateCell_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"BatteryStateful.StateCell",             /*tp_name*/
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
		StateCell_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		StateCell_getset,          /*tp_getset*/
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
 * BatteryStateful
 */

static PyTypeObject BatteryStateful_Type;

static CmodStatefulObject *
newBatteryStatefulObject(void* data_ptr)
{
	CmodStatefulObject *self;
	self = PyObject_New(CmodStatefulObject, &BatteryStateful_Type);

	PySAM_TECH_ATTR()

	PyObject* Controls_obj = Controls_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Controls", Controls_obj);
	Py_DECREF(Controls_obj);

	PyObject* ParamsCell_obj = ParamsCell_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ParamsCell", ParamsCell_obj);
	Py_DECREF(ParamsCell_obj);

	PyObject* ParamsPack_obj = ParamsPack_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ParamsPack", ParamsPack_obj);
	Py_DECREF(ParamsPack_obj);

	PyObject* StatePack_obj = StatePack_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "StatePack", StatePack_obj);
	Py_DECREF(StatePack_obj);

	PyObject* StateCell_obj = StateCell_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "StateCell", StateCell_obj);
	Py_DECREF(StateCell_obj);

	return self;
}

/* BatteryStateful methods */

static void
BatteryStateful_dealloc(CmodStatefulObject *self)
{
	Py_XDECREF(self->x_attr);

	if (!self->data_owner_ptr) {
		SAM_error error = new_error();
		SAM_table_destruct(self->data_ptr, &error);
		PySAM_has_error(error);
	}
	if (self->cmod_ptr) {
		SAM_error error = new_error();
		SAM_module_destruct(self->cmod_ptr, &error);
		PySAM_has_error(error);
	}
	PyObject_Del(self);
}


static PyObject *
BatteryStateful_setup(CmodStatefulObject *self, PyObject *args)
{
	SAM_error error = new_error();
	self->cmod_ptr = SAM_BatteryStateful_setup(self->data_ptr, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
BatteryStateful_execute(CmodStatefulObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_stateful_module_exec(self->cmod_ptr, self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
BatteryStateful_assign(CmodStatefulObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "BatteryStateful"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
BatteryStateful_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "BatteryStateful"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
BatteryStateful_export(CmodStatefulObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
BatteryStateful_value(CmodStatefulObject *self, PyObject *args)
{
	return CmodStateful_value(self, args);
}

static PyObject *
BatteryStateful_unassign(CmodStatefulObject *self, PyObject *args)
{
	return CmodStateful_unassign(self, args);
}

static PyMethodDef BatteryStateful_methods[] = {
		{"setup",            (PyCFunction)BatteryStateful_setup,  METH_VARARGS,
				PyDoc_STR("setup() -> None\n Setup parameters in simulation")},
		{"execute",           (PyCFunction)BatteryStateful_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)BatteryStateful_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Controls': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)BatteryStateful_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Controls': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)BatteryStateful_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)BatteryStateful_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)BatteryStateful_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
BatteryStateful_getattro(CmodStatefulObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
BatteryStateful_setattr(CmodStatefulObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject BatteryStateful_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"BatteryStateful",            /*tp_name*/
		sizeof(CmodStatefulObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)BatteryStateful_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)BatteryStateful_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)BatteryStateful_getattro, /*tp_getattro*/
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
		BatteryStateful_methods,      /*tp_methods*/
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


/* Function of no arguments returning new BatteryStateful object */

static PyObject *
BatteryStateful_new(PyObject *self, PyObject *args)
{
	CmodStatefulObject *rv;
	rv = newBatteryStatefulObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	rv->cmod_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
BatteryStateful_wrap(PyObject *self, PyObject *args)
{
	CmodStatefulObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newBatteryStatefulObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	rv->cmod_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
BatteryStateful_default(PyObject *self, PyObject *args)
{
	CmodStatefulObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newBatteryStatefulObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "BatteryStateful", def) < 0) {
		BatteryStateful_dealloc(rv);
		return NULL;
	}
	rv->cmod_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
BatteryStateful_from_existing(PyObject *self, PyObject *args)
{
	CmodStatefulObject *rv;
	PyObject * module = 0;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "O|s:from_existing", &module, &def)){
		PyErr_BadArgument();
		return NULL;
	}
	CmodStatefulObject *module_obj = (CmodStatefulObject *)module;
	SAM_table ptr = module_obj->data_ptr;

	// do a rough validity check on the data by checking its size
	SAM_error error = new_error();
	int data_size = SAM_table_size(ptr, &error);
	if (PySAM_has_error(error))
		goto fail;
	if (data_size < 0)
		goto fail;

	rv = newBatteryStatefulObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	rv->cmod_ptr = NULL;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "BatteryStateful", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef BatteryStatefulModule_methods[] = {
		{"new",             BatteryStateful_new,         METH_VARARGS,
				PyDoc_STR("new() -> BatteryStateful")},
		{"default",             BatteryStateful_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> BatteryStateful\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"LFPGraphite\"*\n\n		- *\"LMOLTO\"*\n\n		- *\"LeadAcid\"*\n\n		- *\"NMCGraphite\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             BatteryStateful_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> BatteryStateful\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   BatteryStateful_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> BatteryStateful\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "BatteryStateful has two major differences from the Battery module: 1) it contains only the “physical” component models of the battery (thermal, voltage, capacity, lifetime) and none of the dispatch methods (peak shaving, etc) of the Battery module; 2) the Battery module runs annual or multi-year simulations in a single execution, whereas BatteryStateful is run one timestep at a time using control variables, current or power, and can be run at sub-minute timesteps.");


static int
BatteryStatefulModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	BatteryStateful_Type.tp_dict = PyDict_New();
	if (!BatteryStateful_Type.tp_dict) { goto fail; }

	/// Add the Controls type object to BatteryStateful_Type
	if (PyType_Ready(&Controls_Type) < 0) { goto fail; }
	PyDict_SetItemString(BatteryStateful_Type.tp_dict,
				"Controls",
				(PyObject*)&Controls_Type);
	Py_DECREF(&Controls_Type);

	/// Add the ParamsCell type object to BatteryStateful_Type
	if (PyType_Ready(&ParamsCell_Type) < 0) { goto fail; }
	PyDict_SetItemString(BatteryStateful_Type.tp_dict,
				"ParamsCell",
				(PyObject*)&ParamsCell_Type);
	Py_DECREF(&ParamsCell_Type);

	/// Add the ParamsPack type object to BatteryStateful_Type
	if (PyType_Ready(&ParamsPack_Type) < 0) { goto fail; }
	PyDict_SetItemString(BatteryStateful_Type.tp_dict,
				"ParamsPack",
				(PyObject*)&ParamsPack_Type);
	Py_DECREF(&ParamsPack_Type);

	/// Add the StatePack type object to BatteryStateful_Type
	if (PyType_Ready(&StatePack_Type) < 0) { goto fail; }
	PyDict_SetItemString(BatteryStateful_Type.tp_dict,
				"StatePack",
				(PyObject*)&StatePack_Type);
	Py_DECREF(&StatePack_Type);

	/// Add the StateCell type object to BatteryStateful_Type
	if (PyType_Ready(&StateCell_Type) < 0) { goto fail; }
	PyDict_SetItemString(BatteryStateful_Type.tp_dict,
				"StateCell",
				(PyObject*)&StateCell_Type);
	Py_DECREF(&StateCell_Type);

	/// Add the BatteryStateful type object to the module
	if (PyType_Ready(&BatteryStateful_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"BatteryStateful",
				(PyObject*)&BatteryStateful_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot BatteryStatefulModule_slots[] = {
		{Py_mod_exec, BatteryStatefulModule_exec},
		{0, NULL},
};

static struct PyModuleDef BatteryStatefulModule = {
		PyModuleDef_HEAD_INIT,
		"BatteryStateful",
		module_doc,
		0,
		BatteryStatefulModule_methods,
		BatteryStatefulModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_BatteryStateful(void)
{
	return PyModuleDef_Init(&BatteryStatefulModule);
}