#include <Python.h>

#include <SAM_IphToLcoefcr.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * IPHLCOH Group
 */ 

static PyTypeObject IPHLCOH_Type;

static PyObject *
IPHLCOH_new(SAM_IphToLcoefcr data_ptr)
{
	PyObject* new_obj = IPHLCOH_Type.tp_alloc(&IPHLCOH_Type,0);

	VarGroupObject* IPHLCOH_obj = (VarGroupObject*)new_obj;

	IPHLCOH_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* IPHLCOH methods */

static PyObject *
IPHLCOH_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "IphToLcoefcr", "IPHLCOH")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
IPHLCOH_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &IPHLCOH_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "IphToLcoefcr", "IPHLCOH")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
IPHLCOH_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &IPHLCOH_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef IPHLCOH_methods[] = {
		{"assign",            (PyCFunction)IPHLCOH_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``IPHLCOH_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)IPHLCOH_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``IPHLCOH_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)IPHLCOH_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
IPHLCOH_get_annual_electricity_consumption(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_IphToLcoefcr_IPHLCOH_annual_electricity_consumption_nget, self->data_ptr);
}

static int
IPHLCOH_set_annual_electricity_consumption(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_IphToLcoefcr_IPHLCOH_annual_electricity_consumption_nset, self->data_ptr);
}

static PyObject *
IPHLCOH_get_electricity_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_IphToLcoefcr_IPHLCOH_electricity_rate_nget, self->data_ptr);
}

static int
IPHLCOH_set_electricity_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_IphToLcoefcr_IPHLCOH_electricity_rate_nset, self->data_ptr);
}

static PyGetSetDef IPHLCOH_getset[] = {
{"annual_electricity_consumption", (getter)IPHLCOH_get_annual_electricity_consumption,(setter)IPHLCOH_set_annual_electricity_consumption,
	PyDoc_STR("*float*: Annual electricity consumption with avail derate [kWe-hr]\n\n**Required:**\nTrue"),
 	NULL},
{"electricity_rate", (getter)IPHLCOH_get_electricity_rate,(setter)IPHLCOH_set_electricity_rate,
	PyDoc_STR("*float*: Cost of electricity used to operate pumps and trackers [$/kWe]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject IPHLCOH_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"IphToLcoefcr.IPHLCOH",             /*tp_name*/
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
		IPHLCOH_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		IPHLCOH_getset,          /*tp_getset*/
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
 * SimpleLCOE Group
 */ 

static PyTypeObject SimpleLCOE_Type;

static PyObject *
SimpleLCOE_new(SAM_IphToLcoefcr data_ptr)
{
	PyObject* new_obj = SimpleLCOE_Type.tp_alloc(&SimpleLCOE_Type,0);

	VarGroupObject* SimpleLCOE_obj = (VarGroupObject*)new_obj;

	SimpleLCOE_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SimpleLCOE methods */

static PyObject *
SimpleLCOE_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "IphToLcoefcr", "SimpleLCOE")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SimpleLCOE_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SimpleLCOE_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "IphToLcoefcr", "SimpleLCOE")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SimpleLCOE_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SimpleLCOE_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SimpleLCOE_methods[] = {
		{"assign",            (PyCFunction)SimpleLCOE_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SimpleLCOE_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SimpleLCOE_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SimpleLCOE_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SimpleLCOE_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SimpleLCOE_get_fixed_operating_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_IphToLcoefcr_SimpleLCOE_fixed_operating_cost_nget, self->data_ptr);
}

static int
SimpleLCOE_set_fixed_operating_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_IphToLcoefcr_SimpleLCOE_fixed_operating_cost_nset, self->data_ptr);
}

static PyGetSetDef SimpleLCOE_getset[] = {
{"fixed_operating_cost", (getter)SimpleLCOE_get_fixed_operating_cost,(setter)SimpleLCOE_set_fixed_operating_cost,
	PyDoc_STR("*float*: Annual fixed operating cost [$/kW]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SimpleLCOE_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"IphToLcoefcr.SimpleLCOE",             /*tp_name*/
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
		SimpleLCOE_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SimpleLCOE_getset,          /*tp_getset*/
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
 * IphToLcoefcr
 */

static PyTypeObject IphToLcoefcr_Type;

static CmodObject *
newIphToLcoefcrObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &IphToLcoefcr_Type);

	PySAM_TECH_ATTR()

	PyObject* IPHLCOH_obj = IPHLCOH_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "IPHLCOH", IPHLCOH_obj);
	Py_DECREF(IPHLCOH_obj);

	PyObject* SimpleLCOE_obj = SimpleLCOE_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SimpleLCOE", SimpleLCOE_obj);
	Py_DECREF(SimpleLCOE_obj);

	return self;
}

/* IphToLcoefcr methods */

static void
IphToLcoefcr_dealloc(CmodObject *self)
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
IphToLcoefcr_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_IphToLcoefcr_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
IphToLcoefcr_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "IphToLcoefcr"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
IphToLcoefcr_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "IphToLcoefcr"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
IphToLcoefcr_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
IphToLcoefcr_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
IphToLcoefcr_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef IphToLcoefcr_methods[] = {
		{"execute",           (PyCFunction)IphToLcoefcr_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)IphToLcoefcr_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'IPH LCOH': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)IphToLcoefcr_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'IPH LCOH': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)IphToLcoefcr_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)IphToLcoefcr_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)IphToLcoefcr_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
IphToLcoefcr_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
IphToLcoefcr_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject IphToLcoefcr_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"IphToLcoefcr",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)IphToLcoefcr_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)IphToLcoefcr_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)IphToLcoefcr_getattro, /*tp_getattro*/
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
		IphToLcoefcr_methods,      /*tp_methods*/
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


/* Function of no arguments returning new IphToLcoefcr object */

static PyObject *
IphToLcoefcr_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newIphToLcoefcrObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
IphToLcoefcr_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newIphToLcoefcrObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
IphToLcoefcr_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newIphToLcoefcrObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "IphToLcoefcr", def) < 0) {
		IphToLcoefcr_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
IphToLcoefcr_from_existing(PyObject *self, PyObject *args)
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

	rv = newIphToLcoefcrObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "IphToLcoefcr", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef IphToLcoefcrModule_methods[] = {
		{"new",             IphToLcoefcr_new,         METH_VARARGS,
				PyDoc_STR("new() -> IphToLcoefcr")},
		{"default",             IphToLcoefcr_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> IphToLcoefcr\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"DSGLIPHLCOHCalculator\"*\n\n		- *\"PhysicalTroughIPHLCOHCalculator\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             IphToLcoefcr_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> IphToLcoefcr\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   IphToLcoefcr_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> IphToLcoefcr\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Calculate levelized cost of heat using fixed charge rate method for industrial process heat models");


static int
IphToLcoefcrModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	IphToLcoefcr_Type.tp_dict = PyDict_New();
	if (!IphToLcoefcr_Type.tp_dict) { goto fail; }

	/// Add the IPHLCOH type object to IphToLcoefcr_Type
	if (PyType_Ready(&IPHLCOH_Type) < 0) { goto fail; }
	PyDict_SetItemString(IphToLcoefcr_Type.tp_dict,
				"IPHLCOH",
				(PyObject*)&IPHLCOH_Type);
	Py_DECREF(&IPHLCOH_Type);

	/// Add the SimpleLCOE type object to IphToLcoefcr_Type
	if (PyType_Ready(&SimpleLCOE_Type) < 0) { goto fail; }
	PyDict_SetItemString(IphToLcoefcr_Type.tp_dict,
				"SimpleLCOE",
				(PyObject*)&SimpleLCOE_Type);
	Py_DECREF(&SimpleLCOE_Type);

	/// Add the IphToLcoefcr type object to the module
	if (PyType_Ready(&IphToLcoefcr_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"IphToLcoefcr",
				(PyObject*)&IphToLcoefcr_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot IphToLcoefcrModule_slots[] = {
		{Py_mod_exec, IphToLcoefcrModule_exec},
		{0, NULL},
};

static struct PyModuleDef IphToLcoefcrModule = {
		PyModuleDef_HEAD_INIT,
		"IphToLcoefcr",
		module_doc,
		0,
		IphToLcoefcrModule_methods,
		IphToLcoefcrModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_IphToLcoefcr(void)
{
	return PyModuleDef_Init(&IphToLcoefcrModule);
}