#include <Python.h>

#include <SAM_CspSubcomponent.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * System Group
 */ 

static PyTypeObject System_Type;

static PyObject *
System_new(SAM_CspSubcomponent data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CspSubcomponent", "System")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "CspSubcomponent", "System")){
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
System_get_solar_mult(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_System_solar_mult_nget, self->data_ptr);
}

static int
System_set_solar_mult(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_System_solar_mult_nset, self->data_ptr);
}

static PyObject *
System_get_t_step(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_System_t_step_nget, self->data_ptr);
}

static int
System_set_t_step(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_System_t_step_nset, self->data_ptr);
}

static PyGetSetDef System_getset[] = {
{"solar_mult", (getter)System_get_solar_mult,(setter)System_set_solar_mult,
	PyDoc_STR("*float*: Actual solar multiple of system [-]\n\n**Required:**\nTrue"),
 	NULL},
{"t_step", (getter)System_get_t_step,(setter)System_set_t_step,
	PyDoc_STR("*float*: Timestep duration [s]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject System_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CspSubcomponent.System",             /*tp_name*/
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
 * Weather Group
 */ 

static PyTypeObject Weather_Type;

static PyObject *
Weather_new(SAM_CspSubcomponent data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CspSubcomponent", "Weather")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "CspSubcomponent", "Weather")){
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
Weather_get_T_amb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CspSubcomponent_Weather_T_amb_aget, self->data_ptr);
}

static int
Weather_set_T_amb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_CspSubcomponent_Weather_T_amb_aset, self->data_ptr);
}

static PyGetSetDef Weather_getset[] = {
{"T_amb", (getter)Weather_get_T_amb,(setter)Weather_set_T_amb,
	PyDoc_STR("*sequence*: Ambient temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Weather_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CspSubcomponent.Weather",             /*tp_name*/
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
 * TES Group
 */ 

static PyTypeObject TES_Type;

static PyObject *
TES_new(SAM_CspSubcomponent data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CspSubcomponent", "TES")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "CspSubcomponent", "TES")){
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
TES_get_T_sink_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CspSubcomponent_TES_T_sink_out_aget, self->data_ptr);
}

static int
TES_set_T_sink_out(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_CspSubcomponent_TES_T_sink_out_aset, self->data_ptr);
}

static PyObject *
TES_get_T_src_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CspSubcomponent_TES_T_src_out_aget, self->data_ptr);
}

static int
TES_set_T_src_out(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_CspSubcomponent_TES_T_src_out_aset, self->data_ptr);
}

static PyObject *
TES_get_cold_tank_Thtr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_TES_cold_tank_Thtr_nget, self->data_ptr);
}

static int
TES_set_cold_tank_Thtr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_TES_cold_tank_Thtr_nset, self->data_ptr);
}

static PyObject *
TES_get_cold_tank_max_heat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_TES_cold_tank_max_heat_nget, self->data_ptr);
}

static int
TES_set_cold_tank_max_heat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_TES_cold_tank_max_heat_nset, self->data_ptr);
}

static PyObject *
TES_get_dt_hot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_TES_dt_hot_nget, self->data_ptr);
}

static int
TES_set_dt_hot(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_TES_dt_hot_nset, self->data_ptr);
}

static PyObject *
TES_get_h_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_TES_h_tank_nget, self->data_ptr);
}

static int
TES_set_h_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_TES_h_tank_nset, self->data_ptr);
}

static PyObject *
TES_get_h_tank_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_TES_h_tank_min_nget, self->data_ptr);
}

static int
TES_set_h_tank_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_TES_h_tank_min_nset, self->data_ptr);
}

static PyObject *
TES_get_hot_tank_Thtr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_TES_hot_tank_Thtr_nget, self->data_ptr);
}

static int
TES_set_hot_tank_Thtr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_TES_hot_tank_Thtr_nset, self->data_ptr);
}

static PyObject *
TES_get_hot_tank_bypassed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CspSubcomponent_TES_hot_tank_bypassed_aget, self->data_ptr);
}

static int
TES_set_hot_tank_bypassed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_CspSubcomponent_TES_hot_tank_bypassed_aset, self->data_ptr);
}

static PyObject *
TES_get_hot_tank_max_heat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_TES_hot_tank_max_heat_nget, self->data_ptr);
}

static int
TES_set_hot_tank_max_heat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_TES_hot_tank_max_heat_nset, self->data_ptr);
}

static PyObject *
TES_get_init_hot_htf_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_TES_init_hot_htf_percent_nget, self->data_ptr);
}

static int
TES_set_init_hot_htf_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_TES_init_hot_htf_percent_nset, self->data_ptr);
}

static PyObject *
TES_get_mdot_sink(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CspSubcomponent_TES_mdot_sink_aget, self->data_ptr);
}

static int
TES_set_mdot_sink(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_CspSubcomponent_TES_mdot_sink_aset, self->data_ptr);
}

static PyObject *
TES_get_mdot_src(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CspSubcomponent_TES_mdot_src_aget, self->data_ptr);
}

static int
TES_set_mdot_src(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_CspSubcomponent_TES_mdot_src_aset, self->data_ptr);
}

static PyObject *
TES_get_store_fl_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_CspSubcomponent_TES_store_fl_props_mget, self->data_ptr);
}

static int
TES_set_store_fl_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_CspSubcomponent_TES_store_fl_props_mset, self->data_ptr);
}

static PyObject *
TES_get_store_fluid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_TES_store_fluid_nget, self->data_ptr);
}

static int
TES_set_store_fluid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_TES_store_fluid_nset, self->data_ptr);
}

static PyObject *
TES_get_tank_pairs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_TES_tank_pairs_nget, self->data_ptr);
}

static int
TES_set_tank_pairs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_TES_tank_pairs_nset, self->data_ptr);
}

static PyObject *
TES_get_tshours(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_TES_tshours_nget, self->data_ptr);
}

static int
TES_set_tshours(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_TES_tshours_nset, self->data_ptr);
}

static PyObject *
TES_get_u_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_TES_u_tank_nget, self->data_ptr);
}

static int
TES_set_u_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_TES_u_tank_nset, self->data_ptr);
}

static PyGetSetDef TES_getset[] = {
{"T_sink_out", (getter)TES_get_T_sink_out,(setter)TES_set_T_sink_out,
	PyDoc_STR("*sequence*: Temperature from heat sink or power block [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_src_out", (getter)TES_get_T_src_out,(setter)TES_set_T_src_out,
	PyDoc_STR("*sequence*: Temperature from heat source [C]\n\n**Required:**\nTrue"),
 	NULL},
{"cold_tank_Thtr", (getter)TES_get_cold_tank_Thtr,(setter)TES_set_cold_tank_Thtr,
	PyDoc_STR("*float*: Minimum allowable cold tank HTF temp [C]\n\n**Required:**\nTrue"),
 	NULL},
{"cold_tank_max_heat", (getter)TES_get_cold_tank_max_heat,(setter)TES_set_cold_tank_max_heat,
	PyDoc_STR("*float*: Rated heater capacity for cold tank heating [MWe]\n\n**Required:**\nTrue"),
 	NULL},
{"dt_hot", (getter)TES_get_dt_hot,(setter)TES_set_dt_hot,
	PyDoc_STR("*float*: Hot side HX approach temp [C]\n\n**Required:**\nTrue"),
 	NULL},
{"h_tank", (getter)TES_get_h_tank,(setter)TES_set_h_tank,
	PyDoc_STR("*float*: Total height of tank (height of HTF when tank is full [m]\n\n**Required:**\nTrue"),
 	NULL},
{"h_tank_min", (getter)TES_get_h_tank_min,(setter)TES_set_h_tank_min,
	PyDoc_STR("*float*: Minimum allowable HTF height in storage tank [m]\n\n**Required:**\nTrue"),
 	NULL},
{"hot_tank_Thtr", (getter)TES_get_hot_tank_Thtr,(setter)TES_set_hot_tank_Thtr,
	PyDoc_STR("*float*: Minimum allowable hot tank HTF temp [C]\n\n**Required:**\nTrue"),
 	NULL},
{"hot_tank_bypassed", (getter)TES_get_hot_tank_bypassed,(setter)TES_set_hot_tank_bypassed,
	PyDoc_STR("*sequence*: Is mass flow from source going straight to cold tank? [-]\n\n**Required:**\nTrue"),
 	NULL},
{"hot_tank_max_heat", (getter)TES_get_hot_tank_max_heat,(setter)TES_set_hot_tank_max_heat,
	PyDoc_STR("*float*: Rated heater capacity for hot tank heating [MWe]\n\n**Required:**\nTrue"),
 	NULL},
{"init_hot_htf_percent", (getter)TES_get_init_hot_htf_percent,(setter)TES_set_init_hot_htf_percent,
	PyDoc_STR("*float*: Initial fraction of avail. vol that is hot [%]\n\n**Required:**\nTrue"),
 	NULL},
{"mdot_sink", (getter)TES_get_mdot_sink,(setter)TES_set_mdot_sink,
	PyDoc_STR("*sequence*: Mass flow to heat sink or power block [kg/s]\n\n**Required:**\nTrue"),
 	NULL},
{"mdot_src", (getter)TES_get_mdot_src,(setter)TES_set_mdot_src,
	PyDoc_STR("*sequence*: Mass flow from heat source [kg/s]\n\n**Required:**\nTrue"),
 	NULL},
{"store_fl_props", (getter)TES_get_store_fl_props,(setter)TES_set_store_fl_props,
	PyDoc_STR("*sequence[sequence]*: User defined storage fluid property data [-]\n\n**Required:**\nTrue"),
 	NULL},
{"store_fluid", (getter)TES_get_store_fluid,(setter)TES_set_store_fluid,
	PyDoc_STR("*float*: Material number for storage fluid [-]\n\n**Required:**\nTrue"),
 	NULL},
{"tank_pairs", (getter)TES_get_tank_pairs,(setter)TES_set_tank_pairs,
	PyDoc_STR("*float*: Number of equivalent tank pairs [-]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"tshours", (getter)TES_get_tshours,(setter)TES_set_tshours,
	PyDoc_STR("*float*: Equivalent full-load thermal storage hours [hr]\n\n**Required:**\nTrue"),
 	NULL},
{"u_tank", (getter)TES_get_u_tank,(setter)TES_set_u_tank,
	PyDoc_STR("*float*: Loss coefficient from the tank [W/m2-K]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TES_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CspSubcomponent.TES",             /*tp_name*/
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
 * SolarField Group
 */ 

static PyTypeObject SolarField_Type;

static PyObject *
SolarField_new(SAM_CspSubcomponent data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CspSubcomponent", "SolarField")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "CspSubcomponent", "SolarField")){
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
SolarField_get_Fluid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_SolarField_Fluid_nget, self->data_ptr);
}

static int
SolarField_set_Fluid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_SolarField_Fluid_nset, self->data_ptr);
}

static PyObject *
SolarField_get_HDR_rough(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_SolarField_HDR_rough_nget, self->data_ptr);
}

static int
SolarField_set_HDR_rough(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_SolarField_HDR_rough_nset, self->data_ptr);
}

static PyObject *
SolarField_get_T_loop_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_SolarField_T_loop_in_des_nget, self->data_ptr);
}

static int
SolarField_set_T_loop_in_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_SolarField_T_loop_in_des_nset, self->data_ptr);
}

static PyObject *
SolarField_get_T_loop_out(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_SolarField_T_loop_out_nget, self->data_ptr);
}

static int
SolarField_set_T_loop_out(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_SolarField_T_loop_out_nset, self->data_ptr);
}

static PyObject *
SolarField_get_calc_design_pipe_vals(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_SolarField_calc_design_pipe_vals_nget, self->data_ptr);
}

static int
SolarField_set_calc_design_pipe_vals(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_SolarField_calc_design_pipe_vals_nset, self->data_ptr);
}

static PyObject *
SolarField_get_eta_pump(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_SolarField_eta_pump_nget, self->data_ptr);
}

static int
SolarField_set_eta_pump(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_SolarField_eta_pump_nset, self->data_ptr);
}

static PyObject *
SolarField_get_field_fl_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_CspSubcomponent_SolarField_field_fl_props_mget, self->data_ptr);
}

static int
SolarField_set_field_fl_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_CspSubcomponent_SolarField_field_fl_props_mset, self->data_ptr);
}

static PyGetSetDef SolarField_getset[] = {
{"Fluid", (getter)SolarField_get_Fluid,(setter)SolarField_set_Fluid,
	PyDoc_STR("*float*: Field HTF fluid ID number [-]\n\n**Required:**\nTrue"),
 	NULL},
{"HDR_rough", (getter)SolarField_get_HDR_rough,(setter)SolarField_set_HDR_rough,
	PyDoc_STR("*float*: Header pipe roughness [m]\n\n**Required:**\nTrue"),
 	NULL},
{"T_loop_in_des", (getter)SolarField_get_T_loop_in_des,(setter)SolarField_set_T_loop_in_des,
	PyDoc_STR("*float*: Design loop inlet temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_loop_out", (getter)SolarField_get_T_loop_out,(setter)SolarField_set_T_loop_out,
	PyDoc_STR("*float*: Target loop outlet temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"calc_design_pipe_vals", (getter)SolarField_get_calc_design_pipe_vals,(setter)SolarField_set_calc_design_pipe_vals,
	PyDoc_STR("*float*: Calculate temps and pressures at design conditions for runners and headers [none]\n\n**Required:**\nTrue"),
 	NULL},
{"eta_pump", (getter)SolarField_get_eta_pump,(setter)SolarField_set_eta_pump,
	PyDoc_STR("*float*: HTF pump efficiency [none]\n\n**Required:**\nTrue"),
 	NULL},
{"field_fl_props", (getter)SolarField_get_field_fl_props,(setter)SolarField_set_field_fl_props,
	PyDoc_STR("*sequence[sequence]*: User defined field fluid property data [-]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SolarField_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CspSubcomponent.SolarField",             /*tp_name*/
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
Powerblock_new(SAM_CspSubcomponent data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CspSubcomponent", "Powerblock")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "CspSubcomponent", "Powerblock")){
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
Powerblock_get_P_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_Powerblock_P_ref_nget, self->data_ptr);
}

static int
Powerblock_set_P_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_Powerblock_P_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_eta_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_Powerblock_eta_ref_nget, self->data_ptr);
}

static int
Powerblock_set_eta_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_Powerblock_eta_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_pb_pump_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_Powerblock_pb_pump_coef_nget, self->data_ptr);
}

static int
Powerblock_set_pb_pump_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_Powerblock_pb_pump_coef_nset, self->data_ptr);
}

static PyGetSetDef Powerblock_getset[] = {
{"P_ref", (getter)Powerblock_get_P_ref,(setter)Powerblock_set_P_ref,
	PyDoc_STR("*float*: Rated plant capacity [MWe]\n\n**Required:**\nTrue"),
 	NULL},
{"eta_ref", (getter)Powerblock_get_eta_ref,(setter)Powerblock_set_eta_ref,
	PyDoc_STR("*float*: Power cycle efficiency at design [none]\n\n**Required:**\nTrue"),
 	NULL},
{"pb_pump_coef", (getter)Powerblock_get_pb_pump_coef,(setter)Powerblock_set_pb_pump_coef,
	PyDoc_STR("*float*: Pumping power to move 1kg of HTF through PB loop [kW/kg]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Powerblock_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CspSubcomponent.Powerblock",             /*tp_name*/
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
 * Controller Group
 */ 

static PyTypeObject Controller_Type;

static PyObject *
Controller_new(SAM_CspSubcomponent data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CspSubcomponent", "Controller")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "CspSubcomponent", "Controller")){
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
	return PySAM_double_getter(SAM_CspSubcomponent_Controller_DP_SGS_nget, self->data_ptr);
}

static int
Controller_set_DP_SGS(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_Controller_DP_SGS_nset, self->data_ptr);
}

static PyObject *
Controller_get_T_tank_hot_inlet_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_Controller_T_tank_hot_inlet_min_nget, self->data_ptr);
}

static int
Controller_set_T_tank_hot_inlet_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_Controller_T_tank_hot_inlet_min_nset, self->data_ptr);
}

static PyObject *
Controller_get_V_tes_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_Controller_V_tes_des_nget, self->data_ptr);
}

static int
Controller_set_V_tes_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_Controller_V_tes_des_nset, self->data_ptr);
}

static PyObject *
Controller_get_custom_tes_p_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_Controller_custom_tes_p_loss_nget, self->data_ptr);
}

static int
Controller_set_custom_tes_p_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_Controller_custom_tes_p_loss_nset, self->data_ptr);
}

static PyObject *
Controller_get_custom_tes_pipe_sizes(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_Controller_custom_tes_pipe_sizes_nget, self->data_ptr);
}

static int
Controller_set_custom_tes_pipe_sizes(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_Controller_custom_tes_pipe_sizes_nset, self->data_ptr);
}

static PyObject *
Controller_get_has_hot_tank_bypass(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_Controller_has_hot_tank_bypass_nget, self->data_ptr);
}

static int
Controller_set_has_hot_tank_bypass(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_Controller_has_hot_tank_bypass_nset, self->data_ptr);
}

static PyObject *
Controller_get_k_tes_loss_coeffs(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_CspSubcomponent_Controller_k_tes_loss_coeffs_mget, self->data_ptr);
}

static int
Controller_set_k_tes_loss_coeffs(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_CspSubcomponent_Controller_k_tes_loss_coeffs_mset, self->data_ptr);
}

static PyObject *
Controller_get_tanks_in_parallel(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_Controller_tanks_in_parallel_nget, self->data_ptr);
}

static int
Controller_set_tanks_in_parallel(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_Controller_tanks_in_parallel_nset, self->data_ptr);
}

static PyObject *
Controller_get_tes_diams(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_CspSubcomponent_Controller_tes_diams_mget, self->data_ptr);
}

static int
Controller_set_tes_diams(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_CspSubcomponent_Controller_tes_diams_mset, self->data_ptr);
}

static PyObject *
Controller_get_tes_lengths(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_CspSubcomponent_Controller_tes_lengths_mget, self->data_ptr);
}

static int
Controller_set_tes_lengths(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_CspSubcomponent_Controller_tes_lengths_mset, self->data_ptr);
}

static PyObject *
Controller_get_tes_pump_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspSubcomponent_Controller_tes_pump_coef_nget, self->data_ptr);
}

static int
Controller_set_tes_pump_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspSubcomponent_Controller_tes_pump_coef_nset, self->data_ptr);
}

static PyObject *
Controller_get_tes_wallthicks(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_CspSubcomponent_Controller_tes_wallthicks_mget, self->data_ptr);
}

static int
Controller_set_tes_wallthicks(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_CspSubcomponent_Controller_tes_wallthicks_mset, self->data_ptr);
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
{"tanks_in_parallel", (getter)Controller_get_tanks_in_parallel,(setter)Controller_set_tanks_in_parallel,
	PyDoc_STR("*float*: Tanks are in parallel, not in series, with solar field [-]\n\n**Required:**\nTrue"),
 	NULL},
{"tes_diams", (getter)Controller_get_tes_diams,(setter)Controller_set_tes_diams,
	PyDoc_STR("*sequence[sequence]*: Custom TES diameters [m]\n\n**Required:**\nTrue"),
 	NULL},
{"tes_lengths", (getter)Controller_get_tes_lengths,(setter)Controller_set_tes_lengths,
	PyDoc_STR("*sequence[sequence]*: Custom TES lengths [m]"),
 	NULL},
{"tes_pump_coef", (getter)Controller_get_tes_pump_coef,(setter)Controller_set_tes_pump_coef,
	PyDoc_STR("*float*: Pumping power to move 1kg of HTF through tes loop [kW/(kg/s)]\n\n**Required:**\nTrue"),
 	NULL},
{"tes_wallthicks", (getter)Controller_get_tes_wallthicks,(setter)Controller_set_tes_wallthicks,
	PyDoc_STR("*sequence[sequence]*: Custom TES wall thicknesses [m]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Controller_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CspSubcomponent.Controller",             /*tp_name*/
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
 * Outputs Group
 */ 

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_CspSubcomponent data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CspSubcomponent", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "CspSubcomponent", "Outputs")){
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
Outputs_get_T_sink_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CspSubcomponent_Outputs_T_sink_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_src_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CspSubcomponent_Outputs_T_src_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tank_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CspSubcomponent_Outputs_T_tank_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tank_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CspSubcomponent_Outputs_T_tank_hot_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"T_sink_in", (getter)Outputs_get_T_sink_in,(setter)0,
	PyDoc_STR("*sequence*: Temperature to heat sink or power block [C]"),
 	NULL},
{"T_src_in", (getter)Outputs_get_T_src_in,(setter)0,
	PyDoc_STR("*sequence*: Temperature to heat source [C]"),
 	NULL},
{"T_tank_cold", (getter)Outputs_get_T_tank_cold,(setter)0,
	PyDoc_STR("*sequence*: Temperature of cold tank (average) [C]"),
 	NULL},
{"T_tank_hot", (getter)Outputs_get_T_tank_hot,(setter)0,
	PyDoc_STR("*sequence*: Temperature of hot tank (average) [C]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CspSubcomponent.Outputs",             /*tp_name*/
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
 * CspSubcomponent
 */

static PyTypeObject CspSubcomponent_Type;

static CmodObject *
newCspSubcomponentObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &CspSubcomponent_Type);

	PySAM_TECH_ATTR()

	PyObject* System_obj = System_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "System", System_obj);
	Py_DECREF(System_obj);

	PyObject* Weather_obj = Weather_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Weather", Weather_obj);
	Py_DECREF(Weather_obj);

	PyObject* TES_obj = TES_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TES", TES_obj);
	Py_DECREF(TES_obj);

	PyObject* SolarField_obj = SolarField_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SolarField", SolarField_obj);
	Py_DECREF(SolarField_obj);

	PyObject* Powerblock_obj = Powerblock_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Powerblock", Powerblock_obj);
	Py_DECREF(Powerblock_obj);

	PyObject* Controller_obj = Controller_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Controller", Controller_obj);
	Py_DECREF(Controller_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* CspSubcomponent methods */

static void
CspSubcomponent_dealloc(CmodObject *self)
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
CspSubcomponent_get_data_ptr(CmodObject *self, PyObject *args)
{
	PyObject* ptr = PyLong_FromVoidPtr((void*)self->data_ptr);
	return ptr;
}


static PyObject *
CspSubcomponent_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_CspSubcomponent_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
CspSubcomponent_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "CspSubcomponent"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
CspSubcomponent_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "CspSubcomponent"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
CspSubcomponent_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
CspSubcomponent_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
CspSubcomponent_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef CspSubcomponent_methods[] = {
		{"execute",           (PyCFunction)CspSubcomponent_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)CspSubcomponent_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'system': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)CspSubcomponent_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'system': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)CspSubcomponent_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)CspSubcomponent_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)CspSubcomponent_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{"get_data_ptr",           (PyCFunction)CspSubcomponent_get_data_ptr,  METH_VARARGS,
				PyDoc_STR("get_data_ptr() -> Pointer\n Get ssc_data_t pointer")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
CspSubcomponent_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
CspSubcomponent_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject CspSubcomponent_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CspSubcomponent",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)CspSubcomponent_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)CspSubcomponent_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)CspSubcomponent_getattro, /*tp_getattro*/
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
		CspSubcomponent_methods,      /*tp_methods*/
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


/* Function of no arguments returning new CspSubcomponent object */

static PyObject *
CspSubcomponent_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newCspSubcomponentObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
CspSubcomponent_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newCspSubcomponentObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
CspSubcomponent_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newCspSubcomponentObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "CspSubcomponent", def) < 0) {
		CspSubcomponent_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
CspSubcomponent_from_existing(PyObject *self, PyObject *args)
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

	rv = newCspSubcomponentObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "CspSubcomponent", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef CspSubcomponentModule_methods[] = {
		{"new",             CspSubcomponent_new,         METH_VARARGS,
				PyDoc_STR("new() -> CspSubcomponent")},
		{"default",             CspSubcomponent_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> CspSubcomponent\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             CspSubcomponent_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> CspSubcomponent\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   CspSubcomponent_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> CspSubcomponent\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "CspSubcomponent");


static int
CspSubcomponentModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	CspSubcomponent_Type.tp_dict = PyDict_New();
	if (!CspSubcomponent_Type.tp_dict) { goto fail; }

	/// Add the System type object to CspSubcomponent_Type
	if (PyType_Ready(&System_Type) < 0) { goto fail; }
	PyDict_SetItemString(CspSubcomponent_Type.tp_dict,
				"System",
				(PyObject*)&System_Type);
	Py_DECREF(&System_Type);

	/// Add the Weather type object to CspSubcomponent_Type
	if (PyType_Ready(&Weather_Type) < 0) { goto fail; }
	PyDict_SetItemString(CspSubcomponent_Type.tp_dict,
				"Weather",
				(PyObject*)&Weather_Type);
	Py_DECREF(&Weather_Type);

	/// Add the TES type object to CspSubcomponent_Type
	if (PyType_Ready(&TES_Type) < 0) { goto fail; }
	PyDict_SetItemString(CspSubcomponent_Type.tp_dict,
				"TES",
				(PyObject*)&TES_Type);
	Py_DECREF(&TES_Type);

	/// Add the SolarField type object to CspSubcomponent_Type
	if (PyType_Ready(&SolarField_Type) < 0) { goto fail; }
	PyDict_SetItemString(CspSubcomponent_Type.tp_dict,
				"SolarField",
				(PyObject*)&SolarField_Type);
	Py_DECREF(&SolarField_Type);

	/// Add the Powerblock type object to CspSubcomponent_Type
	if (PyType_Ready(&Powerblock_Type) < 0) { goto fail; }
	PyDict_SetItemString(CspSubcomponent_Type.tp_dict,
				"Powerblock",
				(PyObject*)&Powerblock_Type);
	Py_DECREF(&Powerblock_Type);

	/// Add the Controller type object to CspSubcomponent_Type
	if (PyType_Ready(&Controller_Type) < 0) { goto fail; }
	PyDict_SetItemString(CspSubcomponent_Type.tp_dict,
				"Controller",
				(PyObject*)&Controller_Type);
	Py_DECREF(&Controller_Type);

	/// Add the Outputs type object to CspSubcomponent_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(CspSubcomponent_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the CspSubcomponent type object to the module
	if (PyType_Ready(&CspSubcomponent_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"CspSubcomponent",
				(PyObject*)&CspSubcomponent_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot CspSubcomponentModule_slots[] = {
		{Py_mod_exec, CspSubcomponentModule_exec},
		{0, NULL},
};

static struct PyModuleDef CspSubcomponentModule = {
		PyModuleDef_HEAD_INIT,
		"CspSubcomponent",
		module_doc,
		0,
		CspSubcomponentModule_methods,
		CspSubcomponentModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_CspSubcomponent(void)
{
	return PyModuleDef_Init(&CspSubcomponentModule);
}