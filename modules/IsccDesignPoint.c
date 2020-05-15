#include <Python.h>

#include <SAM_IsccDesignPoint.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Common Group
 */ 

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_IsccDesignPoint data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "IsccDesignPoint", "Common")){
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
Common_get_HTF_code(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_IsccDesignPoint_Common_HTF_code_nget, self->data_ptr);
}

static int
Common_set_HTF_code(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_IsccDesignPoint_Common_HTF_code_nset, self->data_ptr);
}

static PyObject *
Common_get_elev(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_IsccDesignPoint_Common_elev_nget, self->data_ptr);
}

static int
Common_set_elev(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_IsccDesignPoint_Common_elev_nset, self->data_ptr);
}

static PyObject *
Common_get_field_fl_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_IsccDesignPoint_Common_field_fl_props_mget, self->data_ptr);
}

static int
Common_set_field_fl_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_IsccDesignPoint_Common_field_fl_props_mset, self->data_ptr);
}

static PyObject *
Common_get_ngcc_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_IsccDesignPoint_Common_ngcc_model_nget, self->data_ptr);
}

static int
Common_set_ngcc_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_IsccDesignPoint_Common_ngcc_model_nset, self->data_ptr);
}

static PyObject *
Common_get_pinch_point_cold(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_IsccDesignPoint_Common_pinch_point_cold_nget, self->data_ptr);
}

static int
Common_set_pinch_point_cold(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_IsccDesignPoint_Common_pinch_point_cold_nset, self->data_ptr);
}

static PyObject *
Common_get_pinch_point_hot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_IsccDesignPoint_Common_pinch_point_hot_nget, self->data_ptr);
}

static int
Common_set_pinch_point_hot(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_IsccDesignPoint_Common_pinch_point_hot_nset, self->data_ptr);
}

static PyObject *
Common_get_q_pb_design(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_IsccDesignPoint_Common_q_pb_design_nget, self->data_ptr);
}

static int
Common_set_q_pb_design(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_IsccDesignPoint_Common_q_pb_design_nset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"HTF_code", (getter)Common_get_HTF_code,(setter)Common_set_HTF_code,
	PyDoc_STR("*float*: HTF fluid code [-]\n\n*Required*: True"),
 	NULL},
{"elev", (getter)Common_get_elev,(setter)Common_set_elev,
	PyDoc_STR("*float*: Plant elevation [m]\n\n*Required*: True"),
 	NULL},
{"field_fl_props", (getter)Common_get_field_fl_props,(setter)Common_set_field_fl_props,
	PyDoc_STR("*sequence[sequence]*: User defined field fluid property data [-]\n\n*Info*: 7 columns (T,Cp,dens,visc,kvisc,cond,h), at least 3 rows\n\n*Required*: True"),
 	NULL},
{"ngcc_model", (getter)Common_get_ngcc_model,(setter)Common_set_ngcc_model,
	PyDoc_STR("*float*: 1: NREL, 2: GE\n\n*Required*: True"),
 	NULL},
{"pinch_point_cold", (getter)Common_get_pinch_point_cold,(setter)Common_set_pinch_point_cold,
	PyDoc_STR("*float*: Cold side pinch point [C]\n\n*Required*: True"),
 	NULL},
{"pinch_point_hot", (getter)Common_get_pinch_point_hot,(setter)Common_set_pinch_point_hot,
	PyDoc_STR("*float*: Hot side pinch point [C]\n\n*Required*: True"),
 	NULL},
{"q_pb_design", (getter)Common_get_q_pb_design,(setter)Common_set_q_pb_design,
	PyDoc_STR("*float*: Design point power block thermal power [MWt]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"IsccDesignPoint.Common",             /*tp_name*/
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
Outputs_new(SAM_IsccDesignPoint data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "IsccDesignPoint", "Outputs")){
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
Outputs_get_T_htf_cold(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_IsccDesignPoint_Outputs_T_htf_cold_nget, self->data_ptr);
}

static PyObject *
Outputs_get_T_st_inject(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_IsccDesignPoint_Outputs_T_st_inject_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_fossil(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_IsccDesignPoint_Outputs_W_dot_fossil_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_solar(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_IsccDesignPoint_Outputs_W_dot_solar_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_solar_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_IsccDesignPoint_Outputs_q_solar_max_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"T_htf_cold", (getter)Outputs_get_T_htf_cold,(setter)0,
	PyDoc_STR("*float*: HTF return temp from HRSG [C]"),
 	NULL},
{"T_st_inject", (getter)Outputs_get_T_st_inject,(setter)0,
	PyDoc_STR("*float*: Steam injection temp into HRSG [C]"),
 	NULL},
{"W_dot_fossil", (getter)Outputs_get_W_dot_fossil,(setter)0,
	PyDoc_STR("*float*: Electric output with no solar contribution [MWe]"),
 	NULL},
{"W_dot_solar", (getter)Outputs_get_W_dot_solar,(setter)0,
	PyDoc_STR("*float*: Solar contribution to hybrid output [MWe]"),
 	NULL},
{"q_solar_max", (getter)Outputs_get_q_solar_max,(setter)0,
	PyDoc_STR("*float*: Max. solar thermal input at design [MWt]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"IsccDesignPoint.Outputs",             /*tp_name*/
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
 * IsccDesignPoint
 */

static PyTypeObject IsccDesignPoint_Type;

static CmodObject *
newIsccDesignPointObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &IsccDesignPoint_Type);

	PySAM_TECH_ATTR()

	PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* IsccDesignPoint methods */

static void
IsccDesignPoint_dealloc(CmodObject *self)
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
IsccDesignPoint_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_IsccDesignPoint_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
IsccDesignPoint_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "IsccDesignPoint"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
IsccDesignPoint_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
IsccDesignPoint_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef IsccDesignPoint_methods[] = {
		{"execute",            (PyCFunction)IsccDesignPoint_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)IsccDesignPoint_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Common': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)IsccDesignPoint_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)IsccDesignPoint_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
IsccDesignPoint_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
IsccDesignPoint_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject IsccDesignPoint_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"IsccDesignPoint",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)IsccDesignPoint_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)IsccDesignPoint_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)IsccDesignPoint_getattro, /*tp_getattro*/
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
		IsccDesignPoint_methods,      /*tp_methods*/
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


/* Function of no arguments returning new IsccDesignPoint object */

static PyObject *
IsccDesignPoint_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newIsccDesignPointObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
IsccDesignPoint_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newIsccDesignPointObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
IsccDesignPoint_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newIsccDesignPointObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "IsccDesignPoint", def);

	return (PyObject *)rv;
}

static PyObject *
IsccDesignPoint_from_existing(PyObject *self, PyObject *args)
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

	rv = newIsccDesignPointObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "IsccDesignPoint", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef IsccDesignPointModule_methods[] = {
		{"new",             IsccDesignPoint_new,         METH_VARARGS,
				PyDoc_STR("new() -> IsccDesignPoint")},
		{"default",             IsccDesignPoint_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> IsccDesignPoint\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             IsccDesignPoint_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> IsccDesignPoint\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   IsccDesignPoint_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> IsccDesignPoint\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "IsccDesignPoint");


static int
IsccDesignPointModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	IsccDesignPoint_Type.tp_dict = PyDict_New();
	if (!IsccDesignPoint_Type.tp_dict) { goto fail; }

	/// Add the Common type object to IsccDesignPoint_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(IsccDesignPoint_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the Outputs type object to IsccDesignPoint_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(IsccDesignPoint_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the IsccDesignPoint type object to the module
	if (PyType_Ready(&IsccDesignPoint_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"IsccDesignPoint",
				(PyObject*)&IsccDesignPoint_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot IsccDesignPointModule_slots[] = {
		{Py_mod_exec, IsccDesignPointModule_exec},
		{0, NULL},
};

static struct PyModuleDef IsccDesignPointModule = {
		PyModuleDef_HEAD_INIT,
		"IsccDesignPoint",
		module_doc,
		0,
		IsccDesignPointModule_methods,
		IsccDesignPointModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_IsccDesignPoint(void)
{
	return PyModuleDef_Init(&IsccDesignPointModule);
}