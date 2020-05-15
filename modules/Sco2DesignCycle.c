#include <Python.h>

#include <SAM_Sco2DesignCycle.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * SCO2PowerCycle Group
 */ 

static PyTypeObject SCO2PowerCycle_Type;

static PyObject *
SCO2PowerCycle_new(SAM_Sco2DesignCycle data_ptr)
{
	PyObject* new_obj = SCO2PowerCycle_Type.tp_alloc(&SCO2PowerCycle_Type,0);

	VarGroupObject* SCO2PowerCycle_obj = (VarGroupObject*)new_obj;

	SCO2PowerCycle_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SCO2PowerCycle methods */

static PyObject *
SCO2PowerCycle_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Sco2DesignCycle", "SCO2PowerCycle")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SCO2PowerCycle_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SCO2PowerCycle_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SCO2PowerCycle_methods[] = {
		{"assign",            (PyCFunction)SCO2PowerCycle_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``SCO2PowerCycle_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SCO2PowerCycle_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SCO2PowerCycle_get_I_N_t_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignCycle_SCO2PowerCycle_I_N_t_des_nget, self->data_ptr);
}

static int
SCO2PowerCycle_set_I_N_t_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignCycle_SCO2PowerCycle_I_N_t_des_nset, self->data_ptr);
}

static PyObject *
SCO2PowerCycle_get_I_P_high_limit(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignCycle_SCO2PowerCycle_I_P_high_limit_nget, self->data_ptr);
}

static int
SCO2PowerCycle_set_I_P_high_limit(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignCycle_SCO2PowerCycle_I_P_high_limit_nset, self->data_ptr);
}

static PyObject *
SCO2PowerCycle_get_I_T_mc_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignCycle_SCO2PowerCycle_I_T_mc_in_des_nget, self->data_ptr);
}

static int
SCO2PowerCycle_set_I_T_mc_in_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignCycle_SCO2PowerCycle_I_T_mc_in_des_nset, self->data_ptr);
}

static PyObject *
SCO2PowerCycle_get_I_T_t_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignCycle_SCO2PowerCycle_I_T_t_in_des_nget, self->data_ptr);
}

static int
SCO2PowerCycle_set_I_T_t_in_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignCycle_SCO2PowerCycle_I_T_t_in_des_nset, self->data_ptr);
}

static PyObject *
SCO2PowerCycle_get_I_UA_total_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignCycle_SCO2PowerCycle_I_UA_total_des_nget, self->data_ptr);
}

static int
SCO2PowerCycle_set_I_UA_total_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignCycle_SCO2PowerCycle_I_UA_total_des_nset, self->data_ptr);
}

static PyObject *
SCO2PowerCycle_get_I_W_dot_net_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignCycle_SCO2PowerCycle_I_W_dot_net_des_nget, self->data_ptr);
}

static int
SCO2PowerCycle_set_I_W_dot_net_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignCycle_SCO2PowerCycle_I_W_dot_net_des_nset, self->data_ptr);
}

static PyObject *
SCO2PowerCycle_get_I_eta_mc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignCycle_SCO2PowerCycle_I_eta_mc_nget, self->data_ptr);
}

static int
SCO2PowerCycle_set_I_eta_mc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignCycle_SCO2PowerCycle_I_eta_mc_nset, self->data_ptr);
}

static PyObject *
SCO2PowerCycle_get_I_eta_rc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignCycle_SCO2PowerCycle_I_eta_rc_nget, self->data_ptr);
}

static int
SCO2PowerCycle_set_I_eta_rc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignCycle_SCO2PowerCycle_I_eta_rc_nset, self->data_ptr);
}

static PyObject *
SCO2PowerCycle_get_I_eta_t(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignCycle_SCO2PowerCycle_I_eta_t_nget, self->data_ptr);
}

static int
SCO2PowerCycle_set_I_eta_t(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignCycle_SCO2PowerCycle_I_eta_t_nset, self->data_ptr);
}

static PyObject *
SCO2PowerCycle_get_I_opt_tol(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignCycle_SCO2PowerCycle_I_opt_tol_nget, self->data_ptr);
}

static int
SCO2PowerCycle_set_I_opt_tol(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignCycle_SCO2PowerCycle_I_opt_tol_nset, self->data_ptr);
}

static PyObject *
SCO2PowerCycle_get_I_tol(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignCycle_SCO2PowerCycle_I_tol_nget, self->data_ptr);
}

static int
SCO2PowerCycle_set_I_tol(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2DesignCycle_SCO2PowerCycle_I_tol_nset, self->data_ptr);
}

static PyGetSetDef SCO2PowerCycle_getset[] = {
{"I_N_t_des", (getter)SCO2PowerCycle_get_I_N_t_des,(setter)SCO2PowerCycle_set_I_N_t_des,
	PyDoc_STR("*float*: Design turbine speed, negative links to comp. [rpm]\n\n*Required*: True"),
 	NULL},
{"I_P_high_limit", (getter)SCO2PowerCycle_get_I_P_high_limit,(setter)SCO2PowerCycle_set_I_P_high_limit,
	PyDoc_STR("*float*: High pressure limit in cycle [MPa]\n\n*Required*: True"),
 	NULL},
{"I_T_mc_in_des", (getter)SCO2PowerCycle_get_I_T_mc_in_des,(setter)SCO2PowerCycle_set_I_T_mc_in_des,
	PyDoc_STR("*float*: Main compressor inlet temp at design [C]\n\n*Required*: True"),
 	NULL},
{"I_T_t_in_des", (getter)SCO2PowerCycle_get_I_T_t_in_des,(setter)SCO2PowerCycle_set_I_T_t_in_des,
	PyDoc_STR("*float*: Turbine inlet temp at design [C]\n\n*Required*: True"),
 	NULL},
{"I_UA_total_des", (getter)SCO2PowerCycle_get_I_UA_total_des,(setter)SCO2PowerCycle_set_I_UA_total_des,
	PyDoc_STR("*float*: Total UA allocatable to recuperators [kW/K]\n\n*Required*: True"),
 	NULL},
{"I_W_dot_net_des", (getter)SCO2PowerCycle_get_I_W_dot_net_des,(setter)SCO2PowerCycle_set_I_W_dot_net_des,
	PyDoc_STR("*float*: Design cycle power output [MW]\n\n*Required*: True"),
 	NULL},
{"I_eta_mc", (getter)SCO2PowerCycle_get_I_eta_mc,(setter)SCO2PowerCycle_set_I_eta_mc,
	PyDoc_STR("*float*: Design main compressor isentropic efficiency [-]\n\n*Required*: True"),
 	NULL},
{"I_eta_rc", (getter)SCO2PowerCycle_get_I_eta_rc,(setter)SCO2PowerCycle_set_I_eta_rc,
	PyDoc_STR("*float*: Design re-compressor isentropic efficiency [-]\n\n*Required*: True"),
 	NULL},
{"I_eta_t", (getter)SCO2PowerCycle_get_I_eta_t,(setter)SCO2PowerCycle_set_I_eta_t,
	PyDoc_STR("*float*: Design turbine isentropic efficiency [-]\n\n*Required*: True"),
 	NULL},
{"I_opt_tol", (getter)SCO2PowerCycle_get_I_opt_tol,(setter)SCO2PowerCycle_set_I_opt_tol,
	PyDoc_STR("*float*: Convergence tolerance - optimization calcs [-]\n\n*Required*: True"),
 	NULL},
{"I_tol", (getter)SCO2PowerCycle_get_I_tol,(setter)SCO2PowerCycle_set_I_tol,
	PyDoc_STR("*float*: Convergence tolerance for performance calcs [-]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SCO2PowerCycle_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Sco2DesignCycle.SCO2PowerCycle",             /*tp_name*/
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
		SCO2PowerCycle_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SCO2PowerCycle_getset,          /*tp_getset*/
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
Outputs_new(SAM_Sco2DesignCycle data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Sco2DesignCycle", "Outputs")){
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
Outputs_get_O_LT_frac_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignCycle_Outputs_O_LT_frac_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_O_N_mc_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignCycle_Outputs_O_N_mc_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_O_PR_mc_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignCycle_Outputs_O_PR_mc_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_O_P_mc_out_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignCycle_Outputs_O_P_mc_out_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_O_T_array_des(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2DesignCycle_Outputs_O_T_array_des_aget, self->data_ptr);
}

static PyObject *
Outputs_get_O_eta_thermal_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignCycle_Outputs_O_eta_thermal_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_O_m_dot_PHX(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignCycle_Outputs_O_m_dot_PHX_nget, self->data_ptr);
}

static PyObject *
Outputs_get_O_recomp_frac_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2DesignCycle_Outputs_O_recomp_frac_des_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"O_LT_frac_des", (getter)Outputs_get_O_LT_frac_des,(setter)0,
	PyDoc_STR("*float*: Optimized design point UA distribution [-]"),
 	NULL},
{"O_N_mc_des", (getter)Outputs_get_O_N_mc_des,(setter)0,
	PyDoc_STR("*float*: Design point compressor shaft speed [rpm]"),
 	NULL},
{"O_PR_mc_des", (getter)Outputs_get_O_PR_mc_des,(setter)0,
	PyDoc_STR("*float*: Optimized Pressure Ratio across main compressor"),
 	NULL},
{"O_P_mc_out_des", (getter)Outputs_get_O_P_mc_out_des,(setter)0,
	PyDoc_STR("*float*: Optimized design point high side pressure [MPa]"),
 	NULL},
{"O_T_array_des", (getter)Outputs_get_O_T_array_des,(setter)0,
	PyDoc_STR("*sequence*: Cycle temp state points at design [K]"),
 	NULL},
{"O_eta_thermal_des", (getter)Outputs_get_O_eta_thermal_des,(setter)0,
	PyDoc_STR("*float*: Design cycle thermal efficiency [-]"),
 	NULL},
{"O_m_dot_PHX", (getter)Outputs_get_O_m_dot_PHX,(setter)0,
	PyDoc_STR("*float*: Mass flow rate through primary HX [kg/s]"),
 	NULL},
{"O_recomp_frac_des", (getter)Outputs_get_O_recomp_frac_des,(setter)0,
	PyDoc_STR("*float*: Optimized recompression fraction [-]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Sco2DesignCycle.Outputs",             /*tp_name*/
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
 * Sco2DesignCycle
 */

static PyTypeObject Sco2DesignCycle_Type;

static CmodObject *
newSco2DesignCycleObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Sco2DesignCycle_Type);

	PySAM_TECH_ATTR()

	PyObject* SCO2PowerCycle_obj = SCO2PowerCycle_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SCO2PowerCycle", SCO2PowerCycle_obj);
	Py_DECREF(SCO2PowerCycle_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Sco2DesignCycle methods */

static void
Sco2DesignCycle_dealloc(CmodObject *self)
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
Sco2DesignCycle_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Sco2DesignCycle_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Sco2DesignCycle_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Sco2DesignCycle"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Sco2DesignCycle_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Sco2DesignCycle_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef Sco2DesignCycle_methods[] = {
		{"execute",            (PyCFunction)Sco2DesignCycle_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Sco2DesignCycle_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'sCO2 power cycle': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Sco2DesignCycle_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Sco2DesignCycle_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Sco2DesignCycle_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Sco2DesignCycle_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Sco2DesignCycle_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Sco2DesignCycle",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Sco2DesignCycle_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Sco2DesignCycle_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Sco2DesignCycle_getattro, /*tp_getattro*/
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
		Sco2DesignCycle_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Sco2DesignCycle object */

static PyObject *
Sco2DesignCycle_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newSco2DesignCycleObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Sco2DesignCycle_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSco2DesignCycleObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Sco2DesignCycle_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSco2DesignCycleObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Sco2DesignCycle", def);

	return (PyObject *)rv;
}

static PyObject *
Sco2DesignCycle_from_existing(PyObject *self, PyObject *args)
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

	rv = newSco2DesignCycleObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Sco2DesignCycle", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Sco2DesignCycleModule_methods[] = {
		{"new",             Sco2DesignCycle_new,         METH_VARARGS,
				PyDoc_STR("new() -> Sco2DesignCycle")},
		{"default",             Sco2DesignCycle_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Sco2DesignCycle\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             Sco2DesignCycle_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Sco2DesignCycle\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   Sco2DesignCycle_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Sco2DesignCycle\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Supercritical CO2 Power Cycle Design");


static int
Sco2DesignCycleModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Sco2DesignCycle_Type.tp_dict = PyDict_New();
	if (!Sco2DesignCycle_Type.tp_dict) { goto fail; }

	/// Add the SCO2PowerCycle type object to Sco2DesignCycle_Type
	if (PyType_Ready(&SCO2PowerCycle_Type) < 0) { goto fail; }
	PyDict_SetItemString(Sco2DesignCycle_Type.tp_dict,
				"SCO2PowerCycle",
				(PyObject*)&SCO2PowerCycle_Type);
	Py_DECREF(&SCO2PowerCycle_Type);

	/// Add the Outputs type object to Sco2DesignCycle_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Sco2DesignCycle_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Sco2DesignCycle type object to the module
	if (PyType_Ready(&Sco2DesignCycle_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Sco2DesignCycle",
				(PyObject*)&Sco2DesignCycle_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Sco2DesignCycleModule_slots[] = {
		{Py_mod_exec, Sco2DesignCycleModule_exec},
		{0, NULL},
};

static struct PyModuleDef Sco2DesignCycleModule = {
		PyModuleDef_HEAD_INIT,
		"Sco2DesignCycle",
		module_doc,
		0,
		Sco2DesignCycleModule_methods,
		Sco2DesignCycleModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Sco2DesignCycle(void)
{
	return PyModuleDef_Init(&Sco2DesignCycleModule);
}