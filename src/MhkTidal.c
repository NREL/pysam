#include <Python.h>

#include <SAM_MhkTidal.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * MHKTidal Group
 */ 

typedef struct {
	PyObject_HEAD
	SAM_MhkTidal   data_ptr;
} MHKTidalObject;

static PyTypeObject MHKTidal_Type;

static PyObject *
MHKTidal_new(SAM_MhkTidal data_ptr)
{
	PyObject* new_obj = MHKTidal_Type.tp_alloc(&MHKTidal_Type,0);

	MHKTidalObject* MHKTidal_obj = (MHKTidalObject*)new_obj;

	MHKTidal_obj->data_ptr = data_ptr;

	return new_obj;
}

/* MHKTidal methods */

static PyObject *
MHKTidal_assign(MHKTidalObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "MhkTidal", "MHKTidal")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
MHKTidal_export(MHKTidalObject *self, PyObject *args)
{
	PyTypeObject* tp = &MHKTidal_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef MHKTidal_methods[] = {
		{"assign",            (PyCFunction)MHKTidal_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``MHKTidal_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)MHKTidal_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
MHKTidal_get_annual_energy_loss(MHKTidalObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_MHKTidal_annual_energy_loss_nget, self->data_ptr);
}

static int
MHKTidal_set_annual_energy_loss(MHKTidalObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkTidal_MHKTidal_annual_energy_loss_nset, self->data_ptr);
}

static PyObject *
MHKTidal_get_calculate_capacity(MHKTidalObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_MHKTidal_calculate_capacity_nget, self->data_ptr);
}

static int
MHKTidal_set_calculate_capacity(MHKTidalObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkTidal_MHKTidal_calculate_capacity_nset, self->data_ptr);
}

static PyObject *
MHKTidal_get_device_rated_capacity(MHKTidalObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_MHKTidal_device_rated_capacity_nget, self->data_ptr);
}

static int
MHKTidal_set_device_rated_capacity(MHKTidalObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkTidal_MHKTidal_device_rated_capacity_nset, self->data_ptr);
}

static PyObject *
MHKTidal_get_number_devices(MHKTidalObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_MHKTidal_number_devices_nget, self->data_ptr);
}

static int
MHKTidal_set_number_devices(MHKTidalObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkTidal_MHKTidal_number_devices_nset, self->data_ptr);
}

static PyObject *
MHKTidal_get_tidal_power_curve(MHKTidalObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_MhkTidal_MHKTidal_tidal_power_curve_mget, self->data_ptr);
}

static int
MHKTidal_set_tidal_power_curve(MHKTidalObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_MhkTidal_MHKTidal_tidal_power_curve_mset, self->data_ptr);
}

static PyObject *
MHKTidal_get_tidal_resource(MHKTidalObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_MhkTidal_MHKTidal_tidal_resource_mget, self->data_ptr);
}

static int
MHKTidal_set_tidal_resource(MHKTidalObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_MhkTidal_MHKTidal_tidal_resource_mset, self->data_ptr);
}

static PyGetSetDef MHKTidal_getset[] = {
{"annual_energy_loss", (getter)MHKTidal_get_annual_energy_loss,(setter)MHKTidal_set_annual_energy_loss,
	PyDoc_STR("*float*: Total energy losses [%]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"calculate_capacity", (getter)MHKTidal_get_calculate_capacity,(setter)MHKTidal_set_calculate_capacity,
	PyDoc_STR("*float*: Calculate device rated capacity from power curve [0/1]\n\n*Constraints*: INTEGER,MIN=0,MAX=1\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"device_rated_capacity", (getter)MHKTidal_get_device_rated_capacity,(setter)MHKTidal_set_device_rated_capacity,
	PyDoc_STR("*float*: Rated capacity of device [kW]\n\n*Required*: True if calculate_capacity=0"),
 	NULL},
{"number_devices", (getter)MHKTidal_get_number_devices,(setter)MHKTidal_set_number_devices,
	PyDoc_STR("*float*: Number of tidal devices in the system\n\n*Constraints*: INTEGER\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"tidal_power_curve", (getter)MHKTidal_get_tidal_power_curve,(setter)MHKTidal_set_tidal_power_curve,
	PyDoc_STR("*sequence[sequence]*: Power curve of tidal energy device as function of stream speeds [kW]\n\n*Required*: True"),
 	NULL},
{"tidal_resource", (getter)MHKTidal_get_tidal_resource,(setter)MHKTidal_set_tidal_resource,
	PyDoc_STR("*sequence[sequence]*: Frequency distribution of resource as a function of stream speeds\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject MHKTidal_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MhkTidal.MHKTidal",             /*tp_name*/
		sizeof(MHKTidalObject),          /*tp_basicsize*/
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
		MHKTidal_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		MHKTidal_getset,          /*tp_getset*/
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
	SAM_MhkTidal   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_MhkTidal data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "MhkTidal", "Outputs")){
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
Outputs_get_annual_cumulative_energy_distribution(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MhkTidal_Outputs_annual_cumulative_energy_distribution_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MhkTidal_Outputs_annual_energy_distribution_aget, self->data_ptr);
}

static PyObject *
Outputs_get_average_power_device(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_average_power_device_nget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_cumulative_energy_distribution", (getter)Outputs_get_annual_cumulative_energy_distribution,(setter)0,
	PyDoc_STR("*sequence*: Cumulative annual energy production of farm as function of speed [kWh]"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual energy production of farm [kWh]"),
 	NULL},
{"annual_energy_distribution", (getter)Outputs_get_annual_energy_distribution,(setter)0,
	PyDoc_STR("*sequence*: Annual energy production of farm as function of speed [kWh]"),
 	NULL},
{"average_power_device", (getter)Outputs_get_average_power_device,(setter)0,
	PyDoc_STR("*float*: Average power production of a single device [kW]"),
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	PyDoc_STR("*float*: Capacity Factor of farm [%]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MhkTidal.Outputs",             /*tp_name*/
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
 * MhkTidal
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_MhkTidal   data_ptr;
} MhkTidalObject;

static PyTypeObject MhkTidal_Type;

static MhkTidalObject *
newMhkTidalObject(void* data_ptr)
{
	MhkTidalObject *self;
	self = PyObject_New(MhkTidalObject, &MhkTidal_Type);

	PySAM_TECH_ATTR("MhkTidal", SAM_MhkTidal_construct)

	PyObject* MHKTidal_obj = MHKTidal_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "MHKTidal", MHKTidal_obj);
	Py_DECREF(MHKTidal_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);


	return self;
}

/* MhkTidal methods */

static void
MhkTidal_dealloc(MhkTidalObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_MhkTidal_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
MhkTidal_execute(MhkTidalObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_MhkTidal_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
MhkTidal_assign(MhkTidalObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "MhkTidal"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
MhkTidal_export(MhkTidalObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyMethodDef MhkTidal_methods[] = {
		{"execute",            (PyCFunction)MhkTidal_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)MhkTidal_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'MHKTidal': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)MhkTidal_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
MhkTidal_getattro(MhkTidalObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
MhkTidal_setattr(MhkTidalObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject MhkTidal_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MhkTidal",            /*tp_name*/
		sizeof(MhkTidalObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)MhkTidal_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)MhkTidal_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)MhkTidal_getattro, /*tp_getattro*/
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
		MhkTidal_methods,      /*tp_methods*/
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


/* Function of no arguments returning new MhkTidal object */

static PyObject *
MhkTidal_new(PyObject *self, PyObject *args)
{
	MhkTidalObject *rv;
	rv = newMhkTidalObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
MhkTidal_wrap(PyObject *self, PyObject *args)
{
	MhkTidalObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newMhkTidalObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
MhkTidal_default(PyObject *self, PyObject *args)
{
	MhkTidalObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newMhkTidalObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "MhkTidal", def);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef MhkTidalModule_methods[] = {
		{"new",             MhkTidal_new,         METH_VARARGS,
				PyDoc_STR("new() -> MhkTidal")},
		{"default",             MhkTidal_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> MhkTidal\n\nUse financial model-specific default attributes\n"
				"config options:\n\n- \"MHKtidalLCOECalculator\"")},
		{"wrap",             MhkTidal_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> MhkTidal\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Tidal marine hydrokinetic system");


static int
MhkTidalModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error(m) < 0) goto fail;

	MhkTidal_Type.tp_dict = PyDict_New();
	if (!MhkTidal_Type.tp_dict) { goto fail; }

	/// Add the MHKTidal type object to MhkTidal_Type
	if (PyType_Ready(&MHKTidal_Type) < 0) { goto fail; }
	PyDict_SetItemString(MhkTidal_Type.tp_dict,
				"MHKTidal",
				(PyObject*)&MHKTidal_Type);
	Py_DECREF(&MHKTidal_Type);

	/// Add the Outputs type object to MhkTidal_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(MhkTidal_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the MhkTidal type object to the module
	if (PyType_Ready(&MhkTidal_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"MhkTidal",
				(PyObject*)&MhkTidal_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot MhkTidalModule_slots[] = {
		{Py_mod_exec, MhkTidalModule_exec},
		{0, NULL},
};

static struct PyModuleDef MhkTidalModule = {
		PyModuleDef_HEAD_INIT,
		"MhkTidal",
		module_doc,
		0,
		MhkTidalModule_methods,
		MhkTidalModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_MhkTidal(void)
{
	return PyModuleDef_Init(&MhkTidalModule);
}