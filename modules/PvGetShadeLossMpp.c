#include <Python.h>

#include <SAM_PvGetShadeLossMpp.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * PVShadeLossDB Group
 */ 

static PyTypeObject PVShadeLossDB_Type;

static PyObject *
PVShadeLossDB_new(SAM_PvGetShadeLossMpp data_ptr)
{
	PyObject* new_obj = PVShadeLossDB_Type.tp_alloc(&PVShadeLossDB_Type,0);

	VarGroupObject* PVShadeLossDB_obj = (VarGroupObject*)new_obj;

	PVShadeLossDB_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* PVShadeLossDB methods */

static PyObject *
PVShadeLossDB_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "PvGetShadeLossMpp", "PVShadeLossDB")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PVShadeLossDB_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &PVShadeLossDB_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef PVShadeLossDB_methods[] = {
		{"assign",            (PyCFunction)PVShadeLossDB_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``PVShadeLossDB_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)PVShadeLossDB_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
PVShadeLossDB_get_diffuse_irrad(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_PvGetShadeLossMpp_PVShadeLossDB_diffuse_irrad_aget, self->data_ptr);
}

static int
PVShadeLossDB_set_diffuse_irrad(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_PvGetShadeLossMpp_PVShadeLossDB_diffuse_irrad_aset, self->data_ptr);
}

static PyObject *
PVShadeLossDB_get_global_poa_irrad(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_PvGetShadeLossMpp_PVShadeLossDB_global_poa_irrad_aget, self->data_ptr);
}

static int
PVShadeLossDB_set_global_poa_irrad(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_PvGetShadeLossMpp_PVShadeLossDB_global_poa_irrad_aset, self->data_ptr);
}

static PyObject *
PVShadeLossDB_get_mods_per_string(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_PvGetShadeLossMpp_PVShadeLossDB_mods_per_string_aget, self->data_ptr);
}

static int
PVShadeLossDB_set_mods_per_string(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_PvGetShadeLossMpp_PVShadeLossDB_mods_per_string_aset, self->data_ptr);
}

static PyObject *
PVShadeLossDB_get_pv_cell_temp(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_PvGetShadeLossMpp_PVShadeLossDB_pv_cell_temp_aget, self->data_ptr);
}

static int
PVShadeLossDB_set_pv_cell_temp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_PvGetShadeLossMpp_PVShadeLossDB_pv_cell_temp_aset, self->data_ptr);
}

static PyObject *
PVShadeLossDB_get_str_shade_fracs(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_PvGetShadeLossMpp_PVShadeLossDB_str_shade_fracs_mget, self->data_ptr);
}

static int
PVShadeLossDB_set_str_shade_fracs(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_PvGetShadeLossMpp_PVShadeLossDB_str_shade_fracs_mset, self->data_ptr);
}

static PyObject *
PVShadeLossDB_get_str_vmp_stc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_PvGetShadeLossMpp_PVShadeLossDB_str_vmp_stc_aget, self->data_ptr);
}

static int
PVShadeLossDB_set_str_vmp_stc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_PvGetShadeLossMpp_PVShadeLossDB_str_vmp_stc_aset, self->data_ptr);
}

static PyObject *
PVShadeLossDB_get_v_mppt_high(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_PvGetShadeLossMpp_PVShadeLossDB_v_mppt_high_aget, self->data_ptr);
}

static int
PVShadeLossDB_set_v_mppt_high(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_PvGetShadeLossMpp_PVShadeLossDB_v_mppt_high_aset, self->data_ptr);
}

static PyObject *
PVShadeLossDB_get_v_mppt_low(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_PvGetShadeLossMpp_PVShadeLossDB_v_mppt_low_aget, self->data_ptr);
}

static int
PVShadeLossDB_set_v_mppt_low(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_PvGetShadeLossMpp_PVShadeLossDB_v_mppt_low_aset, self->data_ptr);
}

static PyGetSetDef PVShadeLossDB_getset[] = {
{"diffuse_irrad", (getter)PVShadeLossDB_get_diffuse_irrad,(setter)PVShadeLossDB_set_diffuse_irrad,
	PyDoc_STR("*sequence*: Diffuse irradiance\n\n*Required*: True"),
 	NULL},
{"global_poa_irrad", (getter)PVShadeLossDB_get_global_poa_irrad,(setter)PVShadeLossDB_set_global_poa_irrad,
	PyDoc_STR("*sequence*: Global POA irradiance\n\n*Required*: True"),
 	NULL},
{"mods_per_string", (getter)PVShadeLossDB_get_mods_per_string,(setter)PVShadeLossDB_set_mods_per_string,
	PyDoc_STR("*sequence*: Modules per string\n\n*Required*: True"),
 	NULL},
{"pv_cell_temp", (getter)PVShadeLossDB_get_pv_cell_temp,(setter)PVShadeLossDB_set_pv_cell_temp,
	PyDoc_STR("*sequence*: PV cell temperature\n\n*Required*: True"),
 	NULL},
{"str_shade_fracs", (getter)PVShadeLossDB_get_str_shade_fracs,(setter)PVShadeLossDB_set_str_shade_fracs,
	PyDoc_STR("*sequence[sequence]*: Shading fractions for each string\n\n*Required*: True"),
 	NULL},
{"str_vmp_stc", (getter)PVShadeLossDB_get_str_vmp_stc,(setter)PVShadeLossDB_set_str_vmp_stc,
	PyDoc_STR("*sequence*: Unshaded Vmp of the string at STC\n\n*Required*: True"),
 	NULL},
{"v_mppt_high", (getter)PVShadeLossDB_get_v_mppt_high,(setter)PVShadeLossDB_set_v_mppt_high,
	PyDoc_STR("*sequence*: Upper bound of inverter MPPT range\n\n*Required*: True"),
 	NULL},
{"v_mppt_low", (getter)PVShadeLossDB_get_v_mppt_low,(setter)PVShadeLossDB_set_v_mppt_low,
	PyDoc_STR("*sequence*: Lower bound of inverter MPPT range\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject PVShadeLossDB_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"PvGetShadeLossMpp.PVShadeLossDB",             /*tp_name*/
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
		PVShadeLossDB_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		PVShadeLossDB_getset,          /*tp_getset*/
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
Outputs_new(SAM_PvGetShadeLossMpp data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "PvGetShadeLossMpp", "Outputs")){
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
Outputs_get_N(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_PvGetShadeLossMpp_Outputs_N_aget, self->data_ptr);
}

static PyObject *
Outputs_get_S(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_PvGetShadeLossMpp_Outputs_S_aget, self->data_ptr);
}

static PyObject *
Outputs_get_d(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_PvGetShadeLossMpp_Outputs_d_aget, self->data_ptr);
}

static PyObject *
Outputs_get_shade_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_PvGetShadeLossMpp_Outputs_shade_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_t(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_PvGetShadeLossMpp_Outputs_t_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"N", (getter)Outputs_get_N,(setter)0,
	PyDoc_STR("*sequence*: N"),
 	NULL},
{"S", (getter)Outputs_get_S,(setter)0,
	PyDoc_STR("*sequence*: S"),
 	NULL},
{"d", (getter)Outputs_get_d,(setter)0,
	PyDoc_STR("*sequence*: d"),
 	NULL},
{"shade_loss", (getter)Outputs_get_shade_loss,(setter)0,
	PyDoc_STR("*sequence*: Shade loss fraction"),
 	NULL},
{"t", (getter)Outputs_get_t,(setter)0,
	PyDoc_STR("*sequence*: t"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"PvGetShadeLossMpp.Outputs",             /*tp_name*/
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
 * PvGetShadeLossMpp
 */

static PyTypeObject PvGetShadeLossMpp_Type;

static CmodObject *
newPvGetShadeLossMppObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &PvGetShadeLossMpp_Type);

	PySAM_TECH_ATTR()

	PyObject* PVShadeLossDB_obj = PVShadeLossDB_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "PVShadeLossDB", PVShadeLossDB_obj);
	Py_DECREF(PVShadeLossDB_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* PvGetShadeLossMpp methods */

static void
PvGetShadeLossMpp_dealloc(CmodObject *self)
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
PvGetShadeLossMpp_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_PvGetShadeLossMpp_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
PvGetShadeLossMpp_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "PvGetShadeLossMpp"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
PvGetShadeLossMpp_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
PvGetShadeLossMpp_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef PvGetShadeLossMpp_methods[] = {
		{"execute",            (PyCFunction)PvGetShadeLossMpp_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)PvGetShadeLossMpp_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'PV Shade Loss DB': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)PvGetShadeLossMpp_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)PvGetShadeLossMpp_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
PvGetShadeLossMpp_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
PvGetShadeLossMpp_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject PvGetShadeLossMpp_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"PvGetShadeLossMpp",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)PvGetShadeLossMpp_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)PvGetShadeLossMpp_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)PvGetShadeLossMpp_getattro, /*tp_getattro*/
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
		PvGetShadeLossMpp_methods,      /*tp_methods*/
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


/* Function of no arguments returning new PvGetShadeLossMpp object */

static PyObject *
PvGetShadeLossMpp_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newPvGetShadeLossMppObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
PvGetShadeLossMpp_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvGetShadeLossMppObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
PvGetShadeLossMpp_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvGetShadeLossMppObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "PvGetShadeLossMpp", def);

	return (PyObject *)rv;
}

static PyObject *
PvGetShadeLossMpp_from_existing(PyObject *self, PyObject *args)
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

	rv = newPvGetShadeLossMppObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "PvGetShadeLossMpp", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef PvGetShadeLossMppModule_methods[] = {
		{"new",             PvGetShadeLossMpp_new,         METH_VARARGS,
				PyDoc_STR("new() -> PvGetShadeLossMpp")},
		{"default",             PvGetShadeLossMpp_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> PvGetShadeLossMpp\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             PvGetShadeLossMpp_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> PvGetShadeLossMpp\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   PvGetShadeLossMpp_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> PvGetShadeLossMpp\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "PvGetShadeLossMpp");


static int
PvGetShadeLossMppModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	PvGetShadeLossMpp_Type.tp_dict = PyDict_New();
	if (!PvGetShadeLossMpp_Type.tp_dict) { goto fail; }

	/// Add the PVShadeLossDB type object to PvGetShadeLossMpp_Type
	if (PyType_Ready(&PVShadeLossDB_Type) < 0) { goto fail; }
	PyDict_SetItemString(PvGetShadeLossMpp_Type.tp_dict,
				"PVShadeLossDB",
				(PyObject*)&PVShadeLossDB_Type);
	Py_DECREF(&PVShadeLossDB_Type);

	/// Add the Outputs type object to PvGetShadeLossMpp_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(PvGetShadeLossMpp_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the PvGetShadeLossMpp type object to the module
	if (PyType_Ready(&PvGetShadeLossMpp_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"PvGetShadeLossMpp",
				(PyObject*)&PvGetShadeLossMpp_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot PvGetShadeLossMppModule_slots[] = {
		{Py_mod_exec, PvGetShadeLossMppModule_exec},
		{0, NULL},
};

static struct PyModuleDef PvGetShadeLossMppModule = {
		PyModuleDef_HEAD_INIT,
		"PvGetShadeLossMpp",
		module_doc,
		0,
		PvGetShadeLossMppModule_methods,
		PvGetShadeLossMppModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_PvGetShadeLossMpp(void)
{
	return PyModuleDef_Init(&PvGetShadeLossMppModule);
}