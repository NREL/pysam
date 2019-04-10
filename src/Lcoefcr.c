#include <Python.h>

#include <SAM_Lcoefcr.h>
#include <SAM_api.h>

#include "PySAM_utils.h"



	/*
	 * FinancialParameters Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Lcoefcr   data_ptr;
} FinancialParametersObject;

static PyTypeObject FinancialParameters_Type;

static PyObject *
FinancialParameters_new(SAM_Lcoefcr data_ptr)
{
	PyObject* new_obj = FinancialParameters_Type.tp_alloc(&FinancialParameters_Type,0);

	FinancialParametersObject* FinancialParameters_obj = (FinancialParametersObject*)new_obj;

	FinancialParameters_obj->data_ptr = data_ptr;

	return new_obj;
}

/* FinancialParameters methods */

static PyObject *
FinancialParameters_assign(FinancialParametersObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Lcoefcr", "FinancialParameters")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialParameters_export(FinancialParametersObject *self, PyObject *args)
{
	PyTypeObject* tp = &FinancialParameters_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef FinancialParameters_methods[] = {
		{"assign",            (PyCFunction)FinancialParameters_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)FinancialParameters_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
FinancialParameters_get_capital_cost(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Lcoefcr_FinancialParameters_capital_cost_fget, self->data_ptr);
}

static int
FinancialParameters_set_capital_cost(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Lcoefcr_FinancialParameters_capital_cost_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_fixed_charge_rate(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Lcoefcr_FinancialParameters_fixed_charge_rate_fget, self->data_ptr);
}

static int
FinancialParameters_set_fixed_charge_rate(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Lcoefcr_FinancialParameters_fixed_charge_rate_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_fixed_operating_cost(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Lcoefcr_FinancialParameters_fixed_operating_cost_fget, self->data_ptr);
}

static int
FinancialParameters_set_fixed_operating_cost(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Lcoefcr_FinancialParameters_fixed_operating_cost_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_variable_operating_cost(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Lcoefcr_FinancialParameters_variable_operating_cost_fget, self->data_ptr);
}

static int
FinancialParameters_set_variable_operating_cost(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Lcoefcr_FinancialParameters_variable_operating_cost_fset, self->data_ptr);
}

static PyGetSetDef FinancialParameters_getset[] = {
{"capital_cost", (getter)FinancialParameters_get_capital_cost,(setter)FinancialParameters_set_capital_cost,
	"Capital cost [$], number.\n Required if: *.",
 	NULL},
{"fixed_charge_rate", (getter)FinancialParameters_get_fixed_charge_rate,(setter)FinancialParameters_set_fixed_charge_rate,
	"Fixed charge rate [], number.\n Required if: *.",
 	NULL},
{"fixed_operating_cost", (getter)FinancialParameters_get_fixed_operating_cost,(setter)FinancialParameters_set_fixed_operating_cost,
	"Annual fixed operating cost [$], number.\n Required if: *.",
 	NULL},
{"variable_operating_cost", (getter)FinancialParameters_get_variable_operating_cost,(setter)FinancialParameters_set_variable_operating_cost,
	"Annual variable operating cost [$/kWh], number.\n Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FinancialParameters_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Lcoefcr.FinancialParameters",             /*tp_name*/
		sizeof(FinancialParametersObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		FinancialParameters_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		FinancialParameters_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * SimpleLCOE Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Lcoefcr   data_ptr;
} SimpleLCOEObject;

static PyTypeObject SimpleLCOE_Type;

static PyObject *
SimpleLCOE_new(SAM_Lcoefcr data_ptr)
{
	PyObject* new_obj = SimpleLCOE_Type.tp_alloc(&SimpleLCOE_Type,0);

	SimpleLCOEObject* SimpleLCOE_obj = (SimpleLCOEObject*)new_obj;

	SimpleLCOE_obj->data_ptr = data_ptr;

	return new_obj;
}

/* SimpleLCOE methods */

static PyObject *
SimpleLCOE_assign(SimpleLCOEObject *self, PyObject *args)
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
SimpleLCOE_export(SimpleLCOEObject *self, PyObject *args)
{
	PyTypeObject* tp = &SimpleLCOE_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SimpleLCOE_methods[] = {
		{"assign",            (PyCFunction)SimpleLCOE_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)SimpleLCOE_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SimpleLCOE_get_annual_energy(SimpleLCOEObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Lcoefcr_SimpleLCOE_annual_energy_fget, self->data_ptr);
}

static int
SimpleLCOE_set_annual_energy(SimpleLCOEObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Lcoefcr_SimpleLCOE_annual_energy_fset, self->data_ptr);
}

static PyGetSetDef SimpleLCOE_getset[] = {
{"annual_energy", (getter)SimpleLCOE_get_annual_energy,(setter)SimpleLCOE_set_annual_energy,
	"Annual energy production [kWh], number.\n Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SimpleLCOE_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Lcoefcr.SimpleLCOE",             /*tp_name*/
		sizeof(SimpleLCOEObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		SimpleLCOE_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SimpleLCOE_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
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
	SAM_Lcoefcr   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Lcoefcr data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Lcoefcr", "Outputs")){
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
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Outputs_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Outputs_get_lcoe_fcr(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Lcoefcr_Outputs_lcoe_fcr_fget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"lcoe_fcr", (getter)Outputs_get_lcoe_fcr,(setter)0,
	"Levelized cost of energy [$/kWh], number.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Lcoefcr.Outputs",             /*tp_name*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Outputs_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Outputs_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};

/*
 * Lcoefcr
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_Lcoefcr   data_ptr;
} LcoefcrObject;

static PyTypeObject Lcoefcr_Type;

#define LcoefcrObject_Check(v)      (Py_TYPE(v) == &Lcoefcr_Type)

static LcoefcrObject *
newLcoefcrObject(void* data_ptr)
{
	LcoefcrObject *self;
	self = PyObject_New(LcoefcrObject, &Lcoefcr_Type);

	PySAM_TECH_ATTR("Lcoefcr", SAM_Lcoefcr_construct)

PyObject* FinancialParameters_obj = FinancialParameters_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FinancialParameters", FinancialParameters_obj);
	Py_DECREF(FinancialParameters_obj);

PyObject* SimpleLCOE_obj = SimpleLCOE_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SimpleLCOE", SimpleLCOE_obj);
	Py_DECREF(SimpleLCOE_obj);

PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

PyObject* AdjustmentFactorsModule = PyImport_ImportModule("AdjustmentFactors");

	PyObject* data_cap = PyCapsule_New(self->data_ptr, NULL, NULL);
	PyObject* Adjust_obj = PyObject_CallMethod(AdjustmentFactorsModule, "new", "(O)", data_cap);
	Py_XDECREF(data_cap);
	Py_XDECREF(AdjustmentFactorsModule);

	if (!Adjust_obj){
		PyErr_SetString(PySAM_ErrorObject, "Couldn't create AdjustmentFactorsObject\n");
		return NULL;
	}

	PyDict_SetItemString(attr_dict, "AdjustmentFactors", Adjust_obj);
	Py_DECREF(Adjust_obj);

	return self;
}

/* Lcoefcr methods */

static void
Lcoefcr_dealloc(LcoefcrObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_Lcoefcr_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
Lcoefcr_execute(LcoefcrObject *self, PyObject *args)
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
Lcoefcr_assign(LcoefcrObject *self, PyObject *args)
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
Lcoefcr_export(LcoefcrObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyMethodDef Lcoefcr_methods[] = {
		{"execute",            (PyCFunction)Lcoefcr_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Lcoefcr_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs")},
		{"export",            (PyCFunction)Lcoefcr_export,  METH_VARARGS,
				PyDoc_STR("assign() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Lcoefcr_getattro(LcoefcrObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Lcoefcr_setattr(LcoefcrObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Lcoefcr_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Lcoefcr",            /*tp_name*/
		sizeof(LcoefcrObject),/*tp_basicsize*/
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
		"see html for help",        /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Lcoefcr_methods,      /*tp_methods*/
		0,                          /*tp_members*/
		0,       /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
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
	LcoefcrObject *rv;
	rv = newLcoefcrObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Lcoefcr_wrap(PyObject *self, PyObject *args)
{
	LcoefcrObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newLcoefcrObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Lcoefcr_default(PyObject *self, PyObject *args)
{
	LcoefcrObject *rv;
	char* fin = 0;
	if (!PyArg_ParseTuple(args, "s:default", &fin)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newLcoefcrObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Lcoefcr", fin);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef LcoefcrModule_methods[] = {
		{"new",             Lcoefcr_new,         METH_VARARGS,
				PyDoc_STR("new() -> new Lcoefcr object")},
		{"default",             Lcoefcr_default,         METH_VARARGS,
				PyDoc_STR("default(financial) -> new Lcoefcr object with financial model-specific default attributes\n"
				"Options: Single Owner, Sale Leaseback, Leveraged Partnership Flip, Commercial, LCOE Calculator, All Equity Partnership Flip, None, ")},
		{"wrap",             Lcoefcr_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> new Lcoefcr object around existing PySSC data")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Refer to http://www.github.com/nrel/PySAM for source code.");


static int
LcoefcrModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	Lcoefcr_Type.tp_dict = PyDict_New();
	if (!Lcoefcr_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to Lcoefcr_Type
	PyObject* AdjustmentFactorsModule = PyImport_ImportModule("AdjustmentFactors");
	if (!AdjustmentFactorsModule){
		PyErr_SetImportError(PyUnicode_FromString("Could not import AdjustmentFactors module."), NULL, NULL);
	}

	PyTypeObject* AdjustmentFactors_Type = (PyTypeObject*)PyObject_GetAttrString(AdjustmentFactorsModule, "AdjustmentFactors");
	if (!AdjustmentFactors_Type){
		PyErr_SetImportError(PyUnicode_FromString("Could not import AdjustmentFactors type."), NULL, NULL);
	}
	Py_XDECREF(AdjustmentFactorsModule);

	if (PyType_Ready(AdjustmentFactors_Type) < 0) { goto fail; }
	PyDict_SetItemString(Lcoefcr_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the FinancialParameters type object to Lcoefcr_Type
	if (PyType_Ready(&FinancialParameters_Type) < 0) { goto fail; }
	PyDict_SetItemString(Lcoefcr_Type.tp_dict,
				"FinancialParameters",
				(PyObject*)&FinancialParameters_Type);
	Py_DECREF(&FinancialParameters_Type);

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

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error() < 0) goto fail;

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