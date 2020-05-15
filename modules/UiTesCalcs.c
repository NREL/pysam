#include <Python.h>

#include <SAM_UiTesCalcs.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Common Group
 */ 

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_UiTesCalcs data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "UiTesCalcs", "Common")){
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
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Common_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Common_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Common_get_P_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiTesCalcs_Common_P_ref_nget, self->data_ptr);
}

static int
Common_set_P_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_UiTesCalcs_Common_P_ref_nset, self->data_ptr);
}

static PyObject *
Common_get_T_htf_cold_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiTesCalcs_Common_T_htf_cold_des_nget, self->data_ptr);
}

static int
Common_set_T_htf_cold_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_UiTesCalcs_Common_T_htf_cold_des_nset, self->data_ptr);
}

static PyObject *
Common_get_T_htf_hot_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiTesCalcs_Common_T_htf_hot_des_nget, self->data_ptr);
}

static int
Common_set_T_htf_hot_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_UiTesCalcs_Common_T_htf_hot_des_nset, self->data_ptr);
}

static PyObject *
Common_get_design_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiTesCalcs_Common_design_eff_nget, self->data_ptr);
}

static int
Common_set_design_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_UiTesCalcs_Common_design_eff_nset, self->data_ptr);
}

static PyObject *
Common_get_field_fl_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_UiTesCalcs_Common_field_fl_props_mget, self->data_ptr);
}

static int
Common_set_field_fl_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_UiTesCalcs_Common_field_fl_props_mset, self->data_ptr);
}

static PyObject *
Common_get_h_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiTesCalcs_Common_h_tank_nget, self->data_ptr);
}

static int
Common_set_h_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_UiTesCalcs_Common_h_tank_nset, self->data_ptr);
}

static PyObject *
Common_get_h_tank_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiTesCalcs_Common_h_tank_min_nget, self->data_ptr);
}

static int
Common_set_h_tank_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_UiTesCalcs_Common_h_tank_min_nset, self->data_ptr);
}

static PyObject *
Common_get_rec_htf(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiTesCalcs_Common_rec_htf_nget, self->data_ptr);
}

static int
Common_set_rec_htf(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_UiTesCalcs_Common_rec_htf_nset, self->data_ptr);
}

static PyObject *
Common_get_tank_pairs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiTesCalcs_Common_tank_pairs_nget, self->data_ptr);
}

static int
Common_set_tank_pairs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_UiTesCalcs_Common_tank_pairs_nset, self->data_ptr);
}

static PyObject *
Common_get_tshours(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiTesCalcs_Common_tshours_nget, self->data_ptr);
}

static int
Common_set_tshours(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_UiTesCalcs_Common_tshours_nset, self->data_ptr);
}

static PyObject *
Common_get_u_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiTesCalcs_Common_u_tank_nget, self->data_ptr);
}

static int
Common_set_u_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_UiTesCalcs_Common_u_tank_nset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"P_ref", (getter)Common_get_P_ref,(setter)Common_set_P_ref,
	PyDoc_STR("*float*: Power cycle output at design [MWe]\n\n*Required*: True"),
 	NULL},
{"T_htf_cold_des", (getter)Common_get_T_htf_cold_des,(setter)Common_set_T_htf_cold_des,
	PyDoc_STR("*float*: Cold HTF temp (out of TES HX, if applicable) [C]\n\n*Required*: True"),
 	NULL},
{"T_htf_hot_des", (getter)Common_get_T_htf_hot_des,(setter)Common_set_T_htf_hot_des,
	PyDoc_STR("*float*: Hot HTF temp (into TES HX, if applicable) [C]\n\n*Required*: True"),
 	NULL},
{"design_eff", (getter)Common_get_design_eff,(setter)Common_set_design_eff,
	PyDoc_STR("*float*: Power cycle thermal efficiency\n\n*Required*: True"),
 	NULL},
{"field_fl_props", (getter)Common_get_field_fl_props,(setter)Common_set_field_fl_props,
	PyDoc_STR("*sequence[sequence]*: User defined tes storage fluid prop data\n\n*Info*: 7 columns (T,Cp,dens,visc,kvisc,cond,h), at least 3 rows\n\n*Required*: True"),
 	NULL},
{"h_tank", (getter)Common_get_h_tank,(setter)Common_set_h_tank,
	PyDoc_STR("*float*: Total height of tank (HTF when tank is full [m]\n\n*Required*: True"),
 	NULL},
{"h_tank_min", (getter)Common_get_h_tank_min,(setter)Common_set_h_tank_min,
	PyDoc_STR("*float*: Min. allowable HTF height in storage tank [m]\n\n*Required*: True"),
 	NULL},
{"rec_htf", (getter)Common_get_rec_htf,(setter)Common_set_rec_htf,
	PyDoc_STR("*float*: TES storage fluid code\n\n*Required*: True"),
 	NULL},
{"tank_pairs", (getter)Common_get_tank_pairs,(setter)Common_set_tank_pairs,
	PyDoc_STR("*float*: Number of equivalent tank pairs\n\n*Required*: True"),
 	NULL},
{"tshours", (getter)Common_get_tshours,(setter)Common_set_tshours,
	PyDoc_STR("*float*: Hours of TES relative to q_dot_pb_des [hr]\n\n*Required*: True"),
 	NULL},
{"u_tank", (getter)Common_get_u_tank,(setter)Common_set_u_tank,
	PyDoc_STR("*float*: Loss coefficient from the tank [W/m2-K]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"UiTesCalcs.Common",             /*tp_name*/
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
Outputs_new(SAM_UiTesCalcs data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "UiTesCalcs", "Outputs")){
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
Outputs_get_csp_pt_tes_htf_density(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiTesCalcs_Outputs_csp_pt_tes_htf_density_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_tes_tank_diameter(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiTesCalcs_Outputs_csp_pt_tes_tank_diameter_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_tes_est(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiTesCalcs_Outputs_q_dot_tes_est_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_tes(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiTesCalcs_Outputs_q_tes_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_avail_vol(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiTesCalcs_Outputs_tes_avail_vol_nget, self->data_ptr);
}

static PyObject *
Outputs_get_vol_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_UiTesCalcs_Outputs_vol_tank_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"csp_pt_tes_htf_density", (getter)Outputs_get_csp_pt_tes_htf_density,(setter)0,
	PyDoc_STR("*float*: HTF dens [kg/m^3]"),
 	NULL},
{"csp_pt_tes_tank_diameter", (getter)Outputs_get_csp_pt_tes_tank_diameter,(setter)0,
	PyDoc_STR("*float*: Single tank diameter [m]"),
 	NULL},
{"q_dot_tes_est", (getter)Outputs_get_q_dot_tes_est,(setter)0,
	PyDoc_STR("*float*: Estimated tank heat loss to env. [MWt]"),
 	NULL},
{"q_tes", (getter)Outputs_get_q_tes,(setter)0,
	PyDoc_STR("*float*: TES thermal capacity at design [MWt-hr]"),
 	NULL},
{"tes_avail_vol", (getter)Outputs_get_tes_avail_vol,(setter)0,
	PyDoc_STR("*float*: Available single temp storage volume [m^3]"),
 	NULL},
{"vol_tank", (getter)Outputs_get_vol_tank,(setter)0,
	PyDoc_STR("*float*: Total single temp storage volume [m^3]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"UiTesCalcs.Outputs",             /*tp_name*/
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
 * UiTesCalcs
 */

static PyTypeObject UiTesCalcs_Type;

static CmodObject *
newUiTesCalcsObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &UiTesCalcs_Type);

	PySAM_TECH_ATTR()

	PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* UiTesCalcs methods */

static void
UiTesCalcs_dealloc(CmodObject *self)
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
UiTesCalcs_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_UiTesCalcs_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
UiTesCalcs_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "UiTesCalcs"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
UiTesCalcs_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
UiTesCalcs_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef UiTesCalcs_methods[] = {
		{"execute",            (PyCFunction)UiTesCalcs_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)UiTesCalcs_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Common': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)UiTesCalcs_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)UiTesCalcs_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
UiTesCalcs_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
UiTesCalcs_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject UiTesCalcs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"UiTesCalcs",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)UiTesCalcs_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)UiTesCalcs_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)UiTesCalcs_getattro, /*tp_getattro*/
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
		UiTesCalcs_methods,      /*tp_methods*/
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


/* Function of no arguments returning new UiTesCalcs object */

static PyObject *
UiTesCalcs_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newUiTesCalcsObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
UiTesCalcs_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newUiTesCalcsObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
UiTesCalcs_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newUiTesCalcsObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "UiTesCalcs", def);

	return (PyObject *)rv;
}

static PyObject *
UiTesCalcs_from_existing(PyObject *self, PyObject *args)
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

	rv = newUiTesCalcsObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "UiTesCalcs", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef UiTesCalcsModule_methods[] = {
		{"new",             UiTesCalcs_new,         METH_VARARGS,
				PyDoc_STR("new() -> UiTesCalcs")},
		{"default",             UiTesCalcs_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> UiTesCalcs\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             UiTesCalcs_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> UiTesCalcs\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   UiTesCalcs_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> UiTesCalcs\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "UiTesCalcs");


static int
UiTesCalcsModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	UiTesCalcs_Type.tp_dict = PyDict_New();
	if (!UiTesCalcs_Type.tp_dict) { goto fail; }

	/// Add the Common type object to UiTesCalcs_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(UiTesCalcs_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the Outputs type object to UiTesCalcs_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(UiTesCalcs_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the UiTesCalcs type object to the module
	if (PyType_Ready(&UiTesCalcs_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"UiTesCalcs",
				(PyObject*)&UiTesCalcs_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot UiTesCalcsModule_slots[] = {
		{Py_mod_exec, UiTesCalcsModule_exec},
		{0, NULL},
};

static struct PyModuleDef UiTesCalcsModule = {
		PyModuleDef_HEAD_INIT,
		"UiTesCalcs",
		module_doc,
		0,
		UiTesCalcsModule_methods,
		UiTesCalcsModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_UiTesCalcs(void)
{
	return PyModuleDef_Init(&UiTesCalcsModule);
}