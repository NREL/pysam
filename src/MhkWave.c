#include <Python.h>

#include <SAM_MhkWave.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * MHKWave Group
 */ 

typedef struct {
	PyObject_HEAD
	SAM_MhkWave   data_ptr;
} MHKWaveObject;

static PyTypeObject MHKWave_Type;

static PyObject *
MHKWave_new(SAM_MhkWave data_ptr)
{
	PyObject* new_obj = MHKWave_Type.tp_alloc(&MHKWave_Type,0);

	MHKWaveObject* MHKWave_obj = (MHKWaveObject*)new_obj;

	MHKWave_obj->data_ptr = data_ptr;

	return new_obj;
}

/* MHKWave methods */

static PyObject *
MHKWave_assign(MHKWaveObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "MhkWave", "MHKWave")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
MHKWave_export(MHKWaveObject *self, PyObject *args)
{
	PyTypeObject* tp = &MHKWave_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef MHKWave_methods[] = {
		{"assign",            (PyCFunction)MHKWave_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``MHKWave_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)MHKWave_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
MHKWave_get_annual_energy_loss(MHKWaveObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkWave_MHKWave_annual_energy_loss_nget, self->data_ptr);
}

static int
MHKWave_set_annual_energy_loss(MHKWaveObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkWave_MHKWave_annual_energy_loss_nset, self->data_ptr);
}

static PyObject *
MHKWave_get_calculate_capacity(MHKWaveObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkWave_MHKWave_calculate_capacity_nget, self->data_ptr);
}

static int
MHKWave_set_calculate_capacity(MHKWaveObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkWave_MHKWave_calculate_capacity_nset, self->data_ptr);
}

static PyObject *
MHKWave_get_rated_capacity(MHKWaveObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkWave_MHKWave_rated_capacity_nget, self->data_ptr);
}

static int
MHKWave_set_rated_capacity(MHKWaveObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkWave_MHKWave_rated_capacity_nset, self->data_ptr);
}

static PyObject *
MHKWave_get_wave_power_curve(MHKWaveObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_MhkWave_MHKWave_wave_power_curve_mget, self->data_ptr);
}

static int
MHKWave_set_wave_power_curve(MHKWaveObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_MhkWave_MHKWave_wave_power_curve_mset, self->data_ptr);
}

static PyObject *
MHKWave_get_wave_resource_definition(MHKWaveObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_MhkWave_MHKWave_wave_resource_definition_mget, self->data_ptr);
}

static int
MHKWave_set_wave_resource_definition(MHKWaveObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_MhkWave_MHKWave_wave_resource_definition_mset, self->data_ptr);
}

static PyGetSetDef MHKWave_getset[] = {
{"annual_energy_loss", (getter)MHKWave_get_annual_energy_loss,(setter)MHKWave_set_annual_energy_loss,
	PyDoc_STR("*float*: Total energy losses [%]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"calculate_capacity", (getter)MHKWave_get_calculate_capacity,(setter)MHKWave_set_calculate_capacity,
	PyDoc_STR("*float*: Calculate capacity outside UI? [0/1]\n\n*Constraints*: INTEGER,MIN=0,MAX=1\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"rated_capacity", (getter)MHKWave_get_rated_capacity,(setter)MHKWave_set_rated_capacity,
	PyDoc_STR("*float*: Rated Capacity of System [kW]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"wave_power_curve", (getter)MHKWave_get_wave_power_curve,(setter)MHKWave_set_wave_power_curve,
	PyDoc_STR("*sequence[sequence]*: Wave Power Matrix\n\n*Required*: True"),
 	NULL},
{"wave_resource_definition", (getter)MHKWave_get_wave_resource_definition,(setter)MHKWave_set_wave_resource_definition,
	PyDoc_STR("*sequence[sequence]*: Frequency distribution of resource as a function of Hs and Te\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject MHKWave_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MhkWave.MHKWave",             /*tp_name*/
		sizeof(MHKWaveObject),          /*tp_basicsize*/
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
		MHKWave_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		MHKWave_getset,          /*tp_getset*/
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

typedef struct {
	PyObject_HEAD
	SAM_MhkWave   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_MhkWave data_ptr)
{
	PyObject* new_obj = Outputs_Type.tp_alloc(&Outputs_Type,0);

	OutputsObject* Outputs_obj = (OutputsObject*)new_obj;

	Outputs_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Outputs methods */

static PyObject *
Outputs_assign(OutputsObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "MhkWave", "Outputs")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Outputs_export(OutputsObject *self, PyObject *args)
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
Outputs_get_annual_energy(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkWave_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution(OutputsObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_MhkWave_Outputs_annual_energy_distribution_mget, self->data_ptr);
}

static PyObject *
Outputs_get_average_power(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkWave_Outputs_average_power_nget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkWave_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual energy production [kWh]"),
 	NULL},
{"annual_energy_distribution", (getter)Outputs_get_annual_energy_distribution,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Annual energy production as function of Hs and Te"),
 	NULL},
{"average_power", (getter)Outputs_get_average_power,(setter)0,
	PyDoc_STR("*float*: Average power production [kW]"),
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	PyDoc_STR("*float*: Capacity Factor [%]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MhkWave.Outputs",             /*tp_name*/
		sizeof(OutputsObject),          /*tp_basicsize*/
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
 * MhkWave
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_MhkWave   data_ptr;
} MhkWaveObject;

static PyTypeObject MhkWave_Type;

static MhkWaveObject *
newMhkWaveObject(void* data_ptr)
{
	MhkWaveObject *self;
	self = PyObject_New(MhkWaveObject, &MhkWave_Type);

	PySAM_TECH_ATTR("MhkWave", SAM_MhkWave_construct)

	PyObject* MHKWave_obj = MHKWave_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "MHKWave", MHKWave_obj);
	Py_DECREF(MHKWave_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);


	return self;
}

/* MhkWave methods */

static void
MhkWave_dealloc(MhkWaveObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_MhkWave_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
MhkWave_execute(MhkWaveObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_MhkWave_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
MhkWave_assign(MhkWaveObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "MhkWave"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
MhkWave_export(MhkWaveObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyMethodDef MhkWave_methods[] = {
		{"execute",            (PyCFunction)MhkWave_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)MhkWave_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'MHKWave': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)MhkWave_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
MhkWave_getattro(MhkWaveObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
MhkWave_setattr(MhkWaveObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject MhkWave_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MhkWave",            /*tp_name*/
		sizeof(MhkWaveObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)MhkWave_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)MhkWave_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)MhkWave_getattro, /*tp_getattro*/
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
		MhkWave_methods,      /*tp_methods*/
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


/* Function of no arguments returning new MhkWave object */

static PyObject *
MhkWave_new(PyObject *self, PyObject *args)
{
	MhkWaveObject *rv;
	rv = newMhkWaveObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
MhkWave_wrap(PyObject *self, PyObject *args)
{
	MhkWaveObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newMhkWaveObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
MhkWave_default(PyObject *self, PyObject *args)
{
	MhkWaveObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newMhkWaveObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "MhkWave", def);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef MhkWaveModule_methods[] = {
		{"new",             MhkWave_new,         METH_VARARGS,
				PyDoc_STR("new() -> MhkWave")},
		{"default",             MhkWave_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> MhkWave\n\nUse financial model-specific default attributes\n"
				"config options:\n\n- \"MHKwaveLCOECalculator\"")},
		{"wrap",             MhkWave_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> MhkWave\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Wave marine hydrokinetic system");


static int
MhkWaveModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error(m) < 0) goto fail;

	MhkWave_Type.tp_dict = PyDict_New();
	if (!MhkWave_Type.tp_dict) { goto fail; }

	/// Add the MHKWave type object to MhkWave_Type
	if (PyType_Ready(&MHKWave_Type) < 0) { goto fail; }
	PyDict_SetItemString(MhkWave_Type.tp_dict,
				"MHKWave",
				(PyObject*)&MHKWave_Type);
	Py_DECREF(&MHKWave_Type);

	/// Add the Outputs type object to MhkWave_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(MhkWave_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the MhkWave type object to the module
	if (PyType_Ready(&MhkWave_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"MhkWave",
				(PyObject*)&MhkWave_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot MhkWaveModule_slots[] = {
		{Py_mod_exec, MhkWaveModule_exec},
		{0, NULL},
};

static struct PyModuleDef MhkWaveModule = {
		PyModuleDef_HEAD_INIT,
		"MhkWave",
		module_doc,
		0,
		MhkWaveModule_methods,
		MhkWaveModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_MhkWave(void)
{
	return PyModuleDef_Init(&MhkWaveModule);
}