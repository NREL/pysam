#include <Python.h>

#include <SAM_Annualoutput.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * AnnualOutput Group
 */ 

static PyTypeObject AnnualOutput_Type;

static PyObject *
AnnualOutput_new(SAM_Annualoutput data_ptr)
{
	PyObject* new_obj = AnnualOutput_Type.tp_alloc(&AnnualOutput_Type,0);

	VarGroupObject* AnnualOutput_obj = (VarGroupObject*)new_obj;

	AnnualOutput_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* AnnualOutput methods */

static PyObject *
AnnualOutput_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Annualoutput", "AnnualOutput")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
AnnualOutput_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &AnnualOutput_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Annualoutput", "AnnualOutput")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
AnnualOutput_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &AnnualOutput_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef AnnualOutput_methods[] = {
		{"assign",            (PyCFunction)AnnualOutput_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``AnnualOutput_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)AnnualOutput_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``AnnualOutput_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)AnnualOutput_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
AnnualOutput_get_analysis_period(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Annualoutput_AnnualOutput_analysis_period_nget, self->data_ptr);
}

static int
AnnualOutput_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Annualoutput_AnnualOutput_analysis_period_nset, self->data_ptr);
}

static PyObject *
AnnualOutput_get_energy_availability(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Annualoutput_AnnualOutput_energy_availability_aget, self->data_ptr);
}

static int
AnnualOutput_set_energy_availability(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Annualoutput_AnnualOutput_energy_availability_aset, self->data_ptr);
}

static PyObject *
AnnualOutput_get_energy_curtailment(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Annualoutput_AnnualOutput_energy_curtailment_mget, self->data_ptr);
}

static int
AnnualOutput_set_energy_curtailment(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Annualoutput_AnnualOutput_energy_curtailment_mset, self->data_ptr);
}

static PyObject *
AnnualOutput_get_energy_degradation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Annualoutput_AnnualOutput_energy_degradation_aget, self->data_ptr);
}

static int
AnnualOutput_set_energy_degradation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Annualoutput_AnnualOutput_energy_degradation_aset, self->data_ptr);
}

static PyObject *
AnnualOutput_get_system_hourly_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Annualoutput_AnnualOutput_system_hourly_energy_aget, self->data_ptr);
}

static int
AnnualOutput_set_system_hourly_energy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Annualoutput_AnnualOutput_system_hourly_energy_aset, self->data_ptr);
}

static PyObject *
AnnualOutput_get_system_use_lifetime_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Annualoutput_AnnualOutput_system_use_lifetime_output_nget, self->data_ptr);
}

static int
AnnualOutput_set_system_use_lifetime_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Annualoutput_AnnualOutput_system_use_lifetime_output_nset, self->data_ptr);
}

static PyGetSetDef AnnualOutput_getset[] = {
{"analysis_period", (getter)AnnualOutput_get_analysis_period,(setter)AnnualOutput_set_analysis_period,
	PyDoc_STR("*float*: Analyis period [years]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=50\n\n**Required:**\nFalse. Automatically set to 30 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"energy_availability", (getter)AnnualOutput_get_energy_availability,(setter)AnnualOutput_set_energy_availability,
	PyDoc_STR("*sequence*: Annual energy availability [%]\n\n**Required:**\nTrue"),
 	NULL},
{"energy_curtailment", (getter)AnnualOutput_get_energy_curtailment,(setter)AnnualOutput_set_energy_curtailment,
	PyDoc_STR("*sequence[sequence]*: First year energy curtailment\n\n**Info:**\n(0..1)\n\n**Required:**\nTrue"),
 	NULL},
{"energy_degradation", (getter)AnnualOutput_get_energy_degradation,(setter)AnnualOutput_set_energy_degradation,
	PyDoc_STR("*sequence*: Annual energy degradation [%]\n\n**Required:**\nTrue"),
 	NULL},
{"system_hourly_energy", (getter)AnnualOutput_get_system_hourly_energy,(setter)AnnualOutput_set_system_hourly_energy,
	PyDoc_STR("*sequence*: Hourly energy produced by the system [kW]\n\n**Required:**\nTrue"),
 	NULL},
{"system_use_lifetime_output", (getter)AnnualOutput_get_system_use_lifetime_output,(setter)AnnualOutput_set_system_use_lifetime_output,
	PyDoc_STR("*float*: Lifetime hourly system outputs [0/1]\n\n**Options:**\n0=hourly first year,1=hourly lifetime\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject AnnualOutput_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Annualoutput.AnnualOutput",             /*tp_name*/
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
		AnnualOutput_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		AnnualOutput_getset,          /*tp_getset*/
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
Outputs_new(SAM_Annualoutput data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Annualoutput", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Annualoutput", "Outputs")){
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
Outputs_get_annual_availability(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Annualoutput_Outputs_annual_availability_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_degradation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Annualoutput_Outputs_annual_degradation_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Annualoutput_Outputs_annual_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_hourly_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Annualoutput_Outputs_hourly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Annualoutput_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_availability", (getter)Outputs_get_annual_availability,(setter)0,
	PyDoc_STR("*sequence*: Annual availability"),
 	NULL},
{"annual_degradation", (getter)Outputs_get_annual_degradation,(setter)0,
	PyDoc_STR("*sequence*: Annual degradation"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*sequence*: Annual energy [kWh]"),
 	NULL},
{"hourly_energy", (getter)Outputs_get_hourly_energy,(setter)0,
	PyDoc_STR("*sequence*: Hourly energy [kWh]"),
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	PyDoc_STR("*sequence*: Monthly energy gross [kWh]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Annualoutput.Outputs",             /*tp_name*/
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
 * Annualoutput
 */

static PyTypeObject Annualoutput_Type;

static CmodObject *
newAnnualoutputObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Annualoutput_Type);

	PySAM_TECH_ATTR()

	PyObject* AnnualOutput_obj = AnnualOutput_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "AnnualOutput", AnnualOutput_obj);
	Py_DECREF(AnnualOutput_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Annualoutput methods */

static void
Annualoutput_dealloc(CmodObject *self)
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
Annualoutput_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Annualoutput_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Annualoutput_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Annualoutput"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Annualoutput_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Annualoutput"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Annualoutput_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Annualoutput_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Annualoutput_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Annualoutput_methods[] = {
		{"execute",           (PyCFunction)Annualoutput_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Annualoutput_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'AnnualOutput': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Annualoutput_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'AnnualOutput': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Annualoutput_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Annualoutput_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Annualoutput_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Annualoutput_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Annualoutput_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Annualoutput_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Annualoutput",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Annualoutput_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Annualoutput_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Annualoutput_getattro, /*tp_getattro*/
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
		Annualoutput_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Annualoutput object */

static PyObject *
Annualoutput_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newAnnualoutputObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Annualoutput_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newAnnualoutputObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Annualoutput_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newAnnualoutputObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Annualoutput", def) < 0) {
		Annualoutput_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Annualoutput_from_existing(PyObject *self, PyObject *args)
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

	rv = newAnnualoutputObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Annualoutput", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef AnnualoutputModule_methods[] = {
		{"new",             Annualoutput_new,         METH_VARARGS,
				PyDoc_STR("new() -> Annualoutput")},
		{"default",             Annualoutput_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Annualoutput\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Annualoutput_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Annualoutput\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Annualoutput_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Annualoutput\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Annualoutput");


static int
AnnualoutputModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Annualoutput_Type.tp_dict = PyDict_New();
	if (!Annualoutput_Type.tp_dict) { goto fail; }

	/// Add the AnnualOutput type object to Annualoutput_Type
	if (PyType_Ready(&AnnualOutput_Type) < 0) { goto fail; }
	PyDict_SetItemString(Annualoutput_Type.tp_dict,
				"AnnualOutput",
				(PyObject*)&AnnualOutput_Type);
	Py_DECREF(&AnnualOutput_Type);

	/// Add the Outputs type object to Annualoutput_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Annualoutput_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Annualoutput type object to the module
	if (PyType_Ready(&Annualoutput_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Annualoutput",
				(PyObject*)&Annualoutput_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot AnnualoutputModule_slots[] = {
		{Py_mod_exec, AnnualoutputModule_exec},
		{0, NULL},
};

static struct PyModuleDef AnnualoutputModule = {
		PyModuleDef_HEAD_INIT,
		"Annualoutput",
		module_doc,
		0,
		AnnualoutputModule_methods,
		AnnualoutputModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Annualoutput(void)
{
	return PyModuleDef_Init(&AnnualoutputModule);
}