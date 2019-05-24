#include <Python.h>

#include <SAM_Grid.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Outputs Group
 */ 

typedef struct {
	PyObject_HEAD
	SAM_Grid   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Grid data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Grid", "Outputs")){
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

static PyGetSetDef Outputs_getset[] = {
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Grid.Outputs",             /*tp_name*/
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
 * Grid
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_Grid   data_ptr;
} GridObject;

static PyTypeObject Grid_Type;

static GridObject *
newGridObject(void* data_ptr)
{
	GridObject *self;
	self = PyObject_New(GridObject, &Grid_Type);

	PySAM_TECH_ATTR("Grid", SAM_Grid_construct)

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);


	return self;
}

/* Grid methods */

static void
Grid_dealloc(GridObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_Grid_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
Grid_execute(GridObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Grid_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Grid_assign(GridObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Grid"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Grid_export(GridObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyMethodDef Grid_methods[] = {
		{"execute",            (PyCFunction)Grid_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Grid_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Outputs': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Grid_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Grid_getattro(GridObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Grid_setattr(GridObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Grid_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Grid",            /*tp_name*/
		sizeof(GridObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Grid_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Grid_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Grid_getattro, /*tp_getattro*/
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
		Grid_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Grid object */

static PyObject *
Grid_new(PyObject *self, PyObject *args)
{
	GridObject *rv;
	rv = newGridObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Grid_wrap(PyObject *self, PyObject *args)
{
	GridObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newGridObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Grid_default(PyObject *self, PyObject *args)
{
	GridObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newGridObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Grid", def);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef GridModule_methods[] = {
		{"new",             Grid_new,         METH_VARARGS,
				PyDoc_STR("new() -> Grid")},
		{"default",             Grid_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Grid\n\nUse financial model-specific default attributes\n"
				"config options:\n\n- \"FlatPlatePVAllEquityPartnershipFlip\"\n- \"FlatPlatePVCommercial\"\n- \"FlatPlatePVCommercialPPA\"\n- \"FlatPlatePVHostDeveloper\"\n- \"FlatPlatePVIndependentPowerProducer\"\n- \"FlatPlatePVLeveragedPartnershipFlip\"\n- \"FlatPlatePVResidential\"\n- \"FlatPlatePVSaleLeaseback\"\n- \"FlatPlatePVSingleOwner\"\n- \"FlatPlatePVThirdParty\"\n- \"FuelCellCommercial\"\n- \"FuelCellSingleOwner\"\n- \"GenericSystemAllEquityPartnershipFlip\"\n- \"GenericSystemCommercial\"\n- \"GenericSystemCommercialPPA\"\n- \"GenericSystemHostDeveloper\"\n- \"GenericSystemIndependentPowerProducer\"\n- \"GenericSystemLCOECalculator\"\n- \"GenericSystemLeveragedPartnershipFlip\"\n- \"GenericSystemNone\"\n- \"GenericSystemResidential\"\n- \"GenericSystemSaleLeaseback\"\n- \"GenericSystemSingleOwner\"\n- \"GenericSystemThirdParty\"\n- \"GeothermalPowerAllEquityPartnershipFlip\"\n- \"GeothermalPowerIndependentPowerProducer\"\n- \"GeothermalPowerLCOECalculator\"\n- \"GeothermalPowerLeveragedPartnershipFlip\"\n- \"GeothermalPowerNone\"\n- \"GeothermalPowerSaleLeaseback\"\n- \"GeothermalPowerSingleOwner\"\n- \"PVWattsAllEquityPartnershipFlip\"\n- \"PVWattsCommercial\"\n- \"PVWattsCommercialPPA\"\n- \"PVWattsHostDeveloper\"\n- \"PVWattsIndependentPowerProducer\"\n- \"PVWattsLCOECalculator\"\n- \"PVWattsLeveragedPartnershipFlip\"\n- \"PVWattsNone\"\n- \"PVWattsResidential\"\n- \"PVWattsSaleLeaseback\"\n- \"PVWattsSingleOwner\"\n- \"PVWattsThirdParty\"\n- \"WindPowerAllEquityPartnershipFlip\"\n- \"WindPowerCommercial\"\n- \"WindPowerCommercialPPA\"\n- \"WindPowerIndependentPowerProducer\"\n- \"WindPowerLCOECalculator\"\n- \"WindPowerLeveragedPartnershipFlip\"\n- \"WindPowerNone\"\n- \"WindPowerResidential\"\n- \"WindPowerSaleLeaseback\"\n- \"WindPowerSingleOwner\"")},
		{"wrap",             Grid_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Grid\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Electric grid model");


static int
GridModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error(m) < 0) goto fail;

	Grid_Type.tp_dict = PyDict_New();
	if (!Grid_Type.tp_dict) { goto fail; }

	/// Add the Outputs type object to Grid_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Grid_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Grid type object to the module
	if (PyType_Ready(&Grid_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Grid",
				(PyObject*)&Grid_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot GridModule_slots[] = {
		{Py_mod_exec, GridModule_exec},
		{0, NULL},
};

static struct PyModuleDef GridModule = {
		PyModuleDef_HEAD_INIT,
		"Grid",
		module_doc,
		0,
		GridModule_methods,
		GridModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Grid(void)
{
	return PyModuleDef_Init(&GridModule);
}