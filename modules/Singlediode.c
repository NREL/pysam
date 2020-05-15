#include <Python.h>

#include <SAM_Singlediode.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * SingleDiodeModel Group
 */ 

static PyTypeObject SingleDiodeModel_Type;

static PyObject *
SingleDiodeModel_new(SAM_Singlediode data_ptr)
{
	PyObject* new_obj = SingleDiodeModel_Type.tp_alloc(&SingleDiodeModel_Type,0);

	VarGroupObject* SingleDiodeModel_obj = (VarGroupObject*)new_obj;

	SingleDiodeModel_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SingleDiodeModel methods */

static PyObject *
SingleDiodeModel_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Singlediode", "SingleDiodeModel")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SingleDiodeModel_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SingleDiodeModel_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SingleDiodeModel_methods[] = {
		{"assign",            (PyCFunction)SingleDiodeModel_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``SingleDiodeModel_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SingleDiodeModel_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SingleDiodeModel_get_Il(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Singlediode_SingleDiodeModel_Il_nget, self->data_ptr);
}

static int
SingleDiodeModel_set_Il(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Singlediode_SingleDiodeModel_Il_nset, self->data_ptr);
}

static PyObject *
SingleDiodeModel_get_Io(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Singlediode_SingleDiodeModel_Io_nget, self->data_ptr);
}

static int
SingleDiodeModel_set_Io(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Singlediode_SingleDiodeModel_Io_nset, self->data_ptr);
}

static PyObject *
SingleDiodeModel_get_Rs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Singlediode_SingleDiodeModel_Rs_nget, self->data_ptr);
}

static int
SingleDiodeModel_set_Rs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Singlediode_SingleDiodeModel_Rs_nset, self->data_ptr);
}

static PyObject *
SingleDiodeModel_get_Rsh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Singlediode_SingleDiodeModel_Rsh_nget, self->data_ptr);
}

static int
SingleDiodeModel_set_Rsh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Singlediode_SingleDiodeModel_Rsh_nset, self->data_ptr);
}

static PyObject *
SingleDiodeModel_get_Vop(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Singlediode_SingleDiodeModel_Vop_nget, self->data_ptr);
}

static int
SingleDiodeModel_set_Vop(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Singlediode_SingleDiodeModel_Vop_nset, self->data_ptr);
}

static PyObject *
SingleDiodeModel_get_a(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Singlediode_SingleDiodeModel_a_nget, self->data_ptr);
}

static int
SingleDiodeModel_set_a(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Singlediode_SingleDiodeModel_a_nset, self->data_ptr);
}

static PyGetSetDef SingleDiodeModel_getset[] = {
{"Il", (getter)SingleDiodeModel_get_Il,(setter)SingleDiodeModel_set_Il,
	PyDoc_STR("*float*: Light current [A]\n\n*Required*: True"),
 	NULL},
{"Io", (getter)SingleDiodeModel_get_Io,(setter)SingleDiodeModel_set_Io,
	PyDoc_STR("*float*: Saturation current [A]\n\n*Required*: True"),
 	NULL},
{"Rs", (getter)SingleDiodeModel_get_Rs,(setter)SingleDiodeModel_set_Rs,
	PyDoc_STR("*float*: Series resistance [ohm]\n\n*Required*: True"),
 	NULL},
{"Rsh", (getter)SingleDiodeModel_get_Rsh,(setter)SingleDiodeModel_set_Rsh,
	PyDoc_STR("*float*: Shunt resistance [ohm]\n\n*Required*: True"),
 	NULL},
{"Vop", (getter)SingleDiodeModel_get_Vop,(setter)SingleDiodeModel_set_Vop,
	PyDoc_STR("*float*: Module operating voltage [V]\n\n*Required*: False"),
 	NULL},
{"a", (getter)SingleDiodeModel_get_a,(setter)SingleDiodeModel_set_a,
	PyDoc_STR("*float*: Modified nonideality factor [1/V]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SingleDiodeModel_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Singlediode.SingleDiodeModel",             /*tp_name*/
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
		SingleDiodeModel_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SingleDiodeModel_getset,          /*tp_getset*/
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
Outputs_new(SAM_Singlediode data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Singlediode", "Outputs")){
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
Outputs_get_I(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Singlediode_Outputs_I_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Isc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Singlediode_Outputs_Isc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_V(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Singlediode_Outputs_V_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Voc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Singlediode_Outputs_Voc_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"I", (getter)Outputs_get_I,(setter)0,
	PyDoc_STR("*float*: Output current [A]"),
 	NULL},
{"Isc", (getter)Outputs_get_Isc,(setter)0,
	PyDoc_STR("*float*: Short circuit current [A]"),
 	NULL},
{"V", (getter)Outputs_get_V,(setter)0,
	PyDoc_STR("*float*: Output voltage [V]"),
 	NULL},
{"Voc", (getter)Outputs_get_Voc,(setter)0,
	PyDoc_STR("*float*: Open circuit voltage [V]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Singlediode.Outputs",             /*tp_name*/
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
 * Singlediode
 */

static PyTypeObject Singlediode_Type;

static CmodObject *
newSinglediodeObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Singlediode_Type);

	PySAM_TECH_ATTR()

	PyObject* SingleDiodeModel_obj = SingleDiodeModel_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SingleDiodeModel", SingleDiodeModel_obj);
	Py_DECREF(SingleDiodeModel_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Singlediode methods */

static void
Singlediode_dealloc(CmodObject *self)
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
Singlediode_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Singlediode_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Singlediode_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Singlediode"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Singlediode_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Singlediode_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef Singlediode_methods[] = {
		{"execute",            (PyCFunction)Singlediode_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Singlediode_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Single Diode Model': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Singlediode_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Singlediode_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Singlediode_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Singlediode_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Singlediode_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Singlediode",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Singlediode_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Singlediode_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Singlediode_getattro, /*tp_getattro*/
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
		Singlediode_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Singlediode object */

static PyObject *
Singlediode_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newSinglediodeObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Singlediode_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSinglediodeObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Singlediode_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSinglediodeObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Singlediode", def);

	return (PyObject *)rv;
}

static PyObject *
Singlediode_from_existing(PyObject *self, PyObject *args)
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

	rv = newSinglediodeObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Singlediode", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef SinglediodeModule_methods[] = {
		{"new",             Singlediode_new,         METH_VARARGS,
				PyDoc_STR("new() -> Singlediode")},
		{"default",             Singlediode_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Singlediode\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             Singlediode_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Singlediode\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   Singlediode_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Singlediode\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Singlediode");


static int
SinglediodeModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Singlediode_Type.tp_dict = PyDict_New();
	if (!Singlediode_Type.tp_dict) { goto fail; }

	/// Add the SingleDiodeModel type object to Singlediode_Type
	if (PyType_Ready(&SingleDiodeModel_Type) < 0) { goto fail; }
	PyDict_SetItemString(Singlediode_Type.tp_dict,
				"SingleDiodeModel",
				(PyObject*)&SingleDiodeModel_Type);
	Py_DECREF(&SingleDiodeModel_Type);

	/// Add the Outputs type object to Singlediode_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Singlediode_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Singlediode type object to the module
	if (PyType_Ready(&Singlediode_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Singlediode",
				(PyObject*)&Singlediode_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot SinglediodeModule_slots[] = {
		{Py_mod_exec, SinglediodeModule_exec},
		{0, NULL},
};

static struct PyModuleDef SinglediodeModule = {
		PyModuleDef_HEAD_INIT,
		"Singlediode",
		module_doc,
		0,
		SinglediodeModule_methods,
		SinglediodeModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Singlediode(void)
{
	return PyModuleDef_Init(&SinglediodeModule);
}