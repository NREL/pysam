#include <Python.h>

#include <SAM_6parsolve.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * SixParameterSolver Group
 */ 

static PyTypeObject SixParameterSolver_Type;

static PyObject *
SixParameterSolver_new(SAM_6parsolve data_ptr)
{
	PyObject* new_obj = SixParameterSolver_Type.tp_alloc(&SixParameterSolver_Type,0);

	VarGroupObject* SixParameterSolver_obj = (VarGroupObject*)new_obj;

	SixParameterSolver_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SixParameterSolver methods */

static PyObject *
SixParameterSolver_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "6parsolve", "SixParameterSolver")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SixParameterSolver_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SixParameterSolver_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SixParameterSolver_methods[] = {
		{"assign",            (PyCFunction)SixParameterSolver_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``SixParameterSolver_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SixParameterSolver_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SixParameterSolver_get_Imp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_6parsolve_SixParameterSolver_Imp_nget, self->data_ptr);
}

static int
SixParameterSolver_set_Imp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_6parsolve_SixParameterSolver_Imp_nset, self->data_ptr);
}

static PyObject *
SixParameterSolver_get_Isc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_6parsolve_SixParameterSolver_Isc_nget, self->data_ptr);
}

static int
SixParameterSolver_set_Isc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_6parsolve_SixParameterSolver_Isc_nset, self->data_ptr);
}

static PyObject *
SixParameterSolver_get_Nser(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_6parsolve_SixParameterSolver_Nser_nget, self->data_ptr);
}

static int
SixParameterSolver_set_Nser(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_6parsolve_SixParameterSolver_Nser_nset, self->data_ptr);
}

static PyObject *
SixParameterSolver_get_Tref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_6parsolve_SixParameterSolver_Tref_nget, self->data_ptr);
}

static int
SixParameterSolver_set_Tref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_6parsolve_SixParameterSolver_Tref_nset, self->data_ptr);
}

static PyObject *
SixParameterSolver_get_Vmp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_6parsolve_SixParameterSolver_Vmp_nget, self->data_ptr);
}

static int
SixParameterSolver_set_Vmp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_6parsolve_SixParameterSolver_Vmp_nset, self->data_ptr);
}

static PyObject *
SixParameterSolver_get_Voc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_6parsolve_SixParameterSolver_Voc_nget, self->data_ptr);
}

static int
SixParameterSolver_set_Voc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_6parsolve_SixParameterSolver_Voc_nset, self->data_ptr);
}

static PyObject *
SixParameterSolver_get_alpha_isc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_6parsolve_SixParameterSolver_alpha_isc_nget, self->data_ptr);
}

static int
SixParameterSolver_set_alpha_isc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_6parsolve_SixParameterSolver_alpha_isc_nset, self->data_ptr);
}

static PyObject *
SixParameterSolver_get_beta_voc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_6parsolve_SixParameterSolver_beta_voc_nget, self->data_ptr);
}

static int
SixParameterSolver_set_beta_voc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_6parsolve_SixParameterSolver_beta_voc_nset, self->data_ptr);
}

static PyObject *
SixParameterSolver_get_celltype(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_6parsolve_SixParameterSolver_celltype_sget, self->data_ptr);
}

static int
SixParameterSolver_set_celltype(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_6parsolve_SixParameterSolver_celltype_sset, self->data_ptr);
}

static PyObject *
SixParameterSolver_get_gamma_pmp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_6parsolve_SixParameterSolver_gamma_pmp_nget, self->data_ptr);
}

static int
SixParameterSolver_set_gamma_pmp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_6parsolve_SixParameterSolver_gamma_pmp_nset, self->data_ptr);
}

static PyGetSetDef SixParameterSolver_getset[] = {
{"Imp", (getter)SixParameterSolver_get_Imp,(setter)SixParameterSolver_set_Imp,
	PyDoc_STR("*float*: Maximum power point current [A]\n\n*Required*: True"),
 	NULL},
{"Isc", (getter)SixParameterSolver_get_Isc,(setter)SixParameterSolver_set_Isc,
	PyDoc_STR("*float*: Short circuit current [A]\n\n*Required*: True"),
 	NULL},
{"Nser", (getter)SixParameterSolver_get_Nser,(setter)SixParameterSolver_set_Nser,
	PyDoc_STR("*float*: Number of cells in series\n\n*Constraints*: INTEGER,POSITIVE\n\n*Required*: True"),
 	NULL},
{"Tref", (getter)SixParameterSolver_get_Tref,(setter)SixParameterSolver_set_Tref,
	PyDoc_STR("*float*: Reference cell temperature ['C]\n\n*Required*: False"),
 	NULL},
{"Vmp", (getter)SixParameterSolver_get_Vmp,(setter)SixParameterSolver_set_Vmp,
	PyDoc_STR("*float*: Maximum power point voltage [V]\n\n*Required*: True"),
 	NULL},
{"Voc", (getter)SixParameterSolver_get_Voc,(setter)SixParameterSolver_set_Voc,
	PyDoc_STR("*float*: Open circuit voltage [V]\n\n*Required*: True"),
 	NULL},
{"alpha_isc", (getter)SixParameterSolver_get_alpha_isc,(setter)SixParameterSolver_set_alpha_isc,
	PyDoc_STR("*float*: Temp coeff of current at SC [A/'C]\n\n*Required*: True"),
 	NULL},
{"beta_voc", (getter)SixParameterSolver_get_beta_voc,(setter)SixParameterSolver_set_beta_voc,
	PyDoc_STR("*float*: Temp coeff of voltage at OC [V/'C]\n\n*Required*: True"),
 	NULL},
{"celltype", (getter)SixParameterSolver_get_celltype,(setter)SixParameterSolver_set_celltype,
	PyDoc_STR("*str*: Cell technology type [monoSi,multiSi/polySi,cis,cigs,cdte,amorphous]\n\n*Required*: True"),
 	NULL},
{"gamma_pmp", (getter)SixParameterSolver_get_gamma_pmp,(setter)SixParameterSolver_set_gamma_pmp,
	PyDoc_STR("*float*: Temp coeff of power at MP [%/'C]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SixParameterSolver_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"SixParsolve.SixParameterSolver",             /*tp_name*/
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
		SixParameterSolver_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SixParameterSolver_getset,          /*tp_getset*/
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
Outputs_new(SAM_6parsolve data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "6parsolve", "Outputs")){
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
Outputs_get_Adj(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_6parsolve_Outputs_Adj_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Il(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_6parsolve_Outputs_Il_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Io(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_6parsolve_Outputs_Io_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Rs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_6parsolve_Outputs_Rs_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Rsh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_6parsolve_Outputs_Rsh_nget, self->data_ptr);
}

static PyObject *
Outputs_get_a(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_6parsolve_Outputs_a_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"Adj", (getter)Outputs_get_Adj,(setter)0,
	PyDoc_STR("*float*: OC SC temp coeff adjustment [%]"),
 	NULL},
{"Il", (getter)Outputs_get_Il,(setter)0,
	PyDoc_STR("*float*: Light current [A]"),
 	NULL},
{"Io", (getter)Outputs_get_Io,(setter)0,
	PyDoc_STR("*float*: Saturation current [A]"),
 	NULL},
{"Rs", (getter)Outputs_get_Rs,(setter)0,
	PyDoc_STR("*float*: Series resistance [ohm]"),
 	NULL},
{"Rsh", (getter)Outputs_get_Rsh,(setter)0,
	PyDoc_STR("*float*: Shunt resistance [ohm]"),
 	NULL},
{"a", (getter)Outputs_get_a,(setter)0,
	PyDoc_STR("*float*: Modified nonideality factor [1/V]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"SixParsolve.Outputs",             /*tp_name*/
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
 * SixParsolve
 */

static PyTypeObject SixParsolve_Type;

static CmodObject *
newSixParsolveObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &SixParsolve_Type);

	PySAM_TECH_ATTR()

	PyObject* SixParameterSolver_obj = SixParameterSolver_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SixParameterSolver", SixParameterSolver_obj);
	Py_DECREF(SixParameterSolver_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* SixParsolve methods */

static void
SixParsolve_dealloc(CmodObject *self)
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
SixParsolve_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_6parsolve_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
SixParsolve_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "6parsolve"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
SixParsolve_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
SixParsolve_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef SixParsolve_methods[] = {
		{"execute",            (PyCFunction)SixParsolve_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)SixParsolve_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Six Parameter Solver': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)SixParsolve_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)SixParsolve_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SixParsolve_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
SixParsolve_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject SixParsolve_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"SixParsolve",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)SixParsolve_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)SixParsolve_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)SixParsolve_getattro, /*tp_getattro*/
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
		SixParsolve_methods,      /*tp_methods*/
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


/* Function of no arguments returning new SixParsolve object */

static PyObject *
SixParsolve_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newSixParsolveObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
SixParsolve_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSixParsolveObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
SixParsolve_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSixParsolveObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "6parsolve", def);

	return (PyObject *)rv;
}

static PyObject *
SixParsolve_from_existing(PyObject *self, PyObject *args)
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

	rv = newSixParsolveObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "6parsolve", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef SixParsolveModule_methods[] = {
		{"new",             SixParsolve_new,         METH_VARARGS,
				PyDoc_STR("new() -> SixParsolve")},
		{"default",             SixParsolve_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> SixParsolve\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             SixParsolve_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> SixParsolve\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   SixParsolve_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> SixParsolve\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "SixParsolve");


static int
SixParsolveModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	SixParsolve_Type.tp_dict = PyDict_New();
	if (!SixParsolve_Type.tp_dict) { goto fail; }

	/// Add the SixParameterSolver type object to SixParsolve_Type
	if (PyType_Ready(&SixParameterSolver_Type) < 0) { goto fail; }
	PyDict_SetItemString(SixParsolve_Type.tp_dict,
				"SixParameterSolver",
				(PyObject*)&SixParameterSolver_Type);
	Py_DECREF(&SixParameterSolver_Type);

	/// Add the Outputs type object to SixParsolve_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(SixParsolve_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the SixParsolve type object to the module
	if (PyType_Ready(&SixParsolve_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"SixParsolve",
				(PyObject*)&SixParsolve_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot SixParsolveModule_slots[] = {
		{Py_mod_exec, SixParsolveModule_exec},
		{0, NULL},
};

static struct PyModuleDef SixParsolveModule = {
		PyModuleDef_HEAD_INIT,
		"SixParsolve",
		module_doc,
		0,
		SixParsolveModule_methods,
		SixParsolveModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_SixParsolve(void)
{
	return PyModuleDef_Init(&SixParsolveModule);
}