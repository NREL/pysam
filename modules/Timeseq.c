#include <Python.h>

#include <SAM_Timeseq.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * TimeSequence Group
 */ 

static PyTypeObject TimeSequence_Type;

static PyObject *
TimeSequence_new(SAM_Timeseq data_ptr)
{
	PyObject* new_obj = TimeSequence_Type.tp_alloc(&TimeSequence_Type,0);

	VarGroupObject* TimeSequence_obj = (VarGroupObject*)new_obj;

	TimeSequence_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* TimeSequence methods */

static PyObject *
TimeSequence_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Timeseq", "TimeSequence")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TimeSequence_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &TimeSequence_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TimeSequence_methods[] = {
		{"assign",            (PyCFunction)TimeSequence_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``TimeSequence_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)TimeSequence_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TimeSequence_get_end_time(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Timeseq_TimeSequence_end_time_nget, self->data_ptr);
}

static int
TimeSequence_set_end_time(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Timeseq_TimeSequence_end_time_nset, self->data_ptr);
}

static PyObject *
TimeSequence_get_start_time(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Timeseq_TimeSequence_start_time_nget, self->data_ptr);
}

static int
TimeSequence_set_start_time(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Timeseq_TimeSequence_start_time_nset, self->data_ptr);
}

static PyObject *
TimeSequence_get_time_step(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Timeseq_TimeSequence_time_step_nget, self->data_ptr);
}

static int
TimeSequence_set_time_step(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Timeseq_TimeSequence_time_step_nset, self->data_ptr);
}

static PyGetSetDef TimeSequence_getset[] = {
{"end_time", (getter)TimeSequence_get_end_time,(setter)TimeSequence_set_end_time,
	PyDoc_STR("*float*: End time [seconds]\n\n*Options*: 0=jan1st 12am\n\n*Constraints*: MIN=0,MAX=31536000\n\n*Required*: True"),
 	NULL},
{"start_time", (getter)TimeSequence_get_start_time,(setter)TimeSequence_set_start_time,
	PyDoc_STR("*float*: Start time [seconds]\n\n*Options*: 0=jan1st 12am\n\n*Constraints*: MIN=0,MAX=31536000\n\n*Required*: True"),
 	NULL},
{"time_step", (getter)TimeSequence_get_time_step,(setter)TimeSequence_set_time_step,
	PyDoc_STR("*float*: Time step [seconds]\n\n*Constraints*: MIN=1,MAX=3600\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TimeSequence_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Timeseq.TimeSequence",             /*tp_name*/
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
		TimeSequence_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TimeSequence_getset,          /*tp_getset*/
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
Outputs_new(SAM_Timeseq data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Timeseq", "Outputs")){
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
Outputs_get_day(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Timeseq_Outputs_day_aget, self->data_ptr);
}

static PyObject *
Outputs_get_hour(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Timeseq_Outputs_hour_aget, self->data_ptr);
}

static PyObject *
Outputs_get_minute(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Timeseq_Outputs_minute_aget, self->data_ptr);
}

static PyObject *
Outputs_get_month(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Timeseq_Outputs_month_aget, self->data_ptr);
}

static PyObject *
Outputs_get_time(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Timeseq_Outputs_time_aget, self->data_ptr);
}

static PyObject *
Outputs_get_timehr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Timeseq_Outputs_timehr_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"day", (getter)Outputs_get_day,(setter)0,
	PyDoc_STR("*sequence*: Day"),
 	NULL},
{"hour", (getter)Outputs_get_hour,(setter)0,
	PyDoc_STR("*sequence*: Hour"),
 	NULL},
{"minute", (getter)Outputs_get_minute,(setter)0,
	PyDoc_STR("*sequence*: Minute"),
 	NULL},
{"month", (getter)Outputs_get_month,(setter)0,
	PyDoc_STR("*sequence*: Month"),
 	NULL},
{"time", (getter)Outputs_get_time,(setter)0,
	PyDoc_STR("*sequence*: Time [secs]"),
 	NULL},
{"timehr", (getter)Outputs_get_timehr,(setter)0,
	PyDoc_STR("*sequence*: HourTime [hours]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Timeseq.Outputs",             /*tp_name*/
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
 * Timeseq
 */

static PyTypeObject Timeseq_Type;

static CmodObject *
newTimeseqObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Timeseq_Type);

	PySAM_TECH_ATTR()

	PyObject* TimeSequence_obj = TimeSequence_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TimeSequence", TimeSequence_obj);
	Py_DECREF(TimeSequence_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Timeseq methods */

static void
Timeseq_dealloc(CmodObject *self)
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
Timeseq_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Timeseq_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Timeseq_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Timeseq"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Timeseq_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Timeseq_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef Timeseq_methods[] = {
		{"execute",            (PyCFunction)Timeseq_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Timeseq_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Time Sequence': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Timeseq_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Timeseq_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Timeseq_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Timeseq_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Timeseq_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Timeseq",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Timeseq_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Timeseq_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Timeseq_getattro, /*tp_getattro*/
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
		Timeseq_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Timeseq object */

static PyObject *
Timeseq_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newTimeseqObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Timeseq_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTimeseqObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Timeseq_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTimeseqObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Timeseq", def);

	return (PyObject *)rv;
}

static PyObject *
Timeseq_from_existing(PyObject *self, PyObject *args)
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

	rv = newTimeseqObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Timeseq", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef TimeseqModule_methods[] = {
		{"new",             Timeseq_new,         METH_VARARGS,
				PyDoc_STR("new() -> Timeseq")},
		{"default",             Timeseq_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Timeseq\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             Timeseq_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Timeseq\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   Timeseq_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Timeseq\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Timeseq");


static int
TimeseqModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Timeseq_Type.tp_dict = PyDict_New();
	if (!Timeseq_Type.tp_dict) { goto fail; }

	/// Add the TimeSequence type object to Timeseq_Type
	if (PyType_Ready(&TimeSequence_Type) < 0) { goto fail; }
	PyDict_SetItemString(Timeseq_Type.tp_dict,
				"TimeSequence",
				(PyObject*)&TimeSequence_Type);
	Py_DECREF(&TimeSequence_Type);

	/// Add the Outputs type object to Timeseq_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Timeseq_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Timeseq type object to the module
	if (PyType_Ready(&Timeseq_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Timeseq",
				(PyObject*)&Timeseq_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot TimeseqModule_slots[] = {
		{Py_mod_exec, TimeseqModule_exec},
		{0, NULL},
};

static struct PyModuleDef TimeseqModule = {
		PyModuleDef_HEAD_INIT,
		"Timeseq",
		module_doc,
		0,
		TimeseqModule_methods,
		TimeseqModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Timeseq(void)
{
	return PyModuleDef_Init(&TimeseqModule);
}