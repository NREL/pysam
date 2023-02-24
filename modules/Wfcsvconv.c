#include <Python.h>

#include <SAM_Wfcsvconv.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * WeatherFileConverter Group
 */ 

static PyTypeObject WeatherFileConverter_Type;

static PyObject *
WeatherFileConverter_new(SAM_Wfcsvconv data_ptr)
{
	PyObject* new_obj = WeatherFileConverter_Type.tp_alloc(&WeatherFileConverter_Type,0);

	VarGroupObject* WeatherFileConverter_obj = (VarGroupObject*)new_obj;

	WeatherFileConverter_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* WeatherFileConverter methods */

static PyObject *
WeatherFileConverter_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Wfcsvconv", "WeatherFileConverter")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
WeatherFileConverter_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &WeatherFileConverter_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Wfcsvconv", "WeatherFileConverter")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
WeatherFileConverter_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &WeatherFileConverter_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef WeatherFileConverter_methods[] = {
		{"assign",            (PyCFunction)WeatherFileConverter_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``WeatherFileConverter_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)WeatherFileConverter_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``WeatherFileConverter_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)WeatherFileConverter_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
WeatherFileConverter_get_input_file(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Wfcsvconv_WeatherFileConverter_input_file_sget, self->data_ptr);
}

static int
WeatherFileConverter_set_input_file(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Wfcsvconv_WeatherFileConverter_input_file_sset, self->data_ptr);
}

static PyObject *
WeatherFileConverter_get_output_file(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Wfcsvconv_WeatherFileConverter_output_file_sget, self->data_ptr);
}

static int
WeatherFileConverter_set_output_file(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Wfcsvconv_WeatherFileConverter_output_file_sset, self->data_ptr);
}

static PyObject *
WeatherFileConverter_get_output_filename_format(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Wfcsvconv_WeatherFileConverter_output_filename_format_sget, self->data_ptr);
}

static int
WeatherFileConverter_set_output_filename_format(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Wfcsvconv_WeatherFileConverter_output_filename_format_sset, self->data_ptr);
}

static PyObject *
WeatherFileConverter_get_output_folder(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Wfcsvconv_WeatherFileConverter_output_folder_sget, self->data_ptr);
}

static int
WeatherFileConverter_set_output_folder(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Wfcsvconv_WeatherFileConverter_output_folder_sset, self->data_ptr);
}

static PyGetSetDef WeatherFileConverter_getset[] = {
{"input_file", (getter)WeatherFileConverter_get_input_file,(setter)WeatherFileConverter_set_input_file,
	PyDoc_STR("*str*: Input weather file name\n\n**Info:**\ntmy2,tmy3,intl,epw,smw\n\n**Required:**\nTrue"),
 	NULL},
{"output_file", (getter)WeatherFileConverter_get_output_file,(setter)WeatherFileConverter_set_output_file,
	PyDoc_STR("*str*: Output file name\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"output_filename_format", (getter)WeatherFileConverter_get_output_filename_format,(setter)WeatherFileConverter_set_output_filename_format,
	PyDoc_STR("*str*: Output file name format\n\n**Info:**\nrecognizes $city $state $country $type $loc\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"output_folder", (getter)WeatherFileConverter_get_output_folder,(setter)WeatherFileConverter_set_output_folder,
	PyDoc_STR("*str*: Output folder\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject WeatherFileConverter_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Wfcsvconv.WeatherFileConverter",             /*tp_name*/
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
		WeatherFileConverter_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		WeatherFileConverter_getset,          /*tp_getset*/
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
 * Wfcsvconv
 */

static PyTypeObject Wfcsvconv_Type;

static CmodObject *
newWfcsvconvObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Wfcsvconv_Type);

	PySAM_TECH_ATTR()

	PyObject* WeatherFileConverter_obj = WeatherFileConverter_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "WeatherFileConverter", WeatherFileConverter_obj);
	Py_DECREF(WeatherFileConverter_obj);

	return self;
}

/* Wfcsvconv methods */

static void
Wfcsvconv_dealloc(CmodObject *self)
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
Wfcsvconv_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Wfcsvconv_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Wfcsvconv_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Wfcsvconv"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Wfcsvconv_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Wfcsvconv"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Wfcsvconv_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Wfcsvconv_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Wfcsvconv_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Wfcsvconv_methods[] = {
		{"execute",           (PyCFunction)Wfcsvconv_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Wfcsvconv_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Weather File Converter': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Wfcsvconv_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Weather File Converter': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Wfcsvconv_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Wfcsvconv_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Wfcsvconv_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Wfcsvconv_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Wfcsvconv_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Wfcsvconv_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Wfcsvconv",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Wfcsvconv_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Wfcsvconv_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Wfcsvconv_getattro, /*tp_getattro*/
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
		Wfcsvconv_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Wfcsvconv object */

static PyObject *
Wfcsvconv_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newWfcsvconvObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Wfcsvconv_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWfcsvconvObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Wfcsvconv_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWfcsvconvObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Wfcsvconv", def) < 0) {
		Wfcsvconv_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Wfcsvconv_from_existing(PyObject *self, PyObject *args)
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

	rv = newWfcsvconvObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Wfcsvconv", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef WfcsvconvModule_methods[] = {
		{"new",             Wfcsvconv_new,         METH_VARARGS,
				PyDoc_STR("new() -> Wfcsvconv")},
		{"default",             Wfcsvconv_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Wfcsvconv\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Wfcsvconv_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Wfcsvconv\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Wfcsvconv_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Wfcsvconv\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Wfcsvconv");


static int
WfcsvconvModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Wfcsvconv_Type.tp_dict = PyDict_New();
	if (!Wfcsvconv_Type.tp_dict) { goto fail; }

	/// Add the WeatherFileConverter type object to Wfcsvconv_Type
	if (PyType_Ready(&WeatherFileConverter_Type) < 0) { goto fail; }
	PyDict_SetItemString(Wfcsvconv_Type.tp_dict,
				"WeatherFileConverter",
				(PyObject*)&WeatherFileConverter_Type);
	Py_DECREF(&WeatherFileConverter_Type);

	/// Add the Wfcsvconv type object to the module
	if (PyType_Ready(&Wfcsvconv_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Wfcsvconv",
				(PyObject*)&Wfcsvconv_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot WfcsvconvModule_slots[] = {
		{Py_mod_exec, WfcsvconvModule_exec},
		{0, NULL},
};

static struct PyModuleDef WfcsvconvModule = {
		PyModuleDef_HEAD_INIT,
		"Wfcsvconv",
		module_doc,
		0,
		WfcsvconvModule_methods,
		WfcsvconvModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Wfcsvconv(void)
{
	return PyModuleDef_Init(&WfcsvconvModule);
}