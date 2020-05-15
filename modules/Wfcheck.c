#include <Python.h>

#include <SAM_Wfcheck.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * WeatherFileChecker Group
 */ 

static PyTypeObject WeatherFileChecker_Type;

static PyObject *
WeatherFileChecker_new(SAM_Wfcheck data_ptr)
{
	PyObject* new_obj = WeatherFileChecker_Type.tp_alloc(&WeatherFileChecker_Type,0);

	VarGroupObject* WeatherFileChecker_obj = (VarGroupObject*)new_obj;

	WeatherFileChecker_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* WeatherFileChecker methods */

static PyObject *
WeatherFileChecker_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Wfcheck", "WeatherFileChecker")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
WeatherFileChecker_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &WeatherFileChecker_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef WeatherFileChecker_methods[] = {
		{"assign",            (PyCFunction)WeatherFileChecker_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``WeatherFileChecker_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)WeatherFileChecker_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
WeatherFileChecker_get_input_file(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Wfcheck_WeatherFileChecker_input_file_sget, self->data_ptr);
}

static int
WeatherFileChecker_set_input_file(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Wfcheck_WeatherFileChecker_input_file_sset, self->data_ptr);
}

static PyGetSetDef WeatherFileChecker_getset[] = {
{"input_file", (getter)WeatherFileChecker_get_input_file,(setter)WeatherFileChecker_set_input_file,
	PyDoc_STR("*str*: Input weather file name\n\n*Info*: wfcsv format\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject WeatherFileChecker_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Wfcheck.WeatherFileChecker",             /*tp_name*/
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
		WeatherFileChecker_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		WeatherFileChecker_getset,          /*tp_getset*/
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
 * Wfcheck
 */

static PyTypeObject Wfcheck_Type;

static CmodObject *
newWfcheckObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Wfcheck_Type);

	PySAM_TECH_ATTR()

	PyObject* WeatherFileChecker_obj = WeatherFileChecker_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "WeatherFileChecker", WeatherFileChecker_obj);
	Py_DECREF(WeatherFileChecker_obj);

	return self;
}

/* Wfcheck methods */

static void
Wfcheck_dealloc(CmodObject *self)
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
Wfcheck_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Wfcheck_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Wfcheck_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Wfcheck"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Wfcheck_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Wfcheck_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef Wfcheck_methods[] = {
		{"execute",            (PyCFunction)Wfcheck_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Wfcheck_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Weather File Checker': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Wfcheck_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Wfcheck_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Wfcheck_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Wfcheck_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Wfcheck_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Wfcheck",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Wfcheck_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Wfcheck_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Wfcheck_getattro, /*tp_getattro*/
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
		Wfcheck_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Wfcheck object */

static PyObject *
Wfcheck_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newWfcheckObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Wfcheck_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWfcheckObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Wfcheck_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWfcheckObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Wfcheck", def);

	return (PyObject *)rv;
}

static PyObject *
Wfcheck_from_existing(PyObject *self, PyObject *args)
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

	rv = newWfcheckObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Wfcheck", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef WfcheckModule_methods[] = {
		{"new",             Wfcheck_new,         METH_VARARGS,
				PyDoc_STR("new() -> Wfcheck")},
		{"default",             Wfcheck_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Wfcheck\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             Wfcheck_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Wfcheck\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   Wfcheck_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Wfcheck\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Wfcheck");


static int
WfcheckModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Wfcheck_Type.tp_dict = PyDict_New();
	if (!Wfcheck_Type.tp_dict) { goto fail; }

	/// Add the WeatherFileChecker type object to Wfcheck_Type
	if (PyType_Ready(&WeatherFileChecker_Type) < 0) { goto fail; }
	PyDict_SetItemString(Wfcheck_Type.tp_dict,
				"WeatherFileChecker",
				(PyObject*)&WeatherFileChecker_Type);
	Py_DECREF(&WeatherFileChecker_Type);

	/// Add the Wfcheck type object to the module
	if (PyType_Ready(&Wfcheck_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Wfcheck",
				(PyObject*)&Wfcheck_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot WfcheckModule_slots[] = {
		{Py_mod_exec, WfcheckModule_exec},
		{0, NULL},
};

static struct PyModuleDef WfcheckModule = {
		PyModuleDef_HEAD_INIT,
		"Wfcheck",
		module_doc,
		0,
		WfcheckModule_methods,
		WfcheckModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Wfcheck(void)
{
	return PyModuleDef_Init(&WfcheckModule);
}