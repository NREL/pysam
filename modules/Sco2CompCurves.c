#include <Python.h>

#include <SAM_Sco2CompCurves.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Common Group
 */ 

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_Sco2CompCurves data_ptr)
{
	PyObject* new_obj = Common_Type.tp_alloc(&Common_Type,0);

	VarGroupObject* Common_obj = (VarGroupObject*)new_obj;

	Common_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Common methods */

static PyObject *
Common_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Sco2CompCurves", "Common")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Common_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Common_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Sco2CompCurves", "Common")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Common_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Common_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Common_methods[] = {
		{"assign",            (PyCFunction)Common_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values\n\n``Common_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Common_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input dict\n\n``Common_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Common_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Common_get_P_comp_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CompCurves_Common_P_comp_in_nget, self->data_ptr);
}

static int
Common_set_P_comp_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CompCurves_Common_P_comp_in_nset, self->data_ptr);
}

static PyObject *
Common_get_T_comp_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CompCurves_Common_T_comp_in_nget, self->data_ptr);
}

static int
Common_set_T_comp_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CompCurves_Common_T_comp_in_nset, self->data_ptr);
}

static PyObject *
Common_get_comp_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CompCurves_Common_comp_type_nget, self->data_ptr);
}

static int
Common_set_comp_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CompCurves_Common_comp_type_nset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"P_comp_in", (getter)Common_get_P_comp_in,(setter)Common_set_P_comp_in,
	PyDoc_STR("*float*: Compressor inlet pressure [MPa]\n\n*Required*: True"),
 	NULL},
{"T_comp_in", (getter)Common_get_T_comp_in,(setter)Common_set_T_comp_in,
	PyDoc_STR("*float*: Compressor inlet temperature [C]\n\n*Required*: True"),
 	NULL},
{"comp_type", (getter)Common_get_comp_type,(setter)Common_set_comp_type,
	PyDoc_STR("*float*: Integer corresponding to compressor model [-]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Sco2CompCurves.Common",             /*tp_name*/
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
		Common_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Common_getset,          /*tp_getset*/
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
Outputs_new(SAM_Sco2CompCurves data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Sco2CompCurves", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Sco2CompCurves", "Outputs")){
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
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values\n\n``Outputs_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Outputs_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input dict\n\n``Outputs_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Outputs_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Outputs_get_eta(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CompCurves_Outputs_eta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_ND(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CompCurves_Outputs_eta_ND_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_norm_design(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CompCurves_Outputs_eta_norm_design_nget, self->data_ptr);
}

static PyObject *
Outputs_get_phi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CompCurves_Outputs_phi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_phi_ND(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CompCurves_Outputs_phi_ND_aget, self->data_ptr);
}

static PyObject *
Outputs_get_phi_design(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CompCurves_Outputs_phi_design_nget, self->data_ptr);
}

static PyObject *
Outputs_get_psi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CompCurves_Outputs_psi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_psi_ND(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CompCurves_Outputs_psi_ND_aget, self->data_ptr);
}

static PyObject *
Outputs_get_psi_design(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CompCurves_Outputs_psi_design_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"eta", (getter)Outputs_get_eta,(setter)0,
	PyDoc_STR("*sequence*: Array of efficiencies at phi [-]"),
 	NULL},
{"eta_ND", (getter)Outputs_get_eta_ND,(setter)0,
	PyDoc_STR("*sequence*: Array of normalized efficiencies at phi [-]"),
 	NULL},
{"eta_norm_design", (getter)Outputs_get_eta_norm_design,(setter)0,
	PyDoc_STR("*float*: Normalized design isentropic efficiency [-]"),
 	NULL},
{"phi", (getter)Outputs_get_phi,(setter)0,
	PyDoc_STR("*sequence*: Array of flow coefficients [-]"),
 	NULL},
{"phi_ND", (getter)Outputs_get_phi_ND,(setter)0,
	PyDoc_STR("*sequence*: Array of normalized flow coefficients [-]"),
 	NULL},
{"phi_design", (getter)Outputs_get_phi_design,(setter)0,
	PyDoc_STR("*float*: Design flow coefficient [-]"),
 	NULL},
{"psi", (getter)Outputs_get_psi,(setter)0,
	PyDoc_STR("*sequence*: Array of isentropic head coefficients at phi [-]"),
 	NULL},
{"psi_ND", (getter)Outputs_get_psi_ND,(setter)0,
	PyDoc_STR("*sequence*: Array of normalized isentropic head coefficients at phi [-]"),
 	NULL},
{"psi_design", (getter)Outputs_get_psi_design,(setter)0,
	PyDoc_STR("*float*: Design isentropic head coefficient [-]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Sco2CompCurves.Outputs",             /*tp_name*/
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
 * Sco2CompCurves
 */

static PyTypeObject Sco2CompCurves_Type;

static CmodObject *
newSco2CompCurvesObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Sco2CompCurves_Type);

	PySAM_TECH_ATTR()

	PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Sco2CompCurves methods */

static void
Sco2CompCurves_dealloc(CmodObject *self)
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
Sco2CompCurves_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Sco2CompCurves_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Sco2CompCurves_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Sco2CompCurves"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Sco2CompCurves_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Sco2CompCurves"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Sco2CompCurves_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Sco2CompCurves_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Sco2CompCurves_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Sco2CompCurves_methods[] = {
		{"execute",           (PyCFunction)Sco2CompCurves_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Sco2CompCurves_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Common': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Sco2CompCurves_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Common': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Sco2CompCurves_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Sco2CompCurves_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Sco2CompCurves_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Sco2CompCurves_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Sco2CompCurves_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Sco2CompCurves_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Sco2CompCurves",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Sco2CompCurves_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Sco2CompCurves_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Sco2CompCurves_getattro, /*tp_getattro*/
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
		Sco2CompCurves_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Sco2CompCurves object */

static PyObject *
Sco2CompCurves_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newSco2CompCurvesObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Sco2CompCurves_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSco2CompCurvesObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Sco2CompCurves_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSco2CompCurvesObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Sco2CompCurves", def) < 0) {
		Sco2CompCurves_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Sco2CompCurves_from_existing(PyObject *self, PyObject *args)
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

	rv = newSco2CompCurvesObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Sco2CompCurves", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Sco2CompCurvesModule_methods[] = {
		{"new",             Sco2CompCurves_new,         METH_VARARGS,
				PyDoc_STR("new() -> Sco2CompCurves")},
		{"default",             Sco2CompCurves_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Sco2CompCurves\n\nUse default attributes\n"
				"None")},
		{"wrap",             Sco2CompCurves_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Sco2CompCurves\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   Sco2CompCurves_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Sco2CompCurves\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Sco2CompCurves");


static int
Sco2CompCurvesModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Sco2CompCurves_Type.tp_dict = PyDict_New();
	if (!Sco2CompCurves_Type.tp_dict) { goto fail; }

	/// Add the Common type object to Sco2CompCurves_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(Sco2CompCurves_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the Outputs type object to Sco2CompCurves_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Sco2CompCurves_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Sco2CompCurves type object to the module
	if (PyType_Ready(&Sco2CompCurves_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Sco2CompCurves",
				(PyObject*)&Sco2CompCurves_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Sco2CompCurvesModule_slots[] = {
		{Py_mod_exec, Sco2CompCurvesModule_exec},
		{0, NULL},
};

static struct PyModuleDef Sco2CompCurvesModule = {
		PyModuleDef_HEAD_INIT,
		"Sco2CompCurves",
		module_doc,
		0,
		Sco2CompCurvesModule_methods,
		Sco2CompCurvesModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Sco2CompCurves(void)
{
	return PyModuleDef_Init(&Sco2CompCurvesModule);
}