#include <Python.h>

#include <SAM_UiUdpcChecks.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * UserDefinedPowerCycle Group
 */ 

static PyTypeObject UserDefinedPowerCycle_Type;

static PyObject *
UserDefinedPowerCycle_new(SAM_UiUdpcChecks data_ptr)
{
	PyObject* new_obj = UserDefinedPowerCycle_Type.tp_alloc(&UserDefinedPowerCycle_Type,0);

	VarGroupObject* UserDefinedPowerCycle_obj = (VarGroupObject*)new_obj;

	UserDefinedPowerCycle_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* UserDefinedPowerCycle methods */

static PyObject *
UserDefinedPowerCycle_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "UiUdpcChecks", "UserDefinedPowerCycle")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
UserDefinedPowerCycle_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &UserDefinedPowerCycle_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef UserDefinedPowerCycle_methods[] = {
		{"assign",            (PyCFunction)UserDefinedPowerCycle_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``UserDefinedPowerCycle_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)UserDefinedPowerCycle_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
UserDefinedPowerCycle_get_ud_ind_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_UiUdpcChecks_UserDefinedPowerCycle_ud_ind_od_mget, self->data_ptr);
}

static int
UserDefinedPowerCycle_set_ud_ind_od(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_UiUdpcChecks_UserDefinedPowerCycle_ud_ind_od_mset, self->data_ptr);
}

static PyGetSetDef UserDefinedPowerCycle_getset[] = {
{"ud_ind_od", (getter)UserDefinedPowerCycle_get_ud_ind_od,(setter)UserDefinedPowerCycle_set_ud_ind_od,
	PyDoc_STR("*sequence[sequence]*: Off design user-defined power cycle performance as function of T_htf, m_dot_htf [ND], and T_amb\n\n*Required*: If not provided, assumed to be [[0]]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject UserDefinedPowerCycle_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"UiUdpcChecks.UserDefinedPowerCycle",             /*tp_name*/
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
		UserDefinedPowerCycle_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		UserDefinedPowerCycle_getset,          /*tp_getset*/
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
Outputs_new(SAM_UiUdpcChecks data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "UiUdpcChecks", "Outputs")){
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
Outputs_get_T_amb_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiUdpcChecks_Outputs_T_amb_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_T_amb_high(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiUdpcChecks_Outputs_T_amb_high_nget, self->data_ptr);
}

static PyObject *
Outputs_get_T_amb_low(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiUdpcChecks_Outputs_T_amb_low_nget, self->data_ptr);
}

static PyObject *
Outputs_get_T_htf_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiUdpcChecks_Outputs_T_htf_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_T_htf_high(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiUdpcChecks_Outputs_T_htf_high_nget, self->data_ptr);
}

static PyObject *
Outputs_get_T_htf_low(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiUdpcChecks_Outputs_T_htf_low_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiUdpcChecks_Outputs_m_dot_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_high(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiUdpcChecks_Outputs_m_dot_high_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_low(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiUdpcChecks_Outputs_m_dot_low_nget, self->data_ptr);
}

static PyObject *
Outputs_get_n_T_amb_pars(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiUdpcChecks_Outputs_n_T_amb_pars_nget, self->data_ptr);
}

static PyObject *
Outputs_get_n_T_htf_pars(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiUdpcChecks_Outputs_n_T_htf_pars_nget, self->data_ptr);
}

static PyObject *
Outputs_get_n_m_dot_pars(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiUdpcChecks_Outputs_n_m_dot_pars_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"T_amb_des", (getter)Outputs_get_T_amb_des,(setter)0,
	PyDoc_STR("*float*: Design ambient temperature [C]"),
 	NULL},
{"T_amb_high", (getter)Outputs_get_T_amb_high,(setter)0,
	PyDoc_STR("*float*: High ambient temperature [C]"),
 	NULL},
{"T_amb_low", (getter)Outputs_get_T_amb_low,(setter)0,
	PyDoc_STR("*float*: Low ambient temperature [C]"),
 	NULL},
{"T_htf_des", (getter)Outputs_get_T_htf_des,(setter)0,
	PyDoc_STR("*float*: HTF design temperature [C]"),
 	NULL},
{"T_htf_high", (getter)Outputs_get_T_htf_high,(setter)0,
	PyDoc_STR("*float*: HTF high temperature [C]"),
 	NULL},
{"T_htf_low", (getter)Outputs_get_T_htf_low,(setter)0,
	PyDoc_STR("*float*: HTF low temperature [C]"),
 	NULL},
{"m_dot_des", (getter)Outputs_get_m_dot_des,(setter)0,
	PyDoc_STR("*float*: Design ambient temperature [C]"),
 	NULL},
{"m_dot_high", (getter)Outputs_get_m_dot_high,(setter)0,
	PyDoc_STR("*float*: High ambient temperature [C]"),
 	NULL},
{"m_dot_low", (getter)Outputs_get_m_dot_low,(setter)0,
	PyDoc_STR("*float*: Low ambient temperature [C]"),
 	NULL},
{"n_T_amb_pars", (getter)Outputs_get_n_T_amb_pars,(setter)0,
	PyDoc_STR("*float*: Number of ambient temperature parametrics [-]"),
 	NULL},
{"n_T_htf_pars", (getter)Outputs_get_n_T_htf_pars,(setter)0,
	PyDoc_STR("*float*: Number of HTF parametrics [-]"),
 	NULL},
{"n_m_dot_pars", (getter)Outputs_get_n_m_dot_pars,(setter)0,
	PyDoc_STR("*float*: Number of HTF mass flow parametrics [-]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"UiUdpcChecks.Outputs",             /*tp_name*/
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
 * UiUdpcChecks
 */

static PyTypeObject UiUdpcChecks_Type;

static CmodObject *
newUiUdpcChecksObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &UiUdpcChecks_Type);

	PySAM_TECH_ATTR()

	PyObject* UserDefinedPowerCycle_obj = UserDefinedPowerCycle_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "UserDefinedPowerCycle", UserDefinedPowerCycle_obj);
	Py_DECREF(UserDefinedPowerCycle_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* UiUdpcChecks methods */

static void
UiUdpcChecks_dealloc(CmodObject *self)
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
UiUdpcChecks_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_UiUdpcChecks_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
UiUdpcChecks_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "UiUdpcChecks"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
UiUdpcChecks_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
UiUdpcChecks_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef UiUdpcChecks_methods[] = {
		{"execute",            (PyCFunction)UiUdpcChecks_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)UiUdpcChecks_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'User Defined Power Cycle': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)UiUdpcChecks_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)UiUdpcChecks_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
UiUdpcChecks_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
UiUdpcChecks_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject UiUdpcChecks_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"UiUdpcChecks",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)UiUdpcChecks_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)UiUdpcChecks_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)UiUdpcChecks_getattro, /*tp_getattro*/
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
		UiUdpcChecks_methods,      /*tp_methods*/
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


/* Function of no arguments returning new UiUdpcChecks object */

static PyObject *
UiUdpcChecks_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newUiUdpcChecksObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
UiUdpcChecks_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newUiUdpcChecksObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
UiUdpcChecks_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newUiUdpcChecksObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "UiUdpcChecks", def);

	return (PyObject *)rv;
}

static PyObject *
UiUdpcChecks_from_existing(PyObject *self, PyObject *args)
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

	rv = newUiUdpcChecksObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "UiUdpcChecks", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef UiUdpcChecksModule_methods[] = {
		{"new",             UiUdpcChecks_new,         METH_VARARGS,
				PyDoc_STR("new() -> UiUdpcChecks")},
		{"default",             UiUdpcChecks_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> UiUdpcChecks\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             UiUdpcChecks_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> UiUdpcChecks\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   UiUdpcChecks_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> UiUdpcChecks\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "UiUdpcChecks");


static int
UiUdpcChecksModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	UiUdpcChecks_Type.tp_dict = PyDict_New();
	if (!UiUdpcChecks_Type.tp_dict) { goto fail; }

	/// Add the UserDefinedPowerCycle type object to UiUdpcChecks_Type
	if (PyType_Ready(&UserDefinedPowerCycle_Type) < 0) { goto fail; }
	PyDict_SetItemString(UiUdpcChecks_Type.tp_dict,
				"UserDefinedPowerCycle",
				(PyObject*)&UserDefinedPowerCycle_Type);
	Py_DECREF(&UserDefinedPowerCycle_Type);

	/// Add the Outputs type object to UiUdpcChecks_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(UiUdpcChecks_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the UiUdpcChecks type object to the module
	if (PyType_Ready(&UiUdpcChecks_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"UiUdpcChecks",
				(PyObject*)&UiUdpcChecks_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot UiUdpcChecksModule_slots[] = {
		{Py_mod_exec, UiUdpcChecksModule_exec},
		{0, NULL},
};

static struct PyModuleDef UiUdpcChecksModule = {
		PyModuleDef_HEAD_INIT,
		"UiUdpcChecks",
		module_doc,
		0,
		UiUdpcChecksModule_methods,
		UiUdpcChecksModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_UiUdpcChecks(void)
{
	return PyModuleDef_Init(&UiUdpcChecksModule);
}