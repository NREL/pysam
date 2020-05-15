#include <Python.h>

#include <SAM_Iec61853interp.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * IEC61853 Group
 */ 

static PyTypeObject IEC61853_Type;

static PyObject *
IEC61853_new(SAM_Iec61853interp data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Iec61853interp", "IEC61853")){
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
	return PySAM_matrix_getter(SAM_Iec61853interp_IEC61853_input_mget, self->data_ptr);
}

static int
IEC61853_set_input(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Iec61853interp_IEC61853_input_mset, self->data_ptr);
}

static PyObject *
IEC61853_get_param(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Iec61853interp_IEC61853_param_mget, self->data_ptr);
}

static int
IEC61853_set_param(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Iec61853interp_IEC61853_param_mset, self->data_ptr);
}

static PyGetSetDef IEC61853_getset[] = {
{"input", (getter)IEC61853_get_input,(setter)IEC61853_set_input,
	PyDoc_STR("*sequence[sequence]*: IEC-61853 matrix test data [various]\n\n*Info*: [IRR,TC,PMP,VMP,VOC,ISC]\n\n*Required*: True"),
 	NULL},
{"param", (getter)IEC61853_get_param,(setter)IEC61853_set_param,
	PyDoc_STR("*sequence[sequence]*: Parameter solution matrix\n\n*Info*: [IL,IO,RS,RSH,A]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject IEC61853_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Iec61853interp.IEC61853",             /*tp_name*/
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
 * SingleDiodeModel Group
 */ 

static PyTypeObject SingleDiodeModel_Type;

static PyObject *
SingleDiodeModel_new(SAM_Iec61853interp data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Iec61853interp", "SingleDiodeModel")){
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
SingleDiodeModel_get_I(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853interp_SingleDiodeModel_I_nget, self->data_ptr);
}

static int
SingleDiodeModel_set_I(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Iec61853interp_SingleDiodeModel_I_nset, self->data_ptr);
}

static PyObject *
SingleDiodeModel_get_T(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853interp_SingleDiodeModel_T_nget, self->data_ptr);
}

static int
SingleDiodeModel_set_T(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Iec61853interp_SingleDiodeModel_T_nset, self->data_ptr);
}

static PyGetSetDef SingleDiodeModel_getset[] = {
{"I", (getter)SingleDiodeModel_get_I,(setter)SingleDiodeModel_set_I,
	PyDoc_STR("*float*: Irradiance [W/m2]\n\n*Required*: True"),
 	NULL},
{"T", (getter)SingleDiodeModel_get_T,(setter)SingleDiodeModel_set_T,
	PyDoc_STR("*float*: Temperature [C]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SingleDiodeModel_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Iec61853interp.SingleDiodeModel",             /*tp_name*/
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
Outputs_new(SAM_Iec61853interp data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Iec61853interp", "Outputs")){
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
Outputs_get_Il(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853interp_Outputs_Il_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Io(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853interp_Outputs_Io_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Rs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853interp_Outputs_Rs_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Rsh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853interp_Outputs_Rsh_nget, self->data_ptr);
}

static PyObject *
Outputs_get_a(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Iec61853interp_Outputs_a_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"Il", (getter)Outputs_get_Il,(setter)0,
	PyDoc_STR("*float*: Light current [A]"),
 	NULL},
{"Io", (getter)Outputs_get_Io,(setter)0,
	PyDoc_STR("*float*: Saturation current [A]"),
 	NULL},
{"Rs", (getter)Outputs_get_Rs,(setter)0,
	PyDoc_STR("*float*: Series resistance [ohm]"),
 	NULL},
{"Rsh", (getter)Outputs_get_Rsh,(setter)0,
	PyDoc_STR("*float*: Shunt resistance [ohm]"),
 	NULL},
{"a", (getter)Outputs_get_a,(setter)0,
	PyDoc_STR("*float*: Modified nonideality factor [1/V]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Iec61853interp.Outputs",             /*tp_name*/
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
 * Iec61853interp
 */

static PyTypeObject Iec61853interp_Type;

static CmodObject *
newIec61853interpObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Iec61853interp_Type);

	PySAM_TECH_ATTR()

	PyObject* IEC61853_obj = IEC61853_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "IEC61853", IEC61853_obj);
	Py_DECREF(IEC61853_obj);

	PyObject* SingleDiodeModel_obj = SingleDiodeModel_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SingleDiodeModel", SingleDiodeModel_obj);
	Py_DECREF(SingleDiodeModel_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Iec61853interp methods */

static void
Iec61853interp_dealloc(CmodObject *self)
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
Iec61853interp_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Iec61853interp_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Iec61853interp_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Iec61853interp"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Iec61853interp_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Iec61853interp_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef Iec61853interp_methods[] = {
		{"execute",            (PyCFunction)Iec61853interp_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Iec61853interp_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'IEC61853': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Iec61853interp_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Iec61853interp_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Iec61853interp_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Iec61853interp_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Iec61853interp_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Iec61853interp",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Iec61853interp_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Iec61853interp_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Iec61853interp_getattro, /*tp_getattro*/
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
		Iec61853interp_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Iec61853interp object */

static PyObject *
Iec61853interp_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newIec61853interpObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Iec61853interp_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newIec61853interpObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Iec61853interp_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newIec61853interpObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Iec61853interp", def);

	return (PyObject *)rv;
}

static PyObject *
Iec61853interp_from_existing(PyObject *self, PyObject *args)
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

	rv = newIec61853interpObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Iec61853interp", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Iec61853interpModule_methods[] = {
		{"new",             Iec61853interp_new,         METH_VARARGS,
				PyDoc_STR("new() -> Iec61853interp")},
		{"default",             Iec61853interp_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Iec61853interp\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             Iec61853interp_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Iec61853interp\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   Iec61853interp_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Iec61853interp\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Iec61853interp");


static int
Iec61853interpModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Iec61853interp_Type.tp_dict = PyDict_New();
	if (!Iec61853interp_Type.tp_dict) { goto fail; }

	/// Add the IEC61853 type object to Iec61853interp_Type
	if (PyType_Ready(&IEC61853_Type) < 0) { goto fail; }
	PyDict_SetItemString(Iec61853interp_Type.tp_dict,
				"IEC61853",
				(PyObject*)&IEC61853_Type);
	Py_DECREF(&IEC61853_Type);

	/// Add the SingleDiodeModel type object to Iec61853interp_Type
	if (PyType_Ready(&SingleDiodeModel_Type) < 0) { goto fail; }
	PyDict_SetItemString(Iec61853interp_Type.tp_dict,
				"SingleDiodeModel",
				(PyObject*)&SingleDiodeModel_Type);
	Py_DECREF(&SingleDiodeModel_Type);

	/// Add the Outputs type object to Iec61853interp_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Iec61853interp_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Iec61853interp type object to the module
	if (PyType_Ready(&Iec61853interp_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Iec61853interp",
				(PyObject*)&Iec61853interp_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Iec61853interpModule_slots[] = {
		{Py_mod_exec, Iec61853interpModule_exec},
		{0, NULL},
};

static struct PyModuleDef Iec61853interpModule = {
		PyModuleDef_HEAD_INIT,
		"Iec61853interp",
		module_doc,
		0,
		Iec61853interpModule_methods,
		Iec61853interpModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Iec61853interp(void)
{
	return PyModuleDef_Init(&Iec61853interpModule);
}