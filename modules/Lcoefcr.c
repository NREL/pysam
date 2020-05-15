#include <Python.h>

#include <SAM_Lcoefcr.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * SimpleLCOE Group
 */ 

static PyTypeObject SimpleLCOE_Type;

static PyObject *
SimpleLCOE_new(SAM_Lcoefcr data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Lcoefcr", "SimpleLCOE")){
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
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``SimpleLCOE_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SimpleLCOE_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SimpleLCOE_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Lcoefcr_SimpleLCOE_annual_energy_nget, self->data_ptr);
}

static int
SimpleLCOE_set_annual_energy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Lcoefcr_SimpleLCOE_annual_energy_nset, self->data_ptr);
}

static PyObject *
SimpleLCOE_get_capital_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Lcoefcr_SimpleLCOE_capital_cost_nget, self->data_ptr);
}

static int
SimpleLCOE_set_capital_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Lcoefcr_SimpleLCOE_capital_cost_nset, self->data_ptr);
}

static PyObject *
SimpleLCOE_get_fixed_charge_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Lcoefcr_SimpleLCOE_fixed_charge_rate_nget, self->data_ptr);
}

static int
SimpleLCOE_set_fixed_charge_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Lcoefcr_SimpleLCOE_fixed_charge_rate_nset, self->data_ptr);
}

static PyObject *
SimpleLCOE_get_fixed_operating_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Lcoefcr_SimpleLCOE_fixed_operating_cost_nget, self->data_ptr);
}

static int
SimpleLCOE_set_fixed_operating_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Lcoefcr_SimpleLCOE_fixed_operating_cost_nset, self->data_ptr);
}

static PyObject *
SimpleLCOE_get_variable_operating_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Lcoefcr_SimpleLCOE_variable_operating_cost_nget, self->data_ptr);
}

static int
SimpleLCOE_set_variable_operating_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Lcoefcr_SimpleLCOE_variable_operating_cost_nset, self->data_ptr);
}

static PyGetSetDef SimpleLCOE_getset[] = {
{"annual_energy", (getter)SimpleLCOE_get_annual_energy,(setter)SimpleLCOE_set_annual_energy,
	PyDoc_STR("*float*: Annual energy production [kWh]\n\n*Required*: True"),
 	NULL},
{"capital_cost", (getter)SimpleLCOE_get_capital_cost,(setter)SimpleLCOE_set_capital_cost,
	PyDoc_STR("*float*: Capital cost [$]\n\n*Required*: True"),
 	NULL},
{"fixed_charge_rate", (getter)SimpleLCOE_get_fixed_charge_rate,(setter)SimpleLCOE_set_fixed_charge_rate,
	PyDoc_STR("*float*: Fixed charge rate\n\n*Required*: True"),
 	NULL},
{"fixed_operating_cost", (getter)SimpleLCOE_get_fixed_operating_cost,(setter)SimpleLCOE_set_fixed_operating_cost,
	PyDoc_STR("*float*: Annual fixed operating cost [$]\n\n*Required*: True"),
 	NULL},
{"variable_operating_cost", (getter)SimpleLCOE_get_variable_operating_cost,(setter)SimpleLCOE_set_variable_operating_cost,
	PyDoc_STR("*float*: Annual variable operating cost [$/kWh]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SimpleLCOE_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Lcoefcr.SimpleLCOE",             /*tp_name*/
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
 * Outputs Group
 */ 

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Lcoefcr data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Lcoefcr", "Outputs")){
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
Outputs_get_lcoe_fcr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Lcoefcr_Outputs_lcoe_fcr_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"lcoe_fcr", (getter)Outputs_get_lcoe_fcr,(setter)0,
	PyDoc_STR("*float*: Levelized cost of energy [$/kWh]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Lcoefcr.Outputs",             /*tp_name*/
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
 * Lcoefcr
 */

static PyTypeObject Lcoefcr_Type;

static CmodObject *
newLcoefcrObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Lcoefcr_Type);

	PySAM_TECH_ATTR()

	PyObject* SimpleLCOE_obj = SimpleLCOE_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SimpleLCOE", SimpleLCOE_obj);
	Py_DECREF(SimpleLCOE_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Lcoefcr methods */

static void
Lcoefcr_dealloc(CmodObject *self)
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
Lcoefcr_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Lcoefcr_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Lcoefcr_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Lcoefcr"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Lcoefcr_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Lcoefcr_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef Lcoefcr_methods[] = {
		{"execute",            (PyCFunction)Lcoefcr_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Lcoefcr_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Simple LCOE': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Lcoefcr_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Lcoefcr_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Lcoefcr_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Lcoefcr_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Lcoefcr_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Lcoefcr",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Lcoefcr_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Lcoefcr_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Lcoefcr_getattro, /*tp_getattro*/
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
		Lcoefcr_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Lcoefcr object */

static PyObject *
Lcoefcr_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newLcoefcrObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Lcoefcr_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newLcoefcrObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Lcoefcr_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newLcoefcrObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Lcoefcr", def);

	return (PyObject *)rv;
}

static PyObject *
Lcoefcr_from_existing(PyObject *self, PyObject *args)
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

	rv = newLcoefcrObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Lcoefcr", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef LcoefcrModule_methods[] = {
		{"new",             Lcoefcr_new,         METH_VARARGS,
				PyDoc_STR("new() -> Lcoefcr")},
		{"default",             Lcoefcr_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Lcoefcr\n\nUse financial config-specific default attributes\n"
				"config options:\n\n- \"BiopowerLCOECalculator\"\n- \"DSGLIPHLCOHCalculator\"\n- \"DSLFLCOECalculator\"\n- \"DishStirlingLCOECalculator\"\n- \"EmpiricalTroughLCOECalculator\"\n- \"FlatPlatePVLCOECalculator\"\n- \"GenericCSPSystemLCOECalculator\"\n- \"GenericSystemLCOECalculator\"\n- \"GeothermalPowerLCOECalculator\"\n- \"HighXConcentratingPVLCOECalculator\"\n- \"MEtidalLCOECalculator\"\n- \"MEwaveLCOECalculator\"\n- \"MSLFLCOECalculator\"\n- \"PVWattsLCOECalculator\"\n- \"PhysicalTroughIPHLCOHCalculator\"\n- \"PhysicalTroughLCOECalculator\"\n- \"SolarWaterHeatingLCOECalculator\"\n- \"WindPowerLCOECalculator\"")},
		{"wrap",             Lcoefcr_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Lcoefcr\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   Lcoefcr_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Lcoefcr\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Calculate levelized cost of electricity using fixed charge rate method instead of cash flow");


static int
LcoefcrModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Lcoefcr_Type.tp_dict = PyDict_New();
	if (!Lcoefcr_Type.tp_dict) { goto fail; }

	/// Add the SimpleLCOE type object to Lcoefcr_Type
	if (PyType_Ready(&SimpleLCOE_Type) < 0) { goto fail; }
	PyDict_SetItemString(Lcoefcr_Type.tp_dict,
				"SimpleLCOE",
				(PyObject*)&SimpleLCOE_Type);
	Py_DECREF(&SimpleLCOE_Type);

	/// Add the Outputs type object to Lcoefcr_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Lcoefcr_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Lcoefcr type object to the module
	if (PyType_Ready(&Lcoefcr_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Lcoefcr",
				(PyObject*)&Lcoefcr_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot LcoefcrModule_slots[] = {
		{Py_mod_exec, LcoefcrModule_exec},
		{0, NULL},
};

static struct PyModuleDef LcoefcrModule = {
		PyModuleDef_HEAD_INIT,
		"Lcoefcr",
		module_doc,
		0,
		LcoefcrModule_methods,
		LcoefcrModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Lcoefcr(void)
{
	return PyModuleDef_Init(&LcoefcrModule);
}