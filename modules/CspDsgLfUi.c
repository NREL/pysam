#include <Python.h>

#include <SAM_CspDsgLfUi.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Common Group
 */ 

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_CspDsgLfUi data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CspDsgLfUi", "Common")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Common_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Common_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "CspDsgLfUi", "Common")){
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
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Common_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Common_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Common_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Common_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Common_get_P_boil(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspDsgLfUi_Common_P_boil_nget, self->data_ptr);
}

static int
Common_set_P_boil(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspDsgLfUi_Common_P_boil_nset, self->data_ptr);
}

static PyObject *
Common_get_deltaT_subcooled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspDsgLfUi_Common_deltaT_subcooled_nget, self->data_ptr);
}

static int
Common_set_deltaT_subcooled(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspDsgLfUi_Common_deltaT_subcooled_nset, self->data_ptr);
}

static PyObject *
Common_get_use_quality_or_subcooled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspDsgLfUi_Common_use_quality_or_subcooled_nget, self->data_ptr);
}

static int
Common_set_use_quality_or_subcooled(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CspDsgLfUi_Common_use_quality_or_subcooled_nset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"P_boil", (getter)Common_get_P_boil,(setter)Common_set_P_boil,
	PyDoc_STR("*float*: Boiling pressure [bar]\n\n**Required:**\nTrue"),
 	NULL},
{"deltaT_subcooled", (getter)Common_get_deltaT_subcooled,(setter)Common_set_deltaT_subcooled,
	PyDoc_STR("*float*: Subcooled temperature difference from saturation temp [C]\n\n**Required:**\nTrue"),
 	NULL},
{"use_quality_or_subcooled", (getter)Common_get_use_quality_or_subcooled,(setter)Common_set_use_quality_or_subcooled,
	PyDoc_STR("*float*: 0 = 2 phase outlet, 1 = subcooled\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CspDsgLfUi.Common",             /*tp_name*/
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
Outputs_new(SAM_CspDsgLfUi data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CspDsgLfUi", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "CspDsgLfUi", "Outputs")){
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
Outputs_get_T_hot_out_target(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspDsgLfUi_Outputs_T_hot_out_target_nget, self->data_ptr);
}

static PyObject *
Outputs_get_T_saturation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CspDsgLfUi_Outputs_T_saturation_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"T_hot_out_target", (getter)Outputs_get_T_hot_out_target,(setter)0,
	PyDoc_STR("*float*: Target outlet temperature [C]"),
 	NULL},
{"T_saturation", (getter)Outputs_get_T_saturation,(setter)0,
	PyDoc_STR("*float*: Saturation pressure [C]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CspDsgLfUi.Outputs",             /*tp_name*/
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
 * CspDsgLfUi
 */

static PyTypeObject CspDsgLfUi_Type;

static CmodObject *
newCspDsgLfUiObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &CspDsgLfUi_Type);

	PySAM_TECH_ATTR()

	PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* CspDsgLfUi methods */

static void
CspDsgLfUi_dealloc(CmodObject *self)
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
CspDsgLfUi_get_data_ptr(CmodObject *self, PyObject *args)
{
	PyObject* ptr = PyLong_FromVoidPtr((void*)self->data_ptr);
	return ptr;
}


static PyObject *
CspDsgLfUi_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_CspDsgLfUi_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
CspDsgLfUi_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "CspDsgLfUi"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
CspDsgLfUi_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "CspDsgLfUi"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
CspDsgLfUi_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
CspDsgLfUi_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
CspDsgLfUi_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef CspDsgLfUi_methods[] = {
		{"execute",           (PyCFunction)CspDsgLfUi_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"get_data_ptr",           (PyCFunction)CspDsgLfUi_get_data_ptr,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> Pointer\n Get ssc_data_t pointer")},
		{"assign",            (PyCFunction)CspDsgLfUi_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Common': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)CspDsgLfUi_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Common': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)CspDsgLfUi_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)CspDsgLfUi_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)CspDsgLfUi_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
CspDsgLfUi_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
CspDsgLfUi_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject CspDsgLfUi_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CspDsgLfUi",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)CspDsgLfUi_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)CspDsgLfUi_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)CspDsgLfUi_getattro, /*tp_getattro*/
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
		CspDsgLfUi_methods,      /*tp_methods*/
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


/* Function of no arguments returning new CspDsgLfUi object */

static PyObject *
CspDsgLfUi_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newCspDsgLfUiObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
CspDsgLfUi_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newCspDsgLfUiObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
CspDsgLfUi_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newCspDsgLfUiObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "CspDsgLfUi", def) < 0) {
		CspDsgLfUi_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
CspDsgLfUi_from_existing(PyObject *self, PyObject *args)
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

	rv = newCspDsgLfUiObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "CspDsgLfUi", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef CspDsgLfUiModule_methods[] = {
		{"new",             CspDsgLfUi_new,         METH_VARARGS,
				PyDoc_STR("new() -> CspDsgLfUi")},
		{"default",             CspDsgLfUi_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> CspDsgLfUi\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             CspDsgLfUi_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> CspDsgLfUi\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   CspDsgLfUi_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> CspDsgLfUi\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "CspDsgLfUi");


static int
CspDsgLfUiModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	CspDsgLfUi_Type.tp_dict = PyDict_New();
	if (!CspDsgLfUi_Type.tp_dict) { goto fail; }

	/// Add the Common type object to CspDsgLfUi_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(CspDsgLfUi_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the Outputs type object to CspDsgLfUi_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(CspDsgLfUi_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the CspDsgLfUi type object to the module
	if (PyType_Ready(&CspDsgLfUi_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"CspDsgLfUi",
				(PyObject*)&CspDsgLfUi_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot CspDsgLfUiModule_slots[] = {
		{Py_mod_exec, CspDsgLfUiModule_exec},
		{0, NULL},
};

static struct PyModuleDef CspDsgLfUiModule = {
		PyModuleDef_HEAD_INIT,
		"CspDsgLfUi",
		module_doc,
		0,
		CspDsgLfUiModule_methods,
		CspDsgLfUiModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_CspDsgLfUi(void)
{
	return PyModuleDef_Init(&CspDsgLfUiModule);
}