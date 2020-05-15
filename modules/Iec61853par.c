#include <Python.h>

#include <SAM_Iec61853par.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * IEC61853 Group
 */ 

static PyTypeObject IEC61853_Type;

static PyObject *
IEC61853_new(SAM_Iec61853par data_ptr)
{
	PyObject* new_obj = IEC61853_Type.tp_alloc(&IEC61853_Type,0);

	VarGroupObject* IEC61853_obj = (VarGroupObject*)new_obj;

	IEC61853_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* IEC61853 methods */

static PyObject *
IEC61853_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Iec61853par", "IEC61853")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
IEC61853_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &IEC61853_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef IEC61853_methods[] = {
		{"assign",            (PyCFunction)IEC61853_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``IEC61853_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)IEC61853_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
IEC61853_get_input(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Iec61853par_IEC61853_input_mget, self->data_ptr);
}

static int
IEC61853_set_input(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Iec61853par_IEC61853_input_mset, self->data_ptr);
}

static PyObject *
IEC61853_get_nser(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853par_IEC61853_nser_nget, self->data_ptr);
}

static int
IEC61853_set_nser(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Iec61853par_IEC61853_nser_nset, self->data_ptr);
}

static PyObject *
IEC61853_get_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853par_IEC61853_type_nget, self->data_ptr);
}

static int
IEC61853_set_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Iec61853par_IEC61853_type_nset, self->data_ptr);
}

static PyObject *
IEC61853_get_verbose(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853par_IEC61853_verbose_nget, self->data_ptr);
}

static int
IEC61853_set_verbose(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Iec61853par_IEC61853_verbose_nset, self->data_ptr);
}

static PyGetSetDef IEC61853_getset[] = {
{"input", (getter)IEC61853_get_input,(setter)IEC61853_set_input,
	PyDoc_STR("*sequence[sequence]*: IEC-61853 matrix test data [various]\n\n*Info*: [IRR,TC,PMP,VMP,VOC,ISC]\n\n*Required*: True"),
 	NULL},
{"nser", (getter)IEC61853_get_nser,(setter)IEC61853_set_nser,
	PyDoc_STR("*float*: Number of cells in series\n\n*Required*: True"),
 	NULL},
{"type", (getter)IEC61853_get_type,(setter)IEC61853_set_type,
	PyDoc_STR("*float*: Cell technology type [0..5]\n\n*Info*: monoSi,multiSi/polySi,cdte,cis,cigs,amorphous\n\n*Required*: True"),
 	NULL},
{"verbose", (getter)IEC61853_get_verbose,(setter)IEC61853_set_verbose,
	PyDoc_STR("*float*: Output solver messages [0/1]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject IEC61853_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Iec61853par.IEC61853",             /*tp_name*/
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
		IEC61853_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		IEC61853_getset,          /*tp_getset*/
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
Outputs_new(SAM_Iec61853par data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Iec61853par", "Outputs")){
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
Outputs_get_C1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853par_Outputs_C1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_C2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853par_Outputs_C2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_C3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853par_Outputs_C3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_D1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853par_Outputs_D1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_D2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853par_Outputs_D2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_D3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853par_Outputs_D3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Egref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853par_Outputs_Egref_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Il(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853par_Outputs_Il_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Io(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853par_Outputs_Io_nget, self->data_ptr);
}

static PyObject *
Outputs_get_alphaIsc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853par_Outputs_alphaIsc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_betaVoc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853par_Outputs_betaVoc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_gammaPmp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853par_Outputs_gammaPmp_nget, self->data_ptr);
}

static PyObject *
Outputs_get_n(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853par_Outputs_n_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"C1", (getter)Outputs_get_C1,(setter)0,
	PyDoc_STR("*float*: Rsh fitting C1"),
 	NULL},
{"C2", (getter)Outputs_get_C2,(setter)0,
	PyDoc_STR("*float*: Rsh fitting C2"),
 	NULL},
{"C3", (getter)Outputs_get_C3,(setter)0,
	PyDoc_STR("*float*: Rsh fitting C3"),
 	NULL},
{"D1", (getter)Outputs_get_D1,(setter)0,
	PyDoc_STR("*float*: Rs fitting D1"),
 	NULL},
{"D2", (getter)Outputs_get_D2,(setter)0,
	PyDoc_STR("*float*: Rs fitting D2"),
 	NULL},
{"D3", (getter)Outputs_get_D3,(setter)0,
	PyDoc_STR("*float*: Rs fitting D3"),
 	NULL},
{"Egref", (getter)Outputs_get_Egref,(setter)0,
	PyDoc_STR("*float*: Bandgap voltage [eV]"),
 	NULL},
{"Il", (getter)Outputs_get_Il,(setter)0,
	PyDoc_STR("*float*: Light current [A]"),
 	NULL},
{"Io", (getter)Outputs_get_Io,(setter)0,
	PyDoc_STR("*float*: Saturation current [A]"),
 	NULL},
{"alphaIsc", (getter)Outputs_get_alphaIsc,(setter)0,
	PyDoc_STR("*float*: SC temp coefficient @ STC [A/C]"),
 	NULL},
{"betaVoc", (getter)Outputs_get_betaVoc,(setter)0,
	PyDoc_STR("*float*: OC temp coefficient @ STC [V/C]"),
 	NULL},
{"gammaPmp", (getter)Outputs_get_gammaPmp,(setter)0,
	PyDoc_STR("*float*: MP temp coefficient @ STC [%/C]"),
 	NULL},
{"n", (getter)Outputs_get_n,(setter)0,
	PyDoc_STR("*float*: Diode factor"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Iec61853par.Outputs",             /*tp_name*/
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
 * Iec61853par
 */

static PyTypeObject Iec61853par_Type;

static CmodObject *
newIec61853parObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Iec61853par_Type);

	PySAM_TECH_ATTR()

	PyObject* IEC61853_obj = IEC61853_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "IEC61853", IEC61853_obj);
	Py_DECREF(IEC61853_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Iec61853par methods */

static void
Iec61853par_dealloc(CmodObject *self)
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
Iec61853par_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Iec61853par_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Iec61853par_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Iec61853par"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Iec61853par_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Iec61853par_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef Iec61853par_methods[] = {
		{"execute",            (PyCFunction)Iec61853par_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Iec61853par_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'IEC61853': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Iec61853par_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Iec61853par_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Iec61853par_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Iec61853par_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Iec61853par_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Iec61853par",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Iec61853par_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Iec61853par_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Iec61853par_getattro, /*tp_getattro*/
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
		Iec61853par_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Iec61853par object */

static PyObject *
Iec61853par_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newIec61853parObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Iec61853par_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newIec61853parObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Iec61853par_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newIec61853parObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Iec61853par", def);

	return (PyObject *)rv;
}

static PyObject *
Iec61853par_from_existing(PyObject *self, PyObject *args)
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

	rv = newIec61853parObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Iec61853par", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Iec61853parModule_methods[] = {
		{"new",             Iec61853par_new,         METH_VARARGS,
				PyDoc_STR("new() -> Iec61853par")},
		{"default",             Iec61853par_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Iec61853par\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             Iec61853par_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Iec61853par\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   Iec61853par_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Iec61853par\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Iec61853par");


static int
Iec61853parModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Iec61853par_Type.tp_dict = PyDict_New();
	if (!Iec61853par_Type.tp_dict) { goto fail; }

	/// Add the IEC61853 type object to Iec61853par_Type
	if (PyType_Ready(&IEC61853_Type) < 0) { goto fail; }
	PyDict_SetItemString(Iec61853par_Type.tp_dict,
				"IEC61853",
				(PyObject*)&IEC61853_Type);
	Py_DECREF(&IEC61853_Type);

	/// Add the Outputs type object to Iec61853par_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Iec61853par_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Iec61853par type object to the module
	if (PyType_Ready(&Iec61853par_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Iec61853par",
				(PyObject*)&Iec61853par_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Iec61853parModule_slots[] = {
		{Py_mod_exec, Iec61853parModule_exec},
		{0, NULL},
};

static struct PyModuleDef Iec61853parModule = {
		PyModuleDef_HEAD_INIT,
		"Iec61853par",
		module_doc,
		0,
		Iec61853parModule_methods,
		Iec61853parModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Iec61853par(void)
{
	return PyModuleDef_Init(&Iec61853parModule);
}