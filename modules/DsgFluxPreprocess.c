#include <Python.h>

#include <SAM_DsgFluxPreprocess.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Common Group
 */ 

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_DsgFluxPreprocess data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "DsgFluxPreprocess", "Common")){
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
Common_get_CT(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Common_CT_nget, self->data_ptr);
}

static int
Common_set_CT(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_DsgFluxPreprocess_Common_CT_nset, self->data_ptr);
}

static PyObject *
Common_get_P_HP_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Common_P_HP_in_nget, self->data_ptr);
}

static int
Common_set_P_HP_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_DsgFluxPreprocess_Common_P_HP_in_nset, self->data_ptr);
}

static PyObject *
Common_get_P_HP_out(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Common_P_HP_out_nget, self->data_ptr);
}

static int
Common_set_P_HP_out(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_DsgFluxPreprocess_Common_P_HP_out_nset, self->data_ptr);
}

static PyObject *
Common_get_P_cycle_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Common_P_cycle_des_nget, self->data_ptr);
}

static int
Common_set_P_cycle_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_DsgFluxPreprocess_Common_P_cycle_des_nset, self->data_ptr);
}

static PyObject *
Common_get_Q_rec_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Common_Q_rec_des_nget, self->data_ptr);
}

static int
Common_set_Q_rec_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_DsgFluxPreprocess_Common_Q_rec_des_nset, self->data_ptr);
}

static PyObject *
Common_get_T_ITD_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Common_T_ITD_des_nget, self->data_ptr);
}

static int
Common_set_T_ITD_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_DsgFluxPreprocess_Common_T_ITD_des_nset, self->data_ptr);
}

static PyObject *
Common_get_T_amb_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Common_T_amb_des_nget, self->data_ptr);
}

static int
Common_set_T_amb_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_DsgFluxPreprocess_Common_T_amb_des_nset, self->data_ptr);
}

static PyObject *
Common_get_T_approach(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Common_T_approach_nget, self->data_ptr);
}

static int
Common_set_T_approach(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_DsgFluxPreprocess_Common_T_approach_nset, self->data_ptr);
}

static PyObject *
Common_get_T_rh_out_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Common_T_rh_out_ref_nget, self->data_ptr);
}

static int
Common_set_T_rh_out_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_DsgFluxPreprocess_Common_T_rh_out_ref_nset, self->data_ptr);
}

static PyObject *
Common_get_T_sh_out_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Common_T_sh_out_ref_nget, self->data_ptr);
}

static int
Common_set_T_sh_out_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_DsgFluxPreprocess_Common_T_sh_out_ref_nset, self->data_ptr);
}

static PyObject *
Common_get_b_q_loss_flux(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Common_b_q_loss_flux_nget, self->data_ptr);
}

static int
Common_set_b_q_loss_flux(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_DsgFluxPreprocess_Common_b_q_loss_flux_nset, self->data_ptr);
}

static PyObject *
Common_get_dT_cooling_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Common_dT_cooling_ref_nget, self->data_ptr);
}

static int
Common_set_dT_cooling_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_DsgFluxPreprocess_Common_dT_cooling_ref_nset, self->data_ptr);
}

static PyObject *
Common_get_eta_cycle_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Common_eta_cycle_des_nget, self->data_ptr);
}

static int
Common_set_eta_cycle_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_DsgFluxPreprocess_Common_eta_cycle_des_nset, self->data_ptr);
}

static PyObject *
Common_get_max_flux_b(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Common_max_flux_b_nget, self->data_ptr);
}

static int
Common_set_max_flux_b(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_DsgFluxPreprocess_Common_max_flux_b_nset, self->data_ptr);
}

static PyObject *
Common_get_max_flux_rh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Common_max_flux_rh_nget, self->data_ptr);
}

static int
Common_set_max_flux_rh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_DsgFluxPreprocess_Common_max_flux_rh_nset, self->data_ptr);
}

static PyObject *
Common_get_max_flux_sh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Common_max_flux_sh_nget, self->data_ptr);
}

static int
Common_set_max_flux_sh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_DsgFluxPreprocess_Common_max_flux_sh_nset, self->data_ptr);
}

static PyObject *
Common_get_rh_frac_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Common_rh_frac_ref_nget, self->data_ptr);
}

static int
Common_set_rh_frac_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_DsgFluxPreprocess_Common_rh_frac_ref_nset, self->data_ptr);
}

static PyObject *
Common_get_rh_q_loss_flux(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Common_rh_q_loss_flux_nget, self->data_ptr);
}

static int
Common_set_rh_q_loss_flux(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_DsgFluxPreprocess_Common_rh_q_loss_flux_nset, self->data_ptr);
}

static PyObject *
Common_get_sh_q_loss_flux(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Common_sh_q_loss_flux_nget, self->data_ptr);
}

static int
Common_set_sh_q_loss_flux(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_DsgFluxPreprocess_Common_sh_q_loss_flux_nset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"CT", (getter)Common_get_CT,(setter)Common_set_CT,
	PyDoc_STR("*float*: Cooling type\n\n*Required*: True"),
 	NULL},
{"P_HP_in", (getter)Common_get_P_HP_in,(setter)Common_set_P_HP_in,
	PyDoc_STR("*float*: HP Turbine inlet pressure [bar]\n\n*Required*: True"),
 	NULL},
{"P_HP_out", (getter)Common_get_P_HP_out,(setter)Common_set_P_HP_out,
	PyDoc_STR("*float*: HP Turbine outlet pressure [bar]\n\n*Required*: True"),
 	NULL},
{"P_cycle_des", (getter)Common_get_P_cycle_des,(setter)Common_set_P_cycle_des,
	PyDoc_STR("*float*: Cycle power output at design [MW]\n\n*Required*: True"),
 	NULL},
{"Q_rec_des", (getter)Common_get_Q_rec_des,(setter)Common_set_Q_rec_des,
	PyDoc_STR("*float*: Receiver thermal power at des. [MW]\n\n*Required*: True"),
 	NULL},
{"T_ITD_des", (getter)Common_get_T_ITD_des,(setter)Common_set_T_ITD_des,
	PyDoc_STR("*float*: T_cond - T_db [C]\n\n*Required*: True"),
 	NULL},
{"T_amb_des", (getter)Common_get_T_amb_des,(setter)Common_set_T_amb_des,
	PyDoc_STR("*float*: Ambient (wb) temp at design [C]\n\n*Required*: True"),
 	NULL},
{"T_approach", (getter)Common_get_T_approach,(setter)Common_set_T_approach,
	PyDoc_STR("*float*: dT cold cooling water - T_wb [C]\n\n*Required*: True"),
 	NULL},
{"T_rh_out_ref", (getter)Common_get_T_rh_out_ref,(setter)Common_set_T_rh_out_ref,
	PyDoc_STR("*float*: Reheater outlet temperature [C]\n\n*Required*: True"),
 	NULL},
{"T_sh_out_ref", (getter)Common_get_T_sh_out_ref,(setter)Common_set_T_sh_out_ref,
	PyDoc_STR("*float*: Superheater outlet temperature [C]\n\n*Required*: True"),
 	NULL},
{"b_q_loss_flux", (getter)Common_get_b_q_loss_flux,(setter)Common_set_b_q_loss_flux,
	PyDoc_STR("*float*: Boiler heat loss flux [kW/m2]\n\n*Required*: True"),
 	NULL},
{"dT_cooling_ref", (getter)Common_get_dT_cooling_ref,(setter)Common_set_dT_cooling_ref,
	PyDoc_STR("*float*: dT of cooling water [C]\n\n*Required*: True"),
 	NULL},
{"eta_cycle_des", (getter)Common_get_eta_cycle_des,(setter)Common_set_eta_cycle_des,
	PyDoc_STR("*float*: Cycle thermal efficiency at des.\n\n*Required*: True"),
 	NULL},
{"max_flux_b", (getter)Common_get_max_flux_b,(setter)Common_set_max_flux_b,
	PyDoc_STR("*float*: Max allow. boiler flux [kW/m2]\n\n*Required*: True"),
 	NULL},
{"max_flux_rh", (getter)Common_get_max_flux_rh,(setter)Common_set_max_flux_rh,
	PyDoc_STR("*float*: Max allow. reheater flux [kW/m2]\n\n*Required*: True"),
 	NULL},
{"max_flux_sh", (getter)Common_get_max_flux_sh,(setter)Common_set_max_flux_sh,
	PyDoc_STR("*float*: Max allow. superheater flux [kW/m2]\n\n*Required*: True"),
 	NULL},
{"rh_frac_ref", (getter)Common_get_rh_frac_ref,(setter)Common_set_rh_frac_ref,
	PyDoc_STR("*float*: Mdot fraction to reheat at design\n\n*Required*: True"),
 	NULL},
{"rh_q_loss_flux", (getter)Common_get_rh_q_loss_flux,(setter)Common_set_rh_q_loss_flux,
	PyDoc_STR("*float*: Reheater heat loss flux [kW/m2]\n\n*Required*: True"),
 	NULL},
{"sh_q_loss_flux", (getter)Common_get_sh_q_loss_flux,(setter)Common_set_sh_q_loss_flux,
	PyDoc_STR("*float*: Superheater heat loss flux [kW/m2]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"DsgFluxPreprocess.Common",             /*tp_name*/
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
Outputs_new(SAM_DsgFluxPreprocess data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "DsgFluxPreprocess", "Outputs")){
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
Outputs_get_f_b(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Outputs_f_b_nget, self->data_ptr);
}

static PyObject *
Outputs_get_f_rh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Outputs_f_rh_nget, self->data_ptr);
}

static PyObject *
Outputs_get_f_sh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Outputs_f_sh_nget, self->data_ptr);
}

static PyObject *
Outputs_get_max_flux(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_DsgFluxPreprocess_Outputs_max_flux_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"f_b", (getter)Outputs_get_f_b,(setter)0,
	PyDoc_STR("*float*: Fraction of total height to boiler"),
 	NULL},
{"f_rh", (getter)Outputs_get_f_rh,(setter)0,
	PyDoc_STR("*float*: Fraction of total height to RH"),
 	NULL},
{"f_sh", (getter)Outputs_get_f_sh,(setter)0,
	PyDoc_STR("*float*: Fraction of total height to SH"),
 	NULL},
{"max_flux", (getter)Outputs_get_max_flux,(setter)0,
	PyDoc_STR("*float*: Maximum flux allow. on receiver [kW/m2]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"DsgFluxPreprocess.Outputs",             /*tp_name*/
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
 * DsgFluxPreprocess
 */

static PyTypeObject DsgFluxPreprocess_Type;

static CmodObject *
newDsgFluxPreprocessObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &DsgFluxPreprocess_Type);

	PySAM_TECH_ATTR()

	PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* DsgFluxPreprocess methods */

static void
DsgFluxPreprocess_dealloc(CmodObject *self)
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
DsgFluxPreprocess_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_DsgFluxPreprocess_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
DsgFluxPreprocess_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "DsgFluxPreprocess"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
DsgFluxPreprocess_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
DsgFluxPreprocess_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef DsgFluxPreprocess_methods[] = {
		{"execute",            (PyCFunction)DsgFluxPreprocess_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)DsgFluxPreprocess_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Common': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)DsgFluxPreprocess_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)DsgFluxPreprocess_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
DsgFluxPreprocess_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
DsgFluxPreprocess_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject DsgFluxPreprocess_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"DsgFluxPreprocess",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)DsgFluxPreprocess_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)DsgFluxPreprocess_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)DsgFluxPreprocess_getattro, /*tp_getattro*/
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
		DsgFluxPreprocess_methods,      /*tp_methods*/
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


/* Function of no arguments returning new DsgFluxPreprocess object */

static PyObject *
DsgFluxPreprocess_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newDsgFluxPreprocessObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
DsgFluxPreprocess_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newDsgFluxPreprocessObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
DsgFluxPreprocess_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newDsgFluxPreprocessObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "DsgFluxPreprocess", def);

	return (PyObject *)rv;
}

static PyObject *
DsgFluxPreprocess_from_existing(PyObject *self, PyObject *args)
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

	rv = newDsgFluxPreprocessObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "DsgFluxPreprocess", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef DsgFluxPreprocessModule_methods[] = {
		{"new",             DsgFluxPreprocess_new,         METH_VARARGS,
				PyDoc_STR("new() -> DsgFluxPreprocess")},
		{"default",             DsgFluxPreprocess_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> DsgFluxPreprocess\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             DsgFluxPreprocess_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> DsgFluxPreprocess\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   DsgFluxPreprocess_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> DsgFluxPreprocess\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "DsgFluxPreprocess");


static int
DsgFluxPreprocessModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	DsgFluxPreprocess_Type.tp_dict = PyDict_New();
	if (!DsgFluxPreprocess_Type.tp_dict) { goto fail; }

	/// Add the Common type object to DsgFluxPreprocess_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(DsgFluxPreprocess_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the Outputs type object to DsgFluxPreprocess_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(DsgFluxPreprocess_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the DsgFluxPreprocess type object to the module
	if (PyType_Ready(&DsgFluxPreprocess_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"DsgFluxPreprocess",
				(PyObject*)&DsgFluxPreprocess_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot DsgFluxPreprocessModule_slots[] = {
		{Py_mod_exec, DsgFluxPreprocessModule_exec},
		{0, NULL},
};

static struct PyModuleDef DsgFluxPreprocessModule = {
		PyModuleDef_HEAD_INIT,
		"DsgFluxPreprocess",
		module_doc,
		0,
		DsgFluxPreprocessModule_methods,
		DsgFluxPreprocessModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_DsgFluxPreprocess(void)
{
	return PyModuleDef_Init(&DsgFluxPreprocessModule);
}