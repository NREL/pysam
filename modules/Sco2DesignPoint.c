#include <Python.h>

#include <SAM_Sco2DesignPoint.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Common Group
 */ 

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_Sco2DesignPoint data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Sco2DesignPoint", "Common")){
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
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Common_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Common_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Common_get_P_high_limit(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignPoint_Common_P_high_limit_nget, self->data_ptr);
}

static int
Common_set_P_high_limit(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignPoint_Common_P_high_limit_nset, self->data_ptr);
}

static PyObject *
Common_get_T_amb_array(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2DesignPoint_Common_T_amb_array_aget, self->data_ptr);
}

static int
Common_set_T_amb_array(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Sco2DesignPoint_Common_T_amb_array_aset, self->data_ptr);
}

static PyObject *
Common_get_T_amb_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignPoint_Common_T_amb_des_nget, self->data_ptr);
}

static int
Common_set_T_amb_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignPoint_Common_T_amb_des_nset, self->data_ptr);
}

static PyObject *
Common_get_T_htf_hot_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignPoint_Common_T_htf_hot_des_nget, self->data_ptr);
}

static int
Common_set_T_htf_hot_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignPoint_Common_T_htf_hot_des_nset, self->data_ptr);
}

static PyObject *
Common_get_W_dot_net_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignPoint_Common_W_dot_net_des_nget, self->data_ptr);
}

static int
Common_set_W_dot_net_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignPoint_Common_W_dot_net_des_nset, self->data_ptr);
}

static PyObject *
Common_get_deltaT_ACC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignPoint_Common_deltaT_ACC_nget, self->data_ptr);
}

static int
Common_set_deltaT_ACC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignPoint_Common_deltaT_ACC_nset, self->data_ptr);
}

static PyObject *
Common_get_deltaT_PHX(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignPoint_Common_deltaT_PHX_nget, self->data_ptr);
}

static int
Common_set_deltaT_PHX(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignPoint_Common_deltaT_PHX_nset, self->data_ptr);
}

static PyObject *
Common_get_eta_c(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignPoint_Common_eta_c_nget, self->data_ptr);
}

static int
Common_set_eta_c(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignPoint_Common_eta_c_nset, self->data_ptr);
}

static PyObject *
Common_get_eta_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignPoint_Common_eta_des_nget, self->data_ptr);
}

static int
Common_set_eta_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignPoint_Common_eta_des_nset, self->data_ptr);
}

static PyObject *
Common_get_eta_t(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignPoint_Common_eta_t_nget, self->data_ptr);
}

static int
Common_set_eta_t(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignPoint_Common_eta_t_nset, self->data_ptr);
}

static PyObject *
Common_get_part_load_fracs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2DesignPoint_Common_part_load_fracs_aget, self->data_ptr);
}

static int
Common_set_part_load_fracs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Sco2DesignPoint_Common_part_load_fracs_aset, self->data_ptr);
}

static PyObject *
Common_get_run_off_des_study(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignPoint_Common_run_off_des_study_nget, self->data_ptr);
}

static int
Common_set_run_off_des_study(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignPoint_Common_run_off_des_study_nset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"P_high_limit", (getter)Common_get_P_high_limit,(setter)Common_set_P_high_limit,
	PyDoc_STR("*float*: High pressure limit in cycle [MPa]\n\n*Required*: True"),
 	NULL},
{"T_amb_array", (getter)Common_get_T_amb_array,(setter)Common_set_T_amb_array,
	PyDoc_STR("*sequence*: Array of ambient temperatures for off-design parametric [C]\n\n*Required*: True if run_off_des_study=1"),
 	NULL},
{"T_amb_des", (getter)Common_get_T_amb_des,(setter)Common_set_T_amb_des,
	PyDoc_STR("*float*: Design: Ambient temperature for air cooler [C]\n\n*Required*: True"),
 	NULL},
{"T_htf_hot_des", (getter)Common_get_T_htf_hot_des,(setter)Common_set_T_htf_hot_des,
	PyDoc_STR("*float*: Tower design outlet temp [C]\n\n*Required*: True"),
 	NULL},
{"W_dot_net_des", (getter)Common_get_W_dot_net_des,(setter)Common_set_W_dot_net_des,
	PyDoc_STR("*float*: Design cycle power output [MW]\n\n*Required*: True"),
 	NULL},
{"deltaT_ACC", (getter)Common_get_deltaT_ACC,(setter)Common_set_deltaT_ACC,
	PyDoc_STR("*float*: Temp diff btw ambient air and compressor inlet [C]\n\n*Required*: True"),
 	NULL},
{"deltaT_PHX", (getter)Common_get_deltaT_PHX,(setter)Common_set_deltaT_PHX,
	PyDoc_STR("*float*: Temp diff btw hot HTF and turbine inlet [C]\n\n*Required*: True"),
 	NULL},
{"eta_c", (getter)Common_get_eta_c,(setter)Common_set_eta_c,
	PyDoc_STR("*float*: Design compressor(s) isentropic efficiency [-]\n\n*Required*: True"),
 	NULL},
{"eta_des", (getter)Common_get_eta_des,(setter)Common_set_eta_des,
	PyDoc_STR("*float*: Power cycle thermal efficiency\n\n*Required*: True"),
 	NULL},
{"eta_t", (getter)Common_get_eta_t,(setter)Common_set_eta_t,
	PyDoc_STR("*float*: Design turbine isentropic efficiency [-]\n\n*Required*: True"),
 	NULL},
{"part_load_fracs", (getter)Common_get_part_load_fracs,(setter)Common_set_part_load_fracs,
	PyDoc_STR("*sequence*: Array of part load q_dot_in fractions for off-design parametric\n\n*Required*: True if run_off_des_study=1"),
 	NULL},
{"run_off_des_study", (getter)Common_get_run_off_des_study,(setter)Common_set_run_off_des_study,
	PyDoc_STR("*float*: 1 = yes, 0/other = no\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Sco2DesignPoint.Common",             /*tp_name*/
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
 * Outputs Group
 */ 

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Sco2DesignPoint data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Sco2DesignPoint", "Outputs")){
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
Outputs_get_P_comp_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignPoint_Outputs_P_comp_in_nget, self->data_ptr);
}

static PyObject *
Outputs_get_P_comp_out(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignPoint_Outputs_P_comp_out_nget, self->data_ptr);
}

static PyObject *
Outputs_get_T_amb_array_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2DesignPoint_Outputs_T_amb_array_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_amb_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2DesignPoint_Outputs_T_amb_coefs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_amb_eta(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2DesignPoint_Outputs_T_amb_eta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_amb_r_squared(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignPoint_Outputs_T_amb_r_squared_nget, self->data_ptr);
}

static PyObject *
Outputs_get_T_htf_cold(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignPoint_Outputs_T_htf_cold_nget, self->data_ptr);
}

static PyObject *
Outputs_get_UA_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignPoint_Outputs_UA_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_thermal_calc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignPoint_Outputs_eta_thermal_calc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_part_load_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2DesignPoint_Outputs_part_load_coefs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_part_load_eta(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2DesignPoint_Outputs_part_load_eta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_part_load_fracs_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2DesignPoint_Outputs_part_load_fracs_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_part_load_r_squared(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignPoint_Outputs_part_load_r_squared_nget, self->data_ptr);
}

static PyObject *
Outputs_get_recomp_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignPoint_Outputs_recomp_frac_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"P_comp_in", (getter)Outputs_get_P_comp_in,(setter)0,
	PyDoc_STR("*float*: Compressor inlet pressure [MPa]"),
 	NULL},
{"P_comp_out", (getter)Outputs_get_P_comp_out,(setter)0,
	PyDoc_STR("*float*: Compressor outlet pressure [MPa]"),
 	NULL},
{"T_amb_array_out", (getter)Outputs_get_T_amb_array_out,(setter)0,
	PyDoc_STR("*sequence*: Array of ambient temps that SOLVED at off design [C]"),
 	NULL},
{"T_amb_coefs", (getter)Outputs_get_T_amb_coefs,(setter)0,
	PyDoc_STR("*sequence*: Part load polynomial coefficients [-]"),
 	NULL},
{"T_amb_eta", (getter)Outputs_get_T_amb_eta,(setter)0,
	PyDoc_STR("*sequence*: Matrix of ambient temps and power cycle efficiency [-]"),
 	NULL},
{"T_amb_r_squared", (getter)Outputs_get_T_amb_r_squared,(setter)0,
	PyDoc_STR("*float*: T amb curve fit R squared [-]"),
 	NULL},
{"T_htf_cold", (getter)Outputs_get_T_htf_cold,(setter)0,
	PyDoc_STR("*float*: Calculated cold HTF temp [C]"),
 	NULL},
{"UA_total", (getter)Outputs_get_UA_total,(setter)0,
	PyDoc_STR("*float*: Total recuperator UA [kW/K]"),
 	NULL},
{"eta_thermal_calc", (getter)Outputs_get_eta_thermal_calc,(setter)0,
	PyDoc_STR("*float*: Calculated cycle thermal efficiency [-]"),
 	NULL},
{"part_load_coefs", (getter)Outputs_get_part_load_coefs,(setter)0,
	PyDoc_STR("*sequence*: Part load polynomial coefficients [-]"),
 	NULL},
{"part_load_eta", (getter)Outputs_get_part_load_eta,(setter)0,
	PyDoc_STR("*sequence*: Matrix of power cycle efficiency results for q_dot_in part load [-]"),
 	NULL},
{"part_load_fracs_out", (getter)Outputs_get_part_load_fracs_out,(setter)0,
	PyDoc_STR("*sequence*: Array of part load fractions that SOLVED at off design [-]"),
 	NULL},
{"part_load_r_squared", (getter)Outputs_get_part_load_r_squared,(setter)0,
	PyDoc_STR("*float*: Part load curve fit R squared [-]"),
 	NULL},
{"recomp_frac", (getter)Outputs_get_recomp_frac,(setter)0,
	PyDoc_STR("*float*: Recompression fraction [-]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Sco2DesignPoint.Outputs",             /*tp_name*/
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
 * Sco2DesignPoint
 */

static PyTypeObject Sco2DesignPoint_Type;

static CmodObject *
newSco2DesignPointObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Sco2DesignPoint_Type);

	PySAM_TECH_ATTR()

	PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Sco2DesignPoint methods */

static void
Sco2DesignPoint_dealloc(CmodObject *self)
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
Sco2DesignPoint_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Sco2DesignPoint_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Sco2DesignPoint_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Sco2DesignPoint"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Sco2DesignPoint_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Sco2DesignPoint_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef Sco2DesignPoint_methods[] = {
		{"execute",            (PyCFunction)Sco2DesignPoint_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Sco2DesignPoint_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Common': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Sco2DesignPoint_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Sco2DesignPoint_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Sco2DesignPoint_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Sco2DesignPoint_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Sco2DesignPoint_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Sco2DesignPoint",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Sco2DesignPoint_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Sco2DesignPoint_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Sco2DesignPoint_getattro, /*tp_getattro*/
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
		Sco2DesignPoint_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Sco2DesignPoint object */

static PyObject *
Sco2DesignPoint_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newSco2DesignPointObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Sco2DesignPoint_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSco2DesignPointObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Sco2DesignPoint_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSco2DesignPointObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Sco2DesignPoint", def);

	return (PyObject *)rv;
}

static PyObject *
Sco2DesignPoint_from_existing(PyObject *self, PyObject *args)
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

	rv = newSco2DesignPointObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Sco2DesignPoint", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Sco2DesignPointModule_methods[] = {
		{"new",             Sco2DesignPoint_new,         METH_VARARGS,
				PyDoc_STR("new() -> Sco2DesignPoint")},
		{"default",             Sco2DesignPoint_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Sco2DesignPoint\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             Sco2DesignPoint_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Sco2DesignPoint\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   Sco2DesignPoint_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Sco2DesignPoint\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Supercritical CO2 Power Cycle Design Point");


static int
Sco2DesignPointModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Sco2DesignPoint_Type.tp_dict = PyDict_New();
	if (!Sco2DesignPoint_Type.tp_dict) { goto fail; }

	/// Add the Common type object to Sco2DesignPoint_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(Sco2DesignPoint_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the Outputs type object to Sco2DesignPoint_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Sco2DesignPoint_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Sco2DesignPoint type object to the module
	if (PyType_Ready(&Sco2DesignPoint_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Sco2DesignPoint",
				(PyObject*)&Sco2DesignPoint_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Sco2DesignPointModule_slots[] = {
		{Py_mod_exec, Sco2DesignPointModule_exec},
		{0, NULL},
};

static struct PyModuleDef Sco2DesignPointModule = {
		PyModuleDef_HEAD_INIT,
		"Sco2DesignPoint",
		module_doc,
		0,
		Sco2DesignPointModule_methods,
		Sco2DesignPointModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Sco2DesignPoint(void)
{
	return PyModuleDef_Init(&Sco2DesignPointModule);
}